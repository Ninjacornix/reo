"""Repair only three PCPYH translations, using source registers from owned ELF.

No shared generated headers or registrations are changed. --emit-test writes
wrappers containing the actual production translation expressions for regression.
"""
import argparse
import hashlib
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
EXPECTED_ELF = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
TARGETS = [(0x107938, 0x107988, 0x700A46E9),
           (0x107C68, 0x107C94, 0x70081EE9),
           (0x14A850, 0x14A89C, 0x700B5EE9)]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--apply', action='store_true')
    parser.add_argument('--emit-test', type=Path)
    args = parser.parse_args()
    elf = (ROOT / 'game_data/SLUS_207.65').read_bytes()
    if hashlib.sha256(elf).hexdigest() != EXPECTED_ELF:
        raise RuntimeError('Unexpected owned ELF revision')
    phoff = struct.unpack_from('<I', elf, 28)[0]
    phnum = struct.unpack_from('<H', elf, 44)[0]
    segments = [struct.unpack_from('<8I', elf, phoff + n * 32) for n in range(phnum)]
    wrappers = ['// Extracted production PCPYH expressions; regenerate before compilation.\n']
    for entry, address, expected in TARGETS:
        segment = next(s for s in segments if s[0] == 1 and s[2] <= address < s[2] + s[4])
        opcode = struct.unpack_from('<I', elf, segment[1] + address - segment[2])[0]
        if opcode != expected:
            raise RuntimeError(f'Unexpected original opcode at {address:X}')
        source, dest = (opcode >> 16) & 31, (opcode >> 11) & 31
        path = ROOT / f'recomp/config/output/sub_{entry:08X}_0x{entry:x}.cpp'
        # Limit replacement to the expression immediately following this opcode.
        raw = path.read_bytes()
        pattern = (rb'(// 0x' + f'{address:x}'.encode() + rb': 0x' + f'{opcode:x}'.encode()
                   + rb'[^\n]*\r?\n\s*ctx->pc[^\n]*\r?\n\s*\{ __m128i src = GPR_VEC\(ctx, )'
                   + rb'(\d+)(\);.*?SET_GPR_VEC\(ctx, ' + str(dest).encode()
                   + rb', _mm_set_epi16\(h,h,h,h, l,l,l,l\)\); \})')
        match = re.search(pattern, raw, flags=re.S)
        if not match or int(match[2]) not in (0, source):
            raise RuntimeError(f'Unexpected production PCPYH expression in {path}')
        if args.apply:
            raw = raw[:match.start(2)] + str(source).encode() + raw[match.end(2):]
            # The old emitted instruction line ended in a trailing space.
            raw = re.sub(rb'(uint16_t h = _mm_extract_epi16\(src, 4\);) +(?=\r?\n)', rb'\1', raw)
            path.write_bytes(raw)
            match = re.search(pattern, raw, flags=re.S)
        expression = b'{ __m128i src = GPR_VEC(ctx, ' + match[2] + match[3]
        wrappers.append(f'static void emitted_{address:x}(R5900Context* ctx) {{\n'
                        + expression.decode() + '\n}\n')
        print(f'0x{address:X}: owned opcode 0x{opcode:08X}, rt={source}, rd={dest}; '
              f'production source={int(match[2])}')
    if args.emit_test:
        args.emit_test.parent.mkdir(parents=True, exist_ok=True)
        args.emit_test.write_text(''.join(wrappers))


if __name__ == '__main__':
    main()
