#!/usr/bin/env python3
"""Compare a real C++ native body between original-word prologue/epilogue phases.

Only isolated synthetic memories and the pinned owned original instructions are
used. No game/runtime executable, device, process attachment or live session.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess

from sjuni_continuation_contract import prepared, PHASES, CALLEE_GPRS
from sjuni_oracle import STACK_BASE, MASK32, ROOT


def words_to_bytes(words):
    return struct.pack('<' + 'I' * len(words), *(value & MASK32 for value in words))


def native_body(machine, executable, output):
    operation = machine.operation
    obj, queue, descriptor = machine.regs[16], machine.regs[18], machine.regs[17]
    request = machine.regs[19] if operation == 'take' else 0
    count = machine.node_capacity
    node_base = machine.mem.load(obj + 12, 4)
    words = [list(PHASES).index(operation), queue, request, obj, count, descriptor]
    words += machine.mem.words(obj, 12)
    words += machine.mem.words(node_base, count * 4)
    words += machine.mem.words(descriptor, 2)
    source, result = output / 'body-input.dat', output / 'body-output.dat'
    source.write_bytes(words_to_bytes(words))
    subprocess.run([str(executable), str(source), str(result)], check=True)
    raw = result.read_bytes()
    expected_size = (1 + 12 + count * 4 + 2) * 4
    if len(raw) != expected_size:
        raise ValueError('Bad native-body result size')
    values = list(struct.unpack('<' + 'I' * (len(raw) // 4), raw))
    disposition = values.pop(0)
    if disposition == 1:  # fallback_before_effects: probe already checked no writes.
        if values != words[6:]:
            raise AssertionError('Unsupported native body changed metadata')
        return False
    if disposition != 0:
        raise AssertionError('Unexpected native callback-contract violation')
    addresses = [obj + 4 * i for i in range(12)]
    addresses += [node_base + 4 * i for i in range(count * 4)]
    addresses += [descriptor + 4 * i for i in range(2)]
    for address, value in zip(addresses, values, strict=True):
        machine.mem.store(address, 4, value)
    return True


def compare(executable, output):
    output.mkdir(parents=True, exist_ok=True)
    cases = []
    for operation, phase in PHASES.items():
        baseline = prepared(operation)
        baseline.advance()
        hybrid = prepared(operation)
        assert hybrid.advance([phase['post_enter']]) == 'stopped'
        assert hybrid.enter_calls == 1 and hybrid.leave_calls == 0
        checkpoint = hybrid.checkpoint()
        used_native = native_body(hybrid, executable, output)
        assert used_native, operation
        # Preserve actual original frame/context. Only skip its queue-body words;
        # original leave and epilogue instructions still run from their real join.
        hybrid.pc = phase['completed_body_resume']
        assert hybrid.pending is None
        hybrid.advance()
        assert hybrid.snapshot() == baseline.snapshot(), operation
        for (a, first), (b, second) in zip(hybrid.mem.regions, baseline.mem.regions, strict=True):
            assert a == b
            if a != STACK_BASE:
                assert first == second, (operation, hex(a))
        # Unsaved scratch-frame bytes and caller-saved GPR clobbers are not the
        # guest ABI. Check every saved slot and restored callee register instead.
        for reg in CALLEE_GPRS:
            assert hybrid.regs[reg] == baseline.regs[reg] == hybrid.initial_gprs[reg]
        for reg, offset in phase['saved_gprs'].items():
            frame = hybrid.entry_sp - phase['frame_bytes']
            assert hybrid.mem.load(frame + offset, 8) == checkpoint.initial_gprs[reg]
        assert hybrid.regs[29] == baseline.regs[29] == hybrid.entry_sp
        assert hybrid.regs[31] == baseline.regs[31]
        assert hybrid.pc == baseline.pc
        assert hybrid.guard_depth == baseline.guard_depth == 0
        assert hybrid.enter_calls == hybrid.leave_calls == 1
        assert len(hybrid.events) == len(baseline.events)
        for actual, expected in zip(hybrid.events, baseline.events, strict=True):
            for key in ('kind', 'guard_depth_before', 'guard_depth_after', 'observed_before'):
                assert actual[key] == expected[key], (operation, key)
        cases.append({'operation': operation, 'post_enter_pc': phase['post_enter'],
                      'original_epilogue_join': phase['completed_body_resume'],
                      'native_body_executed': True, 'nested_original_guard_mutation': True,
                      'guest_state_and_callback_images_match': True,
                      'saved_frame_and_callee_registers_match': True,
                      'entered_once_left_once': True})
    return {'schema': 1, 'status': 'passed', 'cases': cases,
            'elf_sha256': baseline.elf.sha256,
            'native_probe_sha256': hashlib.sha256(executable.read_bytes()).hexdigest(),
            'limits': ['No actual runtime scheduler, IOP, DMA, media or game execution.',
                       'Three body-phase integration cases, not full input-domain coverage.',
                       'Undefined caller-saved clobbers and unsaved stack scratch are excluded.']}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe', type=Path, required=True)
    args = parser.parse_args()
    output = ROOT / 'build-native-sjuni/continuation-comparison'
    receipt = compare(args.probe.resolve(), output)
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Original enter + actual native body + original leave/epilogue: all three cases passed')


if __name__ == '__main__':
    main()
