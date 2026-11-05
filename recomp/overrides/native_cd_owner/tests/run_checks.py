#!/usr/bin/env python3
"""Compile native worker/adapter checks with mocked runtime and disk services.

Reads identity words from the owned ELF only. No original code, device, game
session or runtime library is executed. Detailed receipts stay in ignored output.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[4]
TESTS = Path(__file__).resolve().parent


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', default='g++')
    parser.add_argument('--runtime-headers', type=Path,
                        help='Also compile the adapter against a supplied real patched PS2Recomp checkout; no link.')
    args = parser.parse_args()
    compiler = shutil.which(args.cxx)
    if not compiler:
        parser.error('Pass an installed C++20 GCC/Clang compiler')
    sys.path.insert(0, str(ROOT / 'tools/function_index'))
    from index import Elf
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    if elf.sha256 != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
        raise ValueError('Owned File #1 identity mismatch')
    output = ROOT / 'build-native-sjuni/cd-owner-checks'
    output.mkdir(parents=True, exist_ok=True)
    fixture = output / 'identity.bin'
    fixture.write_bytes(b''.join(struct.pack('<II', pc, length) + elf.read(pc, length)
                                 for pc, length in ((0x101788, 0x1E0), (0x1004D8, 0xB8), (0x100298, 0xA0))))
    sources = [*sorted(TESTS.glob('*')), TESTS.parent / 'runtime_adapter.cpp', TESTS.parent / 'runtime_adapter.h',
               ROOT / 'game/native/tasks/serial_worker.hpp', ROOT / 'game/native/tasks/serial_worker.cpp']
    sources.append(ROOT / 'recomp/overrides/native_geometry/reo_vu_native_sha256.h')
    receipt = dict(schema=1, status='running', game_launched=False, runtime_library_linked=False,
                   elf_sha256=elf.sha256, compiler=compiler, compiler_sha256=sha(Path(compiler)),
                   source_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in sources if p.is_file()}, checks=[])

    def run(command, name):
        result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True, timeout=30)
        receipt['checks'].append(dict(name=name, exit_code=result.returncode, command=[str(x) for x in command],
                                      stdout=result.stdout, stderr=result.stderr))
        if result.returncode:
            sys.stderr.write(result.stdout + result.stderr)
            raise RuntimeError(name + ' failed')
        print(name + ': passed', flush=True)

    try:
        executable = output / ('native_cd_owner_checks.exe' if sys.platform == 'win32' else 'native_cd_owner_checks')
        run([compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-O1', '-pthread',
             '-I'+str(TESTS), '-I'+str(ROOT), str(TESTS/'harness.cpp'), str(TESTS.parent/'runtime_adapter.cpp'),
             str(ROOT/'game/native/tasks/serial_worker.cpp'), '-o', str(executable)], 'host_adapter_build')
        for scenario in ('operations', 'refusals', 'shutdown', 'queue-full', 'callback-overlap',
                         'allocation-failure', 'no-stack', 'late-registration', 'callback-exception',
                         'callback-continuation', 'missing-callback', 'changed-callback', 'read-exception'):
            run([str(executable), str(fixture), scenario], scenario)
        if args.runtime_headers:
            dependency = args.runtime_headers.resolve()
            runtime_header = dependency/'ps2xRuntime/include/ps2_runtime.h'
            receipt['real_runtime_header_sha256'] = sha(runtime_header)
            run([compiler, '-std=c++20', '-Wall', '-Wextra', '-Werror', '-mssse3', '-msse4.1',
                 '-Wno-unused-variable', '-Wno-unused-parameter',
                 '-I'+str(dependency/'ps2xRuntime/include'), '-I'+str(dependency/'ps2xRuntime/src/lib'),
                 '-I'+str(dependency/'ps2xRuntime/src/lib/Kernel'),
                 '-I'+str(ROOT/'recomp/overrides'), '-I'+str(ROOT),
                 '-c', str(TESTS.parent/'runtime_adapter.cpp'), '-o', str(output/'real_runtime_adapter.o')],
                'real_runtime_header_object')
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = ['Mocks check adapter ordering/ownership, not the runtime lifecycle patch implementation.',
                                  'No original instruction, CD device, SRD/DVCI, audio/movie or gameplay execution.',
                                  'The existing false-read callback policy remains; typed error publication is not reconstructed.']
        (output/'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n', encoding='utf-8')
    print('Receipt: build-native-sjuni/cd-owner-checks/receipt.json')


if __name__ == '__main__':
    main()
