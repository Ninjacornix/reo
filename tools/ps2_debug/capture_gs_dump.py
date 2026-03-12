#!/usr/bin/env python3
"""
Capture GS register state from PCSX2 via Pine IPC.

Reads GS privileged registers (0x12000000-0x12001FFF) and the first
few GIF transfer packets from DMA registers. Saves for offline analysis.
"""
import sys
import os
import struct
import json
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pine_client import PineClient, PineError

# GS privileged registers (mapped at 0x12000000 in PS2 memory map)
# In PCSX2's RAM, these are at physical addresses
GS_PRIV_REGS = {
    0x12000000: "PMODE",
    0x12000010: "SMODE1",
    0x12000020: "SMODE2",
    0x12000030: "SRFSH",
    0x12000040: "SYNCH1",
    0x12000050: "SYNCH2",
    0x12000060: "SYNCV",
    0x12000070: "DISPFB1",
    0x12000080: "DISPLAY1",
    0x12000090: "DISPFB2",
    0x120000A0: "DISPLAY2",
    0x120000B0: "EXTBUF",
    0x120000C0: "EXTDATA",
    0x120000D0: "EXTWRITE",
    0x120000E0: "BGCOLOR",
    0x12001000: "CSR",
    0x12001010: "IMR",
    0x12001040: "BUSDIR",
    0x12001080: "SIGLBLID",
}

# DMA channel registers
DMA_GIF_BASE = 0x1000A000
DMA_VIF1_BASE = 0x10009000
DMA_REGS = {
    0x00: "CHCR",  # Channel control
    0x10: "MADR",  # Memory address
    0x20: "QWC",   # Quadword count
    0x30: "TADR",  # Tag address
    0x40: "ASR0",  # Address stack 0
    0x50: "ASR1",  # Address stack 1
}

def read_safe(client, addr):
    """Read 32-bit value, return 0 on error."""
    try:
        return client.read32(addr)
    except PineError:
        return 0

def capture_gs_state(client):
    """Capture GS register state."""
    state = {}
    for addr, name in GS_PRIV_REGS.items():
        lo = read_safe(client, addr)
        hi = read_safe(client, addr + 4)
        val = lo | (hi << 32)
        state[name] = {"addr": f"0x{addr:08X}", "value": f"0x{val:016X}", "lo": f"0x{lo:08X}", "hi": f"0x{hi:08X}"}
    return state

def capture_dma_state(client):
    """Capture DMA channel register state."""
    channels = {}
    for base, ch_name in [(DMA_GIF_BASE, "GIF"), (DMA_VIF1_BASE, "VIF1")]:
        regs = {}
        for off, reg_name in DMA_REGS.items():
            val = read_safe(client, base + off)
            regs[reg_name] = f"0x{val:08X}"
        channels[ch_name] = {"base": f"0x{base:08X}", "regs": regs}
    return channels

def capture_gif_data(client, madr, qwc, max_qw=64):
    """Read GIF packet data from RAM at the DMA source address."""
    if madr == 0 or qwc == 0:
        return None

    read_qw = min(qwc, max_qw)
    data = []
    for i in range(read_qw):
        addr = madr + i * 16
        w0 = read_safe(client, addr)
        w1 = read_safe(client, addr + 4)
        w2 = read_safe(client, addr + 8)
        w3 = read_safe(client, addr + 12)
        data.append({
            "offset": f"0x{i*16:04X}",
            "w0": f"0x{w0:08X}",
            "w1": f"0x{w1:08X}",
            "w2": f"0x{w2:08X}",
            "w3": f"0x{w3:08X}",
        })
    return data

def main():
    output_dir = "gs_capture"
    os.makedirs(output_dir, exist_ok=True)

    print("=== PCSX2 GS State Capture ===")

    client = PineClient()
    try:
        client.connect(timeout=5.0, retries=2)
    except PineError as e:
        print(f"Cannot connect: {e}")
        sys.exit(1)

    title = client.title()
    game_id = client.game_id()
    print(f"Connected: {title} ({game_id})")

    # Capture GS state
    print("\nCapturing GS registers...")
    gs_state = capture_gs_state(client)

    print("Capturing DMA state...")
    dma_state = capture_dma_state(client)

    # Try to read GIF packet at DMA source
    gif_madr = read_safe(client, DMA_GIF_BASE + 0x10)
    gif_qwc = read_safe(client, DMA_GIF_BASE + 0x20)
    gif_data = None
    if gif_madr != 0:
        print(f"Reading GIF data at MADR=0x{gif_madr:08X}, QWC={gif_qwc}...")
        gif_data = capture_gif_data(client, gif_madr, max(gif_qwc, 16))

    # Read some key game rendering state
    print("Reading game rendering state...")
    render_state = {}
    render_addrs = {
        0x2B8DD0: "dma_slot_0_flag",
        0x2B8DD4: "dma_slot_0_ptr",
        0x2B8DD8: "dma_slot_1_flag",
        0x2B8DDC: "dma_slot_1_ptr",
        0x2B8DE0: "dma_slot_2_flag",
        0x2B8DE4: "dma_slot_2_ptr",
        0x2B8E08: "gs_buf_slot",
        0x3445E8: "vblank_counter",
    }
    for addr, name in render_addrs.items():
        val = read_safe(client, addr)
        render_state[name] = f"0x{val:08X}"

    client.close()

    # Save everything
    result = {
        "timestamp": time.strftime("%Y-%m-%d %H:%M:%S"),
        "game": title.strip(),
        "game_id": game_id.strip(),
        "gs_registers": gs_state,
        "dma_channels": dma_state,
        "gif_data": gif_data,
        "render_state": render_state,
    }

    out_path = os.path.join(output_dir, "gs_state.json")
    with open(out_path, "w") as f:
        json.dump(result, f, indent=2)
    print(f"\nSaved to {out_path}")

    # Print summary
    print("\n=== GS Register Summary ===")
    for name in ["PMODE", "SMODE2", "DISPFB1", "DISPLAY1", "DISPFB2", "DISPLAY2", "BGCOLOR", "CSR"]:
        info = gs_state.get(name, {})
        print(f"  {name:12s} = {info.get('value', 'N/A')}")

    print("\n=== DMA Channel Summary ===")
    for ch_name, ch_info in dma_state.items():
        regs = ch_info["regs"]
        print(f"  {ch_name}: CHCR={regs['CHCR']} MADR={regs['MADR']} QWC={regs['QWC']} TADR={regs['TADR']}")

    print("\n=== Game Rendering State ===")
    for name, val in render_state.items():
        print(f"  {name:20s} = {val}")

    if gif_data and len(gif_data) > 0:
        print(f"\n=== GIF Data ({len(gif_data)} QWs at MADR) ===")
        for qw in gif_data[:8]:
            print(f"  {qw['offset']}: {qw['w0']} {qw['w1']} {qw['w2']} {qw['w3']}")
        if len(gif_data) > 8:
            print(f"  ... ({len(gif_data) - 8} more)")

if __name__ == "__main__":
    main()
