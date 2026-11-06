#!/usr/bin/env python3
"""Compare the PCM storage-only projection; decoded PCM is supplied input."""
import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
from original_projection import ROOT, HERE, sha, encode


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--fixture', type=Path, required=True)
    p.add_argument('--cxx', required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--negative-padding', action='store_true')
    a = p.parse_args(); out = a.output.resolve(); cc = shutil.which(a.cxx)
    if not cc or out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/adx-pcm-store'):
        raise ValueError('Exact compiler and fresh scoped output required')
    freeze = json.loads((HERE / 'frozen_identity.json').read_bytes())
    for n, digest in freeze['files'].items():
        if sha(ROOT / n) != digest:
            raise ValueError('Frozen core drift: ' + n)
    manifest = json.loads((a.fixture / 'manifest.json').read_bytes())
    if sha(a.fixture / 'cases.json') != manifest['cases_sha256'] or sha(HERE / 'frozen_identity.json') != manifest['core_freeze_sha256']:
        raise ValueError('Frozen projection drift')
    cases = json.loads((a.fixture / 'cases.json').read_bytes()); out.mkdir(parents=True)
    env = dict(os.environ); env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    source = HERE / 'pcm_store.cpp'
    if a.negative_padding:
        text = source.read_text(encoding='utf-8'); anchor = 'samples.size() * 2'
        # Keep logical publication equal but truncate the raw copy. The original
        # total33/free96 padding comparison must detect this tempting shortcut.
        if text.count('static_cast<std::int32_t>(pcm.left.size() * 2)') != 1:
            raise ValueError('Negative padding anchor changed')
        source = out / 'negative.cpp'
        source.write_text(text.replace('static_cast<std::int32_t>(pcm.left.size() * 2)', 'produced * 2'), encoding='utf-8', newline='\n')
    binary = out / 'fixture.exe'
    command = [cc, '-std=c++20', '-O1', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-I' + str(HERE),
               str(source), str(ROOT / 'game/native/sjrb/sjrb.cpp'), str(HERE / 'fixture_runner.cpp'), '-o', str(binary)]
    build = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, timeout=90)
    (out / 'build.txt').write_text(build.stdout + build.stderr, encoding='utf-8', newline='\n')
    if build.returncode:
        raise RuntimeError(build.stderr)
    inputs = '\n'.join(f"{c['name']} {c['channels']} {c['queued_bytes']} {c['operation']} {c['produced']} {c['published']} {c['left_hex'] or '-'} {c['right_hex'] or '-'}" for c in cases) + '\n'
    run = subprocess.run([str(binary)], input=inputs, cwd=ROOT, env=env, capture_output=True, text=True, timeout=60)
    (out / 'native.jsonl').write_text(run.stdout, encoding='utf-8', newline='\n')
    actual = [json.loads(line) for line in run.stdout.splitlines()]
    if run.returncode or len(actual) != len(cases):
        raise RuntimeError(f'Native fixture failed: {run.returncode}, {len(actual)} rows; {run.stderr}')
    mismatches = [c['name'] for c, r in zip(cases, actual, strict=True)
                  if r != dict(name=c['name'], **c['expected'])]
    receipt = dict(schema=1, status='different' if mismatches else 'matched', cases=len(cases), mismatches=mismatches,
        compiler=cc, compiler_sha256=sha(Path(cc)), command=command, executable_sha256=sha(binary),
        fixture_manifest_sha256=sha(a.fixture / 'manifest.json'), core_freeze_sha256=sha(HERE / 'frozen_identity.json'),
        native_transcript_sha256=sha(out / 'native.jsonl'), negative_padding=a.negative_padding,
        sources={str(n.relative_to(ROOT)): sha(n) for n in [HERE / 'pcm_store.cpp', HERE / 'pcm_store.hpp',
            HERE / 'fixture_runner.cpp', HERE / 'compare_original.py', HERE / 'original_projection.py']},
        whole_window2_parity=False, codec_parity=False, game_run=False)
    (out / 'receipt.json').write_bytes(encode(receipt))
    if a.negative_padding:
        if not mismatches or 'pcm-tail-stereo-total-33-free-96' not in mismatches:
            raise RuntimeError('Negative padding control was not detected')
    elif mismatches:
        raise RuntimeError('PCM storage projection differs: ' + ', '.join(mismatches))
    print(json.dumps(dict(status=receipt['status'], cases=len(cases), mismatches=len(mismatches), receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__':
    main()
