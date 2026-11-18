#!/usr/bin/env python3
"""Compile retained Source/overlay checks without a game or runtime library.

Archive/payload/provider fixtures are synthetic. The owned File1 ELF is copied
into a NEW ignored fixture directory solely to satisfy the unchanged Overlay ELF
identity check; none of its instructions execute. Inputs are never modified.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import uuid

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', default='g++')
    args = parser.parse_args()
    compiler = shutil.which(args.cxx)
    if compiler is None:
        parser.error('Pass an installed C++20 GCC/Clang compiler')
    owned = ROOT / 'game_data/SLUS_207.65'
    identity = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    if sha(owned) != identity:
        raise ValueError('Owned File1 identity fixture mismatch')
    output = ROOT / 'build-native-sjuni/retained-source-checks'
    output.mkdir(parents=True, exist_ok=True)
    token = uuid.uuid4().hex
    fixture = output / ('synthetic-' + token)
    fixture.mkdir()
    (fixture / '.retained-source-fixture').write_text(token, encoding='ascii')
    shutil.copyfile(owned, fixture / 'SLUS_207.65')
    sources = [ROOT / path for path in (
        'runtime/assets/virtual_afs.h', 'runtime/assets/overlay.h',
        'recomp/overrides/native_geometry/reo_vu_native_sha256.h',
        'game/native/resources/byte_view.hpp', 'game/native/resources/resource_session.hpp',
        'game/native/resources/resource_session.cpp', 'game/native/resources/virtual_file_view.hpp',
        'game/native/resources/virtual_file_view.cpp',
        'tools/native_reconstruction/retained_sources_check.cpp',
        'tools/native_reconstruction/verify_retained_sources.py')]
    receipt = dict(schema=1, status='running', game_launched=False, runtime_library_linked=False,
                   owned_elf_role='Read/copy/hash identity fixture only; no instruction execution',
                   owned_elf_sha256=identity, compiler=compiler,
                   compiler_sha256=sha(Path(compiler)),
                   source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in sources}, checks=[])

    def run(command, name):
        result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True, timeout=30)
        receipt['checks'].append(dict(name=name, command=[str(x) for x in command],
                                      exit_code=result.returncode, stdout=result.stdout, stderr=result.stderr))
        if result.returncode:
            raise RuntimeError(name + ' failed:\n' + result.stdout + result.stderr)
        print(name + ': passed', flush=True)

    try:
        executable = output / 'retained_sources_check.exe'
        run([compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-O1', '-pthread',
             '-I.', 'game/native/resources/resource_session.cpp',
             'game/native/resources/virtual_file_view.cpp',
             'tools/native_reconstruction/retained_sources_check.cpp', '-o', str(executable)], 'host_build')
        run([str(executable), str(fixture), token], 'retained_source_contracts')
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = [
            'No Windows pinned handle/snapshot backend, JSON reader, import validation or mount factory.',
            'Provider size/content immutability and safe concurrent positioned reads remain provider obligations.',
            'Resolver is trusted wiring; neither labels nor adoption establish file identity.',
            'Overlay uses unchanged existing bounded hash/parser/extent/layout checks.',
            'Direct Source/VirtualFile reads can expose partial writes on failure; ResourceSession stages output.',
            'No original archive, game I/O, decoder, CD completion or gameplay execution.',
        ]
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Receipt: build-native-sjuni/retained-source-checks/receipt.json')


if __name__ == '__main__':
    main()
