"""File #2 reader isolation and bounded profile propagation checks."""
import json
from pathlib import Path
import struct
import tempfile
import unittest

import coop_playtest as harness
import lobby_driver as lobby
from test_lobby_driver import snapshot
from test_login_driver import Clock


class File2LobbyTests(unittest.TestCase):
    def reader(self):
        segments = {
            0x58D000: bytearray(struct.pack('<II', 0x336F574D, 4)),
            0x6E2ED0: bytearray(0xA00), 0x6E293E: bytearray(struct.pack('<HHH', 1, 0, 1)),
            0x6DEAA0: bytearray(0x15C), 0x8AA5D8: bytearray([1]),
            0x64C160: bytearray(4), 0x6B53F2: bytearray(16), 0x6B547A: bytearray([2]),
            0x6E9490: bytearray([37]), 0x6E9491: bytearray([7]),
            0x6A9848: bytearray([3]), 0x6A9849: bytearray([0]), 0x64C148: bytearray([0])}
        segments[0x6E2ED0][0] = 3
        segments[0x6E2ED0][0xE] = 1
        segments[0x6E2ED0][0x41A] = 1
        segments[0x6DEAA0][0xE] = 1
        ram = object.__new__(lobby.GuestRam)
        ram.game = 'file2'
        ram.check = lambda: None
        def read(address, size):
            self.assertIn(address, segments, f'Unexpected address {address:X}; possible File #1 read')
            self.assertEqual(len(segments[address]), size)
            return bytes(segments[address])
        ram.read = read
        return ram, segments

    def test_reader_isolates_edition_and_preserves_count_width(self):
        ram, segments = self.reader()
        state = ram.snapshot()
        self.assertEqual(state['serverCount'], 1)
        self.assertEqual(state['serverRows'], [])
        self.assertEqual(state['rooms'][0]['kind'], 1)
        self.assertEqual(state['serverControllerSub'], 0)
        segments[0x6E293E][4] = 129
        with self.assertRaisesRegex(ValueError, 'verified bounds'):
            ram.snapshot()
        segments[0x58D000][4] = 3
        with self.assertRaisesRegex(ValueError, 'overlay'):
            ram.snapshot()

    def test_server_confirm_requires_all_verified_idle_gates(self):
        state = snapshot(mainMode=7, serverCount=1, serverRows=[], serverControllerSub=0)
        def plan(s):
            return lobby.plan(1, s, {}, goal='waiting-room', host_waiting=False, game='file2')
        self.assertEqual(plan(state)[:2], ('button', 'cross'))
        for key, value in [('serverCount', 2), ('serverCount', 0), ('serverControllerSub', 1),
                           ('serverWidgetSub', 1), ('cursor', 1), ('chat', True), ('mainMode', 9)]:
            self.assertEqual(plan(dict(state, **{key: value}))[0], 'wait', key)
        del state['serverControllerSub']
        self.assertEqual(plan(state)[0], 'wait')

    def test_file2_difficulty_area_precedes_scenario_list(self):
        for cursor, button in [(0, 'cross'), (4, 'up'), (9, 'left')]:
            state = snapshot(state=1, menu=1, phase=2, cursor=cursor, areaCount=0)
            self.assertEqual(lobby.plan(1, state, {}, goal='waiting-room', host_waiting=False, game='file2')[:2],
                             ('button', button))
            self.assertEqual(lobby.plan(1, state, {}, goal='waiting-room', host_waiting=False)[0], 'wait')

    def test_file2_title_editor_can_be_observed_after_one_frame_warmup(self):
        state = snapshot(state=3, menu=3, phase=3, nested=2)
        context = {}
        def plan(s):
            return lobby.plan(1, s, context, goal='waiting-room', host_waiting=False, game='file2')
        self.assertEqual(plan(state)[0], 'wait')
        self.assertEqual(plan(state)[:2], ('text', 'cooptest'))
        self.assertEqual(plan(dict(state, keyboardComplete=1))[0], 'wait')
        self.assertEqual(plan(state)[0], 'wait')
        self.assertEqual(plan(dict(state, title='existing'))[0], 'refuse')

    def test_manifest_profile_reaches_reader_and_planner_without_claiming_gameplay(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            identity = dict(number=1, pid=123, image=str(folder/'game.exe'), creationFileTime=45)
            harness.save(folder/'run.json', {'players': [identity]})
            record = dict(game='file2', elf='unused', players=[dict(number=1, image=identity['image'], logs=str(folder))])
            calls = []
            class Reader:
                def __init__(self, *args): pass
                def snapshot(self):
                    if self.game != 'file2':
                        raise AssertionError('Profile was not propagated to reader')
                    return snapshot(mainMode=7, serverCount=1, serverRows=[], serverControllerSub=0)
                def close(self): pass
            clock = Clock()
            result = lobby.drive(folder, record, timeout=1, reader_factory=Reader,
                identity_reader=lambda pid: {k: identity[k] for k in ('pid','image','creationFileTime')},
                pad_writer=lambda player, button: calls.append(button), monotonic=clock.read, sleeper=clock.sleep)
            self.assertTrue(calls)
            self.assertEqual(set(calls), {'cross'})
            self.assertEqual(result['game'], 'file2')
            self.assertEqual(result['coopVerdict'], 'not-tested')
            self.assertFalse(result['hostStartSent'])
            self.assertEqual(result['driverVerdict'], 'incomplete')
