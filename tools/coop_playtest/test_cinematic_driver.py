import unittest

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


if __name__ == '__main__':
    unittest.main()
