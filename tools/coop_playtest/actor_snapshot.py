"""Read-only original actor samples; observations are not synchronization proof."""

import json
import math
from pathlib import Path
import re
import struct

import coop_playtest as harness
from lobby_driver import GuestRam


ACTOR_BASE = 0x4A5C30
ACTOR_STRIDE = 0x10E0
ACTOR_COUNT = 4
ACTOR_READ_SIZE = 0x210
LOCAL_ACTOR = 0x4BADED
# Original File #2 actor indexing uses a different stride (13BB28/13BB2C).
LAYOUTS = {"file1": (ACTOR_BASE, ACTOR_STRIDE, LOCAL_ACTOR),
           "file2": (0x4C5E10, 0x1100, 0x4DB3AD)}


def decode_actor(slot, data):
    if not 0 <= slot < ACTOR_COUNT or len(data) != ACTOR_READ_SIZE:
        raise ValueError("Actor slot or read size is outside the verified layout")
    xyz = list(struct.unpack_from("<fff", data, 0x38))
    frame = struct.unpack_from("<f", data, 0x1E4)[0]
    if not all(math.isfinite(value) for value in xyz + [frame]):
        raise ValueError("Actor sample contains non-finite fields; no valid snapshot claimed")
    return {"slot": slot, "active": data[0], "state": data[8:12].hex(), "xyz": xyz,
            "yaw": struct.unpack_from("<H", data, 0x92)[0], "frame": frame,
            "header": data[:32].hex()}


def snapshot_actors(folder, record, label, *, reader_factory=GuestRam,
                    identity_reader=harness.process_identity):
    game = record.get("game", "file1")
    if game not in LAYOUTS:
        raise ValueError("Unsupported actor snapshot game profile")
    actor_base, actor_stride, local_actor = LAYOUTS[game]
    if not isinstance(label, str) or not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_-]{0,63}", label):
        raise ValueError("Snapshot label must be 1..64 ASCII letters, digits, underscores or hyphens")
    folder = Path(folder).resolve()
    run = json.loads((folder / "run.json").read_text(encoding="utf-8"))
    prepared = {p["number"]: p for p in record["players"]}
    players = run["players"]
    if not 1 <= len(players) <= 4 or len({p["number"] for p in players}) != len(players):
        raise ValueError("Actor snapshot requires one to four uniquely owned players")
    path = folder / f"actors-{label}.json"
    result = {"utc": harness.utc(), "game": game, "label": label, "status": "sampling", "readOnly": True,
              "simultaneousAcrossProcesses": False, "coopVerdict": "not-tested", "players": []}
    # Reserve the immutable name before attaching; even failed captures preserve
    # their receipt and cannot be replaced by a later successful observation.
    with open(path, "x", encoding="utf-8") as stream:
        try:
            for identity in players:
                player = prepared.get(identity["number"])
                expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
                if (player is None or Path(identity["image"]).resolve() != Path(player["image"]).resolve() or
                        folder not in Path(identity["image"]).resolve().parents or
                        identity_reader(identity["pid"]) != expected):
                    raise ValueError("Actor snapshot process differs from its owned session identity")
                reader = reader_factory(identity, record["elf"])
                try:
                    reader.check()
                    local = reader.read(local_actor, 1)[0]
                    if local >= ACTOR_COUNT:
                        raise ValueError("Original local actor index is outside the four-player layout")
                    sample = {"number": identity["number"], "identity": expected, "utc": harness.utc(),
                              "localActor": local, "actors": []}
                    for slot in range(ACTOR_COUNT):
                        address = actor_base + slot * actor_stride
                        if address + ACTOR_READ_SIZE > 0x2000000:
                            raise ValueError("Actor read exceeds EE RAM")
                        if game == "file2":
                            # Only the original position field is corroborated for both editions.
                            xyz = list(struct.unpack("<fff", reader.read(address + 0x38, 12)))
                            if not all(math.isfinite(value) for value in xyz):
                                raise ValueError("Actor position contains non-finite fields")
                            sample["actors"].append({"slot": slot, "xyz": xyz})
                        else:
                            sample["actors"].append(decode_actor(slot, reader.read(address, ACTOR_READ_SIZE)))
                    reader.check()
                    if identity_reader(identity["pid"]) != expected:
                        raise ValueError("Actor process identity changed during capture")
                    result["players"].append(sample)
                finally:
                    reader.close()
            result["status"] = "captured"
        except BaseException as error:
            result["status"] = "failed"
            result["error"] = {"type": type(error).__name__, "message": str(error)}
            raise
        finally:
            result["finishedUtc"] = harness.utc()
            json.dump(result, stream, indent=2, allow_nan=False)
            stream.write("\n")
    return {"receipt": str(path), **result}
