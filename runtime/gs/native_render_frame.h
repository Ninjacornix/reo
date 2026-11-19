#pragma once
// Native renderer (REO_NATIVE_RENDER=1): per-frame game state published by the game thread
// for tools/parallel_gs_backend/native_render.hpp (docs/native-gameplay/NATIVE_RENDERER.md).
//
// The game thread copies, once per evaluated room camera (recomp/overrides/native_camera/
// room_camera_adapter.cpp), the File #1 view matrix, the pixel projection, the room part
// matrices and every active character's bone records. The GS worker takes the newest copy
// when it draws. A mutex guards the copy (about 50 KB, once per game frame).
#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <mutex>

namespace reo::native_render {

inline bool enabled() {
    static const bool value = [] { const char* v = std::getenv("REO_NATIVE_RENDER"); return v && v[0] == '1' && !v[1]; }();
    return value;
}

constexpr uint32_t MaxActors = 8, MaxBones = 48, MaxRoomParts = 128;

struct Actor {
    uint8_t character = 0xFF;  // actor +0x30: 0 Kevin ... 7 Cindy (P0n_00.NBD)
    uint32_t bones = 0;        // valid bone records
    float world[MaxBones][16];
    float inverse_bind[MaxBones][16];
};

struct Frame {
    uint64_t serial = 0;
    uint8_t scenario = 0, room = 0;  // 0x7434B0 / 0x7434B1: archive r0SS, room RR
    float view[16]{}, projection[16]{};
    float room_parts[MaxRoomParts][16]{};
    uint32_t actor_count = 0;
    Actor actors[MaxActors];
};

inline std::mutex& frame_lock() { static std::mutex m; return m; }
inline Frame& frame_storage() { static Frame f; return f; }

#if !defined(REO_GAME_FILE2)
// rdram: guest RAM base; main RAM is 32 MB. Addresses: docs/native-gameplay/NATIVE_RENDERER.md.
inline void publish(const uint8_t* rdram) {
    if (!enabled() || !rdram) return;
    constexpr uint32_t Ram = 0x2000000;
    auto read32 = [&](uint32_t a) { uint32_t v = 0; if (a + 4 <= Ram) std::memcpy(&v, rdram + a, 4); return v; };
    auto copy = [&](float* out, uint32_t a, size_t floats) {
        if (a + floats * 4 <= Ram) std::memcpy(out, rdram + a, floats * 4); else std::memset(out, 0, floats * 4);
    };
    static Frame next;  // game thread only
    next.scenario = rdram[0x7434b0];
    next.room = rdram[0x7434b1];
    copy(next.view, 0x3240e0, 16);
    copy(next.projection, 0x294d80, 16);
    copy(&next.room_parts[0][0], 0x49fa10, MaxRoomParts * 16);
    next.actor_count = 0;
    for (uint32_t i = 0; i < MaxActors; ++i) {
        const uint32_t actor = 0x4a5c30 + i * 0x10e0;
        if (!rdram[actor]) continue;                      // inactive slot
        const uint32_t model = read32(actor + 0x34);      // model object
        if (!model || model >= Ram) continue;
        // Model +0x820: one pointer per skeleton node (skin palette index n -> +0x820 + 4n);
        // the record holds the world matrix at +0x00 and the inverse bind matrix at +0x80.
        Actor& out = next.actors[next.actor_count];
        out.character = rdram[actor + 0x30];
        out.bones = 0;
        for (uint32_t b = 0; b < MaxBones; ++b) {
            const uint32_t record = read32(model + 0x820 + 4 * b);
            if (!record || record + 0xC0 > Ram) break;
            copy(out.world[b], record, 16);
            if (out.world[b][15] != 1.f || out.world[b][3] != 0.f || out.world[b][7] != 0.f || out.world[b][11] != 0.f)
                break;  // past the last node
            copy(out.inverse_bind[b], record + 0x80, 16);
            out.bones = b + 1;
        }
        if (out.bones) ++next.actor_count;
    }
    std::lock_guard<std::mutex> guard(frame_lock());
    next.serial = frame_storage().serial + 1;
    frame_storage() = next;
}
#else
inline void publish(const uint8_t*) {}
#endif

inline bool snapshot(Frame& out) {
    std::lock_guard<std::mutex> guard(frame_lock());
    if (!frame_storage().serial) return false;
    out = frame_storage();
    return true;
}

}  // namespace reo::native_render
