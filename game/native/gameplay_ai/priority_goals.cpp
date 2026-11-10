#include "priority_goals.hpp"
#include "reactions.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_navigation/bank.hpp"
namespace reo::native::gameplay_ai {
GoalResourceSelection select_character_seven_resource(const gameplay_world::Actor& self,const gameplay_world::Actor& other,const gameplay_scenario::SceneResources& resources)noexcept{
    if(self.character!=7)return {Status::completed,{}};
    // Owned immutable71B034 is FP32 25. Preserve source multiply/divide order.
    const float scaled=float(other.maximum)*25.f,threshold=scaled/100.f;
    const auto matches=[&](std::uint8_t slot,std::uint16_t content)->std::optional<bool>{
        const auto id=resources.slot(slot);if(!id)return {};
        const auto descriptor=resources.get(*id);if(!descriptor)return {};
        // Original descriptor +6 is attachment/content ID. +4 is the separate
        // authored descriptor lookup ID and can hold an unrelated value.
        return descriptor->active!=0&&descriptor->attachment_id==content;
    };
    if(!(other.status&8)&&other.class_marker==2&&other.current>0&&float(other.current)<threshold){
        const auto slot=self.inventory.storage[28];
        if(slot){const auto match=matches(slot,0x131);if(!match)return {};if(*match)return {Status::completed,slot};}
    }
    if(other.status&1)for(std::size_t i=10;i<19;++i){
        const auto slot=self.inventory.storage[i];if(!slot)continue;
        const auto match=matches(slot,0x12d);if(!match)return {};if(*match)return {Status::completed,slot};
    }
    return {Status::completed,{}};
}
bool actor_target_busy(const gameplay_world::Actor& actor)noexcept{
    return actor.motion_class>=6||(actor.auxiliary_status&0x30000u)||(actor.status&0x200u);
}
GoalReevaluated reevaluate_goal(gameplay_world::Actor& actor,const gameplay_world::Actor* reference,
    const gameplay_world::Actor* companion,const gameplay_navigation::Bank& bank,const gameplay_scenario::SceneResources& resources)noexcept{
    if(!actor.ai_execution)return {};
    auto& state=*actor.ai_execution;
    if(!state.goal_refresh)return {Status::completed,false};
    const auto motion=actor.motion_class;
    const bool eligible=motion<=5||motion==0x1a||motion==0x27||motion==0x31||(motion>=0x21&&motion<=0x24)||(motion>=0x2d&&motion<=0x2f)||motion==0x3b;
    if(!eligible||(actor.auxiliary_status&0x04010000u))return {Status::completed,false};
    if(!bank.bound()||actor.room>=128)return {};
    const auto graph=bank.room(actor.room);if(!graph||graph->nodes().empty())return {Status::completed,false};
    state.observation_flags=0;
    const auto goal=[&](std::uint16_t id){set_goal(state,id);return GoalReevaluated{Status::completed,true};};
    if(actor.status&8)return goal(13);
    if(motion==0x3b)return goal(14);
    if(!reference)return {};
    const bool same_room=actor.room==reference->room;
    if(same_room&&!state.peer_priority){
        if(!companion||!companion->ai_execution)return {};
        if(companion->ai_execution->goal!=10){
            if(reference->status&8){const auto result=goal(10);state.goal_phases[3]=0;return result;}
            if(reference->motion_class==0x30&&(reference->auxiliary_status&0x01000000u)){const auto result=goal(10);state.goal_phases[3]=1;return result;}
            if(reference->motion_class==0x25){const auto result=goal(10);state.goal_phases[3]=2;return result;}
        }
    }
    if(state.reference_request==1){state.goal_resource=reference->equipment_slot;return goal(11);}
    if(state.owned_request&&same_room){state.owned_request=0;return goal(12);}
    if(actor.character==7&&same_room){
        const auto item=select_character_seven_resource(actor,*reference,resources);if(item.status!=Status::completed)return {};
        if(item.selected){state.goal_resource=(state.goal_resource&0xffffff00u)|*item.selected;return goal(15);}
    }
    unsigned best=0,index=255;
    for(unsigned i=0;i<state.combined_weights.size();++i)if(state.combined_weights[i]>best){best=state.combined_weights[i];index=i;}
    switch(index){
    case 0:return goal(3);
    case 1:return goal(4);
    case 2:return goal(2);
    case 3:return goal(actor_target_busy(actor)?2:5);
    case 4:return goal(1);
    default:return {Status::completed,false};
    }
}

namespace {
Status update_motion_goal(gameplay_world::Actor& actor, gameplay_session::Random& random) noexcept {
    auto& state = *actor.ai_execution;
    if (actor.motion_class != 0x3b) {
        set_goal(state, 0);
        set_action(state, 0);
        return Status::completed;
    }
    if (!state.goal_phases[0]) {
        state.goal_phases[0] = 1;
        state.goal_parameters[0] = 10;
        state.goal_parameters[1] = 180;
    }
    if (state.goal_parameters[0]) {
        --state.goal_parameters[0];
        return Status::completed;
    }
    state.goal_parameters[0] = state.goal_parameters[1];
    const bool first_reaction = state.goal_phases[1] == 0;
    if (first_reaction)
        state.goal_phases[1] = 1;
    return schedule_reaction(state, actor.character, first_reaction ? 2 : 3, random).status;
}
}

GoalDispatched dispatch_goal(gameplay_world::Actor& actor, const gameplay_world::Actor* reference,
    const gameplay_world::Actor* companion, const gameplay_navigation::Bank& bank,
    const gameplay_scenario::SceneResources& resources, gameplay_session::Random& random) noexcept {
    if (reevaluate_goal(actor, reference, companion, bank, resources).status != Status::completed)
        return {};
    auto& state = *actor.ai_execution;
    const auto selected = state.goal;
    switch (selected) {
    case 0:
        return {Status::completed, selected};
    case 6:
        finish_goal_six(state);
        return {Status::completed, selected};
    case 14:
        return {update_motion_goal(actor, random), selected};
    default:
        return {Status::unavailable, selected};
    }
}
}
