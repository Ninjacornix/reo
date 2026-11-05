#!/usr/bin/env python3
"""Verify synthetic native resource contracts and existing byte-route parity.

Never builds/launches the game, reads an ISO/import, or links PS2Recomp. Outputs
and source/compiler-bound evidence remain under ignored build-native-sjuni.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
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
    output = ROOT / 'build-native-sjuni/resource-verification'
    output.mkdir(parents=True, exist_ok=True)
    sources = [*sorted((ROOT / 'game/native/resources').glob('*pp')),
               ROOT / 'tools/native_reconstruction/resource_routes_check.cpp',
               Path(__file__), ROOT / 'runtime/assets/virtual_afs.h',
               ROOT / 'runtime/assets/overlay.h', ROOT / 'runtime/core/host_file.h',
               ROOT / 'recomp/overrides/native_geometry/reo_vu_native_sha256.h',
               ROOT / 'runtime/cdvd/cdvd.h', ROOT / 'runtime/cdvd/cdvd.cpp']
    receipt = dict(schema=1, status='running', game_launched=False,
                   scope='synthetic native resource contracts and existing byte providers',
                   compiler=compiler, compiler_sha256=sha(Path(compiler)),
                   compiler_version=subprocess.check_output([compiler, '--version'], text=True).splitlines()[0],
                   source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in sources}, checks=[])

    def run(command, name):
        result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
        receipt['checks'].append(dict(name=name, command=[str(x) for x in command],
                                      exit_code=result.returncode, stdout=result.stdout, stderr=result.stderr))
        if result.returncode:
            sys.stderr.write(result.stdout + result.stderr)
            raise RuntimeError(name + ' failed')
        print(name + ': passed', flush=True)

    common = [compiler, '-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-O1', '-pthread', '-I.']
    library = ['game/native/resources/resource_session.cpp', 'game/native/resources/virtual_file_view.cpp']
    suffix = '.exe' if sys.platform == 'win32' else ''
    try:
        contract = output / ('resource_contract' + suffix)
        run(common + library + ['game/native/resources/resource_tests.cpp', '-o', str(contract)], 'contract_build')
        run([str(contract)], 'contract_tests')
        routes = output / ('resource_routes_check' + suffix)
        reference = output / 'existing_cdvd.o'
        # Existing overlay.h uses C++20-deprecated u8path under GCC 15. Keep this
        # reference-only suppression out of the new library and probe builds.
        run(common + ['-Wno-deprecated-declarations', '-c', 'runtime/cdvd/cdvd.cpp', '-o', str(reference)],
            'existing_cdvd_reference_build')
        run(common + library + [str(reference), 'tools/native_reconstruction/resource_routes_check.cpp',
                               '-o', str(routes)], 'existing_routes_build')
        run([str(routes), str(output / ('synthetic-' + uuid.uuid4().hex))], 'existing_routes_comparison')
        receipt['status'] = 'passed'
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        receipt['limitations'] = [
            'Synthetic files only; no owned import or original-game I/O replay.',
            'The existing PAK sector facade is a comparison oracle, not migrated game integration.',
            'Exact native reads reject EOF overrun; sector facade padding remains explicit adapter policy.',
            'Mount identity, CRI completion and decoder/stop ownership are separate unresolved contracts.',
        ]
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print('Receipt: build-native-sjuni/resource-verification/receipt.json')


if __name__ == '__main__':
    main()
