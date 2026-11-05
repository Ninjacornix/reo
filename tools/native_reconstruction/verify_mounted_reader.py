#!/usr/bin/env python3
"""Verify synchronous mounted exact reads using private synthetic fixtures only.

The existing fixture writer supplies manifests/plans/synthetic archives. Owned
ELF bytes are copied only as data for unchanged identity checks, never executed.
No PS2 runtime, game, original ISO/archive or live target is built/launched.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import uuid

from verify_mounted_resources import prepare, ELF_HASH

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', help='Windows C++20 compiler; optional in prebuilt mode')
    parser.add_argument('--executable', type=Path, help='Existing mounted_reader_tests.exe; skip compilation')
    parser.add_argument('--output', type=Path, help='Ignored private directory named mounted-reader-checks')
    args = parser.parse_args()
    compiler = shutil.which(args.cxx or 'g++') if (args.cxx or not args.executable) else None
    if compiler is None and (args.cxx or not args.executable):
        parser.error('Pass an installed Windows C++20 compiler')
    supplied = args.executable.resolve() if args.executable else None
    if supplied and (not supplied.is_file() or supplied.name.lower() != 'mounted_reader_tests.exe'):
        parser.error('--executable must be an existing mounted_reader_tests.exe')
    output = (args.output or ROOT / 'build-native-sjuni/mounted-reader-checks').resolve()
    if output.name != 'mounted-reader-checks' or not any(output.is_relative_to((ROOT / p).resolve())
            for p in ('build-native-sjuni', 'build-function-index')):
        parser.error('--output must be named mounted-reader-checks beneath an ignored repository build root')
    owned = ROOT / 'game_data/SLUS_207.65'
    if sha(owned) != ELF_HASH:
        raise ValueError('Owned ELF identity fixture mismatch')
    output.mkdir(parents=True, exist_ok=True)
    token = uuid.uuid4().hex
    fixture = output / ('synthetic-' + token)
    fixture.mkdir()
    (fixture / '.mounted-reader-fixture').write_text(token, encoding='ascii')
    scenarios = ('coverage', 'failures', 'overlay', 'concurrent', 'lifetime', 'construction')
    for scenario in scenarios:
        folder = fixture / scenario
        prepare(folder, 'pak-v1', owned)
        aligned = folder / 'data/aligned.bin'
        aligned.write_bytes(bytes((i * 23 + i // 13) % 256 for i in range(8192)))
        manifest_path = folder / 'import.json'
        manifest = json.loads(manifest_path.read_text(encoding='utf-8-sig'))
        manifest['Files'].append(dict(Name='aligned.bin', Length=8192, Sha256=sha(aligned)))
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding='utf-8')
    cpp = [
        'game/native/resources_windows/mounted_reader.cpp',
        'game/native/resources_windows/mounted_resources.cpp',
        'game/native/resources_windows/import_manifest.cpp',
        'game/native/resources_windows/pinned_file.cpp',
        'game/native/resources/resource_session.cpp',
        'game/native/resources/virtual_file_view.cpp',
        'game/native/resources_windows/mounted_reader_tests.cpp',
    ]
    sources = [*map(lambda p: ROOT / p, cpp), *(ROOT / 'game/native/resources_windows').glob('*.hpp'),
               ROOT / 'game/native/resources/resource_session.hpp', ROOT / 'game/native/resources/virtual_file_view.hpp',
               ROOT / 'game/native/resources/byte_view.hpp', ROOT / 'runtime/assets/virtual_afs.h',
               ROOT / 'runtime/assets/overlay.h', ROOT / 'recomp/overrides/native_geometry/reo_vu_native_sha256.h',
               ROOT / 'tools/native_reconstruction/verify_mounted_resources.py',
               ROOT / 'game/native/resources_windows/README_READER.md', Path(__file__)]
    receipt = dict(schema=1, status='running', game_launched=False, runtime_library_linked=False,
                   build_mode='prebuilt' if supplied else 'source',
                   compiler=compiler, compiler_sha256=sha(Path(compiler)) if compiler else None,
                   compiler_version=subprocess.check_output([compiler, '--version'], text=True).splitlines()[0] if compiler else None,
                   owned_elf_sha256=ELF_HASH, owned_elf_role='Copied identity data only; no instructions executed',
                   source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in sources}, checks=[])
    environment = dict(os.environ)
    if compiler:
        environment['PATH'] = str(Path(compiler).parent) + os.pathsep + environment.get('PATH', '')

    def run(command, name):
        result = subprocess.run(command, cwd=ROOT, env=environment, capture_output=True, text=True, timeout=60)
        receipt['checks'].append(dict(name=name, exit_code=result.returncode, command=[str(x) for x in command],
                                      stdout=result.stdout, stderr=result.stderr))
        if result.returncode:
            raise RuntimeError(name + ' failed:\n' + result.stdout + result.stderr)
        print(name + ': passed', flush=True)

    try:
        executable = supplied or output / 'mounted_reader_tests.exe'
        if not supplied:
            run([compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-O1', '-pthread',
                 '-I.', *cpp, '-lruntimeobject', '-lole32', '-lbcrypt', '-static-libgcc', '-static-libstdc++',
                 '-o', str(executable)], 'host_reader_build')
        receipt['executable'] = str(executable)
        receipt['executable_sha256'] = sha(executable)
        for scenario in scenarios:
            run([str(executable), str(fixture / scenario), token, scenario], scenario)
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = [
            'Only exact full sectors wholly inside one admitted file and within configured read budget are native-covered.',
            'No legacy fallback execution, PS2/RPC/guest destination or game integration is tested.',
            'ReadFile faults/short reads/blocking and allocation failure are injected only in the isolated test executable.',
            'The normal PinnedFile writable-mapping and mount namespace/local-manifest assumptions remain.',
        ]
        if supplied:
            receipt['limitations'].append('Prebuilt mode records current source snapshot without proving binary build provenance; retain CMake/build evidence separately.')
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Receipt: ' + str(output / 'receipt.json'))


if __name__ == '__main__':
    main()
