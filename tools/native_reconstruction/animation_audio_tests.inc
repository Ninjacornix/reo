namespace animation_audio=reo::native::gameplay_world::animation_events;
namespace audio_world=reo::native::gameplay_world;
namespace audio_scenario=reo::native::gameplay_scenario;
std::uint64_t frontend_cases{},frontend_commands{},frontend_mixed_frames{},frontend_refusals{};
std::array<std::uint64_t,3> frontend_family_commands{};
std::uint64_t frontend_signal_samples{};
std::vector<std::uint8_t> frontend_snd(){
    auto bank=b_inputs::bank();bank.tq.assign(16+4*128+8*128,0);
    b_inputs::word16(bank.tq,14,128);
    for(unsigned i=0;i<128;++i){const auto at=16+4*128+8*i;b_inputs::word32(bank.tq,16+4*i,0x40000000u|at);const std::array<std::uint8_t,8> code{0xe0,127,0xe2,0,0xb2,127,0xff,0};std::copy(code.begin(),code.end(),bank.tq.begin()+at);}
    std::vector<std::uint8_t> bytes(64+16+128*16);
    write(bytes.data(),32,64u);write(bytes.data(),36,16u+128u*16u);
    for(unsigned i=0;i<128;++i){auto* row=bytes.data()+80+16*i;row[0]=0;row[6]=std::uint8_t(i%16);row[8]=std::uint8_t(80+i%48);row[9]=255;row[12]=3;row[13]=2;row[15]=255;}
    const std::array<std::span<const std::uint8_t>,3> parts{bank.hd,bank.bd,bank.tq};
    for(unsigned i=0;i<3;++i){const auto at=unsigned(bytes.size());write(bytes.data(),8+8*i,at);write(bytes.data(),12+8*i,unsigned(parts[i].size()));bytes.insert(bytes.end(),parts[i].begin(),parts[i].end());}
    return bytes;
}
void compare_animation_frontends(std::vector<std::uint8_t>& memory){
    auto engine=std::make_shared<b::Session>();b::Session reference;const auto bytes=frontend_snd();
    audio_world::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});
    auto session=std::make_shared<audio_world::Session>();auto world=std::make_shared<audio_world::World>(profile,session);
    const auto created=world->spawn_primary(0,std::make_unique<audio_world::Actor>());check(created.status==audio_world::actors::EntityStatus::completed);auto actor=world->primary(0);
    a::Owner owner(engine,session->random);audio_scenario::SceneResources resources;audio_scenario::ResourceTemplates templates;
    spatial.listener={};spatial.world_to_screen=reo::native::transform_math::identity();spatial.world_to_screen[0][0]=.25f;spatial.world_to_screen[3][0]=320;
    animation_audio::BasicAudio frontend(*world,owner,spatial,resources,templates);
    PS2Runtime runtime;Gains gains;fail_at=UINT32_MAX;
    for(unsigned port=0;port<14;++port){
        check(owner.install(owner.begin_bank(port),bytes).status==a::Status::completed);
        const auto imported=a::import_snd(bytes,port);check(imported.status==a::Status::completed);
        auto token=reference.begin_submission();check(token.status==b::Status::ok);const auto& parts=imported.value.parts;
        auto capture=reference.capture(token.value,{parts[0].size,parts[1].size,parts[2].size});check(capture.status==b::Status::ok);
        const std::array<std::span<std::uint8_t>,3> targets{capture.value.hd(),capture.value.bd(),capture.value.tq()};
        for(unsigned i=0;i<3;++i)std::copy_n(bytes.begin()+parts[i].offset,parts[i].size,targets[i].begin());
        auto prepared=reference.prepare(token.value,std::move(capture.value));check(prepared.status==b::Status::ok&&reference.install(token.value,port,prepared.value)==b::Status::ok);
        std::copy(bytes.begin(),bytes.end(),memory.begin()+0x600000);auto c=context(0x1acfb0);SET_GPR_U32(&c,4,0x600000);SET_GPR_U32(&c,5,port);sub_001ACFB0_0x1acfb0(memory.data(),&c,&runtime);check(c.pc==0x1234);
        const b::Command volume=b::SetPortVolume{port,std::uint16_t(16u+port*7u)};check(engine->apply({&volume,1}).status==b::Status::ok&&reference.apply({&volume,1}).status==b::Status::ok);
    }
    constexpr unsigned actor_at=0x4a5c30;
    for(unsigned family=0;family<3;++family)for(unsigned category=0;category<4;++category)for(unsigned slot=0;slot<4;++slot)for(unsigned event_id:{0u,6u,25u,127u,65535u})for(unsigned shape=0;shape<7;++shape){
        active_case="animation audio family="+std::to_string(family)+" category="+std::to_string(category)+" slot="+std::to_string(slot)+" event="+std::to_string(event_id)+" shape="+std::to_string(shape);
        const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference.apply({&stop,1}).status==b::Status::ok);
        actor->category=std::uint8_t(category);actor->slot=std::uint8_t(slot);actor->selected_resource=3;
        actor->position={shape==3?4800.f:(shape==2||shape==4)?1000.f:(shape==1||shape==5)?200.f:50.f,0,0};
        audio_scenario::SceneDescriptor descriptor;descriptor.active=std::uint8_t(shape!=1);descriptor.template_index=shape==2?255:shape==6?128:0;
        check(bool(resources.load(3,descriptor)));
        // A bounded version3 template import supplies the signed selector;
        // it is a presence condition, not the selected bank/event number.
        std::vector<std::byte> raw(56);const auto put=[&](unsigned at,std::uint32_t value){std::memcpy(raw.data()+at,&value,4);};put(0,3);put(4,1);put(16,32);raw[32+14]=std::byte(shape==0?0xff:(shape==3||shape==5)?0xfe:0);
        check(templates.load(raw));std::memcpy(memory.data()+0x74bb50,templates.state().templates.data(),24*129);
        memory[actor_at+2]=actor->category;memory[actor_at+3]=actor->slot;memory[actor_at+0xc7c]=actor->selected_resource;std::memcpy(memory.data()+actor_at+0x38,&actor->position,12);
        memory[0x3c5630+60*3]=descriptor.active;memory[0x3c5630+60*3+0x2b]=descriptor.template_index;
        const s::RandomState seed{std::uint16_t(31+slot),std::uint16_t(123+event_id),0};session->random.restore(seed);write(memory.data(),0x3244b0,seed.primary);write(memory.data(),0x3244b8,seed.secondary);memory[0x2b8de8]=seed.observed;
        original_events.clear();const unsigned address=family==0?0x1b8bb0:family==1?0x1b8b20:0x1b8c70;auto c=context(address);SET_GPR_U32(&c,4,actor_at);SET_GPR_U32(&c,5,event_id);
        if(family==0)sub_001B8BB0_0x1b8bb0(memory.data(),&c,&runtime);
        else if(family==1)sub_001B8B20_0x1b8b20(memory.data(),&c,&runtime);
        else sub_001B8C70_0x1b8c70(memory.data(),&c,&runtime);
        check(c.pc==0x1234);
        for(const auto& e:original_events){const auto command=command_from_event(e);check(reference.apply({&command,1}).status==b::Status::ok);}
        if(family==0)frontend.actor(*actor,event_id,false);else if(family==1)frontend.actor(*actor,event_id,true);else frontend.resource(*actor,std::uint16_t(event_id));
        check(session->random.state().primary==read<std::uint16_t>(memory.data(),0x3244b0)&&session->random.state().secondary==read<std::uint16_t>(memory.data(),0x3244b8)&&session->random.state().observed==memory[0x2b8de8]);
        check((frontend.last_result()?frontend.last_result()->commands:0)==original_events.size());
        const auto actual=engine->snapshot(),expected=reference.snapshot();check(actual.request_age==expected.request_age);
        for(unsigned port=0;port<14;++port)for(unsigned index=0;index<16;++index){const auto& x=actual.ports[port].requests[index];const auto& y=expected.ports[port].requests[index];check(x.index==y.index&&x.group==y.group&&x.priority==y.priority&&x.cancel_flags==y.cancel_flags&&x.request_volume==y.request_volume&&x.request_pan==y.request_pan&&x.request_pitch==y.request_pitch&&x.sequence.active==y.sequence.active&&x.sequence.cursor==y.sequence.cursor&&x.sequence.program_offset==y.sequence.program_offset);}
        std::array<float,128> output{},expected_output{};check(engine->mix_add(output.data(),64,gains)==b::Status::ok&&reference.mix_add(expected_output.data(),64,gains)==b::Status::ok);check(output==expected_output);
        frontend_commands+=original_events.size();frontend_family_commands[family]+=original_events.size();frontend_mixed_frames+=64;for(const auto sample:output)if(sample!=0)++frontend_signal_samples;++frontend_cases;
    }
    for(const auto count:frontend_family_commands)check(count>0);
    check(frontend_signal_samples>0);
    // Canonical owner and genuine generation guards, with no synthetic success.
    s::Random foreign_random; a::Owner foreign_owner(std::make_shared<b::Session>(),foreign_random);bool refused{};
    try{animation_audio::BasicAudio other(*world,foreign_owner,spatial,resources,templates);}catch(const std::invalid_argument&){refused=true;}check(refused);++frontend_refusals;
    audio_world::Actor foreign_actor;refused=false;try{frontend.actor(foreign_actor,0,false);}catch(const std::runtime_error&){refused=true;}check(refused);++frontend_refusals;
    for(unsigned operation=0;operation<3;++operation){refused=false;try{if(operation==0)frontend.surface(*actor,0);else if(operation==1)frontend.node(*actor,0);else frontend.position(*actor,0);}catch(const std::runtime_error&){refused=true;}check(refused);++frontend_refusals;}
    world->retire_primary(0);refused=false;try{frontend.actor(*actor,0,false);}catch(const std::runtime_error&){refused=true;}check(refused);++frontend_refusals;
    world->close();refused=false;try{frontend.actor(*actor,0,false);}catch(const std::runtime_error&){refused=true;}check(refused);++frontend_refusals;
}
