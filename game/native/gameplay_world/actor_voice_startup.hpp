#pragma once
#include "primary_roster_startup.hpp"
#include "../gameplay_scenario/stream_channels.hpp"
namespace reo::native::gameplay_world {
// Replaces only the real1BA440 branch with the canonical native stream
// backend. Other reached resource consumers remain explicit capabilities.
class ActorVoiceStartupEffects final:public PrimaryStartupEffects {
public:
    ActorVoiceStartupEffects(World&,gameplay_scenario::StreamBackend&,PrimaryStartupEffects&);
    bool bound_to(const World&)const noexcept override;
    PrimaryStartupStatus voice_archive(std::uint8_t slot,std::uint8_t character)override;
    PrimaryStartupStatus background(std::uint8_t value)override{return remaining_.background(value);}
    PrimaryStartupStatus initialize_stream_stage()override{return remaining_.initialize_stream_stage();}
    PrimaryStartupStatus run(PrimaryStartupWork value)override{return remaining_.run(value);}
    PrimaryStartupStatus actor_resources(PrimaryStartupWork value,const actors::EntityId& id)override{return remaining_.actor_resources(value,id);}
    std::optional<std::int8_t> roster_kind(std::uint8_t row)const noexcept override{return remaining_.roster_kind(row);}
    std::optional<float> reference_height(std::uint8_t character)const noexcept override{return remaining_.reference_height(character);}
private:
    World& world_;gameplay_scenario::StreamBackend& backend_;PrimaryStartupEffects& remaining_;
};
}
