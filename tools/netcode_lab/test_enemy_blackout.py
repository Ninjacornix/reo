# SPDX-License-Identifier: GPL-3.0-only
"""Synthetic framing boundaries preserve all unrelated and critical traffic."""
import struct
import unittest
from enemy_blackout import (
    FOOTERS, KINEMATIC_LENGTHS, classify_enemy_blackout,
    enemy_kinematic_only_unreliable_snap,
)


def record(kind=0x29, group=8, mode=2):
    size = KINEMATIC_LENGTHS.get(kind, 6)
    app = bytes([kind, size, 1, 3]) + bytes(size - 4)
    header = struct.pack('<HBBIHBB', group, mode, size + 12, 22, group, kind, 0)
    data = header + app
    return data + bytes((-len(data)) % 4)


def batch(*records):
    data = b''.join(records)
    return struct.pack('<H', len(data) | 0x1000) + data


def snap(body, flags=0x2000, command=15, ack=0):
    return struct.pack('>HHIII', flags | (len(body) + 16), command, 3, 5, ack) + body


def wire(*messages):
    return b''.join(messages) + FOOTERS[0]


class EnemyBlackoutTests(unittest.TestCase):
    def test_verified_kinematic_variants(self):
        for kind in KINEMATIC_LENGTHS:
            with self.subTest(kind=kind):
                self.assertTrue(enemy_kinematic_only_unreliable_snap(wire(snap(batch(record(kind))))))

    def test_checks_every_batch_and_outer_message(self):
        data = wire(snap(batch(record()) + batch(record(2))), snap(batch(record(0x2D))))
        self.assertEqual(classify_enemy_blackout(data), (True, 'enemy-kinematic-only', 3))

    def test_stale_ack_word_without_response_flag_is_not_ack(self):
        self.assertTrue(enemy_kinematic_only_unreliable_snap(wire(snap(batch(record()), ack=123))))

    def test_preserves_ack_reliable_multi_and_other_contexts(self):
        for flags in (0x6000, 0xA000, 0x2800, 0x2400, 0x3000, 0x0200):
            with self.subTest(flags=flags):
                self.assertFalse(enemy_kinematic_only_unreliable_snap(wire(snap(batch(record()), flags))))

    def test_preserves_mixed_groups_in_any_batch(self):
        for group in (1, 4, 5, 6, 7, 9):
            with self.subTest(group=group):
                self.assertFalse(enemy_kinematic_only_unreliable_snap(
                    wire(snap(batch(record(), record(group=group))))))
        self.assertFalse(enemy_kinematic_only_unreliable_snap(
            wire(snap(batch(record()) + batch(record(group=5))))))

    def test_preserves_critical_unknown_reliable_and_heartbeat_records(self):
        for kind in (0, 8, 9, 0x32, 0x33, 0x36, 0x54, 0x55, 0x59, 0xFF):
            with self.subTest(kind=kind):
                self.assertFalse(enemy_kinematic_only_unreliable_snap(wire(snap(batch(record(kind))))))
        self.assertFalse(enemy_kinematic_only_unreliable_snap(wire(snap(batch(record(mode=4))))))
        self.assertFalse(enemy_kinematic_only_unreliable_snap(wire(snap(batch()))))

    def test_rejects_truncation_and_corrupted_length_or_identity(self):
        good = wire(snap(batch(record())))
        for size in range(len(good)):
            self.assertFalse(enemy_kinematic_only_unreliable_snap(good[:size]), size)
        for address, value in ((1, 0), (16, 0xFF), (17, 0xFF), (21, 0xFF),
                               (28, 0xFF), (30, 0xFF), (31, 0xFF)):
            bad = bytearray(good)
            bad[address] = value
            self.assertFalse(enemy_kinematic_only_unreliable_snap(bad), address)


if __name__ == '__main__':
    unittest.main()
