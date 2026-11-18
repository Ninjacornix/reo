"""Independent original-word and generic-instruction checks; no native core import."""
import json
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

from ee_mac_oracle import encode, implementation_identity, GENERATOR, MACROS
from movie_position_oracle import (BODIES, MAIN, MASK64, ROOT, ClockIntegerInstructions,
    Machine, OriginalBreak, UndefinedInstruction, UnknownInstruction, corpus, defaults,
    helper_corpus, source_audit)
from sjuni_oracle import OracleError, sext32


class MicroMachine(ClockIntegerInstructions):
    def __init__(self):
        self.regs = [0] * 32
        self.initialize_mac(hi=1, lo=2, hi1=3, lo1=4)
        self.extension_counts = {}


class MoviePositionTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.cases, cls.helpers = corpus(), helper_corpus()

    def test_complete_publisher_and_all_real_helper_entries_execute(self):
        self.assertEqual(len(self.cases), 25)
        for row in self.cases:
            counts = row['expected']['body_entry_counts']
            self.assertEqual(counts['16F338'], 1)
            self.assertEqual(counts['171530'], 1)
            if row['inputs']['clock_flag']:
                for key in ('171E58', '15BA80', '10FB18'):
                    self.assertEqual(counts[key], 1)
            else:
                self.assertEqual(set(counts), {'16F338', '171530'})
            self.assertFalse(row['expected']['defined_return'])

    def test_source_descriptor_selective_writes_and_real_frame_guards(self):
        for row in self.cases:
            result = row['expected']
            writes = result['writes']
            self.assertTrue(all(x['span'] in ('main', 'descriptor', 'stack') for x in writes))
            main = [x['offset'] for x in writes if x['span'] == 'main']
            self.assertIn(main, ([], [0xF00, 0xF04]))
            descriptor = [x['offset'] for x in writes if x['span'] == 'descriptor']
            self.assertEqual(descriptor, [0x10, 0xC, 0x20, 0x24] + ([0x20, 0xC, 0x24] if row['inputs']['clock_flag'] else []))
            self.assertEqual(result['before']['inner_fields_u32'], result['after']['inner_fields_u32'])
            self.assertEqual(result['after']['original_frame_guard_words_u32'][:4], [0xCCCCCCCC] * 4)
            for reg in (*range(16, 24), 29, 30, 31):
                self.assertEqual(result['before']['abi']['gpr_lower64'][reg], result['after']['abi']['gpr_lower64'][reg])
            self.assertEqual(result['before']['abi']['mac_lower64']['hi1'], result['after']['abi']['mac_lower64']['hi1'])
            self.assertEqual(result['before']['abi']['mac_lower64']['lo1'], result['after']['abi']['mac_lower64']['lo1'])

    def test_equal_and_decreasing_positions_preserve_both_latest_words(self):
        for name in ('equal-preserves-scale', 'lower-preserves-latest'):
            result = next(row['expected'] for row in self.cases if row['name'] == name)
            for key in ('latest_numerator', 'latest_scale'):
                self.assertEqual(result['before']['source_fields_u32'][key], result['after']['source_fields_u32'][key])

    def test_tables_are_actual_owned_bytes_and_never_written(self):
        self.assertEqual({row['inputs']['rate_index'] for row in self.cases if row['name'].startswith('side-rate-')}, set(range(9)))
        all_rows = self.cases + self.helpers
        self.assertTrue(any(x['span'] == 'owned_normalization' for row in all_rows for x in row['expected']['reads']))
        self.assertFalse(any(x['span'].startswith('owned_') for row in all_rows for x in row['expected']['writes']))
        for index in (-1, 9):
            with self.assertRaises(OracleError):
                Machine(defaults(rate_index=index))

    def test_zero_divisor_ratio_returns_original_sign_limit_without_helper(self):
        ratios = [row for row in self.helpers if row['name'].startswith('product-ratio-')][:5]
        expected = [0x7FFFFFFF, 0xFFFFFFFF80000000, 0xFFFFFFFF80000000, 0x7FFFFFFF, 0xFFFFFFFF80000000]
        self.assertEqual([row['expected']['raw_v0_lower64'] for row in ratios], expected)
        self.assertTrue(all('10FB18' not in row['expected']['body_entry_counts'] for row in ratios))

    def test_direct_original_zero_division_is_recorded_break_not_a_result(self):
        stopped = [row for row in self.helpers if row['expected']['status'] == 'original_break']
        self.assertEqual(len(stopped), 3)
        self.assertTrue(all(row['expected']['break_code'] == 7 and row['expected']['break_pc'] == '0x10fd58' for row in stopped))
        self.assertTrue(all(not row['expected']['defined_return'] for row in stopped))

    def test_signed64_helper_ordinary_high_denominator_and_overflow_bit_patterns(self):
        expected = [(0, 1, 0), (1, 2, 0), (-10, 3, -3), (10, -3, -3), (-10, -3, 3),
                    (-0x8000000000000000, -1, -0x8000000000000000),
                    (-0x8000000000000000, -0x8000000000000000, 1),
                    (0x7FFFFFFFFFFFFFFF, 0x100000001, 0x7FFFFFFF)]
        for numerator, denominator, quotient in expected:
            result = Machine(defaults()).run(0x10FB18, [numerator, denominator])
            self.assertEqual(result['raw_v0_lower64'], quotient & MASK64)
            self.assertEqual(set(result['body_entry_counts']), {'10FB18'})

    def test_complete_generated_source_word_audit(self):
        rows = source_audit(ROOT / 'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
        self.assertEqual(len(rows), 5)
        self.assertEqual(sum(x['comments'] for x in rows), 516)
        self.assertEqual(sum(x['omitted_zero_words'] for x in rows), 2)


class GenericInstructionTests(unittest.TestCase):
    def test_hand_calculated_variable_word_and_doubleword_shifts(self):
        vectors = [(4, 1, 0x40000000, 0, 0xFFFFFFFF80000000),
                   (6, 31, 0xFFFFFFFF, 0, 1), (4, 32, 1, 0, 1),
                   (0x3C, 0, 0x12345678, 0, 0x1234567800000000),
                   (0x3E, 0, 0xFFFFFFFF80000000, 0, 0xFFFFFFFF),
                   (0x3F, 0, 0xFFFFFFFF80000000, 0, MASK64),
                   (0x3C, 0, 1, 31, 0x8000000000000000)]
        for fn, shift, value, sa, expected in vectors:
            machine = MicroMachine()
            machine.regs[1], machine.regs[2] = shift, value
            machine.instruction(0, encode(0, fn, 1 if fn in (4, 6) else 0, 2, 3, sa))
            self.assertEqual(machine.regs[3], expected)

    def test_divu_sign_extended_banks_other_bank_and_undefined_zero(self):
        machine = MicroMachine()
        machine.regs[1], machine.regs[2] = MASK64, 2
        machine.instruction(0, encode(0, 0x1B, 1, 2))
        self.assertEqual((machine.lo, machine.hi, machine.lo1, machine.hi1), (0x7FFFFFFF, 1, 4, 3))
        machine.regs[2] = 0
        before = (machine.regs.copy(), machine.mac_state(), machine.extension_counts.copy())
        with self.assertRaises(UndefinedInstruction):
            machine.instruction(0, encode(0, 0x1B, 1, 2))
        self.assertEqual((machine.regs, machine.mac_state(), machine.extension_counts), before)

    def test_reserved_encodings_fail_before_state_mutation(self):
        for word in (encode(0, 4, 1, 2, 3, 1), encode(0, 0x3C, 1, 2, 3), encode(0, 0x1B, 1, 2, 3)):
            machine = MicroMachine()
            before = (machine.regs.copy(), machine.mac_state())
            with self.assertRaises(UnknownInstruction):
                machine.instruction(0, word)
            self.assertEqual((machine.regs, machine.mac_state()), before)

    def test_exact_pinned_emitter_templates_gcc_and_llvm(self):
        identity = implementation_identity()
        text = GENERATOR.read_text()
        forms = [('SPECIAL_SLLV', 4, 0), ('SPECIAL_SRLV', 6, 0),
                 ('SPECIAL_DSLL32', 0x3C, 0), ('SPECIAL_DSLL32', 0x3C, 31),
                 ('SPECIAL_DSRL32', 0x3E, 0), ('SPECIAL_DSRL32', 0x3E, 31),
                 ('SPECIAL_DSRA32', 0x3F, 0), ('SPECIAL_DSRA32', 0x3F, 31),
                 ('SPECIAL_DIVU', 0x1B, 0)]
        fragments, expected, calls = [], [], []
        for number, (symbol, fn, sa) in enumerate(forms):
            body = text.split('case ' + symbol + ':', 1)[1].split('case ', 1)[0]
            templates = re.findall(r'return fmt::format\("([^"\n]+)", ([^;\n]+)\);', body)
            self.assertEqual(len(templates), 1)
            template, arguments = templates[0]
            values = {'inst.rs': 1 if fn in (4, 6, 0x1B) else 0, 'inst.rt': 2, 'inst.rd': 3, 'inst.sa': sa}
            fragments.append(template.format(*(values[arg.strip()] for arg in arguments.split(','))))
            vectors = [(sext32(a), sext32(b)) for a, b in [(-1, 1), (-1, 2), (-1, -1), (-2147483648, 65535)]] if fn == 0x1B else [
                (shift, value) for shift in (0, 1, 31, 32, 63) for value in (0, 1, MASK64, 0x8000000000000000, 0x123456789ABCDEF0)]
            for lhs, rhs in vectors:
                machine = MicroMachine()
                machine.regs[1], machine.regs[2] = lhs, rhs
                machine.instruction(0, encode(0, fn, values['inst.rs'], 2, 0 if fn == 0x1B else 3, sa))
                expected.append([machine.regs[3], machine.hi, machine.lo, machine.hi1, machine.lo1])
                calls.append(f'{{ Context c{{}}; c.r[1]={lhs}ull; c.r[2]={rhs}ull; execute({number},&c); '
                             'std::cout<<c.r[3]<<" "<<c.hi<<" "<<c.lo<<" "<<c.hi1<<" "<<c.lo1<<"\\n"; }')
        macro_text = MACROS.read_text()
        shifts = '\n'.join(re.search(r'^#define ' + name + r'\([^\n]+', macro_text, re.M).group(0) for name in ('SLL32', 'SRL32'))
        preamble = '''#include <cstdint>
#include <iostream>
struct Context { uint64_t r[32]{}; uint64_t hi=1,lo=2,hi1=3,lo1=4; };
#define GPR_U32(c,n) static_cast<uint32_t>((c)->r[n])
#define GPR_U64(c,n) ((c)->r[n])
#define GPR_S64(c,n) static_cast<int64_t>((c)->r[n])
#define SET_GPR_S32(c,n,v) do { if(n) (c)->r[n]=static_cast<uint64_t>(static_cast<int64_t>(static_cast<int32_t>(v))); } while(false)
#define SET_GPR_U64(c,n,v) do { if(n) (c)->r[n]=static_cast<uint64_t>(v); } while(false)
#define SET_GPR_S64(c,n,v) SET_GPR_U64(c,n,v)
'''
        source = preamble + shifts + '\nvoid execute(int form,Context* ctx) { switch(form) {\n' + ''.join(
            f'case {index}: {fragment} break;\n' for index, fragment in enumerate(fragments)) + '} }\nint main(){\n' + '\n'.join(calls) + '\n}\n'
        output = Path(tempfile.mkdtemp(prefix='movie-position-emissions-', dir=ROOT / 'build-native-sjuni'))
        cpp = output / 'instructions.cpp'
        cpp.write_text(source)
        receipts = []
        for name in ('g++', 'clang++'):
            compiler = shutil.which(name)
            self.assertIsNotNone(compiler, 'Both host compilers required for exact emission validation')
            exe = output / (name.replace('+', 'p') + '.exe')
            command = [compiler, '-std=c++20', '-O1', '-Wall', '-Wextra', '-Werror', str(cpp), '-o', str(exe)]
            subprocess.run(command, capture_output=True, text=True, check=True)
            result = subprocess.run([str(exe)], capture_output=True, text=True, check=True)
            actual = [[int(value) for value in line.split()] for line in result.stdout.splitlines()]
            self.assertEqual(actual, expected)
            receipts.append(dict(compiler=compiler, command=command, cases=len(expected), passed=True))
        (output / 'receipt.json').write_text(json.dumps(dict(identity=identity, receipts=receipts,
            limitation='Only emitted generic instruction expressions compiled; no full runtime/helper body link or game execution.'), indent=2) + '\n')


if __name__ == '__main__':
    unittest.main()
