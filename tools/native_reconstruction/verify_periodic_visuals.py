"""Compare native periodic visuals with complete owned creation/update bodies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
from audit_retail_effect_descriptors import compare_source, elf_reader
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--compiler', type=Path, required=True)
    p.add_argument('--corpus', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    corpus = args.corpus.resolve()
    cr = json.loads((corpus / 'receipt.json').read_bytes())
    assert len(cr['assets']) == 12 and sha(corpus / 'owned_effect_geometry.bin') == cr['package_sha256']
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    main_read = elf_reader(elf.read_bytes())
    overlay = {}
    for bank, digest in [('o0', 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'), ('o2', '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
        path = ROOT / 'build-function-index/owned-overlays' / (bank + '.bin')
        assert sha(path) == digest
        overlay[bank] = path.read_bytes()
    pending = [0x1d3350, 0x1a31b0, 0x1a34b0, 0x1a3500, 0x6525d0, 0x6535c0, 0x651850, 0x652ce0, 0x5d9680]
    ports = [0x107c68, 0x18dc50, 0x18dca0, 0x18dc90, 0x1b10c0, 0x1b1110, 0x1b3830, 0x573740]
    entries = {}
    while pending:
        at = pending.pop()
        if at in entries or at in ports:
            continue
        bank = 'o2' if at >= 0x570000 else 'o0' if at >= 0x370000 else None
        folder = ROOT / ('recomp/config/output_ovl/' + bank if bank else 'recomp/config/output')
        matches = list(folder.glob(f'{bank or "sub"}_{at:08X}_*'))
        if not matches:
            continue
        name = matches[0].relative_to(ROOT).as_posix()
        entries[at] = name
        pending.extend(int(v, 16) for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)', matches[0].read_text()))
    originals = list(entries.values())
    proof = []
    for at, name in entries.items():
        begin, end = [int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', (ROOT / name).read_text()).groups()]
        reader = main_read if at < 0x370000 else (lambda a, n: overlay['o0'][a - 0x370000:a - 0x370000 + n]) if at < 0x570000 else lambda a, n: overlay['o2'][a - 0x570000:a - 0x570000 + n]
        proof.append(compare_source('complete periodic visual factory, pools, update, resource sampling or camera helper', name, begin, end, reader))
    units = ['game/native/gameplay_effects/' + n + '.cpp' for n in ['periodic_visuals', 'geometry', 'tracks']]
    units += ['game/native/animation/' + n + '.cpp' for n in ['model', 'model_math', 'curves']]
    units += ['game/native/transform_math/transform_math.cpp', 'game/native/gameplay_actors/entity.cpp']
    units += ['game/native/gameplay_scenario/' + n + '.cpp' for n in ['periodic_effects', 'scene_controls', 'flags', 'fog']]
    units += ['game/native/gameplay_session/session.cpp', 'game/native/gameplay_tasks/tasks.cpp']
    files = list(units)
    frozen = {}
    for name in files:
        body = (ROOT / name).read_bytes()
        frozen[name] = body
        for include in re.findall(r'^\s*#include "([^"]+)"', body.decode(), re.M):
            local = ((ROOT / name).parent / include).resolve()
            target = local if local.is_file() else (ROOT / include).resolve()
            assert target.is_relative_to(ROOT / 'game/native') and target.is_file(), (name, include)
            relative = target.relative_to(ROOT).as_posix()
            if relative not in files:
                files.append(relative)
    fixture = 'tools/native_reconstruction/periodic_visuals_tests.cpp'
    helper = 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    for name in originals + [fixture, helper, Path(__file__).relative_to(ROOT).as_posix()]:
        frozen[name] = (ROOT / name).read_bytes()
    out.mkdir(parents=True)
    record = dict(schema=1, status='failed', game_run=False, installed_in_game=False, stage4_complete=False,
                  selected_visual_family='variant0 logical36/37/38, flags1A193, null parent, complete6535C0 callback',
                  physical_ps2_exceptional_parity=False, opcode131_installed=False,
                  source_sha256={n: hashlib.sha256(b).hexdigest() for n, b in frozen.items()},
                  compiler_sha256=sha(args.compiler), original_owned_bodies=proof,
                  corpus=dict(path=str(corpus / 'receipt.json'), sha256=sha(corpus / 'receipt.json')),
                  declared_ports=['107C68 bounded memset;18DC50/18DCA0/18DC90 private resource allocation/lookup/release',
                                  '1B10C0/1B1110 resource-cache bookkeeping',
                                  '1B3830 debug-overfree diagnostic remains unadmitted and throws if reached',
                                  '573740 task retirement is a declared independently qualified native scheduler seam'],
                  native_modernization=['Immutable native frame/resource leases replace work pointers in renderer handoff.',
                                        'Unused fourth stack rotation halfword is not an invented native angle.',
                                        'New native ownership clears all256 piece states; original reset clears only168 active bytes; fresh zeroed source-pool profile compared.'])
    try:
        for name, body in frozen.items():
            target = out / 'source' / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(body)
        (out / 'tests.cpp').write_bytes(frozen[fixture])
        reference = frozen[helper].decode().replace('pc{},branch_pc{},fcr31{}', 'pc{},branch_pc{},fcr31{},vu0_vpu_stat{}')
        reference = reference.replace('Register r[32];', 'Register r[32];std::uint64_t lo{},hi{};')
        reference += '\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (static_cast<std::int32_t>(a) >> (static_cast<std::uint32_t>(b)&31))\n#define FPU_CVT_W_S(a) static_cast<std::int32_t>(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n'
        (out / 'reference.hpp').write_text(reference)
        body = '\n'.join(frozen[n].decode() for n in originals)
        (out / 'original_visuals.cpp').write_text(body)
        actual = {Path(n).stem for n in originals}
        names = set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram', body))
        decl = ''.join('void ' + n + '(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(actual))
        decl += ''.join('inline void ' + n + '(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(names - actual))
        (out / 'functions.h').write_text('#pragma once\n' + decl)
        (out / 'original_dispatch.hpp').write_text(''.join('case ' + hex(at) + ':' + Path(n).stem + '(memory,context,runtime);return;\n' for at, n in sorted(entries.items())))
        for name in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
            (out / name).write_text('#pragma once\n#include "reference.hpp"\n')
        for name in ['o0_functions.h', 'o2_functions.h', 'ps2_recompiled_functions.h']:
            (out / name).write_text('#pragma once\n#include "functions.h"\n')
        for name in ['ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h']:
            (out / name).write_text('#pragma once\n')
        raw = overlay['o2'][0x73e110 - 0x570000:0x73e110 - 0x570000 + 36]
        record['owned_transform_switch_table'] = dict(address='0x73e110', bytes=raw.hex())
        (out / 'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* memory){const std::uint8_t bytes[]{' + ','.join(str(v) for v in raw) + '};std::memcpy(memory+0x73e110,bytes,sizeof bytes);}\n')
        (out / 'owned_effect_geometry.bin').write_bytes((corpus / 'owned_effect_geometry.bin').read_bytes())
        env = dict(os.environ)
        env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        binary = out / 'checks.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-msse4.1', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-I' + str(out), '-I' + str(out / 'source')]
        command += [str(out / 'source' / name) for name in units] + [str(out / 'tests.cpp'), '-o', str(binary)]
        record['command'] = command
        for label, cmd in [('compile', command), ('run', [str(binary), str(out / 'owned_effect_geometry.bin')])]:
            result = subprocess.run(cmd, env=env, capture_output=True, timeout=180)
            (out / (label + '.stdout.txt')).write_bytes(result.stdout)
            (out / (label + '.stderr.txt')).write_bytes(result.stderr)
            assert result.returncode == 0, label + ' failed; see retained logs'
            if label == 'run':
                record['observed'] = json.loads(result.stdout)
        record['source_unchanged'] = all((ROOT / n).read_bytes() == b for n, b in frozen.items())
        assert record['source_unchanged']
        record.update(status='passed', binary_sha256=sha(binary))
    finally:
        record['output_sha256'] = {p.relative_to(out).as_posix(): sha(p) for p in out.rglob('*') if p.is_file() and p.name != 'receipt.json'}
        (out / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(record['observed']))


if __name__ == '__main__':
    main()
