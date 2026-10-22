"""Compare --test-enemies baseline and randomized smoke receipts.

Usage: python tools/check_enemy_randomizer_session.py baseline.json randomized.json
Checks initialization, exact write boundaries, spawning and AI updates. Damage is
reported separately; this does not assert a bite, a kill or scenario completion.
"""
import collections
import json
from pathlib import Path
import re
import struct
import sys


def session(path):
    receipt = json.loads(Path(path).read_text(encoding="utf-8-sig"))
    folder = Path(receipt["logs"])
    return receipt, json.loads((folder / "mods.json").read_text(encoding="utf-8-sig")), (folder / "stderr.log").read_text(errors="replace")


def verify(baseline, randomized):
    base_receipt, base_mods, base_log = session(baseline)
    receipt, mods, log = session(randomized)
    if base_mods:
        raise ValueError("Baseline must have no selected mods")
    selected = [m["enemyRandomizer"] for m in mods if m.get("enemyRandomizer")]
    if len(selected) != 1 or any(m.get("effects") or m.get("patches") for m in mods):
        raise ValueError("Expected one enemy randomizer and no cheat effects or data patches")
    def tables(text):
        return {int(a, 16): bytes.fromhex(b) for a, b in re.findall(r"\[TEST-ENEMIES\] record=([0-9a-f]+) bytes=([0-9a-f]+)", text)}
    before, after = tables(base_log), tables(log)
    if not before or before.keys() != after.keys() or any(len(r) != 96 for r in list(before.values()) + list(after.values())):
        raise ValueError("Missing or incompatible enemy-table diagnostics")
    summaries = re.findall(r"\[MOD-ZOMBIE-RANDOMIZER-1\] seed=(\d+) eligible=(\d+) changed=(\d+)", log)
    if len(summaries) != 1:
        raise ValueError("Expected exactly one shuffled scenario")
    seed, eligible, changed = map(int, summaries[0])
    mutations = re.findall(r"\[MOD-ZOMBIE-RANDOMIZER-1\] record=([0-9a-f]+) room=(\d+) mode=(\d+) variant=(\d+):(\d+) -> (\d+):(\d+)", log)
    mutations = [(int(a, 16), *map(int, values)) for a, *values in mutations]
    addresses = {r[0] for r in mutations}
    checks = {
        "cleanExits": all(r.get("exited") is True and r.get("exitCode") == 0 for r in (base_receipt, receipt)),
        "seedMatches": seed == selected[0]["seed"],
        "completeMutationLog": len(mutations) == len(addresses) == eligible and addresses <= before.keys(),
        "changedCountMatches": sum((r[3], r[4]) != (r[5], r[6]) for r in mutations) == changed and changed > 0,
        "roomAndLifecycleSupplyConserved": collections.Counter((r[1], r[2], r[3], r[4]) for r in mutations) == collections.Counter((r[1], r[2], r[5], r[6]) for r in mutations),
        "onlyPermittedBytesChanged": all(a[i] == after[address][i] for address, a in before.items() for i in range(96) if address not in addresses or i not in (3, 28, 29, 30, 31)),
    }
    checks["mutationRecordsMatch"] = all(
        before[a][2] == after[a][2] == 1 and before[a][3] == old and after[a][3] == new
        and before[a][0x22] == room and before[a][0x26] == mode
        and struct.unpack_from("<hh", before[a], 28) == (old_hp, old_hp)
        and struct.unpack_from("<hh", after[a], 28) == (hp, hp)
        for a, room, mode, old, old_hp, new, hp in mutations)
    changed_profiles = {(a - 0x74f250) // 96: (new, hp) for a, room, mode, old, old_hp, new, hp in mutations if (old, old_hp) != (new, hp)}
    spawns = re.findall(r"\[TEST-ENEMIES\] actor=([0-9a-f]+) type=1 variant=(\d+) spawn=(\d+) hp=(\d+) callback=00696300", log)
    verified_spawns = {int(spawn) for actor, variant, spawn, hp in spawns if changed_profiles.get(int(spawn)) == (int(variant), int(hp))}
    updates = re.findall(r"\[TEST-ENEMIES\] update actor=[0-9a-f]+ spawn=(\d+) variant=(\d+)", log)
    checks["changedProfilesSpawned"] = bool(verified_spawns)
    checks["changedZombieAIUpdated"] = any(int(spawn) in verified_spawns and changed_profiles[int(spawn)][0] == int(variant) for spawn, variant in updates)
    health = list(map(int, re.findall(r"playerHp=(\d+)", log)))
    return {"passed": all(checks.values()), "seed": seed, "eligible": eligible, "changed": changed,
            "checks": checks, "verifiedChangedSpawns": sorted(verified_spawns),
            "playerDamageObserved": bool(health and min(health) < max(health)),
            "biteVerified": False, "scenarioCompletionVerified": False, "session": receipt["logs"]}


if __name__ == "__main__":
    try:
        result = verify(sys.argv[1], sys.argv[2])
    except (OSError, ValueError, IndexError, KeyError) as error:
        result = {"passed": False, "error": str(error)}
    print(json.dumps(result, indent=2))
    sys.exit(0 if result["passed"] else 1)
