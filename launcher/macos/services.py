"""Owned openSNAP services and native account input for macOS."""
import ipaddress
import json
import os
from pathlib import Path
import re
import signal
import socket
import struct
import subprocess
import sys
import threading
import time
import urllib.parse
import urllib.request
import uuid

from core import ROOT, ELF_SHA256, clean_environment


def host_address(settings):
    host = str(ipaddress.IPv4Address(settings['CoopHost']))
    if ipaddress.IPv4Address(host).is_multicast or host.startswith('0.'):
        raise ValueError('Enter a unicast IPv4 server address')
    return host


def online_environment(settings, card):
    host = host_address(settings)
    if not re.fullmatch(r'(?!_)(?!.*__)(?!.*_$)[A-Za-z0-9_]{4,10}', settings['Username']):
        raise ValueError('Player name: 4–10 letters, digits or underscores; no leading, trailing or doubled underscore')
    directory = Path(card) / 'BWNETCNF'
    try:
        directory.mkdir()
    except FileExistsError:
        if not any(directory.iterdir()):
            raise ValueError('The selected memory card contains an empty network profile')
    else:
        (directory / 'BWNETDCNF').write_text('REO native host profile provider v1')
    return {'REO_COOP_HOST': host, 'REO_COOP_PLATFORM_AUTH': 'native',
            'REO_COOP_USERNAME': settings['Username'], 'REO_COOP_AUTO_ACCOUNT': '1'}


class NoRedirect(urllib.request.HTTPRedirectHandler):
    def redirect_request(self, *args, **kwargs):
        return None


class OnlineAccount:
    def __init__(self, settings, folder, report, resources):
        self.settings, self.report, self.resources = settings, report, Path(resources)
        self.status = Path(folder) / 'network/status'
        self.status.parent.mkdir(mode=0o700)
        self.stop = threading.Event()
        self.attempt, self.password = 0, None
        self.setup = None
        self.threads = []
        self.delivering = set()

    def publish(self, value):
        if self.stop.is_set() or int(value.rsplit(' ',1)[1]) != self.attempt:
            return
        temp = self.status.with_name('status.'+uuid.uuid4().hex+'.pending')
        temp.write_text(value, encoding='ascii')
        temp.replace(self.status)

    def worker(self, function, number):
        def work():
            try:
                function(number)
            except Exception as error:
                self.publish(f'error {number}')
                self.report(f'Network account: {error}')
        thread = threading.Thread(target=work, daemon=True)
        self.threads.append(thread)
        thread.start()
        return thread

    def on_line(self, line):
        request = re.match(r'^\[COOP-AUTO\] account-request (\d+)', line)
        ready = re.match(r'^\[COOP-AUTO\] password-ready (\d+)', line)
        if request and self.attempt < int(request[1]) <= 1000:
            self.attempt = int(request[1])
            previous = list(self.threads)
            def prepare(number):
                for thread in previous:thread.join()
                if not self.stop.is_set():self.prepare(number)
            self.setup = self.worker(prepare, self.attempt)
        if ready and int(ready[1]) == self.attempt and self.attempt not in self.delivering:
            self.delivering.add(self.attempt)
            setup = self.setup
            self.worker(lambda number:self.deliver(number, setup), self.attempt)

    def prepare(self, number):
        helper = self.resources / 'tools/AccountKeychain'
        if not helper.is_file():
            helper = ROOT / 'build-macos/launcher-tools/AccountKeychain'
        result = subprocess.run([str(helper), host_address(self.settings), self.settings['Username']],
                                capture_output=True, timeout=60, check=True)
        password = result.stdout.decode('ascii')
        if not re.fullmatch('[A-Za-z0-9]{15}', password):
            raise ValueError('Saved credential is invalid')
        opener = urllib.request.build_opener(urllib.request.ProxyHandler({}), NoRedirect())
        body = urllib.parse.urlencode({'username': self.settings['Username'], 'password': password}).encode()
        port = int(self.settings['SignupPort'])
        request = urllib.request.Request(f'http://{host_address(self.settings)}:{port}/reweb/signup/create_id.html', body)
        with opener.open(request, timeout=20) as response:
            text = response.read(65537).decode('utf-8', errors='replace')
        if len(text) > 65536 or '<!--AM-USA-COMP-SIGNUP-->' not in text or (
                '<!--INPUT-IDS-->' + self.settings['Username'] + '<!--INPUT-IDE-->') not in text:
            raise ValueError('Server did not confirm registration. If that name is taken, choose another.')
        if self.stop.is_set() or number != self.attempt:return
        self.password = password
        self.publish(f'ready {number}')
        self.report('Network account ready; waiting for the game login screen.')

    def deliver(self, number, setup):
        if setup:
            setup.join()
        if not self.password or self.stop.is_set() or number != self.attempt:
            return
        credential = Path(str(self.status) + '.credential')
        applied = Path(str(self.status) + '.applied')
        applied.unlink(missing_ok=True)
        temporary = credential.with_suffix('.pending')
        fd = os.open(temporary, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600)
        try:
            with os.fdopen(fd, 'wb') as stream:
                stream.write(struct.pack('<III', 0x52454f41, number, 15) + self.password.encode('ascii') + b'\0')
            temporary.replace(credential)
            self.publish(f'input {number}')
            for _ in range(800):
                if self.stop.wait(.025) or number != self.attempt:
                    return
                if applied.is_file() and applied.read_text().strip() == str(number):
                    self.password = None
                    self.publish(f'typed {number}')
                    self.report('Native credential input accepted.')
                    return
            raise TimeoutError('The game did not accept credential input')
        finally:
            temporary.unlink(missing_ok=True)
            credential.unlink(missing_ok=True)

    def close(self):
        self.stop.set()
        for thread in self.threads:
            thread.join(timeout=21)
        self.password = None
        for path in self.status.parent.iterdir():
            path.unlink(missing_ok=True)


class HostedServer:
    def __init__(self, store):
        self.store, self.children, self.files = store, [], []
        self.folder = None
        self.discovery = None
        self.stop = threading.Event()
        self.randomizers = None

    def start(self, settings, report=lambda text: None):
        if self.children:
            raise RuntimeError('The server is already running')
        host = host_address(settings)
        bind = '127.0.0.1' if ipaddress.IPv4Address(host).is_loopback else '0.0.0.0'
        signup, game = int(settings['SignupPort']), int(settings['GamePort'])
        for kind, port in ((socket.SOCK_STREAM, 10127), (socket.SOCK_STREAM, signup),
                           (socket.SOCK_DGRAM, 9090), (socket.SOCK_DGRAM, game), (socket.SOCK_DGRAM, 10129)):
            with socket.socket(socket.AF_INET, kind) as check:
                check.bind((bind, port))
        source = self.store.resources / 'server'
        if not (source / 'run.py').is_file():
            source = ROOT / 'build-macos/opensnap-source'
        if not (source / 'run.py').is_file():
            raise RuntimeError('The bundled openSNAP server is missing')
        self.folder = self.store.home / 'hosted-server'
        self.folder.mkdir(parents=True, exist_ok=True)
        empty = self.folder / 'launcher-empty.env'
        empty.write_text('')
        env = clean_environment()
        values = {'LOG_LEVEL':'info', 'DATA_DIR':str(self.folder), 'STORAGE_BACKEND':'sqlite',
            'SQLITE_PATH':str(self.folder / 'opensnap.db'), 'ENV_FILE':str(empty), 'ENV_DIST_FILE':str(empty),
            'BOOTSTRAP_GAMES':'outbreak', 'GAME_PLUGIN':'outbreak', 'WEB_GAME_PLUGIN':'outbreak',
            'GAME_SERVER_MAP':json.dumps({'outbreak':{'host':host,'port':game}}),
            'BOOTSTRAP_PORT':'9090', 'GAME_PORT':str(game), 'CAPCOM_APP_PORT':'10127', 'WEB_PORT':str(signup),
            'BOOTSTRAP_ADVERTISE_HOST':host, 'GAME_ADVERTISE_HOST':host,
            'WEB_HTTPS_HOST':'', 'WEB_HTTPS_CERTFILE':'', 'WEB_HTTPS_KEYFILE':''}
        for service in ('BOOTSTRAP','GAME','CAPCOM_APP','WEB'):
            values[service + '_HOST'] = bind
        env.update({'OPENSNAP_' + key:value for key,value in values.items()})
        env.update(PYTHONNOUSERSITE='1', PYTHONDONTWRITEBYTECODE='1', PYTHONUNBUFFERED='1', PYTHONPATH=str(source))
        try:
            for name, arguments in [('app',['app','capcom']), ('web',['web','--web-plugin','outbreak']),
                                    ('game',['game']), ('bootstrap',['bootstrap'])]:
                output = (self.folder / (name + '.log')).open('a')
                self.files.append(output)
                command = [sys.executable, '--server-worker', str(source), *arguments] if getattr(sys, 'frozen', False) else [sys.executable, '-u', str(Path(__file__).with_name('main.py')), '--server-worker', str(source), *arguments]
                self.children.append(subprocess.Popen(command, cwd=self.folder, env=env,
                    stdout=output, stderr=subprocess.STDOUT, start_new_session=True))
            deadline = time.monotonic() + 20
            while time.monotonic() < deadline:
                if any(child.poll() is not None for child in self.children):
                    raise RuntimeError(f'An openSNAP service stopped; see {self.folder}')
                try:
                    for port in (10127, signup):
                        with socket.create_connection(('127.0.0.1',port), timeout=.2):
                            pass
                    break
                except OSError:
                    time.sleep(.1)
            else:
                raise TimeoutError('The hosted server did not become ready')
            self.discovery = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.discovery.bind((bind,10129))
            self.discovery.settimeout(.5)
            self.stop.clear()
            self.thread = threading.Thread(target=self.serve, args=(settings,), daemon=True)
            self.thread.start()
            report(f'Hosting openSNAP at {host}. Signup TCP {signup}, app TCP 10127, game UDP {game}, bootstrap UDP 9090.')
        except BaseException:
            self.close()
            raise

    def serve(self, settings):
        last, count = time.monotonic(), 0
        client = self.discovery
        while not self.stop.is_set():
            try:
                packet, peer = client.recvfrom(513)
                if time.monotonic() - last > 1:
                    last, count = time.monotonic(), 0
                count += 1
                if count > 20:
                    continue
                if packet == b'REO-LAN?1':
                    data = {'name':settings['Username'], 'address':settings['CoopHost'], 'version':'1.0.20-rc1-mac',
                            'room':False, 'signup':int(settings['SignupPort']), 'game':'file1', 'title':''}
                    client.sendto(b'REO-LAN!1' + json.dumps(data).encode(), peer)
                elif packet.startswith(b'REO-MODS?3') and len(packet) == len(b'REO-MODS?3') + 16:
                    client.sendto(b'REO-MODS!3' + packet[-16:] + (self.randomizers or b''), peer)
            except socket.timeout:
                pass
            except OSError:
                return

    def close(self):
        self.stop.set()
        if self.discovery:
            self.discovery.close()
            self.discovery = None
        if hasattr(self,'thread'):
            self.thread.join(timeout=1)
        for child in self.children:
            if child.poll() is None:
                try:
                    os.killpg(child.pid, signal.SIGTERM)
                except ProcessLookupError:
                    pass
        for child in self.children:
            try:
                child.wait(timeout=5)
            except subprocess.TimeoutExpired:
                os.killpg(child.pid, signal.SIGKILL)
                child.wait()
        self.children.clear()
        for output in self.files:
            output.close()
        self.files.clear()
        self.randomizers = None


def discover():
    found = {}
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
        client.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        client.settimeout(.2)
        for address in ('255.255.255.255', '127.0.0.1'):
            client.sendto(b'REO-LAN?1', (address,10129))
        deadline = time.monotonic() + 2
        while time.monotonic() < deadline:
            try:
                packet, peer = client.recvfrom(513)
                if len(packet) <= 512 and packet.startswith(b'REO-LAN!1'):
                    value = json.loads(packet[len(b'REO-LAN!1'):])
                    ipaddress.IPv4Address(value['address'])
                    if value.get('game', 'file1') == 'file1':
                        found[value['address']] = value
            except (socket.timeout, ValueError, KeyError, TypeError):
                pass
    return list(found.values())


def host_randomizers(settings, home):
    from mods import installed
    import uuid
    chosen=[manifest for _,manifest,_ in installed(home)
            if manifest and manifest['id'] in settings['EnabledMods']]
    if len(chosen)!=len(settings['EnabledMods']):
        raise ValueError('An enabled mod is missing or invalid')
    config={'protocol':3,'session':uuid.uuid4().hex,'elf':ELF_SHA256,'host':settings['Username'],
            'weapons':None,'items':None,'enemies':None}
    for manifest in chosen:
        if manifest.get('effects') or manifest.get('patches') or settings['CheatsEnabled']:
            raise ValueError('Co-op supports shared randomizers; disable cheats and effect/data-patch mods')
        for key,field in [('weaponShuffle','weapons'),('itemRandomizer','items'),('enemyRandomizer','enemies')]:
            if key in manifest:
                if config[field] is not None:raise ValueError('Select one mod for each randomizer type')
                config[field]=manifest[key]
    return json.dumps(config,separators=(',',':')).encode('utf-8')


def fetch_randomizers(settings):
    nonce=os.urandom(16)
    prefix=b'REO-MODS!3'+nonce
    with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as client:
        client.connect((host_address(settings),10129));client.settimeout(2)
        for _ in range(3):
            client.send(b'REO-MODS?3'+nonce)
            try:
                packet=client.recv(32769)
                if len(packet)>32768 or not packet.startswith(prefix):continue
                if len(packet)==len(prefix):raise ValueError('The host has not launched a game yet')
                return packet[len(prefix):]
            except socket.timeout:pass
    raise TimeoutError('The host did not provide a shared randomizer configuration on UDP 10129')


def shared_randomizer_manifests(packet):
    if len(packet)>32768:raise ValueError('Shared mod configuration is too large')
    value=json.loads(packet)
    if value.get('protocol')!=3 or value.get('elf')!=ELF_SHA256 or not re.fullmatch('[a-fA-F0-9]{32}',value.get('session','')):
        raise ValueError('Incompatible shared mod configuration')
    if not re.fullmatch(r'(?!_)(?!.*__)(?!.*_$)[A-Za-z0-9_]{4,10}',value.get('host','')):
        raise ValueError('Invalid shared mod host')
    manifest={'format':1,'elfSha256':ELF_SHA256,'id':'shared-'+value['session'],'name':'Host randomizers'}
    for field,key in [('weapons','weaponShuffle'),('items','itemRandomizer'),('enemies','enemyRandomizer')]:
        if value.get(field) is not None:
            options=value[field]
            if not isinstance(options,dict) or type(options.get('seed',0)) is not int or not 0<=options.get('seed',0)<=0xffffffff:
                raise ValueError('Invalid shared randomizer seed')
            if key=='itemRandomizer' and options.get('mode','shuffle') not in ('shuffle','global'):
                raise ValueError('Invalid shared item randomizer mode')
            if key=='enemyRandomizer' and options.get('mode','zombieProfiles') not in ('zombieProfiles','enemyTypes'):
                raise ValueError('Invalid shared enemy randomizer mode')
            manifest[key]=options
    return [manifest]
