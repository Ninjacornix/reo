"""Start the four openSNAP services on loopback, mirroring launcher/HostedServer.cs."""
import json, os, subprocess, sys, time
root = r'C:\Users\Ninjacornix\reo'
game = sys.argv[1]  # file1|file2
data = os.path.abspath(sys.argv[2])
plugin = 'outbreak' if game == 'file1' else 'outbreak2'
python = os.path.join(root, r'build-ninja\coop-research\openSNAP\.venv\Scripts\python.exe')
source = os.path.join(root, r'build-ninja\hybrid\package-preview5\network-server\source')
os.makedirs(data, exist_ok=True)
for f in ('launcher-empty.env', 'launcher-empty.dist'):
    open(os.path.join(data, f), 'a').close()
host = '127.0.0.1'
pids = []
for args in (['app', 'capcom'], ['web', '--web-plugin', plugin], ['game'], ['bootstrap']):
    env = {k: v for k, v in os.environ.items() if not k.upper().startswith(('OPENSNAP_', 'PYTHON'))}
    env.update({
        'PYTHONPATH': source, 'PYTHONNOUSERSITE': '1', 'PYTHONDONTWRITEBYTECODE': '1',
        'OPENSNAP_LOG_LEVEL': 'info',
        'OPENSNAP_ENV_FILE': os.path.join(data, 'launcher-empty.env'),
        'OPENSNAP_ENV_DIST_FILE': os.path.join(data, 'launcher-empty.dist'),
        'OPENSNAP_DATA_DIR': os.path.join(source, 'data'),
        'OPENSNAP_STORAGE_BACKEND': 'sqlite', 'OPENSNAP_SQLITE_PATH': os.path.join(data, 'opensnap.db'),
        'OPENSNAP_WEB_HTTPS_HOST': '', 'OPENSNAP_WEB_HTTPS_CERTFILE': '', 'OPENSNAP_WEB_HTTPS_KEYFILE': '',
        'OPENSNAP_BOOTSTRAP_ADVERTISE_HOST': host, 'OPENSNAP_GAME_ADVERTISE_HOST': host,
        'OPENSNAP_BOOTSTRAP_PORT': '9090', 'OPENSNAP_GAME_PORT': '9091',
        'OPENSNAP_CAPCOM_APP_PORT': '10127', 'OPENSNAP_WEB_PORT': '10128',
        'OPENSNAP_BOOTSTRAP_HOST': host, 'OPENSNAP_GAME_HOST': host, 'OPENSNAP_CAPCOM_APP_HOST': host,
        'OPENSNAP_WEB_HOST': host, 'OPENSNAP_BOOTSTRAP_GAMES': plugin, 'OPENSNAP_GAME_PLUGIN': plugin,
        'OPENSNAP_WEB_GAME_PLUGIN': plugin,
        'OPENSNAP_GAME_SERVER_MAP': json.dumps({plugin: {'host': host, 'port': 9091}}),
    })
    if args[0] == 'game':
        env['OPENSNAP_NATIVE_METRICS_FILE'] = os.path.join(data, 'network-metrics.jsonl')
    out = open(os.path.join(data, args[0] + '-stdout.log'), 'w')
    err = open(os.path.join(data, args[0] + '-stderr.log'), 'w')
    p = subprocess.Popen([python, '-u', os.path.join(source, 'run.py')] + args, cwd=data, env=env,
                         stdout=out, stderr=err, creationflags=0x08000000)
    pids.append(p.pid)
json.dump(pids, open(os.path.join(data, 'pids.json'), 'w'))
time.sleep(6)
print('pids', pids)
for name in ('app', 'web', 'game', 'bootstrap'):
    t = open(os.path.join(data, name + '-stderr.log')).read().strip().splitlines()
    print(name, t[-1][:160] if t else '(empty)')
