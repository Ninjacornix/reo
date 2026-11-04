"""Host starts the scenario; every player skips movies/cutscenes until original gameplay.

Ordinary pad input only (START SCENARIO, then Start to skip). Guest RAM is read-only and is used to
decide when a player is in gameplay, so Start is never pressed during play (it would open the menu).
Reaching gameplay on every client is a UI observation, not synchronization proof.
"""

import json
from pathlib import Path
import time

import coop_playtest as harness
from lobby_driver import GuestRam

STATE = 0x4BADD0        # original game-state block (same fields tools/room_playtest.py samples)
STATE_BY_GAME = {"file1": STATE, "file2": 0x4DB390}
PRESS_GAP = 0.6         # skip presses per player
GAMEPLAY_STABLE = 2.0   # seconds of continuous gameplay before a player counts as in game


def game_state(block):
    return {"phase": block[0], "modal": block[0x1E], "paused": block[0x28], "request": block[0x37]}


def in_gameplay(state):
    # Interactive play: phase 2 with no modal or pause layer. A nonzero request can persist during
    # ordinary play, so it does not mark a cutscene here.
    return state["phase"] == 2 and not state["modal"] and not state["paused"]


def drive(folder, record, *, timeout=240, reader_factory=GuestRam, identity_reader=harness.process_identity,
          pad_writer=None, monotonic=time.monotonic, sleeper=time.sleep):
    if not 10 <= timeout <= 900:
        raise ValueError("Start driver timeout must be 10..900 seconds")
    game = record.get("game", "file1")
    if game not in STATE_BY_GAME:
        raise ValueError("Unsupported start-driver game profile")
    folder = Path(folder).resolve()
    run = json.loads((folder / "run.json").read_text(encoding="utf-8"))
    identities = {r["number"]: r for r in run["players"]}
    if 1 not in identities:
        raise ValueError("Start driver requires host player1")
    receipt_path = folder / "drive-start.json"
    with open(receipt_path, "x", encoding="utf-8") as stream:
        json.dump({"status": "initializing", "coopVerdict": "not-tested"}, stream)
    if pad_writer is None:
        def pad_writer(player, button):
            harness.save(player["inputFile"], {"buttons": [button] if button else [],
                                               "expiresUnix": time.time() + 0.18})
    players = {p["number"]: p for p in record["players"] if p["number"] in identities}
    readers, rows = {}, {}
    result = {"startedUtc": harness.utc(), "game": game, "coopVerdict": "not-tested", "events": [], "players": []}
    started = monotonic()

    def event(number, value, reason):
        result["events"].append({"elapsedSeconds": round(monotonic() - started, 2), "player": number,
                                 "value": value, "reason": reason})

    try:
        for number, player in players.items():
            identity = identities[number]
            expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
            if (Path(identity["image"]).resolve() != Path(player["image"]).resolve() or
                    identity_reader(identity["pid"]) != expected):
                raise ValueError("A start-driver process does not match its owned session identity")
            readers[number] = reader_factory(identity, record["elf"])
            readers[number].game = game
            rows[number] = {"number": number, "status": "waiting-for-start", "skips": 0,
                            "gameplaySince": None, "expected": expected}
            result["players"].append(rows[number])
        # Only start once the host sits in the waiting room with every player joined.
        from lobby_driver import waiting_room
        while True:
            if monotonic() - started > timeout:
                raise ValueError("Host never reached the waiting room with all players; run drive-lobby first")
            snap = readers[1].snapshot()
            if waiting_room(snap, host=True) and snap.get("memberCount", 0) >= len(rows):
                break
            sleeper(0.2)
        # Host: from the default STANDBY cursor, Left selects START SCENARIO; Cross starts for everyone.
        host = players[1]
        pad_writer(host, "left"); event(1, "left", "select-start-scenario")
        sleeper(0.5)
        pad_writer(host, "cross"); event(1, "cross", "start-scenario")
        result["hostStartSent"] = True
        next_press = {number: monotonic() + 3.0 for number in rows}  # let the start transition begin
        while monotonic() - started < timeout:
            for number, row in rows.items():
                if row["status"] in ("in-gameplay", "failed"):
                    continue
                if identity_reader(identities[number]["pid"]) != row["expected"]:
                    row["status"], row["reason"] = "failed", "identity-changed"
                    continue
                try:
                    state = game_state(readers[number].read(STATE_BY_GAME[game], 0x40))
                except (OSError, ValueError):
                    row["status"], row["reason"] = "failed", "read-error"
                    continue
                row["state"] = state
                now = monotonic()
                if in_gameplay(state):
                    if row["gameplaySince"] is None:
                        row["gameplaySince"] = now
                    elif now - row["gameplaySince"] >= GAMEPLAY_STABLE:
                        row["status"] = "in-gameplay"
                        row["gameplayAtSeconds"] = round(row["gameplaySince"] - started, 2)
                    continue
                row["gameplaySince"] = None
                row["status"] = "skipping"
                if now >= next_press[number]:
                    pad_writer(players[number], "start")
                    row["skips"] += 1
                    event(number, "start", "skip-movie-or-cutscene")
                    next_press[number] = now + PRESS_GAP
            harness.save(receipt_path, result)
            if all(row["status"] in ("in-gameplay", "failed") for row in rows.values()):
                break
            sleeper(0.1)
        result["allInGameplay"] = all(row["status"] == "in-gameplay" for row in rows.values())
    except KeyboardInterrupt:
        result["interrupted"] = True
    except (OSError, ValueError) as error:
        result["driverError"] = {"type": type(error).__name__, "message": str(error)}
    finally:
        for reader in readers.values():
            reader.close()
        for row in rows.values():
            row.pop("expected", None)
        result["finishedUtc"] = harness.utc()
        result["elapsedSeconds"] = round(monotonic() - started, 2)
        result["driverVerdict"] = ("gameplay-observed-no-sync-proof" if result.get("allInGameplay")
                                   else "gameplay-not-reached")
        harness.save(receipt_path, result)
    return result
