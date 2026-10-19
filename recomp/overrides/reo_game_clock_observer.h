#pragma once
// Opt-in original Outbreak clock observation. Normal bootstrap RAM only.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
namespace reo_game_clock {
constexpr unsigned capacity = 16384;
struct Row {
    int64_t elapsed_ns = 0;
    uint32_t clock_units = 0, room_counter = 0, actor = 0, animation_bits = 0, x_bits = 0,
             z_bits = 0;
    uint32_t event_root = 0, manager = 0, skeleton = 0;
    uint16_t room = 0, destination = 0, main_service16 = 0;
    uint8_t step = 0, phase = 0, subphase = 0, paused = 0, selected = 0, request = 0, door = 0;
    uint8_t cache_scenario = 0, cache_room = 0, cache_variant = 0;
};
inline std::array<Row, capacity> rows{};
inline std::array<std::atomic<bool>, capacity> ready{};
inline std::atomic<unsigned> reserved{0}, dropped{0}, invalid{0};
inline bool enabled = false, started = false, closed = false;
inline uint8_t* expected_ram = nullptr;
inline double from_seconds = 0, duration_seconds = 120;
inline std::string output_file;
inline std::chrono::steady_clock::time_point first_room;
inline uint32_t word(const uint8_t* r, uint32_t a) {
    uint32_t v;
    std::memcpy(&v, r + a, 4);
    return v;
}
inline uint16_t half(const uint8_t* r, uint32_t a) {
    uint16_t v;
    std::memcpy(&v, r + a, 2);
    return v;
}
inline bool range(uint32_t a, uint32_t n) {
    return a < PS2_RAM_SIZE && n <= PS2_RAM_SIZE - a;
}
inline bool setting(const char* name, double fallback, double low, double high, double& out) {
    const char* text = std::getenv(name);
    out = fallback;
    if (!text || !*text)
        return true;
    char* end = nullptr;
    out = std::strtod(text, &end);
    return end != text && end && !*end && std::isfinite(out) && out >= low && out <= high;
}
// Configure once, before guest execution. Bootstrap's runtime initialize uses
// PS2Memory::initialize() default32MiB; no public RAM-size accessor is invented.
inline void configure(const char* serial, uint8_t* ram, size_t normal_ram_size) {
    const char* log = std::getenv("REO_GAME_CLOCK_LOG");
    enabled = false;
    if (!log || std::strcmp(log, "1"))
        return;
    if (!serial || std::strcmp(serial, "SLUS-20765") || !ram || normal_ram_size != PS2_RAM_SIZE ||
        word(ram, 0x1b0b80) != 0x27bdffd0u || word(ram, 0x1b0b84) != 0xffbf0020u ||
        word(ram, 0x1b0b88) != 0x7fb10010u || word(ram, 0x1b0b8c) != 0x7fb00000u ||
        !setting("REO_GAME_CLOCK_FROM_SECS", 0, 0, 600, from_seconds) ||
        !setting("REO_GAME_CLOCK_SECONDS", 120, 1, 600, duration_seconds)) {
        std::fprintf(stderr, "[GAME-CLOCK] invalid game/RAM/window; observer disabled\n");
        return;
    }
    const char* path = std::getenv("REO_GAME_CLOCK_FILE");
    output_file = path && *path ? path : "reo-game-clock.csv";
    expected_ram = ram;
    started = closed = false;
    reserved.store(0);
    dropped.store(0);
    invalid.store(0);
    for (auto& flag : ready)
        flag.store(false, std::memory_order_relaxed);
    enabled = true;
    std::fprintf(stderr, "[GAME-CLOCK] configured from=%.3f duration=%.3f capacity=%u file=%s\n",
                 from_seconds, duration_seconds, capacity, output_file.c_str());
}
// Called only by one main-ELF entry wrapper on the guest owner, before original
// controller copy. No background RAM sampling or guest state/context writes.
inline void sample(uint8_t* r, R5900Context* c, PS2Runtime* p) {
    if (!enabled || closed || !r || r != expected_ram || !c || !p || p->memory().getRDRAM() != r ||
        c->pc != 0x1b0b80u || GPR_U32(c, 31) != 0x66a0d8u)
        return;
    const uint8_t id = r[0x4baded];
    const uint32_t actor = 0x4a5c30u + uint32_t(id) * 0x10e0u;
    if (id >= 4 || GPR_U32(c, 4) != actor || !r[actor])
        return;
    if (!started && r[0x4badd0] != 2)
        return;
    const auto now = std::chrono::steady_clock::now();
    if (!started) {
        first_room = now;
        started = true;
    }
    const int64_t elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(now - first_room).count();
    const double seconds = double(elapsed) * 1e-9;
    if (seconds < from_seconds)
        return;
    if (seconds >= from_seconds + duration_seconds) {
        closed = true;
        return;
    }
    if (r[0x4bae00] >= 100 || r[0x4bae01] >= 60 || r[0x4bae02] >= 60 || r[0x4bae03] >= 60) {
        invalid.fetch_add(1, std::memory_order_relaxed);
        return;
    }
    const unsigned n = reserved.fetch_add(1, std::memory_order_relaxed);
    if (n >= capacity) {
        dropped.fetch_add(1, std::memory_order_relaxed);
        return;
    }
    Row q{};
    q.elapsed_ns = elapsed;
    q.clock_units =
        ((uint32_t(r[0x4bae00]) * 60 + r[0x4bae01]) * 60 + r[0x4bae02]) * 60 + r[0x4bae03];
    q.room_counter = word(r, 0x4bade8);
    q.actor = actor;
    q.animation_bits = word(r, actor + 0x1e4);
    q.x_bits = word(r, actor + 0x38);
    q.z_bits = word(r, actor + 0x40);
    q.event_root = word(r, 0x3b5160);
    q.manager = word(r, actor + 0x34);
    if (q.manager && range(q.manager, 0x824))
        q.skeleton = word(r, q.manager + 0x820);
    q.room = half(r, 0x3243dc);
    q.destination = half(r, 0x3243e2);
    q.main_service16 = half(r, 0x3244c0);
    q.step = r[0x3243cc] ? 2 : 1;
    q.phase = r[0x4badd0];
    q.subphase = r[0x4badd1];
    q.paused = r[0x4badf8];
    q.selected = id;
    q.request = r[0x4bae07];
    q.door = r[0x4bae05];
    q.cache_scenario = r[0x7434b0];
    q.cache_room = r[0x7434b1];
    q.cache_variant = r[0x7434b2];
    rows[n] = q;
    ready[n].store(true, std::memory_order_release);
}
// runtime.run() joins IRQ/all guest/GS workers before returning in this baseline.
inline void export_after_join() {
    if (!enabled)
        return;
    FILE* f = std::fopen(output_file.c_str(), "wb");
    if (!f) {
        std::fprintf(stderr, "[GAME-CLOCK] cannot open export %s\n", output_file.c_str());
        return;
    }
    std::fprintf(f,
                 "# from_secs=%.9f duration_secs=%.9f started=%u closed=%u reserved=%u dropped=%u "
                 "invalid_clock=%u capacity=%u\n",
                 from_seconds, duration_seconds, unsigned(started), unsigned(closed),
                 reserved.load(), dropped.load(), invalid.load(), capacity);
    std::fprintf(f,
                 "n,elapsed_ns,clock_units,room_counter,actor,animation_bits,x_bits,z_bits,event_"
                 "root,manager,skeleton,room,destination,main_service16,step,phase,subphase,paused,"
                 "selected,request,door,cache_scenario,cache_room,cache_variant\n");
    const unsigned limit = reserved.load();
    unsigned count = 0, unpublished = 0;
    for (unsigned n = 0; n < limit && n < capacity; ++n) {
        if (!ready[n].load(std::memory_order_acquire)) {
            ++unpublished;
            continue;
        }
        const Row& q = rows[n];
        ++count;
        std::fprintf(
            f, "%u,%lld,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u\n", n,
            static_cast<long long>(q.elapsed_ns), q.clock_units, q.room_counter, q.actor,
            q.animation_bits, q.x_bits, q.z_bits, q.event_root, q.manager, q.skeleton, q.room,
            q.destination, q.main_service16, q.step, q.phase, q.subphase, q.paused, q.selected,
            q.request, q.door, q.cache_scenario, q.cache_room, q.cache_variant);
    }
    std::fprintf(f, "# rows=%u unpublished=%u\n", count, unpublished);
    std::fclose(f);
    std::fprintf(stderr,
                 "[GAME-CLOCK] export rows=%u dropped=%u invalid=%u unpublished=%u started=%u "
                 "closed=%u file=%s\n",
                 count, dropped.load(), invalid.load(), unpublished, unsigned(started),
                 unsigned(closed), output_file.c_str());
}
} // namespace reo_game_clock
