"""Verify read-only room snapshots and native replacement logs from a round trip.

Usage: python tools/check_randomizer_revisit.py <coop_playtest session>
Snapshots must include phase and transitionRequest; a room number during loading
does not count as completed navigation. This is not full-scenario validation.
"""
import collections
import json
from pathlib import Path
import re
import sys


def verify(folder):
    names = ('actors-room1-before.json', 'actors-room3.json',
             'actors-room1-after.json', 'actors-room1-late.json')
    snapshots = [json.loads((folder / name).read_text())[-1] for name in names]
    checks = {'orderedSnapshots': all(a['unixMs'] < b['unixMs']
                                     for a, b in zip(snapshots, snapshots[1:]))}
    results = []
    for initial in snapshots[0]['players']:
        number = initial['number']
        states = [next(p for p in s['players'] if p['number'] == number) for s in snapshots]
        log = (folder / f'player{number}' / 'logs/stderr.log').read_text(errors='replace')
        ready = re.findall(r'ready actor=.*? spawn=(\d+) type=(\d+) model=(\d+)', log)
        handoffs = re.findall(r'handoff actor=.*? spawn=(\d+) source=\d+:\d+ replacement=(\d+):(\d+)', log)
        counts = collections.Counter(tuple(map(int, r)) for r in ready)
        replacements = {spawn: (kind, model) for spawn, kind, model in counts}
        actor_maps = [{a['spawn']: a for a in s['actors']} for s in states]
        retained = bool(replacements) and all(
            spawn in m and (m[spawn]['type'], m[spawn]['model']) == profile
            for spawn, profile in replacements.items() for m in (actor_maps[0], actor_maps[2], actor_maps[3]))
        checks.update({
            f'p{number}CompletedRoundTrip': states[0]['room'] == states[2]['room'] == states[3]['room']
                and states[1]['room'] != states[0]['room'],
            f'p{number}FinishedLoading': all(s['phase'] == 2 and s['transitionRequest'] == 0 for s in states),
            f'p{number}PlayerSurvived': all(s['playerHp'] > 0 for s in states),
            f'p{number}SameReplacementProfiles': retained,
            f'p{number}ReconstructedSameSpawns': bool(counts) and all(n >= 2 for n in counts.values()),
            f'p{number}AllHandoffsFinished': bool(handoffs) and collections.Counter(handoffs) == collections.Counter(ready),
            f'p{number}NoMissingFunctions': not re.search(r'Function at address .* not found', log),
            f'p{number}UpdatedAfterReturn': any(int(t) > snapshots[2]['unixMs']
                for t in re.findall(r'\[TEST-ENEMY-SPECIES\].* unixMs=(\d+)', log)),
        })
        results.append({'player': number, 'rooms': [s['room'] for s in states],
                        'replacements': replacements, 'reinitializations': [list(k) + [v] for k, v in counts.items()]})
    return {'passed': all(checks.values()), 'checks': checks, 'players': results,
            'scenarioCompletionVerified': False}


if __name__ == '__main__':
    try:
        result = verify(Path(sys.argv[1]))
    except (OSError, ValueError, KeyError, StopIteration) as error:
        result = {'passed': False, 'error': str(error)}
    print(json.dumps(result, indent=2))
    sys.exit(0 if result['passed'] else 1)
