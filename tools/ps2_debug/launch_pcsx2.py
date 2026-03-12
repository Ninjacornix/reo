#!/usr/bin/env python3
"""
PCSX2 Launcher + Debug Session

Launches PCSX2 with a game ISO/ELF and automatically connects via Pine IPC
for debug tracing. Designed to be fully automated for CI or batch analysis.

Usage:
  python launch_pcsx2.py <game.iso> [options]
  python launch_pcsx2.py --find-pcsx2                    # Just locate PCSX2
  python launch_pcsx2.py game.iso --trace-config reo.json # Full trace session
  python launch_pcsx2.py game.iso --gs-dump --frames 5    # Capture 5 frames then exit
  python launch_pcsx2.py game.iso --ram-dump 0x100000:0x260000:code.bin
"""

import argparse
import os
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pine_client import PineClient, PineError, wait_for_pcsx2


# Common PCSX2 install locations on Windows
PCSX2_SEARCH_PATHS = [
    r"C:\Program Files\PCSX2",
    r"C:\Program Files (x86)\PCSX2",
    r"C:\PCSX2",
    r"D:\PCSX2",
    os.path.expanduser(r"~\AppData\Local\PCSX2"),
    os.path.expanduser(r"~\Desktop\PCSX2"),
    os.path.expanduser(r"~\Downloads\PCSX2"),
]

PCSX2_EXE_NAMES = ["pcsx2-qt.exe", "pcsx2-qtx64-avx2.exe", "pcsx2-qtx64.exe", "pcsx2.exe"]


def find_pcsx2() -> str:
    """Search for PCSX2 executable."""
    # Check PATH first
    for name in PCSX2_EXE_NAMES:
        for path_dir in os.environ.get("PATH", "").split(os.pathsep):
            candidate = os.path.join(path_dir, name)
            if os.path.isfile(candidate):
                return candidate

    # Check common install locations
    for search_dir in PCSX2_SEARCH_PATHS:
        if not os.path.isdir(search_dir):
            continue
        for name in PCSX2_EXE_NAMES:
            candidate = os.path.join(search_dir, name)
            if os.path.isfile(candidate):
                return candidate
            # Check subdirectories
            for sub in os.listdir(search_dir):
                candidate = os.path.join(search_dir, sub, name)
                if os.path.isfile(candidate):
                    return candidate

    return None


def launch_pcsx2(pcsx2_path: str, game_path: str, extra_args: list = None,
                 nogui: bool = False, fullscreen: bool = False,
                 logfile: str = None) -> subprocess.Popen:
    """Launch PCSX2 with a game."""
    cmd = [pcsx2_path]

    if nogui:
        cmd.append("-nogui")
    if fullscreen:
        cmd.append("-fullscreen")
    if logfile:
        cmd.extend(["-logfile", logfile])

    # Fast boot (skip BIOS)
    cmd.append("-fastboot")

    if extra_args:
        cmd.extend(extra_args)

    # Game path goes last
    cmd.append("--")
    cmd.append(game_path)

    print(f"Launching: {' '.join(cmd)}")
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return proc


def main():
    parser = argparse.ArgumentParser(description="PCSX2 Launcher + Debug Session")
    parser.add_argument("game", nargs="?", help="Path to game ISO/ELF")
    parser.add_argument("--pcsx2", help="Path to PCSX2 executable")
    parser.add_argument("--find-pcsx2", action="store_true",
                        help="Just locate PCSX2 and print path")
    parser.add_argument("--nogui", action="store_true",
                        help="Run PCSX2 without GUI (headless)")
    parser.add_argument("--logfile", help="PCSX2 log output file")
    parser.add_argument("--pine-port", type=int, default=28011,
                        help="Pine IPC port")
    parser.add_argument("--wait-time", type=int, default=30,
                        help="Seconds to wait for game to boot")
    parser.add_argument("--trace-config", help="Run full trace with config file")
    parser.add_argument("--ram-dump", action="append",
                        help="Dump RAM region: start:end:filename (hex addrs)")
    parser.add_argument("--watch", action="append",
                        help="Watch address: 0xADDR:name")
    parser.add_argument("--watch-duration", type=int, default=30,
                        help="Watch duration in seconds")
    args = parser.parse_args()

    # Find PCSX2
    pcsx2_path = args.pcsx2 or find_pcsx2()
    if args.find_pcsx2:
        if pcsx2_path:
            print(f"PCSX2 found: {pcsx2_path}")
        else:
            print("PCSX2 not found!")
            print("Searched:")
            for p in PCSX2_SEARCH_PATHS:
                print(f"  {p}")
        return

    if not pcsx2_path:
        print("ERROR: PCSX2 not found. Specify with --pcsx2 <path>")
        sys.exit(1)

    if not args.game:
        print("ERROR: No game path specified")
        sys.exit(1)

    print(f"PCSX2: {pcsx2_path}")
    print(f"Game:  {args.game}")
    print()

    # Launch PCSX2
    proc = launch_pcsx2(
        pcsx2_path, args.game,
        nogui=args.nogui,
        logfile=args.logfile
    )

    print(f"PCSX2 started (PID={proc.pid})")
    print(f"Waiting for Pine IPC on port {args.pine_port}...")
    print("(Make sure Pine IPC is enabled in PCSX2: Settings → Advanced)")
    print()

    # Wait for Pine IPC connection
    time.sleep(3)  # Give PCSX2 time to start
    try:
        client = wait_for_pcsx2(port=args.pine_port, timeout=args.wait_time)
    except PineError as e:
        print(f"\nFailed to connect: {e}")
        print("Make sure Pine IPC is enabled in PCSX2 settings.")
        proc.terminate()
        sys.exit(1)

    print()

    try:
        # Show game info
        try:
            print(f"PCSX2 Version: {client.version()}")
            print(f"Game Title:    {client.title()}")
            print(f"Game ID:       {client.game_id()}")
        except PineError:
            pass

        # RAM dumps
        if args.ram_dump:
            for spec in args.ram_dump:
                parts = spec.split(":")
                if len(parts) < 2:
                    print(f"Invalid RAM dump spec: {spec} (need start:end[:file])")
                    continue
                start = int(parts[0], 16)
                end = int(parts[1], 16)
                fname = parts[2] if len(parts) > 2 else f"ram_{start:08X}_{end:08X}.bin"
                size = end - start

                print(f"\nDumping {fname}: 0x{start:08X}-0x{end:08X} ({size} bytes)...")
                data = bytearray()
                for offset in range(0, size, 4):
                    try:
                        val = client.read32(start + offset)
                        import struct
                        data.extend(struct.pack("<I", val)[:min(4, size - offset)])
                    except PineError:
                        data.extend(b"\x00" * min(4, size - offset))
                with open(fname, "wb") as f:
                    f.write(data)
                print(f"Saved: {fname} ({len(data)} bytes)")

        # Watch mode
        if args.watch:
            print(f"\nWatching addresses for {args.watch_duration}s...")
            import struct
            watches = []
            for spec in args.watch:
                parts = spec.split(":")
                addr = int(parts[0], 16)
                name = parts[1] if len(parts) > 1 else f"0x{addr:08X}"
                watches.append({"addr": addr, "name": name, "prev": None})

            t0 = time.time()
            while time.time() - t0 < args.watch_duration:
                elapsed = time.time() - t0
                line = f"{elapsed:8.1f}"
                for w in watches:
                    try:
                        val = client.read32(w["addr"])
                        changed = w["prev"] is not None and val != w["prev"]
                        w["prev"] = val
                        marker = " *" if changed else "  "
                        line += f"  {w['name']}={val:#010x}{marker}"
                    except PineError:
                        line += f"  {w['name']}=ERROR"
                print(line)
                time.sleep(0.5)

        # Full trace
        if args.trace_config:
            from ps2_trace import cmd_full_trace
            class FakeArgs:
                config = args.trace_config
            cmd_full_trace(client, FakeArgs())

    except KeyboardInterrupt:
        print("\nInterrupted.")
    finally:
        client.close()
        print("\nPCSX2 is still running. Close it manually or press Ctrl+C again.")


if __name__ == "__main__":
    main()
