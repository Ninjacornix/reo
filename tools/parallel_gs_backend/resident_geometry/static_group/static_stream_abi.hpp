#pragma once
#include <cstdint>
#include <array>
namespace reo_gpu_static_stream {
inline constexpr std::uint32_t Magic = 0x53535431u, Version = 1, Binding = 0x5273fa3eu;
inline constexpr std::uint32_t MaxJobs = 128, MaxRawWrites = 32768, MaxPairs = 65536;
inline constexpr std::uint32_t HeaderWords = 16, JobWords = 16, RawWords = 8, EchoWords = 64;
enum class SourceClass : std::uint32_t { DerivedControl = 1, LiteralTypedVIF = 2 };
enum class RawKind : std::uint32_t { AlignedQword = 1, VIFV432Mode0 = 2 };
enum class KindHint : std::uint32_t { Init = 0, Geometry = 1, AD6 = 2 };
enum class Operation : std::uint32_t { MSCAL = 0, MSCNT = 4 };
struct Header {
    std::uint32_t magic = Magic, version = Version, jobs = 0, rawWrites = 0;
    std::uint32_t jobOffset = HeaderWords, rawOffset = 0, payloadOffset = 0, payloadWords = 0;
    std::uint32_t echoOffset = 0, echoWords = 0, totalWords = 0, generation = 1;
    std::uint32_t sourceClass = std::uint32_t(SourceClass::DerivedControl), binding = Binding,
                  maxPairs = MaxPairs, reserved = 0;
};
struct Job {
    std::uint32_t entryPC = 0, operation = 0, TOP = 0, ITOP = 0;
    std::uint32_t rawBegin = 0, rawEnd = 0, echoOffset = 0, eventCapacity = 495;
    std::uint32_t nativeCapacity = 3213, ordinal = 0, materialEpoch = 0, kindHint = 0;
    std::array<std::uint32_t, 4> reserved{};
};
struct Raw {
    std::uint32_t beforeJob = 0, qword = 0, componentMask = 15, payloadOffset = 0;
    std::uint32_t kind = std::uint32_t(RawKind::AlignedQword), ordinal = 0, reserved0 = 0,
                  reserved1 = 0;
};
static_assert(sizeof(Header) == 64 && sizeof(Job) == 64 && sizeof(Raw) == 32);
// Immutable binding6 packs Header/jobs/raw descriptors/payload/echo regions.
// Raw payloadOffset is relative to Header.payloadOffset. Echo offsets absolute.
// Every raw record carries four payload words even when its component mask is
// partial. beforeJob is0..jobs: records apply BEFORE that call; jobs is final
// raw memory updates after all calls and before final authority publication.
// rawBegin/rawEnd identify records applied immediately before this call and
// are contiguous, ordered, and exclusive-end. No per-job VF/register snapshots.
// Echo64 is the existing {kind,count,0,0,7rawQwords,zero padding} command echo.
// MSCNT entryPC is diagnostic metadata only; actual PC derives from GPU state.
} // namespace reo_gpu_static_stream
