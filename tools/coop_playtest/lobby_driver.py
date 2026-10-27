"""Bounded ordinary-pad lobby steering. Guest RAM is opened read-only."""

import ctypes
import json
import os
from pathlib import Path
import struct
import time

import coop_playtest as harness


ROOT = 0x6D8DB0
# Local test pacing: the driver reads the original menu state before every press, so it only needs
# a short settle time, not a fixed long delay between inputs.
PRESS_GAP = 0.35
STABLE_FOR = 0.12
BUSY_RETRY = 0.3


class GuestRam:
    class Region(ctypes.Structure):
        _fields_ = [("base", ctypes.c_void_p), ("allocation", ctypes.c_void_p),
                    ("allocationProtect", ctypes.c_ulong), ("partition", ctypes.c_ushort),
                    ("size", ctypes.c_size_t), ("state", ctypes.c_ulong),
                    ("protect", ctypes.c_ulong), ("kind", ctypes.c_ulong)]

    def __init__(self, identity, elf, game="file1"):
        if game not in ("file1", "file2"):
            raise ValueError("Unsupported lobby game profile")
        self.game = game
        self.identity = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
        self.k = harness.native()
        self.k.VirtualQueryEx.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t]
        self.k.VirtualQueryEx.restype = ctypes.c_size_t
        self.k.ReadProcessMemory.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p,
                                            ctypes.c_size_t, ctypes.POINTER(ctypes.c_size_t)]
        self.handle = self.k.OpenProcess(0x1010, False, identity["pid"])  # QUERY_LIMITED_INFORMATION | VM_READ
        if not self.handle:
            raise ctypes.WinError(ctypes.get_last_error())
        try:
            self.check()
            image = Path(elf).read_bytes()
            phoff = struct.unpack_from("<I", image, 0x1C)[0]
            phnum = struct.unpack_from("<H", image, 0x2C)[0]
            segment = None
            for i in range(phnum):
                kind, offset, address, _, size = struct.unpack_from("<IIIII", image, phoff + i * 32)
                if kind == 1 and size >= 64:
                    segment = address, image[offset:offset + 64]
                    break
            if segment is None:
                raise ValueError("ELF has no usable loaded segment")
            candidates = set()
            cursor = 0
            while cursor < 0x7FFFFFFFFFFF:
                region = self.Region()
                if not self.k.VirtualQueryEx(self.handle, cursor, ctypes.byref(region), ctypes.sizeof(region)):
                    break
                base = region.base or 0
                if region.state == 0x1000 and region.size >= 0x2000000 and not region.protect & 0x101:
                    for slack in (0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x1000):
                        if self._host_read(base + slack + segment[0], 64, optional=True) == segment[1]:
                            candidates.add(base + slack)
                next_cursor = base + region.size
                if next_cursor <= cursor:
                    break
                cursor = next_cursor
            if len(candidates) != 1:
                raise ValueError("Guest RAM signature was missing or ambiguous")
            self.base = candidates.pop()
        except BaseException:
            self.close()
            raise

    def check(self):
        if harness.process_exited(self.k, self.handle):
            raise ValueError("Owned process exited")
        length = ctypes.c_ulong(32768)
        image = ctypes.create_unicode_buffer(length.value)
        stamps = [ctypes.c_uint64() for _ in range(4)]
        if not self.k.QueryFullProcessImageNameW(self.handle, 0, image, ctypes.byref(length)) or not self.k.GetProcessTimes(
                self.handle, *(ctypes.byref(t) for t in stamps)):
            raise ctypes.WinError(ctypes.get_last_error())
        if stamps[0].value != self.identity["creationFileTime"] or Path(image.value).resolve() != Path(self.identity["image"]).resolve():
            raise ValueError("Owned process identity changed")

    def _host_read(self, address, size, optional=False):
        data = ctypes.create_string_buffer(size)
        count = ctypes.c_size_t()
        if not self.k.ReadProcessMemory(self.handle, address, data, size, ctypes.byref(count)) or count.value != size:
            if optional:
                return None
            raise ctypes.WinError(ctypes.get_last_error())
        return data.raw

    def read(self, address, size):
        if address < 0 or size < 0 or address + size > 0x2000000:
            raise ValueError("Guest read exceeds EE RAM")
        return self._host_read(self.base + address, size)

    def snapshot(self):
        self.check()
        game = getattr(self, "game", "file1")
        if game not in ("file1", "file2"):
            raise ValueError("Unsupported lobby game profile")
        second = game == "file2"
        if self.read(0x58D000 if second else 0x570000, 8) != struct.pack("<II", 0x336F574D, 4):
            raise ValueError("Expected BIN3 lobby overlay is not active")
        raw = self.read(0x6E2ED0 if second else ROOT, 0xA00 if second else 0x980)
        counts = self.read(0x6E293E if second else 0x6D881E, 6)
        area_count, room_ordinal, room_count = struct.unpack("<HHH", counts)
        if area_count > 128 or room_count > 128:
            raise ValueError("Original lobby list counts exceed the verified bounds")
        rooms = self.read(0x6DEAA0 if second else 0x6CD4A0, room_count * 0x15C) if raw[0] == 3 and raw[0xE] == 1 else b""
        # File #2's original 5F55E0 loads a byte count, not File #1's mode/backend pairs.
        server_count = self.read(0x8AA5D8, 1)[0] if second else struct.unpack("<I", self.read(0x699560, 4))[0]
        server_rows = b"" if second else self.read(0x6994E0, min(server_count, 32) * 2)
        keyboard_work = struct.unpack("<I", self.read(0x64C160 if second else 0x6436D0, 4))[0]
        keyboard_valid = 0 < keyboard_work < 0x2000000 - 0x40
        keyboard = self.read(keyboard_work, 0x40) if keyboard_valid else bytes(0x40)
        state = {"state": raw[0], "sub": raw[1], "menu": raw[0xE], "phase": raw[0xF],
                 "nested": raw[0x10], "pending": -1 if second else raw[0x42B], "cursor": raw[0x907 if second else 0x8DE],
                 "settingsCursor": raw[0x908 if second else 0x8DF], "joinCursor": raw[0x909 if second else 0x8E0],
                 "characterIndex": struct.unpack_from("<H", raw, 4)[0],
                 "characterCount": struct.unpack_from("<H", raw, 0xA)[0],
                 "areaCursor": raw[0x44A if second else 0x446], "areaPage": raw[0x44B if second else 0x447],
                 "roomCursor": raw[0x448 if second else 0x444], "roomPage": raw[0x449 if second else 0x445],
                 "memberCount": struct.unpack_from("<H", raw, 0x456 if second else 0x452)[0], "host": raw[0x97E if second else 0x956],
                 "chat": bool(raw[0x13] or raw[0x14] or raw[0x56B if second else 0x54F]),
                 "areaCount": area_count, "roomCount": room_count, "roomOrdinal": -1 if second else room_ordinal,
                 "title": self.read(0x6B53F2 if second else 0x6A3DF2, 16).split(b"\0")[0].decode("ascii", errors="replace"),
                 "maxPlayersIndex": self.read(0x6B547A if second else 0x6A3E7A, 1)[0], "rooms": []}
        state.update({"outerStep": self.read(0x6E9490 if second else 0x6DF150, 1)[0], "outerSub": self.read(0x6E9491 if second else 0x6DF151, 1)[0],
                      "mainMode": raw[0x41A], "serverController": self.read(0x6A9848 if second else 0x6995A0, 1)[0],
                      "serverWidget": raw[0x900 if second else 0x8D8], "serverWidgetSub": raw[0x901 if second else 0x8D9],
                      "serverCount": server_count,
                      "serverControllerSub": self.read(0x6A9849, 1)[0] if second else -1,
                      "serverRows": [{"mode": server_rows[i], "backend": server_rows[i + 1]}
                                     for i in range(0, len(server_rows), 2)],
                      "keyboardInitialized": keyboard_valid and keyboard[0x28] == 1,
                      "keyboardDelay": self.read(0x64C148 if second else 0x6436C8, 1)[0], "keyboardComplete": keyboard[0x36]})
        for i in range(len(rooms) // 0x15C):
            row = rooms[i * 0x15C:(i + 1) * 0x15C]
            state["rooms"].append({"index": i, "kind": row[0xE], "containsTitle": row[0x18:0x28].split(b"\0", 1)[0] == b"cooptest"})
        self.check()
        return state

    def close(self):
        if getattr(self, "handle", None):
            self.k.CloseHandle(self.handle)
            self.handle = None


def waiting_room(snapshot, host=False):
    return (snapshot["state"] == 4 and snapshot["sub"] == 0 and snapshot["phase"] == 6 and
            snapshot["nested"] == 2 and not snapshot["chat"] and bool(snapshot["host"]) == host)


def plan(number, snapshot, context, *, goal, host_waiting, game="file1"):
    """Return one action only for source- and native017-verified idle gates."""
    state, sub, menu, phase, nested = (snapshot[k] for k in ("state", "sub", "menu", "phase", "nested"))
    if game not in ("file1", "file2"):
        return "refuse", None, "unsupported-game-lobby-layout"
    if game == "file2" and snapshot["mainMode"] != 1:
        if (snapshot["mainMode"] == 7 and snapshot["serverController"] == 3 and
                snapshot.get("serverControllerSub", -1) == 0 and snapshot["serverWidget"] == 2 and
                snapshot["serverWidgetSub"] == 0 and not snapshot["chat"]):
            if snapshot["serverCount"] == 1 and snapshot["cursor"] == 0:
                return "button", "cross", "select-original-file2-only-server"
            if snapshot["serverCount"] == 0:
                return "wait", None, "await-original-file2-server-list"
            return "wait", None, "file2-select-server-in-original-menu"
        return "wait", None, "await-original-file2-server-selection"
    if (game == "file1" and snapshot["outerStep"] == 37 and snapshot["outerSub"] == 7 and snapshot["mainMode"] == 7 and
            snapshot["serverController"] == 3 and snapshot["serverWidget"] == 2 and snapshot["serverWidgetSub"] == 0):
        rows = snapshot["serverRows"]
        if snapshot["serverCount"] != len(rows) or not rows or snapshot["cursor"] >= len(rows):
            return "refuse", None, "invalid-original-server-selection-map"
        targets = [i for i, row in enumerate(rows) if row["mode"] == 1]
        if len(targets) != 1:
            return "refuse", None, "free-mode-server-map-is-missing-or-ambiguous"
        target = targets[0]
        return "button", ("cross" if snapshot["cursor"] == target else
                          "right" if snapshot["cursor"] < target else "left"), "select-original-free-mode-server"
    # Root state can be stale in Server Select; only trust it in the lobby mode.
    if snapshot["mainMode"] != 1:
        return "wait", None, "await-original-lobby-mode"
    if snapshot["chat"]:
        return "wait", None, "original-chat-or-modal-active"
    if state in (6, 14):
        # Right after login this transient state appears before Server Select settles: wait ~15 s first.
        context["outsideCount"] = context.get("outsideCount", 0) + 1
        if context["outsideCount"] < 150:
            return "wait", None, "await-post-login-transition"
        return "refuse", None, "disconnect-or-post-start-ui-is-outside-this-driver"
    if game == "file2" and state == 1 and sub == 0 and menu == 1 and phase == 2 and nested == 0:
        # Original 608DB0 phase2 selects ten difficulty areas before the scenario lobby.
        cursor = snapshot["cursor"]
        if not 0 <= cursor < 10:
            return "refuse", None, "invalid-file2-difficulty-area-cursor"
        return "button", "left" if cursor >= 5 else "up" if cursor else "cross", "select-original-file2-first-difficulty-area"
    editor_ready = (state == 3 and sub == 0 and menu == 3 and phase == 3 and nested == 2 and
                    snapshot["keyboardInitialized"] and snapshot["keyboardDelay"] == 0 and
                    snapshot["keyboardComplete"] == 0)
    context["titleReadySamples"] = context.get("titleReadySamples", 0) + 1 if editor_ready else 0
    if goal == "shared-area" and state == 3 and sub == 0 and menu == 1 and phase == 0:
        return "done", None, "original-room-list-reached"
    if goal == "waiting-room" and waiting_room(snapshot, host=number == 1):
        return "done", None, "original-waiting-room-reached"
    if state == 2 and sub == 0 and menu == 1 and phase == 0:
        return "button", "cross" if snapshot["cursor"] == 0 else "left", "select-original-room-list"
    if state == 2 and sub == 0 and menu == 5 and phase == 0 and snapshot["areaCount"]:
        if number != 1 and goal == "waiting-room" and not host_waiting:
            return "wait", None, "hold-area-entry-until-host-room-is-created"
        index = snapshot["areaCursor"] + snapshot["areaPage"]
        return "button", "up" if index else "cross", "enter-original-first-area"
    if state == 3 and sub == 0 and menu == 1 and phase == 0 and goal == "waiting-room":
        if number == 1:
            matches = [r["index"] for r in snapshot["rooms"] if r["kind"] == 1]
        else:
            matches = [r["index"] for r in snapshot["rooms"] if r["kind"] == 3 and r["containsTitle"]]
            if len(matches) > 1:
                return "refuse", None, "multiple-cooptest-rooms-cannot-identify-owned-room"
        if not matches:
            return "wait", None, "waiting-for-original-vacancy-or-owned-room-record"
        target = matches[0]
        current = snapshot["roomCursor"] + snapshot["roomPage"]
        return "button", "up" if current > target else "down" if current < target else "cross", "select-original-room-record"
    if state == 3 and sub == 0 and menu == 3 and number == 1 and goal == "waiting-room":
        if phase == 3 and nested == 2 and not context.get("titleQueued"):
            if ((context["titleReadySamples"] < 2 if game == "file2" else not context.get("titleWarmupObserved")) or
                    not snapshot["keyboardInitialized"] or
                    snapshot["keyboardDelay"] != 0 or snapshot["keyboardComplete"] != 0):
                return "wait", None, "await-original-title-editor-input-readiness"
            if snapshot["title"]:
                return "refuse", None, "title-input-is-not-empty-will-not-overwrite"
            return "text", "cooptest", "enter-owned-room-title-through-usb-keyboard"
        if phase == 2 and nested == 1:
            cursor = snapshot["settingsCursor"]
            if snapshot["title"] != "cooptest":
                if context.get("titleQueued"):
                    return "refuse", None, "original-title-returned-with-unexpected-content"
                if snapshot["title"]:
                    return "refuse", None, "existing-room-title-needs-manual-clear"
                return "button", "up" if cursor else "cross", "open-original-title-editor"
            if snapshot["maxPlayersIndex"] != 2:
                if cursor != 2:
                    return "button", "up" if cursor > 2 else "down", "select-original-no-players-option"
                return "button", "right" if snapshot["maxPlayersIndex"] < 2 else "left", "select-option-index2-four-players"
            return "button", "down" if cursor < 10 else "up" if cursor > 10 else "cross", "select-original-finish"
    if state == 3 and sub == 0 and menu == 2 and phase == 1 and nested == 1 and number > 1:
        # Original 5cdf10 skips occupied roster characters. Accept the game's
        # available current choice; fixed indices can be occupied/unreachable.
        if not 0 < snapshot["characterCount"] <= 32 or snapshot["characterIndex"] >= snapshot["characterCount"]:
            return "refuse", None, "invalid-original-character-selection"
        if snapshot["joinCursor"] == 0:
            return "button", "down", "select-original-room-entry"
        if snapshot["joinCursor"] == 1:
            return "button", "cross", "confirm-original-room-entry"
    if state == 4 and sub == 0 and phase == 4 and goal == "waiting-room":
        return "button", "cross", "confirm-original-pre-waiting-ready-stage"
    return "wait", None, "await-known-idle-lobby-gate"


def drive(folder, record, *, goal="shared-area", timeout=240, press_limit=100,
          reader_factory=GuestRam, identity_reader=harness.process_identity,
          pad_writer=None, queue_writer=harness.queue_keyboard, monotonic=time.monotonic, sleeper=time.sleep):
    if goal not in ("shared-area", "waiting-room") or not 1 <= timeout <= 900 or not 1 <= press_limit <= 200:
        raise ValueError("Invalid lobby goal, timeout or press limit")
    game = record.get("game", "file1")
    if game not in ("file1", "file2"):
        raise ValueError("Unsupported lobby game profile")
    folder = Path(folder).resolve()
    run = json.loads((folder / "run.json").read_text(encoding="utf-8"))
    identities = {r["number"]: r for r in run["players"]}
    if len(record["players"]) not in (1, 2, 3, 4) or 1 not in identities:
        raise ValueError("Lobby driver requires one to four players including host player1")
    receipt_path = folder / ("drive-lobby-" + goal + ".json")
    with open(receipt_path, "x", encoding="utf-8") as stream:
        json.dump({"status": "initializing", "coopVerdict": "not-tested"}, stream)
    readers, rows, contexts, next_action = {}, [], {}, {}
    result = {"goal": goal, "game": game, "startedUtc": harness.utc(), "coopVerdict": "not-tested", "hostStartSent": False,
              "serverMembershipVerified": False, "players": rows, "events": []}
    started = monotonic()
    if pad_writer is None:
        def pad_writer(player, button):
            harness.save(player["inputFile"], {"buttons": [button] if button else [],
                                               "expiresUnix": time.time() + 0.18})
    try:
        for player in record["players"]:
            number = player["number"]
            identity = identities[number]
            expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
            if (Path(identity["image"]).resolve() != Path(player["image"]).resolve() or
                    identity_reader(identity["pid"]) != expected):
                raise ValueError("A lobby process does not match its owned session identity")
            readers[number] = reader_factory(identity, record["elf"])
            readers[number].game = game
            contexts[number] = {"titleQueued": False, "stableKey": None, "stableSince": monotonic(),
                                "log": harness.LoginLogCursor(Path(player["logs"]) / "stderr.log")}
            rows.append({"number": number, "status": "observing", "presses": 0, "snapshot": None})
            next_action[number] = monotonic()
        while monotonic() - started < timeout:
            snapshots = {}
            for row in rows:
                if row["status"] in ("failed", "read-error", "press-limit"):
                    continue
                try:
                    lines = contexts[row["number"]]["log"].lines()
                    if any(needle in line.lower() for line in lines for _, needle in harness.FATAL_DIAGNOSTICS):
                        row["status"], row["reason"] = "failed", "native-fatal-diagnostic"
                        continue
                    snapshots[row["number"]] = readers[row["number"]].snapshot()
                except (OSError, ValueError):
                    row["status"] = "read-error"
            host_waiting = 1 in snapshots and waiting_room(snapshots[1], host=True)
            for row, player in zip(rows, record["players"]):
                number = row["number"]
                if number not in snapshots:
                    continue
                snapshot = snapshots[number]
                row["snapshot"] = snapshot
                context = contexts[number]
                if (snapshot["state"] == 3 and snapshot["menu"] == 3 and snapshot["phase"] == 3 and
                        snapshot["nested"] == 2 and snapshot["keyboardInitialized"] and snapshot["keyboardDelay"] > 0):
                    context["titleWarmupObserved"] = True
                key = json.dumps(snapshot, sort_keys=True)
                if key != context["stableKey"]:
                    context["stableKey"], context["stableSince"] = key, monotonic()
                kind, value, reason = plan(number, snapshot, context, goal=goal, host_waiting=host_waiting, game=game)
                row["reason"] = reason
                if kind in ("done", "refuse"):
                    row["status"] = "observed-goal" if kind == "done" else "failed"
                    continue
                if kind == "wait":
                    row["status"] = "waiting"
                    continue
                if monotonic() < next_action[number] or monotonic() - context["stableSince"] < STABLE_FOR:
                    continue
                identity = identities[number]
                expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
                if identity_reader(identity["pid"]) != expected:
                    row["status"] = "failed"
                    row["reason"] = "identity-changed-before-input"
                    continue
                if row["presses"] >= press_limit:
                    row["status"] = "press-limit"
                    continue
                if kind == "button":
                    pad_writer(player, value)
                    row["presses"] += 1
                else:
                    try:
                        queued = queue_writer(Path(player["keyboardFile"]), value, True)
                    except ValueError as error:
                        if str(error).startswith(("Keyboard consumer has not acknowledged", "Keyboard reports are still pending", "Another keyboard writer owns")):
                            next_action[number] = monotonic() + BUSY_RETRY
                            continue
                        row["status"] = "failed"
                        row["reason"] = "private-keyboard-queue-error"
                        continue
                    context["titleQueued"] = True
                    row["titleSequence"] = queued["sequence"]
                row["status"] = "steering"
                next_action[number] = monotonic() + PRESS_GAP
                result["events"].append({"elapsedSeconds": monotonic() - started, "player": number,
                                         "action": kind, "value": value, "reason": reason})
            harness.save(receipt_path, result)
            if any(row["status"] in ("failed", "read-error", "press-limit") for row in rows):
                break
            if all(row["status"] == "observed-goal" for row in rows):
                if goal == "shared-area" or snapshots[1]["memberCount"] >= len(rows):
                    result["uiGoalObserved"] = True
                    break
            sleeper(0.1)
    except KeyboardInterrupt:
        result["interrupted"] = True
    except (OSError, ValueError) as error:
        result["driverError"] = {"type": type(error).__name__, "message": str(error)}
    finally:
        for number, reader in readers.items():
            reader.close()
        result["finishedUtc"] = harness.utc()
        result["elapsedSeconds"] = monotonic() - started
        result["driverVerdict"] = "ui-goal-observed-no-gameplay-proof" if result.get("uiGoalObserved") else "incomplete"
        harness.save(receipt_path, result)
    return result
