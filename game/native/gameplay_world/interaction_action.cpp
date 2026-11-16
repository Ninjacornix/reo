#include "interaction_action.hpp"
#include "../transform_math/transform_math.hpp"

namespace reo::native::gameplay_world {
namespace {
InteractionActionResult complete(bool value) noexcept {
    return {InteractionActionStatus::completed,value};
}
InteractionActionResult unavailable() noexcept { return {}; }
bool live(World& world,const actors::EntityId& id,const Actor& actor) noexcept {
    return !world.closed()&&world.resolve(id).get()==&actor;
}
InteractionActionResult held_contact(World& world,Actor& actor,
    InteractionActionServices& services,const actors::EntityId& id) {
    const float offset=actor.motion_class==2?-96.0f:96.0f;
    const auto contact=services.forward_contact(world,actor,0xffffffffu,0,offset);
    if(contact.status!=ForwardContactStatus::completed||!live(world,id,actor))return unavailable();
    if(contact.original_result!=2){
        if(!actor.forward_contact_attempts)return unavailable();
        *actor.forward_contact_attempts=0;
        return complete(false);
    }
    // 64EDF4/EE00 asks1B0340 and requires exactly one. Then BA0&90 rejects.
    if(!world.locally_controlled(actor)||(actor.status&0x90u))return complete(false);
    // F80 bit1; 191DF0 computes the ordered xyz dot product of the forward
    // direction with the negated contact normal. 370100(0x2000) supplies
    // the cosine threshold for a quarter of a right angle.
    if(!(actor.input.held&1u)){
        if(!actor.forward_contact_attempts)return unavailable();
        *actor.forward_contact_attempts=0;
        return complete(false);
    }
    const auto& normal=actor.projectile_contact.normal;
    const float alignment=(actor.candidate_direction.x*-normal.x+
        actor.candidate_direction.y*-normal.y)+actor.candidate_direction.z*-normal.z;
    const float threshold=transform_math::sin_cos(transform_math::radians(0x2000)).cosine;
    if(alignment<threshold){
        if(!actor.forward_contact_attempts)return unavailable();
        *actor.forward_contact_attempts=0;
        return complete(false);
    }
    if(!actor.forward_contact_attempts)return unavailable();
    *actor.forward_contact_attempts=std::uint16_t(*actor.forward_contact_attempts+1u);
    const auto limit=std::uint16_t(world.session().clock_mode?30:60); //3243CC
    if(*actor.forward_contact_attempts<limit)return complete(false);

    // Query result is deliberately ignored by source. The timer clear is in
    // 64EEC8's delay slot, before the request consumer runs.
    const auto queried=services.actor_query(world,actor,1,5);
    if(!queried||!live(world,id,actor))return unavailable();
    *actor.forward_contact_attempts=0;
    const auto consumed=services.consume_request(world,actor);
    if(!consumed||!live(world,id,actor))return unavailable();
    if(!*consumed)return complete(false);
    if(!services.notify(world,actor,3)||!live(world,id,actor))return unavailable();
    return complete(true);
}
}

InteractionActionResult process_interaction_action(World& world,Actor& actor,
    InteractionActionServices& services) {
    // 64E974..9A4. These two gates precede all query and contact writes.
    if(world.closed())return unavailable();
    const auto id=world.identity_of(actor);
    const auto lease=id?world.resolve(id):nullptr;
    if(!id||lease.get()!=&actor)return unavailable();
    if(actor.status&0x8u)return complete(false);
    if(actor.surface_kind==1)return complete(false);

    // 64E9A4..EC: radius is selected by B9B and negated only for motion class2.
    float radius=actor.class_marker==2?75.0f:55.0f; //B9B
    if(actor.motion_class==2)radius=-radius;
    const auto contact=services.forward_contact(world,actor,0xffffffffu,0,radius);
    if(contact.status!=ForwardContactStatus::completed||!live(world,id,actor))return unavailable();
    const std::uint16_t result=contact.original_result;
    if(result==0x002){
        return held_contact(world,actor,services,id);
    }

    // The first table contains only the authored response codes dispatched by
    // 64E9F8..EA2C. A hit that needs the authored contact-alignment gate calls
    // the already source-qualified666F50 equivalent before writing action state.
    std::uint8_t secondary{};
    bool align=false;
    switch(result){
    case 0x004: case 0x010: case 0x020: case 0x008:
    case 0x040: case 0x080: case 0x100: case 0x200: case 0x800:
        align=true;break;
    default:break;
    }
    if(align){
        // 64EAF4..EB20: codes8/20 ask6AF9E0 only when BA0 bit4000 is set.
        if((result==0x008||result==0x020)&&(actor.status&0x4000u)){
            const auto admitted=services.admit_actor(world,actor);
            if(!admitted||!live(world,id,actor))return unavailable();
            if(!*admitted){
                return held_contact(world,actor,services,id);
            }
        }
        if(!(actor.input.pressed&0x20u)){
            return held_contact(world,actor,services,id);
        }
        if(!services.prepare_alignment(world,actor,0x2000u,50.0f)){
            if(result==0x004||result==0x010||result==0x008||result==0x020)
                return held_contact(world,actor,services,id);
            return complete(false);
        }
        if(!live(world,id,actor))return unavailable();

        switch(result){
        case 0x004: secondary=0x13;break;
        case 0x010: secondary=0x47;break;
        case 0x020: secondary=0x3b;break;
        case 0x008: secondary=0x14;break;
        case 0x040: secondary=0x56;break;
        case 0x080: secondary=0x57;break;
        case 0x100: secondary=0x58;break;
        case 0x200: secondary=0x57;break;
        case 0x800: secondary=0x56;break;
        default:break;
        }
        actor.primary=1;actor.secondary=secondary;actor.phase=0;actor.subphase=0;
        if(!services.activate(world,actor)||!live(world,id,actor))return unavailable();
        if(!services.notify(world,actor,6)||!live(world,id,actor))return unavailable();
        return complete(true);
    }
    // All values that miss the compact response table join the common
    // 64ED90 held-contact suffix (including an initial zero result).
    return held_contact(world,actor,services,id);
}
}
