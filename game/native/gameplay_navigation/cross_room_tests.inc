std::uint64_t cross_search_cases{},cross_route_cases{},cross_refusals{},cross_corrected_cases{},cross_retail_cases{};
#ifdef REO_NAVIGATION_ORIGINAL
bool reference_initialize_collection{};std::uint64_t reference_collection_calls{},reference_visit_copies{};std::uint32_t reference_cross_stack{};
void cross_reference_setup(const n::Bank& bank,std::span<const std::uint8_t> bytes,n::ActorFacts facts,unsigned status,const n::RoomFlags& flags){
    std::copy(bytes.begin(),bytes.end(),memory.begin()+0x843780);
    for(unsigned room=0;room<128;++room){memory[0x4b9d20+room]=bank.current_variant(room).value_or(0);put(memory,0x4b9e20+12*room,flags[room].value_or(0));}
    call(0x815e70,{2});
    for(unsigned room=0;room<128;++room)if(bank.room(room)){
        for(unsigned i=0;i<128;++i)memory[0x83e550+164*room+0x14+i]=*bank.occupancy(room,i);
        const auto address=word(memory,0x83e550+164*room+0xa0);const auto edge=bank.edge_flags(room);check(bool(edge));std::copy(edge->begin(),edge->end(),memory.begin()+address);
    }
    const auto mask=word(memory,0x83e54c);
    for(unsigned actor=0;actor<4;++actor){const auto visits=bank.visits(actor);std::copy(visits.begin(),visits.end(),memory.begin()+mask+actor*visits.size());}
    constexpr unsigned actor=0xf00000;memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;put(memory,actor+0xba0,status);
    std::fill(memory.begin()+0x1ec0000,memory.begin()+0x1f00000,0xa7);reference_collection_calls=0;
}
#endif
n::CrossRoomResult compare_cross_search(const n::Bank& bank,[[maybe_unused]] std::span<const std::uint8_t> bytes,n::ActorFacts facts,unsigned status,const n::RoomFlags& flags,
    std::int32_t entry,std::int32_t destination,std::vector<std::uint8_t>& visits,n::CrossRoomProfile profile){
    [[maybe_unused]] const auto before=visits;const auto result=n::search_link_path(bank,facts,status,flags,entry,destination,visits,profile);
    if(result.status!=n::QueryStatus::completed){++cross_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    cross_reference_setup(bank,bytes,facts,status,flags);constexpr unsigned mask=0x1c00000;std::copy(before.begin(),before.end(),memory.begin()+mask);
    reference_initialize_collection=profile.initialize_collection_cost;
    const auto expected=std::bit_cast<std::int32_t>(call(0x817820,{0xf00000,std::uint32_t(entry),std::uint32_t(destination),mask}));
    reference_initialize_collection=false;check(result.selected==expected&&reference_collection_calls==result.calls);
    check(std::equal(visits.begin(),visits.end(),memory.begin()+mask));++cross_search_cases;if(profile.initialize_collection_cost)++cross_corrected_cases;
#endif
    return result;
}
n::CrossRoomResult compare_cross_route(n::Bank& bank,[[maybe_unused]] std::span<const std::uint8_t> bytes,n::ActorFacts facts,unsigned status,const n::RoomFlags& flags,
    unsigned source_room,unsigned destination_room,std::int32_t source,std::int32_t destination,n::CrossRoomOutput& output,n::CrossRoomProfile profile){
    [[maybe_unused]] const auto before=output;
#ifdef REO_NAVIGATION_ORIGINAL
    cross_reference_setup(bank,bytes,facts,status,flags);
#endif
    const auto result=n::cross_room_route(bank,facts,status,flags,source_room,destination_room,source,destination,output,profile);
    if(result.status!=n::QueryStatus::completed){++cross_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    constexpr unsigned out=0x1d00000,stack=0x1f00000;std::fill_n(memory.begin()+out,64,0xcc);
    memory[out]=std::bit_cast<std::uint8_t>(before.route.first);memory[out+1]=std::bit_cast<std::uint8_t>(before.route.second);
    std::memcpy(memory.data()+out+4,&before.route.first_position,12);std::memcpy(memory.data()+out+16,&before.route.second_position,12);put(memory,out+28,before.link);
    put(memory,stack,out+16);put(memory,stack+8,out+28);R5900Context context;PS2Runtime runtime;context.pc=0x817470;
    const std::array<unsigned,8> args{0xf00000,source_room,destination_room,std::uint32_t(source),std::uint32_t(destination),out,out+1,out+4};
    for(unsigned i=0;i<args.size();++i){SET_GPR_U32(&context,4+i,args[i]);}SET_GPR_U32(&context,29,stack);SET_GPR_U32(&context,31,0x100);
    reference_initialize_collection=profile.initialize_collection_cost;original_transform_port(memory.data(),&context,&runtime);reference_initialize_collection=false;
    check(context.pc==0x100&&GPR_U32(&context,29)==stack&&result.selected==std::bit_cast<std::int32_t>(GPR_U32(&context,2))&&reference_collection_calls==result.calls);
    check(output.route.first==std::bit_cast<std::int8_t>(memory[out])&&output.route.second==std::bit_cast<std::int8_t>(memory[out+1]));
    check(std::memcmp(&output.route.first_position,memory.data()+out+4,12)==0&&std::memcmp(&output.route.second_position,memory.data()+out+16,12)==0);
    const auto link=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(memory[out+28])|std::uint16_t(memory[out+29])<<8));check(output.link==link);
    const auto mask=word(memory,0x83e54c);for(unsigned actor=0;actor<4;++actor){const auto visits=bank.visits(actor);check(std::equal(visits.begin(),visits.end(),memory.begin()+mask+actor*visits.size()));}
    ++cross_route_cases;if(profile.initialize_collection_cost)++cross_corrected_cases;
#endif
    return result;
}
std::vector<std::uint8_t> cross_asset(){
    constexpr unsigned count=8,rooms=4,b=16+12*count+count*count+4*count,start=b+4+12*rooms;
    const auto graph=synthetic();std::vector<std::uint8_t> bytes(start+440*rooms);
    put(bytes,0,std::uint32_t(0x20030724));put(bytes,4,std::uint32_t(12));put(bytes,8,std::uint32_t(b));put(bytes,12,std::uint32_t(count));put(bytes,b,std::uint32_t(rooms));
    const std::array<unsigned,8> room{7,8,8,9,8,10,9,10},node{1,0,2,0,3,0,3,2},paired{1,0,3,2,5,4,7,6};
    for(unsigned i=0;i<count;++i){bytes[16+12*i]=std::uint8_t(room[i]);bytes[18+12*i]=std::uint8_t(node[i]);bytes[20+12*i]=std::uint8_t(room[paired[i]]);put(bytes,26+12*i,std::uint16_t(paired[i]));}
    std::fill_n(bytes.begin()+16+12*count,count*count,1);
    for(unsigned r=0;r<rooms;++r){
        const auto payload=start+440*r;put(bytes,b+4+12*r,std::uint16_t(7+r));put(bytes,b+8+12*r,std::uint32_t(payload));
        std::copy(graph.begin()+synthetic_room,graph.end(),bytes.begin()+payload);bytes[payload+340]=1;bytes[payload+341]=3;
        const auto table=payload+12+64*4;std::fill_n(bytes.begin()+table,64,255);
        for(unsigned i=0;i<4;++i){const auto at=payload+12+64*i;bytes[at+1]=4;put(bytes,at+4,float((7+r)*100+i));
            for(unsigned slot=0;slot<4;++slot){bytes[at+20+slot]=std::uint8_t(slot);put(bytes,at+36+2*slot,std::uint16_t(10*(i+1)));}
            for(unsigned destination=0;destination<4;++destination)bytes[table+4*(destination*4+i)]=std::uint8_t(destination);
        }
    }
    return bytes;
}
void cross_room_contracts(){
    auto bytes=cross_asset();reo::native::gameplay_session::RoomVariants variants;variants.restore({});n::Bank bank(variants);n::RoomFlags flags;flags.fill(0);
    const auto bind=[&]{check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));};bind();
    for(unsigned entry=0;entry<8;++entry)for(unsigned destination=0;destination<8;++destination)for(unsigned pattern=0;pattern<4;++pattern){
        std::vector<std::uint8_t> visits(8);for(unsigned i=0;i<8;++i)visits[i]=std::uint8_t(pattern==1?1:pattern==2?i%2:pattern==3?i==entry:0);
        compare_cross_search(bank,bytes,{},0,flags,std::int32_t(entry),std::int32_t(destination),visits,{true,4096,128});
    }
    // A later failed recursive branch overwrites an earlier success.
    std::vector<std::uint8_t> visits(8);const auto overwritten=compare_cross_search(bank,bytes,{},0,flags,1,7,visits,{true,4096,128});check(overwritten.status==n::QueryStatus::completed&&overwritten.selected==-1&&overwritten.depth>=3);
    // Restrict adjacency so only the successful branch remains.
    bytes[16+12*8+4+7*8]=2;bind();visits.assign(8,0);const auto succeeded=compare_cross_search(bank,bytes,{},0,flags,1,7,visits,{true,4096,128});check(succeeded.status==n::QueryStatus::completed&&succeeded.selected!=-1);
    visits.assign(8,0);const auto unknown=compare_cross_search(bank,bytes,{},0,flags,1,7,visits,{});check(unknown.failure==n::CrossRoomFailure::collection&&unknown.collection_failure==n::CollectionFailure::unknown_cost);
    visits.assign(8,0);check(compare_cross_search(bank,bytes,{},0,flags,1,7,visits,{true,0,128}).failure==n::CrossRoomFailure::work_budget);
    visits.assign(8,0);check(compare_cross_search(bank,bytes,{},0,flags,1,7,visits,{true,4096,1}).failure==n::CrossRoomFailure::depth_budget);
    visits.assign(8,1);check(compare_cross_search(bank,bytes,{},0,flags,1,7,visits,{}).status==n::QueryStatus::completed);
    for(unsigned source_room=7;source_room<=10;++source_room)for(unsigned destination_room=7;destination_room<=10;++destination_room)
        for(unsigned source=0;source<4;++source)for(unsigned destination=0;destination<4;++destination)for(unsigned status:{0u,8u,0x80u}){
            check(bank.clear_actor_visits(0));n::CrossRoomOutput output{{-22,-23,{1,2,3},{4,5,6}},314};
            compare_cross_route(bank,bytes,{},status,flags,source_room,destination_room,std::int32_t(source),std::int32_t(destination),output,{true,4096,128});
        }
    check(bank.clear_actor_visits(0));n::CrossRoomOutput output{{-22,-23,{1,2,3},{4,5,6}},314};
    const auto marked=compare_cross_route(bank,bytes,{},0,flags,7,8,1,0,output,{true,4096,128});check(marked.selected==1&&output.link==0&&bank.visits(0)[0]==1);
    check(bank.clear_actor_visits(0));const auto pending=compare_cross_route(bank,bytes,{},0,flags,7,8,1,0,output,{});check(pending.collection_failure==n::CollectionFailure::unknown_cost);
    const auto unchanged=output;const auto work=compare_cross_route(bank,bytes,{},0,flags,7,8,1,0,output,{true,1,128});check(work.failure==n::CrossRoomFailure::work_budget&&output.link==unchanged.link);
    visits.assign(8,0);check(n::search_link_path(bank,{},0,flags,-1,7,visits).status==n::QueryStatus::unavailable);
}
