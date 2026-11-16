#include "hit_contact_response.hpp"
#include "auxiliary_actors.hpp"
#include "linked_models.hpp"
#include "../animation/playback.hpp"
#include "../transform_math/transform_math.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
[[noreturn]] void unavailable(){throw std::runtime_error("Native hit contact source unavailable");}
std::shared_ptr<Actor> source(World& world,std::uint8_t category,std::uint8_t token){
    std::shared_ptr<Actor> actor;
    switch(category){
    case 0:actor=world.primary(token);break;
    case 1:actor=world.resolve(world.auxiliary_actors().identity_at(token));break;
    case 2:{
        const auto* descriptor=world.session().enemy_descriptors.record(token);
        if(!descriptor)unavailable();
        actor=world.resolve(world.linked_models().identity_at(descriptor->actor_slot));break;
    }
    default:return{}; //663350 returns a known null for other categories.
    }
    if(!actor)unavailable(); //A physical original record needs its native owner.
    return actor;
}
}
void finish_hit_contact(World& world,Actor& actor){
    if(world.closed()||world.resolve(world.identity_of(actor)).get()!=&actor)unavailable();
    if(actor.category!=0||actor.character!=1)return;
    if(actor.motion_class!=0x41){
        if(!actor.animation||actor.animation->model()!=actor.model)unavailable();
        if(actor.animation->motion!=0x1049)return;
    }
    if(actor.response_class==2)return;
    std::shared_ptr<Actor> other;
    if(actor.source_kind==9){
        const auto kind=actor.contact.source_related.category;
        if(kind==0||kind==1)other=source(world,kind,actor.contact.source_related.token);
        else{
            other=world.resolve(actor.contact.recorded_source);
            if(actor.contact.recorded_source&&!other)unavailable();
        }
    }else other=source(world,actor.source_kind,actor.source_slot);

    gameplay_collision::Vec3 direction{0,0,1}; //owned712BB8
    if(!other)direction=actor.contact.direction;
    else if(!actor.contact.auxiliary_a){
        direction={actor.position.x-other->position.x,actor.position.y-other->position.y,actor.position.z-other->position.z};
        const float squared=(direction.x*direction.x+direction.y*direction.y)+direction.z*direction.z;
        const float reciprocal=1.f/std::sqrt(squared); //191D80's reciprocal-then-product order
        direction={direction.x*reciprocal,direction.y*reciprocal,direction.z*reciprocal};
    }else{
        const auto turn=std::uint16_t(int(other->orientation[1])+(int(actor.contact.auxiliary_a)<<8));
        constexpr float tau=std::bit_cast<float>(0x40c90fdbu); //owned740470
        const auto wave=transform_math::sin_cos((tau*float(turn))/65536.f);
        direction={wave.sine,0,wave.cosine}; //191BC0 rotates the owned unit Z vector.
    }
    const auto& forward=actor.candidate_direction;
    const float dot=(forward.x*direction.x+forward.y*direction.y)+forward.z*direction.z;
    if(!(dot<0.f))return;
    actor.response_flags|=1u;
    if(actor.damage_word<=0)return;
    if(!(world.session().gameplay_flags&2u)){actor.damage_word=0;return;} //668BB8 -> 668C64
    if(other&&other->category==0&&(other->status&0x80u)){actor.damage_word=0;return;}
    if(actor.source_kind==0||actor.source_kind==1||
       actor.contact.source_related.category==0||actor.contact.source_related.category==1)
        actor.damage_word/=2;
    else actor.damage_word=0;
}
}
