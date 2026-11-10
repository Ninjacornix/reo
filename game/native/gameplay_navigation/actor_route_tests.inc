std::uint64_t actor_route_cases{},actor_action_cases{},actor_route_refusals{},actor_route_corrected_cases{},actor_route_retail_cases{};
std::uint64_t destination_cases{},destination_refusals{},destination_corrected_cases{},destination_retail_cases{};
struct BeginCase {n::RouteActorFacts actor;std::uint16_t session_room{};n::Position target;std::uint16_t target_room{};};
n::CrossRoomResult compare_actor_route(n::Bank& bank,[[maybe_unused]] std::span<const std::uint8_t> bytes,n::ActorFacts facts,unsigned status,const n::RoomFlags& flags,
    std::uint16_t room,n::ActorRouteState& state,bool action,n::CrossRoomProfile profile,const BeginCase* begin=nullptr){
    [[maybe_unused]] const auto before=state;
#ifdef REO_NAVIGATION_ORIGINAL
    cross_reference_setup(bank,bytes,facts,status,flags);
#endif
    const auto result=begin?n::begin_actor_route(bank,begin->actor,begin->session_room,flags,state,begin->target,begin->target_room,profile):action?n::update_actor_route_action(bank,facts,status,room,flags,state,profile):n::refresh_actor_route(bank,facts,status,room,flags,state,profile);
    if(result.status!=n::QueryStatus::completed){if(begin)++destination_refusals;else ++actor_route_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    constexpr unsigned actor=0xf00000;std::fill(memory.begin()+actor+0x100c,memory.begin()+actor+0x10ac,0xcc);
    const auto write_byte=[&](unsigned offset,std::int8_t value){memory[actor+offset]=std::bit_cast<std::uint8_t>(value);};
    const auto write_position=[&](unsigned offset,n::Position value){std::memcpy(memory.data()+actor+offset,&value,12);};
    write_byte(0x100c,before.current_node);write_byte(0x100d,before.destination_node);write_byte(0x1065,before.last_current_node);
    write_byte(0x100e,before.output.route.first);write_byte(0x100f,before.output.route.second);write_position(0x1010,before.final_position);
    write_position(0x101c,before.output.route.first_position);write_position(0x1028,before.output.route.second_position);
    put(memory,actor+0x1054,before.previous_action);put(memory,actor+0x1056,before.action);put(memory,actor+0x1058,before.destination_room);put(memory,actor+0x10aa,before.output.link);
    memory[actor+0x105a]=before.completed;memory[actor+0x1064]=before.refresh;put(memory,actor+0x1e2,room);
    if(begin){
        const auto& input=begin->actor;check(input.identity.slot==facts.slot&&input.status==status&&input.room==room);
        put(memory,actor+0xba4,input.auxiliary_status);write_position(0x38,input.position);memory[actor+0x54f]=input.motion_class;memory[actor+0x10a9]=input.transient_marker;
        put(memory,0x3243dc,begin->session_room);std::memcpy(memory.data()+0x1e00000,&begin->target,12);
    }
    reference_initialize_collection=profile.initialize_collection_cost;
    const auto expected=std::bit_cast<std::int32_t>(call(begin?0x816890:action?0x816ef0:0x8173d0,{actor,begin?0x1e00000u:123u,begin?begin->target_room:before.destination_room,0}));reference_initialize_collection=false;
    check(result.selected==expected&&reference_collection_calls==result.calls);
    const auto check_byte=[&](unsigned offset,std::int8_t value){check(std::bit_cast<std::uint8_t>(value)==memory[actor+offset]);};
    const auto check_half=[&](unsigned offset,std::uint16_t value){check(std::uint16_t(std::uint16_t(memory[actor+offset])|std::uint16_t(memory[actor+offset+1])<<8)==value);};
    const auto check_position=[&](unsigned offset,n::Position value){check(std::memcmp(&value,memory.data()+actor+offset,12)==0);};
    check_byte(0x100c,state.current_node);check_byte(0x100d,state.destination_node);check_byte(0x1065,state.last_current_node);
    check_byte(0x100e,state.output.route.first);check_byte(0x100f,state.output.route.second);check_position(0x1010,state.final_position);
    check_position(0x101c,state.output.route.first_position);check_position(0x1028,state.output.route.second_position);
    check_half(0x1054,state.previous_action);check_half(0x1056,state.action);check_half(0x1058,state.destination_room);check_half(0x10aa,std::bit_cast<std::uint16_t>(state.output.link));
    check(memory[actor+0x105a]==state.completed&&memory[actor+0x1064]==state.refresh);
    const auto mask=word(memory,0x83e54c);for(unsigned actor_slot=0;actor_slot<4;++actor_slot){const auto visits=bank.visits(actor_slot);check(std::equal(visits.begin(),visits.end(),memory.begin()+mask+actor_slot*visits.size()));}
    for(unsigned node=0;node<128;++node){check(bank.occupancy(room,node)==memory[0x83e550+164*room+0x14+node]);}
    if(begin){++destination_cases;if(profile.initialize_collection_cost)++destination_corrected_cases;}
    else{if(action)++actor_action_cases;else ++actor_route_cases;if(profile.initialize_collection_cost)++actor_route_corrected_cases;}
#endif
    return result;
}
n::ActorRouteState actor_route_state(std::int8_t source,std::int8_t destination,std::uint16_t room){
    n::ActorRouteState state;state.current_node=source;state.destination_node=destination;state.last_current_node=-24;
    state.final_position={1234,5678,9999};state.output={{-22,-23,{1,2,3},{4,5,6}},314};
    state.previous_action=321;state.action=543;state.destination_room=room;state.completed=7;state.refresh=9;return state;
}
void actor_route_contracts(){
    auto bytes=cross_asset();constexpr unsigned count=8,b=16+12*count+count*count+4*count,start=b+4+12*4;
    // Full16-bit actions distinguish the first direct from last reverse match.
    for(unsigned room=0;room<4;++room)for(unsigned node=0;node<4;++node)for(unsigned slot=0;slot<4;++slot){
        put(bytes,start+440*room+12+64*node+24+2*slot,std::uint16_t(0x100+0x100*room+0x10*node+slot));
    }
    reo::native::gameplay_session::RoomVariants variants;variants.restore({});n::Bank bank(variants);n::RoomFlags flags;flags.fill(0);
    check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));
    for(unsigned room=7;room<=10;++room)for(unsigned destination_room=7;destination_room<=10;++destination_room)
        for(unsigned source=0;source<4;++source)for(unsigned destination=0;destination<4;++destination)
            for(unsigned status:{0u,8u,0x80u})for(unsigned slot:{0u,3u})for(bool action:{false,true}){
                check(bank.clear_actor_visits(slot));auto state=actor_route_state(std::int8_t(source),std::int8_t(destination),std::uint16_t(destination_room));
                compare_actor_route(bank,bytes,{7,std::uint8_t(slot),255},status,flags,std::uint16_t(room),state,action,{room!=destination_room,4096,128});
            }
    // Occupancy uses the source32-bit shift followed by byte truncation. Local
    // routing does not demand a four-slot cross-room visit capability.
    for(unsigned slot:{5u,8u,31u,32u,255u}){
        check(bank.occupancy(7,0,0));auto state=actor_route_state(0,0,7);
        const auto result=compare_actor_route(bank,bytes,{0,std::uint8_t(slot),0},0,flags,7,state,true,{});
        check(result.selected==0&&bank.occupancy(7,0)==std::uint8_t(std::uint32_t(1)<<(slot&31)));
    }
    check(bank.clear_actor_visits(0));auto state=actor_route_state(0,1,7);
    check(compare_actor_route(bank,bytes,{},0,flags,7,state,true,{}).selected==0&&state.action==0x101&&state.previous_action==321);
    check(state.output.route.first_position.x==1234&&state.output.route.second_position.y==5678&&state.output.route.first==1);
    state=actor_route_state(1,1,7);check(compare_actor_route(bank,bytes,{},0,flags,7,state,true,{}).selected==0&&state.action==0x131);
    check(bank.clear_actor_visits(0));state=actor_route_state(1,0,8);const auto unknown=compare_actor_route(bank,bytes,{},0,flags,7,state,false,{});
    check(unknown.collection_failure==n::CollectionFailure::unknown_cost&&state.last_current_node==-24&&state.output.link==314);
    state=actor_route_state(0,0,8);const auto blocked=compare_actor_route(bank,bytes,{},8,flags,7,state,false,{});
    check(blocked.status==n::QueryStatus::completed&&blocked.selected==-1&&state.last_current_node==0&&state.output.link==314);
}
