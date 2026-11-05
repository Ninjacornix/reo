#!/usr/bin/env python3
"""Summarize a completed, owned SJUNI playtest without executing the game.

Reports scoped evidence and explicit gaps, never an automatic playback/parity or
performance verdict. Proof counters are lower bounds after native body commit.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
OPERATIONS = {'get', 'put', 'unget', 'queued_bytes', 'availability', 'queued_nodes', 'free_nodes'}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def analyze(session):
    session = session.resolve()
    if not session.is_relative_to(ROOT / 'build-native-sjuni'):
        raise ValueError('Use the separate candidate session under build-native-sjuni')
    manifest = json.loads((session / 'session.json').read_text(encoding='utf-8'))
    run = json.loads((session / 'run.json').read_text(encoding='utf-8'))
    if (manifest.get('owner') != 'reo-coop-playtest' or Path(manifest['session']).resolve() != session or
        len(manifest['players']) != 1 or not run.get('finishedUtc') or len(run['players']) != 1):
        raise ValueError('A completed single-player owned-process test is required')
    player, identity = manifest['players'][0], run['players'][0]
    image = Path(player['image']).resolve()
    if (not image.is_relative_to(session) or Path(identity['image']).resolve() != image or
        not identity['creationFileTime'] or sha(image) != manifest['sourceSha256']):
        raise ValueError('Copied executable / captured process identity mismatch')
    logs = Path(player['logs']).resolve()
    if not logs.is_relative_to(session):
        raise ValueError('Logs escaped private session')
    lines = (logs / 'stderr.log').read_text(encoding='utf-8', errors='replace').splitlines()
    proofs, notices, audio, movies, routes = {}, [], [], [], []
    for number, line in enumerate(lines, 1):
        if '[native-sjuni]' in line:
            match = re.fullmatch(r'\[native-sjuni\] native op=(\w+) guarded=([01]) calls=(\d+) queue=(\d+) slot=(\d+)', line)
            if match:
                operation, guarded, calls, queue, slot = match.groups()
                calls, queue, slot = int(calls), int(queue), int(slot)
                if operation not in OPERATIONS or calls < 1 or queue > 3 or slot > 63:
                    raise ValueError('Invalid proof record on log line ' + str(number))
                key = operation + ('_guarded' if guarded == '1' else '_canonical')
                prior = proofs.get(key, {'body_count_lower_bound': 0, 'proof_lines': []})
                if calls <= prior['body_count_lower_bound']:
                    raise ValueError('Proof counter regressed or repeated within this process')
                prior['body_count_lower_bound'] = calls
                prior['proof_lines'].append(number)
                proofs[key] = prior
            else:
                notices.append({'line': number, 'text': line})
        match = re.search(r'\[CRI-AUDIO\] frames=(\d+) signal=(\d+) underrun=(\d+) queuedSamples=(\d+) host=([01])', line)
        if match:
            audio.append(dict(zip(('frames', 'signal', 'underrun', 'queued_samples', 'host'), map(int, match.groups()))))
        match = re.search(r'\[CRI-SYNC\] movie ns=(\d+).*decoded=(\d+)/(\d+)', line)
        if match:
            movies.append({'line': number, 'ns': int(match[1]), 'decoded': int(match[2]), 'duration': int(match[3])})
        if '[TEST-ROUTE]' in line and ('reached' in line or 'timeout' in line):
            routes.append({'line': number, 'text': line})
    if proofs and identity['environment'].get('REO_NATIVE_SJUNI') != '1':
        raise ValueError('Native proof with opt-in disabled: inspect build/config provenance')
    return dict(schema=1, session=str(session), source_executable_sha256=manifest['sourceSha256'],
                process_identity={k: identity[k] for k in ('pid', 'image', 'creationFileTime')},
                evidence_sha256={name: sha(session / name) for name in ('session.json', 'run.json')} |
                                {'stderr.log': sha(logs / 'stderr.log')},
                environment=identity['environment'], elapsed_seconds=run['elapsedSeconds'],
                exit_codes=run['exitCodes'], stop_reason=run.get('stopReason'),
                native_results=run['nativeResults'], native_body_proof=proofs, native_notices=notices,
                routes=routes,
                audio=dict(report_windows=len(audio), frames=sum(x['frames'] for x in audio),
                           signal_frames=sum(x['signal'] for x in audio),
                           underrun_frames=sum(x['underrun'] for x in audio),
                           host_ready_windows=sum(x['host'] for x in audio),
                           host_signal_windows=sum(x['host'] == 1 and x['signal'] > 0 for x in audio)),
                movie_samples=movies,
                limitations=['Native counters are lower bounds; guarded proof precedes original leave/epilogue.',
                             'Audio producer/output counters do not establish subjective sound quality.',
                             'Movie timing logs do not prove visible image correctness.',
                             'A duration-limit termination does not validate clean shutdown.',
                             'This summary makes no automatic equivalence, performance or full-migration verdict.'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    report = analyze(args.session)
    output = args.session.resolve() / 'sjuni-analysis.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: report[k] for k in ('source_executable_sha256', 'exit_codes', 'stop_reason',
                                            'native_body_proof', 'audio', 'routes')}, indent=2))
    print('Evidence summary: ' + str(output))


if __name__ == '__main__':
    main()
