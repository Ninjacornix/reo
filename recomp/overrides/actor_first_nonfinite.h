#pragma once
#include "ps2_runtime.h"
#include <array>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <fstream>
namespace reo_actor_origin {
constexpr uint32_t ActorBase = 0x4a5c30, ActorBytes = 0x10e0, ManagerBytes = 0x824,
                   SkeletonWindow = 0x8000, MaxObservations = 8192;
struct Snapshot {
    uint32_t actor = 0, manager = 0, skeleton = 0, pc = 0, ra = 0, sp = 0, frame = 0,
             observation = 0, worldMask = 0;
    bool haveManager = false, haveSkeleton = false;
    std::array<uint8_t, sizeof(R5900Context)> context{};
    std::array<uint8_t, ActorBytes> actorBytes{};
    std::array<uint8_t, ManagerBytes> managerBytes{};
    std::array<uint8_t, SkeletonWindow> skeletonBytes{};
};
struct Event {
    Snapshot finite{}, nonfinite{};
    bool found = false, haveFinite = false;
    uint32_t phase = 0;
};
struct Token {
    uint32_t id = 4, actor = 0;
    bool valid = false;
};
inline std::array<Snapshot, 4> lastFinite{};
inline std::array<bool, 4> haveFinite{};
inline std::array<Event, 4> events{};
inline bool enabled = false;
inline uint8_t* expected = nullptr;
inline uint32_t frame = 0, observations = 0, eventsFound = 0;
inline std::filesystem::path directory;
inline uint32_t word(const uint8_t* r, uint32_t a) {
    uint32_t v;
    std::memcpy(&v, r + a, 4);
    return v;
}
inline uint32_t reg(const R5900Context* c, unsigned n) {
    uint32_t v;
    std::memcpy(&v, &c->r[n], 4);
    return v;
}
inline bool range(uint32_t a, uint32_t n) {
    return a < PS2_RAM_SIZE && n <= PS2_RAM_SIZE - a;
}
// Host storage classification only. No guest arithmetic, PS2E255 reinterpretation,
// quantization, clock, or sign/saturation policy is introduced here.
inline uint32_t worldMask(const uint8_t* r, uint32_t actor) {
    uint32_t mask = 0;
    for (unsigned c = 0; c < 3; ++c)
        if ((word(r, actor + 0x38 + 4 * c) & 0x7f800000u) == 0x7f800000u)
            mask |= 1u << c;
    return mask;
}
inline void configure(const char* serial, uint8_t* r, size_t bytes) noexcept {
    const char* path = std::getenv("REO_ACTOR_ORIGIN_DIR");
    enabled = false;
    if (!path || !*path)
        return;
    if (!serial || std::strcmp(serial, "SLUS-20765") || !r || bytes != PS2_RAM_SIZE ||
        word(r, 0x1b0b80) != 0x27bdffd0u || word(r, 0x1b0b84) != 0xffbf0020u ||
        word(r, 0x1b02d0) != 0x27bdfff0u || word(r, 0x1b02d4) != 0xffbf0000u) {
        std::fputs("[ACTOR-ORIGIN] disabled: original game/RAM signature mismatch\n", stderr);
        return;
    }
    try {
        directory = path;
        if (std::filesystem::exists(directory) && !std::filesystem::is_empty(directory)) {
            std::fputs("[ACTOR-ORIGIN] disabled: directory is not empty\n", stderr);
            return;
        }
        std::filesystem::create_directories(directory);
        expected = r;
        frame = observations = eventsFound = 0;
        haveFinite.fill(false);
        for (auto& e : events)
            e = Event{};
        enabled = true;
    } catch (...) {
        std::fputs("[ACTOR-ORIGIN] disabled: directory initialization failed\n", stderr);
    }
}
inline bool owner(uint8_t* r, R5900Context* c, PS2Runtime* p) {
    return enabled && r && r == expected && c && p && p->memory().getRDRAM() == r &&
           observations < MaxObservations && r[0x4badd0] == 2;
}
inline void snapshot(Snapshot& s, uint8_t* r, R5900Context* c, uint32_t id) {
    s.actor = ActorBase + id * ActorBytes;
    s.pc = c->pc;
    s.ra = reg(c, 31);
    s.sp = reg(c, 29);
    s.frame = frame;
    s.observation = observations;
    s.worldMask = worldMask(r, s.actor);
    std::memcpy(s.context.data(), c, sizeof(*c));
    std::memcpy(s.actorBytes.data(), r + s.actor, ActorBytes);
    s.manager = word(r, s.actor + 0x34);
    s.haveManager = s.manager && range(s.manager, ManagerBytes);
    s.skeleton = s.haveManager ? word(r, s.manager + 0x820) : 0;
    s.haveSkeleton = s.skeleton && range(s.skeleton, SkeletonWindow);
    if (s.haveManager)
        std::memcpy(s.managerBytes.data(), r + s.manager, ManagerBytes);
    if (s.haveSkeleton)
        std::memcpy(s.skeletonBytes.data(), r + s.skeleton, SkeletonWindow);
}
inline void observe(uint8_t* r, R5900Context* c, uint32_t id, uint32_t phase) {
    if (id >= 4 || events[id].found || !r[ActorBase + id * ActorBytes] ||
        observations >= MaxObservations)
        return;
    ++observations;
    if (!worldMask(r, ActorBase + id * ActorBytes)) {
        snapshot(lastFinite[id], r, c, id);
        haveFinite[id] = true;
        return;
    }
    auto& e = events[id];
    e.haveFinite = haveFinite[id];
    if (e.haveFinite)
        e.finite = lastFinite[id];
    snapshot(e.nonfinite, r, c, id);
    e.phase = phase;
    e.found = true;
    ++eventsFound;
}
// Original1B0B80 entry with original669F30 caller; includes corruption already
// present before controller copy. It is not labelled the physics producer.
inline Token beforeInput(uint8_t* r, R5900Context* c, PS2Runtime* p) {
    Token t;
    if (!owner(r, c, p) || c->pc != 0x1b0b80u || reg(c, 31) != 0x66a0d8u)
        return t;
    const uint32_t id = r[0x4baded], actor = ActorBase + id * ActorBytes;
    if (id >= 4 || reg(c, 4) != actor || !r[actor])
        return t;
    t = {id, actor, true};
    observe(r, c, id, 1);
    return t;
}
inline void afterInput(Token t, uint8_t* r, R5900Context* c, PS2Runtime* p) {
    if (t.valid && owner(r, c, p) && c->pc == 0x66a0d8u)
        observe(r, c, t.id, 2);
}
// Original669F30 reaches1B02D0 after ALL8actor iterations, not after oneactor.
// This compares each active player's lastfinite input boundary to frame-end.
inline void endActorPass(uint8_t* r, R5900Context* c, PS2Runtime* p) {
    if (!owner(r, c, p) || c->pc != 0x1b02d0u || reg(c, 31) != 0x66a2b8u)
        return;
    for (uint32_t id = 0; id < 4; ++id)
        observe(r, c, id, 3);
    ++frame;
}
// Must be called after runtime.run joins guest/IRQ/GS workers.
inline void export_after_join() noexcept {
    if (!enabled)
        return;
    try {
        auto bytes = [&](const std::string& name, const void* p, size_t n) {
            std::ofstream f(directory / name, std::ios::binary);
            f.write(static_cast<const char*>(p), n);
            return bool(f);
        };
        bool ok = true;
        for (unsigned id = 0; id < 4; ++id)
            if (events[id].found) {
                auto& e = events[id];
                for (unsigned which = 0; which < 2; ++which) {
                    if (!which && !e.haveFinite)
                        continue;
                    const Snapshot& s = which ? e.nonfinite : e.finite;
                    const auto stem = "actor-" + std::to_string(id) +
                                      (which ? "-first-nonfinite" : "-last-finite");
                    ok = bytes(stem + ".context.bin", s.context.data(), s.context.size()) && ok;
                    ok = bytes(stem + ".actor.bin", s.actorBytes.data(), s.actorBytes.size()) && ok;
                    if (s.haveManager)
                        ok = bytes(stem + ".manager.bin", s.managerBytes.data(),
                                   s.managerBytes.size()) &&
                             ok;
                    if (s.haveSkeleton)
                        ok = bytes(stem + ".skeleton-window.bin", s.skeletonBytes.data(),
                                   s.skeletonBytes.size()) &&
                             ok;
                }
            }
        std::ofstream f(directory / "summary.json");
        f << "{\"version\":1,\"complete\":" << (ok ? "true" : "false") << ",\"frames\":" << frame
          << ",\"observations\":" << observations << ",\"observation_limit\":" << MaxObservations
          << ",\"context_bytes\":" << sizeof(R5900Context) << ",\"actor_bytes\":" << ActorBytes
          << ",\"manager_bytes\":" << ManagerBytes
          << ",\"skeleton_window_bytes\":" << SkeletonWindow << ",\"events\":[";
        bool comma = false;
        for (unsigned id = 0; id < 4; ++id)
            if (events[id].found) {
                if (comma)
                    f << ',';
                comma = true;
                const auto& e = events[id];
                f << "{\"id\":" << id << ",\"phase\":" << e.phase
                  << ",\"have_finite\":" << (e.haveFinite ? "true" : "false")
                  << ",\"finite_frame\":" << e.finite.frame
                  << ",\"bad_frame\":" << e.nonfinite.frame
                  << ",\"finite_observation\":" << e.finite.observation
                  << ",\"bad_observation\":" << e.nonfinite.observation
                  << ",\"bad_mask\":" << e.nonfinite.worldMask << ",\"actor\":" << e.nonfinite.actor
                  << ",\"manager\":" << e.nonfinite.manager
                  << ",\"skeleton\":" << e.nonfinite.skeleton << ",\"bad_pc\":" << e.nonfinite.pc
                  << ",\"bad_ra\":" << e.nonfinite.ra << ",\"bad_sp\":" << e.nonfinite.sp;
                for (unsigned which = 0; which < 2; ++which) {
                    const auto& s = which ? e.nonfinite : e.finite;
                    f << (which ? ",\"bad_raw_fields\":[" : ",\"finite_raw_fields\":[");
                    constexpr uint32_t offsets[] = {0x38, 0x3c, 0x40, 0x170, 0xaa0, 0xaa4, 0x1e4};
                    for (unsigned j = 0; j < 7; ++j) {
                        if (j)
                            f << ',';
                        f << word(s.actorBytes.data(), offsets[j]);
                    }
                    f << ']';
                }
                f << '}';
            }
        f << "]}\n";
    } catch (...) {
        std::fputs("[ACTOR-ORIGIN] export failed\n", stderr);
    }
}
} // namespace reo_actor_origin
