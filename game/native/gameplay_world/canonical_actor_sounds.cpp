#include "canonical_actor_sounds.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
bool CanonicalActorSoundOffsets::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
std::optional<std::uint8_t> CanonicalActorSoundOffsets::find(const actors::EntityId& id){
    if(!bound_to(world_))return{};
    const auto actor=world_.resolve(id);return actor&&actor->sound_state?std::optional(actor->sound_state->program_variant):std::nullopt;
}
bool CanonicalProjectileParentVariant::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
std::optional<std::uint8_t> CanonicalProjectileParentVariant::read(const actors::EntityId& id){
    if(!bound_to(world_))return{};
    const auto actor=world_.resolve(id);return actor?actor->projectile_variant:std::nullopt;
}
CanonicalActorOffsetSound::CanonicalActorOffsetSound(World& world,gameplay_audio::Owner& audio,const gameplay_audio::SpatialContext& spatial)
    :world_(world),audio_(audio),spatial_(spatial){if(!bound_to(world))throw std::invalid_argument("Native offset sound owners unavailable");}
bool CanonicalActorOffsetSound::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed()&&audio_.bound_to(world_.session().random);}
bool CanonicalActorOffsetSound::sound(const actors::EntityId& id,std::uint8_t event){
    last_.reset();if(!bound_to(world_))return false;
    const auto actor=world_.resolve(id);if(!actor)return false;
    const auto plan=plan_actor_offset_sound(actor->sound_state,event);if(!plan.available)return false;
    if(!plan.request)return true;
    last_=audio_.positional(*plan.request,{actor->position.x,actor->position.y,actor->position.z},spatial_,1);return true;
}
}
