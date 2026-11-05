#!/usr/bin/env python3
"""Report observed native movie-publication capability in a completed owned test."""
import argparse
import json
from pathlib import Path
import re

from analyze_pcm_playtest import analyze as analyze_pcm
from analyze_sjuni_playtest import iter_log

INSTALLED = '[NATIVE-MOVIE-POSITION] synchronous known-caller publication pilot installed'
BODY = re.compile(r'^\[NATIVE-MOVIE-POSITION\] native op=publish calls=(\d+)$')


def parse(lines, environment):
    installations, observations, unavailable, errors = [], [], [], []
    for number, value in enumerate(lines, 1):
        value = value.strip()
        if value == INSTALLED:
            installations.append(number)
        elif match := BODY.fullmatch(value):
            count = int(match[1])
            if (not 0 < count < 1 << 64 or
                    (count > 4 and count & (count - 1)) or
                    (observations and count <= observations[-1]['calls_lower_bound'])):
                errors.append(dict(line=number, error='Invalid/nonmonotonic sparse body counter'))
            else:
                observations.append(dict(line=number, calls_lower_bound=count))
        elif '[NATIVE-MOVIE-POSITION] installation unavailable' in value:
            unavailable.append(dict(line=number, text=value))
    requested = environment.get('REO_NATIVE_MOVIE_POSITION') == '1'
    if len(installations) > 1 or (installations and unavailable):
        errors.append(dict(error='Contradictory/multiple installation evidence'))
    if observations and (not installations or environment.get('REO_NATIVE_MOVIE_POSITION_TRACE') != '1'):
        errors.append(dict(error='Body evidence lacks installation or exact trace opt-in'))
    if (installations or observations) and not requested:
        errors.append(dict(error='Native evidence contradicts launch opt-in'))
    status = ('invalid-evidence' if errors else 'native-publication-observed' if observations else
              'installed-without-body-proof' if installations else 'unavailable' if unavailable else
              'requested-without-installation-proof' if requested else 'not-requested')
    return dict(status=status, installation_lines=installations, body_observations=observations,
                successful_publications_lower_bound=observations[-1]['calls_lower_bound'] if observations and not errors else None,
                unavailable=unavailable, errors=errors)


def analyze(session):
    report = analyze_pcm(session)
    manifest = json.loads((session/'session.json').read_text(encoding='utf-8'))
    log = Path(manifest['players'][0]['logs'])/'stderr.log'
    report['native_movie_position'] = parse(iter_log(log), report['environment'])
    report['limitations'] += [
        'Publication counters follow native commit; installation or a saved setting alone is not executed-body proof.',
        'Sparse counts are lower bounds; uninstrumented original fallbacks and actual unique movie pictures are unknown.',
        'This pilot does not own movie/audio clocks, every caller, guest scheduling or complete playback lifecycle.']
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    session = args.session.resolve()
    report = analyze(session)
    path = session/'movie-position-analysis.json'
    path.write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(report['native_movie_position'], indent=2))
    print('Evidence summary: '+str(path))


if __name__ == '__main__':
    main()
