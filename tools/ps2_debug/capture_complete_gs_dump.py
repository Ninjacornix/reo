"""Capture the ORIGINAL game's full stock PCSX2 GS dump; default is plan-only.

Windows, Python stdlib and the adjacent read-only PineClient. No guest writes,
emulator code patches, synthetic state, global keyboard injection or GPU replay.
Use --run explicitly. The coordinator owns launching this tool.
"""
from __future__ import annotations

import argparse
import ctypes
from ctypes import wintypes
import hashlib
import json
import mmap
import os
from pathlib import Path
import re
import socket
import struct
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
SOURCES = {
    "dump_writer": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/GS/GSDump.cpp",
    "dump_header": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/GS/GSDump.h",
    "dump_hotkeys": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/GS/GS.cpp",
    "freeze": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/GS/GSState.cpp",
    "version": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/GS/GSState.h",
    "host": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2-qt/QtHost.cpp",
    "pine_start": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/VMManager.cpp",
    "pine_default": "https://github.com/PCSX2/pcsx2/blob/v2.2.0/pcsx2/PINE.h",
}
ROUTE = [(55, 0x0D), (60, 0x5A), (64, 0x5A), (70, 0x5A),
         (76, 0x5A), (82, 0x5A), (88, 0x0D), (94, 0x0D),
         (104, 0x0D), (114, 0x0D)]
MAX_DUMP = 512 * 1024 * 1024


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def patch_ini(original: bytes, changes: dict[str, dict[str, str]]) -> bytes:
    """Keep all unrelated settings and newline/BOM style; reject ambiguity."""
    bom = original.startswith(b"\xef\xbb\xbf")
    text = original.decode("utf-8-sig")
    newline = "\r\n" if "\r\n" in text else "\n"
    lines = text.splitlines()
    # Free the reserved local capture keys before assigning the official action.
    section = ""
    for index, line in enumerate(lines):
        match = re.fullmatch(r"\s*\[([^]]+)\]\s*", line)
        if match:
            section = match[1]
        elif section == "Hotkeys" and "=" in line:
            key, value = line.split("=", 1)
            if re.search(r"Keyboard/F1[01](?![0-9])", value):
                lines[index] = key.rstrip() + " = "
    for section, values in changes.items():
        starts = [i for i, line in enumerate(lines)
                  if re.fullmatch(r"\s*\[" + re.escape(section) + r"\]\s*", line)]
        if len(starts) > 1:
            raise ValueError(f"duplicate INI section: {section}")
        if not starts:
            lines.extend(["", f"[{section}]"])
            starts = [len(lines) - 1]
        start = starts[0]
        end = next((i for i in range(start + 1, len(lines))
                    if re.fullmatch(r"\s*\[[^]]+\]\s*", lines[i])), len(lines))
        additions = []
        for key, value in values.items():
            matches = [i for i in range(start + 1, end)
                       if re.match(r"\s*" + re.escape(key) + r"\s*=", lines[i])]
            if len(matches) > 1:
                raise ValueError(f"duplicate INI key: {section}/{key}")
            if matches:
                lines[matches[0]] = f"{key} = {value}"
            else:
                additions.append(f"{key} = {value}")
        lines[end:end] = additions
    result = (newline.join(lines) + newline).encode("utf-8")
    return (b"\xef\xbb\xbf" if bom else b"") + result


def validate_dump(path: Path, expected_version: int | None = None) -> dict:
    """Read, never repair: new-header uncompressed stock GS dump, versions 8/9.

    Structural validation is not a pixel/replay equivalence claim. Compressed
    dumps are deliberately rejected: this capture sets GSDumpCompression=0.
    """
    if path.suffix.lower() != ".gs":
        raise ValueError("expected uncompressed .gs; compressed/partial captures unsupported")
    size = path.stat().st_size
    if not 44 + 4 * 1024 * 1024 + 0x2000 < size <= MAX_DUMP:
        raise ValueError(f"dump length outside bounded complete-state range: {size}")
    with path.open("rb") as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as data:
        magic, header_size = struct.unpack_from("<II", data)
        if magic != 0xFFFFFFFF or not 36 <= header_size <= 64 * 1024 * 1024:
            raise ValueError("missing stock secondary header or invalid header size")
        if 8 + header_size > size:
            raise ValueError("truncated secondary header")
        (version, state_size, serial_offset, serial_size, crc, width, height,
         picture_offset, picture_size) = struct.unpack_from("<9I", data, 8)
        if version not in (8, 9) or (expected_version is not None and version != expected_version):
            raise ValueError(f"unexpected freeze version {version}; expected {expected_version or '8/9'}")
        for offset, length, label in [(serial_offset, serial_size, "serial"),
                                       (picture_offset, picture_size, "thumbnail")]:
            if offset < 36 or offset + length > header_size:
                raise ValueError(f"{label} span outside header")
        if serial_size and picture_size and not (
                serial_offset + serial_size <= picture_offset or
                picture_offset + picture_size <= serial_offset):
            raise ValueError("serial/thumbnail spans overlap")
        if width > 16384 or height > 16384 or picture_size != width * height * 4:
            raise ValueError("invalid RGBA thumbnail dimensions")
        if not 4 * 1024 * 1024 <= state_size <= 32 * 1024 * 1024:
            raise ValueError("freeze does not contain the bounded complete VRAM/state span")
        state_offset = 8 + header_size
        regs_offset = state_offset + state_size
        cursor = regs_offset + 0x2000
        if cursor >= size or struct.unpack_from("<I", data, state_offset)[0] != version:
            raise ValueError("truncated state/privileged registers or mismatched state version")
        counts = [0, 0, 0, 0]
        paths = [{"packets": 0, "bytes": 0} for _ in range(4)]
        fields = [0, 0]
        fifo_bytes = 0
        last = None
        while cursor < size:
            packet_offset = cursor
            kind = data[cursor]
            cursor += 1
            if kind > 3:
                raise ValueError(f"unknown packet {kind} at {packet_offset}")
            if kind == 0:
                if cursor + 5 > size:
                    raise ValueError("truncated transfer header")
                path_index = data[cursor]
                length = struct.unpack_from("<I", data, cursor + 1)[0]
                cursor += 5
                if path_index > 3 or length == 0 or length % 16 or cursor + length > size:
                    raise ValueError(f"invalid/truncated GIF transfer at {packet_offset}")
                paths[path_index]["packets"] += 1
                paths[path_index]["bytes"] += length
                cursor += length
            elif kind == 1:
                if cursor == size or data[cursor] > 1:
                    raise ValueError("truncated/invalid VSync field")
                fields[data[cursor]] += 1
                cursor += 1
            elif kind == 2:
                if cursor + 4 > size:
                    raise ValueError("truncated FIFO record")
                length = struct.unpack_from("<I", data, cursor)[0]
                if length == 0:
                    raise ValueError("invalid zero-length FIFO record")
                fifo_bytes += length
                cursor += 4
            else:
                cursor += 0x2000
                if cursor > size:
                    raise ValueError("truncated privileged-register update")
            counts[kind] += 1
            last = kind
            if sum(counts) > 10_000_000:
                raise ValueError("packet count exceeds bounded validator budget")
        if not counts[0] or counts[1] < 2 or counts[3] < 2 or last != 1:
            raise ValueError("missing transfers/VSync tail: capture is incomplete or non-room")
        serial = data[8 + serial_offset:8 + serial_offset + serial_size].decode("utf-8", errors="strict")
        report = dict(path=str(path.resolve()), bytes=size, sha256=hashlib.sha256(data).hexdigest(),
                      format="stock_new_header_uncompressed", state_version=version,
                      state_bytes=state_size, state_offset=state_offset,
                      state_sha256=hashlib.sha256(data[state_offset:regs_offset]).hexdigest(),
                      privileged_regs_offset=regs_offset, privileged_regs_bytes=0x2000,
                      privileged_regs_sha256=hashlib.sha256(data[regs_offset:regs_offset + 0x2000]).hexdigest(),
                      header_bytes=header_size, serial=serial, game_crc=f"{crc:08X}",
                      thumbnail=dict(width=width, height=height, bytes=picture_size,
                                     offset=8 + picture_offset),
                      record_counts=dict(zip(["transfer", "vsync", "read_fifo", "registers"], counts)),
                      paths=paths, fields=fields, fifo_bytes=fifo_bytes,
                      structural_complete=True, last_record="vsync", pixel_replay_validated=False)
    return report


class WindowsOwner:
    def __init__(self):
        if os.name != "nt":
            raise RuntimeError("owned-window automation requires Windows")
        self.user = ctypes.WinDLL("user32", use_last_error=True)
        self.kernel = ctypes.WinDLL("kernel32", use_last_error=True)
        self.callback = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)
        self.user.EnumWindows.argtypes = [self.callback, wintypes.LPARAM]
        self.user.GetWindowThreadProcessId.argtypes = [wintypes.HWND, ctypes.POINTER(wintypes.DWORD)]
        self.user.IsWindowVisible.argtypes = [wintypes.HWND]
        self.user.GetWindowTextW.argtypes = [wintypes.HWND, wintypes.LPWSTR, ctypes.c_int]
        self.user.PostMessageW.argtypes = [wintypes.HWND, wintypes.UINT, wintypes.WPARAM, wintypes.LPARAM]
        self.user.PostMessageW.restype = wintypes.BOOL
        self.user.MapVirtualKeyW.argtypes = [wintypes.UINT, wintypes.UINT]
        self.held = set()

    def running_emulators(self) -> list[dict]:
        class Entry(ctypes.Structure):
            _fields_ = [("dwSize", wintypes.DWORD), ("cntUsage", wintypes.DWORD),
                        ("th32ProcessID", wintypes.DWORD), ("th32DefaultHeapID", ctypes.c_size_t),
                        ("th32ModuleID", wintypes.DWORD), ("cntThreads", wintypes.DWORD),
                        ("th32ParentProcessID", wintypes.DWORD), ("pcPriClassBase", wintypes.LONG),
                        ("dwFlags", wintypes.DWORD), ("szExeFile", wintypes.WCHAR * 260)]
        self.kernel.CreateToolhelp32Snapshot.argtypes = [wintypes.DWORD, wintypes.DWORD]
        self.kernel.CreateToolhelp32Snapshot.restype = wintypes.HANDLE
        self.kernel.Process32FirstW.argtypes = [wintypes.HANDLE, ctypes.POINTER(Entry)]
        self.kernel.Process32NextW.argtypes = [wintypes.HANDLE, ctypes.POINTER(Entry)]
        self.kernel.CloseHandle.argtypes = [wintypes.HANDLE]
        handle = self.kernel.CreateToolhelp32Snapshot(2, 0)
        if handle in (None, ctypes.c_void_p(-1).value):
            raise ctypes.WinError(ctypes.get_last_error())
        result = []
        try:
            entry = Entry()
            entry.dwSize = ctypes.sizeof(entry)
            present = self.kernel.Process32FirstW(handle, ctypes.byref(entry))
            while present:
                if entry.szExeFile.lower().startswith("pcsx2"):
                    result.append(dict(pid=entry.th32ProcessID, name=entry.szExeFile))
                present = self.kernel.Process32NextW(handle, ctypes.byref(entry))
        finally:
            self.kernel.CloseHandle(handle)
        return result

    def windows(self, pid: int) -> list[tuple[int, str]]:
        result = []
        @self.callback
        def visit(handle, _):
            owner = wintypes.DWORD()
            self.user.GetWindowThreadProcessId(handle, ctypes.byref(owner))
            if owner.value == pid and self.user.IsWindowVisible(handle):
                name = ctypes.create_unicode_buffer(512)
                self.user.GetWindowTextW(handle, name, len(name))
                result.append((handle, name.value))
            return True
        self.user.EnumWindows(visit, 0)
        return result

    def listeners(self, pid: int) -> list[dict]:
        """Windows TCP listener PID table; do not connect to an unowned port."""
        api = ctypes.WinDLL("iphlpapi", use_last_error=True)
        query = api.GetExtendedTcpTable
        query.argtypes = [ctypes.c_void_p, ctypes.POINTER(wintypes.DWORD),
                          wintypes.BOOL, wintypes.ULONG, ctypes.c_int, wintypes.ULONG]
        query.restype = wintypes.DWORD
        capacity = wintypes.DWORD(0)
        result = query(None, ctypes.byref(capacity), False, 2, 3, 0)
        if result not in (0, 122):
            raise OSError(result, "GetExtendedTcpTable size query failed")
        for _ in range(4):
            if not 4 <= capacity.value <= 16 * 1024 * 1024:
                raise ValueError("TCP listener table exceeds bounded query budget")
            table = ctypes.create_string_buffer(capacity.value)
            result = query(table, ctypes.byref(capacity), False, 2, 3, 0)
            if result == 122:
                continue
            if result:
                raise OSError(result, "GetExtendedTcpTable query failed")
            data = table.raw[:capacity.value]
            count = struct.unpack_from("<I", data)[0]
            if 4 + count * 24 > len(data):
                raise ValueError("truncated Windows TCP listener table")
            listeners = []
            for index in range(count):
                state, address, port, _, _, owner = struct.unpack_from("<6I", data, 4 + index * 24)
                if owner == pid:
                    listeners.append(dict(pid=owner, address=socket.inet_ntoa(struct.pack("<I", address)),
                                          port=socket.ntohs(port & 0xFFFF), state=state))
            return listeners
        raise RuntimeError("TCP listener table changed repeatedly during bounded query")

    def key(self, handle: int, code: int, down: bool):
        scan = self.user.MapVirtualKeyW(code, 0)
        flags = 1 | (scan << 16) | (0 if down else 3 << 30)
        if not self.user.PostMessageW(handle, 0x100 if down else 0x101, code, flags):
            raise ctypes.WinError(ctypes.get_last_error())
        if down:
            self.held.add((handle, code))
        else:
            self.held.discard((handle, code))

    def pulse(self, handle: int, code: int):
        self.key(handle, code, True)
        try:
            time.sleep(.30)
        finally:
            self.key(handle, code, False)

    def close(self, proc) -> bool:
        for handle, code in list(self.held):
            try:
                self.key(handle, code, False)
            except OSError:
                pass
        if proc.poll() is not None:
            return proc.returncode == 0
        for handle, _ in self.windows(proc.pid):
            self.user.PostMessageW(handle, 0x10, 0, 0)  # WM_CLOSE, owned HWND only.
        try:
            proc.wait(timeout=15)
            return proc.returncode == 0
        except subprocess.TimeoutExpired:
            proc.terminate()
            try:
                proc.wait(timeout=5)
            except subprocess.TimeoutExpired:
                proc.kill()
                proc.wait(timeout=5)
            return False


def room_state(client) -> dict:
    phase = client.read32(0x4BADD0)
    manager = client.read32(0x4A5C30 + 0x34)
    root = client.read32(manager + 0x820) if 0 < manager < 0x1FFF000 else 0
    valid = phase == 2 and 0 < manager < 0x1FFF000 and 0 < root < 0x1FFF000
    return dict(phase=phase, player0_manager=manager, player0_root=root, room=valid)


def run_capture(args) -> dict:
    from pine_client import PineClient
    owner = WindowsOwner()
    running = owner.running_emulators()
    if running:
        raise RuntimeError(f"close existing PCSX2 first; settings are shared: {running}")
    for path in (args.pcsx2, args.ini, args.iso):
        if path is None or not path.is_file():
            raise ValueError(f"missing required input file: {path}")
    if args.state_file and not args.state_file.is_file():
        raise ValueError("provided genuine savestate does not exist")
    if (args.pcsx2.parent / "portable.ini").exists():
        raise ValueError("portable PCSX2 uses another INI; this user-INI helper refuses ambiguity")
    with socket.socket() as probe:
        probe.bind(("127.0.0.1", args.pine_port))
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    original = args.ini.read_bytes()
    (out / "PCSX2.original.ini").write_bytes(original)
    changes = {
        "Folders": {"Snapshots": out.as_posix()},
        "UI": {"ConfirmShutdown": "false", "StartPaused": "false",
               "PauseOnFocusLoss": "false", "StartFullscreen": "false",
               "RenderToSeparateWindow": "false"},
        "EmuCore": {"EnablePINE": "true", "PINESlot": str(args.pine_port),
                    "SaveStateOnShutdown": "false"},
        "EmuCore/GS": {"GSDumpCompression": "0"},
        "Pad1": {"Start": "Keyboard/Return", "Cross": "Keyboard/Z",
                 "Circle": "Keyboard/X", "Left": "Keyboard/Left"},
        "Hotkeys": {"GSDumpSingleFrame": "Keyboard/F10", "GSDumpMultiFrame": "Keyboard/F11"},
    }
    patched = patch_ini(original, changes)
    (out / "PCSX2.capture.ini").write_bytes(patched)
    manifest = dict(kind="original_stock_full_gs_dump", output=str(out), sources=SOURCES,
                    binary=str(args.pcsx2), binary_sha256=sha256_file(args.pcsx2),
                    iso=str(args.iso), ini=str(args.ini), ini_original_sha256=hashlib.sha256(original).hexdigest(),
                    ini_capture_sha256=hashlib.sha256(patched).hexdigest(), changes=changes,
                    launch=None, room_proof=None, dump=None, graceful_close=False,
                    ini_restored=False, success=False, partial_pine_capture=False)
    proc = client = None
    try:
        args.ini.write_bytes(patched)
        command = [str(args.pcsx2), "-fastboot", "-nofullscreen"]
        if args.state_file:
            command += ["-statefile", str(args.state_file.resolve())]
        command += [str(args.iso.resolve())]
        manifest["launch"] = command
        with (out / "pcsx2-console.log").open("wb") as console, (out / "timeline.jsonl").open("w", encoding="utf-8") as timeline:
            proc = subprocess.Popen(command, stdout=console, stderr=subprocess.STDOUT)
            start = time.monotonic()
            manifest["pid"] = proc.pid
            print(json.dumps(dict(owned_pid=proc.pid, output=str(out))), flush=True)
            stable = None
            event = 0
            handle = None
            last_error = None
            while time.monotonic() - start < args.timeout - 25:
                elapsed = time.monotonic() - start
                if proc.poll() is not None:
                    raise RuntimeError(f"owned PCSX2 exited before capture: {proc.returncode}")
                windows = owner.windows(proc.pid)
                handle = next((h for h, name in windows if "Outbreak" in name), None)
                row = dict(elapsed=elapsed, windows=[name for _, name in windows])
                if client is None:
                    listeners = owner.listeners(proc.pid)
                    row["owned_tcp_listeners"] = listeners
                    port_owned = any(item["port"] == args.pine_port and
                                     item["address"] == "127.0.0.1" for item in listeners)
                    if not port_owned:
                        if elapsed >= 20:
                            raise TimeoutError(f"owned PINE listener {args.pine_port} missing after20s; actual={listeners}")
                        timeline.write(json.dumps(row) + "\n")
                        timeline.flush()
                        time.sleep(.25)
                        continue
                    candidate = PineClient(port=args.pine_port)
                    try:
                        candidate.connect(timeout=.4, retries=1)
                        identity = dict(version=candidate.version(), title=candidate.title(), game_id=candidate.game_id())
                        if not identity["game_id"]:
                            raise RuntimeError("original game identity is not available during boot yet")
                        if re.sub(r"[^A-Z0-9]", "", identity["game_id"].upper()) != re.sub(r"[^A-Z0-9]", "", args.game_id.upper()):
                            raise ValueError(f"wrong original game: {identity}")
                        manifest["pine_identity"] = identity
                        manifest["pine_listener"] = next(item for item in listeners if item["port"] == args.pine_port)
                        client = candidate
                    except ValueError:
                        candidate.close()
                        raise
                    except Exception as error:
                        candidate.close()
                        row["pine_error"] = str(error)
                if client:
                    try:
                        state = room_state(client)
                        row.update(state)
                        if state["room"] and handle:
                            if stable is None:
                                stable = (time.monotonic(), state)
                            if time.monotonic() - stable[0] >= 2:
                                manifest["room_proof"] = dict(first=stable[1], last=state, elapsed=elapsed,
                                                              stable_seconds=time.monotonic() - stable[0],
                                                              method="read_only_phase2_valid_player_manager_root")
                                timeline.write(json.dumps(row) + "\n")
                                timeline.flush()
                                break
                        else:
                            stable = None
                    except Exception as error:
                        row["pine_error"] = str(error)
                        last_error = str(error)
                        stable = None
                if not args.state_file and not stable and handle and event < len(ROUTE) and elapsed >= ROUTE[event][0]:
                    when, key = ROUTE[event]
                    owner.pulse(handle, key)
                    row["ordinary_pad"] = dict(scheduled=when, key=key)
                    event += 1
                timeline.write(json.dumps(row) + "\n")
                timeline.flush()
                time.sleep(.25)
            if not manifest["room_proof"]:
                raise TimeoutError(f"ordinary reference route did not establish first room: {last_error}")
            manifest["trigger"] = dict(elapsed=time.monotonic() - start, hwnd=handle,
                                       action="GSDumpSingleFrame", local_key="F10", stock_default="Shift+F8")
            owner.pulse(handle, 0x79)  # F10; stock GS dump queues on key release.
            seen = None
            stable_file_since = None
            deadline = min(start + args.timeout, time.monotonic() + 22)
            while time.monotonic() < deadline:
                files = list(out.glob("*.gs"))
                if len(files) > 1:
                    raise RuntimeError("single trigger produced multiple unexpected dump files")
                if files:
                    dump = files[0]
                    current = (dump.stat().st_size, dump.stat().st_mtime_ns)
                    if current[0] > MAX_DUMP:
                        raise RuntimeError("dump exceeds 512MiB bounded capture budget")
                    if current != seen:
                        seen, stable_file_since = current, time.monotonic()
                    elif time.monotonic() - stable_file_since >= 2:
                        try:
                            validate_dump(dump, args.expected_state_version)
                        except (ValueError, OSError):
                            pass
                        else:
                            manifest["dump_path"] = str(dump)
                            manifest["post_trigger_room"] = room_state(client)
                            break
                time.sleep(.5)
            if "dump_path" not in manifest:
                raise TimeoutError("stock hotkey did not finish a valid .gs before capture deadline")
    except BaseException as error:
        manifest["error"] = f"{type(error).__name__}: {error}"
    finally:
        if client:
            client.close()
        try:
            if proc:
                manifest["graceful_close"] = owner.close(proc)
                manifest["exit_code"] = proc.returncode
        finally:
            # Never restore while our process could subsequently overwrite it.
            if proc is None or proc.poll() is not None:
                args.ini.write_bytes(original)
                manifest["ini_restored"] = args.ini.read_bytes() == original
            else:
                manifest["restore_error"] = "owned process still alive; original INI backup retained"
        try:
            if "dump_path" in manifest and manifest["graceful_close"]:
                manifest["dump"] = validate_dump(Path(manifest["dump_path"]), args.expected_state_version)
                manifest["associated_png"] = [str(p) for p in out.glob("*.png")]
                manifest["success"] = bool(manifest["ini_restored"] and not manifest.get("error"))
        except Exception as error:
            manifest["validation_error"] = str(error)
        (out / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    return manifest


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--run", action="store_true", help="explicitly launch and capture; otherwise plan only")
    parser.add_argument("--validate-only", type=Path, metavar="FILE.gs")
    parser.add_argument("--pcsx2", type=Path, default=Path.home() / "ps2/pcsx2-qt.exe")
    parser.add_argument("--ini", type=Path, default=Path.home() / "Documents/PCSX2/inis/PCSX2.ini")
    parser.add_argument("--iso", type=Path)
    parser.add_argument("--state-file", type=Path, help="optional existing original PCSX2 savestate; never manufactured")
    parser.add_argument("--output", type=Path, default=ROOT / "build-ninja/m2-gs-dump-capture-plan" / time.strftime("capture-%Y%m%d-%H%M%S"))
    # Stock v2.2.0 ReloadPINE accidentally calls Initialize() without PINESlot;
    # its default argument forces28011 even when the INI/UI asks for another.
    parser.add_argument("--pine-port", type=int, choices=(28011,), default=28011)
    parser.add_argument("--game-id", default="SLUS-20765")
    parser.add_argument("--timeout", type=float, default=200)
    parser.add_argument("--expected-state-version", type=int, choices=(8, 9), default=8)
    args = parser.parse_args()
    if not 150 <= args.timeout <= 300 or not 1024 <= args.pine_port <= 65535:
        parser.error("timeout must be 150..300 seconds and PINE port 1024..65535")
    if args.validate_only:
        print(json.dumps(validate_dump(args.validate_only, args.expected_state_version), indent=2))
        return 0
    if args.run:
        report = run_capture(args)
        print(json.dumps(report, indent=2), flush=True)
        return 0 if report["success"] else 1
    print(json.dumps(dict(mode="PLAN_ONLY_NO_PROCESS_OR_CONFIG_MUTATION", binary=str(args.pcsx2),
                          ini=str(args.ini), iso=str(args.iso) if args.iso else None,
                          output=str(args.output), port=args.pine_port, route=ROUTE,
                          room_predicate="phase2 + valid player0 manager/root stable 2s",
                          capture="official GSDumpSingleFrame action remapped F10; compression0",
                          expected_state_version=args.expected_state_version,
                          sources=SOURCES), indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
