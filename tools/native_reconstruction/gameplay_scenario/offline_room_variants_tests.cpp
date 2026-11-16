#include "game/native/gameplay_scenario/room_variant_commands.hpp"
#include "game/native/gameplay_scenario/flags.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;namespace n=reo::native::gameplay_navigation;
namespace {
unsigned checks{},calls{},dispatches{},refusals{},cold_cases{},warm_cases{},authored{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Offline variants check at "+std::to_string(at.line()));
}
template<class T>void put(std::vector<std::byte>& bytes,unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
using Bytes=std::vector<std::uint8_t>;
std::uint32_t word(std::span<const std::uint8_t> bytes,unsigned at){std::uint32_t value;std::memcpy(&value,bytes.data()+at,4);return value;}
std::shared_ptr<const s::Program> program(std::uint32_t room,std::uint32_t value,bool prefix=false,s::DispatchProfile profile=s::DispatchProfile::offline_actor){
    std::vector<std::byte> bytes(prefix?40:24);put(bytes,0,1u);unsigned at=4;
    if(prefix){put(bytes,at,0x02000110u);put(bytes,at+4,0u);put(bytes,at+8,77u);at+=16;}
    put(bytes,at,0x0200005au);put(bytes,at+4,room);put(bytes,at+8,value);put(bytes,at+16,0xau);
    return std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
}
struct Fixture {
    std::shared_ptr<w::Session> session=std::make_shared<w::Session>();
    w::World world{{{w::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session};s::FlagState flags;
    n::Bank& bank=world.navigation();Bytes memory=Bytes(0x900000);
    std::uint32_t original(std::uint32_t pc,std::uint32_t first=0){
        R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,first);
        SET_GPR_U32(&context,29,0x8f0000);SET_GPR_U32(&context,31,0x100);
        original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x100);++calls;return GPR_U32(&context,2);
    }
    void cold(){
        session->room_variants.restore(std::array<std::uint8_t,128>{});check(bank.initialize_cold_empty());check(!bank.bound()&&!bank.asset());
    }
    s::TickResult run(std::uint32_t room,std::uint32_t value,s::OfflineDispatch dispatch={0,0,0}){
        s::Interpreter interpreter;check(interpreter.install(0,program(room,value))==s::Status::completed);
        s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&flags;++dispatches;
        return interpreter.tick_offline_channel(0,{true,false,0},dispatch,providers);
    }
    void compare(std::uint32_t room,std::uint32_t value,bool empty,const n::Asset* asset=nullptr,s::OfflineDispatch dispatch={0,0,0}){
        for(unsigned i=0;i<128;++i){check(session->room_variants.get(i).has_value());memory[0x4b9d20+i]=*session->room_variants.get(i);}
        transform_write(memory.data(),0x10000,room);transform_write(memory.data(),0x10004,value);
        check(original(0x701840,0x10000)==0);check(run(room,value,dispatch).status==s::Status::yielded);
        for(unsigned i=0;i<128;++i)check(session->room_variants.get(i)==memory[0x4b9d20+i]);
        check(memory[0x4b9d1f]==0&&memory[0x4b9da0]==0);
        for(unsigned i=0;i<128;++i){
            const auto entry=0x83e550+164*i;const auto graph=bank.room(i);check(word(memory,entry)==unsigned(bool(graph)));
            if(empty){check(!graph&&!bank.occupancy(i,0));check(std::all_of(memory.begin()+entry,memory.begin()+entry+164,[](auto b){return b==0;}));continue;}
            check(asset&&graph==asset->find_room(std::int32_t(i),std::int32_t(*session->room_variants.get(i))));
            if(graph){
                const auto offset=graph->source_offset(),base=0x843780+offset;
                check(word(memory,entry+8)==graph->nodes().size()&&word(memory,entry+12)==base+12&&word(memory,entry+16)==base+12+64*graph->nodes().size());
                check(word(memory,entry+0x94)==base+word(graph->encoding(),4)&&word(memory,entry+0x98)==graph->conditions().size());
                check(word(memory,entry+0x9c)==base+word(graph->encoding(),0)+8&&word(memory,entry+0xa0)==base+word(graph->encoding(),0));
                unsigned descriptor{};for(unsigned j=0;j<asset->descriptors().size();++j){const auto& d=asset->descriptors()[j];if(d.room==std::int32_t(i)&&d.variant==std::int32_t(*session->room_variants.get(i)))descriptor=j;}
                check(word(memory,entry+4)==descriptor);
                const auto native_flags=bank.edge_flags(i);check(bool(native_flags));for(unsigned j=0;j<4;++j)check((*native_flags)[j]==memory[base+word(graph->encoding(),0)+j]);
            }
            for(unsigned node=0;node<128;++node)check(bank.occupancy(i,node)==memory[entry+0x14+node]);
        }
        if(empty){check(!bank.bound()&&bank.header_byte()==0&&bank.refresh_source_ready());check(word(memory,0x83e540)==0);++cold_cases;}
        else{check(bank.bound());++warm_cases;}
    }
};
void cold_contracts(){
    for(const auto room:{0u,7u,127u})for(const auto value:{0u,1u,255u,256u,257u,0xffffffffu,0xffffff80u}){
        Fixture fixture;fixture.cold();fixture.compare(room,value,true);
        (void)fixture.original(0x8194f0,0);check(fixture.bank.clear_actor_visits(0));check(!fixture.bank.initialize_cold_empty());
    }
    const std::array commands{
#include "authored_commands.inc"
    };
    for(const auto& command:commands){Fixture fixture;fixture.cold();fixture.compare(command[0],command[1],true);++authored;}
    for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<3;++relation){
        Fixture fixture;fixture.cold();
        if(category<2)fixture.compare(7,255,true,nullptr,{category,relation,0});
        else{check(fixture.run(7,255,{category,relation,0}).status==s::Status::yielded);check(fixture.session->room_variants.get(7)==0);}
    }
}
void warm_contracts(const char* path){
    std::ifstream stream(path,std::ios::binary);check(bool(stream));Bytes bytes{std::istreambuf_iterator<char>(stream),{}};
    check(0x843780+bytes.size()<0x8e0000); // Original stack is outside every owned SGL.
    n::ImportFailure failure;auto decoded=n::Asset::read(bytes,failure);check(bool(decoded));const auto asset=std::make_shared<const n::Asset>(std::move(*decoded));
    Fixture fixture;fixture.session->room_variants.restore(std::array<std::uint8_t,128>{});check(fixture.bank.bind(asset));check(!fixture.bank.initialize_cold_empty());
    std::copy(bytes.begin(),bytes.end(),fixture.memory.begin()+0x843780);
    const auto links=unsigned(asset->links().size());const auto a=word(bytes,4),visits=a+4+12*links+((links*links+3)&~3u);
    for(unsigned actor=0;actor<4;++actor)for(unsigned link=0;link<links;++link){const auto value=std::uint8_t(actor*17+link*7);check(fixture.bank.visit(actor,link,value));fixture.memory[0x843780+visits+actor*links+link]=value;}
    for(unsigned room=0;room<128;++room)if(const auto graph=fixture.bank.room(room)){
        const std::array<std::uint8_t,4> flags{std::uint8_t(graph->source_offset()),37,128,255};check(fixture.bank.edge_flags(room,flags));
        std::copy(flags.begin(),flags.end(),fixture.memory.begin()+0x843780+graph->source_offset()+word(graph->encoding(),0));
    }
    check(fixture.bank.clear_header_byte());fixture.memory[0x843780]=0;
    const Bytes saved(fixture.memory.begin()+0x843780,fixture.memory.begin()+0x843780+bytes.size());
    for(const auto room:{0u,7u,127u})for(const auto value:{0u,1u,255u,256u,257u,0xffffffffu,0xffffff80u}){
        for(unsigned i=0;i<128;++i)for(unsigned node=0;node<128;++node)check(fixture.bank.occupancy(i,node,0x6d));
        std::fill_n(fixture.memory.begin()+0x83e550,128*164,0x6d);std::fill_n(fixture.memory.begin()+0x83e540,16,0x6d);
        fixture.compare(room,value,false,asset.get());
        check(std::equal(saved.begin(),saved.end(),fixture.memory.begin()+0x843780));check(fixture.bank.header_byte()==0);
        check(word(fixture.memory,0x83e540)==links&&word(fixture.memory,0x83e544)==0x843780+a+4);
        check(word(fixture.memory,0x83e548)==0x843780+a+4+12*links&&word(fixture.memory,0x83e54c)==0x843780+visits);
        for(unsigned actor=0;actor<4;++actor){const auto native=fixture.bank.visits(actor);check(native.size()==links);for(unsigned link=0;link<links;++link)check(native[link]==fixture.memory[0x843780+visits+actor*links+link]);}
    }
    fixture.bank.clear_rooms();check(!fixture.bank.bound()&&fixture.bank.refresh_source_ready());
    (void)fixture.original(0x815e30);(void)fixture.original(0x8194f0,0);check(fixture.bank.clear_actor_visits(0));
    check(std::equal(saved.begin(),saved.end(),fixture.memory.begin()+0x843780));fixture.compare(7,0,false,asset.get());
}
void refusals_and_prefixes(const char* path){
    w::World uncreated({{w::input::Remap{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<w::Session>());
    check(!uncreated.navigation_if_created()&&!s::offline_room_variant_ready(uncreated));
    check(!program(7,1)->admits_offline_room_variants(&uncreated)&&!uncreated.navigation_if_created());++refusals;
    Fixture unknown;check(!unknown.bank.refresh_source_ready()&&!unknown.bank.refresh_rooms_mode_two());
    s::Interpreter interpreter;check(interpreter.install(0,program(7,1,true))==s::Status::completed);
    s::Providers providers;providers.world=&unknown.world;providers.flags=providers.canonical_flags=&unknown.flags;
    check(interpreter.tick_offline_channel(0,{}, {0,0,0},providers).status==s::Status::provider_unavailable);check(!unknown.session->room_variants.get(7)&&interpreter.counters()[0]==0);++refusals;
    for(const auto room:{128u,256u,0xffffffffu}){bool rejected{};try{(void)program(room,1);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;}
    Fixture cold;cold.cold();cold.bank.close();check(!cold.bank.initialize_cold_empty()&&!cold.bank.refresh_rooms_mode_two());check(!s::set_offline_room_variant(cold.world,7,1)&&cold.session->room_variants.get(7)==0);++refusals;
    std::ifstream stream(path,std::ios::binary);Bytes bytes{std::istreambuf_iterator<char>(stream),{}};n::ImportFailure failure;auto decoded=n::Asset::read(bytes,failure);check(bool(decoded));
    Fixture warm;warm.session->room_variants.restore(std::array<std::uint8_t,128>{});const auto asset=std::make_shared<const n::Asset>(std::move(*decoded));check(warm.bank.bind(asset));
    const auto first=std::find_if(asset->descriptors().begin(),asset->descriptors().end(),[](const auto& d){return d.variant>=0&&d.variant<=255;});check(first!=asset->descriptors().end());
    check(asset->links().size()>0&&warm.bank.visit(0,0,0x77));check(warm.bank.occupancy(7,0,99));
    warm.session->room_variants=reo::native::gameplay_session::RoomVariants{};
    check(warm.session->room_variants.store(std::uint32_t(first->room),std::uint32_t(first->variant)));
    check(!s::set_offline_room_variant(warm.world,127,0x1234));check(warm.session->room_variants.get(127)==0x34);check(warm.bank.occupancy(7,0)==0);check(warm.bank.refresh_source_ready());
    //815E30 has cleared global link views, while earlier descriptor stores
    // have already published their room graph and flag pointer.
    check(warm.bank.bound()&&!warm.bank.asset()&&warm.bank.visits(0).empty()&&!warm.bank.visit(0,0,1));
    check(warm.bank.room(std::uint32_t(first->room))&&warm.bank.current_variant(std::uint32_t(first->room))==first->variant);
    const std::array<std::uint8_t,4> retained_flags{4,3,2,1};check(warm.bank.edge_flags(std::uint32_t(first->room),retained_flags));
    check(warm.bank.occupancy(std::uint32_t(first->room),0,3)&&warm.bank.clear_actor_visits(0));
    check(warm.bank.occupancy(std::uint32_t(first->room),0)==2);
    warm.session->room_variants.restore(std::array<std::uint8_t,128>{});check(warm.session->room_variants.store(std::uint32_t(first->room),std::uint32_t(first->variant)));
    check(warm.bank.refresh_rooms_mode_two()&&warm.bank.asset()==asset.get()&&warm.bank.visits(0)[0]==0x77);
    check(warm.bank.edge_flags(std::uint32_t(first->room))==retained_flags);++refusals;
    check(warm.world.close()==w::Status::completed);check(!s::set_offline_room_variant(warm.world,127,1));++refusals;
    // Ordinary68ECA0 remains the store-only handler and does not need SGL authority.
    s::Interpreter ordinary;check(ordinary.install(0,program(7,1,false,s::DispatchProfile::ordinary))==s::Status::completed);
    check(ordinary.tick(0,{},providers).status==s::Status::yielded&&unknown.session->room_variants.get(7)==1&&!unknown.bank.refresh_source_ready());
}
}
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    switch(c->pc){
#include "original_lookup.inc"
    case 0x107c68:std::memset(m+GPR_U32(c,4),int(GPR_U32(c,5)),GPR_U32(c,6));SET_GPR_U32(c,2,GPR_U32(c,4));c->pc=GPR_U32(c,31);return;
    default:throw std::runtime_error("Unexpected offline variant callback "+std::to_string(c->pc));
    }
}
int main(int argc,char** argv)try{
    check(argc==6);cold_contracts();for(int i=1;i<argc;++i)warm_contracts(argv[i]);refusals_and_prefixes(argv[1]);
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"dispatches\":"<<dispatches<<",\"cold_cases\":"<<cold_cases<<",\"warm_cases\":"<<warm_cases<<",\"refusals\":"<<refusals<<",\"authored_records\":"<<authored<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
