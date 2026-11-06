#!/usr/bin/env python3
"""Detect a late-store observation while all final PCM remains correct."""
import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
sys.path.insert(0, str(HERE.parent))
from original_projection import sha, encode


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx', required=True)
    p.add_argument('--fixture', type=Path, required=True)
    p.add_argument('--phases', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args(); out = a.output.resolve(); cc = shutil.which(a.cxx)
    if not cc or out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/adx-pcm-store/v2'):
        raise ValueError('Exact compiler and fresh scoped output required')
    for name, digest in json.loads((HERE / 'frozen_identity.json').read_bytes())['files'].items():
        if sha(ROOT / name) != digest:
            raise ValueError('Frozen source drift')
    fixture = json.loads((a.fixture / 'manifest.json').read_bytes())
    phases = json.loads((a.phases / 'receipt.json').read_bytes())
    if sha(a.fixture / 'cases.json') != fixture['cases_sha256'] or sha(a.phases / 'phases.json') != phases['phases_sha256']:
        raise ValueError('Frozen evidence drift')
    cases = json.loads((a.fixture / 'cases.json').read_bytes())
    rows = json.loads((a.phases / 'phases.json').read_bytes()); out.mkdir(parents=True)
    text = (HERE / 'fixture_runner.cpp').read_text(encoding='utf-8')
    anchor = '''            if (owner.stage(reservation.lease, {l, r}, produced, published) != a::Status::completed) return 3;
            staged = storage(owner, channels);'''
    if text.count(anchor) != 1:
        raise ValueError('Negative phase anchor changed')
    private = out / 'late_observation.cpp'
    private.write_text(text.replace(anchor, '''            staged = storage(owner, channels); // negative: input-credit observer sees pre-store PCM
            if (owner.stage(reservation.lease, {l, r}, produced, published) != a::Status::completed) return 3;'''), encoding='utf-8', newline='\n')
    env = dict(os.environ); env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    binary = out / 'negative.exe'
    command = [cc, '-std=c++20', '-O1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-I' + str(HERE),
               str(HERE / 'pcm_store.cpp'), str(ROOT / 'game/native/sjrb/sjrb.cpp'), str(private), '-o', str(binary)]
    build = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, timeout=90)
    (out / 'build.txt').write_text(build.stdout + build.stderr, encoding='utf-8', newline='\n')
    if build.returncode:
        raise RuntimeError(build.stderr)
    inputs = '\n'.join(f"{c['name']} {c['channels']} {c['queued_bytes']} {c['operation']} {c['produced']} {c['published']} {c['left_hex'] or '-'} {c['right_hex'] or '-'}" for c in cases) + '\n'
    run = subprocess.run([str(binary)], input=inputs, cwd=ROOT, env=env, capture_output=True, text=True, timeout=60)
    (out / 'native.jsonl').write_text(run.stdout, encoding='utf-8', newline='\n')
    actual = [json.loads(s) for s in run.stdout.splitlines()]
    if run.returncode or len(actual) != len(cases):
        raise ValueError('Negative fixture failed before comparison')
    differences = []
    for c, phase, result in zip(cases, rows, actual, strict=True):
        if result['name'] != c['name'] or phase['name'] != c['name'] or c['original_case_sha256'] != phase['original_transcript_sha256']:
            raise ValueError('Different input identities')
        if result['final'] != {n: c['expected'][n] for n in ('rings', 'backings')} or result['callbacks'] != c['expected']['callbacks']:
            raise ValueError('Negative control must preserve ALL final storage observations')
        expected = None if phase['stage'] is None else {n: phase['stage'][n] for n in ('rings', 'backings')}
        if result['stage'] != expected:
            differences.append(c['name'])
    if len(differences) != 30:
        raise ValueError('Expected all30 accepted-stage differences')
    receipt = dict(schema=1, status='negative phase detected', cases=90, phase_differences=differences,
        all_final_storage_and_callbacks_match=True, compiler=cc, compiler_sha256=sha(Path(cc)),
        binary_sha256=sha(binary), private_source_sha256=sha(private), runner_sha256=sha(HERE / 'fixture_runner.cpp'),
        checker_sha256=sha(Path(__file__)), core_freeze_sha256=sha(HERE / 'frozen_identity.json'),
        fixture_manifest_sha256=sha(a.fixture / 'manifest.json'), phase_receipt_sha256=sha(a.phases / 'receipt.json'),
        native_transcript_sha256=sha(out / 'native.jsonl'), whole_window2_parity=False, game_run=False)
    (out / 'receipt.json').write_bytes(encode(receipt))
    print(json.dumps(dict(cases=90, phase_differences=30, final_differences=0, receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__':
    main()
