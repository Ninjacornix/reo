#!/usr/bin/env python3
"""Owned-word tag0 outer ADXB transaction, real SJRB and actual ADX kernels."""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

from sjrb_oracle import RingInstructions, BODIES as RING_BODIES
from sjuni_oracle import Elf, Memory, OracleError, StepLimit, MASK32, sext32, signed
from ee_mac_oracle import implementation_identity

ROOT = Path(__file__).resolve().parents[2]
BODIES = {
    **RING_BODIES,
    0x124810: (0x124860, '318e91cf582de1ee96b4a495c071466a9f1a41ad333f96e2953a16d0e46fb61a'),
    0x124E60: (0x124E88, '3278c8ea382d7b135e9bde5fde570d885d1fa684394da1058c8a42b0c5f6c8df'),
    0x124EE8: (0x124F00, '7ae2e7eef6a834bb2e4e6198f0bde90af2d8beafca6ffa72b99b1f7e030458f0'),
    0x1251A0: (0x12522C, '87b0807acebec110314e514933075909a5ec9dcda13ef395eeff733daaac314a'),
    0x125230: (0x125248, '1be23ed80c065aa139dee8598a227eb9d11cf0185528a3e859535c498564f442'),
    0x125278: (0x1252C8, 'acd905f6f4c5ad888201dce0cb4cfd61fb933c13132e81e1b276e8f4a8487940'),
    0x1252D0: (0x125458, '1662a4ee296827b04b1c9b4b18fa3649d7e79b7ef7b0a314f6af509dba0c4de3'),
    0x125458: (0x1254F4, '20d52e250eb9bd8deefa15d697a4b9aaccaae8d715d15803dd736a09153d70ee'),
    0x1254F8: (0x125764, 'dec2a85829ac4aca052d388a647a0d8c7849a595b421bdfe1d6a0123e4f76192'),
    0x125768: (0x125818, 'c88cc3461060b80d2b2ea22000282948f57112dc4e6bf5b11222e7adbebb3e22'),
    0x126F20: (0x126F7C, '10e91f575a9021b7b7ae2107a341d34b8c3570f48708a9b7c9372ec7d3f235f2'),
    0x1276D8: (0x1278B4, 'f68258d902ba372da0e477288c3a3b98a396a07b3c43bb28e55fb5805348b115'),
    0x1278B8: (0x127C7C, 'fece7d5c5d7dc0148717351d200c67d845e0242f5e7b93c01cfc19db7c2687ab'),
    0x127C80: (0x128038, '58d41606e993b12a22376a745eb9da45eaad3835718cbd12214300cd9947cf69'),
    0x12CEB8: (0x12D334, '7f0c781a139520332f00fc528928fbd277702219d132b1057b71b738a67e14a9'),
    0x12D338: (0x12D4FC, '003927f1732877ad02c642fb4ee8668112a3650d4f83e92b3d898e732c3e5645'),
    0x12D590: (0x12D638, 'ea9d31163ce39ecb857b2eb99b5ee6d5759083ece71649176eedbb456402104e'),
    0x12D638: (0x12D678, '166986473a6bc25e0204900fe64bdc7e99ef36eb86ad9c4e4c570bc2cc49aaa0'),
    0x12D7D8: (0x12D7F0, '1b7f24684d042b8914d9106411e2a27af4e769887a653b45d94841f5f981cbe0'),
    0x12D808: (0x12D820, '77d4de26aacb07b8ff20bc1fd1d0e625f4ea0037ac9a443e84fc2376cd98f213'),
    0x134F98: (0x13501C, '03464cd72a33f260db18224268a4194ddf810478ed6d401db41b7d01eec21e52'),
    0x135048: (0x135170, '3d4a4b4f0dc7c90b713e339308a021ceaaf0b04df1a004800cf5304cd75a528d'),
}
GLOBAL, POOL, INPUT, PCM = 0x224C20, 0x224C60, 0x400010, 0x410010
OUTER, INNER, PRED, SCRATCH = 0x600000, 0x610000, 0x620000, 0x630004
STACK, SP, RETURN = 0x700000, 0x701000, 0xFFFFF0
TABLE, MODE, ODD = 0x239BE8, 0x20C7A8, 0x21B7B0
ENTER, LEAVE, MEMSET, MEMCPY, REPORT, ERROR, PCM_CALLBACK = 0x13F258, 0x13F270, 0x107C68, 0x107AB0, 0x13F288, 0xFFFF00, 0xFFFF10
INPUT_CAP, INPUT_EXT, PCM_CAP, PCM_EXT = 2048, 36, 16384, 192
PCM_PHYSICAL = PCM_CAP + PCM_EXT
PROFILE = dict(input_capacity_bytes=2048, input_extension_bytes=36,
    pcm_capacity_bytes=16384, pcm_extension_bytes=192,
    encoding=3, bits_per_sample=4, block_bytes=18, samples_per_block=32, frequency=44100,
    history_i16=[1234,-5678,-9012,3456], coefficients_i16=[7192,-3172],
    key_u16=23456, multiplier_i16=7, addend_i16=-9,
    outer_reservation_callback=0x12CEB8, default_completion_callback=0x124840,
    constructor_default_reservation_callback=0x124810)
TRACE = {0x12CFD8:'input_service', 0x12CEB8:'reserve_output', 0x124810:'constructor_default_reserve',
    0x124840:'default_complete', 0x125370:'budget', 0x125518:'result_wrap',
    0x135078:'predictor_service', 0x1276D8:'mono', 0x127FC8:'stereo_select',
    0x127C80:'normal_stereo', 0x1278B8:'downmix', 0x135068:'odd_result',
    0x12D338:'publication', 0x125278:'outer_ack', 0x135048:'predictor_ack',
    0x13FA88:'ring_get', 0x13FBF8:'ring_put', 0x13FD58:'ring_unget',
    0x125458:'halfword_copy', 0x1407E0:'split', 0x126F20:'end_marker'}


def sha(data): return hashlib.sha256(data).hexdigest()
def serialized(value): return (json.dumps(value, sort_keys=True, indent=2) + '\n').encode()


class ObservedMemory(Memory):
    def __init__(self):
        super().__init__(); self.active = False; self.writes = []; self.reads = {}; self.pc = 0

    def load(self, address, size):
        if self.active:
            self.reads[self.pc] = self.reads.get(self.pc, 0) + 1
        return super().load(address, size)

    def store(self, address, size, value):
        if self.active:
            if any(address < base+length and base < address+size for base,length in
                   [(0x224C28,48), (0x23DA58,16), (TABLE,64)]):
                raise OracleError('Write into read-only owned table')
            self.writes.append(dict(pc=self.pc, address=address, bytes=size, value_hex=(value & ((1 << (8*size))-1)).to_bytes(size, 'little').hex()))
        return super().store(address, size, value)


class WindowInstructions(RingInstructions):
    """Only new ISA: REGIMM BLTZL/BGEZL, with an annulled false delay slot.

    This is a single instruction extension. It does not emulate a window or
    replace any call; the ordinary bounded runner executes its actual delay.
    """
    def instruction(self, pc, word):
        rt, rs = (word >> 16) & 31, (word >> 21) & 31
        if word >> 26 == 1 and rt in (2, 3):
            negative = signed(self.regs[rs], 64) < 0
            self.regs[0] = 0
            return (negative if rt == 2 else not negative,
                    (pc + 4 + signed(word, 16)*4) & MASK32, True)
        return super().instruction(pc, word)


class Machine(WindowInstructions):
    def __init__(self, inputs, profile=None):
        self.inputs = inputs
        self.profile = PROFILE if profile is None else profile
        if self.profile != PROFILE:
            raise OracleError('Only the declared header-admitted profile is qualified')
        if inputs['channels'] not in (1, 2) or inputs['downmix'] not in (0, 1):
            raise OracleError('Only admitted mono/stereo tag0 geometry')
        if len(bytes.fromhex(inputs['encoded_hex'])) > 512:
            raise OracleError('Finite synthetic input bound')
        if not 0 <= inputs['input_position'] < INPUT_CAP:
            raise OracleError('Input ring start outside geometry')
        if len(inputs['pcm_positions']) != inputs['channels'] or len(inputs['occupied_pcm_bytes']) != inputs['channels']:
            raise OracleError('Missing channel geometry')
        if len(set(inputs['pcm_positions'])) != 1 or len(set(inputs['occupied_pcm_bytes'])) != 1:
            raise OracleError('Asymmetric output grants excluded from admitted pilot')
        if any(not 0 <= v < PCM_CAP or v % 2 for v in inputs['pcm_positions']):
            raise OracleError('PCM offsets must be bounded halfwords')
        if any(not 0 <= v <= PCM_CAP or v % 2 for v in inputs['occupied_pcm_bytes']):
            raise OracleError('PCM occupancy must be bounded halfwords')
        if inputs['max_request_samples'] not in range(257) or inputs['total_samples'] not in range(1, 4097) or not -1 <= inputs['sample_limit'] <= 4096:
            raise OracleError('Finite accounting domain')
        self.elf = Elf(ROOT / 'game_data/SLUS_207.65'); self.code = {}
        for start, (end, expected) in BODIES.items():
            data = self.elf.read(start, end-start)
            if data is None or sha(data) != expected: raise OracleError('Original body identity mismatch')
            self.code.update({start+i: struct.unpack_from('<I', data, i)[0] for i in range(0, len(data), 4)})
        self.mem = ObservedMemory()
        for address, length, fill in [(GLOBAL, POOL+0x4000-GLOBAL, 0), (0x23DA58, 16, 0),
            (INPUT-16, INPUT_CAP+INPUT_EXT+32, 0xA5), (PCM-16, inputs['channels']*PCM_PHYSICAL+32, 0xA5),
            (OUTER, 0x9C, 0), (INNER, 0xE4, 0), (PRED, 0x3C, 0),
            (SCRATCH-4, 0x100, 0x5A), (STACK, 0x2000, 0xCC),
            (TABLE, 64, 0), (MODE, 4, 0), (ODD, 4, 0)]: self.mem.map(address, length, fill)
        for address, length in [(0x224C28, 48), (0x23DA58, 16), (TABLE, 64)]:
            self.mem.store(address, length, int.from_bytes(self.elf.read(address, length), 'little'))
        self.mem.store(MODE, 4, inputs['downmix'])
        self.initialize_mac(hi=0x11111111, lo=0x22222222, hi1=0x33333333, lo1=0x44444444)
        self.regs = [0]*32; self.guard_depth = 0; self.all_visited = set(); self.total_steps = 0
        self.rings = [POOL + i*64 for i in range(inputs['channels']+1)]
        self.buffers = [(INPUT, INPUT_CAP+INPUT_EXT)] + [(PCM+i*PCM_PHYSICAL, PCM_PHYSICAL) for i in range(inputs['channels'])]
        self.setup = []

    def raw(self, address, size):
        data, offset = self.mem.region(address, size); return bytes(data[offset:offset+size])

    def small(self):
        return dict(outer_hex=self.raw(OUTER, 0x9C).hex(), inner_hex=self.raw(INNER, 0xE4).hex(),
            predictor_hex=self.raw(PRED, 0x3C).hex(), rings=[self.mem.words(r, 16) for r in self.rings],
            odd_u32=self.mem.load(ODD, 4))

    def snapshot(self):
        return dict(**self.small(), encoded_backing_guard_hex=self.raw(INPUT-16, INPUT_CAP+INPUT_EXT+32).hex(),
            pcm_arena_guard_hex=self.raw(PCM-16, self.inputs['channels']*PCM_PHYSICAL+32).hex(),
            scratch_hex=self.raw(SCRATCH-4, 0x100).hex(), stack_frame_hex=self.raw(SP-0x400, 0x400).hex(),
            lower_stack_guard_hex=self.raw(STACK, 32).hex(), caller_guard_hex=self.raw(SP, 32).hex(),
            original_table_sha256=sha(self.raw(TABLE,64)))

    def hook(self, pc):
        if pc not in (ENTER, LEAVE, MEMSET, MEMCPY, REPORT, ERROR, PCM_CALLBACK): return False
        event = dict(pc=pc, from_pc=self.from_pc, arguments_u64=list(self.regs[4:8]), depth_before=self.guard_depth,
                     write_index_before=len(self.mem.writes))
        if pc == ENTER: event['kind'] = 'enter'; self.guard_depth += 1
        elif pc == LEAVE:
            event['kind'] = 'leave'; self.guard_depth -= 1
            if self.guard_depth < 0: raise OracleError('Unbalanced external guard')
        elif pc == MEMSET:
            dest, value, size = (r & MASK32 for r in self.regs[4:7])
            if not (POOL <= dest <= dest+size <= POOL+0x4000): raise OracleError('Unadmitted memset')
            event['kind'] = 'bounded_memset'; self.mem.fill(dest, size, value)
            self.regs[2] = self.regs[4]
        elif pc == MEMCPY:
            dest, source, size = (r & MASK32 for r in self.regs[4:7])
            if size > PCM_CAP or not any(base <= dest <= dest+size <= base+length and base <= source <= source+size <= base+length for base, length in self.buffers):
                raise OracleError('Unadmitted ring copy extent')
            if size and dest < source+size and source < dest+size: raise OracleError('Overlapping memcpy excluded')
            event['kind'] = 'bounded_memcpy'; event['source_bytes_hex'] = self.raw(source, size).hex()
            for i in range(size): self.mem.store(dest+i, 1, self.mem.load(source+i, 1))
            self.regs[2] = sext32(dest)
        else:
            event['kind'] = 'pcm_callback' if pc == PCM_CALLBACK else 'error_callback' if pc == ERROR else 'diagnostic'
            active = self.mem.active; self.mem.active = False
            event['observed_before'] = self.small()
            self.mem.active = active
            if pc == PCM_CALLBACK:
                size = self.regs[7] & MASK32
                if size > 2048: raise OracleError('Finite observational callback limit')
                event['pcm_bytes_hex'] = self.raw(self.regs[6] & MASK32, size).hex()
                event['pcm_planes_sha256'] = [sha(self.raw(PCM+i*PCM_PHYSICAL, PCM_PHYSICAL)) for i in range(self.inputs['channels'])]
                event['pcm_prefix_hex'] = [self.raw(PCM+i*PCM_PHYSICAL, PCM_EXT).hex() for i in range(self.inputs['channels'])]
            # Observation-only: no codec result, queue grant, cancel or publication.
        event['depth_after'] = self.guard_depth; event['write_index_after'] = len(self.mem.writes); self.events.append(event)
        self.pc = self.regs[31] & MASK32
        return True

    def run(self, entry, arguments=(), *, limit=200000, full=True):
        self.regs = [0]*32; self.regs[2] = 0xBAD0BAD0; self.regs[29] = SP; self.regs[31] = RETURN
        for n in (*range(16, 24), 30): self.regs[n] = 0x1234567800000000+n
        saved = {n:self.regs[n] for n in (*range(16, 24), 30)}
        for n, value in enumerate(arguments): self.regs[4+n] = sext32(value)
        before = self.snapshot() if full else self.small()
        self.events = []; self.pc = entry; self.from_pc = None; pending = None; steps = 0; visited = set(); traces = []
        self.mem.writes = []; self.mem.reads = {}; self.mem.active = True; failure = None
        try:
            while self.pc != RETURN:
                if steps >= limit: raise StepLimit('Original transaction instruction bound')
                self.mem.pc = self.pc
                if pending is None and self.hook(self.pc): continue
                pc = self.pc
                if pc not in self.code: raise OracleError(f'Unowned instruction fetch {pc:#x}')
                if pc in TRACE:
                    active = self.mem.active; self.mem.active = False
                    traces.append(dict(pc=pc, name=TRACE[pc], from_pc=self.from_pc, write_index=len(self.mem.writes),
                        arguments_u64=list(self.regs[4:12]), state=self.small()))
                    self.mem.active = active
                steps += 1; visited.add(pc)
                branch = self.instruction(pc, self.code[pc])
                if pending is not None:
                    if branch is not None: raise OracleError('Control in delay slot')
                    self.pc, self.from_pc = pending; pending = None
                elif branch is None: self.pc += 4
                else:
                    taken, target, likely = branch
                    if likely and not taken: self.pc += 8
                    else: pending = (target if taken else pc+8, pc); self.pc = pc+4
        except OracleError as error:
            failure = dict(type=type(error).__name__, detail=str(error), pc=self.pc, word_u32=self.code.get(self.pc))
        finally: self.mem.active = False
        if failure is None and (self.guard_depth or self.regs[29] != SP or any(self.regs[n] != value for n, value in saved.items())):
            raise OracleError('Original transaction failed ABI/guard restoration')
        self.all_visited.update(visited); self.total_steps += steps
        return dict(status='partial_refusal' if failure else 'returned', failure=failure, entry=entry,
            arguments_u32=[v & MASK32 for v in arguments], original_instructions=steps,
            before=before, after=self.snapshot() if full else self.small(),
            traces=traces, events=self.events, writes=self.mem.writes,
            reads_by_pc={f'{pc:06X}':count for pc,count in self.mem.reads.items()},
            visited_pcs=sorted(visited), raw_v0_lower64_observation_only=self.regs[2],
            return_is_defined=entry in (0x13F8A8, 0x124810),
            mac_lower64=self.mac_state())

    def setup_call(self, entry, args):
        result = self.run(entry, args, full=False)
        self.setup.append(dict(entry=entry, arguments=list(args), expected=result))
        if result['failure']: raise OracleError('Setup original call failed: ' + result['failure']['detail'])
        return result

    def advance_empty(self, ring, count):
        if not count: return
        self.setup_call(0x13FA88, [ring, 0, count, SCRATCH])
        if self.mem.load(SCRATCH+4, 4) != count: raise OracleError('Advance not contiguous')
        self.setup_call(0x13FBF8, [ring, 1, SCRATCH])
        self.setup_call(0x13FA88, [ring, 1, count, SCRATCH])
        self.setup_call(0x13FBF8, [ring, 0, SCRATCH])

    def produce(self, ring, data=None, count=None):
        remaining = len(data) if data is not None else count
        consumed = 0
        while remaining:
            self.setup_call(0x13FA88, [ring, 0, remaining, SCRATCH])
            pointer, granted = self.mem.words(SCRATCH, 2)
            if not 0 < granted <= remaining: raise OracleError('Producer cannot make bounded progress')
            if data is not None:
                for i, value in enumerate(data[consumed:consumed+granted]): self.mem.store(pointer+i, 1, value)
            self.setup_call(0x13FBF8, [ring, 1, SCRATCH])
            consumed += granted; remaining -= granted

    def prepare(self):
        self.setup_call(0x13F7F8, [])
        for index, (base, length) in enumerate(self.buffers):
            capacity, extension = (INPUT_CAP, INPUT_EXT) if index == 0 else (PCM_CAP, PCM_EXT)
            result = self.setup_call(0x13F8A8, [base, capacity, extension])
            if result['raw_v0_lower64_observation_only'] & MASK32 != self.rings[index]: raise OracleError('Actual pool identity differed')
            self.setup_call(0x13F9E0, [self.rings[index], ERROR, self.rings[index]])
        self.advance_empty(self.rings[0], self.inputs['input_position'])
        self.produce(self.rings[0], data=bytes.fromhex(self.inputs['encoded_hex']))
        for i in range(self.inputs['channels']):
            self.advance_empty(self.rings[i+1], self.inputs['pcm_positions'][i])
            self.produce(self.rings[i+1], count=self.inputs['occupied_pcm_bytes'][i])
        # Header-admitted setup only, not constructor/parser/coefficient emulation.
        for offset, value in {4:INNER, 8:self.rings[0], 0x38:self.inputs['max_request_samples'],
            0x3C:self.inputs['sample_limit'], 0x50:PCM_CALLBACK if self.inputs['callback'] else 0,
            0x54:0x24681357}.items(): self.mem.store(OUTER+offset, 4, value)
        self.mem.store(OUTER, 1, 1); self.mem.store(OUTER+1, 1, 2); self.mem.store(OUTER+2, 1, self.inputs['channels'])
        for i in range(self.inputs['channels']): self.mem.store(OUTER+0xC+4*i, 4, self.rings[i+1])
        for offset, value in {8:PRED, 0x10:32, 0x18:self.inputs['total_samples'], 0x38:self.inputs['channels'],
            0x3C:PCM, 0x40:PCM_CAP//2, 0x44:PCM_PHYSICAL//2,
            0x50:self.inputs['channels'], 0x54:18, 0x58:32, 0x5C:PCM,
            0x60:PCM_CAP//2, 0x64:PCM_PHYSICAL//2, 0x78:0x12CEB8, 0x7C:OUTER,
            0x80:0x124840, 0x84:INNER}.items(): self.mem.store(INNER+offset, 4, value)
        self.mem.store(INNER, 2, 1); self.mem.store(INNER+2, 2, 1)
        self.mem.store(INNER+0xC, 1, self.profile['encoding']); self.mem.store(INNER+0x14, 4, self.profile['frequency'])
        self.mem.store(INNER+0xD, 1, 4); self.mem.store(INNER+0xE, 1, self.inputs['channels']); self.mem.store(INNER+0xF, 1, 18)
        self.mem.store(PRED, 4, 1)
        values = self.profile['history_i16'] + self.profile['coefficients_i16'] + [self.profile['key_u16'], self.profile['multiplier_i16'], self.profile['addend_i16']]
        for i, value in enumerate(values): self.mem.store(PRED+0x28+2*i, 2, value)


def block(index=0, marker=False):
    return (0x8000 if marker else 0x1234+index).to_bytes(2, 'big') + bytes((i*37+index*19) & 255 for i in range(16))


def corpus_inputs():
    rows = []
    def add(name, *, channels=1, encoded=None, **changes):
        values = dict(name=name, kind='outer_transaction', channels=channels, downmix=0,
            encoded_hex=(encoded if encoded is not None else b''.join(block(i) for i in range(4*channels))).hex(),
            input_position=0, pcm_positions=[0]*channels, occupied_pcm_bytes=[0]*channels,
            total_samples=1000, sample_limit=-1, max_request_samples=128, callback=True, actions=['service'])
        values.update(changes); rows.append(values)
    add('mono-four-blocks'); add('stereo-four-pairs', channels=2)
    add('downmix-four-pairs', channels=2, downmix=1)
    add('mono-empty', encoded=b''); add('mono-short-three-bytes', encoded=b'\x12\x34\x56')
    add('mono-zero-budget', sample_limit=0); add('mono-zero-output-request', max_request_samples=0)
    add('mono-partial-budget-35', sample_limit=35); add('stereo-partial-budget-35', channels=2, sample_limit=35)
    add('downmix-partial-budget-35', channels=2, downmix=1, sample_limit=35)
    add('outer-total-clips-to-35', total_samples=35, actions=['service', 'service'])
    add('mono-unconsumed-tail-byte', encoded=block()+b'\x7f', actions=['service','service'])
    add('stereo-odd-input-blocks', channels=2, encoded=block()+block(1)+block(2), actions=['service','service'])
    add('mono-input-wrap-split', input_position=2020, encoded=b''.join(block(i) for i in range(8)), actions=['service']*3)
    add('stereo-input-wrap-split', channels=2, input_position=2020, encoded=b''.join(block(i) for i in range(8)), actions=['service']*3)
    add('mono-output-wrap', pcm_positions=[16352]); add('stereo-output-wrap', channels=2, pcm_positions=[16352]*2)
    add('downmix-output-wrap', channels=2, downmix=1, pcm_positions=[16352]*2)
    add('partial-budget-near-output-end', pcm_positions=[16382], sample_limit=33, actions=['service','service'])
    add('mono-backpressure-recover', occupied_pcm_bytes=[16352], actions=['service', 'consume64', 'service', 'service'])
    add('stereo-backpressure-recover', channels=2, occupied_pcm_bytes=[16352]*2, actions=['service','consume64','service'])
    add('mono-marker-first', encoded=block(marker=True)+block(1))
    add('mono-marker-after-prefix', encoded=block()+block(1)+block(marker=True)+block(3))
    add('stereo-left-marker-after-prefix', channels=2, encoded=block()+block(1)+block(marker=True)+block(3))
    add('stereo-right-marker-after-prefix', channels=2, encoded=block()+block(1)+block(2)+block(marker=True))
    add('downmix-right-marker-after-prefix', channels=2, downmix=1, encoded=block()+block(1)+block(2)+block(marker=True))
    add('outer-end-marker', encoded=b'\x80\x01\x00\x0c'+bytes(12))
    add('zero-prefixed-block-source-observation', encoded=bytes(5)+block(), actions=['service','service'])
    add('zero-filled-block-source-observation', encoded=bytes(24), actions=['service','service'])
    add('outer-end-marker-then-padding', encoded=b'\x80\x01\x00\x0c'+bytes(36), actions=['service','service'])
    add('outer-end-marker-then-ordinary-block', encoded=b'\x80\x01\x00\x0c'+bytes(12)+block(), actions=['service','service'])
    add('no-publication-callback', callback=False)
    add('inner-constructor-default-reserve', kind='default_reserve_helper', actions=['default_reserve'])
    return dict(schema=1, provenance='Authored header-admitted synthetic inputs; no native result or runtime recording.', profile=PROFILE, cases=rows)


def execute_case(inputs, profile=None):
    machine = Machine(inputs, profile); machine.prepare(); initial = machine.snapshot(); operations = []
    for action in inputs['actions']:
        if action == 'service': result = machine.run(0x12D638, [OUTER])
        elif action == 'consume64':
            results = []
            for ring in machine.rings[1:]:
                results.append(machine.run(0x13FA88, [ring, 1, 64, SCRATCH], full=False))
                results.append(machine.run(0x13FBF8, [ring, 0, SCRATCH], full=False))
            operations.append(dict(action=action, expected=results)); continue
        elif action == 'default_reserve':
            machine.mem.store(INNER+0x8C, 4, 7); machine.mem.store(INNER+0x88, 4, 12)
            result = machine.run(0x124810, [INNER, SCRATCH, SCRATCH+4, SCRATCH+8])
        else: raise OracleError('Unknown frozen action')
        operations.append(dict(action=action, expected=result))
        if result['failure']: break
    return dict(name=inputs['name'], kind=inputs['kind'], setup=machine.setup, initial=initial,
        operations=operations, final=machine.snapshot(), original_instructions=machine.total_steps,
        visited_pcs=sorted(machine.all_visited))


def source_audit(source):
    elf = Elf(ROOT / 'game_data/SLUS_207.65'); comments = {}; files = []
    for path in sorted(source.glob('*.cpp')):
        match = re.match(r'sub_([0-9A-Fa-f]+)_', path.name)
        if not match or not any(start <= int(match[1], 16) < end for start,(end,_) in BODIES.items()): continue
        data = path.read_bytes(); files.append(dict(path=str(path.relative_to(ROOT)), sha256=sha(data)))
        for pc,word in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)', data):
            pc,word = int(pc,16), int(word,16)
            if any(start <= pc < end for start,(end,_) in BODIES.items()):
                if pc in comments and comments[pc] != word: raise OracleError('Conflicting original comments')
                comments[pc] = word
    omitted = []
    for start,(end,_) in BODIES.items():
        for pc in range(start,end,4):
            word = int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if word != comments[pc]: raise OracleError(f'Original comment mismatch {pc:#x}')
            elif word: raise OracleError(f'Omitted nonzero source word {pc:#x}')
            else: omitted.append(pc)
    return dict(files=files, matched_comments=len(comments), omitted_zero_pcs=omitted)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--reference-source', type=Path, default=ROOT / 'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
    args = parser.parse_args(); target = args.output.resolve(); frozen = target.with_name(target.stem+'-inputs.json')
    if target.exists() or frozen.exists(): raise OracleError('Never overwrite staged evidence; choose a new output path')
    target.parent.mkdir(parents=True, exist_ok=True); frozen.write_bytes(serialized(corpus_inputs()))
    audit = source_audit(args.reference_source.resolve()); isa = implementation_identity()
    transcript = json.loads(frozen.read_bytes())
    rows = [execute_case(row, transcript['profile']) for row in transcript['cases']]
    result = dict(schema=1, provenance='Actual original ring/window/kernel instructions on frozen synthetic state, not a full ADXT player.',
        elf_sha256=Elf(ROOT / 'game_data/SLUS_207.65').sha256,
        inputs_file=str(frozen.relative_to(ROOT)), inputs_sha256=sha(frozen.read_bytes()), source_word_audit=audit,
        body_sha256={hex(start):expected for start,(_,expected) in BODIES.items()}, isa_reference=isa,
        engine_sha256={name:sha(Path(__file__).with_name(name).read_bytes()) for name in
            ('sjuni_oracle.py','ee_mac_oracle.py','adx_stereo_oracle.py','sjrb_oracle.py','adx_window_oracle.py')},
        cases=rows, summary=dict(cases=len(rows), original_instructions=sum(row['original_instructions'] for row in rows),
            unique_visited_words=len(set(pc for row in rows for pc in row['visited_pcs'])),
            failed_cases=[row['name'] for row in rows if any(result['failure'] for op in row['operations']
                for result in ([op['expected']] if isinstance(op['expected'],dict) else op['expected']))]),
        limitations=['Prepared, already admitted tag0 keyed18-byte/32-sample header state; no header/coefficient calculation proof.',
            'Actual12CEB8 outer reservation and124840 default completion; constructor default124810 separately executed as a helper.',
            'Only guard, bounded generic memory primitives and observation-only external callbacks are hooked; no codec or ring results are scripted.',
            'Symmetric1/2-channel grants, whole guarded backing, bounded requests and no reentrant cancellation; no resource/loop/clock/RNA credit owner.',
            'No full volatile-GPR/MAC equivalence to hooked libc and no scheduler timing or device/playback speed claim.'])
    target.write_bytes(serialized(result))
    print(json.dumps(dict(**result['summary'], bytes=target.stat().st_size, sha256=sha(target.read_bytes()),
        inputs_sha256=result['inputs_sha256'], output=str(target)), indent=2))


if __name__ == '__main__': main()
