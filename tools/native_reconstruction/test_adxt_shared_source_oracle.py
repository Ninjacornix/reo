import hashlib,json,unittest
from pathlib import Path
import adxt_shared_source_oracle as oracle

ROOT=Path(__file__).resolve().parents[2]
OUTPUT=ROOT/'build-native-sjuni/adxt-shared-source-oracle/v3'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
class SharedSourceOracleTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.inputs=json.loads((OUTPUT/'inputs.json').read_bytes())
        cls.expected=json.loads((OUTPUT/'expected.json').read_bytes())
        cls.cases={case['name']:case for case in cls.expected['cases']}
    def test_input_freeze_and_explicit_boundary(self):
        self.assertEqual(sha(OUTPUT/'inputs.json'),'eb358b57da388fcfe54bc0e233c80d64c5cec50223e21dbf5153c685da6da9cd')
        self.assertEqual(sha(OUTPUT/'input-manifest.json'),'8598ffc6894c960be7cc93000821b6b1b252f2007fd6e589de8f4bcb082e8b23')
        self.assertEqual(self.inputs,oracle.corpus_inputs())
        for case in self.inputs['cases']:
            for action in case['actions']:
                if action['kind']=='source':self.assertEqual(action['entry'],0x130b78)
        self.assertNotIn('expected',json.dumps(self.inputs['cases']))
    def test_core_was_frozen_before_new_expected(self):
        path=ROOT/'game/native/adxt_shared_source/frozen_identity.json'
        self.assertEqual(sha(path),'a1eb49209edf71ee13911f556a67be18ae271f658949e2335f33c64fb819f631')
        frozen=json.loads(path.read_bytes());self.assertFalse(frozen['original_source2_expected_seen']);self.assertFalse(frozen['comparator_authored'])
        for name,digest in frozen['files'].items():self.assertEqual(sha(ROOT/name),digest)
    def test_complete_owned_instruction_authority(self):
        self.assertEqual(sha(ROOT/'game_data/SLUS_207.65'),'06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46')
        self.assertEqual(sha(OUTPUT/'expected.json'),'f6ab00eb1f0f88ad35fb3215e826d2f59471e70e4f240289d9f1c05f3a3c6446')
        self.assertEqual(len(self.cases),30)
        self.assertEqual(sum(len(case['rows'])for case in self.cases.values()),133)
        self.assertTrue(all(not case['partial']for case in self.cases.values()))
        self.assertTrue(all(case['original_instructions']>0 for case in self.cases.values()))
        for name,digest in self.expected['engine_sha256'].items():self.assertEqual(sha(ROOT/'tools/native_reconstruction'/name),digest)
        elf=oracle.refill.Elf(ROOT/'game_data/SLUS_207.65')
        for address,body in self.expected['body_sha256'].items():
            start=int(address,16);self.assertEqual(hashlib.sha256(elf.read(start,body['end']-start)).hexdigest(),body['sha256'])
    def test_all_dispositions_and_zero_noops(self):
        plans={a['plan']for c in self.inputs['cases']for a in c['actions']if a['kind']=='finish'}
        self.assertEqual(plans,{'single','first','second','reverse'})
        case=self.cases['both-zero'];self.assertEqual([view['bytes']for view in case['rows'][1]['views']],[0,0])
        self.assertEqual(len(case['rows'][1]['ring_events']),4)
        self.assertEqual(case['rows'][2]['ring_events'],[])
        self.assertEqual(case['rows'][0]['state']['ring'],case['rows'][2]['state']['ring'])
    def test_pending_two_positive_conservation(self):
        case=self.cases['pending-two-positive-full'];row=case['rows'][2]
        self.assertEqual([view['bytes']for view in row['views']],[328,1720])
        self.assertEqual(row['state']['ring'][2:4],[0,0])
        self.assertEqual(row['state']['source'][12],6144)
        self.assertEqual(sum(v['bytes']for v in row['views'])+row['state']['source'][12],8192)
    def test_target_mutates_before_terminal(self):
        enabled=self.cases['physical-end-enabled']['rows'][-1]
        disabled=self.cases['physical-end-disabled']['rows'][-1]
        self.assertEqual(enabled['state']['source'][:4],[2,1,0,2048])
        self.assertEqual(disabled['state']['source'][:4],[3,1,2,2048])
        self.assertEqual(enabled['targets'][0]['before']['source'][:4],[2,1,2,2048])
        self.assertEqual(disabled['targets'][0]['after']['loop'][:2],[-1,0x7fffffff])
        self.assertEqual(disabled['targets'][0]['after']['source'][0],2) # terminal branch has not run.
    def test_current_geometry_and_pending_enable(self):
        changed=self.cases['pending-current-header']['rows'][-1]
        self.assertEqual(changed['state']['source'][2],1)
        self.assertEqual(changed['state']['loop'][3:],[2048,4096,32,64])
        self.assertEqual(self.cases['pending-toggle-off']['rows'][-1]['state']['loop'][:2],[-1,0x7fffffff])
        self.assertEqual(self.cases['pending-toggle-on']['rows'][-1]['state']['source'][2],0)
    def test_prior_raw_refill_failure_preserved(self):
        prior=ROOT/'build-native-sjuni/adxt-shared-source-oracle/v2'
        self.assertEqual(sha(prior/'expected.json'),'aab2da951dea1a66ffebb2a17bcd9a1799f5cbcdfa7050c44022a5e2623471e3')
        self.assertEqual(sha(prior/'oracle-source.py'),'516ac1d92e3882814b92d86a064e698b2e85ac0a67969379aa2a39e0655f8914')
        failure=json.loads((ROOT/'build-native-sjuni/adxt-shared-source-parity/gcc-v1/receipt.json').read_bytes())
        self.assertEqual(failure['status'],'failed');self.assertIn('root.state.source[7]: 0/1',failure['failure'])

if __name__=='__main__':unittest.main()
