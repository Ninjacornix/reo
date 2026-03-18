"""
Dump game task table and state from running PCSX2 via Pine IPC.

This script connects to a running PCSX2 instance playing RE Outbreak
and dumps the task table at 0x341640 (256 entries, 16 bytes each)
plus key game state variables.

Usage:
    py dump_task_table.py              # dump once
    py dump_task_table.py --watch      # dump every 2 seconds
    py dump_task_table.py --full       # dump wider memory range

Requires PCSX2 with Pine IPC enabled (port 28011).
"""

import sys
import time
import struct

# Add parent dir for pine_client import
sys.path.insert(0, '.')
from pine_client import PineClient

TASK_TABLE_BASE = 0x341640
TASK_TABLE_ENTRIES = 256
TASK_ENTRY_SIZE = 16

# Key game state addresses
STATE_ADDRS = {
    'game_state':       0x2B0EC0,
    'game_state2':      0x2B0EC8,
    'game_counter':     0x2B0ED0,
    'pad_state':        0x29FA10,
    'db_index':         0x29FDB4,
    'vblank_counter':   0x3445E8,
    'task_head_ptr':    0x340A20,
    'task_head_data':   0x340A40,
}

def dump_task_table(client, verbose=False):
    """Read and display the task table."""
    print(f"\n{'='*60}")
    print(f"Task Table @ 0x{TASK_TABLE_BASE:08X} ({TASK_TABLE_ENTRIES} entries)")
    print(f"{'='*60}")

    active = 0
    for i in range(TASK_TABLE_ENTRIES):
        addr = TASK_TABLE_BASE + i * TASK_ENTRY_SIZE
        data = client.read_bytes(addr, TASK_ENTRY_SIZE)
        words = struct.unpack('<IIII', data)

        if any(w != 0 for w in words):
            active += 1
            print(f"  [{i:3d}] @ 0x{addr:08X}: "
                  f"flag=0x{words[0]:08X} cb=0x{words[1]:08X} "
                  f"p1=0x{words[2]:08X} p2=0x{words[3]:08X}")
        elif verbose and i < 8:
            print(f"  [{i:3d}] @ 0x{addr:08X}: (empty)")

    print(f"\n  Active entries: {active} / {TASK_TABLE_ENTRIES}")
    return active


def dump_state(client):
    """Read and display key game state variables."""
    print(f"\n{'='*60}")
    print("Game State Variables")
    print(f"{'='*60}")

    for name, addr in STATE_ADDRS.items():
        val = client.read32(addr)
        print(f"  {name:20s} @ 0x{addr:08X} = 0x{val:08X} ({val})")


def dump_wider_range(client, base, size, label):
    """Dump a memory range showing non-zero values."""
    print(f"\n{'='*60}")
    print(f"{label} (0x{base:08X} - 0x{base+size:08X})")
    print(f"{'='*60}")

    data = client.read_bytes(base, size)
    count = 0
    for off in range(0, size, 4):
        val = struct.unpack_from('<I', data, off)[0]
        if val != 0:
            print(f"  0x{base+off:08X} = 0x{val:08X}")
            count += 1
    print(f"  ({count} non-zero words)")


def main():
    watch = '--watch' in sys.argv
    full = '--full' in sys.argv

    client = PineClient()
    try:
        client.connect()
        print("[OK] Connected to PCSX2 Pine IPC")
    except Exception as e:
        print(f"[ERROR] Could not connect to PCSX2: {e}")
        print("Make sure PCSX2 is running with Pine IPC enabled (port 28011)")
        return 1

    try:
        while True:
            dump_state(client)
            dump_task_table(client, verbose=True)

            if full:
                dump_wider_range(client, 0x340000, 0x5000,
                                "Task Manager Region")
                dump_wider_range(client, 0x2B0E00, 0x200,
                                "Game State Region")
                dump_wider_range(client, 0x29F600, 0x800,
                                "Display/Render State")

            if not watch:
                break

            print("\n--- Waiting 2 seconds (Ctrl+C to stop) ---")
            time.sleep(2)

    except KeyboardInterrupt:
        print("\n[Stopped]")
    finally:
        client.close()

    return 0


if __name__ == '__main__':
    sys.exit(main())
