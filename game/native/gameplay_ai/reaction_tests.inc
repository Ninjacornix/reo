std::uint64_t reaction_cases{},reaction_random_draws{},reaction_writes{},reaction_refusals{};
void compare_reaction(std::uint32_t event,std::uint8_t character,std::uint16_t seed,ai::ExecutionState before){
    auto actual=before;reo::native::gameplay_session::Random random({seed,std::uint16_t(seed^0x9876),std::uint8_t(seed+13)});
#ifdef REO_AI_ORIGINAL
    constexpr unsigned actor=0x10000,random_at=0x3244a0;
    project(memory,before);memory[actor+0xb98]=character;
    auto expected=std::vector<std::uint8_t>(memory.begin()+actor,memory.begin()+actor+0x1100);
    for(unsigned i=0;i<32;++i)memory[random_at+i]=std::uint8_t(seed+7*i);
    put(memory,0x3244b0,random.state().primary);put(memory,0x3244b8,random.state().secondary);
    std::array<std::uint8_t,32> expected_random;std::memcpy(expected_random.data(),memory.data()+random_at,32);
#endif
    const auto result=ai::schedule_reaction(actual,character,event,random);check(result.status==ai::Status::completed);
    check(random.state().secondary==std::uint16_t(seed^0x9876)&&random.state().observed==std::uint8_t(seed+13));
#ifdef REO_AI_ORIGINAL
    project(expected,actual,0);
    const auto primary=random.state().primary;std::memcpy(expected_random.data()+16,&primary,2);
    const auto draws=reference_random_draws;R5900Context context;PS2Runtime runtime;context.pc=0x8130d0;
    SET_GPR_U32(&context,4,actor);SET_GPR_U32(&context,5,event);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&reference_random_draws-draws==result.random_draws);
    check(std::memcmp(expected.data(),memory.data()+actor,0x1100)==0&&std::memcmp(expected_random.data(),memory.data()+random_at,32)==0);
#endif
    ++reaction_cases;reaction_random_draws+=result.random_draws;reaction_writes+=result.written;
}
void reaction_contracts(){
    // Every16-bit initial RNG state against each complete event, forcing the
    // weighted probability branch for5..8. Includes source seed0=>1 behavior.
    for(unsigned seed=0;seed<65536;++seed)for(unsigned event=0;event<13;++event){
        auto value=state(seed);value.combined_weights.fill(0);
        if(event>=5&&event<=8)value.combined_weights[event==5?2:event==8?4:0]=123;
        compare_reaction(event,0,std::uint16_t(seed),value);
    }
    // Every authored chance column; independently varied prior state/streams.
    for(unsigned event=0;event<13;++event)for(unsigned character=0;character<8;++character)for(unsigned seed=0;seed<256;++seed){
        auto value=state(seed);value.combined_weights.fill(0);
        if(event>=5&&event<=8)value.combined_weights[event==5?2:event==8?4:0]=255;
        compare_reaction(event,std::uint8_t(character),std::uint16_t(seed*257),value);
    }
    for(unsigned event=5;event<=8;++event)for(unsigned winner=0;winner<8;++winner)for(unsigned weight=0;weight<256;++weight){
        auto value=state(weight);value.combined_weights.fill(0);value.combined_weights[winner]=std::uint8_t(weight);
        compare_reaction(event,std::uint8_t(weight%8),std::uint16_t(weight*199),value);
        // Equal maxima preserve the earliest weight; all-zero chooses index0.
        value.combined_weights[0]=std::uint8_t(weight);compare_reaction(event,std::uint8_t(weight%8),std::uint16_t(weight*179),value);
    }
    for(unsigned event=13;event<256;++event)for(unsigned character:{0u,7u,8u,255u})compare_reaction(event,std::uint8_t(character),65535,state(event));
    for(unsigned event:{256u,65536u,0x80000000u,0xffffffffu})compare_reaction(event,255,0,state(1));
    for(unsigned character=8;character<256;++character)for(unsigned event=0;event<12;++event){
        auto value=state(character);value.combined_weights.fill(0);if(event>=5&&event<=8)value.combined_weights[event==5?2:event==8?4:0]=1;
        const auto before=value;reo::native::gameplay_session::Random random({1234,5678,99});const auto prior=random.state();
        const auto result=ai::schedule_reaction(value,std::uint8_t(character),event,random);
        check(result.status==ai::Status::unavailable&&result.random_draws==0&&!result.written&&value==before&&random.state()==prior);++reaction_refusals;
    }
    // Unauthored characters need no chance profile on deterministic branches.
    auto value=state(7);value.combined_weights.fill(0);value.combined_weights[3]=100;
    for(unsigned event=5;event<=8;++event)compare_reaction(event,255,123,value);
    compare_reaction(12,255,0,value);
}
