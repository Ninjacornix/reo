#!/usr/bin/env python3
"""Independent owned-word SJRB ring oracle; synthetic storage, no native core."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

from adx_stereo_oracle import EeDivInstructions
from ee_mac_oracle import EeMacInstructions, implementation_identity
from sjuni_oracle import Elf, Memory, OracleError, UnknownInstruction, StepLimit, MASK32, MASK64, sext32, signed

ROOT = Path(__file__).resolve().parents[2]
BODIES = {
    0x13F7D8: (0x140000, '43267f4a90d33777e2bc4f75c3d3867f04d6dc459704d0d9709162273c4bd596'),
    0x1407E0: (0x14083C, '7686ce72fb6cc995c05c8f4498a1e746cb308ff9a8ff2d5f99d322544cffe422'),
}
ENTRIES = {
    'default_error': (0x13F7D8, False), 'initialize': (0x13F7F8, False),
    'release': (0x13F858, False), 'create': (0x13F8A8, True),
    'destroy': (0x13F998, False), 'uuid': (0x13F9D8, True),
    'set_error': (0x13F9E0, False), 'reset': (0x13F9F0, False),
    'count': (0x13FA38, True), 'get': (0x13FA88, False),
    'put': (0x13FBF8, False), 'unget': (0x13FD58, False),
    'peek': (0x13FEF0, True), 'buffer': (0x13FFB8, True),
    'capacity': (0x13FFC0, True), 'extension': (0x13FFC8, True),
    'set_total': (0x13FFD0, False), 'total': (0x13FFE8, True),
    'split': (0x1407E0, False),
}
GLOBAL, POOL_REF, POOL, POOL_BYTES = 0x224C20, 0x224C58, 0x224C60, 0x4000
BUFFER, SLOTS, STACK, STACK_TOP, RETURN = 0x400010, 0x500004, 0x700000, 0x701000, 0xFFFFF0
ENTER, LEAVE, MEMSET, MEMCPY, REPORT, ERROR = 0x13F258, 0x13F270, 0x107C68, 0x107AB0, 0x13F288, 0xFFFF00
CONTEXT = 0x13572468
FIELDS = {'vtable': 0, 'active': 4, 'uuid': 8, 'data': 0xC, 'free': 0x10,
          'write': 0x14, 'read': 0x18, 'buffer': 0x1C, 'capacity': 0x20,
          'extension': 0x24, 'free_get': 0x28, 'free_put': 0x2C,
          'data_get': 0x30, 'data_put': 0x34, 'error': 0x38, 'context': 0x3C}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def canonical(value):
    return (json.dumps(value, sort_keys=True, indent=2) + '\n').encode()


class RingInstructions(EeDivInstructions, EeMacInstructions):
    """DIV1 is a single instruction, never a replacement for ring arithmetic.

    Signed32 division truncates towards zero, signextends both second-bank
    results, and leaves the first bank untouched. Zero is architecturally
    undefined and is refused before any bank mutation. BREAK is reported only
    if an actual original instruction reaches it.
    """
    def instruction(self, pc, word):
        if word >> 26 == 0x1C and word & 63 == 0x1A:
            if word & 0xFFC0:
                raise UnknownInstruction('Reserved DIV1 rd/shift encoding')
            rs, rt = (word >> 21) & 31, (word >> 16) & 31
            if any(self.regs[n] != sext32(self.regs[n]) for n in (rs, rt)):
                raise OracleError('DIV1 requires canonical signextended operands')
            lhs, rhs = signed(self.regs[rs], 32), signed(self.regs[rt], 32)
            if rhs == 0:
                raise OracleError(f'Undefined architectural DIV1 by zero at {pc:#x}')
            if lhs == -0x80000000 and rhs == -1:
                quotient, remainder = -0x80000000, 0
            else:
                quotient = abs(lhs) // abs(rhs)
                if (lhs < 0) != (rhs < 0):
                    quotient = -quotient
                remainder = lhs - quotient * rhs
            self.lo1, self.hi1 = sext32(quotient), sext32(remainder)
            self.regs[0] = 0
            self.div1_count = getattr(self, 'div1_count', 0) + 1
            return None
        if word >> 26 == 0 and word & 63 == 0xD:
            raise OracleError(f'Original BREAK at {pc:#x} code={(word >> 6) & 0xFFFFF}')
        return super().instruction(pc, word)


class RingMemory(Memory):
    def __init__(self):
        super().__init__()
        self.active, self.writes, self.reads = False, [], []

    def load(self, address, size):
        if self.active:
            self.reads.append([address, size])
        return super().load(address, size)

    def store(self, address, size, value):
        if self.active:
            self.writes.append([address, size, value & ((1 << (8 * size)) - 1)])
        return super().store(address, size, value)


class Machine(RingInstructions):
    def __init__(self, capacity=16, extension=4, elf_path=ROOT / 'game_data/SLUS_207.65'):
        if not 0 <= capacity <= 8192 or not 0 <= extension <= 192:
            raise OracleError('Finite synthetic backing domain exceeded')
        self.elf = Elf(elf_path)
        self.code = {}
        for start, (end, sha) in BODIES.items():
            data = self.elf.read(start, end - start)
            if data is None or digest(data) != sha:
                raise OracleError('Owned SJRB body identity mismatch')
            self.code.update({start + i: struct.unpack_from('<I', data, i)[0] for i in range(0, len(data), 4)})
        self.capacity, self.extension = capacity, extension
        self.mem = RingMemory()
        self.mem.map(GLOBAL, POOL + POOL_BYTES - GLOBAL)
        self.mem.map(0x23DA58, 16)
        for address, length, sha in [
            (0x224C28, 48, '13ab97d9e638744bb82fba08078b3f12f4f087862da10d15da1c9e13e868738d'),
            (0x23DA58, 16, 'a0dc963e91254115785fce386e05a752e21f3116e4c14fe318b4d5b84d23492f')]:
            data = self.elf.read(address, length)
            if data is None or digest(data) != sha:
                raise OracleError('Owned SJRB table identity mismatch')
            self.mem.store(address, length, int.from_bytes(data, 'little'))
        self.mem.map(BUFFER - 16, max(1, capacity + extension) + 32, 0xA5)
        self.mem.map(SLOTS - 4, 0x100, 0x5A)
        self.mem.map(STACK, 0x2000, 0xCC)
        self.regs = [0] * 32
        self.initialize_mac(hi=0x11111111, lo=0x22222222, hi1=0x33333333, lo1=0x44444444)
        self.guard_depth, self.all_visited = 0, set()
        self.callback_action = None

    def bytes(self, address, size):
        data, offset = self.mem.region(address, size)
        return bytes(data[offset:offset + size])

    def state(self):
        return dict(object_words_u32=self.mem.words(POOL, 16),
                    fields_u32={name: self.mem.load(POOL + offset, 4) for name, offset in FIELDS.items()},
                    pool_reference_u32=self.mem.load(POOL_REF, 4),
                    pool_sha256=digest(self.bytes(POOL, POOL_BYTES)),
                    active_objects=[i for i in range(256) if self.mem.load(POOL + 64*i + 4, 4)],
                    descriptors=[dict(address=SLOTS + 16*i, pointer_u32=self.mem.load(SLOTS + 16*i, 4),
                                      bytes_i32=signed(self.mem.load(SLOTS + 16*i + 4, 4), 32)) for i in range(8)],
                    descriptors_hex=self.bytes(SLOTS - 4, 0x100).hex(),
                    backing_with_guards_hex=self.bytes(BUFFER - 16, max(1, self.capacity + self.extension) + 32).hex(),
                    stack_hex=self.bytes(STACK_TOP - 0x100, 0x100).hex())

    def hook(self, pc):
        if pc not in (ENTER, LEAVE, MEMSET, MEMCPY, REPORT, ERROR):
            return False
        event = dict(pc=pc, from_pc=self.last_transfer, arguments_u64=list(self.regs[4:8]),
                     guard_depth_before=self.guard_depth)
        if pc == ENTER:
            event['kind'] = 'enter'
            self.guard_depth += 1
        elif pc == LEAVE:
            event['kind'] = 'leave'
            self.guard_depth -= 1
            if self.guard_depth < 0:
                raise OracleError('Unbalanced synthetic guard')
        elif pc == MEMSET:
            event['kind'] = 'memset'
            address, value, count = [x & MASK32 for x in self.regs[4:7]]
            if count > POOL_BYTES or not (POOL <= address and address + count <= POOL + POOL_BYTES):
                raise OracleError('Memset outside finite original pool')
            # Each generic byte write is retained; ring routines are never hooks.
            for i in range(count):
                self.mem.store(address + i, 1, value)
            self.regs[2] = self.regs[4]
        elif pc == MEMCPY:
            event['kind'] = 'memcpy'
            dest, source, count = [x & MASK32 for x in self.regs[4:7]]
            start, end = BUFFER, BUFFER + self.capacity + self.extension
            if count > 8192 or not (start <= dest <= dest + count <= end and start <= source <= source + count <= end):
                raise OracleError('Memcpy outside caller backing')
            if count and dest < source + count and source < dest + count:
                raise OracleError('Overlapping memcpy has no admitted byte-copy semantics')
            for i in range(count):
                self.mem.store(dest + i, 1, self.mem.load(source + i, 1))
            self.regs[2] = sext32(dest)
        else:
            event['kind'] = 'error_callback' if pc == ERROR else 'diagnostic'
            event['object_words_before'] = self.mem.words(POOL, 16)
            event['descriptors_before_hex'] = self.bytes(SLOTS - 4, 0x100).hex()
            if pc == ERROR:
                event['error_i32'] = signed(self.regs[5], 32)
                if self.callback_action:
                    # Explicit external callback, not ring implementation. Tests
                    # expose continuation reads; arbitrary ring reentry excluded.
                    address, values = self.callback_action
                    for i, value in enumerate(values):
                        self.mem.store(address + 4*i, 4, value)
                    event['callback_writes'] = [address, values]
        event['guard_depth_after'] = self.guard_depth
        self.events.append(event)
        self.pc = self.regs[31] & MASK32
        return True

    def run(self, operation, arguments, step_cap=10000):
        entry, defined = ENTRIES[operation]
        self.regs = [0] * 32
        for reg in (*range(16, 24), 30):
            self.regs[reg] = 0x1234567800000000 + reg
        saved = {reg: self.regs[reg] for reg in (*range(16, 24), 30)}
        self.regs[2], self.regs[29], self.regs[31] = 0xBAD0BAD0, STACK_TOP, RETURN
        for i, value in enumerate(arguments):
            self.regs[4 + i] = sext32(value)
        before = self.state()
        self.events, self.last_transfer, self.pc, pending = [], None, entry, None
        visited, steps, hooks = set(), 0, 0
        self.mem.reads, self.mem.writes, self.mem.active = [], [], True
        failure = None
        try:
            while self.pc != RETURN:
                if steps + hooks >= step_cap:
                    raise StepLimit('Finite SJRB instruction bound exhausted')
                if pending is None and self.hook(self.pc):
                    hooks += 1
                    continue
                pc = self.pc
                if pc not in self.code or pc % 4:
                    raise OracleError(f'Unowned original control transfer {pc:#x}')
                steps += 1
                visited.add(pc)
                branch = self.instruction(pc, self.code[pc])
                if pending is not None:
                    if branch is not None:
                        raise OracleError('Control transfer in delay slot refused')
                    self.pc, self.last_transfer = pending
                    pending = None
                elif branch is None:
                    self.pc += 4
                else:
                    taken, target, likely = branch
                    if likely and not taken:
                        self.pc += 8
                    else:
                        pending = (target if taken else pc + 8, pc)
                        self.pc += 4
        except OracleError as error:
            failure = dict(type=type(error).__name__, detail=str(error), pc=self.pc,
                           word_u32=self.code.get(self.pc))
        finally:
            self.mem.active = False
        self.all_visited.update(visited)
        if failure is None:
            if self.guard_depth or self.regs[29] != STACK_TOP or any(self.regs[n] != value for n, value in saved.items()):
                raise OracleError('Original operation did not restore ABI/guard balance')
        return dict(status='refused' if failure else 'returned', failure=failure,
                    entry_pc=entry, arguments_u32=[v & MASK32 for v in arguments],
                    return_is_defined=defined and not failure,
                    return_u32=self.regs[2] & MASK32 if defined and not failure else None,
                    raw_v0_lower64_observation_only=self.regs[2], original_instructions=steps,
                    hook_count=hooks, visited_pcs=sorted(visited), events=self.events,
                    before=before, after=self.state(), writes=self.mem.writes, reads=self.mem.reads,
                    mac_lower64=self.mac_state(), div1_count=getattr(self, 'div1_count', 0))


def call(name, *args):
    return dict(call=name, arguments=list(args))


def words(address, *values):
    return dict(words=address, values=list(values))


def data(address, count, seed=0x20):
    return dict(bytes=address, hex=bytes((seed + i) & 255 for i in range(count)).hex())


def corpus_inputs():
    """Authored operation transcripts, serialized before any expected execution."""
    s = lambda i: SLOTS + 16*i
    base = lambda: [call('initialize'), call('create', BUFFER, 16, 4), call('set_error', POOL, ERROR, CONTEXT)]
    cases = []
    def add(name, actions, capacity=16, extension=4, prefix=True):
        cases.append(dict(name=name, capacity=capacity, extension=extension,
                          actions=(base() if prefix else []) + actions))
    add('identity-reset-and-accessors', [call('uuid', POOL), call('buffer', POOL), call('capacity', POOL),
        call('extension', POOL), call('get', POOL, 0, 7, s(0)), call('reset', POOL),
        call('count', POOL, 0), call('count', POOL, 1)])
    add('empty-short-zero-peek', [call('get', POOL, 1, 20, s(0)), call('peek', POOL, 1, 1, s(1)),
        call('peek', POOL, 1, 0, s(1)), call('get', POOL, 0, 40, s(2)), call('peek', POOL, 0, 1, s(1))])
    add('split-publish-return-suffix', [call('get', POOL, 0, 8, s(0)), data(BUFFER, 8),
        call('split', s(0), 5, s(1), s(2)), call('put', POOL, 1, s(1)), call('unget', POOL, 0, s(2)),
        call('get', POOL, 1, 5, s(3)), call('split', s(3), 2, s(4), s(5)),
        call('put', POOL, 0, s(4)), call('unget', POOL, 1, s(5)),
        call('count', POOL, 0), call('count', POOL, 1)])
    add('exact-end-and-mirror', [call('get', POOL, 0, 16, s(0)), data(BUFFER, 16),
        call('put', POOL, 1, s(0)), call('get', POOL, 1, 16, s(1)), call('put', POOL, 0, s(1))])
    advance = [call('get', POOL, 0, 12, s(0)), data(BUFFER, 12), call('put', POOL, 1, s(0)),
        call('get', POOL, 1, 12, s(1)), call('put', POOL, 0, s(1))]
    add('input-output-extension-wrap', advance + [call('get', POOL, 0, 8, s(2)), data(BUFFER + 12, 8, 0x70),
        call('put', POOL, 1, s(2)), call('peek', POOL, 1, 8, s(3)),
        call('get', POOL, 1, 8, s(4)), call('put', POOL, 0, s(4))])
    add('extension-grant-clips-request', advance + [call('get', POOL, 0, 16, s(2)), call('unget', POOL, 0, s(2))])
    add('free-wrap-suffix-modulo-unget', advance + [call('get', POOL, 0, 8, s(2)), data(BUFFER + 12, 8, 0x70),
        call('split', s(2), 4, s(3), s(4)), call('put', POOL, 1, s(3)), call('unget', POOL, 0, s(4))])
    add('data-wrap-suffix-modulo-unget', advance + [call('get', POOL, 0, 8, s(2)), data(BUFFER + 12, 8, 0x70),
        call('put', POOL, 1, s(2)), call('get', POOL, 1, 8, s(3)), call('split', s(3), 4, s(4), s(5)),
        call('put', POOL, 0, s(4)), call('unget', POOL, 1, s(5)), call('get', POOL, 1, 4, s(6)), call('put', POOL, 0, s(6))])
    add('mirror-short-prefix', [call('get', POOL, 0, 3, s(0)), data(BUFFER, 3, 0x90), call('put', POOL, 1, s(0))])
    for selector in (0, 1):
        setup = [] if selector == 0 else [call('get', POOL, 0, 8, s(0)), data(BUFFER, 8), call('put', POOL, 1, s(0))]
        add(f'unget-match-pool{selector}', setup + [call('get', POOL, selector, 6, s(1)), call('unget', POOL, selector, s(1))])
        add(f'unget-mismatch-pool{selector}', setup + [call('get', POOL, selector, 6, s(1)),
            words(s(2), BUFFER + 1, 6), call('unget', POOL, selector, s(2))])
        add(f'unget-mismatch-null-callback-pool{selector}', setup + [call('set_error', POOL, 0, CONTEXT),
            call('get', POOL, selector, 6, s(1)), words(s(2), BUFFER + 1, 6), call('unget', POOL, selector, s(2))])
    for op in ('get', 'put', 'unget', 'count', 'peek'):
        actions = [words(s(0), BUFFER, 3)]
        args = [POOL, 7] + ([3, s(0)] if op in ('get', 'peek') else [s(0)] if op in ('put', 'unget') else [])
        add(f'invalid-selector-{op}', actions + [call(op, *args)])
    add('invalid-selector-zero-peek', [call('peek', POOL, 7, 0, s(0))])
    add('default-error-route', [call('set_error', POOL, 0x13F7D8, POOL), call('count', POOL, 7)])
    add('zero-null-negative-return-noop', [words(s(0), BUFFER, 0), call('put', POOL, 1, s(0)),
        call('unget', POOL, 0, s(0)), words(s(0), 0, 3), call('put', POOL, 1, s(0)),
        call('unget', POOL, 0, s(0)), words(s(0), BUFFER, -3), call('put', POOL, 1, s(0)), call('unget', POOL, 0, s(0))])
    add('negative-request-observation-outside-adxt', [call('get', POOL, 0, -2, s(0)), call('peek', POOL, 0, -3, s(1))])
    add('totals-word-wrap', [call('set_total', POOL, 0, 0, -2), call('get', POOL, 0, 4, s(0)),
        call('set_total', POOL, 1, 1, -2), data(BUFFER, 4), call('put', POOL, 1, s(0))] +
        [call('total', POOL, p, k) for p in (0, 1) for k in (0, 1)])
    add('split-exact-large-zero-unaligned', [words(s(0), BUFFER + 1, 8), call('split', s(0), 8, s(1), s(2)),
        call('split', s(0), 20, s(3), s(4)), call('split', s(0), 0, s(5), s(6))])
    add('callback-edits-returned-length-continuation', [call('get', POOL, 0, 6, s(0)), words(s(1), BUFFER + 1, 6),
        dict(callback_words=s(1) + 4, values=[2]), call('unget', POOL, 0, s(1))])
    add('second-object-and-destroy-reuse', [call('create', BUFFER, 16, 4), call('destroy', POOL),
        call('create', BUFFER, 16, 4), call('destroy', 0)])
    add('module-references-clear-not-backing', [call('initialize'), data(BUFFER, 4), call('release'), call('release')])
    add('pool-exhaustion', [dict(occupy_all=True), call('create', BUFFER, 16, 4)], prefix=False)
    add('zero-capacity-unget-original-break', [call('create', BUFFER, 0, 4), words(s(0), BUFFER, 1), call('unget', POOL, 1, s(0))], capacity=0, prefix=False)
    add('zero-capacity-get-undefined-div-refusal', [call('create', BUFFER, 0, 4), call('get', POOL, 0, 1, s(0))], capacity=0, prefix=False)
    for capacity, extension, label in [(16, 0, 'no-extension'), (8192, 192, 'adxt-pcm-geometry'), (2048, 36, 'encoded-sector-geometry')]:
        actions = [call('initialize'), call('create', BUFFER, capacity, extension), call('set_error', POOL, ERROR, CONTEXT),
            call('get', POOL, 0, capacity - 2, s(0)), data(BUFFER, capacity - 2), call('put', POOL, 1, s(0)),
            call('get', POOL, 1, capacity - 2, s(1)), call('put', POOL, 0, s(1)),
            call('get', POOL, 0, 8, s(2)), call('unget', POOL, 0, s(2))]
        add(label, actions, capacity, extension, prefix=False)
    return cases


def execute_case(inputs):
    machine = Machine(inputs['capacity'], inputs['extension'])
    results = []
    for action in inputs['actions']:
        if 'call' in action:
            result = machine.run(action['call'], action['arguments'])
            results.append(dict(action=action, expected=result))
            if result['status'] != 'returned':
                break  # no fabricated continuation after partial/trapped state
        elif 'words' in action:
            for i, value in enumerate(action['values']):
                machine.mem.store(action['words'] + 4*i, 4, value)
        elif 'bytes' in action:
            for i, value in enumerate(bytes.fromhex(action['hex'])):
                machine.mem.store(action['bytes'] + i, 1, value)
        elif 'callback_words' in action:
            machine.callback_action = (action['callback_words'], action['values'])
        elif action.get('occupy_all'):
            for i in range(256):
                machine.mem.store(POOL + 64*i + 4, 4, 1)
        else:
            raise OracleError('Unknown frozen transcript action')
    return dict(name=inputs['name'], operations=results, final=machine.state(),
                visited_pcs=sorted(machine.all_visited))


def source_audit(source):
    """Every commented word equals ELF; only omitted all-zero words permitted."""
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    comments = {}
    files = []
    for path in sorted(source.glob('*.cpp')):
        # Restrict files without reading thousands of unrelated generated bodies.
        match = re.match(r'sub_([0-9A-Fa-f]+)_', path.name)
        if not match or not any(start <= int(match[1], 16) < end for start, (end, _) in BODIES.items()):
            continue
        text = path.read_text(encoding='utf-8')
        files.append(dict(path=str(path.relative_to(ROOT)), sha256=digest(path.read_bytes())))
        for pc, word in re.findall(r'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)', text):
            pc, word = int(pc, 16), int(word, 16)
            if not any(start <= pc < end for start, (end, _) in BODIES.items()):
                continue
            if pc in comments and comments[pc] != word:
                raise OracleError('Conflicting generated instruction comments')
            comments[pc] = word
    omitted = []
    for start, (end, _) in BODIES.items():
        for pc in range(start, end, 4):
            word = int.from_bytes(elf.read(pc, 4), 'little')
            if pc in comments:
                if word != comments[pc]:
                    raise OracleError(f'Generated comment differs at {pc:#x}')
            elif word:
                raise OracleError(f'Missing nonzero generated word at {pc:#x}')
            else:
                omitted.append(pc)
    return dict(files=files, matched_comments=len(comments), omitted_zero_pcs=omitted)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--reference-source', type=Path, default=ROOT / 'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
    args = parser.parse_args()
    args.output = args.output.resolve()
    args.reference_source = args.reference_source.resolve()
    transcript = dict(schema=1, provenance='Authored bounded synthetic inputs; no captured gameplay or native implementation.', cases=corpus_inputs())
    frozen = args.output.with_name(args.output.stem + '-inputs.json')
    if frozen.exists() or args.output.exists():
        raise OracleError('Refusing to overwrite staged evidence; select a new output path')
    args.output.parent.mkdir(parents=True, exist_ok=True)
    frozen.write_bytes(canonical(transcript))  # MUST precede all expected execution.
    input_sha = digest(frozen.read_bytes())
    audit = source_audit(args.reference_source)
    reference = implementation_identity()
    rows = [execute_case(row) for row in json.loads(frozen.read_bytes())['cases']]
    operations = [op['expected'] for row in rows for op in row['operations']]
    result = dict(schema=1, provenance='Owned original words over frozen synthetic inputs, not a game or complete ADXT player.',
        elf_sha256=Elf(ROOT / 'game_data/SLUS_207.65').sha256,
        inputs_file=str(frozen.relative_to(ROOT)), inputs_sha256=input_sha,
        source_word_audit=audit, isa_reference=reference,
        body_sha256={hex(start): sha for start, (_, sha) in BODIES.items()},
        engine_sha256={name: digest((Path(__file__).parent / name).read_bytes()) for name in
            ('sjuni_oracle.py', 'ee_mac_oracle.py', 'adx_stereo_oracle.py', 'sjrb_oracle.py')},
        cases=rows, summary=dict(cases=len(rows), operations=len(operations),
            instructions=sum(op['original_instructions'] for op in operations),
            partial_refusals=sum(op['status'] != 'returned' for op in operations),
            unique_visited_words=len(set(pc for row in rows for pc in row['visited_pcs']))),
        limitations=['Lower64 integer/MAC only; serialized synthetic tag1 hooks are not concurrency or real CRI lock validation.',
            'No native queue algorithm imported. Generic memset/memcpy and declared synchronous diagnostic callbacks only.',
            'Nonoverlapping copies require complete guarded caller backing; aliases outside the explicit split domain are excluded.',
            'Zero division is architecturally undefined and refused before bank mutation; partial original effects remain recorded.',
            'Callback mutation case only edits returned length; arbitrary reentrant stop/destroy/reset and cross-thread cancellation remain unproved.',
            'Transfers reserve/publish bytes, not audio frames played; no ADX header/window/transport/loop/device proof.'])
    args.output.write_bytes(canonical(result))
    print(json.dumps(dict(**result['summary'], output=str(args.output), bytes=args.output.stat().st_size,
                          sha256=digest(args.output.read_bytes()), inputs_sha256=input_sha), indent=2))


if __name__ == '__main__':
    main()
