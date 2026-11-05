#!/usr/bin/env python3
"""Original-word, isolated SJUNI prologue/guard/continuation contract receipt.

Uses sjuni_oracle.Machine's instruction decoder unchanged. Synthetic hooks can
perform nested original operations on shared synthetic memory/disjoint frames.
No native queue algorithm, runtime, process, game or build is imported/executed.
The receipt contains synthetic frame data/PC hashes, never original code arrays.
"""
from __future__ import annotations

import argparse
from copy import deepcopy
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import struct

from sjuni_oracle import (Machine, Memory, OracleError, StepLimit, ENTRIES,
                          CODE_START, CODE_END, ENTER, LEAVE, MASK32, MASK64,
                          NODES, INPUT, OUTPUT, STACK_TOP, RETURN_SENTINEL,
                          STEP_CAP, ERROR_HOOK, CONTEXT, sext32, signed, ROOT)

PHASES = {
    'take': {'entry': 0x140300, 'enter_call': 0x140358, 'post_enter': 0x140360,
             'frame_bytes': 0x50, 'saved_gprs': {16: 0x20, 17: 0x28, 18: 0x30, 19: 0x38, 31: 0x40},
             'post_enter_operands': {'object_gpr': 16, 'queue_gpr': 18, 'request_gpr': 19, 'output_descriptor_gpr': 17},
             'leave_transfer': 0x140410, 'leave_kind': 'jal', 'post_leave': 0x140418,
             'completed_body_resume': 0x140410, 'end': 0x140434},
    'put': {'entry': 0x140438, 'enter_call': 0x140498, 'post_enter': 0x1404A0,
            'frame_bytes': 0x20, 'saved_gprs': {16: 0, 17: 8, 18: 0x10, 31: 0x18},
            'post_enter_operands': {'object_gpr': 16, 'queue_gpr': 18, 'input_descriptor_gpr': 17},
            'leave_transfer': 0x14056C, 'leave_kind': 'tail_j', 'post_leave': None,
            'completed_body_resume': 0x14055C, 'end': 0x14058C},
    'unget': {'entry': 0x140590, 'enter_call': 0x1405F0, 'post_enter': 0x1405F8,
              'frame_bytes': 0x20, 'saved_gprs': {16: 0, 17: 8, 18: 0x10, 31: 0x18},
              'post_enter_operands': {'object_gpr': 16, 'queue_gpr': 18, 'input_descriptor_gpr': 17},
              'leave_transfer': 0x1406B4, 'leave_kind': 'tail_j', 'post_leave': None,
              'completed_body_resume': 0x1406A4, 'end': 0x1406D4},
}
NESTED_INPUT = 0x500064
VOLATILE_GPRS = (1, *range(2, 16), 24, 25)
CALLEE_GPRS = (*range(16, 24), 28, 30)


@dataclass
class Checkpoint:
    elf_sha256: str
    operation: str
    original_arguments: tuple
    entry_sp: int
    initial_gprs: tuple
    gprs: tuple
    pc: int
    pending: tuple | None
    last_transfer_pc: int | None
    guard_depth: int
    steps: int
    visited: tuple
    events: list
    enter_calls: int
    leave_calls: int
    mutations: list
    object_address: int
    regions: tuple  # Private checkpoint: only synthetic memory, not ELF/code.


class ContinuationMachine(Machine):
    """Bounded continuation scheduler over the existing unchanged decoder."""
    def __init__(self, *args, enter_mutation=None, poison_volatile=True, **kwargs):
        super().__init__(*args, **kwargs)
        self.enter_mutation = enter_mutation
        self.poison_volatile = poison_volatile
        self.enter_calls = self.leave_calls = self.steps = 0
        self.mutations = []
        self.pending = None
        self.operation = None
        self.original_arguments = ()
        self.entry_sp = STACK_TOP
        self.initial_gprs = ()

    def begin(self, operation, args, stack_top=STACK_TOP):
        if operation not in PHASES or len(args) > 4 or stack_top % 16:
            raise OracleError('Unsupported phase entry/arguments/stack alignment')
        if self.guard_depth:
            raise OracleError('Canonical restart while guard is active requires explicit bad-restart experiment')
        self.operation = operation
        self.original_arguments = tuple(args)
        self.entry_sp = stack_top
        self.regs = [0] * 32
        # Distinct high64 saved values prove that the SD/LD original frame,
        # rather than reconstructed canonical arguments, carries return context.
        for reg in CALLEE_GPRS:
            self.regs[reg] = 0xA11CE00000000000 | reg
        self.regs[2] = 0xBAD0BAD0
        self.regs[29] = stack_top
        self.regs[31] = RETURN_SENTINEL
        for index, arg in enumerate(args): self.regs[4 + index] = sext32(arg)
        self.initial_gprs = tuple(self.regs)
        self.pc = PHASES[operation]['entry']
        self.pending = None
        self.events = []
        self.visited = set()
        self.last_transfer_pc = None
        self.steps = self.enter_calls = self.leave_calls = 0
        self.mutations = []

    def hook(self, pc):
        accepted = super().hook(pc)
        if not accepted:
            return False
        if pc == ENTER:
            self.enter_calls += 1
            if self.enter_mutation:
                self.mutations.append(self.enter_mutation(self))
            # A synchronous external guard is allowed to clobber caller-saved
            # registers. Both compared runs use the same deterministic hook.
            if self.poison_volatile:
                for reg in VOLATILE_GPRS:
                    self.regs[reg] = 0xD15EA5E000000000 | reg
        elif pc == LEAVE:
            self.leave_calls += 1
        return True

    def advance(self, stop_before=(), step_cap=STEP_CAP):
        if not 1 <= step_cap <= STEP_CAP:
            raise OracleError('Continuation limit must be bounded by original oracle cap')
        stops = set(stop_before)
        used = 0
        while self.pc != RETURN_SENTINEL:
            if self.pending is None and self.pc in stops:
                return 'stopped'
            if used >= step_cap:
                raise StepLimit('Continuation exceeded finite step cap')
            used += 1
            self.steps += 1
            if self.pending is None and self.hook(self.pc):
                continue
            pc = self.pc
            if not CODE_START <= pc < CODE_END or pc % 4:
                raise OracleError(f'Continuation fetch outside original SJUNI text at{pc:#x}')
            word = struct.unpack_from('<I', self.code, pc - CODE_START)[0]
            self.visited.add(pc)
            branch = self.instruction(pc, word)
            if self.pending is not None:
                if branch is not None:
                    raise OracleError('Control transfer in continuation delay slot')
                self.pc, self.last_transfer_pc = self.pending
                self.pending = None
            elif branch is not None:
                taken, target, likely = branch
                if not taken and likely:
                    self.pc = pc + 8
                else:
                    self.pending = (target if taken else pc + 8, pc)
                    self.pc = pc + 4
            else:
                self.pc = pc + 4
        if self.guard_depth:
            raise OracleError('Returned with substituted guard still entered')
        return 'returned'

    def checkpoint(self):
        return Checkpoint(self.elf.sha256, self.operation, self.original_arguments,
                          self.entry_sp, self.initial_gprs, tuple(self.regs), self.pc,
                          self.pending, self.last_transfer_pc, self.guard_depth,
                          self.steps, tuple(sorted(self.visited)), deepcopy(self.events),
                          self.enter_calls, self.leave_calls, deepcopy(self.mutations),
                          self.object, tuple((base, bytes(data)) for base, data in self.mem.regions))

    def restore(self, checkpoint):
        if checkpoint.elf_sha256 != self.elf.sha256 or checkpoint.operation not in PHASES:
            raise OracleError('Continuation identity/operation mismatch')
        if len(checkpoint.gprs) != 32 or checkpoint.gprs[0] != 0 or any(
                not 0 <= value <= MASK64 for value in checkpoint.gprs):
            raise OracleError('Invalid full GPR checkpoint')
        memory = Memory()
        for base, data in checkpoint.regions:
            memory.map(base, len(data))
            region, offset = memory.region(base, len(data))
            region[offset:offset + len(data)] = data
        self.mem = memory
        self.operation, self.original_arguments = checkpoint.operation, checkpoint.original_arguments
        self.entry_sp, self.initial_gprs = checkpoint.entry_sp, checkpoint.initial_gprs
        self.regs, self.pc = list(checkpoint.gprs), checkpoint.pc
        self.pending, self.last_transfer_pc = checkpoint.pending, checkpoint.last_transfer_pc
        self.guard_depth, self.steps = checkpoint.guard_depth, checkpoint.steps
        self.visited, self.events = set(checkpoint.visited), deepcopy(checkpoint.events)
        self.enter_calls, self.leave_calls = checkpoint.enter_calls, checkpoint.leave_calls
        self.mutations = deepcopy(checkpoint.mutations)
        self.object = checkpoint.object_address

    def restore_post_enter(self, checkpoint):
        """Accept only a captured original post-enter frame, never canonicalize.

        This rejects an unknown frame terminally in the harness. It cannot
        justify restarting canonical entry after an external hook already ran.
        Queue-state admission is deliberately NOT a native algorithm here.
        """
        if checkpoint.operation not in PHASES:
            raise OracleError('Unknown post-enter operation')
        phase = PHASES[checkpoint.operation]
        if (checkpoint.pc != phase['post_enter'] or checkpoint.pending is not None or
                checkpoint.guard_depth != 1 or checkpoint.enter_calls != 1 or checkpoint.leave_calls != 0 or
                len(checkpoint.gprs) != 32 or len(checkpoint.initial_gprs) != 32 or
                checkpoint.gprs[29] != checkpoint.entry_sp - phase['frame_bytes'] or
                checkpoint.gprs[31] != phase['post_enter']):
            raise OracleError('Unknown post-enter phase/frame; canonical restart is unsafe')
        memory = Memory()
        for base, data in checkpoint.regions:
            memory.map(base, len(data))
            region, offset = memory.region(base, len(data))
            region[offset:offset + len(data)] = data
        frame = checkpoint.entry_sp - phase['frame_bytes']
        for reg, offset in phase['saved_gprs'].items():
            if memory.load(frame + offset, 8) != checkpoint.initial_gprs[reg]:
                raise OracleError('Unknown original saved-frame contents; canonical restart is unsafe')
        self.restore(checkpoint)

    def receipt_state(self):
        phase = PHASES[self.operation]
        frame_base = self.entry_sp - phase['frame_bytes']
        data, offset = self.mem.region(frame_base, phase['frame_bytes'])
        frame = bytes(data[offset:offset + phase['frame_bytes']])
        return {
            'pc': self.pc, 'gprs_lower64_u64': list(self.regs),
            'pending_delay_transfer': self.pending,
            'stack_pointer': self.regs[29], 'caller_stack_pointer': self.entry_sp,
            'saved_frame_base': frame_base, 'saved_frame_bytes': phase['frame_bytes'],
            'synthetic_saved_frame_hex': frame.hex(), 'saved_frame_sha256': hashlib.sha256(frame).hexdigest(),
            'saved_gpr_words_u64': {str(reg): self.mem.load(frame_base + off, 8)
                                    for reg, off in phase['saved_gprs'].items()},
            'original_queue_memory': self.snapshot(),
            'synthetic_memory_regions': [{'base': base, 'size': len(data),
                                         'sha256': hashlib.sha256(data).hexdigest()}
                                        for base, data in self.mem.regions],
            'guard_depth': self.guard_depth, 'outer_enter_calls': self.enter_calls,
            'outer_leave_calls': self.leave_calls,
            'outer_event_kinds': [event['kind'] for event in self.events],
            'nested_original_operations': deepcopy(self.mutations),
            'steps': self.steps, 'visited_original_pcs': sorted(self.visited),
        }


def original_call(machine, operation, args, stack_top):
    """Nested original call, same synthetic memory, separate register/frame set."""
    nested = ContinuationMachine(node_capacity=machine.node_capacity,
                                 poison_volatile=machine.poison_volatile)
    nested.mem = machine.mem
    nested.object = machine.object
    nested.begin(operation, args, stack_top)
    nested.advance()
    return nested


def mutate_by_nested_original(machine):
    # Never calls a native algorithm. The three mutations exercise queue-head
    # splitting or adjacency that only exists after the original enter hook.
    operation = machine.operation
    before = machine.snapshot()
    if operation == 'take':
        args = [machine.object, 0, 8, NESTED_INPUT]
    else:
        pointer = 0x600110 if operation == 'put' else 0x6000F0
        machine.mem.store(NESTED_INPUT, 4, pointer)
        machine.mem.store(NESTED_INPUT + 4, 4, 16)
        args = [machine.object, 0, NESTED_INPUT]
    nested = original_call(machine, operation, args, machine.regs[29] - 0x100)
    return {'entry': ENTRIES[operation][0], 'arguments_i32': [signed(x, 32) for x in args],
            'separate_stack_pointer': nested.entry_sp,
            'original_pcs': sorted(nested.visited),
            'event_kinds': [event['kind'] for event in nested.events],
            'before': before, 'after': machine.snapshot()}


def prepared(operation):
    machine = ContinuationMachine(node_capacity=4, enter_mutation=mutate_by_nested_original)
    # Setup also interprets original words; no queue construction algorithm is
    # duplicated in Python. Disable mutation while arranging this fixed input.
    Machine.run(machine, 'create', [1, NODES, 64])
    Machine.run(machine, 'set_error', [machine.object, ERROR_HOOK, CONTEXT])
    machine.mem.store(INPUT, 4, 0x600100)
    machine.mem.store(INPUT + 4, 4, 16)
    old_mutator = machine.enter_mutation
    machine.enter_mutation = None
    Machine.run(machine, 'put', [machine.object, 0, INPUT])
    machine.enter_mutation = old_mutator
    if operation == 'take':
        args = [machine.object, 0, 16, OUTPUT]
    else:
        pointer = 0x600120 if operation == 'put' else 0x6000E0
        machine.mem.store(INPUT, 4, pointer)
        machine.mem.store(INPUT + 4, 4, 16)
        args = [machine.object, 0, INPUT]
    machine.begin(operation, args)
    return machine


def same_final(first, second):
    return (first.pc == second.pc == RETURN_SENTINEL and first.regs == second.regs and
            first.mem.regions == second.mem.regions and first.guard_depth == second.guard_depth and
            first.enter_calls == second.enter_calls and first.leave_calls == second.leave_calls and
            first.events == second.events and first.mutations == second.mutations)


def contract_case(operation):
    phase = PHASES[operation]
    baseline = prepared(operation)
    initial = baseline.checkpoint()
    baseline.advance()

    paused = prepared(operation)
    assert paused.advance([ENTER]) == 'stopped'
    before_enter = paused.receipt_state()
    assert paused.pending is None and paused.regs[31] == phase['post_enter']
    assert paused.advance([phase['post_enter']]) == 'stopped'
    post_enter = paused.receipt_state()
    assert paused.enter_calls == 1 and paused.leave_calls == 0
    assert paused.guard_depth == 1 and paused.pending is None
    # A deliberately declined native admission decision performs no writes.
    # Resume from the exact post-enter context, not canonical arguments.
    post_checkpoint = paused.checkpoint()
    resumed = prepared(operation)
    resumed.restore_post_enter(post_checkpoint)
    assert resumed.advance([LEAVE]) == 'stopped'
    before_leave = resumed.receipt_state()
    leave_checkpoint = resumed.checkpoint()
    after_leave = prepared(operation)
    after_leave.restore(leave_checkpoint)
    assert after_leave.advance() == 'returned'
    assert same_final(baseline, after_leave), operation

    # Also stop at the real completed-body epilogue join. This is NOT a native
    # operation implementation: original queue instructions have already run.
    body = prepared(operation)
    body.restore_post_enter(post_checkpoint)
    assert body.advance([phase['completed_body_resume']]) == 'stopped'
    completed_body = body.receipt_state()
    body.advance()
    assert same_final(baseline, body), operation

    # Controlled negative witness: restarting canonical entry repeats the hook.
    # Reset only its GPR call inputs/frame bookkeeping, preserving post-hook
    # queue memory. The previous logical guard remains active to show imbalance.
    wrong = prepared(operation)
    wrong.restore(post_checkpoint)
    prior_guard = wrong.guard_depth
    wrong.guard_depth = 0  # permit construction of explicit bad-restart frame
    wrong.begin(operation, initial.original_arguments)
    wrong.guard_depth = prior_guard  # the abandoned first enter was never left
    try:
        wrong.advance()
    except OracleError as error:
        if (str(error) != 'Returned with substituted guard still entered' or
                wrong.pc != RETURN_SENTINEL or wrong.guard_depth != prior_guard):
            raise
    else:
        raise AssertionError('Canonical restart unexpectedly balanced abandoned enter')
    wrong_final = wrong.receipt_state()
    wrong_final['earlier_unmatched_enter_depth'] = prior_guard
    wrong_final['bad_return_retains_abandoned_enter'] = wrong.guard_depth == prior_guard
    wrong_final['total_enter_calls_including_discarded_prologue'] = 1 + wrong.enter_calls
    wrong_final['queue_or_output_differs_from_uninterrupted'] = wrong.snapshot() != baseline.snapshot()
    assert wrong_final['total_enter_calls_including_discarded_prologue'] == 2
    assert wrong_final['queue_or_output_differs_from_uninterrupted']

    preserved = all(after_leave.regs[reg] == initial.initial_gprs[reg] for reg in CALLEE_GPRS)
    assert preserved and after_leave.regs[29] == initial.entry_sp
    return {'operation': operation, 'phase_contract': phase,
            'uninterrupted_final': baseline.receipt_state(),
            'before_enter_hook': before_enter, 'post_enter_native_admission_declined': post_enter,
            'before_leave_hook': before_leave, 'completed_body_epilogue_join': completed_body,
            'resumed_final': after_leave.receipt_state(),
            'checks': {'post_enter_resume_matches_uninterrupted': True,
                       'completed_body_epilogue_matches_uninterrupted': True,
                       'callee_saved_lower64_and_caller_sp_restored': preserved,
                       'outer_guard_entered_once_left_once': after_leave.enter_calls == after_leave.leave_calls == 1},
            'canonical_restart_negative_witness': wrong_final}


def generate():
    cases = [contract_case(operation) for operation in PHASES]
    sample = prepared('take')
    intervals = [{'operation': operation, 'start_pc': phase['entry'], 'end_pc_exclusive': phase['end'],
                  'sha256': hashlib.sha256(sample.elf.read(phase['entry'], phase['end'] - phase['entry'])).hexdigest()}
                 for operation, phase in PHASES.items()]
    decoder = Path(__file__).with_name('sjuni_oracle.py')
    return {'schema': 1, 'kind': 'original_word_sjuni_guarded_continuation_contract',
            'identity': {'elf_sha256': sample.elf.sha256,
                         'decoder_path': decoder.relative_to(ROOT).as_posix(),
                         'decoder_sha256': hashlib.sha256(decoder.read_bytes()).hexdigest(),
                         'intervals': intervals},
            'limits': {'step_cap_per_advance': STEP_CAP,
                'execution': 'owned integer instruction words over isolated synthetic memory only',
                'hooks': 'synchronous trace/mutation substitute; no actual CRI scheduler or runtime callback dispatch',
                'registers': 'all32 lower64 GPRs; no upper64 EE GPR lanes/FPU/VU/MMI/CP0 model',
                'synthetic_frame_hex': 'synthetic saved data and return-PC values; not original instruction bytes',
                'resume': 'resume exact captured post-enter PC/GPR/frame/memory, with no second enter',
                'native_body': 'none; epilogue tests execute the original body before resuming original join',
                'unknown_instruction': 'abort through unchanged original-word decoder'},
            'recommendation': {
                'unsupported_after_enter_before_queue_effects': 'restore exact post-enter context and resume original continuation; never restart canonical entry',
                'post_enter_arguments': 'read preserved s0/s1/s2 and Get s3, not caller-saved a0..a3; the receipt deliberately poisons caller-saved registers after enter',
                'native_phase': 'an already-entered body must not call the canonical native operation enter hook again; use an explicit phase API or separately proved body-only route',
                'completed_native_body': 'publish exact queue/output state before the leave hook, then execute the original completed-body epilogue join with its original saved frame',
                'after_native_effects': 'post-enter fallback is no longer safe; require a separately proven completion/rollback or terminal rejection',
                'before_original_prologue_or_any_hook': 'canonical fallback remains possible only while no original/native effects have occurred',
                'runtime_activation': 'not authorized by this receipt; runtime frame ownership, full EE context, exception/continuation and installed-hook lifetime remain separate integration requirements'},
            'counts': {'operations': len(cases), 'positive_continuation_cases': len(cases),
                       'canonical_restart_negative_witnesses': len(cases)},
            'cases': cases}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, default=Path(__file__).with_name('sjuni_continuation_contract_receipt.json'))
    args = parser.parse_args()
    result = generate()
    output = args.output.resolve()
    if output.parent != Path(__file__).resolve().parent:
        raise OracleError('Continuation receipt must stay in tools/native_reconstruction')
    output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'output': str(output), **result['counts']}))


if __name__ == '__main__':
    main()
