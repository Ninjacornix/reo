"""Original-word clock replay and source identity; no game or native expected."""
import json
from pathlib import Path
import unittest
import adxt_integer_clock_oracle as clock

COHORT=clock.ROOT/'build-native-sjuni/adxt-integer-clock-original-v2'


class ClockOracleTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.plan=json.loads((COHORT/'input-manifest.json').read_bytes())
        cls.inputs=json.loads((COHORT/'inputs.json').read_bytes())['cases']
        cls.rows=json.loads((COHORT/'expected.json').read_bytes())
        cls.by_name={r['name']:r for r in cls.rows}

    def test_frozen_authority(self):
        self.assertEqual(clock.audit(),self.plan['source_audit'])
        self.assertEqual(clock.sha((COHORT/'inputs.json').read_bytes()),self.plan['inputs_sha256'])
        self.assertEqual(clock.sha(Path(clock.__file__).read_bytes()),self.plan['oracle_sha256'])
        for name,digest in self.plan['engines'].items():
            self.assertEqual(clock.sha(Path(clock.__file__).with_name(name).read_bytes()),digest)

    def test_every_original_transcript_replays_without_supplied_results(self):
        self.assertEqual(len(self.inputs),132)
        for case,expected in zip(self.inputs,self.rows,strict=True):
            with self.subTest(case=case['name']):self.assertEqual(clock.execute(case),expected)

    def test_active_rna_ratio_uses_actual_fixed_child(self):
        row=self.by_name['131f60-state-3']
        self.assertEqual(row['projection']['numerator_u32'],123)
        self.assertEqual(row['projection']['denominator_u32'],48000)
        self.assertIn(0x13eca0,row['result']['visited_pcs'])
        self.assertNotIn(0x13ecb0,row['result']['visited_pcs'])

    def test_queries_leave_source_fields_and_output_guards_unchanged(self):
        for case,row in zip(self.inputs,self.rows,strict=True):
            if case['entry']not in(0x131f60,0x132028):continue
            before,after=row['result']['before'],row['result']['after']
            for field in('main_hex','inner_hex','outer_hex','rings','globals_hex'):
                self.assertEqual(before[field],after[field],(case['name'],field))
            raw=bytes.fromhex(after['output_guard_hex'])
            self.assertEqual(raw[:16],bytes([0x5a])*16)
            self.assertEqual(raw[24:],bytes([0x5a])*24)

    def test_raw_query_reaches_both_actual_ring_count_calls(self):
        row=self.by_name['132028-queue-1-1-16383']
        self.assertIn(0x13fa38,row['result']['visited_pcs'])
        self.assertIn(0x13ecb0,row['result']['visited_pcs'])
        self.assertIn(0x132a08,row['result']['visited_pcs'])
        self.assertEqual(row['projection']['numerator_u32'],40017)
        self.assertEqual(row['result']['reads_by_pc']['13FA78'],2)
        self.assertEqual(row['result']['events'],[]) # Count getters have no guard.

    def test_null_output_ring_has_no_synthetic_ring_call(self):
        row=self.by_name['132028-queue-0-0-16384']
        self.assertEqual(row['projection']['numerator_u32'],40017)
        self.assertEqual(row['result']['reads_by_pc']['13FA78'],1)
        self.assertNotIn('13FA4C',row['result']['reads_by_pc'])
        self.assertEqual(row['result']['events'],[])

    def test_terminal_depth_helper_and_modulo_product_are_actual_words(self):
        row=self.by_name['132028-terminal-4294967295-2-2']
        self.assertIn(0x124e88,row['result']['visited_pcs'])
        self.assertEqual(row['projection']['numerator_u32'],0x7ffffff9)
        self.assertTrue(all(r['result']['status']=='returned'for r in self.rows))

    def test_counter_wrap_and_selector_preserve_unselected_ratio(self):
        self.assertEqual(self.by_name['counter-4294967295']['projection']['counter_u32'],0)
        self.assertEqual(self.by_name['select-1']['projection']['ratio_u32'],5994)
        self.assertEqual(self.by_name['select-2']['projection']['ratio_u32'],5000)
        self.assertEqual(self.by_name['select-0']['projection']['ratio_u32'],5994)


if __name__=='__main__':unittest.main()
