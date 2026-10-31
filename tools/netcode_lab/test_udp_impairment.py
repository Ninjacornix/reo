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

    def test_profile_rejects_nan_and_invalid_rates(self):
        for settings in [{'loss_percent': 100}, {'rtt_ms': -1}, {'jitter_ms': float('nan')}, {'drop_unreliable_snap': 'yes'}]:
            with self.assertRaises(ValueError):
                profile(settings)


if __name__ == '__main__':
    unittest.main()
