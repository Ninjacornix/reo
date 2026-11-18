#include "actor_contact_channels.hpp"
#include <array>
#include <bit>
namespace reo::native::gameplay_effects {
namespace {
std::int16_t add(std::int16_t a,int b){return std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(a)+b));}
}
std::optional<ActorContactProfile> actor_contact_profile(std::uint32_t mode,std::uint32_t variant)noexcept{
    constexpr std::array<ActorContactProfile,8> profiles{{{19,0,1},{19,1,1},{19,2,1},{10,0,1},{13,0,3},{13,1,3},{13,2,3},{13,3,3}}};
    const auto index=std::uint64_t(mode)+std::uint64_t(variant&0x7fffffffu);
    return index<profiles.size()?std::optional(profiles[std::size_t(index)]):std::nullopt;
}
ActorContactStep advance_actor_contact(ActorContactState& state,std::uint8_t primary,std::uint8_t secondary,ActorContactOperations& operations){
    if(state.phase==2)return{true,true};
    if(state.phase>1)return{};
    if(state.phase==0){state.phase=1;state.visible=true;state.clone_timer=5;state.parent_left=false;}
    if(!state.parent_left&&(primary!=2||secondary!=2))state.parent_left=true;
    if(state.pose_phase==0){state.pose_phase=1;state.visible=true;state.position=state.base_position;}
    else if(state.pose_phase!=1)return{};
    if(!state.clone){
        if(state.visible){state.remaining=add(state.remaining,-1);if(state.remaining<0)state.visible=false;}
        if(state.parent_left){++state.phase;state.pose_phase=0;state.visible=false;return{};}
        state.clone_timer=add(state.clone_timer,-1);
        if(state.clone_timer<=0){
            state.clone_timer=5;state.cycle=add(state.cycle,1);if(state.cycle>=4)state.cycle=0;
            if(!operations.rebind(state))return{false,false};
            const auto result=operations.clone(state,std::uint32_t(std::int32_t(state.cycle))|0x80000000u);
            if(result==WorkStatus::unavailable)return{false,false};
        }
    }else{
        state.remaining=add(state.remaining,-1);
        if(state.remaining<0){++state.phase;state.pose_phase=0;state.visible=false;return{};}
    }
    if(!operations.sample(state))return{false,false};
    state.age=add(state.age,2);return{};
}
}
