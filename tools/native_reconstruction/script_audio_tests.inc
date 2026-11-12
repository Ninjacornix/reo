std::uint64_t script_audio_cases{},script_audio_commands{},script_audio_frames{},script_audio_signal{},script_audio_refusals{};
void compare_script_audio(std::vector<std::uint8_t>& memory,const std::filesystem::path& directory){
    std::array<std::uint8_t,2080> tables{};std::ifstream source(directory/"owned_scenario_audio.bin",std::ios::binary);
    source.read(reinterpret_cast<char*>(tables.data()),tables.size());check(bool(source));std::copy(tables.begin(),tables.end(),memory.begin()+0x730ba0);
    audio_world::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});
    auto session=std::make_shared<audio_world::Session>();auto world=std::make_shared<audio_world::World>(profile,session);
    for(unsigned i=0;i<4;++i){check(world->spawn_primary(i,std::make_unique<audio_world::Actor>()).status==audio_world::actors::EntityStatus::completed);world->primary(i)->position={float(50+500*i),float(-20*int(i)),float(30*i)};}
    auto engine=std::make_shared<b::Session>();b::Session reference;a::Owner owner(engine,session->random);const auto bytes=frontend_snd();
    check(owner.install(owner.begin_bank(2),bytes).status==a::Status::completed);
    const auto imported=a::import_snd(bytes,2);check(imported.status==a::Status::completed);const auto& parts=imported.value.parts;
    auto token=reference.begin_submission();check(token.status==b::Status::ok);
    auto capture=reference.capture(token.value,{parts[0].size,parts[1].size,parts[2].size});check(capture.status==b::Status::ok);
    const std::array<std::span<std::uint8_t>,3> targets{capture.value.hd(),capture.value.bd(),capture.value.tq()};
    for(unsigned i=0;i<3;++i)std::copy_n(bytes.begin()+parts[i].offset,parts[i].size,targets[i].begin());
    auto prepared=reference.prepare(token.value,std::move(capture.value));check(prepared.status==b::Status::ok&&reference.install(token.value,2,prepared.value)==b::Status::ok);
    PS2Runtime runtime;std::copy(bytes.begin(),bytes.end(),memory.begin()+0x600000);
    auto setup=context(0x1acfb0);SET_GPR_U32(&setup,4,0x600000);SET_GPR_U32(&setup,5,2);sub_001ACFB0_0x1acfb0(memory.data(),&setup,&runtime);check(setup.pc==0x1234);
    spatial.listener={};spatial.world_to_screen=reo::native::transform_math::identity();spatial.world_to_screen[0][0]=.25f;spatial.world_to_screen[3][0]=320;
    audio_scenario::ScriptAudio frontend(*world,owner,spatial);Gains gains;fail_at=UINT32_MAX;
    const std::array<std::array<std::int32_t,3>,7> locations{{{0,0,0},{50,-20,30},{1000,200,-300},{10000,0,0},{INT32_MIN,INT32_MAX,-1},{16777217,-16777217,8388609},{-200,100,500}}};
    const auto run=[&](unsigned scenario,std::uint32_t cue,std::uint32_t mode,std::uint32_t selector,std::array<std::int32_t,3> coordinates){
        active_case="script73 scenario="+std::to_string(scenario)+" cue="+std::to_string(cue)+" mode="+std::to_string(mode)+" selector="+std::to_string(selector);
        const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference.apply({&stop,1}).status==b::Status::ok);
        original_events.clear();const s::RandomState seed{std::uint16_t(31+selector),std::uint16_t(217+cue),0};session->random.restore(seed);
        write(memory.data(),0x3244b0,seed.primary);write(memory.data(),0x3244b8,seed.secondary);memory[0x2b8de8]=seed.observed;
        session->scenario=std::uint16_t(scenario);write(memory.data(),0x3243da,std::uint16_t(scenario));
        world->selected_actor=std::uint8_t(cue%4);memory[0x4baded]=world->selected_actor;
        for(unsigned i=0;i<4;++i){auto actor=world->primary(i);std::memcpy(memory.data()+0x4a5c30+0x10e0*i+0x38,&actor->position,12);}
        session->last_scenario_audio=0xa57c;write(memory.data(),0x316550,std::uint16_t(0xa57c));
        constexpr unsigned payload=0x220000;write(memory.data(),payload,cue);write(memory.data(),payload+4,mode);
        write(memory.data(),payload+8,mode==1?selector:std::bit_cast<std::uint32_t>(coordinates[0]));
        write(memory.data(),payload+12,coordinates[1]);write(memory.data(),payload+16,coordinates[2]);
        auto c=context(0x68f640);SET_GPR_U32(&c,4,payload);o2_0068F640_0x68f640(memory.data(),&c,&runtime);check(c.pc==0x1234&&GPR_U32(&c,2)==0);
        check(frontend.ready(cue,mode,selector)&&frontend.command(cue,mode,selector,coordinates));
        check(session->last_scenario_audio==read<std::uint16_t>(memory.data(),0x316550));
        for(const auto& e:original_events){const auto command=command_from_event(e);check(reference.apply({&command,1}).status==b::Status::ok);}
        check(session->random.state().primary==read<std::uint16_t>(memory.data(),0x3244b0)&&session->random.state().secondary==read<std::uint16_t>(memory.data(),0x3244b8)&&session->random.state().observed==memory[0x2b8de8]);
        check((frontend.last_result()?frontend.last_result()->commands:0)==original_events.size());
        const auto actual=engine->snapshot(),expected=reference.snapshot();check(actual.request_age==expected.request_age);
        for(unsigned i=0;i<16;++i){const auto& x=actual.ports[2].requests[i];const auto& y=expected.ports[2].requests[i];
            check(x.index==y.index&&x.group==y.group&&x.request_volume==y.request_volume&&x.request_pan==y.request_pan&&x.request_pitch==y.request_pitch&&x.sequence.active==y.sequence.active&&x.sequence.cursor==y.sequence.cursor&&x.sequence.program_offset==y.sequence.program_offset);
        }
        std::array<float,64> output{},expected_output{};check(engine->mix_add(output.data(),32,gains)==b::Status::ok&&reference.mix_add(expected_output.data(),32,gains)==b::Status::ok);check(output==expected_output);
        for(float sample:output)if(sample!=0)++script_audio_signal;
        script_audio_frames+=32;script_audio_commands+=original_events.size();++script_audio_cases;
    };
    for(unsigned scenario:{0u,1u,2u,28u,35u,41u})for(unsigned cue=0;cue<208;++cue){
        run(scenario,cue,0,0,{});
        for(unsigned actor=0;actor<5;++actor)run(scenario,cue,1,actor,{});
        for(auto point:locations)run(scenario,cue,2,0,point);
        for(unsigned mode:{3u,0x80000000u,UINT32_MAX})run(scenario,cue,mode,UINT32_MAX,{});
    }
    for(auto cue:{255u,65535u,0x80000000u,UINT32_MAX})for(unsigned mode:{0u,1u,2u})run(0,cue,mode,4,locations[1]);
    // Pending and unloaded banks are real command outcomes, not frontend errors.
    auto pending=owner.begin_bank(2);check(bool(pending));memory[0x2b3934+2]=1;memory[0x2b3924+2]=1;
    run(1,0,0,0,{});check(frontend.last_result()&&frontend.last_result()->status==a::Status::pending);
    check(owner.cancel(pending).status==a::Status::completed);check(owner.unload(2).status==a::Status::completed);
    memory[0x2b3934+2]=1;memory[0x2b3924+2]=0;run(1,0,0,0,{});
    auto other_session=std::make_shared<audio_world::Session>();audio_world::World other(profile,other_session);
    check(!frontend.bound_to(other));++script_audio_refusals;
    bool refused=false;try{audio_scenario::ScriptAudio wrong(other,owner,spatial);}catch(const std::invalid_argument&){refused=true;}check(refused);++script_audio_refusals;
    session->scenario=1;for(unsigned cue:{208u,255u,UINT32_MAX}){const auto before=session->last_scenario_audio;check(!frontend.ready(cue,0)&&!frontend.command(cue,0)&&session->last_scenario_audio==before);++script_audio_refusals;}
    for(unsigned actor:{5u,UINT32_MAX}){check(!frontend.ready(0,1,actor)&&!frontend.command(0,1,actor));++script_audio_refusals;}
    check(world->retire_primary(3)==audio_world::actors::EntityStatus::completed);check(!frontend.ready(0,1,3)&&!frontend.command(0,1,3));++script_audio_refusals;
    session->scenario.reset();check(!frontend.command(0,0)&&frontend.command(UINT32_MAX,3));++script_audio_refusals;
    world->close();check(!frontend.bound_to(*world)&&!frontend.command(0,0));++script_audio_refusals;
}
