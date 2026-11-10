#include "navigation.hpp"
#include "bank.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <source_location>
#include <stdexcept>
#include <string>
#ifdef REO_NAVIGATION_ORIGINAL
#include "reference.hpp"
#include "functions.h"
#endif
namespace n=reo::native::gameplay_navigation;
namespace {
std::uint64_t checks{},nearest_cases{},action_cases{},asset_nodes{},asset_conditions{},asset_rooms{},asset_links{},refusals{},bindings{},clears{},nearest_refusals{},action_refusals{},bank_cells{},bank_visit_cells{},bank_clears{};
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
std::vector<std::uint8_t> memory(0x2000000);
std::uint32_t call(unsigned pc,std::array<unsigned,4> args={}){
    R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);
}
void source_graph(const n::RoomGraph& graph){
    const auto room=std::size_t(0x83e550),data=std::size_t(0x1000000);
    std::copy(graph.encoding().begin(),graph.encoding().end(),memory.begin()+data);
    put(memory,room+8,std::uint32_t(graph.nodes().size()));put(memory,room+12,std::uint32_t(data+12));
    put(memory,room+0x9c,std::uint32_t(data+word(graph.encoding(),0)+8));
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
#else
void source_graph(const n::RoomGraph&){}
void compare_action(const n::RoomGraph&,std::int32_t){}
void compare_nearest(const n::RoomGraph&,n::Position,std::int8_t){}
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
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
    case 0x107c68:{const auto start=GPR_U32(context,4),count=GPR_U32(context,6);check(GPR_U32(context,5)==0&&((start==0x83e550&&count==0x5200)||(start==0x83e540&&count==16)));std::fill_n(memory+start,count,0);++clears;SET_GPR_U32(context,2,start);context->pc=GPR_U32(context,31);return;}
#include "dispatch.inc"
    default:throw std::runtime_error("Unexpected navigation original port "+std::to_string(context->pc));
    }
}
#endif
int main(int argc,char** argv){
    try{
#ifdef REO_NAVIGATION_ORIGINAL
        check(argc==7);const auto overlay=read(argv[1]);check(overlay.size()==113152);std::copy(overlay.begin(),overlay.end(),memory.begin()+0x810000);
#endif
        contracts();bank_contracts();
#ifdef REO_NAVIGATION_ORIGINAL
        for(int i=2;i<argc;++i)owned(argv[i]);
        check(asset_rooms==166&&asset_nodes==3334&&asset_conditions==2167&&asset_links==432);
#else
        for(int i=1;i<argc;++i)owned(argv[i]);
#endif
        std::cout<<"{\"checks\":"<<checks<<",\"nearest_cases\":"<<nearest_cases<<",\"action_cases\":"<<action_cases<<",\"asset_rooms\":"<<asset_rooms<<",\"asset_nodes\":"<<asset_nodes<<",\"asset_conditions\":"<<asset_conditions<<",\"asset_links\":"<<asset_links<<",\"refusals\":"<<refusals<<",\"nearest_refusals\":"<<nearest_refusals<<",\"action_refusals\":"<<action_refusals<<",\"bindings\":"<<bindings<<",\"clears\":"<<clears<<",\"bank_cells\":"<<bank_cells<<",\"bank_visit_cells\":"<<bank_visit_cells<<",\"bank_clears\":"<<bank_clears<<"}\n";
    }catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
}
