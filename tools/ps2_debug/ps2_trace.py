#!/usr/bin/env python3
"""
PS2 Debug Trace Tool

Automates PCSX2 to capture debug data for PS2 recompilation projects.
Connects to a running PCSX2 instance via Pine IPC and can:

  1. Dump RAM regions to files (for comparison with recompiled output)
  2. Monitor memory addresses over time (watch variables change)
  3. Capture function call traces by monitoring known call sites
  4. Take periodic RAM snapshots for diff analysis
  5. Record DMA register activity

Works with ANY PS2 game — not REO-specific. Provide your own address maps.

Prerequisites:
  - PCSX2 2.x with Pine IPC enabled (Settings → Advanced → Enable Pine IPC)
  - Python 3.8+
  - No external packages required

Usage:
  # Start PCSX2 with your game, enable Pine IPC, then:

  # Dump a RAM region
  python ps2_trace.py dump 0x100000 0x200000 -o ram_dump.bin

  # Watch memory addresses
  python ps2_trace.py watch 0x3445E8:vblank_counter 0x2B8DD0:dma_slot0

  # Periodic RAM snapshots (every 5 seconds for comparison)
  python ps2_trace.py snapshot 0x100000 0x260000 --interval 5 --count 10

  # Monitor DMA control registers
  python ps2_trace.py dma-watch

  # Full trace: RAM dump + DMA + key addresses
  python ps2_trace.py full-trace --config trace_config.json
"""

import argparse
import json
import os
import struct
import sys
import time
import hashlib
from pathlib import Path

# Add parent dir to path for pine_client import
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pine_client import PineClient, PineError, wait_for_pcsx2


# ── PS2 hardware constants ───────────────────────────────────────

PS2_RAM_SIZE     = 32 * 1024 * 1024  # 32 MB EE RAM
PS2_DMA_BASE     = 0x10008000
PS2_GIF_DMA      = 0x1000A000
PS2_VIF1_DMA     = 0x10009000
PS2_GS_PRIV_BASE = 0x12000000

# DMA channel register offsets
DMA_CHCR = 0x00   # Channel control
DMA_MADR = 0x10   # Memory address
DMA_QWC  = 0x20   # Quadword count
DMA_TADR = 0x30   # Tag address


def format_hex(value: int, width: int = 8) -> str:
    return f"0x{value:0{width}X}"


def format_size(size: int) -> str:
    if size >= 1024 * 1024:
        return f"{size / (1024 * 1024):.1f} MB"
    elif size >= 1024:
        return f"{size / 1024:.1f} KB"
    return f"{size} bytes"


# ── RAM Dump ─────────────────────────────────────────────────────

def cmd_dump(client: PineClient, args):
    """Dump a region of PS2 RAM to a file."""
    start = int(args.start, 16) if isinstance(args.start, str) else args.start
    end = int(args.end, 16) if isinstance(args.end, str) else args.end
    size = end - start
    output = args.output or f"ram_{start:08X}_{end:08X}.bin"

    print(f"Dumping RAM: {format_hex(start)} - {format_hex(end)} ({format_size(size)})")

    data = bytearray()
    chunk_size = 4  # Read 4 bytes at a time via read32
    t0 = time.time()

    for offset in range(0, size, chunk_size):
        addr = start + offset
        remaining = min(chunk_size, size - offset)
        try:
            val = client.read32(addr)
            data.extend(struct.pack("<I", val)[:remaining])
        except PineError:
            # Fill with zeros on read failure
            data.extend(b"\x00" * remaining)

        # Progress
        if offset > 0 and offset % (64 * 1024) == 0:
            pct = 100 * offset / size
            elapsed = time.time() - t0
            rate = offset / elapsed if elapsed > 0 else 0
            eta = (size - offset) / rate if rate > 0 else 0
            print(f"  {pct:.0f}% ({format_size(offset)}) "
                  f"rate={format_size(int(rate))}/s ETA={eta:.0f}s")

    with open(output, "wb") as f:
        f.write(data)

    elapsed = time.time() - t0
    md5 = hashlib.md5(data).hexdigest()
    print(f"Saved: {output} ({format_size(len(data))}, {elapsed:.1f}s, md5={md5})")


# ── Memory Watch ─────────────────────────────────────────────────

def cmd_watch(client: PineClient, args):
    """Watch memory addresses and print changes."""
    # Parse address specs: "0xADDR:name" or just "0xADDR"
    watches = []
    for spec in args.addresses:
        parts = spec.split(":")
        addr = int(parts[0], 16)
        name = parts[1] if len(parts) > 1 else f"addr_{addr:08X}"
        watches.append({"addr": addr, "name": name, "prev": None})

    interval = args.interval
    print(f"Watching {len(watches)} addresses (interval={interval}s, Ctrl+C to stop)")
    print()

    # Header
    header = f"{'Time':>8s}"
    for w in watches:
        header += f"  {w['name']:>16s}"
    print(header)
    print("-" * len(header))

    t0 = time.time()
    try:
        while True:
            elapsed = time.time() - t0
            line = f"{elapsed:8.1f}"

            for w in watches:
                try:
                    val = client.read32(w["addr"])
                    changed = w["prev"] is not None and val != w["prev"]
                    w["prev"] = val
                    marker = " *" if changed else "  "
                    line += f"  {val:>#14X}{marker}"
                except PineError:
                    line += f"  {'ERROR':>16s}"

            print(line)
            time.sleep(interval)
    except KeyboardInterrupt:
        print("\nWatch stopped.")


# ── RAM Snapshots ────────────────────────────────────────────────

def cmd_snapshot(client: PineClient, args):
    """Take periodic RAM snapshots for diff analysis."""
    start = int(args.start, 16)
    end = int(args.end, 16)
    size = end - start
    interval = args.interval
    count = args.count
    out_dir = args.out_dir or "snapshots"

    os.makedirs(out_dir, exist_ok=True)

    print(f"Snapshotting {format_hex(start)}-{format_hex(end)} ({format_size(size)})")
    print(f"Interval: {interval}s, Count: {count}, Output: {out_dir}/")
    print()

    snapshots = []
    for i in range(count):
        print(f"Snapshot {i + 1}/{count}...", end=" ", flush=True)
        t0 = time.time()

        data = bytearray()
        for offset in range(0, size, 4):
            try:
                val = client.read32(start + offset)
                data.extend(struct.pack("<I", val)[:min(4, size - offset)])
            except PineError:
                data.extend(b"\x00" * min(4, size - offset))

        elapsed = time.time() - t0
        md5 = hashlib.md5(data).hexdigest()
        fname = f"{out_dir}/snap_{i:04d}_{start:08X}.bin"
        with open(fname, "wb") as f:
            f.write(data)

        snapshots.append({"file": fname, "md5": md5, "time": elapsed})
        print(f"saved ({elapsed:.1f}s, md5={md5[:12]}...)")

        if i < count - 1:
            time.sleep(interval)

    # Diff summary
    print("\n=== Snapshot Diff Summary ===")
    for i in range(1, len(snapshots)):
        if snapshots[i]["md5"] == snapshots[i - 1]["md5"]:
            print(f"  Snap {i-1} → {i}: identical")
        else:
            # Load both and count differences
            with open(snapshots[i - 1]["file"], "rb") as f:
                prev = f.read()
            with open(snapshots[i]["file"], "rb") as f:
                curr = f.read()
            diff_count = sum(1 for a, b in zip(prev, curr) if a != b)
            print(f"  Snap {i-1} → {i}: {diff_count} bytes differ "
                  f"({100 * diff_count / len(prev):.2f}%)")


# ── DMA Watch ────────────────────────────────────────────────────

def cmd_dma_watch(client: PineClient, args):
    """Monitor PS2 DMA control registers."""
    channels = {
        "VIF0":  0x10008000,
        "VIF1":  0x10009000,
        "GIF":   0x1000A000,
        "IPU_F": 0x1000B000,
        "IPU_T": 0x1000B400,
        "SIF0":  0x1000C000,
        "SIF1":  0x1000C400,
        "SPR_F": 0x1000D000,
        "SPR_T": 0x1000D400,
    }

    # Only watch the channels the user cares about
    if args.channels:
        channels = {k: v for k, v in channels.items()
                    if k.lower() in [c.lower() for c in args.channels]}

    interval = args.interval
    print(f"Watching DMA channels: {', '.join(channels.keys())}")
    print(f"Interval: {interval}s (Ctrl+C to stop)")
    print()

    # Header
    header = f"{'Time':>8s}"
    for name in channels:
        header += f"  {name + '_CHCR':>12s}  {name + '_MADR':>12s}  {name + '_QWC':>10s}"
    print(header)
    print("-" * len(header))

    t0 = time.time()
    prev_vals = {}

    try:
        while True:
            elapsed = time.time() - t0
            line = f"{elapsed:8.1f}"

            for name, base in channels.items():
                try:
                    chcr = client.read32(base + DMA_CHCR)
                    madr = client.read32(base + DMA_MADR)
                    qwc = client.read32(base + DMA_QWC)

                    key = f"{name}_chcr"
                    changed = key in prev_vals and prev_vals[key] != chcr
                    prev_vals[key] = chcr

                    marker = "*" if changed else " "
                    line += f"  {chcr:>#12X}{marker} {madr:>#12X}  {qwc:>10d}"
                except PineError:
                    line += f"  {'ERR':>12s}  {'ERR':>12s}  {'ERR':>10s}"

            print(line)
            time.sleep(interval)
    except KeyboardInterrupt:
        print("\nDMA watch stopped.")


# ── Full Trace ───────────────────────────────────────────────────

def cmd_full_trace(client: PineClient, args):
    """Run a full debug trace session with config file."""
    config_path = args.config
    if config_path and os.path.exists(config_path):
        with open(config_path) as f:
            config = json.load(f)
    else:
        # Default config for RE Outbreak
        config = {
            "game": "RE Outbreak File #1",
            "game_id": "SLUS-20765",
            "duration": 30,
            "output_dir": "trace_output",
            "ram_dump": {
                "regions": [
                    {"name": "code", "start": "0x100000", "end": "0x260000"},
                    {"name": "heap", "start": "0x260000", "end": "0x370000"},
                    {"name": "bss",  "start": "0x370000", "end": "0x570000"},
                ]
            },
            "watches": [
                {"addr": "0x3445E8", "name": "vblank_counter"},
                {"addr": "0x2B8DD0", "name": "dma_slot_0"},
                {"addr": "0x2B8DD8", "name": "dma_slot_1"},
                {"addr": "0x2B8E08", "name": "gs_buf_slot"},
                {"addr": "0x2999D0", "name": "heap_struct"},
            ],
            "dma_channels": ["GIF", "VIF1"],
            "snapshots": {
                "region_start": "0x100000",
                "region_end": "0x370000",
                "interval": 5,
                "count": 6
            }
        }

    out_dir = config.get("output_dir", "trace_output")
    os.makedirs(out_dir, exist_ok=True)

    print(f"=== PS2 Full Debug Trace ===")
    print(f"Game: {config.get('game', 'Unknown')}")
    print(f"Output: {out_dir}/")
    print()

    # Get game info from PCSX2
    try:
        title = client.title()
        game_id = client.game_id()
        version = client.version()
        print(f"PCSX2: {version}")
        print(f"Running: {title} [{game_id}]")
    except PineError as e:
        print(f"Warning: Could not query game info: {e}")

    # Phase 1: Initial RAM dump
    print(f"\n--- Phase 1: Initial RAM Dump ---")
    for region in config.get("ram_dump", {}).get("regions", []):
        start = int(region["start"], 16)
        end = int(region["end"], 16)
        name = region.get("name", f"{start:08X}")
        fname = f"{out_dir}/ram_{name}_{start:08X}.bin"
        print(f"  Dumping {name}: {format_hex(start)}-{format_hex(end)} "
              f"({format_size(end - start)})...", end=" ", flush=True)

        data = bytearray()
        for offset in range(0, end - start, 4):
            try:
                val = client.read32(start + offset)
                data.extend(struct.pack("<I", val)[:min(4, end - start - offset)])
            except PineError:
                data.extend(b"\x00" * min(4, end - start - offset))

        with open(fname, "wb") as f:
            f.write(data)
        md5 = hashlib.md5(data).hexdigest()
        print(f"done ({format_size(len(data))}, md5={md5[:12]})")

    # Phase 2: Watch key addresses for a duration
    duration = config.get("duration", 30)
    watches = config.get("watches", [])
    if watches:
        print(f"\n--- Phase 2: Memory Watch ({duration}s) ---")
        watch_log = []
        t0 = time.time()

        # Header
        header = f"{'Time':>8s}"
        for w in watches:
            header += f"  {w['name']:>16s}"
        print(header)

        while time.time() - t0 < duration:
            elapsed = time.time() - t0
            entry = {"time": round(elapsed, 2)}
            line = f"{elapsed:8.1f}"

            for w in watches:
                addr = int(w["addr"], 16)
                try:
                    val = client.read32(addr)
                    entry[w["name"]] = val
                    line += f"  {val:>#16X}"
                except PineError:
                    entry[w["name"]] = None
                    line += f"  {'ERR':>16s}"

            watch_log.append(entry)
            print(line)
            time.sleep(0.5)

        # Save watch log
        watch_file = f"{out_dir}/watch_log.json"
        with open(watch_file, "w") as f:
            json.dump(watch_log, f, indent=2)
        print(f"  Watch log saved: {watch_file} ({len(watch_log)} samples)")

    # Phase 3: Final RAM dump (for diff)
    print(f"\n--- Phase 3: Final RAM Dump ---")
    for region in config.get("ram_dump", {}).get("regions", []):
        start = int(region["start"], 16)
        end = int(region["end"], 16)
        name = region.get("name", f"{start:08X}")
        fname_initial = f"{out_dir}/ram_{name}_{start:08X}.bin"
        fname_final = f"{out_dir}/ram_{name}_{start:08X}_final.bin"
        print(f"  Dumping {name} (final)...", end=" ", flush=True)

        data = bytearray()
        for offset in range(0, end - start, 4):
            try:
                val = client.read32(start + offset)
                data.extend(struct.pack("<I", val)[:min(4, end - start - offset)])
            except PineError:
                data.extend(b"\x00" * min(4, end - start - offset))

        with open(fname_final, "wb") as f:
            f.write(data)

        # Diff against initial
        with open(fname_initial, "rb") as f:
            initial = f.read()
        diff_count = sum(1 for a, b in zip(initial, data) if a != b)
        print(f"done ({diff_count} bytes changed, "
              f"{100 * diff_count / len(initial):.2f}%)")

    # Save config used
    config_out = f"{out_dir}/trace_config.json"
    with open(config_out, "w") as f:
        json.dump(config, f, indent=2)
    print(f"\nTrace complete! Output in {out_dir}/")


# ── GS Dump Trigger ──────────────────────────────────────────────

def cmd_gs_dump(client: PineClient, args):
    """Trigger a GS dump capture in PCSX2.

    PCSX2 captures GS dumps via Shift+F8 or the Tools menu.
    This command can trigger it by writing to a specific memory
    address that PCSX2 watches, or by using save states as a
    workaround to capture at specific moments.
    """
    print("=== GS Dump Capture ===")
    print()
    print("To capture a GS dump from PCSX2:")
    print("  1. Run your game in PCSX2 to the desired frame")
    print("  2. Press Shift+F8 to start/stop capture")
    print("  3. Or use: Tools → Save Single Frame GS Dump")
    print("  4. Dumps are saved to PCSX2's snaps/ directory")
    print()
    print("Automated capture via Pine IPC is not directly supported.")
    print("As a workaround, this tool can:")
    print("  - Save a state at a specific moment (for reproducible capture)")
    print("  - Wait for a specific game state before prompting you to capture")
    print()

    if args.wait_addr:
        addr = int(args.wait_addr, 16)
        target = int(args.wait_value, 16) if args.wait_value else None
        print(f"Watching {format_hex(addr)} for value "
              f"{format_hex(target) if target else 'any change'}...")

        prev = client.read32(addr)
        while True:
            val = client.read32(addr)
            if target is not None and val == target:
                print(f"\n>>> Target value reached! Press Shift+F8 in PCSX2 NOW! <<<")
                break
            elif target is None and val != prev:
                print(f"\n>>> Value changed: {format_hex(prev)} → {format_hex(val)} "
                      f"Press Shift+F8 in PCSX2 NOW! <<<")
                break
            prev = val
            time.sleep(0.016)  # ~60fps polling

    if args.save_state is not None:
        slot = args.save_state
        print(f"Saving state to slot {slot}...")
        client.save_state(slot)
        print(f"State saved! You can load this state later for reproducible captures.")


# ── Compare tool ─────────────────────────────────────────────────

def cmd_compare(client: PineClient, args):
    """Compare a RAM dump file against live PCSX2 memory."""
    dump_path = args.dump_file
    base_addr = int(args.base_addr, 16)

    with open(dump_path, "rb") as f:
        reference = f.read()

    size = len(reference)
    print(f"Comparing {dump_path} ({format_size(size)}) against "
          f"live memory at {format_hex(base_addr)}")

    diff_regions = []
    current_diff_start = None
    diff_bytes = 0

    for offset in range(0, size, 4):
        remaining = min(4, size - offset)
        ref_val = struct.unpack("<I", reference[offset:offset + 4].ljust(4, b"\x00"))[0]
        try:
            live_val = client.read32(base_addr + offset)
        except PineError:
            live_val = 0xDEADDEAD

        if ref_val != live_val:
            diff_bytes += remaining
            if current_diff_start is None:
                current_diff_start = offset
        else:
            if current_diff_start is not None:
                diff_regions.append((current_diff_start, offset))
                current_diff_start = None

        if offset > 0 and offset % (64 * 1024) == 0:
            print(f"  {100 * offset / size:.0f}% checked, "
                  f"{diff_bytes} bytes differ so far")

    if current_diff_start is not None:
        diff_regions.append((current_diff_start, size))

    print(f"\n=== Comparison Results ===")
    print(f"Total bytes: {format_size(size)}")
    print(f"Bytes different: {diff_bytes} ({100 * diff_bytes / size:.2f}%)")
    print(f"Different regions: {len(diff_regions)}")

    # Show first N diff regions
    for i, (start, end) in enumerate(diff_regions[:20]):
        addr = base_addr + start
        print(f"  {format_hex(addr)}-{format_hex(base_addr + end)} "
              f"({format_size(end - start)})")

    if len(diff_regions) > 20:
        print(f"  ... and {len(diff_regions) - 20} more regions")


# ── Main ─────────────────────────────────────────────────────────

def parse_args():
    parser = argparse.ArgumentParser(
        description="PS2 Debug Trace Tool — PCSX2 Pine IPC automation",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s dump 0x100000 0x200000 -o code_region.bin
  %(prog)s watch 0x3445E8:vblank 0x2B8DD0:dma_slot0
  %(prog)s snapshot 0x100000 0x370000 --interval 5 --count 10
  %(prog)s dma-watch --channels GIF VIF1
  %(prog)s full-trace --config my_trace.json
  %(prog)s gs-dump --wait-addr 0x3445E8 --save-state 1
  %(prog)s compare ram_dump.bin 0x100000
        """
    )
    parser.add_argument("--host", default="127.0.0.1", help="PCSX2 host")
    parser.add_argument("--port", type=int, default=28011, help="Pine IPC port")
    parser.add_argument("--timeout", type=int, default=30, help="Connection timeout")

    sub = parser.add_subparsers(dest="command", required=True)

    # dump
    p = sub.add_parser("dump", help="Dump RAM region to file")
    p.add_argument("start", help="Start address (hex)")
    p.add_argument("end", help="End address (hex)")
    p.add_argument("-o", "--output", help="Output file")

    # watch
    p = sub.add_parser("watch", help="Watch memory addresses")
    p.add_argument("addresses", nargs="+", help="Addresses (0xADDR:name)")
    p.add_argument("--interval", type=float, default=0.5, help="Poll interval")

    # snapshot
    p = sub.add_parser("snapshot", help="Periodic RAM snapshots")
    p.add_argument("start", help="Start address (hex)")
    p.add_argument("end", help="End address (hex)")
    p.add_argument("--interval", type=float, default=5.0, help="Seconds between snaps")
    p.add_argument("--count", type=int, default=5, help="Number of snapshots")
    p.add_argument("--out-dir", help="Output directory")

    # dma-watch
    p = sub.add_parser("dma-watch", help="Monitor DMA registers")
    p.add_argument("--channels", nargs="*", help="Channels to watch (GIF, VIF1, etc.)")
    p.add_argument("--interval", type=float, default=0.1, help="Poll interval")

    # full-trace
    p = sub.add_parser("full-trace", help="Full debug trace session")
    p.add_argument("--config", help="JSON config file (or uses REO defaults)")

    # gs-dump
    p = sub.add_parser("gs-dump", help="Assist with GS dump capture")
    p.add_argument("--wait-addr", help="Address to watch for trigger")
    p.add_argument("--wait-value", help="Target value (hex)")
    p.add_argument("--save-state", type=int, help="Save state slot")

    # compare
    p = sub.add_parser("compare", help="Compare RAM dump against live memory")
    p.add_argument("dump_file", help="Path to reference RAM dump")
    p.add_argument("base_addr", help="Base address in PS2 memory (hex)")

    return parser.parse_args()


def main():
    args = parse_args()

    # Connect to PCSX2
    client = wait_for_pcsx2(args.host, args.port, args.timeout)

    try:
        commands = {
            "dump":       cmd_dump,
            "watch":      cmd_watch,
            "snapshot":   cmd_snapshot,
            "dma-watch":  cmd_dma_watch,
            "full-trace": cmd_full_trace,
            "gs-dump":    cmd_gs_dump,
            "compare":    cmd_compare,
        }
        commands[args.command](client, args)
    except KeyboardInterrupt:
        print("\nInterrupted.")
    except PineError as e:
        print(f"\nPine IPC error: {e}")
        sys.exit(1)
    finally:
        client.close()


if __name__ == "__main__":
    main()
