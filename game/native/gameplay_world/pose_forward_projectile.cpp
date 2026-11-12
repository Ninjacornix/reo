#include "pose_forward_projectile.hpp"
#include <bit>
namespace reo::native::gameplay_world {
namespace {
constexpr std::uint8_t contacts[6][3]{{20,107,12},{22,100,12},{23,101,13},{24,0,15},{25,0,14},{26,104,12}};
std::int16_t decrement(std::int16_t v){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(v)-1u));}
}
bool advance_forward_pose_projectile(Actor& actor,const actors::EntityId& id,ForwardProjectileEffects& effects){
    if(!actor.pose_work)return false;
    auto& state=*actor.pose_work;
    if(actor.primary==0){state.travel_speed=50;actor.previous_position=actor.position;++actor.primary;state.timer=60;return effects.visual(id);}
    if(actor.primary==1){
        actor.previous_position=actor.position;
        const auto delta=transform_math::direction(state.basis,{0,0,state.travel_speed});
        actor.position={actor.position.x+delta.x,actor.position.y+delta.y,actor.position.z+delta.z};
        state.timer=decrement(state.timer);
        if(state.timer<=0){actor.primary=3;actor.auxiliary_status|=1;return true;}
        if(!actor.contact.serial)return true;
        unsigned descriptor=6;
        for(const auto& row:contacts){
            if(state.variant!=row[0])continue;
            if(actor.contact.recipient.category==255&&actor.contact.recipient.token==255&&actor.contact.related_recipient.category==255&&actor.contact.related_recipient.token==255&&!actor.sampled_surface_valid&&(actor.contact.serial==1||actor.contact.serial==2)&&!effects.sound(id,row[2]))return false;
            // Contact recipient/surface/serial tests gate only sound. Every
            // matching variant selects its row descriptor at584438.
            descriptor=row[1];break;
        }
        if(descriptor>=100){actor.primary=2;actor.auxiliary_status&=~1u;if(!effects.packet(id,std::uint8_t(descriptor),0))return false;if(descriptor==0x6b&&!effects.light({actor.position.x,actor.position.y,actor.position.z}))return false;}
        else{actor.primary=3;actor.auxiliary_status|=1;}
        return true;
    }
    if(actor.primary==2){actor.primary=3;actor.auxiliary_status|=1;return true;}
    return effects.retire(id);
}
}
