#pragma once
#include <array>
#include <cstdint>
namespace reo_gpu_batched_stream_consumer {
constexpr uint32_t MaxJobs = 128, MaxRawVertices = 247, MaxTriangles = 11 * MaxRawVertices;
constexpr uint32_t TapeWords = 65536, NativeUvec4 = 32768, CertificateWords = 1048;
constexpr uint32_t QueueWord = 1008, ParameterWords = 112, OutputAlignment = 256;
constexpr uint32_t ABI = 0x42534331u, Version = 1;
constexpr uint32_t aligned(uint32_t bytes) {
    return (bytes + OutputAlignment - 1) / OutputAlignment * OutputAlignment;
}
constexpr uint32_t PositionStrideBytes = aligned(MaxTriangles * 48),
                   AttributeStrideBytes = aligned(MaxTriangles * 72),
                   PrimitiveStrideBytes = aligned(MaxTriangles * 32);
static_assert(PositionStrideBytes == 130560 && AttributeStrideBytes == 195840 &&
              PrimitiveStrideBytes == 87040);
struct Push {
    uint32_t jobs, capacityJobs, maximumTriangleSlots, generation;
};
static_assert(sizeof(Push) == 16);
struct alignas(16) JobParameters {
    // Identical128-byte Parameters prefix: limits/identity/mainTag/geometry,
    // offset+scissor and8 material words. No derived vertices or draw counts.
    std::array<uint32_t, 32> fixed{};
    // kindHint,requestedEntry,jobs,reserved0,ABI,version,EchoWords64,reserved0.
    std::array<uint32_t, 8> source{};
    // Immutable raw command Echo copied from the typed source tape, not readback.
    std::array<uint32_t, 64> echo{};
    std::array<uint32_t, 8> reserved{};
};
static_assert(sizeof(JobParameters) == 448);
constexpr std::array<uint64_t, 5> outputBytes(uint32_t jobs) {
    return {uint64_t(jobs) * PositionStrideBytes, uint64_t(jobs) * AttributeStrideBytes,
            uint64_t(jobs) * PrimitiveStrideBytes, uint64_t(jobs) * CertificateWords * 4,
            uint64_t(jobs) * ParameterWords * 4};
}
// Geometry buffers use these padded offsets, not11N byte strides. GS chunk
// offsets add256 triangles and retain256-byte storage-view alignment.
constexpr uint64_t positionOffset(uint32_t job, uint32_t chunk) {
    return uint64_t(job) * PositionStrideBytes + uint64_t(chunk) * 256 * 48;
}
constexpr uint64_t attributeOffset(uint32_t job, uint32_t chunk) {
    return uint64_t(job) * AttributeStrideBytes + uint64_t(chunk) * 256 * 72;
}
constexpr uint64_t primitiveOffset(uint32_t job, uint32_t chunk) {
    return uint64_t(job) * PrimitiveStrideBytes + uint64_t(chunk) * 256 * 32;
}
constexpr uint64_t certificateOffset(uint32_t job) {
    return uint64_t(job) * CertificateWords * 4;
}
} // namespace reo_gpu_batched_stream_consumer
