"""Owned original-word composition evidence; no native Window2 imports."""
import json
from pathlib import Path
import unittest

import adx_shared_window_oracle as s

DIRECTORY=s.ROOT/'build-native-sjuni/adx-shared-window-oracle-v14'
MANIFEST_SHA='e41b48940b06b95d5b5641160225e10b0902dd5808d9eaf1dca5b1aa0b127972'
INPUT_SHA='d3adee3434a56a218b6a67040ee44a2df99b1cdd813bcaf15c067d8d0adb4d46'


def word(state,name,offset):
    return int.from_bytes(bytes.fromhex(state[name])[offset:offset+4],'little',signed=True)


def results(case):
    return [result for op in case['operations'] for result in
            (op['results'] if isinstance(op['results'],list) else [op['results']])]


def events(case,name):
    return [event for result in results(case) for event in result['events'] if event.get('name',event['kind'])==name]


def action_result(case,kind,index=0):
    return [op['results'] for op in case['operations'] if op['input']['kind']==kind][index]


class SharedOriginalTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        raw=(DIRECTORY/'manifest.json').read_bytes()
        if s.sha(raw)!=MANIFEST_SHA:raise AssertionError('Frozen original manifest changed')
        cls.manifest=json.loads(raw);cls.rows={}
        for entry in cls.manifest['cases']:
            raw=(DIRECTORY/entry['file']).read_bytes()
            if s.sha(raw)!=entry['sha256']:raise AssertionError('Frozen original case changed')
            cls.rows[entry['name']]=json.loads(raw)

    def test_authored_inputs_before_expectations_and_exact_source_identity(self):
        raw=(DIRECTORY/'inputs.json').read_bytes()
        self.assertEqual(s.sha(raw),INPUT_SHA)
        self.assertEqual(s.sha(s.serialized(s.corpus_inputs())),INPUT_SHA)
        self.assertNotIn('expected',json.dumps(s.corpus_inputs()))
        self.assertEqual(self.manifest['oracle_sha256'],s.sha(Path(s.__file__).read_bytes()))
        for name,digest in self.manifest['engine_sha256'].items():
            self.assertEqual(s.sha(Path(s.__file__).with_name(name).read_bytes()),digest)
        self.assertEqual(len(self.manifest['body_sha256']),163)
        self.assertEqual(self.manifest['source_word_audit']['matched_comments'],5654)
        self.assertEqual(len(self.manifest['source_word_audit']['omitted_zero_pcs']),92)

    def test_all_six_complete_ready_configurations_and_actual_setter_children(self):
        for rate,finite,loop in [(24000,640,1216),(44100,1152,2240),(48000,1216,2432)]:
            for mode,request in [('finite',finite),('loop',loop)]:
                row=self.rows[f'ready-{rate}-{mode}'];r=action_result(row,'ready')
                self.assertEqual(r['status'],'returned')
                self.assertEqual(word(r['after'],'outer_hex',0x38),request)
                self.assertEqual(word(r['after'],'inner_hex',0xB4),request)
                self.assertEqual(word(r['after'],'inner_hex',0xB8),request//96)
                self.assertEqual(word(r['after'],'inner_hex',0xC0),request)
                self.assertEqual(word(r['after'],'inner_hex',0xC4),request//1536)
                self.assertIn(0x123020,r['visited_pcs']);self.assertIn(0x122E70,r['visited_pcs'])
                self.assertTrue(any(e['kind']=='external_rna_control' for e in r['events']))

    def test_long_accounting_crosses_all_prior_caps_without_resets(self):
        for name in ('long-mono-44100','long-stereo-48000','long-downmix-24000'):
            row=self.rows[name];states=[op['results']['after'] for op in row['operations'] if op['input']['kind']=='decode']
            counts=[word(state,'outer_hex',0x2C) for state in states]
            self.assertEqual(counts,sorted(counts));self.assertGreater(max(counts),32768)
            self.assertEqual(counts[-1],40017);self.assertEqual(word(row['final'],'outer_hex',0x34),40017)
            self.assertTrue(any(4096<a<8192 for a in counts));self.assertTrue(any(8192<a<32768 for a in counts))
            self.assertTrue(row['final']['jobs']);self.assertFalse(any(r['failure'] for r in results(row)))

    def test_real_full_loop_requests_reach_actual_codec(self):
        for name,route,blocks in [('full-loop-request-44100-1-0','mono',70),
                ('full-loop-request-48000-1-0','mono',76),('full-loop-request-44100-2-1','downmix',140)]:
            self.assertEqual(max(e['arguments_u64'][1] for e in events(self.rows[name],route)),blocks)

    def test_repeated_loop_snapshot_restore_padding_and_counter(self):
        row=self.rows['file-loop-first-and-repeat']
        for name in ('first_loop_snapshot','repeat_loop','snapshot_history_key','restore_history_key'):
            self.assertTrue(events(row,name))
        self.assertEqual(word(row['final'],'main_hex',0x4C),1)
        self.assertEqual(word(row['final'],'outer_hex',0x3C),96)
        short=self.rows['repeat-padding-short-diagnostic'];self.assertTrue(events(short,'diagnostic'))
        self.assertEqual(word(short['final'],'main_hex',0x4C),1)

    def test_pending_producer_coexists_with_two_positive_consumer_grants(self):
        row=self.rows['seamless-pending-producer-two-grants'];scans=events(row,'aligned_header_scan')
        self.assertEqual(len(scans),2)
        self.assertTrue(all(e['arguments_u64'][1]>0 for e in scans))
        self.assertTrue(all(bytes.fromhex(e['state']['source_hex'])[2]==1 for e in scans))
        self.assertTrue(all(e['state']['rings'][0][3]+e['state']['rings'][0][4]<8192 for e in scans))
        self.assertEqual(word(row['final'],'inner_hex',0x14),48000)
        self.assertEqual(word(row['final'],'outer_hex',0x2C),96)

    def test_partial_and_error_provider_disposition_remains_real(self):
        partial=self.rows['seamless-pending-partial-acceptance'];req=events(partial,'scripted_cvfs_request')[0]
        self.assertEqual(req['accepted_sectors'],1);self.assertGreater(req['requested_sectors'],1)
        self.assertEqual(word(partial['final'],'outer_hex',0x2C),96)
        error=self.rows['seamless-pending-error-return']
        self.assertTrue(any(e.get('return_i32')==3 for e in events(error,'scripted_cvfs_status')))
        self.assertFalse(error['final']['jobs'][0]['written'])
        self.assertEqual(error['final']['rings'][0][3]+error['final']['rings'][0][4],8192)

    def test_file_target_mutation_controls_postcallback_terminal_branch(self):
        enabled=self.rows['file-target-at-physical-end-loop-1'];disabled=self.rows['file-target-at-physical-end-loop-0']
        for row in (enabled,disabled):
            callback=events(row,'file_target_loop')[0]
            self.assertEqual(word(callback['state'],'source_hex',0x54),2)
            self.assertEqual(word(callback['state'],'source_hex',0x30),2048)
            self.assertEqual(word(callback['state'],'source_hex',0x24),0)
        self.assertEqual(word(enabled['final'],'source_hex',0x54),0)
        self.assertEqual(bytes.fromhex(enabled['final']['source_hex'])[1],2)
        self.assertEqual(word(disabled['final'],'source_hex',0x54),2)
        self.assertEqual(bytes.fromhex(disabled['final']['source_hex'])[1],3)
        self.assertEqual(word(disabled['final'],'outer_hex',0x3C),-1)

    def test_seamless_failure_keeps_consumed_prefix_and_selective_resets(self):
        rejected=self.rows['seamless-next-header-reject'];deferred=self.rows['seamless-header-defer-after-prefix']
        self.assertEqual(bytes.fromhex(rejected['final']['outer_hex'])[1],4)
        self.assertEqual(bytes.fromhex(deferred['final']['outer_hex'])[1],1)
        for row in (rejected,deferred):
            self.assertEqual(bytes.fromhex(row['final']['main_hex'])[0x98],0)
            self.assertEqual(word(row['final'],'main_hex',0xA4),64)
            self.assertGreater(row['final']['rings'][0][11],0)
            self.assertEqual(word(row['final'],'outer_hex',0x2C),0)

    def test_missing_magic_restores_grants_in_real_source_order(self):
        row=self.rows['seamless-no-next-magic'];r=action_result(row,'decode',1)
        self.assertEqual(bytes.fromhex(row['final']['main_hex'])[0x98],0)
        ungets=[e for e in r['events'] if e.get('name')=='ring_unget']
        self.assertGreaterEqual(len(ungets),2)
        self.assertGreater(ungets[0]['arguments_u64'][2],ungets[1]['arguments_u64'][2])
        gets=[e for e in r['events'] if e.get('name')=='ring_get' and e['arguments_u64'][:2]==[s.window.POOL,1]]
        # First two are inside the callback; the third is the enclosing call's
        # resumed input admission. Later outer end-marker handling may consume.
        self.assertGreaterEqual(len(gets),3)
        self.assertEqual(gets[0]['state']['rings'][0][3:5],gets[2]['state']['rings'][0][3:5])

    def test_stop_is_not_accepted_publication_cancellation(self):
        row=self.rows['producer-stop-accepted-publication'];stop=action_result(row,'call')
        self.assertEqual(bytes.fromhex(stop['after']['source_hex'])[0x44],1)
        self.assertEqual(bytes.fromhex(stop['after']['source_hex'])[2],1)
        self.assertTrue(row['final']['jobs'][0]['written'])
        self.assertEqual(word(row['final'],'source_hex',0x30),2048)
        self.assertGreater(row['final']['rings'][0][3],0)

    def test_partial_cuts_are_not_success_or_native_admission(self):
        expected={'seamless-negative-record-length':0x126688,'seamless-next-header-math-cut':0x120AE8,
                  'repeat-without-file-disabled':0x1307B4,'ready-insufficient-channel-cut':0x1282A0}
        self.assertEqual({row['name']:row['pc'] for row in self.manifest['summary']['partial']},expected)
        for name,pc in expected.items():
            failure=next(r['failure'] for r in results(self.rows[name]) if r['failure'])
            self.assertEqual(failure['pc'],pc)
            self.assertEqual(results(self.rows[name])[-1]['status'],'partial_refusal')

    def test_exact_backing_deltas_reconstruct_every_observable_write_and_guards(self):
        for row in self.rows.values():
            backings=[bytearray.fromhex(data) for data in row['initial_backings_hex']]
            for result in results(row):
                for backing,effect in zip(backings,result['backing_effects']):
                    self.assertEqual(s.sha(backing),effect['before_sha256'])
                    end=0
                    for change in effect['changes']:
                        offset=change['offset'];before=bytes.fromhex(change['before_hex']);after=bytes.fromhex(change['after_hex'])
                        self.assertGreaterEqual(offset,end);self.assertEqual(len(before),len(after))
                        self.assertEqual(backing[offset:offset+len(before)],before)
                        backing[offset:offset+len(after)]=after;end=offset+len(after)
                    self.assertEqual(s.sha(backing),effect['after_sha256'])
            for backing,digest in zip(backings,row['final']['backing_sha256']):self.assertEqual(s.sha(backing),digest)
            # PCM planes are contiguous, so per-plane windows overlap actual
            # adjacent PCM. Only the arena's outer edges are guards.
            self.assertEqual(backings[0][:16],b'\xA5'*16);self.assertEqual(backings[0][-16:],b'\xA5'*16)
            self.assertEqual(backings[1][:16],b'\xA5'*16);self.assertEqual(backings[-1][-16:],b'\xA5'*16)
            self.assertEqual(row['final']['caller_guard_hex'],'cc'*32)
            self.assertEqual(row['final']['lower_stack_guard_hex'],'cc'*32)

    def test_current_gcc_and_llvm_workers_replay_complete_selected_boundaries(self):
        names={'ready-24000-finite','ready-24000-loop','ready-44100-finite','ready-44100-loop',
               'ready-48000-finite','ready-48000-loop','seamless-pending-producer-two-grants',
               'file-target-at-physical-end-loop-1','seamless-next-header-reject','seamless-header-defer-after-prefix'}
        bodies=s.owned_bodies();inputs=s.corpus_inputs()
        for compiler in ('gcc','llvm'):
            binary=s.ROOT/f'build-native-sjuni/adx-header-math-oracle-v4/{compiler}/fp_worker.exe'
            parent=json.loads(binary.with_name('original-fixture.json').read_bytes())
            self.assertIn(s.sha(binary.with_name('original-fixture.json').read_bytes()),s.FP_PARENT_SHA256)
            self.assertEqual(s.sha(binary.read_bytes()),parent['compatibility']['worker_binary_sha256'])
            with s.math.FpuWorker(binary) as worker:
                for case in inputs['cases']:
                    if case['name'] in names:
                        with self.subTest(compiler=compiler,name=case['name']):
                            self.assertEqual(s.execute_case(case,worker,bodies),self.rows[case['name']])


if __name__=='__main__':unittest.main()
