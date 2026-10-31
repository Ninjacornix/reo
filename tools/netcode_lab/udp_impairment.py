"""Loopback-only, bidirectional UDP impairment fixture for real co-op clients.

Each client has an independent upstream socket, preserving server-side session
identity. TCP APP/signup traffic is untouched. No packet payloads are recorded.
"""
import argparse
import heapq
import ipaddress
import json
from pathlib import Path
import random
import selectors
import socket
import time
from enemy_blackout import enemy_kinematic_only_unreliable_snap


def profile(value):
    limits = {'rtt_ms': (0, 2000), 'jitter_ms': (0, 1000), 'loss_percent': (0, 50),
              'duplicate_percent': (0, 50), 'reorder_percent': (0, 50)}
    result = {}
    for key, (low, high) in limits.items():
        number = float(value.get(key, 0))
        if not low <= number <= high:
            raise ValueError('Invalid impairment parameter: ' + key)
        result[key] = number
    drop = value.get('drop_unreliable_snap', False)
    if not isinstance(drop, bool):
        raise ValueError('drop_unreliable_snap must be a boolean')
    result['drop_unreliable_snap'] = drop
    enemy = value.get('drop_enemy_kinematic', False)
    if not isinstance(enemy, bool):
        raise ValueError('drop_enemy_kinematic must be a boolean')
    result['drop_enemy_kinematic'] = enemy
    return result


class Proxy:
    def __init__(self, ports, *, seed=27813, settings=None, profile_file=None, stats_file=None, back_host='127.0.0.1'):
        if not ipaddress.IPv4Address(back_host).is_loopback:
            raise ValueError('Impairment fixtures require a loopback backend')
        self.back_host = back_host
        self.selector = selectors.DefaultSelector()
        self.fronts, self.clients, self.queue = [], {}, []
        self.random = random.Random(seed)
        self.settings = profile(settings or {})
        self.profile_file, self.stats_file = profile_file, stats_file
        self.serial = self.sent = self.dropped = self.duplicated = self.queue_dropped = 0
        self.next_report = 0
        self.native_status = {}
        try:
            for front_port, back_port in ports:
                front = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                self.fronts.append(front)
                front.bind(('127.0.0.1', front_port))
                front.setblocking(False)
                self.selector.register(front, selectors.EVENT_READ, ('front', back_port))
        except BaseException:
            self.close()
            raise

    def close(self):
        self.selector.close()
        for sock in self.fronts:
            sock.close()
        for sock in self.clients.values():
            sock.close()

    def schedule(self, destination, payload, address=None):
        if len(payload) == 64 and payload[:6] == b'REO2\x01\x02':
            # Never retain the instance nonce. This is room/feature metadata only.
            u32 = lambda offset: int.from_bytes(payload[offset:offset+4], 'big')
            sid = u32(8)
            if sid in self.native_status or len(self.native_status) < 64:
                self.native_status[sid] = {'session': sid, 'room': u32(12), 'epoch': u32(16),
                                           'features': u32(40), 'mode': u32(44),
                                           'members': [u32(p) for p in (48,52,56,60) if u32(p)]}
        if self.settings['drop_enemy_kinematic'] and enemy_kinematic_only_unreliable_snap(payload):
            self.dropped += 1
            return
        if (self.settings['drop_unreliable_snap'] and len(payload) >= 20 and
                payload[:4] != b'REO2' and payload[3] == 0x0f and not payload[0] & 0x80):
            self.dropped += 1
            return
        if self.random.random() * 100 < self.settings['loss_percent']:
            self.dropped += 1
            return
        delay = max(0, self.settings['rtt_ms'] / 2 + self.random.uniform(-1, 1) * self.settings['jitter_ms']) / 1000
        if self.random.random() * 100 < self.settings['reorder_percent']:
            delay += .075
        self.enqueue(destination, payload, address, delay)
        if self.random.random() * 100 < self.settings['duplicate_percent']:
            self.enqueue(destination, payload, address, delay + .02)
            self.duplicated += 1

    def enqueue(self, destination, payload, address, delay):
        if len(self.queue) >= 4096:
            self.queue_dropped += 1
            return
        self.serial += 1
        heapq.heappush(self.queue, (time.monotonic() + delay, self.serial, destination, payload, address))

    def step(self, timeout=.05):
        now = time.monotonic()
        if self.queue:
            timeout = min(timeout, max(0, self.queue[0][0] - now))
        for key, _ in self.selector.select(timeout):
            role, target = key.data
            try:
                payload, source = key.fileobj.recvfrom(65536)
            except (BlockingIOError, ConnectionResetError):
                continue
            if role == 'front':
                identity = (key.fileobj, source)
                if identity not in self.clients:
                    if len(self.clients) >= 64:
                        continue
                    upstream = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                    upstream.bind(('127.0.0.1', 0))
                    upstream.connect((self.back_host, target))
                    upstream.setblocking(False)
                    self.clients[identity] = upstream
                    self.selector.register(upstream, selectors.EVENT_READ, ('back', identity))
                self.schedule(self.clients[identity], payload)
            else:
                front, client = target
                self.schedule(front, payload, client)
        now = time.monotonic()
        while self.queue and self.queue[0][0] <= now:
            _, _, sock, payload, address = heapq.heappop(self.queue)
            try:
                if address is None:
                    sock.send(payload)
                else:
                    sock.sendto(payload, address)
                self.sent += 1
            except (BlockingIOError, ConnectionResetError):
                self.queue_dropped += 1
        if now >= self.next_report:
            self.next_report = now + 1
            if self.profile_file and Path(self.profile_file).exists():
                self.settings = profile(json.loads(Path(self.profile_file).read_text()))
            if self.stats_file:
                with Path(self.stats_file).open('a', encoding='utf-8') as stream:
                    stream.write(json.dumps({'t': now, 'settings': self.settings, 'forwarded': self.sent,
                                             'dropped': self.dropped, 'duplicated': self.duplicated,
                                             'queue_dropped': self.queue_dropped, 'queued': len(self.queue),
                                             'clients': len(self.clients),
                                             'native_status': list(self.native_status.values())}) + '\n')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--port', action='append', required=True, metavar='FRONT:BACK')
    parser.add_argument('--profile', type=Path)
    parser.add_argument('--stats', type=Path)
    parser.add_argument('--back-host', default='127.0.0.1')
    parser.add_argument('--seconds', type=float, default=1800)
    args = parser.parse_args()
    ports = [tuple(map(int, p.split(':'))) for p in args.port]
    if any(len(p) != 2 or any(n < 1 or n > 65535 for n in p) for p in ports):
        parser.error('Ports must be FRONT:BACK, each 1..65535')
    if not 0 < args.seconds <= 7200:
        parser.error('Use a bounded duration of 1..7200 seconds')
    proxy = Proxy(ports, profile_file=args.profile, stats_file=args.stats, back_host=args.back_host)
    try:
        deadline = time.monotonic() + args.seconds
        while time.monotonic() < deadline:
            proxy.step()
    finally:
        proxy.close()


if __name__ == '__main__':
    main()
