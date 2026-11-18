#include "scene_voice_assets.hpp"
namespace reo::native::gameplay_scenario {
namespace {
constexpr SceneVoiceAsset assets[]{
#include "scene_voice_profile.inc"
};
}
std::span<const SceneVoiceAsset> scene_voice_assets()noexcept{return assets;}
const SceneVoiceAsset* scene_voice_asset(std::uint16_t scenario,std::string_view key)noexcept{
    for(const auto& asset:assets)if(asset.scenario==scenario&&asset.key==key)return &asset;
    return nullptr;
}
const SceneVoiceAsset* scene_voice_asset(std::uint16_t scenario,CutsceneCue cue)noexcept{
    for(const auto& asset:assets)if(asset.scenario==scenario&&asset.cue.area==cue.area&&asset.cue.scene==cue.scene&&asset.cue.variant==cue.variant)return &asset;
    return nullptr;
}
}
