#pragma once
// Bounded, opt-in observations of original guest chain construction. Every
// wrapper delegates its original compiled body once; no tag/IRQ/count repair.
#include <array>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <stdexcept>

extern void sub_0018C730_0x18c730(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_0018C7C0_0x18c7c0(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_00189B08_0x189b08(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_0018CFB0_0x18cfb0(uint8_t*, R5900Context*, PS2Runtime*);

namespace reo_dma_builder_observer {
inline FILE* file = nullptr;
inline uint32_t first = 0, bytes = 0, sequence = 0, watch = 0;
inline bool configured = false;
inline bool configure() {
    if (configured)
        return file != nullptr;
    configured = true;
    const char* path = std::getenv("REO_DMA_BUILD_TRACE_FILE");
    if (!path || !*path)
        return false;
    const char *start = std::getenv("REO_DMA_BUILD_TRACE_BASE"),
               *size = std::getenv("REO_DMA_BUILD_TRACE_BYTES");
    if (!start || !size)
        throw std::invalid_argument("DMA builder trace needs explicit bounds");
    first = uint32_t(std::strtoul(start, nullptr, 0));
    bytes = uint32_t(std::strtoul(size, nullptr, 0));
    const char* watched = std::getenv("REO_DMA_BUILD_TRACE_WATCH");
    watch = watched ? uint32_t(std::strtoul(watched, nullptr, 0)) : first;
    if (!bytes || bytes > 65536u || first >= PS2_RAM_SIZE || bytes > PS2_RAM_SIZE - first)
        throw std::invalid_argument("DMA builder trace outside guest RAM");
    if (watch >= PS2_RAM_SIZE || 32u > PS2_RAM_SIZE - watch)
        throw std::invalid_argument("DMA builder watch outside guest RAM");
    if (std::filesystem::exists(path))
        throw std::runtime_error("Preserve prior DMA builder trace");
    file = std::fopen(path, "wb");
    if (!file)
        throw std::runtime_error("Cannot open DMA builder trace");
    return true;
}
inline bool overlaps(uint32_t address, uint64_t length) {
    address &= PS2_RAM_MASK;
    return length && uint64_t(address) + length > first && address < uint64_t(first) + bytes;
}
inline void record(const char* operation, const char* phase, uint8_t* ram, R5900Context* ctx,
                   const std::array<uint32_t, 5>& args, uint32_t address) {
    if (!file || sequence >= 4096u)
        return;
    address &= PS2_RAM_MASK;
    uint32_t words[8]{};
    if (address < PS2_RAM_SIZE && sizeof(words) <= PS2_RAM_SIZE - address)
        std::memcpy(words, ram + address, sizeof(words));
    uint32_t watched[8]{};
    std::memcpy(watched, ram + watch, sizeof(watched));
    std::fprintf(file,
                 "{\"seq\":%u,\"operation\":\"%s\",\"phase\":\"%s\",\"pc\":%u,\"ra\":%u,\"args\":[%"
                 "u,%u,%u,%u,%u],\"address\":%u,\"words\":[%u,%u,%u,%u,%u,%u,%u,%u],\"watch\":%u,"
                 "\"watch_words\":[%u,%u,%u,%u,%u,%u,%u,%u]}\n",
                 sequence++, operation, phase, ctx->pc, GPR_U32(ctx, 31), args[0], args[1], args[2],
                 args[3], args[4], address, words[0], words[1], words[2], words[3], words[4],
                 words[5], words[6], words[7], watch, watched[0], watched[1], watched[2],
                 watched[3], watched[4], watched[5], watched[6], watched[7]);
    std::fflush(file);
}
template <auto Original, unsigned Kind>
void observe(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    const std::array<uint32_t, 5> args{GPR_U32(ctx, 4), GPR_U32(ctx, 5), GPR_U32(ctx, 6),
                                       GPR_U32(ctx, 7), GPR_U32(ctx, 31)};
    const uint32_t address = Kind == 2 ? args[1] : Kind == 3 ? args[2] : args[0];
    const uint64_t length = Kind == 2 ? uint64_t(args[2]) * 16u : 32u;
    const bool selected = overlaps(address, length);
    constexpr const char* names[]{"CALL", "END", "QWC_COPY", "ENQUEUE"};
    if (selected)
        record(names[Kind], "before", ram, ctx, args, address);
    if constexpr (Kind == 2) {
        if (selected && length >= 32u && uint64_t(args[0] & PS2_RAM_MASK) + length <= PS2_RAM_SIZE)
            record("QWC_SOURCE_END", "before", ram, ctx, args,
                   (args[0] & PS2_RAM_MASK) + uint32_t(length) - 32u);
    }
    Original(ram, ctx, runtime);
    if (selected)
        record(names[Kind], "returned", ram, ctx, args, address);
}
inline auto call = observe<&sub_0018C730_0x18c730, 0>;
inline auto end = observe<&sub_0018C7C0_0x18c7c0, 1>;
inline auto copy = observe<&sub_00189B08_0x189b08, 2>;
inline auto enqueue = observe<&sub_0018CFB0_0x18cfb0, 3>;
} // namespace reo_dma_builder_observer
