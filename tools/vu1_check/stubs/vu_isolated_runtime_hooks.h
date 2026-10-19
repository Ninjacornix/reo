#pragma once
// Include only in the SINGLE entrypoint TU of a direct-VU isolated executable.
// Full-runtime/profile harnesses must use the real ps2_runtime definitions.
#include <cstdint>
#include "vu_program_collection.h"
#include "vif_launch_overhead.h"
bool ps2VifKickVuProfileActive() noexcept {
    return false;
}
void ps2VifKickVuProfileRecord(uint64_t, uint32_t, bool) noexcept {}
void ps2VifKickStageRecord(unsigned, uint64_t, uint64_t, uint64_t) noexcept {}
void ps2VifKickVuSpecializedRecord(bool, uint64_t, uint64_t) noexcept {}
void ps2VifKickVuNativeGeometryRecord(uint64_t, uint64_t, uint64_t) noexcept {}
void ps2VifKickVuNativeGeometryTimingRecord(uint64_t, uint64_t) noexcept {}
namespace vu_program_collection {
void recordLaunch(const void*, const uint8_t*, uint32_t, uint32_t, uint32_t, uint32_t) noexcept {}
} // namespace vu_program_collection
namespace vif_launch_overhead {
bool active() noexcept {
    return false;
}
void recordProgramObserver(uint64_t) noexcept {}
} // namespace vif_launch_overhead
namespace reo_resident_live {
// Replay diagnostics observe execution; they do not participate in numerical
// semantics. The standalone reference has its own retained packet/state output.
void recordReplayKick(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, bool) {}
void recordReplayFinish(uint32_t, uint32_t, const VU1State&, bool, bool) {}
} // namespace reo_resident_live
