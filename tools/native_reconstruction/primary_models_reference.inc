#include "primary_models_reference.hpp"
namespace {
constexpr std::uint32_t reference_actor=0x100000;
std::vector<std::uint8_t> cache_memory(0x2000000);
std::vector<std::uint32_t> cache_trace;
unsigned reference_releases{},reference_loads{},reference_initializations{},reference_slot{},reference_character{},reference_class{};
bool reference_scene{};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;const auto at=context->pc;
    if(reference_scene){
        if(at==0x5f0610){o2_005F0610_0x5f0610(memory,context,runtime);return;}
        if(at==0x663170){o2_00663170_0x663170(memory,context,runtime);return;}
        if(at==0x5f0b50){o2_005F0B50_0x5f0b50(memory,context,runtime);return;}
        if(at==0x5ec100){
            check(GPR_U32(context,4)==0&&GPR_U32(context,5)==reference_actor);
            const auto scale=g::primary_actor_default(memory[reference_actor+0xb98]).scale;
            transform_write(memory,reference_actor+0xb4,scale);
        }else if(at!=0x5f0dc0&&at!=0x5f0c00&&at!=0x5d6850)
            throw std::runtime_error("Undeclared primary-scene original port "+std::to_string(at));
        context->pc=GPR_U32(context,31);return;
    }
    if(at==0x5ec100){o2_005EC100_0x5ec100(memory,context,runtime);return;}
    if(at==0x5ec270){o2_005EC270_0x5ec270(memory,context,runtime);return;}
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
void compare_release(const Keys& before,const Keys& after,unsigned slot,const g::PrimaryModelApplied& result){
    auto* memory=cache_memory.data();reference_slot=slot;
    for(unsigned i=0;i<8;++i){memory[0x7434b4+2*i]=before[i].character;memory[0x7434b5+2*i]=before[i].model_class;}
    std::memset(memory+reference_actor,0,0x10e0);memory[reference_actor+1]=1;cache_trace.clear();reference_releases=0;
    R5900Context context;PS2Runtime runtime;context.pc=0x5ec270;SET_GPR_U32(&context,4,slot);SET_GPR_U32(&context,5,reference_actor);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
    original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);
    for(unsigned i=0;i<8;++i)check(after[i].character==memory[0x7434b4+2*i]&&after[i].model_class==memory[0x7434b5+2*i]);
    check(result.retired==(memory[reference_actor+1]==0)&&result.character_released==(reference_releases!=0));
    check(cache_trace==(result.retired?std::vector<std::uint32_t>{0x5ec010,0x5ec0e0}:std::vector<std::uint32_t>{}));++retirement_original_cases;
}
void compare_primary_scene(const reo::native::gameplay_scenario::CutsceneDescriptor& descriptor,std::size_t group,const g::Actor& actor,std::span<const reo::native::gameplay_scenario::CutsceneActorParameter> parameters,std::uint16_t room,std::int8_t pause){
    auto* memory=cache_memory.data();std::memset(memory+0x38ec00,0,0x1700);std::memset(memory+reference_actor,0,0x10e0);
    const auto header=descriptor.section(descriptor.actor_groups()[group][7]);const auto stream=descriptor.section(descriptor.actor_groups()[group][3]);check(header.size()<0x10000&&stream.size()>=4&&stream.size()<0x10000);
    std::memcpy(memory+0x200000,header.data(),header.size());std::memcpy(memory+0x210000,stream.data(),stream.size());
    transform_write(memory,0x38fb60+28,0x200000u);transform_write(memory,0x38fb60+12,0x210000u);transform_write(memory,0x38eddc,reference_actor);transform_write(memory,0x38ecb6,std::int16_t(1));
    memory[reference_actor+0xb98]=actor.character;memory[reference_actor+0x54d]=actor.model_pose_class;memory[reference_actor+0xbbc]=1;memory[reference_actor+0xc6f]=0;
    transform_write(memory,0x3243dc,room);transform_write(memory,0x4badf8,pause);
    R5900Context context;PS2Runtime runtime;context.pc=0x5f0610;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
    reference_scene=true;original_transform_port(memory,&context,&runtime);reference_scene=false;
    check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);
    check(actor.room==transform_read<std::uint16_t>(memory,reference_actor+0x1e2)&&actor.appearance_variant==memory[reference_actor+0xbbc]);
    check(actor.movement_enabled==memory[reference_actor+0x553]&&actor.scripted->scale_profile==memory[reference_actor+0xb8b]&&std::memcmp(&actor.model_scale,memory+reference_actor+0xb4,12)==0);
    for(unsigned part=0;part<actor.primary_state->part_visibility.size();++part)check(actor.primary_state->part_visibility[part]==memory[reference_actor+0xf4+part]);
    check(parameters.size()==transform_read<std::uint32_t>(memory,0x38ede0));
    for(unsigned i=0;i<parameters.size();++i)check(parameters[i].key==transform_read<std::int32_t>(memory,0x38ede4+4*i)&&parameters[i].value==transform_read<std::uint32_t>(memory,0x38ee24+4*i));
    ++scene_original_cases;
}
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
