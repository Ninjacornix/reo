#include "contact_weapon_effects.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
class Channels final:public gameplay_effects::ContactStyleChannels {
public:
    World& world;const actors::EntityId& actor;ActorContactChannels* target;
    Channels(World& w,const actors::EntityId& a,ActorContactChannels* t):world(w),actor(a),target(t){}
    gameplay_effects::WorkStatus create(const std::optional<animation::Matrix>& basis,animation::Vector point,std::uint32_t mode,std::uint32_t variant)override{
        if(!target||!target->channels_bound_to(world)||!world.resolve(actor))return gameplay_effects::WorkStatus::unavailable;
        return target->actor_channel(actor,basis,point,mode,variant);
    }
};
}
ContactWeaponEffects::ContactWeaponEffects(World& world,gameplay_effects::WorkBackend& work,ActorContactChannels* channels,WeaponEffects* remaining)
    :world_(world),work_(work),channels_(channels),remaining_(remaining){
    if(!bound_to(world))throw std::invalid_argument("Native contact effect owners unavailable");
}
bool ContactWeaponEffects::bound_to(const World& world)const noexcept{
    return &world==&world_&&!world_.closed()&&work_.admitted()&&work_.bound_to(world_.session().random)&&
        (!channels_||channels_->channels_bound_to(world))&&(!remaining_||remaining_->bound_to(world));
}
bool ContactWeaponEffects::contact_style(const actors::EntityId& id,const animation::Matrix& basis,animation::Vector point,std::uint8_t style){
    if(!bound_to(world_))return false;
    const auto actor=world_.resolve(id);if(!actor)return false;
    Channels channels(world_,id,channels_);
    return gameplay_effects::construct_contact_style(work_,{actor->contact_style_discriminator,&channels},basis,point,style)==gameplay_effects::WorkStatus::completed&&world_.resolve(id)==actor;
}
bool ContactWeaponEffects::pose_work(const actors::EntityId& id,const animation::Matrix& basis,animation::Vector point,std::uint32_t resource){return bound_to(world_)&&remaining_&&remaining_->pose_work(id,basis,point,resource);}
bool ContactWeaponEffects::transient_light(const actors::EntityId& id,animation::Vector point){return bound_to(world_)&&remaining_&&remaining_->transient_light(id,point);}
bool ContactWeaponEffects::flight(const actors::EntityId& id,const animation::Matrix& basis,std::uint32_t style){return bound_to(world_)&&remaining_&&remaining_->flight(id,basis,style);}
}
