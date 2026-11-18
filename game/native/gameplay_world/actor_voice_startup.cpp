#include "actor_voice_startup.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ActorVoiceStartupEffects::ActorVoiceStartupEffects(World& world,gameplay_scenario::StreamBackend& backend,PrimaryStartupEffects& remaining):world_(world),backend_(backend),remaining_(remaining){
    if(world_.closed()||!remaining_.bound_to(world_))throw std::invalid_argument("Native actor voice startup owners unavailable or foreign");
}
bool ActorVoiceStartupEffects::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed()&&remaining_.bound_to(world_);}
PrimaryStartupStatus ActorVoiceStartupEffects::voice_archive(std::uint8_t slot,std::uint8_t character){
    if(!bound_to(world_))return PrimaryStartupStatus::unavailable;
    using S=gameplay_scenario::StreamStatus;
    switch(backend_.activate_actor_archive(slot,character)){
    case S::completed:return PrimaryStartupStatus::completed;
    case S::closed:return PrimaryStartupStatus::closed;
    case S::busy:return PrimaryStartupStatus::busy;
    default:return PrimaryStartupStatus::unavailable;
    }
}
}
