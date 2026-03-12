/*
 * REO Execution Trace Format
 *
 * Shared header between the tracer (in reo_recomp) and the trace
 * comparison tool. Records key events for comparison against PCSX2.
 *
 * Two comparison modes:
 *   1. Hardware trace: DMA transfers, GS register writes, VU runs
 *      → Compare against PCSX2 GS dump to validate bridge correctness
 *
 *   2. Memory snapshot: RAM contents at specific points
 *      → Compare against PCSX2 save state to find divergences
 */

#pragma once
#include <cstdint>

namespace reo_trace {

// Trace file magic: "REOT" + version
constexpr uint32_t TRACE_MAGIC   = 0x544F4552; // "REOT"
constexpr uint32_t TRACE_VERSION = 1;

// Event types
enum EventType : uint8_t {
    EVT_FUNC_CALL     = 0x01,  // Function called (addr, from_addr)
    EVT_FUNC_RETURN   = 0x02,  // Function returned (addr, retval)
    EVT_DMA_GIF       = 0x10,  // GIF DMA transfer (madr, qwc, first 64 bytes)
    EVT_DMA_VIF1      = 0x11,  // VIF1 DMA transfer (madr, qwc, first 64 bytes)
    EVT_GS_REG_WRITE  = 0x20,  // GS privileged register write (offset, value)
    EVT_GS_INTERNAL   = 0x21,  // GS internal register write (reg, value)
    EVT_VU_START      = 0x30,  // VU microprogram start (unit, addr)
    EVT_VU_END        = 0x31,  // VU microprogram end (unit, cycles)
    EVT_XGKICK        = 0x32,  // XGKICK GIF submission (size, first 64 bytes)
    EVT_VSYNC          = 0x40,  // VSync event (frame number)
    EVT_MEM_SNAPSHOT   = 0x50,  // Memory region snapshot (addr, size, hash)
    EVT_STUB_CALL      = 0x60,  // Stub function hit (addr, a0, a1)
    EVT_OVERRIDE_CALL  = 0x61,  // Override function called (addr, a0, a1)
};

// File header
struct TraceHeader {
    uint32_t magic;
    uint32_t version;
    uint32_t game_crc;      // For matching against PCSX2 dumps
    uint32_t flags;          // Reserved
    uint64_t timestamp;      // Unix timestamp when trace started
};

// Event record header (followed by type-specific payload)
struct EventRecord {
    uint64_t sequence;       // Monotonic sequence number
    uint32_t timestamp_us;   // Microseconds since trace start
    EventType type;
    uint8_t  reserved[3];
};

// Payloads
struct FuncCallEvent {
    uint32_t addr;           // Function address
    uint32_t caller;         // Return address
    uint32_t a0, a1, a2, a3; // First 4 args
};

struct DmaEvent {
    uint32_t channel_base;
    uint32_t madr;
    uint32_t qwc;
    uint32_t tadr;
    uint8_t  first_bytes[64]; // First 64 bytes of transfer data
};

struct GsRegEvent {
    uint32_t offset;
    uint64_t value;
};

struct VuEvent {
    uint8_t  unit;
    uint32_t addr;
    uint32_t cycles;
};

struct MemSnapshotEvent {
    uint32_t addr;
    uint32_t size;
    uint64_t xxhash;         // XXHash64 of the region
};

} // namespace reo_trace
