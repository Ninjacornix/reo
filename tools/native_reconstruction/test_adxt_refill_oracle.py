"""Replay and control/ownership checks for the independent original refill oracle."""
import json
from pathlib import Path
import unittest

import adxt_refill_oracle as r

FIXTURE=r.ROOT/'build-native-sjuni/adxt-refill-oracle-v2/original-fixture.json'
FIXTURE_SHA='366dcf38ac63e9d2c88c4be1392e9914d82925c87e0e5e1fbcc506aad7706b52'
INPUT_SHA='1f6253974eb701d83a6912dadcdcb09c321cae533009c8ca9dc2030c16e10572'


def field(state,offset,size=4):
    return int.from_bytes(bytes.fromhex(state['record_hex'])[offset:offset+size],'little')


def calls(row):
    return [value.get('expected',value) for operation in row['operations'] for value in
            ([operation['expected']] if isinstance(operation.get('expected'),dict) else operation.get('expected',[]))]


def events(call,kind): return [value for value in call['events'] if value['kind']==kind]
def backing(state): return bytes.fromhex(state['backing_guard_hex'])[16:-16]


class RefillTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        data=FIXTURE.read_bytes()
        if r.sha(data)!=FIXTURE_SHA: raise AssertionError('Frozen original evidence changed')
        cls.fixture=json.loads(data)
        cls.rows={row['name']:row for row in cls.fixture['cases']}
        cls.inputs=json.loads((r.ROOT/cls.fixture['inputs_file']).read_bytes())

    def case(self,name): return self.rows[name]

    def test_frozen_inputs_and_current_oracle_engines(self):
        self.assertEqual(r.sha(r.serialized(r.corpus_inputs())),INPUT_SHA)
        self.assertEqual(r.sha(r.serialized(self.inputs)),INPUT_SHA)
        self.assertNotIn('expected',json.dumps(self.inputs))
        for name,expected in self.fixture['engine_sha256'].items():
            self.assertEqual(r.sha(Path(r.__file__).with_name(name).read_bytes()),expected,name)

    def test_complete_original_source_word_audit(self):
        audit=r.source_audit(r.ROOT/'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
        self.assertEqual(audit,self.fixture['source_word_audit'])
        self.assertEqual(audit['matched_comments'],1180)
        self.assertEqual(len(audit['omitted_zero_pcs']),34)
        self.assertEqual(self.fixture['summary']['failed_cases'],[])
        self.assertEqual(self.fixture['summary']['original_instructions'],18337)

    def test_all_frozen_cases_replay_exactly(self):
        for inputs in self.inputs['cases']:
            with self.subTest(case=inputs['name']):
                self.assertEqual(r.execute_case(inputs),self.rows[inputs['name']])

    def test_real_calls_not_host_ring_results(self):
        for row in self.rows.values():
            self.assertTrue({0x130108,0x130698,0x13F8A8}.issubset(row['visited_pcs']))
            for call in calls(row):
                self.assertIsNone(call['failure'])
                for event in call['events']:
                    self.assertNotIn(event['kind'],('scripted_ring_get','scripted_publication','decoder'))
                if 'lower_stack_guard_hex' not in call['after']: continue
                self.assertEqual(call['after']['lower_stack_guard_hex'],'cc'*32)
                self.assertEqual(call['after']['caller_guard_hex'],'cc'*32)
                raw=bytes.fromhex(call['after']['backing_guard_hex'])
                self.assertEqual(raw[:16],bytes([0xA5])*16)
                self.assertEqual(raw[-16:],bytes([0xA5])*16)

    def test_inline_io_write_still_requires_later_service_publication(self):
        first,second=calls(self.case('synchronous-write-later-publication'))
        self.assertEqual(first['after']['ring_u32'][3:5],[0,0])
        self.assertEqual(backing(first['after'])[:4096],bytes.fromhex(self.inputs['cases'][0]['file_hex'])[:4096])
        self.assertEqual(second['after']['ring_u32'][3:5],[4096,0])
        self.assertEqual(field(first['after'],0x54),0)
        self.assertEqual(field(second['after'],0x54),2)
        self.assertEqual(len(events(first,'scripted_cvfs_request')),1)
        self.assertEqual(events(second,'scripted_cvfs_request'),[])

    def test_request_observes_inflight_before_stored_destination(self):
        call=calls(self.case('synchronous-write-later-publication'))[0]
        observed=events(call,'scripted_cvfs_request')[0]['observed_during_request']
        self.assertEqual(field(observed,2,1),1)
        self.assertEqual(field(observed,0x20),0)
        self.assertEqual(field(observed,0x24),0)
        self.assertEqual(field(call['after'],0x20),r.BUFFER)
        self.assertEqual(field(call['after'],0x24),4096)

    def test_partial_acceptance_publishes_only_accepted_prefix(self):
        first,second=calls(self.case('partial-accepted-prefix-return-suffix'))
        self.assertEqual(field(first['after'],0x1C),1)
        self.assertEqual(field(first['after'],0x24),4096)
        self.assertEqual(second['after']['ring_u32'][3:5],[2048,2048])
        ringcalls=[event['name'] for event in second['events'] if event['kind']=='original_entry']
        self.assertLess(ringcalls.index('ring_put'),ringcalls.index('ring_unget'))
        self.assertEqual(field(second['after'],0x30),2048)

    def test_pending_consumer_and_reservation_conservation(self):
        row=self.case('consumer-during-pending'); observed=calls(row)
        self.assertEqual(observed[0]['after']['ring_u32'][3:5],[2048,0])
        self.assertEqual(observed[2]['after']['ring_u32'][3:5],[1024,1024])
        self.assertEqual(field(observed[2]['after'],0x24),2048)
        self.assertEqual(row['final']['ring_u32'][3:5],[3072,1024])

    def test_pending_unknown_status_retains_grant(self):
        first,pending,completed=calls(self.case('pending-keeps-whole-free-grant'))
        self.assertEqual(pending['after']['record_hex'],first['after']['record_hex'])
        self.assertEqual(pending['after']['ring_u32'],first['after']['ring_u32'])
        self.assertEqual(events(pending,'scripted_cvfs_request'),[])
        self.assertEqual(field(completed['after'],0x20),0)

    def test_wrap_mirrors_actual_tail_and_returns_unused_suffix(self):
        row=self.case('wrapped-prefix-mirror-copy'); first,second=calls(row)
        self.assertEqual(field(first['after'],0x20),r.BUFFER+2060)
        self.assertEqual(field(first['after'],0x24),2072)
        source=bytes.fromhex(next(v for v in self.inputs['cases'] if v['name']==row['name'])['file_hex'])
        self.assertEqual(backing(second['after'])[:12],source[2036:2048])
        self.assertEqual(second['after']['ring_u32'][3:5],[2048,2048])
        self.assertTrue(events(second,'bounded_memcpy'))

    def test_backpressure_and_threshold_equality_do_not_request(self):
        for name in ('backpressure-no-request','threshold-equality-no-request'):
            call=calls(self.case(name))[0]
            self.assertEqual(events(call,'scripted_cvfs_request'),[])
            self.assertEqual(call['before']['ring_u32'],call['after']['ring_u32'])

    def test_zero_sector_requests_are_actual_source_effects(self):
        for name in ('zero-sector-physical-grant','zero-max-sector-request'):
            call=calls(self.case(name))[0]; request=events(call,'scripted_cvfs_request')[0]
            self.assertEqual(request['requested_sectors'],0)
            self.assertEqual(call['after']['ring_u32'][3:5],[0,4096])
            self.assertEqual(field(call['after'],2,1),0)
        row=self.case('partial-sector-file-length')
        self.assertEqual(field(row['final'],0x54),1)
        self.assertEqual(field(row['final'],1,1),2)
        self.assertEqual(events(calls(row)[-1],'scripted_cvfs_request')[0]['requested_sectors'],0)

    def test_rejected_acceptance_and_error_return_entire_free_span(self):
        for name in ('zero-acceptance-returns-free','negative-acceptance-returns-free','pending-error-returns-free'):
            final=self.case(name)['final']
            self.assertEqual(final['ring_u32'][3:5],[0,4096])
            self.assertEqual(field(final,0x20),0); self.assertEqual(field(final,0x24),0)
        self.assertEqual(field(self.case('retry-limit-terminal')['final'],1,1),4)
        self.assertEqual(field(self.case('retry-limit-terminal')['final'],3,1),2)
        self.assertEqual(field(self.case('negative-retry-limit-no-increment')['final'],3,1),0)
        self.assertEqual(field(self.case('zero-acceptance-nonerror-status')['final'],3,1),0)

    def test_pause_gates_new_request_but_not_completion(self):
        operations=calls(self.case('pause-blocks-new-only'))
        self.assertEqual(events(operations[1],'scripted_cvfs_request'),[])
        self.assertEqual(operations[-1]['after']['ring_u32'][3:5],[4096,0])
        self.assertEqual(field(operations[-1]['after'],0x40,1),1)

    def test_stop_completes_pending_publication_before_stopped_state(self):
        values=calls(self.case('stop-pending-late-completion'))
        self.assertEqual(field(values[1]['after'],0x44,1),1)
        self.assertEqual(field(values[1]['after'],0x43,1),0)
        self.assertEqual(field(values[-2]['after'],1,1),2)
        self.assertEqual(values[-2]['after']['ring_u32'][3],4096)
        self.assertEqual(field(values[-1]['after'],1,1),1)
        self.assertEqual(field(values[-1]['after'],0x20),0)

    def test_close_is_deferred_and_clears_file_before_external_close_call(self):
        values=calls(self.case('close-deferred-until-completion'))
        for call in values[:-1]: self.assertEqual(events(call,'scripted_cvfs_close'),[])
        event=events(values[-1],'scripted_cvfs_close')[0]
        self.assertEqual(event['arguments_u64'][0],r.FILE)
        self.assertEqual(event['record_file_u32'],0)
        self.assertEqual(field(values[-1]['after'],0x45,1),0)

    def test_callback_and_finite_limit_are_distinct(self):
        target=calls(self.case('target-callback-exact'))[-1]
        callback=events(target,'target_callback')[0]
        self.assertEqual(callback['arguments_u64'][0],0x24681357)
        self.assertEqual(field(callback['observed_before'],0x54),1)
        self.assertEqual(field(callback['observed_before'],0x20),0)
        self.assertEqual(field(target['after'],1,1),2)
        finite=calls(self.case('finite-limit-terminal'))[-1]
        self.assertEqual(events(finite,'target_callback'),[])
        self.assertEqual(field(finite['after'],1,1),3)

    def test_reset_loses_reservation_without_return_or_provider_cancel(self):
        row=self.case('reset-loses-outstanding-reservation'); values=calls(row)
        reset=values[1]
        self.assertEqual(reset['after']['ring_u32'],reset['before']['ring_u32'])
        self.assertEqual(field(reset['after'],0x20),0)
        self.assertEqual(field(reset['after'],2,1),0)
        self.assertEqual(row['final']['ring_u32'][3:5],[0,0])
        self.assertTrue(row['final']['jobs'][0]['written'])
        self.assertEqual(events(reset,'scripted_cvfs_close'),[])

    def test_reuse_does_not_invent_generation_suppression_of_external_write(self):
        row=self.case('ring-reset-reuse-late-external-write')
        external=row['operations'][-1]['external_effect']
        self.assertEqual(backing(external['before'])[:2048],bytes([0xEE])*2048)
        self.assertNotEqual(backing(external['after'])[:2048],bytes([0xEE])*2048)
        self.assertEqual(external['before']['ring_u32'],external['after']['ring_u32'])
        self.assertEqual(row['final']['ring_u32'][3:5],[2048,2048])
        late=self.case('reset-close-late-external-write')['operations'][-1]['external_effect']
        self.assertTrue(late['before']['file_closed'])
        self.assertFalse(late['before']['jobs'][0]['written'])
        self.assertTrue(late['after']['jobs'][0]['written'])

    def test_script_bound_failures_are_partial_evidence_not_faked_results(self):
        inputs=dict(self.inputs['cases'][0]); inputs['actions']=[r.service(accept=3)]
        row=r.execute_case(inputs); result=calls(row)[0]
        self.assertEqual(result['status'],'partial_refusal')
        self.assertIn('Unspecified or unbounded',result['failure']['detail'])
        self.assertEqual(result['after']['ring_u32'][3:5],[0,0])
        machine=r.Machine(self.inputs['cases'][0]); machine.prepare()
        machine.jobs=[dict(observation_id=0,destination=r.BUFFER+4090,sector=0,accepted_sectors=2,written=False)]
        with self.assertRaisesRegex(r.OracleError,'destination exceeds'): machine.write_job(0)


if __name__=='__main__': unittest.main()
