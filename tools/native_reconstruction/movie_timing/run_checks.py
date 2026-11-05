#!/usr/bin/env python3
"""Isolated recorder and actual V6 dependency header checks; no game/link/device."""
import argparse
import csv
import hashlib
import io
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
OWNED = ['runtime/media/movie_timing.h',
         'tools/parallel_gs_backend/movie_runtime/movie_owner_service.h',
         'tools/parallel_gs_backend/movie_runtime/live_movie_producer.h']


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def run(command, output, label):
    result = subprocess.run([str(x) for x in command], capture_output=True, text=True)
    (output / (label + '.stdout.log')).write_text(result.stdout, encoding='utf-8')
    (output / (label + '.stderr.log')).write_text(result.stderr, encoding='utf-8')
    if result.returncode:
        raise RuntimeError(label + ' failed: ' + result.stderr[-4000:])
    return result


def recorder_check(compiler, output):
    output.mkdir()
    binary = output / 'movie-timing-check.exe'
    run([compiler, '-std=c++20', '-O1', '-Wall', '-Wextra', '-Werror',
         '-I' + str(ROOT), HERE / 'check.cpp', '-o', binary], output, 'compile')
    path = output / 'timings.csv'
    result = run([binary, path, output / 'missing-parent' / 'not-created.csv'], output, 'execute')
    assert result.stderr.count('export failed:') == 4
    assert result.stderr.count('exported owner epoch=') == 3
    text = path.read_text(encoding='utf-8')
    assert text.count('# reo_movie_timing_schema=1') == 5  # two failure injectors wrote data
    assert text.count('# owner_complete=1') == 5
    assert '# dropped_slow_events=5' in text and '# aggregates_saturated=1' in text
    first = text.split('# reo_movie_timing_schema=1')[1]
    data = '\n'.join(line for line in first.splitlines() if line and not line.startswith('#'))
    rows = list(csv.DictReader(io.StringIO(data)))
    assert rows == [dict(boundary='decode', generation='8', serial='10', begin_ns='100',
                         end_ns='2000100', elapsed_ns='2000000'),
                    dict(boundary='output', generation='11', serial='12', begin_ns='100',
                         end_ns='3000100', elapsed_ns='3000000')]
    return dict(compiler=str(compiler), compiler_sha256=sha(Path(compiler)),
                export_sha256=sha(path), failures_checked=['open', 'write', 'flush', 'close'],
                recorder_checks='passed')


def actual_header_check(kit, output, toolchain):
    output.mkdir()
    source = kit / 'source'
    stage = output / 'source'
    hashes = {}
    for relative in OWNED:
        path = stage / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(ROOT / relative, path)
        hashes[relative] = sha(path)
    relative_cpp = 'tools/parallel_gs_backend/movie_runtime/movie_owner_service.cpp'
    cpp = stage / relative_cpp
    shutil.copyfile(source / relative_cpp, cpp)
    plan = json.loads((kit / 'compile-plan.json').read_text())
    unit = next(u for u in plan['units'] if any('movie_owner_service.cpp' in s for s in u['sources']))
    if plan.get('externalToolchain'):
        if not toolchain:
            raise ValueError('Supply --toolchain or REO_LLVM_MINGW for the pinned external compiler')
        compiler = toolchain.resolve() / plan['compiler'].removeprefix('{kit}/toolchain/')
        if sha(compiler) != plan['externalCompilerSha256']:
            raise ValueError('External compiler does not match sealed plan SHA-256')
    else:
        compiler = Path(plan['compiler'].replace('{kit}', str(kit)))
    flags = []
    for flag in unit['options']:
        if flag.startswith('/I'):
            flags.append('-I' + flag[2:].replace('{work}/project', str(source)))
        elif flag.startswith('/D'):
            flags.append('-D' + flag[2:])
        elif flag != '/fp:precise':
            raise ValueError('Unhandled actual unit option: ' + flag)
    obj = output / 'movie_owner_service.o'
    command = [compiler, '-std=c++20', '-O0', '-ffp-contract=off', '-I' + str(stage),
               '-I' + str(source / 'tools/parallel_gs_backend/movie_runtime'),
               *flags, '-c', cpp, '-o', obj]
    run(command, output, 'actual-header-object')
    assert all(sha(ROOT / relative) == digest for relative, digest in hashes.items())
    return dict(compiler=str(compiler), compiler_sha256=sha(compiler),
                compile_plan_sha256=sha(kit / 'compile-plan.json'), changed_header_sha256=hashes,
                original_owner_source_sha256=sha(cpp), object_sha256=sha(obj),
                command=[str(x) for x in command], actual_header_object='passed')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--kit', type=Path)
    parser.add_argument('--toolchain', type=Path,
                        default=Path(os.environ['REO_LLVM_MINGW']) if os.environ.get('REO_LLVM_MINGW') else None)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    output = Path(tempfile.mkdtemp(prefix='movie-timing-', dir=args.output.resolve()))
    compilers = [shutil.which('g++'), shutil.which('clang++')]
    if any(value is None for value in compilers):
        raise RuntimeError('Both GCC and LLVM must be available for these checks')
    result = dict(schema=1, output=str(output), recorder=[
        recorder_check(compiler, output / label) for compiler, label in zip(compilers, ['gcc', 'llvm'])])
    if args.kit:
        result['actual_headers'] = actual_header_check(args.kit.resolve(), output / 'actual-headers', args.toolchain)
    result['limitations'] = ['No game, runtime launch, device, decoder or GPU fence was executed.',
        'Supplied timestamps and export failures are deterministic synthetic checks.',
        'Actual object compile uses the sealed V6 dependency source with copied changed headers; no link or library rebuild.',
        'No cross-thread writer admission: production recorder belongs to one serialized GS owner.']
    (output / 'receipt.json').write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(recorder='GCC+LLVM passed', actual_headers='passed' if args.kit else 'not requested',
                          receipt=str(output / 'receipt.json')), indent=2))


if __name__ == '__main__':
    main()
