#include "actor_scene_triggers.hpp"
namespace reo::native::gameplay_world {
ActorSceneTriggerReport update_actor_scene_triggers(World& world,Actor& actor,gameplay_scene::Records& records,gameplay_scenario::SceneMatrixPrograms& programs,gameplay_scenario::FlagState& flags)noexcept{
    ActorSceneTriggerReport result;if(world.closed()||!programs.bound_to_records(records,flags,world.room)){result.status=ActorSceneTriggerStatus::unavailable;return result;}if(records.size()==0)return result;
    const auto point=gameplay_collision::integer_xz({actor.position.x,actor.position.y,actor.position.z});
    if(!point){result.status=ActorSceneTriggerStatus::unavailable;return result;}
    for(auto node=records.first();node;node=node->next){
        ++result.visited;auto& record=node->value;if(gameplay_scene::kind(record.body)!=0x85)continue;
        const auto source=records.acquire(record.source);if(!source){result.status=ActorSceneTriggerStatus::unavailable;return result;}
        const auto channel_index=source->value.authored_id;const auto channel=programs.inspect(channel_index);if(!channel){result.status=ActorSceneTriggerStatus::unavailable;return result;}
        if(channel->contact.gate!=2)continue;
        if(!record.collision){result.status=ActorSceneTriggerStatus::unavailable;return result;}
        const auto& shape=*record.collision;if(!gameplay_collision::contains(shape.bounds,*point))continue;
        const float lower=float(shape.lower),height=actor.position.y;
        const bool admitted=lower<=height?(lower<height?!(float(shape.upper)<height):true):lower<=height+200.f;
        if(!admitted)continue;
        const auto id=world.identity_of(actor);if(!id){result.status=ActorSceneTriggerStatus::unavailable;return result;}
        record.owner=id;records.touch();
        if(actor.category==0){
            if(world.locally_controlled(actor)){
                // Original SLLV masks the bit count before narrowing to16.
                if(!flags.strided(world.room,channel_index&31u,1,true,false)){result.status=ActorSceneTriggerStatus::unavailable;return result;}
                actor.auxiliary_status|=0x20000u;
            }
            if(world.mode==0)actor.auxiliary_status|=0x20000u;
        }
        if(programs.interaction(channel_index,1)!=gameplay_scenario::SceneMatrixStatus::completed){result.status=ActorSceneTriggerStatus::unavailable;return result;}
        ++result.triggered;
    }
    return result;
}
}
