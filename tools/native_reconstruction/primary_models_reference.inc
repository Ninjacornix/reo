#include "primary_models_reference.hpp"
namespace {
constexpr std::uint32_t reference_actor=0x100000;
std::vector<std::uint8_t> cache_memory(0x2000000);
std::vector<std::uint32_t> cache_trace;
unsigned reference_releases{},reference_loads{},reference_initializations{},reference_slot{},reference_character{},reference_class{};
bool reference_scene{};
bool reference_construction{};
bool reference_entry{};unsigned reference_entry_visits{},reference_entry_base_calls{};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;const auto at=context->pc;
    if(reference_construction){
        if(at==0x5f1400){o2_005F1400_0x5f1400(memory,context,runtime);return;}
        if(at==0x107c68||at==0x107ab0){
            const auto to=GPR_U32(context,4),size=GPR_U32(context,6);check(to<0x2000000&&size<=0x2000000-to);
            if(at==0x107c68){check(size==80&&GPR_U32(context,5)==0);std::memset(memory+to,0,size);}
            else{const auto from=GPR_U32(context,5);check(size==0x10e0&&from<0x2000000&&size<=0x2000000-from);std::memcpy(memory+to,memory+from,size);}
            SET_GPR_U32(context,2,to);context->pc=GPR_U32(context,31);return;
        }
    }
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
    if(at==0x5f0c00){o2_005F0C00_0x5f0c00(memory,context,runtime);return;}
    if(at==0x5ec270){if(reference_entry){reference_slot=GPR_U32(context,4);check(reference_slot<4&&GPR_U32(context,5)==0x4a5c30+0x10e0*reference_slot);++reference_entry_visits;}o2_005EC270_0x5ec270(memory,context,runtime);return;}
    if(at==0x5ec010){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_slot&&GPR_U32(context,5)==((reference_entry||reference_construction)?0x4a5c30+0x10e0*reference_slot:reference_actor));o2_005EC010_0x5ec010(memory,context,runtime);return;}
    if(at==0x5ebfe0){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_actor);o2_005EBFE0_0x5ebfe0(memory,context,runtime);return;}
    if(at==0x1d1c40){sub_001D1C40_0x1d1c40(memory,context,runtime);return;}
    if(at==0x5ec0e0){cache_trace.push_back(at);check(GPR_U32(context,4)==memory[0x7434b4+2*reference_slot]);++reference_releases;}
    else if(at==0x1aa740){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_slot&&GPR_U32(context,5)==reference_actor);++reference_loads;}
    else if(at==0x66a750){cache_trace.push_back(at);check(GPR_U32(context,4)==reference_actor&&GPR_U32(context,5)==reference_character);++reference_initializations;}
    else if(at==0x18dcb0)cache_trace.push_back(at);
    else if(at==0x1cd080){const auto old_class=memory[0x7434b5+2*reference_slot];check(GPR_U32(context,4)==8*reference_slot+(old_class==1?0x1100:0x1000)&&GPR_U32(context,5)==8);}
    else if(at==0x1b2280){check(memory[0x7434b5+2*reference_slot]==1);}
    else if(at==0x1b1df0&&reference_entry){++reference_entry_base_calls;memory[0x4bae0f]=0;}
    else throw std::runtime_error("Undeclared primary-cache original port "+std::to_string(at));
    context->pc=GPR_U32(context,31);
}
namespace {
void compare_entry(const Keys& before,const Keys& after,const std::array<std::uint8_t,8>& before_visible,const std::array<std::uint8_t,8>& after_visible,const g::PrimarySceneEntryReleased& result){
    auto* memory=cache_memory.data();
    for(unsigned i=0;i<8;++i){memory[0x7434b4+2*i]=before[i].character;memory[0x7434b5+2*i]=before[i].model_class;const auto actor=0x4a5c30+0x10e0*i;std::memset(memory+actor,0,0x10e0);memory[actor+1]=before_visible[i];}
    memory[0x4bae0f]=1;cache_trace.clear();reference_releases=reference_entry_visits=reference_entry_base_calls=0;
    R5900Context context;PS2Runtime runtime;context.pc=0x5f0c00;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
    reference_entry=true;original_transform_port(memory,&context,&runtime);reference_entry=false;
    check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000&&reference_entry_visits==4&&reference_entry_base_calls==1&&result.visited==4&&result.base_released&&memory[0x4bae0f]==0);
    check(result.retired==reference_releases&&result.character_releases==reference_releases);
    for(unsigned i=0;i<8;++i)check(after[i].character==memory[0x7434b4+2*i]&&after[i].model_class==memory[0x7434b5+2*i]&&after_visible[i]==memory[0x4a5c30+0x10e0*i+1]);
    ++entry_original_cases;
}
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
namespace {
void construction_record(std::uint8_t* m,unsigned at,const g::Actor& actor){
    std::memset(m+at,0,0x10e0);m[at]=actor.active;m[at+1]=actor.visible;m[at+2]=actor.category;m[at+3]=actor.slot;
    m[at+8]=actor.primary;m[at+9]=actor.secondary;m[at+10]=actor.phase;m[at+11]=actor.subphase;
    transform_write(m,at+0x1e2,actor.room);m[at+0x54d]=actor.model_pose_class;m[at+0xb98]=actor.character;transform_write(m,at+0xbb4,actor.model_variant);m[at+0xbbc]=actor.appearance_variant;
    if(actor.primary_state)transform_write(m,at+0xd90,actor.primary_state->initialization_marker);
    if(!actor.scripted)return;
    const auto& s=*actor.scripted;m[at+0xb38]=std::uint8_t(s.cue_phase);transform_write(m,at+0xb3c,s.request_flags);
    m[at+0xb40]=std::uint8_t(s.motion_rate_mode);m[at+0xb41]=std::uint8_t(s.scale_lock);m[at+0xb42]=s.request_phase;m[at+0xb43]=std::uint8_t(s.motion_selector);transform_write(m,at+0xb44,s.motion_blend_duration);
    transform_write(m,at+0xb48,s.relation_mode);transform_write(m,at+0xb4c,unsigned(bool(s.related_actor)));transform_write(m,at+0xb50,s.relation_options);transform_write(m,at+0xb54,s.relation_offset);transform_write(m,at+0xb60,s.relation_parameter);
    transform_write(m,at+0xb64,s.command_angles);transform_write(m,at+0xb6c,s.movement_angles);transform_write(m,at+0xb70,s.forward_step);transform_write(m,at+0xb74,s.yaw_step);transform_write(m,at+0xb78,s.movement_remaining);transform_write(m,at+0xb7c,s.track_two_motion);m[at+0xb8b]=s.scale_profile;transform_write(m,at+0xc50,s.command_angle_copy);
}
void compare_construction(const g::Actor& destination,const g::Actor& source,const g::Actor& actor,
    const reo::native::gameplay_scenario::CutscenePrimaryRoster& before,
    const reo::native::gameplay_scenario::CutscenePrimaryRoster& after,
    const reo::native::gameplay_scenario::CutscenePrimaryChoice& choice,std::uint16_t room,const g::PrimarySceneConstructed& result){
    constexpr unsigned target=0x180000,metadata=0x190000,expected=0x1a0000;auto* m=cache_memory.data();construction_record(m,target,destination);construction_record(m,expected,actor);
    std::memset(m+0x4a5c30,0,8*0x10e0);std::memset(m+metadata,0x55,8);std::memcpy(m+0x38ed90,before.characters.data(),8);transform_write(m,0x3243dc,room);
    m[target+0xb98]=choice.character;m[target+3]=choice.temporary_slot;
    reference_slot=choice.cloned_roster_slot.value_or(0);if(choice.cloned_roster_slot)construction_record(m,0x4a5c30+0x10e0*reference_slot,source);
    for(unsigned i=0;i<8;++i){m[0x7434b4+2*i]=choice.cloned_roster_slot&&i==*choice.cloned_roster_slot?choice.character:255;m[0x7434b5+2*i]=choice.cloned_roster_slot&&i==*choice.cloned_roster_slot?0:255;}
    reference_releases=0;cache_trace.clear();R5900Context c;PS2Runtime runtime;c.pc=0x5f1400;SET_GPR_U32(&c,4,target);SET_GPR_U32(&c,5,metadata);SET_GPR_U32(&c,6,choice.model_class);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);
    reference_construction=true;original_transform_port(m,&c,&runtime);reference_construction=false;check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);
    for(const auto [at,size]:std::array<std::pair<unsigned,unsigned>,11>{{{0,4},{8,4},{0x1e2,2},{0x54d,1},{0xb38,1},{0xb3c,80},{0xb98,1},{0xbb4,2},{0xbbc,1},{0xc50,2},{0xd90,2}}})check(std::memcmp(m+target+at,m+expected+at,size)==0);
    check(m[metadata]==0&&m[metadata+1]==result.roster_slot.value_or(255)&&bool(m[metadata+2])==result.release_on_exit&&m[metadata+3]==choice.model_class&&transform_read<unsigned>(m,metadata+4)==target);
    check(std::memcmp(after.characters.data(),m+0x38ed90,8)==0&&bool(reference_releases)==result.main_model_retired);++construction_original_cases;
}
}
