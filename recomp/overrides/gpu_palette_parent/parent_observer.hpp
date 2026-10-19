#pragma once
// Bounded read-only source frontiers. These observations confer no GPU ownership.
#include "ps2_runtime.h"
#include <array>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <stdexcept>
#include <string>

namespace reo_palette_parent {
using Fn = void (*)(uint8_t*, R5900Context*, PS2Runtime*);
constexpr uint32_t RamBytes = 0x2000000u, PacketBytes = 0xfb0u;
constexpr unsigned MaxParents = 16, MaxEvents = 80;
constexpr uint32_t GlobalAddress = 0x294000u, GlobalBytes = 0x1000u;
constexpr uint32_t ParentPCs[]{0x19bbd0, 0x19bbfc, 0x19bcfc, 0x19bd2c, 0x19bd50,
                               0x19bd9c, 0x19bdb4, 0x19be54, 0x19be64};
enum class Phase : uint32_t {
    Entry,
    Allocated,
    UniformBefore,
    UniformAfter,
    Palette,
    Copy3FC0,
    Light,
    Material,
    Returned
};
struct Call {
    PS2Runtime* runtime = nullptr;
    R5900Context* context = nullptr;
    uint64_t ordinal = 0;
    uint32_t frame = 0, descriptor = 0, outerReturn = 0, packet = 0;
    uint32_t events = 0, bone = 0, paletteMask = 0, paletteSeen = 0, paletteReturned = 0;
    uint32_t pendingReturn = 0;
    Phase pending = Phase::Entry;
    bool live = false, allocated = false, complete = false, refused = false, pendingCall = false;
    bool beforeUniform = false, afterUniform = false, copyReturned = false, lightReturned = false,
         materialReturned = false;
};
struct Capture {
    std::recursive_mutex mutex;
    bool enabled = false, ioFailed = false, limitLogged = false;
    unsigned calls = 0, events = 0, completed = 0, refused = 0;
    uint64_t nextOrdinal = 1;
    std::array<Call, MaxParents> parents{};
    std::filesystem::path directory;
    std::ofstream log;
};
inline Capture capture;
inline bool range(uint32_t at, uint32_t bytes) noexcept {
    return at < RamBytes && bytes <= RamBytes - at;
}
inline uint32_t word(const void* p) noexcept {
    uint32_t v;
    std::memcpy(&v, p, 4);
    return v;
}
inline uint32_t reg(const R5900Context& ctx, unsigned index) noexcept {
    return word(&ctx.r[index]);
}
inline bool overlap(uint32_t a, uint32_t n, uint32_t b, uint32_t m) noexcept {
    return uint64_t(a) < uint64_t(b) + m && uint64_t(b) < uint64_t(a) + n;
}
inline const char* phaseName(Phase p) noexcept {
    switch (p) {
        case Phase::Entry:
            return "entry";
        case Phase::Allocated:
            return "allocated";
        case Phase::UniformBefore:
            return "uniform-before";
        case Phase::UniformAfter:
            return "uniform-after";
        case Phase::Palette:
            return "palette";
        case Phase::Copy3FC0:
            return "copy3fc0";
        case Phase::Light:
            return "light";
        case Phase::Material:
            return "material";
        case Phase::Returned:
            return "returned";
    }
    return "invalid";
}
inline Call* find(PS2Runtime* runtime, R5900Context* ctx, bool final = false) noexcept {
    if (!runtime || !ctx)
        return nullptr;
    const uint32_t sp = reg(*ctx, 29);
    for (unsigned i = capture.calls; i; --i) {
        auto& c = capture.parents[i - 1];
        if (c.live && c.runtime == runtime && c.context == ctx &&
            sp == c.frame + (final ? 0x70u : 0u))
            return &c;
    }
    return nullptr;
}
inline void refuse(Call& c, const char* reason) {
    if (c.refused)
        return;
    c.refused = true;
    ++capture.refused;
    capture.log << "{\"kind\":\"refusal\",\"ordinal\":" << c.ordinal << ",\"reason\":\"" << reason
                << "\",\"ownership_certified\":false,\"guest_writes\":false}\n";
    capture.log.flush();
}
inline void save(const std::string& name, const void* data, size_t bytes) {
    if (!data || !bytes || capture.ioFailed)
        return;
    const auto path = capture.directory / name;
    if (std::filesystem::exists(path)) {
        capture.ioFailed = true;
        throw std::runtime_error("Capture file already exists");
    }
    std::ofstream f(path, std::ios::binary);
    f.write(static_cast<const char*>(data), std::streamsize(bytes));
    if (!f) {
        capture.ioFailed = true;
        throw std::runtime_error("Capture write failed");
    }
}
inline void snapshot(Call& c, const uint8_t* ram, R5900Context* ctx, Phase phase,
                     const char* direction) {
    if (c.refused || capture.ioFailed || !ram || !ctx || !c.runtime)
        return;
    if (c.events >= MaxEvents) {
        refuse(c, "event-limit");
        return;
    }
    const uint32_t currentDescriptor = c.descriptor;
    if (!range(currentDescriptor, 0x180) || !range(c.frame, 0x70) || c.frame < 0x60) {
        refuse(c, "source-range");
        return;
    }
    const uint32_t meta = word(ram + currentDescriptor + 0x4c);
    if (!range(meta, 0x28)) {
        refuse(c, "descriptor-meta-range");
        return;
    }
    const unsigned index = c.events++;
    ++capture.events;
    const std::string stem =
        "parent-" + std::to_string(c.ordinal) + "-event-" + std::to_string(index);
    save(stem + ".context.bin", ctx, sizeof(*ctx));
    save(stem + ".spr.bin", c.runtime->memory().getScratchpad(), 0x4000);
    save(stem + ".globals-294000.bin", ram + GlobalAddress, GlobalBytes);
    save(stem + ".globals-29fe40.bin", ram + 0x29fe40, 0x10);
    save(stem + ".descriptor.bin", ram + currentDescriptor, 0x180);
    save(stem + ".descriptor-meta.bin", ram + meta, 0x28);
    save(stem + ".stack-minus60.bin", ram + c.frame - 0x60, 0xd0);
    if (c.allocated)
        save(stem + ".packet.bin", ram + c.packet, PacketBytes);
    capture.log
        << "{\"kind\":\"source-frontier\",\"schema\":1,\"ordinal\":" << c.ordinal
        << ",\"event\":" << index << ",\"phase\":\"" << phaseName(phase) << "\",\"direction\":\""
        << direction << "\",\"pc\":" << ctx->pc << ",\"RA\":" << reg(*ctx, 31)
        << ",\"SP\":" << reg(*ctx, 29) << ",\"frame\":" << c.frame
        << ",\"outer_return\":" << c.outerReturn << ",\"descriptor\":" << currentDescriptor
        << ",\"descriptor_meta\":" << meta << ",\"packet\":" << c.packet
        << ",\"packet_allocated\":" << (c.allocated ? "true" : "false") << ",\"bone\":" << c.bone
        << ",\"raw_capture_complete\":true,\"GPU_authority\":false,\"guest_writes\":false}\n";
    capture.log.flush();
}
inline void entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) noexcept {
    if (!capture.enabled || !ctx || !runtime || ctx->pc != 0x19bbd0u)
        return;
    try {
        std::lock_guard<std::recursive_mutex> guard(capture.mutex);
        if (capture.calls >= MaxParents) {
            if (!capture.limitLogged) {
                capture.limitLogged = true;
                capture.log << "{\"kind\":\"parent-limit\",\"limit\":16,\"prior_observations_"
                               "retained\":true,\"GPU_authority\":false}\n";
                capture.log.flush();
            }
            return;
        }
        const uint32_t sp = reg(*ctx, 29);
        if (sp < 0xd0 || !range(sp - 0xd0, 0xd0))
            return;
        const uint32_t descriptor = reg(*ctx, 4);
        if (!range(descriptor, 0x180))
            return;
        if (auto* previous = find(runtime, ctx)) {
            refuse(*previous, "reentered-parent-frame");
            previous->live = false;
        }
        auto& c = capture.parents[capture.calls++];
        c.runtime = runtime;
        c.context = ctx;
        c.ordinal = capture.nextOrdinal++;
        c.frame = sp - 0x70;
        c.descriptor = descriptor;
        c.outerReturn = reg(*ctx, 31);
        c.live = true;
        snapshot(c, ram, ctx, Phase::Entry, "before");
    } catch (...) {
        capture.ioFailed = true;
    }
}
inline void allocated(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) noexcept {
    if (!capture.enabled)
        return;
    try {
        std::lock_guard<std::recursive_mutex> guard(capture.mutex);
        auto* c = find(runtime, ctx);
        if (!c || c->refused)
            return;
        if (c->allocated) {
            refuse(*c, "duplicate-allocator-continuation");
            return;
        }
        const uint32_t packet = reg(*ctx, 2);
        if ((packet & 15) || !range(packet, PacketBytes) || reg(*ctx, 18) != c->descriptor ||
            word(ram + c->frame + 0x30) != c->outerReturn) {
            refuse(*c, "allocator-return-join");
            return;
        }
        for (unsigned i = 0; i < capture.calls; ++i) {
            auto& old = capture.parents[i];
            if (&old != c && old.live && old.allocated && old.runtime == runtime &&
                overlap(packet, PacketBytes, old.packet, PacketBytes)) {
                refuse(old, "allocation-reused-before-parent-return");
                old.live = false;
            }
        }
        c->allocated = true;
        c->packet = packet;
        c->paletteMask = word(ram + c->descriptor + 0x54);
        snapshot(*c, ram, ctx, Phase::Allocated, "before-first-packet-write");
    } catch (...) {
        capture.ioFailed = true;
    }
}
inline void uniformBefore(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) noexcept {
    if (!capture.enabled)
        return;
    try {
        std::lock_guard<std::recursive_mutex> guard(capture.mutex);
        auto* c = find(runtime, ctx);
        if (!c || c->refused || !c->allocated || c->beforeUniform)
            return;
        c->beforeUniform = true;
        snapshot(*c, ram, ctx, Phase::UniformBefore, "before-three-mul-and-depth-div");
    } catch (...) {
        capture.ioFailed = true;
    }
}
inline void uniformAfter(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) noexcept {
    if (!capture.enabled)
        return;
    try {
        std::lock_guard<std::recursive_mutex> guard(capture.mutex);
        auto* c = find(runtime, ctx);
        if (!c || c->refused || !c->beforeUniform || c->afterUniform)
            return;
        c->afterUniform = true;
        snapshot(*c, ram, ctx, Phase::UniformAfter, "after-depth-and-uniform-writes");
    } catch (...) {
        capture.ioFailed = true;
    }
}
inline void before(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime, Phase phase) noexcept {
    if (!capture.enabled)
        return;
    try {
        std::lock_guard<std::recursive_mutex> guard(capture.mutex);
        auto* c = find(runtime, ctx);
        if (!c || c->refused || !c->allocated || !c->afterUniform)
            return;
        if (c->pendingCall) {
            refuse(*c, "uncaptured-callee-return");
            return;
        }
        const uint32_t expectedRA = phase == Phase::Palette    ? 0x19bd9c
                                    : phase == Phase::Copy3FC0 ? 0x19bdb4
                                    : phase == Phase::Light    ? 0x19be54
                                    : phase == Phase::Material ? 0x19be64
                                                               : 0;
        if (!expectedRA || reg(*ctx, 31) != expectedRA || reg(*ctx, 2) != c->packet) {
            refuse(*c, "callee-source-join");
            return;
        }
        if (phase == Phase::Palette) {
            const uint32_t bone = reg(*ctx, 8);
            if (bone >= 32 || !(c->paletteMask & (1u << bone)) || (c->paletteSeen & (1u << bone))) {
                refuse(*c, "palette-loop-identity");
                return;
            }
            c->bone = bone;
            c->paletteSeen |= 1u << bone;
        } else if (c->paletteReturned != c->paletteMask) {
            refuse(*c, "incomplete-selected-palette");
            return;
        }
        c->pending = phase;
        c->pendingReturn = expectedRA;
        c->pendingCall = true;
        snapshot(*c, ram, ctx, phase, "actual-post-delay-slot-callee-entry");
    } catch (...) {
        capture.ioFailed = true;
    }
}
inline void after(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime, Phase phase) noexcept {
    if (!capture.enabled)
        return;
    try {
        std::lock_guard<std::recursive_mutex> guard(capture.mutex);
        auto* c = find(runtime, ctx);
        if (!c || c->refused || !c->pendingCall)
            return; // Unselected bone jumps reach the same original label.
        if (c->pending != phase || ctx->pc != c->pendingReturn || reg(*ctx, 2) != c->packet) {
            refuse(*c, "callee-return-identity");
            return;
        }
        if (phase == Phase::Palette) {
            if (reg(*ctx, 8) != c->bone) {
                refuse(*c, "callee-bone-return");
                return;
            }
            c->paletteReturned |= 1u << c->bone;
        }
        if (phase == Phase::Copy3FC0)
            c->copyReturned = true;
        if (phase == Phase::Light)
            c->lightReturned = true;
        if (phase == Phase::Material)
            c->materialReturned = true;
        c->pendingCall = false;
        snapshot(*c, ram, ctx, phase, "original-callee-return");
    } catch (...) {
        capture.ioFailed = true;
    }
}
inline void returned(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) noexcept {
    if (!capture.enabled)
        return;
    try {
        std::lock_guard<std::recursive_mutex> guard(capture.mutex);
        auto* c = find(runtime, ctx, true);
        if (!c || c->refused)
            return;
        const bool full = ctx->pc == c->outerReturn && reg(*ctx, 2) == c->packet &&
                          !c->pendingCall && c->beforeUniform && c->afterUniform &&
                          c->paletteSeen == c->paletteMask &&
                          c->paletteReturned == c->paletteMask && c->copyReturned &&
                          c->lightReturned && c->materialReturned;
        if (!full) {
            refuse(*c, "incomplete-parent-return");
            c->live = false;
            return;
        }
        snapshot(*c, ram, ctx, Phase::Returned, "true-final-JR-after-delay-slot");
        if (c->refused || capture.ioFailed) {
            c->live = false;
            return;
        }
        c->complete = true;
        c->live = false;
        ++capture.completed;
        capture.log << "{\"kind\":\"complete-original-parent\",\"ordinal\":" << c->ordinal
                    << ",\"events\":" << c->events << ",\"packet\":" << c->packet
                    << ",\"mask\":" << c->paletteMask
                    << ",\"whole_parent_input_frontiers\":true,\"chronological_UNPACK_join\":false,"
                       "\"GPU_authority\":false}\n";
        capture.log.flush();
    } catch (...) {
        capture.ioFailed = true;
    }
}
inline bool open(const std::filesystem::path& directory) {
    if (capture.enabled || std::filesystem::exists(directory) ||
        !std::filesystem::create_directories(directory))
        return false;
    capture.directory = directory;
    capture.log.open(directory / "parent-frontiers.jsonl");
    if (!capture.log)
        return false;
    capture.enabled = true;
    return true;
}
} // namespace reo_palette_parent
