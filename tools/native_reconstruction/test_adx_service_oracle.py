"""Independent dispatch/state/ABI expectations, without a native service core."""
import hashlib
from pathlib import Path
import unittest

from adx_service_oracle import (Machine,generated_word_audit,generate,CONTEXT,INPUT,LEFT,
    RIGHT,SP,RETURN,SERVICE,ODD,FLAG,SAVED,MONO,STEREO)
from sjuni_oracle import OracleError,StepLimit,sext32


class ServiceOracleTests(unittest.TestCase):
    def test_requested_and_processing_both_execute_once_then_ready(self):
        for phase in (1,2):
            machine=Machine(phase=phase,result=-9)
            result=machine.run()
            self.assertEqual(len(result['events']),1)
            self.assertEqual(result['events'][0]['before']['context_words_u32'][3],2)
            self.assertEqual(result['state']['context_words_u32'][3:5],[3,0xFFFFFFF7])
            phase_stores=[w['value_u64'] for w in result['writes']
                if w['origin']=='original' and w['address']==CONTEXT+12]
            self.assertEqual(phase_stores,[2,3] if phase==1 else [3])

    def test_all_other_phase_examples_preserve_context_and_never_call_codec(self):
        for phase in (0,3,4,0x7FFFFFFF,0x80000000,0xFFFFFFFF):
            machine=Machine(phase=phase,initial_flag=0xAA55AA55,hook_payload=True)
            before=machine.snapshot()
            result=machine.run()
            self.assertFalse(result['events'])
            self.assertEqual(result['state']['context_words_u32'],before['context_words_u32'])
            self.assertEqual(result['state']['odd_flag_u32'],0xAA55AA55)
            self.assertTrue(all(SP-64<=w['address']<SP for w in result['writes']))

    def test_only_mode_one_is_mono(self):
        for mode in (0,1,2,3,0x80000000,0xFFFFFFFF):
            event=Machine(mode=mode).run()['events'][0]
            self.assertEqual(event['target_pc'],MONO if mode==1 else STEREO)
            self.assertEqual(event['route'],'mono' if mode==1 else 'stereo')

    def test_mono_registers_and_signed_stack_parameter_are_exact(self):
        result=Machine(mode=1,requested=-17).run()
        event=result['events'][0]
        self.assertEqual(event['arguments_lower64'],[INPUT,sext32(-17),LEFT,CONTEXT+40,
            sext32(-32768),32767,CONTEXT+52,sext32(-32767)])
        self.assertEqual(event['stack_argument_words_u32'],[0xFFFFF00D,0xCCCCCCCC,0xCCCCCCCC])
        self.assertEqual((event['caller_pc'],event['return_pc']),(0x1350E0,0x1350E8))

    def test_stereo_registers_and_three_stack_parameters_are_exact(self):
        event=Machine(mode=2,requested=-2147483648).run()['events'][0]
        self.assertEqual(event['arguments_lower64'],[INPUT,sext32(-2147483648),LEFT,CONTEXT+40,
            RIGHT,CONTEXT+44,sext32(-32768),32767])
        self.assertEqual(event['stack_argument_words_u32'],[CONTEXT+52,0xFFFF8001,0xFFFFF00D])
        self.assertEqual((event['caller_pc'],event['return_pc']),(0x135120,0x135128))

    def test_stereo_signed_remainder_flags_positive_odd_only(self):
        for value in (-2147483648,-2147483647,-3,-2,-1,0,1,2,3,2147483646,2147483647):
            result=Machine(mode=2,result=value,initial_flag=0xDEADBEEF).run()
            expected=1 if value>0 and value%2 else 0xDEADBEEF
            self.assertEqual(result['state']['odd_flag_u32'],expected)
            self.assertEqual(ODD in result['visited_pcs'],expected==1)
            self.assertEqual(result['state']['context_words_u32'][4],value&0xFFFFFFFF)
            self.assertEqual(result['state']['context_words_u32'][3],3)
        self.assertEqual(Machine(mode=2,result=4,initial_flag=1).run()['state']['odd_flag_u32'],1)

    def test_mono_odd_result_does_not_call_flag_helper(self):
        for value in (1,3,-1,0x7FFFFFFF):
            result=Machine(mode=1,result=value,initial_flag=0xABCDEF01).run()
            self.assertNotIn(ODD,result['visited_pcs'])
            self.assertEqual(result['state']['odd_flag_u32'],0xABCDEF01)

    def test_no_scripted_effect_has_only_two_context_field_publications(self):
        for mode in (1,2):
            machine=Machine(mode=mode,result=4)
            before=machine.snapshot()['context_words_u32']
            result=machine.run()
            expected=before.copy();expected[3]=3;expected[4]=4
            self.assertEqual(result['state']['context_words_u32'],expected)
            self.assertEqual({w['address'] for w in result['writes'] if CONTEXT<=w['address']<CONTEXT+60},
                {CONTEXT+12,CONTEXT+16})

    def test_frame_saved_words_holes_and_caller_guards(self):
        for phase in (0,1,2,3):
            for mode in (1,2):
                machine=Machine(phase=phase,mode=mode)
                before=machine.snapshot()
                result=machine.run()
                expected=bytearray([0xCC]*64)
                for offset,value,size in ((32,SAVED[16],8),(40,SAVED[17],8),(48,RETURN,8)):
                    expected[offset:offset+size]=value.to_bytes(size,'little')
                if phase in (1,2):
                    args=((0,0xFFFFF00D),) if mode==1 else ((0,CONTEXT+52),(8,0xFFFF8001),(16,0xFFFFF00D))
                    for offset,value in args:
                        expected[offset:offset+4]=value.to_bytes(4,'little')
                self.assertEqual(result['state']['frame_bytes_hex'],expected.hex())
                self.assertEqual(result['state']['lower_stack_guard_hex'],before['lower_stack_guard_hex'])
                self.assertEqual(result['state']['caller_stack_guard_hex'],before['caller_stack_guard_hex'])
                self.assertTrue(all(result['abi'].values()))
                self.assertFalse(result['return_is_defined'])

    def test_scripted_codec_effects_remain_separate_from_original_stores(self):
        for mode in (1,2):
            machine=Machine(mode=mode,hook_payload=True,result=2)
            before=machine.snapshot()
            result=machine.run()
            self.assertEqual(result['state']['input_sha256'],before['input_sha256'])
            self.assertNotEqual(result['state']['left_bytes_hex'],before['left_bytes_hex'])
            self.assertEqual(result['state']['right_bytes_hex']==before['right_bytes_hex'],mode==1)
            self.assertTrue(any(w['origin']=='scripted_codec' for w in result['writes']))
            self.assertFalse(any(w['origin']=='original' and w['address'] in (LEFT,RIGHT,CONTEXT+52)
                for w in result['writes']))

    def test_scripted_cancel_is_not_a_completion_fence(self):
        result=Machine(mode=2,result=3,hook_payload=True,hook_effect='cancel').run()
        event=result['events'][0]
        self.assertEqual(event['after']['context_words_u32'][3],0)
        self.assertEqual(event['after']['context_words_u32'][10:12],[0,0])
        self.assertEqual(result['state']['context_words_u32'][3:5],[3,3])
        self.assertEqual(result['state']['context_words_u32'][10:12],[0,0])
        self.assertEqual(result['state']['context_words_u32'][13]&65535,0x3456)

    def test_scripted_release_does_not_prevent_cached_context_publication(self):
        result=Machine(mode=1,result=-1,hook_payload=True,hook_effect='release').run()
        self.assertEqual(result['events'][0]['after']['context_words_u32'],[0]*15)
        expected=[0]*15;expected[3]=3;expected[4]=0xFFFFFFFF
        self.assertEqual(result['state']['context_words_u32'],expected)

    def test_scripted_busy_request_and_acknowledge_do_not_change_processing(self):
        for effect in ('request','acknowledge'):
            result=Machine(hook_effect=effect).run()
            self.assertEqual(result['events'][0]['after']['context_words_u32'][3],2)
            self.assertEqual(result['state']['context_words_u32'][3],3)

    def test_boundaries_limits_and_one_shot_fail_explicitly(self):
        for kwargs in (dict(phase=-1),dict(mode=1<<32),dict(result=1<<31),
                       dict(requested=-(1<<31)-1),dict(hook_effect='thread'),dict(hook_payload=1)):
            with self.subTest(kwargs=kwargs),self.assertRaises(OracleError):
                Machine(**kwargs)
        machine=Machine()
        with self.assertRaises(OracleError):machine.fetch(0x135170)
        with self.assertRaises(OracleError):machine.fetch(SERVICE+1)
        with self.assertRaises(StepLimit):machine.run(step_cap=1)
        self.assertFalse(machine.mem.active)
        with self.assertRaises(OracleError):machine.run()
        with self.assertRaises(OracleError):Machine().run(step_cap=0)

    def test_owned_word_audit_and_deterministic_corpus(self):
        audit=generated_word_audit()
        self.assertEqual(sum(row['matched_comment_words'] for row in audit),64)
        self.assertEqual([pc for row in audit for pc in row['omitted_zero_pcs']],[0x13514C,0x13516C])
        result=generate()
        self.assertEqual(result,generate())
        self.assertEqual(result['counts'],dict(cases=74,original_instructions=2558,codec_calls=54,
            body_words=66,reached_words=65,unreached_pcs=[0x13516C]))
        engine=Path(__file__).with_name('sjuni_oracle.py')
        self.assertEqual(result['identity']['integer_engine_sha256'],hashlib.sha256(engine.read_bytes()).hexdigest())


if __name__=='__main__':
    unittest.main()
