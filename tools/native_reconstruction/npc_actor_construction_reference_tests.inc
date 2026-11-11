namespace {
constexpr unsigned npc_reference_actor=0x80000;
const w::Actor* observed_npc{};
unsigned npc_allocations{},npc_models{},npc_claims{};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x6837c0){o2_006837C0_0x6837c0(memory,context,runtime);return;}
    check(observed_npc!=nullptr);
    if(context->pc==0x682d10){
        check(GPR_U32(context,4)==1);std::memset(memory+npc_reference_actor,0,0x10e0);memory[npc_reference_actor+3]=observed_npc->slot;
        SET_GPR_U32(context,2,npc_reference_actor);++npc_allocations;
    }else if(context->pc==0x683b10){SET_GPR_U32(context,2,observed_npc->npc->attachment.value_or(255));++npc_claims;}
    else if(context->pc==0x5ec320){
        check(GPR_U32(context,4)==observed_npc->slot&&GPR_U32(context,5)==std::uint8_t(observed_npc->model_variant)&&GPR_U32(context,6)==observed_npc->model_pose_class&&GPR_U32(context,7)==observed_npc->npc->attachment.value_or(255));
        const auto work=transform_read<std::uint32_t>(memory,npc_reference_actor+0x34);transform_write(memory,work+0x812,observed_npc->model_asset->part_count());++npc_models;
    }else throw std::runtime_error("Undeclared NPC construction port "+std::to_string(context->pc));
    context->pc=GPR_U32(context,31);
}
void compare_original_npc(const w::Actor& actor,unsigned identity,unsigned definition){
    static std::vector<std::uint8_t> memory=[](){std::vector<std::uint8_t> result(0x2000000);owned_npc_construction_constants(result.data());return result;}();
    observed_npc=&actor;npc_allocations=npc_models=npc_claims=0;transform_write(memory.data(),0x3243dc,actor.room);
    R5900Context context;PS2Runtime runtime;context.pc=0x6837c0;SET_GPR_U32(&context,4,identity);SET_GPR_U32(&context,5,definition);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
    original_transform_port(memory.data(),&context,&runtime);
    const auto at=npc_reference_actor;check(context.pc==0xabcdef&&GPR_U32(&context,2)==at&&GPR_U32(&context,29)==0x1f00000&&npc_allocations==1&&npc_models==1&&npc_claims==unsigned(actor.model_pose_class==1));
    check(actor.active==bool(memory[at])&&actor.visible==bool(memory[at+1])&&actor.category==memory[at+2]&&actor.slot==memory[at+3]&&actor.ai_control==memory[at+4]);
    check(actor.character==memory[at+0xb98]&&actor.motion_style==memory[at+0xb99]&&actor.motion_subtype==memory[at+0xb9a]&&actor.model_pose_class==memory[at+0x54d]);
    check(actor.model_variant==transform_read<std::uint16_t>(memory.data(),at+0xbb4)&&actor.current==transform_read<std::int16_t>(memory.data(),at+0x544)&&actor.maximum==transform_read<std::int16_t>(memory.data(),at+0x546));
    check(std::memcmp(&actor.model_scale,memory.data()+at+0xb4,12)==0&&actor.npc->height_parameter==transform_read<float>(memory.data(),at+0xaa8));
    check(std::memcmp(&actor.position,memory.data()+at+0x38,12)==0&&std::memcmp(actor.orientation.data(),memory.data()+at+0x90,6)==0&&actor.motion_multiplier==transform_read<float>(memory.data(),at+0xf0));
    check(std::memcmp(&actor.collision.local_center,memory.data()+at+0x1ac,12)==0&&actor.collision.radius==transform_read<float>(memory.data(),at+0x1b8));
    check(std::memcmp(&actor.collision.previous_local_center,memory.data()+at+0x1bc,12)==0&&actor.collision.previous_radius==transform_read<float>(memory.data(),at+0x1c8));
    check(actor.auxiliary_status==transform_read<std::uint32_t>(memory.data(),at+0xba4)&&actor.room==transform_read<std::uint16_t>(memory.data(),at+0x1e2));
    check(actor.npc->attachment.value_or(255)==memory[at+0xfb4]&&actor.npc->constructor_marker==memory[at+0xfd7]);
    check(actor.animation->channel_count==memory[at+0x524]);
    check(transform_read<std::uint32_t>(memory.data(),at+0x514)==0x4bc810&&transform_read<std::uint32_t>(memory.data(),at+0x518)==(actor.motion_style?0x4e6a20u:0x4e8970u)&&transform_read<std::uint32_t>(memory.data(),at+0x51c)==0x4d7000u+0x1f44u*actor.ai_control);
    for(unsigned part=0;part<actor.scripted->part_visibility.size();++part)check(actor.scripted->part_visibility[part]==memory[at+0xf4+part]);
    ++original_cases;original_models+=npc_models;original_attachments+=npc_claims;observed_npc=nullptr;
}
