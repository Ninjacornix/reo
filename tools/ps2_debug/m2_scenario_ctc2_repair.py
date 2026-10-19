"""Verify/repair the three reached original main trig CTC2 VI2 emissions.

Checks the owned ELF and original opcodes. Changes no guest instructions,
function boundaries, headers, registrations, or other control selectors.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

ROOT = Path(__file__).resolve().parents[2]
TARGETS = {
    'sub_0018F340_0x18f340.cpp': 0x18F37C,
    'sub_0018F470_0x18f470.cpp': 0x18F4AC,
    'sub_0018F570_0x18f570.cpp': 0x18F5B0,
}
OLD = b'ctx->vu0_vpu_stat = GPR_U32(ctx, 8);'
NEW = b'ctx->vi[2] = (uint16_t)GPR_U32(ctx, 8);'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--apply', action='store_true')
    args = parser.parse_args()
    elf = (ROOT / 'game_data/SLUS_207.65').read_bytes()
    elf_hash = hashlib.sha256(elf).hexdigest()
    if elf_hash != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
        raise RuntimeError('Unexpected owned main ELF revision')
    phoff = struct.unpack_from('<I', elf, 28)[0]
    phnum = struct.unpack_from('<H', elf, 44)[0]
    rows = []
    for filename, pc in TARGETS.items():
        for n in range(phnum):
            typ, off, va, _, size, _, _, _ = struct.unpack_from('<8I', elf, phoff+n*32)
            if typ == 1 and va <= pc < va+size:
                word = struct.unpack_from('<I', elf, off+pc-va)[0]
                break
        else:
            raise RuntimeError('Target outside owned ELF segment')
        if word != 0x48C81000:
            raise RuntimeError('Original target is not CTC2 t0,VI2')
        path = ROOT / 'recomp/config/output' / filename
        source = path.read_bytes()
        # Bound replacement to this exact instruction, preserving line endings.
        pattern = (rb'(// 0x'+format(pc, 'x').encode()+
                   rb': 0x48c81000[^\r\n]*\r?\n\s*ctx->pc = 0x'+
                   format(pc, 'x').encode()+rb'u;\r?\n\s*)('+re.escape(OLD)+
                   rb'|'+re.escape(NEW)+rb')')
        matches = list(re.finditer(pattern, source))
        if len(matches) != 1:
            raise RuntimeError('Expected one exact original CTC2 emission: '+filename)
        match = matches[0]
        corrected = match.group(2) == NEW
        if args.apply and not corrected:
            source = source[:match.start(2)]+NEW+source[match.end(2):]
            path.write_bytes(source)
        rows.append({'file': filename, 'pc': hex(pc), 'original_word': hex(word),
                     'source_rt': 8, 'destination_vi': 2,
                     'corrected': corrected or args.apply,
                     'source_sha256': hashlib.sha256(source).hexdigest()})
    output = ROOT / 'build-ninja/m2-scenario/ctc2-repair.json'
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps({'owned_elf_sha256': elf_hash, 'functions': rows,
                                 'remaining_generated_low_vi_occurrences_outside_scope': True}, indent=2))
    print(json.dumps(rows, indent=2))


if __name__ == '__main__':
    main()
