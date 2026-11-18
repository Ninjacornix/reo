"""Original-word continuation/frame tests; no runtime or native algorithm."""
from dataclasses import replace
import unittest

from sjuni_continuation_contract import (
    ContinuationMachine, PHASES, CALLEE_GPRS, prepared, contract_case, same_final,
    generate, ENTER, LEAVE, STEP_CAP, RETURN_SENTINEL, OracleError, StepLimit,
)


class OriginalContinuationTests(unittest.TestCase):
    def test_prologues_preserve_original_callee_frame_before_enter(self):
        for operation, phase in PHASES.items():
            with self.subTest(operation=operation):
                machine = prepared(operation)
                self.assertEqual(machine.advance([ENTER]), 'stopped')
                self.assertEqual(machine.regs[29], machine.entry_sp - phase['frame_bytes'])
                self.assertEqual(machine.regs[31], phase['post_enter'])
                self.assertEqual(machine.guard_depth, 0)
                self.assertEqual(machine.enter_calls, 0)
                frame = machine.regs[29]
                for reg, offset in phase['saved_gprs'].items():
                    self.assertEqual(machine.mem.load(frame + offset, 8), machine.initial_gprs[reg])

    def test_nested_original_mutation_then_postenter_resume_matches_uninterrupted(self):
        for operation in PHASES:
            with self.subTest(operation=operation):
                baseline = prepared(operation)
                baseline.advance()
                machine = prepared(operation)
                machine.advance([ENTER])
                before = machine.snapshot()
                machine.advance([PHASES[operation]['post_enter']])
                self.assertNotEqual(before, machine.snapshot())
                self.assertEqual(len(machine.mutations), 1)
                self.assertEqual(machine.mutations[0]['event_kinds'], ['enter', 'leave'])
                self.assertEqual(machine.regs[16], machine.original_arguments[0])
                self.assertEqual(machine.regs[18], machine.original_arguments[1])
                self.assertNotEqual(machine.regs[4], machine.original_arguments[0])
                self.assertEqual(machine.regs[17], machine.original_arguments[3 if operation == 'take' else 2])
                if operation == 'take':
                    self.assertEqual(machine.regs[19], machine.original_arguments[2])
                checkpoint = machine.checkpoint()
                resumed = prepared(operation)
                resumed.restore_post_enter(checkpoint)
                resumed.advance()
                self.assertTrue(same_final(baseline, resumed))
                self.assertEqual(resumed.enter_calls, 1)
                self.assertEqual(resumed.leave_calls, 1)
                self.assertEqual(len(resumed.regs), 32)
                for reg in CALLEE_GPRS:
                    self.assertEqual(resumed.regs[reg], resumed.initial_gprs[reg])

    def test_get_retains_frame_at_leave_but_put_unget_have_tail_restored(self):
        for operation, phase in PHASES.items():
            with self.subTest(operation=operation):
                machine = prepared(operation)
                machine.advance([LEAVE])
                self.assertEqual(machine.leave_calls, 0)
                self.assertEqual(machine.guard_depth, 1)
                if operation == 'take':
                    self.assertEqual(machine.regs[29], machine.entry_sp - 0x50)
                    self.assertEqual(machine.regs[31], 0x140418)
                else:
                    self.assertEqual(machine.regs[29], machine.entry_sp)
                    self.assertEqual(machine.regs[31], RETURN_SENTINEL)
                    for reg in phase['saved_gprs']:
                        self.assertEqual(machine.regs[reg], machine.initial_gprs[reg])
                machine.advance()
                self.assertEqual(machine.leave_calls, 1)
                self.assertEqual(machine.regs[29], machine.entry_sp)

    def test_completed_original_body_epilogue_join_matches_full_return(self):
        for operation in PHASES:
            with self.subTest(operation=operation):
                result = contract_case(operation)
                self.assertTrue(result['checks']['completed_body_epilogue_matches_uninterrupted'])
                self.assertTrue(result['checks']['post_enter_resume_matches_uninterrupted'])

    def test_canonical_restart_repeats_enter_and_changes_result(self):
        for operation in PHASES:
            with self.subTest(operation=operation):
                result = contract_case(operation)['canonical_restart_negative_witness']
                self.assertEqual(result['total_enter_calls_including_discarded_prologue'], 2)
                self.assertEqual(result['earlier_unmatched_enter_depth'], 1)
                self.assertEqual(result['guard_depth'], 1)
                self.assertTrue(result['bad_return_retains_abandoned_enter'])
                self.assertTrue(result['queue_or_output_differs_from_uninterrupted'])

    def test_unknown_postenter_frame_is_rejected_without_mutating_destination(self):
        machine = prepared('take')
        machine.advance([PHASES['take']['post_enter']])
        checkpoint = machine.checkpoint()
        for bad in (replace(checkpoint, pc=PHASES['take']['entry']),
                    replace(checkpoint, pending=(PHASES['take']['post_enter'], 0)),
                    replace(checkpoint, enter_calls=2),
                    replace(checkpoint, elf_sha256='0' * 64)):
            destination = prepared('take')
            before = destination.checkpoint()
            with self.assertRaises(OracleError): destination.restore_post_enter(bad)
            self.assertEqual(destination.checkpoint(), before)

    def test_corrupt_saved_frame_is_rejected_before_restore(self):
        machine = prepared('put')
        machine.advance([PHASES['put']['post_enter']])
        checkpoint = machine.checkpoint()
        regions = list(checkpoint.regions)
        target = checkpoint.entry_sp - PHASES['put']['frame_bytes']
        for index, (base, data) in enumerate(regions):
            if base <= target < base + len(data):
                changed = bytearray(data)
                changed[target - base] ^= 1
                regions[index] = (base, bytes(changed))
                break
        bad = replace(checkpoint, regions=tuple(regions))
        with self.assertRaisesRegex(OracleError, 'saved-frame'):
            prepared('put').restore_post_enter(bad)

    def test_continuation_step_cap_and_unbounded_limit_fail_closed(self):
        with self.assertRaises(StepLimit): prepared('put').advance(step_cap=1)
        with self.assertRaises(OracleError): prepared('put').advance(step_cap=STEP_CAP + 1)

    def test_receipt_contains_complete_registers_and_no_original_code_arrays(self):
        receipt = generate()
        self.assertEqual(receipt['counts']['positive_continuation_cases'], 3)
        self.assertEqual(receipt['counts']['canonical_restart_negative_witnesses'], 3)
        for case in receipt['cases']:
            for name in ('before_enter_hook', 'post_enter_native_admission_declined',
                         'before_leave_hook', 'resumed_final'):
                self.assertEqual(len(case[name]['gprs_lower64_u64']), 32)
                self.assertEqual(len(case[name]['synthetic_saved_frame_hex']), 2 * case[name]['saved_frame_bytes'])
        self.assertNotIn('code_bytes', receipt)
        self.assertNotIn('instruction_words', receipt)


if __name__ == '__main__':
    unittest.main()
