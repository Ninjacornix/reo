#!/usr/bin/env python3
"""Isolated synchronous payload adapter checks; no game/device/mount execution.

Only three identity intervals are read from the pinned owned ELF. Reader, facade,
runtime scheduling and file mounting are mocked. Optional real-header mode emits
an adapter object only; it never links or executes a game/runtime library.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[4]
TESTS = Path(__file__).resolve().parent


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--elf', type=Path, default=ROOT / 'game_data/SLUS_207.65')
    parser.add_argument('--runtime-headers', type=Path)
    args = parser.parse_args()
    compiler = shutil.which(args.cxx)
    if not compiler:
        parser.error('Pass an installed C++20 GCC/LLVM compiler')
    compiler = Path(compiler).resolve()
    output = args.output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if output == allowed or not output.is_relative_to(allowed):
        parser.error('Use an ignored output below build-native-sjuni')
    if output.exists():
        parser.error('Use a fresh output directory to preserve prior evidence')
    output.mkdir(parents=True)
    sys.path.insert(0, str(ROOT / 'tools/function_index'))
    from index import Elf
    elf = Elf(args.elf.resolve())
    if elf.sha256 != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
        raise ValueError('Owned File #1 identity differs')
    fixture = output / 'identity.bin'
    ranges = ((0x101788, 0x1E0), (0x1004D8, 0xB8), (0x100298, 0xA0))
    fixture.write_bytes(b''.join(struct.pack('<II', pc, size) + elf.read(pc, size) for pc, size in ranges))
    sources = [*sorted(p for p in TESTS.rglob('*') if p.is_file()),
               TESTS.parent / 'runtime_adapter.h', TESTS.parent / 'runtime_adapter.cpp',
               ROOT / 'recomp/overrides/native_geometry/reo_vu_native_sha256.h']
    receipt = dict(schema=1, status='running', compiler=str(compiler), compiler_sha256=sha(compiler),
                   game_launched=False, game_built=False, runtime_library_linked=False,
                   source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in sources},
                   elf_sha256=elf.sha256, checks=[])
    env = dict(os.environ)
    bins = [compiler.parent, compiler.parent.parent / 'x86_64-w64-mingw32/bin']
    env['PATH'] = os.pathsep.join(str(p) for p in bins if p.is_dir()) + os.pathsep + env.get('PATH', '')

    def run(name, command):
        result = subprocess.run([str(x) for x in command], cwd=ROOT, env=env, capture_output=True,
                                text=True, encoding='utf-8', errors='replace', timeout=45)
        receipt['checks'].append(dict(name=name, command=[str(x) for x in command],
                                      exit_code=result.returncode, stdout=result.stdout, stderr=result.stderr))
        if result.returncode:
            raise RuntimeError(name + ' failed:\n' + result.stdout + result.stderr)
        print(name + ': passed', flush=True)
        return result

    try:
        common = [compiler, '-std=c++20', '-O1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-pthread']
        defines = ['-DREO_GAME_FILE1=1', '-DREO_BUILD_NATIVE_RESOURCE_READS=1']
        inputs = ['-I' + str(TESTS), '-I' + str(ROOT), TESTS / 'harness.cpp', TESTS.parent / 'runtime_adapter.cpp']
        static = [] if 'clang' in compiler.name.lower() else ['-static-libgcc', '-static-libstdc++']
        executable = output / 'native_payload_checks.exe'
        run('mock_adapter_build', [*common, *defines, *inputs, *static, '-o', executable])
        scenarios = ('operations', 'refusals', 'mount-handoff', 'reader-results', 'shutdown', 'self-join', 'overlay',
                     'flag-off', 'pak-off', 'async-on', 'async-unset', 'mount-failure', 'null-mount',
                     'layout-mismatch', 'missing-bridge', 'registration-refused', 'stopped', 'identity', 'wrong-edition',
                     'timing', 'timing-invalid')
        for scenario in scenarios:
            result=run(scenario, [executable, fixture, scenario])
            count=result.stderr.count('[NATIVE-RESOURCE-READS] slow begin_ns=')
            if count!=(64 if scenario=='timing' else 0):
                raise ValueError('Unexpected bounded read-timing output '+scenario)
        disabled = output / 'native_payload_disabled_checks.exe'
        run('numeric_feature_zero_build', [*common, '-DREO_GAME_FILE1=1', '-DREO_BUILD_NATIVE_RESOURCE_READS=0',
                                           *inputs, *static, '-o', disabled])
        run('numeric_feature_zero', [disabled, fixture, 'disabled'])
        if args.runtime_headers:
            dep = args.runtime_headers.resolve()
            receipt['real_runtime_header_sha256'] = sha(dep / 'ps2xRuntime/include/ps2_runtime.h')
            receipt['real_mount_reader_header_sha256'] = sha(ROOT / 'game/native/resources_windows/mounted_reader.hpp')
            receipt['real_bridge_header_sha256'] = sha(ROOT / 'recomp/overrides/reo_hw_bridge.h')
            # Existing public runtime headers contain unused inline parameters/
            # locals; these are the same explicit SDK exceptions as CD-owner checks.
            run('real_runtime_header_object', [compiler, '-std=c++20', '-Wall', '-Wextra', '-Werror',
                '-Wno-unused-variable', '-Wno-unused-parameter', '-mssse3', '-msse4.1', *defines,
                '-I' + str(dep / 'ps2xRuntime/include'), '-I' + str(dep / 'ps2xRuntime/src/lib'),
                '-I' + str(dep / 'ps2xRuntime/src/lib/Kernel'), '-I' + str(ROOT / 'recomp/overrides'),
                '-I' + str(ROOT), '-c', TESTS.parent / 'runtime_adapter.cpp', '-o', output / 'real_runtime_adapter.o'])
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = [
            'Host mocks verify adapter/lifetime/fallback boundaries, not the runtime lifecycle implementation.',
            'Owned ELF intervals are identity data only; no original instructions are executed.',
            'No actual imported mount, disk provider, game, RPC service, callback or guest scheduler is run.',
            'Real-header mode compiles one object without linking a runtime or game.',
        ]
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')


if __name__ == '__main__':
    main()
