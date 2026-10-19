#pragma once
#include <cstdint>
namespace reo_gpu_static_stream_export {
inline constexpr uint32_t Family = 0x5273fa3eu, StreamMagic = 0x53535431u, CertMagic = 0x53544331u,
                          CertVersion = 1;
inline constexpr uint32_t MaxJobs = 128, StateStride = 576, DataStride = 8192, TapeStride = 65536,
                          CertWords = 1048;
inline constexpr uint32_t StateSeed = MaxJobs * StateStride, DataSeed = MaxJobs * DataStride,
                          DataFinal = DataSeed + 4096;
struct Push {
    uint32_t jobs = 0, capacity = 0, generation = 0, reserved = 0;
};
static_assert(sizeof(Push) == 16);
// Bindings:0producer State uint,1producer Data uint,2all Tape uint,3Results
// uint,4packed cert uvec4 (262/job),5authority State158uint,6authority Data
//4096uint,7authority Completion12uint. All fields are raw binary words.
// Source/consumer must finish ALL jobs before admission dispatch1, barrier,
// commit dispatch1, barrier, GPUcopy aggregate certs to their original slices,
// then ALL publication. No intermediate authority exports.
// Global result10=all-job admission,11=complete final authority commit.
// Completion0..7 copies last actual result receipt;8shared first sticky.
// Completion9StreamMagic/10Mode/11jobs are labeled private diagnostic fields.
} // namespace reo_gpu_static_stream_export
