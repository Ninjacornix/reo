"""Isolated native-game instances. Endpoint visibility is not a co-op verdict."""

from __future__ import annotations

import argparse
import ctypes
from functools import lru_cache
import hashlib
import json
import mmap
import os
from pathlib import Path
import shutil
import socket
import struct
import subprocess
import sys
import time
import uuid
import zlib


EXPECTED_ELF = "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46"
GAMES = {
    "file1": (EXPECTED_ELF, "SLUS_207.65", "reo_recomp.exe", "Resident Evil - Outbreak (v2.00).iso"),
    "file2": ("5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d", "SLUS_209.84", "reo_recomp_file2.exe", "Resident Evil - Outbreak - File #2.iso"),
}
SHADERS = ("present_opaque.vert.spv", "present_native.frag.spv",
           "present_smaa_edge.frag.spv", "present_smaa_weights.frag.spv",
           "present_smaa_blend.frag.spv")
BUTTONS = {"up": 1, "down": 2, "left": 4, "right": 8, "start": 16,
           "select": 32, "l3": 64, "r3": 128, "l1": 256, "r1": 512,
           "cross": 4096, "circle": 8192, "square": 16384, "triangle": 32768}
PINNED = {"REO_ISO", "REO_MC0_ROOT", "REO_MC1_ROOT", "REO_LAUNCHER_PAD_MAP", "REO_COOP_KEYBOARD_FILE"}
KEYBOARD_MAGIC = 0x52454F4B


def save(path, obj):
    path = Path(path)
    temporary = path.with_name(path.name + ".tmp-" + uuid.uuid4().hex)
    try:
        temporary.write_text(json.dumps(obj, indent=2), encoding="utf-8")
        # Windows readers may briefly omit FILE_SHARE_DELETE. Retry only the
        # atomic replacement; never expose a partly-written controller state.
        for attempt in range(11):
            try:
                temporary.replace(path)
                break
            except PermissionError:
                if attempt == 10:
                    raise
                time.sleep(0.02)
    finally:
        if temporary.exists():
            temporary.unlink()


def digest(path):
    with open(path, "rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def utc():
    return time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime())


def beneath(root, relative):
    root = Path(root).resolve()
    path = (root / relative).resolve()
    if path == root or root not in path.parents:
        raise ValueError(f"Path escapes private root: {relative}")
    return path


def validate_import(folder, iso, game="file1"):
    expected, elf_name, _, _ = GAMES[game]
    folder, iso = Path(folder).resolve(), Path(iso).resolve()
    record = json.loads((folder / "import.json").read_text(encoding="utf-8-sig"))
    metadata = iso.stat()
    ticks = metadata.st_mtime_ns // 100 + 621355968000000000
    if (record.get("Version") != 1 or record.get("Game") != game
            or Path(record["Source"]).resolve() != iso
            or record["SourceLength"] != metadata.st_size
            or record["SourceWriteTicks"] != ticks
            or record["ElfSha256"] != expected):
        raise ValueError("Import does not match the supported ISO and current source metadata")
    data = folder / "data"
    for entry in record["Files"]:
        path = beneath(data, entry["Name"])
        if not path.is_file() or path.stat().st_size != entry["Length"]:
            raise ValueError(f"Incomplete imported file: {entry['Name']}")
    elf = data / elf_name
    if digest(elf) != expected:
        raise ValueError("Imported ELF hash differs from the selected supported edition")
    return data, elf


def configured_import(root, iso, supplied, game="file1"):
    if supplied:
        return Path(supplied)
    home = Path(os.environ["LOCALAPPDATA"]) / "OutbreakRecomp" / "launcher"
    settings = home / "settings.json"
    if settings.exists():
        folder = json.loads(settings.read_text(encoding="utf-8-sig")).get("ImportedFile2" if game == "file2" else "ImportedFile1")
        if folder:
            return Path(folder)
    candidates = []
    for record in (home / "imports" / game).glob("*/import.json"):
        value = json.loads(record.read_text(encoding="utf-8-sig"))
        if Path(value["Source"]).resolve() == iso:
            candidates.append(record.parent)
    if len(candidates) != 1:
        raise ValueError("Import the ISO in the launcher first, or specify --import-root")
    return candidates[0]


def prepare(args):
    if not 1 <= args.players <= 4:
        raise ValueError("Use 1 through 4 players (1 is for online-menu discovery)")
    root = Path(args.root).resolve()
    game = getattr(args, "game", "file1")
    _, _, exe_name, iso_name = GAMES[game]
    source = Path(args.exe or root / "build-ninja/recomp" / exe_name).resolve()
    iso = Path(args.iso or root / "iso" / iso_name).resolve()
    imported = configured_import(root, iso, args.import_root, game)
    data, elf = validate_import(imported, iso, game)
    adapter = Path(args.adapter or root / "launcher/bin/Release/net8.0-windows/XINPUT1_4.dll").resolve()
    required = [source, adapter] + [source.parent / "reo-gpu-present" / s for s in SHADERS]
    for path in required:
        if not path.is_file():
            raise ValueError(f"Missing dependency: {path}")
    session = Path(args.session).resolve()
    if session.exists():
        raise ValueError("Session already exists; use a new directory to preserve prior evidence")
    token = uuid.uuid4().hex
    session.mkdir(parents=True)
    manifest = {"game": game, "format": 1, "owner": "reo-coop-playtest", "token": token,
                "createdUtc": utc(), "session": str(session), "iso": str(iso),
                "importRoot": str(imported.resolve()), "data": str(data), "elf": str(elf),
                "sourceExe": str(source), "sourceSha256": digest(source),
                "mountedIso": False, "players": [],
                "coopVerdict": "not-tested", "trafficCapture": "process-owned endpoints only; no payload capture"}
    dependencies = [p for p in source.parent.glob("*.dll") if p.name.lower() in {
        "msvcp140.dll", "msvcp140_atomic_wait.dll", "vcruntime140.dll", "vcruntime140_1.dll", "vulkan-1.dll",
        "libc++.dll", "libunwind.dll", "libwinpthread-1.dll"}]
    for i in range(args.players):
        player = session / f"player{i + 1}"
        for leaf in ("image/reo-gpu-present", "work", "card0", "logs"):
            (player / leaf).mkdir(parents=True)
        image = player / "image" / "reo_coop_game.exe"
        shutil.copy2(source, image)
        if digest(image) != manifest["sourceSha256"]:
            raise ValueError("Native source changed while preparing copies; preserved partial session, use a new directory")
        shutil.copy2(adapter, image.parent / "XINPUT1_4.dll")
        # Match the launcher's adapter aliases for both MSVC and LLVM/MinGW.
        shutil.copy2(adapter, image.parent / "XINPUT1_3.dll")
        for path in dependencies:
            shutil.copy2(path, image.parent / path.name)
        # Native movies/readbacks also use certified helper shaders. Preserve
        # the complete built shader set, as the production launcher does.
        for shader in (source.parent / "reo-gpu-present").glob("*.spv"):
            shutil.copy2(shader, image.parent / "reo-gpu-present" / shader.name)
        files = [{"path": str(p.relative_to(player)), "sha256": digest(p)}
                 for p in sorted((player / "image").rglob("*")) if p.is_file()]
        save(player / "input.json", {"buttons": [], "lx": 0, "ly": 0, "rx": 0, "ry": 0})
        keyboard = player / "keyboard.bin"
        keyboard.write_bytes(struct.pack("<III", KEYBOARD_MAGIC, 0, 0))
        # Only the consumer acknowledges queues. The empty initial queue is not
        # pre-acknowledged: text refuses until the live service has attached.
        manifest["players"].append({"number": i + 1, "image": str(image), "workingDirectory": str(player / "work"),
                                   "card": str(player / "card0"), "logs": str(player / "logs"),
                                   "inputFile": str(player / "input.json"),
                                   "keyboardFile": str(keyboard),
                                   "map": f"Local\\REO-Coop-{token}-{i + 1}", "files": files})
    save(session / "session.json", manifest)
    print(json.dumps({"prepared": str(session), "players": args.players, "coopVerdict": "not-tested"}))


def session_record(folder):
    folder = Path(folder).resolve()
    record = json.loads((folder / "session.json").read_text(encoding="utf-8"))
    if record.get("owner") != "reo-coop-playtest" or Path(record["session"]).resolve() != folder:
        raise ValueError("Not an owned playtest session")
    for player in record["players"]:
        for key in ("image", "workingDirectory", "card", "logs", "inputFile"):
            if folder not in Path(player[key]).resolve().parents:
                raise ValueError("Session path escaped its private directory")
        if player.get("keyboardFile") and folder not in Path(player["keyboardFile"]).resolve().parents:
            raise ValueError("Keyboard queue path escaped its private directory")
    return folder, record


@lru_cache(maxsize=1)
def native():
    if os.name != "nt":
        raise OSError("Live instance control requires Windows")
    k32 = ctypes.WinDLL("kernel32", use_last_error=True)
    k32.OpenProcess.argtypes = [ctypes.c_ulong, ctypes.c_int, ctypes.c_ulong]
    k32.OpenProcess.restype = ctypes.c_void_p
    k32.CloseHandle.argtypes = [ctypes.c_void_p]
    k32.QueryFullProcessImageNameW.argtypes = [ctypes.c_void_p, ctypes.c_ulong, ctypes.c_wchar_p, ctypes.POINTER(ctypes.c_ulong)]
    k32.GetProcessTimes.argtypes = [ctypes.c_void_p] + [ctypes.c_void_p] * 4
    k32.GetExitCodeProcess.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_ulong)]
    k32.TerminateProcess.argtypes = [ctypes.c_void_p, ctypes.c_uint]
    return k32


def process_exited(k32, handle):
    code = ctypes.c_ulong()
    if not k32.GetExitCodeProcess(handle, ctypes.byref(code)):
        raise ctypes.WinError(ctypes.get_last_error())
    return code.value != 259  # STILL_ACTIVE


def process_identity(pid):
    k32 = native()
    handle = k32.OpenProcess(0x1000, False, pid)
    if not handle:
        if ctypes.get_last_error() not in (87, 1168):
            raise ctypes.WinError(ctypes.get_last_error())
        return None
    try:
        if process_exited(k32, handle):
            return None
        length = ctypes.c_ulong(32768)
        name = ctypes.create_unicode_buffer(length.value)
        stamps = [ctypes.c_uint64() for _ in range(4)]
        if not k32.QueryFullProcessImageNameW(handle, 0, name, ctypes.byref(length)):
            query_error = ctypes.get_last_error()
            if process_exited(k32, handle):
                return None
            raise ctypes.WinError(query_error)
        if not k32.GetProcessTimes(handle, *(ctypes.byref(t) for t in stamps)):
            raise ctypes.WinError(ctypes.get_last_error())
        return {"pid": pid, "image": str(Path(name.value).resolve()), "creationFileTime": stamps[0].value}
    finally:
        k32.CloseHandle(handle)


def stop_owned(identity, *, before_terminate=None):
    # Validate creation time and image on the SAME handle used to terminate.
    k32 = native()
    handle = k32.OpenProcess(0x1001, False, identity["pid"])
    if not handle:
        if ctypes.get_last_error() not in (87, 1168):
            raise ctypes.WinError(ctypes.get_last_error())
        return False
    try:
        if process_exited(k32, handle):
            return False
        length = ctypes.c_ulong(32768)
        image = ctypes.create_unicode_buffer(length.value)
        stamps = [ctypes.c_uint64() for _ in range(4)]
        if not k32.QueryFullProcessImageNameW(handle, 0, image, ctypes.byref(length)):
            query_error = ctypes.get_last_error()
            if process_exited(k32, handle):
                return False
            raise ctypes.WinError(query_error)
        if not k32.GetProcessTimes(handle, *(ctypes.byref(t) for t in stamps)):
            raise ctypes.WinError(ctypes.get_last_error())
        if Path(image.value).resolve() != Path(identity["image"]).resolve() or stamps[0].value != identity["creationFileTime"]:
            raise ValueError("Refusing reused PID or different process image")
        if before_terminate is not None:
            before_terminate()
        if not k32.TerminateProcess(handle, 0xC000013A):
            if process_exited(k32, handle):
                return False
            raise ctypes.WinError(ctypes.get_last_error())
        return True
    finally:
        k32.CloseHandle(handle)


def request_owned_stop(folder, identity, *, stopper=stop_owned):
    """Publish provenance only after validation on the terminating process handle."""
    directory = Path(folder) / "stop-requests"
    directory.mkdir(exist_ok=True)
    path = directory / f'{identity["pid"]}-{identity["creationFileTime"]}-{uuid.uuid4().hex}.json'
    receipt = {"owner": "reo-coop-playtest-stop", "identity": {k: identity[k] for k in
               ("pid", "image", "creationFileTime")}, "requestedUtc": utc(),
               "terminationCode": 0xC000013A, "state": "validated-intent"}

    def intent():
        save(path, receipt)

    stopped = stopper(identity, before_terminate=intent)
    if path.exists():
        receipt["state"] = "terminated-owned-process" if stopped else "already-exited-before-termination"
        receipt["finishedUtc"] = utc()
        save(path, receipt)
    return stopped


def owned_stop_provenance(folder, identity, exit_code):
    # A request cannot hide another crash code or fatal native diagnostic.
    if exit_code is None or exit_code & 0xFFFFFFFF != 0xC000013A:
        return None
    expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
    pending, deadline = True, time.monotonic() + 1
    while pending:
        pending = False
        for path in (Path(folder) / "stop-requests").glob(f'{identity["pid"]}-{identity["creationFileTime"]}-*.json'):
            try:
                row = json.loads(path.read_text(encoding="utf-8"))
            except (OSError, ValueError):
                continue
            if row.get("owner") != "reo-coop-playtest-stop" or row.get("identity") != expected:
                continue
            if row.get("state") == "terminated-owned-process" and row.get("terminationCode") == 0xC000013A:
                return str(path)
            pending |= row.get("state") == "validated-intent"
        if pending and time.monotonic() < deadline:
            time.sleep(0.02)
        else:
            break
    return None


FATAL_DIAGNOSTICS = (
    ("unimplemented-guest-function", "called unimplemented function at address"),
    ("native-crash", "[crash]"),
    ("graphics-backend-failure", "[gs-backend-fail]"),
    ("graphics-backend-failure", "[run] graphics backend failure"),
    ("graphics-backend-failure", "missing certified native movie shader asset"),
    ("account-provider-failure", "[coop-account] cannot"),
    ("account-provider-failure", "[coop-account] invalid"),
    ("account-provider-failure", "[coop-account] original account helper did not return"),
)


def classify_native_logs(logs):
    findings, total, read_errors = [], 0, []
    for name in ("stdout.log", "stderr.log"):
        path = Path(logs) / name
        try:
            with open(path, encoding="utf-8", errors="replace") as stream:
                for line_number, line in enumerate(stream, 1):
                    lower = line.lower()
                    categories = sorted({kind for kind, needle in FATAL_DIAGNOSTICS if needle in lower})
                    if categories:
                        total += 1
                        if len(findings) < 100:
                            findings.append({"file": name, "line": line_number, "categories": categories,
                                             "evidence": line.strip()[:1000]})
        except OSError as e:
            read_errors.append({"file": name, "error": str(e)})
    return {"fatal": total > 0, "fatalLineCount": total, "findings": findings,
            "findingsTruncated": total > len(findings), "readErrors": read_errors}


def native_outcome(exit_code, diagnostics, supervisor_stopped=False, operator_stopped=False):
    if diagnostics["fatal"]:
        return "fatal-diagnostic"
    if supervisor_stopped:
        return "supervisor-stopped"
    if operator_stopped:
        return "operator-stopped"
    if exit_code != 0:
        return "nonzero-exit"
    if diagnostics["readErrors"]:
        return "diagnostics-unavailable"
    return "exited-no-fatal-diagnostic"


class LoginLogCursor:
    def __init__(self, path):
        self.path = Path(path)
        self.offset = 0
        self.partial = b""

    def lines(self):
        if not self.path.exists():
            return []
        with open(self.path, "rb") as stream:
            if stream.seek(0, os.SEEK_END) < self.offset:
                raise ValueError("Native log was truncated during login driving")
            stream.seek(self.offset)
            block = stream.read(1024 * 1024)
            self.offset = stream.tell()
        pieces = (self.partial + block).split(b"\n")
        self.partial = pieces.pop()
        if len(self.partial) > 65536:
            raise ValueError("Native log has an oversized unterminated line")
        return [line.decode("utf-8", errors="replace") for line in pieces]


def drive_login(folder, record, passwords, timeout, *, replace=False, identity_reader=process_identity,
                queue_writer=None,
                monotonic=time.monotonic, sleeper=time.sleep):
    """Drive only the original password keyboard; never assert authentication."""
    if queue_writer is None:
        queue_writer = queue_keyboard
    if not 1 <= timeout <= 900:
        raise ValueError("Login driver timeout must be 1..900 seconds")
    if not passwords or not 1 <= len(passwords) <= 4:
        raise ValueError("Select between one and four players")
    for password in passwords.values():
        if not isinstance(password, str) or not 4 <= len(password) <= 15 or any(not 32 <= ord(c) <= 126 for c in password):
            raise ValueError("Use a disposable test password of 4..15 printable ASCII characters")
    folder = Path(folder)
    run_receipt = json.loads((folder / "run.json").read_text(encoding="utf-8"))
    players = {p["number"]: p for p in record["players"]}
    identities = {p["number"]: p for p in run_receipt["players"]}
    work = {}
    for number in passwords:
        if number not in players or number not in identities or not players[number].get("keyboardFile"):
            raise ValueError("A selected player has no launched process or private keyboard queue")
        player, identity = players[number], identities[number]
        if Path(identity["image"]).resolve() != Path(player["image"]).resolve():
            raise ValueError("Run process image differs from the prepared owned image")
        keyboard = Path(player["keyboardFile"]).resolve()
        if folder.resolve() not in keyboard.parents:
            raise ValueError("Keyboard queue escaped the private session")
        work[number] = {"player": player, "identity": identity,
                        "cursor": LoginLogCursor(Path(player["logs"]) / "stderr.log")}
    output = folder / "drive-login.json"
    # One driver per immutable session: restarting after an ambiguous crash must
    # never replay a password into a different original UI state.
    try:
        with open(output, "x", encoding="utf-8") as stream:
            json.dump({"state": "initializing", "coopVerdict": "not-tested"}, stream)
    except FileExistsError:
        raise ValueError("A login driver receipt already exists; refusing possible credential replay") from None
    result = {"startedUtc": utc(), "timeoutSeconds": timeout, "replaceExisting": replace, "coopVerdict": "not-tested",
              "driverVerdict": "in-progress", "players": []}
    for number in passwords:
        identity = work[number]["identity"]
        result["players"].append({"number": number, "pid": identity["pid"],
                                  "image": identity["image"], "creationFileTime": identity["creationFileTime"],
                                  "status": "waiting-password-ui", "readyObserved": False,
                                  "queuedSequence": None, "queueAcknowledged": False,
                                  "submittedObserved": False})
    save(output, result)
    started = monotonic()
    terminal = {"submitted-not-authenticated", "already-submitted", "process-exited", "fatal-diagnostic",
                "identity-mismatch", "queue-error", "log-error", "timed-out", "interrupted"}
    retryable = ("Keyboard consumer has not acknowledged", "Keyboard reports are still pending",
                 "Another keyboard writer owns")
    try:
        while any(row["status"] not in terminal for row in result["players"]):
            if monotonic() - started >= timeout:
                for row in result["players"]:
                    if row["status"] not in terminal:
                        row["status"] = "timed-out"
                break
            for row in result["players"]:
                if row["status"] in terminal:
                    continue
                number = row["number"]
                item = work[number]
                identity = item["identity"]
                expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
                try:
                    actual = identity_reader(identity["pid"])
                    if actual is None:
                        row["status"] = "process-exited"
                        continue
                    if actual != expected:
                        row["status"] = "identity-mismatch"
                        continue
                    lines = item["cursor"].lines()
                except (OSError, ValueError):
                    row["status"] = "log-error"
                    continue
                if any(needle in line.lower() for line in lines for _, needle in FATAL_DIAGNOSTICS):
                    row["status"] = "fatal-diagnostic"
                    continue
                if any("[TEST-ROUTE] password-input-ready" in line for line in lines):
                    row["readyObserved"] = True
                if any("[TEST-ROUTE] login-submitted" in line for line in lines):
                    row["submittedObserved"] = True
                    if row["queuedSequence"] is None:
                        row["status"] = "already-submitted"
                        continue
                keyboard = Path(item["player"]["keyboardFile"])
                if row["queuedSequence"] is not None:
                    try:
                        ack = int(Path(str(keyboard) + ".ack").read_text(encoding="ascii").strip())
                        row["queueAcknowledged"] = ack == row["queuedSequence"]
                    except (OSError, ValueError):
                        pass
                    if row["submittedObserved"]:
                        row["status"] = "submitted-not-authenticated"
                    continue
                if not row["readyObserved"]:
                    continue
                # Revalidate immediately before writing any private input.
                try:
                    identity_matches = identity_reader(identity["pid"]) == expected
                except (OSError, ValueError):
                    identity_matches = False
                if not identity_matches:
                    row["status"] = "identity-mismatch"
                    continue
                row["status"] = "queue-intent"
                save(output, result)
                try:
                    queued = (queue_writer(keyboard, passwords[number], True, replace=True) if replace else
                              queue_writer(keyboard, passwords[number], True))
                except ValueError as error:
                    row["status"] = "waiting-keyboard-ack" if str(error).startswith(retryable) else "queue-error"
                except OSError:
                    row["status"] = "queue-error"
                else:
                    row["queuedSequence"] = queued["sequence"]
                    row["status"] = "queued-not-submitted"
            save(output, result)
            if any(row["status"] not in terminal for row in result["players"]):
                sleeper(0.1)
    except KeyboardInterrupt:
        for row in result["players"]:
            if row["status"] not in terminal:
                row["status"] = "interrupted"
    finally:
        result["finishedUtc"] = utc()
        result["elapsedSeconds"] = monotonic() - started
        result["driverVerdict"] = ("submitted-not-authenticated" if all(
            row["status"] in ("submitted-not-authenticated", "already-submitted") for row in result["players"])
            else "incomplete")
        save(output, result)
    return result


def input_state(command):
    bits = 0
    for button in command.get("buttons", []):
        bits |= BUTTONS[button.lower()]
    axes = [int(command.get(k, 0)) for k in ("lx", "ly", "rx", "ry")]
    triggers = [int(command.get(k, 0)) for k in ("lt", "rt")]
    if any(abs(v) > 32767 for v in axes) or any(not 0 <= v <= 255 for v in triggers):
        raise ValueError("Input axis or trigger outside XInput range")
    return bits, *triggers, *axes


def keyboard_reports(text, enter=False, *, replace=False):
    """US-layout USB boot-keyboard reports, with a release after every key."""
    if (not text and not enter) or len(text) > 255 or any(not 32 <= ord(c) <= 126 for c in text):
        raise ValueError("Keyboard text must contain 1..255 printable ASCII characters, or use empty text with Enter")
    unshifted = {c: (0, 4 + i) for i, c in enumerate("abcdefghijklmnopqrstuvwxyz")}
    unshifted.update({c.upper(): (2, 4 + i) for i, c in enumerate("abcdefghijklmnopqrstuvwxyz")})
    unshifted.update({c: (0, 30 + i) for i, c in enumerate("1234567890")})
    unshifted.update({c: (2, 30 + i) for i, c in enumerate("!@#$%^&*()")})
    for plain, shifted, code in (("-", "_", 45), ("=", "+", 46), ("[", "{", 47),
                                 ("]", "}", 48), ("\\", "|", 49), (";", ":", 51),
                                 ("'", '"', 52), ("`", "~", 53), (",", "<", 54),
                                 (".", ">", 55), ("/", "?", 56)):
        unshifted[plain], unshifted[shifted] = (0, code), (2, code)
    unshifted[" "] = (0, 44)
    reports = []
    if replace:
        # Original editor: End (5c70d0) moves to strlen; Backspace (5c6a70)
        # removes the preceding character. Password fields hold at most 15.
        for code in (77,) + (42,) * 15:
            reports.extend((bytes((0, 0, code, 0, 0, 0, 0, 0)), bytes(8)))
    for character in text:
        modifier, code = unshifted[character]
        # Original EE libusbkb (0x1d5a88) uses a modifier change as a
        # state-only event and discards a simultaneous new key. Settle Shift
        # separately, then release the key before releasing the modifier.
        if modifier:
            reports.append(bytes((modifier, 0, 0, 0, 0, 0, 0, 0)))
        reports.append(bytes((modifier, 0, code, 0, 0, 0, 0, 0)))
        reports.append(bytes((modifier, 0, 0, 0, 0, 0, 0, 0)))
        if modifier:
            reports.append(bytes(8))
    if enter:
        reports.extend((bytes((0, 0, 40, 0, 0, 0, 0, 0)), bytes(8)))
    if len(reports) > 512:
        raise ValueError("Keyboard queue exceeds 512 boot reports")
    return reports


def queue_keyboard(path, text, enter=False, *, replace=False):
    reports = keyboard_reports(text, enter, replace=replace)
    path = Path(path)
    lock = Path(str(path) + ".writer-lock")
    try:
        descriptor = os.open(lock, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600)
    except FileExistsError:
        raise ValueError("Another keyboard writer owns this queue") from None
    try:
        os.close(descriptor)
        old = path.read_bytes()
        if len(old) < 12:
            raise ValueError("Keyboard queue header is incomplete")
        magic, previous, count = struct.unpack_from("<III", old)
        if magic != KEYBOARD_MAGIC or count > 512 or len(old) != 12 + count * 8:
            raise ValueError("Keyboard queue format is invalid")
        ack = Path(str(path) + ".ack")
        try:
            acknowledged = int(ack.read_text(encoding="ascii").strip())
        except (OSError, ValueError):
            raise ValueError("Keyboard consumer has not acknowledged the previous sequence") from None
        if acknowledged != previous:
            raise ValueError("Keyboard reports are still pending; refusing to overwrite them")
        if previous == 0xFFFFFFFF:
            raise ValueError("Keyboard sequence exhausted; use a new session")
        sequence = previous + 1
        payload = struct.pack("<III", KEYBOARD_MAGIC, sequence, len(reports)) + b"".join(reports)
        temporary = Path(str(path) + ".tmp-" + uuid.uuid4().hex)
        try:
            with open(temporary, "xb") as stream:
                stream.write(payload)
                stream.flush()
                os.fsync(stream.fileno())
            for attempt in range(11):
                try:
                    temporary.replace(path)
                    break
                except PermissionError:
                    if attempt == 10:
                        raise
                    time.sleep(0.02)
        finally:
            if temporary.exists():
                temporary.unlink()
        return {"sequence": sequence, "reports": len(reports), "characters": len(text),
                "enter": enter, "replaceExisting": replace,
                "acknowledgement": str(ack), "delivery": "queued-not-consumed"}
    finally:
        lock.unlink()


class Publisher:
    def __init__(self, name):
        self.mapping = mmap.mmap(-1, 64, tagname=name, access=mmap.ACCESS_WRITE)
        self.sequence = 0
        self.packet = 0
        self.previous = None
        self.mapping[:4] = struct.pack("<I", 0x52454F50)

    def publish(self, command):
        state = input_state(command)
        if state != self.previous:
            self.packet += 1
            self.previous = state
        self.sequence += 1
        self.mapping[4:8] = struct.pack("<I", self.sequence)
        self.mapping[8:32] = struct.pack("<IIIHBBhhhh", 1, native().GetTickCount() & 0xFFFFFFFF,
                                       self.packet, *state)
        self.sequence += 1
        self.mapping[4:8] = struct.pack("<I", self.sequence)

    def close(self):
        self.publish({})
        self.mapping.close()


def endpoints(pids):
    """IP Helper owner-PID tables. TCP state/remote and UDP bindings, no packet bytes."""
    library = ctypes.WinDLL("iphlpapi")
    rows = []
    for protocol in ("tcp", "udp"):
        for family in (2, 23):
            function = getattr(library, "GetExtendedTcpTable" if protocol == "tcp" else "GetExtendedUdpTable")
            function.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_ulong), ctypes.c_int,
                                 ctypes.c_ulong, ctypes.c_int, ctypes.c_ulong]
            size = ctypes.c_ulong()
            table_class = 5 if protocol == "tcp" else 1
            result = function(None, ctypes.byref(size), False, family, table_class, 0)
            if result not in (0, 122):
                raise OSError(f"IP Helper {protocol}/{family}: {result}")
            buffer = ctypes.create_string_buffer(size.value)
            result = function(buffer, ctypes.byref(size), False, family, table_class, 0)
            if result:
                raise OSError(f"IP Helper {protocol}/{family}: {result}")
            count = struct.unpack_from("<I", buffer)[0]
            stride = (24 if protocol == "tcp" else 12) if family == 2 else (56 if protocol == "tcp" else 28)
            for i in range(count):
                row = buffer.raw[4 + i * stride:4 + (i + 1) * stride]
                pid = struct.unpack_from("<I", row, stride - 4)[0]
                if pid not in pids:
                    continue
                if family == 2:
                    offset = 4 if protocol == "tcp" else 0
                    address = socket.inet_ntop(socket.AF_INET, row[offset:offset + 4])
                    port = socket.ntohs(struct.unpack_from("<I", row, offset + 4)[0] & 0xFFFF)
                    remote = socket.inet_ntop(socket.AF_INET, row[12:16]) if protocol == "tcp" else None
                    remote_port = socket.ntohs(struct.unpack_from("<I", row, 16)[0] & 0xFFFF) if protocol == "tcp" else None
                    state = struct.unpack_from("<I", row)[0] if protocol == "tcp" else None
                else:
                    address = socket.inet_ntop(socket.AF_INET6, row[:16])
                    port = socket.ntohs(struct.unpack_from("<I", row, 20)[0] & 0xFFFF)
                    remote = socket.inet_ntop(socket.AF_INET6, row[24:40]) if protocol == "tcp" else None
                    remote_port = socket.ntohs(struct.unpack_from("<I", row, 44)[0] & 0xFFFF) if protocol == "tcp" else None
                    state = struct.unpack_from("<I", row, 48)[0] if protocol == "tcp" else None
                rows.append(dict(pid=pid, protocol=protocol, family=family, local=address,
                                 localPort=port, remote=remote, remotePort=remote_port, state=state))
    return rows


def capture_window(identity, output, foreground=False, position=None):
    """Capture the owned HWND's desktop client rectangle without guest writes."""
    expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
    if process_identity(identity["pid"]) != expected:
        raise ValueError("Capture refused: PID creation time or executable differs")
    user = ctypes.WinDLL("user32", use_last_error=True)
    gdi = ctypes.WinDLL("gdi32", use_last_error=True)
    callback_type = ctypes.WINFUNCTYPE(ctypes.c_int, ctypes.c_void_p, ctypes.c_void_p)
    user.EnumWindows.argtypes = [callback_type, ctypes.c_void_p]
    user.GetWindowThreadProcessId.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_ulong)]
    user.IsWindowVisible.argtypes = [ctypes.c_void_p]
    user.IsIconic.argtypes = [ctypes.c_void_p]
    user.SetForegroundWindow.argtypes = [ctypes.c_void_p]
    user.SetWindowPos.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int, ctypes.c_int,
                                  ctypes.c_int, ctypes.c_int, ctypes.c_uint]
    user.SetThreadDpiAwarenessContext.argtypes = [ctypes.c_void_p]
    user.SetThreadDpiAwarenessContext.restype = ctypes.c_void_p
    user.GetClientRect.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
    user.ClientToScreen.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
    user.GetDC.argtypes = [ctypes.c_void_p]
    user.GetDC.restype = ctypes.c_void_p
    user.ReleaseDC.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
    gdi.CreateCompatibleDC.argtypes = [ctypes.c_void_p]
    gdi.CreateCompatibleDC.restype = ctypes.c_void_p
    gdi.CreateCompatibleBitmap.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int]
    gdi.CreateCompatibleBitmap.restype = ctypes.c_void_p
    gdi.SelectObject.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
    gdi.SelectObject.restype = ctypes.c_void_p
    gdi.DeleteObject.argtypes = [ctypes.c_void_p]
    gdi.DeleteDC.argtypes = [ctypes.c_void_p]
    gdi.BitBlt.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int,
                          ctypes.c_void_p, ctypes.c_int, ctypes.c_int, ctypes.c_ulong]
    gdi.GetDIBits.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_uint, ctypes.c_uint,
                             ctypes.c_void_p, ctypes.c_void_p, ctypes.c_uint]

    class Rect(ctypes.Structure):
        _fields_ = [(k, ctypes.c_long) for k in ("left", "top", "right", "bottom")]

    class Point(ctypes.Structure):
        _fields_ = [("x", ctypes.c_long), ("y", ctypes.c_long)]

    windows = []

    @callback_type
    def visit(hwnd, _):
        pid = ctypes.c_ulong()
        user.GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
        rect = Rect()
        if pid.value == identity["pid"] and user.IsWindowVisible(hwnd) and user.GetClientRect(hwnd, ctypes.byref(rect)):
            area = (rect.right - rect.left) * (rect.bottom - rect.top)
            if area > 0:
                windows.append((area, hwnd))
        return 1

    previous_dpi = user.SetThreadDpiAwarenessContext(ctypes.c_void_p(-4))
    dc = bitmap = memory = old = None
    try:
        user.EnumWindows(visit, None)
        if not windows:
            raise ValueError("Owned process has no visible client window")
        hwnd = max(windows)[1]
        if user.IsIconic(hwnd):
            raise ValueError("Capture refused: owned window is minimized")
        if position:
            if not user.SetWindowPos(hwnd, None, *position, 0, 0, 0x4015):
                raise ctypes.WinError(ctypes.get_last_error())
            time.sleep(0.15)
        if foreground:
            user.SetForegroundWindow(hwnd)
            time.sleep(0.15)
        rect, origin = Rect(), Point()
        if not user.GetClientRect(hwnd, ctypes.byref(rect)) or not user.ClientToScreen(hwnd, ctypes.byref(origin)):
            raise ctypes.WinError(ctypes.get_last_error())
        width, height = rect.right - rect.left, rect.bottom - rect.top
        if not (0 < width <= 16384 and 0 < height <= 16384):
            raise ValueError("Invalid capture dimensions")
        dc = user.GetDC(None)
        memory = gdi.CreateCompatibleDC(dc)
        bitmap = gdi.CreateCompatibleBitmap(dc, width, height)
        if not dc or not memory or not bitmap:
            raise ctypes.WinError(ctypes.get_last_error())
        old = gdi.SelectObject(memory, bitmap)
        if not gdi.BitBlt(memory, 0, 0, width, height, dc, origin.x, origin.y, 0x40CC0020):
            raise ctypes.WinError(ctypes.get_last_error())
        gdi.SelectObject(memory, old)
        old = None
        header = ctypes.create_string_buffer(struct.pack("<IiiHHIIiiII", 40, width, -height, 1, 32,
                                                         0, width * height * 4, 0, 0, 0, 0))
        pixels = ctypes.create_string_buffer(width * height * 4)
        if gdi.GetDIBits(dc, bitmap, 0, height, pixels, header, 0) != height:
            raise ctypes.WinError(ctypes.get_last_error())
        current_pid = ctypes.c_ulong()
        user.GetWindowThreadProcessId(hwnd, ctypes.byref(current_pid))
        if current_pid.value != identity["pid"] or process_identity(identity["pid"]) != expected:
            raise ValueError("Process/window identity changed during capture")
        rgba = bytearray(pixels.raw)
        rgba[0::4], rgba[2::4] = rgba[2::4], rgba[0::4]
        rgba[3::4] = b"\xff" * (width * height)
        raw = b"".join(b"\x00" + rgba[y * width * 4:(y + 1) * width * 4] for y in range(height))

        def chunk(kind, contents):
            return struct.pack(">I", len(contents)) + kind + contents + struct.pack(">I", zlib.crc32(kind + contents))

        png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
        png += chunk(b"IDAT", zlib.compress(raw, 6)) + chunk(b"IEND", b"")
        Path(output).write_bytes(png)
        result = {"utc": utc(), **expected, "hwnd": hwnd, "width": width, "height": height,
                  "screenX": origin.x, "screenY": origin.y, "method": "desktop-client-rectangle",
                  "occlusionPossible": True, "foregroundRequested": foreground,
                  "positionRequested": position,
                  "screenshot": str(Path(output).resolve()), "sha256": digest(output)}
        save(Path(output).with_suffix(".json"), result)
        return result
    finally:
        if old and memory:
            gdi.SelectObject(memory, old)
        if bitmap:
            gdi.DeleteObject(bitmap)
        if memory:
            gdi.DeleteDC(memory)
        if dc:
            user.ReleaseDC(None, dc)
        if previous_dpi:
            user.SetThreadDpiAwarenessContext(previous_dpi)


def environment(record, player, extra):
    env = {k: v for k, v in os.environ.items() if not k.upper().startswith("REO_")}
    env.update(REO_ISO=record["iso"], REO_MC0_ROOT=player["card"], REO_MC1_ROOT=":none:",
               REO_LAUNCHER_PAD_MAP=player["map"], REO_NATURAL="1", REO_TURBO="1",
               REO_GS_BACKEND="parallel", REO_GS_THREAD="1", REO_GS_GPU_PRESENT="1",
               REO_GS_DISPATCH_PACE="2", REO_GS_SPRITE_DEPTH_PARALLEL="1",
               REO_VIF1_ASYNC="1", REO_VIF1_GPU_RESIDENT="0", REO_GPU_MOVIE="1",
               REO_WINDOW_WIDTH="640", REO_WINDOW_HEIGHT="480", REO_POST_AA="off")
    if player.get("keyboardFile"):
        env["REO_COOP_KEYBOARD_FILE"] = player["keyboardFile"]
    for key, value in extra.items():
        if not key.startswith("REO_") or key in PINNED or not isinstance(value, str):
            raise ValueError(f"Invalid or isolation-protected environment key: {key}")
        env[key] = value
    return env


def run(args):
    folder, record = session_record(args.session)
    if (folder / "run.json").exists():
        raise ValueError("This prepared session was already run; prepare a new session")
    validate_import(record["importRoot"], record["iso"], record.get("game", "file1"))
    config = json.loads(Path(args.config).read_text(encoding="utf-8")) if args.config else {}
    if args.route:
        config.setdefault("environment", {})["REO_TEST_ROUTE"] = args.route
    if len(config.get("players", [])) not in (0, len(record["players"])):
        raise ValueError("Config players must match the prepared player count")
    # Validate all inputs before starting any native process.
    launches = []
    for i, player in enumerate(record["players"]):
        for item in player["files"]:
            if digest(beneath(Path(player["image"]).parent.parent, item["path"])) != item["sha256"]:
                raise ValueError("Immutable copied image dependency changed")
        extra = dict(config.get("environment", {}))
        if config.get("players"):
            extra.update(config["players"][i].get("environment", {}))
        launches.append(environment(record, player, extra))
    # Online clients: write the same network-profile marker the launcher writes (launcher
    # OnlineOptions.PrepareMemoryCard), or a fresh card stops at "Select Network Configuration".
    # An existing BWNETCNF folder is left untouched.
    for player, env in zip(record["players"], launches):
        if env.get("REO_COOP_HOST") and env.get("REO_COOP_PLATFORM_AUTH") == "native":
            profile = Path(player["card"]) / "BWNETCNF"
            if not profile.exists():
                profile.mkdir()
                (profile / "BWNETDCNF").write_bytes(b"REO native host profile provider v1")
    processes, publishers, handles = [], [], []
    receipt = {"startedUtc": utc(), "players": [], "coopVerdict": "not-tested",
               "networkConfig": config, "errors": []}
    started = time.monotonic()
    try:
        for player, env in zip(record["players"], launches):
            publisher = Publisher(player["map"])
            publishers.append(publisher)
            publisher.publish({})
            output = open(Path(player["logs"]) / "stdout.log", "wb")
            error = open(Path(player["logs"]) / "stderr.log", "wb")
            handles += [output, error]
            argv = [player["image"], "--game", record.get("game", "file1"), "--elf", record["elf"], "--data", record["data"]]
            process = subprocess.Popen(argv, cwd=player["workingDirectory"], env=env,
                                       stdout=output, stderr=error, creationflags=subprocess.CREATE_NO_WINDOW)
            processes.append(process)
            identity = process_identity(process.pid)
            if identity is None:
                raise ValueError("Native process exited before identity capture")
            receipt["players"].append({"number": player["number"], **identity, "argv": argv,
                                       "environment": {k: v for k, v in env.items() if k.startswith("REO_")}})
            save(folder / "run.json", receipt)
        print(json.dumps({"running": str(folder), "pids": [p.pid for p in processes],
                          "coopVerdict": "not-tested"}), flush=True)
        last_network = -10.0
        with open(folder / "endpoints.jsonl", "a", encoding="utf-8") as traffic:
            while any(p.poll() is None for p in processes):
                elapsed = time.monotonic() - started
                if args.seconds and elapsed >= args.seconds:
                    receipt["stopReason"] = "duration-limit"
                    break
                for player, publisher, process in zip(record["players"], publishers, processes):
                    if process.poll() is None:
                        try:
                            command = json.loads(Path(player["inputFile"]).read_text(encoding="utf-8"))
                            expires = command.get("expiresUnix", float("inf"))
                            publisher.publish(command if expires >= time.time() else {})
                        except (OSError, ValueError, KeyError) as e:
                            publisher.publish({})
                            receipt["errors"].append({"utc": utc(), "input": player["number"], "error": str(e)})
                if elapsed - last_network >= 2:
                    try:
                        sample = {"utc": utc(), "elapsedSeconds": elapsed,
                                  "endpoints": endpoints({p.pid for p in processes if p.poll() is None})}
                    except OSError as e:
                        sample = {"utc": utc(), "error": str(e)}
                    traffic.write(json.dumps(sample) + "\n")
                    traffic.flush()
                    last_network = elapsed
                time.sleep(0.016)
    except KeyboardInterrupt:
        receipt["stopReason"] = "operator-interrupt"
    finally:
        # Stop only PIDs with the captured creation identity and owned image.
        stopped_pids = set()
        receipt["cleanup"] = []
        for identity in receipt["players"]:
            try:
                stopped = stop_owned(identity)
                if stopped:
                    stopped_pids.add(identity["pid"])
                receipt["cleanup"].append({"pid": identity["pid"],
                                           "action": "terminated-owned-process" if stopped else "already-exited"})
            except (OSError, ValueError) as e:
                receipt["errors"].append({"utc": utc(), "stopPid": identity["pid"], "error": str(e)})
        for p in processes:
            p.wait(timeout=15)
        for publisher in publishers:
            publisher.close()
        for handle in handles:
            handle.close()
        receipt["finishedUtc"] = utc()
        receipt["elapsedSeconds"] = time.monotonic() - started
        receipt["exitCodes"] = [p.returncode for p in processes]
        receipt["nativeResults"] = []
        for player, process in zip(record["players"], processes):
            diagnostics = classify_native_logs(player["logs"])
            identity = next(p for p in receipt["players"] if p["pid"] == process.pid)
            external_stop = owned_stop_provenance(folder, identity, process.returncode)
            receipt["nativeResults"].append({"number": player["number"], "pid": process.pid,
                "exitCode": process.returncode, "diagnostics": diagnostics,
                "operatorStopReceipt": external_stop,
                "outcome": native_outcome(process.returncode, diagnostics, process.pid in stopped_pids, bool(external_stop))})
        receipt["runVerdict"] = "native-failure" if any(
            p["outcome"] in ("fatal-diagnostic", "nonzero-exit") for p in receipt["nativeResults"]) else "not-evaluated"
        save(folder / "run.json", receipt)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    p = sub.add_parser("prepare")
    p.add_argument("--session", required=True)
    p.add_argument("--players", type=int, default=2)
    p.add_argument("--game", choices=tuple(GAMES), default="file1")
    p.add_argument("--root", default=str(Path(__file__).resolve().parents[2]))
    for arg in ("exe", "iso", "import-root", "adapter"):
        p.add_argument("--" + arg)
    p.set_defaults(action=prepare)
    p = sub.add_parser("run")
    p.add_argument("--session", required=True)
    p.add_argument("--seconds", type=float, default=0, help="0 runs until exit or Ctrl+C")
    p.add_argument("--config")
    p.add_argument("--route", choices=("main-menu", "character", "gameplay", "network-connect", "network-account", "network-login"))
    p.set_defaults(action=run)
    p = sub.add_parser("drive-login")
    p.add_argument("--session", required=True)
    p.add_argument("--timeout", type=float, default=240)
    p.add_argument("--replace", action="store_true", help="Replace an existing password through original End/Backspace input")
    p.add_argument("--player", type=int, action="append", help="Repeat to select players; default all")
    passwords = p.add_mutually_exclusive_group(required=True)
    passwords.add_argument("--password", help="Disposable test password shared by selected players")
    passwords.add_argument("--password-file", help="JSON object mapping player numbers to disposable test passwords")
    p = sub.add_parser("drive-lobby")
    p.add_argument("--session", required=True)
    p.add_argument("--goal", choices=("shared-area", "waiting-room"), default="shared-area")
    p.add_argument("--timeout", type=float, default=240)
    p.add_argument("--press-limit", type=int, default=100)
    p = sub.add_parser("drive-start", help="Host starts the scenario; all players skip cutscenes until gameplay")
    p.add_argument("--session", required=True)
    p.add_argument("--timeout", type=float, default=240)
    p = sub.add_parser("snapshot-actors")
    p.add_argument("--session", required=True)
    p.add_argument("--label", required=True)
    for name in ("status", "stop", "input", "capture", "text", "diagnostics"):
        p = sub.add_parser(name)
        p.add_argument("--session", required=True)
        if name == "input":
            p.add_argument("--player", type=int, required=True)
            p.add_argument("--buttons", nargs="*", default=[])
            p.add_argument("--hold", type=float, default=0.2)
        if name == "capture":
            p.add_argument("--player", type=int, default=1)
            p.add_argument("--foreground", action="store_true")
            p.add_argument("--position", nargs=2, type=int, metavar=("X", "Y"))
            p.add_argument("--output", help="Relative path inside the session directory")
        if name == "text":
            p.add_argument("--player", type=int, required=True)
            p.add_argument("--text", required=True)
            p.add_argument("--enter", action="store_true")
            p.add_argument("--replace", action="store_true", help="End then 15 Backspaces before text; only for an initialized password editor")
    args = parser.parse_args()
    if hasattr(args, "action"):
        args.action(args)
        return
    folder, record = session_record(args.session)
    if args.command == "snapshot-actors":
        import actor_snapshot
        print(json.dumps(actor_snapshot.snapshot_actors(folder, record, args.label), indent=2))
        return
    if args.command == "drive-start":
        import start_driver
        result = start_driver.drive(folder, record, timeout=args.timeout)
        print(json.dumps(result, indent=2))
        if not result.get("allInGameplay"):
            raise SystemExit(2)
        return
    if args.command == "drive-lobby":
        import lobby_driver
        result = lobby_driver.drive(folder, record, goal=args.goal, timeout=args.timeout, press_limit=args.press_limit)
        print(json.dumps(result, indent=2))
        if not result.get("uiGoalObserved"):
            raise SystemExit(2)
        return
    if args.command == "drive-login":
        numbers = args.player or [p["number"] for p in record["players"]]
        if len(set(numbers)) != len(numbers):
            raise ValueError("Duplicate selected player")
        if args.password_file:
            supplied = json.loads(Path(args.password_file).read_text(encoding="utf-8"))
            if not isinstance(supplied, dict) or any(str(n) not in supplied for n in numbers):
                raise ValueError("Password file must map every selected player number to a disposable test password")
            passwords = {n: supplied[str(n)] for n in numbers}
        else:
            passwords = {n: args.password for n in numbers}
        result = drive_login(folder, record, passwords, args.timeout, replace=args.replace)
        print(json.dumps(result, indent=2))
        if result["driverVerdict"] != "submitted-not-authenticated":
            raise SystemExit(2)
        return
    if args.command == "diagnostics":
        print(json.dumps({"players": [{"number": p["number"], "diagnostics": classify_native_logs(p["logs"])}
                                      for p in record["players"]], "coopVerdict": "not-tested"}, indent=2))
        return
    if args.command == "text":
        if not 1 <= args.player <= len(record["players"]):
            raise ValueError("Invalid player")
        player = record["players"][args.player - 1]
        if not player.get("keyboardFile"):
            raise ValueError("Legacy session has no keyboard queue; prepare a new session")
        print(json.dumps(queue_keyboard(player["keyboardFile"], args.text, args.enter, replace=args.replace), indent=2))
        return
    if args.command == "input":
        if not 1 <= args.player <= len(record["players"]) or not 0 <= args.hold <= 30:
            raise ValueError("Invalid player or hold duration (0..30 seconds)")
        command = {"buttons": args.buttons, "expiresUnix": time.time() + args.hold}
        input_state(command)
        save(record["players"][args.player - 1]["inputFile"], command)
        return
    receipt = json.loads((folder / "run.json").read_text(encoding="utf-8"))
    if args.command == "capture":
        matches = [p for p in receipt["players"] if p["number"] == args.player]
        if len(matches) != 1:
            raise ValueError("Player has no unique launched process identity")
        output = beneath(folder, args.output or f"captures/player{args.player}-{time.time_ns()}.png")
        output.parent.mkdir(parents=True, exist_ok=True)
        if output.suffix.lower() != ".png":
            raise ValueError("Capture output must use .png")
        if output.exists() or output.with_suffix(".json").exists():
            raise ValueError("Capture output exists; use a new path")
        print(json.dumps(capture_window(matches[0], output, args.foreground, args.position), indent=2))
        return
    states = []
    for item in receipt["players"]:
        actual = process_identity(item["pid"])
        owned = actual == {k: item[k] for k in ("pid", "image", "creationFileTime")}
        states.append({"player": item["number"], "pid": item["pid"], "sameProcessAlive": owned})
        if args.command == "stop" and owned:
            request_owned_stop(folder, item)
    print(json.dumps({"players": states, "coopVerdict": "not-tested"}, indent=2))


if __name__ == "__main__":
    main()
