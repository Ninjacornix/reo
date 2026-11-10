std::uint64_t control_membership_cases{},control_register_cases{},control_unregister_cases{},control_lookup_cases{},control_request_cases{},control_publish_cases{};
#ifdef REO_AI_ORIGINAL
void project_controls(std::vector<std::uint8_t>& target,unsigned base,const ai::ControlRequests& controls){
    put(target,base,std::uint32_t(controls.pending().size()));
    for(unsigned i=0;i<controls.pending().size();++i){const auto& request=controls.pending()[i];target[base+8+5*i]=request.registration;std::memcpy(target.data()+base+9+5*i,request.payload.data(),4);}
    for(unsigned i=0;i<64;++i){const auto at=base+328+28*i;const auto& entry=controls.registrations()[i];
        target[at]=entry.active;target[at+1]=entry.kind;target[at+2]=entry.phase;target[at+3]=entry.owner_tag;put(target,at+4,entry.target);
        std::memcpy(target.data()+at+6,entry.payload.data(),4);for(unsigned j=0;j<4;++j)put(target,at+16+2*j,entry.counters[j]);
    }
}
#endif
void compare_controls(ai::ControlRequests& controls,unsigned pc,std::uint32_t kind,std::uint32_t target,std::int32_t selector=-1,std::array<std::uint8_t,4> payload={1,2,3,4}){
    [[maybe_unused]] bool member{};[[maybe_unused]] std::optional<std::uint8_t> selected;[[maybe_unused]] ai::RequestResult requested;
#ifdef REO_AI_ORIGINAL
    constexpr unsigned base=0x7449b0,bytes=328+64*28,actor=0x10000,input=0x20000;
    project_controls(memory,base,controls);auto expected=std::vector<std::uint8_t>(memory.begin()+base,memory.begin()+base+bytes);
#endif
    switch(pc){
    case 0x681240:member=controls.registered(kind,target);++control_membership_cases;break;
    case 0x6812b0:(void)controls.register_control(kind,target);++control_register_cases;break;
    case 0x681330:(void)controls.unregister_control(kind,target);++control_unregister_cases;break;
    case 0x681710:selected=controls.find(std::bit_cast<std::int32_t>(kind),std::bit_cast<std::int32_t>(target),selector);++control_lookup_cases;break;
    case 0x681790:requested=controls.request(std::bit_cast<std::int32_t>(kind),std::bit_cast<std::int32_t>(target),payload,selector);++control_request_cases;break;
    case 0x815df0:requested=ai::publish_actor_control(controls,std::uint8_t(kind),target);++control_publish_cases;break;
    default:throw std::runtime_error("Undeclared control test entry");
    }
#ifdef REO_AI_ORIGINAL
    project_controls(expected,0,controls);R5900Context context;PS2Runtime runtime;context.pc=pc;
    SET_GPR_U32(&context,4,kind);SET_GPR_U32(&context,5,target);SET_GPR_U32(&context,7,std::uint32_t(selector));
    if(pc==0x681710){SET_GPR_U32(&context,4,base+328);SET_GPR_U32(&context,5,kind);SET_GPR_U32(&context,6,target);}
    if(pc==0x681790){std::memcpy(memory.data()+input,payload.data(),4);SET_GPR_U32(&context,6,input);}
    if(pc==0x815df0){memory[actor+3]=std::uint8_t(kind);SET_GPR_U32(&context,4,actor);}
    SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&std::memcmp(expected.data(),memory.data()+base,bytes)==0);
    if(pc==0x681240)check(member==(GPR_U32(&context,2)!=0));
    if(pc==0x681710)check((selected?std::int32_t(*selected):-1)==std::bit_cast<std::int32_t>(GPR_U32(&context,2)));
    if(pc==0x681790||pc==0x815df0)check((requested.registration?std::int32_t(*requested.registration):-1)==std::bit_cast<std::int32_t>(GPR_U32(&context,2)));
#endif
}
void control_contracts(){
    ai::ControlRequests controls;
    for(unsigned i=0;i<64;++i){
        auto& entry=*controls.registration(i);entry.phase=std::uint8_t(3*i);entry.owner_tag=std::uint8_t(7*i);entry.payload={1,2,3,4};entry.counters.fill(1234);
        compare_controls(controls,0x6812b0,i%4,i);compare_controls(controls,0x681240,i%4,i);
        compare_controls(controls,0x6812b0,(i%4)|0xffffff00u,i|0xffff0000u); // source narrow duplicate key
    }
    compare_controls(controls,0x6812b0,0,1000);check(controls.register_control(0,1000)==ai::RegistrationStatus::full);
    for(unsigned i=0;i<64;i+=3){compare_controls(controls,0x681330,i%4,i);compare_controls(controls,0x681330,i%4,i);compare_controls(controls,0x6812b0,255,0xffff8000u+i);}
    // Exercise full-argument lookup versus narrowed registration keys and all
    // selector byte boundaries. Lookup itself never narrows kind/target.
    for(unsigned sample=0;sample<64;++sample){
        ai::ControlRequests snapshot;
        for(unsigned i=0;i<64;++i){auto& e=*snapshot.registration(i);e.active=std::uint8_t((i+sample)%4);e.kind=std::uint8_t((i+sample)%5==0?255:(i+sample)%3);e.target=std::bit_cast<std::int16_t>(std::uint16_t(i%7==0?0x8000u:i%5==0?0xffffu:i%4));e.owner_tag=std::uint8_t(i%5==0?255:i%4);}
        for(unsigned kind:{0u,1u,2u,255u,256u,0xffffffffu})for(unsigned target:{0u,1u,2u,0xffffu,0xffff8000u,0xffffffffu})for(std::int32_t selector:{-1,0,1,254,255,256,511,-2}){
            compare_controls(snapshot,0x681710,kind,target,selector);
            auto requests=snapshot;compare_controls(requests,0x681790,kind,target,selector,{std::uint8_t(sample),2,3,255});
        }
    }
    ai::ControlRequests pending;compare_controls(pending,0x6812b0,0,5);
    for(unsigned i=0;i<64;++i)compare_controls(pending,0x815df0,5,0xffff0000u+i);
    check(pending.pending().size()==64&&pending.pending()[63].payload==std::array<std::uint8_t,4>{63,0,0,0});
    compare_controls(pending,0x815df0,5,999);compare_controls(pending,0x815df0,6,999);
    check(pending.request(0,5,{}).status==ai::RequestStatus::full&&pending.request(0,6,{}).status==ai::RequestStatus::missing_registration);
}
