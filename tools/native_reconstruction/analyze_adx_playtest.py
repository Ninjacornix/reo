#!/usr/bin/env python3
"""Summarize traced synchronous ADX execution in a completed owned candidate."""
import argparse
import json
from pathlib import Path
import re

from analyze_resource_playtest import analyze as analyze_resources

TAG = '[NATIVE-ADX-BLOCK] '
INSTALLED = TAG + 'synchronous keyed mono pilot installed count=1..16'
STEREO_TAG = '[NATIVE-ADX-STEREO] '
STEREO_INSTALLED = STEREO_TAG + 'synchronous stereo/downmix pilot installed count=1..16'


def parse_adx(lines, environment):
    installations, proofs, notices = [], [], []
    previous = 0
    for number, line in enumerate(lines, 1):
        if TAG not in line:
            continue
        fragment = line[line.index(TAG):]
        record = dict(line=number, text=line)
        if fragment.startswith(INSTALLED):
            installations.append(record)
        elif match := re.match(re.escape(TAG) + r'native op=keyed-mono calls=(\d+) blocks=(\d+) marker=([01])(?=$|\s|\[)', fragment):
            count, blocks, marker = map(int, match.groups())
            if count <= previous or not 0 <= blocks <= 16 or (blocks == 0 and not marker):
                raise ValueError('Invalid ADX execution proof on line ' + str(number))
            if not installations:
                raise ValueError('ADX execution without prior installation')
            previous = count
            proofs.append(dict(**record, calls=count, blocks=blocks, marker=bool(marker)))
        elif fragment.startswith(TAG + 'native op='):
            raise ValueError('Malformed ADX proof on line ' + str(number))
        else:
            notices.append(record)
    if len(installations) > 1:
        raise ValueError('Multiple ADX installations for one process')
    if installations and environment.get('REO_NATIVE_ADX_BLOCK') != '1':
        raise ValueError('ADX installation contradicts launch configuration')
    if proofs and environment.get('REO_NATIVE_ADX_BLOCK_TRACE') != '1':
        raise ValueError('ADX execution proof without explicit trace admission')
    return dict(installations=installations, native_call_lower_bound=previous,
                sampled_pcm_sample_lower_bound=sum(x['blocks'] * 32 for x in proofs),
                execution_proofs=proofs, notices=notices)


def parse_stereo(lines, environment):
    installations, notices, operations = [], [], {}
    for number, line in enumerate(lines, 1):
        if STEREO_TAG not in line:
            continue
        fragment = line[line.index(STEREO_TAG):]
        record = dict(line=number, text=line)
        if fragment.startswith(STEREO_INSTALLED):
            installations.append(record)
        elif match := re.match(re.escape(STEREO_TAG) + r'native op=(stereo|downmix) calls=(\d+) pairs=(\d+) marker=([012])(?=$|\s|\[)', fragment):
            operation, count, pairs, marker = match.groups()
            count, pairs, marker = map(int, (count, pairs, marker))
            old = operations.setdefault(operation, dict(native_call_lower_bound=0,
                sampled_pcm_sample_lower_bound=0, execution_proofs=[]))
            if not installations or count <= old['native_call_lower_bound'] or not 0 <= pairs <= 8:
                raise ValueError('Invalid stereo execution proof on line ' + str(number))
            old['native_call_lower_bound'] = count
            old['sampled_pcm_sample_lower_bound'] += pairs*64
            old['execution_proofs'].append(dict(**record, calls=count, pairs=pairs, marker=marker))
        elif fragment.startswith(STEREO_TAG + 'native op='):
            raise ValueError('Malformed stereo proof on line ' + str(number))
        else:
            notices.append(record)
    if len(installations) > 1:
        raise ValueError('Multiple stereo installations for one process')
    if installations and environment.get('REO_NATIVE_ADX_STEREO') != '1':
        raise ValueError('Stereo installation contradicts launch configuration')
    if operations and environment.get('REO_NATIVE_ADX_STEREO_TRACE') != '1':
        raise ValueError('Stereo execution proof without explicit trace admission')
    return dict(installations=installations, operations=operations, notices=notices)


def analyze(session):
    report = analyze_resources(session)
    manifest = json.loads((session / 'session.json').read_text(encoding='utf-8'))
    lines = (Path(manifest['players'][0]['logs']) / 'stderr.log').read_text(
        encoding='utf-8', errors='replace').splitlines()
    report['native_adx'] = parse_adx(lines, report['environment'])
    report['native_adx_stereo'] = parse_stereo(lines, report['environment'])
    report['limitations'] += [
        'Installation is availability evidence; only post-commit trace records prove native calls.',
        'PCM sample lower bound sums logged calls only, without extrapolating sampled block counts.',
        'Decode commits do not prove speaker output, stream completion, clock equivalence or a speedup.']
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    session = args.session.resolve()
    report = analyze(session)
    output = session / 'adx-analysis.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(source_executable_sha256=report['source_executable_sha256'],
        exit_codes=report['exit_codes'], native_adx=report['native_adx'],
        native_adx_stereo=report['native_adx_stereo']), indent=2))
    print('Evidence summary: ' + str(output))


if __name__ == '__main__':
    main()
