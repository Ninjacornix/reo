#!/usr/bin/env python3
"""Developer qualification of the native owner; never launches the game."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

ROOT = Path(__file__).resolve().parents[2]
SOURCES = (
    'tools/native_reconstruction/host_movie_session_check.cpp',
    'game/native/host_movie/session.cpp', 'game/native/host_movie/player.cpp',
    'game/native/movie_assets/catalogue.cpp', 'game/native/resources_windows/pinned_file.cpp',
)


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--cache', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    compiler, cache, output = (p.resolve() for p in (args.compiler, args.cache, args.output))
    if output.exists() or not output.is_relative_to(ROOT / 'build-native-sjuni'):
        raise ValueError('Fresh private evidence directory required')
    output.mkdir(parents=True)
    fixture = output / 'invalid source'
    fixture.mkdir()
    document = json.loads((cache / 'movies.json').read_text())
    row = dict(document['movies'][0])
    data = b'Invalid native media source. ' * 64
    row.update(sha256=hashlib.sha256(data).hexdigest(), bytes=len(data))
    (fixture / row['file']).write_bytes(data)
    document.update(complete_catalogue=False, prepared=1, movies=[row])
    (fixture / 'movies.json').write_text(json.dumps(document), encoding='utf-8')
    executable = output / 'session-check.exe'
    command = [str(compiler), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
               '-municode', '-I' + str(ROOT), *[str(ROOT / s) for s in SOURCES], '-o', str(executable),
               '-lruntimeobject', '-lbcrypt', '-lmfplat', '-lmfuuid', '-lole32', '-loleaut32',
               '-lshlwapi', '-ld3d11', '-ldxguid']
    env = dict(os.environ, PATH=str(compiler.parent) + os.pathsep + os.environ['PATH'])
    receipt = dict(schema=1, compiler=str(compiler), compiler_sha256=digest(compiler),
                   sources={s: digest(ROOT / s) for s in SOURCES}, game_run=False, checks=[])
    started = time.monotonic()
    try:
        for name, cmd, timeout in [('compile', command, 180),
                                   ('native_owner', [str(executable), str(cache), str(fixture)], 90)]:
            result = subprocess.run(cmd, capture_output=True, text=True, env=env, timeout=timeout)
            receipt['checks'].append(dict(name=name, command=cmd, exit_code=result.returncode,
                                          stdout=result.stdout, stderr=result.stderr))
            print(name, result.returncode, result.stdout, result.stderr, flush=True)
            if result.returncode:
                raise RuntimeError(name + ' failed')
        receipt['status'] = 'passed'
        receipt['executable_sha256'] = digest(executable)
    finally:
        receipt['elapsed_seconds'] = time.monotonic() - started
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')


if __name__ == '__main__':
    main()
