std::uint64_t scene_audio_cases{},scene_audio_commands{},scene_audio_mixed_frames{},scene_audio_signal{},scene_audio_playbacks{},scene_audio_frames{},scene_audio_sounds{},scene_audio_refusals{};
struct ComparingSceneAudio final:audio_scenario::SceneMatrixSoundSink {
    audio_scenario::SceneBankAudio& native;
    std::function<bool(reo::native::transform_math::Vector,std::uint8_t,std::uint16_t)> compare;
    explicit ComparingSceneAudio(audio_scenario::SceneBankAudio& value):native(value){}
    bool admitted()const noexcept override{return native.admitted();}
    bool emit(reo::native::transform_math::Vector point,std::uint8_t resource,std::uint16_t cue)override{return compare(point,resource,cue);}
};
void compare_scene_audio(std::vector<std::uint8_t>& memory,const std::filesystem::path& directory){
    std::array<std::uint8_t,256> raw{};std::ifstream source(directory/"owned_scene_audio.bin",std::ios::binary);source.read(reinterpret_cast<char*>(raw.data()),raw.size());check(bool(source));std::copy(raw.begin(),raw.end(),memory.begin()+0x730aa0);
    auto session=std::make_shared<audio_world::Session>();audio_world::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});audio_world::World world(profile,session);
    auto engine=std::make_shared<b::Session>();b::Session reference;a::Owner owner(engine,session->random);const auto bytes=frontend_snd();check(owner.install(owner.begin_bank(1),bytes).status==a::Status::completed);
    const auto imported=a::import_snd(bytes,1);check(imported.status==a::Status::completed);const auto& parts=imported.value.parts;auto token=reference.begin_submission();check(token.status==b::Status::ok);auto capture=reference.capture(token.value,{parts[0].size,parts[1].size,parts[2].size});check(capture.status==b::Status::ok);
    const std::array<std::span<std::uint8_t>,3> targets{capture.value.hd(),capture.value.bd(),capture.value.tq()};for(unsigned i=0;i<3;++i)std::copy_n(bytes.begin()+parts[i].offset,parts[i].size,targets[i].begin());auto prepared=reference.prepare(token.value,std::move(capture.value));check(prepared.status==b::Status::ok&&reference.install(token.value,1,prepared.value)==b::Status::ok);
    PS2Runtime runtime;std::copy(bytes.begin(),bytes.end(),memory.begin()+0x600000);auto c=context(0x1acfb0);SET_GPR_U32(&c,4,0x600000);SET_GPR_U32(&c,5,1);sub_001ACFB0_0x1acfb0(memory.data(),&c,&runtime);check(c.pc==0x1234);
    spatial.listener={};spatial.world_to_screen=reo::native::transform_math::identity();spatial.world_to_screen[3][0]=320;audio_scenario::SceneBankAudio native(world,owner,spatial);ComparingSceneAudio sink(native);Gains gains;fail_at=UINT32_MAX;
    const auto begin=[&](){const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference.apply({&stop,1}).status==b::Status::ok);const s::RandomState seed{31,217,0};session->random.restore(seed);write(memory.data(),0x3244b0,seed.primary);write(memory.data(),0x3244b8,seed.secondary);memory[0x2b8de8]=seed.observed;};
    sink.compare=[&](reo::native::transform_math::Vector point,std::uint8_t resource,std::uint16_t cue){
        check(session->scenario.has_value());write(memory.data(),0x3243da,*session->scenario);write(memory.data(),0x230000,point);original_events.clear();auto ctx=context(0x6b60e0);SET_GPR_U32(&ctx,4,0x230000);SET_GPR_U32(&ctx,5,resource);SET_GPR_U32(&ctx,6,cue);o2_006B60E0_0x6b60e0(memory.data(),&ctx,&runtime);check(ctx.pc==0x1234);
        for(const auto& e:original_events){const auto command=command_from_event(e);check(reference.apply({&command,1}).status==b::Status::ok);}
        const auto accepted=native.emit(point,resource,cue);check(accepted&&native.last_result().has_value()&&native.last_result()->commands==original_events.size());check(session->random.state().primary==read<std::uint16_t>(memory.data(),0x3244b0)&&session->random.state().secondary==read<std::uint16_t>(memory.data(),0x3244b8)&&session->random.state().observed==memory[0x2b8de8]);
        const auto actual=engine->snapshot(),expected=reference.snapshot();check(actual.request_age==expected.request_age);
        for(unsigned i=0;i<16;++i){const auto& x=actual.ports[1].requests[i];const auto& y=expected.ports[1].requests[i];check(x.index==y.index&&x.group==y.group&&x.request_volume==y.request_volume&&x.request_pan==y.request_pan&&x.request_pitch==y.request_pitch&&x.sequence.active==y.sequence.active&&x.sequence.cursor==y.sequence.cursor&&x.sequence.program_offset==y.sequence.program_offset);}
        std::array<float,64> output{},expected_output{};check(engine->mix_add(output.data(),32,gains)==b::Status::ok&&reference.mix_add(expected_output.data(),32,gains)==b::Status::ok);check(output==expected_output);for(const auto sample:output)if(sample!=0)++scene_audio_signal;scene_audio_mixed_frames+=32;scene_audio_commands+=original_events.size();return accepted;
    };
    for(unsigned scenario=0;scenario<42;++scenario)for(unsigned resource=0;resource<10;++resource)for(unsigned cue:{0u,1u,7u,8u,15u,16u,31u,32u,63u,64u,127u,128u,255u,256u,32768u,65535u})for(unsigned location=0;location<3;++location){
        active_case="scene scenario="+std::to_string(scenario)+" resource="+std::to_string(resource)+" cue="+std::to_string(cue)+" location="+std::to_string(location);session->scenario=std::uint16_t(scenario);begin();check(sink.emit({location==0?50.f:location==1?1000.f:4800.f,0,0},std::uint8_t(resource),std::uint16_t(cue)));++scene_audio_cases;
    }
    // Real canonical scene channels now advance into the concrete bank sink.
    // Curve/callback semantics have a separate complete6B4BA0 comparison;
    // here each reached sound executes full6B60E0 and actual native bank audio.
    const auto& tables=audio_scenario::stock_scene_matrix_tables();
    for(unsigned scenario:{0u,1u,2u,28u,35u,41u})for(unsigned resource:{0u,1u})for(unsigned curve=0;curve<236;++curve){
        const auto& group=tables.groups[curve/4];const auto sounds=group.sounds[curve%4];if(sounds<0||tables.sounds[std::size_t(sounds)].empty())continue;
        active_case="scene playback scenario="+std::to_string(scenario)+" resource="+std::to_string(resource)+" curve="+std::to_string(curve);session->scenario=std::uint16_t(scenario);begin();
        audio_scenario::SceneModelState state;state.poses[0]=reo::native::transform_math::identity();state.poses[0][3][0]=50;state.sound_resources[0]=std::uint8_t(resource);audio_scenario::SceneModels models(state,{});audio_world::actors::EntityStore ids;audio_scenario::SceneModelBindings bindings(models,ids);audio_scenario::SceneControls controls;audio_scenario::FlagState flags;
        audio_scenario::SceneMatrixPrograms::State channels{};channels[0].playback=1;channels[0].progress=1;channels[0].curve=std::uint8_t(curve);channels[0].transform=2;audio_scenario::SceneMatrixPrograms programs(controls,models,bindings,flags,world.room,channels);
        const auto keys=tables.curves[group.curves[curve%4]];const unsigned limit=unsigned(keys.back().time+4);unsigned emitted{};
        for(unsigned frame=0;frame<limit;++frame){const auto result=programs.advance(0,curve%2!=0,&sink);check(result.status==audio_scenario::SceneMatrixStatus::completed);++scene_audio_frames;emitted+=unsigned(result.sounds);scene_audio_sounds+=result.sounds;if(programs.inspect(0)->playback==0)break;check(frame+1<limit);}
        check(programs.inspect(0)->progress==2&&emitted>0);++scene_audio_playbacks;
    }
    for(unsigned failure=0;failure<4;++failure){session->scenario=failure==0?std::optional<std::uint16_t>{}:std::optional<std::uint16_t>(failure==1?42:0);check(!native.emit({},std::uint8_t(failure==2?10:failure==3?255:0),0)&&!native.last_result());++scene_audio_refusals;}
    s::Random foreign;a::Owner wrong(std::make_shared<b::Session>(),foreign);bool refused{};try{audio_scenario::SceneBankAudio other(world,wrong,spatial);}catch(const std::invalid_argument&){refused=true;}check(refused);++scene_audio_refusals;session->scenario=0;world.close();check(!native.admitted()&&!native.emit({},0,0));++scene_audio_refusals;check(scene_audio_signal>0);
}
