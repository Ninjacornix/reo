"""Narrow representation relation; never normalize flags, credit or PCM."""
import copy
import json
from pathlib import Path
import unittest
import compare_original as comparison

BASE = comparison.ROOT / 'build-native-sjuni/window2'


class ComparisonPolicyTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        folder = BASE / 'parity-gcc-v1'
        native = [json.loads(s) for s in (folder / 'long-mono-44100.native.jsonl').read_text().splitlines()]
        original = json.loads((folder / 'long-mono-44100.expected.json').read_bytes())
        cls.native = native[30:32]; cls.original = original[30:32]

    def test_exact_original_captures_match_on_both_workers(self):
        gcc = comparison.load(BASE / 'capture-gcc-v1/receipt.json')
        llvm = comparison.load(BASE / 'capture-llvm-v1/receipt.json')
        self.assertEqual(gcc['cases'], llvm['cases'])
        self.assertEqual(len(gcc['cases']), 133)
        self.assertEqual(gcc['original_instructions'], 6801810)
        self.assertTrue(gcc['original_transcripts_unchanged'] and llvm['original_transcripts_unchanged'])

    def test_live_lease_and_delayed_cache_are_explicit_not_raw_abi_parity(self):
        a = copy.deepcopy(self.native); b = copy.deepcopy(self.original)
        before_a, before_b = copy.deepcopy(a), copy.deepcopy(b)
        self.assertNotEqual(a[1]['state']['source'][11:13], b[1]['state']['source'][11:13])
        mismatch, excluded = comparison.compare_records(a, b)
        self.assertIsNone(mismatch)
        self.assertEqual(len(excluded), 1)
        self.assertEqual(excluded[0]['native_live_owned_descriptor'], [0, 744])
        self.assertEqual(excluded[0]['original_pre_copy_cache'], [0, 0])
        self.assertEqual(excluded[0]['measured_acquired_bytes'], 744)
        self.assertEqual(a, before_a); self.assertEqual(b, before_b)

    def test_invented_native_lease_does_not_match_measured_credit(self):
        bad = copy.deepcopy(self.native); bad[1]['state']['source'][12] -= 1
        mismatch, _ = comparison.compare_records(bad, self.original)
        self.assertIn('ownership disagrees', mismatch)

    def test_source_flag_and_progress_changes_are_still_differences(self):
        for field in (2, 6, 7, 8, 9):
            with self.subTest(field=field):
                bad = copy.deepcopy(self.native); bad[1]['state']['source'][field] += 1
                mismatch, _ = comparison.compare_records(bad, self.original)
                self.assertIn('state.source[' + str(field) + ']', mismatch)

    def test_no_arbitrary_original_cache_mask(self):
        bad = copy.deepcopy(self.original); bad[1]['state']['source'][12] = 1
        mismatch, _ = comparison.compare_records(self.native, bad)
        self.assertIn('not the measured pre-Get cache', mismatch)

    def test_pcm_change_remains_a_difference_at_the_same_transfer(self):
        bad = copy.deepcopy(self.native); bad[1]['pcm_backing_sha256'][0] = '0' * 64
        mismatch, _ = comparison.compare_records(bad, self.original)
        self.assertIn('pcm_backing_sha256', mismatch)


if __name__ == '__main__': unittest.main()
