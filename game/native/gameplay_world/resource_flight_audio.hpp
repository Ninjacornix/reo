#pragma once
#include "animation_audio.hpp"
#include "../gameplay_effects/resource_flight.hpp"
namespace reo::native::gameplay_world {
class ResourceFlightAudio final:public gameplay_effects::FlightAudio {
public:
    ResourceFlightAudio(World&,animation_events::BasicAudio&);
    bool bound_to(const World&)const noexcept override;
    bool cue(const actors::EntityId&,transform_math::Vector)override;
private:
    World& world_;animation_events::BasicAudio& audio_;
};
}
