"""Instruction and finite-fixture checks independent of any native ADX core."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import struct
import sys
import unittest

from adx_stereo_oracle import (BODIES, Machine, ObservedMemory, EeDivInstructions,
    ROOT, block, generate, INPUT, LEFT, RIGHT, HISTORY, KEY, TABLE, STACK_TOP, RETURN)
from ee_mac_oracle import MicroMachine as MacMicroMachine, encode, implementation_identity, GENERATOR
from sjuni_oracle import OracleError, UnknownInstruction, StepLimit, sext32, signed


class DivMachine(EeDivInstructions, MacMicroMachine):
    pass


def original_abi_case(case, *, frame_fill=0xCC, saved_gprs=None):
    """Observe complete original frame effects without changing the PCM oracle.

    No stack-layout synthesis occurs here. Actual interpreted original stores
    populate the frame and trace. Layout expectations are tested separately.
    All GPR data is lower64; upper-lane behavior requires the runtime macros.
    """
    if not isinstance(frame_fill, int) or not 0 <= frame_fill <= 255:
        raise ValueError('Frame fill must be a byte')
    params = case['input']
    m = Machine(bytes.fromhex(params['encoded_hex']), params['requested_i32'],
        mode=params['mode'], selector_flag=params['selector_flag_u32'],
        history=tuple(params['history_i16']), coefficients=tuple(params['coefficients_i16']),
        key=params['key_u16'], multiplier=params['multiplier_i16'], addend=params['addend_i16'],
        output_samples=params['output_capacity_samples_per_plane'],
        mac_initial=tuple(params['mac_initial_u64']),
        poison_halfword_arguments=params['poison_halfword_arguments'])
    frame = STACK_TOP-112
    m.mem.store(frame, 112, int.from_bytes(bytes([frame_fill])*112, 'little'))
    if saved_gprs is not None:
        if set(saved_gprs) != set(m.saved) or any(not isinstance(v, int) or not 0 <= v < 1 << 64 for v in saved_gprs.values()):
            raise ValueError('Exactly nine uint64 callee-saved GPRs required')
        for reg, value in saved_gprs.items():
            m.regs[reg] = value
        m.saved = saved_gprs.copy()
    initial_frame, initial_args = m.raw(frame, 112), m.raw(STACK_TOP, 24)
    stack_stores, transfers = [], []
    original_store, original_instruction = m.mem.store, m.instruction

    def observe_store(address, size, value):
        if m.mem.active and frame <= address and address+size <= STACK_TOP:
            stack_stores.append(dict(pc=m.pc, frame_offset=address-frame, bytes=size,
                value_u64=value & ((1 << (8*size))-1)))
        original_store(address, size, value)

    def observe_instruction(pc, word):
        result = original_instruction(pc, word)
        if result is not None:
            taken, target, likely = result
            transfers.append(dict(pc=pc, instruction_u32=word, taken=taken,
                                  target=target, likely=likely))
        return result

    m.mem.store, m.instruction = observe_store, observe_instruction
    result = m.run()
    if not transfers or transfers[-1]['instruction_u32'] != 0x03E00008:
        raise OracleError('Expected original final JR RA, not a guessed return')
    # The runner reached RETURN after executing the original JR delay slot. The
    # generated macro sets branch_pc to that JR, clears in_delay_slot and uses
    # the captured incoming RA. It is not a hardware cycle/interlock model.
    return dict(name=case['name'], input=params,
        abi_input=dict(frame_address=frame, frame_fill_u8=frame_fill,
            frame_hex=initial_frame.hex(), caller_argument_bytes_hex=initial_args.hex(),
            incoming_saved_gprs_u64={str(reg): value for reg, value in m.saved.items()},
            caller_sp=STACK_TOP, return_address=RETURN),
        expected=dict(frame_hex=m.raw(frame, 112).hex(), frame_stores=stack_stores,
            caller_argument_bytes_hex=m.raw(STACK_TOP, 24).hex(),
            final_gpr_lower64=m.regs, return_i32=result['return_i32'],
            pc=m.pc, branch_pc=transfers[-1]['pc'], in_delay_slot=False,
            state=result['state'], saved_registers_restored=result['abi']['saved_registers_restored']))


def export_original_abi(output, pcm_fixture=ROOT/'build-native-sjuni/adx-stereo-fixtures.json'):
    """Export a separate ABI receipt; never regenerate or overwrite PCM proof."""
    output, pcm_fixture = Path(output), Path(pcm_fixture)
    if output.resolve() == pcm_fixture.resolve():
        raise ValueError('ABI export cannot overwrite the frozen PCM fixture')
    pcm_bytes = pcm_fixture.read_bytes()
    if hashlib.sha256(pcm_bytes).hexdigest() != 'a02fc85b996feb650751407a5a2e5fc9cd8104fd1c5d9fe4278864cf4027f6b0':
        raise OracleError('Frozen original PCM fixture changed')
    fixture = json.loads(pcm_bytes)
    result = dict(schema=1, kind='separate complete original ADX stereo stack/return ABI observations',
        identity=dict(frozen_pcm_fixture_sha256=hashlib.sha256(pcm_bytes).hexdigest(),
            original_identity=fixture['identity'],
            exporter_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()),
        limitations=['Original lower64 GPR and actual stack-store observations, not a new calling convention.',
            'Last JR branch_pc/delay flag follows inspected pinned generated return protocol.',
            'Upper128 lanes, scheduler/preemption and arbitrary alias layouts are not interpreted.'],
        cases=[original_abi_case(case) for case in fixture['cases']])
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    return dict(cases=len(result['cases']), sha256=hashlib.sha256(output.read_bytes()).hexdigest())


class AbiTests(unittest.TestCase):
    def case(self, mode, count=2, marker=None):
        encoded = block(1, bytes([0x78])*16)+block(3, bytes([0xF1])*16)
        if count > 2:
            encoded *= count//2
        if count <= 1:
            encoded = b''
        if marker == 'left':
            encoded = b'\x80\x00'
        elif marker == 'right':
            encoded = block(1, bytes([0x78])*16)+b'\x80\x00'
        m = Machine(encoded, count, mode=mode, multiplier=-7, addend=-9)
        return dict(name=f'{mode}_{count}_{marker}', input=m.case_input)

    def test_original_dead_frame_layout_and_saved_values(self):
        saves = {reg: 0xFEDCBA9800000000+reg for reg in (*range(16, 24), 30)}
        for mode in ('normal', 'downmix'):
            for count in (0, 1, 2, 3, 4):
                row = original_abi_case(self.case(mode, count), frame_fill=0x5A, saved_gprs=saves)
                expected, params = row['expected'], row['input']
                frame = bytes.fromhex(expected['frame_hex'])
                locals = struct.unpack_from('<8I', frame)
                fixed = [count, HISTORY, HISTORY+4, 0xFFFFFFF9, 0xFFFFFFF7]
                self.assertEqual(list(locals[:5]), fixed)
                if mode == 'normal':
                    self.assertEqual(locals[5:7], (count//2, count//2))
                    self.assertEqual(locals[7], 0x5A5A5A5A)
                else:
                    self.assertEqual(locals[5], count//2)
                    self.assertEqual(locals[6:], (0x5A5A5A5A, 0x5A5A5A5A))
                self.assertEqual(struct.unpack_from('<9Q', frame, 32), tuple(saves.values()))
                self.assertEqual(frame[104:], b'\x5A'*8)
                self.assertEqual(expected['branch_pc'], 0x127FC0 if mode == 'normal' else 0x127C74)
                self.assertEqual(expected['pc'], RETURN)
                self.assertFalse(expected['in_delay_slot'])
                self.assertEqual(expected['return_i32'], count)
                self.assertEqual(expected['final_gpr_lower64'][29], STACK_TOP)
                self.assertEqual(expected['final_gpr_lower64'][31], RETURN)
                self.assertTrue(expected['saved_registers_restored'])
                self.assertEqual(expected['caller_argument_bytes_hex'], row['abi_input']['caller_argument_bytes_hex'])
                # Defined native result effects remain those of the original run.
                self.assertEqual(params['mode'], mode)

    def test_marker_frame_count_and_explicit_original_store_trace(self):
        for mode in ('normal', 'downmix'):
            for marker in ('left', 'right'):
                row = original_abi_case(self.case(mode, 2, marker))
                stores = row['expected']['frame_stores']
                self.assertEqual(row['expected']['return_i32'], 0)
                self.assertEqual(sum(store['bytes'] == 8 for store in stores), 9)
                self.assertTrue(all(store['frame_offset'] < 104 for store in stores))
                self.assertEqual(struct.unpack_from('<I', bytes.fromhex(row['expected']['frame_hex']), 20)[0],
                                 0 if mode == 'normal' else 1)

    def test_invalid_abi_parameters_rejected(self):
        case = self.case('normal')
        for kwargs in (dict(frame_fill=-1), dict(frame_fill=256), dict(saved_gprs={16: 1})):
            with self.assertRaises(ValueError):
                original_abi_case(case, **kwargs)


class DivTests(unittest.TestCase):
    def machine(self, dividend, divisor):
        m = DivMachine(hi=0x11223344, lo=0x55667788, hi1=0x12345678, lo1=0x9ABCDEF0)
        m.regs[1], m.regs[2] = sext32(dividend), sext32(divisor)
        return m

    def test_hand_calculated_signed_division_and_overflow(self):
        vectors = ((7, 10, 0, 7), (-7, 10, 0, -7), (17, 10, 1, 7),
                   (-17, 10, -1, -7), (17, -10, -1, 7), (-17, -10, 1, -7),
                   (-2147483648, -1, -2147483648, 0),
                   (-2147483648, 10, -214748364, -8), (2147483647, 10, 214748364, 7))
        for a, b, quotient, remainder in vectors:
            m = self.machine(a, b)
            before = m.regs.copy(), m.hi1, m.lo1
            m.instruction(0, encode(0, 0x1A, 1, 2))
            self.assertEqual((m.lo, m.hi), (sext32(quotient), sext32(remainder)))
            self.assertEqual((m.regs, m.hi1, m.lo1), before)
            self.assertEqual(m.div_count, 1)

    def test_reject_undefined_or_reserved_before_any_mutation(self):
        bad = ((1, 0, encode(0, 0x1A, 1, 2)),
               (0, 1, encode(0, 0x1A, 1, 2, rd=3)),
               (0, 1, encode(0, 0x1A, 1, 2, sa=1)))
        for a, b, word in bad:
            m = self.machine(a, b)
            before = m.regs.copy(), m.mac_state(), m.mac_counts.copy()
            with self.assertRaises(OracleError):
                m.instruction(0, word)
            self.assertEqual((m.regs, m.mac_state(), m.mac_counts), before)
            self.assertFalse(hasattr(m, 'div_count'))
        for reg in (1, 2):
            for badvalue in (0xFFFFFFFF, 0xFFFFFFFF00000001, 0x1234000000000001):
                m = self.machine(7, 10)
                m.regs[reg] = badvalue
                before = m.regs.copy(), m.mac_state()
                with self.assertRaises(OracleError):
                    m.instruction(0, encode(0, 0x1A, 1, 2))
                self.assertEqual((m.regs, m.mac_state()), before)

    def test_unextended_integer_and_mac_engines_still_reject_div(self):
        m = MacMicroMachine(hi=1, lo=2, hi1=3, lo1=4)
        m.regs[1], m.regs[2] = 7, 10
        with self.assertRaises(UnknownInstruction):
            m.instruction(0, encode(0, 0x1A, 1, 2))

    def test_exact_pinned_emitter_gcc_and_llvm(self):
        implementation_identity()
        section = GENERATOR.read_text(encoding='utf-8').split('case SPECIAL_DIV:', 1)[1].split('case SPECIAL_DIVU:', 1)[0]
        # Join actual authored C++ string literals, preserving fmt escaped braces.
        literal_part = section.split('return fmt::format(', 1)[1].split('inst.rt', 1)[0]
        template = ''.join(json.loads(s) for s in re.findall(r'"(?:[^"\\]|\\.)*"', literal_part))
        emission = template.format(2, 1)
        self.assertIn('INT32_MIN', emission)
        cpp = '''#include <cstdint>
#include <climits>
#include <iostream>
struct Context { uint64_t r[32]{}; uint64_t hi{},lo{}; };
#define GPR_S32(c,n) static_cast<int32_t>((c)->r[n])
void run(Context* ctx) { '''+emission+''' }
int main() { int64_t a,b; while(std::cin>>a>>b) { Context context; Context* ctx=&context;
ctx->r[1]=static_cast<uint64_t>(a); ctx->r[2]=static_cast<uint64_t>(b); run(ctx);
std::cout<<ctx->lo<<" "<<ctx->hi<<"\\n"; } }
'''
        vectors = [(a, b) for a in (-2147483648, -1001, -17, -11, -10, -9, -7, -1, 0, 1, 7, 9, 10, 11, 17, 1001, 2147483647)
                   for b in (-2147483648, -101, -10, -3, -1, 1, 3, 10, 101, 2147483647)]
        expected = []
        for a, b in vectors:
            m = self.machine(a, b)
            m.instruction(0, encode(0, 0x1A, 1, 2))
            expected.append((m.lo, m.hi))
            if (a, b) != (-2147483648, -1):
                q, r = signed(m.lo, 64), signed(m.hi, 64)
                self.assertEqual(a, q*b+r)
                self.assertLess(abs(r), abs(b))
                self.assertTrue(r == 0 or (r < 0) == (a < 0))
        output = ROOT/'build-native-sjuni/adx-stereo-div-checks'
        output.mkdir(parents=True, exist_ok=True)
        source = output/'pinned_div_emission.cpp'
        source.write_text(cpp, encoding='utf-8')
        compilers = {
            'gcc': Path('C:/msys64/mingw64/bin/g++.exe'),
            'llvm': Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')}
        receipts = {}
        for name, compiler in compilers.items():
            self.assertTrue(compiler.is_file(), str(compiler))
            exe = output/(name+'.exe')
            subprocess.run([str(compiler), '-std=c++20', '-Wall', '-Wextra', '-Werror', str(source), '-o', str(exe)],
                           check=True, capture_output=True, text=True)
            env = os.environ.copy()
            env['PATH'] = str(compiler.parent)+os.pathsep+env.get('PATH', '')
            result = subprocess.run([str(exe)], input=''.join(f'{a} {b}\n' for a, b in vectors),
                                    check=True, capture_output=True, text=True, env=env)
            actual = [tuple(map(int, line.split())) for line in result.stdout.splitlines()]
            self.assertEqual(actual, expected)
            receipts[name] = dict(compiler=str(compiler),
                compiler_sha256=hashlib.sha256(compiler.read_bytes()).hexdigest(),
                executable_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(), vectors=len(vectors))
        (output/'receipt.json').write_text(json.dumps(dict(schema=1,
            source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
            pinned_isa=implementation_identity(), checks=receipts), indent=2)+'\n', encoding='utf-8')


class StereoTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.fixture = generate()
        cls.by_name = {c['name']: c for c in cls.fixture['cases']}

    def pair(self, left=0x77, right=0x88, header=0):
        return block(header, bytes([left])*16)+block(header, bytes([right])*16)

    def test_hand_calculated_nibbles_and_independent_planes(self):
        result = Machine(self.pair(), 2).run()
        self.assertEqual(result['return_i32'], 2)
        self.assertEqual(result['state']['left_pcm_i16'], [7]*32)
        self.assertEqual(result['state']['right_pcm_i16'], [-8]*32)
        self.assertEqual(result['state']['history_i16'], [7, 7, -8, -8])
        result = Machine(block(0, bytes([0x78])*16)+block(0, bytes([0xF1])*16), 2).run()
        self.assertEqual(result['state']['left_pcm_i16'], [7, -8]*16)
        self.assertEqual(result['state']['right_pcm_i16'], [-1, 1]*16)

    def test_downmix_signed_truncation_duplicate_planes_and_unmixed_history(self):
        for left, right, expected in ((0x77, 0x88, 0), (0x88, 0x88, -11),
                                      (0x77, 0x77, 9), (0xFF, 0xFF, -1)):
            result = Machine(self.pair(left, right), 2, mode='downmix').run()
            self.assertEqual(result['state']['left_pcm_i16'], [expected]*32)
            self.assertEqual(result['state']['right_pcm_i16'], [expected]*32)
            self.assertEqual(result['div_instruction_count'], 32)
        result = Machine(self.pair(), 2, mode='downmix').run()
        self.assertEqual(result['state']['history_i16'], [7, 7, -8, -8])

    def test_individual_clamp_precedes_mix_and_final_clamp(self):
        # Scale8192, coeff0: L7 clips32767, R-8 clips-32768 -> mixed0.
        result = Machine(self.pair(header=0x1FFF), 2, mode='downmix').run()
        self.assertEqual(result['state']['left_pcm_i16'], [0]*32)
        self.assertEqual(result['state']['history_i16'], [32767, 32767, -32768, -32768])
        for nibble, expected in ((0x77, 32767), (0x88, -32768)):
            result = Machine(self.pair(nibble, nibble, 0x1FFF), 2, mode='downmix').run()
            self.assertEqual(result['state']['left_pcm_i16'], [expected]*32)
            self.assertEqual(result['state']['right_pcm_i16'], [expected]*32)

    def test_nonpositive_and_odd_return_is_not_processed_block_count(self):
        for mode in ('normal', 'downmix', 'selector'):
            for count in (0, 1, -1, -2, -2147483648):
                result = Machine(b'', count, mode=mode, history=(1, 2, 3, 4), key=5).run()
                self.assertEqual(result['return_i32'], count)
                self.assertNotIn('encoded', result['reads'])
                self.assertEqual(result['pcm_store_count'], 0)
                self.assertEqual(result['state']['history_i16'], [1, 2, 3, 4])
                self.assertEqual(result['state']['key_u16'], 5)
            result = Machine(self.pair(), 3, mode=mode).run()
            self.assertEqual(result['return_i32'], 3)
            self.assertEqual(result['pcm_store_count'], 64)

    def test_left_and_right_marker_key_order_and_no_history_publication(self):
        for mode in ('normal', 'downmix'):
            for side in ('left', 'right'):
                for completed in (0, 1, 2):
                    row = self.by_name[f'{mode}_00000000_{side}_marker_after_{completed}']
                    result, initial = row['expected'], row['input']
                    self.assertEqual(result['return_i32'], completed*2)
                    self.assertEqual(result['pcm_store_count'], completed*64)
                    self.assertEqual(result['state']['history_i16'], initial['history_i16'])
                    self.assertNotIn('history', result['writes'])
                    self.assertEqual(result['writes'].get('key', {}).get('accesses', 0),
                                     completed*2+(side == 'right'))
                    if not completed:
                        self.assertEqual(result['state']['key_u16'], 23456 if side == 'left' else 343)

    def test_selector_chooses_complete_kernel_without_modifying_flag(self):
        encoded = self.pair()
        for flag, mode in ((0, 'normal'), (1, 'downmix'), (0x80000000, 'downmix'), (0xFFFFFFFF, 'downmix')):
            direct = Machine(encoded, 2, mode=mode, selector_flag=flag).run()
            selected = Machine(encoded, 2, mode='selector', selector_flag=flag).run()
            self.assertEqual(selected['state'], direct['state'])
            self.assertEqual(selected['return_i32'], direct['return_i32'])
            self.assertEqual(selected['pcm_stores'], direct['pcm_stores'])
            self.assertEqual(selected['reads']['selector_flag']['accesses'], 1)
            self.assertNotIn('selector_flag', selected['writes'])

    def test_low_signed_halfword_abi_and_unused_output_tail(self):
        for mode, flag in (('normal', 0), ('downmix', 0), ('selector', 0), ('selector', 1)):
            prefix = f'{mode}_{flag:08X}_halfword_packing_'
            clean, poisoned = (self.by_name[prefix+str(v)]['expected'] for v in (False, True))
            self.assertEqual(clean['state'], poisoned['state'])
            self.assertEqual(clean['pcm_stores'], poisoned['pcm_stores'])
        result = Machine(self.pair(), 2, output_samples=64).run()
        self.assertEqual(result['state']['left_pcm_i16'][32:], [-23131]*32)
        self.assertEqual(result['state']['right_pcm_i16'][32:], [-23131]*32)

    def test_all_fixtures_abi_guards_and_readonly_spans(self):
        for case in self.fixture['cases']:
            result, initial = case['expected'], case['input']
            self.assertTrue(all(result['abi'].values()), case['name'])
            state = result['state']
            for field in ('left_guard_hex', 'right_guard_hex'):
                self.assertEqual(state[field], 'a5'*16)
            self.assertEqual(state['history_guard_hex'], 'b6'*16)
            self.assertEqual(state['key_guard_hex'], 'c7'*16)
            self.assertEqual(state['encoded_sha256'], hashlib.sha256(bytes.fromhex(initial['encoded_hex'])).hexdigest())
            self.assertEqual(state['nibble_table_sha256'], self.fixture['identity']['nibble_table_sha256'])
            self.assertEqual(state['selector_flag_u32'], initial['selector_flag_u32'])
            self.assertTrue(set(result['writes']) <= {'left_pcm', 'right_pcm', 'history', 'key', 'stack'})

    def test_complete_owned_words_match_generated_instruction_evidence(self):
        ref = Machine(b'', 0)
        for mode, (start, end) in BODIES.items():
            path = ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp'
            comments = {int(pc, 16): int(word, 16) for pc, word in
                        re.findall(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s', path.read_text(encoding='utf-8'))}
            self.assertEqual({pc: ref.code[pc] for pc in range(start, end, 4)},
                             {pc: comments[pc] for pc in range(start, end, 4)})
        self.assertEqual(list(__import__('struct').unpack('<16i', ref.table)),
                         [0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1])

    def test_finite_coverage_exactly_unreachable_breaks_and_tail_padding(self):
        self.assertEqual(self.fixture['coverage']['normal']['unvisited_pcs'], [])
        self.assertEqual(self.fixture['coverage']['downmix']['unvisited_pcs'], [0x127ACC, 0x127BCC])
        self.assertEqual(self.fixture['coverage']['selector']['unvisited_pcs'], [0x128014])
        self.assertEqual(self.fixture['counts']['owned_body_words'], 479)

    def test_fail_closed_short_input_output_step_limit_and_unknown_word(self):
        for encoded, capacity in ((self.pair()[:-1], 32), (self.pair(), 31), (b'\x80', 32)):
            with self.assertRaises(OracleError):
                Machine(encoded, 2, output_samples=capacity).run()
        with self.assertRaises(StepLimit):
            Machine(self.pair(), 2).run(step_cap=1)
        m = Machine(self.pair(), 2)
        m.code[m.pc] = 0xFFFFFFFF  # valid SD encoding -> unadmitted read of RA-relative address
        with self.assertRaises(OracleError):
            m.run()
        m = Machine(self.pair(), 2)
        m.code[m.pc] = 0x0000003F  # unsupported SPECIAL fn
        with self.assertRaises(UnknownInstruction):
            m.run()

    def test_admission_and_memory_access_boundaries(self):
        for args in (dict(requested=17), dict(requested=-2147483649),
                     dict(requested=2, mode='guessed'), dict(requested=2, key=65536),
                     dict(requested=2, history=(1, 2)), dict(requested=2, coefficients=(32768, 0)),
                     dict(requested=2, selector_flag=-1), dict(requested=2, output_samples=257)):
            requested = args.pop('requested')
            with self.assertRaises(OracleError):
                Machine(self.pair(), requested, **args)
        memory = ObservedMemory()
        memory.map(INPUT, 8)
        memory.allow('test', INPUT, 8)
        with self.assertRaises(OracleError):
            memory.allow('overlap', INPUT+4, 4)
        memory.active = True
        with self.assertRaises(OracleError):
            memory.store(INPUT, 1, 1)
        with self.assertRaises(OracleError):
            memory.load(INPUT+7, 2)

    def test_generation_is_deterministic_and_frozen_dependencies_unchanged(self):
        self.assertEqual(generate(), self.fixture)
        identity = self.fixture['identity']['tool_sha256']
        for name, expected in identity.items():
            self.assertEqual(hashlib.sha256(Path(__file__).with_name(name).read_bytes()).hexdigest(), expected)


if __name__ == '__main__':
    if len(sys.argv) >= 2 and sys.argv[1] == '--export-abi':
        if len(sys.argv) != 3:
            raise SystemExit('Usage: test_adx_stereo_oracle.py --export-abi OUTPUT.json')
        print(json.dumps(export_original_abi(sys.argv[2])))
    else:
        unittest.main()
