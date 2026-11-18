#!/usr/bin/env python3
"""Evidence summary for a completed private native-resource/scalar candidate.

Availability, executed native payloads, failures and later gameplay observations
remain separate. This tool does not execute the game or assert equivalence.
"""
import argparse
import json
from pathlib import Path
import re

from analyze_cd_owner_playtest import analyze as analyze_owned
from analyze_sjuni_playtest import iter_log

READ_TAG = '[NATIVE-RESOURCE-READS] '
SCALAR_TAG = '[NATIVE-DISC-STREAM] '
SCALAR_INSTALLED = 'quiescent scalar pilot installed; requests remain original'
OPS = {'seek', 'tell', 'status', 'transferred'}


def parse_native(lines, environment):
    setups, failures, notices, scalar_installs = [], [], [], []
    successes, scalar = [], {}
    previous = 0
    for number, line in enumerate(lines, 1):
        record = dict(line=number, text=line)
        if READ_TAG in line:
            fragment = line[line.index(READ_TAG):]
            setup = re.match(re.escape(READ_TAG) + r'mounted import=([12]) sources=(\d+) '
                r'route=([0-9a-f]{64}) manifest=([0-9a-f]{64}) overlay=(none|[0-9a-f]{64}) '
                r'mode=synchronous-exact maxBytes=(\d+)(?=$|\s|\[)', fragment)
            payload = re.match(re.escape(READ_TAG) + r'payload successes=(\d+) lba=(\d+) '
                r'sectors=(\d+) bytes=(\d+)(?=$|\s|\[)', fragment)
            if setup:
                version, sources, route, manifest, overlay, maximum = setup.groups()
                if int(sources) < 2 or int(maximum) < 2048:
                    raise ValueError('Invalid native mount setup on line ' + str(number))
                setups.append(dict(**record, version=int(version), sources=int(sources),
                    route_sha256=route, manifest_sha256=manifest, overlay=overlay, max_bytes=int(maximum)))
            elif payload:
                count, lba, sectors, size = map(int, payload.groups())
                if count <= previous or not 1 <= sectors <= 0x4000 or size != sectors * 2048 or not 0 <= lba <= 0xffffffff:
                    raise ValueError('Invalid/regressing native payload proof on line ' + str(number))
                previous = count
                successes.append(dict(**record, calls=count, lba=lba, sectors=sectors, bytes=size))
            elif fragment.startswith(READ_TAG + 'payload failed ') or fragment.startswith(READ_TAG + 'payload exception;'):
                failures.append(record)
            elif fragment.startswith(READ_TAG + 'payload successes=') or fragment.startswith(READ_TAG + 'mounted import='):
                raise ValueError('Malformed native proof on line ' + str(number))
            else:
                notices.append(record)
        if SCALAR_TAG in line:
            fragment = line[line.index(SCALAR_TAG):]
            if fragment.startswith(SCALAR_TAG + SCALAR_INSTALLED):
                scalar_installs.append(record)
            elif match := re.match(re.escape(SCALAR_TAG) + r'native op=(\w+) calls=(\d+) slot=(\d+)(?=$|\s|\[)', fragment):
                operation, count, slot = match.groups()
                count, slot = int(count), int(slot)
                old = scalar.get(operation, dict(body_count_lower_bound=0, proof_lines=[]))
                if operation not in OPS or count <= old['body_count_lower_bound'] or slot >= 40:
                    raise ValueError('Invalid scalar proof on line ' + str(number))
                old['body_count_lower_bound'] = count
                old['proof_lines'].append(number)
                scalar[operation] = old
            elif fragment.startswith(SCALAR_TAG + 'native op='):
                raise ValueError('Malformed scalar proof on line ' + str(number))
    if len(setups) > 1 or len(scalar_installs) > 1:
        raise ValueError('Expected at most one native setup per process')
    if successes or failures:
        if not setups or (successes and successes[0]['line'] < setups[0]['line']):
            raise ValueError('Native payload attempt without prior verified mount setup')
        if any(x['bytes'] > setups[0]['max_bytes'] for x in successes):
            raise ValueError('Native payload exceeds its recorded mount read cap')
    if setups and any(environment.get(key) != value for key, value in
                      [('REO_NATIVE_RESOURCE_READS','1'), ('REO_GAME_PAK','1'), ('REO_CD_ASYNC','0')]):
        raise ValueError('Native mount proof contradicts explicit synchronous PAK launch admission')
    if scalar_installs and environment.get('REO_NATIVE_DISC_STREAM') != '1':
        raise ValueError('Native scalar installation contradicts launch configuration')
    if scalar and (not scalar_installs or environment.get('REO_NATIVE_DISC_STREAM_TRACE') != '1'):
        raise ValueError('Scalar execution proof without traced installation')
    return dict(resource_setup=setups, payload_success_lower_bound=previous,
                payload_proofs=successes, payload_failures=failures, setup_notices=notices,
                scalar_installations=scalar_installs, scalar_body_proofs=scalar)


def analyze(session):
    report = analyze_owned(session)
    manifest = json.loads((session / 'session.json').read_text(encoding='utf-8'))
    lines = iter_log(Path(manifest['players'][0]['logs']) / 'stderr.log')
    report['native_resource_and_scalar'] = parse_native(lines, report['environment'])
    report['limitations'] += [
        'A mount setup proves actual admitted identity; a saved setting alone proves no capability.',
        'Sampled successful payload counts do not prove every route or original completion/SJ publication.',
        'Native failed reads preserve destination while legacy HLE may zero/partially modify it.',
        'Original reply/callback still runs after handled failure; guest-visible error reconstruction remains open.',
        'No automatic equivalence, performance, native-engine or compatibility-removal verdict.']
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    report = analyze(args.session.resolve())
    output = args.session.resolve() / 'resource-analysis.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    evidence = report['native_resource_and_scalar']
    print(json.dumps(dict(source_executable_sha256=report['source_executable_sha256'],
        exit_codes=report['exit_codes'], resource_mount_observed=bool(evidence['resource_setup']),
        payload_success_lower_bound=evidence['payload_success_lower_bound'],
        payload_failure_count=len(evidence['payload_failures']),
        scalar_body_proofs=evidence['scalar_body_proofs'], audio=report['audio'], routes=report['routes']), indent=2))
    print('Evidence summary: ' + str(output))


if __name__ == '__main__':
    main()
