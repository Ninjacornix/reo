"""Verify a spawn-replacement run against a mod-disabled baseline.

Usage: python tools/check_enemy_spawn_session.py baseline.json randomized.json
Screenshots still require visual review. Process survival is not gameplay proof.
"""
import json
from collections import Counter
import re
import sys
from datetime import datetime
from pathlib import Path
from check_enemy_randomizer_session import session


def verify(baseline, randomized):
    _, base_mods, before = session(baseline)
    receipt, mods, log = session(randomized)
    selected = [m['enemyRandomizer'] for m in mods if m.get('enemyRandomizer')]
    if base_mods or len(selected) != 1 or selected[0]['mode'] != 'enemyTypes':
        raise ValueError('Expected an unmodded baseline and one enemyTypes package')
    config = selected[0]
    pool = {(p['type'], p['model']) for p in config['pool']}

    def initial_table(text):
        result = {}
        for address, data in re.findall(r'\[TEST-ENEMIES\] record=([0-9a-f]+) bytes=([0-9a-f]+)', text):
            result.setdefault(address, data)
        return result

    handoffs = re.findall(r'handoff actor=([0-9a-f]+) spawn=(\d+) source=(\d+):(\d+) replacement=(\d+):(\d+)', log)
    ready = re.findall(r'ready actor=([0-9a-f]+) spawn=(\d+) type=(\d+) model=(\d+) bones=\d+ animation=\d+ callback=([0-9a-f]+)', log)
    updates = re.findall(r'\[TEST-ENEMY-SPECIES\] actor=([0-9a-f]+) spawn=(\d+) type=(\d+) model=(\d+) hp=(\d+) state=(\d+)/(\d+)/(\d+) xyz=([^ ]+) callback=([0-9a-f]+)', log)
    originals = {d[0]: (d[2], d[3]) for raw in initial_table(before).values() for d in [bytes.fromhex(raw)]}
    observed = []
    for actor, spawn, kind, model, callback in ready:
        samples = [u for u in updates if u[:4] == (actor, spawn, kind, model) and u[-1] == callback]
        positions = {u[8] for u in samples}
        states = {u[5:8] for u in samples}
        observed.append(dict(actor=actor, spawn=int(spawn), type=int(kind), model=int(model),
                             samples=len(samples), positions=len(positions), states=len(states),
                             moved=len(samples) >= 3 and len(positions) >= 2))
    checks = {
        'cleanExit': receipt.get('exited') is True and receipt.get('exitCode') == 0,
        'noCheatEffectsOrPatches': not any(m.get('effects') or m.get('patches') for m in mods),
        'seedMatches': f'[MOD-ENEMY-SPAWN-1] installed seed={config["seed"]}' in log,
        'originalSpawnTablePreserved': bool(initial_table(before)) and initial_table(before) == initial_table(log),
        'speciesActuallyChanged': any(a[2] != a[4] for a in handoffs),
        'handoffsUseOriginalSpawns': bool(handoffs) and all(originals.get(int(a[1])) == (int(a[2]), int(a[3])) for a in handoffs),
        'choicesFromConfiguredPool': bool(handoffs) and all((int(a[4]), int(a[5])) in pool for a in handoffs),
        'allHandoffsInitialized': bool(handoffs) and not (Counter(h[:2]+h[4:6] for h in handoffs) - Counter(r[:4] for r in ready)),
        'replacementsKeptUpdatingAndMoved': bool(observed) and all(a['moved'] for a in observed),
        'noMissingGuestFunctions': not re.search(r'Function at address .* not found', log),
    }
    if '[MOD-SESSION-2]' in log:
        ticks = [int(t) for t in re.findall(r'\[TEST-ENEMY-SPECIES\].* unixMs=(\d+)', log)]
        exit_receipt = json.loads((Path(receipt['logs'])/'exit.json').read_text(encoding='utf-8-sig'))
        ended = datetime.fromisoformat(exit_receipt['utc'].replace('Z','+00:00')).timestamp()*1000
        checks['enemyUpdatesContinuedUntilExit'] = bool(ticks) and abs(ended-max(ticks)) < 15000
    return dict(passed=all(checks.values()), checks=checks, replacements=observed,
                session=receipt['logs'], screenshotsRequireVisualReview=True,
                scenarioCompletionVerified=False)


if __name__ == '__main__':
    try:
        result = verify(sys.argv[1], sys.argv[2])
        print(json.dumps(result, indent=2))
        sys.exit(0 if result['passed'] else 1)
    except (ValueError, KeyError, IndexError, OSError) as error:
        print(json.dumps({'passed': False, 'error': str(error)}))
        sys.exit(1)
