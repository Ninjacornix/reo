#!/usr/bin/env python3
"""Compare bounded producer PCM artifacts from two completed private sessions.

Equal files establish captured byte equality only: channel keys can be reused,
capture files can be truncated/replaced at queue reset, and no source-generation
or audible-output equivalence follows without additional evidence.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

from analyze_adx_playtest import analyze

MAX_CAPTURE = 48000*2*8
NAME = re.compile(r'cri-pcm-[0-9a-f]{8}\.raw\Z')


def differences(left, right):
    first = next((i for i, (a,b) in enumerate(zip(left,right)) if a != b), None)
    if first is None and len(left) != len(right):
        first = min(len(left),len(right))
    return dict(equal=first is None, left_bytes=len(left), right_bytes=len(right),
        first_difference_byte=first,
        first_difference_sample=None if first is None else first//2,
        left_sha256=hashlib.sha256(left).hexdigest(), right_sha256=hashlib.sha256(right).hexdigest())


def capture_session(path):
    session = path.resolve()
    allowed = Path(__file__).resolve().parents[2] / 'build-native-sjuni'
    if not session.is_relative_to(allowed) or session == allowed:
        raise ValueError('Requires a private session below build-native-sjuni')
    report = analyze(session)
    if report['exit_codes'] != [0] or report['environment'].get('REO_CRI_PCM_DUMP') != '1':
        raise ValueError('Requires one cleanly exited process with explicit producer PCM capture')
    manifest = json.loads((session/'session.json').read_text(encoding='utf-8'))
    work = Path(manifest['players'][0]['workingDirectory']).resolve()
    if not work.is_relative_to(session):
        raise ValueError('Capture directory escaped private session')
    files = {}
    for file in work.glob('cri-pcm-*.raw'):
        if not NAME.fullmatch(file.name) or file.is_symlink() or file.resolve().parent != work or not file.is_file():
            raise ValueError('Unexpected capture file identity')
        size = file.stat().st_size
        if size == 0 or size % 2 or size > MAX_CAPTURE:
            raise ValueError('Capture exceeds the pinned producer extent or is malformed')
        files[file.name] = file.read_bytes()
    if not files:
        raise ValueError('No producer PCM artifacts recorded')
    return dict(session=str(session), game=manifest['game'],
        source_executable_sha256=report['source_executable_sha256'],
        environment=report['environment'], native_adx=report['native_adx'],
        native_adx_stereo=report['native_adx_stereo'], audio=report['audio']), files


def compare(left, right):
    left_report, left_files = capture_session(left)
    right_report, right_files = capture_session(right)
    if left_report['session'] == right_report['session'] or left_report['game'] != right_report['game']:
        raise ValueError('Requires two distinct sessions of the same game')
    shared = sorted(left_files.keys() & right_files.keys())
    return dict(schema=1, left=left_report, right=right_report,
        matched_names=[dict(name=name, **differences(left_files[name], right_files[name])) for name in shared],
        left_only=sorted(left_files.keys()-right_files.keys()),
        right_only=sorted(right_files.keys()-left_files.keys()),
        limitation='Byte comparison of final bounded producer artifacts only. Names do not identify an asset/generation; no speaker, mix, clock, frame or performance equivalence verdict.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--left', required=True, type=Path)
    parser.add_argument('--right', required=True, type=Path)
    args = parser.parse_args()
    result = compare(args.left,args.right)
    output = args.right.resolve()/'pcm-comparison.json'
    if output.exists():
        raise ValueError('Comparison receipt already exists')
    output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(matched_names=result['matched_names'], left_only=result['left_only'],
        right_only=result['right_only'], receipt=str(output)),indent=2))


if __name__ == '__main__':
    main()
