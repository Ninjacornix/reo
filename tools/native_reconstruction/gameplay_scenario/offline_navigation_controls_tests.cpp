#include "game/native/gameplay_scenario/offline_navigation_controls.hpp"
#include "game/native/gameplay_scenario/interpreter.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "reference.hpp"
#include "functions.h"
#include "authored_command.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <string>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
namespace nav=reo::native::gameplay_navigation;namespace u=reo::native::gameplay_update;
namespace {
using Bytes=std::vector<std::uint8_t>;
std::uint64_t checks{},calls{},dispatches{},authored{},consumers{},refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Offline navigation controls check "+std::to_string(at.line()));
}
template<class T>void put(Bytes& b,unsigned at,T value){check(at+sizeof(T)<=b.size());std::memcpy(b.data()+at,&value,sizeof value);}
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
struct Notes final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
Bytes graph_asset(){
    constexpr unsigned start=44,tail=80,conditions=64,directory=tail+8+16*conditions;
    Bytes b(start+directory+64);put(b,0,0x20030724u);put(b,4,12u);put(b,8,16u);put(b,16,2u);
    for(unsigned i=0;i<2;++i){put(b,20+12*i,std::uint16_t(7+i));put(b,24+12*i,start);}
    put(b,start,tail);put(b,start+4,directory);put(b,start+8,1u);b[start+12]=1;put(b,start+28,0xffffffffu);put(b,start+tail+4,conditions);
    for(unsigned i=0;i<conditions;++i){const auto at=start+tail+8+16*i;b[at]=std::uint8_t(i%5);b[at+1]=i<32?3:2;
        constexpr unsigned ids[]{0,7,8,255};b[at+2]=std::uint8_t(ids[i%4]);b[at+3]=std::uint8_t(i/4%8);}
    return b;
}
struct Fixture {
    Notes notes;std::shared_ptr<w::Session> session=std::make_shared<w::Session>();w::World world{profile(),session};u::Owner owner{world,notes};
    s::SceneControls controls;std::vector<s::SceneControlId> ids;std::vector<s::SceneControl> initial;
    Bytes memory=Bytes(0x900000),asset_bytes=graph_asset();std::shared_ptr<const nav::Asset> asset,bound_asset;
    explicit Fixture(const Bytes& constants){
        for(std::size_t at=0;at<constants.size();){unsigned target{},n{};check(at+8<=constants.size());std::memcpy(&target,constants.data()+at,4);std::memcpy(&n,constants.data()+at+4,4);at+=8;check(at+n<=constants.size()&&target+n<memory.size());std::memcpy(memory.data()+target,constants.data()+at,n);at+=n;}
        auto actor=std::make_unique<w::Actor>();actor->active=true;actor->slot=0;actor->character=2;actor->ai_control=1;actor->room=7;
        check(bool(world.spawn_primary(0,std::move(actor)).id));memory[0x4a5c33]=0;memory[0x4a67c8]=2;memory[0x4a6c20]=1;
        nav::ImportFailure failure;const auto parsed=nav::Asset::read(asset_bytes,failure);check(bool(parsed));asset=std::make_shared<const nav::Asset>(*parsed);
        session->room_variants.restore({});world.room=7;
        for(unsigned id:{0u,7u,8u,255u,0x10007u,0xffffffffu}){
            for(unsigned mode=0;mode<5;++mode)initial.push_back({id,0x80,s::ControlTypeThree{mode,0xbeef}});
            initial.push_back({id,0x80,s::ControlTypeFour{0,99}});initial.push_back({id,0x80,s::ControlTypeFour{1,99}});
            initial.push_back({id,0x80,s::ControlOther{17}});
        }
        for(const auto& c:initial){const auto added=controls.append(c);check(bool(added));ids.push_back(*added);}
        reset();
    }
    template<class T>void write(unsigned at,T value){put(memory,at,value);}
    template<class T>T get(unsigned at)const{return transform_read<T>(memory.data(),at);}
    unsigned call(unsigned pc,std::array<unsigned,3> args={}){
        R5900Context c;PS2Runtime runtime;c.pc=pc;for(unsigned i=0;i<3;++i)SET_GPR_U32(&c,4+i,args[i]);SET_GPR_U32(&c,29,0x8f0000);SET_GPR_U32(&c,31,0xabcdef);
        original_transform_port(memory.data(),&c,&runtime);
        if(c.pc!=0xabcdef||GPR_U32(&c,29)!=0x8f0000)std::cerr<<"Original return entry="<<std::hex<<pc<<" pc="<<c.pc<<" sp="<<GPR_U32(&c,29)<<std::dec<<'\n';
        check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x8f0000);++calls;return GPR_U32(&c,2);
    }
    void project(Bytes& bytes,unsigned at,const s::SceneControl& c){put(bytes,at+0x3c,c.enabled);put(bytes,at+0x40,c.authored_id);
        if(const auto v=std::get_if<s::ControlTypeThree>(&c.body)){put(bytes,at+0x30,std::uint8_t(3));put(bytes,at+0x44,v->mode);put(bytes,at+0x58,v->parameter);}
        else if(const auto v=std::get_if<s::ControlTypeFour>(&c.body)){put(bytes,at+0x30,std::uint8_t(4));put(bytes,at+0x64,v->mode);put(bytes,at+0x44,v->selector);}
        else put(bytes,at+0x30,std::uint8_t(17));
    }
    void reset(){
        bound_asset=std::make_shared<const nav::Asset>(*asset);check(world.navigation().bind(bound_asset));
        std::copy(asset_bytes.begin(),asset_bytes.end(),memory.begin()+0x843780);std::fill_n(memory.begin()+0x4b9d20,128,0);call(0x815e70,{2});
        for(unsigned i=0;i<ids.size();++i){check(controls.replace(ids[i],initial[i])==s::ControlStatus::completed);
            const auto at=0x150000+256*i;std::fill_n(memory.begin()+at,256,0xa5);project(memory,at,initial[i]);write(at+0x28,i+1<ids.size()?at+256:0u);}
        write(0x3b5160,0x150000u);controls.enabled(true);write(0x3b5150,std::int16_t(-1));
    }
    void compare(){
        for(unsigned i=0;i<ids.size();++i){const auto at=0x150000+256*i;Bytes projected(memory.begin()+at,memory.begin()+at+256);project(projected,0,*controls.get(ids[i]));check(!std::memcmp(projected.data(),memory.data()+at,256));}
        const auto graph=world.navigation().room(7);check(graph&&graph==world.navigation().room(8));
        check(std::equal(graph->encoding().begin(),graph->encoding().end(),memory.begin()+0x843780+graph->source_offset()));
        check(std::equal(asset->find_room(7,0)->encoding().begin(),asset->find_room(7,0)->encoding().end(),asset_bytes.begin()+asset->find_room(7,0)->source_offset()));
        const auto id=world.identity(0);check(bool(id));
        for(unsigned i=0;i<graph->conditions().size();++i){
            const auto first=owner.applicable_navigation_condition(id,7,std::int32_t(i));const auto second=owner.admit_navigation_condition(id,7,std::int32_t(i));
            check(first.status==nav::QueryStatus::completed&&second.status==nav::QueryStatus::completed);
            check(first.index==std::bit_cast<std::int32_t>(call(0x81a0e0,{0x4a5c30,i,7})));
            check(second.allowed==(call(0x819220,{0x4a5c30,i,7})==1));++consumers;
        }
    }
    void run(unsigned opcode,unsigned authored_id,unsigned parameter,unsigned relation,bool enabled,unsigned category=0){
        reset();controls.enabled(enabled);write(0x3b5150,std::int16_t(enabled?-1:128));write(0x75a4b8,7u);write(0x75a4c0,relation);
        std::vector<std::byte> b(opcode==0x53?16:24);const std::array<unsigned,6> words{1,opcode==0x53?0x01000053u:0x02000058u,authored_id,opcode==0x53?0xau:parameter,0,0xa};std::memcpy(b.data(),words.data(),b.size());
        auto p=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{b},s::DispatchProfile::offline_actor);s::Interpreter vm;check(vm.install(0,p)==s::Status::completed);
        s::Providers providers;providers.world=category>=2||(!relation&&!enabled)?nullptr:&world;providers.scene_controls=relation?nullptr:&controls;
        providers.flags=providers.canonical_flags=&owner.flags();
        const auto result=vm.tick_offline_channel(0,{true,false,0,7},{category,relation,7},providers);
        if(result.status!=s::Status::yielded)std::cerr<<"VM status="<<unsigned(result.status)<<" op="<<std::hex<<opcode<<" id="<<authored_id<<" parameter="<<parameter<<std::dec<<" relation="<<relation<<" enabled="<<enabled<<" dispatch="<<dispatches<<'\n';
        check(result.status==s::Status::yielded);++dispatches;
        if(category<2){write(0x10000,authored_id);write(0x10004,parameter);check(call(opcode==0x53?0x7012c0:0x701550,{0x10000})==0);}
        compare();
    }
};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unexpected offline control original boundary "+std::to_string(context->pc));}}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream in(argv[1],std::ios::binary);const Bytes constants{std::istreambuf_iterator<char>(in),{}};check(!constants.empty());Fixture f(constants);
    for(const auto row:authored_commands){f.run(row[0],row[1],row[2],0,true);++authored;}
    for(unsigned op:{0x53u,0x58u})for(unsigned id:{0u,7u,8u,255u,0x10007u,0xffffffffu})for(unsigned parameter:{0u,0x12345678u,0xffffffffu})for(unsigned relation:{0u,1u,2u})for(bool enabled:{false,true})f.run(op,id,parameter,relation,enabled);
    for(unsigned op:{0x53u,0x58u})for(unsigned relation:{0u,1u,2u})for(unsigned category:{1u,2u,3u})f.run(op,7,17,relation,true,category);
    f.run(0x53,7,0,0,true);check(f.world.navigation().bind(f.bound_asset));f.call(0x815e70,{2});f.compare();
    check(f.world.navigation().refresh_rooms_mode_two());f.call(0x815e70,{2});f.compare();
    f.world.navigation().clear_rooms();f.call(0x815e30);check(f.world.navigation().condition_count(7)==0);
    check(s::apply_offline_navigation_control(&f.world,nullptr,7,2,true,7,17));f.write(0x75a4c0,2u);f.write(0x10000,7u);f.write(0x10004,17u);check(f.call(0x701550,{0x10000})==0);
    check(f.world.navigation().refresh_rooms_mode_two());f.call(0x815e70,{2});f.compare();
    {w::World unknown(profile(),std::make_shared<w::Session>());s::SceneControls controls;controls.enabled(false);
        check(s::apply_offline_navigation_control(nullptr,&controls,65535,0,false,7,0));
        controls.enabled(true);const auto id=controls.append({7,1,s::ControlTypeThree{0,0}});check(bool(id));
        check(!s::apply_offline_navigation_control(&unknown,&controls,7,0,false,7,0));check(controls.get(*id)->enabled==0&&!unknown.navigation_if_created());++refusals;
        check(!s::apply_offline_navigation_control(nullptr,nullptr,7,0,false,7,0));++refusals;
        unknown.navigation().clear_rooms();check(s::apply_offline_navigation_control(&unknown,nullptr,7,2,true,7,0));
    }
    std::cout<<"{\"checks\":"<<checks<<",\"dispatches\":"<<dispatches<<",\"authored_records\":"<<authored<<",\"original_calls\":"<<calls<<",\"consumer_queries\":"<<consumers<<",\"refusals\":"<<refusals<<"}\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
