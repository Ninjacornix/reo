std::vector<std::uint8_t> graph_fixture(unsigned count){
    const unsigned room=32,nodes=44,tail=nodes+64*count+4*count*count,directory=tail+40;
    std::vector<std::uint8_t> bytes(directory+64);put(bytes,0,0x20030724u);put(bytes,4,12u);put(bytes,8,16u);put(bytes,16,1u);
    put(bytes,20,std::uint16_t(7));put(bytes,24,room);put(bytes,room,tail-room);put(bytes,room+4,directory-room);put(bytes,room+8,count);put(bytes,tail+4,2u);
    for(unsigned i=0;i<count;++i){const auto node=nodes+64*i;bytes[node]=1;put(bytes,node+4,float(i));put(bytes,node+16,std::int32_t(-1));std::fill_n(bytes.begin()+node+20,4,255);}
    return bytes;
}
void graph_cost_contracts(){
    auto bytes=synthetic();reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    const auto bind=[&]{check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));};
    // Every directed four-node graph without self edges (4096 topologies),
    // three independent weight profiles and all ordered source/target pairs.
    for(unsigned topology=0;topology<4096;++topology)for(unsigned profile=0;profile<3;++profile){
        unsigned bit=0;
        for(unsigned node=0;node<4;++node){
            const auto at=synthetic_nodes+64*node;std::fill_n(bytes.begin()+at+20,4,255);unsigned slot=0;
            for(unsigned target=0;target<4;++target)if(target!=node){
                const bool present=(topology&(1u<<bit))!=0;++bit;
                if(present){bytes[at+20+slot]=std::uint8_t(target);put(bytes,at+36+2*slot,std::uint16_t(profile==0?0:profile==1?1+node*7+target:((node+target)%3==0?65535:2)));++slot;}
            }
        }
        bind();
        for(std::int32_t source=0;source<4;++source)for(std::int32_t target=0;target<4;++target){
            n::RouteOutput output{-22,-23,{1,2,3},{4,5,6},1234};
            check(compare_cost(bank,{},0,source,target,0,output,65536,7,true).status==n::QueryStatus::completed);
        }
    }
    // Seeded graphs add self edges, duplicate neighbors, arbitrary slot order,
    // all unsigned-halfword costs, status gates and cyclic zero-cost ties.
    std::uint32_t random=0x6b1d3e95;const auto next=[&]{random^=random<<13;random^=random>>17;random^=random<<5;return random;};
    for(unsigned sample=0;sample<8192;++sample){
        for(unsigned node=0;node<4;++node)for(unsigned slot=0;slot<4;++slot){
            const auto at=synthetic_nodes+64*node;const auto target=next()%5;bytes[at+20+slot]=std::uint8_t(target==4?255:target);
            const auto value=next();put(bytes,at+36+2*slot,std::uint16_t(sample%3==0?0:sample%3==1?value%32:value));put(bytes,at+24+2*slot,std::uint16_t(next()%16));
        }
        bind();
        for(std::int32_t source=0;source<4;++source)for(std::int32_t target=0;target<4;++target)for(unsigned status:{0u,0x88u}){
            n::RouteOutput output{-22,-23,{1,2,3},{4,5,6},1234};
            check(compare_cost(bank,{},status,source,target,0,output,65536,7,true).status==n::QueryStatus::completed);
        }
    }
    bytes=graph_fixture(6);
    for(unsigned sample=0;sample<4096;++sample){
        for(unsigned node=0;node<6;++node)for(unsigned slot=0;slot<4;++slot){
            const auto at=44+64*node;const auto target=next()%7;bytes[at+20+slot]=std::uint8_t(target==6?255:target);
            const auto value=next();put(bytes,at+36+2*slot,std::uint16_t(sample%3==0?0:sample%3==1?value%32:value));put(bytes,at+24+2*slot,std::uint16_t(next()%16));
        }
        bind();
        for(std::int32_t source=0;source<6;++source)for(std::int32_t target=0;target<6;++target)for(unsigned status:{0u,0x88u}){
            n::RouteOutput output{-22,-23,{1,2,3},{4,5,6},1234};check(compare_cost(bank,{},status,source,target,0,output,65536,7,true).status==n::QueryStatus::completed);
        }
    }
    // A zero cycle must not win the secondary hop by reentering the current
    // recursive owner. Its only exit can be the owner's later sibling.
    bytes=graph_fixture(5);bytes[44+20]=1;bytes[44+64+20]=2;bytes[44+64+21]=3;
    bytes[44+128+20]=1;bytes[44+192+20]=4;put(bytes,44+192+36,std::uint16_t(10));bind();
    n::RouteOutput tied;const auto zero_cycle=compare_cost(bank,{},0,0,4,0,tied,65536,7,true);check(zero_cycle.selected==1&&tied.cost==10&&tied.second==3);
    // Root self-edge calls the recursive helper despite the initial root mark.
    bytes=graph_fixture(4);bytes[44+20]=0;bytes[44+21]=3;put(bytes,44+36,std::uint16_t(2));put(bytes,44+38,std::uint16_t(10));bind();
    n::RouteOutput self;const auto root_self=compare_cost(bank,{},0,0,3,0,self,65536,7,true);check(root_self.selected==3&&self.cost==12&&self.second==3);
    // Candidate admission validates the entire graph, including unused slots;
    // this is deliberately more conservative than the existing depth-first API.
    bytes[synthetic_nodes+20]=127;bind();n::RouteOutput output{-22,-23,{1,2,3},{4,5,6},1234};
    const auto invalid=compare_cost(bank,{},0,0,3,0,output,65536,7,true);
    check(invalid.status==n::QueryStatus::unavailable&&output.first==-22&&output.cost==1234);
#ifdef REO_NAVIGATION_ORIGINAL
    // The generated recursive helper jumps back to its internal entry label.
    // Both entries must be observed, not only the initial runtime dispatch.
    bytes=graph_fixture(4);bytes[44+20]=1;bytes[44+64+20]=2;bytes[44+128+20]=3;bind();
    n::RouteOutput guarded;const auto before_entries=graph_original_total_entries;
    check(compare_cost(bank,{},0,0,3,0,guarded,65536,7,true,true).status==n::QueryStatus::completed);
    check(reference_cost_recursions==2&&graph_original_total_entries==before_entries+2);++graph_guard_self_tests;
#endif
}
