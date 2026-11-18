#!/usr/bin/env python3
"""Whole-owner isolated unit build with exact immutable draft inputs; no game."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx', required=True)
    p.add_argument('--implementation', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args(); cc = shutil.which(a.cxx); out = a.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/window2'):
        raise ValueError('Exact compiler and fresh scoped output required')
    manifest = json.loads((a.implementation / 'manifest.json').read_bytes())
    for name, digest in manifest['files'].items():
        if sha(ROOT / name) != digest:
            raise ValueError('Frozen draft input drift: ' + name)
    out.mkdir(parents=True); env = dict(os.environ)
    env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    sources = ['game/native/sjrb/sjrb.cpp', 'game/native/adxt_shared_source/shared_source.cpp',
        'game/native/adxt_refill/adxt_refill.cpp', 'game/native/resource_io/async_read_owner.cpp',
        'game/native/tasks/serial_worker.cpp', 'game/native/resources/resource_session.cpp',
        'game/native/resources/virtual_file_view.cpp', 'game/native/resources/bounded_view.cpp',
        'game/native/adx_header/adx_header.cpp', 'game/native/adx_workspace/adx_workspace.cpp',
        'game/native/adx_pcm_store/v2/pcm_store.cpp', 'game/native/adx_window/v2/stream_window.cpp',
        'game/native/adx_window/v2/stream_window_tests.cpp']
    binary = out / 'tests.exe'
    command = [cc, '-std=c++20', '-O1', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
        '-Wno-misleading-indentation', '-fno-fast-math', '-ffp-contract=off', '-frounding-math',
        '-I' + str(ROOT), *sources, '-o', str(binary)]
    receipt = dict(schema=1, status='running', implementation_manifest_sha256=sha(a.implementation / 'manifest.json'),
        compiler=cc, compiler_sha256=sha(Path(cc)), verifier_sha256=sha(Path(__file__)), checks=[],
        game_run=False, device_opened=False, original_whole_owner_parity=False)
    try:
        for name, args in [('compile', command), ('units', [str(binary)])]:
            run = subprocess.run(args, cwd=ROOT, env=env, capture_output=True, text=True, timeout=90)
            (out / (name + '.txt')).write_text(run.stdout + run.stderr, encoding='utf-8', newline='\n')
            receipt['checks'].append(dict(name=name, command=args, exit_code=run.returncode, stdout=run.stdout))
            if run.returncode:
                raise RuntimeError(run.stdout + run.stderr)
        receipt.update(status='passed', executable_sha256=sha(binary))
    except Exception as error:
        receipt.update(status='failed', failure=str(error)); raise
    finally:
        receipt['input_drift'] = [name for name, digest in manifest['files'].items() if sha(ROOT / name) != digest]
        if receipt['input_drift']:
            receipt.update(status='failed', failure='Input drift during verification')
        (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps(dict(status=receipt['status'], receipt_sha256=sha(out / 'receipt.json'), units=receipt['checks'][-1]['stdout'])))


if __name__ == '__main__':
    main()
