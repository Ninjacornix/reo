#!/usr/bin/env python3
"""Bounded, original-word SJUNI fixture oracle over isolated synthetic memory.

This is a finite integer-instruction harness, not a game/runtime emulator. Queue
operations come exclusively from the owned ELF's instruction words. It imports
no native SJUNI algorithm and never attaches, launches, builds or reads a process.
Only generic memset and synchronous guard/error hooks are substituted. Output
contains synthetic state and original identity/PC hashes, never original code.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/function_index'))
from index import Elf, ELF_SHA  # noqa: E402

MASK32 = (1 << 32) - 1
MASK64 = (1 << 64) - 1
CODE_START, CODE_END = 0x140000, 0x140840
POOL_REF, POOL, POOL_BYTES = 0x228C90, 0x228C98, 64 * 48
NODES, INPUT, OUTPUT, REMAINDER = 0x400000, 0x500004, 0x500024, 0x500044
STACK_BASE, STACK_BYTES, STACK_TOP = 0x700000, 0x20000, 0x71F000
ERROR_HOOK, RETURN_SENTINEL = 0xFFFF00, 0xFFFFF0
ENTER, LEAVE, MEMSET, REPORT = 0x13F258, 0x13F270, 0x107C68, 0x13F288
CONTEXT = 0x13572468
STEP_CAP = 20000
ENTRIES = {
    'default_error': (0x140000, 0x14001C, False),
    'initialize_pool': (0x140020, 0x14006C, False),
    'release_pool': (0x140070, 0x1400BC, False),
    'create': (0x1400C0, 0x1401A4, True),
    'destroy': (0x1401A8, 0x1401DC, False),
    'uuid': (0x1401E0, 0x1401E8, True),
    'set_error': (0x1401E8, 0x1401F4, False),
    'reset': (0x1401F8, 0x140284, False),
    'sum_bytes': (0x140288, 0x1402FC, True),
    'take': (0x140300, 0x140434, False),
    'put': (0x140438, 0x14058C, False),
    'unget': (0x140590, 0x1406D4, False),
    'availability': (0x1406D8, 0x140764, True),
    'queue_node_count': (0x140768, 0x1407A4, True),
    'free_node_count': (0x1407A8, 0x1407DC, True),
    'split': (0x1407E0, 0x14083C, False),
}


class OracleError(RuntimeError):
    pass


class UnknownInstruction(OracleError):
    pass


class StepLimit(OracleError):
    pass


def signed(value, bits):
    value &= (1 << bits) - 1
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def sext32(value):
    return signed(value, 32) & MASK64


class Memory:
    """Explicit mapped regions: unmapped/straddling accesses always abort."""
    def __init__(self):
        self.regions = []

    def map(self, base, size, fill=0):
        if size <= 0 or base < 0 or base + size > 1 << 32:
            raise OracleError('Invalid synthetic memory region')
        if any(base < b + len(data) and b < base + size for b, data in self.regions):
            raise OracleError('Overlapping synthetic memory regions')
        self.regions.append((base, bytearray([fill]) * size))

    def region(self, addr, size):
        if addr < 0 or size < 0 or addr + size > 1 << 32:
            raise OracleError(f'Wrapped synthetic access {addr:#x}+{size}')
        for base, data in self.regions:
            if base <= addr and addr + size <= base + len(data):
                return data, addr - base
        raise OracleError(f'Unmapped synthetic access {addr:#x}+{size}')

    def load(self, addr, size):
        data, offset = self.region(addr, size)
        return int.from_bytes(data[offset:offset + size], 'little')

    def store(self, addr, size, value):
        data, offset = self.region(addr, size)
        data[offset:offset + size] = (value & ((1 << (size * 8)) - 1)).to_bytes(size, 'little')

    def fill(self, addr, size, value):
        data, offset = self.region(addr, size)
        data[offset:offset + size] = bytes([value & 255]) * size

    def words(self, addr, count):
        return [self.load(addr + 4 * i, 4) for i in range(count)]


class Machine:
    """Lower64 integer GPR subset actually reached by these original bodies.

    Word arithmetic/load results sign-extend as on the EE; DADDU/bitwise ops use
    lower64. There are no FPU/VU/MMI, exceptions, caches, scheduler or IOP devices.
    Branch-likely annuls its delay instruction when false. A control transfer in
    a delay slot is outside this harness and aborts rather than being guessed.
    """
    def __init__(self, elf_path=ROOT / 'game_data/SLUS_207.65', node_capacity=4):
        self.elf = Elf(elf_path)  # identity checked before interpreting any word
        self.code = self.elf.read(CODE_START, CODE_END - CODE_START)
        if self.code is None:
            raise OracleError('Original SJUNI text unavailable')
        if not 1 <= node_capacity <= 64:
            raise OracleError('Synthetic node allocation must be1..64')
        self.node_capacity = node_capacity
        self.mem = Memory()
        self.mem.map(POOL_REF, 8 + POOL_BYTES)
        self.mem.map(NODES, node_capacity * 16)
        self.mem.map(0x500000, 0x100, 0xA5)
        self.mem.map(STACK_BASE, STACK_BYTES, 0xCC)
        for i in range(node_capacity):
            self.mem.store(NODES + 16 * i + 4, 4, 0xC0DE0000 + i)
        self.regs = [0] * 32
        self.pc = 0
        self.events = []
        self.guard_depth = 0
        self.last_transfer_pc = None
        self.visited = set()
        self.object = POOL
        self.observe = {'input': (INPUT, 2), 'output': (OUTPUT, 2),
                        'remainder': (REMAINDER, 2)}

    def snapshot(self):
        return {
            'object_address': self.object,
            'object_words_u32': self.mem.words(self.object, 12),
            'nodes': [{'address': NODES + 16 * i,
                       'words_u32': self.mem.words(NODES + 16 * i, 4)}
                      for i in range(self.node_capacity)],
            'pool_reference_u32': self.mem.load(POOL_REF, 4),
            'pool_active_bytes': [self.mem.load(POOL + 48 * i + 4, 1) for i in range(64)],
            'nonzero_pool_objects': [{'address': POOL + 48 * i, 'words_u32': words}
                                     for i in range(64)
                                     if any(words := self.mem.words(POOL + 48 * i, 12))],
            'buffers': {name: {'address': addr, 'words_u32': self.mem.words(addr, count)}
                        for name, (addr, count) in self.observe.items()},
        }

    def hook(self, pc):
        if pc not in (ENTER, LEAVE, MEMSET, REPORT, ERROR_HOOK):
            return False
        event = {'target_pc': pc, 'from_pc': self.last_transfer_pc,
                 'arguments_u64': self.regs[4:8], 'guard_depth_before': self.guard_depth,
                 'observed_before': self.snapshot()}
        if pc == ENTER:
            event['kind'] = 'enter'
            self.guard_depth += 1
        elif pc == LEAVE:
            event['kind'] = 'leave'
            self.guard_depth -= 1
            if self.guard_depth < 0:
                raise OracleError('Unmatched guard leave in isolated operation')
        elif pc == MEMSET:
            event['kind'] = 'memset'
            count = self.regs[6] & MASK32
            if count > POOL_BYTES:
                raise OracleError('Memset exceeds finite harness limit')
            self.mem.fill(self.regs[4] & MASK32, count, self.regs[5])
            self.regs[2] = self.regs[4]
        elif pc == REPORT:
            event['kind'] = 'default_error_report'
            event['diagnostic_address'] = self.regs[4] & MASK32
        else:
            event['kind'] = 'registered_error'
            event['context_u32'] = self.regs[4] & MASK32
            event['error_i32'] = signed(self.regs[5], 32)
        event['guard_depth_after'] = self.guard_depth
        self.events.append(event)
        self.pc = self.regs[31] & MASK32
        return True

    def instruction(self, pc, word):
        """Execute one non-delay-aware instruction; return a branch descriptor.

        Branch return is (taken,target,likely); PC scheduling stays in run().
        Unknown encodings always fail closed, including known opcodes/unknown fn.
        """
        op = word >> 26
        rs, rt, rd, sa, fn = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31, word & 63
        imm = signed(word, 16)
        r = self.regs
        address = (r[rs] + imm) & MASK32
        branch = None
        if op == 0:
            if fn == 0: r[rd] = sext32((r[rt] & MASK32) << sa)
            elif fn == 2: r[rd] = sext32((r[rt] & MASK32) >> sa)
            elif fn == 3: r[rd] = sext32(signed(r[rt], 32) >> sa)
            elif fn == 8: branch = (True, r[rs] & MASK32, False)
            elif fn == 9:
                target = r[rs] & MASK32
                r[rd] = pc + 8
                branch = (True, target, False)
            elif fn == 10:
                if r[rt] == 0: r[rd] = r[rs]
            elif fn == 11:
                if r[rt] != 0: r[rd] = r[rs]
            elif fn == 33: r[rd] = sext32(r[rs] + r[rt])
            elif fn == 35: r[rd] = sext32(r[rs] - r[rt])
            elif fn == 36: r[rd] = r[rs] & r[rt]
            elif fn == 37: r[rd] = r[rs] | r[rt]
            elif fn == 38: r[rd] = r[rs] ^ r[rt]
            elif fn == 39: r[rd] = ~(r[rs] | r[rt]) & MASK64
            elif fn == 42: r[rd] = int(signed(r[rs], 64) < signed(r[rt], 64))
            elif fn == 43: r[rd] = int(r[rs] < r[rt])
            elif fn == 45: r[rd] = (r[rs] + r[rt]) & MASK64
            else: raise UnknownInstruction(f'Unsupported SPECIAL fn{fn:#x} at{pc:#x}')
        elif op in (2, 3):
            if op == 3: r[31] = pc + 8
            branch = (True, ((pc + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2), False)
        elif op == 1 and rt in (0, 1):
            test = signed(r[rs], 64) < 0 if rt == 0 else signed(r[rs], 64) >= 0
            branch = (test, (pc + 4 + imm * 4) & MASK32, False)
        elif op in (4, 5, 6, 7, 20, 21, 22, 23):
            kind = op & 15
            test = {4: lambda: r[rs] == r[rt], 5: lambda: r[rs] != r[rt],
                    6: lambda: signed(r[rs], 64) <= 0,
                    7: lambda: signed(r[rs], 64) > 0}[kind]()
            branch = (test, (pc + 4 + imm * 4) & MASK32, op >= 20)
        elif op == 9: r[rt] = sext32(r[rs] + imm)
        elif op == 10: r[rt] = int(signed(r[rs], 64) < imm)
        elif op == 11: r[rt] = int(r[rs] < (imm & MASK64))
        elif op == 12: r[rt] = r[rs] & (word & 65535)
        elif op == 13: r[rt] = r[rs] | (word & 65535)
        elif op == 14: r[rt] = r[rs] ^ (word & 65535)
        elif op == 15: r[rt] = sext32((word & 65535) << 16)
        elif op in (32, 33, 35, 36, 37, 39, 55):
            size = {32: 1, 33: 2, 35: 4, 36: 1, 37: 2, 39: 4, 55: 8}[op]
            if size > 1 and address % size:
                raise OracleError(f'Unaligned ordinary load at{pc:#x}')
            value = self.mem.load(address, size)
            r[rt] = (signed(value, size * 8) & MASK64) if op in (32, 33, 35) else value
        elif op in (40, 41, 43, 63):
            size = {40: 1, 41: 2, 43: 4, 63: 8}[op]
            if size > 1 and address % size:
                raise OracleError(f'Unaligned ordinary store at{pc:#x}')
            self.mem.store(address, size, r[rt])
        elif op in (26, 27):  # little-endian LDL/LDR merge into lower64
            base, offset = address & ~7, address & 7
            if op == 26:
                count, shift = offset + 1, (7 - offset) * 8
                bits = ((1 << (count * 8)) - 1) << shift
                r[rt] = (r[rt] & ~bits) | (self.mem.load(base, count) << shift)
            else:
                count = 8 - offset
                bits = (1 << (count * 8)) - 1
                r[rt] = (r[rt] & ~bits) | self.mem.load(address, count)
        elif op in (44, 45):  # little-endian SDL/SDR partial stores
            offset = address & 7
            if op == 44: self.mem.store(address & ~7, offset + 1, r[rt] >> ((7 - offset) * 8))
            else: self.mem.store(address, 8 - offset, r[rt])
        else:
            raise UnknownInstruction(f'Unsupported opcode{op:#x} at{pc:#x}')
        r[0] = 0
        return branch

    def run(self, operation, args, step_cap=STEP_CAP):
        if operation not in ENTRIES:
            raise OracleError(f'Unsupported entry {operation}')
        if len(args) > 4 or step_cap <= 0:
            raise OracleError('Invalid isolated call arguments/limit')
        entry, _, defined_return = ENTRIES[operation]
        self.regs = [0] * 32
        self.regs[2] = 0xBAD0BAD0  # raw void returns remain explicitly undefined
        self.regs[29] = STACK_TOP
        self.regs[31] = RETURN_SENTINEL
        for i, arg in enumerate(args): self.regs[4 + i] = sext32(arg)
        self.pc = entry
        self.events = []
        self.last_transfer_pc = None
        pending = None
        steps = 0
        call_pcs = set()
        while self.pc != RETURN_SENTINEL:
            if steps >= step_cap:
                raise StepLimit(f'Operation {operation} exceeded {step_cap} interpreted steps')
            steps += 1
            if pending is None and self.hook(self.pc):
                continue
            pc = self.pc
            if not CODE_START <= pc < CODE_END or pc % 4:
                raise OracleError(f'Instruction fetch outside isolated SJUNI text at{pc:#x}')
            word = struct.unpack_from('<I', self.code, pc - CODE_START)[0]
            call_pcs.add(pc)
            branch = self.instruction(pc, word)
            if pending is not None:
                if branch is not None:
                    raise OracleError(f'Control instruction in delay slot at{pc:#x}')
                self.pc, self.last_transfer_pc = pending
                pending = None
            elif branch is not None:
                taken, target, likely = branch
                if not taken and likely:
                    self.pc = pc + 8
                else:
                    pending = (target if taken else pc + 8, pc)
                    self.pc = pc + 4
            else:
                self.pc = pc + 4
        if self.guard_depth != 0:
            raise OracleError('Unbalanced substituted guard hooks')
        self.visited.update(call_pcs)
        return {'entry_pc': entry, 'arguments_i32': [signed(a, 32) for a in args],
                'steps': steps, 'visited_pcs': sorted(call_pcs),
                'return_is_defined': defined_return,
                'return_u32': self.regs[2] & MASK32 if defined_return else None,
                'return_raw_u64_observation_only': self.regs[2],
                'events': self.events, 'state': self.snapshot()}


class Scenario:
    def __init__(self, name, mode=1, nodes=4, elf_path=ROOT / 'game_data/SLUS_207.65'):
        self.name = name
        self.machine = Machine(elf_path, nodes)
        self.operations = []
        self.call('create', [mode, NODES, nodes * 16])
        self.machine.object = self.operations[-1]['expected']['return_u32']
        self.call('set_error', [self.machine.object, ERROR_HOOK, CONTEXT])

    def call(self, name, args, writes=()):
        for addr, values in writes:
            for i, value in enumerate(values): self.machine.mem.store(addr + 4 * i, 4, value)
        result = self.machine.run(name, args)
        self.operations.append({'operation': name, 'pre_writes': [
            {'address': addr, 'words_u32': [v & MASK32 for v in values]} for addr, values in writes],
            'expected': result})
        return result

    @property
    def obj(self): return self.machine.object

    def put(self, pool, pointer, length, unget=False):
        return self.call('unget' if unget else 'put', [self.obj, pool, INPUT], [(INPUT, [pointer, length])])

    def take(self, pool, length):
        return self.call('take', [self.obj, pool, length, OUTPUT], [(OUTPUT, [0xA1A2A3A4, 0xB1B2B3B4])])

    def available(self, pool, length):
        return self.call('availability', [self.obj, pool, length, OUTPUT], [(OUTPUT, [0xA1A2A3A4])])

    def fixture(self):
        return {'name': self.name, 'node_capacity': self.machine.node_capacity,
                'synthetic_initialization': {'pool_and_reference': 'zero',
                    'node_word4': '0xC0DE0000+index', 'other_node_words': 'zero',
                    'scratch_fill_byte': 0xA5, 'stack_fill_byte': 0xCC},
                'operations': self.operations}


def generate(elf_path=ROOT / 'game_data/SLUS_207.65'):
    scenarios = []
    def case(*args, **kwargs):
        s = Scenario(*args, elf_path=elf_path, **kwargs)
        scenarios.append(s)
        return s

    for mode in (0, 1, 2, 257):
        for pool in range(4):
            s = case(f'mode_{mode}_pool_{pool}_fifo_split_and_availability', mode=mode, nodes=4)
            s.call('uuid', [s.obj])
            s.available(pool, 1)
            s.put(pool, 0x600100, 16)
            s.put(pool, 0x600200, 24)
            s.put(pool, 0x600080, 8, unget=True)
            s.call('sum_bytes', [s.obj, pool])
            s.call('queue_node_count', [s.obj, pool])
            s.call('free_node_count', [s.obj])
            s.available(pool, 9)  # mode0 refuses; take with larger request succeeds
            s.take(pool, 9)
            s.available(pool, 8)
            s.take(pool, 8)       # mode1 splits the16-byte next head
            s.call('reset', [s.obj])
            s.call('free_node_count', [s.obj])

    for request in (0, -1, -16, 0x7FFFFFFF):
        s = case(f'signed_request_{request}', nodes=2)
        s.put(0, 0x600100, 16)
        s.available(0, request)
        s.take(0, request)
        s.call('sum_bytes', [s.obj, 0])
        s.call('queue_node_count', [s.obj, 0])

    for mode in (0, 1):
        s = case(f'exhaustion_and_adjacency_mode_{mode}', mode=mode, nodes=2)
        s.put(0, 0x600100, 16)
        s.put(0, 0x600200, 16)
        s.put(0, 0x600300, 16)  # callback while inside guard
        s.put(0, 0x600210, 16)  # mode1 tail merge even with no free nodes
        s.put(0, 0x6000F0, 16, unget=True)  # mode1 head merge, no node needed
        s.call('sum_bytes', [s.obj, 0])
        s.take(0, 0x7FFFFFFF)
        s.call('free_node_count', [s.obj])

    s = case('invalid_selectors_callback_output_order', nodes=2)
    for pool in (4, -1):
        s.call('sum_bytes', [s.obj, pool])
        s.take(pool, 16)       # callback observes old output before clearing
        s.available(pool, 16)  # callback observes already-zero length output
        s.put(pool, 0, -1)     # invalid selector reported before span admission
        s.put(pool, 0, -1, unget=True)
    s.call('set_error', [s.obj, 0, CONTEXT])
    s.take(4, 16)
    s.available(4, 16)
    s.call('set_error', [s.obj, 0x140000, s.obj])
    s.take(4, 16)             # original default-error wrapper to reporting hook

    s = case('span_admission_reset_and_destroy', nodes=3)
    for ptr, length in ((0, 16), (0x600100, 0), (0x600100, -1)):
        s.put(0, ptr, length)
        s.put(0, ptr, length, unget=True)
    s.put(3, 0x600100, 16)
    s.call('reset', [s.obj])
    s.call('destroy', [s.obj])
    s.call('destroy', [0])
    s.call('create', [1, NODES, 48])

    s = case('signed_sum_wrap_and_pointer_adjacency_wrap', nodes=4)
    s.put(0, 0x80000000, 0x7FFFFFFF)
    s.put(0, 0x100, 5)
    s.call('sum_bytes', [s.obj, 0])
    s.call('reset', [s.obj])
    s.put(0, 0xFFFFFFF0, 16)
    s.put(0, 0x100, 16)
    s.put(0, 0x110, 0x7FFFFFF0)
    s.call('sum_bytes', [s.obj, 0])
    s.available(0, -1)

    s = case('standalone_split_alias_and_unaligned_descriptors', nodes=2)
    for request in (0, -1, 8, 16, 32):
        s.call('split', [INPUT, request, OUTPUT, REMAINDER], [(INPUT, [0x600100, 16])])
        s.call('split', [INPUT, request, INPUT, REMAINDER], [(INPUT, [0x600100, 16])])

    s = case('pool_first_last_reference_and_slot_scan', nodes=2)
    s.call('create', [2, NODES, 32])  # second slot; first object remains visible
    s.call('initialize_pool', [])    # count0 clears the whole object pool
    s.call('initialize_pool', [])    # count1 only increments
    s.call('create', [1, NODES, 32])
    s.call('release_pool', [])       # nonlast does not clear
    s.call('release_pool', [])       # last clears

    m = scenarios[0].machine
    intervals = [{'operation': name, 'start_pc': start, 'end_pc_exclusive': end,
                  'sha256': hashlib.sha256(m.elf.read(start, end - start)).hexdigest()}
                 for name, (start, end, _) in ENTRIES.items()]
    fixtures = [s.fixture() for s in scenarios]
    return {'schema': 1, 'kind': 'owned_original_word_sjuni_oracle',
            'identity': {'elf_sha256': m.elf.sha256, 'required_elf_sha256': ELF_SHA,
                         'text_start_pc': CODE_START, 'text_end_pc_exclusive': CODE_END,
                         'text_sha256': hashlib.sha256(m.code).hexdigest(), 'intervals': intervals},
            'execution': {'step_cap_per_call': STEP_CAP, 'unknown_instruction': 'abort',
                'memory': 'isolated explicit synthetic mappings; unmapped accesses abort',
                'gpr_model': 'lower64; word arithmetic/loads sign-extend32; no128-bit/FPU/VU/MMI',
                'substituted_hooks': {'enter': ENTER, 'leave': LEAVE, 'memset': MEMSET,
                                     'error': ERROR_HOOK, 'default_report': REPORT},
                'hook_scope': 'synchronous observation only; guard depth is harness-local, not a full CRI scheduler model',
                'void_return': 'raw register observational only; return_u32=null and not a contract',
                'payload': 'pointer metadata only; no payload bytes allocated/read/copied',
                'fixture_memory_addresses': {'pool': POOL, 'nodes': NODES, 'input': INPUT,
                    'output': OUTPUT, 'remainder': REMAINDER, 'stack_top': STACK_TOP}},
            'counts': {'cases': len(fixtures), 'operations': sum(len(s['operations']) for s in fixtures),
                       'unique_original_pcs': len(set().union(*(s.machine.visited for s in scenarios)))},
            'cases': fixtures}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--elf', type=Path, default=ROOT / 'game_data/SLUS_207.65')
    p.add_argument('--output', type=Path, default=Path(__file__).with_name('sjuni_oracle_fixtures.json'))
    args = p.parse_args()
    result = generate(args.elf)
    output = args.output.resolve()
    allowed = (ROOT / 'tools/native_reconstruction').resolve()
    if output.parent != allowed:
        raise OracleError('Fixture output must stay in tools/native_reconstruction')
    output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'output': str(output), **result['counts']}))


if __name__ == '__main__':
    main()
