"""Complete original1D2CB0 static-room skeleton/model-pose producer comparison."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
from audit_retail_effect_descriptors import compare_source, elf_reader
from verify_gameplay_collision import COMPILERS

ROOT = Path(__file__).resolve().parents[2]
EXTERNAL = {0x18dc50,0x18dc90,0x18dca0,0x1aa4c0,0x1cd1c0,0x1b2a70,0x1ce110}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', choices=COMPILERS, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    out.mkdir()
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(elf.read_bytes())
    pending, entries = [0x1d2cb0,0x1a31b0,0x1d0a70], {}
    while pending:
        at = pending.pop()
        if at in entries or at in EXTERNAL:
            continue
        found = list((ROOT / 'recomp/config/output').glob(f'sub_{at:08X}_*'))
        if not found:
            continue  # Internal labels share their containing complete body.
        source = found[0]
        entries[at] = source
        pending.extend(int(value, 16) for value in re.findall(
            r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)', source.read_text()))
    overlay_path=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(overlay_path)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    overlay=overlay_path.read_bytes()
    for at in [0x5ebe30,0x5d7d60]:
        entries[at]=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'))
    entries[0x1cdfe0]=next((ROOT/'recomp/config/output').glob('sub_001CDFE0_*'))
    cold_source=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_005EAEB0_*'))
    audits = []
    for source in entries.values():
        start, end = [int(value, 16) for value in re.search(
            r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', source.read_text()).groups()]
        audits.append(compare_source('complete static-room model producer/import/math body',
            source.relative_to(ROOT).as_posix(), start, end, read if start<0x570000 else lambda at,n:overlay[at-0x570000:at-0x570000+n]))
    native = [ROOT / name for name in [
        'game/native/gameplay_scenario/room_model_assets.cpp',
        'game/native/gameplay_world/model_parts.cpp',
        'game/native/gameplay_application/room_models.cpp',
        'game/native/gameplay_scenario/scene_models.cpp','game/native/gameplay_scenario/content.cpp',
        'game/native/animation/model.cpp', 'game/native/animation/model_math.cpp',
        'game/native/animation/curves.cpp', 'game/native/transform_math/transform_math.cpp']]
    reference = ROOT / 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    conversion = ROOT / 'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'
    fixture = ROOT / 'tools/native_reconstruction/room_model_assets_tests.cpp'
    closure = set(native + list(entries.values()) + [cold_source,reference,conversion,fixture,Path(__file__).resolve()])
    pending = list(closure)
    while pending:
        path = pending.pop()
        for name in re.findall(r'#\s*include\s*"([^"]+)"', path.read_text()):
            candidate = next((p.resolve() for p in [path.parent / name, ROOT / name] if p.is_file()), None)
            if candidate and candidate.is_relative_to(ROOT) and candidate not in closure:
                closure.add(candidate)
                pending.append(candidate)
    before = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(closure)}
    for name in before:
        target = out / 'source' / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes((ROOT / name).read_bytes())
    (out / 'tests.cpp').write_bytes(fixture.read_bytes())
    macros = '\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n'
    macros += '\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n'
    (out / 'ps2_fpu_convert.h').write_bytes(conversion.read_bytes())
    (out / 'reference.hpp').write_text(reference.read_text().replace(
        'pc{},branch_pc{},fcr31{}', 'pc{},branch_pc{},fcr31{},vu0_vpu_stat{}') + macros)
    body = '\n'.join(source.read_text() for source in entries.values())
    (out / 'original_models.cpp').write_text(body)
    actual = {source.stem for source in entries.values()}
    names = set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
    declaration = ''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))
    declaration += ''.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n' for name in sorted(names - actual))
    (out / 'functions.h').write_text('#pragma once\n' + declaration)
    (out / 'original_dispatch.hpp').write_text(''.join(
        f'case {hex(at)}:{source.stem}(memory,context,runtime);return;\n' for at, source in sorted(entries.items())))
    for name in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
        (out / name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o2_functions.h', 'ps2_recompiled_functions.h']:
        (out / name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h']:
        (out / name).write_text('#pragma once\n')
    constants = 'inline void owned_constants(std::uint8_t* p){\n'
    for at, size in [(0x22fe20, 32), (0x241c78, 40), (0x241e90, 4)]:
        raw = read(at, size)
        constants += '{const std::uint8_t b[]{' + ','.join(str(v) for v in raw) + f'}};std::memcpy(p+{at},b,sizeof b);}}\n'
    (out / 'owned_constants.hpp').write_text(constants + '}\n')
    inventory = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory) == '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    rows = json.loads(inventory.read_bytes())
    assets = []
    with (ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
        for name in ['r0417300.nbd', 'r0010100.nbd', 'r0023200.nbd']:
            row = next(row for row in rows if name in row['names'])
            stream.seek(row['iso_offset'])
            data = stream.read(row['bytes'])
            assert hashlib.sha256(data).hexdigest() == row['sha256']
            (out / name).write_bytes(data)
            assets.append(dict(name=name, **row))
    manifest = out / 'models.txt'
    manifest.write_text('\n'.join(str(out / row['name']) for row in assets) + '\n')
    compiler = COMPILERS[args.compiler]
    env = dict(os.environ, PATH=str(compiler.parent) + os.pathsep + os.environ.get('PATH', ''))
    command = [str(compiler), '-std=c++20', '-O2', '-msse4.1', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
        '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off',
        '-I' + str(out), '-I' + str(out / 'source'),
        *[str(out / 'source' / p.relative_to(ROOT)) for p in native], str(out / 'tests.cpp'), '-o', str(out / 'checks.exe')]
    receipt = dict(schema='reo.native.room_model_assets.v1', status='failed', source_sha256=before,
        compiler_sha256=sha(compiler), original_word_audits=audits, owned_assets=assets,
        external_ports=['18DC50 bounded SDK packed-data allocation','18DCA0 live allocation lookup','18DC90 allocation release',
            '107C68 standard memset projection','5BE980 camera reset outside the pose/style projection',
            '1B1820 renderer context retirement','1CD080 renderer resource interval retirement','18DCB0 cooperative I/O yield',
            '1D1F50 textures','1D0C80 shadow resources','1D25A0 wall/floor consumer separately qualified by SessionRooms',
            '1CD1C0 renderer resource selection','1B2A70 bounded128/type6 renderer slot allocation',
            '1CE110 rendering/archive boundary invoking complete original1A31B0+1CDFE0+1D2CB0 on the owned bytes'],
        limitations=['The asset producer executes complete1D2CB0 and its raw skeleton/model/math dependency bodies.',
            'Persistent banks compare all128 current/saved poses, styles, visibility and24 group records through complete5EBE30/1D0A70 defined normal-mode callers, with the listed renderer/I/O boundaries.',
            'Complete5D7D60 executes but comparison/adoption is only its pose/style subproducer; its other reset side effects remain separate native owners.',
            'Cold initialization projects the actual5EAEB0 clear andFF-cache calls; whole original application bootstrap is not executed here.',
            'The alternate1AA4C0 cache-miss branch remains an explicit undeclared call in this oracle; this is not an original full renderer/model-loader or installed game proof.'],
        game_launched=False, installed_in_game=False, stage4_complete=False)
    cold_start,cold_end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',cold_source.read_text()).groups()]
    receipt['cold_source_audit']=compare_source('source cold bank/cache producer call contracts',cold_source.relative_to(ROOT).as_posix(),cold_start,cold_end,lambda at,n:overlay[at-0x570000:at-0x570000+n])
    try:
        for label, cmd in [('compile', command), ('run', [str(out / 'checks.exe'), str(manifest)])]:
            result = subprocess.run(cmd, capture_output=True, text=True, env=env, timeout=240)
            (out / (label + '.txt')).write_text(result.stdout + result.stderr)
            assert result.returncode == 0, label + ': ' + (result.stdout + result.stderr)[-3000:]
            if label == 'run':
                receipt['observed'] = json.loads(result.stdout)
        receipt['source_unchanged'] = all(sha(ROOT / name) == digest for name, digest in before.items())
        assert receipt['source_unchanged']
        receipt['status'] = 'passed'
    finally:
        receipt['output_sha256'] = {p.relative_to(out).as_posix(): sha(p) for p in out.rglob('*') if p.is_file() and p.name != 'receipt.json'}
        (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(receipt['observed']))


if __name__ == '__main__':
    main()
