"""Compare complete owned selector/restore bodies with the typed native consumer."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from audit_retail_effect_descriptors import compare_source

ROOT = Path(__file__).resolve().parents[2]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    image = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert sha(image) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    overlay = image.read_bytes()
    read = lambda at, size: overlay[at-0x570000:at-0x570000+size]
    profile_path = ROOT / 'build-native-sjuni/secondary-pose-link-profile-v1/receipt.json'
    profile = json.loads(profile_path.read_bytes())
    assert profile['status'] == 'static_owned_secondary_link_profile' and sha(ROOT / profile['generated']) == profile['output_sha256']
    for path, digest in profile['source_sha256'].items():
        assert sha(ROOT / path) == digest
    original, proof = [], []
    for at in [0x61a6a0, 0x61b1a0]:
        path = next((ROOT / 'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'))
        start, end = [int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', path.read_text()).groups()]
        proof.append(compare_source('complete secondary link consumer', path.relative_to(ROOT).as_posix(), start, end, read))
        original.append(path.relative_to(ROOT).as_posix())
    units = ['game/native/' + name for name in ['gameplay_world/secondary_pose_links.cpp', 'animation/model.cpp', 'animation/model_math.cpp', 'animation/curves.cpp', 'transform_math/transform_math.cpp']]
    native, pending = set(units), list(units)
    while pending:
        path = pending.pop()
        for rel in re.findall(r'^#include "([^"]+)"', (ROOT / path).read_text(), re.M):
            dep = ((ROOT / path).parent / rel).resolve()
            assert dep.is_file() and dep.is_relative_to(ROOT / 'game/native'), (path, rel)
            key = dep.relative_to(ROOT).as_posix()
            if key not in native:
                native.add(key)
                pending.append(key)
    helpers = ['tools/native_reconstruction/verify_secondary_pose_links.py', 'tools/native_reconstruction/secondary_pose_links_tests.cpp', 'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp']
    files = sorted(native) + helpers + original
    before = {path: sha(ROOT / path) for path in files}
    out.mkdir()
    record = dict(schema=1, status='failed', game_run=False, installed_in_game=False, stage4_complete=False, source_sha256=before,
                  compiler_sha256=sha(args.compiler), original_owned_bodies=proof, profile=dict(path=str(profile_path), sha256=sha(profile_path)),
                  declared_ports=['Selector-only cases observe61B1A0 dispatch without patching a nonexistent model; actual model cases execute both full original bodies.',
                                  'Original model inputs project the already-qualified native importer links from actual owned skeletons. Original packing is not newly executed here.',
                                  'Category1 profile2 uses controlled HP07 binding; profile3 uses actual HN54/HN88 and constructor category/variant/class inputs. No complete scene assignment or traversal is claimed.'])
    try:
        for path in files:
            target = out / 'source' / path
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes((ROOT / path).read_bytes())
        reference = (ROOT / helpers[2]).read_text() + '\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
        (out / 'reference.hpp').write_text(reference)
        (out / 'functions.h').write_text('#pragma once\n' + ''.join('void ' + Path(path).stem + '(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for path in original))
        for path in ['ps2_runtime.h', 'ps2_runtime_macros.h']:
            (out / path).write_text('#pragma once\n#include "reference.hpp"\n')
        (out / 'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
        for path in ['ps2_recompiled_stubs.h', 'ps2_stubs.h', 'ps2_syscalls.h']:
            (out / path).write_text('#pragma once\n')
        (out / 'original.cpp').write_text('\n'.join((ROOT / path).read_text() for path in original))
        constants = 'inline void owned_constants(std::uint8_t* p){\n'
        for at, size in [(0x70f298, 8), (0x70f2a0, 8), (0x70f2b0, 224), (0x70f390, 224), (0x70f628, 56)]:
            constants += '{const std::uint8_t b[]{' + ','.join(map(str, read(at, size))) + '};std::memcpy(p+' + str(at) + ',b,sizeof b);}\n'
        (out / 'owned_constants.hpp').write_text(constants + '}\n')
        inventory = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
        assert sha(inventory) == '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
        members = {row['member']: row for row in json.loads(inventory.read_bytes())}
        raw_skeletons, assets = [], []
        with (ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
            for member in [507, 490, 274, 319]:
                item = members[f'NETBIO00.DAT/0/{member}']
                stream.seek(item['iso_offset'])
                payload = stream.read(item['bytes'])
                assert hashlib.sha256(payload).hexdigest() == item['sha256']
                at, size = struct.unpack_from('<II', payload, 0x24)
                assert at and size and size <= len(payload)-at
                raw_skeletons.append(payload[at:at+size])
                assets.append(item)
        record['owned_assets'] = assets
        (out / 'owned_skeletons.bin').write_bytes(struct.pack('<I', len(raw_skeletons)) + b''.join(struct.pack('<I', len(raw)) + raw for raw in raw_skeletons))
        env = dict(os.environ)
        env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
        binary = out / 'checks.exe'
        command = [str(args.compiler), '-std=c++20', '-O2', '-msse4.1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-Wno-unused-label', '-Wno-unused-parameter', '-fno-fast-math', '-ffp-contract=off', '-I'+str(out), '-I'+str(out / 'source'), *[str(out / 'source' / path) for path in units], str(out / 'original.cpp'), str(out / 'source' / helpers[1]), '-o', str(binary)]
        record['command'] = command
        result = subprocess.run(command, env=env, capture_output=True, text=True, timeout=180)
        (out / 'compile.txt').write_text(result.stdout + result.stderr)
        assert result.returncode == 0, 'compile failed'
        result = subprocess.run([str(binary), str(out / 'owned_skeletons.bin')], env=env, capture_output=True, text=True, timeout=120)
        (out / 'run.txt').write_text(result.stdout + result.stderr)
        assert result.returncode == 0, 'comparison failed'
        record.update(status='passed', observed=json.loads(result.stdout), binary_sha256=sha(binary), source_unchanged=all(sha(ROOT / path) == digest for path, digest in before.items()))
        assert record['source_unchanged']
    finally:
        record['output_sha256'] = {p.relative_to(out).as_posix(): sha(p) for p in out.rglob('*') if p.is_file() and p.name != 'receipt.json'}
        (out / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(dict(status=record['status'], observed=record['observed'])))


if __name__ == '__main__':
    main()
