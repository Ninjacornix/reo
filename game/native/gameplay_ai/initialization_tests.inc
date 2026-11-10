std::uint64_t initialization_cases{},initialization_disabled{},initialization_limited{},initialization_refusals{};
std::shared_ptr<const reo::native::gameplay_navigation::Asset> initialization_asset(){
    std::array<std::uint8_t,20> bytes{};bytes[0]=0x24;bytes[1]=7;bytes[2]=3;bytes[3]=0x20;bytes[4]=12;bytes[8]=16;
    reo::native::gameplay_navigation::ImportFailure failure;auto asset=reo::native::gameplay_navigation::Asset::read(bytes,failure);check(bool(asset));
    return std::make_shared<const reo::native::gameplay_navigation::Asset>(std::move(*asset));
}
#ifdef REO_AI_ORIGINAL
void project_initial_route(std::vector<std::uint8_t>& target,const reo::native::gameplay_navigation::ActorRouteState& route){
    constexpr unsigned a=0x10000;
    target[a+0x100c]=std::uint8_t(route.current_node);target[a+0x100d]=std::uint8_t(route.destination_node);target[a+0x1065]=std::uint8_t(route.last_current_node);
    target[a+0x100e]=std::uint8_t(route.output.route.first);target[a+0x100f]=std::uint8_t(route.output.route.second);
    std::memcpy(target.data()+a+0x1010,&route.final_position,12);std::memcpy(target.data()+a+0x101c,&route.output.route.first_position,12);std::memcpy(target.data()+a+0x1028,&route.output.route.second_position,12);
    put(target,a+0x1054,route.previous_action);put(target,a+0x1056,route.action);put(target,a+0x1058,route.destination_room);put(target,a+0x10aa,route.output.link);
    target[a+0x105a]=route.completed;target[a+0x105b]=route.selection_mode;target[a+0x1064]=route.refresh;
}
#endif
void initialization_contracts(){
    namespace nav=reo::native::gameplay_navigation;
    reo::native::gameplay_session::RoomVariants variants;const auto asset=initialization_asset();
    for(unsigned profile=0;profile<4;++profile)for(unsigned slot=0;slot<256;++slot)for(std::uint8_t enabled:{0,1,255}){
        nav::Bank bank(variants);check(bank.bind(asset)&&bank.header_byte()==0x24);
        ai::ControlRequests controls;
        if(profile==1){(void)controls.register_control(0,slot);controls.registration(0)->phase=7;controls.registration(0)->payload={1,2,3,4};}
        else if(profile==2)for(unsigned i=0;i<64;++i)(void)controls.register_control(1,i);
        else if(profile==3){(void)controls.register_control(0,slot);for(unsigned i=0;i<64;++i)(void)ai::publish_actor_control(controls,std::uint8_t(slot),i);}
        auto execution=state(slot+profile*256);nav::ActorRouteState route;
        route.current_node=-3;route.destination_node=4;route.last_current_node=7;route.final_position={1,2,3};route.output.route={5,6,{4,5,6},{7,8,9}};route.output.link=314;
        route.previous_action=0x1234;route.action=0x2345;route.destination_room=99;route.completed=7;route.selection_mode=3;route.refresh=8;
#ifdef REO_AI_ORIGINAL
        constexpr unsigned a=0x10000,base=0x7449b0,table_bytes=328+64*28;
        project(memory,execution);project_initial_route(memory,route);project_controls(memory,base,controls);
        memory[a+3]=std::uint8_t(slot);memory[a+0xff0]=enabled;memory[0x843780]=bank.header_byte();
        auto expected=std::vector<std::uint8_t>(memory.begin(),memory.begin()+0x11100);
        auto table=std::vector<std::uint8_t>(memory.begin()+base,memory.begin()+base+table_bytes);
#endif
        const auto result=ai::initialize(bank,controls,enabled,std::uint8_t(slot),&execution,&route);
        check(result.status==ai::Status::completed&&result.enabled==(enabled!=0)&&bank.header_byte()==0);
        if(!enabled){++initialization_disabled;check(!result.registration&&!result.publication);}
        else{check(result.registration.has_value()&&result.publication.has_value());if(result.publication->status!=ai::RequestStatus::queued)++initialization_limited;}
#ifdef REO_AI_ORIGINAL
        project(expected,execution);project_initial_route(expected,route);project_controls(table,0,controls);
        R5900Context context;PS2Runtime runtime;context.pc=0x8120c0;SET_GPR_U32(&context,4,a);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
        check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&memory[0x843780]==bank.header_byte());
        check(std::memcmp(expected.data()+a,memory.data()+a,0x1100)==0&&std::memcmp(table.data(),memory.data()+base,table_bytes)==0);
#endif
        ++initialization_cases;
    }
    nav::Bank bank(variants);check(bank.bind(asset));ai::ControlRequests controls;auto execution=state(17);const auto before=execution;nav::ActorRouteState route;
    check(ai::initialize(bank,controls,1,0,&execution,nullptr).status==ai::Status::unavailable&&execution==before&&controls.pending().empty()&&bank.header_byte()==0);++initialization_refusals;
    check(bank.bind(asset)&&bank.header_byte()==0); // rebinding is not reloading
    check(ai::initialize(bank,controls,1,0,nullptr,&route).status==ai::Status::unavailable&&controls.pending().empty());++initialization_refusals;
    check(bank.bind(initialization_asset())&&bank.header_byte()==0x24);
    check(ai::initialize(bank,controls,0,255,nullptr,nullptr).status==ai::Status::completed&&bank.header_byte()==0&&controls.pending().empty());
    bank.close();check(ai::initialize(bank,controls,0,0,nullptr,nullptr).status==ai::Status::unavailable);++initialization_refusals;
}
