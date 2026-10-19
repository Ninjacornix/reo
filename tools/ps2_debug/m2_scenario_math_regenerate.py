"""Recover two original, reached overlay-0 angle helpers omitted from its map.

Reads only the user's ISO. Writes candidates and provenance under build-ninja;
--apply copies exactly the two generated bodies and adds their two declarations
and MWo3-gated entries to register_o0.cpp. Shared headers remain untouched.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from overlay_extract import Iso, decompress, wrap_elf

TARGETS = {
    0x3700C0: '1bfa73c07d63d2615f40f8a3d8a0d48a32ac670aa52e98d703e1c07b7467f863',
    0x370100: '1b9133ad53a9553f9c42b34f6cd612afd6dcfa891d9c1183cce60865235051e6',
}


def update_registrar(path, declarations, registrations, apply):
    original = path.read_bytes()
    newline = b'\r\n' if b'\r\n' in original else b'\n'
    source = original
    missing_declarations, missing_registrations = [], []
    for declaration in declarations:
        encoded = declaration.encode()
        if source.count(encoded) > 1:
            raise RuntimeError('Duplicate angle-helper declaration')
        if encoded not in source:
            missing_declarations.append(encoded)
    for registration in registrations:
        encoded = registration.encode()
        if source.count(encoded) > 1:
            raise RuntimeError('Duplicate angle-helper registration')
        if encoded not in source:
            fn = encoded.rsplit(b', ', 1)[1][:-2]
            pc = encoded.rsplit(b', ', 2)[1]
            if re.search(rb'registerOverlayFunction\([^;\r\n]*'+re.escape(pc)+rb'\s*,', source):
                raise RuntimeError('Conflicting angle-helper registration: '+pc.decode())
            if re.search(rb'registerOverlayFunction\([^;\r\n]*'+re.escape(fn)+rb'\);', source):
                raise RuntimeError('Angle-helper registered at an unexpected address')
            missing_registrations.append(encoded)
    if missing_declarations:
        anchor = b'#include "ps2_runtime.h"'+newline
        if source.count(anchor) != 1:
            raise RuntimeError('Unexpected overlay-0 include anchor')
        source = source.replace(anchor, anchor+newline.join(missing_declarations)+newline, 1)
    if missing_registrations:
        anchor = b'void reoRegisterOverlay_o0(PS2Runtime& runtime) {'+newline
        if source.count(anchor) != 1:
            raise RuntimeError('Unexpected overlay-0 registration anchor')
        source = source.replace(anchor, anchor+newline.join(missing_registrations)+newline, 1)
    if apply and source != original:
        path.write_bytes(source)
    return {'path': str(path), 'missing_declarations': len(missing_declarations),
            'missing_registrations': len(missing_registrations),
            'applied': apply, 'sha256': hashlib.sha256(source).hexdigest()}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--iso', type=Path, default=ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso')
    p.add_argument('--apply', action='store_true')
    p.add_argument('--recompiler', type=Path, default=ROOT / 'third_party/PS2Recomp/out/build/ps2xRecomp/Release/ps2_recomp.exe')
    a = p.parse_args()
    iso = Iso(str(a.iso))
    try:
        directory = next((l, s) for n, l, s, f in iso.listdir(*iso.root()) if n == 'BIN')
        _, sector, size, _ = next(x for x in iso.listdir(*directory) if x[0] == '0.DAT')
        raw = iso.read(sector, size)
        image = decompress(raw) if raw[:2] == b'\x02\x00' else raw
    finally:
        iso.f.close()
    image_hash = hashlib.sha256(image).hexdigest()
    if image_hash != 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2':
        raise RuntimeError('Unexpected original overlay revision')
    ident, base, text, data = struct.unpack_from('<4I', image, 4)
    if (ident, base, text, data) != (1, 0x370000, 0xFD40, 0xD000):
        raise RuntimeError('Unexpected MWo3 layout')
    work = ROOT / 'build-ninja/m2-scenario/math'
    work.mkdir(parents=True, exist_ok=True)
    (work / 'original-o0.bin').write_bytes(image)
    main_elf = (ROOT / 'game_data/SLUS_207.65').read_bytes()
    if hashlib.sha256(main_elf).hexdigest() != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
        raise RuntimeError('Unexpected original main ELF revision')
    phoff = struct.unpack_from('<I', main_elf, 28)[0]
    phnum = struct.unpack_from('<H', main_elf, 44)[0]
    main_report = []
    for filename in ('sub_00192190_0x192190.cpp', 'sub_001921A0_0x1921a0.cpp',
                     'sub_0018F340_0x18f340.cpp', 'sub_0018F470_0x18f470.cpp'):
        source = (ROOT / 'recomp/config/output' / filename).read_text()
        start, end = map(lambda s: int(s, 16), re.search(r'// Address: (0x[\da-fA-F]+) - (0x[\da-fA-F]+)', source).groups())
        for n in range(phnum):
            typ, off, va, _, size, _, _, _ = struct.unpack_from('<8I', main_elf, phoff+n*32)
            if typ == 1 and va <= start and end <= va+size:
                code = main_elf[off+start-va:off+end-va]
                break
        else:
            raise RuntimeError('Main trig function outside original ELF segment')
        actual = {int(pc, 16): int(word, 16) for pc, word in re.findall(r'// (0x[\da-fA-F]+): (0x[\da-fA-F]+)', source)}
        expected = {start+i: struct.unpack_from('<I', code, i)[0] for i in range(0, len(code), 4)}
        if any(expected.get(pc) != word for pc, word in actual.items()) or any(actual.get(pc) != word for pc, word in expected.items() if word) or 'TODO_NAMED' in source:
            raise RuntimeError(f'Original main trig opcode coverage mismatch: {filename}')
        main_report.append({'file':filename,'start':hex(start),'end':hex(end),'sha256':hashlib.sha256(code).hexdigest(),'words':len(expected),'codegen_original_coverage_verified':True})
    registrations, declarations, report = [], [], []
    for start, expected_hash in TARGETS.items():
        end = start + 64
        code = image[start-base:end-base]
        if hashlib.sha256(code).hexdigest() != expected_hash:
            raise RuntimeError(f'Original code hash mismatch at {start:X}')
        run = work / f'{start:x}'
        run.mkdir(exist_ok=True)
        elf = run / 'function.elf'
        elf.write_bytes(wrap_elf(code, start, len(code)))
        name = f'o0_{start:08X}'
        mapping = run / 'function.csv'
        with mapping.open('w', newline='') as f:
            w = csv.writer(f)
            w.writerow(['name', 'start', 'end', 'size'])
            w.writerow([name, hex(start), hex(end), len(code)])
        output = run / 'generated'
        output.mkdir(exist_ok=True)
        config = run / 'function.toml'
        config.write_text('[general]\ninput = "%s"\nghidra_output = "%s"\noutput = "%s/"\n'
                          'single_file_output = false\npatch_syscalls = false\npatch_cop0 = true\npatch_cache = true\n'
                          % (elf.as_posix(), mapping.as_posix(), output.as_posix()))
        result = subprocess.run([str(a.recompiler.resolve()), str(config)], capture_output=True, text=True)
        (run / 'recompiler.log').write_text(result.stdout + result.stderr)
        if result.returncode:
            raise RuntimeError(f'Recompiler failed: {run}/recompiler.log')
        fn = f'{name}_0x{start:x}'
        candidate = output / f'{fn}.cpp'
        source = candidate.read_text()
        actual = {int(pc, 16): int(word, 16) for pc, word in re.findall(r'// (0x[\da-fA-F]+): (0x[\da-fA-F]+)', source)}
        expected = {start+i: struct.unpack_from('<I', code, i)[0] for i in range(0, 64, 4)}
        if any(expected.get(pc) != word for pc, word in actual.items()) or any(actual.get(pc) != word for pc, word in expected.items() if word) or 'TODO_NAMED' in source:
            raise RuntimeError('Generated opcode coverage differs from owned original')
        source = source.replace('#include "ps2_recompiled_functions.h"', '#include "o0_functions.h"')
        candidate.write_text(source)
        declarations.append(f'void {fn}(uint8_t*, R5900Context*, PS2Runtime*);')
        for pc, emitted_fn in re.findall(r'runtime\.registerFunction\((0x[\da-fA-F]+), (\w+)\);', (output / 'register_functions.cpp').read_text()):
            if emitted_fn == fn and start <= int(pc, 16) < end:
                registrations.append(f'    runtime.registerOverlayFunction(0x370000u, 0x336F574Du, 4u, 1u, {pc}u, {fn});')
        if a.apply:
            (ROOT / 'recomp/config/output_ovl/o0' / candidate.name).write_text(source)
        report.append({'start':hex(start),'end':hex(end),'code_sha256':expected_hash,'original_words':16,'emitted_nonzero_words':len(actual),'candidate':str(candidate),'applied':a.apply})
    (work / 'registrar.inc').write_text('\n'.join(declarations) + '\n\n' + '\n'.join(registrations) + '\n')
    registrar_report = update_registrar(ROOT / 'recomp/config/output_ovl/o0/register_o0.cpp',
                                        declarations, registrations, a.apply)
    (work / 'report.json').write_text(json.dumps({'overlay_sha256':image_hash,'functions':report,
                                               'actual_main_trig':main_report,
                                               'overlay_registrar':registrar_report}, indent=2))
    print(json.dumps(report, indent=2))
    print('Coordinator declarations/entry/resume registrations:', work / 'registrar.inc')
    print('Original overlay-0 registrar:', json.dumps(registrar_report))


if __name__ == '__main__':
    main()
