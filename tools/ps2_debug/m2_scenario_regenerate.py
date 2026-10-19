"""Regenerate two original M2 blockers without replacing shared generated headers.

The default writes candidates under ignored build-ninja/m2-scenario. --apply
copies only the selected function files and adds their resumable registrations.
Original game code is read from the user's local ELF/ISO, never downloaded.
"""
import argparse
import csv
import hashlib
import re
import struct
import subprocess
import sys
from pathlib import Path

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from overlay_extract import Iso, decompress, wrap_elf

TARGETS = {
    'sprite': ('o1_00588200', 0x588200, 0x588478,
               'recomp/config/output_ovl/o1', 'o1_functions.h',
               'recomp/config/output_ovl/o1/register_o1.cpp'),
    'progress': ('sub_001F73B0', 0x1F73B0, 0x1F7524,
                 'recomp/config/output', 'ps2_recompiled_functions.h',
                 'recomp/config/output/register_functions.cpp'),
}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--target', choices=['sprite', 'progress', 'both'], default='both')
    parser.add_argument('--iso', type=Path, default=ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso')
    parser.add_argument('--elf', type=Path, default=ROOT / 'game_data/SLUS_207.65')
    parser.add_argument('--recompiler', type=Path, default=ROOT / 'third_party/PS2Recomp/out/build/ps2xRecomp/Release/ps2_recomp.exe')
    parser.add_argument('--apply', action='store_true')
    args = parser.parse_args()
    work = ROOT / 'build-ninja/m2-scenario'
    work.mkdir(parents=True, exist_ok=True)
    selected = TARGETS if args.target == 'both' else {args.target: TARGETS[args.target]}
    for target, (name, start, end, dest, header, register) in selected.items():
        if target == 'sprite':
            iso = Iso(str(args.iso))
            try:
                directory = next((l, s) for n, l, s, f in iso.listdir(*iso.root()) if n == 'BIN')
                _, sector, size, _ = next(e for e in iso.listdir(*directory) if e[0] == '1.DAT')
                raw = iso.read(sector, size)
                img = decompress(raw) if raw[:2] == b'\x02\x00' else raw
            finally:
                iso.f.close()
            ident, base, text, data = struct.unpack_from('<4I', img, 4)
            if img[:4] != b'MWo3' or ident != 2 or base != 0x570000 or len(img) != 0x40 + text + data:
                raise RuntimeError('Unexpected overlay revision/header extent')
            code = img[start-base:end-base]
        else:
            original = args.elf.read_bytes()
            if hashlib.sha256(original).hexdigest() != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
                raise RuntimeError('Unexpected main ELF revision')
            phoff = struct.unpack_from('<I', original, 28)[0]
            phnum = struct.unpack_from('<H', original, 44)[0]
            for n in range(phnum):
                typ, off, va, pa, size, mem, flags, align = struct.unpack_from('<8I', original, phoff+n*32)
                if typ == 1 and va <= start and end <= va+size:
                    code = original[off+start-va:off+end-va]
                    break
            else:
                raise RuntimeError('Function outside file-backed ELF segments')
        if len(code) != end-start:
            raise RuntimeError('Truncated original function')
        run = work / target
        run.mkdir(exist_ok=True)
        elf = run / 'function.elf'
        elf.write_bytes(wrap_elf(code, start, len(code)))
        mapping = run / 'function.csv'
        with mapping.open('w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['name', 'start', 'end', 'size'])
            writer.writerow([name, hex(start), hex(end), len(code)])
        output = run / 'generated'
        output.mkdir(exist_ok=True)
        config = run / 'function.toml'
        config.write_text('[general]\ninput = "%s"\nghidra_output = "%s"\noutput = "%s/"\n'
                          'single_file_output = false\npatch_syscalls = false\npatch_cop0 = true\npatch_cache = true\n'
                          % (elf.as_posix(), mapping.as_posix(), output.as_posix()))
        result = subprocess.run([str(args.recompiler.resolve()), str(config)], capture_output=True, text=True)
        (run / 'recompiler.log').write_text(result.stdout + result.stderr)
        if result.returncode:
            raise RuntimeError(f'Recompiler failed; inspect {run}/recompiler.log')
        function = f'{name}_0x{start:x}'
        candidate = output / f'{function}.cpp'
        source = candidate.read_text()
        words = {int(a, 16): int(w, 16) for a, w in re.findall(r'// (0x[\da-fA-F]+): (0x[\da-fA-F]+)', source)}
        expected = {start+i: struct.unpack_from('<I', code, i)[0] for i in range(0, len(code), 4)}
        # The generator elides some zero-word NOP delay slots.
        if (any(expected.get(a) != word for a, word in words.items())
                or any(words.get(a) != word for a, word in expected.items() if word)
                or 'TODO_NAMED' in source):
            raise RuntimeError('Generated instruction coverage differs from original function')
        source = source.replace('#include "ps2_recompiled_functions.h"', f'#include "{header}"')
        candidate.write_text(source)
        registrations = re.findall(r'runtime\.registerFunction\((0x[\da-fA-F]+), (\w+)\);',
                                   (output / 'register_functions.cpp').read_text())
        additions = []
        current = (ROOT / register).read_text()
        for address, fn in registrations:
            if fn != function or not start <= int(address, 16) < end:
                continue
            if target == 'sprite':
                line = f'    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 2u, {address}u, {fn});'
            else:
                line = f'    runtime.registerFunction({address}, {fn});'
            if line not in current:
                additions.append(line)
        if args.apply:
            (ROOT / dest / candidate.name).write_text(source)
            if additions:
                marker = current.rfind('}')
                (ROOT / register).write_text(current[:marker] + '\n'.join(additions) + '\n' + current[marker:])
        print(f'{target}: {len(expected)} original words verified ({len(expected)-len(words)} elided NOPs), SHA256={hashlib.sha256(code).hexdigest()}')
        print(f'candidate={candidate}; new registrations={len(additions)}; applied={args.apply}')


if __name__ == '__main__':
    main()
