import tempfile
import unittest
from pathlib import Path

import coop_playtest as harness


class NativeDiagnosticsTests(unittest.TestCase):
    def classify(self, stderr):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            (path / 'stdout.log').write_text('', encoding='utf-8')
            (path / 'stderr.log').write_text(stderr, encoding='utf-8')
            return harness.classify_native_logs(path)

    def test_admission_refusal_remains_failure_after_joined_shutdown(self):
        result = self.classify(
            '[NATIVE-ADXT] ordinary-file binding selected entries=17\n'
            '[NATIVE-ADXT-REFUSAL] boundary=loop-pan-pitch-profile address=0020f550 status=0\n'
            '[NATIVE-AUDIO-REPORT] owner_joined=1 native_sources=1 source_joined=1\n'
            '[run] exiting loop, activeThreads=0\n')
        self.assertTrue(result['fatal'])
        self.assertEqual(result['fatalLineCount'], 1)
        self.assertEqual(result['findings'][0]['line'], 2)
        self.assertEqual(result['findings'][0]['categories'], ['native-media-admission-refused'])

    def test_post_selection_fatal_is_a_failure(self):
        result = self.classify('[NATIVE-ADXT-FATAL] selected factory omitted order capability\n')
        self.assertTrue(result['fatal'])
        self.assertEqual(result['findings'][0]['categories'], ['native-media-failure'])

    def test_native_movie_refusal_is_failure_even_with_zero_exit_and_join(self):
        result = self.classify(
            '[NATIVE-HOST-MOVIE-REFUSAL] boundary=unprepared-archive-cue address=000001a3\n'
            'Error during program execution: Native movie game boundary refused\n'
            '[NATIVE-HOST-MOVIE-REPORT] joined=1 sources=0 delivered_frames=0 error=none\n')
        self.assertTrue(result['fatal'])
        self.assertEqual(result['fatalLineCount'], 2)
        self.assertEqual(harness.native_outcome(0, result), 'fatal-diagnostic')

    def test_installation_and_clean_retirement_are_not_refusals(self):
        result = self.classify(
            '[NATIVE-ADXT] ordinary-file binding selected entries=17\n'
            '[NATIVE-AUDIO-REPORT] owner_joined=1 native_sources=1 source_joined=1\n')
        self.assertFalse(result['fatal'])
        self.assertEqual(result['findings'], [])


if __name__ == '__main__':
    unittest.main()
