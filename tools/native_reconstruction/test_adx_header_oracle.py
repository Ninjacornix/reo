"""Integer/header partial evidence checks; no FPU or native algorithm imports."""
import json
from pathlib import Path
import struct
import unittest

import adx_header_oracle as h

FIXTURE=h.ROOT/'build-native-sjuni/adx-header-oracle-v1/original-fixture.json'
FIXTURE_SHA='0e14d00464193c3585c377c8e38118b127bb38257030bc95cc13d3c9188f2d60'
INPUT_SHA='a643baf7e599a25f403d9b7fa986aa6669566b08228f7b73f4b02cfe1d427eaa'

def raw(row,field,after=True):return bytes.fromhex(row['result']['after' if after else 'before'][field])
def output(row):return raw(row,'helper_output_hex')
def entries(row):return [e for e in row['result']['events'] if e['kind']=='original_entry']

class HeaderTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        data=FIXTURE.read_bytes()
        if h.sha(data)!=FIXTURE_SHA:raise AssertionError('Frozen original header evidence changed')
        cls.fixture=json.loads(data);cls.rows={r['name']:r for r in cls.fixture['cases']}
        cls.inputs=json.loads((h.ROOT/cls.fixture['inputs_file']).read_bytes())
    def case(self,name):return self.rows[name]
    def test_frozen_authored_inputs_engines_and_exact_replay(self):
        self.assertEqual(h.sha(h.serialized(h.corpus_inputs())),INPUT_SHA)
        self.assertNotIn('expected',json.dumps(self.inputs))
        self.assertEqual(self.fixture['inputs_sha256'],INPUT_SHA)
        for name,digest in self.fixture['engine_sha256'].items():self.assertEqual(h.sha(Path(h.__file__).with_name(name).read_bytes()),digest)
        for case in self.inputs['cases']:
            with self.subTest(case=case['name']):self.assertEqual(h.execute_case(case),self.rows[case['name']])
    def test_whole_owned_source_word_audit(self):
        actual=h.source_audit(h.ROOT/'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
        self.assertEqual(actual,self.fixture['source_word_audit'])
        self.assertEqual(actual['matched_comments'],1802);self.assertEqual(len(actual['omitted_zero_pcs']),26)
        self.assertEqual(self.fixture['summary']['original_instructions'],16082)
    def test_exact_partial_boundary_no_success_claim(self):
        partial=self.fixture['summary']['partial'];self.assertEqual(len(partial),8)
        for row in partial:
            self.assertEqual((row['pc'],row['word_u32'],row['type']),(0x126514,0xE7B60038,'UnknownInstruction'))
            result=self.case(row['name'])
            self.assertEqual(result['completion_claim'],'partial_not_completed')
            self.assertFalse(result['result']['return_is_defined'])
            self.assertNotIn(0x126518,result['result']['visited_pcs'])
        self.assertEqual(self.fixture['summary']['returned'],31)
    def test_short_outer_returns_real_entire_data_grant(self):
        for length in (0,1,15,16,19):
            row=self.case(f'outer-short-{length}');before=row['result']['before'];after=row['result']['after']
            self.assertEqual(after['ring_u32'],before['ring_u32'])
            self.assertEqual(raw(row,'outer_hex')[1],1)
            self.assertFalse(row['result']['return_is_defined'])
            if length<16:self.assertEqual(raw(row,'inner_hex'),raw(row,'inner_hex',False))
            else:
                self.assertEqual(int.from_bytes(raw(row,'inner_hex')[2:4],'little'),1)
                self.assertEqual(int.from_bytes(raw(row,'inner_hex')[0x14:0x18],'little'),44100)
    def test_rejection_returns_borrow_and_sets_outer_error(self):
        for name in ('outer-bad-magic','outer-reject-ahx-without-plugin'):
            row=self.case(name)
            self.assertEqual(row['result']['after']['ring_u32'],row['result']['before']['ring_u32'])
            self.assertEqual(raw(row,'outer_hex')[1],4)
            self.assertTrue(any(e['kind']=='diagnostic' for e in row['result']['events']))
        bad=self.case('outer-bad-magic')
        self.assertEqual(len([e for e in bad['result']['events'] if e['kind']=='bounded_memcmp']),5)
    def test_invalid_declared_offsets_defer_with_partial_inner_effects(self):
        for name in ('outer-declared-offset-too-small','outer-declared-offset-signed-negative'):
            row=self.case(name)
            self.assertEqual(raw(row,'outer_hex')[1],1)
            self.assertEqual(int.from_bytes(raw(row,'inner_hex')[2:4],'little'),1)
            self.assertEqual(raw(row,'inner_hex')[0xC:0x10],bytes([3,4,1,18]))
            self.assertEqual(row['result']['after']['ring_u32'],row['result']['before']['ring_u32'])
    def test_valid_partial_preserves_held_credit_and_selective_writes(self):
        row=self.case('outer-valid-mono-COP1-open');after=row['result']['after']
        self.assertEqual(after['ring_u32'][3:5],[0,1952])
        self.assertEqual(after['ring_u32'][3]+after['ring_u32'][4]+96,2048)
        self.assertEqual(raw(row,'outer_hex')[1],1)
        inner=raw(row,'inner_hex');pred=raw(row,'predictor_hex')
        self.assertEqual(inner[0x20:0x38],bytes([0x6D])*24)
        self.assertEqual(inner[0x50:0x68],bytes([0x6D])*24)
        self.assertEqual(pred[0x28:0x34],bytes([0x4B])*12)
        self.assertEqual(pred[0x34:0x3A],bytes(6))
        names=[e['name'] for e in entries(row)]
        self.assertIn('history',names);self.assertIn('coefficient_math',names)
        self.assertNotIn('install_history',names);self.assertNotIn('loop',names);self.assertNotIn('ainf',names)
    def test_declared_header_fit_happens_after_coefficient_work(self):
        row=self.case('outer-wrap-short-first-span')
        ringcalls=[t for t in row['result']['traces'] if t['name']=='ring_get']
        self.assertEqual(len(ringcalls),1)
        after=row['result']['after'];self.assertEqual(after['ring_u32'][3],42)
        self.assertEqual(96-after['ring_u32'][3],54)
        self.assertEqual(row['result']['failure']['pc'],0x126514)
        self.assertEqual(raw(row,'outer_hex')[0x98:0x9C],bytes([0x5A])*4)
    def test_base_outputs_signed_arithmetic_and_word_identity(self):
        mono=output(self.case('base-mono'))
        self.assertEqual(struct.unpack_from('<H',mono)[0],96)
        self.assertEqual(mono[4:8],bytes([3,4,18,1]))
        self.assertEqual(struct.unpack_from('<I',mono,16)[0],44100)
        self.assertEqual(struct.unpack_from('<2I',mono,32),(1000,32))
        signed=output(self.case('base-signed-bytes'))
        self.assertEqual(struct.unpack_from('<I',signed,16)[0],0xFFFFFFFF)
        self.assertEqual(struct.unpack_from('<2I',signed,32),(0x80000001,24))
        self.assertEqual(struct.unpack_from('<I',output(self.case('base-zero-bits')),36)[0],0)
        self.assertEqual(struct.unpack_from('<H',output(self.case('base-header-halfword-wrap')))[0],2)
    def test_parser_failure_leaves_outputs_untouched(self):
        for name,ret in [('base-short',-1),('base-bad-magic',-2),('version-short',-1),('filter-short',-1),('history-v4-short',-1)]:
            row=self.case(name)
            self.assertEqual(output(row),bytes([0x5A])*256)
            self.assertEqual(row['result']['raw_v0_lower64_observation_only'],ret & ((1<<64)-1))
    def test_version_filter_and_history_exact_selective_outputs(self):
        data=output(self.case('version-v4'));self.assertEqual(data[:8],bytes.fromhex('045a5a5a085a5a5a'))
        self.assertEqual(output(self.case('filter-signed-halfword'))[:4],bytes.fromhex('01805a5a'))
        self.assertEqual(output(self.case('history-v3-clears'))[:12],bytes(8)+bytes([0x5A])*4)
        self.assertEqual(output(self.case('history-v4'))[:12],bytes.fromhex('34127856dcfe98ba')+bytes([0x5A])*4)
    def test_complete_loop_helpers_keep_corrected_fourth_word(self):
        for version in (3,4):
            data=output(self.case(f'loop-v{version}'))
            self.assertEqual(int.from_bytes(data[:4],'little',signed=True),-2)
            self.assertEqual(struct.unpack_from('<2H',data,4),(1,0x1234))
            self.assertEqual(struct.unpack_from('<3I',data,16),(0x00112233,0x44556677,0x8899AABB))
            self.assertEqual(struct.unpack_from('<I',data,32)[0],0xCCDDEEFF)
            self.assertEqual(data[28:32],bytes([0x5A])*4)
    def test_complete_ainf_helpers_and_failure_partial_clear(self):
        for version in (3,4):
            data=output(self.case(f'ainf-v{version}'))
            self.assertEqual(struct.unpack_from('<I',data)[0],0x12345678)
            self.assertEqual(data[4:20],bytes(range(16)))
            self.assertEqual(struct.unpack_from('<H',data,32)[0],0xFEDC)
            self.assertEqual(struct.unpack_from('<2H',data,36),(0x3344,0x5566))
        self.assertEqual(output(self.case('ainf-absent-partial-clear'))[:8],bytes(4)+bytes([0x5A])*4)
        self.assertEqual(output(self.case('loop-absent-partial-clear'))[:8],bytes(6)+bytes([0x5A])*2)
    def test_key_selection_and_real_table_derived_path(self):
        self.assertEqual(struct.unpack_from('<3H',output(self.case('key-fallback-selection'))),(23456,7,65527))
        self.assertEqual(struct.unpack_from('<3H',output(self.case('key-derived-format-table'))),(17383,19867,21787))
        for name,expected in [('outer-fallback-key-COP1-open',(23456,7,65527)),
            ('outer-configured-key-COP1-open',(32769,65535,4660)),('outer-derived-key-COP1-open',(17383,19867,21787))]:
            self.assertEqual(struct.unpack_from('<3H',raw(self.case(name),'predictor_hex'),0x34),expected)
        row=self.case('key-derived-format-table')
        self.assertIn('derive_key',[e['name'] for e in entries(row)])
        fmt=[e for e in row['result']['events'] if e['kind']=='bounded_format_u32']
        self.assertEqual([e['output_hex'] for e in fmt],[b'FEDCBA98\0'.hex()])
        self.assertEqual(int.from_bytes(raw(row,'key_global_hex')[:4],'little'),1)
    def test_current_fpu_authority_does_not_supply_integer_engine(self):
        elf=h.Elf(h.ROOT/'game_data/SLUS_207.65')
        for pc,word,ft,fd in [(0x12652C,0x46160504,22,20),(0x1265E8,0x460C0004,12,0)]:
            self.assertEqual(int.from_bytes(elf.read(pc,4),'little'),word)
            self.assertEqual(((word>>16)&31,(word>>6)&31),(ft,fd))
        runtime=h.ROOT/'third_party/PS2Recomp/ps2xRuntime/include'
        self.assertEqual(h.sha((runtime/'ps2_fpu_convert.h').read_bytes()),'db9db81090400ac42fd7e391c0998887c4e922a1cb7c0d77516f47d3d8a9c8f3')
        self.assertEqual(h.sha((runtime/'ps2_runtime_macros.h').read_bytes()),'763baab6071c4a10c418a2f9f968e92e4da2e62a1e5ace642593a38d4c734287')
        self.assertEqual(h.sha((h.ROOT/'third_party/PS2Recomp/ps2xRecomp/src/lib/code_generator.cpp').read_bytes()),'cf90c94d772b028bc71ebe965a6c3ad29cc9e89f6b22ac481c87e88d868c6f55')
    def test_no_math_hook_or_synthetic_success_is_admitted(self):
        for row in self.rows.values():
            kinds={e['kind'] for e in row['result']['events']}
            self.assertFalse(kinds & {'coefficient_hook','sqrt_hook','cos_hook','synthetic_header_success'})
            self.assertEqual(raw(row,'direct_guard_hex')[:16],bytes([0xA5])*16)
            self.assertEqual(raw(row,'direct_guard_hex')[-16:],bytes([0xA5])*16)
        for name in ('outer-zero-rate-COP1-open','outer-zero-bits-COP1-open'):
            self.assertEqual(self.case(name)['result']['status'],'partial_refusal')

if __name__=='__main__':unittest.main()
