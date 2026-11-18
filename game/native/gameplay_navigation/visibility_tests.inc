namespace collision=reo::native::gameplay_collision;
std::uint64_t visibility_cases{},visible_nearest_cases{},visibility_refusals{},visibility_retail_cases{};
std::uint64_t node_policy_cases{},node_choice_cases{},node_choice_refusals{};
std::vector<std::uint8_t> visibility_grid(std::optional<std::uint32_t> flags){
    std::vector<std::uint8_t> bytes(flags?108:52);
    put(bytes,8,1000000u);put(bytes,12,1000000u);put(bytes,16,1u);put(bytes,20,1u);
    put(bytes,32,32u);put(bytes,36,44u);put(bytes,40,36u);put(bytes,44,flags?0u:0xffffffffu);
    if(flags){
        put(bytes,48,0xffffffffu);put(bytes,52,*flags);
        const collision::response::Triangle triangle{*flags,{{{10,0,0},{10,1000,0},{10,0,1000}}},{-1,0,0},10};
        static_assert(sizeof(triangle)==56);std::memcpy(bytes.data()+52,&triangle,56);
    }
    return bytes;
}
#ifdef REO_NAVIGATION_ORIGINAL
void visibility_reference_setup(std::span<const std::uint8_t> bytes,const collision::response::Filter& filter,std::span<const collision::response::Triangle> dynamic={}){
    constexpr unsigned input=0x1a00000,triangles=0x1b00000;
    std::copy(bytes.begin(),bytes.end(),memory.begin()+input);call(0x6161e0,{input});
    put(memory,0x743720,0xffffffffu);put(memory,0x3c2748,filter.disabled);
    check(dynamic.size()<=31);
    for(unsigned i=0;i<dynamic.size();++i){std::memcpy(memory.data()+triangles+56*i,&dynamic[i],56);put(memory,0x743720+4*i,triangles+56*i);}
    put(memory,0x743720+4*dynamic.size(),0xffffffffu);
    for(unsigned i=0;i<16;++i){memory[0x4a3621+96*i]=filter.slots[i].state;memory[0x4a3634+96*i]=filter.slots[i].kind;}
}
#endif
n::VisibilityResult compare_visibility(const n::VisibilityRoom& room,[[maybe_unused]] std::span<const std::uint8_t> bytes,n::Position from,n::Position to){
    const auto result=n::navigation_visibility(room,from,to);
    if(result.status!=n::QueryStatus::completed){++visibility_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    visibility_reference_setup(bytes,room.filter,room.dynamic);
    constexpr unsigned start=0x1e00000,end=start+16,out=start+32;
    std::memcpy(memory.data()+start,&from,12);std::memcpy(memory.data()+end,&to,12);put(memory,out,0xdeadbeefu);
    check(result.blocked==bool(call(0x81a340,{start,end,out})));
    if(result.hit_kind)check(*result.hit_kind==std::uint16_t(word(memory,out)));
    ++visibility_cases;
#endif
    return result;
}
n::NodeResult compare_visible_nearest(const n::RoomGraph& graph,const n::VisibilityRoom& room,[[maybe_unused]] std::span<const std::uint8_t> bytes,n::Position query,std::int8_t group){
    const auto result=n::nearest_visible_node(graph,query,group,room);
    if(result.status!=n::QueryStatus::completed){++visibility_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    visibility_reference_setup(bytes,room.filter,room.dynamic);source_graph(graph);
    constexpr unsigned position=0x1e00000;std::memcpy(memory.data()+position,&query,12);
    check(result.node==std::bit_cast<std::int32_t>(call(0x8171e0,{position,std::uint32_t(std::int32_t(group)),0,1})));
    if(group==0)check(result.node==std::bit_cast<std::int32_t>(call(0x8171c0,{position,0})));
    ++visible_nearest_cases;
#endif
    return result;
}
n::NodeResult compare_node_choice(const n::Bank& bank,const n::RouteActorFacts& actor,unsigned policy,const n::VisibilityRoom& room,
    [[maybe_unused]] std::span<const std::uint8_t> bytes,n::ActorRouteState& state){
    [[maybe_unused]] const auto before=state;const auto result=n::choose_actor_node(bank,actor,policy,room,state);
    if(result.status!=n::QueryStatus::completed){++node_choice_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    visibility_reference_setup(bytes,room.filter,room.dynamic);const auto graph=bank.room(actor.room);check(bool(graph));source_graph(*graph,actor.room);
    constexpr unsigned raw=0xf00000,position=0x1e00000;
    put(memory,raw+0x1e2,actor.room);put(memory,raw+0xba0,actor.status);put(memory,raw+0xba4,actor.auxiliary_status);
    memory[raw+0x54f]=actor.motion_class;memory[raw+0x105b]=before.selection_mode;memory[raw+0x100c]=std::bit_cast<std::uint8_t>(before.current_node);
    std::memcpy(memory.data()+position,&actor.position,12);
    check(result.node==std::bit_cast<std::int32_t>(call(0x815bc0,{raw,position,policy})));
    check(state.current_node==std::bit_cast<std::int8_t>(memory[raw+0x100c]));++node_choice_cases;
#endif
    return result;
}
void visibility_contracts(){
    for(unsigned type=0;type<16;++type)for(unsigned high:{0x10000u,0x20000u})for(bool disabled:{false,true}){
        const auto bytes=visibility_grid(high|type);const auto grid=collision::response::Grid::import(std::as_bytes(std::span(bytes)));
        collision::response::Filter filter;filter.include=0;filter.exclude=0xffffffff;filter.dynamic_kind_gate=true;filter.disabled=disabled?0x10000:0;
        const auto result=compare_visibility({grid,filter,{}},bytes,{1,0,1},{100,9999,1});check(result.status==n::QueryStatus::completed);
        if(high==0x20000||disabled)check(!result.blocked&&!result.hit_kind);
        else{const auto kind=std::uint16_t(1u<<type);check(result.hit_kind==kind);check(result.blocked==(type==0||type==1||type==10||type==13||type==14||type==15));}
    }
    const auto clear=visibility_grid({});const auto empty_grid=collision::response::Grid::import(std::as_bytes(std::span(clear)));
    const auto wall_bytes=visibility_grid(0x10000u);const auto wall=collision::response::Grid::import(std::as_bytes(std::span(wall_bytes)));
    const auto dynamic=wall.triangles();check(compare_visibility({empty_grid,{},dynamic},clear,{1,0,1},{100,-9999,1}).blocked);
    const auto allowed_bytes=visibility_grid(0x10002u);const auto allowed=collision::response::Grid::import(std::as_bytes(std::span(allowed_bytes)));
    const auto first_allowed=compare_visibility({allowed,{},dynamic},allowed_bytes,{1,0,1},{100,0,1});
    check(!first_allowed.blocked&&first_allowed.hit_kind==4); // Later blocking dynamic hit is never substituted.
    check(compare_visibility({wall,{},allowed.triangles()},wall_bytes,{1,0,1},{100,0,1}).blocked);
    const auto state_bytes=visibility_grid(0x10001u);const auto state_grid=collision::response::Grid::import(std::as_bytes(std::span(state_bytes)));
    collision::response::Filter slot_filter;slot_filter.dynamic_kind_gate=true;slot_filter.slots[0].state=2;
    const auto inactive_slot=compare_visibility({state_grid,slot_filter,{}},state_bytes,{1,0,1},{100,0,1});check(!inactive_slot.blocked&&!inactive_slot.hit_kind);
    auto bytes=synthetic();for(unsigned i=0;i<4;++i){put(bytes,synthetic_nodes+64*i+4,float(30-5*i));put(bytes,synthetic_nodes+64*i+12,1.f);}
    auto graph=imported(bytes).graphs()[0];
    const auto all_blocked=compare_visible_nearest(graph,{wall,{},{}},wall_bytes,{1,0,1},0);
    // Source s1 is reused by pairwise swaps before the filter loop. The last
    // swapped old head survives when all visible tests block; it is not -1.
    check(all_blocked.status==n::QueryStatus::completed&&all_blocked.node==0);
    for(const auto& room:{n::VisibilityRoom{wall,{},{}},n::VisibilityRoom{empty_grid,{},{}}}){
        const auto& encoded=room.walls.triangles().empty()?clear:wall_bytes;
        for(unsigned i=0;i<4;++i)for(const auto offset:{n::Position{},n::Position{1,20,0},n::Position{-2,0,0}}){
            auto query=graph.nodes()[i].position;query.x+=offset.x;query.y+=offset.y;query.z+=offset.z;
            for(std::int8_t group:{std::int8_t(-1),std::int8_t(0),std::int8_t(1)})compare_visible_nearest(graph,room,encoded,query,group);
        }
    }
    const auto no_group=compare_visible_nearest(graph,{empty_grid,{},{}},clear,{1,0,1},1);check(no_group.status==n::QueryStatus::completed&&no_group.node==-1);
    check(compare_visibility({empty_grid,{},{}},clear,{-10,0,1},{100,0,1}).status==n::QueryStatus::unavailable);
    check(compare_visible_nearest(graph,{empty_grid,{},{}},clear,{std::numeric_limits<float>::infinity(),0,0},0).status==n::QueryStatus::unavailable);
#ifdef REO_NAVIGATION_ORIGINAL
    for(unsigned motion=0;motion<256;++motion)for(unsigned status:{0u,0x200u,0x20000u,0xffffffffu})for(unsigned auxiliary:{0u,0x10000u,0x20000u,0x4000000u,0x400u,0xffffffffu}){
        constexpr unsigned actor=0xf00000;memory[actor+0x54f]=std::uint8_t(motion);put(memory,actor+0xba0,status);put(memory,actor+0xba4,auxiliary);
        check(n::node_selection_prefers_unfiltered(std::uint8_t(motion),status,auxiliary)==bool(call(0x813bd0,{actor})));++node_policy_cases;
    }
#endif
    reo::native::gameplay_session::RoomVariants variants;variants.restore({});n::Bank bank(variants);
    for(bool descending:{false,true}){
        for(unsigned i=0;i<4;++i){put(bytes,synthetic_nodes+64*i+4,float(descending?30-5*i:15+5*i));}
        check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));
        for(unsigned policy:{0u,1u,2u,3u,0xffffffffu})for(unsigned mode:{0u,1u,255u})for(unsigned motion:{0u,6u,0x21u,0x3bu})for(unsigned status:{0u,0x200u}){
            for(const auto& room:{n::VisibilityRoom{wall,{},{}},n::VisibilityRoom{empty_grid,{},{}}}){
                const auto& encoded=room.walls.triangles().empty()?clear:wall_bytes;
                auto state=actor_route_state(-42,0,7);state.selection_mode=std::uint8_t(mode);
                compare_node_choice(bank,{{},status,0,7,{1,0,1},std::uint8_t(motion),0},policy,room,encoded,state);
            }
        }
    }
}
