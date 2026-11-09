std::uint64_t node_cases{},position_cases{},remap_cases{},node_position_commands{},node_position_mixed_frames{},node_position_signal{},node_position_refusals{};
void compare_node_position_audio(std::vector<std::uint8_t>& memory,const std::filesystem::path& directory){
    std::array<std::uint8_t,2080> tables{};std::ifstream source(directory/"owned_scenario_audio.bin",std::ios::binary);source.read(reinterpret_cast<char*>(tables.data()),tables.size());check(bool(source));std::copy(tables.begin(),tables.end(),memory.begin()+0x730ba0);
    PS2Runtime runtime;
    // Every 16-bit scenario selector, all five table extents, and full-word
    // identity cases. Native remaps are independently extracted immutable data.
    const auto compare_remap=[&](std::uint16_t scenario,std::uint32_t cue){
        write(memory.data(),0x3243da,scenario);auto c=context(0x1b8870);SET_GPR_U32(&c,4,cue);sub_001B8870_0x1b8870(memory.data(),&c,&runtime);check(c.pc==0x1234&&a::scenario_cue(scenario,cue)==GPR_U32(&c,2));++remap_cases;
    };
    for(unsigned scenario=0;scenario<65536;++scenario)compare_remap(std::uint16_t(scenario),scenario%208);
    for(unsigned scenario:{1u,2u,28u,35u,41u})for(unsigned cue=0;cue<208;++cue)compare_remap(std::uint16_t(scenario),cue);
    for(unsigned scenario:{0u,3u,27u,29u,34u,36u,40u,42u,65535u})for(unsigned cue:{255u,65535u,0x80000000u,UINT32_MAX})compare_remap(std::uint16_t(scenario),cue);
    auto session=std::make_shared<audio_world::Session>();audio_world::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});auto world=std::make_shared<audio_world::World>(profile,session);
    check(world->spawn_primary(0,std::make_unique<audio_world::Actor>()).status==audio_world::actors::EntityStatus::completed);auto actor=world->primary(0);actor->position={4800,0,0};
    auto engine=std::make_shared<b::Session>();b::Session reference;a::Owner owner(engine,session->random);const auto bytes=frontend_snd();
    for(unsigned port:{1u,2u}){
        check(owner.install(owner.begin_bank(port),bytes).status==a::Status::completed);const auto imported=a::import_snd(bytes,port);check(imported.status==a::Status::completed);const auto& parts=imported.value.parts;
        auto token=reference.begin_submission();check(token.status==b::Status::ok);auto capture=reference.capture(token.value,{parts[0].size,parts[1].size,parts[2].size});check(capture.status==b::Status::ok);
        const std::array<std::span<std::uint8_t>,3> targets{capture.value.hd(),capture.value.bd(),capture.value.tq()};for(unsigned i=0;i<3;++i)std::copy_n(bytes.begin()+parts[i].offset,parts[i].size,targets[i].begin());auto prepared=reference.prepare(token.value,std::move(capture.value));check(prepared.status==b::Status::ok&&reference.install(token.value,port,prepared.value)==b::Status::ok);
        std::copy(bytes.begin(),bytes.end(),memory.begin()+0x600000);auto c=context(0x1acfb0);SET_GPR_U32(&c,4,0x600000);SET_GPR_U32(&c,5,port);sub_001ACFB0_0x1acfb0(memory.data(),&c,&runtime);check(c.pc==0x1234);
    }
    audio_scenario::SceneModelState initial;audio_scenario::RoomModelRemap remap{};audio_scenario::SceneModels models(initial,remap);audio_scenario::SceneResources resources;audio_scenario::ResourceTemplates templates;
    spatial.listener={};spatial.world_to_screen=reo::native::transform_math::identity();spatial.world_to_screen[3][0]=320;
    animation_audio::BasicAudio frontend(*world,owner,spatial,resources,templates);frontend.bind_scene_models(models);Gains gains;fail_at=UINT32_MAX;
    std::ifstream skeleton_file(directory/"owned_skeletons.bin",std::ios::binary);std::uint32_t count{},size{};skeleton_file.read(reinterpret_cast<char*>(&count),4);skeleton_file.read(reinterpret_cast<char*>(&size),4);check(count==2&&size>0&&size<100000);std::vector<std::byte> raw(size);skeleton_file.read(reinterpret_cast<char*>(raw.data()),size);check(bool(skeleton_file));actor->model=std::make_shared<reo::native::animation::Instance>(reo::native::animation::Skeleton::import_raw(raw));
    constexpr unsigned actor_at=0x4a5c30,work=0x220000,node=0x230000;
    write(memory.data(),actor_at+0x34,work);write(memory.data(),work+0x85c,node);
    const auto begin=[&](){
        const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference.apply({&stop,1}).status==b::Status::ok);
        original_events.clear();const s::RandomState seed{31,217,0};session->random.restore(seed);write(memory.data(),0x3244b0,seed.primary);write(memory.data(),0x3244b8,seed.secondary);memory[0x2b8de8]=seed.observed;
    };
    const auto finish=[&](unsigned port){
        for(const auto& e:original_events){const auto command=command_from_event(e);check(reference.apply({&command,1}).status==b::Status::ok);}
        check(session->random.state().primary==read<std::uint16_t>(memory.data(),0x3244b0)&&session->random.state().secondary==read<std::uint16_t>(memory.data(),0x3244b8)&&session->random.state().observed==memory[0x2b8de8]);
        check((frontend.last_result()?frontend.last_result()->commands:0)==original_events.size());const auto actual=engine->snapshot(),expected=reference.snapshot();check(actual.request_age==expected.request_age);
        for(unsigned i=0;i<16;++i){const auto& x=actual.ports[port].requests[i];const auto& y=expected.ports[port].requests[i];
            if(x.index!=y.index||x.group!=y.group||x.request_volume!=y.request_volume||x.request_pan!=y.request_pan||x.request_pitch!=y.request_pitch||x.sequence.active!=y.sequence.active||x.sequence.cursor!=y.sequence.cursor||x.sequence.program_offset!=y.sequence.program_offset){
                std::cerr<<"request "<<i<<" native/source index="<<unsigned(x.index)<<'/'<<unsigned(y.index)<<" group="<<unsigned(x.group)<<'/'<<unsigned(y.group)<<" volume="<<unsigned(x.request_volume)<<'/'<<unsigned(y.request_volume)<<" pan="<<unsigned(x.request_pan)<<'/'<<unsigned(y.request_pan)<<" pitch="<<x.request_pitch<<'/'<<y.request_pitch<<" active="<<x.sequence.active<<'/'<<y.sequence.active<<" cursor="<<x.sequence.cursor<<'/'<<y.sequence.cursor<<" offset="<<unsigned(x.sequence.program_offset)<<'/'<<unsigned(y.sequence.program_offset)<<'\n';check(false);
            }check(true);
        }
        std::array<float,64> output{},expected_output{};check(engine->mix_add(output.data(),32,gains)==b::Status::ok&&reference.mix_add(expected_output.data(),32,gains)==b::Status::ok);check(output==expected_output);for(const auto sample:output)if(sample!=0)++node_position_signal;node_position_mixed_frames+=32;node_position_commands+=original_events.size();
    };
    for(unsigned model=0;model<128;++model)for(unsigned sound:{0u,1u,2u,255u})for(unsigned kind:{0u,1u,2u,65535u})for(unsigned location=0;location<3;++location){
        active_case="node model="+std::to_string(model)+" sound="+std::to_string(sound)+" kind="+std::to_string(kind)+" location="+std::to_string(location);begin();
        actor->scene_model=audio_scenario::ModelReference(model);check(models.sound_resource(model,std::uint8_t(sound))==audio_scenario::ModelStatus::completed);memory[actor_at+0xabb]=std::uint8_t(model);memory[0x4a1d70+model]=std::uint8_t(sound);
        auto parent=reo::native::transform_math::identity();parent[3][0]=location==0?50.f:location==1?1000.f:10000.f;actor->model->rebuild(parent);const auto point=actor->model->world_translation(15);write(memory.data(),node+0x30,point);
        auto c=context(0x595f10);SET_GPR_U32(&c,4,actor_at);SET_GPR_U32(&c,5,kind);o2_00595F10_0x595f10(memory.data(),&c,&runtime);check(c.pc==0x1234);frontend.node(*actor,std::uint16_t(kind));finish(1);++node_cases;
    }
    for(unsigned scenario:{0u,1u,2u,28u,35u,41u})for(unsigned cue=0;cue<208;++cue)for(unsigned location=0;location<3;++location){
        active_case="position scenario="+std::to_string(scenario)+" cue="+std::to_string(cue)+" location="+std::to_string(location);begin();
        session->scenario=std::uint16_t(scenario);session->last_scenario_audio=0xabcd;write(memory.data(),0x3243da,*session->scenario);write(memory.data(),0x316550,std::uint16_t(0xabcd));actor->position={location==0?50.f:location==1?1000.f:4800.f,0,0};write(memory.data(),actor_at+0x38,actor->position);
        auto c=context(0x1b8930);SET_GPR_U32(&c,4,actor_at+0x38);SET_GPR_U32(&c,5,cue);sub_001B8930_0x1b8930(memory.data(),&c,&runtime);check(c.pc==0x1234);frontend.position(*actor,cue);check(session->last_scenario_audio==read<std::uint16_t>(memory.data(),0x316550));finish(2);++position_cases;
    }
    // Unknown kind with sound-map0 skips before requiring any model. With map1
    // it still emits8 and therefore requires a published joint15.
    actor->scene_model=audio_scenario::ModelReference(0);check(models.sound_resource(0u,0)==audio_scenario::ModelStatus::completed);actor->model.reset();frontend.node(*actor,2);check(!frontend.last_result());
    for(unsigned failure=0;failure<6;++failure){
        bool refused{};session->scenario=1;actor->scene_model=audio_scenario::ModelReference(failure==2?255u:0u);check(models.sound_resource(0u,std::uint8_t(failure==1?1:0))==audio_scenario::ModelStatus::completed);
        try{if(failure<3)frontend.node(*actor,failure==1?2:0);else if(failure==3){session->scenario.reset();frontend.position(*actor,0);}else if(failure==4)frontend.position(*actor,208);else {animation_audio::BasicAudio missing(*world,owner,spatial,resources,templates);missing.node(*actor,0);}}catch(const std::exception&){refused=true;}
        check(refused&&!frontend.last_result());++node_position_refusals;
    }
    check(node_position_signal>0);
}
