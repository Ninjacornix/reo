std::uint64_t cost_cases{},cost_refusals{},cost_budgets{},cost_retail_refusals{},cost_retail_budgets{},cost_maximum_work{};
std::uint64_t graph_cost_cases{},graph_cost_refusals{},graph_admission_maximum{},graph_relaxation_maximum{},graph_scan_maximum{};
std::uint64_t graph_retail_admitted{},graph_retail_equivalent{},graph_retail_new{},graph_retail_refused{};
std::uint64_t graph_original_extended{},graph_original_limited{},graph_original_total_entries{},graph_original_per_query_limited{},graph_original_global_limited{},graph_guard_self_tests{};
std::vector<std::array<std::uint32_t,9>> graph_original_limit_rows;
n::CostRouteResult compare_cost(const n::Bank& bank,n::ActorFacts facts,unsigned status,std::int32_t source,std::int32_t destination,std::uint16_t flags,n::RouteOutput& output,std::size_t maximum=65536,unsigned room=7,bool graph_solver=false,[[maybe_unused]] bool bounded_original=false){
    [[maybe_unused]] const auto before=output;
    n::CostRouteResult result;
    if(graph_solver){
        const auto candidate=n::graph_cost_route(bank,room,source,destination,facts,status,flags,output);
        result={candidate.status,candidate.selected,false,candidate.admission_checks+candidate.relaxations,candidate.cost_written};
        graph_admission_maximum=std::max(graph_admission_maximum,std::uint64_t(candidate.admission_checks));graph_relaxation_maximum=std::max(graph_relaxation_maximum,std::uint64_t(candidate.relaxations));graph_scan_maximum=std::max(graph_scan_maximum,std::uint64_t(candidate.vertex_scans));
    }else{result=n::bounded_cost_route(bank,room,source,destination,facts,status,flags,output,maximum);cost_maximum_work=std::max(cost_maximum_work,std::uint64_t(result.considered_edges));}
    if(result.status!=n::QueryStatus::completed){if(graph_solver)++graph_cost_refusals;else{++cost_refusals;if(result.budget_exhausted)++cost_budgets;}return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    const auto graph=bank.room(room);check(bool(graph));source_graph(*graph,room);
    const auto edge_flags=bank.edge_flags(room);check(bool(edge_flags));std::copy(edge_flags->begin(),edge_flags->end(),memory.begin()+0x1000000+word(graph->encoding(),0));
    for(unsigned i=0;i<128;++i)memory[0x83e550+164*room+0x14+i]=*bank.occupancy(room,i);
    constexpr unsigned actor=0xf00000,out=0x1d00000,stack=0x1f00000;
    memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;put(memory,actor+0xba0,status);put(memory,0x4b9e20+12*room,flags);
    put(memory,out,before.first);put(memory,out+1,before.second);
    put(memory,out+4,before.first_position.x);put(memory,out+8,before.first_position.y);put(memory,out+12,before.first_position.z);
    put(memory,out+16,before.second_position.x);put(memory,out+20,before.second_position.y);put(memory,out+24,before.second_position.z);put(memory,out+28,before.cost);put(memory,stack,out+28);
    R5900Context context;PS2Runtime runtime;context.pc=0x818b70;
    const std::array<unsigned,8> args{actor,room,std::uint32_t(source),std::uint32_t(destination),out,out+1,out+4,out+16};
    for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);
    SET_GPR_U32(&context,29,stack);SET_GPR_U32(&context,31,0x100);reference_cost_address=out+28;reference_cost_written=false;
    reference_cost_recursions=0;reference_cost_recursion_limit=bounded_original?16384:0;
    try{original_transform_port(memory.data(),&context,&runtime);}
    catch(const OriginalCostLimit& limit){
        reference_cost_recursion_limit=0;reference_cost_address=0;++graph_original_limited;const auto variant=bank.current_variant(room);
        if(limit.global)++graph_original_global_limited;else ++graph_original_per_query_limited;
        graph_original_limit_rows.push_back({room,variant?std::uint32_t(*variant):UINT32_MAX,std::uint32_t(source),std::uint32_t(destination),status,flags,facts.slot,std::uint32_t(reference_cost_recursions),limit.global?1u:0u});return result;
    }
    reference_cost_recursion_limit=0;if(bounded_original)++graph_original_extended;
    check(result.cost_written==reference_cost_written);reference_cost_address=0;
    check(context.pc==0x100&&GPR_U32(&context,29)==stack);
    check(std::int32_t(result.selected)==std::bit_cast<std::int32_t>(GPR_U32(&context,2)));
    check(output.first==std::bit_cast<std::int8_t>(memory[out])&&output.second==std::bit_cast<std::int8_t>(memory[out+1]));
    check(std::memcmp(&output.first_position,memory.data()+out+4,12)==0&&std::memcmp(&output.second_position,memory.data()+out+16,12)==0);
    check(std::bit_cast<unsigned>(output.cost)==word(memory,out+28));if(graph_solver)++graph_cost_cases;else ++cost_cases;
#endif
    return result;
}
void cost_contracts(){
    auto bytes=synthetic();for(unsigned node=0;node<4;++node){std::fill_n(bytes.begin()+synthetic_nodes+64*node+20,4,255);for(unsigned slot=0;slot<4;++slot)put(bytes,synthetic_nodes+64*node+36+2*slot,std::uint16_t(10+10*slot));}
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    const auto bind=[&]{check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));};
    const auto run=[&](std::size_t maximum=65536){n::RouteOutput out{-22,-23,{1,2,3},{4,5,6},1234};const auto result=compare_cost(bank,{},0,0,3,0,out,maximum);return std::pair{result,out};};
    bytes[synthetic_nodes+20]=3;bind();auto [direct,direct_out]=run();check(direct.status==n::QueryStatus::completed&&direct.selected==3&&direct_out.cost==10000&&direct_out.first==3&&direct_out.second==3&&direct.considered_edges==1);
    for(unsigned slot=0;slot<4;++slot){std::fill_n(bytes.begin()+synthetic_nodes+20,4,255);bytes[synthetic_nodes+20+slot]=1;bytes[synthetic_nodes+64+20]=3;put(bytes,synthetic_nodes+64+36,std::uint16_t(5));bind();const auto [result,out]=run();check(result.selected==1&&out.cost==15+10*slot&&out.second==3);}
    // Full unsigned-halfword cost domain and strict10000 admission sentinel.
    std::fill_n(bytes.begin()+synthetic_nodes+20,4,255);bytes[synthetic_nodes+20]=1;
    for(unsigned cost=0;cost<65536;++cost){put(bytes,synthetic_nodes+36,std::uint16_t(cost));bind();const auto [result,out]=run();check(result.status==n::QueryStatus::completed&&(result.selected==1)==(cost+5<10000)&&out.cost==(cost+5<10000?float(cost+5):1234.f));}
    // A later root direct edge retains the earlier cost/secondary. A direct
    // edge inside recursion replaces a cheaper prior recursive candidate.
    put(bytes,synthetic_nodes+36,std::uint16_t(10));bytes[synthetic_nodes+20]=1;bytes[synthetic_nodes+21]=3;
    bytes[synthetic_nodes+64+20]=2;bytes[synthetic_nodes+128+20]=3;put(bytes,synthetic_nodes+128+36,std::uint16_t(7));bind();
    const auto [late,late_out]=run();check(late.selected==3&&late_out.first==3&&late_out.second==2&&late_out.cost==22);
    bytes[synthetic_nodes+21]=255;bytes[synthetic_nodes+64+21]=3;put(bytes,synthetic_nodes+64+38,std::uint16_t(100));bind();
    const auto [recursive,recursive_out]=run();check(recursive.selected==1&&recursive_out.cost==110&&recursive_out.second==3);
    // Occupancy bytes are irrelevant to this policy, unlike ranked routes.
    for(unsigned i=0;i<128;++i){check(bank.occupancy(7,i,255));}const auto [occupied,occupied_out]=run();check(occupied.selected==1&&occupied_out.cost==110);
    bytes[synthetic_nodes+64+21]=255;bind();
    for(unsigned budget=0;budget<13;++budget){const auto [result,out]=run(budget);check((result.status==n::QueryStatus::completed)==(budget>=9));if(budget<9)check(result.budget_exhausted&&result.considered_edges==budget&&out.first==-22&&out.second==-23&&out.cost==1234);}
    n::RouteOutput same; same.cost=1234;const auto equal=compare_cost(bank,{},0xffffffff,2,2,0,same,0);check(equal.status==n::QueryStatus::completed&&equal.selected==2&&equal.considered_edges==0&&same.cost==10000);
    // Cyclic/dead ends complete without manufacturing a route or changing cost.
    bytes[synthetic_nodes+128+20]=0;bind();const auto [cycle,cycle_out]=run();check(cycle.status==n::QueryStatus::completed&&cycle.selected==-1&&cycle_out.first==0&&cycle_out.second==0&&cycle_out.cost==1234);
    bytes[synthetic_nodes+20]=127;bind();const auto [invalid,invalid_out]=run();check(invalid.status==n::QueryStatus::unavailable&&!invalid.budget_exhausted&&invalid_out.cost==1234);
}
