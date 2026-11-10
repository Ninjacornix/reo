"""Compare bounded native SGL ownership/queries with hash-pinned originals.

Headless tests only. Never opens the game, devices, windows or live memory.
"""
import argparse
import hashlib
import json
import os
import re
import subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
PINS = {
    'build-function-index/owned-overlays/o9.bin': '604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343',
    'game_data/SLUS_207.65': '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
    'build-native-sjuni/audio-asset-inventory/file1-v1/members.json': '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2',
}
ASSETS = {
    'r001.sgl': '73df31bfd576bc6095fe44b6c51f1eb1e6c955c73b25d2ff9d5e4312cb475faf',
    'r002.sgl': '0347121969ec0a76d4baf6d0e5256e874bf5f93eaa95fe6f147187dd4877a64a',
    'r028.sgl': 'e79050973d67a082954357452782bd571e1fd71c87802b8ec4799f8766afbe36',
    'r035.sgl': '64776cadc528f509bde1d864bb1c1684072a8fbdeed3e49940eabbf02e94a468',
    'r041.sgl': '55e3a5e8d1ef8a8a04599736315322323a5facbc995298742c32fedfbb01e17d',
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', choices=COMPILERS, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    for name, digest in PINS.items():
        assert sha(ROOT/name) == digest, name
    overlay = (ROOT/'build-function-index/owned-overlays/o9.bin').read_bytes()
    elf = elf_reader((ROOT/'game_data/SLUS_207.65').read_bytes())
    sources, entries, audits = [], {}, []
    selected = {0x815e30, 0x815e70, 0x8171d0, 0x8171e0, 0x8194d0, 0x8196e0}
    for path in sorted((ROOT/'recomp/config/output_ovl/o9').glob('o9_*.cpp')):
        address = int(path.stem.split('_')[-1], 16)
        if 0x816000 <= address < 0x816460 or address in selected:
            text = path.read_text()
            end = int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)', text)[1], 16)
            relative = path.relative_to(ROOT).as_posix()
            audits.append(compare_source('Complete original SGL access/binding, unfiltered nearest or reverse-action body', relative, address, end, lambda a, n: overlay[a-0x810000:a-0x810000+n]))
            sources.append(relative)
            entries[address] = relative
    name = 'recomp/config/output/sub_00191D10_0x191d10.cpp'
    audits.append(compare_source('Complete distance body; finite audited SDK scalar/SIMD profile', name, 0x191d10, 0x191d80, elf))
    entries[0x191d10] = name
    sources.append(name)
    assert selected.issubset(entries)
    unit = 'game/native/gameplay_navigation/navigation.cpp'
    fixture = 'game/native/gameplay_navigation/navigation_tests.cpp'
    helper = 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    files = [unit, fixture, 'game/native/gameplay_navigation/navigation.hpp', 'game/native/gameplay_navigation/CMakeLists.txt', 'game/native/CMakeLists.txt', helper, Path(__file__).relative_to(ROOT).as_posix(), *sources]
    frozen = {name: (ROOT/name).read_bytes() for name in files}
    out.mkdir(parents=True)
    for name, data in frozen.items():
        path = out/'source'/name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
    (out/'reference.hpp').write_bytes(frozen[helper].replace(b'Register r[32];', b'Register r[32];std::uint64_t hi{},lo{};')+b'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (std::int32_t(a) >> (std::uint32_t(b)&31))\n')
    body = '\n'.join(frozen[name].decode() for name in entries.values())
    (out/'original.cpp').write_text(body)
    actual = {Path(name).stem for name in entries.values()}
    calls = set(re.findall(r'\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
    (out/'functions.h').write_text('#pragma once\n'+''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))+''.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n' for name in sorted(calls-actual)))
    (out/'dispatch.inc').write_text(''.join(f'case {address}:{Path(name).stem}(memory,context,runtime);return;\n' for address, name in entries.items()))
    for name in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
        (out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o9_functions.h', 'ps2_recompiled_functions.h']:
        (out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h']:
        (out/name).write_text('#pragma once\n')
    # Re-read exact owned ISO extents using the pinned inventory. The recorded
    # full ISO digest is historical; only selected members are rehashed here.
    members = json.loads((ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json').read_bytes())
    assert isinstance(members, list)
    asset_evidence = []
    with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as iso:
        for basename, digest in ASSETS.items():
            rows = [row for row in members if basename in row.get('names', [])]
            assert len(rows) == 1
            row = rows[0]
            assert row['sha256'] == digest
            iso.seek(row['iso_offset'])
            data = iso.read(row['bytes'])
            assert hashlib.sha256(data).hexdigest() == digest
            (out/basename).write_bytes(data)
            asset_evidence.append(row)
    (out/'o9.bin').write_bytes(overlay)
    compiler = COMPILERS[args.compiler]
    env = dict(os.environ)
    env['PATH'] = str(compiler.parent)+os.pathsep+env.get('PATH', '')
    exe = out/'navigation.exe'
    command = [str(compiler), '-std=c++20', '-O2', '-msse4.1', '-DREO_NAVIGATION_ORIGINAL=1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-I'+str(out), '-I'+str(out/'source'), str(out/'source'/unit), str(out/'source'/fixture), str(out/'original.cpp'), '-o', str(exe)]
    receipt = dict(schema=1,status='failed',game_launched=False,installed_in_game=False,stage4_complete=False,compiler_sha256=sha(compiler),source_sha256={name: hashlib.sha256(data).hexdigest() for name, data in frozen.items()},original_word_audits=audits,pinned_inputs=PINS,assets=asset_evidence,commands=[],declared_ports=['107C68 bounded zero-fill in original-only test surroundings; real runtime allocator not installed'],limitations=['Native immutable input/query owner only; canonical mutable room-variant, occupancy, visits, dynamic conditions and actual AI/scene consumers remain open.', 'Nearest comparison covers flags0 with finite distance; flags1 segment collision is not admitted. Empty or overflowed distances return unavailable.', 'Malformed reachable neighbor/condition references return unavailable; no adjacent-section emulation or silent asset repair.', 'Original route ordering is preserved; no measured performance fix or game installation is claimed.'])
    try:
        for label, cmd in [('compile', command), ('test', [str(exe), str(out/'o9.bin'), *(str(out/name) for name in ASSETS)])]:
            result = subprocess.run(cmd, capture_output=True, env=env, timeout=240)
            (out/(label+'.stdout.txt')).write_bytes(result.stdout)
            (out/(label+'.stderr.txt')).write_bytes(result.stderr)
            receipt['commands'].append(dict(label=label,command=cmd,exit=result.returncode))
            if result.returncode:
                raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-4000:])
            if label == 'test':
                receipt['observed'] = json.loads(result.stdout)
        receipt['source_unchanged'] = all((ROOT/name).read_bytes() == data for name, data in frozen.items())
        assert receipt['source_unchanged']
        receipt['status'] = 'passed'
    finally:
        receipt['output_sha256'] = {path.relative_to(out).as_posix(): sha(path) for path in out.rglob('*') if path.is_file()}
        (out/'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps(receipt['observed']))


if __name__ == '__main__':
    main()
