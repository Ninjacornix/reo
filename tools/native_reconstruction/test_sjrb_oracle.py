"""Synthetic contract and independently qualified DIV1 tests; never runs game."""
import ast
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

import sjrb_oracle as s


class Div1Machine(s.RingInstructions):
    def __init__(self):
        self.regs = [0] * 32
        self.initialize_mac(hi=11, lo=22, hi1=33, lo1=44)


# Hand-authored instruction expectations, independently fixed before execution.
DIV_CASES = [(7, 3, 2, 1), (-7, 3, -2, -1), (7, -3, -2, 1),
             (-7, -3, 2, -1), (-2147483648, -1, -2147483648, 0),
             (-2147483648, 3, -715827882, -2), (2147483647, 16, 134217727, 15),
             (0, 2147483647, 0, 0), (1, -2147483648, 0, 1)]
DIV1_WORD = 0x7085001A  # DIV1 zero,a0,a1


class Div1Tests(unittest.TestCase):
    def test_signed_results_and_independent_banks(self):
        for lhs, rhs, quotient, remainder in DIV_CASES:
            with self.subTest(lhs=lhs, rhs=rhs):
                m = Div1Machine()
                m.regs[4], m.regs[5] = s.sext32(lhs), s.sext32(rhs)
                m.instruction(0, DIV1_WORD)
                self.assertEqual((m.lo1, m.hi1), (s.sext32(quotient), s.sext32(remainder)))
                self.assertEqual((m.hi, m.lo), (11, 22))
                # Real second-bank MFHI1 encoding used in original Unget.
                m.instruction(4, 0x70001810)
                self.assertEqual(m.regs[3], s.sext32(remainder))

    def test_zero_and_noncanonical_refuse_without_bank_mutation(self):
        for lhs, rhs in [(7, 0), (-7, 0), (0x100000001, 3)]:
            m = Div1Machine()
            m.regs[4], m.regs[5] = lhs & s.MASK64, s.sext32(rhs)
            before = m.mac_state()
            with self.assertRaises(s.OracleError):
                m.instruction(0, DIV1_WORD)
            self.assertEqual(m.mac_state(), before)

    def test_reserved_fields_refused(self):
        for bits in (1 << 6, 1 << 11):
            with self.assertRaises(s.UnknownInstruction):
                Div1Machine().instruction(0, DIV1_WORD | bits)

    def test_actual_pinned_emission_both_compilers(self):
        """Compile exact DIV1 emission, not a handwritten C++ ring algorithm."""
        s.implementation_identity()
        path = s.ROOT / 'third_party/PS2Recomp/ps2xRecomp/src/lib/code_generator.cpp'
        text = path.read_text(encoding='utf-8')
        block = text.split('case MMI_DIV1:', 1)[1].split('case MMI_DIVU1:', 1)[0]
        strings = re.findall(r'"(?:[^"\\]|\\.)*"', block)
        emission = ''.join(ast.literal_eval(value) for value in strings)
        emission = emission.replace('{}', '5', 1).replace('{}', '4', 1).replace('{{', '{').replace('}}', '}')
        self.assertNotIn('fmt::', emission)
        self.assertIn('ctx->lo1', emission)
        source = '''#include <cstdint>
#include <climits>
#include <cstdio>
struct Context { uint64_t r[32]{}, hi=11, lo=22, hi1=33, lo1=44; };
#define GPR_S32(c,n) static_cast<int32_t>((c)->r[n])
void execute(Context* ctx) { EMISSION }
int main() { CASES }
'''.replace('EMISSION', emission)
        calls = []
        for lhs, rhs, quotient, remainder in DIV_CASES:
            calls.append('{ Context c; c.r[4]=static_cast<uint64_t>(static_cast<int64_t>(int32_t(%d))); '
                         'c.r[5]=static_cast<uint64_t>(static_cast<int64_t>(int32_t(%d))); execute(&c); '
                         'if(c.hi!=11 || c.lo!=22 || c.lo1!=uint64_t(int64_t(int32_t(%d))) || '
                         'c.hi1!=uint64_t(int64_t(int32_t(%d)))) return 1; }' % (lhs, rhs, quotient, remainder))
        source = source.replace('CASES', '\n'.join(calls) + '\nputs("DIV1 exact-emission checks passed");')
        root = s.ROOT / 'build-native-sjuni/sjrb-isa-checks'
        root.mkdir(parents=True, exist_ok=True)
        receipts = []
        with tempfile.TemporaryDirectory(prefix='div1-', dir=root) as directory:
            cpp = Path(directory) / 'check.cpp'
            cpp.write_text(source, encoding='utf-8')
            for compiler in ('g++', 'clang++'):
                tool = shutil.which(compiler)
                self.assertIsNotNone(tool, f'Required isolated compiler unavailable: {compiler}')
                exe = Path(directory) / (compiler.replace('+', 'p') + '.exe')
                compiled = subprocess.run([tool, '-std=c++17', '-O2', str(cpp), '-o', str(exe)], capture_output=True, text=True)
                self.assertEqual(compiled.returncode, 0, compiled.stderr)
                ran = subprocess.run([str(exe)], capture_output=True, text=True)
                self.assertEqual(ran.returncode, 0, ran.stderr)
                self.assertIn('checks passed', ran.stdout)
                receipts.append(dict(compiler=tool, compiler_sha256=s.digest(Path(tool).read_bytes()),
                    executable_sha256=s.digest(exe.read_bytes()), stdout=ran.stdout,
                    command=[tool, '-std=c++17', '-O2', str(cpp), '-o', str(exe)]))
        with tempfile.NamedTemporaryFile(prefix='qualification-', suffix='.json', dir=root, delete=False) as receipt:
            receipt.write(s.canonical(dict(schema=1, synthetic=True, isa_reference=s.implementation_identity(),
                harness_source=source, harness_sha256=s.digest(source.encode()), cases=DIV_CASES, compilers=receipts)))


class RingTests(unittest.TestCase):
    @staticmethod
    def case(name):
        inputs = next(row for row in s.corpus_inputs() if row['name'] == name)
        return s.execute_case(inputs)

    def test_complete_frozen_domain_only_declared_partial_refusals(self):
        refused = {}
        total = 0
        for inputs in s.corpus_inputs():
            row = s.execute_case(inputs)
            for op in row['operations']:
                total += 1
                expected = op['expected']
                if expected['status'] == 'refused':
                    refused[inputs['name']] = expected['failure']['detail']
        self.assertEqual(total, 248)
        self.assertEqual(set(refused), {'zero-capacity-unget-original-break', 'zero-capacity-get-undefined-div-refusal'})
        self.assertIn('Original BREAK at 0x13fe34 code=7', refused['zero-capacity-unget-original-break'])
        self.assertIn('Undefined architectural DIV', refused['zero-capacity-get-undefined-div-refusal'])

    def test_source_comments_and_zero_padding(self):
        audit = s.source_audit(s.ROOT / 'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
        self.assertEqual(audit['matched_comments'], 532)
        self.assertEqual(len(audit['omitted_zero_pcs']), 13)

    def test_inputs_are_fixed_separate_from_expected(self):
        inputs = s.corpus_inputs()
        self.assertEqual(s.digest(s.canonical(dict(schema=1,
            provenance='Authored bounded synthetic inputs; no captured gameplay or native implementation.', cases=inputs))),
            '0fbd6dc535541105733bcc295cf0494132e52ca391df63e244f3a70b14240a35')
        self.assertNotIn('expected', json.dumps(inputs))

    def test_split_returns_and_exact_totals(self):
        row = self.case('split-publish-return-suffix')
        fields = row['final']['fields_u32']
        self.assertEqual([fields[k] for k in ('free', 'data', 'write', 'read', 'free_get', 'free_put', 'data_get', 'data_put')],
                         [13, 3, 5, 2, 5, 2, 2, 5])
        self.assertEqual([row['operations'][-i]['expected']['return_u32'] for i in (2, 1)], [13, 3])
        self.assertGreater(row['operations'][-3]['expected']['div1_count'], 0)

    def test_wrap_copy_and_positions(self):
        row = self.case('input-output-extension-wrap')
        fields = row['final']['fields_u32']
        self.assertEqual([fields[k] for k in ('free', 'data', 'write', 'read')], [16, 0, 4, 4])
        backing = bytes.fromhex(row['final']['backing_with_guards_hex'])
        self.assertEqual(backing[16:20], bytes(range(0x74, 0x78)))
        self.assertEqual(backing[32:36], bytes(range(0x74, 0x78)))
        self.assertEqual(backing[:16], b'\xa5' * 16)
        self.assertEqual(backing[-16:], b'\xa5' * 16)
        copies = [event for op in row['operations'] for event in op['expected']['events'] if event['kind'] == 'memcpy']
        self.assertEqual(len(copies), 2)  # prefix mirror, then extension back to start
        self.assertTrue(all(event['guard_depth_before'] == 1 for event in copies))

    def test_exact_end_full_cycle_and_mirror(self):
        row = self.case('exact-end-and-mirror')
        fields = row['final']['fields_u32']
        self.assertEqual([fields[k] for k in ('free', 'data', 'write', 'read')], [16, 0, 0, 0])
        backing = bytes.fromhex(row['final']['backing_with_guards_hex'])
        self.assertEqual(backing[16:20], backing[32:36])

    def test_suffix_pointers_in_extension_match_modulo_both_banks(self):
        row = self.case('free-wrap-suffix-modulo-unget')
        self.assertEqual((row['final']['fields_u32']['write'], row['final']['fields_u32']['free']), (0, 12))
        self.assertEqual(row['final']['descriptors'][4]['pointer_u32'], s.BUFFER + 16)
        row = self.case('data-wrap-suffix-modulo-unget')
        unget = next(op['expected'] for op in row['operations'] if op['action']['call'] == 'unget')
        self.assertEqual(unget['after']['descriptors'][5]['pointer_u32'], s.BUFFER + 16)
        self.assertEqual((unget['after']['fields_u32']['read'], unget['after']['fields_u32']['data']), (0, 4))
        self.assertGreater(unget['div1_count'], 0)
        self.assertEqual((row['final']['fields_u32']['free'], row['final']['fields_u32']['data']), (16, 0))

    def test_request_limited_by_extension_or_available(self):
        row = self.case('extension-grant-clips-request')
        descriptor = row['operations'][-2]['expected']['after']['descriptors'][2]
        self.assertEqual((descriptor['pointer_u32'], descriptor['bytes_i32']), (s.BUFFER + 12, 8))
        row = self.case('no-extension')
        self.assertEqual(row['operations'][-2]['expected']['after']['descriptors'][2]['bytes_i32'], 2)
        row = self.case('empty-short-zero-peek')
        self.assertEqual(row['operations'][3]['expected']['after']['descriptors'][0]['bytes_i32'], 0)
        self.assertEqual(row['operations'][6]['expected']['after']['descriptors'][2]['bytes_i32'], 16)

    def test_unget_match_and_mismatch_after_returning_error(self):
        for pool in (0, 1):
            matched = self.case(f'unget-match-pool{pool}')['final']['fields_u32']
            mismatch = self.case(f'unget-mismatch-pool{pool}')
            fields = mismatch['final']['fields_u32']
            position, count, total = ('write', 'free', 'free_get') if pool == 0 else ('read', 'data', 'data_get')
            self.assertEqual(matched[position], 0)
            self.assertEqual(fields[position], 6)
            self.assertEqual(fields[total], 0)  # even mismatch subtracts acquisition
            self.assertEqual(matched[count] - fields[count], 6)
            event = next(e for e in mismatch['operations'][-1]['expected']['events'] if e['kind'] == 'error_callback')
            self.assertEqual(event['error_i32'], -3)
            self.assertEqual(event['guard_depth_before'], 1)

    def test_callback_continuation_rereads_length(self):
        row = self.case('callback-edits-returned-length-continuation')
        fields = row['final']['fields_u32']
        self.assertEqual((fields['free_get'], fields['free'], fields['write']), (4, 10, 6))
        event = next(e for e in row['operations'][-1]['expected']['events'] if e['kind'] == 'error_callback')
        self.assertEqual(event['object_words_before'][0x28 // 4], 6)

    def test_invalid_selector_outputs_and_zero_peek_quirk(self):
        for op in ('get', 'put', 'unget'):
            row = self.case('invalid-selector-' + op)
            descriptor = row['final']['descriptors'][0]
            self.assertEqual((descriptor['pointer_u32'], descriptor['bytes_i32']), (0, 0))
        row = self.case('invalid-selector-zero-peek')
        self.assertEqual(row['operations'][-1]['expected']['return_u32'], 1)
        row = self.case('invalid-selector-count')
        self.assertEqual(row['operations'][-1]['expected']['return_u32'], 0)

    def test_nonpositive_and_null_put_unget_no_guard(self):
        row = self.case('zero-null-negative-return-noop')
        for op in row['operations'][3:]:
            self.assertEqual(op['expected']['events'], [])
        self.assertEqual(row['final']['fields_u32']['free'], 16)

    def test_reset_preserves_storage_and_identity(self):
        row = self.case('identity-reset-and-accessors')
        fields = row['final']['fields_u32']
        self.assertEqual([fields[k] for k in ('free', 'data', 'write', 'read', 'free_get')], [16, 0, 0, 0, 0])
        self.assertEqual((fields['buffer'], fields['error'], fields['context']), (s.BUFFER, s.ERROR, s.CONTEXT))

    def test_pool_full_reuse_and_reference_lifetime(self):
        row = self.case('pool-exhaustion')
        self.assertEqual(row['operations'][-1]['expected']['return_u32'], 0)
        self.assertEqual(len(row['final']['active_objects']), 256)
        row = self.case('second-object-and-destroy-reuse')
        creates = [op['expected']['return_u32'] for op in row['operations'] if op['action']['call'] == 'create']
        self.assertEqual(creates, [s.POOL, s.POOL + 64, s.POOL])
        row = self.case('module-references-clear-not-backing')
        self.assertEqual(row['final']['active_objects'], [])
        self.assertEqual(row['final']['pool_reference_u32'], 0)
        self.assertEqual(bytes.fromhex(row['final']['backing_with_guards_hex'])[16:20], bytes(range(0x20, 0x24)))

    def test_default_error_runs_original_thunk(self):
        op = self.case('default-error-route')['operations'][-1]['expected']
        self.assertIn(0x13F7D8, op['visited_pcs'])
        self.assertTrue(any(event['kind'] == 'diagnostic' and event['arguments_u64'][0] == 0x23DA68 for event in op['events']))

    def test_totals_are_word_wrapped_not_host_counts(self):
        fields = self.case('totals-word-wrap')['final']['fields_u32']
        self.assertEqual((fields['free_get'], fields['data_put']), (2, 2))

    def test_adxt_backing_geometry_is_real_bounded_allocation(self):
        row = self.case('adxt-pcm-geometry')
        self.assertEqual(row['final']['fields_u32']['capacity'], 16384)
        self.assertEqual(row['final']['fields_u32']['extension'], 192)
        self.assertEqual(len(bytes.fromhex(row['final']['backing_with_guards_hex'])) - 32, 0x40C0)
        self.assertEqual(row['operations'][-2]['expected']['after']['descriptors'][2]['bytes_i32'], 8)

    def test_constructor_source_converts_pcm_halfwords_to_bytes(self):
        # Static caller evidence, not a claim to execute complete ADXT creation.
        elf = s.Elf(s.ROOT / 'game_data/SLUS_207.65')
        words = {0x1316B8: 0x24082000, 0x1316C0: 0x24092060,
                 0x1316F8: 0xAE080030, 0x131700: 0xAE090034,
                 0x13174C: 0x8E060034, 0x131750: 0x8E050030,
                 0x131760: 0x00C53023, 0x131764: 0x00063040,
                 0x131768: 0x00052840, 0x131770: 0x0C04FE2A}
        for pc, word in words.items():
            self.assertEqual(int.from_bytes(elf.read(pc, 4), 'little'), word)
        halfwords = words[0x1316B8] & 0xFFFF
        total_halfwords = words[0x1316C0] & 0xFFFF
        self.assertEqual((2 * halfwords, 2 * (total_halfwords - halfwords)), (16384, 192))
        self.assertEqual(2 * total_halfwords, 0x40C0)

    def test_finite_geometry_and_copy_limits_remain_explicit(self):
        self.assertEqual((s.MAX_CAPACITY, s.MAX_EXTENSION, s.MAX_COPY_BYTES), (16384, 192, 16384))
        with self.assertRaises(s.OracleError):
            s.Machine(16385, 192)
        with self.assertRaises(s.OracleError):
            s.Machine(16384, 193)

    def test_step_cap_and_unknown_instruction_fail_closed(self):
        m = s.Machine()
        result = m.run('create', [s.BUFFER, 16, 4], step_cap=1)
        self.assertEqual(result['failure']['type'], 'StepLimit')
        with self.assertRaises(s.UnknownInstruction):
            m.instruction(0, 0x0000003F)


if __name__ == '__main__':
    unittest.main()
