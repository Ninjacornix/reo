"""Run the existing secondary-ground original comparison against sealed archives.

The original verifier audits the generated bodies and owned floor assets. This
wrapper compiles only its original-body and test units, replacing its redundant
native source compilation with the exact immutable cohort archives and headers.
"""
import argparse
import hashlib
import json
import sys
from pathlib import Path

import verify_gameplay_secondary_ground as original

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--snapshot', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    snapshot = args.snapshot.resolve()
    output = args.output.resolve()
    receipt_path = snapshot / 'receipt.json'
    receipt = json.loads(receipt_path.read_text())
    if receipt['status'] != 'passed':
        raise ValueError('Snapshot did not pass')
    sources = snapshot / 'source'
    libraries = snapshot / 'native-build'
    pinned = {sources / name: digest for name, digest in receipt['source_sha256'].items()}
    pinned.update({libraries / name: digest for name, digest in receipt['archives_sha256'].items()})
    pinned[receipt_path] = sha(receipt_path)

    def verify():
        for path, expected in pinned.items():
            if not path.is_file() or sha(path) != expected:
                raise ValueError('Snapshot identity mismatch: ' + str(path))

    verify()
    names = ['gameplay_collision/libreo_native_gameplay_collision.a',
             'gameplay_actors/libreo_native_gameplay_actors.a',
             'gameplay_session/libreo_native_gameplay_session.a',
             'transform_math/libreo_native_transform_math.a']
    archives = [libraries / name for name in names]
    if any(name not in receipt['archives_sha256'] for name in names):
        raise ValueError('Required archive missing from snapshot')
    test_relative = 'game/native/gameplay_collision/secondary_ground_tests.cpp'
    actual_compile = []
    run = original.subprocess.run

    def snapshot_run(command, *positional, **keywords):
        if '-std=c++20' not in command:
            return run(command, *positional, **keywords)
        native_prefix = (ROOT / 'game/native').resolve()
        filtered = []
        for argument in command:
            candidate = Path(argument)
            if candidate.is_absolute() and candidate.suffix == '.cpp':
                try:
                    relative = candidate.resolve().relative_to(native_prefix)
                except ValueError:
                    pass
                else:
                    if relative.as_posix() == 'gameplay_collision/secondary_ground_tests.cpp':
                        filtered.append(str(sources / test_relative))
                    continue
            filtered.append(argument)
        insertion = filtered.index('-o')
        filtered[insertion:insertion] = ['-Wl,--start-group', *map(str, archives), '-Wl,--end-group']
        actual_compile.extend(filtered)
        return run(filtered, *positional, **keywords)

    original.subprocess.run = snapshot_run
    old_argv = sys.argv
    try:
        sys.argv = [str(Path(original.__file__)), '--compiler', 'llvm', '--output', str(output)]
        original.main()
    finally:
        sys.argv = old_argv
        original.subprocess.run = run
    verify()
    result_path = output / 'receipt.json'
    result = json.loads(result_path.read_text())
    if not actual_compile:
        raise ValueError('Original verifier did not compile')
    for name in result['source_sha256']:
        if name.startswith('game/native/'):
            if name not in receipt['source_sha256']:
                raise ValueError('Native input absent from snapshot: ' + name)
            result['source_sha256'][name] = receipt['source_sha256'][name]
    result['checks'][0]['command'] = actual_compile
    result['snapshot_receipt_sha256'] = pinned[receipt_path]
    result['snapshot_archives_sha256'] = {name: receipt['archives_sha256'][name] for name in names}
    result['snapshot_sources_and_archives_verified'] = len(pinned) - 1
    result['wrapper_sha256'] = sha(Path(__file__))
    result_path.write_text(json.dumps(result, indent=2) + '\n')


if __name__ == '__main__':
    main()
