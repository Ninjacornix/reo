import unittest
from unittest import mock
import json
from pathlib import Path
import struct
import tempfile

import cinematic_driver
from cinematic_driver import confirmable


class CinematicInputAdmission(unittest.TestCase):
    def test_stale_menu_state_cannot_send_input_during_playback_or_gameplay(self):
        for phase in (2, 14):
            for state in (0x109, 0x30A, 0x50B):
                self.assertFalse(confirmable(phase, state, 0))

    def test_only_known_idle_character_and_confirmation_states_admitted(self):
        self.assertTrue(confirmable(13, 0x109, 0))
        self.assertFalse(confirmable(13, 0x109, 1))
        for state in (None, 0, 0x108, 0x10A, 0x50C):
            self.assertFalse(confirmable(13, state, 0))

    def test_observer_reaches_play_without_any_movie_log(self):
        # Exercise actual driver transitions and controller writes. A large or
        # unavailable diagnostics log must not participate in this control loop.
        class Clock:
            value = 0
            def now(self):
                self.value += 0.25
                return self.value
        class Reader:
            step = 0
            def __init__(self, *args): pass
            def check(self): pass
            def close(self): pass
            def read(self, address, size):
                if address == 0x4BADD0:
                    phase = (0,14,2)[min(self.step,2)]
                    self.step += 1
                    return bytes([phase])+bytes(size-1)
                if address == 0x32442C:
                    return struct.pack('<I',0x900000)
                if address == 0x900000:
                    block = bytearray(size)
                    struct.pack_into('<I',block,4,0x109)
                    return bytes(block)
                raise AssertionError('Unexpected observer address')
        with tempfile.TemporaryDirectory() as temporary:
            folder = Path(temporary)
            image = str(folder/'private.exe')
            identity = dict(pid=123,image=image,creationFileTime=456)
            player = dict(image=image,inputFile=str(folder/'input.json'),logs=str(folder/'missing-logs'))
            record = dict(game='file1',players=[player],elf='owned-elf',sourceSha256='a'*64)
            (folder/'run.json').write_text(json.dumps(dict(players=[dict(**identity,
                environment={'REO_TEST_ROUTE':'character'})])))
            clock = Clock()
            with mock.patch.object(cinematic_driver.harness,'session_record',return_value=(folder,record)), \
                 mock.patch.object(cinematic_driver.harness,'process_identity',return_value=identity), \
                 mock.patch.object(cinematic_driver,'GuestRam',Reader), \
                 mock.patch.object(cinematic_driver.time,'monotonic',side_effect=clock.now), \
                 mock.patch.object(cinematic_driver.time,'sleep'):
                result = cinematic_driver.drive(folder,timeout=20)
            self.assertTrue(result['cinematic_observed'])
            self.assertTrue(result['gameplay_observed'])
            self.assertEqual([row['button'] for row in result['inputs']],['cross'])
            self.assertEqual(result['skip_inputs'],0)
            self.assertFalse((folder/'missing-logs').exists())


if __name__ == '__main__':
    unittest.main()
