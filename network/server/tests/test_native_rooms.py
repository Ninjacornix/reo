# SPDX-License-Identifier: AGPL-3.0-only
"""Integration checks against real upstream authentication, room and scenario handlers.

Run with the patched server source and pinned upstream tests on PYTHONPATH.
"""
import struct
import unittest

from opensnap.protocol import commands
from opensnap.protocol.models import Endpoint
from reo_native.protocol import (
    CAPABILITIES, ENHANCED, HEADER, HELLO, HELLO_BODY, LEGACY, MOTION, MOTION_BODY,
    NativeRooms, STATUS_BODY, packet,
    WORLD_DIGEST, WORLD_REQUEST, CAP_BATCH, CAP_MOTION,
)
from tests import test_outbreak_plugin as file1
from tests import test_outbreak2_plugin as file2


class Checks:
    game = 1

    def setUp(self):
        self.fixture = file1.OutbreakEngineHarness() if self.game == 1 else file2.Outbreak2LobbyTests()
        self.fixture.setUp()
        self.addCleanup(self.fixture.doCleanups)
        self.engine = self.fixture.engine
        self.now = 100.0
        self.native = NativeRooms(self.engine, clock=lambda: self.now)
        self.host, self.guest, self.outsider = self.fixture.players
        self.room = self.fixture._create_room(self.host)
        self.fixture._send(self.guest, commands.CMD_JOIN, file1._join_payload(self.room))
        self.native.observe()
        self.epoch = self.native.rooms[self.room].epoch

    def hello(self, player, ack=True, capabilities=CAPABILITIES):
        endpoint, sid = player
        self.now += .2
        return self.native.handle(packet(HELLO, sid, self.room, self.epoch, 1, 1000000,
                                        HELLO_BODY.pack(sid, capabilities, self.epoch if ack else 0)), endpoint)

    def start(self):
        self.fixture._send(self.host, commands.CMD_CHANGE_ATTRIBUTE, b'STAT' + struct.pack('>L', 0x40000000))
        self.fixture._send(self.host, commands.CMD_CHANGE_USER_STATUS, struct.pack('>L', 1))
        self.native.observe()

    def motion(self, player, sequence=1, slot=0, epoch=None, **kwargs):
        endpoint, sid = player
        return self.native.handle(packet(MOTION, sid, self.room, self.epoch if epoch is None else epoch,
                                        sequence, 1000000+sequence*50000,
                                        MOTION_BODY.pack(slot, 0, 10, kwargs.get('x', 1), 2, 3, 0)), endpoint)

    def test_all_native_agreement_and_authenticated_relay(self):
        self.hello(self.host)
        self.hello(self.guest)
        self.start()
        self.assertEqual(self.native.rooms[self.room].mode, ENHANCED)
        response = self.hello(self.host)
        self.assertEqual(STATUS_BODY.unpack(response[0][1][HEADER.size:])[2], ENHANCED)
        forwarded = self.motion(self.host)
        self.assertEqual([p[0] for p in forwarded], [self.guest[0]])
        self.assertEqual(HEADER.unpack_from(forwarded[0][1])[4], self.host[1])
        self.assertEqual(self.motion(self.host), [])  # duplicate
        self.assertEqual(self.motion(self.host, sequence=0), [])  # reordered
        self.assertEqual(self.motion(self.host, sequence=2, epoch=self.epoch+1), [])
        self.assertEqual(self.motion(self.guest, slot=0), [])  # actor ownership conflict
        self.assertEqual(len(self.motion(self.guest, slot=1)), 1)

    def test_legacy_member_forces_entire_room_to_legacy(self):
        self.hello(self.host)
        self.start()
        self.assertEqual(self.native.rooms[self.room].mode, LEGACY)
        self.hello(self.guest)  # no mid-game upgrade
        self.assertEqual(self.native.rooms[self.room].mode, LEGACY)
        self.assertEqual(self.motion(self.host), [])

    def test_missing_epoch_ack_and_expired_capability_force_legacy(self):
        self.hello(self.host)
        self.hello(self.guest, ack=False)
        self.start()
        self.assertEqual(self.native.rooms[self.room].mode, LEGACY)

    def test_wrong_endpoint_sid_and_nonmember_cannot_inject(self):
        self.hello(self.host); self.hello(self.guest); self.start()
        valid = packet(MOTION, self.host[1], self.room, self.epoch, 2, 1000000,
                       MOTION_BODY.pack(0, 0, 10, 1, 2, 3, 0))
        self.assertEqual(self.native.handle(valid, self.guest[0]), [])
        self.assertEqual(self.native.handle(valid, Endpoint(host=self.host[0].host, port=9999)), [])
        self.assertEqual(self.motion(self.outsider), [])
        self.assertEqual(self.motion(self.host, x=float('nan')), [])
        for size in range(4, len(valid)):
            self.assertEqual(self.native.handle(valid[:size], self.host[0]), [])
        self.assertIsNone(self.native.handle(b'original snap packet', self.host[0]))

    def test_membership_change_invalidates_old_agreement(self):
        self.hello(self.host); self.hello(self.guest)
        self.fixture._send(self.outsider, commands.CMD_JOIN, file1._join_payload(self.room))
        self.native.observe()
        self.assertNotEqual(self.native.rooms[self.room].epoch, self.epoch)
        self.start()
        self.assertEqual(self.native.rooms[self.room].mode, LEGACY)

    def test_client_timeout_and_session_removal_stop_native_delivery(self):
        self.hello(self.host); self.hello(self.guest); self.start()
        self.now += 6
        self.assertEqual(self.motion(self.host), [])
        self.engine._sessions.remove(self.guest[1])
        self.native.observe()
        self.assertNotIn(self.guest[1], self.native.peers)

    def test_sequence_wrap_and_rate_limit(self):
        self.hello(self.host); self.hello(self.guest); self.start()
        self.assertEqual(len(self.motion(self.host, sequence=0xffffffff)), 1)
        self.assertEqual(len(self.motion(self.host, sequence=0)), 1)
        self.assertEqual(self.motion(self.host, sequence=0xffffffff), [])
        sent = sum(bool(self.motion(self.host, sequence=i)) for i in range(1, 100))
        self.assertLessEqual(sent, 38)

    def test_world_digest_and_requests_follow_authenticated_actor_authority(self):
        self.hello(self.host); self.hello(self.guest); self.start()
        self.motion(self.host, slot=0); self.motion(self.guest, slot=1)
        digest = struct.pack('!HBBQHH', 10, 0, 0, 0x1234567812345678, 4, 0)
        def send(player, kind, body, seq):
            return self.native.handle(packet(kind, player[1], self.room, self.epoch, seq, 1000000, body), player[0])
        self.assertEqual([v[0] for v in send(self.host, WORLD_DIGEST, digest, 2)], [self.guest[0]])
        self.assertEqual(send(self.guest, WORLD_DIGEST, digest, 2), [])
        request = struct.pack('!HBB', 10, 0, 0)
        self.assertEqual([v[0] for v in send(self.guest, WORLD_REQUEST, request, 3)], [self.host[0]])
        self.assertEqual(send(self.guest, WORLD_REQUEST, request, 4), [])  # bounded requests
        self.assertEqual(send(self.outsider, WORLD_REQUEST, request, 5), [])
        self.assertEqual(send(self.host, WORLD_DIGEST, digest[:-1], 5), [])

    def test_older_native_capability_cannot_enable_world_refresh(self):
        self.hello(self.host)
        self.hello(self.guest, capabilities=CAP_BATCH | CAP_MOTION)
        self.start()
        self.motion(self.host, slot=0)
        digest = struct.pack('!HBBQHH', 10, 0, 0, 1, 4, 0)
        result = self.native.handle(packet(WORLD_DIGEST, self.host[1], self.room, self.epoch, 2, 0, digest), self.host[0])
        self.assertEqual(result, [])

    def test_authenticated_nonce_preserves_session_during_nat_port_rebinding(self):
        self.hello(self.host); self.hello(self.guest); self.start()
        moved = Endpoint(host=self.host[0].host, port=self.host[0].port+1)
        sid = self.host[1]
        bad = packet(HELLO, sid, self.room, self.epoch, 2, 0, HELLO_BODY.pack(sid+1, CAPABILITIES, self.epoch))
        self.assertEqual(self.native.handle(bad, moved), [])
        good = packet(HELLO, sid, self.room, self.epoch, 3, 0, HELLO_BODY.pack(sid, CAPABILITIES, self.epoch))
        self.now += .5
        self.assertEqual(self.native.handle(good, moved)[0][0], moved)
        self.assertEqual(self.engine._sessions.get(sid).endpoint, moved)
        self.assertEqual(self.native.take_endpoint_moves(), [(self.host[0], moved, sid)])
        self.assertEqual(self.native.take_endpoint_moves(), [])
        self.assertEqual(self.native.rooms[self.room].mode, ENHANCED)
        foreign = Endpoint(host='10.9.9.9', port=moved.port)
        self.assertEqual(self.native.handle(good, foreign), [])
        self.native.restart(sid)
        self.assertNotIn(sid, self.native.peers)
        self.assertEqual(self.native.rooms[self.room].mode, LEGACY)
        self.assertNotEqual(self.native.rooms[self.room].epoch, self.epoch)

    def test_current_room_zero_roster_survives_server_upgrade(self):
        rows = self.fixture._send(self.host, commands.CMD_QUERY_USER, struct.pack('>L', 0))
        roster = [r for r in rows if r.command == commands.CMD_QUERY_USER]
        self.assertTrue(roster)
        self.assertEqual(struct.unpack_from('>3L', roster[0].payload), (0, 2, 2))
        outside = self.fixture._send(self.outsider, commands.CMD_QUERY_USER, struct.pack('>L', 0))
        empty = [r for r in outside if r.command == commands.CMD_QUERY_USER]
        self.assertEqual(struct.unpack_from('>3L', empty[0].payload), (0, 0, 0))

    def test_original_header_that_coincides_with_native_magic_is_preserved(self):
        original = b'REO2' + bytes(577) + bytes.fromhex('ba476611')
        self.assertEqual(len(original), 585)  # word 0x5245 carries original length 581
        self.assertIsNone(self.native.handle(original, self.host[0]))


class File1Checks(Checks, unittest.TestCase):
    game = 1


class File2Checks(Checks, unittest.TestCase):
    game = 2


if __name__ == '__main__':
    unittest.main()
