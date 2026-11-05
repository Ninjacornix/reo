#!/usr/bin/env python3
"""Build/run isolated SJUNI checks and retain a source/compiler-bound receipt.

Uses an existing GCC/Clang C++20 compiler. Never builds, launches or attaches to
the game, loads PS2Recomp libraries, changes dependencies or enables a setting.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

from compare_sjuni import generate as comparison_source
from sjuni_oracle import generate as original_fixtures

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', default='g++', help='Existing GCC/Clang C++ compiler')
    args = parser.parse_args()
    compiler = shutil.which(args.cxx)
    if compiler is None:
        parser.error('Compiler unavailable; pass --cxx with an installed GCC/Clang path')
    output = ROOT / 'build-native-sjuni/verified'
    output.mkdir(parents=True, exist_ok=True)
    fixture = ROOT / 'tools/native_reconstruction/sjuni_oracle_fixtures.json'
    decoded = json.loads(fixture.read_text(encoding='utf-8'))
    if decoded != original_fixtures():
        raise ValueError('Committed original fixtures differ from the pinned owned-word oracle')
    generated = output / 'original_comparison.cpp'
    generated.write_text(comparison_source(fixture), encoding='utf-8', newline='\n')
    receipt = {'schema': 1, 'status': 'running',
               'scope': 'isolated native core/portable bridge/original integer-word oracle',
               'game_launched': False, 'runtime_library_linked': False,
               'compiler': compiler, 'compiler_sha256': sha(Path(compiler)),
               'compiler_version': subprocess.check_output([compiler, '--version'], text=True).splitlines()[0],
               'elf_sha256': decoded['identity']['elf_sha256'],
               'fixture_sha256': sha(fixture), 'oracle_counts': decoded['counts'], 'checks': []}
    sources = [*sorted((ROOT / 'game/native').rglob('*.cpp')),
               *sorted((ROOT / 'game/native').rglob('*.hpp')),
               *sorted((ROOT / 'game/native').rglob('*.h')),
               *sorted((ROOT / 'tools/native_reconstruction').glob('*.cpp')),
               *sorted((ROOT / 'tools/native_reconstruction').glob('*.py'))]
    receipt['source_sha256'] = {p.relative_to(ROOT).as_posix(): sha(p) for p in sources}

    def run(command, name):
        result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
        receipt['checks'].append({'name': name, 'command': [str(a) for a in command],
                                  'exit_code': result.returncode,
                                  'stdout': result.stdout, 'stderr': result.stderr})
        if result.returncode != 0:
            receipt['status'] = 'failed'
            (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
            sys.stderr.write(result.stdout + result.stderr)
            raise SystemExit(f'{name} failed; see build-native-sjuni/verified/receipt.json')
        print(name + ': passed')

    run([sys.executable, '-m', 'unittest', 'discover', '-s', 'tools/native_reconstruction',
         '-p', 'test_*.py', '-q'], 'original_oracle_tests')
    common = [compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
              '-O1', '-I.']
    core = 'game/native/sjuni/sjuni.cpp'
    bridge = 'game/native/sjuni_adapter/queue_bridge.cpp'
    targets = [
        ('core', [core, 'game/native/sjuni/sjuni_tests.cpp']),
        ('bridge', [core, bridge, 'game/native/sjuni_adapter/queue_bridge_tests.cpp']),
        ('original_comparison', [core, bridge, generated.relative_to(ROOT).as_posix()]),
        ('body_probe', [core, bridge, 'tools/native_reconstruction/sjuni_body_probe.cpp']),
    ]
    for name, inputs in targets:
        stem = 'sjuni_body_probe' if name == 'body_probe' else name
        executable = output / (stem + ('.exe' if sys.platform == 'win32' else ''))
        run(common + inputs + ['-o', str(executable)], name + '_build')
        if name == 'body_probe':
            run([sys.executable, 'tools/native_reconstruction/compare_sjuni_continuations.py',
                 '--probe', str(executable)], 'original_continuation_native_body_comparison')
            run([sys.executable, 'tools/native_reconstruction/fuzz_sjuni_continuations.py',
                 '--probe', str(executable)], 'seeded_original_continuation_comparison')
        else:
            run([str(executable)], name + '_tests')
    receipt['status'] = 'passed'
    receipt['limitations'] = [
        'Original scheduling, syscalls, DMA, IOP and real audio/movie consumers are not executed.',
        '109 fixture calls provide original setup/lifecycle/helper context, not native replacements.',
        'Unsupported admissions are checked for no writes/hooks; they do not count as native execution.',
        'Three hybrid cases run the native body between original prologue/leave/epilogue phases.',
        'Seeded continuation fuzz omits error callback ordering on its native error paths; fixed fixtures cover that contract.',
        'Runtime wrapper registration/build identity and gameplay validation are separate checks.',
        'No performance gain or complete native transition is established.',
    ]
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Source-bound receipt: build-native-sjuni/verified/receipt.json')


if __name__ == '__main__':
    main()
