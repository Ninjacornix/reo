void destination_contracts(){
    auto bytes=cross_asset();constexpr unsigned count=8,b=16+12*count+count*count+4*count,start=b+4+12*4;
    for(unsigned room=0;room<4;++room)for(unsigned node=0;node<4;++node)for(unsigned slot=0;slot<4;++slot){
        constexpr std::array<std::uint16_t,4> actions{0x101,0x207,0x308,0x40d};put(bytes,start+440*room+12+64*node+24+2*slot,actions[node]);
    }
    reo::native::gameplay_session::RoomVariants variants;variants.restore({});n::Bank bank(variants);n::RoomFlags flags;flags.fill(0);
    check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));
    const std::array<n::Position,9> offsets{{{0,0,0},{49.999f,0,0},{50,0,0},{100,0,0},{0,0,50},{0,0,-50},{2,20,3},{2,-20,3},{0,100,0}}};
    for(unsigned destination_room:{7u,8u})for(unsigned source=0;source<4;++source)for(unsigned destination=0;destination<4;++destination)
        for(unsigned motion:{0u,0x1au,0x27u,0x31u})for(unsigned status:{0u,8u})for(const auto offset:offsets)
            for(unsigned marker:{0u,1u})for(unsigned session_room:{7u,8u}){
                check(bank.occupancy(42,63,0xff));auto state=actor_route_state(std::int8_t(source),-1,10);
                BeginCase input{{{7,0,255},status,marker?0x10000u:0u,7,{700.f+float(source)+offset.x,offset.y,offset.z},std::uint8_t(motion),std::uint8_t(marker)},std::uint16_t(session_room),{100.f*float(destination_room)+float(destination),0,0},std::uint16_t(destination_room)};
                compare_actor_route(bank,bytes,input.actor.identity,status,flags,7,state,true,{destination_room!=7,4096,128},&input);
                check(bank.occupancy(42,63)==0xfe);
            }
    auto state=actor_route_state(0,1,7);BeginCase input{{{},0,0,7,{},0,0},7,{std::numeric_limits<float>::quiet_NaN(),0,0},7};
    const auto unknown=compare_actor_route(bank,bytes,{},0,flags,7,state,true,{},&input);
    check(unknown.status==n::QueryStatus::unavailable&&state.completed==0&&state.refresh==0&&state.output.link==-1&&std::isnan(state.final_position.x)&&state.destination_node==1);
    state=actor_route_state(0,1,7);input.actor.identity.slot=5;input.target={700,0,0};
    check(compare_actor_route(bank,bytes,{0,5,0},0,flags,7,state,true,{},&input).status==n::QueryStatus::unavailable&&state.destination_node==0&&state.last_current_node==-24);
}
