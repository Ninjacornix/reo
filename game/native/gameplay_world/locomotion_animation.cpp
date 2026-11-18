#include "locomotion_animation.hpp"
#include "../transform_math/heading.hpp"
#include <bit>
#include <algorithm>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "locomotion_transition_profile.inc"
animation::Playback& playback(Actor& actor){
    if(!actor.animation||!actor.model||actor.animation->model()!=actor.model)
        throw std::runtime_error("Native locomotion playback unavailable");
    return *actor.animation;
}
// Owned File1 o2 SHA45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
// Halfwords71BD60; selector thresholds70B000.7404B0 maps all six motions
//2010..2015 to66BF78. These are authored motion identities, not guest pointers.
constexpr std::array<std::array<std::uint16_t,3>,4> floor_motions{{
    {{0x2003,0x2004,0x2005}},{{0x2012,0x2014,0x2012}},
    {{0x2015,0x2011,0x2015}},{{0,0,0}}
}};
void retain_previous_motion(animation::Playback& state){
    state.channel(animation::ModelBank::secondary,0)=state.channel(animation::ModelBank::primary,0);
    //5D43C0 copies binding pointers and sampling caches, not the primary clear.
    if(state.secondary_model())animation::PoseBlend::capture_links(*state.secondary_model(),*state.model(),0);
}
}
std::uint8_t locomotion_floor_variant(const Actor& actor,const gameplay_collision::response::Grid& floors){
    const auto probe=probe_locomotion_floor(actor,floors);
    if(probe.type!=1)return 255;
    const auto normal=floors.floor({probe.probe.x,probe.probe.y,probe.probe.z}).normal;
    //616FA0's matrix up column transformed by1919D0's (0,1,0).
    const auto heading=transform_math::direction_turn(normal.x,normal.z);
    const auto delta=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(actor.orientation[1])-heading));
    const auto absolute=std::uint16_t(std::abs(int(delta)));
    return absolute<0x3000?2:absolute<0x5000?0:1;
}
void select_floor_locomotion(Actor& actor,std::uint8_t mode,const gameplay_collision::response::Grid& floors,ActionAnimation& actions){
    if(actor.phase==255)return;
    const auto probe=probe_locomotion_floor(actor,floors);
    if(mode>=3)throw std::out_of_range("Native floor locomotion mode unavailable");
    auto& state=playback(actor);
    const auto desired=std::uint8_t(mode+1);
    std::uint16_t motion{};float initial{};
    if(probe.type==1){
        motion=floor_motions[locomotion_floor_variant(actor,floors)&3u][mode];
        if(state.motion==motion){actor.phase=1;return;}
        if(actor.motion_class==desired){initial=actions.matched_frame(actor,motion,0);retain_previous_motion(state);}
        else state.channel(animation::ModelBank::secondary,0)={};
    }else{
        if(state.motion<0x2010||state.motion>0x2015)return;
        motion=floor_motions[0][mode];initial=actions.matched_frame(actor,motion,0);retain_previous_motion(state);
    }
    actor.motion_rate=1;
    if(!actor.primary_state)throw std::runtime_error("Native locomotion statistic unavailable");
    actor.motion_rate=actor.motion_rate*actor.primary_state->statistic_multiplier;
    actions.or_flags(actor);actions.select(actor,motion,initial,30);actions.activate(actor);
    actor.motion_class=desired;actor.phase=2;
}
void advance_floor_locomotion(Actor& actor,std::uint8_t clock_mode,const gameplay_collision::response::Grid& floors){
    if(probe_locomotion_floor(actor,floors).type==1)playback(actor).advance_locomotion_blend(actor.motion_rate,clock_mode);
}
void finish_locomotion_step(Actor& actor,std::uint8_t clock_mode){
    auto& state=playback(actor);
    const auto sample=actor.model->local_translation(2);
    if(actor.character){if(!(actor.root_motion_delta.z<10))actor.root_motion_delta.z=10;return;}
    const auto& channel=state.channel(animation::ModelBank::primary,0);
    if(channel.selector!=0x67||(channel.timing.flags&0x20)||!(channel.timing.frame<=channel.timing.restart))return;
    if(!actor.locomotion)throw std::runtime_error("Native locomotion root history unavailable");
    auto& previous=actor.locomotion->root_sample_z;
    if(channel.timing.frame<3.f-float(clock_mode?1:2))previous=sample.z;
    if(channel.timing.flags&2)return;
    const float delta=sample.z-previous;
    previous=actor.model->local_translation(2).z;
    actor.model->local_translation(2,{sample.x,sample.y,0});
    actor.root_motion_delta.z=actor.root_motion_delta.z+delta;
    if(!(actor.root_motion_delta.z<10))actor.root_motion_delta.z=10;
    if(actor.root_motion_delta.z<0)actor.root_motion_delta.z=0;
}
float locomotion_transition_frame(Actor& actor,std::uint16_t motion,ActionAnimation& actions){
    const auto matched=[&]{return actions.matched_frame(actor,motion,0);};
    if(actor.resource_action){
        if(actor.resource_action>=locomotion_resource_classes.size())throw std::out_of_range("Native locomotion resource class unavailable");
        if(locomotion_resource_classes[actor.resource_action])return matched();
    }
    constexpr std::array<std::uint16_t,4> ids{0x2003,0x2005,0x2010,0x2013};
    const auto current=std::uint16_t(playback(actor).motion);
    const auto from=std::find(ids.begin(),ids.end(),current),to=std::find(ids.begin(),ids.end(),motion);
    if(from==ids.end()||to==ids.end())return matched();
    //74F100 lies outside the owned o2 file. Its class2 producer must be
    //qualified before supplying entries; unknown memory is not a zero table.
    if(actor.class_marker==2)throw std::runtime_error("Native injured locomotion transition table unavailable");
    if(actor.class_marker>2)return matched();
    const auto index=std::size_t(from-ids.begin())*4+std::size_t(to-ids.begin());
    if(index!=1&&index!=4)return matched();
    if(actor.character>=8)throw std::out_of_range("Native locomotion character unavailable");
    const auto& mapping=locomotion_intervals[index==1?0:1][actor.character];
    float selected=0;
    const auto frame=playback(actor).channel(animation::ModelBank::primary,0).timing.frame;
    for(unsigned i=0;i<mapping.count;++i){const auto& row=mapping.rows[i];
        if(frame<float(row[0])||!(frame<float(row[1])))continue;
        const float fraction=(frame-float(row[0]))/float(int(row[1])-row[0]);
        selected=float(row[2])+fraction*float(int(row[3])-row[2]);
    }
    if(selected==0)return matched();
    return selected<=actions.last_frame(actor,motion,0)?selected:matched();
}
}
