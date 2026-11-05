#!/usr/bin/env python3
"""Summarize a completed owned CD-worker candidate without running the game.

Read proof and callback-return proof are separate. Neither proves subsequent
SRD/SJ publication, playback equivalence, borrowed-buffer lifetime or a speedup.
"""
import argparse
import json
from pathlib import Path
import re

from analyze_sjuni_playtest import analyze as analyze_common

TAG = '[NATIVE-CD-OWNER] '
REGISTERED = 'bounded session worker registered with runtime lifecycle'
JOINED = 'session joined before bootstrap export/destruction'


def owner_records(lines):
    registration, joins, reads, completions, errors, notices = [], [], [], [], [], []
    previous = 0
    for number, line in enumerate(lines, 1):
        if TAG not in line:
            continue
        record = dict(line=number, text=line)
        if line == TAG + REGISTERED:
            registration.append(record)
        elif line == TAG + JOINED:
            joins.append(record)
        elif match := re.fullmatch(re.escape(TAG) + r'read lsn=(\d+) n=(\d+) dst=([0-9a-f]{8}) result=(ok|FAIL)', line):
            lba, count, destination, result = match.groups()
            reads.append(dict(**record, lba=int(lba), sectors=int(count),
                              destination=int(destination, 16), result=result))
            if result != 'ok':
                errors.append(record)
        elif match := re.fullmatch(re.escape(TAG) + r'completion calls=(\d+) dispatches=(\d+)', line):
            count, dispatches = map(int, match.groups())
            if count <= previous or not 1 <= dispatches <= 256:
                raise ValueError('Invalid or regressing completion proof on line ' + str(number))
            previous = count
            completions.append(dict(**record, calls=count, dispatches=dispatches))
        else:
            notices.append(record)
            if any(text in line for text in ('completion stopped:', 'completion dispatch limit',
                                             'completion continuation unregistered', 'worker join failed',
                                             'runtime stop raised', 'completion metadata changed')):
                errors.append(record)
    if len(registration) > 1 or len(joins) > 1:
        raise ValueError('Expected at most one session registration/join per process')
    if (reads or completions or joins) and not registration:
        raise ValueError('Owner work/join proof without session registration')
    if registration and joins and registration[0]['line'] >= joins[0]['line']:
        raise ValueError('Owner join precedes registration')
    if joins and any(x['line'] > joins[0]['line'] for x in reads + completions):
        raise ValueError('Owner activity follows the claimed completed join')
    return dict(registrations=registration, joins=joins, logged_reads=reads,
                callback_returns=completions, callback_return_lower_bound=previous,
                errors=errors, notices=notices)


def analyze(session):
    report = analyze_common(session)
    manifest = json.loads((session / 'session.json').read_text(encoding='utf-8'))
    lines = (Path(manifest['players'][0]['logs']) / 'stderr.log').read_text(
        encoding='utf-8', errors='replace').splitlines()
    owner = owner_records(lines)
    if owner['registrations'] and report['environment'].get('REO_NATIVE_CD_OWNER') != '1':
        raise ValueError('Owner registration while explicit opt-in was disabled')
    clean = (report['exit_codes'] == [0] and report['stop_reason'] != 'duration-limit' and
             all(x.get('outcome') not in ('fatal-diagnostic', 'nonzero-exit')
                 for x in report['native_results']))
    report['cd_owner'] = owner
    report['scoped_owner_checks'] = dict(
        native_registration_observed=bool(owner['registrations']),
        callback_return_observed=bool(owner['callback_returns']),
        explicit_owner_errors_observed=bool(owner['errors']),
        joined_with_clean_process_exit=bool(owner['joins']) and clean)
    report['limitations'] += [
        'Read lines are capped at 40; callback counters are sampled lower bounds.',
        'Callback PC=0 establishes dispatcher return, not SRD status or borrowed SJ publication.',
        'Runtime stop/join evidence does not establish mid-game stop/close/reuse safety.',
        'No automated image, waveform, media equivalence or performance verdict.']
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    report = analyze(args.session.resolve())
    output = args.session.resolve() / 'cd-owner-analysis.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: report[k] for k in ('source_executable_sha256', 'exit_codes',
          'scoped_owner_checks', 'audio', 'routes')}, indent=2))
    print('Evidence summary: ' + str(output))


if __name__ == '__main__':
    main()
