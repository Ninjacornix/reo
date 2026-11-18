"""Frozen actual-word/FP evidence checks; no native estimated clock or game."""
import json
from contextlib import contextmanager
import os
from pathlib import Path
import unittest
import oracle

BASE=oracle.ROOT/'build-native-sjuni/adxt-estimated-clock'


class EstimatedClockTests(unittest.TestCase):
    @contextmanager
    def worker(self,name):
        receipt=json.loads((BASE/name/'receipt.json').read_bytes())
        previous=os.environ.get('PATH','')
        os.environ['PATH']=str(Path(receipt['compiler']).parent)+os.pathsep+previous
        try:
            with oracle.prior_fp.FpuWorker(BASE/name/'fp_worker.exe')as worker:yield worker
        finally:os.environ['PATH']=previous

    @classmethod
    def setUpClass(cls):
        cls.identity=json.loads((BASE/'frozen-v1/input-manifest.json').read_bytes())
        cls.inputs=json.loads((BASE/'frozen-v1/inputs.json').read_bytes())
        cls.rows={name:json.loads((BASE/name/'expected.json').read_bytes())for name in('gcc-v1','llvm-v1')}
        cls.by_name={r['name']:r for r in cls.rows['gcc-v1']}

    def test_frozen_inputs_and_complete_source_authority(self):
        self.assertEqual(oracle.authority(),self.identity['authority'])
        self.assertEqual(oracle.statements(),self.identity['emission'])
        self.assertEqual(oracle.sha(Path(oracle.__file__).read_bytes()),self.identity['oracle_sha256'])
        self.assertEqual(oracle.sha((BASE/'frozen-v1/inputs.json').read_bytes()),self.identity['inputs_sha256'])
        self.assertEqual(self.inputs,oracle.inputs(self.identity['emission']))
        for name,digest in self.identity['engines'].items():
            self.assertEqual(oracle.sha((oracle.HERE.parent/name).read_bytes()),digest)

    def test_literal_workers_and_current_receipts(self):
        for name in self.rows:
            r=json.loads((BASE/name/'receipt.json').read_bytes())
            self.assertEqual(r['source_postcheck'],[])
            self.assertEqual(r['inputs_sha256'],self.identity['inputs_sha256'])
            for filename,digest in r['outputs'].items():self.assertEqual(oracle.sha((BASE/name/filename).read_bytes()),digest)
            self.assertEqual(oracle.sha((BASE/name/'fp_worker.exe').read_bytes()),r['worker_binary_sha256'])
            self.assertEqual(oracle.sha((BASE/name/'fp_worker.cpp').read_bytes()),r['worker_cpp_sha256'])
        self.assertEqual(self.rows['gcc-v1'],self.rows['llvm-v1'])
        self.assertEqual((BASE/'gcc-v1/micro-qualification.json').read_bytes(),(BASE/'llvm-v1/micro-qualification.json').read_bytes())

    def test_all_original_transcripts_replay_with_each_worker(self):
        for name,expected in self.rows.items():
            with self.subTest(compiler=name),self.worker(name)as worker:
                for case,row in zip(self.inputs['cases'],expected,strict=True):
                    with self.subTest(case=case['name']):self.assertEqual(oracle.replay_case(case,worker,self.identity),row)

    def test_all_micro_steps_match_actual_emission_and_retained_literal(self):
        for name in self.rows:
            expected=json.loads((BASE/name/'micro-qualification.json').read_bytes())
            with self.subTest(compiler=name),self.worker(name)as worker:
                for i,(case,row)in enumerate(zip(self.inputs['micro_cases'],expected,strict=True)):
                    values=[case[k]for k in('word_u32','fcr31','regs','fpr_u32','memory_u32')]
                    a=worker.step(*values,mode=0,rounding=case['host_rounding'])
                    b=worker.step(*values,mode=1,rounding=case['host_rounding'])
                    self.assertEqual(a,b,i);self.assertEqual(a,row['literal_result'],i)

    def test_rounding_at_nominal_threshold_is_not_normalized(self):
        plus=self.by_name['drift-nominal-60-rebase-0']['operations'][0]['projection']
        minus=self.by_name['drift-nominal--60-rebase-0']['operations'][0]['projection']
        self.assertEqual(plus['drift_bits_u32'],0x42700001) # 60 + one float ULP.
        self.assertEqual(plus['estimate_base_u32'],1000)
        self.assertEqual(plus['output_u32'],940) # Publishes pre-rebase estimate.
        self.assertEqual(minus['drift_bits_u32'],0xc26ffff1) # Magnitude below 60.
        self.assertEqual(minus['estimate_base_u32'],1060)

    def test_recursive_resync_and_counter_wrap(self):
        row=self.by_name['counter-wrap-mode-1']['operations'][0]
        self.assertEqual(row['projection']['counter_u32'],0)
        self.assertEqual(row['projection']['mode_u32'],1)
        self.assertIn(0x132148,row['result']['visited_pcs'])
        self.assertIn(0x132028,row['result']['visited_pcs'])

    def test_pause_resume_keeps_distinct_clock_and_rna_fields(self):
        rows=self.by_name['pause-resume-tick-sequence']['operations']
        self.assertEqual([r['projection']['paused_byte']for r in rows],[1,1,1,0,0,0])
        self.assertEqual(rows[0]['projection']['estimate_base_u32'],6002)
        self.assertEqual(rows[3]['projection']['tick_base_u32'],150)
        self.assertEqual(rows[3]['projection']['rna_play_byte'],1)
        self.assertEqual(rows[4]['projection']['output_u32'],6119)

    def test_service_cut_and_zero_divisors_are_literal_observations(self):
        operations=[r for row in self.rows['gcc-v1']for r in row['operations']]
        partial=[r for r in operations if r['result']['failure']]
        self.assertEqual(len(operations),136);self.assertEqual(len(partial),1)
        self.assertEqual(partial[0]['result']['failure']['pc'],0x12d678)
        self.assertEqual(self.by_name['discard-busy-guard-0']['operations'][0]['result']['status'],'returned')
        zero=self.by_name['zero-denominators-0-6000']['operations'][0]
        self.assertEqual(zero['result']['status'],'returned')
        self.assertEqual(zero['projection']['drift_bits_u32'],0x7f800000)


if __name__=='__main__':unittest.main()
