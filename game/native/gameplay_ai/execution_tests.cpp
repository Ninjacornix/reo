#include "execution.hpp"
#include "control_requests.hpp"
#include "initialization.hpp"
#include "priority_goals.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_session/activity.hpp"
#include <bit>
#include <cstring>
#include <fstream>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
#ifdef REO_AI_ORIGINAL
#include "reference.hpp"
#include "functions.h"
#endif
namespace ai=reo::native::gameplay_ai;
namespace {
std::uint64_t checks{},goal_cases{},action_cases{},phase_cases{},finish_cases{},profile_cases{},profile_refusals{},copies{},clears{};
std::uint64_t reference_goal_sets{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("AI execution check at "+std::to_string(at.line()));
}
ai::ExecutionState state(unsigned seed){
    ai::ExecutionState result;result.goal=std::uint16_t(seed*43);result.previous_goal=std::uint16_t(seed*67+1);
    result.action=std::uint16_t(seed*13+2);result.previous_action=std::uint16_t(seed*71+3);
    result.goal_refresh=std::uint8_t(seed+7);result.action_marker=std::uint8_t(seed+11);
    for(unsigned i=0;i<4;++i){result.goal_phases[i]=std::uint8_t(seed+i);result.action_phases[i]=std::uint8_t(seed*3+i);result.goal_parameters[i]=std::uint16_t(seed*7+i);}
    if(seed&1)result.weight_profile=std::uint8_t(seed%20);
    for(unsigned i=0;i<8;++i){result.base_weights[i]=std::uint8_t(seed+i);result.reactive_weights[i]=std::uint8_t(seed*3+i);result.status_weights[i]=std::uint8_t(seed*7+i);result.combined_weights[i]=std::uint8_t(seed*11+i);}
    result.inhibited=std::uint8_t(seed+13);result.reaction=std::uint8_t(seed+17);result.pending_reaction=std::uint8_t(seed+19);result.observation_flags=std::uint8_t(seed+23);
    result.periodic_counter=std::uint16_t(seed*17);result.room_memo=std::uint16_t(seed*19);result.reaction_countdown=std::uint16_t(seed*23);result.action_counter=seed*67u;result.forced_priority=std::bit_cast<std::int32_t>(seed*97u);
    result.peer_priority=std::uint8_t(seed+29);result.reference_request=std::uint8_t(seed+31);result.owned_request=std::uint16_t(seed*29);result.goal_resource=0xdead0000u+seed;
    return result;
}
#ifdef REO_AI_ORIGINAL
std::vector<std::uint8_t> memory(0x2000000);
template<class T>void put(std::vector<std::uint8_t>& target,unsigned at,T value){check(at+sizeof(T)<=target.size());std::memcpy(target.data()+at,&value,sizeof(T));}
void project(std::vector<std::uint8_t>& target,const ai::ExecutionState& s,unsigned a=0x10000){
    put(target,a+0xff4,s.goal);put(target,a+0xff6,s.previous_goal);put(target,a+0xff8,s.action);put(target,a+0xffa,s.previous_action);
    for(unsigned i=0;i<4;++i){target[a+0xffc+i]=s.goal_phases[i];put(target,a+0x1000+2*i,s.goal_parameters[i]);target[a+0x1008+i]=s.action_phases[i];}
    target[a+0x1074]=s.goal_refresh;target[a+0x103a]=s.action_marker;
    target[a+0x1067]=s.weight_profile.value_or(255);put(target,a+0x10ac,s.weight_profile?0x828a60u+56u*(*s.weight_profile):0u);
    for(unsigned i=0;i<8;++i){target[a+0x10b0+i]=s.base_weights[i];target[a+0x10b8+i]=s.reactive_weights[i];target[a+0x10c0+i]=s.status_weights[i];target[a+0x10c8+i]=s.combined_weights[i];}
    target[a+0xff1]=s.inhibited;target[a+0x1098]=s.reaction;target[a+0x1099]=s.pending_reaction;target[a+0x1083]=s.observation_flags;
    put(target,a+0x1072,s.periodic_counter);put(target,a+0x107c,s.room_memo);put(target,a+0x109a,s.reaction_countdown);put(target,a+0x1034,s.action_counter);put(target,a+0x109c,s.forced_priority);
    target[a+0x1080]=s.reference_request;target[a+0x1081]=s.peer_priority;put(target,a+0x108a,s.owned_request);put(target,a+0x1090,s.goal_resource);
}
#endif
void compare(unsigned pc,std::uint32_t argument,ai::ExecutionState before){
    auto actual=before;std::uint32_t returned=~0u;auto status=ai::Status::completed;
    switch(pc){
    case 0x813380:ai::set_goal(actual,argument);break;
    case 0x81a6e0:ai::set_action(actual,argument);break;
    case 0x81a6f0:ai::clear_action_phases(actual);break;
    case 0x814b30:returned=ai::finish_goal_six(actual);break;
    case 0x8123e0:status=ai::select_weight_profile(actual,std::bit_cast<std::int32_t>(argument));break;
    default:throw std::runtime_error("Undeclared native AI test entry");
    }
    if(status!=ai::Status::completed){check(actual==before);++profile_refusals;return;}
#ifdef REO_AI_ORIGINAL
    project(memory,before);auto expected=std::vector<std::uint8_t>(memory.begin(),memory.begin()+0x11100);project(expected,actual);
    R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,5,argument);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);
    check(std::memcmp(expected.data()+0x10000,memory.data()+0x10000,0x1100)==0);
    if(pc==0x814b30)check(returned==GPR_U32(&context,2));
#else
    (void)returned;
#endif
    if(pc==0x813380)++goal_cases;else if(pc==0x81a6e0)++action_cases;else if(pc==0x81a6f0)++phase_cases;else if(pc==0x814b30)++finish_cases;else ++profile_cases;
}
#include "control_request_tests.inc"
#include "activity_tests.inc"
#include "initialization_tests.inc"
#include "priority_goal_tests.inc"
}
#ifdef REO_AI_ORIGINAL
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x1afe70)++activity_queries;
    if(context->pc==0x813380)++reference_goal_sets;
    if(context->pc==0x107ab0){check(GPR_U32(context,4)==0x110b0&&GPR_U32(context,6)==8);++copies;}
    switch(context->pc){
    case 0x107c68:{const auto at=GPR_U32(context,4);check((at==0x110b8||at==0x110c0)&&GPR_U32(context,5)==0&&GPR_U32(context,6)==8);std::memset(memory+at,0,8);++clears;SET_GPR_U32(context,2,at);context->pc=GPR_U32(context,31);return;}
#include "dispatch.inc"
    default:throw std::runtime_error("Undeclared AI original dependency "+std::to_string(context->pc));
    }
}
#endif
int main(int argc,char** argv){
    try{
#ifdef REO_AI_ORIGINAL
        check(argc==3);std::ifstream file(argv[1],std::ios::binary);check(bool(file));std::vector<std::uint8_t> overlay{std::istreambuf_iterator<char>(file),{}};check(overlay.size()==113152);std::memcpy(memory.data()+0x810000,overlay.data(),overlay.size());
        std::ifstream other_file(argv[2],std::ios::binary);check(bool(other_file));std::vector<std::uint8_t> other{std::istreambuf_iterator<char>(other_file),{}};check(0x570000+other.size()<memory.size());std::memcpy(memory.data()+0x570000,other.data(),other.size());
        for(unsigned i=0;i<20;++i){const auto profile=ai::weight_profile(std::uint8_t(i));check(profile&&std::memcmp(profile->base.data(),overlay.data()+0x828a60-0x810000+56*i,8)==0&&std::memcmp(profile->policy.data(),overlay.data()+0x828a60-0x810000+56*i+8,48)==0);}
#else
        (void)argc;(void)argv;
#endif
        for(unsigned i=0;i<65536;++i){
            for(unsigned upper:{0u,0xffff0000u}){compare(0x813380,i|upper,state(i));compare(0x81a6e0,i|upper,state(i+1));}
            compare(0x814b30,0,state(i+3));
        }
        for(unsigned i=0;i<256;++i){compare(0x81a6f0,0,state(i));compare(0x8123e0,i,state(i));check((ai::weight_profile(std::uint8_t(i))!=nullptr)==(i<20));}
        for(std::int32_t invalid:{-1,-20,-256,INT32_MIN})compare(0x8123e0,std::uint32_t(invalid),state(17));
        // Full halfword gate:256 is nonzero, while65536 resets the goal.
        auto halfword=state(42);const auto previous=halfword.previous_goal;ai::set_goal(halfword,256);check(halfword.goal==256&&halfword.goal_refresh==0&&halfword.previous_goal==previous);
        ai::set_goal(halfword,65536);check(halfword.goal==0&&halfword.goal_refresh==1&&halfword.previous_goal==256);
        control_contracts();
        control_receive_contracts();
        activity_contracts();
        initialization_contracts();
        priority_goal_contracts();
        std::cout<<'{';bool first=true;
        const auto emit=[&](const char* key,std::uint64_t value){if(!first)std::cout<<',';first=false;std::cout<<'"'<<key<<"\":"<<value;};
        emit("checks",checks);emit("goal_cases",goal_cases);emit("action_cases",action_cases);emit("phase_cases",phase_cases);emit("finish_cases",finish_cases);
        emit("profile_cases",profile_cases);emit("profile_refusals",profile_refusals);emit("copies",copies);emit("clears",clears);
        emit("control_membership_cases",control_membership_cases);emit("control_register_cases",control_register_cases);emit("control_unregister_cases",control_unregister_cases);
        emit("control_lookup_cases",control_lookup_cases);emit("control_request_cases",control_request_cases);emit("control_publish_cases",control_publish_cases);
        emit("control_apply_cases",control_apply_cases);emit("control_receive_cases",control_receive_cases);emit("control_receive_refusals",control_receive_refusals);
        emit("activity_queries",activity_queries);emit("activity_mode_cases",activity_mode_cases);emit("activity_mode_refusals",activity_mode_refusals);
        emit("initialization_cases",initialization_cases);emit("initialization_disabled",initialization_disabled);emit("initialization_limited",initialization_limited);emit("initialization_refusals",initialization_refusals);
        emit("goal_resource_cases",goal_resource_cases);emit("target_busy_cases",target_busy_cases);emit("goal_reevaluation_cases",goal_reevaluation_cases);emit("goal_reevaluation_writes",goal_reevaluation_writes);emit("goal_reevaluation_refusals",goal_reevaluation_refusals);emit("goal_alias_cases",goal_alias_cases);
        std::cout<<"}\n";
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
