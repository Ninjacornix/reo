"""Check exact-source missing/shared-channel observations and corpus admission."""
import copy
import hashlib
import json
from pathlib import Path
import unittest

from pcm_source_domains_oracle import ROOT,input_transcript,validate_inputs,action_program,validate,sha


class SourceDomainTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.fixtures={}
        tool=Path(__file__).with_name('pcm_source_domains_oracle.py')
        for name in ('gcc','llvm'):
            output=ROOT/'build-native-sjuni/pcm-source-domains'/name
            proof=json.loads((output/'receipt.json').read_text())
            if proof['status']!='passed' or proof['tool_sha256']!=sha(tool):
                raise ValueError('Generate current compiler-specific source-domain fixtures first')
            if proof['fixture_sha256']!=sha(output/'fixtures.json'):
                raise ValueError('Frozen fixture identity differs')
            cls.fixtures[name]=json.loads((output/'fixtures.json').read_text())
        cls.rows=cls.fixtures['gcc']['records']
        cls.by={(row['case'],row['operation']):row for row in cls.rows}

    def test_exact_transcript_shape_and_separate_observations(self):
        inputs=input_transcript()
        self.assertEqual(inputs,input_transcript())
        self.assertEqual(len(inputs),19)
        self.assertEqual(validate(self.rows,inputs),dict(cases=19,snapshots=36,float_values=228,shared_cases=9))
        self.assertNotIn('pre_state',inputs[0])
        self.assertIn('int main()',action_program(inputs))

    def test_both_compilers_executed_the_complete_unchanged_source(self):
        for name,fixture in self.fixtures.items():
            proof=json.loads((ROOT/'build-native-sjuni/pcm-source-domains'/name/'receipt.json').read_text())
            self.assertFalse(proof['game_run']);self.assertFalse(proof['device_opened'])
            self.assertFalse(proof['assets_read'])
            self.assertEqual(proof['compile']['exit_code'],0)
            self.assertEqual(proof['execution']['exit_code'],0)
            source=ROOT/'build-native-sjuni/pcm-source-domains'/name/'snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp'
            self.assertEqual(sha(source),fixture['source_sha256']['Kernel/Syscalls/Helpers/CriAudio.cpp'])
            self.assertEqual(fixture['schema'],2)
            self.assertEqual(fixture['inputs'],input_transcript())
            self.assertEqual(validate(fixture['records'],fixture['inputs'])['snapshots'],36)

    def test_zero_left_skips_while_nonzero_missing_queue_accrues_debt(self):
        skipped=self.by[('left_zero_skip','zero_left')]
        voice=skipped['state']['voices'][0]
        self.assertEqual((voice['left'],voice['late'],voice['phase_bits']),(0,0,0))
        self.assertEqual(skipped['state']['underrun_frames'],skipped['pre_state']['underrun_frames'])
        self.assertEqual(skipped['float_bits'],[0]*6)
        missing=self.by[('left_zero_skip','nonzero_missing_left')]
        self.assertEqual(missing['state']['voices'][0]['late'],4)
        self.assertEqual(missing['state']['underrun_frames']-missing['pre_state']['underrun_frames'],2)
        self.assertEqual(self.by[('missing_left_queue','starve')]['state']['voices'][0]['late'],3)

    def test_missing_right_preserves_existing_left_and_late_pairs_repay_together(self):
        for case,operation in (('stereo_right_zero','missing_right_zero'),('stereo_right_missing','starve')):
            row=self.by[(case,operation)]
            self.assertEqual(row['pre_state']['channels'],row['state']['channels'])
            self.assertEqual(row['state']['voices'][0]['late'],3)
            self.assertEqual(row['float_bits'],[0]*6)
        for case,skipped in (('stereo_right_missing',3),('stereo_left_missing',2)):
            row=self.by[(case,'refill')]
            self.assertEqual(row['state']['voices'][0]['skipped'],skipped)
            self.assertEqual(row['state']['voices'][0]['late'],0)
            left,right=row['state']['channels']
            self.assertEqual(left['consumed_bytes'],right['consumed_bytes'])

    def test_disabled_voice_still_gets_gain_without_consuming_or_starving(self):
        row=self.by[('disabled_channels','disabled')]
        self.assertEqual(row['declared_raw_order'],[10])
        self.assertEqual(row['gain_read_order'],[10])
        self.assertEqual(row['pre_state']['channels'],row['state']['channels'])
        self.assertTrue(row['state']['voices'][0]['playing'])
        self.assertEqual(row['state']['voices'][0]['channels'],0)
        self.assertEqual(row['state']['voices'][0]['late'],0)
        self.assertEqual(row['state']['underrun_frames'],row['pre_state']['underrun_frames'])

    def test_raw_voice_zero_is_a_real_source_record(self):
        row=self.by[('raw_voice_zero','voice_zero')]
        self.assertEqual(row['declared_raw_order'],[0])
        self.assertEqual(row['gain_read_order'],[0])
        self.assertEqual(row['state']['voices'][0]['key'],0)
        self.assertEqual(row['state']['channels'][0]['consumed_bytes'],6)
        self.assertTrue(any(row['float_bits']))
        released=self.by[('raw_voice_zero','released_zero')]
        self.assertEqual(released['state']['voices'],[])
        self.assertEqual(released['state']['channels'][0]['sample_count'],5)

    def test_raw_channel_count_and_frequency_are_source_normalized(self):
        first=self.by[('channels_clamp','channels3')]['state']['voices'][0]
        self.assertEqual((first['channels'],first['frequency'],first['volume']),(2,48000,0xFFFFFFFF))
        paused=self.by[('channels_clamp','paused_max_channels')]
        self.assertEqual((paused['state']['voices'][0]['channels'],paused['state']['voices'][0]['frequency']),(2,96000))
        self.assertFalse(paused['state']['voices'][0]['playing'])
        self.assertEqual(paused['pre_state']['channels'],paused['state']['channels'])

    def test_shared_voice_graphs_are_recorded_without_deduplicating_consumption(self):
        cases={r['case'] for r in self.rows if r['case'].startswith(('shared_','cross_'))}
        self.assertEqual(len(cases),9)
        for case in cases:
            first=next(r for r in self.rows if r['case']==case)
            voices=first['pre_state']['voices']
            references=[key for v in voices for key in ([v['left'],v['right']] if v['channels']>1 else [v['left']])]
            self.assertLess(len(set(references)),len(references))
            self.assertEqual(first['declared_raw_order'],first['gain_read_order'])
            self.assertTrue(all(v['left']!=v['right'] for v in voices if v['channels']>1))
        three=self.by[('shared_three_mixed','three_voice_share')]
        self.assertEqual(set(three['declared_raw_order']),{10,20,30})

    def test_shared_drain_pause_and_release_keep_independent_record_semantics(self):
        row=self.by[('shared_drain_pause','drain_overrides_false')]
        draining=next(v for v in row['state']['voices'] if v['key']==20)
        self.assertTrue(draining['playing']);self.assertTrue(draining['draining'])
        tail=self.by[('shared_drain_pause','drain_tail')]
        self.assertTrue(all(not v['playing'] and not v['draining'] for v in tail['state']['voices']))
        released=self.by[('shared_drain_pause','release_retains_channel')]
        self.assertEqual(released['state']['raw_voice_order'],[10])
        self.assertEqual(released['state']['channels'],tail['state']['channels'])

    def test_unknown_consumed_query_ticks_without_creating_an_unknown_channel(self):
        row=self.by[('headless_unknown_consumed','unknown_query')]
        self.assertTrue(row['result_is_defined']);self.assertEqual(row['result_u64'],0)
        self.assertEqual(row['state']['channels'][0]['consumed_bytes'],8)
        self.assertEqual([c['key'] for c in row['state']['channels']],[1])
        self.assertFalse(row['state']['frame_clock'])
        self.assertEqual(row['state']['output_frames']-row['pre_state']['output_frames'],4)
        same=self.by[('headless_unknown_consumed','known_query_same_time')]
        self.assertEqual(same['result_u64'],8);self.assertEqual(same['gain_read_order'],[])

    def test_configure_ticks_before_new_voice_insertion_and_gain_cache_refresh(self):
        row=self.by[('headless_configure_before_insert','insert_after_tick')]
        self.assertEqual(row['declared_raw_order'],[10]);self.assertEqual(row['gain_read_order'],[10])
        self.assertEqual([v['key'] for v in row['pre_state']['voices']],[10])
        self.assertEqual([v['key'] for v in row['state']['voices']],[10,20])
        self.assertEqual(row['state']['channels'][0]['consumed_bytes'],4)
        new=next(v for v in row['state']['voices'] if v['key']==20)
        self.assertNotEqual(new['gain_bits'],new['cached_mixer_gain_bits'])
        later=self.by[('headless_configure_before_insert','both_after_insert')]
        self.assertEqual(later['gain_read_order'],later['declared_raw_order'])
        self.assertEqual(later['result_u64'],4)
        self.assertTrue(all(v['gain_bits']==v['cached_mixer_gain_bits'] for v in later['state']['voices']))

    def test_zero_frame_render_selects_clock_and_reads_gains_without_progress(self):
        row=self.by[('headless_configure_before_insert','select_frame_clock')]
        self.assertFalse(row['pre_state']['frame_clock']);self.assertTrue(row['state']['frame_clock'])
        self.assertEqual(row['float_bits'],[])
        self.assertEqual(row['gain_read_order'],row['declared_raw_order'])
        self.assertEqual(row['state']['output_frames'],row['pre_state']['output_frames'])
        self.assertEqual(row['state']['channels'],row['pre_state']['channels'])

    def test_self_alias_is_rejected_before_generating_or_executing_source(self):
        for key in (0,1):
            inputs=input_transcript()
            config=next(a for a in inputs[0]['actions'] if a['kind']=='configure')
            config.update(left=key,right=key,channels=2)
            with self.assertRaises(ValueError):validate_inputs(inputs)
            with self.assertRaises(ValueError):action_program(inputs)

    def test_corrupt_transcript_order_gain_trace_and_snapshot_extents_reject(self):
        inputs=input_transcript()
        for mutation in ('truncate','gain','queue','order','pcm'):
            rows=copy.deepcopy(self.rows)
            if mutation=='truncate':rows.pop()
            elif mutation=='gain':rows[0]['gain_read_order']=[]
            elif mutation=='queue':rows[1]['state']['channels']=[dict(key=1,queued_bytes=2,consumed_bytes=4,sample_count=0,samples_i16=[])]
            elif mutation=='order':rows[0]['declared_raw_order']=[99]
            elif mutation=='pcm':rows[0]['float_bits'].pop()
            with self.subTest(mutation=mutation),self.assertRaises(ValueError):validate(rows,inputs)


if __name__=='__main__':unittest.main()
