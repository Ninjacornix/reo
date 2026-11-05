#!/usr/bin/env python3
"""Seeded bounded original-word/native-body continuation comparison.

Only synthetic metadata and an explicitly supplied isolated C++ body probe are
used. Python chooses inputs but never implements queue mutation algorithms.
No game/runtime build, game launch, attachment, IOP, DMA or device execution.
"""
from collections import Counter
import argparse
import hashlib
import json
from pathlib import Path
import random

from compare_sjuni_continuations import native_body
from sjuni_continuation_contract import ContinuationMachine, PHASES, CALLEE_GPRS
from sjuni_oracle import (Machine, Memory, ROOT, POOL, NODES, INPUT, OUTPUT,
                          ERROR_HOOK, CONTEXT, STACK_BASE, LEAVE, MASK32,
                          RETURN_SENTINEL, OracleError)

MODES = (0, 1, 2, 257)
MAX_OPERATIONS_PER_MODE = 128
DEFAULT_SEED = 0x5A1F0001


def sha(data): return hashlib.sha256(data).hexdigest()


def memory_identity(machine, include_stack=False):
    return [(base, sha(data)) for base, data in machine.mem.regions
            if include_stack or base != STACK_BASE]


def fresh_memory(machine, template, mode):
    machine.mem = Memory()
    for base, data in template:
        machine.mem.map(base, len(data))
        target, offset = machine.mem.region(base, len(data))
        target[offset:offset + len(data)] = data
    machine.object = POOL
    machine.guard_depth = 0
    Machine.run(machine, 'create', [mode, NODES, 16 * 16])
    Machine.run(machine, 'set_error', [POOL, ERROR_HOOK, CONTEXT])


def endpoint(machine, queue, tail=False):
    """Read a test-input lead from original state; never mutates a queue."""
    pointer = machine.mem.load(POOL + 24 + 4 * queue, 4)
    if pointer == 0: return None
    visited = set()
    while tail:
        if pointer in visited: raise OracleError('Unexpected cyclic original test state')
        visited.add(pointer)
        next_pointer = machine.mem.load(pointer, 4)
        if next_pointer == 0: break
        pointer = next_pointer
    return machine.mem.load(pointer + 8, 4), machine.mem.load(pointer + 12, 4)


def select_input(machine, rng, index):
    # Deterministic warm-up reaches exhaustion, adjacency with no free metadata,
    # an overlarge take, and publication of the actual returned span elsewhere.
    if index < 16:
        return 'put', 0, 0, 0x600100 + index * 0x100, 16, 'fill_nonadjacent'
    if index in (16, 17):
        return ('put' if index == 16 else 'unget'), 0, 0, 0x605000, 16, 'exhaustion'
    if index == 18:
        pointer, length = endpoint(machine, 0, True)
        return 'put', 0, 0, (pointer + length) & MASK32, 16, 'adjacent_tail_at_capacity'
    if index == 19:
        pointer, _ = endpoint(machine, 0)
        return 'unget', 0, 0, pointer - 16, 16, 'adjacent_head_at_capacity'
    if index == 20: return 'take', 0, 0x7FFFFFFF, 0, 0, 'overlarge_take'
    if index == 21:
        pointer, length = machine.mem.words(OUTPUT, 2)
        return 'put', 1, 0, pointer, length, 'republish_original_returned_span'
    if index == 22: return 'take', 1, 0, 0, 0, 'zero_take'
    if index == 23: return 'take', 1, -8, 0, 0, 'negative_take'
    if index == 24: return 'put', 4, 0, 0, -1, 'invalid_selector_before_span_admission'
    if index == 25: return 'take', 4, 16, 0, 0, 'invalid_selector_before_enter'
    if index == 26: return 'put', 2, 0, 0, 16, 'null_before_enter'
    if index == 27: return 'unget', 2, 0, 0x600100, 0, 'nonpositive_before_enter'
    if index == 28:
        # Deliberately outside native signed-remainder admission. The original
        # words still produce their32-bit result; the probe must decline with
        # no copy-back, then the ORIGINAL post-enter body continues exactly once.
        return 'take', 1, -0x80000000, 0, 0, 'unsupported_signed_remainder_overflow'

    operation = rng.choices(('take', 'put', 'unget'), weights=(38, 42, 20))[0]
    queue = rng.randrange(4) if rng.random() > 0.06 else rng.choice((4, -1))
    if operation == 'take':
        request = rng.choice((0, -1, -8, -16, 1, 8, 16, 32, 64, 128, 0x7FFFFFFF))
        return operation, queue, request, 0, 0, 'random_take'
    length = rng.choice((1, 8, 16, 32, 48, 64, 128))
    pointer = 0x610000 + rng.randrange(512) * 0x100
    label = 'random_nonadjacent_publish'
    selected = endpoint(machine, queue, operation == 'put') if 0 <= queue < 4 else None
    if selected and rng.random() < 0.5:
        old_pointer, old_length = selected
        pointer = ((old_pointer + old_length) if operation == 'put' else old_pointer - length) & MASK32
        label = 'random_adjacent_publish'
    if rng.random() < 0.07:
        pointer, length = rng.choice(((0, 16), (pointer, 0), (pointer, -1)))
        label = 'random_preenter_noop'
    return operation, queue, 0, pointer, length, label


def compare_state(baseline, hybrid, checkpoint, operation, compare_events):
    if baseline.snapshot() != hybrid.snapshot():
        raise AssertionError('Original/native object, nodes or descriptor mismatch')
    if memory_identity(baseline) != memory_identity(hybrid):
        raise AssertionError('Original/native non-stack memory mismatch')
    for reg in CALLEE_GPRS:
        if baseline.regs[reg] != hybrid.regs[reg] or hybrid.regs[reg] != checkpoint.initial_gprs[reg]:
            raise AssertionError(f'Callee register mismatch r{reg}')
    if (baseline.regs[29] != hybrid.regs[29] or hybrid.regs[29] != checkpoint.entry_sp or
            baseline.regs[31] != hybrid.regs[31] or baseline.pc != hybrid.pc or
            baseline.pc != RETURN_SENTINEL):
        raise AssertionError('Original/native stack, RA or return-PC mismatch')
    phase = PHASES[operation]
    frame = checkpoint.entry_sp - phase['frame_bytes']
    for reg, offset in phase['saved_gprs'].items():
        if baseline.mem.load(frame + offset, 8) != hybrid.mem.load(frame + offset, 8):
            raise AssertionError('Original saved-frame slot changed')
    if (baseline.guard_depth != hybrid.guard_depth or baseline.guard_depth != 0 or
            baseline.enter_calls != hybrid.enter_calls or baseline.leave_calls != hybrid.leave_calls):
        raise AssertionError('Original guard enter/leave count mismatch')
    if compare_events:
        if len(baseline.events) != len(hybrid.events):
            raise AssertionError('Original callback event-count mismatch')
        for expected, actual in zip(baseline.events, hybrid.events, strict=True):
            for key in ('kind', 'guard_depth_before', 'guard_depth_after', 'observed_before'):
                if expected[key] != actual[key]:
                    raise AssertionError(f'Original callback image/order mismatch:{key}')


def compare(probe, output, seed=DEFAULT_SEED, operations_per_mode=128):
    if not 1 <= operations_per_mode <= MAX_OPERATIONS_PER_MODE:
        raise ValueError('operations-per-mode must be1..128; maximum512 total')
    probe = Path(probe).resolve()
    if not probe.is_file() or probe.name.lower() != 'sjuni_body_probe.exe':
        raise ValueError('Supply the existing isolated sjuni_body_probe.exe')
    output = Path(output).resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if not output.is_relative_to(allowed):
        raise ValueError('Fuzz receipts must stay under ignored build-native-sjuni')
    output.mkdir(parents=True, exist_ok=True)
    baseline = ContinuationMachine(node_capacity=16, enter_mutation=None)
    hybrid = ContinuationMachine(node_capacity=16, enter_mutation=None)
    template = tuple((base, bytes(data)) for base, data in baseline.mem.regions)
    rng = random.Random(seed)
    count_keys = ('operations', 'take', 'put', 'unget', 'original_only_preenter',
                  'postenter_body_admissions', 'native_bodies', 'unsupported_native_fallbacks',
                  'callback_image_sequences_compared', 'native_error_paths_metadata_only',
                  'excluded_native_error_callbacks')
    totals = Counter({key: 0 for key in count_keys})
    traces = []
    mode_results = []
    visited = set()
    receipt = {'schema': 1, 'status': 'running', 'seed': seed,
        'operations_per_mode': operations_per_mode, 'modes': list(MODES), 'node_capacity': 16,
        'elf_sha256': baseline.elf.sha256, 'probe_sha256': sha(probe.read_bytes()),
        'driver_sha256': sha(Path(__file__).read_bytes()),
        'probe': str(probe), 'original_phase_intervals': [
            {'operation': op, 'start_pc': phase['entry'], 'end_pc_exclusive': phase['end'],
             'sha256': sha(baseline.elf.read(phase['entry'], phase['end'] - phase['entry']))}
            for op, phase in PHASES.items()],
        'limits': [
            'Original integer words over isolated synthetic memories; no game/runtime/IOP/DMA/scheduler execution.',
            'The C++ probe has no external hooks; original errors are traced synchronous no-mutation hooks.',
            'For native error paths metadata is compared; omitted error callback delivery/image order is explicitly excluded.',
            'Caller-saved register clobbers and unsaved stack scratch bytes are outside this comparison.',
            'One wide numeric region in the existing probe is not runtime payload ownership/registration proof.',
            'The deliberate INT32_MIN request witnesses unsupported signed-remainder arithmetic, not a valid payload-buffer admission claim.',
            'Seeded512-operation maximum is finite evidence, not complete-input coverage or performance/game parity.'],
        'counts': {}, 'mode_results': mode_results, 'operations': traces}
    current = None
    try:
        for mode in MODES:
            fresh_memory(baseline, template, mode)
            mode_counts = Counter({key: 0 for key in count_keys})
            for index in range(operations_per_mode):
                operation, queue, request, pointer, length, label = select_input(baseline, rng, index)
                if operation == 'take':
                    baseline.mem.store(OUTPUT, 4, 0xA1A2A3A4)
                    baseline.mem.store(OUTPUT + 4, 4, 0xB1B2B3B4)
                    args = [POOL, queue, request, OUTPUT]
                else:
                    baseline.mem.store(INPUT, 4, pointer)
                    baseline.mem.store(INPUT + 4, 4, length)
                    args = [POOL, queue, INPUT]
                baseline.begin(operation, args)
                before = baseline.checkpoint()
                phase = PHASES[operation]
                current = {'mode': mode, 'index': index, 'operation': operation, 'queue': queue,
                           'request_i32': request, 'input_pointer_u32': pointer & MASK32,
                           'input_length_i32': length, 'selection': label}
                mode_counts['operations'] += 1
                mode_counts[operation] += 1
                if baseline.advance([phase['post_enter']]) == 'returned':
                    mode_counts['original_only_preenter'] += 1
                    hybrid.restore(before)
                    hybrid.advance()
                    compare_state(baseline, hybrid, before, operation, True)
                    current['route'] = 'original_only_preenter'
                    current['callback_images_compared'] = True
                else:
                    mode_counts['postenter_body_admissions'] += 1
                    checkpoint = baseline.checkpoint()
                    assert baseline.enter_calls == 1 and baseline.leave_calls == 0
                    baseline.advance([LEAVE])
                    expected_body = baseline.snapshot()
                    expected_errors = sum(e['kind'] in ('registered_error', 'default_error_report')
                                          for e in baseline.events)
                    baseline.advance()
                    hybrid.restore_post_enter(checkpoint)
                    before_probe_memory = memory_identity(hybrid, True)
                    before_probe_regs = list(hybrid.regs)
                    used_native = native_body(hybrid, probe, output)
                    if used_native:
                        mode_counts['native_bodies'] += 1
                        hybrid.pc = phase['completed_body_resume']
                        current['route'] = 'native_body_original_completion'
                    else:
                        mode_counts['unsupported_native_fallbacks'] += 1
                        if memory_identity(hybrid, True) != before_probe_memory or hybrid.regs != before_probe_regs:
                            raise AssertionError('Unsupported native probe changed original checkpoint')
                        current['route'] = 'unchanged_original_postenter_fallback'
                    hybrid.advance([LEAVE])
                    if hybrid.snapshot() != expected_body:
                        raise AssertionError('Body metadata mismatch before original leave')
                    hybrid.advance()
                    compare_events = not (used_native and expected_errors)
                    compare_state(baseline, hybrid, checkpoint, operation, compare_events)
                    if not compare_events:
                        mode_counts['native_error_paths_metadata_only'] += 1
                        mode_counts['excluded_native_error_callbacks'] += expected_errors
                    else:
                        mode_counts['callback_image_sequences_compared'] += 1
                    current['callback_images_compared'] = compare_events
                    current['original_error_callbacks'] = expected_errors
                    assert hybrid.enter_calls == hybrid.leave_calls == 1
                visited.update(baseline.visited)
                current['final_nonstack_memory_sha256'] = sha(json.dumps(memory_identity(baseline)).encode())
                traces.append(current)
                if (index + 1) % 32 == 0:
                    print(f'mode{mode}: {index + 1}/{operations_per_mode} original/native continuations checked', flush=True)
            totals.update(mode_counts)
            mode_results.append({'mode': mode, 'stored_mode_byte': mode & 255, 'counts': dict(mode_counts)})
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = {'operation': current, 'exception': type(error).__name__, 'message': str(error),
                              'original_state': baseline.snapshot(), 'hybrid_state': hybrid.snapshot()}
        raise
    finally:
        receipt['counts'] = dict(totals)
        receipt['completed_comparisons'] = len(traces)
        receipt['visited_original_pcs'] = sorted(visited)
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    return receipt


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--seed', type=lambda x: int(x, 0), default=DEFAULT_SEED)
    parser.add_argument('--operations-per-mode', type=int, default=128)
    parser.add_argument('--output', type=Path, default=ROOT / 'build-native-sjuni/continuation-fuzz')
    args = parser.parse_args()
    result = compare(args.probe, args.output, args.seed, args.operations_per_mode)
    print(json.dumps({'status': result['status'], 'seed': result['seed'], **result['counts']}))


if __name__ == '__main__':
    main()
