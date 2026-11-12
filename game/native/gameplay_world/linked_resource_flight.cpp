#include "linked_resource_flight.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
using V=transform_math::Vector;
V cross(V a,V b){return{a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
}
bool advance_linked_resource_flight(Actor& actor,ResourceModel* model,std::uint8_t clock,
    const actors::EntityId& id,LinkedFlightEffects& effects){
    if(!actor.pose_work)return false;
    auto& state=*actor.pose_work;
    if(!model||(model->flags&0x20000u))actor.primary=255;
    if(actor.primary==0){
        actor.primary=1;actor.visible=false;state.timer=60;
        state.velocity={model->use_vector.x,model->use_vector.y,model->use_vector.z};
        actor.previous_orientation=model->use_parameters;
        model->angles[1]=std::uint16_t(unsigned(model->angles[1])+std::uint16_t(actor.orientation[1]));
    }
    if(actor.primary==1){
        state.timer=std::bit_cast<std::int16_t>(std::uint16_t(std::uint32_t(std::int32_t(state.timer))-(1u<<(clock&31u))));
        if(state.timer<0)++actor.primary;
        else if(actor.contact.serial){
            const auto content=model->content_id;
            const auto empty=[](const auto& r){return r.category==255&&r.token==255;};
            const bool unclaimed=empty(actor.contact.recipient)&&empty(actor.contact.related_recipient);
            const bool special=content==0x72||(content>=0x9b&&content<=0x9f);
            if(special){
                if(content==0x72){
                    const auto sampled=effects.floor({actor.position.x,actor.position.y,actor.position.z});if(!sampled)return false;
                    const V point{actor.position.x,3.0f+sampled->height,actor.position.z};
                    if(sampled->type!=255){
                        if(!effects.burst(actor.contact.related,point))return false;
                        if(!effects.light(actor.contact.related,point))return false;
                    }
                }
                if(unclaimed&&(actor.contact.serial==1||actor.contact.serial==2)&&!effects.sound(id,0x12))return false;
                const auto descriptor=std::uint8_t(content==0x72?0x69:content==0x9c?0x65:content==0x9f?0x64:0);
                if(descriptor){actor.auxiliary_status&=~1u;if(!effects.packet(id,descriptor))return false;}
                ++actor.primary;
            }else if(!unclaimed){state.velocity.x=state.velocity.x*-.3f;state.velocity.z=state.velocity.z*-.3f;}
            else if(actor.contact.serial==1){
                const auto n=actor.projectile_contact.normal;const V normal{n.x,n.y,n.z};
                auto t=cross(normal,state.velocity);t={t.x*2.0f,t.y*2.0f,t.z*2.0f};t=cross(t,normal);
                t={t.x-state.velocity.x,t.y-state.velocity.y,t.z-state.velocity.z};
                state.velocity.x=.3f*t.x;state.velocity.z=.3f*t.z;
            }else ++actor.primary;
            actor.contact.serial=0;
        }
        state.velocity.y=state.velocity.y-(clock==0?1.0f:2.0f);
        actor.position={actor.position.x+state.velocity.x,actor.position.y+state.velocity.y,actor.position.z+state.velocity.z};
        model->position={actor.position.x,actor.position.y,actor.position.z};
        for(unsigned i=0;i<3;++i)model->angles[i]=std::uint16_t(unsigned(model->angles[i])+std::uint16_t(actor.previous_orientation[i]));
        return true;
    }
    if(actor.primary==2&&model)model->flags|=0x40000000u;
    actor.auxiliary_status|=1;state.lifetime=1;return true;
}
LinkedResourceFlight::LinkedResourceFlight(World& world,PoseWorkPool& pool,gameplay_scenario::SceneResources& resources,
    LinkedFlightEffects& effects,PoseWorkUpdates* remaining):world_(world),pool_(pool),resources_(resources),effects_(effects),remaining_(remaining){
    if(!bound_to(world))throw std::invalid_argument("Native linked flight owners unavailable");
}
bool LinkedResourceFlight::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&effects_.bound_to(world)&&(!remaining_||remaining_->bound_to(world));}
bool LinkedResourceFlight::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    if(kind!=9)return remaining_&&remaining_->update(pool,id,kind);
    const auto actor=pool.resolve(id);if(!actor)return false;
    const auto key=resources_.slot(actor->slot);const auto descriptor=key?resources_.get(*key):std::nullopt;
    const auto model=descriptor?std::dynamic_pointer_cast<ResourceModel>(descriptor->primary):nullptr;
    if(descriptor&&descriptor->primary&&(!model||!model->current()))return false;
    return advance_linked_resource_flight(*actor,model.get(),world_.session().clock_mode,id,effects_);
}
}
