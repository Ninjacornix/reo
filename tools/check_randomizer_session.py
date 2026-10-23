"""Validate an item-randomizer --test-pickup smoke receipt using guest observations.

Usage: python tools/check_randomizer_session.py build-ninja/items-inventory-on.json
This checks pickup, not item use, save/resume, or scenario completion.
"""
import collections
import json
from pathlib import Path
import re
import struct
import sys


def catalogue_items(path):
    data = Path(path).read_bytes()
    if data[:8] != b"RGIC1\0\0\0":
        raise ValueError("Invalid global item catalogue")
    count, = struct.unpack_from("<I", data, 8)
    position, items = 12, {}
    for _ in range(count):
        item_type, = struct.unpack_from("<H", data, position)
        flags, = struct.unpack_from("<I", data, position + 2)
        capacity, = struct.unpack_from("<H", data, position + 10)
        combinations, = struct.unpack_from("<H", data, position + 38)
        position += 40 + combinations * 6
        if item_type in items or position > len(data):
            raise ValueError("Invalid global item entry")
        protected = item_type in (312, 450) or item_type >= 10000 or bool(flags & 0x08000000)
        category = (None if protected else "ammunition" if 200 <= item_type < 300
                    else "weapon" if flags & 1 and not flags & 4
                    else "common" if flags & 4 or 300 <= item_type < 500 else None)
        items[item_type] = (category, capacity, flags)
    if position != len(data):
        raise ValueError("Incomplete global item catalogue")
    return items


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
        "changedCountMatches": changed == sum((r[1], r[2]) != (r[3], r[4]) for r in rows) and changed > 0,
        "excludedTypesAbsent": all(r[1] not in options.get("excludeItemTypes", []) and r[3] not in options.get("excludeItemTypes", []) for r in rows),
        "returnedToMenu": bool(re.search(r"MAIN MENU PROOF .*pickupProof=1 resultsProof=1", log)),
    }
    if options.get("mode", "shuffle") == "global":
        items = catalogue_items(session / "global-items.bin")
        checks.update({
            "globalCatalogueInstalled": "[MOD-GLOBAL-ITEMS-1] definitions=" in log,
            "separateCategories": all(a in items and b in items and items[a][0] is not None
                                      and items[a][0] == items[b][0] for _, a, _, b, _, _ in rows),
            "everyTypeChanged": all(r[1] != r[3] for r in rows),
            "replacementQuantityWithinCapacity": all(r[3] in items and 1 <= r[4] <= items[r[3]][1] for r in rows),
            "originalPersonalEquipmentExcluded": all(r[1] in items and not items[r[1]][2] & 0x40 for r in rows),
            "progressionTypesExcluded": all(t not in (312, 450) and t < 600
                                            and t in items and not items[t][2] & 0x08000000
                                            for r in rows for t in (r[1], r[3])),
        })
    else:
        checks["supplyConserved"] = collections.Counter((r[1], r[2]) for r in rows) == collections.Counter((r[3], r[4]) for r in rows)
        checks["progressionAndPersonalTypesExcluded"] = all(0 <= r[1] < 400 and 0 <= r[3] < 400 for r in rows)
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
    except (IndexError, KeyError, ValueError, OSError, struct.error) as error:
        result = {"passed": False, "error": str(error)}
    print(json.dumps(result, indent=2))
    sys.exit(0 if result["passed"] else 1)
