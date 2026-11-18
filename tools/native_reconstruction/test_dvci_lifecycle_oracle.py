"""Owned lifecycle evidence; external responses remain explicit scripted inputs."""
import hashlib
import json
import os
from pathlib import Path
import unittest

from dvci_lifecycle_oracle import Machine,Plan,Scenario,generate,POOL,STRIDE,SUBJECT,SRD,NAME
from sjuni_oracle import OracleError,StepLimit


def subject(result):
    return bytes.fromhex(result['state']['subject_bytes_hex'])


def u32(data,offset):
    return int.from_bytes(data[offset:offset+4],'little')


class LifecycleTests(unittest.TestCase):
    def test_early_stop_preserves_fields_then_close_clears_exact_subject(self):
        for state in (0,1):
            s=Scenario('early',writes=[(SUBJECT+2,1,state)])
            before=s.machine.snapshot()
            r=s.call('stop',[SUBJECT])
            self.assertEqual(r['state'],before)
            self.assertEqual(r['hook_count'],0)
            r=s.call('close',[SUBJECT])
            self.assertEqual(subject(r),bytes(STRIDE))
            self.assertEqual(r['hook_counts'],{'memset':1})
            self.assertEqual(s.call('find_slot',[])['return_u32'],SUBJECT)
            # Real close never clears a different active slot.
            pool=bytes.fromhex(r['state']['pool_bytes_hex'])
            self.assertEqual(pool[0],1)
            self.assertEqual(r['state']['srd_prefix_hex'],before['srd_prefix_hex'])

    def test_stop_consumes_original_terminal_update_then_normalizes_stop_state(self):
        for initial in (2,3):
            for terminal in (0,3,9):
                s=Scenario('terminal',plan=Plan(srd_states=(terminal,)),
                           writes=[(SUBJECT+2,1,initial)])
                r=s.call('stop',[SUBJECT])
                data=subject(r)
                self.assertEqual((data[2],u32(data,20),u32(data,28)),(0,0,0))
                self.assertEqual(u32(data,12),4 if terminal==3 else 3)
                self.assertEqual(u32(bytes.fromhex(r['state']['srd_prefix_hex']),4),1)
                self.assertEqual(r['hook_counts']['srd_status'],1)
                self.assertEqual(r['hook_counts']['srd_destroy'],1)
                observed=r['hook_samples']['srd_destroy']['first'][0]['observed_before']
                during=bytes.fromhex(observed['subject_bytes_hex'])
                self.assertEqual(u32(during,28),SRD)
                self.assertEqual(during[2],{0:0,3:1,9:3}[terminal])

    def test_pending_sequence_progress_is_scripted_but_field_changes_are_owned(self):
        s=Scenario('sequence',plan=Plan(srd_states=(1,2,4,3)))
        r=s.call('stop',[SUBJECT])
        self.assertEqual(r['hook_counts']['srd_status'],4)
        self.assertEqual(r['hook_counts']['server_service'],4)
        self.assertEqual(r['pc_execution_counts']['0x139f38'],4)
        self.assertEqual(r['pc_execution_counts']['0x139f5c'],3)
        self.assertEqual(u32(subject(r),12),4)
        self.assertEqual(subject(r)[2],0)

    def test_close_reopen_executes_real_allocator_and_open_field_stores(self):
        s=Scenario('reuse',writes=[(SUBJECT+2,1,0)])
        s.call('close',[SUBJECT])
        self.assertEqual(s.call('find_slot',[])['return_u32'],SUBJECT)
        r=s.call('open',[NAME,0,0]);data=subject(r)
        self.assertEqual(r['return_u32'],SUBJECT)
        self.assertEqual((data[0],data[1],data[2]),(1,1,0))
        self.assertEqual((u32(data,4),u32(data,8)),(4097,3))
        self.assertEqual([u32(data,x) for x in (12,16,20,24,28)],[0]*5)
        self.assertEqual((u32(data,32),u32(data,36)),(0x123400,4097))
        self.assertEqual(r['hook_counts'],{'cached_metadata':1})
        # The one declared cache hook supplies only its metadata words.
        event=r['hook_samples']['cached_metadata']['first'][0]
        before=bytes.fromhex(event['observed_before']['subject_bytes_hex'])
        after=bytes.fromhex(event['observed_after']['subject_bytes_hex'])
        self.assertEqual(before[:32],after[:32]);self.assertEqual(before[40:],after[40:])

    def test_cached_result_one_sets_original_sentinel(self):
        s=Scenario('sentinel',plan=Plan(cached_result=1),writes=[(SUBJECT+2,1,0)])
        s.call('close',[SUBJECT])
        self.assertEqual(u32(subject(s.call('open',[NAME,0,0])),8),0x7FFFFFFF)

    def test_free_lookup_is_last_not_first_and_open_refusals_do_not_mutate(self):
        s=Scenario('free',writes=[(POOL+i*STRIDE,1,0) for i in (0,3,39)])
        self.assertEqual(s.call('find_slot',[])['return_u32'],SUBJECT)
        s=Scenario('full')
        before=s.machine.snapshot()
        self.assertEqual(s.call('find_slot',[])['return_u32'],0)
        self.assertEqual(s.call('open',[NAME,0,0])['return_u32'],0)
        self.assertEqual(s.machine.snapshot(),before)
        for args in ([0,0,0],[NAME,0,1]):
            self.assertEqual(s.call('open',args)['return_u32'],0)
            self.assertEqual(s.machine.snapshot(),before)

    def test_unknown_inputs_and_step_budget_fail_closed(self):
        for plan in (Plan(service_gate=2),Plan(srd_states=(10,)),Plan(cached_bytes=0)):
            with self.assertRaises(OracleError):Machine(plan=plan)
        with self.assertRaises(StepLimit):
            Machine(plan=Plan(service_gate=0)).run('stop',[SUBJECT],step_cap=100)
        with self.assertRaises(OracleError):Machine().run('not_lifecycle',[])

    def test_fast_fixture_is_deterministic_and_has_no_code_arrays(self):
        first=generate()
        self.assertEqual(first,generate())
        self.assertEqual(first['counts'],dict(cases=18,operations=52,caps_included=False,interpreted_steps=16023))
        for case in first['cases']:
            for operation in case['operations']:
                self.assertNotIn('code',operation['expected'])
                self.assertNotIn('instructions',operation['expected'])
                self.assertEqual(len(operation['expected']['hook_trace_sha256']),64)

    @unittest.skipUnless(os.getenv('DVCI_LIFECYCLE_CAP_FIXTURE'),'Supply separately generated full-cap fixture')
    def test_complete_original_cap_receipt(self):
        path=Path(os.environ['DVCI_LIFECYCLE_CAP_FIXTURE'])
        fixture=json.loads(path.read_text(encoding='utf-8'))
        source=Path(__file__).with_name('dvci_lifecycle_oracle.py')
        self.assertEqual(fixture['identity']['generator_sha256'],hashlib.sha256(source.read_bytes()).hexdigest())
        self.assertEqual(fixture['identity']['elf_sha256'],
                         '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46')
        engine=Path(__file__).with_name('sjuni_oracle.py')
        self.assertEqual(fixture['identity']['integer_engine_sha256'],hashlib.sha256(engine.read_bytes()).hexdigest())
        machine=Machine()
        for body in fixture['identity']['bodies']:
            raw=machine.code[body['start_pc'],body['end_pc_exclusive']]
            self.assertEqual(body['sha256'],hashlib.sha256(raw).hexdigest())
        self.assertTrue(fixture['counts']['caps_included'])
        cases=[c for c in fixture['cases'] if c['name'].startswith('owned_cap_')]
        self.assertEqual(len(cases),2)
        for case in cases:
            stop=case['operations'][0]['expected'];data=subject(stop)
            self.assertEqual(stop['pc_execution_counts']['0x139f5c'],0xA0000)
            self.assertEqual(stop['pc_execution_counts']['0x139f64'],0xA0000)
            self.assertEqual(stop['hook_counts']['server_service'],0xA0000)
            self.assertEqual(stop['hook_counts']['service_gate'],0xA0000)
            self.assertEqual(stop['hook_counts'].get('message',0),1 if case['external_plan']['verbosity']==0 else 0)
            self.assertEqual((data[2],u32(data,20),u32(data,28)),(0,0,SRD))
            self.assertEqual(subject(case['operations'][1]['expected']),bytes(STRIDE))
            self.assertEqual(case['operations'][2]['expected']['return_u32'],SUBJECT)
            self.assertEqual(case['operations'][3]['expected']['return_u32'],SUBJECT)


if __name__=='__main__':unittest.main()
