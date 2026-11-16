#include "game/native/gameplay_world/actor_resource_operations.hpp"
#include "game/native/gameplay_scenario/interpreter.hpp"
#include "game/native/gameplay_scenario/flags.hpp"
#include "reference.hpp"
#include "functions.h"
#include "authored_command.hpp"
#include "priority_rows.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
namespace {
using Bytes=std::vector<std::uint8_t>;
unsigned checks{},calls{},commands{},authored{},policy_cases{},refusals{};std::string diagnostic;
void check(bool v,std::source_location where=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Offline acquisition check "+std::to_string(where.line())+" "+diagnostic);}
template<class Buffer,class T>void put(Buffer& b,unsigned at,T v){check(at+sizeof v<=b.size());std::memcpy(b.data()+at,&v,sizeof v);}
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
struct Notes:s::FlagNotifications{bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}};
struct Fixture {
    std::shared_ptr<w::Session> session=std::make_shared<w::Session>();w::World world{profile(),session};Notes notes;s::FlagState flags{&notes};
    s::SceneResources resources;s::ResourceTemplates templates;w::ResourceModels models;std::shared_ptr<const w::ResourceStaticAssets> assets;
    w::ResourceFrames frames;w::ResourceFactory factory;w::ResourceContents contents;w::ResourcePairs pairs;w::WorldInventory inventory;w::ResourceRecipes recipes;w::ActorResourceOperations operations;
    Bytes memory=Bytes(0x2000000),expected_actors,expected_resources;
    static std::shared_ptr<const w::ResourceStaticAssets> empty_assets(){std::array<std::byte,12>b{};put(b,8,12u);return w::ResourceStaticAssets::import_forest(b);}
    explicit Fixture(const Bytes& constants):assets(empty_assets()),frames(world,resources,models,nullptr,{},&templates),factory(models,frames,templates,assets),
        contents(world,resources,templates,frames,factory),pairs(world,resources,templates,frames),inventory(world,resources,templates,frames),recipes(pairs,contents,inventory),operations(recipes){
        for(std::size_t at=0;at<constants.size();){unsigned dest{},n{};std::memcpy(&dest,constants.data()+at,4);std::memcpy(&n,constants.data()+at+4,4);at+=8;check(at+n<=constants.size()&&dest+n<memory.size());std::memcpy(memory.data()+dest,constants.data()+at,n);at+=n;}
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->active=true;actor->slot=std::uint8_t(i);actor->character=std::uint8_t(i);actor->ai_control=1;check(bool(world.spawn_primary(i,std::move(actor)).id));}
        session->primary_population=8;world.room=7;
    }
    unsigned call(unsigned pc,std::array<unsigned,4> args={}){R5900Context ctx;PS2Runtime runtime;ctx.pc=pc;for(unsigned i=0;i<4;++i)SET_GPR_U32(&ctx,4+i,args[i]);SET_GPR_U32(&ctx,29,0x1e00000);SET_GPR_U32(&ctx,31,0xabcdef);
        original_transform_port(memory.data(),&ctx,&runtime);check(ctx.pc==0xabcdef&&GPR_U32(&ctx,29)==0x1e00000);++calls;return GPR_U32(&ctx,2);}
    void setup(unsigned content=0x10a,unsigned policy=0,unsigned kind=0,unsigned action=0){
        Bytes section(32+16*24);put(section,0,3u);put(section,4,16u);put(section,16,32u);
        for(unsigned i=0;i<16;++i){const auto at=32+24*i;put(section,at,i<8?policy:0u);put(section,at+18,std::uint16_t(i<8?content:std::array<unsigned,8>{10209,10208,14106,14102,17,18,19,20}[i-8]));section[at+15]=std::uint8_t(i<8?action:0);section[at+21]=std::uint8_t(i<8?kind:0);}
        check(templates.load(std::as_bytes(std::span(section))));
        for(unsigned i=0;i<256;++i){s::SceneDescriptor item;if(i>=1&&i<=8){item.active=1;item.instance_index=std::uint8_t(i);item.attachment_id=std::uint16_t(content);item.ownership_tag=1;item.template_index=std::uint8_t(i-1);item.parameter=3;}
            if(i==12){item.active=1;item.instance_index=12;item.kind=1;item.authored_id=77;item.flags=0x20200001;}
            check(bool(resources.load(i,item)));}
        for(unsigned i=0;i<8;++i){const auto actor=world.primary(i);actor->active=true;actor->ai_control=1;actor->inventory={};actor->selected_resource=actor->secondary_equipped_resource=0;actor->resource_action=19;}
        session->primary_population=8;
    }
    void project_actor(Bytes& out,unsigned at,const w::Actor& a){
        put(out,at,std::uint8_t(a.active?128:0));put(out,at+3,a.slot);put(out,at+0xb98,a.character);put(out,at+0xff0,a.ai_control);
        put(out,at+0xc84,a.inventory.carried);put(out,at+0xc88,a.inventory.storage);put(out,at+0xc7c,a.selected_resource);put(out,at+0xc7d,a.secondary_equipped_resource);put(out,at+0xca8,a.resource_action);
    }
    void project_resource(Bytes& out,unsigned at,const s::SceneDescriptor& d){
        put(out,at,d.active);put(out,at+1,d.room);put(out,at+2,d.instance_index);put(out,at+3,d.kind);put(out,at+4,d.authored_id);put(out,at+6,d.attachment_id);
        put(out,at+8,d.position);put(out,at+20,d.tilt);put(out,at+22,d.yaw);put(out,at+24,d.flags);check(!d.primary&&!d.secondary);put(out,at+28,0u);put(out,at+32,0u);
        put(out,at+36,d.parameter);put(out,at+40,d.ownership_tag);put(out,at+42,d.claim_tag);put(out,at+43,d.template_index);put(out,at+44,d.shape_profile);put(out,at+45,d.orientation_variant);put(out,at+46,d.saved_yaw);put(out,at+48,d.saved_position);
    }
    void project(){
        std::fill_n(memory.begin()+0x4a5c30,8*0x10e0,0xa5);for(unsigned i=0;i<8;++i)project_actor(memory,0x4a5c30+0x10e0*i,*world.primary(i));
        std::fill_n(memory.begin()+0x3c5630,256*60,0);for(unsigned i=0;i<256;++i)project_resource(memory,0x3c5630+60*i,*resources.get(*resources.slot(i)));
        std::memcpy(memory.data()+0x74bb50,templates.state().templates.data(),129*24);std::memcpy(memory.data()+0x74b6e0,templates.state().selectors.data(),600);
        put(memory,0x743128,std::uint32_t(resources.active_count()));put(memory,0x4baea0,std::uint8_t(session->primary_population.value_or(0)));
        expected_actors.assign(memory.begin()+0x4a5c30,memory.begin()+0x4a5c30+8*0x10e0);expected_resources.assign(memory.begin()+0x3c5630,memory.begin()+0x3c5630+256*60);
    }
    void compare(){auto actors=expected_actors,items=expected_resources;for(unsigned i=0;i<8;++i)project_actor(actors,0x10e0*i,*world.primary(i));for(unsigned i=0;i<256;++i)project_resource(items,60*i,*resources.get(*resources.slot(i)));
        const auto same=[&](const Bytes& expected,unsigned base){for(unsigned i=0;i<expected.size();++i)if(expected[i]!=memory[base+i]){std::cerr<<diagnostic<<" difference base="<<std::hex<<base<<" offset="<<i<<" native="<<unsigned(expected[i])<<" original="<<unsigned(memory[base+i])<<std::dec<<'\n';check(false);}};
        same(actors,0x4a5c30);same(items,0x3c5630);check(transform_read<unsigned>(memory.data(),0x743128)==resources.active_count());
    }
    void command(std::array<unsigned,4> args){
        project();std::vector<std::byte> script(40);const std::array<unsigned,10> words{1,0x03000175,args[0],args[1],args[2],args[3],0,0,0,0xa};std::memcpy(script.data(),words.data(),sizeof words);
        s::Interpreter vm;const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{script},s::DispatchProfile::offline_actor);check(!program->unsupported()&&vm.install(0,program)==s::Status::completed);
        s::Providers p;p.world=&world;p.flags=p.canonical_flags=&flags;p.scene_resources=&resources;p.resource_templates=&templates;p.actor_resource_operations=&operations;
        const auto result=vm.tick_offline_channel(0,{true,false,0,7},{0,0,7},p);check(result.status==s::Status::yielded);
        for(unsigned i=0;i<4;++i)put(memory,0x10000+4*i,args[i]);check(call(0x7030f0,{0x10000})==0);compare();++commands;
    }
};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unreached acquisition original port "+std::to_string(context->pc));}}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream input(argv[1],std::ios::binary);const Bytes constants{std::istreambuf_iterator<char>(input),{}};Fixture f(constants);
    for(auto args:authored_commands){f.setup();diagnostic="authored";f.command(args);++authored;}
    for(unsigned slot=0;slot<8;++slot)for(unsigned count:{0u,1u,4u,8u,128u,255u})for(unsigned gate=0;gate<3;++gate){f.setup();f.session->primary_population=count;const auto actor=f.world.primary(slot);actor->active=gate!=0;actor->ai_control=std::uint8_t(gate==2);diagnostic="175 gates";f.command({0xabcd0000u|slot,0xdead27e1u,0xcafe0001u,0xbeef0000u});}
    for(const auto row:priority_rows)for(unsigned character:{0u,6u})for(unsigned quantity:{row[1],row[2],row[1]?row[1]-1u:65535u,row[2]+1u}){
        const auto family=row[4];const unsigned flag=family<4?std::array<unsigned,4>{0x1000,0x2000,0x4000,0x8000}[family]:family==4?4:family==5?2:0;
        f.setup(row[0],flag,0,family<4?1:0);auto actor=f.world.primary(1);actor->character=std::uint8_t(character);actor->inventory.carried={1,2,3,4};
        for(unsigned i=1;i<=4;++i)actor->inventory.storage[i]=std::uint8_t(4+i);
        for(unsigned i=1;i<=8;++i){auto value=*f.resources.get(*f.resources.slot(i));value.parameter=std::bit_cast<std::int16_t>(std::uint16_t(quantity));value.ownership_tag=2;check(f.resources.replace(*f.resources.slot(i),value)==s::SceneStatus::completed);}
        diagnostic="priority content="+std::to_string(row[0])+" family="+std::to_string(family)+" character="+std::to_string(character)+" quantity="+std::to_string(quantity);f.command({1,10209,1,77});++policy_cases;
    }
    {
        f.setup();auto actor=f.world.primary(1);actor->character=1;actor->inventory.carried={1,2,3,4};
        //The descriptor's instance byte is a later destruction target.8261C0
        //queries metadata using the original inventory slot, independently.
        for(unsigned i=1;i<=4;++i){auto value=*f.resources.get(*f.resources.slot(i));value.instance_index=200;value.ownership_tag=2;check(f.resources.replace(*f.resources.slot(i),value)==s::SceneStatus::completed);}
        s::SceneDescriptor target;target.active=1;target.instance_index=200;target.template_index=200;check(bool(f.resources.load(200,target)));
        diagnostic="independent descriptor slot and instance byte";f.command({1,10209,1,0});
    }
    f.setup();f.session->primary_population.reset();check(!w::offline_actor_resource_required(f.world,1,10209));++refusals;
    check(w::offline_actor_resource_required(f.world,-1,10209)==false&&w::offline_actor_resource_required(f.world,1,-1)==false);
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"commands\":"<<commands<<",\"authored\":"<<authored<<",\"original_calls\":"<<calls<<",\"policy_cases\":"<<policy_cases<<",\"refusals\":"<<refusals<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
