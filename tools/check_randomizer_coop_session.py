"""Check actual native co-op logs; matching seeds alone are not gameplay proof.

Usage: python tools/check_randomizer_coop_session.py <coop_playtest session>
Room revisits and complete-scenario progression are reported separately.
"""
import collections
import json
from pathlib import Path
import re
import sys
from datetime import datetime


def inspect(folder):
    log = (folder / "stderr.log").read_text(errors="replace")
    items = re.findall(r'\[MOD-ITEM-RANDOMIZER-1\] item=([0-9a-f]+) ([0-9a-f]+:\d+) -> ([0-9a-f]+:\d+) metadata=(\d+)', log)
    choices = re.findall(r'\[MOD-ENEMY-CHOICE-2\] scenario=(\d+) room=(\d+) spawn=(\d+) type=(\d+) model=(\d+)', log)
    picks, rooms = collections.defaultdict(set), collections.defaultdict(set)
    for scenario, room, spawn, kind, model in choices:
        picks[(scenario, spawn)].add((kind, model))
        rooms[(scenario, spawn)].add(room)
    ready = re.findall(r'ready actor=([0-9a-f]+) spawn=(\d+) type=(\d+) model=(\d+) bones=\d+ animation=\d+ callback=([0-9a-f]+)', log)
    handoffs = re.findall(r'handoff actor=([0-9a-f]+) spawn=(\d+) source=\d+:\d+ replacement=(\d+):(\d+)', log)
    ticks = [int(t) for t in re.findall(r'\[TEST-ENEMY-SPECIES\].* unixMs=(\d+)', log)]
    updates = re.findall(r'\[TEST-ENEMY-SPECIES\] actor=([0-9a-f]+) spawn=(\d+) type=(\d+) model=(\d+) hp=(\d+) state=(\d+)/(\d+)/(\d+) xyz=([^ ]+) callback=([0-9a-f]+)', log)
    observations = []
    for actor, spawn, kind, model, callback in ready:
        samples = [u for u in updates if u[:4] == (actor, spawn, kind, model) and u[-1] == callback]
        observations.append(dict(spawn=spawn, type=kind, model=model, samples=len(samples),
                                 positions=len({u[8] for u in samples})))
    return dict(items=items, picks=picks, rooms=rooms, ready=ready, observations=observations,
                lastTick=max(ticks) if ticks else 0, handoffs=handoffs,
                missing=bool(re.search(r'Function at address .* not found', log)))


def verify(path):
    session = json.loads((path / "session.json").read_text(encoding="utf-8-sig"))
    players = [inspect(Path(p["logs"])) for p in session["players"]]
    run = json.loads((path / "run.json").read_text(encoding="utf-8-sig"))
    ended = datetime.fromisoformat(run["finishedUtc"].replace('Z','+00:00')).timestamp()*1000
    if len(players) < 2:
        raise ValueError("At least two actual clients required")
    checks = {
        "identicalInitialItemLayouts": bool(players[0]["items"]) and all(p["items"] == players[0]["items"] for p in players),
        "choicesObservedOnEveryClient": all(p["picks"] for p in players),
        "choicesStableWithinEachClient": all(len(v) == 1 for p in players for v in p["picks"].values()),
        "identicalChoices": all(p["picks"] == players[0]["picks"] for p in players),
        "multipleReplacementSpeciesOnEveryClient": all(len({r[2] for r in p["ready"]}) >= 2 for p in players),
        "replacementsActuallyUpdatedAndMoved": all(p["observations"] and all(o["samples"] >= 3 and o["positions"] >= 2 for o in p["observations"]) for p in players),
        "noMissingGuestFunctions": not any(p["missing"] for p in players),
        "allHandoffsInitialized": all(p["handoffs"] and not (collections.Counter(p["handoffs"])-collections.Counter(r[:4] for r in p["ready"])) for p in players),
        "enemyUpdatesContinuedUntilExit": all(p["lastTick"] and abs(ended-p["lastTick"]) < 15000 for p in players),
    }
    ready_sets = [{tuple(r[1:4]) for r in p["ready"]} for p in players]
    checks["identicalInitializedReplacementActors"] = bool(ready_sets[0]) and all(s == ready_sets[0] for s in ready_sets)
    return dict(passed=all(checks.values()), checks=checks,
                observations=[p["observations"] for p in players],
                spawnObservedAcrossRoomsOnEveryClient=all(any(len(v) > 1 for v in p["rooms"].values()) for p in players),
                scenarioCompletionVerified=False, screenshotsRequireVisualReview=True)


if __name__ == "__main__":
    try:
        result = verify(Path(sys.argv[1]))
        print(json.dumps(result, indent=2))
        sys.exit(0 if result["passed"] else 1)
    except (OSError, KeyError, ValueError, IndexError) as error:
        print(json.dumps(dict(passed=False, error=str(error))))
        sys.exit(1)
