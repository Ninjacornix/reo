#include "scene_voice_preparation.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
SceneVoicePreparation::SceneVoicePreparation(gameplay_world::World& world,StreamChannels& channels,StreamBackend& backend,const std::optional<std::uint32_t>& tick)noexcept:world_(world),channels_(channels),backend_(backend),tick_(tick){}
StreamStatus SceneVoicePreparation::prepare(const CutsceneBatch& batch,bool playlist)noexcept{
    if(world_.closed())return StreamStatus::closed;
    if(!world_.scenario)return StreamStatus::unbound;
    if(!playlist){const auto asset=scene_voice_asset(*world_.scenario,batch.current);if(!asset)return StreamStatus::completed;if(!tick_)return StreamStatus::unbound;return channels_.prepare_start(1,asset->source,*tick_,backend_);}
    if(batch.audio_count>batch.audio_cues.size())return StreamStatus::unsupported_profile;
    if(!tick_)return StreamStatus::unbound;
    std::array<StreamCue,CutsceneRequests::capacity> cues;std::size_t count{};
    for(std::size_t i=0;i<batch.audio_count;++i){if(!world_.scenario)return StreamStatus::unbound;const auto asset=scene_voice_asset(*world_.scenario,batch.audio_cues[i]);if(asset)cues[count++]={asset->source,asset->basename};}
    return channels_.prepare_playlist(1,std::span(cues).first(count),*tick_,backend_);
}
}
