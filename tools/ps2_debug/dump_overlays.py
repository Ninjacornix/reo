#!/usr/bin/env python3
"""
Dump runtime overlay code from PS2 RAM via PCSX2 Pine IPC.

RE Outbreak loads executable MIPS code into BSS region (0x370000-0x400000)
at runtime. These are overlay functions not present in the static ELF.

This script:
1. Dumps the overlay region from live PCSX2
2. Scans for function prologues (addiu sp, sp, -N)
3. Creates a minimal ELF wrapper for PS2Recomp processing
4. Outputs a function map for registration

Usage:
    py dump_overlays.py [--state STATE_NAME] [--output DIR]
"""
import sys
import os
import struct
import argparse
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pine_client import PineClient, PineError

# Overlay region boundaries
OVERLAY_START = 0x370000
OVERLAY_END   = 0x400000
OVERLAY_SIZE  = OVERLAY_END - OVERLAY_START

# Extended scan for larger overlays
EXTENDED_END  = 0x500000

# MIPS instruction patterns
ADDIU_SP_SP_MASK = 0xFFFF0000
ADDIU_SP_SP_OP   = 0x27BD0000  # addiu sp, sp, -N (N > 0 means prologue when imm is negative)
JR_RA            = 0x03E00008
LUI_OP_MASK      = 0xFC1F0000
LUI_OP           = 0x3C000000


def dump_region(client, start, end):
    """Dump a memory region via Pine IPC read32 calls."""
    size = end - start
    data = bytearray(size)

    # Read in 4-byte chunks
    total = size // 4
    for i in range(total):
        addr = start + i * 4
        try:
            val = client.read32(addr)
            struct.pack_into("<I", data, i * 4, val)
        except PineError:
            pass  # Leave as zeros

        # Progress every 4KB
        if i % 1024 == 0 and i > 0:
            pct = (i * 100) // total
            print(f"  {pct}% ({i*4:#x} bytes)...", end="\r")

    print(f"  100% ({size:#x} bytes)       ")
    return bytes(data)


def find_functions(data, base_addr):
    """Scan for MIPS function prologues in the dump."""
    functions = []

    for offset in range(0, len(data) - 4, 4):
        word = struct.unpack_from("<I", data, offset)[0]

        if word == 0:
            continue

        # Check for addiu sp, sp, -N (function prologue)
        if (word & ADDIU_SP_SP_MASK) == ADDIU_SP_SP_OP:
            imm = word & 0xFFFF
            # Sign-extend 16-bit immediate
            if imm >= 0x8000:
                imm_signed = imm - 0x10000
            else:
                imm_signed = imm

            # Negative offset = stack frame allocation = function prologue
            if imm_signed < 0 and imm_signed >= -0x1000:
                addr = base_addr + offset
                frame_size = -imm_signed
                functions.append({
                    "addr": addr,
                    "offset": offset,
                    "frame_size": frame_size,
                })

    return functions


def find_code_bounds(data):
    """Find the actual extent of non-zero code in the dump."""
    first_nonzero = None
    last_nonzero = 0

    for i in range(0, len(data), 4):
        word = struct.unpack_from("<I", data, i)[0]
        if word != 0:
            if first_nonzero is None:
                first_nonzero = i
            last_nonzero = i + 4

    return first_nonzero, last_nonzero


def create_overlay_elf(data, base_addr, output_path):
    """
    Create a minimal ELF32 for MIPS that PS2Recomp can analyze.
    The overlay code is placed at its original virtual address.
    """
    # ELF32 header (52 bytes)
    # Program header (32 bytes)
    # Section headers later

    ELF_HEADER_SIZE = 52
    PHDR_SIZE = 32
    SHDR_SIZE = 40

    # We need: ELF header + 1 program header + code + section headers
    code_offset = ELF_HEADER_SIZE + PHDR_SIZE
    # Align to 16 bytes
    code_offset = (code_offset + 15) & ~15

    code_size = len(data)

    # Section header table after code
    shdr_offset = code_offset + code_size
    shdr_offset = (shdr_offset + 15) & ~15

    # String table
    shstrtab_offset = shdr_offset + SHDR_SIZE * 4  # null, .text, .shstrtab, .symtab
    shstrtab = b"\x00.text\x00.shstrtab\x00"

    total_size = shstrtab_offset + len(shstrtab)

    elf = bytearray(total_size)

    # ELF header
    struct.pack_into("<4sBBBBB7xHHIIIIIHHHHHH", elf, 0,
        b"\x7fELF",  # magic
        1,            # 32-bit
        1,            # little-endian
        1,            # ELF version
        0,            # OS/ABI (NONE)
        0,            # ABI version
        2,            # ET_EXEC
        8,            # EM_MIPS
        1,            # ELF version
        base_addr,    # entry point
        ELF_HEADER_SIZE,  # program header offset
        shdr_offset,      # section header offset
        0x20000001,       # flags (MIPS)
        ELF_HEADER_SIZE,  # ELF header size
        PHDR_SIZE,        # program header entry size
        1,                # number of program headers
        SHDR_SIZE,        # section header entry size
        3,                # number of section headers
        2,                # shstrtab index
    )

    # Program header (PT_LOAD)
    struct.pack_into("<IIIIIIII", elf, ELF_HEADER_SIZE,
        1,            # PT_LOAD
        code_offset,  # file offset
        base_addr,    # virtual address
        base_addr,    # physical address
        code_size,    # file size
        code_size,    # memory size
        5,            # flags (PF_R | PF_X)
        16,           # alignment
    )

    # Copy code data
    elf[code_offset:code_offset + code_size] = data

    # Section headers
    # [0] NULL
    # [1] .text
    struct.pack_into("<IIIIIIIIII", elf, shdr_offset + SHDR_SIZE,
        1,            # name offset in shstrtab
        1,            # SHT_PROGBITS
        6,            # SHF_ALLOC | SHF_EXECINSTR
        base_addr,    # virtual address
        code_offset,  # file offset
        code_size,    # size
        0, 0, 16, 0,  # link, info, align, entsize
    )
    # [2] .shstrtab
    struct.pack_into("<IIIIIIIIII", elf, shdr_offset + SHDR_SIZE * 2,
        7,                  # name offset
        3,                  # SHT_STRTAB
        0,                  # no flags
        0,                  # no vaddr
        shstrtab_offset,    # file offset
        len(shstrtab),      # size
        0, 0, 1, 0,
    )

    # String table
    elf[shstrtab_offset:shstrtab_offset + len(shstrtab)] = shstrtab

    with open(output_path, "wb") as f:
        f.write(elf)

    return total_size


def main():
    parser = argparse.ArgumentParser(description="Dump PS2 runtime overlays via PCSX2 Pine IPC")
    parser.add_argument("--state", default="title", help="Game state label (e.g. title, ingame, lobby)")
    parser.add_argument("--output", default="overlay_dumps", help="Output directory")
    parser.add_argument("--extended", action="store_true", help="Scan extended range up to 0x500000")
    args = parser.parse_args()

    os.makedirs(args.output, exist_ok=True)

    print("=== RE Outbreak Overlay Dumper ===")
    print(f"State: {args.state}")
    print(f"Output: {args.output}/")
    print()

    # Connect to PCSX2
    client = PineClient()
    try:
        client.connect(timeout=5.0, retries=2)
    except PineError as e:
        print(f"Cannot connect to PCSX2: {e}")
        sys.exit(1)

    title = client.title()
    game_id = client.game_id()
    print(f"Connected: {title} ({game_id})")
    print()

    # Determine dump range
    end_addr = EXTENDED_END if args.extended else OVERLAY_END

    # Dump overlay region
    print(f"Dumping overlay region 0x{OVERLAY_START:08X}-0x{end_addr:08X}...")
    data = dump_region(client, OVERLAY_START, end_addr)

    # Save raw dump
    raw_path = os.path.join(args.output, f"overlay_{args.state}_raw.bin")
    with open(raw_path, "wb") as f:
        f.write(data)
    print(f"Raw dump saved: {raw_path} ({len(data)} bytes)")

    # Find code bounds
    first, last = find_code_bounds(data)
    if first is None:
        print("No non-zero data found in overlay region!")
        client.close()
        return

    code_start = OVERLAY_START + first
    code_end = OVERLAY_START + last
    code_data = data[first:last]
    print(f"Code extent: 0x{code_start:08X}-0x{code_end:08X} ({last - first} bytes)")

    # Find functions
    functions = find_functions(data, OVERLAY_START)
    print(f"Found {len(functions)} function prologues")

    # Also scan for trampoline-style entries (lui + jr patterns)
    trampoline_count = 0
    for offset in range(0, len(data) - 8, 4):
        w0 = struct.unpack_from("<I", data, offset)[0]
        w1 = struct.unpack_from("<I", data, offset + 4)[0]
        # lui rN, imm followed by jr rN or addiu+jr
        if (w0 & LUI_OP_MASK) == LUI_OP and w0 != 0:
            if w1 == JR_RA or (w1 & 0xFC000000) == 0x08000000:  # jr or j
                trampoline_count += 1

    print(f"Found {trampoline_count} potential trampolines")

    # Save function map
    map_path = os.path.join(args.output, f"overlay_{args.state}_functions.txt")
    with open(map_path, "w") as f:
        f.write(f"# Overlay functions - state: {args.state}\n")
        f.write(f"# Game: {title} ({game_id})\n")
        f.write(f"# Region: 0x{OVERLAY_START:08X}-0x{end_addr:08X}\n")
        f.write(f"# Code extent: 0x{code_start:08X}-0x{code_end:08X}\n")
        f.write(f"# Total functions: {len(functions)}\n")
        f.write(f"#\n")
        f.write(f"# addr       frame_size  offset\n")
        for fn in functions:
            f.write(f"0x{fn['addr']:08X}  {fn['frame_size']:4d}        0x{fn['offset']:06X}\n")
    print(f"Function map saved: {map_path}")

    # Create minimal ELF for PS2Recomp
    elf_path = os.path.join(args.output, f"overlay_{args.state}.elf")
    elf_size = create_overlay_elf(code_data, code_start, elf_path)
    print(f"Overlay ELF saved: {elf_path} ({elf_size} bytes)")

    # Also dump a few key addresses for cross-reference
    print()
    print("Key memory values:")
    key_addrs = {
        0x3445E8: "vblank_counter",
        0x2B8DD0: "dma_slot_0_flag",
        0x2B8E08: "gs_buf_slot",
        0x2999D0: "heap_struct",
    }
    for addr, name in key_addrs.items():
        try:
            val = client.read32(addr)
            print(f"  {name:20s} [0x{addr:08X}] = 0x{val:08X}")
        except PineError as e:
            print(f"  {name:20s} [0x{addr:08X}] = ERROR ({e})")

    client.close()

    print()
    print("=== Summary ===")
    print(f"  Overlay region:  0x{OVERLAY_START:08X}-0x{end_addr:08X}")
    print(f"  Code extent:     0x{code_start:08X}-0x{code_end:08X} ({last-first} bytes)")
    print(f"  Functions found: {len(functions)}")
    print(f"  Raw dump:        {raw_path}")
    print(f"  Function map:    {map_path}")
    print(f"  Overlay ELF:     {elf_path}")
    print()
    print("Next steps:")
    print(f"  1. Run PS2Recomp analyzer on {elf_path}")
    print(f"  2. Navigate to different game state, re-run with --state <name>")
    print(f"  3. Diff function maps to find state-specific overlays")


if __name__ == "__main__":
    main()
