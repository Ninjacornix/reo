#include "assistance.hpp"
#include "auxiliary_actors.hpp"
#include "motion.hpp"
#include "cooperation.hpp"
#include "inventory_ui.hpp"
#include "idle_action.hpp"
#include "../gameplay_update/update.hpp"
#include "../transform_math/heading.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
[[noreturn]] void unavailable(){throw std::runtime_error("Native assistance actor state unavailable");}
actors::EntityId admit(World& world,Actor& actor){
    const auto id=world.identity_of(actor);
    if(world.closed()||!id||world.resolve(id).get()!=&actor)unavailable();return id;
}
actors::ActorReference reference(const Actor& actor){
    return actor.category==1?actors::ActorReference{actors::ActorReference::Kind::auxiliary,std::uint16_t(actor.model_variant&0x7fff)}:
        actors::ActorReference{actors::ActorReference::Kind::primary,actor.slot};
}
}
actors::EntityId nearest_assistance_actor(World& world,Actor& actor){
    (void)admit(world,actor);float closest=100.f;actors::EntityId result;
    const auto consider=[&](const std::shared_ptr<Actor>& candidate){
        if(!candidate)unavailable();
        if(!candidate->active||!candidate->visible)return;
        const float dx=actor.position.x-candidate->position.x,dz=actor.position.z-candidate->position.z;
        const float xx=dx*dx,zz=dz*dz,distance=std::sqrt((xx+0.f)+zz);
        if(!std::isfinite(distance))unavailable();
        if(!(distance<=closest)||(candidate->status&0x010000e0u))return;
        if(!(candidate->position.y<=actor.position.y+30.f)||candidate->position.y<actor.position.y-30.f)return;
        const auto heading=transform_math::direction_turn(candidate->position.x-actor.position.x,candidate->position.z-actor.position.z);
        if(std::uint16_t(heading-std::uint16_t(actor.orientation[1])+0x4000u)>0x8000u)return;
        closest=distance;
        //6667A0 commits the distance before the class2/status10 rejection.
        //The enclosing scan retains its earlier target on this rejection.
        if(actor.class_marker==2&&!(candidate->status&0x10u))return;
        result=admit(world,*candidate);
    };
    const auto count=world.session().primary_population;if(!count||*count>World::primary_capacity)unavailable();
    for(std::size_t i=0;i<*count;++i){const auto candidate=world.primary(i);if(!candidate)unavailable();if(candidate->slot!=actor.slot)consider(candidate);}
    auto& auxiliary=world.auxiliary_actors();
    for(auto id=auxiliary.head();id;id=auxiliary.next(id))consider(world.resolve(id));
    return result;
}
actors::EntityId select_assistance_actor(gameplay_update::Owner& update,Actor& actor){
    auto& world=update.world();(void)admit(world,actor);
    if(!update.open())unavailable();
    if(world.paused||actor.category||actor.motion_class==0x16||(actor.status&0x1e8u))return{};
    const auto id=nearest_assistance_actor(world,actor);if(!id)return{};
    const auto target=world.resolve(id);if(!target)unavailable();
    if(target->response_lock)return{};
    if(world.mode==0&&actor.ai_control&&target->slot==0&&!(target->status&8u))return{};
    if(target->motion_class!=0&&target->motion_class!=1&&target->motion_class!=3)return{};
    if(target->class_marker!=2&&!(target->status&8u))return{};
    if(world.locally_controlled(actor)&&(target->status&8u)){
        if(!update.completion_statistics().record_assistance())unavailable();
        if(target->category==0){
            const auto status=update.record_event(9,target->character,0).status;
            if(status!=gameplay_events::Status::completed&&status!=gameplay_events::Status::priority_rejected&&status!=gameplay_events::Status::full)unavailable();
        }
    }
    return id;
}
void begin_assistance(gameplay_update::Owner& update,Actor& actor,Actor& target){
    auto& world=update.world();const auto id=admit(world,actor),related=admit(world,target);
    const auto retained=world.resolve(id),other=world.resolve(related);
    if(!update.open())unavailable();
    if(target.category!=0&&target.category!=1)return;
    actor.primary=1;actor.secondary=0xa1;actor.phase=target.category==1?2:0;actor.subphase=0;save_action_pose(actor);
    actor.transient_contact=2;if(!actor.peer_request)unavailable();
    actor.peer_request->state_high=1;actor.peer_request->peer=reference(target);
    if(update.record_actor_message(id,gameplay_update::ActorMessageSelector::peer)!=gameplay_update::PublicationStatus::completed)unavailable();
    if(world.resolve(id)!=retained||world.resolve(related)!=other)unavailable();
    target.transient_contact=2;if(!target.peer_request)unavailable();
    target.peer_request->state_high=1;
    //C68 is a byte write: preserve the high byte of its signed halfword.
    target.peer_request->parameters[0]=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(target.peer_request->parameters[0])&0xff00u));
    target.peer_request->peer={actors::ActorReference::Kind::primary,actor.slot};
    actor.transient_contact=0;if(!actor.peer_request)unavailable();
    actor.peer_request->state_high=0;actor.peer_request->peer=reference(target);
}
void update_cooperation_action(gameplay_update::Owner& update,Actor& actor,InventoryUi& inventory,ActionAnimation* animation){
    auto& world=update.world();const auto id=admit(world,actor);const auto lease=world.resolve(id);
    if(!update.open()||!inventory.bound_to(world))unavailable();
    if(world.paused||actor.transient_contact!=2)return;
    actor.transient_contact=0;
    if(!actor.peer_request)unavailable();
    const auto publish=[&](gameplay_update::ActorMessageSelector selector){
        if(update.record_actor_message(id,selector)!=gameplay_update::PublicationStatus::completed)unavailable();
        if(world.resolve(id)!=lease)unavailable();
    };
    const auto change=[&](std::uint8_t secondary,std::uint8_t phase){
        actor.primary=1;actor.secondary=secondary;actor.phase=phase;actor.subphase=0;save_action_pose(actor);
    };
    switch(actor.peer_request->state_high){
    case 1:{
        const auto target=world.referenced_actor(actor.peer_request->peer);
        const auto reject=[&](){
            if(!target)unavailable();
            class Publication final:public CooperationPublication {
            public:
                explicit Publication(gameplay_update::Owner& owner):owner_(owner){}
                bool publish_peer(World& source,Actor& value)override{
                    return &source==&owner_.world()&&owner_.record_actor_message(source.identity_of(value),gameplay_update::ActorMessageSelector::peer)==gameplay_update::PublicationStatus::completed;
                }
            private:gameplay_update::Owner& owner_;
            } publication(update);
            if(update_cooperation_request(world,actor,*target,publication)!=CooperationStatus::completed)unavailable();
        };
        if((world.selected_frame_marker&2u)||
           (actor.class_marker!=2&&!(actor.status&8u))||
           (actor.auxiliary_status&0x10000u)||actor.response_lock){reject();return;}
        if(actor.primary!=1||(actor.secondary>14&&actor.secondary!=0x31&&actor.secondary!=0x32)){reject();return;}
        const auto phase=world.session().message_phase;
        if((phase==1||phase==2)&&actor.category==0){
            if(!target)unavailable();
            actor.transient_contact=2;actor.peer_request->state_high=3;actor.peer_request->peer=reference(*target);
            publish(gameplay_update::ActorMessageSelector::peer);
        }
        actor.transient_contact=0;
        if(!actor.peer_request||!target||!world.identity_of(*target))unavailable();
        actor.peer_request->state_high=0;actor.peer_request->peer=reference(*target);
        actor.status|=0x80000u;change(0xac,0);
        break;
    }
    case 2:
        actor.status&=~0x80000u;change(0,0);
        publish(gameplay_update::ActorMessageSelector::snapshot);
        actor.motion_class=0;actor.action_flags&=~std::uint16_t(1);change(0,1);
        if(!animation)unavailable();animation->select(actor,0x2050,0.f,10.f);
        if(world.resolve(id)!=lease)unavailable();animation->activate(actor);return;
    case 3:
        if(actor.motion_class!=0x16)break;
        change(0xa1,2);publish(gameplay_update::ActorMessageSelector::snapshot);break;
    case 4:
        if(actor.motion_class!=0x16||actor.secondary==0xa2)break;
        change(0xa2,0);publish(gameplay_update::ActorMessageSelector::snapshot);break;
    default:return;
    }
    if(world.locally_controlled(actor)&&inventory.force_close()!=InventoryUiStatus::completed)unavailable();
}
}
