std::uint64_t local_cases{},local_refusals{},local_budgets{},local_retail_refusals{},local_retail_budgets{};
n::CostRouteResult compare_local(const n::Bank& bank,[[maybe_unused]] std::span<const std::uint8_t> bytes,n::ActorFacts facts,unsigned status,std::int32_t source,std::int32_t destination,std::uint16_t flags,unsigned policy,n::RouteOutput& output,std::int16_t& link,std::size_t maximum=65536,unsigned room=7){
    [[maybe_unused]] const auto before=output;[[maybe_unused]] const auto before_link=link;
    const auto result=n::local_route(bank,room,source,destination,facts,status,flags,policy,output,link,maximum);
    if(result.used_graph_solver){++local_api_graph_cases;api_graph_work_maximum=std::max(api_graph_work_maximum,std::uint64_t(result.considered_edges));api_graph_vertex_maximum=std::max(api_graph_vertex_maximum,std::uint64_t(result.graph_vertex_scans));}
    check(result.considered_edges<=maximum);
    if(result.status!=n::QueryStatus::completed){++local_refusals;if(result.budget_exhausted)++local_budgets;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    std::copy(bytes.begin(),bytes.end(),memory.begin()+0x843780);const auto section=word(bytes,4);
    put(memory,0x83e540,word(bytes,section));put(memory,0x83e544,std::uint32_t(0x843780+section+4));
    const auto variant=bank.current_variant(room);check(bool(variant));memory[0x4b9d20+room]=*variant;
    const auto graph=bank.room(room);check(bool(graph));
    const bool bounded_original=result.used_graph_solver&&graph->nodes().size()>6&&original_cost_needs_guard(bank,facts,status,room,source,destination,flags,before,maximum);
    source_graph(*graph,room);
    const auto edge_flags=bank.edge_flags(room);check(bool(edge_flags));std::copy(edge_flags->begin(),edge_flags->end(),memory.begin()+0x1000000+word(graph->encoding(),0));
    for(unsigned i=0;i<128;++i)memory[0x83e550+164*room+0x14+i]=*bank.occupancy(room,i);
    constexpr unsigned actor=0xf00000,out=0x1d00000,stack=0x1f00000;
    memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;put(memory,actor+0xba0,status);put(memory,0x4b9e20+12*room,flags);
    put(memory,out,before.first);put(memory,out+1,before.second);
    put(memory,out+4,before.first_position.x);put(memory,out+8,before.first_position.y);put(memory,out+12,before.first_position.z);
    put(memory,out+16,before.second_position.x);put(memory,out+20,before.second_position.y);put(memory,out+24,before.second_position.z);put(memory,out+28,before.cost);put(memory,out+32,before_link);
    put(memory,stack,out+28);put(memory,stack+8,out+32);put(memory,stack+16,policy);
    R5900Context context;PS2Runtime runtime;context.pc=0x817db0;
    const std::array<unsigned,8> args{actor,room,std::uint32_t(source),std::uint32_t(destination),out,out+1,out+4,out+16};for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);
    SET_GPR_U32(&context,29,stack);SET_GPR_U32(&context,31,0x100);reference_cost_address=out+28;reference_cost_written=false;
    reference_cost_recursions=0;reference_cost_recursion_limit=bounded_original?16384:0;
    try{original_transform_port(memory.data(),&context,&runtime);}
    catch(const OriginalCostLimit& limit){record_original_cost_limit(bank,facts,status,room,source,destination,flags,1,limit);return result;}
    reference_cost_recursion_limit=0;if(bounded_original){++graph_original_extended;++original_extended_by_kind[1];}
    check(result.cost_written==reference_cost_written);reference_cost_address=0;
    check(context.pc==0x100&&GPR_U32(&context,29)==stack&&std::int32_t(result.selected)==std::bit_cast<std::int32_t>(GPR_U32(&context,2)));
    check(output.first==std::bit_cast<std::int8_t>(memory[out])&&output.second==std::bit_cast<std::int8_t>(memory[out+1]));
    check(std::memcmp(&output.first_position,memory.data()+out+4,12)==0&&std::memcmp(&output.second_position,memory.data()+out+16,12)==0);
    check(std::bit_cast<unsigned>(output.cost)==word(memory,out+28)&&link==std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(memory[out+32])|std::uint16_t(memory[out+33])<<8)));++local_cases;
#endif
    return result;
}
void local_contracts(){
    auto bytes=synthetic();bytes.insert(bytes.begin()+16,36,0);put(bytes,8,std::uint32_t(52));put(bytes,12,std::uint32_t(2));put(bytes,60,std::uint32_t(68));
    bytes[16]=7;bytes[18]=3;bytes[28]=7;bytes[30]=3;bytes[31]=1;
    const auto node=synthetic_nodes+36,tail=synthetic_tail+36,table=node+64*4;
    std::fill_n(bytes.begin()+table,64,255);for(unsigned i=0;i<4;++i)std::fill_n(bytes.begin()+node+64*i+20,4,255);
    bytes[node+20]=3;bytes[table+4*(3*4)]=0;
    bytes[tail+8]=0;bytes[tail+9]=1;bytes[tail+24]=1;bytes[tail+25]=3;
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    const auto bind=[&]{check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));};
    const auto run=[&](unsigned policy,unsigned flags=0,std::int32_t source=0,std::size_t budget=65536){n::RouteOutput out{-22,-23,{1,2,3},{4,5,6},1234};std::int16_t link=314;const auto result=compare_local(bank,bytes,{},0,source,3,std::uint16_t(flags),policy,out,link,budget);return std::tuple{result,out,link};};
    bind();for(unsigned policy:{0u,1u,2u,3u,0xffffffffu}){const auto [result,out,link]=run(policy);check(result.status==n::QueryStatus::completed&&result.selected==3&&out.first==3&&out.second==3&&out.cost==(policy<2?0.f:10000.f)&&link==1);}
    // Same-node bypasses every inner policy and preserves cost, even policy2
    // with zero work budget. Post-routing link admission still runs.
    for(unsigned policy:{0u,1u,2u,0xffffffffu}){const auto [result,out,link]=run(policy,0,3,0);check(result.status==n::QueryStatus::completed&&result.selected==3&&out.cost==1234&&link==1);}
    put(bytes,node+3*64+16,std::int32_t(0));bind();
    for(unsigned policy:{0u,1u,2u}){const auto [result,out,link]=run(policy);check(result.status==n::QueryStatus::completed&&result.selected==-1&&out.first==-22&&out.second==-23&&out.cost==1234&&link==314);}
    // The current session variant may change while the old graph stays bound.
    // Both pre-routing existence and post-routing admission use the new byte.
    check(variants.store(7,1));const auto [changed,changed_out,changed_link]=run(0);check(changed.status==n::QueryStatus::completed&&changed.selected==3&&changed_out.first==3&&changed_link==-1);
    check(variants.store(7,0));put(bytes,node+3*64+16,std::int32_t(-1));bytes[31]=127;bind();
    const auto [post,post_out,post_link]=run(0);check(post.status==n::QueryStatus::unavailable&&post_out.first==3&&post_out.cost==0&&post_link==-1);
    bytes[31]=1;bind();const auto [limited,limited_out,limited_link]=run(2,0,0,0);check(limited.status==n::QueryStatus::unavailable&&limited.budget_exhausted&&limited_out.first==-22&&limited_out.cost==1234&&limited_link==314);
    // Inner failure writes source nodes and clears the link, unlike pre-denial.
    bytes[node+20]=255;bind();for(unsigned policy:{0u,1u,2u}){const auto [failed,failed_out,failed_link]=run(policy);check(failed.status==n::QueryStatus::completed&&failed.selected==-1&&failed_out.first==0&&failed_out.second==0&&failed_link==-1);}
}
