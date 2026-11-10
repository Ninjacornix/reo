std::uint64_t observation_blocked_cases{},observation_gate_cases{},observation_gate_random_draws{},observation_gate_admitted{},observation_gate_refusals{};
void compare_observation_blocked(const gw::Actor& actor){
    [[maybe_unused]] const auto result=ai::observation_blocked(actor);
#ifdef REO_AI_ORIGINAL
    project_goal_actor(memory,0x10000,actor);R5900Context context;PS2Runtime runtime;context.pc=0x813bd0;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&result==(GPR_U32(&context,2)!=0));
#endif
    ++observation_blocked_cases;
}
void compare_observation_gate(gw::Actor actor,gw::Actor reference,std::uint32_t mode,std::uint16_t seed,bool alias=false){
    const auto other=alias?&actor:&reference;
    reo::native::gameplay_session::Random random({seed,std::uint16_t(seed^0x32f1),std::uint8_t(seed+7)});
#ifdef REO_AI_ORIGINAL
    constexpr unsigned self_at=0x10000;const unsigned other_at=alias?self_at:0x20000;
    project_goal_actor(memory,self_at,actor);project_goal_actor(memory,other_at,*other);
    auto expected=std::vector<std::uint8_t>(memory.begin()+self_at,memory.begin()+self_at+0x1100),expected_other=std::vector<std::uint8_t>(memory.begin()+other_at,memory.begin()+other_at+0x1100);
    put(memory,0x3244b0,seed);put(memory,0x3244b8,random.state().secondary);const auto draws=reference_random_draws;
#endif
    const auto result=ai::admit_reference_reaction(actor,other,mode,random);check(result.status==ai::Status::completed);
    check(random.state().secondary==std::uint16_t(seed^0x32f1)&&random.state().observed==std::uint8_t(seed+7));
#ifdef REO_AI_ORIGINAL
    project_goal_actor(expected,0,actor);project_goal_actor(expected_other,0,*other);
    R5900Context context;PS2Runtime runtime;context.pc=0x812ef0;SET_GPR_U32(&context,4,self_at);SET_GPR_U32(&context,5,other_at);SET_GPR_U32(&context,6,mode);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&result.admitted==(GPR_U32(&context,2)!=0)&&reference_random_draws-draws==result.random_draws);
    check(transform_read<std::uint16_t>(memory.data(),0x3244b0)==random.state().primary&&transform_read<std::uint16_t>(memory.data(),0x3244b8)==random.state().secondary);
    check(std::memcmp(expected.data(),memory.data()+self_at,0x1100)==0&&std::memcmp(expected_other.data(),memory.data()+other_at,0x1100)==0);
#endif
    ++observation_gate_cases;observation_gate_random_draws+=result.random_draws;observation_gate_admitted+=result.admitted;
}
void observation_gate_contracts(){
    gw::Actor actor,reference;actor.ai_execution=state(3);reference.ai_execution=state(7);actor.room=17;
    for(unsigned motion=0;motion<256;++motion)for(unsigned aux=0;aux<33;++aux)for(unsigned status=0;status<33;++status){
        actor.motion_class=std::uint8_t(motion);actor.auxiliary_status=aux==32?0xffffffffu:1u<<aux;actor.status=status==32?0u:1u<<status;compare_observation_blocked(actor);
    }
    for(unsigned seed=0;seed<65536;++seed)for(unsigned character=0;character<8;++character){
        actor.character=std::uint8_t(character);actor.ai_execution->room_memo=65535;actor.ai_execution->room_reaction_gate=0;
        for(unsigned context=0;context<4;++context){actor.ai_execution->weight_mode=std::uint8_t(context&1);reference.ai_execution->weight_mode=std::uint8_t(context&2);compare_observation_gate(actor,reference,0,std::uint16_t(seed));}
        compare_observation_gate(actor,reference,1,std::uint16_t(seed));
    }
    for(unsigned room=0;room<65536;++room)for(unsigned gate:{0u,255u})for(bool same:{false,true}){
        actor.character=3;actor.room=std::uint16_t(room);actor.ai_execution->room_memo=std::uint16_t(room+(same?0:1));actor.ai_execution->room_reaction_gate=std::uint8_t(gate);
        compare_observation_gate(actor,reference,0xffffffffu,std::uint16_t(room));
    }
    actor.room=17;actor.ai_execution->room_memo=65535;actor.ai_execution->room_reaction_gate=0;
    for(unsigned value=0;value<256;++value)for(unsigned character=0;character<8;++character){
        actor.character=std::uint8_t(character);actor.ai_execution->weight_mode=std::uint8_t(value);reference.ai_execution->weight_mode=std::uint8_t(255-value);compare_observation_gate(actor,reference,0,std::uint16_t(value*257));
        compare_observation_gate(actor,reference,0,std::uint16_t(value*251),true);
    }
    for(unsigned character=8;character<256;++character)for(unsigned mode:{0u,1u}){
        actor.character=std::uint8_t(character);auto before=*actor.ai_execution;reo::native::gameplay_session::Random random({123,456,7});const auto old=random.state();
        const auto result=ai::admit_reference_reaction(actor,&reference,mode,random);check(result.status==ai::Status::unavailable&&*actor.ai_execution==before&&random.state()==old);++observation_gate_refusals;
    }
    actor.character=0;reo::native::gameplay_session::Random random({123,456,7});const auto before=*actor.ai_execution,old_reference=*reference.ai_execution;const auto old=random.state();
    check(ai::admit_reference_reaction(actor,nullptr,0,random).status==ai::Status::unavailable&&*actor.ai_execution==before&&random.state()==old);++observation_gate_refusals;
    reference.ai_execution.reset();check(ai::admit_reference_reaction(actor,&reference,0,random).status==ai::Status::unavailable&&*actor.ai_execution==before&&random.state()==old);++observation_gate_refusals;
    reference.ai_execution=old_reference;actor.ai_execution->room_memo=actor.room;check(ai::admit_reference_reaction(actor,nullptr,1,random).status==ai::Status::completed&&random.state()==old);
    actor.ai_execution.reset();check(ai::admit_reference_reaction(actor,&reference,0,random).status==ai::Status::unavailable&&random.state()==old);++observation_gate_refusals;
}
