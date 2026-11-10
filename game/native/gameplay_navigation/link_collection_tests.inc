std::uint64_t collection_cases{},collection_entries{},collection_refusals{},collection_unknown_costs{},collection_retail_refusals{},collection_retail_unknown_costs{};
n::CollectionResult compare_collection(const n::Bank& bank,[[maybe_unused]] std::span<const std::uint8_t> bytes,n::ActorFacts facts,unsigned status,unsigned room,std::int32_t variant,std::int32_t node,std::uint16_t flags,std::span<const std::uint8_t> visits,n::CollectionProfile profile){
    const auto result=n::collect_links(bank,room,variant,node,facts,status,flags,visits,profile);
    if(result.status!=n::QueryStatus::completed){++collection_refusals;if(result.failure==n::CollectionFailure::unknown_cost)++collection_unknown_costs;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    std::copy(bytes.begin(),bytes.end(),memory.begin()+0x843780);const auto section=word(bytes,4);
    put(memory,0x83e540,word(bytes,section));put(memory,0x83e544,std::uint32_t(0x843780+section+4));
    memory[0x4b9d20+room]=bank.current_variant(room).value_or(0);
    const auto graph=bank.room(room);check(bool(graph));source_graph(*graph,room);
    const auto edge_flags=bank.edge_flags(room);check(bool(edge_flags));std::copy(edge_flags->begin(),edge_flags->end(),memory.begin()+0x1000000+word(graph->encoding(),0));
    for(unsigned i=0;i<128;++i)memory[0x83e550+164*room+0x14+i]=*bank.occupancy(room,i);
    constexpr unsigned actor=0xf00000,out=0x1d00000,stack=0x1f00000,mask=0x1c00000;
    std::copy(visits.begin(),visits.end(),memory.begin()+mask);std::fill_n(memory.begin()+out,640,0xcc);
    memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;put(memory,actor+0xba0,status);put(memory,0x4b9e20+12*room,flags);
    put(memory,stack,profile.omit_metadata?0u:out+384);put(memory,stack+8,mask);put(memory,stack+16,unsigned(profile.reverse));put(memory,stack+24,unsigned(profile.omit_metadata));
    put(memory,stack-8,profile.initial_cost.value_or(std::bit_cast<float>(0x7fc05678u)));
    R5900Context context;PS2Runtime runtime;context.pc=0x8179f0;
    const std::array<unsigned,8> args{actor,room,std::uint32_t(variant),std::uint32_t(node),out,profile.omit_metadata?0u:out+64,profile.omit_metadata?0u:out+96,profile.omit_metadata?0u:out+128};
    for(unsigned i=0;i<args.size();++i){SET_GPR_U32(&context,4+i,args[i]);}
    SET_GPR_U32(&context,29,stack);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==stack&&result.count==GPR_U32(&context,2));
    for(unsigned i=0;i<result.count;++i){
        const auto& candidate=result.candidates[i];const auto index=std::uint16_t(std::uint16_t(memory[out+2*i])|std::uint16_t(memory[out+2*i+1])<<8);
        check(candidate.link==index&&std::bit_cast<unsigned>(candidate.cost)==word(memory,stack-0x70+4*i));
        if(profile.omit_metadata)check(!candidate.projection);
        else{check(bool(candidate.projection));const auto& projection=*candidate.projection;
            check(projection.first==std::bit_cast<std::int8_t>(memory[out+64+i])&&projection.second==std::bit_cast<std::int8_t>(memory[out+96+i]));
            check(std::memcmp(&projection.first_position,memory.data()+out+128+12*i,12)==0&&std::memcmp(&projection.second_position,memory.data()+out+384+12*i,12)==0);
        }
        ++collection_entries;
    }
    if(result.last_cost)check(std::bit_cast<unsigned>(*result.last_cost)==word(memory,stack-8));
    if(profile.omit_metadata)check(std::all_of(memory.begin()+out+64,memory.begin()+out+640,[](auto value){return value==0xcc;}));
    ++collection_cases;
#endif
    return result;
}
void collection_contracts(){
    auto bytes=synthetic();bytes.insert(bytes.begin()+16,36,0);put(bytes,8,std::uint32_t(52));put(bytes,12,std::uint32_t(2));put(bytes,60,std::uint32_t(68));
    const auto node=synthetic_nodes+36,tail=synthetic_tail+36,table=node+64*4;
    bytes[16]=7;bytes[18]=3;bytes[28]=7;bytes[30]=0;bytes[31]=1;
    bytes[tail+8]=bytes[tail+24]=1;bytes[tail+9]=bytes[tail+25]=3;
    std::fill_n(bytes.begin()+table,64,255);for(unsigned i=0;i<4;++i){std::fill_n(bytes.begin()+node+64*i+20,4,255);put(bytes,node+64*i+36,std::uint16_t(10+10*i));}
    bytes[node+20]=3;bytes[table+4*(3*4)]=0;bytes[node+3*64+20]=0;bytes[table+4*(0*4+3)]=0;
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    const auto bind=[&]{check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));};bind();
    const auto run=[&](std::int32_t from,n::CollectionProfile profile){return compare_collection(bank,bytes,{},0,7,0,from,0,bank.visits(0),profile);};
    for(bool reverse:{false,true})for(bool omit:{false,true})for(const auto seed:{std::optional<float>{},std::optional<float>{0.f},std::optional<float>{1234.f}}){
        const auto result=run(0,{reverse,omit,seed,16});check(result.status==n::QueryStatus::completed&&result.count==2&&result.last_cost==std::optional<float>(reverse?40.f:10.f));
        check(result.candidates[0].cost==(reverse?40.f:10.f)&&result.candidates[1].cost==(reverse?40.f:10.f));
    }
    // When the first admitted route is same-node, its cost has no writer.
    std::swap(bytes[18],bytes[30]);bind();const auto unknown=run(0,{});
    check(unknown.status==n::QueryStatus::unavailable&&unknown.failure==n::CollectionFailure::unknown_cost&&unknown.count==0&&unknown.unavailable_link==0);
    for(float seed:{0.f,1234.f}){const auto result=run(0,{false,false,seed,16});check(result.status==n::QueryStatus::completed&&result.count==2);}
    check(bank.visit(0,0,7));const auto skipped=run(0,{});check(skipped.status==n::QueryStatus::completed&&skipped.count==1&&skipped.candidates[0].link==1);
    // Three candidates expose the sort's indirect tie reordering.
    bytes=synthetic();bytes.insert(bytes.begin()+16,60,0);put(bytes,8,std::uint32_t(76));put(bytes,12,std::uint32_t(3));put(bytes,84,std::uint32_t(92));
    const auto n3=synthetic_nodes+60,t3=synthetic_tail+60,r3=n3+64*4;bytes[t3+8]=1;bytes[t3+9]=3;
    for(unsigned i=0;i<3;++i){bytes[16+12*i]=7;bytes[18+12*i]=std::uint8_t(i==0?2:i==1?3:1);}
    std::fill_n(bytes.begin()+r3,64,255);for(unsigned i=0;i<4;++i){std::fill_n(bytes.begin()+n3+64*i+20,4,255);put(bytes,n3+64*i+36,std::uint16_t(i?20:10));}
    bytes[n3+20]=1;bytes[n3+21]=2;bytes[n3+22]=3;bytes[n3+2*64+20]=3;bytes[n3+3*64+20]=2;
    bytes[r3+4*(1*4+0)]=0;bytes[r3+4*(2*4+0)]=2;bytes[r3+4*(2*4+3)]=0;bytes[r3+4*(3*4+0)]=1;bytes[r3+4*(3*4+2)]=0;
    bind();for(bool omit:{false,true}){const auto result=run(0,{false,omit,{},16});check(result.status==n::QueryStatus::completed&&result.count==3&&result.candidates[0].link==2&&result.candidates[1].link==1&&result.candidates[2].link==0);}
    const auto limited=run(0,{false,false,{},2});check(limited.status==n::QueryStatus::unavailable&&limited.failure==n::CollectionFailure::capacity&&limited.count==2&&limited.unavailable_link==2);
    check(n::collect_links(bank,7,0,0,{},0,0,{},{}).status==n::QueryStatus::unavailable);
    check(n::collect_links(bank,7,0,0,{},0,0,bank.visits(0),{false,false,0.f,17}).status==n::QueryStatus::unavailable);
}
