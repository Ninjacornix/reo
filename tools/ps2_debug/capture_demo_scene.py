#!/usr/bin/env python3
"""
Capture demo scene state from PCSX2 during active demo playback.

Usage:
  1. Launch RE Outbreak in PCSX2 with Pine IPC enabled
  2. Wait for the demo scene to start playing (don't press START on title)
  3. Run: py capture_demo_scene.py

This captures:
  - Scene struct at 0x236A08 (especially +0x520 file handle)
  - Scene lookup table at 0x259D08
  - Scene state variables at 0x34C7F0, 0x34D9F8, 0x34DA00
  - Full scene struct dump (0x600 bytes) for analysis
  - Surrounding memory regions for context
"""
import struct, sys, os, time

sys.path.insert(0, os.path.dirname(__file__))
from pine_client import PineClient

def dump_mem(client, addr, size):
    """Read a block of memory from PCSX2"""
    data = bytearray()
    chunk = 1024
    for off in range(0, size, chunk):
        n = min(chunk, size - off)
        data.extend(client.read_bytes(addr + off, n))
    return bytes(data)

def hex_dump(data, base=0, limit=256):
    for row in range(0, min(len(data), limit), 16):
        hex_part = ' '.join(f'{data[row+i]:02X}' if row+i < len(data) else '  ' for i in range(16))
        asc_part = ''.join(chr(data[row+i]) if 32 <= data[row+i] < 127 else '.' for i in range(16) if row+i < len(data))
        print(f'  {base+row:08X}: {hex_part}  {asc_part}')

def main():
    print("Connecting to PCSX2 Pine IPC (port 28011)...")
    client = PineClient()
    try:
        client.connect()
    except Exception as e:
        print(f"Failed to connect: {e}")
        print("Make sure PCSX2 is running with Pine IPC enabled")
        return

    print(f"Connected! Game: {client.title()}")
    print()

    # Key addresses
    SCENE_STRUCT_BASE = 0x236A08
    SCENE_STRUCT_SIZE = 0x600  # Capture full struct
    LOOKUP_TABLE = 0x259D08
    LOOKUP_COUNT = 32
    STATE_ADDRS = {
        0x34C7F0: "scene_cmd",
        0x34D9F8: "loading_flag",
        0x34DA00: "loaded_result",
        0x235FF8: "thread_id",
        0x3445E8: "vblank_counter",
    }

    # 1. Dump state variables
    print("=== State Variables ===")
    for addr, name in STATE_ADDRS.items():
        val = client.read32(addr)
        print(f"  {name} @ 0x{addr:08X} = 0x{val:08X} ({val})")

    # 2. Dump lookup table
    print(f"\n=== Scene Lookup Table @ 0x{LOOKUP_TABLE:08X} ===")
    for i in range(LOOKUP_COUNT):
        val = client.read32(LOOKUP_TABLE + i * 4)
        if val != 0:
            print(f"  [{i:2d}] = 0x{val:08X}")

    # 3. Dump scene struct
    print(f"\n=== Scene Struct @ 0x{SCENE_STRUCT_BASE:08X} ===")
    scene_data = dump_mem(client, SCENE_STRUCT_BASE, SCENE_STRUCT_SIZE)

    # Key fields
    fields = {
        0x000: "base",
        0x004: "field_04",
        0x008: "field_08",
        0x00C: "field_0C",
        0x010: "field_10",
        0x050: "field_50",
        0x100: "field_100",
        0x200: "field_200",
        0x500: "field_500",
        0x504: "field_504",
        0x508: "field_508",
        0x50C: "loaded_flag",
        0x510: "field_510",
        0x514: "field_514",
        0x518: "field_518",
        0x51C: "field_51C",
        0x520: "file_handle",  # <-- THE KEY FIELD
        0x524: "field_524",
        0x528: "field_528",
        0x52C: "field_52C",
        0x530: "field_530",
    }

    print("  Key fields:")
    for off, name in sorted(fields.items()):
        if off + 4 <= len(scene_data):
            val = struct.unpack_from('<I', scene_data, off)[0]
            marker = " <<<" if name == "file_handle" else ""
            print(f"    +0x{off:03X} ({name:15s}) = 0x{val:08X}{marker}")

    # Hex dump around +0x520
    print(f"\n  Hex dump +0x500..+0x540:")
    hex_dump(scene_data[0x500:0x540], SCENE_STRUCT_BASE + 0x500)

    # Full hex dump of first 0x40 bytes
    print(f"\n  Hex dump +0x000..+0x040:")
    hex_dump(scene_data[0x000:0x040], SCENE_STRUCT_BASE)

    # 4. Save full struct to file
    out_dir = "tools/ps2_debug"
    struct_file = os.path.join(out_dir, "pcsx2_scene_struct.bin")
    with open(struct_file, 'wb') as f:
        f.write(scene_data)
    print(f"\n  Saved full struct ({len(scene_data)} bytes) to {struct_file}")

    # 5. If file_handle is non-null, dump what it points to
    file_handle = struct.unpack_from('<I', scene_data, 0x520)[0]
    if file_handle != 0 and file_handle < 0x02000000:
        print(f"\n=== File Handle @ 0x{file_handle:08X} ===")
        fh_data = dump_mem(client, file_handle, 256)
        hex_dump(fh_data, file_handle)

        fh_file = os.path.join(out_dir, "pcsx2_file_handle.bin")
        with open(fh_file, 'wb') as f:
            f.write(fh_data)
        print(f"  Saved to {fh_file}")

    # 6. Dump broader region for context
    print(f"\n=== Broader Memory Regions ===")
    regions = [
        ("scene_struct_full", SCENE_STRUCT_BASE, SCENE_STRUCT_SIZE),
        ("lookup_table", LOOKUP_TABLE, LOOKUP_COUNT * 4),
        ("state_34C7F0", 0x34C7F0, 0x100),
        ("state_34D9F0", 0x34D9F0, 0x20),
    ]
    for name, addr, size in regions:
        data = dump_mem(client, addr, size)
        fname = os.path.join(out_dir, f"pcsx2_demo_{name}.bin")
        with open(fname, 'wb') as f:
            f.write(data)
        print(f"  {name}: 0x{addr:08X} ({size} bytes) -> {fname}")

    client.close()
    print("\nDone! Now analyze pcsx2_scene_struct.bin to find the file_handle field.")

if __name__ == '__main__':
    main()
