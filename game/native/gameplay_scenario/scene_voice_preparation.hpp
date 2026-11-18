#pragma once
#include "scene_voice_assets.hpp"
#include <optional>
namespace reo::native::gameplay_scenario {
// Borrows the existing World/session and stream controller. No second clock,
// Instances owner, decoder, logical channel record or asset lookup table.
class SceneVoicePreparation final {
public:
    SceneVoicePreparation(gameplay_world::World&,StreamChannels&,StreamBackend&,const std::optional<std::uint32_t>& audio_tick)noexcept;
    StreamStatus prepare(const CutsceneBatch&,bool playlist)noexcept;
private:
    gameplay_world::World& world_;StreamChannels& channels_;StreamBackend& backend_;const std::optional<std::uint32_t>& tick_;
};
}
