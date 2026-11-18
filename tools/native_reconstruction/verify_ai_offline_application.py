"""Focused shipping-LLVM application comparison against three owned bodies.

Uses an already-built coherent application graph, with every linked archive and
native source identity captured before and checked after the comparison. The
reference register/runtime environment is test-only; production uses the
actual SessionActorServices instance and canonical session/resource graph.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import time

from audit_retail_effect_descriptors import compare_source
from generate_ai_offline_frame_policy import generated
from verify_ai_observation_frame import prepare_reference, REFERENCE, CONVERSION

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = 'tools/native_reconstruction/ai_offline_frame_application_tests.cpp'
EXPECTED_COMPILER = 'f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
IMAGES = {
    'o9': (0x810000, '604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343'),
    'o2': (0x570000, '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'),
}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def file_digest(path):
    value = hashlib.sha256()
    with Path(path).open('rb') as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b''):
            value.update(chunk)
    return value.hexdigest()


def source_hashes():
    root = ROOT / 'game/native'
    return {p.relative_to(ROOT).as_posix(): digest(p.read_bytes()) for p in sorted(root.rglob('*'))
            if p.is_file() and (p.suffix in ('.cpp', '.hpp', '.h', '.inc') or p.name == 'CMakeLists.txt')}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--build', type=Path, default=ROOT / 'build-native-sjuni/gameplay-native-llvm-v1')
    parser.add_argument('--inputs-receipt', type=Path, default=ROOT / 'build-native-sjuni/stage4-orchestration/frame-control-llvm-v2/receipt.json')
    args = parser.parse_args()
    out, build = args.output.resolve(), args.build.resolve()
    if out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni'):
        raise ValueError('Use a new evidence directory below build-native-sjuni')
    compiler = Path(os.environ.get('LOCALAPPDATA', '')) / 'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
    if digest(compiler.read_bytes()) != EXPECTED_COMPILER:
        raise ValueError('Shipping LLVM compiler identity mismatch')
    if (ROOT / 'game/native/gameplay_application/ai_offline_frame_policy.inc').read_text() != generated():
        raise ValueError('Offline policy differs from pinned overlay extraction')
    images, entries, audits = {}, {}, []
    for bank, addresses in [('o9', (0x8122b0,)), ('o2', (0x5f6ee0, 0x5f6fb0))]:
        base, expected = IMAGES[bank]
        path = ROOT / 'build-function-index/owned-overlays' / (bank + '.bin')
        data = path.read_bytes()
        if digest(data) != expected:
            raise ValueError('Owned overlay identity mismatch: ' + bank)
        images[bank] = (path, data)
        for address in addresses:
            source = next((ROOT / 'recomp/config/output_ovl' / bank).glob(f'*_{address:08X}_0x{address:x}.cpp'))
            end = int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)', source.read_text())[1], 16)
            name = source.relative_to(ROOT).as_posix()
            entries[address] = name
            audits.append(compare_source('Complete offline frame body', name, address, end,
                                         lambda at, size, image=data, origin=base: image[at-origin:at-origin+size]))
    frozen = {name: (ROOT / name).read_bytes() for name in [REFERENCE, CONVERSION, FIXTURE, *entries.values()]}
    oracle_files = [*frozen, Path(__file__).relative_to(ROOT).as_posix(),
                    'tools/native_reconstruction/generate_ai_offline_frame_policy.py',
                    'tools/native_reconstruction/verify_ai_observation_frame.py']
    oracle_hashes = {name:digest((ROOT/name).read_bytes()) for name in oracle_files}
    before = source_hashes()
    ninja = (build / 'build.ninja').read_text().splitlines()
    at = next(i for i, line in enumerate(ninja) if line.startswith('build gameplay_application/session_resources_tests.exe:'))
    libraries = next(line.split('=', 1)[1].split() for line in ninja[at+1:at+8] if line.lstrip().startswith('LINK_LIBRARIES ='))
    archives = [build / name for name in libraries if name.endswith('.a')]
    identities = {p.relative_to(build).as_posix(): digest(p.read_bytes()) for p in archives}
    receipt = json.loads(args.inputs_receipt.read_text())
    command = next(item['command'] for item in receipt['commands'] if item.get('label') == 'session-resources')
    inputs = [str((ROOT / value).resolve()) if not Path(value).is_absolute() else value for value in command[1:4]]
    out.mkdir(parents=True)
    prepare_reference(out, entries, frozen)
    fixture = out / 'fixture.cpp';fixture.write_bytes(frozen[FIXTURE])
    exe = out / 'offline_frame_oracle.exe'
    flags = ['-std=c++20', '-O2', '-msse4.1', '-fno-fast-math', '-ffp-contract=off', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
             '-Wno-unused-parameter', '-Wno-unused-label', '-Wno-unused-variable', '-I'+str(out), '-I'+str(ROOT)]
    compile_command = [str(compiler), *flags, str(fixture), '-o', str(exe), *libraries]
    env = dict(os.environ);env['PATH'] = str(compiler.parent) + os.pathsep + env.get('PATH', '')
    started = time.monotonic()
    compiled = subprocess.run(compile_command, cwd=build, env=env, capture_output=True, text=True)
    (out/'compile.stdout.txt').write_text(compiled.stdout);(out/'compile.stderr.txt').write_text(compiled.stderr)
    result = {'status':'failed', 'compiler_sha256':EXPECTED_COMPILER, 'game_run':False, 'stage4_complete':False,
              'source_sha256':before, 'archives_sha256':identities, 'original_word_audits':audits,
              'oracle_sources_sha256':oracle_hashes, 'input_sha256':{name:file_digest(name) for name in inputs},
              'compile_command':compile_command, 'compile_seconds':time.monotonic()-started, 'compile_returncode':compiled.returncode}
    if compiled.returncode == 0:
        started = time.monotonic()
        run_command = [str(exe), *inputs, str(images['o9'][0]), str(images['o2'][0])]
        run = subprocess.run(run_command, cwd=ROOT, env=env, capture_output=True, text=True)
        (out/'test.stdout.txt').write_text(run.stdout);(out/'test.stderr.txt').write_text(run.stderr)
        result.update(test_command=run_command, test_seconds=time.monotonic()-started, test_returncode=run.returncode)
        result['executable_sha256'] = digest(exe.read_bytes())
        if run.returncode == 0:
            result['result'] = json.loads(run.stdout)
    after = source_hashes()
    result['source_drift'] = [name for name in sorted(set(before)|set(after)) if before.get(name) != after.get(name)]
    result['archive_drift'] = [name for name, old in identities.items() if digest((build/name).read_bytes()) != old]
    result['oracle_source_drift'] = [name for name, old in oracle_hashes.items() if digest((ROOT/name).read_bytes()) != old]
    if compiled.returncode == 0 and result.get('test_returncode') == 0 and not result['source_drift'] and not result['archive_drift'] and not result['oracle_source_drift']:
        result['status'] = 'passed'
    (out/'receipt.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps({k:result.get(k) for k in ('status','compile_returncode','test_returncode','source_drift','archive_drift','result')}))
    if result['status'] != 'passed':
        raise SystemExit(1)


if __name__ == '__main__':
    main()
