import tempfile
import unittest
from pathlib import Path

from compile_game import MSVC_FLAGS, PORTABLE_DEFAULTS, source_flags
from prepare_audio_output import instrument, prepare


class AudioOutputBuildTests(unittest.TestCase):
    SOURCE = """// upstream license remains here
void InitAudioDevice(void)
{
    config.playback.pDeviceID = NULL;  // NULL for the default playback AUDIO.System.device
    result = ma_device_init(&AUDIO.System.context, &config, &AUDIO.System.device);
}
"""

    def test_transform_preserves_other_code_and_fails_on_changed_calls(self):
        result = instrument(self.SOURCE)
        self.assertIn('// upstream license remains here', result)
        self.assertIn('reoAudioOutputDevice(&AUDIO.System.context, &reoOutputId)', result)
        self.assertIn('reoAudioInitDevice(&AUDIO.System.context, &config, &AUDIO.System.device)', result)
        with self.assertRaises(ValueError):
            instrument(self.SOURCE.replace('ma_device_init(', 'different_init('))
        with self.assertRaises(ValueError):
            instrument(self.SOURCE + self.SOURCE)

    def test_staging_is_source_preserving_and_does_not_force_rebuild(self):
        with tempfile.TemporaryDirectory() as temporary:
            original = Path(temporary) / 'raudio.c'
            staged = Path(temporary) / 'staged.c'
            original.write_text(self.SOURCE)
            prepare(original, staged)
            before = staged.stat().st_mtime_ns
            prepare(original, staged)
            self.assertEqual(staged.stat().st_mtime_ns, before)
            self.assertEqual(original.read_text(), self.SOURCE)

    def test_c_provider_uses_c11_and_preserves_existing_cpp_flags(self):
        self.assertIs(source_flags(False), MSVC_FLAGS)
        self.assertIs(source_flags(False, portable=True), PORTABLE_DEFAULTS)
        self.assertIn('/TC', source_flags(True))
        self.assertNotIn('/TP', source_flags(True))
        self.assertNotIn('/std:c++20', source_flags(True))
        self.assertIn('-std=c11', source_flags(True, portable=True))
        self.assertNotIn('-std=c++20', source_flags(True, portable=True))


if __name__ == '__main__':
    unittest.main()
