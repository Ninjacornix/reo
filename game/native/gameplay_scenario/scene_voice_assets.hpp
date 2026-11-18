#pragma once
#include "cutscene_cues.hpp"
#include "stream_channels.hpp"
#include <span>
#include <string_view>
namespace reo::native::gameplay_scenario {
struct SceneVoiceAsset {
    std::uint16_t scenario{};
    CutsceneCue cue;
    std::string_view key,basename;
    StreamRequest source;
};
// Complete owned6D7520 name policy; source identifies the already indexed
// native archive/member. This grants no file access or decoder ownership.
std::span<const SceneVoiceAsset> scene_voice_assets()noexcept;
const SceneVoiceAsset* scene_voice_asset(std::uint16_t scenario,std::string_view key)noexcept;
const SceneVoiceAsset* scene_voice_asset(std::uint16_t scenario,CutsceneCue)noexcept;
}
