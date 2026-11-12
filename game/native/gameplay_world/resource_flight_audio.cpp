#include "resource_flight_audio.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceFlightAudio::ResourceFlightAudio(World& world,animation_events::BasicAudio& audio):world_(world),audio_(audio){
    if(!bound_to(world))throw std::invalid_argument("Native resource flight sound owners foreign or unavailable");
}
bool ResourceFlightAudio::bound_to(const World& world)const noexcept{return &world_==&world&&audio_.bound_to(world);}
bool ResourceFlightAudio::cue(const actors::EntityId& id,transform_math::Vector point){
    if(!bound_to(world_))return false;
    const auto actor=world_.resolve(id);if(!actor)return false;
    audio_.flight_contact(*actor,point);return true;
}
}
