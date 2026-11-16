#include "scene_entry_requests.hpp"
#include "actor_interaction_commands.hpp"
#include "../transform_math/transform_math.hpp"
#include <bit>
#include <cmath>
namespace reo::native::gameplay_scenario {
namespace {
namespace w=gameplay_world;namespace t=transform_math;
#include "scene_entry_request_profiles.inc"
using EntryResult=SceneEntryRequestStatus;
bool finite(t::Vector v)noexcept{return std::isfinite(v.x)&&std::isfinite(v.y)&&std::isfinite(v.z);}
w::Position add(t::Vector a,t::Vector b)noexcept{return{a.x+b.x,a.y+b.y,a.z+b.z};}
t::Vector translation(const ModelMatrix& matrix)noexcept{return{matrix[3][0],matrix[3][1],matrix[3][2]};}
t::Vector rotate(std::uint32_t yaw,t::Vector vector){auto matrix=t::identity();t::reset_euler_axes(matrix,{0,std::uint16_t(yaw),0});return t::direction(matrix,vector);}
gameplay_scene::Records::Lease last_record(SceneControls& controls,std::uint8_t entry,std::uint8_t type){
    gameplay_scene::Records::Lease selected;
    for(auto node=controls.records()->first();node;node=node->next){
        if(gameplay_scene::kind(node->value.body)==type&&node->value.authored_id==entry)selected=node;
    }
    return selected;
}
EntryResult door(w::World& world,w::Actor& actor,SceneControls& controls,SceneModels& models,FlagState& flags,std::uint8_t entry,std::uint8_t kind){
    const auto node=last_record(controls,entry,0);if(!node)return EntryResult::completed;
    const auto& record=node->value;const auto& body=std::get<ControlTypeZero>(record.body);
    if(!body.matrix_program||!record.door_entry)return EntryResult::unavailable;
    const auto pose=models.pose(body.matrix_program->model_slot);if(!pose)return EntryResult::unavailable;
    const auto position=translation(*pose);if(!finite(position))return EntryResult::unavailable;
    actor.position={position.x,position.y,position.z};
    actor.scene_model=body.matrix_program->model_slot.byte_view();
    if(!actor.interaction_request)return EntryResult::unavailable;
    auto& request=*actor.interaction_request;const auto& detail=*record.door_entry;
    switch(body.matrix_program->resource_class){
    case 0:{const auto stop=flags.strided_half(world.room,2);if(!stop)return EntryResult::unavailable;
        if((*stop&(1u<<(record.authored_id&31u)))||kind==5){
            request.travel_distance=168.f;if(detail.side>=door_kinds.size())return EntryResult::unavailable;
            request.kind=std::uint8_t(door_kinds[detail.side]+31u);
        }else{if(detail.side>=door_kinds.size())return EntryResult::unavailable;request.kind=std::uint8_t(door_kinds[detail.side]+1u);}
        break;}
    case 1:request.travel_distance=168.f;request.kind=kind==5?47:26;break;
    case 3:request.travel_distance=168.f;request.kind=kind==5?48:41;break;
    default:break; //2 and other full words preserve the previous request fields.
    }
    if(detail.side>=door_offsets.size())return EntryResult::unavailable;
    const auto offset=t::direction(*pose,(request.kind==26||request.kind==41)?door_stopped_offsets[detail.side]:door_offsets[detail.side]);
    if(!finite(offset))return EntryResult::unavailable;
    actor.position=add(position,offset);request.orientation=detail.yaw;
    actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(detail.yaw));
    request.anchor=actor.position;actor.transient_action=1;return EntryResult::completed;
}
EntryResult object(w::World& world,w::Actor& actor,SceneControls& controls,FlagState& flags,std::uint8_t entry){
    const auto node=last_record(controls,entry,1);if(!node)return EntryResult::completed;
    const auto& record=node->value;if(!record.collision||!record.object_entry||!actor.interaction_request)return EntryResult::unavailable;
    const auto& detail=*record.object_entry;const auto mode=std::bit_cast<std::uint32_t>(record.collision->object.mode);
    if(mode>=object_kinds.size())return EntryResult::unavailable;
    auto& request=*actor.interaction_request;request.kind=object_kinds[mode];
    if(detail.scenario_flag!=65535){
        if(!flags.scenario(detail.scenario_flag,1,NotifyOwner::selected_actor_plus_one,std::uint8_t(world.selected_actor+1)))return EntryResult::unavailable;
        request.kind=49;
    }
    if(mode>=8){actor.transient_action=1;return EntryResult::completed;}
    const t::Vector anchor{detail.anchor[0],detail.anchor[1],detail.anchor[2]};
    if(!finite(anchor))return EntryResult::unavailable;
    if(mode==0||mode==7||mode==6){
        request.orientation=detail.yaw;actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(detail.yaw));
        request.anchor={anchor.x,anchor.y,anchor.z};actor.position=request.anchor;
        if(mode==6){actor.transient_equipment=1;actor.control_request.kind=11;return EntryResult::completed;}
        request.travel_distance=script_coordinate_float(detail.travel);
    }else{
        const auto yaw=mode==1?detail.yaw-0x8000u:detail.yaw;
        request.orientation=yaw;actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(yaw));
        if(actor.motion_subtype>=object_first_offsets.size())return EntryResult::unavailable;
        const auto offset=rotate(yaw,mode==1?object_first_offsets[actor.motion_subtype]:object_other_offsets[actor.motion_subtype]);
        if(!finite(offset))return EntryResult::unavailable;
        actor.position=add(anchor,offset);request.anchor=actor.position;
        if(mode==1){request.travel_distance=0;actor.scene_model=ModelReference{std::uint8_t(detail.endpoint)};}
        else request.travel_distance=script_coordinate_float(detail.travel);
    }
    actor.transient_action=1;return EntryResult::completed;
}
EntryResult ladder(w::Actor& actor,SceneControls& controls,SceneModels& models,std::uint8_t entry){
    gameplay_scene::Records::Lease selected;const auto selector=entry&127u;const bool upper=entry&128u;
    for(auto node=controls.records()->first();node;node=node->next){
        const auto& record=node->value;const auto body=std::get_if<ControlTypeSix>(&record.body);if(!body)continue;
        if(!record.ladder_entry)return EntryResult::unavailable;
        const auto mode=record.ladder_entry->mode;
        if(body->selector==selector&&((mode==4&&!upper)||(mode==5&&upper)))selected=node;
    }
    if(!selected)return EntryResult::completed;
    const auto& record=selected->value;if(!record.collision||!record.other_content||!actor.interaction_request)return EntryResult::unavailable;
    const auto& detail=*record.ladder_entry;const auto yaw=*record.other_content;
    if(actor.motion_subtype>=ladder_offsets.size())return EntryResult::unavailable;
    const auto offset=rotate(yaw,ladder_offsets[actor.motion_subtype]);
    const auto pose=models.pose(detail.model);if(!pose)return EntryResult::unavailable;
    const auto position=translation(*pose);if(!finite(position)||!finite(offset))return EntryResult::unavailable;
    actor.position=add(offset,position);actor.position.y=float(record.collision->lower);
    auto& request=*actor.interaction_request;request.anchor=actor.position;request.orientation=yaw;
    actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(yaw));request.travel_distance=200.f;
    actor.scene_model=detail.model.byte_view();actor.transient_action=1;request.kind=detail.mode==4?16:15;
    return EntryResult::completed;
}
}
SceneEntryRequestStatus queue_scene_entry_request(gameplay_world::World& world,gameplay_world::Actor& actor,
    SceneControls& controls,SceneModels& models,FlagState& flags,std::uint32_t entry,std::uint32_t kind)noexcept{
    if(world.closed())return EntryResult::unavailable;
    if(!controls.enabled())return EntryResult::completed;
    try{
        switch(std::uint8_t(kind)){
        case 1:case 5:return door(world,actor,controls,models,flags,std::uint8_t(entry),std::uint8_t(kind));
        case 2:case 6:return object(world,actor,controls,flags,std::uint8_t(entry));
        case 4:return ladder(actor,controls,models,std::uint8_t(entry));
        default:return EntryResult::completed;
        }
    }catch(...){return EntryResult::unavailable;}
}
}
