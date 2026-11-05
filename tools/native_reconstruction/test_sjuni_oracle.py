"""Fail-closed interpreter checks and original-output fixtures, no game/native core."""
import json
from pathlib import Path
import tempfile
import unittest

from sjuni_oracle import (Machine, Scenario, OracleError, UnknownInstruction,
                          StepLimit, INPUT, OUTPUT, NODES, POOL, MASK64,
                          ERROR_HOOK, CONTEXT, generate)


class InstructionBoundaryTests(unittest.TestCase):
    def test_wrong_owned_identity_rejected_before_execution(self):
        with tempfile.TemporaryDirectory(dir=Path(__file__).parent) as tmp:
            path = Path(tmp) / 'wrong.elf'
            path.write_bytes(b'not the owned File #1 ELF')
            with self.assertRaisesRegex(ValueError, 'identity mismatch'):
                Machine(path)

    def test_unknown_opcode_and_unknown_special_fail_closed(self):
        m = Machine()
        with self.assertRaises(UnknownInstruction):
            m.instruction(0x140000, 0xFC000000 - (1 << 26))  # unsupported op62
        with self.assertRaises(UnknownInstruction):
            m.instruction(0x140000, 0x0000000C)  # syscall, not an allowed hook

    def test_step_cap_stops_valid_original_operation(self):
        m = Machine()
        with self.assertRaises(StepLimit):
            m.run('create', [1, NODES, 64], step_cap=1)

    def test_unknown_entry_and_unmapped_memory_abort(self):
        m = Machine()
        with self.assertRaises(OracleError): m.run('not_an_operation', [])
        with self.assertRaises(OracleError): m.mem.load(0, 4)

    def test_little_endian_doubleword_merge_all_alignments(self):
        # Independently known byte sequence; tests LDL/LDR and SDL/SDR without
        # relying on any queue algorithm or distributing original instructions.
        for alignment in range(8):
            m = Machine()
            m.mem.map(0x1000, 0x100)
            for i in range(0x100): m.mem.store(0x1000 + i, 1, i)
            m.regs[1] = 0x1020 + alignment
            m.regs[2] = 0xAABBCCDDEEFF0011
            m.instruction(0, (26 << 26) | (1 << 21) | (2 << 16) | 7)
            m.instruction(4, (27 << 26) | (1 << 21) | (2 << 16))
            expected = int.from_bytes(bytes(range(0x20 + alignment, 0x28 + alignment)), 'little')
            self.assertEqual(m.regs[2], expected)
            m.regs[1] = 0x1080 + alignment
            m.instruction(8, (44 << 26) | (1 << 21) | (2 << 16) | 7)
            m.instruction(12, (45 << 26) | (1 << 21) | (2 << 16))
            for i in range(0x70, 0xA0):
                expected_byte = i
                if 0x80 + alignment <= i < 0x88 + alignment:
                    expected_byte = i - 0x60
                self.assertEqual(m.mem.load(0x1000 + i, 1), expected_byte)

    def test_word_sign_extension_and_64bit_add_are_distinct(self):
        m = Machine()
        m.instruction(0, (15 << 26) | (2 << 16) | 0x8000)
        self.assertEqual(m.regs[2], 0xFFFFFFFF80000000)
        m.instruction(4, (9 << 26) | (2 << 21) | (3 << 16) | 0xFFFF)
        self.assertEqual(m.regs[3], 0x7FFFFFFF)
        m.regs[1], m.regs[2] = MASK64, 2
        m.instruction(8, (1 << 21) | (2 << 16) | (3 << 11) | 45)
        self.assertEqual(m.regs[3], 1)


class OriginalOperationTests(unittest.TestCase):
    def test_constructor_reset_preserves_untouched_node_word(self):
        s = Scenario('constructor', nodes=3)
        self.assertEqual(s.obj, POOL)
        state = s.operations[0]['expected']['state']
        self.assertEqual(state['object_words_u32'][4], 3)
        self.assertEqual(state['object_words_u32'][5], NODES)
        self.assertEqual([n['words_u32'][1] for n in state['nodes']],
                         [0xC0DE0000, 0xC0DE0001, 0xC0DE0002])
        s.put(2, 0x600100, 16)
        state = s.call('reset', [s.obj])['state']
        self.assertEqual(state['object_words_u32'][6:10], [0] * 4)
        self.assertEqual([n['words_u32'][1] for n in state['nodes']],
                         [0xC0DE0000, 0xC0DE0001, 0xC0DE0002])

    def test_non_splitting_availability_differs_from_whole_take(self):
        s = Scenario('mode0', mode=0, nodes=2)
        s.put(3, 0x600100, 16)
        self.assertEqual(s.available(3, 17)['return_u32'], 0)
        state = s.take(3, 17)['state']
        self.assertEqual(state['buffers']['output']['words_u32'], [0x600100, 16])
        self.assertEqual(state['object_words_u32'][9], 0)

    def test_zero_and_negative_split_follow_original_signed_arithmetic(self):
        for request, expected_pointer, expected_length in ((0, 0x600100, 16), (-1, 0x6000FF, 17)):
            s = Scenario('signed', nodes=2)
            s.put(1, 0x600100, 16)
            state = s.take(1, request)['state']
            self.assertEqual(state['buffers']['output']['words_u32'], [0x600100, request & 0xFFFFFFFF])
            self.assertEqual(state['nodes'][0]['words_u32'][2:], [expected_pointer, expected_length])

    def test_invalid_take_callback_precedes_clear_available_clears_first(self):
        s = Scenario('callback', nodes=1)
        r = s.take(4, 16)
        self.assertEqual([e['kind'] for e in r['events']], ['registered_error'])
        e = r['events'][0]
        self.assertEqual((e['context_u32'], e['error_i32'], e['guard_depth_before']), (CONTEXT, -3, 0))
        self.assertEqual(e['observed_before']['buffers']['output']['words_u32'], [0xA1A2A3A4, 0xB1B2B3B4])
        self.assertEqual(r['state']['buffers']['output']['words_u32'], [0, 0])
        r = s.available(4, 16)
        self.assertEqual(r['events'][0]['observed_before']['buffers']['output']['words_u32'][0], 0)

    def test_exhaustion_inside_guard_but_adjacent_merge_still_succeeds(self):
        s = Scenario('exhaustion', nodes=1)
        s.put(0, 0x600100, 16)
        r = s.put(0, 0x600200, 16)
        self.assertEqual([e['kind'] for e in r['events']], ['enter', 'registered_error', 'leave'])
        self.assertEqual(r['events'][1]['guard_depth_before'], 1)
        r = s.put(0, 0x600110, 16)
        self.assertEqual([e['kind'] for e in r['events']], ['enter', 'leave'])
        self.assertEqual(r['state']['nodes'][0]['words_u32'][3], 32)
        self.assertEqual(r['state']['object_words_u32'][5], 0)

    def test_byte_sum_wrap_is_original_word_result(self):
        s = Scenario('wrap', nodes=2)
        s.put(0, 0x80000000, 0x7FFFFFFF)
        s.put(0, 0x100, 5)
        self.assertEqual(s.call('sum_bytes', [s.obj, 0])['return_u32'], 0x80000004)

    def test_generated_fixture_has_identity_trace_and_no_code_arrays(self):
        fixture = generate()
        self.assertGreaterEqual(fixture['counts']['operations'], 365)
        self.assertEqual(len(fixture['identity']['intervals']), 16)
        self.assertEqual(fixture['execution']['unknown_instruction'], 'abort')
        encoded = json.dumps(fixture)
        self.assertNotIn('instruction_words', encoded)
        self.assertNotIn('code_bytes', encoded)
        self.assertTrue(all(len(i['sha256']) == 64 for i in fixture['identity']['intervals']))


if __name__ == '__main__':
    unittest.main()
