import copy
import json
import os
from pathlib import Path
import shutil
import unittest

import pcm_order_oracle as oracle


class OriginalOrderEvidence(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        compilers = {
            'gcc':'C:/msys64/mingw64/bin/g++.exe',
            'llvm':str(Path(os.environ.get('LOCALAPPDATA',''))/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')}
        cls.corpora = {}
        for name,compiler in compilers.items():
            if not shutil.which(compiler):
                continue
            output = oracle.ROOT/'build-native-sjuni/pcm-order-oracle/tests'/name
            proof = oracle.generate(oracle.ROOT/'build-native-sjuni/dependency-workers-reapply-v2',compiler,output)
            fixture = json.loads((output/'fixtures.json').read_text(encoding='utf-8'))
            cls.corpora[name] = proof,fixture
        if not cls.corpora:
            raise unittest.SkipTest('Existing checked GCC/LLVM toolchain required')

    def test_exact_source_identity_and_complete_input_observations(self):
        for proof,fixture in self.corpora.values():
            self.assertEqual(proof['status'],'passed')
            self.assertFalse(proof['game_run'])
            self.assertFalse(proof['device_opened'])
            self.assertEqual(fixture['schema'],2)
            self.assertEqual(oracle.validate(fixture['records'],fixture['inputs'])['snapshots'],49)

    def test_three_term_real_outputs_depend_on_order(self):
        for _,fixture in self.corpora.values():
            rows = fixture['records'][:6]
            self.assertEqual(len({tuple(r['declared_raw_order']) for r in rows}),6)
            self.assertEqual({r['float_bits'][0] for r in rows},{0x35000000,0x34A3D70A})
            for row in rows:
                self.assertEqual(row['gain_read_order'],row['declared_raw_order'])
                self.assertEqual(len(row['float_bits']),4)

    def test_reconfigure_erase_and_reset_observed_order(self):
        for _,fixture in self.corpora.values():
            rows = {r['operation']:r for r in fixture['records'] if r['case']=='mutations'}
            self.assertEqual(rows['inserted']['declared_raw_order'],rows['reconfigure_existing']['declared_raw_order'])
            self.assertEqual(rows['erase_middle']['declared_raw_order'],[key for key in rows['inserted']['declared_raw_order'] if key!=20])
            self.assertEqual(rows['reinsert_middle']['declared_raw_order'][0],20)
            self.assertEqual(rows['reset_empty']['declared_raw_order'],[])
            self.assertEqual(rows['reset_empty']['bucket_count'],rows['draining_record']['bucket_count'])

    def test_paused_record_still_has_gain_but_no_consumption(self):
        for _,fixture in self.corpora.values():
            rows = {r['operation']:r for r in fixture['records'] if r['case']=='mutations'}
            before = next(c for c in rows['reinsert_middle']['channels'] if c['key']==1020)
            after = next(c for c in rows['paused_record']['channels'] if c['key']==1020)
            self.assertEqual(before,after)
            self.assertIn(20,rows['paused_record']['gain_read_order'])
            self.assertFalse(next(v for v in rows['paused_record']['voices'] if v['key']==20)['playing'])

    def test_rehash_observed_without_assuming_portable_bucket_policy(self):
        for _,fixture in self.corpora.values():
            rows = [r for r in fixture['records'] if r['case']=='rehash' and r['operation']=='insert']
            self.assertGreater(len({r['bucket_count'] for r in rows}),1)
            self.assertEqual(set(rows[-1]['declared_raw_order']),set(range(100,132)))
            self.assertEqual(rows[-1]['float_bits'],[])
            self.assertTrue(all(c['consumed']==0 for c in rows[-1]['channels']))

    def test_malformed_or_mispaired_evidence_rejected(self):
        _,fixture = next(iter(self.corpora.values()))
        bad = copy.deepcopy(fixture['records'])
        bad[0]['gain_read_order'].reverse()
        with self.assertRaises(ValueError):
            oracle.validate(bad,fixture['inputs'])
        bad = copy.deepcopy(fixture['inputs'])
        bad[0]['actions'][-1]['frames'] = 3
        with self.assertRaises(ValueError):
            oracle.validate(fixture['records'],bad)


if __name__ == '__main__':
    unittest.main()
