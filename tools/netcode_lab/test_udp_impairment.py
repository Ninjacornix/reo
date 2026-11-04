"""Real sockets verify return routing, independent client identities and loss."""
import socket
import time
import unittest
from udp_impairment import Proxy, profile


class ImpairmentTests(unittest.TestCase):
    def test_bidirectional_real_udp_and_per_client_identity(self):
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server:
            server.bind(('127.0.0.1', 0)); server.setblocking(False)
            proxy = Proxy([(0, server.getsockname()[1])], settings={'rtt_ms': 20})
            self.addCleanup(proxy.close)
            clients = [socket.socket(socket.AF_INET, socket.SOCK_DGRAM) for _ in range(2)]
            for i, client in enumerate(clients):
                self.addCleanup(client.close)
                client.setblocking(False)
                client.sendto(bytes([i]), proxy.fronts[0].getsockname())
            peers, replies = set(), {}
            until = time.monotonic() + 2
            while time.monotonic() < until and len(replies) < 2:
                proxy.step(.005)
                try:
                    payload, peer = server.recvfrom(100)
                    peers.add(peer); server.sendto(payload + b'reply', peer)
                except BlockingIOError:
                    pass
                for i, client in enumerate(clients):
                    try:
                        payload, _ = client.recvfrom(100); replies[i] = payload
                    except BlockingIOError:
                        pass
            self.assertEqual(len(peers), 2)
            self.assertEqual(replies, {0: b'\0reply', 1: b'\1reply'})
            self.assertEqual(proxy.queue_dropped, 0)
            self.assertEqual(proxy.traffic['up']['original'],
                             {'packets': 2, 'payload_bytes': 2, 'ipv4_bytes': 58})
            self.assertEqual(proxy.traffic['down']['original'],
                             {'packets': 2, 'payload_bytes': 12, 'ipv4_bytes': 68})

    def test_byte_counts_classify_without_retaining_payloads(self):
        proxy = Proxy([])
        self.addCleanup(proxy.close)
        for kind, category, size in [(1, 'native_hello', 48), (2, 'native_status', 64),
                                     (3, 'native_motion', 50), (6, 'native_world_digest', 48),
                                     (7, 'native_world_request', 36)]:
            frame = b'REO2\x01' + bytes([kind]) + b'x' * (size - 6)
            proxy.observe_traffic('up', frame)
            self.assertEqual(proxy.traffic['up'][category],
                             {'packets': 1, 'payload_bytes': size, 'ipv4_bytes': size + 28})
        self.assertNotIn('xxxx', repr(proxy.traffic))

    def test_profile_rejects_nan_and_invalid_rates(self):
        for settings in [{'loss_percent': 100}, {'rtt_ms': -1}, {'jitter_ms': float('nan')}, {'drop_unreliable_snap': 'yes'}]:
            with self.assertRaises(ValueError):
                profile(settings)


if __name__ == '__main__':
    unittest.main()
