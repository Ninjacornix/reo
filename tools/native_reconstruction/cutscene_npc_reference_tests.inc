namespace {
std::vector<std::uint8_t> npc_scene_ram(0x2000000);
std::vector<std::shared_ptr<w::Actor>> npc_scene_actors;
unsigned scene_model_index{},scene_shadow_requests{},scene_constraint_requests{},scene_parameter_requests{};
constexpr unsigned scene_actor_address(unsigned index){return 0x400000+0x2000*index;}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x5f0610){o2_005F0610_0x5f0610(memory,context,runtime);return;}
    if(context->pc==0x5f0b50){++scene_parameter_requests;o2_005F0B50_0x5f0b50(memory,context,runtime);return;}
    if(context->pc==0x5f0dc0||context->pc==0x5f0c00){}
    else if(context->pc==0x6837c0){
        check(scene_model_index<npc_scene_actors.size());const auto& actor=*npc_scene_actors[scene_model_index];
        check(GPR_U32(context,4)==actor.model_variant&&GPR_U32(context,5)==actor.model_pose_class);
        const auto at=scene_actor_address(scene_model_index),work=0xb00000+0x2000*scene_model_index;std::memset(memory+at,0,0x1170);
        memory[at]=1;memory[at+2]=1;memory[at+3]=actor.slot;memory[at+0x54d]=actor.model_pose_class;memory[at+0xb98]=actor.character;
        transform_write(memory,at+0xbb4,actor.model_variant);transform_write(memory,at+0x34,work);transform_write(memory,work+0x812,actor.model_asset->part_count());
        const auto scale=w::npc_actor_definition(actor.model_variant).scale;for(unsigned axis=0;axis<3;++axis)transform_write(memory,at+0xb4+4*axis,scale);
        SET_GPR_U32(context,2,at);++scene_model_index;
    }else if(context->pc==0x5d6850){++scene_constraint_requests;}
    else if(context->pc==0x377560){check(GPR_U32(context,5)==0);const auto at=GPR_U32(context,4);
        check(GPR_U32(context,6)==transform_read<std::uint16_t>(memory,at+0xbb4));SET_GPR_U32(context,2,0);++scene_shadow_requests;
    }else throw std::runtime_error("Undeclared scene NPC original port "+std::to_string(context->pc));
    context->pc=GPR_U32(context,31);
}
void compare_scene_npcs(const s::CutsceneDescriptor& descriptor,std::span<const w::actors::EntityId> ids,w::World& world,std::int8_t pause){
    auto& memory=npc_scene_ram;std::memset(memory.data()+0x38ec00,0xa5,0x1700);npc_scene_actors.clear();
    const auto requests=w::cutscene_npc_requests(descriptor);unsigned constraints{};
    for(unsigned group=0;group<ids.size();++group){
        auto header=std::vector<std::byte>(descriptor.section(descriptor.actor_groups()[group][7]).begin(),descriptor.section(descriptor.actor_groups()[group][7]).end());check(header.size()>=36);
        if(!requests[group]){const std::uint16_t terminal=65535;std::memcpy(header.data()+2,&terminal,2);}
        else{check(bool(ids[group]));npc_scene_actors.push_back(world.resolve(ids[group]));std::uint32_t scale;std::memcpy(&scale,header.data()+20,4);constraints+=std::uint8_t(scale)==0;}
        const auto header_at=0x900000+0x1000*group;check(header.size()<0x1000);std::memcpy(memory.data()+header_at,header.data(),header.size());transform_write(memory.data(),0x38fb60+32*group+28,header_at);
        const auto parameters=descriptor.section(descriptor.actor_groups()[group][3]);check(parameters.size()<0x1000);std::memcpy(memory.data()+0xa00000+0x1000*group,parameters.data(),parameters.size());transform_write(memory.data(),0x38fb60+32*group+12,0xa00000+0x1000*group);
    }
    transform_write(memory.data(),0x38ecb6,std::int16_t(ids.size()));transform_write(memory.data(),0x38ecb8,std::int16_t(0));memory[0x3243d7]=std::uint8_t(pause);transform_write(memory.data(),0x3243dc,world.room);
    scene_model_index=scene_shadow_requests=scene_constraint_requests=scene_parameter_requests=0;
    R5900Context context;PS2Runtime runtime;context.pc=0x5f0610;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0xabcdef&&scene_model_index==npc_scene_actors.size()&&scene_constraint_requests==constraints&&scene_shadow_requests==(pause?0:npc_scene_actors.size())&&scene_parameter_requests==npc_scene_actors.size());
    unsigned index{};
    for(unsigned group=0;group<ids.size();++group){if(!ids[group])continue;const auto actor=world.resolve(ids[group]);const auto at=scene_actor_address(index++);
        check(memory[0x38edd8+0x8c*group]==1&&transform_read<std::uint32_t>(memory.data(),0x38eddc+0x8c*group)==at);
        check(actor->room==transform_read<std::uint16_t>(memory.data(),at+0x1e2)&&actor->scripted->scale_profile==memory[at+0xb8b]&&std::memcmp(&actor->model_scale,memory.data()+at+0xb4,12)==0);
        for(unsigned part=0;part<actor->scripted->part_visibility.size();++part)check(actor->scripted->part_visibility[part]==memory[at+0xf4+part]);
        const auto parameters=descriptor.actor_parameters(group);check(parameters.size()==transform_read<std::uint32_t>(memory.data(),0x38ede0+0x8c*group));
        for(unsigned parameter=0;parameter<parameters.size();++parameter)check(parameters[parameter].key==transform_read<std::int32_t>(memory.data(),0x38ede4+0x8c*group+4*parameter)&&parameters[parameter].value==transform_read<std::uint32_t>(memory.data(),0x38ee24+0x8c*group+4*parameter));
        ++original_npcs;
    }
    ++original_cases;
}
