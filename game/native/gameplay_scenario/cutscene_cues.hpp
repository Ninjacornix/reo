#pragma once
#include "cutscene_requests.hpp"

namespace reo::native::gameplay_scenario {
class FlagState;

struct CutsceneCue {
    std::uint8_t area{}, scene{}, variant{};
};

struct CutsceneBatch {
    std::uint8_t mode{}, selector{};
    std::uint16_t actor_selection{};
    CutsceneCue current;
    std::array<CutsceneCue,CutsceneRequests::capacity> audio_cues{};
    std::size_t audio_count{};
};

// Prepare a batch on the simulation thread. If a selector references missing
// actor or flag state, the request queue is preserved for the caller.
std::optional<CutsceneBatch> collect_cutscene_cues(gameplay_world::World&,const FlagState&) noexcept;
}
