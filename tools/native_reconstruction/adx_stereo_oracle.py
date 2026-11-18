#!/usr/bin/env python3
"""Bounded synthetic original-word keyed ADX stereo/downmix/selector oracle.

No native decoder is imported. The owned ELF supplies every executed instruction
and the nibble table; input media and all state are authored synthetic bytes.
The shared integer and EE MAC engines are used without modification.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from ee_mac_oracle import EeMacInstructions, implementation_identity
from sjuni_oracle import Elf, Memory, OracleError, UnknownInstruction, StepLimit, MASK32, sext32, signed

ROOT = Path(__file__).resolve().parents[2]
BODIES = {'normal': (0x127C80, 0x127FC8), 'downmix': (0x1278B8, 0x127C7C),
          'selector': (0x127FC8, 0x128038)}
TABLE, TABLE_BYTES, FLAG = 0x239BE8, 64, 0x20C7A8
INPUT, LEFT, RIGHT, HISTORY, KEY = 0x400000, 0x410008, 0x420008, 0x430000, 0x440000
STACK, STACK_BYTES, STACK_TOP, RETURN = 0x700000, 0x2000, 0x701000, 0xFFFFF0
MAX_BLOCKS = 16


class EeDivInstructions:
    """One new instruction, SPECIAL DIV, composed with the frozen engines.

    Sony EE instruction manual v6 p51 defines canonical signed-word inputs,
    signed quotient/remainder and signextended lower64 HI/LO; INT_MIN/-1 yields
    INT_MIN,0. Zero's arithmetic result is undefined, so reject before mutation
    even though the pinned local emitter chooses a specific zero result.
    """
    def instruction(self, pc, word):
        if word >> 26 == 0 and word & 63 == 0x1A:
            rs, rt = (word >> 21) & 31, (word >> 16) & 31
            if word & 0xFFC0:
                raise UnknownInstruction('Reserved DIV rd/shift encoding')
            if any(self.regs[n] != sext32(self.regs[n]) for n in (rs, rt)):
                raise OracleError('DIV operands must be canonical signextended words')
            dividend, divisor = signed(self.regs[rs], 32), signed(self.regs[rt], 32)
            if divisor == 0:
                raise OracleError('Undefined architectural DIV by zero not admitted')
            if dividend == -0x80000000 and divisor == -1:
                quotient, remainder = -0x80000000, 0
            else:
                magnitude = abs(dividend)//abs(divisor)
                quotient = -magnitude if (dividend < 0) != (divisor < 0) else magnitude
                remainder = dividend-quotient*divisor
            self.lo, self.hi = sext32(quotient), sext32(remainder)
            self.regs[0] = 0
            self.div_count = getattr(self, 'div_count', 0)+1
            return None
        return super().instruction(pc, word)


class ObservedMemory(Memory):
    """Only whole accesses within disjoint named admitted spans are allowed."""
    def __init__(self):
        super().__init__()
        self.active = False
        self.allowed = []
        self.reads, self.writes, self.pcm_stores = {}, {}, []

    def allow(self, name, base, length, writable=False):
        if length:
            if any(base < old + size and old < base + length for _, old, size, _ in self.allowed):
                raise OracleError('Overlapping admitted spans')
            self.allowed.append((name, base, length, writable))

    def observe(self, address, size, write):
        if not self.active:
            return None
        for name, base, length, writable in self.allowed:
            if base <= address and address + size <= base + length:
                if write and not writable:
                    raise OracleError('Write to read-only ' + name)
                counters = self.writes if write else self.reads
                row = counters.setdefault(name, dict(accesses=0, bytes=0,
                    first_offset=address-base, last_end=address+size-base))
                row['accesses'] += 1
                row['bytes'] += size
                row['first_offset'] = min(row['first_offset'], address-base)
                row['last_end'] = max(row['last_end'], address+size-base)
                return name
        raise OracleError(f'Access outside admitted stereo spans: {address:#x}+{size}')

    def load(self, address, size):
        self.observe(address, size, False)
        return super().load(address, size)

    def store(self, address, size, value):
        name = self.observe(address, size, True)
        if self.active and name in ('left_pcm', 'right_pcm'):
            base = LEFT if name == 'left_pcm' else RIGHT
            self.pcm_stores.append(dict(plane=name, offset=address-base, bytes=size,
                                       value=value & ((1 << (size*8))-1)))
        super().store(address, size, value)


class Machine(EeDivInstructions, EeMacInstructions):
    def __init__(self, encoded, requested, *, mode='normal', selector_flag=0,
                 history=(0, 0, 0, 0), coefficients=(0, 0), key=0,
                 multiplier=1, addend=0, output_samples=None,
                 elf_path=ROOT/'game_data/SLUS_207.65', mac_initial=(0, 0, 0, 0),
                 poison_halfword_arguments=False):
        if mode not in BODIES:
            raise OracleError('Unknown complete body entry')
        if not isinstance(encoded, bytes) or len(encoded) > MAX_BLOCKS*18:
            raise OracleError('Synthetic encoded span must be bounded bytes')
        if not isinstance(requested, int) or not -0x80000000 <= requested <= MAX_BLOCKS:
            raise OracleError('Requested count outside bounded signed32 domain')
        if len(history) != 4 or len(coefficients) != 2 or any(
                not isinstance(v, int) or not -32768 <= v <= 32767
                for v in (*history, *coefficients, multiplier, addend)):
            raise OracleError('History, coefficients and key steps must be signed16')
        if not isinstance(key, int) or not 0 <= key <= 65535:
            raise OracleError('Key must be uint16')
        if not isinstance(selector_flag, int) or not 0 <= selector_flag <= MASK32:
            raise OracleError('Selector flag must be raw uint32')
        if output_samples is None:
            output_samples = max(requested, 0)//2*32  # allocation geometry only
        if not isinstance(output_samples, int) or not 0 <= output_samples <= MAX_BLOCKS//2*32:
            raise OracleError('Output plane capacity outside finite domain')
        if len(mac_initial) != 4:
            raise OracleError('Explicit MAC bank initialization required')
        self.elf = Elf(elf_path)
        self.code = {}
        self.body_bytes = {}
        for name, (start, end) in BODIES.items():
            data = self.elf.read(start, end-start)
            if data is None:
                raise OracleError('Owned body unavailable')
            self.body_bytes[name] = data
            self.code.update((pc, struct.unpack_from('<I', data, pc-start)[0])
                             for pc in range(start, end, 4))
        self.table = self.elf.read(TABLE, TABLE_BYTES)
        if self.table is None:
            raise OracleError('Owned nibble table unavailable')
        self.initialize_mac(hi=mac_initial[0], lo=mac_initial[1],
                            hi1=mac_initial[2], lo1=mac_initial[3])
        self.mem = ObservedMemory()
        self.output_samples = output_samples
        if encoded:
            self.mem.map(INPUT, len(encoded))
            self.mem.store(INPUT, len(encoded), int.from_bytes(encoded, 'little'))
        for base in (LEFT, RIGHT):
            self.mem.map(base-8, output_samples*2+16, 0xA5)
        self.mem.map(HISTORY-8, 24, 0xB6)
        self.mem.map(KEY-8, 18, 0xC7)
        self.mem.map(TABLE, TABLE_BYTES)
        self.mem.map(FLAG, 4)
        self.mem.map(STACK, STACK_BYTES, 0xCC)
        for i, value in enumerate(history):
            self.mem.store(HISTORY+2*i, 2, value)
        self.mem.store(KEY, 2, key)
        self.mem.store(TABLE, TABLE_BYTES, int.from_bytes(self.table, 'little'))
        self.mem.store(FLAG, 4, selector_flag)
        self.mem.store(STACK_TOP, 4, KEY)
        poison = 0xA6B70000 if poison_halfword_arguments else 0
        self.mem.store(STACK_TOP+8, 4, poison | (multiplier & 65535))
        self.mem.store(STACK_TOP+16, 4, poison | (addend & 65535))
        for name, base, length, writable in (
                ('encoded', INPUT, len(encoded), False),
                ('left_pcm', LEFT, output_samples*2, True),
                ('right_pcm', RIGHT, output_samples*2, True),
                ('history', HISTORY, 8, True), ('key', KEY, 2, True),
                ('owned_nibble_table', TABLE, TABLE_BYTES, False),
                ('selector_flag', FLAG, 4, False), ('stack', STACK, STACK_BYTES, True)):
            self.mem.allow(name, base, length, writable)
        self.regs = [0]*32
        self.saved = {reg: 0x1234000000000000+reg for reg in (*range(16, 24), 30)}
        for reg, value in self.saved.items():
            self.regs[reg] = value
        args = [INPUT, requested, LEFT, HISTORY, RIGHT, HISTORY+4,
                poison | (coefficients[0] & 65535), poison | (coefficients[1] & 65535)]
        for i, arg in enumerate(args):
            self.regs[4+i] = sext32(arg)
        self.regs[29], self.regs[31] = STACK_TOP, RETURN
        self.pc = BODIES[mode][0]
        self.visited, self.instruction_counts = set(), {}
        self.case_input = dict(mode=mode, selector_flag_u32=selector_flag,
            encoded_hex=encoded.hex(), requested_i32=requested, history_i16=list(history),
            coefficients_i16=list(coefficients), key_u16=key, multiplier_i16=multiplier,
            addend_i16=addend, output_capacity_samples_per_plane=output_samples,
            mac_initial_u64=list(mac_initial), poison_halfword_arguments=poison_halfword_arguments)

    def raw(self, base, length):
        return bytes(self.mem.load(base+i, 1) for i in range(length))

    def snapshot(self):
        active, self.mem.active = self.mem.active, False
        try:
            result = {}
            for plane, base in (('left', LEFT), ('right', RIGHT)):
                pcm = self.raw(base, self.output_samples*2)
                result[plane+'_pcm_i16'] = list(struct.unpack('<'+'h'*self.output_samples, pcm))
                result[plane+'_pcm_sha256'] = hashlib.sha256(pcm).hexdigest()
                result[plane+'_guard_hex'] = (self.raw(base-8, 8)+self.raw(base+len(pcm), 8)).hex()
            result.update(history_i16=[signed(self.mem.load(HISTORY+2*i, 2), 16) for i in range(4)],
                key_u16=self.mem.load(KEY, 2), selector_flag_u32=self.mem.load(FLAG, 4),
                encoded_sha256=hashlib.sha256(self.raw(INPUT, len(bytes.fromhex(self.case_input['encoded_hex'])))).hexdigest(),
                nibble_table_sha256=hashlib.sha256(self.raw(TABLE, TABLE_BYTES)).hexdigest(),
                history_guard_hex=(self.raw(HISTORY-8, 8)+self.raw(HISTORY+8, 8)).hex(),
                key_guard_hex=(self.raw(KEY-8, 8)+self.raw(KEY+2, 8)).hex())
            return result
        finally:
            self.mem.active = active

    def run(self, step_cap=100000):
        if not isinstance(step_cap, int) or step_cap <= 0:
            raise OracleError('Invalid finite instruction cap')
        pending, steps = None, 0
        self.mem.active = True
        try:
            while self.pc != RETURN:
                if steps >= step_cap:
                    raise StepLimit('Owned stereo instruction cap')
                if self.pc not in self.code:
                    raise OracleError(f'Transfer outside complete owned bodies: {self.pc:#x}')
                steps += 1
                pc = self.pc
                self.visited.add(pc)
                self.instruction_counts[pc] = self.instruction_counts.get(pc, 0)+1
                branch = self.instruction(pc, self.code[pc])
                if pending is not None:
                    if branch is not None:
                        raise OracleError('Control transfer in delay slot')
                    self.pc, pending = pending, None
                elif branch is not None:
                    taken, target, likely = branch
                    if not taken and likely:
                        self.pc = pc+8
                    else:
                        pending, self.pc = target if taken else pc+8, pc+4
                else:
                    self.pc = pc+4
        finally:
            self.mem.active = False
        return dict(return_is_defined=True, return_i32=signed(self.regs[2], 32), steps=steps,
            state=self.snapshot(), reads=self.mem.reads, writes=self.mem.writes,
            pcm_store_count=len(self.mem.pcm_stores), pcm_stores=self.mem.pcm_stores,
            visited_pcs=sorted(self.visited), mac_instruction_counts=self.mac_counts,
            div_instruction_count=getattr(self, 'div_count', 0),
            abi=dict(stack_restored=self.regs[29] == STACK_TOP,
                return_address_restored=self.regs[31] == RETURN,
                saved_registers_restored=all(self.regs[r] == v for r, v in self.saved.items())),
            observations_not_abi=dict(mac_final_u64=self.mac_state()),
            instruction_counts={f'{pc:08X}': n for pc, n in sorted(self.instruction_counts.items())})


def block(header, payload):
    """Author one synthetic eighteen-byte input block, never an asset reader."""
    if not isinstance(header, int) or not 0 <= header <= 65535 or len(payload) != 16:
        raise ValueError('Synthetic block geometry')
    return header.to_bytes(2, 'big')+bytes(payload)


def generate(elf_path=ROOT/'game_data/SLUS_207.65', *, modes=('normal', 'downmix', 'selector')):
    cases = []
    def add(name, encoded, count, **kwargs):
        machine = Machine(encoded, count, elf_path=elf_path, **kwargs)
        cases.append(dict(name=name, input=machine.case_input, expected=machine.run()))
    for mode in modes:
        flags = (0, 1, 0x80000000, 0xFFFFFFFF) if mode == 'selector' else (0,)
        for flag in flags:
            prefix = f'{mode}_{flag:08X}'
            common = dict(mode=mode, selector_flag=flag)
            for name, left, right, header in (
                    ('clamp_positive', 0x77, 0x77, 0x1FFF),
                    ('clamp_negative', 0x88, 0x88, 0x1FFF),
                    ('individual_clamp_before_mix', 0x77, 0x88, 0x1FFF),
                    ('negative_fraction_truncates', 0xFF, 0xFF, 0)):
                add(f'{prefix}_{name}', block(header, bytes([left])*16)
                    +block(header, bytes([right])*16), 2, **common)
            add(f'{prefix}_unchanged_output_tail', block(0, bytes([0x78])*16)
                +block(0, bytes([0xF1])*16), 2, output_samples=64, **common)
            for nibble in range(16):
                add(f'{prefix}_nibble_{nibble:X}', block(0, bytes([nibble*17])*16)
                    +block(0, bytes([(15-nibble)*17])*16), 2, **common)
            for high in range(16):
                add(f'{prefix}_nibble_pairs_{high:X}',
                    block(0, bytes(high*16+low for low in range(16)))
                    +block(0, bytes(low*16+high for low in range(16))), 2, **common)
            for header in (0, 1, 0x1FFF, 0x2000, 0x7FFF):
                for key in (0, 0x1FFF, 0xFFFF):
                    add(f'{prefix}_scale_{header:04X}_key_{key:04X}',
                        block(header, bytes(range(0, 256, 16)))+block(header ^ 0x1FFF, bytes(range(15, 256, 16))),
                        2, key=key, multiplier=-32768, addend=32767, **common)
            for history in ((32767, 32767, -32768, -32768),
                            (-32768, 32767, 32767, -32768), (12345, -23456, -8765, 4321)):
                for coefficients in ((32767, 32767), (-32768, -32768), (7192, -3172), (4096, 0), (0, 4096)):
                    add(f'{prefix}_predictor_{history}_{coefficients}',
                        block(0x1FFF, bytes(range(16)))+block(0x7FFF, bytes(range(240, 256))),
                        2, history=history, coefficients=coefficients,
                        key=32767, multiplier=-1, addend=-32768, **common)
            for requested in (0, 1, -1, -2, -2147483648):
                add(f'{prefix}_no_pairs_{requested}', b'', requested,
                    history=(1234, -5678, -9012, 3456), key=65535, **common)
            for count in (2, 3, 4, 5, 8, 16):
                encoded = b''.join(block((i*127) & 0x7FFF,
                    bytes((j*37+i*19) & 255 for j in range(16))) for i in range(count//2*2))
                add(f'{prefix}_multiple_{count}', encoded, count,
                    history=(23456, -12345, -11111, 22222), coefficients=(7192, -3172),
                    key=32766, multiplier=-32767, addend=12345, **common)
            for completed in (0, 1, 2):
                prior = b''.join(block(i, bytes([0x7F, 0x80]*8)) for i in range(completed*2))
                for side in ('left', 'right'):
                    encoded = prior+(block(4, bytes([0x77]*16)) if side == 'right' else b'')+b'\x80\x00'
                    add(f'{prefix}_{side}_marker_after_{completed}', encoded, completed*2+2,
                        history=(1234, -5678, -9012, 3456), coefficients=(4096, 0),
                        key=23456, multiplier=7, addend=-9, **common)
            for poison in (False, True):
                add(f'{prefix}_halfword_packing_{poison}',
                    block(19, bytes(range(16)))+block(27, bytes(range(240, 256))), 2,
                    coefficients=(-32768, 32767), multiplier=-32767, addend=-12345,
                    history=(32767, -32768, -12345, 23456), poison_halfword_arguments=poison, **common)
            add(f'{prefix}_nonzero_mac', block(12, bytes(range(16)))+block(29, bytes(range(16))), 2,
                history=(32767, -32768, -32768, 32767), coefficients=(-32768, 32767),
                mac_initial=(0x123456789ABCDEF0, 0xFEDCBA9876543210,
                             0x9999999999999999, 0x7777777777777777), **common)
    ref = Machine(b'', 0, elf_path=elf_path)
    visited = set().union(*(set(case['expected']['visited_pcs']) for case in cases))
    return dict(schema=1, kind='owned-word keyed ADX stereo/downmix/selector fixtures',
        identity=dict(elf_sha256=ref.elf.sha256,
            bodies={name: dict(entry_pc=start, end_pc_exclusive=end, words=(end-start)//4,
                sha256=hashlib.sha256(ref.body_bytes[name]).hexdigest()) for name, (start, end) in BODIES.items()},
            nibble_table_address=TABLE, nibble_table_bytes=TABLE_BYTES,
            nibble_table_sha256=hashlib.sha256(ref.table).hexdigest(), selector_flag_address=FLAG,
            tool_sha256={name: hashlib.sha256(Path(__file__).with_name(name).read_bytes()).hexdigest()
                         for name in ('sjuni_oracle.py', 'ee_mac_oracle.py', 'adx_stereo_oracle.py')},
            local_isa_reference=implementation_identity()),
        limitations=['Synthetic disjoint aligned input, two PCM planes, four history halves, key, table, flag and stack only.',
            'Requested signed32 <=16, maximum eight complete pairs; finite corpus is not universal equivalence.',
            'All original body words fetched from pinned ELF; no native decoder or media assets imported.',
            'Local DIV-only composition rejects undefined zero divisor and noncanonical operands before mutation; shared engines unchanged.',
            'No scheduling, IOP, IO, device, packed upper lanes, architectural timing or game integration claim.',
            'Only defined signed32 return, memory effects and saved-register/stack/RA ABI are compared; other registers are observations.'],
        counts=dict(cases=len(cases), runner_steps=sum(c['expected']['steps'] for c in cases),
            pcm_halfword_stores=sum(c['expected']['pcm_store_count'] for c in cases),
            visited_pcs=len(visited), owned_body_words=len(ref.code)),
        coverage={name: dict(visited_words=sum(pc in visited for pc in range(start, end, 4)),
            unvisited_pcs=[pc for pc in range(start, end, 4) if pc not in visited])
                  for name, (start, end) in BODIES.items()}, cases=cases)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--elf', type=Path, default=ROOT/'game_data/SLUS_207.65')
    parser.add_argument('--output', type=Path, default=ROOT/'build-native-sjuni/adx-stereo-fixtures.json')
    args = parser.parse_args()
    result = generate(args.elf)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(counts=result['counts'], coverage=result['coverage'])))


if __name__ == '__main__':
    main()
