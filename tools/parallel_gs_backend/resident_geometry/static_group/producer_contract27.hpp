#pragma once
#include <array>
#include <cstdint>
namespace reo_gpu_static_group {
constexpr std::array<const char*, 27> StageNames = {
    "validate_header",    "validate_records", "validate_seal",       "provenance_clear",
    "provenance_scatter", "raw_snapshots",    "classify_candidates", "classify_scan",
    "possible_clear",     "possible_scatter", "classify_guards",     "classify_decide",
    "static_prefix",      "static_geometry",  "point_routes",        "history_repair",
    "prefetch_repair",    "static_clip",      "static_compose",      "carry_prepare",
    "carry_scan",         "carry_emit",       "carry_seal",          "graphics_clear",
    "graphics_scatter",   "resolve_banks",    "whole_group_fallback"};
constexpr std::array<const char*, 27> StageHashes = {
    "4074787242b4bba3600d109285c7c1c8ec84063440867d4909dec0febe1707d4",
    "e3558af40affb5e0187583fe9c3c36636d600329d2b6b3f941da776bb0969eb5",
    "36d80de6d48bc8ccf0d94edc168a3e78e90c35dac659a5d0fd77611433c9670d",
    "ebed8ef45bcf3869c9e8524515edd395352501176617e4b49f14b87552e0ef95",
    "db33bbb1cd429562bd63f3bf6bd3bbe87911126fcf1cf242d577e6d3408c5b59",
    "3050fcfe1cf8fe6d3a6d17c28ff5317648b0a329d8748301acc1d70a19ba5dce",
    "aba6474df7ef02d042fda7150b1e909270990efaae890993824a26ee5d88cbf7",
    "562455b2b843a75ddb5813c85a7a5b189c34e089cd3bb2c74a87d61eb86b73d2",
    "6c1faa8ff64fc6f3f34f1b4b5f71c01053f94bd045086d4ec838d68baa306f53",
    "102e7fe3eda86cbf6314de32b2a665dd06e80d26a7b02cff08dcf798d68b8d7a",
    "7fa5fe9ee3d9f837f87b618fc0f67b91129c324fcf0bd6fc423e2c7ba9face6b",
    "457fa494ffae543a1105705974f6a9a3496afd8fc9d18e4a67462d2319547448",
    "1cc99cb0b59f9477848e3642a3543cd6a548befa259ff291a542c195cd4ec6e3",
    "c4730a9f5f51e1376b6d724432381ea7dd73b08f2ec63e5a90f05d3b621f1bbb",
    "315a1d363b706f0f6763866846c2b3610b490aa193fddac05a88172f63941795",
    "3b8b229b9ec21b61986c41fb21a6eda09c65e3e6829114c3f076408c6f901e1d",
    "42f347dbee55dc1c80a267541a3125ea44bdab2deaef429331485dc45496aac6",
    "3db9c3369dafbeef39739f61498ee88a4f78375b17b4cd39549ecbec450fea6b",
    "652bb5ac939b8803814ecda13b859cdef68c12c16674cf89b73afb5eb05753dd",
    "a2d950a5269320bcb9279a91a266a658de4ff3f4efd69208b8c4aabe6a9da45b",
    "8b01413d10605cb9aa5959e07c215ca33da79c70b5ff4d619744dfa80aa092e0",
    "a3437f1847c39ffdd3d74c2dca4cbfc07ea146b38dfde7b18a5f7bae609b7ca6",
    "a91d0ecb63e4663ccde03963d18d02316e9fc94cf85b4b5053486d912d5b3b42",
    "36e778639ca07aa5c18a3977ae9c0b44ac6c72e3e5f90ec1a66407a040f42523",
    "5e797ee53e4a2d3d1b3bf09e5e0c3e83454cbee67873c6dfbb61e99af03718ac",
    "8444fe02b2123fe8d8863123a736471dce165df620ef53fc2088692c075dbe18",
    "5332b606f6c1ed36eee8c2becbaf70ca7a1ffa70aa3c8c23288211984e21b227"};
inline uint32_t grid(uint32_t stage, uint32_t jobs, uint32_t raw) {
    switch (stage) {
        case 0:
        case 2:
        case 7:
        case 11:
        case 22:
        case 26:
            return 1;
        case 1:
            return ((raw > jobs ? raw : jobs) + 63u) >> 6u;
        case 3:
        case 8:
            return 8192;
        case 4:
            return (raw + 63u) / 64u ? (raw + 63u) / 64u : 1u;
        case 5:
            return 16 * (jobs + 1);
        case 17:
            return 50 * jobs;
        case 20:
            return 158;
        case 23:
            return 32768;
        case 24:
            return 64 * jobs;
        case 25:
            return 64 * (jobs + 1);
        default:
            return jobs;
    }
}
struct LiveProofs {
    bool literalTypedVif = false, fullCarriedState = false, orderedMultiEffects = false;
    bool groupedConsumerAndAuthority = false, mixedMaterialPreview = false,
         frontendTailOwnership = false;
    bool realProducerFence = false, completeRegistry = false;
    constexpr bool complete() const {
        return literalTypedVif && fullCarriedState && orderedMultiEffects &&
               groupedConsumerAndAuthority && mixedMaterialPreview && frontendTailOwnership &&
               realProducerFence && completeRegistry;
    }
};
enum class Scope { OfflineDerivedComponent, ScopedLive };
} // namespace reo_gpu_static_group
