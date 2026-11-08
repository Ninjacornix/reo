#!/usr/bin/env python3
"""Bounded process-only audio for one identity-checked private game test."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/coop_playtest'))
import coop_playtest as owned


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', type=Path, required=True)
    parser.add_argument('--helper', type=Path, required=True)
    parser.add_argument('--seconds', type=int, default=600)
    parser.add_argument('--name', default='owned-audio')
    args = parser.parse_args()
    folder, manifest = owned.session_record(args.session)
    if not folder.is_relative_to(ROOT / 'build-native-sjuni/playtests') or len(manifest['players']) != 1:
        raise ValueError('One private owned game required')
    if not 1 <= args.seconds <= 900 or not args.name or any(c not in 'abcdefghijklmnopqrstuvwxyz0123456789-' for c in args.name):
        raise ValueError('Bounded duration and simple report name required')
    run = json.loads((folder / 'run.json').read_text())
    if run.get('finishedUtc') or len(run['players']) != 1:
        raise ValueError('One running owned game required')
    target = run['players'][0]
    identity = {k: target[k] for k in ('pid', 'image', 'creationFileTime')}
    image = Path(manifest['players'][0]['image'])
    if image.resolve() != Path(identity['image']).resolve() or sha(image) != manifest['sourceSha256'] or owned.process_identity(identity['pid']) != identity:
        raise ValueError('Owned image/process identity mismatch')
    helper = args.helper.resolve()
    if not helper.is_relative_to(ROOT / 'build-native-sjuni') or not helper.is_file():
        raise ValueError('Explicit private capture helper required')
    output = folder / (args.name + '.wav')
    receipt_path = folder / (args.name + '-receipt.json')
    if any(p.exists() for p in (output, Path(str(output) + '.packets.csv'), receipt_path)):
        raise ValueError('Fresh evidence names required')
    command = [str(helper), str(identity['pid']), str(identity['creationFileTime']), identity['image'], str(args.seconds), str(output)]
    result = dict(schema=1, identity=identity, scope='owned-process-tree-only',
                  executable_sha256=manifest['sourceSha256'], helper_sha256=sha(helper),
                  source_sha256=sha(Path(__file__)), command=command, status='failed',
                  microphone_capture=False, endpoint_mix_capture=False, game_writes=False,
                  limitations=['OS audio packets and QPC observations do not independently prove audible/video synchronization.'])
    started = time.monotonic()
    try:
        process = subprocess.run(command, capture_output=True, text=True, timeout=args.seconds + 30, env=dict(os.environ))
        result.update(exit_code=process.returncode, stdout=process.stdout, stderr=process.stderr)
        if process.returncode:
            raise RuntimeError('Process-only audio capture failed: ' + process.stderr.strip())
        result['capture'] = json.loads(process.stdout)
        result['status'] = 'completed'
    finally:
        result['elapsed_seconds'] = time.monotonic() - started
        result['outputs_sha256'] = {p.name: sha(p) for p in (output, Path(str(output) + '.packets.csv')) if p.exists()}
        receipt_path.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result['capture'], indent=2))


if __name__ == '__main__':
    main()
