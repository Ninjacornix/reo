"""Run production escape hooks with locally generated original countdown code.

Guest sources and ELF inputs are read only. Include directives are the only
generated-source transformations; private staged guest code is never packaged.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess


def stage(root: Path, output: Path, game: str) -> dict:
    file2 = game == 'file2'
    address = 0x6bd820 if file2 else 0x68c7b0
    folder = root / ('recomp/config/output_file2/output_ovl/o2' if file2 else 'recomp/config/output_ovl/o2')
    source = next(folder.glob(f'*_0x{address:x}.cpp'))
    original = source.read_text()
    calls = set(re.findall(r'\b((?:o2_|sub_|func_)\w+_0x[0-9a-f]+)\(rdram, ctx, runtime\)', original))
    declarations = '\n'.join(f'void {name}(uint8_t*,R5900Context*,PS2Runtime*);' for name in calls)
    definitions, registrations = [], []
    for name in sorted(calls):
        pc = int(re.search(r'_0x([0-9a-f]+)$', name)[1], 16)
        bank = int(pc == (0x58d660 if file2 else 0x5705f0))
        definitions.append(f'void {name}(uint8_t*,R5900Context* c,PS2Runtime*) {{ expiryCalls.push_back({{{bank},GPR_U32(c,4),GPR_U32(c,5)}});c->pc=GPR_U32(c,31); }}')
        registrations.append(f'runtime.functions[0x{pc:x}]={name};')
    staged = declarations + '\n' + re.sub(r'^#include .*$', '', original, flags=re.M) + '\n'
    staged += '\n'.join(definitions) + '\nvoid registerExpiryCallbacks(PS2Runtime& runtime) {' + ''.join(registrations) + '}\n'
    output.mkdir(parents=True, exist_ok=True)
    (output / 'owned_escape_timer.inc').write_text(staged)
    (output / 'ps2_runtime.h').write_text('#pragma once\n// Controlled runtime is declared by escape_timer_harness.cpp.\n')
    elf = root / ('game_data_file2/ovl/ovl2.elf' if file2 else 'build-ninja/file2-lobby-research/file1/2.elf')
    data = elf.read_bytes()
    phoff = struct.unpack_from('<I', data, 28)[0]
    phnum = struct.unpack_from('<H', data, 44)[0]
    segments = [struct.unpack_from('<8I', data, phoff + i * 32) for i in range(phnum)]
    count, mismatches = 0, []
    for pc, word in re.findall(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)', original):
        pc, word = int(pc, 16), int(word, 16)
        for kind, offset, vaddr, _, size, *_ in segments:
            if kind == 1 and vaddr <= pc and pc + 4 <= vaddr + size:
                count += 1
                actual = struct.unpack_from('<I', data, offset + pc - vaddr)[0]
                if actual != word:
                    mismatches.append([hex(pc), hex(word), hex(actual)])
                break
        else:
            mismatches.append([hex(pc), 'unmapped'])
    receipt = {'game': game, 'source': str(source.relative_to(root)), 'elf': str(elf.relative_to(root)),
               'elfSha256': hashlib.sha256(data).hexdigest(), 'originalInstructions': count, 'mismatches': mismatches}
    (output / 'byte-proof.json').write_text(json.dumps(receipt, indent=2))
    if mismatches or count == 0:
        raise ValueError(f'{game}: generated countdown code differs from owned ELF')
    return receipt


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', default=shutil.which('clang++'))
    args = parser.parse_args()
    if not args.compiler:
        parser.error('Provide --compiler or put MinGW clang++ on PATH')
    root = Path(__file__).resolve().parents[2]
    output = root / 'build-ninja/points-cheats/escape-native'
    env = os.environ.copy()
    env['PATH'] = str(Path(args.compiler).resolve().parent) + os.pathsep + env['PATH']
    receipts = []
    for game in ('file1', 'file2'):
        folder = output / game
        receipt = stage(root, folder, game)
        executable = folder / 'escape_timer_check.exe'
        command = [args.compiler, '-std=c++20', '-O2', '-Wall', '-Wextra', '-DREO_GAME_' + game.upper(),
                   '-I', str(folder), str(Path(__file__).with_name('escape_timer_harness.cpp')), '-o', str(executable)]
        result = subprocess.run(command, capture_output=True, text=True)
        (folder / 'build.log').write_text(result.stdout + result.stderr)
        if result.returncode:
            raise SystemExit(result.stdout + result.stderr)
        result = subprocess.run([str(executable)], env=env, capture_output=True, text=True)
        (folder / 'test.log').write_text(result.stdout + result.stderr)
        print(game, result.stdout.strip(), result.stderr.strip())
        if result.returncode:
            raise SystemExit(result.returncode)
        receipt['passed'] = True
        receipt['checks'] = int(re.search(r'PASS (\d+)', result.stdout)[1])
        receipts.append(receipt)
    (output / 'verification.json').write_text(json.dumps(receipts, indent=2))


if __name__ == '__main__':
    main()
