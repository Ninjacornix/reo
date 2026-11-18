#include "game/native/gameplay_lighting/transient_lights.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace l=reo::native::gameplay_lighting;
unsigned checks{},cases{},calls{},released{},retirements{};
#ifdef REO_PROJECTILE_LIGHT_OWNER
bool projectile_floor_port(std::uint8_t*,R5900Context*);
#endif
std::array<bool,2> release_mask;bool task_retired{};
#ifdef REO_TRANSIENT_OWNER
extern bool transient_owner_mode;
bool transient_owner_port(std::uint8_t*,R5900Context*);
#endif
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Transient light check "+std::to_string(at.line()));
}
template<class T>T get(const std::uint8_t* memory,unsigned address){return transform_read<T>(memory,address);}
template<class T>void put(std::uint8_t* memory,unsigned address,T value){transform_write(memory,address,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
#ifdef REO_PROJECTILE_LIGHT_OWNER
    if(projectile_floor_port(memory,context)){context->pc=GPR_U32(context,31);return;}
#endif
#ifdef REO_TRANSIENT_OWNER
    if(transient_owner_mode){
        if(transient_owner_port(memory,context)){context->pc=GPR_U32(context,31);return;}
        switch(context->pc){
#include "original_dispatch.hpp"
        default:throw std::runtime_error("Unadmitted transient owner helper "+std::to_string(context->pc));
        }
    }
#endif
    switch(context->pc){
#ifdef REO_AUXILIARY_LIGHT_POOL
    case 0x107c68:{const auto dst=GPR_U32(context,4),bytes=GPR_U32(context,6);check(dst>=0x748350&&dst<0x748350+64*56&&(dst-0x748350)%56==0&&bytes==56&&GPR_U32(context,5)==0);std::memset(memory+dst,0,bytes);SET_GPR_U32(context,2,dst);break;}
    case 0x107ab0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),bytes=GPR_U32(context,6);check(dst>=0x748354&&dst<0x748350+64*56&&(dst-0x748354)%56==0&&bytes==52&&src==0x100000);std::memcpy(memory+dst,memory+src,bytes);SET_GPR_U32(context,2,dst);break;}
#endif
    case 0x6b3020:check(GPR_U32(context,4)==0x20000);release_mask[0]=true;break;
    case 0x6b2c50:check(GPR_U32(context,4)==0x21000);release_mask[1]=true;break;
    case 0x573740:check(GPR_U32(context,4)==0x10000);task_retired=true;break;
    default:
        switch(context->pc){
#include "original_dispatch.hpp"
        default:throw std::runtime_error("Unadmitted transient helper "+std::to_string(context->pc));
        }
    }
    context->pc=GPR_U32(context,31);
}
void call(std::uint8_t* memory,unsigned address){
    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);
    SET_GPR_U32(&context,4,address);context.pc=0x5d83d0;original_transform_port(memory,&context,&runtime);check(context.pc==0x1234);
}
#ifdef REO_AUXILIARY_LIGHT_POOL
#include "tools/native_reconstruction/auxiliary_lighting_tests.inc"
#endif
#ifdef REO_TRANSIENT_OWNER
#include "tools/native_reconstruction/transient_lights_owner_tests.inc"
#endif
#ifdef REO_PROJECTILE_LIGHT_OWNER
#include "tools/native_reconstruction/projectile_lights_owner_tests.inc"
#endif
int main(int argc,char** argv)try{
    (void)argc;(void)argv;
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    const auto definition=l::transient_definition({1,-2,3});auto expected=get<l::Definition>(memory.data(),0x720240);expected.position={1,-2,3};
    check(std::memcmp(&definition,&expected,sizeof definition)==0);
    for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned mask=0;mask<4;++mask)for(unsigned bits=0;bits<65536;++bits){
        l::TransientState state;state.phase=std::uint8_t(phase);state.remaining={std::bit_cast<std::int16_t>(std::uint16_t(bits)),std::bit_cast<std::int16_t>(std::uint16_t(bits*257u))};
        memory[0x10008]=state.phase;put(memory.data(),0x1000c,state.remaining[0]);put(memory.data(),0x1000e,state.remaining[1]);
        put(memory.data(),0x10028,mask&1?0x20000u:0u);put(memory.data(),0x10024,mask&2?0x21000u:0u);
        put(memory.data(),0x20030,123.0f);put(memory.data(),0x21030,-456.0f);release_mask={};task_retired=false;
        call(memory.data(),0x10000);const auto actual=l::advance_transient_light(state,{bool(mask&1),bool(mask&2)});
        check(state.phase==memory[0x10008]&&state.remaining[0]==get<std::int16_t>(memory.data(),0x1000c)&&state.remaining[1]==get<std::int16_t>(memory.data(),0x1000e));
        check(actual.retire==task_retired&&actual.release==release_mask);
        for(unsigned i=0;i<2;++i){
            const auto source=get<float>(memory.data(),i?0x21030:0x20030);
            if(actual.attenuation[i])check(std::bit_cast<unsigned>(*actual.attenuation[i])==std::bit_cast<unsigned>(source));
            else check(source==(i?-456.0f:123.0f));
            if(actual.release[i])++released;
        }
        if(actual.retire)++retirements;
        ++cases;
    }
#ifdef REO_AUXILIARY_LIGHT_POOL
    compare_auxiliary_lighting(memory.data());
#endif
#ifdef REO_TRANSIENT_OWNER
    compare_transient_owner(memory.data());
#endif
#ifdef REO_PROJECTILE_LIGHT_OWNER
    check(argc==2);compare_projectile_lights(memory.data(),argv[1]);
#endif
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"releases\":"<<released<<",\"retirements\":"<<retirements
#ifdef REO_AUXILIARY_LIGHT_POOL
        <<",\"auxiliary_allocations\":"<<auxiliary_light_allocations<<",\"auxiliary_releases\":"<<auxiliary_light_releases<<",\"auxiliary_refusals\":"<<auxiliary_light_refusals
#endif
#ifdef REO_TRANSIENT_OWNER
        <<",\"owner_cases\":"<<transient_owner_cases<<",\"owner_frames\":"<<transient_owner_frames<<",\"owner_refusals\":"<<transient_owner_refusals
#endif
#ifdef REO_PROJECTILE_LIGHT_OWNER
        <<",\"projectile_cases\":"<<projectile_cases<<",\"projectile_frames\":"<<projectile_frames<<",\"floor_queries\":"<<projectile_queries<<",\"floor_hits\":"<<projectile_hits
#endif
        <<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
