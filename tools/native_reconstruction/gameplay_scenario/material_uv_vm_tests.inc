#include "game/native/gameplay_world/material_uv.hpp"
namespace {
std::size_t material_uv_calls{};
void material_uv_tests(){
    namespace w=reo::native::gameplay_world;
    std::vector<std::uint8_t> ram(0x900000);
    const auto compare=[&](w::MaterialAnimationState& state,w::MaterialUv& uv){
        std::array<std::uint8_t,64> task;task.fill(0xa5);
        std::array<std::uint8_t,0xd90> actor;actor.fill(0x5a);
        const auto put=[](auto& bytes,unsigned offset,auto value){std::memcpy(bytes.data()+offset,&value,sizeof(value));};
        put(task,1,state.presentation_mask);put(task,8,state.phase);put(task,9,state.subphase);
        put(task,12,state.first);put(task,14,state.second);put(task,40,0xa0000u);
        put(actor,0xd24,uv.u);put(actor,0xd28,uv.v);
        std::memcpy(ram.data()+0x90000,task.data(),task.size());
        std::memcpy(ram.data()+0xa0000,actor.data(),actor.size());
        invoke_npc_original(ram,o2_005D0C90_0x5d0c90,{0x90000,0,0,0});
        w::advance_material_uv(state,uv);
        put(task,1,state.presentation_mask);put(task,8,state.phase);put(task,9,state.subphase);
        put(task,12,state.first);put(task,14,state.second);
        put(actor,0xd24,uv.u);put(actor,0xd28,uv.v);
        check(std::memcmp(ram.data()+0x90000,task.data(),task.size())==0);
        check(std::memcmp(ram.data()+0xa0000,actor.data(),actor.size())==0);
        ++material_uv_calls;
    };
    for(unsigned phase=0;phase<256;++phase){
        assertion_context="Material UV phase="+std::to_string(phase);
        w::MaterialAnimationState state{std::uint8_t(phase),255,0x87,-32768,32767};
        w::MaterialUv uv{std::bit_cast<float>(0x7fc12345u),-123.5f};compare(state,uv);
    }
    for(unsigned bits=0;bits<65536;++bits){
        assertion_context="Material UV timer bits="+std::to_string(bits);
        w::MaterialAnimationState state{1,std::uint8_t(bits),std::uint8_t(bits>>8),
            std::bit_cast<std::int16_t>(std::uint16_t(bits)),
            std::bit_cast<std::int16_t>(std::uint16_t(bits*31337u))};
        w::MaterialUv uv{-1,2};compare(state,uv);
    }
    w::MaterialAnimationState state;w::MaterialUv uv{-17,31};
    for(unsigned update=0;update<1802;++update){
        assertion_context="Material UV continuous update="+std::to_string(update);compare(state,uv);
    }
}
}
