#include "actor_voice_requests.hpp"
namespace reo::native::gameplay_world {
ActorVoiceRequests::ActorVoiceRequests(World& world,gameplay_scenario::StreamChannels& channels,
    gameplay_scenario::StreamBackend& backend,const gameplay_audio::SpatialContext& spatial,
    const std::optional<std::uint32_t>& tick)noexcept:
    world_(world),channels_(channels),backend_(backend),spatial_(spatial),tick_(tick){}
bool ActorVoiceRequests::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
ActorVoiceResult ActorVoiceRequests::request(const actors::EntityId& id,std::int32_t member)noexcept{
    using S=gameplay_scenario::StreamStatus;
    if(world_.closed())return{S::closed,-1};
    if(member<0)return{};
    const auto actor=world_.resolve(id);if(!actor)return{S::unsupported_profile,-1};
    if(actor->category||actor->slot>=5)return{S::unsupported_profile,-1};
    const auto marker=backend_.actor_archive_marker(actor->slot);
    if(!gameplay_scenario::stream_accepted(marker.status))return{marker.status,-1};
    if(!marker.value)return{};
    if(marker.value<0||marker.value>8)return{S::unsupported_profile,-1};
    const auto phase=backend_.phase(2);
    if(!gameplay_scenario::stream_accepted(phase.status))return{phase.status,-1};
    if(phase.value==1||phase.value==2)return{phase.status,-1};
    if(!tick_)return{S::unbound,-1};
    const auto source=backend_.actor_voice_source(actor->slot,member);
    if(!gameplay_scenario::stream_accepted(source.status))return{source.status,-1};
    const auto started=channels_.request(2,source.source.member,std::int32_t(source.source.archive),*tick_,backend_);
    if(!gameplay_scenario::stream_accepted(started.status))return{started.status,0};
    if(started.original_return)return{started.status,0};
    // Owned234BF4 points to234890, the already qualified falling profile1/2.
    const auto volume=gameplay_audio::locate({actor->position.x,actor->position.y,actor->position.z},spatial_,*gameplay_audio::attenuation(1));
    if(volume.status!=gameplay_audio::Status::completed&&volume.status!=gameplay_audio::Status::skipped)
        return{S::unsupported_profile,0};
    const auto level=channels_.level(2,volume.status==gameplay_audio::Status::completed?std::int32_t(volume.gain):0,backend_);
    if(!gameplay_scenario::stream_accepted(level))return{level,0};
    return{started.status==S::pending||level==S::pending?S::pending:S::completed,0};
}
}
