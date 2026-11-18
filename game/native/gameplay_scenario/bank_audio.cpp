#include "bank_audio.hpp"
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
#include "scene_audio_profile.inc"
}
std::optional<std::uint8_t> scene_sound_offset(std::uint16_t scenario,std::uint8_t resource)noexcept{
    if(scenario>=scene_audio_scenarios.size()||resource>=10)return{};
    return scene_audio_offsets[scene_audio_scenarios[scenario]][resource];
}
SceneBankAudio::SceneBankAudio(gameplay_world::World& world,gameplay_audio::Owner& owner,const gameplay_audio::SpatialContext& spatial)
    :world_(world),owner_(owner),spatial_(spatial){
    if(world_.closed()||!owner_.bound_to(world_.session().random))throw std::invalid_argument("Native scene audio requires the canonical World/bank owner");
}
bool SceneBankAudio::admitted()const noexcept{
    return !world_.closed()&&owner_.bound_to(world_.session().random)&&world_.session().scenario&&*world_.session().scenario<42;
}
bool SceneBankAudio::emit(transform_math::Vector point,std::uint8_t resource,std::uint16_t event){
    last_.reset();
    if(!admitted())return false;
    const auto offset=scene_sound_offset(*world_.session().scenario,resource);
    if(!offset)return false;
    // Source combines these bit fields with OR, not addition, and selects
    // attenuation2. A rejected ordinary bank command does not rewind playback.
    const auto cue=std::uint32_t(event)|*offset;
    last_=owner_.positional({1,cue},point,spatial_,2);
    return last_->status!=gameplay_audio::Status::numeric_domain;
}
}
