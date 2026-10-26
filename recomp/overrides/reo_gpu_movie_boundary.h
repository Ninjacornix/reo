#pragma once
#include "reo_movie_game_addresses.h"
// Narrow original libmpeg picture boundary. Read-only transport metadata;
// this does not decode pixels, alter guest state, or fake movie completion.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <array>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>

namespace reo_movie_entry {
using GuestFunction = void (*)(uint8_t*, R5900Context*, PS2Runtime*);
struct Metadata {
    uint32_t outer = 0, inner = 0, destination = 0, macroblocks = 0, returnAddress = 0;
    uint32_t sofdec = 0, work = 0, expectedOuter = 0, compressedRing = 0;
    std::array<uint32_t, 22> ringWords{};
    bool outerSupported = false, innerSupported = false, workSupported = false;
    // Named only by proven original offsets; interpretation comes from the
    // original instruction trace rather than synthetic completion flags.
    std::array<uint32_t, 22> words{};
    std::array<std::array<uint32_t, 3>, 4> callbacks{}; // entry, userdata, GP
};
inline constexpr std::array<uint32_t, 22> Offsets{
    0x00, 0x04,  0x08,  0xAC,  0xB0,  0xB4,  0xC8,  0xEC,  0xF0,  0xF4,  0xF8,
    0xFC, 0x130, 0x138, 0x18C, 0x1D8, 0x1E8, 0x1F8, 0x838, 0x860, 0x870, 0x10A0};
inline constexpr std::array<uint32_t, 22> RingOffsets{
    0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28,
    0x2C, 0x30, 0x34, 0x38, 0x3C, 0x40, 0x44, 0x48, 0x4C, 0x50, 0x54};
inline std::atomic<unsigned> metadataReads{0}, metadataCaptures{0};
// Only documented main-RDRAM address classes: physical RAM, the game's
// uncached20000000 alias, and direct KSEG0/KSEG1 RAM aliases. SPR70000000,
// MMIO10000000, other TLB windows, and wraparound ranges are not RAM here.
inline bool resolveRam(uint32_t address, uint32_t bytes, uint32_t& physical) {
    const uint32_t bank = address & 0xFE000000u;
    if (bank != 0u && bank != 0x20000000u && bank != 0x80000000u && bank != 0xA0000000u)
        return false;
    physical = address & 0x1FFFFFFu;
    return bytes <= 0x2000000u && physical <= 0x2000000u - bytes;
}
inline uint32_t word(const uint8_t* ram, uint32_t address) {
    uint32_t p = 0;
    if (!ram || !resolveRam(address, 4, p))
        return 0;
    metadataReads.fetch_add(1, std::memory_order_relaxed);
    uint32_t v = 0;
    std::memcpy(&v, ram + p, 4);
    return v;
}
inline bool span(uint32_t address, uint32_t bytes) {
    uint32_t p = 0;
    return resolveRam(address, bytes, p) && p;
}
inline bool sameRam(uint32_t a, uint32_t b) {
    uint32_t x = 0, y = 0;
    return resolveRam(a, 4, x) && resolveRam(b, 4, y) && x == y;
}
inline Metadata capture(const uint8_t* ram, const R5900Context* c) {
    metadataCaptures.fetch_add(1, std::memory_order_relaxed);
    Metadata m;
    m.outer = GPR_U32(c, 4);
    m.destination = GPR_U32(c, 5);
    m.macroblocks = GPR_U32(c, 6);
    m.returnAddress = GPR_U32(c, 31);
    m.outerSupported = span(m.outer, 0x44);
    if (m.outerSupported)
        m.inner = word(ram, m.outer + 0x40);
    m.innerSupported = span(m.inner, 0x10A4);
    if (m.innerSupported) {
        for (size_t i = 0; i < Offsets.size(); ++i)
            m.words[i] = word(ram, m.inner + Offsets[i]);
        for (unsigned i = 0; i < 4; ++i)
            for (unsigned j = 0; j < 3; ++j)
                m.callbacks[i][j] = word(ram, m.inner + 0xC + 12 * i + 4 * j);
    }
    m.sofdec = word(ram, REO_MA(0x22F18C));
    if (span(m.sofdec, 0x1B34))
        m.work = word(ram, m.sofdec + 0x1B30);
    m.workSupported = span(m.work, 0xAA0);
    if (m.workSupported) {
        m.expectedOuter = m.work + 0xA00;
        // Proven compressed IPU1/B400 ring:171630/171768 -> work+A48;
        //170AE8 initializes base/tag/capacity;171160 submits its DMA chain.
        m.compressedRing = m.work + 0xA48;
        for (size_t i = 0; i < RingOffsets.size(); ++i)
            m.ringWords[i] = word(ram, m.compressedRing + RingOffsets[i]);
    }
    return m;
}
inline GuestFunction originals[2]{};
inline std::atomic<unsigned> entries{0};
template <unsigned Kind> void picture(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    constexpr uint32_t entry = Kind == 0 ? REO_MA(0x147D30u) : REO_MA(0x147D78u);
    auto original = originals[Kind];
    if (!original) {
        std::fprintf(stderr, "[GPU-MOVIE-BOUNDARY] missing original entry\n");
        std::terminate();
    }
    // A merged continuation must retain its original implementation and stack.
    if (ctx->pc != entry) {
        original(ram, ctx, rt);
        return;
    }
    if (entries.load(std::memory_order_relaxed) >= 24) {
        original(ram, ctx, rt);
        return;
    }
    const unsigned n = entries.fetch_add(1, std::memory_order_relaxed);
    if (n >= 24) {
        original(ram, ctx, rt);
        return;
    } // Bound reads, not only logs.
    const auto before = capture(ram, ctx);
    // No replacement yet: the original graphics path remains transitional.
    original(ram, ctx, rt);
    std::fprintf(stderr,
                 "[GPU-MOVIE-BOUNDARY] n=%u entry=%08x ra=%08x pc=%08x completed=%u result=%08x "
                 "outer=%08x inner=%08x destination=%08x macroblocks=%u sofdec=%08x work=%08x "
                 "expected_outer=%08x match=%u pointer_classes=%u,%u,%u\n",
                 n, entry, before.returnAddress, ctx->pc, unsigned(ctx->pc == before.returnAddress),
                 GPR_U32(ctx, 2), before.outer, before.inner, before.destination,
                 before.macroblocks, before.sofdec, before.work, before.expectedOuter,
                 unsigned(before.outerSupported && before.workSupported &&
                          sameRam(before.outer, before.expectedOuter)),
                 unsigned(before.outerSupported), unsigned(before.innerSupported),
                 unsigned(before.workSupported));
    for (size_t i = 0; i < Offsets.size(); ++i)
        std::fprintf(stderr, "[GPU-MOVIE-BOUNDARY] n=%u offset=%03x before=%08x after=%08x\n", n,
                     Offsets[i], before.words[i],
                     before.innerSupported ? word(ram, before.inner + Offsets[i]) : 0);
    for (unsigned i = 0; i < 4; ++i)
        std::fprintf(stderr,
                     "[GPU-MOVIE-BOUNDARY] n=%u callback=%u entry=%08x userdata=%08x gp=%08x\n", n,
                     i, before.callbacks[i][0], before.callbacks[i][1], before.callbacks[i][2]);
    std::fprintf(stderr,
                 "[GPU-MOVIE-TRANSPORT] n=%u ring=%08x base=%08x dma_tags=%08x capacity_chunks=%u "
                 "capacity_bytes=%u\n",
                 n, before.compressedRing, before.ringWords[0], before.ringWords[1],
                 before.ringWords[2], before.ringWords[6]);
    for (size_t i = 0; i < RingOffsets.size(); ++i)
        std::fprintf(stderr, "[GPU-MOVIE-TRANSPORT] n=%u offset=%02x before=%08x after=%08x\n", n,
                     RingOffsets[i], before.ringWords[i],
                     before.compressedRing ? word(ram, before.compressedRing + RingOffsets[i]) : 0);
}
inline bool install(PS2Runtime& rt) {
    const char* env = std::getenv("REO_GPU_MOVIE_BOUNDARY_DIAG");
    if (!env || env[0] != '1')
        return false;
    // Requires the real original generated registration first. Do not bind to
    // sceMpeg stubs; natural execution currently uses these original entries.
    auto first = rt.lookupFunction(REO_MA(0x147D30u)), second = rt.lookupFunction(REO_MA(0x147D78u));
    if (!first || !second || first == picture<0> || second == picture<1>)
        return false;
    originals[0] = first;
    originals[1] = second;
    entries.store(0, std::memory_order_relaxed);
    metadataReads.store(0, std::memory_order_relaxed);
    metadataCaptures.store(0, std::memory_order_relaxed);
    rt.registerFunction(REO_MA(0x147D30u), picture<0>);
    rt.registerFunction(REO_MA(0x147D78u), picture<1>);
    std::fprintf(stderr, "[GPU-MOVIE-BOUNDARY] enabled original147d30/147d78 observer; metadata "
                         "only; limit24; no replacement/completion writes\n");
    return true;
}
} // namespace reo_movie_entry
