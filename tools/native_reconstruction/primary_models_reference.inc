#include "primary_models_reference.hpp"
namespace {
constexpr std::uint32_t reference_actor=0x100000;
std::vector<std::uint8_t> cache_memory(0x2000000);
std::vector<std::uint32_t> cache_trace;
unsigned reference_releases{},reference_loads{},reference_initializations{},reference_slot{},reference_character{},reference_class{};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;const auto at=context->pc;
    if(at==0x5ec100){o2_005EC100_0x5ec100(memory,context,runtime);return;}
    if(at==0x5ec010){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_slot&&GPR_U32(context,5)==reference_actor);o2_005EC010_0x5ec010(memory,context,runtime);return;}
    if(at==0x5ebfe0){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_actor);o2_005EBFE0_0x5ebfe0(memory,context,runtime);return;}
    if(at==0x1d1c40){sub_001D1C40_0x1d1c40(memory,context,runtime);return;}
    if(at==0x5ec0e0){cache_trace.push_back(at);check(GPR_U32(context,4)==memory[0x7434b4+2*reference_slot]);++reference_releases;}
    else if(at==0x1aa740){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_slot&&GPR_U32(context,5)==reference_actor);++reference_loads;}
    else if(at==0x66a750){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_actor&&GPR_U32(context,5)==reference_character);++reference_initializations;}
    else if(at==0x18dcb0)cache_trace.push_back(at);
    else if(at==0x1cd080){const auto old_class=memory[0x7434b5+2*reference_slot];check(GPR_U32(context,4)==8*reference_slot+(old_class==1?0x1100:0x1000)&&GPR_U32(context,5)==8);}
    else if(at==0x1b2280){check(memory[0x7434b5+2*reference_slot]==1);}
    else throw std::runtime_error("Undeclared primary-cache original port "+std::to_string(at));
    context->pc=GPR_U32(context,31);
}
namespace {
void compare_cache(const Keys& before,const Keys& after,unsigned slot,std::uint8_t character,std::uint8_t model_class,std::uint8_t loading,std::int8_t pause,const g::PrimaryModelApplied& result){
    auto* memory=cache_memory.data();reference_slot=slot;reference_character=character;reference_class=model_class;
    for(unsigned i=0;i<8;++i){memory[0x7434b4+2*i]=before[i].character;memory[0x7434b5+2*i]=before[i].model_class;}
    std::memset(memory+reference_actor,0,0x10e0);memory[reference_actor+1]=1;memory[reference_actor+3]=std::uint8_t(slot);memory[reference_actor+0xb98]=character;memory[reference_actor+0x54d]=model_class;
    memory[0x3243d7]=loading;transform_write(memory,0x4badf8,pause);cache_trace.clear();reference_loads=reference_releases=reference_initializations=0;
    R5900Context context;PS2Runtime runtime;context.pc=0x5ec100;SET_GPR_U32(&context,4,slot);SET_GPR_U32(&context,5,reference_actor);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
    original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);
    for(unsigned i=0;i<8;++i)check(after[i].character==memory[0x7434b4+2*i]&&after[i].model_class==memory[0x7434b5+2*i]);
    check(result.replaced==(reference_loads!=0)&&result.character_released==(reference_releases!=0)&&reference_initializations==unsigned(!result.replaced));
    if(result.replaced){
        std::vector<std::uint32_t> expected;if(before[slot].character!=255)expected={0x5ec010,0x5ec0e0,0x18dcb0};expected.push_back(0x1aa740);
        if(std::none_of(before.begin(),before.end(),[&](auto key){return key.character==character;}))expected.push_back(0x5ebfe0);
        expected.push_back(0x18dcb0);check(cache_trace==expected);
    }else check(cache_trace==std::vector<std::uint32_t>{0x66a750});
    ++original_cases;
}
}
