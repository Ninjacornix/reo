std::uint64_t ranked_cases{},ranked_refusals{},ranked_retail_refusals{};
n::RouteResult compare_ranked(const n::Bank& bank,n::ActorFacts facts,unsigned status,std::int32_t source,std::int32_t destination,std::uint16_t flags,n::RankedPolicy policy,n::RouteOutput& output,unsigned room=7){
    [[maybe_unused]] const auto before=output;
    const auto result=n::ranked_route(bank,room,source,destination,facts,status,flags,policy,output);
    if(result.status!=n::QueryStatus::completed){++ranked_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    const auto graph=bank.room(room);check(bool(graph));source_graph(*graph,room);
    const auto edge_flags=bank.edge_flags(room);check(bool(edge_flags));std::copy(edge_flags->begin(),edge_flags->end(),memory.begin()+0x1000000+word(graph->encoding(),0));
    for(unsigned i=0;i<128;++i)memory[0x83e550+164*room+0x14+i]=*bank.occupancy(room,i);
    constexpr unsigned actor=0xf00000,out=0x1d00000,stack=0x1f00000;
    memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;put(memory,actor+0xba0,status);put(memory,0x4b9e20+12*room,flags);
    put(memory,out,before.first);put(memory,out+1,before.second);
    put(memory,out+4,before.first_position.x);put(memory,out+8,before.first_position.y);put(memory,out+12,before.first_position.z);
    put(memory,out+16,before.second_position.x);put(memory,out+20,before.second_position.y);put(memory,out+24,before.second_position.z);put(memory,out+28,before.cost);put(memory,stack,out+28);
    R5900Context context;PS2Runtime runtime;context.pc=policy==n::RankedPolicy::four_candidates?0x818010:0x8185c0;
    const std::array<unsigned,8> args{actor,room,std::uint32_t(source),std::uint32_t(destination),out,out+1,out+4,out+16};
    for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);
    SET_GPR_U32(&context,29,stack);SET_GPR_U32(&context,31,0x100);reference_cost_address=out+28;reference_cost_written=false;original_transform_port(memory.data(),&context,&runtime);
    check(result.cost_written==reference_cost_written);reference_cost_address=0;
    check(context.pc==0x100&&GPR_U32(&context,29)==stack);
    check(std::int32_t(result.selected)==std::bit_cast<std::int32_t>(GPR_U32(&context,2)));
    check(output.first==std::bit_cast<std::int8_t>(memory[out])&&output.second==std::bit_cast<std::int8_t>(memory[out+1]));
    check(std::memcmp(&output.first_position,memory.data()+out+4,12)==0&&std::memcmp(&output.second_position,memory.data()+out+16,12)==0);
    check(std::bit_cast<unsigned>(output.cost)==word(memory,out+28));++ranked_cases;
#endif
    return result;
}
void ranked_contracts(){
    auto bytes=synthetic();const auto table=synthetic_nodes+4*64;
    std::fill_n(bytes.begin()+table,4*4*4,255);
    for(unsigned i=0;i<4;++i){std::fill_n(bytes.begin()+synthetic_nodes+64*i+20,4,255);for(unsigned slot=0;slot<4;++slot)put(bytes,synthetic_nodes+64*i+36+2*slot,std::uint16_t(10+10*slot+i));}
    const auto route=[&](unsigned from,unsigned to,std::array<std::uint8_t,4> choices){std::copy(choices.begin(),choices.end(),bytes.begin()+table+4*(to*4+from));};
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    const auto bind=[&]{check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));};
    const auto run=[&](n::RankedPolicy policy,unsigned status=0,n::ActorFacts facts=n::ActorFacts{}){
        n::RouteOutput output{-22,-23,{1,2,3},{4,5,6},1234};const auto result=compare_ranked(bank,facts,status,0,3,0,policy,output);return std::pair{result,output};
    };
    bytes[synthetic_nodes+20]=1;bytes[synthetic_nodes+21]=2;bytes[synthetic_nodes+64+20]=3;
    route(0,3,{1,0,255,255});route(1,3,{0,255,255,255});put(bytes,synthetic_nodes+64+36,std::uint16_t(5));bind();
    auto [four,out_four]=run(n::RankedPolicy::four_candidates);check(four.status==n::QueryStatus::completed&&four.selected==1&&out_four.first==1&&out_four.second==3&&out_four.cost==25);
    auto [first,out_first]=run(n::RankedPolicy::first_candidate);check(first.status==n::QueryStatus::completed&&first.selected==-1&&out_first.first==0&&out_first.second==0&&out_first.cost==10);
    // Reordered selected slots retain rank-indexed cost. This is not a generic
    // shortest path or a lookup of the selected neighbor's cost slot.
    for(unsigned rank=0;rank<4;++rank)for(unsigned slot=0;slot<4;++slot){
        std::fill_n(bytes.begin()+synthetic_nodes+20,4,255);bytes[synthetic_nodes+20+slot]=3;
        std::array<std::uint8_t,4> choices;choices.fill(255);choices[rank]=std::uint8_t(slot);route(0,3,choices);bind();
        const auto [result,output]=run(n::RankedPolicy::four_candidates);check(result.selected==3&&output.cost==10+10*rank&&output.first==3&&output.second==3);
        (void)run(n::RankedPolicy::first_candidate);
    }
    std::fill_n(bytes.begin()+synthetic_nodes+20,4,255);bytes[synthetic_nodes+20]=1;bytes[synthetic_nodes+64+20]=2;bytes[synthetic_nodes+128+20]=3;
    route(0,3,{0,255,255,255});route(1,3,{0,255,255,255});route(2,3,{0,255,255,255});put(bytes,synthetic_nodes+128+36,std::uint16_t(7));bind();
    const auto [chain,chain_out]=run(n::RankedPolicy::four_candidates);check(chain.selected==1&&chain_out.second==2&&chain_out.cost==22);
    bytes[synthetic_nodes+128+20]=0;bind();const auto [cycle,cycle_out]=run(n::RankedPolicy::four_candidates);check(cycle.selected==-1&&cycle_out.cost==15&&cycle_out.first==0&&cycle_out.second==0);
    // Failure before an eligible candidate leaves cost untouched. Same-node
    // selection also leaves its arbitrary existing float bits untouched.
    route(0,3,{255,255,255,255});bind();const auto [absent,absent_out]=run(n::RankedPolicy::four_candidates);check(absent.selected==-1&&absent_out.cost==1234);
    n::RouteOutput same; same.cost=std::bit_cast<float>(0x7fc01234u);check(compare_ranked(bank,{},0,2,2,0,n::RankedPolicy::four_candidates,same).selected==2&&std::bit_cast<unsigned>(same.cost)==0x7fc01234u);
    // Occupancy uses the original five-bit actor-slot shift. Other actor bits
    // do not block this route and are not silently treated as global blockage.
    bytes[synthetic_nodes+128+20]=3;route(0,3,{0,255,255,255});bind();
    for(unsigned actor_slot=0;actor_slot<256;++actor_slot)for(unsigned occupancy:{0u,1u,2u,128u,255u}){
        check(bank.occupancy(7,1,std::uint8_t(occupancy)));const auto [result,output]=run(n::RankedPolicy::four_candidates,0,{7,std::uint8_t(actor_slot),255});
        const bool blocked=(occupancy&(1u<<(actor_slot&31)))!=0;check((result.selected==-1)==blocked);(void)output;
    }
    route(0,3,{4,255,255,255});bind();const auto [invalid,invalid_out]=run(n::RankedPolicy::four_candidates);check(invalid.status==n::QueryStatus::unavailable&&invalid_out.cost==1234&&invalid_out.first==-22);
    n::RouteOutput untouched;untouched.cost=777;check(n::ranked_route(bank,7,-1,3,{},0,0,n::RankedPolicy::four_candidates,untouched).status==n::QueryStatus::unavailable&&untouched.cost==777);
    check(n::ranked_route(bank,7,0,3,{},0,0,n::RankedPolicy(99),untouched).status==n::QueryStatus::unavailable&&untouched.cost==777);
}
