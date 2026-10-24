#pragma once
#include "runtime/gs/performance.h"
#include "reo_game_clock_observer.h"

namespace reo_performance {
inline uint8_t* ram = nullptr;
inline reo::performance::UpdateTracker tracker;
inline void configure(const char* serial, uint8_t* memory, size_t bytes) {
    if (!reo::performance::enabled()) return;
    if (!serial || std::strcmp(serial, "SLUS-20765") || !memory || bytes != PS2_RAM_SIZE ||
        reo_game_clock::word(memory, 0x1b0b80) != 0x27bdffd0u ||
        reo_game_clock::word(memory, 0x1b0b84) != 0xffbf0020u ||
        reo_game_clock::word(memory, 0x1b0b88) != 0x7fb10010u ||
        reo_game_clock::word(memory, 0x1b0b8c) != 0x7fb00000u) return;
    ram = memory;
    tracker = {};
    reo::performance::updates.store(0, std::memory_order_relaxed);
    std::fprintf(stderr, "[PERFORMANCE-OVERLAY] enabled; FPS=successful display presents, frame=present interval, UPS=original gameplay updates\n");
}
inline void sample(uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    if (!ram || memory != ram || !context || !runtime ||
        runtime->memory().getRDRAM() != ram || context->pc != 0x1b0b80u ||
        GPR_U32(context, 31) != 0x66a0d8u || ram[0x4badd0] != 2) return;
    const auto id = ram[0x4baded];
    const uint32_t actor = 0x4a5c30u + uint32_t(id) * 0x10e0u;
    if (id >= 4 || GPR_U32(context, 4) != actor || !ram[actor]) return;
    if (tracker.observe(reo_game_clock::word(ram, 0x4bade8)))
        reo::performance::updates.fetch_add(1, std::memory_order_relaxed);
}
}
