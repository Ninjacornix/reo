"""Bounded original transaction/branch checks, no native window implementation."""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

import adx_window_oracle as w

FIXTURE = w.ROOT / 'build-native-sjuni/adx-window-oracle-v5/original-fixture.json'
FIXTURE_SHA = '62dfa91bf99698bc10c84356e8320912967cefadbd6a83feb95f453122fafeff'
INPUT_SHA = '55a7b1bdda757fbeeb764e3766453b062bab9f692e5da7f2ea23eefe5d8dcbee'


def word(state, name, offset):
    return int.from_bytes(bytes.fromhex(state[name])[offset:offset+4], 'little', signed=True)


def calls(case):
    return [result for op in case['operations'] for result in
            ([op['expected']] if isinstance(op['expected'], dict) else op['expected'])]


def callbacks(result):
    return [event for event in result['events'] if event['kind'] == 'pcm_callback']


class BranchTests(unittest.TestCase):
    def test_both_regimm_likely_conditions_signed64(self):
        machine = w.Machine(w.corpus_inputs()['cases'][0])
        for value, negative in [(0,False),(1,False),(-1,True),(1<<31,False),(-(1<<63),True),((1<<63)-1,False)]:
            machine.regs[3] = value & ((1 << 64)-1)
            for rt in (2,3):
                branch = machine.instruction(0x1000, (1<<26)|(3<<21)|(rt<<16)|5)
                self.assertEqual(branch, (negative if rt == 2 else not negative, 0x1018, True))

    def test_real_runner_annuls_false_delay_and_preserves_taken_delay(self):
        for rt in (2,3):
            for value, negative in [(0,False),(-1,True)]:
                machine = w.Machine(w.corpus_inputs()['cases'][0])
                machine.code = {0x1000:(1<<26)|(4<<21)|(rt<<16)|3,
                    0x1004:0x24020007, 0x1008:0x03E00008, 0x100C:0,
                    0x1010:0x03E00008, 0x1014:0}
                result = machine.run(0x1000,[value],full=False)
                self.assertEqual(result['status'],'returned')
                taken = negative if rt == 2 else not negative
                self.assertEqual(result['raw_v0_lower64_observation_only'], 7 if taken else 0xBAD0BAD0)
                self.assertEqual(0x1004 in result['visited_pcs'], taken)

    def test_exact_original_bltzl_emission_gcc_llvm(self):
        w.implementation_identity()
        path = w.ROOT / 'build-native-sjuni/candidate-work-v6/project/recomp/config/output/sub_0012CEB8_0x12ceb8.cpp'
        source = path.read_text()
        emitted = source[source.index('    // 0x12cf88:'):source.index('    // 0x12cf90:')]
        self.assertIn('GPR_S64(ctx, 3) < 0', emitted)
        self.assertIn('if (branch_taken_0x12cf88)', emitted)
        self.assertIn('goto label_12cfa0', emitted)
        harness = '''#include <bit>
#include <cstdint>
#include <cstdio>
struct Context { uint64_t r[32]{}; uint32_t pc{}, branch_pc{}; bool in_delay_slot{}; };
#define GPR_S64(c,n) std::bit_cast<int64_t>((c)->r[n])
#define SET_GPR_S32(c,n,v) ((c)->r[n]=uint64_t(int64_t(int32_t(v))))
void execute(Context* ctx) { EMISSION return; label_12cfa0: return; }
int main() { CASES puts("Exact BLTZL emission passed"); }
'''.replace('EMISSION',emitted)
        cases = []
        for value, negative in [(0,False),(1,False),(-1,True),(1<<31,False),(-(1<<63),True),((1<<63)-1,False)]:
            bits = value & ((1<<64)-1)
            cases.append('{ Context c; c.r[3]=%dull; c.r[2]=0xBAD0BAD0; execute(&c); '
                         'if(c.pc!=%du || c.r[2]!=%dull || c.in_delay_slot) return 1; }' %
                         (bits, 0x12CFA0 if negative else 0x12CF90, 0x1FFF0000 if negative else 0xBAD0BAD0))
        harness = harness.replace('CASES','\n'.join(cases))
        root = w.ROOT / 'build-native-sjuni/adx-window-isa-checks'; root.mkdir(parents=True,exist_ok=True)
        observations = []
        with tempfile.TemporaryDirectory(prefix='branch-',dir=root) as directory:
            cpp = Path(directory)/'check.cpp'; cpp.write_text(harness)
            for name in ('g++','clang++'):
                compiler = shutil.which(name); self.assertIsNotNone(compiler)
                exe = Path(directory)/(name.replace('+','p')+'.exe')
                compiled = subprocess.run([compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror',str(cpp),'-o',str(exe)],capture_output=True,text=True)
                self.assertEqual(compiled.returncode,0,compiled.stderr)
                ran = subprocess.run([str(exe)],capture_output=True,text=True)
                self.assertEqual(ran.returncode,0,ran.stderr)
                observations.append(dict(compiler=compiler,compiler_sha256=w.sha(Path(compiler).read_bytes()),
                    binary_sha256=w.sha(exe.read_bytes()),stdout=ran.stdout))
        with tempfile.NamedTemporaryFile(prefix='qualification-',suffix='.json',dir=root,delete=False) as receipt:
            receipt.write(w.serialized(dict(schema=1,synthetic=True,harness_source=harness,harness_sha256=w.sha(harness.encode()),
                generated_source_sha256=w.sha(path.read_bytes()),isa_reference=w.implementation_identity(),compilers=observations)))


class WindowTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        data = FIXTURE.read_bytes()
        if w.sha(data) != FIXTURE_SHA: raise AssertionError('Frozen original fixture changed')
        cls.fixture = json.loads(data); cls.rows = {row['name']:row for row in cls.fixture['cases']}

    def case(self, name): return self.rows[name]

    def test_frozen_authored_inputs_and_current_source_identity(self):
        self.assertEqual(w.sha(w.serialized(w.corpus_inputs())),INPUT_SHA)
        self.assertNotIn('expected',json.dumps(w.corpus_inputs()))
        self.assertEqual(self.fixture['inputs_sha256'],INPUT_SHA)
        for name,sha in self.fixture['engine_sha256'].items():
            self.assertEqual(w.sha(Path(w.__file__).with_name(name).read_bytes()),sha)

    def test_complete_source_audit_and_real_engines(self):
        audit = w.source_audit(w.ROOT/'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
        self.assertEqual(audit['matched_comments'],2146)
        self.assertEqual(len(audit['omitted_zero_pcs']),30)
        self.assertEqual(self.fixture['summary']['failed_cases'],[])
        self.assertEqual(self.fixture['summary']['original_instructions'],118066)
        self.assertEqual(self.fixture['summary']['unique_visited_words'],1879)

    def test_live_replay_of_entire_frozen_transcript(self):
        transcript = w.corpus_inputs()
        for inputs in transcript['cases']:
            with self.subTest(name=inputs['name']):
                self.assertEqual(w.execute_case(inputs,transcript['profile']),self.case(inputs['name']))

    def test_all_final_guards_table_and_balanced_borrows(self):
        for row in self.rows.values():
            final = row['final']
            for name in ('encoded_backing_guard_hex','pcm_arena_guard_hex'):
                data = bytes.fromhex(final[name])
                self.assertEqual(data[:16],b'\xa5'*16); self.assertEqual(data[-16:],b'\xa5'*16)
            self.assertEqual(final['lower_stack_guard_hex'],'cc'*32)
            self.assertEqual(final['caller_guard_hex'],'cc'*32)
            self.assertEqual(final['original_table_sha256'],row['initial']['original_table_sha256'])
            for ring in final['rings']:
                self.assertEqual(ring[3]+ring[4],ring[8])
            for result in calls(row):
                self.assertEqual(result['status'],'returned')
                self.assertFalse(any(event['kind'] in ('error_callback','diagnostic') for event in result['events']))

    def test_actual_mono_stereo_downmix_and_phase_closure(self):
        for name,route,consumed,completed in [('mono-four-blocks','mono',72,4),('stereo-four-pairs','normal_stereo',144,8),('downmix-four-pairs','downmix',144,8)]:
            row = self.case(name); result = calls(row)[0]
            self.assertIn(route,[trace['name'] for trace in result['traces']])
            self.assertEqual(word(row['final'],'outer_hex',0x34),128)
            self.assertEqual(word(row['final'],'outer_hex',0x30),consumed)
            self.assertEqual(word(row['final'],'predictor_hex',0x10),completed)
            self.assertEqual(word(row['final'],'predictor_hex',0xC),0)
            self.assertEqual(word(row['final'],'inner_hex',4),0)
            self.assertEqual(word(row['final'],'inner_hex',0x8C),0)

    def test_real_callbacks_and_publication_order(self):
        result = calls(self.case('stereo-four-pairs'))[0]; events = callbacks(result)
        self.assertEqual([event['arguments_u64'][1] for event in events],[0,1])
        for event in events:
            self.assertEqual(event['depth_before'],0)
            self.assertEqual(event['observed_before']['rings'][0][3:5],[0,2048])
            self.assertEqual(event['write_index_before'],event['write_index_after'])
        self.assertEqual(events[0]['observed_before']['rings'][1][3],0)
        self.assertEqual(events[1]['observed_before']['rings'][1][3],256)
        names = [trace['name'] for trace in result['traces']]
        self.assertLess(names.index('reserve_output'),names.index('budget'))
        self.assertLess(names.index('result_wrap'),names.index('default_complete'))
        self.assertLess(names.index('default_complete'),names.index('publication'))
        self.assertLess(names.index('publication'),names.index('outer_ack'))

    def test_zero_progress_returns_all_reservations(self):
        for name,remaining in [('mono-empty',0),('mono-short-three-bytes',3),('mono-zero-budget',72),('mono-zero-output-request',72)]:
            row = self.case(name)
            self.assertEqual(word(row['final'],'outer_hex',0x34),0)
            self.assertEqual(row['final']['rings'][0][3],remaining)
            self.assertEqual(row['final']['rings'][1][4],16384)
            self.assertEqual(row['final']['predictor_hex'][0x28*2:0x34*2],row['initial']['predictor_hex'][0x28*2:0x34*2])

    def test_partial_sample_budget_is_distinct_from_outer_total_clamp(self):
        for name,encoded in [('mono-partial-budget-35',36),('stereo-partial-budget-35',72),('downmix-partial-budget-35',72)]:
            row = self.case(name)
            self.assertEqual(word(row['final'],'inner_hex',0x90),35)
            self.assertEqual(word(row['final'],'inner_hex',0x94),encoded)
            self.assertTrue(all(ring[3] == 70 for ring in row['final']['rings'][1:]))
        row = self.case('outer-total-clips-to-35')
        self.assertEqual(word(row['final'],'outer_hex',0x34),35)
        self.assertEqual(word(row['final'],'inner_hex',0x90),128)
        self.assertEqual(word(row['final'],'inner_hex',0x94),72)
        self.assertEqual(row['final']['rings'][1][3],70)

    def test_real_input_wrap_and_suffix_survival(self):
        for name,samples in [('mono-input-wrap-split',256),('stereo-input-wrap-split',128)]:
            row = self.case(name)
            self.assertEqual(word(row['final'],'outer_hex',0x34),samples)
            self.assertEqual(row['final']['rings'][0][3],0)
            self.assertEqual(row['final']['rings'][0][5:7],[116,116])
        self.assertEqual(self.case('mono-unconsumed-tail-byte')['final']['rings'][0][3],1)
        self.assertEqual(self.case('stereo-odd-input-blocks')['final']['rings'][0][3],18)

    def test_output_wrap_copy_precedes_observer_and_sjrb_publication(self):
        for name,channels in [('mono-output-wrap',1),('stereo-output-wrap',2),('downmix-output-wrap',2)]:
            row = self.case(name); result = calls(row)[0]; copies = [t for t in result['traces'] if t['name']=='halfword_copy']
            self.assertEqual(len(copies),channels)
            self.assertTrue(all(t['arguments_u64'][2] == 16 for t in copies))
            observed = callbacks(result)
            for event in observed:
                self.assertGreater(event['write_index_before'],copies[-1]['write_index'])
            arena = bytes.fromhex(row['final']['pcm_arena_guard_hex'])[16:-16]
            for i in range(channels):
                base = i*w.PCM_PHYSICAL
                self.assertEqual(arena[base:base+32],arena[base+w.PCM_CAP:base+w.PCM_CAP+32])
                self.assertEqual(row['final']['rings'][i+1][5],32)

    def test_backpressure_recovery_and_no_hidden_decode(self):
        for name in ('mono-backpressure-recover','stereo-backpressure-recover'):
            row = self.case(name); first = calls(row)[0]
            self.assertNotIn('budget',[t['name'] for t in first['traces']])
            self.assertEqual(word(first['after'],'outer_hex',0x34),0)
            self.assertEqual(word(row['final'],'outer_hex',0x34),32)
            self.assertTrue(all(ring[3]==16352 for ring in row['final']['rings'][1:]))

    def test_markers_keep_prefix_pcm_and_key_but_uncommitted_histories(self):
        for name,samples in [('mono-marker-first',0),('mono-marker-after-prefix',64),('stereo-left-marker-after-prefix',32),('stereo-right-marker-after-prefix',32),('downmix-right-marker-after-prefix',32)]:
            row = self.case(name)
            self.assertEqual(word(row['final'],'outer_hex',0x34),samples)
            self.assertEqual(row['final']['predictor_hex'][0x28*2:0x30*2],row['initial']['predictor_hex'][0x28*2:0x30*2])
            self.assertEqual(word(row['final'],'predictor_hex',0x10),samples//32*(1 if name.startswith('mono') else 2))
            if samples:
                self.assertNotEqual(row['final']['predictor_hex'][0x34*2:0x36*2],row['initial']['predictor_hex'][0x34*2:0x36*2])

    def test_end_marker_padding_differs_from_ordinary_zero_blocks(self):
        for name in ('outer-end-marker','outer-end-marker-then-padding','outer-end-marker-then-ordinary-block'):
            row = self.case(name)
            self.assertEqual(bytes.fromhex(row['final']['outer_hex'])[1],3)
            self.assertEqual(word(row['final'],'outer_hex',0x34),0)
            self.assertNotIn('mono',[t['name'] for result in calls(row) for t in result['traces']])
        self.assertEqual(self.case('outer-end-marker-then-padding')['final']['rings'][0][3],0)
        self.assertEqual(self.case('outer-end-marker-then-ordinary-block')['final']['rings'][0][3],18)
        self.assertEqual(self.case('zero-filled-block-source-observation')['final']['rings'][0][3],6)
        self.assertEqual(word(self.case('zero-filled-block-source-observation')['final'],'outer_hex',0x34),32)

    def test_constructor_default_reservation_helper_not_a_fake_ring_reserve(self):
        row = self.case('inner-constructor-default-reserve'); result = calls(row)[0]
        self.assertEqual(result['entry'],0x124810)
        self.assertEqual(result['raw_v0_lower64_observation_only'],w.PCM)
        raw = bytes.fromhex(result['after']['scratch_hex'])
        self.assertEqual([int.from_bytes(raw[4+i*4:8+i*4],'little') for i in range(3)],[7,8185,988])
        self.assertEqual(result['before']['rings'],result['after']['rings'])

    def test_missing_callback_and_bounded_domain_refusals(self):
        self.assertFalse(callbacks(calls(self.case('no-publication-callback'))[0]))
        for changes in [dict(channels=3),dict(channels=2,pcm_positions=[0,2],occupied_pcm_bytes=[0,0]),
                        dict(pcm_positions=[16384]),dict(encoded_hex='12'*513)]:
            inputs = dict(w.corpus_inputs()['cases'][0]); inputs.update(changes)
            with self.assertRaises(w.OracleError): w.Machine(inputs)

    def test_readonly_tables_and_unknown_instructions_fail_closed(self):
        m = w.Machine(w.corpus_inputs()['cases'][0]); m.mem.active = True
        with self.assertRaises(w.OracleError): m.mem.store(w.TABLE,1,0)
        m.mem.active = False; m.code = {0x1000:0x3F}
        result = m.run(0x1000,full=False)
        self.assertEqual(result['status'],'partial_refusal')
        self.assertEqual(result['failure']['pc'],0x1000)
        self.assertEqual(result['failure']['word_u32'],0x3F)


if __name__ == '__main__': unittest.main()
