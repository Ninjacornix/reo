#pragma once
#include "world.hpp"
#include "../gameplay_audio/spatial.hpp"
#include "../gameplay_scenario/stream_channels.hpp"
namespace reo::native::gameplay_world {
struct ActorVoiceResult {
    gameplay_scenario::StreamStatus status{gameplay_scenario::StreamStatus::completed};
    std::int32_t original_return{-1};
};
// Complete1BA250 ordinary-slot profile. One World, canonical stream channel2,
// existing spatial math and the same backend's activated archive selections.
// The NPC/common slot5 producer is separate and remains unavailable here.
class ActorVoiceRequests final {
public:
    ActorVoiceRequests(World&,gameplay_scenario::StreamChannels&,gameplay_scenario::StreamBackend&,
        const gameplay_audio::SpatialContext&,const std::optional<std::uint32_t>& audio_tick)noexcept;
    bool bound_to(const World&)const noexcept;
    ActorVoiceResult request(const actors::EntityId&,std::int32_t member)noexcept;
private:
    World& world_;gameplay_scenario::StreamChannels& channels_;gameplay_scenario::StreamBackend& backend_;
    const gameplay_audio::SpatialContext& spatial_;const std::optional<std::uint32_t>& tick_;
};
}
