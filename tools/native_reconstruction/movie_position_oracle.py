#!/usr/bin/env python3
"""Bounded owned-word movie-position publisher; no native algorithm or game IO."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

from ee_mac_oracle import EeMacInstructions
from sjuni_oracle import Elf, Memory, OracleError, UnknownInstruction, StepLimit, MASK32, MASK64, sext32, signed

ROOT = Path(__file__).resolve().parents[2]
BODIES = {
    0x16F338: (0x16F434, 'a9da933b0444e36ca9216439b9987a8c43b35329f1a8018707f1760a43940747'),
    0x171530: (0x171540, 'fe86d348b236afbb16ed45b2d5206cf8b37db1ce50cd27246e3da791ec753591'),
    0x171E58: (0x171E64, '520d116b70df02845b4cf1f537ef3f05d6c8133d5189643ff392dfc7aae8dd0f'),
    0x15BA80: (0x15BAEC, '10fceefc065a3b476f69b6420d7135bb0882e6baf7e106ffe21d58398767edd5'),
    0x10FB18: (0x1101AC, 'b062fd51648ef4ea2270b845c3cd6b1760a55bfc7f1f3de9fe5e34c703fd0aae'),
}
RATE, RATE_BYTES = 0x240AF0, 36
NORM, NORM_BYTES = 0x2381A0, 256
MAIN, DESCRIPTOR, INNER = 0x400000, 0x500000, 0x600000
STACK, STACK_BYTES, STACK_TOP, RETURN = 0x700000, 0x2000, 0x701000, 0xFFFFF0
SOURCE_FIELDS = {'state': 0x48, 'header_numerator': 0xD74, 'header_scale': 0xD78,
                 'origin': 0xDC4, 'side_base': 0xDDC, 'bias': 0xDE0,
                 'latest_numerator': 0xF00, 'latest_scale': 0xF04, 'inner': 0x1B30}


class UndefinedInstruction(OracleError):
    """Architecturally undefined arithmetic is refused, never fabricated."""


class OriginalBreak(OracleError):
    def __init__(self, pc, code):
        self.pc, self.code = pc, code
        super().__init__(f'Original BREAK at {pc:#x} code={code}')


class ClockIntegerInstructions(EeMacInstructions):
    """Generic shifts and unsigned-word DIV, composed with unchanged EE engines.

    DIVU is one machine instruction, not a hook for the original division helper.
    All 421 words of that helper remain available to the ordinary branch runner.
    """
    def instruction(self, pc, word):
        rs, rt, rd, sa, fn = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31, word & 63
        if word >> 26 == 0 and fn in (4, 6, 0x3C, 0x3E, 0x3F, 0x1B):
            if fn in (4, 6):
                if sa:
                    raise UnknownInstruction('Reserved variable word-shift encoding')
                shift = self.regs[rs] & 31
                value = self.regs[rt] & MASK32
                self.regs[rd] = sext32(value << shift if fn == 4 else value >> shift)
            elif fn in (0x3C, 0x3E, 0x3F):
                if rs:
                    raise UnknownInstruction('Reserved immediate doubleword-shift encoding')
                value = self.regs[rt] & MASK64
                shift = sa + 32
                self.regs[rd] = ((value << shift) if fn == 0x3C else
                                 (value >> shift) if fn == 0x3E else
                                 (signed(value, 64) >> shift)) & MASK64
            else:
                if rd or sa:
                    raise UnknownInstruction('Reserved DIVU encoding')
                if any(self.regs[n] != sext32(self.regs[n]) for n in (rs, rt)):
                    raise OracleError('DIVU operands require canonical signextended words')
                dividend, divisor = self.regs[rs] & MASK32, self.regs[rt] & MASK32
                if divisor == 0:
                    raise UndefinedInstruction(f'DIVU by zero at {pc:#x}; no result admitted')
                self.lo, self.hi = sext32(dividend // divisor), sext32(dividend % divisor)
            self.regs[0] = 0
            self.extension_counts[fn] = self.extension_counts.get(fn, 0) + 1
            return None
        if word >> 26 == 0 and fn == 0xD:
            raise OriginalBreak(pc, (word >> 6) & 0xFFFFF)
        return super().instruction(pc, word)


class AccessMemory(Memory):
    def __init__(self):
        super().__init__()
        self.allowed, self.writes, self.reads = [], [], []
        self.active = False

    def span(self, name, base, size, writable=False, fill=0):
        self.map(base, size, fill)
        self.allowed.append((name, base, size, writable))

    def access(self, address, size, write, value=None):
        if not self.active:
            return
        for name, base, length, writable in self.allowed:
            if base <= address and address + size <= base + length:
                if write and not writable:
                    raise OracleError('Write to read-only original table')
                row = dict(span=name, offset=address - base, bytes=size)
                if write:
                    row['value_u64'] = value & ((1 << (size * 8)) - 1)
                    self.writes.append(row)
                else:
                    self.reads.append(row)
                return
        raise OracleError(f'Access outside synthetic spans: {address:#x}+{size}')

    def load(self, address, size):
        self.access(address, size, False)
        return super().load(address, size)

    def store(self, address, size, value):
        self.access(address, size, True, value)
        super().store(address, size, value)


class Machine(ClockIntegerInstructions):
    def __init__(self, inputs, elf_path=ROOT / 'game_data/SLUS_207.65'):
        self.elf = Elf(elf_path)
        self.code = {}
        for entry, (end, expected) in BODIES.items():
            data = self.elf.read(entry, end - entry)
            if data is None or hashlib.sha256(data).hexdigest() != expected:
                raise OracleError('Owned original function hash mismatch')
            self.code.update({entry + i: struct.unpack_from('<I', data, i)[0] for i in range(0, len(data), 4)})
        if inputs['rate_index'] not in range(9):
            raise OracleError('Only the owned nine-rate table is admitted')
        if any(not isinstance(value, int) or not -(1 << 31) <= value < (1 << 31)
               for key, value in inputs.items() if key != 'rate_index'):
            raise OracleError('Input fields must be signed32 raw words')
        self.inputs = inputs
        self.mem = AccessMemory()
        for name, base, size, fill in [('main', MAIN, 0x2C00, 0xA5),
            ('descriptor', DESCRIPTOR, 0x80, 0x5A), ('inner', INNER, 0xB00, 0xC3),
            ('stack', STACK, STACK_BYTES, 0xCC)]:
            self.mem.span(name, base, size, True, fill)
        for name, base, size in [('owned_rates', RATE, RATE_BYTES), ('owned_normalization', NORM, NORM_BYTES)]:
            self.mem.span(name, base, size)
            self.mem.store(base, size, int.from_bytes(self.elf.read(base, size), 'little'))
        self.mem.store(MAIN + 0x1B30, 4, INNER)
        for key in ('header_numerator', 'header_scale', 'origin', 'bias', 'side_base', 'latest_numerator', 'latest_scale'):
            self.mem.store(MAIN + SOURCE_FIELDS[key], 4, inputs[key])
        self.mem.store(INNER + 0x9D8, 4, inputs['clock_flag'])
        self.mem.store(INNER + 0xA08, 4, inputs['side_counter'])
        self.mem.store(DESCRIPTOR + 0x3C, 4, inputs['rate_index'])
        self.regs = [0] * 32
        for register in (*range(16, 24), 30):
            self.regs[register] = 0x1234567800000000 + register
        self.saved = {register: self.regs[register] for register in (*range(16, 24), 30)}
        self.initialize_mac(hi=0x11111111, lo=0x22222222, hi1=0x33333333, lo1=0x44444444)
        self.extension_counts, self.visited, self.steps, self.body_entries = {}, {}, 0, {}

    def snapshot(self):
        active, self.mem.active = self.mem.active, False
        result = dict(source_fields_u32={key: self.mem.load(MAIN + offset, 4) for key, offset in SOURCE_FIELDS.items()},
            cc0_words_u32=self.mem.words(MAIN + 0xCC0, 0x2A0 // 4),
            d54_words_u32=self.mem.words(MAIN + 0xD54, 10),
            inner_fields_u32={'clock_flag': self.mem.load(INNER + 0x9D8, 4), 'side_counter': self.mem.load(INNER + 0xA08, 4)},
            descriptor_words_u32=self.mem.words(DESCRIPTOR, 0x80 // 4),
            original_frame_guard_words_u32=self.mem.words(STACK_TOP - 0x80, 0x90 // 4),
            abi=dict(gpr_lower64=self.regs[:], mac_lower64=self.mac_state()))
        self.mem.active = active
        return result

    def run(self, entry=0x16F338, arguments=None, limit=10000):
        self.regs[2] = 0xBAD0BAD0
        self.regs[29], self.regs[31] = STACK_TOP, RETURN
        for index, value in enumerate(arguments if arguments is not None else [MAIN, DESCRIPTOR]):
            self.regs[4 + index] = value & MASK64
        self.before = self.snapshot()
        self.mem.active = True
        pc, pending = entry, None
        while pc != RETURN:
            if self.steps >= limit:
                raise StepLimit('Finite original movie-position execution exhausted')
            if pc not in self.code or pc % 4:
                raise OracleError(f'Unowned original control transfer {pc:#x}')
            self.steps += 1
            self.visited[pc] = self.visited.get(pc, 0) + 1
            if pc in BODIES:
                self.body_entries[pc] = self.body_entries.get(pc, 0) + 1
            branch = self.instruction(pc, self.code[pc])
            if pending is not None:
                if branch is not None:
                    raise OracleError('Control transfer in a delay slot is not admitted')
                pc, pending = pending, None
            elif branch is None:
                pc += 4
            else:
                taken, target, likely = branch
                if likely and not taken:
                    pc += 8
                else:
                    pending = target if taken else pc + 8
                    pc += 4
        self.mem.active = False
        if self.regs[29] != STACK_TOP or any(self.regs[r] != value for r, value in self.saved.items()):
            raise OracleError('Original call did not restore its actual lower64 ABI')
        return dict(before=self.before, after=self.snapshot(), original_instructions=self.steps,
                    body_entry_counts={f'{key:06X}': value for key, value in sorted(self.body_entries.items())},
                    instruction_visits={f'{key:06X}': value for key, value in sorted(self.visited.items())},
                    writes=self.mem.writes, reads=self.mem.reads,
                    defined_return=entry in (0x15BA80, 0x10FB18), raw_v0_lower64=self.regs[2])


def defaults(**changes):
    values = dict(clock_flag=0, rate_index=4, header_numerator=90000, header_scale=90000,
                  origin=1200, bias=300, side_base=0, side_counter=1000,
                  latest_numerator=-5, latest_scale=1)
    values.update(changes)
    return values


def corpus():
    cases = [('disabled-baseline', defaults())]
    for index in range(9):
        cases.append((f'side-rate-{index}', defaults(clock_flag=1, rate_index=index)))
    for name, changes in [
        ('equal-preserves-scale', dict(header_numerator=100, origin=0, bias=0, latest_numerator=100, latest_scale=7)),
        ('lower-preserves-latest', dict(header_numerator=-10, origin=0, bias=0, latest_numerator=2)),
        ('negative-increase', dict(header_numerator=-10, origin=0, bias=0, latest_numerator=-20)),
        ('header-origin-wrap', dict(header_numerator=2147483647, origin=-1, bias=0)),
        ('bias-wrap', dict(header_numerator=2147483647, origin=0, bias=1)),
        ('counter-zero', dict(clock_flag=1, side_counter=0)),
        ('counter-negative', dict(clock_flag=1, side_counter=-1)),
        ('counter-delta-wrap', dict(clock_flag=1, side_counter=2147483647, side_base=-1)),
        ('counter-times1000-wrap', dict(clock_flag=1, side_counter=2147484)),
        ('negative-scale', dict(clock_flag=1, header_scale=-90000)),
        ('minimum-scale', dict(clock_flag=1, header_scale=-2147483648, side_counter=-2147483648)),
        ('large-product-positive', dict(clock_flag=1, header_scale=2147483647, side_counter=2147483, rate_index=0)),
        ('large-product-negative', dict(clock_flag=1, header_scale=-2147483648, side_counter=2147483, rate_index=8)),
        ('raw-nonboolean-flag', dict(clock_flag=2, side_counter=-2000, side_base=1000)),
        ('negative-bias-after-side', dict(clock_flag=1, side_counter=2, bias=-2147483648)),
    ]:
        cases.append((name, defaults(**changes)))
    rows = []
    for name, values in cases:
        machine = Machine(values)
        rate = machine.mem.load(RATE + 4 * values['rate_index'], 4)
        rows.append(dict(name=name, inputs=values, source_table_word_u32=rate, expected=machine.run()))
    return rows


def helper_corpus():
    rows = []
    cases = [(f'quotient-{index}', 0x10FB18, [numerator, denominator]) for index, (numerator, denominator) in enumerate([
        (0, 1), (1, 2), (-10, 3), (10, -3), (-10, -3),
        (0x7FFFFFFFFFFFFFFF, 1), (-0x8000000000000000, -1),
        (-0x8000000000000000, 1), (0x7FFFFFFFFFFFFFFF, 65535),
        (0x7FFFFFFFFFFFFFFF, 65536), (0x7FFFFFFFFFFFFFFF, 0xFFFFFFFF),
        (0x7FFFFFFFFFFFFFFF, 0x100000001), (-0x8000000000000000, 1 << 40),
        (-0x8000000000000000, -0x8000000000000000),
        (0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF), (1, 0x7FFFFFFFFFFFFFFF),
        (0x123456789ABCDEF, 0x123456789), (-0x123456789ABCDEF, 0x123456789),
        (0, 0), (10, 0), (-0x8000000000000000, 0),
    ])]
    cases += [(f'product-ratio-{index}', 0x15BA80, list(arguments)) for index, arguments in enumerate([
        (0, 0, 0), (-1, 0, 0), (0, -1, 0), (-1, -1, 0),
        (-2147483648, 2147483647, 0), (2147483647, 2147483647, 1),
        (-2147483648, -2147483648, -1), (-7, 5, 3), (7, 5, -3),
    ])]
    for name, entry, arguments in cases:
        machine = Machine(defaults())
        try:
            expected = dict(status='returned', **machine.run(entry, arguments))
        except (OriginalBreak, UndefinedInstruction) as error:
            expected = dict(status='original_break' if isinstance(error, OriginalBreak) else 'undefined_instruction_refused',
                detail=str(error), original_instructions=machine.steps, defined_return=False,
                before=machine.before, partial_after=machine.snapshot(),
                instruction_visits={f'{key:06X}': value for key, value in sorted(machine.visited.items())},
                body_entry_counts={f'{key:06X}': value for key, value in sorted(machine.body_entries.items())},
                writes=machine.mem.writes, reads=machine.mem.reads)
            if isinstance(error, OriginalBreak):
                expected.update(break_pc=hex(error.pc), break_code=error.code)
        rows.append(dict(name=name, entry=hex(entry), arguments_lower64=[value & MASK64 for value in arguments], expected=expected))
    return rows


def source_audit(directory):
    result = []
    for entry, (end, _) in BODIES.items():
        path = next(directory.glob(f'sub_{entry:08X}_*.cpp'))
        comments = {int(pc, 16): int(word, 16) for pc, word in re.findall(
            r'// (0x[0-9a-f]+): (0x[0-9a-f]+)', path.read_text(), re.I)}
        elf = Elf(ROOT / 'game_data/SLUS_207.65')
        if any(elf.read(pc, 4) != word.to_bytes(4, 'little') for pc, word in comments.items() if entry <= pc < end):
            raise OracleError('Generated instruction comments differ from owned words')
        omitted = [pc for pc in range(entry, end, 4) if pc not in comments]
        if any(int.from_bytes(elf.read(pc, 4), 'little') for pc in omitted):
            raise OracleError('Generated source omitted a nonzero owned word')
        result.append(dict(entry=hex(entry), end_exclusive=hex(end), source_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),
                           comments=sum(entry <= pc < end for pc in comments), omitted_zero_words=len(omitted)))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--reference-source', type=Path,
                        default=ROOT / 'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
    args = parser.parse_args()
    rows, helpers = corpus(), helper_corpus()
    result = dict(schema=1, provenance='Independent original-word execution on bounded synthetic state; not a game/player test.',
        elf_sha256=Elf(ROOT / 'game_data/SLUS_207.65').sha256,
        body_sha256={hex(entry): value for entry, (_, value) in BODIES.items()},
        source_word_audit=source_audit(args.reference_source), cases=rows, helper_cases=helpers,
        engine_sha256={name: hashlib.sha256((Path(__file__).parent / name).read_bytes()).hexdigest() for name in
                       ('sjuni_oracle.py', 'ee_mac_oracle.py', 'movie_position_oracle.py')},
        table_sha256={hex(address): hashlib.sha256(Elf(ROOT / 'game_data/SLUS_207.65').read(address, length)).hexdigest()
                      for address, length in ((RATE, RATE_BYTES), (NORM, NORM_BYTES))},
        limitations=['Only lower64 GPR/MAC state; no FPU, scheduler, device, codec or actual movie timing.',
            'Synthetic source/context/descriptor/stack spans are disjoint; aliases and out-of-table indices are excluded.',
            'No whole-helper numerical hook or native implementation is imported.',
            'DIVU-zero is refused before result mutation; reached original BREAK terminates a helper case without inventing a return.',
            'Standalone ratio/division helper cases have a different input domain from the admitted nine-rate publisher.'])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    data = (json.dumps(result, sort_keys=True, indent=2) + '\n').encode()
    args.output.write_bytes(data)
    print(json.dumps(dict(cases=len(rows), helper_cases=len(helpers), original_instructions=sum(row['expected']['original_instructions'] for row in rows + helpers),
                          bytes=len(data), sha256=hashlib.sha256(data).hexdigest(), output=str(args.output)), indent=2))


if __name__ == '__main__':
    main()
