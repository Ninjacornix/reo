std::uint64_t control_membership_cases{},control_register_cases{},control_unregister_cases{},control_lookup_cases{},control_request_cases{},control_publish_cases{};
std::uint64_t control_apply_cases{},control_receive_cases{},control_receive_refusals{},activity_queries{};
[[maybe_unused]] std::int32_t reference_activity_mode{};
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
void compare_control_receive(ai::ControlRequests& controls,std::span<const std::uint8_t> packet,std::int32_t activity,bool direct=false,std::uint8_t index=0,std::uint8_t mode=0){
#ifdef REO_AI_ORIGINAL
    constexpr unsigned base=0x7449b0,bytes=328+64*28,input=0x20000;
    project_controls(memory,base,controls);auto expected=std::vector<std::uint8_t>(memory.begin()+base,memory.begin()+base+bytes);
#endif
    const auto result=direct?controls.apply(index,packet,mode,activity):controls.receive(packet,activity);
    if(result.status!=ai::ControlApplyStatus::completed){++control_receive_refusals;return;}
#ifdef REO_AI_ORIGINAL
    project_controls(expected,0,controls);std::memcpy(memory.data()+input,packet.data(),packet.size());reference_activity_mode=activity;
    R5900Context context;PS2Runtime runtime;context.pc=direct?0x681820:0x6818d0;
    SET_GPR_U32(&context,4,direct?index:0);SET_GPR_U32(&context,5,input);SET_GPR_U32(&context,6,0xa5);SET_GPR_U32(&context,7,mode);
    SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&std::memcmp(expected.data(),memory.data()+base,bytes)==0);
#endif
    if(direct)++control_apply_cases;else ++control_receive_cases;
}
void control_receive_contracts(){
    ai::ControlRequests controls;
    for(unsigned i=0;i<64;++i){auto& entry=*controls.registration(i);entry.active=std::uint8_t(i%3);entry.kind=std::uint8_t(i);entry.phase=0xff;entry.owner_tag=255;entry.target=std::int16_t(i);entry.counters.fill(4321);}
    const std::array<std::uint8_t,4> payload{255,128,7,0};
    for(unsigned index=0;index<256;++index)for(std::uint8_t mode:{0,1,2,255})for(std::int32_t activity:{-1,0,1,2}){
        compare_control_receive(controls,payload,activity,true,std::uint8_t(index),mode);
    }
    std::array<std::uint8_t,260> packet{};packet[2]=0xa5;packet[3]=0xff;
    for(unsigned i=4;i<packet.size();++i)packet[i]=std::uint8_t(i*43);
    for(unsigned mode=0;mode<256;++mode)for(unsigned length=0;length<256;++length){
        packet[0]=std::uint8_t(mode);packet[1]=std::uint8_t(length);
        compare_control_receive(controls,packet,std::int32_t(length%3)-1);
    }
    // Malformed frames are a bounded admission boundary; no prefix is applied.
    const auto before=*controls.registration(0);std::array<std::uint8_t,9> short_packet{};
    for(unsigned size=0;size<9;++size)check(controls.receive(std::span(short_packet).first(size),0).status==ai::ControlApplyStatus::malformed);
    short_packet[0]=1;short_packet[1]=8;check(controls.receive(std::span(short_packet).first(7),0).status==ai::ControlApplyStatus::malformed);
    check(*controls.registration(0)==before);
    short_packet[1]=6;short_packet[4]=0;short_packet[5]=77;
    check(controls.receive(short_packet,{}).status==ai::ControlApplyStatus::unavailable&&*controls.registration(0)==before);
    short_packet[1]=4;check(controls.receive(short_packet,{}).status==ai::ControlApplyStatus::completed); // no entries, mode unused
    short_packet[0]=0;check(controls.receive(short_packet,{}).status==ai::ControlApplyStatus::completed); // payload does not consume activity
    check(controls.apply(0,{},1,1).status==ai::ControlApplyStatus::completed); // no payload read on ignored owner update
    check(controls.apply(0,{},0,0).status==ai::ControlApplyStatus::malformed);
    check(controls.apply(0,{},1,0).status==ai::ControlApplyStatus::malformed);
}
