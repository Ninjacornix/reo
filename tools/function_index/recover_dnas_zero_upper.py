#!/usr/bin/env python3
"""Static arithmetic recovery of three fixed zero-key o4 spans, as data only.

Never maps, loads, invokes, emulates or executes guest instructions. The owned
image is read-only. All transformed values and receipts are private new buffers.
"""
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x6E0000
SHA = '8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16'
A, B, MASK = 0x09F8ED17, 0xA95128C3, 0xFFFFFFFF
FORWARD = (0x745AD8, 0x745B78, 0x745C18, 0x745CC8,
           0x745D78, 0x745E50, 0x745F10, 0x746010)
INVERSE = (0x746200, 0x7462A0, 0x746340, 0x746400,
           0x7464C0, 0x746598, 0x746670, 0x746780)
CASES = (
    (0x749500, 0x749638, 0x749570, 0x749584, 0x7495C8, 0x7495E8,
     0x749548, 0x749610, (5, 7, 5, 1, 2), (2, 1, 5, 7, 5)),
    (0x749638, 0x7497A8, 0x74969C, 0x7496B0, 0x74973C, 0x74975C,
     0x749674, 0x749784, (6, 3, 2), (2, 3, 6)),
    (0x74E1A8, 0x74E2E0, 0x74E218, 0x74E22C, 0x74E270, 0x74E290,
     0x74E1F0, 0x74E2B8, (0, 1, 5, 0, 5, 5, 2), (2, 5, 5, 0, 5, 1, 0)),
)


def rol(w, n):
    return ((w << n) | (w >> (32 - n))) & MASK


def ror(w, n):
    return ((w >> n) | (w << (32 - n))) & MASK


def permute(w, order):
    raw = w.to_bytes(4, 'little')
    return int.from_bytes(bytes(raw[i] for i in order), 'little')


def transform(w, slot, inverse):
    """Transcription of independently reviewed original 32-bit word arithmetic."""
    if slot == 0:
        return w ^ A
    if slot == 1:
        return w ^ B
    if slot == 2:
        return ror(w, 13) if inverse else rol(w, 13)
    if slot == 3:
        return ror(w, 8) if inverse else rol(w, 8)
    if slot == 4:
        return permute(w, (2, 0, 3, 1) if inverse else (1, 3, 0, 2))
    if slot == 5:
        return ror(w ^ A, 13) if inverse else rol(w, 13) ^ A
    if slot == 6:
        return (ror(permute(w, (2, 0, 3, 1)) ^ B, 8) if inverse
                else permute(rol(w, 8) ^ B, (1, 3, 0, 2)))
    if slot == 7:
        return (permute(ror(ror(w ^ A, 8), 13), (2, 0, 3, 1)) if inverse
                else rol(rol(permute(w, (1, 3, 0, 2)), 13), 8) ^ A)
    raise ValueError(slot)


def schedule(packed):
    count = ((packed >> 28) & 7) or 5
    return tuple((packed >> (4 * i)) & 7 for i in range(count))


def apply(words, slots, inverse):
    result = list(words)
    for slot in slots:
        result = [transform(w, slot, inverse) for w in result]
    return result


REG = ('zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 '
       's0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra').split()


def fields(pc, w):
    """Small explicit word-field listing, not a CPU or execution engine."""
    if not w:
        return 'nop'
    op, rs, rt, rd, sh, fn = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31, w & 63
    imm = w & 65535
    signed = imm - 65536 if imm & 32768 else imm
    r = lambda n: '$' + REG[n]
    if op == 0:
        if fn in (0, 2, 3):
            return f'{ {0:"sll",2:"srl",3:"sra"}[fn]} {r(rd)}, {r(rt)}, {sh}'
        if fn in (8, 9):
            return f'{"jr" if fn == 8 else "jalr"} {r(rs)}'
        if fn in (10, 11):
            return f'{"movz" if fn == 10 else "movn"} {r(rd)}, {r(rs)}, {r(rt)}'
        names = {0x20: 'add', 0x21: 'addu', 0x23: 'subu', 0x24: 'and',
                 0x25: 'or', 0x26: 'xor', 0x2A: 'slt', 0x2B: 'sltu', 0x2D: 'daddu'}
        if fn in names:
            return f'{names[fn]} {r(rd)}, {r(rs)}, {r(rt)}'
    if op in (2, 3):
        dest = ((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        return f'{"j" if op == 2 else "jal"} 0x{dest:08X}'
    if op in (4, 5, 6, 7, 0x14, 0x15):
        dest = pc + 4 + signed * 4
        name = {4:'beq',5:'bne',6:'blez',7:'bgtz',0x14:'beql',0x15:'bnel'}[op]
        args = f'{r(rs)}, {r(rt)}, ' if op in (4,5,0x14,0x15) else f'{r(rs)}, '
        return f'{name} {args}0x{dest:08X}'
    if op == 1 and rt in (0, 1, 2, 3):
        return f'{ {0:"bltz",1:"bgez",2:"bltzl",3:"bgezl"}[rt]} {r(rs)}, 0x{pc+4+signed*4:08X}'
    if op == 15:
        return f'lui {r(rt)}, 0x{imm:04X}'
    if op in (8, 9, 10, 11, 12, 13, 14):
        name = {8:'addi',9:'addiu',10:'slti',11:'sltiu',12:'andi',13:'ori',14:'xori'}[op]
        return f'{name} {r(rt)}, {r(rs)}, {signed if op < 12 else hex(imm)}'
    memory = {0x20:'lb',0x21:'lh',0x23:'lw',0x24:'lbu',0x25:'lhu',0x27:'lwu',
              0x28:'sb',0x29:'sh',0x2B:'sw',0x37:'ld',0x3F:'sd'}
    if op in memory:
        return f'{memory[op]} {r(rt)}, {signed}({r(rs)})'
    return f'UNDECODED op={op:X} rs={rs} rt={rt} rd={rd} sh={sh} fn={fn:X}'


def main():
    image = ROOT / 'build-function-index/owned-overlays/o4.bin'
    raw = image.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    read = lambda a, n: struct.unpack_from('<' + 'I' * n, raw, a - BASE)
    pack = lambda words: struct.pack('<' + 'I' * len(words), *words)
    assert read(0x767A40, 8) == FORWARD
    assert read(0x767A60, 8) == INVERSE
    # Both directions on zero, all bits, each basis bit and mixed-bit probes.
    probes = [0, MASK, 0x12345678, 0x89ABCDEF, 0xA5A5A5A5] + [1 << k for k in range(32)]
    for slot in range(8):
        for w in probes:
            assert transform(transform(w, slot, True), slot, False) == w
            assert transform(transform(w, slot, False), slot, True) == w
    receipts, listing = [], []
    for owner, owner_end, header_at, start, end, restore_at, entry_call, restore_call, entry_slots, restore_slots in CASES:
        header, restore = read(header_at, 5), read(restore_at, 4)
        assert header[0] == header[2] == header[4] == 0 and restore[1] == 1 and restore[3] == 0
        assert header[1] ^ header[3] == restore[0] ^ restore[2] == end - start
        assert schedule(header[1]) == entry_slots and schedule(restore[0]) == restore_slots
        assert read(entry_call, 1)[0] == read(restore_call, 1)[0] == 0x0C1D15F2  # JAL7457C8
        # No guessed reversal: restore_slots above must match the owned restore descriptor.
        source = list(read(start, (end - start) // 4))
        candidate = apply(source, entry_slots, True)
        restored = apply(candidate, restore_slots, False)
        assert restored == source
        candidate_sha = hashlib.sha256(pack(candidate)).hexdigest()
        expected_sha = ('1e3cc730042815eba63f666ec8d1b8dfbbc772cfed5cdcdee3cb51605baf292e'
                        if owner == 0x749638 else
                        'e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9')
        assert candidate_sha == expected_sha
        clear_ranges = ((owner, header_at - 0x18), (end, end + 8), (end + 0x30, owner_end))
        listing.append(f'OWNER {owner:08X}..{owner_end:08X} DATA-ONLY RECONSTRUCTION')
        records = []
        for lo, hi, kind in [(lo, hi, 'owned_clear') for lo, hi in clear_ranges] + [(start, end, 'reconstructed')]:
            words = candidate if kind == 'reconstructed' else read(lo, (hi - lo) // 4)
            listing.append(f'{kind} {lo:08X}..{hi:08X}')
            for i, word in enumerate(words):
                pc = lo + i * 4
                decoded = fields(pc, word)
                assert 'UNDECODED' not in decoded
                records.append(dict(address=f'{pc:08X}', word=f'{word:08X}', origin=kind, fields=decoded))
                listing.append(f'{pc:08X} {word:08X} {decoded}')
        receipts.append(dict(owner=f'o4:0x{owner:08X}', owner_end_exclusive=hex(owner_end),
                             payload_start=hex(start), payload_end_exclusive=hex(end),
                             header_address=hex(header_at), header_words=[f'{w:08X}' for w in header],
                             restore_address=hex(restore_at), restore_words=[f'{w:08X}' for w in restore],
                             entry_call=hex(entry_call), restore_call=hex(restore_call),
                             entry_direction='inverse', entry_slots=entry_slots,
                             restore_direction='forward', restore_slots=restore_slots,
                             exception_key=0, exception_offsets=[],
                             source_words=[f'{w:08X}' for w in source],
                             candidate_words=[f'{w:08X}' for w in candidate],
                             source_sha256=hashlib.sha256(pack(source)).hexdigest(),
                             candidate_sha256=candidate_sha,
                             payload_roundtrip_exact=True, reviewed_word_listing=records))
    assert hashlib.sha256(image.read_bytes()).hexdigest() == SHA
    result = dict(schema=1, image='o4', image_sha256=SHA, cases=receipts,
                  owned_image_unchanged=True, no_guest_execution=True,
                  limitation='Fixed zero-key copied-data recovery only. No guest execution, mapping, cache operation, '
                  'header mutation or runtime attachment. Roundtrip is byte arithmetic, not dynamic reachability or '
                  'whole-program correctness. Embedded skipped data is deliberately excluded from instruction listings.')
    out = ROOT / 'build-function-index/dnas-zero-upper-recovery.json'
    out.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    (ROOT / 'build-function-index/dnas-zero-upper-recovery.txt').write_text('\n'.join(listing) + '\n', encoding='utf-8')
    print('Copied-data recovery: 3 fixed spans, 69 words, exact actual-selector restores; owned image unchanged; no execution.')


if __name__ == '__main__':
    main()
