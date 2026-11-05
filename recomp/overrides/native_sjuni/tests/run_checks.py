#!/usr/bin/env python3
"""Compile and run ONLY host-side native SJUNI wrapper checks.

The owned original text is read for its identity gate, never executed. Mock
runtime bindings are sentinels, not guest instruction implementations. No game
build, game process, audio, device, network or live target is used.
"""
import argparse
import hashlib
import os
import re
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[4]
TESTS = Path(__file__).resolve().parent
PINNED_ELF_SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
TEXT_SHA = '544376807278847bc0f4294c7a62238acff5a645accc2ec2dec9bf58073d5cc2'
GUARD_RANGES = ((0x13F258, 0x2C), (0x1415E0, 0x120), (0x12A968, 0x84), (0x12A9F0, 0x70))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', default=os.environ.get('CXX') or shutil.which('g++') or shutil.which('clang++'))
    parser.add_argument('--output', type=Path, default=ROOT / 'build-native-sjuni/runtime-adapter-checks')
    parser.add_argument('--check-runtime-headers', action='store_true', help='Also compile adapter object against current real runtime headers; no runtime/game link.')
    args = parser.parse_args()
    if not args.cxx:
        parser.error('A C++20 g++/clang++ compiler is required; pass --cxx.')
    sys.path.insert(0, str(ROOT / 'tools/function_index'))
    from index import Elf
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    if elf.sha256 != PINNED_ELF_SHA:
        raise ValueError('Wrong owned File #1 ELF; no artifact will be executed')
    text = elf.read(0x140000, 0x840)
    if text is None or hashlib.sha256(text).hexdigest() != TEXT_SHA:
        raise ValueError('Original text range does not match adapter identity')
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    text_path = output / 'owned_text.bin'
    text_path.write_bytes(text + b''.join(elf.read(address, size) for address, size in GUARD_RANGES))
    compiler = str(args.cxx)
    common = [compiler, '-std=c++20', '-Wall', '-Wextra', '-Werror']
    if args.check_runtime_headers:
        command = common + ['-mssse3', '-msse4.1', '-Wno-unused-parameter', '-Wno-unused-variable']
        command += ['-I'+str(ROOT), '-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include'),
                    '-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/src/lib'),
                    '-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel'),
                    '-c', str(TESTS.parent/'runtime_adapter.cpp'), '-o', str(output/'runtime_adapter.o')]
        subprocess.run(command, cwd=ROOT, check=True)
        print('Current real-header adapter object compiled.', flush=True)
    executable = output / ('runtime_adapter_checks.exe' if os.name == 'nt' else 'runtime_adapter_checks')
    command = common + ['-O1']
    if 'g++' in Path(compiler).name:
        # GCC warns about the intentional malloc/free global-new fault injector
        # after inlining standard containers. The runtime adapter has no such
        # allocation overrides; this suppression is confined to the mock harness.
        command += ['-Wno-mismatched-new-delete']
    command += ['-I'+str(TESTS), '-I'+str(ROOT), str(TESTS/'harness.cpp'),
                str(ROOT/'game/native/sjuni_adapter/queue_bridge.cpp'),
                str(ROOT/'game/native/sjuni/sjuni.cpp'), '-o', str(executable)]
    subprocess.run(command, cwd=ROOT, check=True)
    for scenario in ('operations', 'changed-binding', 'changed-memory', 'changed-text', 'partial-install'):
        print('Host synthetic scenario:', scenario, flush=True)
        subprocess.run([str(executable), str(text_path), scenario], cwd=ROOT, check=True)
    guarded_executable = output / ('guarded_adapter_checks.exe' if os.name == 'nt' else 'guarded_adapter_checks')
    guarded_command = [str(TESTS/'guarded_harness.cpp') if arg == str(TESTS/'harness.cpp') else
                       str(guarded_executable) if arg == str(executable) else arg for arg in command]
    subprocess.run(guarded_command, cwd=ROOT, check=True)
    for scenario in ('guarded', 'missing-primary', 'missing-enter', 'missing-leave', 'missing-epilogue', 'missing-post', 'bad-guard-hash'):
        print('Host guarded-phase scenario:', scenario, flush=True)
        subprocess.run([str(guarded_executable), str(text_path), scenario], cwd=ROOT, check=True)
    print('Host guarded-phase scenario: trace-on', flush=True)
    traced = subprocess.run([str(guarded_executable), str(text_path), 'trace-on'], cwd=ROOT,
                            check=True, capture_output=True, text=True)
    print(traced.stdout, end='')
    print(traced.stderr, end='', file=sys.stderr)
    calls = [int(x) for x in re.findall(r'^\[native-sjuni\] native op=queued_bytes guarded=0 calls=(\d+) queue=0 slot=0$', traced.stderr, re.M)]
    if calls != [1, 2, 3, 4, 8, 16]:
        raise AssertionError(f'Wrong bounded proof-trace cadence: {calls}')
    if not re.search(r'\[native-sjuni\] native op=get guarded=1 calls=', traced.stderr):
        raise AssertionError('Missing actual native guarded-body trace')
    print('All thirteen host-only adapter scenarios passed; no game/runtime link performed.')


if __name__ == '__main__':
    main()
