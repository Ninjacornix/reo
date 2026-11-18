#!/usr/bin/env python3
"""Check real Windows pinned-file behavior using only fresh synthetic files.

No game, import, ISO, process attachment or dependency library is used. SHA
expectations come independently from Python hashlib; artifacts are retained.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import uuid

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', default='g++')
    parser.add_argument('--executable', type=Path,
                        help='Run an already-built pinned_file_tests executable (CTest)')
    args = parser.parse_args()
    if os.name != 'nt':
        parser.error('The Windows backend requires Windows')
    compiler = shutil.which(args.cxx) if not args.executable else None
    if not args.executable and not compiler:
        parser.error('Pass an installed C++20 GCC/Clang compiler')
    if args.executable and (not args.executable.is_file() or
                           args.executable.name != 'pinned_file_tests.exe'):
        parser.error('--executable must name an existing pinned_file_tests.exe')
    output = ROOT/'build-native-sjuni/pinned-file-checks'
    output.mkdir(parents=True, exist_ok=True)
    data = output/('synthetic-'+uuid.uuid4().hex)
    data.mkdir()
    (data/'abc.bin').write_bytes(b'abc')
    os.link(data/'abc.bin', data/'hardlink.bin')
    (data/'empty.bin').write_bytes(b'')
    (data/'caf\u00e9_\u6d4b\u8bd5.bin').write_bytes(b'abc')
    (data/'patterned.bin').write_bytes(bytes(((i * 37) ^ (i >> 8)) & 255 for i in range(1048579)))
    with (data/'large.bin').open('wb') as stream:
        stream.seek(256*1024*1024+2)
        stream.write(b'\0')
    files = [data/name for name in ('abc.bin', 'empty.bin', 'patterned.bin', 'large.bin', 'caf\u00e9_\u6d4b\u8bd5.bin')]
    (data/'hashes.txt').write_text(''.join(f'{p.name} {p.stat().st_size} {sha(p)}\n' for p in files), encoding='utf-8')
    module = ROOT/'game/native/resources_windows'
    sources = [module/'pinned_file.cpp', module/'pinned_file_tests.cpp',
               ROOT/'game/native/resources/resource_session.cpp', ROOT/'game/native/resources/virtual_file_view.cpp']
    identities = sources + [module/'pinned_file.hpp', module/'types.hpp', ROOT/'runtime/assets/virtual_afs.h',
                            ROOT/'game/native/resources/byte_view.hpp', ROOT/'game/native/resources/resource_session.hpp',
                            ROOT/'game/native/resources/virtual_file_view.hpp', Path(__file__)]
    receipt = dict(schema=1, status='running', game_launched=False, imported_assets_read=False,
                   compiler=compiler, compiler_sha256=sha(Path(compiler)) if compiler else None,
                   source_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in identities},
                   synthetic_sha256={p.name:sha(p) for p in files}, checks=[])
    executable = args.executable.resolve() if args.executable else output/'pinned_file_tests.exe'
    try:
        commands = []
        if not args.executable:
            commands.append(('build', [compiler, '-std=c++20', '-O1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-pthread', '-D_WIN32_WINNT=0x0A00',
                            '-I'+str(ROOT), *map(str, sources), '-lbcrypt', '-o', str(executable)]))
        commands.append(('synthetic_windows_file_checks', [str(executable), str(data)]))
        for name, command in commands:
            result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True, timeout=60)
            receipt['checks'].append(dict(name=name, command=command, exit_code=result.returncode,
                                          stdout=result.stdout, stderr=result.stderr))
            if result.returncode:
                sys.stderr.write(result.stdout+result.stderr)
                raise RuntimeError(name+' failed')
            print(name+': passed', flush=True)
        receipt['status'] = 'passed'
        receipt['executable_sha256'] = sha(executable)
    except Exception as error:
        receipt['status'] = 'failed'; receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = ['Synthetic files, not an imported manifest/virtual-route mount or game integration.',
                                  'Read-only sharing blocks ordinary write/delete opens, including hard links.',
                                  'External mutation through pre-existing writable mappings is outside the immutability contract.',
                                  'The local expected digest is matched; it does not authenticate a canonical retail asset.']
        (output/'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n', encoding='utf-8')
    print('Receipt: build-native-sjuni/pinned-file-checks/receipt.json')


if __name__ == '__main__':
    main()
