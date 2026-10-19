#pragma once
#include <cstdint>
namespace reo_gpu_static_consumer {
inline constexpr uint32_t Magic = 0x53544331u, Version = 1u;
enum Word : uint32_t {
    Sticky = 0,
    Ready = 1,
    TriangleSlots = 2,
    EventCount = 3,
    Generation = 4,
    JobOrdinal = 5,
    MagicWord = 6,
    VersionWord = 7,
    Validated = 8,
    Committed = 9,
    PublicationReady = 10,
    PrefixBase = 16
};
inline constexpr uint32_t MaxEvents = 495, FinalQueueBase = 1008, FinalQueueWords = 40,
                          Words = FinalQueueBase + FinalQueueWords;
// GPU-only final semantic GS queue: Ready,rawPRIM,count,magic then three
// rawSTQ/RGBA/XYZ records in original queue order. Diagnostic fixture may read
// after completion; ordinary routing must keep this queue GPU authoritative.
// Producer's authoritative export must require matching magic/version,
// generation/job ordinal, Ready1, and zero consumer/tape/global sticky.
// Successful authoritative export writes Committed9=1 only after copying.
// Publication gate runs after ALL exports and writes PublicationReady10.
} // namespace reo_gpu_static_consumer
