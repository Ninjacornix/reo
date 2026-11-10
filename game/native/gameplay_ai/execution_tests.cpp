#include "execution.hpp"
#include "control_requests.hpp"
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
    return result;
}
#ifdef REO_AI_ORIGINAL
std::vector<std::uint8_t> memory(0x2000000);
template<class T>void put(std::vector<std::uint8_t>& target,unsigned at,T value){check(at+sizeof(T)<=target.size());std::memcpy(target.data()+at,&value,sizeof(T));}
void project(std::vector<std::uint8_t>& target,const ai::ExecutionState& s){
    constexpr unsigned a=0x10000;
    put(target,a+0xff4,s.goal);put(target,a+0xff6,s.previous_goal);put(target,a+0xff8,s.action);put(target,a+0xffa,s.previous_action);
    for(unsigned i=0;i<4;++i){target[a+0xffc+i]=s.goal_phases[i];put(target,a+0x1000+2*i,s.goal_parameters[i]);target[a+0x1008+i]=s.action_phases[i];}
    target[a+0x1074]=s.goal_refresh;target[a+0x103a]=s.action_marker;
    target[a+0x1067]=s.weight_profile.value_or(255);put(target,a+0x10ac,s.weight_profile?0x828a60u+56u*(*s.weight_profile):0u);
    for(unsigned i=0;i<8;++i){target[a+0x10b0+i]=s.base_weights[i];target[a+0x10b8+i]=s.reactive_weights[i];target[a+0x10c0+i]=s.status_weights[i];target[a+0x10c8+i]=s.combined_weights[i];}
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
}
#ifdef REO_AI_ORIGINAL
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
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
        check(argc==2);std::ifstream file(argv[1],std::ios::binary);check(bool(file));std::vector<std::uint8_t> overlay{std::istreambuf_iterator<char>(file),{}};check(overlay.size()==113152);std::memcpy(memory.data()+0x810000,overlay.data(),overlay.size());
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
        std::cout<<"{\"checks\":"<<checks<<",\"goal_cases\":"<<goal_cases<<",\"action_cases\":"<<action_cases<<",\"phase_cases\":"<<phase_cases<<",\"finish_cases\":"<<finish_cases<<",\"profile_cases\":"<<profile_cases<<",\"profile_refusals\":"<<profile_refusals<<",\"copies\":"<<copies<<",\"clears\":"<<clears<<",\"control_membership_cases\":"<<control_membership_cases<<",\"control_register_cases\":"<<control_register_cases<<",\"control_unregister_cases\":"<<control_unregister_cases<<",\"control_lookup_cases\":"<<control_lookup_cases<<",\"control_request_cases\":"<<control_request_cases<<",\"control_publish_cases\":"<<control_publish_cases<<"}\n";
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
