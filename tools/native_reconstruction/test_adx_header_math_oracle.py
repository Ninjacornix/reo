"""Pinned runtime raw-bit FP compatibility and complete bounded header replay."""
import json
from pathlib import Path
import struct
import unittest

import adx_header_math_oracle as m

BASE=m.ROOT/'build-native-sjuni/adx-header-math-oracle-v4'
FIXTURES={'gcc':'7ffa76de4fe5aa56e4825c1a4a25ed591d5dfefe0331807848498974707a7158',
          'llvm':'0e2b3fd61fdcad1fe4f6f7fb479165dc6fe706bf12427e5533787371ed8d0d8f'}
MICROS={'gcc':'505e34926ec478464ca87abe03d231d77f6b7ba6d48910b1d0919337a9b4322f',
        'llvm':'e1e58a04f30f161eab3cda501545024e37a635b7d9d9df43abdc1f0dbcbd4744'}
INPUT_SHA='ab304db5087b8c476b3e818c60d35da2fbaa9915161b71f6d0615391de0fc843'

def raw(row,field):return bytes.fromhex(row['result']['after'][field])

class MathTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.fixtures={};cls.micros={}
        for name,digest in FIXTURES.items():
            data=(BASE/name/'original-fixture.json').read_bytes()
            if m.sha(data)!=digest:raise AssertionError('Frozen math/header evidence changed')
            cls.fixtures[name]=json.loads(data)
            data=(BASE/name/'micro-qualification.json').read_bytes()
            if m.sha(data)!=MICROS[name]:raise AssertionError('Frozen FP qualification changed')
            cls.micros[name]=json.loads(data)
        cls.fixture=cls.fixtures['gcc'];cls.rows={row['name']:row for row in cls.fixture['cases']}
        cls.inputs=json.loads((BASE/'gcc/inputs.json').read_bytes())
    def test_frozen_inputs_current_sources_and_worker_emission(self):
        self.assertEqual(m.sha(m.serialized(m.corpus_inputs())),INPUT_SHA)
        self.assertNotIn('"expected":',json.dumps(self.inputs))
        statements=m.reference_statements();worker=m.worker_source(statements)
        for name,fixture in self.fixtures.items():
            self.assertEqual(fixture['inputs_sha256'],INPUT_SHA)
            self.assertEqual(fixture['fp_emission'],statements)
            emitted=BASE/name/'fp_worker.cpp'
            self.assertEqual(emitted.read_text(),worker)
            self.assertEqual(m.sha(emitted.read_bytes()),fixture['compatibility']['worker_source_sha256'])
            self.assertEqual(m.sha((BASE/name/'fp_worker.exe').read_bytes()),fixture['compatibility']['worker_binary_sha256'])
            for path,digest in fixture['engine_sha256'].items():self.assertEqual(m.sha(Path(m.__file__).with_name(path).read_bytes()),digest)
    def test_all_raw_microcases_replay_exact_reference_under_both_compilers(self):
        for name in FIXTURES:
            with self.subTest(compiler=name),m.FpuWorker(BASE/name/'fp_worker.exe') as worker:
                self.assertEqual(m.qualify(worker,self.inputs),self.micros[name])
                self.assertEqual(worker.environment,{'host_round':0,'mxcsr':0x1F80})
    def test_all_original_functions_and_header_states_replay_exactly(self):
        for name in FIXTURES:
            fixture=self.fixtures[name]
            with self.subTest(compiler=name),m.FpuWorker(BASE/name/'fp_worker.exe') as worker:
                for inputs,expected in zip(self.inputs['cases'],fixture['cases'],strict=True):
                    with self.subTest(case=inputs['name']):self.assertEqual(m.execute_case(inputs,worker),expected)
        self.assertEqual(self.fixtures['gcc']['cases'],self.fixtures['llvm']['cases'])
    def test_complete_source_word_and_new_math_audit(self):
        self.assertEqual(m.header.source_audit(m.SOURCE),self.fixture['source_word_audit'])
        self.assertEqual(m.math_source_audit(),self.fixture['math_source_word_audit'])
        self.assertEqual(self.fixture['source_word_audit']['matched_comments'],1802)
        self.assertEqual(self.fixture['math_source_word_audit']['matched_comments'],134)
        self.assertEqual(len(self.fixture['math_source_word_audit']['omitted_zero_pcs']),3)
        self.assertEqual(self.fixture['summary']['qualified_unique_fp_words'],70)
        self.assertEqual(self.fixture['summary']['micro_cases'],1975)
    def test_every_reached_instruction_family_is_covered_by_owned_emission(self):
        families=set()
        for row in self.fixture['fp_emission']['instructions']:
            word=row['word_u32'];op=word>>26;rs=(word>>21)&31
            families.add((op,rs if op==0x11 else 0,(word&63) if op==0x11 and rs in (16,20) else ((word>>16)&3) if rs==8 else 0))
        self.assertEqual(len(families),16)
        for case in self.inputs['micro_cases']:
            self.assertIn(case['word_u32'],set(m.fp_words().values()))
            self.assertTrue(all(isinstance(v,int) for v in case['fpr_u32']))
    def test_positive_finite_whole_math_outputs_and_fpr_callee_restore(self):
        for name,expected in [('math-24000-500',(6687,-2729)),('math-44100-500',(7334,-3283)),('math-48000-500',(7400,-3342))]:
            row=self.rows[name];result=row['result']
            self.assertEqual(result['status'],'returned')
            self.assertEqual(struct.unpack_from('<2h',raw(row,'helper_output_hex')),expected)
            self.assertEqual(result['fp_before']['fpr_u32'][20:23],result['fp_after']['fpr_u32'][20:23])
            self.assertIn(0x120F68,row['visited_pcs'])
            self.assertNotIn(0x120AE8,row['visited_pcs']);self.assertNotIn(0x122708,row['visited_pcs'])
    def test_real_successful_tag0_header_publishes_consumed_prefix(self):
        for name in ('outer-valid-mono-COP1-open','outer-valid-stereo-v4-COP1-open','outer-fallback-key-COP1-open',
                     'outer-configured-key-COP1-open','outer-derived-key-COP1-open'):
            row=self.rows[name];outer=raw(row,'outer_hex');inner=raw(row,'inner_hex');predictor=raw(row,'predictor_hex')
            self.assertEqual(row['result']['status'],'returned')
            self.assertEqual(outer[1],2);self.assertEqual(int.from_bytes(outer[0x98:0x9C],'little'),96)
            self.assertEqual(row['result']['after']['ring_u32'][3:5],[0,2048])
            self.assertEqual(struct.unpack_from('<2h',predictor,0x30),(7334,-3283))
            self.assertEqual(int.from_bytes(inner[0x98:0x9A],'little'),0)
            self.assertEqual(int.from_bytes(inner[0x8C:0x90],'little'),0)
            names=[e['name'] for e in row['result']['events'] if e['kind']=='original_entry']
            self.assertLess(names.index('coefficient_math'),names.index('install_history'))
            self.assertLess(names.index('install_history'),names.index('loop'));self.assertLess(names.index('loop'),names.index('ainf'))
        stereo=self.rows['outer-valid-stereo-v4-COP1-open']
        self.assertEqual(struct.unpack_from('<4H',raw(stereo,'predictor_hex'),0x28),(0x1234,0xFEDC,0x5678,0xBA98))
        self.assertEqual(struct.unpack_from('<6I',raw(stereo,'inner_hex'),0x50),(2,18,32,0x410010,8192,8288))
    def test_complete_wrapped_defer_keeps_selective_configuration(self):
        row=self.rows['outer-wrap-short-first-span'];outer=raw(row,'outer_hex')
        self.assertEqual(row['result']['status'],'returned');self.assertEqual(outer[1],1)
        self.assertEqual(row['result']['before']['ring_u32'],row['result']['after']['ring_u32'])
        self.assertEqual(outer[0x98:0x9C],bytes([0x5A])*4)
        self.assertEqual(struct.unpack_from('<2h',raw(row,'predictor_hex'),0x30),(7334,-3283))
    def test_full_header_other_rates_and_loop_ainf_metadata(self):
        for rate,expected in [(24000,(6687,-2729)),(48000,(7400,-3342))]:
            row=self.rows[f'outer-mono-{rate}-500']
            self.assertEqual(row['result']['status'],'returned');self.assertEqual(raw(row,'outer_hex')[1],2)
            self.assertEqual(struct.unpack_from('<2h',raw(row,'predictor_hex'),0x30),expected)
        row=self.rows['outer-v4-complete-loop-metadata'];inner=raw(row,'inner_hex')
        self.assertEqual(raw(row,'outer_hex')[1],2)
        self.assertEqual(struct.unpack_from('<I',inner,0x20)[0],1)
        self.assertEqual(struct.unpack_from('<H',inner,0x24)[0],1)
        self.assertEqual(struct.unpack_from('<4I',inner,0x28),(32,114,64,132))
        row=self.rows['outer-v4-complete-AINF-metadata'];inner=raw(row,'inner_hex')
        self.assertEqual(raw(row,'outer_hex')[1],2)
        self.assertEqual(struct.unpack_from('<I',inner,0xC8)[0],0x12345678)
        self.assertEqual(inner[0xCC:0xDC],bytes(range(16)))
        self.assertEqual(struct.unpack_from('<3H',inner,0xDC),(0xFEDC,0x3344,0x5566))
    def test_partial_range_and_zero_rate_remain_refused_without_fake_callee(self):
        self.assertEqual(self.fixture['summary']['cases'],48);self.assertEqual(self.fixture['summary']['returned'],45)
        for partial in self.fixture['summary']['partial']:
            self.assertEqual(partial['pc'],0x120AE8);self.assertIsNone(partial['word_u32'])
            row=self.rows[partial['name']];self.assertEqual(row['result']['status'],'partial_refusal')
            if row['kind']=='math':self.assertEqual(raw(row,'helper_output_hex')[:4],bytes([0x5A])*4)
        zero=self.rows['outer-zero-rate-COP1-open']
        self.assertEqual(raw(zero,'outer_hex')[1],1);self.assertEqual(zero['result']['after']['ring_u32'][3:5],[0,1952])
    def test_malformed_zero_bits_return_is_not_native_format_admission(self):
        row=self.rows['outer-zero-bits-COP1-open']
        self.assertEqual(row['result']['status'],'returned');self.assertEqual(raw(row,'outer_hex')[1],2)
        self.assertEqual(struct.unpack_from('<I',raw(row,'inner_hex'),0x58)[0],0)
    def test_cvt_fixed_truncation_fcr_and_all_host_round_modes(self):
        cases=self.inputs['micro_cases'];rows=self.micros['gcc'];selected={}
        for case,row in zip(cases,rows,strict=True):
            word=case['word_u32']
            if word==0x46001024:
                selected.setdefault((case['fpr_u32'][2],case['fcr31']),[]).append(row['raw_result']['fpr'][0])
        self.assertEqual(set(map(len,selected.values())),{4})
        for outputs in selected.values():self.assertEqual(len(set(outputs)),1)
        by_value={key[0]:value[0] for key,value in selected.items()}
        self.assertEqual(by_value[0x3FC00000],1);self.assertEqual(by_value[0xBFC00000],0xFFFFFFFF)
        self.assertEqual(by_value[0x4F000000],0x7FFFFFFF);self.assertEqual(by_value[0xCF000000],0x80000000)
        self.assertEqual(by_value[0x7FC12345],0x7FFFFFFF)
    def test_mfc1_uses_actual_sign_extending_gpr_macro(self):
        for case,row in zip(self.inputs['micro_cases'],self.micros['gcc'],strict=True):
            if case['word_u32']==0x44020000 and case['fpr_u32'][0]==0x80000000:
                self.assertEqual(row['raw_result']['regs'][2],0xFFFFFFFF80000000);return
        self.fail('Missing actual MFC1 signed-word vector')
    def test_snan_crosscompiler_difference_is_retained_not_normalized(self):
        changed=[]
        for a,b,case in zip(self.micros['gcc'],self.micros['llvm'],self.inputs['micro_cases'],strict=True):
            if a!=b:
                word=case['word_u32'];changed.append(word);fd=(word>>6)&31
                self.assertEqual(a['raw_result']['fpr'][fd],0x7FE12345)
                self.assertEqual(b['raw_result']['fpr'][fd],0x7FA12345)
        self.assertEqual(sorted(changed),[0x460C0004,0x46160504])
    def test_fp_branch_delay_and_likely_annul_use_actual_raw_operations(self):
        with m.FpuWorker(BASE/'gcc/fp_worker.exe') as worker:
            for word in (0x45010004,0x45030004):
                for taken in (False,True):
                    inputs=self.inputs['cases'][0].copy();inputs['fcr31']=0x800000 if taken else 0
                    machine=m.Machine(inputs,worker);machine.prepare();machine.fpr[0]=0x3F000000;machine.fpr[21]=0x40000000
                    machine.code={0x1000:word,0x1004:0x4600A801,0x1008:0x03E00008,0x100C:0,0x1014:0x03E00008,0x1018:0}
                    result=machine.run(0x1000)
                    self.assertEqual(result['status'],'returned')
                    executes=taken or word==0x45010004
                    self.assertEqual(machine.fpr[0],0x3FC00000 if executes else 0x3F000000)
                    self.assertEqual(0x1004 in result['visited_pcs'],executes)
    def test_unqualified_fp_instruction_refuses_without_mutation(self):
        with m.FpuWorker(BASE/'gcc/fp_worker.exe') as worker:
            machine=m.Machine(self.inputs['cases'][0],worker)
            before=(machine.fpr.copy(),machine.fcr31,machine.regs.copy())
            with self.assertRaisesRegex(m.OracleError,'Unqualified FP word'):machine.instruction(0x1000,0x46010404)
            self.assertEqual((machine.fpr,machine.fcr31,machine.regs),before)

if __name__=='__main__':unittest.main()
