#include "navigation.hpp"
#include "bank.hpp"
#include "conditions.hpp"
#include "edges.hpp"
#include "routes.hpp"
#include "cost_routes.hpp"
#include "cost_graph.hpp"
#include "local_routes.hpp"
#include "link_collection.hpp"
#include "cross_room.hpp"
#include "actor_routes.hpp"
#include "destination.hpp"
#include "visibility.hpp"
#include "scene_candidates.hpp"
#include "scene_lookup.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <source_location>
#include <stdexcept>
#include <string>
#include <utility>
#include <tuple>
#ifdef REO_NAVIGATION_ORIGINAL
#include "reference.hpp"
#include "functions.h"
#endif
namespace n=reo::native::gameplay_navigation;
namespace {
std::uint64_t checks{},nearest_cases{},action_cases{},asset_nodes{},asset_conditions{},asset_rooms{},asset_links{},refusals{},bindings{},clears{},nearest_refusals{},action_refusals{},bank_cells{},bank_visit_cells{},bank_clears{};
std::uint64_t condition_cases{},link_cases{},link_refusals{};
std::uint64_t edge_cases{},edge_refusals{};
std::uint64_t retail_edge_refusals{},edge_flag_bindings{};
std::uint64_t cost_scratch_clears{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Navigation check "+std::to_string(checks)+" line "+std::to_string(at.line()));
}
template<class T>void put(std::vector<std::uint8_t>& b,std::size_t at,T value){
    static_assert(sizeof(T)<=4);check(at+sizeof(T)<=b.size());
    const auto raw=std::bit_cast<std::array<std::uint8_t,sizeof(T)>>(value);
    std::copy(raw.begin(),raw.end(),b.begin()+at);
}
std::uint32_t word(std::span<const std::uint8_t> b,std::size_t at){check(at+4<=b.size());return std::uint32_t(b[at])|std::uint32_t(b[at+1])<<8|std::uint32_t(b[at+2])<<16|std::uint32_t(b[at+3])<<24;}
std::vector<std::uint8_t> read(const char* path){std::ifstream f(path,std::ios::binary);check(bool(f));return {std::istreambuf_iterator<char>(f),{}};}
constexpr std::size_t synthetic_room=32,synthetic_nodes=44,synthetic_tail=364,synthetic_directory=404;
std::vector<std::uint8_t> synthetic(){
    // 4 nodes, 16 route words, 2 conditions, directory, one trailing payload.
    std::vector<std::uint8_t> b(472);put(b,0,std::uint32_t(0x20030724));put(b,4,std::uint32_t(12));put(b,8,std::uint32_t(16));
    put(b,16,std::uint32_t(1));put(b,20,std::uint16_t(7));put(b,22,std::uint16_t(0));put(b,24,std::uint32_t(synthetic_room));
    put(b,synthetic_room,std::uint32_t(synthetic_tail-synthetic_room));put(b,synthetic_room+4,std::uint32_t(synthetic_directory-synthetic_room));put(b,synthetic_room+8,std::uint32_t(4));
    put(b,synthetic_tail+4,std::uint32_t(2));put(b,synthetic_directory,std::uint32_t(64));b[synthetic_directory+64]=9;
    for(std::size_t i=0;i<4;++i){const auto at=synthetic_nodes+64*i;b[at]=1;put(b,at+4,float(i));put(b,at+16,std::int32_t(-1));}
    return b;
}
n::Asset imported(const std::vector<std::uint8_t>& bytes){n::ImportFailure why;auto asset=n::Asset::read(bytes,why);check(bool(asset)&&why.reason==n::ImportError::none);return std::move(*asset);}
#ifdef REO_NAVIGATION_ORIGINAL
std::uint32_t reference_cost_address{};bool reference_cost_written{};
struct OriginalCostLimit {bool global{};};
std::size_t reference_cost_recursion_limit{},reference_cost_recursions{};
std::vector<std::uint8_t> memory(0x2000000);
std::uint32_t call(unsigned pc,std::array<unsigned,4> args={}){
    R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);
}
void source_graph(const n::RoomGraph& graph,unsigned room_index=0){
    const auto room=std::size_t(0x83e550+164*room_index),data=std::size_t(0x1000000);
    std::copy(graph.encoding().begin(),graph.encoding().end(),memory.begin()+data);
    put(memory,room+8,std::uint32_t(graph.nodes().size()));put(memory,room+12,std::uint32_t(data+12));
    put(memory,room+16,std::uint32_t(data+12+64*graph.nodes().size()));
    put(memory,room+0x9c,std::uint32_t(data+word(graph.encoding(),0)+8));
    put(memory,room+0xa0,std::uint32_t(data+word(graph.encoding(),0)));
}
void compare_action(const n::RoomGraph& graph,std::int32_t index){
    const auto native=n::reverse_edge_action(graph,index);
    if(native.status==n::QueryStatus::completed){check(native.action==std::bit_cast<std::int32_t>(call(0x8196e0,{0,std::uint32_t(index)})));++action_cases;}
    else {++refusals;++action_refusals;}
}
void compare_nearest(const n::RoomGraph& graph,n::Position query,std::int8_t group){
    const auto native=n::nearest_node(graph,query,group);
    if(native.status!=n::QueryStatus::completed){++refusals;++nearest_refusals;return;}
    put(memory,0x1e00000,query.x);put(memory,0x1e00004,query.y);put(memory,0x1e00008,query.z);
    const auto expected=std::bit_cast<std::int32_t>(call(0x8171e0,{0x1e00000,std::uint32_t(std::int32_t(group)),0,0}));
    check(native.node==expected);++nearest_cases;
    if(!group){check(native.node==std::bit_cast<std::int32_t>(call(0x8171d0,{0x1e00000,0})));}
}
void compare_condition(const n::RoomGraph& graph,std::int32_t index,n::ActorFacts facts,std::uint16_t flags){
    constexpr unsigned actor=0xf00000;memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;put(memory,0x4b9e20,flags);
    const auto native=n::applicable_condition(graph,index,facts);const auto admitted=n::admit_condition(graph,index,facts,flags);
    check(native.status==n::QueryStatus::completed&&admitted.status==n::QueryStatus::completed);
    check(native.index==std::bit_cast<std::int32_t>(call(0x81a0e0,{actor,std::uint32_t(index),0})));
    check(admitted.allowed==(call(0x819220,{actor,std::uint32_t(index),0})==1));++condition_cases;
}
void compare_edge(const n::Bank& bank,n::ActorFacts facts,unsigned status,std::int32_t source,std::int32_t destination,std::uint16_t flags,unsigned room=7){
    const auto native=n::admit_edge(bank,room,source,destination,facts,status,flags);
    if(native.status!=n::QueryStatus::completed){++edge_refusals;return;}
    const auto graph=bank.room(room);check(bool(graph));source_graph(*graph,room);
    const auto edge_flags=bank.edge_flags(room);check(bool(edge_flags));std::copy(edge_flags->begin(),edge_flags->end(),memory.begin()+0x1000000+word(graph->encoding(),0));
    constexpr unsigned actor=0xf00000;memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;put(memory,actor+0xba0,status);put(memory,0x4b9e20+12*room,flags);
    check(native.allowed==(call(0x819010,{actor,std::uint32_t(source),std::uint32_t(destination),room})==1));++edge_cases;
}
#else
void source_graph(const n::RoomGraph&,unsigned=0){}
void compare_action(const n::RoomGraph&,std::int32_t){}
void compare_nearest(const n::RoomGraph&,n::Position,std::int8_t){}
void compare_condition(const n::RoomGraph&,std::int32_t,n::ActorFacts,std::uint16_t){}
void compare_edge(const n::Bank&,n::ActorFacts,unsigned,std::int32_t,std::int32_t,std::uint16_t,unsigned=7){}
#endif
void contracts(){
    auto bytes=synthetic();auto asset=imported(bytes);const auto* graph=asset.find_room(7,0);check(graph&&graph->nodes().size()==4&&graph->conditions().size()==2);
    check(!asset.find_room(7,1)&&!asset.find_room(-1,0)&&graph->condition_directory_entry(0).size()==4&&graph->condition_directory_entry(0)[0]==9);
    check(graph->condition_directory_entry(1).empty()&&graph->condition_directory_entry(16).empty());
    source_graph(*graph);
    check(n::nearest_node(*graph,{0.5f,0,0},0).node==0);compare_nearest(*graph,{0.5f,0,0},0);
    check(n::nearest_node(*graph,{2.5f,0,0},0).node==2);compare_nearest(*graph,{2.5f,0,0},0);
    check(n::nearest_node(*graph,{},1).status==n::QueryStatus::unavailable);
    check(n::nearest_node(*graph,{std::numeric_limits<float>::infinity(),0,0},0).status==n::QueryStatus::unavailable);
    check(n::nearest_node(*graph,{std::numeric_limits<float>::max(),0,0},0).status==n::QueryStatus::unavailable);
    check(n::reverse_edge_action(*graph,-1).status==n::QueryStatus::unavailable&&n::reverse_edge_action(*graph,4).status==n::QueryStatus::unavailable);
    // No neighbors is an early no-action even with a condition of type0.
    put(bytes,synthetic_nodes+16,std::int32_t(0));asset=imported(bytes);graph=asset.find_room(7,0);source_graph(*graph);
    check(n::reverse_edge_action(*graph,0).action==-1);compare_action(*graph,0);
    bytes[synthetic_nodes+1]=1;bytes[synthetic_nodes+20]=1;
    for(unsigned type=0;type<256;++type)for(unsigned subtype=0;subtype<256;++subtype){
        bytes[synthetic_tail+8+1]=std::uint8_t(type);bytes[synthetic_tail+8+3]=std::uint8_t(subtype);
        asset=imported(bytes);graph=asset.find_room(7,0);source_graph(*graph);
        const auto value=n::reverse_edge_action(*graph,0);const auto expected=type==0?4:type==1?5:type==6&&subtype==4?8:type==6&&subtype==5?9:-1;
        check(value.status==n::QueryStatus::completed&&value.action==expected);compare_action(*graph,0);
    }
    // Full action-word domain, not just low-byte selectors. Later reverse
    // entries in the first productive neighbor win; types11/12 return at once.
    bytes=synthetic();bytes[synthetic_nodes+1]=2;bytes[synthetic_nodes+20]=1;bytes[synthetic_nodes+21]=2;
    bytes[synthetic_nodes+64+1]=2;bytes[synthetic_nodes+64+20]=0;bytes[synthetic_nodes+64+21]=0;
    bytes[synthetic_nodes+128+1]=1;bytes[synthetic_nodes+128+20]=0;put(bytes,synthetic_nodes+128+24,std::uint16_t(0x3309));
    for(const auto second:{std::uint16_t(0),std::uint16_t(0x1205),std::uint16_t(0x990c)})for(unsigned value=0;value<65536;++value){
        put(bytes,synthetic_nodes+64+24,std::uint16_t(value));put(bytes,synthetic_nodes+64+26,second);
        asset=imported(bytes);graph=asset.find_room(7,0);source_graph(*graph);const auto action=n::reverse_edge_action(*graph,0);
        const auto low=value&255;const auto expected=low==11||low==12||second==0x990c?11:second?int(second):low==4||low==5||low==8||low==9?int(value):0x3309;
        check(action.status==n::QueryStatus::completed&&action.action==expected);compare_action(*graph,0);
    }
    // A productive first neighbor prevents inspecting a later invalid neighbor.
    bytes[synthetic_nodes+21]=127;put(bytes,synthetic_nodes+64+24,std::uint16_t(4));put(bytes,synthetic_nodes+64+26,std::uint16_t(0x1205));asset=imported(bytes);graph=asset.find_room(7,0);source_graph(*graph);
    check(n::reverse_edge_action(*graph,0).action==0x1205);compare_action(*graph,0);
    bytes[synthetic_nodes+20]=127;asset=imported(bytes);graph=asset.find_room(7,0);check(n::reverse_edge_action(*graph,0).status==n::QueryStatus::unavailable);
    bytes=synthetic();bytes[synthetic_nodes+1]=1;bytes[synthetic_nodes+20]=1;put(bytes,synthetic_nodes+16,std::int32_t(2));asset=imported(bytes);graph=asset.find_room(7,0);check(n::reverse_edge_action(*graph,0).status==n::QueryStatus::unavailable);
    // Signed count<=0 returns before that invalid ordinal or neighbor.
    for(unsigned count=128;count<256;++count){bytes[synthetic_nodes+1]=std::uint8_t(count);asset=imported(bytes);graph=asset.find_room(7,0);source_graph(*graph);check(n::reverse_edge_action(*graph,0).action==-1);compare_action(*graph,0);}
    // Signed query group versus unsigned stored halfword, active nonzero.
    bytes=synthetic();for(unsigned group=0;group<256;++group){
        for(unsigned i=0;i<4;++i){bytes[synthetic_nodes+64*i]=std::uint8_t(i?255:0);put(bytes,synthetic_nodes+64*i+2,std::uint16_t(group));}
        asset=imported(bytes);graph=asset.find_room(7,0);source_graph(*graph);const auto selected=std::bit_cast<std::int8_t>(std::uint8_t(group));
        check(n::nearest_node(*graph,{1,0,0},selected).node==1);compare_nearest(*graph,{1,0,0},selected);
    }
    bytes=synthetic();for(unsigned i=0;i<4;++i)bytes[synthetic_nodes+64*i]=0;asset=imported(bytes);check(n::nearest_node(*asset.find_room(7,0),{},-1).status==n::QueryStatus::unavailable);
    // Import has bounded extents and budgets, never partial success.
    const auto reject=[&](const auto& bad,n::ImportError error){n::ImportFailure why;check(!n::Asset::read(bad,why)&&why.reason==error);++refusals;};
    bytes=synthetic();for(std::size_t length=0;length<bytes.size();++length){
        // Trailing directory payload is opaque and may legally have any length
        // >=1; only required-section truncations must fail.
        if(length<=synthetic_directory+64){n::ImportFailure why;check(!n::Asset::read(std::span(bytes).first(length),why));++refusals;}
    }
    const auto bad_word=[&](std::size_t at,std::uint32_t value,n::ImportError error){auto bad=synthetic();put(bad,at,value);reject(bad,error);};
    bad_word(0,0,n::ImportError::version);bad_word(4,0xfffffffcu,n::ImportError::layout);bad_word(8,20,n::ImportError::layout);
    bad_word(12,257,n::ImportError::budget);bad_word(16,513,n::ImportError::budget);bad_word(24,20,n::ImportError::layout);
    bad_word(synthetic_room,0xffffffffu,n::ImportError::layout);bad_word(synthetic_room+4,0xffffffffu,n::ImportError::layout);
    bad_word(synthetic_room+8,129,n::ImportError::budget);bad_word(synthetic_tail+4,4097,n::ImportError::budget);
    bad_word(synthetic_directory,63,n::ImportError::layout);bad_word(synthetic_directory,0xffffffffu,n::ImportError::layout);
    bad_word(synthetic_nodes+4,0x7fc00000u,n::ImportError::coordinates);bytes=synthetic();bytes[synthetic_nodes+1]=5;reject(bytes,n::ImportError::layout);
    // Two descriptor keys can refer to one immutable graph. Last matching key
    // selects the last authored descriptor, with a different graph as well.
    bytes=synthetic();bytes.insert(bytes.begin()+32,12,0);put(bytes,16,std::uint32_t(2));put(bytes,24,std::uint32_t(44));
    put(bytes,32,std::uint16_t(7));put(bytes,34,std::uint16_t(1));put(bytes,36,std::uint32_t(44));
    asset=imported(bytes);check(asset.graphs().size()==1&&asset.find_room(7,0)==asset.find_room(7,1));
    auto second=std::vector<std::uint8_t>(bytes.begin()+44,bytes.end());const auto end=std::uint32_t(bytes.size());bytes.insert(bytes.end(),second.begin(),second.end());put(bytes,36,end);put(bytes,34,std::uint16_t(0));
    asset=imported(bytes);check(asset.graphs().size()==2&&asset.find_room(7,0)->source_offset()==end);
}
void bank_contracts(){
    auto bytes=synthetic();bytes.insert(bytes.begin()+16,20,0);put(bytes,8,std::uint32_t(36));put(bytes,12,std::uint32_t(1));put(bytes,44,std::uint32_t(52));
    for(unsigned i=0;i<4;++i)bytes[32+i]=std::uint8_t(17+i);
    const auto asset=std::make_shared<const n::Asset>(imported(bytes));
    reo::native::gameplay_session::RoomVariants variants;n::Bank bank(variants);
    check(!variants.get(7)&&!bank.bind(asset)&&!bank.bound()&&!bank.room(7));
    check(variants.store(7,0)&&bank.bind(asset)&&bank.room(7));
    for(unsigned i=0;i<4;++i)check(bank.visits(i).size()==1&&bank.visits(i)[0]==17+i);
    check(bank.visit(2,0,255)&&bank.occupancy(7,127,255));check(bank.bind(asset)&&bank.visits(2)[0]==255&&bank.occupancy(7,127)==0);
    check(variants.store(7,1)&&bank.room(7));check(bank.bind(asset)&&!bank.room(7)&&bank.visits(2)[0]==255);
    bank.clear_rooms();check(!bank.bound()&&!bank.room(7)&&bank.visits(0).empty());
    check(variants.store(7,0)&&bank.bind(asset)&&bank.visits(2)[0]==255&&bank.room(7));
    check(bank.bind(std::make_shared<const n::Asset>(*asset))&&bank.visits(2)[0]==19);
    check(!bank.bind(nullptr)&&bank.bound()&&bank.room(7));
    check(!bank.visit(4,0,1)&&!bank.visit(0,1,1)&&!bank.clear_actor_visits(4)&&bank.visits(4).empty());
    check(!bank.occupancy(128,0)&&!bank.occupancy(0,128)&&!bank.occupancy(128,0,1)&&!bank.occupancy(0,128,1));
    bank.close();check(!bank.bound()&&!bank.bind(asset)&&!bank.clear_actor_visits(0)&&!bank.occupancy(7,0)&&bank.visits(0).empty());
    check(!variants.get(128)&&!variants.store(128,1));
}
void condition_contracts(){
    auto bytes=synthetic();
    const auto compare=[&](n::ActorFacts actor,std::uint16_t flags){const auto asset=imported(bytes);const auto graph=asset.find_room(7,0);source_graph(*graph);compare_condition(*graph,0,actor,flags);};
    // Every type and subtype3 byte, including type7's19/20 exceptions and
    // inactive conditions that are intentionally admitted by default cases.
    for(unsigned type=0;type<256;++type)for(unsigned subtype=0;subtype<256;++subtype)for(unsigned active:{0u,255u}){
        bytes[synthetic_tail+8]=std::uint8_t(active);bytes[synthetic_tail+9]=std::uint8_t(type);bytes[synthetic_tail+11]=std::uint8_t(subtype);
        bytes[synthetic_tail+14]=std::uint8_t(subtype);bytes[synthetic_tail+15]=7;compare({7,3,255},0xffff);
    }
    bytes[synthetic_tail+8]=1;bytes[synthetic_tail+9]=1;
    for(unsigned subtype=0;subtype<256;++subtype)for(unsigned character=0;character<256;++character)for(unsigned ai:{0u,255u})for(unsigned match=0;match<3;++match){
        const auto slot=std::uint8_t(character*17);bytes[synthetic_tail+14]=std::uint8_t(subtype);
        bytes[synthetic_tail+15]=match==0?std::uint8_t(character):match==1?std::uint8_t(character+1):slot;
        compare({std::uint8_t(character),slot,std::uint8_t(ai)},0);
    }
    for(unsigned type:{0u,2u})for(unsigned bit=0;bit<256;++bit)for(unsigned flags:{0u,1u,0x8000u,0xffffu}){
        bytes[synthetic_tail+9]=std::uint8_t(type);bytes[synthetic_tail+10]=std::uint8_t(bit);compare({},std::uint16_t(flags));
    }
    bytes=synthetic();bytes[synthetic_tail+8]=1;auto asset=imported(bytes);const auto graph=asset.find_room(7,0);
    check(n::admit_condition(*graph,0,{},{}).status==n::QueryStatus::unavailable); // active type0 needs a real flag value
    check(n::applicable_condition(*graph,-1,{}).status==n::QueryStatus::unavailable&&n::admit_condition(*graph,2,{},0).status==n::QueryStatus::unavailable);
    bytes[synthetic_tail+8]=0;asset=imported(bytes);check(n::admit_condition(*asset.find_room(7,0),0,{},{}).status==n::QueryStatus::completed&&!n::admit_condition(*asset.find_room(7,0),0,{},{}).allowed);
    // Default admission is allowed even when applicability returns -1.
    bytes[synthetic_tail+9]=3;asset=imported(bytes);check(n::admit_condition(*asset.find_room(7,0),0,{},{}).allowed);
    reo::native::gameplay_session::RoomVariants variants;n::Bank bank(variants);check(n::find_admitted_link(bank,{},7,0,0,0).status==n::QueryStatus::unavailable);
}
void link_contracts(){
    auto bytes=synthetic();bytes.insert(bytes.begin()+16,36,0);put(bytes,8,std::uint32_t(52));put(bytes,12,std::uint32_t(2));put(bytes,60,std::uint32_t(68));
    bytes[16]=7;bytes[28]=7;bytes[31]=1;bytes[synthetic_tail+8+36]=0;bytes[synthetic_tail+9+36]=1;
    bytes[synthetic_tail+24+36]=1;bytes[synthetic_tail+25+36]=1;
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    const auto test=[&](std::optional<std::size_t> wanted,n::QueryStatus status){
        const auto asset=std::make_shared<const n::Asset>(imported(bytes));check(bank.bind(asset));check(n::find_link(*asset,7,0,0)==0);
        const auto selected=n::find_admitted_link(bank,{},7,0,0,0);check(selected.status==status&&selected.index==wanted);
#ifdef REO_NAVIGATION_ORIGINAL
        if(status==n::QueryStatus::completed){
            std::copy(bytes.begin(),bytes.end(),memory.begin()+0x843780);std::fill_n(memory.begin()+0x4b9d20,128,0);call(0x815e70,{2});
            check(call(0x8193a0,{7,0,0})==0x843780+16);check(call(0x819410,{0xf00000,7,0,0})==(wanted?0x843780+16+12*(*wanted):0));++link_cases;
        }else ++link_refusals;
#endif
    };
    test(1,n::QueryStatus::completed);bytes[synthetic_tail+24+36]=0;test({},n::QueryStatus::completed);
    bytes[19]=255;test({},n::QueryStatus::unavailable); // signed invalid condition cannot be bypassed
    check(n::find_admitted_link(bank,{},7,1,0,{}).status==n::QueryStatus::completed&&!n::find_admitted_link(bank,{},7,1,0,{}).index);
}
void edge_contracts(){
    auto bytes=synthetic();bytes[synthetic_nodes+20]=1;put(bytes,synthetic_nodes+16,std::int32_t(0));bytes[synthetic_tail+8]=1;bytes[synthetic_tail+9]=3;
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    const auto bind=[&]{check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));};
    for(unsigned word=0;word<65536;++word){
        put(bytes,synthetic_nodes+24,std::uint16_t(word));put(bytes,synthetic_nodes+44,std::uint32_t(1));bind();
        for(unsigned status:{0u,8u,0x80u,0x10000u})compare_edge(bank,{7,3,255},status,0,1,0);
    }
    for(unsigned action:{0u,4u,10u})for(unsigned lane=0;lane<4;++lane)for(unsigned code=0;code<256;++code){
        put(bytes,synthetic_nodes+24,std::uint16_t(action));put(bytes,synthetic_nodes+44,std::uint32_t(code<<(8*lane)));bind();
        for(unsigned present:{0u,1u,255u})for(unsigned status:{0u,8u}){
            std::array<std::uint8_t,4> flags{};flags[lane]=std::uint8_t(present);check(bank.edge_flags(7,flags));compare_edge(bank,{7,3,0},status,0,1,0);
        }
    }
    for(unsigned packed=0;packed<256;++packed){
        unsigned encoded{};for(unsigned lane=0;lane<4;++lane)encoded|=((packed>>(2*lane))&3)<<(8*lane);
        put(bytes,synthetic_nodes+44,encoded);put(bytes,synthetic_nodes+24,std::uint16_t(4));bind();
        for(unsigned mask=0;mask<16;++mask){std::array<std::uint8_t,4> flags{};for(unsigned lane=0;lane<4;++lane)flags[lane]=mask&(1u<<lane)?255:0;check(bank.edge_flags(7,flags));compare_edge(bank,{7,3,0},0,0,1,0);}
    }
    // First of four signed slots wins even when neighbor_count is0. The target
    // record itself is not dereferenced by this admission helper.
    bytes=synthetic();bytes[synthetic_nodes+20]=1;bytes[synthetic_nodes+21]=1;bytes[synthetic_nodes+22]=3;bytes[synthetic_nodes+23]=254;
    put(bytes,synthetic_nodes+24,std::uint16_t(0));put(bytes,synthetic_nodes+26,std::uint16_t(4));bind();
    check(n::admit_edge(bank,7,0,1,{},8,0).allowed);compare_edge(bank,{},8,0,1,0);compare_edge(bank,{},0,0,-2,0);
    check(!n::admit_edge(bank,7,0,2,{},0,0).allowed);compare_edge(bank,{},0,0,2,0);
    // Destination-1 selects only the node condition, independent of action,
    // packed edge flags or actor status. Missing ordinal is unavailable.
    put(bytes,synthetic_nodes+16,std::int32_t(0));bytes[synthetic_tail+8]=1;bytes[synthetic_tail+9]=1;bytes[synthetic_tail+14]=4;bind();
    for(unsigned ai:{0u,255u}){compare_edge(bank,{7,3,std::uint8_t(ai)},0xffffffff,0,-1,0);check(n::admit_edge(bank,7,0,-1,{7,3,std::uint8_t(ai)},0xffffffff,0).allowed==(ai!=0));}
    put(bytes,synthetic_nodes+16,std::int32_t(2));bind();compare_edge(bank,{},0,0,-1,0);check(n::admit_edge(bank,7,0,-1,{},0,0).status==n::QueryStatus::unavailable);
    check(n::admit_edge(bank,7,-2,1,{},0,0).status==n::QueryStatus::unavailable&&n::admit_edge(bank,8,0,1,{},0,0).status==n::QueryStatus::unavailable);
    const auto held=bank.asset();check(held&&bank.edge_flags(7,std::array<std::uint8_t,4>{1,2,3,4}));
    auto same=std::make_shared<const n::Asset>(imported(bytes));check(bank.bind(same)&&bank.edge_flags(7,std::array<std::uint8_t,4>{1,2,3,4})&&bank.bind(same)&&bank.edge_flags(7)==std::array<std::uint8_t,4>{1,2,3,4});
#ifdef REO_NAVIGATION_ORIGINAL
    std::copy(bytes.begin(),bytes.end(),memory.begin()+0x843780);std::fill_n(memory.begin()+0x4b9d20,128,0);
    const auto source_tail=0x843780+synthetic_tail;for(unsigned i=0;i<4;++i)memory[source_tail+i]=std::uint8_t(i+1);call(0x815e70,{2});
    const auto pointer=word(memory,0x83e550+164*7+0xa0);check(pointer==source_tail);for(unsigned i=0;i<4;++i)check((*bank.edge_flags(7))[i]==memory[pointer+i]);++edge_flag_bindings;
#endif
    bank.clear_rooms();check(!bank.edge_flags(7)&&bank.bind(same)&&bank.edge_flags(7)==std::array<std::uint8_t,4>{1,2,3,4});
    bank.close();check(!bank.edge_flags(7)&&!bank.edge_flags(7,std::array<std::uint8_t,4>{}));
    // Original returns immediately for equal node codes, before any graph read.
    check(n::admit_edge(bank,0xffffffff,-1,-1,{},0,{}).allowed);
    // Different rooms can select the same authored graph. Its mutable flags
    // have one identity across both room selections, just like source pointers.
    bytes=synthetic();bytes.insert(bytes.begin()+32,12,0);put(bytes,16,std::uint32_t(2));put(bytes,24,std::uint32_t(44));
    put(bytes,32,std::uint16_t(8));put(bytes,34,std::uint16_t(0));put(bytes,36,std::uint32_t(44));
    n::Bank shared_bank(variants);check(variants.store(8,0)&&shared_bank.bind(std::make_shared<const n::Asset>(imported(bytes))));
    check(shared_bank.edge_flags(7,std::array<std::uint8_t,4>{7,8,9,10})&&shared_bank.edge_flags(8)==std::array<std::uint8_t,4>{7,8,9,10});
#ifdef REO_NAVIGATION_ORIGINAL
    std::copy(bytes.begin(),bytes.end(),memory.begin()+0x843780);call(0x815e70,{2});
    const auto first=word(memory,0x83e550+164*7+0xa0),second=word(memory,0x83e550+164*8+0xa0);check(first==second);
    for(unsigned i=0;i<4;++i){memory[first+i]=std::uint8_t(i+7);}
    call(0x815e70,{2});for(unsigned i=0;i<4;++i){check((*shared_bank.edge_flags(8))[i]==memory[second+i]);}++edge_flag_bindings;
#endif
}
#include "ranked_route_tests.inc"
#include "cost_route_tests.inc"
#include "cost_graph_tests.inc"
#include "local_route_tests.inc"
#include "link_collection_tests.inc"
#include "cross_room_tests.inc"
#include "actor_route_tests.inc"
#include "destination_tests.inc"
#include "visibility_tests.inc"
#include "scene_candidate_tests.inc"
#include "scene_lookup_tests.inc"
void owned(const char* path){
    const auto bytes=read(path);const auto asset=imported(bytes);asset_rooms+=asset.descriptors().size();asset_links+=asset.links().size();
    reo::native::gameplay_session::RoomVariants native_variants;n::Bank bank(native_variants);const auto shared=std::make_shared<const n::Asset>(asset);
#ifdef REO_NAVIGATION_ORIGINAL
    constexpr unsigned input=0x843780;std::copy(bytes.begin(),bytes.end(),memory.begin()+input);
    const auto a=word(bytes,4),b=word(bytes,8);const auto links=asset.links().size();
    check(call(0x816000)==input+a&&call(0x816020)==input+b&&call(0x816040)==links);
    check(call(0x816060)==input+a+4&&call(0x816080)==input+a+4+12*links);
    check(call(0x8160c0)==input+a+4+12*links+((links*links+3)&~std::size_t(3)));
    check(call(0x816100)==asset.descriptors().size());
    std::vector<unsigned> variants{0,255};
    for(const auto& descriptor:asset.descriptors())if(descriptor.variant>=0&&descriptor.variant<=255)variants.push_back(unsigned(descriptor.variant));
    std::sort(variants.begin(),variants.end());variants.erase(std::unique(variants.begin(),variants.end()),variants.end());
    for(const auto variant:variants){
        std::array<std::uint8_t,128> native_values;native_values.fill(std::uint8_t(variant));native_variants.restore(native_values);check(bank.bind(shared));
        std::fill_n(memory.begin()+0x4b9d20,128,std::uint8_t(variant));call(0x815e70,{2});
        for(unsigned room=0;room<128;++room){
            const auto graph=asset.find_room(std::int32_t(room),std::int32_t(variant));const auto entry=0x83e550+164*room;
            check(word(memory,entry)==unsigned(bool(graph)));
            check(bank.room(room)==shared->find_room(std::int32_t(room),std::int32_t(variant)));
            if(graph)check(word(memory,entry+8)==graph->nodes().size()&&word(memory,entry+12)==input+graph->source_offset()+12&&word(memory,entry+0x98)==graph->conditions().size());
            check(std::all_of(memory.begin()+entry+0x14,memory.begin()+entry+0x94,[](auto value){return value==0;}));++bindings;
        }
        const auto link_base=call(0x816060);
        for(const auto& link:asset.links()){
            const auto unfiltered=n::find_link(asset,link.room,link.variant,link.node);check(bool(unfiltered));
            check(call(0x8193a0,{std::uint32_t(std::int32_t(link.room)),std::uint32_t(std::int32_t(link.variant)),std::uint32_t(std::int32_t(link.node))})==link_base+12*(*unfiltered));
            for(unsigned profile=0;profile<4;++profile){
                const n::ActorFacts facts{std::uint8_t(profile*2),std::uint8_t(profile),std::uint8_t(profile&1?255:0)};const auto flags=std::uint16_t(profile&2?0xffff:0);
                const auto selected=n::find_admitted_link(bank,facts,link.room,link.variant,link.node,flags);
                if(selected.status!=n::QueryStatus::completed){++link_refusals;continue;}
                constexpr unsigned actor=0xf00000;memory[actor+3]=facts.slot;memory[actor+0xb98]=facts.character;memory[actor+0xff0]=facts.ai_control;
                check(link.room>=0);put(memory,0x4b9e20+12*unsigned(link.room),flags);
                const auto original=call(0x819410,{actor,std::uint32_t(std::int32_t(link.room)),std::uint32_t(std::int32_t(link.variant)),std::uint32_t(std::int32_t(link.node))});
                check(original==(selected.index?link_base+12*(*selected.index):0));++link_cases;
            }
        }
        for(unsigned i=0;i<asset.links().size();++i){
            const auto& from=asset.links()[i];if(from.variant!=std::int32_t(variant)||from.room<0)continue;
            for(const auto target:{i,unsigned((i+1)%asset.links().size()),unsigned((i+asset.links().size()/2)%asset.links().size())})for(unsigned profile=0;profile<3;++profile){
                const auto& to=asset.links()[target];if(to.room<0)continue;
                n::RoomFlags flags;flags.fill(std::uint16_t(profile==1?0xffff:0));
                const n::ActorFacts facts{std::uint8_t(profile*3),std::uint8_t(profile),std::uint8_t(profile&1)};
                check(bank.clear_actor_visits(profile));
                for(unsigned index=0;index<asset.links().size();++index)if(profile==1&&index%5==0)check(bank.visit(profile,index,7));
                n::CrossRoomOutput output{{-22,-23,{1,2,3},{4,5,6}},314};
                const auto result=compare_cross_route(bank,bytes,facts,profile==2?8u:0u,flags,unsigned(from.room),unsigned(to.room),from.node,to.node,output,{profile!=1,4096,128});
                if(result.status==n::QueryStatus::completed)++cross_retail_cases;
            }
        }
        for(unsigned room=0;room<128;++room)if(const auto graph=bank.room(room)){
            for(unsigned node=0;node<graph->nodes().size();++node)for(unsigned profile=0;profile<2;++profile)for(bool reverse:{false,true})for(bool omit:{false,true}){
                const n::ActorFacts facts{std::uint8_t(profile*7),std::uint8_t(profile),std::uint8_t(profile)};
                for(unsigned link=0;link<asset.links().size();++link){check(bank.visit(profile,link,std::uint8_t(profile&&link%3==0?7:0)));}
                const auto collected=compare_collection(bank,bytes,facts,profile?0x88u:0u,room,std::int32_t(variant),std::int32_t(node),std::uint16_t(profile?0xffff:0),bank.visits(profile),{reverse,omit,profile?std::optional<float>{}:std::optional<float>{0.f},16});
                if(collected.status!=n::QueryStatus::completed){++collection_retail_refusals;if(collected.failure==n::CollectionFailure::unknown_cost)++collection_retail_unknown_costs;}
            }
            for(unsigned i=0;i<graph->nodes().size();++i)for(unsigned slot=0;slot<4;++slot)for(unsigned profile=0;profile<4;++profile){
                check(bank.edge_flags(room,profile&1?std::array<std::uint8_t,4>{1,0,255,1}:graph->initial_edge_flags()));
                compare_edge(bank,{std::uint8_t(profile*2),std::uint8_t(profile),std::uint8_t(profile&1?255:0)},profile&2?0x88u:0u,std::int32_t(i),graph->nodes()[i].neighbors[slot],std::uint16_t(profile&2?0xffff:0),room);
                if(n::admit_edge(bank,room,std::int32_t(i),graph->nodes()[i].neighbors[slot],{std::uint8_t(profile*2),std::uint8_t(profile),std::uint8_t(profile&1?255:0)},profile&2?0x88u:0u,std::uint16_t(profile&2?0xffff:0)).status!=n::QueryStatus::completed){
                    check(std::string(path).ends_with("r041.sgl")&&room==70&&graph->source_offset()==138140&&i==0&&graph->nodes()[i].condition==19&&graph->conditions().size()==14);
                    ++retail_edge_refusals;
                }
            }
            for(unsigned source=0;source<graph->nodes().size();++source)for(const auto destination:{source,unsigned((source+1)%graph->nodes().size()),unsigned(graph->nodes().size()-1)})for(unsigned profile=0;profile<2;++profile){
                for(unsigned node=0;node<128;++node){check(bank.occupancy(room,node,std::uint8_t(profile&&(node+source)%7==0?255:0)));}
                for(const auto policy:{n::RankedPolicy::four_candidates,n::RankedPolicy::first_candidate}){
                    n::RouteOutput output{-22,-23,{1,2,3},{4,5,6},std::bit_cast<float>(0x7fc01234u)};
                    const auto result=compare_ranked(bank,{std::uint8_t(profile*7),std::uint8_t(profile),std::uint8_t(profile)},profile?0x88u:0u,std::int32_t(source),std::int32_t(destination),std::uint16_t(profile?0xffff:0),policy,output,room);
                    if(result.status!=n::QueryStatus::completed)++ranked_retail_refusals;
                }
                n::RouteOutput cost_output{-22,-23,{1,2,3},{4,5,6},std::bit_cast<float>(0x7fc01234u)};
                auto legacy_output=cost_output;
                const auto legacy=n::enumerated_cost_route(bank,room,std::int32_t(source),std::int32_t(destination),{std::uint8_t(profile*7),std::uint8_t(profile),std::uint8_t(profile)},profile?0x88u:0u,std::uint16_t(profile?0xffff:0),legacy_output,4096);
                const auto cost_result=compare_cost(bank,{std::uint8_t(profile*7),std::uint8_t(profile),std::uint8_t(profile)},profile?0x88u:0u,std::int32_t(source),std::int32_t(destination),std::uint16_t(profile?0xffff:0),cost_output,4096,room);
                if(cost_result.status!=n::QueryStatus::completed){++cost_retail_refusals;if(cost_result.budget_exhausted)++cost_retail_budgets;}
                n::RouteOutput candidate{-22,-23,{1,2,3},{4,5,6},std::bit_cast<float>(0x7fc01234u)};
                const auto solved=n::graph_cost_route(bank,room,std::int32_t(source),std::int32_t(destination),{std::uint8_t(profile*7),std::uint8_t(profile),std::uint8_t(profile)},profile?0x88u:0u,std::uint16_t(profile?0xffff:0),candidate);
                graph_admission_maximum=std::max(graph_admission_maximum,std::uint64_t(solved.admission_checks));graph_relaxation_maximum=std::max(graph_relaxation_maximum,std::uint64_t(solved.relaxations));graph_scan_maximum=std::max(graph_scan_maximum,std::uint64_t(solved.vertex_scans));
                if(solved.status==n::QueryStatus::completed){
                    ++graph_retail_admitted;
                    if(legacy.status==n::QueryStatus::completed){
                        check(solved.selected==legacy.selected&&solved.cost_written==legacy.cost_written&&candidate.first==legacy_output.first&&candidate.second==legacy_output.second);
                        check(std::memcmp(&candidate.first_position,&legacy_output.first_position,12)==0&&std::memcmp(&candidate.second_position,&legacy_output.second_position,12)==0&&std::bit_cast<unsigned>(candidate.cost)==std::bit_cast<unsigned>(legacy_output.cost));++graph_retail_equivalent;
                    }else{
                        check(legacy.budget_exhausted&&cost_result.used_graph_solver);++graph_retail_new;
                    }
                    check(cost_result.status==n::QueryStatus::completed&&solved.selected==cost_result.selected&&solved.cost_written==cost_result.cost_written);
                    check(candidate.first==cost_output.first&&candidate.second==cost_output.second&&std::memcmp(&candidate.first_position,&cost_output.first_position,12)==0&&std::memcmp(&candidate.second_position,&cost_output.second_position,12)==0&&std::bit_cast<unsigned>(candidate.cost)==std::bit_cast<unsigned>(cost_output.cost));
                }else ++graph_retail_refused;
                for(unsigned policy:{0u,1u,2u}){
                    n::RouteOutput local_output{-22,-23,{1,2,3},{4,5,6},std::bit_cast<float>(0x7fc01234u)};std::int16_t destination_link=314;
                    const auto local_result=compare_local(bank,bytes,{std::uint8_t(profile*7),std::uint8_t(profile),std::uint8_t(profile)},profile?0x88u:0u,std::int32_t(source),std::int32_t(destination),std::uint16_t(profile?0xffff:0),policy,local_output,destination_link,4096,room);
                    if(local_result.status!=n::QueryStatus::completed){++local_retail_refusals;if(local_result.budget_exhausted)++local_retail_budgets;}
                }
            }
        }
        for(unsigned room=0;room<128;++room)if(const auto graph=bank.room(room)){
            n::RoomFlags flags;flags.fill(0);
            for(unsigned node=0;node<graph->nodes().size();++node)for(unsigned target:{node,unsigned((node+1)%graph->nodes().size())})for(bool action:{false,true}){
                auto state=actor_route_state(std::int8_t(node),std::int8_t(target),std::uint16_t(room));
                const auto result=compare_actor_route(bank,bytes,{},0,flags,std::uint16_t(room),state,action,{});
                if(result.status==n::QueryStatus::completed)++actor_route_retail_cases;
                if(action){
                    const auto position=graph->nodes()[node].position,target_position=graph->nodes()[target].position;
                    auto requested=actor_route_state(std::int8_t(node),-1,std::uint16_t(room));
                    const std::array<std::uint8_t,4> classes{0,0x1a,0x27,0x31};
                    BeginCase input{{{},0,node&1?0x10000u:0u,std::uint16_t(room),{position.x+50.f,position.y,position.z},classes[node%4],std::uint8_t(node%7==0)},std::uint16_t(room),target_position,std::uint16_t(room)};
                    const auto begun=compare_actor_route(bank,bytes,{},0,flags,std::uint16_t(room),requested,true,{},&input);
                    if(begun.status==n::QueryStatus::completed)++destination_retail_cases;
                }
            }
        }
        check(word(memory,0x83e540)==links&&word(memory,0x83e548)==call(0x816080)&&word(memory,0x83e54c)==call(0x8160c0));
    }
    for(unsigned i=0;i<4;++i)check(call(0x8194d0,{i})==call(0x8160c0)+i*links);
    for(unsigned actor=0;actor<4;++actor){
        const auto visit_base=call(0x8160c0);
        for(unsigned other=0;other<4;++other)for(unsigned link=0;link<links;++link){const auto value=std::uint8_t(17*actor+23*other+link);check(bank.visit(other,link,value));memory[visit_base+other*links+link]=value;}
        for(unsigned room=0;room<128;++room)for(unsigned node=0;node<128;++node){const auto value=std::uint8_t(room+node*17+actor*31);check(bank.occupancy(room,node,value));memory[0x83e550+164*room+0x14+node]=value;}
        check(bank.clear_actor_visits(actor));call(0x8194f0,{actor});++bank_clears;
        for(unsigned other=0;other<4;++other)for(unsigned link=0;link<links;++link){check(bank.visits(other)[link]==memory[visit_base+other*links+link]);++bank_visit_cells;}
        for(unsigned room=0;room<128;++room)for(unsigned node=0;node<128;++node){check(bank.occupancy(room,node)==memory[0x83e550+164*room+0x14+node]);++bank_cells;}
    }
    // Relocation is performed only in original test memory. Native import
    // retains file-relative immutable offsets and does not rewrite the asset.
    call(0x8163f0);
    for(unsigned i=0;i<asset.descriptors().size();++i){
        const auto& graph=asset.graphs()[asset.descriptors()[i].graph];const auto start=graph.source_offset();
        check(call(0x816120,{i})==input+b+4+12*i&&call(0x8161e0,{i})==input+start);
        check(call(0x816220,{i})==graph.nodes().size()&&call(0x816250,{i})==input+start+12);
        check(call(0x816280,{i})==input+start+12+64*graph.nodes().size()&&call(0x8162c0,{i})==graph.conditions().size());
        check(call(0x816310,{i})==input+start+word(graph.encoding(),0)+8&&call(0x816360,{i})==input+start+word(graph.encoding(),0));
        const auto directory=call(0x8163b0,{i});check(directory==input+start+word(graph.encoding(),4));
        for(unsigned entry=0;entry<16;++entry){const auto relative=word(graph.encoding(),word(graph.encoding(),4)+4*entry);check(word(memory,directory+4*entry)==(relative?directory+relative:0));}
    }
#endif
    for(const auto& graph:asset.graphs()){
        asset_nodes+=graph.nodes().size();asset_conditions+=graph.conditions().size();source_graph(graph);
        const auto clear=visibility_grid({});const auto empty_grid=collision::response::Grid::import(std::as_bytes(std::span(clear)));
        for(const auto& node:graph.nodes()){
            const auto result=compare_visible_nearest(graph,{empty_grid,{},{}},clear,node.position,0);
            if(result.status==n::QueryStatus::completed)++visibility_retail_cases;
        }
        for(unsigned i=0;i<graph.conditions().size();++i)for(unsigned profile=0;profile<8;++profile)for(unsigned flags:{0u,0xffffu})compare_condition(graph,std::int32_t(i),{std::uint8_t(profile),std::uint8_t(7-profile),std::uint8_t(profile&1?255:0)},std::uint16_t(flags));
        for(unsigned i=0;i<graph.nodes().size();++i){
            const auto& node=graph.nodes()[i];compare_action(graph,std::int32_t(i));
            for(const auto offset:{n::Position{},n::Position{1,2,3},n::Position{-50,100,50},n::Position{0,10000,0}}){
                const n::Position query{node.position.x+offset.x,node.position.y+offset.y,node.position.z+offset.z};
                for(const auto group:{std::int8_t(-1),std::int8_t(0),std::int8_t(1),std::int8_t(127)})compare_nearest(graph,query,group);
            }
        }
    }
}
}
#ifdef REO_NAVIGATION_ORIGINAL
void navigation_reference_write(std::uint32_t at,std::size_t size){
    if(reference_cost_address&&at<=reference_cost_address&&std::size_t(reference_cost_address-at)<size)reference_cost_written=true;
}
void navigation_reference_cost_entry(){
    if(reference_cost_recursion_limit){
        if(++reference_cost_recursions>reference_cost_recursion_limit)throw OriginalCostLimit{false};
        if(graph_original_total_entries==2000000)throw OriginalCostLimit{true};
        ++graph_original_total_entries;
    }
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x817470)reference_cross_stack=GPR_U32(context,29);
    if(context->pc==0x8179f0){
        ++reference_collection_calls;
        // Declared correction oracle only; complete source instructions follow.
        if(reference_initialize_collection)std::fill_n(memory+GPR_U32(context,29)-8,4,0);
    }
    if(context->pc==0x107ab0){
        const auto destination=GPR_U32(context,4),source=GPR_U32(context,5),count=GPR_U32(context,6);
        check(destination==reference_cross_stack-0x4c0+0xe0&&count<=256&&count==word(::memory,0x83e540));
        check(source>=word(::memory,0x83e54c)&&source+count<=word(::memory,0x83e54c)+4*count);
        ++reference_visit_copies;
    }
    switch(context->pc){
    case 0x107c68:{
        const auto start=GPR_U32(context,4),count=GPR_U32(context,6),value=GPR_U32(context,5);
        if(start==0x893780&&value==255&&count==128){std::fill_n(memory+start,count,255);++cost_scratch_clears;}
        else{check(value==0&&((start==0x83e550&&count==0x5200)||(start==0x83e540&&count==16)));std::fill_n(memory+start,count,0);++clears;}
        SET_GPR_U32(context,2,start);context->pc=GPR_U32(context,31);return;}
#include "dispatch.inc"
    default:throw std::runtime_error("Unexpected navigation original port "+std::to_string(context->pc));
    }
}
#endif
int main(int argc,char** argv){
    try{
#ifdef REO_NAVIGATION_ORIGINAL
        check(argc==8);const auto constants=read(argv[2]);for(std::size_t at=0;at<constants.size();){const auto address=word(constants,at),count=word(constants,at+4);at+=8;check(at+count<=constants.size()&&address<=memory.size()&&count<=memory.size()-address);std::copy_n(constants.begin()+at,count,memory.begin()+address);at+=count;}const auto overlay=read(argv[1]);check(overlay.size()==113152);std::copy(overlay.begin(),overlay.end(),memory.begin()+0x810000);
#endif
        contracts();bank_contracts();condition_contracts();link_contracts();edge_contracts();ranked_contracts();cost_contracts();graph_cost_contracts();local_contracts();collection_contracts();cross_room_contracts();actor_route_contracts();destination_contracts();visibility_contracts();scene_candidate_contracts();scene_lookup_contracts();
#ifdef REO_NAVIGATION_ORIGINAL
        for(int i=3;i<argc;++i)owned(argv[i]);
        check(asset_rooms==166&&asset_nodes==3334&&asset_conditions==2167&&asset_links==432);
#else
        for(int i=1;i<argc;++i)owned(argv[i]);
#endif
        std::cout<<"{\"checks\":"<<checks<<",\"nearest_cases\":"<<nearest_cases<<",\"action_cases\":"<<action_cases<<",\"asset_rooms\":"<<asset_rooms<<",\"asset_nodes\":"<<asset_nodes<<",\"asset_conditions\":"<<asset_conditions<<",\"asset_links\":"<<asset_links<<",\"refusals\":"<<refusals<<",\"nearest_refusals\":"<<nearest_refusals<<",\"action_refusals\":"<<action_refusals<<",\"bindings\":"<<bindings<<",\"clears\":"<<clears<<",\"bank_cells\":"<<bank_cells<<",\"bank_visit_cells\":"<<bank_visit_cells<<",\"bank_clears\":"<<bank_clears<<",\"condition_cases\":"<<condition_cases<<",\"link_cases\":"<<link_cases<<",\"link_refusals\":"<<link_refusals<<",\"edge_cases\":"<<edge_cases<<",\"edge_refusals\":"<<edge_refusals<<",\"retail_edge_refusals\":"<<retail_edge_refusals<<",\"edge_flag_bindings\":"<<edge_flag_bindings<<",\"ranked_cases\":"<<ranked_cases<<",\"ranked_refusals\":"<<ranked_refusals<<",\"ranked_retail_refusals\":"<<ranked_retail_refusals<<",\"cost_cases\":"<<cost_cases<<",\"cost_refusals\":"<<cost_refusals<<",\"cost_budgets\":"<<cost_budgets<<",\"cost_retail_refusals\":"<<cost_retail_refusals<<",\"cost_retail_budgets\":"<<cost_retail_budgets<<",\"cost_maximum_work\":"<<cost_maximum_work<<",\"cost_scratch_clears\":"<<cost_scratch_clears<<",\"local_cases\":"<<local_cases<<",\"local_refusals\":"<<local_refusals<<",\"local_budgets\":"<<local_budgets<<",\"local_retail_refusals\":"<<local_retail_refusals<<",\"local_retail_budgets\":"<<local_retail_budgets<<",\"collection_cases\":"<<collection_cases<<",\"collection_entries\":"<<collection_entries<<",\"collection_refusals\":"<<collection_refusals<<",\"collection_unknown_costs\":"<<collection_unknown_costs<<",\"collection_retail_refusals\":"<<collection_retail_refusals<<",\"collection_retail_unknown_costs\":"<<collection_retail_unknown_costs<<",\"cross_search_cases\":"<<cross_search_cases<<",\"cross_route_cases\":"<<cross_route_cases<<",\"cross_refusals\":"<<cross_refusals<<",\"cross_corrected_cases\":"<<cross_corrected_cases<<",\"cross_retail_cases\":"<<cross_retail_cases<<",\"actor_route_cases\":"<<actor_route_cases<<",\"actor_action_cases\":"<<actor_action_cases<<",\"actor_route_refusals\":"<<actor_route_refusals<<",\"actor_route_corrected_cases\":"<<actor_route_corrected_cases<<",\"actor_route_retail_cases\":"<<actor_route_retail_cases<<",\"destination_cases\":"<<destination_cases<<",\"destination_refusals\":"<<destination_refusals<<",\"destination_corrected_cases\":"<<destination_corrected_cases<<",\"destination_retail_cases\":"<<destination_retail_cases<<",\"visibility_cases\":"<<visibility_cases<<",\"visible_nearest_cases\":"<<visible_nearest_cases<<",\"visibility_refusals\":"<<visibility_refusals<<",\"visibility_retail_cases\":"<<visibility_retail_cases<<",\"node_policy_cases\":"<<node_policy_cases<<",\"node_choice_cases\":"<<node_choice_cases<<",\"node_choice_refusals\":"<<node_choice_refusals<<",\"graph_cost_cases\":"<<graph_cost_cases<<",\"graph_cost_refusals\":"<<graph_cost_refusals<<",\"graph_admission_maximum\":"<<graph_admission_maximum<<",\"graph_relaxation_maximum\":"<<graph_relaxation_maximum<<",\"graph_scan_maximum\":"<<graph_scan_maximum<<",\"graph_retail_admitted\":"<<graph_retail_admitted<<",\"graph_retail_equivalent\":"<<graph_retail_equivalent<<",\"graph_retail_new\":"<<graph_retail_new<<",\"graph_retail_refused\":"<<graph_retail_refused<<",\"graph_original_extended\":"<<graph_original_extended<<",\"graph_original_limited\":"<<graph_original_limited<<",\"graph_original_total_entries\":"<<graph_original_total_entries<<",\"graph_original_per_query_limited\":"<<graph_original_per_query_limited<<",\"graph_original_global_limited\":"<<graph_original_global_limited<<",\"graph_guard_self_tests\":"<<graph_guard_self_tests<<",\"graph_original_limited_queries\":[";
        for(std::size_t i=0;i<graph_original_limit_rows.size();++i){if(i)std::cout<<',';std::cout<<'[';for(unsigned j=0;j<10;++j){if(j)std::cout<<',';std::cout<<graph_original_limit_rows[i][j];}std::cout<<']';}
        std::cout<<"],\"api_graph_cases\":"<<api_graph_cases<<",\"local_api_graph_cases\":"<<local_api_graph_cases<<",\"api_graph_work_maximum\":"<<api_graph_work_maximum<<",\"api_graph_vertex_maximum\":"<<api_graph_vertex_maximum<<",\"original_extended_by_kind\":[";
        for(unsigned i=0;i<3;++i){if(i)std::cout<<',';std::cout<<original_extended_by_kind[i];}std::cout<<"],\"original_limited_by_kind\":[";
        for(unsigned i=0;i<3;++i){if(i)std::cout<<',';std::cout<<original_limited_by_kind[i];}std::cout<<"],\"scene_candidate_cases\":"<<scene_candidate_cases<<",\"scene_actor_cases\":"<<scene_actor_cases<<",\"scene_candidate_refusals\":"<<scene_candidate_refusals<<",\"scene_lookup_cases\":"<<scene_lookup_cases<<",\"scene_global_lookup_cases\":"<<scene_global_lookup_cases<<",\"scene_lookup_refusals\":"<<scene_lookup_refusals<<"}\n";
    }catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
}
