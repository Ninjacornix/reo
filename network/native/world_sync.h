// SPDX-License-Identifier: GPL-3.0-only
#pragma once
#include <cstddef>
#include <cstdint>

struct R5900Context;
class PS2Runtime;

namespace reo_network::native {
struct WorldDigest {
    uint16_t room = 0;
    uint8_t authoritySlot = 0;
    uint64_t hash = 0;
    uint16_t count = 0;
};
struct WorldStats {
    uint64_t requests = 0, rejected = 0, completed = 0;
    uint64_t actors = 0, packets = 0, skipped = 0;
};

// Pure canonical reader, independent of the SDK. The caller supplies only the
// initialized prefix of the original 256 x 96-byte scenario spawn table.
// Constructor-local slot +01, position, target, timers and flags are excluded.
inline bool worldDigestRecords(const uint8_t* records, size_t bytes,
                               uint16_t room, uint8_t authority, WorldDigest& out) {
    if (!records || bytes % 96 || bytes > 256 * 96 || room >= 128 || authority >= 4) return false;
    uint64_t hash = 14695981039346656037ull;
    auto byte = [&](uint8_t value) { hash = (hash ^ value) * 1099511628211ull; };
    byte(1); byte(uint8_t(room)); byte(uint8_t(room >> 8)); byte(authority);
    uint16_t count = 0;
    for (size_t i = 0; i < bytes / 96; ++i) {
        const auto* r = records + i * 96;
        // 6BAA40 / 6E80B0 assigns the stable ID; +22 is room and +26
        // distinguishes room-owned enemies from individually owned actors.
        if (r[0] != i) return false;
        if (r[0x22] != room || r[0x26] != 0) continue;
        byte(r[0]); byte(r[2]); byte(r[3]);
        byte(r[0x1c]); byte(r[0x1d]); byte(r[0x1e]); byte(r[0x1f]);
        byte(r[0x22]); byte(r[0x26]);
        ++count;
    }
    byte(uint8_t(count)); byte(uint8_t(count >> 8));
    out = {room, authority, hash, count};
    return true;
}

// All functions taking RAM run on the guest owner. worldRequest/worldStats/
// worldReset may be called from a transport thread and never access guest RAM.
bool worldCapture(uint8_t* ram, bool file2, uint64_t now, WorldDigest& out);
bool worldRequest(uint16_t room, uint8_t authoritySlot);
void worldTick(uint8_t* ram, R5900Context* context, PS2Runtime* runtime,
               bool file2, uint64_t now);
void worldObserve(const uint8_t* ram, bool file2, uint32_t group, uint32_t record);
void worldReset();
WorldStats worldStats();

// Only true while a fresh, validated original enemy sender is executing.
// The original queue wrapper changes that call's mode to reliable mode 4.
extern thread_local bool reliableRefresh;
} // namespace reo_network::native
