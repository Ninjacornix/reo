"""Identity, lifecycle and measured physical effects of the new original corpus."""
import json
from pathlib import Path
import struct
import unittest

import adx_window_v2_oracle as oracle

ROOT = oracle.ROOT
BASE = ROOT / 'build-native-sjuni/adx-window-v2-oracle'


def load(path):
    return json.loads(path.read_bytes())


def changed_offsets(effect):
    return {i - 16 for change in effect['changes']
            for i in range(change['offset'], change['offset'] + len(bytes.fromhex(change['after_hex'])))}


class Window2OriginalTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.frozen = BASE / 'frozen-v3'
        cls.manifest = load(cls.frozen / 'input-manifest.json')
        cls.inputs = load(cls.frozen / 'inputs.json')['cases']
        cls.gcc = load(BASE / 'gcc-v2/manifest.json')
        cls.llvm = load(BASE / 'llvm-v2/manifest.json')

    def row(self, name, cohort='gcc-v2'):
        return load(BASE / cohort / (name + '.json'))

    def test_frozen_inputs_source_engines_and_actual_authority(self):
        self.assertEqual(oracle.sha((self.frozen / 'inputs.json').read_bytes()), self.manifest['inputs_sha256'])
        self.assertEqual(oracle.sha(Path(oracle.__file__).read_bytes()), self.manifest['oracle_sha256'])
        self.assertEqual((self.frozen / 'oracle-source.py').read_bytes(), Path(oracle.__file__).read_bytes())
        self.assertEqual(oracle.authority()[1], self.manifest['authority'])
        for name, digest in self.manifest['engines'].items():
            self.assertEqual(oracle.sha(Path(oracle.__file__).with_name(name).read_bytes()), digest)

    def test_complete_transcripts_match_across_exact_compiler_workers(self):
        self.assertEqual(self.gcc['cases'], self.llvm['cases'])
        self.assertEqual(self.gcc['summary'], self.llvm['summary'])
        self.assertEqual(self.gcc['summary']['cases'], 133)
        self.assertEqual(self.gcc['summary']['original_instructions'], 6801810)
        for cohort, manifest in [('gcc-v2', self.gcc), ('llvm-v2', self.llvm)]:
            self.assertFalse(manifest['game_run'])
            self.assertFalse(manifest['native_window2_executed'])
            self.assertEqual(manifest['input_manifest_sha256'], oracle.sha((self.frozen / 'input-manifest.json').read_bytes()))
            for row in manifest['cases']:
                self.assertEqual(oracle.sha((BASE / cohort / (row['name'] + '.json')).read_bytes()), row['sha256'])

    def test_source_actions_use_complete_lifecycle_and_explicit_normal_or_error_inputs(self):
        sources = [a for c in self.inputs for a in c['actions'] if a['kind'] == 'source']
        self.assertTrue(sources)
        self.assertTrue(all(a['entry'] == 0x130b78 for a in sources))
        self.assertTrue(any(a['statuses'][0] == 3 for a in sources))
        self.assertTrue(all(a['statuses'][1] == 2 for a in sources if a['statuses'][0] != 3))
        # Old authored I/O errors and their actual early terminal results remain.
        old = load(BASE / 'frozen-v2/inputs.json')['cases']
        self.assertTrue(any(a['statuses'] == [1, 3] for c in old for a in c['actions'] if a['kind'] == 'source'))
        for cohort in ['gcc-v1', 'llvm-v1']:
            self.assertEqual(struct.unpack_from('<I', bytes.fromhex(self.row('long-mono-44100', cohort)['final']['outer_hex']), 0x2c)[0], 14368)

    def test_long_streams_reach_actual_terminal_state_without_teleporting_counters(self):
        for name in ['long-mono-44100', 'long-stereo-48000', 'long-downmix-24000']:
            row = self.row(name)
            outer = bytes.fromhex(row['final']['outer_hex'])
            source = bytes.fromhex(row['final']['source_hex'])
            self.assertEqual(struct.unpack_from('<I', outer, 0x2c)[0], 40017)
            self.assertEqual(struct.unpack_from('<I', outer, 0x34)[0], 40017)
            self.assertEqual(outer[1], 3)
            self.assertEqual(source[1], 3)
            self.assertIn(0x130b78, row['visited_pcs'])
            self.assertIn(0x130800, row['visited_pcs'])

    def test_sub_block_free_space_backpressures_without_pcm_changes(self):
        cases = [c for c in self.inputs if c['name'].startswith('pcm-tail-') and c['name'].endswith(('-free-2', '-free-30', '-free-32', '-free-62'))]
        self.assertEqual(len(cases), 60)
        for case in cases:
            result = self.row(case['name'])['operations'][-1]['results']
            self.assertEqual(result['status'], 'returned')
            self.assertFalse(any(t['name'] == 'predictor_service' for t in result['traces']))
            self.assertTrue(all(not e['changes'] for e in result['backing_effects'][1:]))
            self.assertEqual(result['before']['rings'][1:], result['after']['rings'][1:])

    def test_partial_final_block_preserves_unpublished_extension_effects(self):
        result = self.row('pcm-tail-stereo-total-33-free-96')['operations'][-1]['results']
        codec = [t for t in result['traces'] if t['name'] == 'normal_stereo']
        self.assertEqual(len(codec), 1)
        self.assertEqual(codec[0]['arguments_u64'][1], 4)  # Two complete stereo groups.
        callbacks = [e for e in result['events'] if e['kind'] == 'pcm_callback']
        self.assertEqual([e['arguments_u64'][3] for e in callbacks], [66, 66])
        for effect, before, after in zip(result['backing_effects'][1:], result['before']['rings'][1:], result['after']['rings'][1:], strict=True):
            offsets = changed_offsets(effect)
            self.assertEqual((before[3], before[4], before[5]), (16288, 96, 16288))
            self.assertEqual((after[3], after[4], after[5]), (16354, 30, 16354))
            self.assertTrue(offsets & set(range(16384, 16416)))
            self.assertTrue(offsets <= set(range(16288, 16416)))
            self.assertFalse(offsets & set(range(16288)))

    def test_asymmetric_original_probe_changes_queued_right_bytes(self):
        result = self.row('pcm-asymmetric-free-64-32')['operations'][-1]['results']
        before = result['before']['rings'][2]
        self.assertEqual((before[3], before[4], before[5]), (16352, 32, 16352))
        changed = changed_offsets(result['backing_effects'][2])
        self.assertTrue(changed & set(range(16320, 16352)))
        self.assertEqual(result['failure'], None)
        self.assertFalse(any(e['kind'] == 'error_callback' for e in result['events']))

    def test_four_unowned_or_invalid_cases_remain_partial(self):
        self.assertEqual({r['name'] for r in self.gcc['summary']['partials']}, {
            'seamless-negative-record-length', 'seamless-next-header-math-cut',
            'repeat-without-file-disabled', 'ready-insufficient-channel-cut'})
        for row in self.gcc['summary']['partials']:
            self.assertIsNotNone(row['failure'])


if __name__ == '__main__':
    unittest.main()
