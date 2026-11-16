#include "room_camera.hpp"
#include "room_camera_records.hpp"
#include "sequence_control.hpp"
#include "scene_models.hpp"
#include "fog.hpp"
#include "../gameplay_world/world.hpp"
#include <bit>
#include <cmath>
#include <cstring>

namespace reo::native::gameplay_scenario {
namespace {
using Vector=transform_math::Vector;
Vector converted(const CameraIntegerPoint& value){return{float(value[0]),float(value[1]),float(value[2])};}
float divide(float numerator,float denominator)noexcept{
    if(denominator!=0.f)return numerator/denominator;
    return std::bit_cast<float>(0x7f7fffffu|((std::bit_cast<std::uint32_t>(numerator)^std::bit_cast<std::uint32_t>(denominator))&0x80000000u));
}
Vector weighted(const std::array<CameraIntegerPoint,2>& pair,float next,float first){
    const auto a=converted(pair[0]),b=converted(pair[1]);const auto total=next+first;
    return{divide(first*a.x+next*b.x,total),divide(first*a.y+next*b.y,total),divide(first*a.z+next*b.z,total)};
}
std::uint32_t truncated(float value)noexcept{
    if(!std::isfinite(value)||value>=2147483648.f||value<-2147483648.f)
        return std::signbit(value)?0x80000000u:0x7fffffffu;
    return std::bit_cast<std::uint32_t>(std::int32_t(value));
}
void lens_and_roll(CameraParameters& parameters,const RoomCameraRecord& record,float next,float first){
    const auto a=record.parameters[2],b=record.parameters[3];
    parameters.pose.roll=a==b?a:a+truncated((next*float(std::bit_cast<std::int32_t>(b-a)))/100000.f);
    parameters.lens=record.lens==record.distance?record.lens:
        divide(first*record.lens+next*record.distance,next+first);
}
float fractional(float value)noexcept{
    //192200->10A2F0 is modff, not floor: negative fractions keep their sign.
    const auto bits=std::bit_cast<std::uint32_t>(value);
    const auto exponent=int((bits>>23)&255u)-127;
    if(exponent<0)return value;
    if(exponent>=23)return std::bit_cast<float>(bits&0x80000000u);
    const auto mask=0x7fffffu>>exponent;
    return bits&mask?value-std::bit_cast<float>(bits&~mask):std::bit_cast<float>(bits&0x80000000u);
}
Vector quadratic(Vector first,Vector control,Vector last,float t){
    const auto part=[&](float a,float b,float c){const float x=a+(b-a)*t,y=b+(c-b)*t;return x+(y-x)*t;};
    return{part(first.x,control.x,last.x),part(first.y,control.y,last.y),part(first.z,control.z,last.z)};
}
bool finite(Vector value)noexcept{return std::isfinite(value.x)&&std::isfinite(value.y)&&std::isfinite(value.z);}
}
RoomCameraStatus RoomCamera::evaluate(std::uint8_t index,Vector actor,CameraDisplayBinding& display){
    const auto& asset=*sequences_.records_;auto& state=sequences_.state_;
    const auto& incoming=asset.records()[index];
    if(incoming.type==1)state.previous_camera=index;
    display.initialize(parameters_);
    if(incoming.type==1){
        parameters_.pose.eye=converted(incoming.endpoints[1][0]);
        parameters_.pitch=incoming.parameters[0];parameters_.yaw=incoming.parameters[1];
        parameters_.pose.roll=incoming.parameters[2];parameters_.lens=incoming.lens;
        //5BF1F0 overwrites its temporary rotated aim before any publication.
        parameters_.pose.aim=converted(incoming.endpoints[2][0]);
        return RoomCameraStatus::completed;
    }
    const auto ratio=asset.boundary_ratio(index,0,actor);if(!ratio)return RoomCameraStatus::unavailable;
    if(incoming.type==8){
        state.camera_target[0]=incoming.sequence_time+*ratio;
        if(!incoming.sequence_root)return RoomCameraStatus::unavailable;
        if(state.previous_camera==incoming.sequence_root){
            state.camera_progress[0]=state.camera_progress[0]+(state.camera_target[0]-state.camera_progress[0])/6.f;
            const auto value=state.camera_progress[0];
            const auto step=value>=2147483648.f?truncated(value-2147483648.f)|0x80000000u:truncated(value);
            const auto followed=asset.follow(*incoming.sequence_root,step);if(!followed)return RoomCameraStatus::unavailable;
            index=*followed;
        }else{state.previous_camera=incoming.sequence_root;state.camera_progress[0]=state.camera_target[0];}
        const auto& record=asset.records()[index];
        const float next=100000.f*fractional(state.camera_progress[0]),first=100000.f-next,t=next/100000.f;
        parameters_.pose.eye=quadratic(converted(record.endpoints[1][0]),record.first_control,converted(record.endpoints[1][1]),t);
        state.camera_anchors[index]=parameters_.pose.eye;
        lens_and_roll(parameters_,record,next,first);
        parameters_.pose.aim=quadratic(converted(record.endpoints[2][0]),record.last_control,converted(record.endpoints[2][1]),t);
        return RoomCameraStatus::completed;
    }
    state.camera_target[0]=*ratio;
    if(incoming.type==6||incoming.type==7){
        const auto second=asset.boundary_ratio(index,1,actor);if(!second)return RoomCameraStatus::unavailable;
        state.camera_target[1]=*second;
    }
    if(state.previous_camera!=index){state.previous_camera=index;state.camera_progress=state.camera_target;}
    else for(unsigned i=0;i<2;++i)state.camera_progress[i]=state.camera_progress[i]+(state.camera_target[i]-state.camera_progress[i])/6.f;
    const auto next=100000.f*state.camera_progress[0],first=100000.f-next;
    // Owned73E810 and73E7E0 select these branches, including the zero slots.
    switch(incoming.type){
    case 2:case 4:case 5:case 6:case 7:case 9:
        parameters_.pose.eye=weighted(incoming.endpoints[1],next,first);
        state.camera_anchors[index]=parameters_.pose.eye;lens_and_roll(parameters_,incoming,next,first);break;
    case 3:
        parameters_.pose.eye=converted(incoming.endpoints[1][0]);
        parameters_.pose.roll=incoming.parameters[2];parameters_.lens=incoming.lens;break;
    default:break;
    }
    switch(incoming.type){
    case 2:case 3:case 4:
        parameters_.pose.aim=weighted(incoming.endpoints[2],next,first);
        if(incoming.type==4){parameters_.pose.aim.x=actor.x;parameters_.pose.aim.z=actor.z;}break;
    case 5:parameters_.pose.aim=converted(incoming.endpoints[2][0]);break;
    case 6:case 7:{
        const auto second=100000.f*state.camera_progress[1];
        parameters_.pose.aim=weighted(incoming.endpoints[2],second,100000.f-second);
        if(incoming.type==7){
            const auto initial=converted(incoming.endpoints[2][0]);auto& anchor=state.camera_anchors[index];
            anchor={anchor.x+(parameters_.pose.aim.x-initial.x),anchor.y+(parameters_.pose.aim.y-initial.y),anchor.z+(parameters_.pose.aim.z-initial.z)};
            parameters_.pose.eye=anchor;
        }
        break;
    }
    case 9:parameters_.pose.aim={actor.x,100.f+actor.y,actor.z};break;
    default:break;
    }
    return RoomCameraStatus::completed;
}
RoomCameraStatus RoomCamera::update(gameplay_world::World& world,SceneModels& models,std::size_t count,
                                  Fog& fog,CameraDisplayBinding& display){
    auto& state=sequences_.state_;state.selection_changed=0;
    if(!state.initialized)return RoomCameraStatus::completed;
    if(!sequences_.records_||world.closed()||count>models.state().visibility.size())return RoomCameraStatus::unavailable;
    Vector position{};
    const auto actor_position=[&](){const auto actor=world.primary(state.actor);if(!actor)return false;
        position={actor->position.x,actor->position.y,actor->position.z};return finite(position);};
    const auto& asset=*sequences_.records_;std::uint8_t chosen=255,best=255;
    if(state.selection)chosen=state.selected_id;
    else for(int i=0;i<state.count;++i)if(state.active[std::size_t(i)]){
        if(!actor_position())return RoomCameraStatus::unavailable;
        const auto inside=asset.contains(std::uint8_t(i),position);if(!inside)return RoomCameraStatus::unsupported_numeric;
        if(!*inside)continue;
        const auto priority=asset.records()[std::size_t(i)].interpolation;
        if(best==255||priority>best){best=priority;chosen=std::uint8_t(i);}
        else if(priority==best&&state.condition_id==i)chosen=std::uint8_t(i);
    }
    if(chosen==255){
        if(state.condition_id!=255){display.publish(parameters_);return RoomCameraStatus::completed;}
        chosen=0;
    }
    if(chosen>=RoomCameraRecords::capacity||(state.condition_id!=255&&state.condition_id>=RoomCameraRecords::capacity))return RoomCameraStatus::unavailable;
    if(chosen==state.condition_id){if(state.progress<255)++state.progress;}
    else{
        if(state.condition_id!=255&&asset.records()[chosen].interpolation<asset.records()[state.condition_id].interpolation&&state.progress<8){
            ++state.progress;display.publish(parameters_);return RoomCameraStatus::completed;
        }
        //5BEE98 skips the one-shot write when there was no previous camera.
        state.selection_changed=std::uint8_t(state.condition_id!=255);state.condition_id=chosen;state.progress=0;
        const auto& record=asset.records()[chosen];
        if(fog.select(record.policy)!=FogStatus::completed)return RoomCameraStatus::unavailable;
        for(std::size_t i=0;i<count;++i){
            const auto visible=(std::to_integer<unsigned>(record.view_controls[i/8])>>(i%8))&1u;
            models.mark_slot_byte(std::uint8_t(i),std::uint8_t((models.state().visibility[i]&0xfeu)|visible));
        }
        std::uint32_t first,second;std::memcpy(&first,record.auxiliary.data(),4);std::memcpy(&second,record.auxiliary.data()+4,4);
        state.view_masks.first=first;state.view_masks.second=second;
    }
    //5BEFD8 is also reached when selection is unchanged. These flags are
    // republished on every evaluated frame, unlike the switch-only masks.
    const auto hide=asset.records()[chosen].extra[0];auto& session=world.session();
    session.resource_hide_selected=std::uint8_t(hide&1u);session.resource_hide_others=std::uint8_t((hide>>1)&1u);
    for(unsigned i=0;i<2;++i)session.resource_hide_remaining[i]=std::uint8_t((hide>>(i+2))&1u);
    if(asset.records()[chosen].type!=1&&!actor_position())return RoomCameraStatus::unavailable;
    const auto result=evaluate(chosen,position,display);if(result!=RoomCameraStatus::completed)return result;
    if(!finite(parameters_.pose.eye)||!finite(parameters_.pose.aim)||!std::isfinite(parameters_.lens))return RoomCameraStatus::unsupported_numeric;
    display.publish(parameters_);return RoomCameraStatus::completed;
}
}
