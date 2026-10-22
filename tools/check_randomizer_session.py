"""Validate an item-randomizer --test-pickup smoke receipt using guest observations.

Usage: python tools/check_randomizer_session.py build-ninja/items-inventory-on.json
This checks pickup, not item use, save/resume, or scenario completion.
"""
import collections
import json
from pathlib import Path
import re
import sys


def verify(receipt_path):
    receipt = json.loads(Path(receipt_path).read_text(encoding="utf-8-sig"))
    session = Path(receipt["logs"])
    mods = json.loads((session / "mods.json").read_text(encoding="utf-8-sig"))
    selected = [m["itemRandomizer"] for m in mods if m.get("itemRandomizer") is not None]
    if len(selected) != 1 or any(m.get("effects") or m.get("patches") or m.get("weaponShuffle") for m in mods):
        raise ValueError("Expected exactly one item randomizer and no cheat effects/data patches")
    options = selected[0]
    log = (session / "stderr.log").read_text(encoding="utf-8", errors="replace")
    summaries = re.findall(r"\[MOD-ITEM-RANDOMIZER-1\] seed=(\d+) eligible=(\d+) changed=(\d+)", log)
    if len(summaries) != 1:
        raise ValueError("Expected exactly one scenario initialization")
    seed, eligible, changed = map(int, summaries[0])
    rows = re.findall(r"\[MOD-ITEM-RANDOMIZER-1\] item=([0-9a-f]+) ([0-9a-f]+):(\d+) -> ([0-9a-f]+):(\d+) metadata=(\d+)", log)
    rows = [(int(a, 16), int(b, 16), int(c), int(d, 16), int(e), int(f)) for a, b, c, d, e, f in rows]
    checks = {
        "cleanExit": receipt.get("exited") is True and receipt.get("exitCode") == 0,
        "seedMatches": seed == options["seed"],
        "completeItemLog": len(rows) == eligible and len({r[0] for r in rows}) == eligible,
        "supplyConserved": collections.Counter((r[1], r[2]) for r in rows) == collections.Counter((r[3], r[4]) for r in rows),
        "changedCountMatches": changed == sum((r[1], r[2]) != (r[3], r[4]) for r in rows) and changed > 0,
        "excludedTypesAbsent": all(r[1] not in options.get("excludeItemTypes", []) and r[3] not in options.get("excludeItemTypes", []) for r in rows),
        "progressionAndPersonalTypesExcluded": all(0 <= r[1] < 400 and 0 <= r[3] < 400 for r in rows),
        "returnedToMenu": bool(re.search(r"MAIN MENU PROOF .*pickupProof=1 resultsProof=1", log)),
    }
    proofs = re.findall(r"PICKUP PROOF handle=(\d+) item=(\d+) slot=(\d+) before=([\d/]+) after=([\d/]+) owner=(\d+) world=(\d+) active=(\d+) type=([0-9a-f]+) quantity=(\d+) metadata=(\d+)", log)
    acquired = []
    for handle, item, slot, before, after, owner, world, active, item_type, quantity, metadata in proofs:
        handle, item, slot = int(handle), int(item), int(slot)
        before, after = list(map(int, before.split("/"))), list(map(int, after.split("/")))
        row = next((r for r in rows if r[0] == 0x3C5630 + handle * 60), None)
        if (row and row[1] != row[3] and handle == item and len(before) == len(after) == 4
                and 0 <= slot < 4 and item not in before and after[slot] == item
                and (owner, world, active) == ("1", "0", "1")
                and (int(item_type, 16), int(quantity), int(metadata)) == row[3:]):
            acquired.append({"handle": handle, "originalType": row[1], "type": row[3], "quantity": row[4]})
    checks["randomizedPickupTransferred"] = bool(acquired)
    return {"passed": all(checks.values()), "session": str(session), "seed": seed,
            "eligible": eligible, "changed": changed, "checks": checks, "acquired": acquired,
            "itemUseVerified": False}


if __name__ == "__main__":
    try:
        result = verify(sys.argv[1])
    except (IndexError, KeyError, ValueError, OSError) as error:
        result = {"passed": False, "error": str(error)}
    print(json.dumps(result, indent=2))
    sys.exit(0 if result["passed"] else 1)
