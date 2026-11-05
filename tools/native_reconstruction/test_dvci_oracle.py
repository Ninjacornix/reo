"""Independent scalar expectations over owned-word execution, no native DVCI."""
from pathlib import Path
import tempfile
import unittest

from dvci_oracle import (Machine, Scenario, HookPlan, HANDLE, BUFFER, SRD,
                         TABLE, TABLE_BYTES, ENTRIES, generate)
from sjuni_oracle import (OracleError, UnknownInstruction, StepLimit, MASK32)


def words(result):
    return result['state']['handle_words_u32']


def state(result):
    return result['state']['handle_bytes_u8'][2]


def kinds(result):
    return [event['kind'] for event in result['events']]


class DvciInstructionBoundaryTests(unittest.TestCase):
    def test_owned_identity_unknown_instruction_and_fetch_fail_closed(self):
        with tempfile.TemporaryDirectory() as tmp:
            wrong=Path(tmp)/'wrong.elf'
            wrong.write_bytes(b'not the owned File #1 ELF')
            with self.assertRaisesRegex(ValueError,'identity mismatch'):
                Machine(wrong)
        m=Machine()
        with self.assertRaises(UnknownInstruction):
            m.instruction(0,12)  # generic syscall encoding is not interpreted
        with self.assertRaises(OracleError):m.fetch(0x140000)
        with self.assertRaises(OracleError):m.fetch(ENTRIES['request'][0]+1)
        with self.assertRaises(StepLimit):m.run('request',[HANDLE,4,BUFFER],step_cap=1)

    def test_unknown_state_hook_plan_identity_and_operation_abort(self):
        for plan in (HookPlan(srd_state=-1),HookPlan(srd_state=10),
                     HookPlan(create=123),HookPlan(prepare=2),HookPlan(sync_mode=4)):
            with self.assertRaises(OracleError):Machine(plan=plan)
        for offset,size,value in ((2,1,7),(28,4,SRD+4)):
            m=Machine();m.mem.store(HANDLE+offset,size,value)
            with self.assertRaises(OracleError):m.run('status',[HANDLE])
        m=Machine()
        with self.assertRaises(OracleError):m.run('not_a_dvci_operation',[HANDLE])
        with self.assertRaises(OracleError):m.run('tell',[HANDLE+4])
        m.mem.store(TABLE,4,ENTRIES['seek'][0])
        with self.assertRaisesRegex(OracleError,'dispatch table was modified'):
            m.run('update',[HANDLE])


class DvciScalarContractTests(unittest.TestCase):
    def test_seek_origins_clamps_invalid_origin_and_word_wrap(self):
        for origin,offset,cursor,expected in (
                (0,7,3,7),(0,-7,3,0),(0,99,3,20),(1,4,3,7),
                (1,-9,3,0),(2,-3,3,17),(2,5,3,20),(7,123,9,9),
                (7,123,-1,0),(1,1,0x7FFFFFFF,0),(2,0x7FFFFFFF,3,0)):
            s=Scenario('seek',writes=[(HANDLE+12,4,cursor)])
            r=s.call('seek',[HANDLE,offset,origin])
            self.assertEqual(r['return_u32'],expected)
            self.assertEqual(words(r)[3],expected)
            self.assertEqual(words(r)[5],0)
            self.assertEqual(s.call('tell',[HANDLE])['return_u32'],expected)
            self.assertEqual(kinds(r),[])

    def test_null_negative_and_null_buffer_only_diagnose(self):
        for operation,args in (
                ('seek',[0,5,0]),('tell',[0]),('status',[0]),('transferred',[0]),
                ('request',[0,1,BUFFER]),('request',[HANDLE,-1,BUFFER]),
                ('request',[HANDLE,0,0]),('request',[HANDLE,1,0])):
            s=Scenario('invalid')
            before=s.machine.snapshot()
            r=s.call(operation,args)
            self.assertEqual(r['return_u32'],0)
            self.assertEqual(kinds(r),['diagnostic'])
            self.assertEqual(r['state'],before)

    def test_zero_request_retains_completed_but_busy_zero_changes_nothing(self):
        s=Scenario('zero',writes=[(HANDLE+2,1,3)])
        r=s.call('request',[HANDLE,0,BUFFER])
        self.assertEqual(r['return_u32'],0)
        self.assertEqual(state(r),1)
        self.assertEqual(words(r)[5],0x11223344)
        self.assertEqual(kinds(r),[])
        self.assertEqual(s.call('transferred',[HANDLE])['return_u32'],
                         (0x11223344<<11)&MASK32)
        s=Scenario('busy',writes=[(HANDLE+2,1,2)])
        before=s.machine.snapshot()
        for count in (0,4):
            r=s.call('request',[HANDLE,count,BUFFER])
            self.assertEqual(r['return_u32'],0)
            self.assertEqual(r['state'],before)
            self.assertEqual(kinds(r),[])

    def test_clamped_async_acceptance_and_later_terminal_publication(self):
        s=Scenario('async',writes=[(HANDLE+12,4,18)])
        r=s.call('request',[HANDLE,8,BUFFER])
        self.assertEqual(r['return_u32'],2)
        self.assertEqual((state(r),words(r)[3:8]),
                         (2,[18,2,0x11223344,BUFFER,SRD]))
        self.assertEqual(kinds(r),['srd_create','cache_range','srd_prepare_disc'])
        prepare=r['events'][-1]
        self.assertEqual(prepare['arguments_u64'][:4],[SRD,0x123412,2,BUFFER])
        self.assertEqual(prepare['mode_bytes_u8'],[1,2,3,0xA5])
        self.assertEqual(s.call('transferred',[HANDLE])['return_u32'],0)
        r=s.call('update',[HANDLE])
        self.assertFalse(r['return_is_defined'])
        self.assertIsNone(r['return_u32'])
        self.assertEqual((state(r),words(r)[3],words(r)[5],words(r)[7]),(1,20,2,0))
        self.assertEqual(s.call('transferred',[HANDLE])['return_u32'],4096)

    def test_sync_counts_original_request_and_wait_return_is_not_consumed(self):
        for wait in (0,-1):
            s=Scenario('sync',plan=HookPlan(sync_mode=1,wait_return=wait),
                       writes=[(HANDLE+12,4,18)])
            r=s.call('request',[HANDLE,8,BUFFER])
            self.assertEqual(r['return_u32'],2)
            self.assertEqual((state(r),words(r)[3],words(r)[4],words(r)[5],words(r)[7]),
                             (1,20,2,8,0))
            self.assertEqual(kinds(r),['srd_create','cache_range','srd_prepare_disc',
                                      'cd_sync','server_gate','server_service',
                                      'srd_wait','srd_destroy'])
            self.assertEqual(s.call('transferred',[HANDLE])['return_u32'],8*2048)
        # This only proves that the wrapper does not inspect the stubbed return;
        # it does not reconstruct device errors or the real wait's side effects.

    def test_zero_accepted_positive_request_still_prepares_under_scripted_success(self):
        s=Scenario('eof',writes=[(HANDLE+12,4,20)])
        r=s.call('request',[HANDLE,1,BUFFER])
        self.assertEqual(r['return_u32'],0)
        self.assertEqual(state(r),2)
        self.assertEqual(words(r)[4],0)
        self.assertEqual(r['events'][1]['arguments_u64'][:2],[BUFFER,BUFFER-1])
        self.assertEqual(r['events'][2]['arguments_u64'][2],0)

    def test_declined_create_and_prepare_preserve_distinct_residual_fields(self):
        s=Scenario('create0',plan=HookPlan(create=0),writes=[(HANDLE+28,4,SRD)])
        r=s.call('request',[HANDLE,4,BUFFER])
        self.assertEqual(r['return_u32'],0)
        self.assertEqual(words(r)[7],0)
        self.assertEqual(kinds(r),['srd_create'])
        s=Scenario('prepare0',plan=HookPlan(prepare=0))
        r=s.call('request',[HANDLE,4,BUFFER])
        self.assertEqual(r['return_u32'],0)
        self.assertEqual((state(r),words(r)[3],words(r)[4],words(r)[7]),(0,3,4,SRD))
        self.assertEqual(kinds(r),['srd_create','cache_range','srd_prepare_disc','srd_destroy'])
        self.assertEqual(r['events'][-1]['observed_before']['handle_words_u32'][7],SRD)

    def test_update_all_owned_table_states_and_destroy_observation_order(self):
        for request_state in range(10):
            s=Scenario('update',plan=HookPlan(srd_state=request_state),
                       writes=[(HANDLE+2,1,2),(HANDLE+28,4,SRD)])
            r=s.call('update',[HANDLE])
            terminal=request_state in (0,3,9)
            self.assertEqual(kinds(r),['guard_enter','srd_status']+
                             (['srd_destroy'] if terminal else [])+['guard_leave'])
            self.assertEqual(words(r)[7],0 if terminal else SRD)
            expected_state={0:0,3:1,9:3}.get(request_state,2)
            self.assertEqual(state(r),expected_state)
            self.assertEqual(words(r)[3],9 if request_state==3 else 3)
            self.assertEqual(words(r)[5],6 if request_state==3 else 0x11223344)
            if terminal:
                destroy=r['events'][-2]
                self.assertEqual(destroy['guard_depth_before'],1)
                self.assertEqual(destroy['observed_before']['handle_words_u32'][7],SRD)
                self.assertEqual(r['events'][-1]['observed_before']['handle_words_u32'][7],0)

    def test_queries_do_not_service_requests_or_modify_payload_probe(self):
        for current in range(4):
            s=Scenario('query',writes=[(HANDLE+2,1,current),(HANDLE+28,4,SRD),
                                       (HANDLE+20,4,0x100001)])
            before=s.machine.snapshot()
            r=s.call('status',[HANDLE])
            self.assertEqual(r['return_u32'],current)
            self.assertEqual(kinds(r),[])
            self.assertEqual(r['state'],before)
            r=s.call('transferred',[HANDLE])
            self.assertEqual(r['return_u32'],((0x100001<<11)&MASK32) if current==1 else 0)
            self.assertEqual(r['state'],before)
        s=Scenario('empty_update')
        r=s.call('update',[HANDLE])
        self.assertEqual(kinds(r),[])
        self.assertEqual(r['state']['destination_probe_bytes_u8'],[0xD7]*64)

    def test_fixture_identity_determinism_and_no_instruction_arrays(self):
        a=generate()
        self.assertEqual(a,generate())
        self.assertEqual(a['counts'],dict(cases=51,operations=178,unique_instruction_pcs=228))
        self.assertEqual(len(a['identity']['bodies']),6)
        self.assertEqual(a['identity']['dispatch_table']['bytes'],TABLE_BYTES)
        self.assertEqual(a['identity']['dispatch_table']['start_pc'],TABLE)
        for case in a['cases']:
            for operation in case['operations']:
                self.assertEqual(operation['expected']['state']['destination_probe_bytes_u8'],[0xD7]*64)
                self.assertNotIn('instructions',operation['expected'])
                self.assertNotIn('code',operation['expected'])


if __name__=='__main__':unittest.main()
