#pragma once
#include "ps2_runtime.h"
#include <array>
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <fstream>
namespace reo_ground_origin {
constexpr uint32_t ActorBase = 0x4a5c30, ActorBytes = 0x10e0, QueryLimit = 65536;
struct Work {
    bool valid = false, directActor = false, selected = false;
    uint32_t id = 4, kind = 0, ordinal = 0, actor = 0, ra = 0, sp = 0, queryAddress = 0, plane = 0,
             result = 0, selectionPC = 0, surfaceAddress = 0, surfaceValue = 0, selectionCount = 0;
    std::array<uint32_t, 4> query{}, selectedQuery{};
    std::array<uint32_t, 7> preActor{}, postActor{};
    std::array<uint8_t, sizeof(R5900Context)> entry{}, exit{}, selectedContext{};
    std::array<uint8_t, 56> planeBytes{};
    std::array<uint8_t, ActorBytes> actorBytes{};
};
inline bool enabled = false;
inline uint8_t* expected = nullptr;
inline uint32_t calls = 0, interrupted = 0, selectedCalls = 0;
inline std::array<Work, 8> events{};
inline std::array<bool, 8> found{};
inline std::filesystem::path directory;
inline thread_local Work* active = nullptr;
inline uint32_t word(const void* p) {
    uint32_t v;
    std::memcpy(&v, p, 4);
    return v;
}
inline uint32_t reg(const R5900Context* c, unsigned n) {
    return word(&c->r[n]);
}
inline bool range(uint32_t a, uint32_t n) {
    return a < PS2_RAM_SIZE && n <= PS2_RAM_SIZE - a;
}
inline uint32_t fbits(const R5900Context* c, unsigned n) {
    return word(&c->f[n]);
}
inline bool hostNonfinite(uint32_t u) {
    return (u & 0x7f800000u) == 0x7f800000u;
}
inline void actorFields(std::array<uint32_t, 7>& out, uint8_t* r, uint32_t a) {
    constexpr uint32_t offsets[] = {0x38, 0x3c, 0x40, 0x170, 0xaa0, 0xaa4, 0x174};
    for (unsigned i = 0; i < 7; ++i)
        out[i] = word(r + a + offsets[i]);
}
inline void configure(const char* serial, uint8_t* r, size_t bytes) noexcept {
    enabled = false;
    const char* path = std::getenv("REO_GROUND_ORIGIN_DIR");
    if (!path || !*path)
        return;
    if (!serial || std::strcmp(serial, "SLUS-20765") || !r || bytes != PS2_RAM_SIZE)
        return;
    try {
        directory = path;
        if (std::filesystem::exists(directory) && !std::filesystem::is_empty(directory)) {
            std::fputs("[GROUND-ORIGIN] disabled: directory not empty\n", stderr);
            return;
        }
        std::filesystem::create_directories(directory);
        expected = r;
        calls = interrupted = selectedCalls = 0;
        found.fill(false);
        for (auto& e : events)
            e = Work{};
        active = nullptr;
        enabled = true;
    } catch (...) {
        std::fputs("[GROUND-ORIGIN] disabled: directory initialization failed\n", stderr);
    }
}
inline bool owner(uint8_t* r, R5900Context* c, PS2Runtime* p) {
    return enabled && r && r == expected && c && p && p->memory().getRDRAM() == r &&
           r[0x4badd0] == 2;
}
inline void begin(Work& w, uint8_t* r, R5900Context* c, PS2Runtime* p) {
    if (!owner(r, c, p) || c->pc != 0x617000u || calls >= QueryLimit)
        return;
    const uint32_t ra = reg(c, 31);
    if (ra != 0x616f04u && ra != 0x616f48u)
        return;
    uint32_t id = r[0x4baded];
    bool direct = false;
    if (ra == 0x616f04u) {
        const uint32_t flag = reg(c, 7);
        if (flag < ActorBase + 0x174)
            return;
        const uint32_t delta = flag - ActorBase - 0x174;
        if (delta % ActorBytes || delta / ActorBytes >= 4)
            return;
        id = delta / ActorBytes;
        direct = true;
    }
    if (id >= 4)
        return;
    const uint32_t kind = ra == 0x616f04u ? 0 : 1, index = id * 2 + kind;
    if (found[index])
        return;
    const uint32_t query = reg(c, 4);
    if (!range(query, 16))
        return;
    w.valid = true;
    w.directActor = direct;
    w.id = id;
    w.kind = kind;
    w.ordinal = ++calls;
    w.actor = ActorBase + id * ActorBytes;
    w.ra = ra;
    w.sp = reg(c, 29);
    w.queryAddress = query;
    std::memcpy(w.query.data(), r + query, 16);
    std::memcpy(w.entry.data(), c, sizeof(*c));
    actorFields(w.preActor, r, w.actor);
}
struct Scope {
    Work* previous;
    explicit Scope(Work& w) : previous(active) {
        active = w.valid ? &w : nullptr;
    }
    ~Scope() {
        active = previous;
    }
    Scope(const Scope&) = delete;
};
// Called immediately before the two genuine selected-surface writes in an
// otherwise byte-for-byte normalized original 617000 body. Both ordinary
// callers have T3=0 and do not reach the optional 371480 callback.
inline void selectionWrite(uint8_t* r, R5900Context* c, PS2Runtime* p, uint32_t address,
                           uint8_t value) {
    if (!active || !active->valid || !owner(r, c, p) || (c->pc != 0x6171ccu && c->pc != 0x617214u))
        return;
    const uint32_t plane = reg(c, 16), query = reg(c, 21);
    if (!range(plane, 56) || !range(query, 16) || !range(address, 1) || reg(c, 19) != plane ||
        query != active->queryAddress || address != reg(c, 23) || fbits(c, 1) != fbits(c, 20))
        return;
    auto& w = *active;
    w.selected = true;
    w.plane = plane;
    w.selectionPC = c->pc;
    w.surfaceAddress = address;
    w.surfaceValue = value;
    ++w.selectionCount;
    ++selectedCalls;
    std::memcpy(w.planeBytes.data(), r + plane, 56);
    std::memcpy(w.selectedContext.data(), c, sizeof(*c));
    std::memcpy(w.selectedQuery.data(), r + query, 16);
}
inline void finish(Work& w, uint8_t* r, R5900Context* c, PS2Runtime* p) {
    if (!w.valid)
        return;
    if (!owner(r, c, p) || c->pc != w.ra || reg(c, 29) != w.sp) {
        ++interrupted;
        return;
    }
    w.result = fbits(c, 0);
    if (!hostNonfinite(w.result))
        return;
    const unsigned index = w.id * 2 + w.kind;
    if (found[index])
        return;
    std::memcpy(w.exit.data(), c, sizeof(*c));
    std::memcpy(w.actorBytes.data(), r + w.actor, ActorBytes);
    actorFields(w.postActor, r, w.actor);
    events[index] = w;
    found[index] = true;
}
inline void export_after_join() noexcept {
    if (!enabled)
        return;
    try {
        bool ok = true;
        auto bytes = [&](const std::string& name, const void* p, size_t n) {
            std::ofstream f(directory / name, std::ios::binary);
            f.write(static_cast<const char*>(p), n);
            return bool(f);
        };
        for (unsigned i = 0; i < 8; ++i)
            if (found[i]) {
                const auto& w = events[i];
                const auto stem = "query-" + std::to_string(i);
                ok = bytes(stem + ".entry-context.bin", w.entry.data(), w.entry.size()) && ok;
                ok = bytes(stem + ".exit-context.bin", w.exit.data(), w.exit.size()) && ok;
                ok = bytes(stem + ".actor.bin", w.actorBytes.data(), w.actorBytes.size()) && ok;
                if (w.selected) {
                    ok = bytes(stem + ".selected-context.bin", w.selectedContext.data(),
                               w.selectedContext.size()) &&
                         ok;
                    ok = bytes(stem + ".plane.bin", w.planeBytes.data(), w.planeBytes.size()) && ok;
                }
            }
        std::ofstream f(directory / "summary.json");
        f << "{\"version\":2,\"complete\":" << (ok ? "true" : "false")
          << ",\"context_bytes\":" << sizeof(R5900Context)
          << ",\"context_f_offset\":" << offsetof(R5900Context, f)
          << ",\"context_pc_offset\":" << offsetof(R5900Context, pc)
          << ",\"query_limit\":" << QueryLimit << ",\"calls\":" << calls
          << ",\"interrupted_calls\":" << interrupted << ",\"selected_calls\":" << selectedCalls
          << ",\"events\":[";
        bool comma = false;
        for (unsigned i = 0; i < 8; ++i)
            if (found[i]) {
                const auto& w = events[i];
                if (comma)
                    f << ',';
                comma = true;
                f << "{\"slot\":" << i << ",\"id\":" << w.id << ",\"kind\":" << w.kind
                  << ",\"ordinal\":" << w.ordinal
                  << ",\"direct_actor_join\":" << (w.directActor ? "true" : "false")
                  << ",\"actor\":" << w.actor << ",\"entry_ra\":" << w.ra
                  << ",\"query_address\":" << w.queryAddress << ",\"result_bits\":" << w.result
                  << ",\"input_y_host_nonfinite\":"
                  << (hostNonfinite(w.query[1]) ? "true" : "false")
                  << ",\"selected\":" << (w.selected ? "true" : "false")
                  << ",\"plane\":" << w.plane;
                auto array = [&](const char* key, const auto& values) {
                    f << ",\"" << key << "\":[";
                    for (unsigned j = 0; j < values.size(); ++j) {
                        if (j)
                            f << ',';
                        f << values[j];
                    }
                    f << ']';
                };
                array("query_raw", w.query);
                array("selected_query_raw", w.selectedQuery);
                array("pre_actor_raw", w.preActor);
                array("post_actor_raw", w.postActor);
                if (w.selected) {
                    f << ",\"selection_pc\":" << w.selectionPC
                      << ",\"selection_count\":" << w.selectionCount
                      << ",\"surface_address\":" << w.surfaceAddress
                      << ",\"surface_value\":" << w.surfaceValue << ",\"selected_height_f20_bits\":"
                      << word(w.selectedContext.data() + offsetof(R5900Context, f) + 20 * 4)
                      << ",\"selected_numerator_f3_bits\":"
                      << word(w.selectedContext.data() + offsetof(R5900Context, f) + 3 * 4);
                    std::array<uint32_t, 4> coeff{};
                    std::memcpy(coeff.data(), w.planeBytes.data() + 0x28, 16);
                    array("plane_abcd_raw", coeff);
                }
                f << '}';
            }
        f << "]}\n";
    } catch (...) {
        std::fputs("[GROUND-ORIGIN] export failed\n", stderr);
    }
}
} // namespace reo_ground_origin
