#pragma once
#include "reo_movie_game_addresses.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "compressed_movie_lineage.h"
#include <atomic>
#include <cstdio>
#include <cstdlib>

namespace reo_gpu_movie_transport {
using PictureHeader = void (*)(void*, PS2Runtime&, R5900Context&, uint32_t inner);
using RingReset = void (*)(void*, PS2Runtime&, uint32_t ring);
struct Binding {
    PS2Runtime* runtime = nullptr;
    reo_gpu_movie::OriginalCompressedLineage* lineage = nullptr;
    void* headerOwner = nullptr;
    PictureHeader pictureHeader = nullptr;
    RingReset ringReset = nullptr;
};
inline Binding binding;
// Original171920 is demux callback #1 (registered by FUN_001715f0 via 147F30): it runs when the demuxer reaches
// end of program. After it, the only further ES bytes are its 16-byte sequence-end marker. Serial lets a
// transport ignore ends that happened before it attached (consecutive movies can reuse the same work block).
inline std::atomic<uint64_t> demuxEndSerial{0};
inline std::atomic<uint32_t> demuxEndWork{0};
inline void demuxEnded(const uint8_t* ram, uint32_t sofdec) {
    uint32_t work = 0;
    try {
        work = reo_gpu_movie::OriginalCompressedLineage::canonical(
            reo_gpu_movie::OriginalCompressedLineage::read32(ram, sofdec + 0x1b30));
    } catch (...) {
        return;
    }
    demuxEndWork.store(work, std::memory_order_relaxed);
    const auto serial = demuxEndSerial.fetch_add(1, std::memory_order_release) + 1;
    const char* v = std::getenv("REO_GPU_MOVIE_LOG");
    if (v && *v && *v != '0')
        std::fprintf(stderr, "[GPU-MOVIE-EOF] demux-end work=%08x serial=%llu\n", work,
                     (unsigned long long)serial);
}
template <class Work> inline void metadata(PS2Runtime* runtime, const char* boundary, Work&& work) {
    if (binding.runtime != runtime)
        return;
    try {
        work();
    } catch (const std::exception& error) {
        const auto* log = std::getenv("REO_GPU_MOVIE_LOG");
        if (log && *log && *log != '0')
            std::fprintf(stderr, "[GPU-MOVIE] metadata-failure boundary=%s detail=%s\n", boundary,
                         error.what());
        runtime->requestStop();
        throw;
    } catch (...) {
        runtime->requestStop();
        throw;
    }
}
// Install before original movie initialization/first video packet. This
// records bounded compressed provenance only; native ownership is bound later
// at the actual outer quiescent player boundary.
bool install(PS2Runtime&, reo_gpu_movie::OriginalCompressedLineage&, void* headerOwner,
             PictureHeader, RingReset = nullptr);
inline void initialized(const uint8_t* ram, R5900Context*, PS2Runtime* runtime, uint32_t ring) {
    metadata(runtime, "initialized", [&] {
        if (binding.ringReset)
            binding.ringReset(binding.headerOwner, *runtime, ring);
        binding.lineage->initialized(ram, ring);
    });
}
inline void selected(const uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    metadata(runtime, "selected", [&] {
        if (GPR_U32(ctx, 31) == REO_MA(0x171978))
            binding.lineage->selectedEnd(ram, reinterpret_cast<uintptr_t>(ctx), GPR_U32(ctx, 29),
                                         GPR_U32(ctx, 4), GPR_U32(ctx, 5), GPR_U32(ctx, 6),
                                         GPR_U32(ctx, 31));
        else
            binding.lineage->selectedCopy(ram, reinterpret_cast<uintptr_t>(ctx), GPR_U32(ctx, 29),
                                          GPR_U32(ctx, 4), GPR_U32(ctx, 5), GPR_U32(ctx, 6),
                                          GPR_U32(ctx, 17), GPR_U32(ctx, 31));
    });
}
inline void committed(const uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime, uint32_t ring,
                      uint32_t bytes) {
    metadata(runtime, "committed", [&] {
        binding.lineage->committed(ram, reinterpret_cast<uintptr_t>(ctx), ring, bytes);
    });
}
inline void parsed(const uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    metadata(runtime, "parsed", [&] {
        binding.lineage->pesParsed(
            ram, GPR_U32(ctx, 11), GPR_U32(ctx, 12),
            reo_gpu_movie::OriginalCompressedLineage::read32(ram, GPR_U32(ctx, 14)));
    });
}
inline void selectedResult(const uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    if (ctx->pc == REO_MA(0x16ab1c))
        metadata(runtime, "selected-result", [&] {
            binding.lineage->selectedResult(ram, reinterpret_cast<uintptr_t>(ctx), GPR_U32(ctx, 29),
                                            GPR_U32(ctx, 2));
        });
}
inline void endPaddingPublished(const uint8_t* ram, R5900Context*, PS2Runtime* runtime,
                                uint32_t ring) {
    metadata(runtime, "end-padding", [&] { binding.lineage->endPaddingPublished(ram, ring); });
}
} // namespace reo_gpu_movie_transport
