"""Large-loop original-word contracts, no candidate arithmetic imported."""
import hashlib
import json
from pathlib import Path
import unittest

import adx_decode_oracle as mono
import adx_stereo_oracle as stereo
from adx_large_block_oracle import (machine_for,parameters_for,encoded_blocks,
    identities,ROOT,MAX_ORIGINAL_BLOCKS)
from sjuni_oracle import OracleError,StepLimit,sext32


class LargeOriginalTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        path=ROOT/'build-native-sjuni/adx-large-block-fixtures.json'
        cls.fixture=json.loads(path.read_text())
        source=Path(__file__).with_name('adx_large_block_oracle.py')
        if cls.fixture['identity']['generator_sha256']!=hashlib.sha256(source.read_bytes()).hexdigest():
            raise ValueError('Regenerate large fixture after generator change')
        if cls.fixture['identity']['tool_sha256']!=identities():
            raise ValueError('Frozen original engines changed')
        cls.cases={case['name']:case for case in cls.fixture['cases']}

    def test_exact_corpus_extent_and_real_loop_counts(self):
        self.assertEqual(self.fixture['counts'],dict(cases=21,original_instructions=5625317,
            pcm_halfword_stores=220896,visited_pcs=dict(mono=119,normal=210,downmix=239)))
        self.assertEqual(mono.MAX_BLOCKS,16)
        self.assertEqual(stereo.MAX_BLOCKS,16)
        for mode in ('mono','normal','downmix'):
            counts={c['input']['requested_i32'] for c in self.fixture['cases']
                if c['mode']==mode and '_full_' in c['name']}
            self.assertEqual(counts,{17,210,300,511,512,513})
        for case in self.fixture['cases']:
            result=case['expected']
            self.assertEqual(result['steps'],sum(result['instruction_counts'].values()))
            self.assertGreater(result['steps'],10000)
            self.assertGreater(max(result['instruction_counts'].values()),100)

    def test_normal_completion_counts_key_writes_and_unpaired_stereo_input(self):
        for case in self.fixture['cases']:
            if '_full_' not in case['name']:
                continue
            count=case['input']['requested_i32'];mode=case['mode'];result=case['expected']
            actual_blocks=count if mode=='mono' else count//2*2
            self.assertEqual(result['return_i32'],count)
            self.assertEqual(result['pcm_store_count'],actual_blocks*32)
            self.assertEqual(result['writes']['key']['accesses'],actual_blocks)
            self.assertEqual(result['reads']['encoded']['last_end'],actual_blocks*18)
            self.assertEqual(result['writes']['history']['accesses'],2 if mode=='mono' else 4)
            if mode=='mono':
                pcm=result['state']['pcm_i16']
                self.assertEqual(result['state']['history_i16'],[pcm[-1],pcm[-2]])
            elif mode=='normal':
                left,right=result['state']['left_pcm_i16'],result['state']['right_pcm_i16']
                self.assertEqual(result['state']['history_i16'],[left[-1],left[-2],right[-1],right[-2]])

    def test_downmix_duplicates_output_but_keeps_unmixed_predictor_state(self):
        for count in (17,210,300,511,512,513):
            mixed=self.cases[f'downmix_full_{count}']['expected']
            separate=self.cases[f'normal_full_{count}']['expected']
            self.assertEqual(mixed['state']['left_pcm_i16'],mixed['state']['right_pcm_i16'])
            self.assertEqual(mixed['state']['history_i16'],separate['state']['history_i16'])
            self.assertEqual(mixed['state']['key_u16'],separate['state']['key_u16'])
            self.assertEqual(mixed['div_instruction_count'],count//2*32)
            self.assertEqual(mixed['writes']['key']['accesses'],separate['writes']['key']['accesses'])

    def test_markers_keep_history_and_exact_prefix_effects(self):
        for name,done,extra_key in (
            ('mono_marker_after210_request512',210,0),
            ('normal_right_marker_after150pairs_odd_request511',300,1),
            ('downmix_left_marker_after105pairs_request512',210,0)):
            case=self.cases[name];result=case['expected'];state=result['state']
            self.assertEqual(result['return_i32'],done)
            self.assertEqual(result['pcm_store_count'],done*32)
            self.assertEqual(state['history_i16'],case['input']['history_i16'])
            self.assertNotIn('history',result['writes'])
            self.assertEqual(result['writes']['key']['accesses'],done+extra_key)
            if case['mode']=='mono':
                self.assertEqual(state['pcm_i16'][done*32:],[-23131]*(512-done)*32)
            else:
                total=case['input']['output_capacity_samples_per_plane']
                for field in ('left_pcm_i16','right_pcm_i16'):
                    self.assertEqual(state[field][done//2*32:],[-23131]*(total-done//2*32))

    def test_all_output_guards_input_identity_and_saved_abi(self):
        expected_jr=dict(mono=0x1278AC,normal=0x127FC0,downmix=0x127C74)
        for case in self.fixture['cases']:
            result=case['expected'];state=result['state'];abi=result['original_abi']
            self.assertTrue(all(result['abi'].values()),case['name'])
            self.assertEqual(abi['return_branch_pc'],expected_jr[case['mode']])
            self.assertEqual(abi['final_pc_u32'],abi['return_address_u32'])
            self.assertEqual(len(bytes.fromhex(abi['final_frame_hex'])),80 if case['mode']=='mono' else 112)
            self.assertEqual(abi['final_caller_argument_bytes_hex'],abi['caller_argument_bytes_hex'])
            self.assertEqual(abi['final_lower_stack_guard_hex'],abi['initial_lower_stack_guard_hex'])
            for reg in abi['saved_register_indices']+[29,31]:
                self.assertEqual(abi['final_gpr_lower64_observation_only'][reg],abi['initial_gpr_lower64'][reg])
            self.assertEqual(state['encoded_sha256'],hashlib.sha256(bytes.fromhex(case['input']['encoded_hex'])).hexdigest())
            guards=('output_guard_hex',) if case['mode']=='mono' else ('left_guard_hex','right_guard_hex')
            for field in guards:
                self.assertEqual(state[field],'a5'*16)

    def test_canonical_callsite_arguments_and_caller_slot_widths(self):
        for case in self.fixture['cases']:
            initial=case['input'];abi=case['expected']['original_abi'];gprs=abi['initial_gpr_lower64']
            arguments=bytes.fromhex(abi['caller_argument_bytes_hex'])
            if case['mode']=='mono':
                self.assertEqual(gprs[8:10],[sext32(v) for v in initial['coefficients_i16']])
                self.assertEqual(gprs[11],sext32(initial['multiplier_i16']))
                self.assertEqual(int.from_bytes(arguments[:4],'little'),initial['addend_i16']&0xFFFFFFFF)
            else:
                self.assertEqual(gprs[10:12],[sext32(v) for v in initial['coefficients_i16']])
                self.assertEqual(int.from_bytes(arguments[8:12],'little'),initial['multiplier_i16']&0xFFFFFFFF)
                self.assertEqual(int.from_bytes(arguments[16:20],'little'),initial['addend_i16']&0xFFFFFFFF)

    def test513_is_original_evidence_outside_proposed_adapter_admission(self):
        for mode in ('mono','normal','downmix'):
            case=self.cases[f'{mode}_full_513']
            self.assertFalse(case['proposed_adapter_count_admitted'])
            self.assertEqual(case['expected']['return_i32'],513)
        self.assertTrue(all(c['proposed_adapter_count_admitted'] for c in self.fixture['cases'] if c['input']['requested_i32']<=512))

    def test_new_span_admission_and_short_read_limit_fail_closed(self):
        params=parameters_for('mono',17)
        for args in (dict(requested=0),dict(requested=514),dict(requested=17,mode='selector'),
                     dict(requested=17,output_samples=MAX_ORIGINAL_BLOCKS*32+1)):
            with self.subTest(args=args),self.assertRaises(OracleError):
                machine_for(b'',**args,**params)
        with self.assertRaises(OracleError):
            machine_for(encoded_blocks(17)[:-1],17,**params).run(step_cap=100000)
        with self.assertRaises(StepLimit):
            machine_for(encoded_blocks(17),17,**params).run(step_cap=10)


if __name__=='__main__':
    unittest.main()
