#include "game/native/gameplay_scenario/actor_ai_policy.hpp"
#include "game/native/gameplay_scenario/actor_script_predicates.hpp"
#include "game/native/gameplay_scenario/actor_script_terminal.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_world/actor_resource_operations.hpp"
#include "reference.hpp"
#include "functions.h"
#include "authored_command.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;namespace nav=reo::native::gameplay_navigation;
namespace {
using Bytes=std::vector<std::uint8_t>;
unsigned checks{},calls{},dispatches{},predicates{},retirements{},authored{},refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Offline actor controls check "+std::to_string(at.line()));
}
template<class Buffer,class T>void put(Buffer& b,unsigned at,T value){check(at+sizeof(T)<=b.size());std::memcpy(b.data()+at,&value,sizeof value);}
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
struct Notes:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
void emit(std::vector<std::byte>& b,unsigned op,std::initializer_list<unsigned> values){
    unsigned shift{},words=1;while(words<values.size()+1){words*=2;++shift;}
    const auto begin=unsigned(b.size());b.resize(begin+4*words);put(b,begin,op|(shift<<24));
    unsigned n{};for(unsigned value:values)put(b,begin+4+4*n++,value);
}
Bytes graph_asset(){
    constexpr unsigned count=3,start=32,tail=12+64*count+4*count*count,directory=tail+8;
    Bytes b(start+directory+64);put(b,0,0x20030724u);put(b,4,12u);put(b,8,16u);put(b,16,1u);
    put(b,20,std::uint16_t(7));put(b,24,start);put(b,start,tail);put(b,start+4,directory);put(b,start+8,count);
    for(unsigned i=0;i<count;++i){const auto at=start+12+64*i;b[at]=1;put(b,at+4,float(i*100));put(b,at+12,300.f);put(b,at+16,0xffffffffu);}
    std::fill_n(b.begin()+start+12+64*count,4*count*count,255);return b;
}
struct Fixture {
    std::shared_ptr<w::Session> session=std::make_shared<w::Session>();w::World world{profile(),session};Notes notes;u::Owner owner{world,notes};
    s::ResourceTemplates templates;s::SceneResources resources;w::ResourceModels models;
    std::shared_ptr<const w::ResourceStaticAssets> assets;
    w::ResourceFrames frames;w::ResourceFactory factory;w::ResourceContents contents;w::ResourcePairs pairs;
    w::WorldInventory inventory;w::ResourceRecipes recipes;w::ActorResourceOperations operations;
    Bytes memory=Bytes(0x900000);Bytes before;
    static std::shared_ptr<const w::ResourceStaticAssets> static_assets(){std::array<std::byte,12> b{};put(b,8,12u);return w::ResourceStaticAssets::import_forest(b);}
    explicit Fixture(const Bytes& constants):assets(static_assets()),frames(world,resources,models,nullptr,{},&templates),factory(models,frames,templates,assets),
        contents(world,resources,templates,frames,factory),pairs(world,resources,templates,frames),inventory(world,resources,templates,frames),recipes(pairs,contents,inventory),operations(recipes){
        for(std::size_t at=0;at<constants.size();){unsigned dest{},n{};check(at+8<=constants.size());std::memcpy(&dest,constants.data()+at,4);std::memcpy(&n,constants.data()+at+4,4);at+=8;check(at+n<=constants.size()&&dest+n<memory.size());std::memcpy(memory.data()+dest,constants.data()+at,n);at+=n;}
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->active=true;actor->slot=std::uint8_t(i);actor->character=std::uint8_t(i);
            actor->room=7;actor->ai_control=1;actor->ai_execution.emplace();actor->navigation_route.emplace();actor->navigation_route->current_node=1;actor->position={100,0,300};
            check(bool(world.spawn_primary(i,std::move(actor)).id));}
        std::array<std::byte,32+8*24> encoded{};put(encoded,0,3u);put(encoded,4,8u);put(encoded,16,32u);
        for(unsigned i=0;i<8;++i){put(encoded,32+i*24+18,std::uint16_t(42+i));encoded[32+i*24+21]=std::byte(i%4);}
        check(templates.load(encoded));
        for(unsigned i=1;i<=8;++i){s::SceneDescriptor descriptor;descriptor.active=1;descriptor.attachment_id=std::uint16_t(41+i);descriptor.ownership_tag=1;
            descriptor.claim_tag=7;descriptor.template_index=std::uint8_t(i-1);check(bool(resources.load(i,descriptor)));}
        check(owner.actor_script_terminal().bind_resource_operations(&operations)==s::ActorScriptTerminalStatus::completed);
        nav::ImportFailure failure;const auto raw=graph_asset();const auto parsed=nav::Asset::read(raw,failure);check(bool(parsed));
        session->room_variants.restore({});check(world.navigation().bind(std::make_shared<const nav::Asset>(*parsed)));world.room=7;
        std::copy(raw.begin(),raw.end(),memory.begin()+0x200000);put(memory,0x83e55c+164*7,0x200000u+32+12);
    }
    unsigned call(unsigned pc,std::array<unsigned,3> args={}){
        R5900Context c;PS2Runtime runtime;c.pc=pc;for(unsigned i=0;i<3;++i)SET_GPR_U32(&c,4+i,args[i]);
        SET_GPR_U32(&c,29,0x8f0000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory.data(),&c,&runtime);
        check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x8f0000);++calls;return GPR_U32(&c,2);
    }
    void project(Bytes& b,unsigned at,const w::Actor& actor){
        put(b,at,std::uint8_t(actor.active?128:0));put(b,at+1,std::uint8_t(actor.visible));put(b,at+2,actor.category);put(b,at+3,actor.slot);
        put(b,at+0x38,actor.position);put(b,at+0x1e2,actor.room);put(b,at+0xb98,actor.character);put(b,at+0xba0,actor.status);put(b,at+0xba4,actor.auxiliary_status);
        put(b,at+0xc7c,actor.selected_resource);put(b,at+0xca8,actor.resource_action);put(b,at+0xc84,actor.inventory.carried);put(b,at+0xc88,actor.inventory.storage);put(b,at+0xd92,actor.pending_notice);
        put(b,at+0xff0,actor.ai_control);
        if(actor.ai_execution){const auto& x=*actor.ai_execution;put(b,at+0xff4,x.goal);put(b,at+0xff6,x.previous_goal);put(b,at+0xff8,x.action);put(b,at+0xffa,x.previous_action);
            put(b,at+0xffc,x.goal_phases);put(b,at+0x1000,x.goal_parameters);put(b,at+0x1008,x.action_phases);put(b,at+0x103a,x.action_marker);put(b,at+0x1074,x.goal_refresh);
            put(b,at+0x109c,x.forced_priority);put(b,at+0x10a0,x.forced_content);}
        if(actor.navigation_route)put(b,at+0x100c,actor.navigation_route->current_node);
    }
    void project_all(){
        for(unsigned i=0;i<8;++i){const auto at=0x4a5c30+0x10e0*i;std::fill_n(memory.begin()+at,0x10e0,0xa5);project(memory,at,*world.primary(i));}
        before.assign(memory.begin()+0x4a5c30,memory.begin()+0x4a5c30+8*0x10e0);
        put(memory,0x4baded,world.selected_actor);put(memory,0x4bac52,session->auxiliary_resources);
        for(unsigned i=1;i<=8;++i){const auto value=*resources.get(*resources.slot(i));const auto at=0x3c5630+i*60;
            std::fill_n(memory.begin()+at,60,0);memory[at]=value.active;put(memory,at+6,value.attachment_id);put(memory,at+40,value.ownership_tag);memory[at+42]=value.claim_tag;memory[at+43]=value.template_index;}
        for(unsigned i=0;i<8;++i){put(memory,0x74bb50+24*i+18,std::uint16_t(42+i));memory[0x74bb50+24*i+21]=std::uint8_t(i%4);}
        put(memory,0x4b9a80,owner.flags().snapshot().primary);
    }
    void compare(unsigned op,unsigned selector){
        auto expected=before;for(unsigned i=0;i<8;++i)project(expected,i*0x10e0,*world.primary(i));
        // Only the low10A0 halfword has a native consumer. Source writes its
        // unconsumed high half too; compare every other projected actor byte.
        if(op==0x1a6||op==0x1a7)for(unsigned i=0;i<2;++i)expected[selector*0x10e0+0x10a2+i]=memory[0x4a5c30+selector*0x10e0+0x10a2+i];
        if(!std::equal(expected.begin(),expected.end(),memory.begin()+0x4a5c30)){
            for(unsigned i=0;i<expected.size();++i)if(expected[i]!=memory[0x4a5c30+i]){std::cerr<<"op="<<std::hex<<op<<" selector="<<selector<<" offset="<<i<<" native="<<unsigned(expected[i])<<" original="<<unsigned(memory[0x4a5c30+i])<<std::dec<<'\n';break;}}
        check(std::equal(expected.begin(),expected.end(),memory.begin()+0x4a5c30));
        check(!std::memcmp(memory.data()+0x4bac52,session->auxiliary_resources.data(),32));
        for(unsigned i=1;i<=8;++i)check(memory[0x3c5630+i*60+42]==resources.get(*resources.slot(i))->claim_tag);
    }
    s::Channel run(std::vector<std::byte> script){
        const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{script},s::DispatchProfile::offline_actor);
        s::Interpreter vm;check(vm.install(0,program)==s::Status::completed);s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&owner.flags();providers.actor_script_terminal=&owner.actor_script_terminal();
        const auto result=vm.tick_offline_channel(0,{true,false,world.selected_actor,7},{0,0,7},providers);
        if(result.status!=s::Status::yielded)std::cerr<<"VM status="<<unsigned(result.status)<<" op="<<result.opcode<<'\n';
        check(result.status==s::Status::yielded);++dispatches;return vm.channels()[0];
    }
    void command(unsigned op,std::array<unsigned,3> args){
        project_all();std::vector<std::byte> script;emit(script,1,{});if(op==0x1a6)emit(script,op,{args[0],args[1],args[2]});else emit(script,op,{args[0]});emit(script,0xa,{});
        run(script);for(unsigned i=0;i<3;++i)put(memory,0x10004+4*i,args[i]);
        check(call(op==0x1a6?0x702ad0:op==0x1a7?0x702bc0:0x702ce0,{0x10004})==0);compare(op,args[0]);if(op==0x1a9)++retirements;
    }
    void predicate(unsigned op,std::array<unsigned,3> args){
        project_all();std::vector<std::byte> script;emit(script,op,{args[0],args[1],args[2]});emit(script,0x110,{0,1});emit(script,0xe4,{});emit(script,0x110,{0,2});emit(script,0xe5,{});emit(script,0xa,{});
        // Call the complete original handler/scanner, then run the real native
        // VM through that branch. The original result identifies its exact
        // continuation; the marker and ordinal verify native flow composition.
        std::memcpy(memory.data()+0x10000,script.data(),script.size());put(memory,0x4badc1,std::uint8_t(0));put(memory,0x4bace0,0x10000u);put(memory,0x4bad58,0u);
        const auto result=call(op==0x1aa?0x702d70:0x702f90,{0x10004});
        const auto continuation=transform_read<unsigned>(memory.data(),0x4bace0);const auto ordinal=transform_read<unsigned>(memory.data(),0x4bad58);
        const bool matches=result!=2;check(matches?continuation==0x10000:continuation==0x10024);
        const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{script},s::DispatchProfile::offline_actor);s::Interpreter vm;check(vm.install(0,program)==s::Status::completed);
        s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&owner.flags();
        // Stop at the same post-handler boundary, including scanner work.
        const auto boundary=vm.tick_offline_channel(0,{true,false,0,7},{0,0,7},providers,matches?1:3);
        check(boundary.status==s::Status::budget_exhausted&&vm.channels()[0].current.offset==(matches?16:continuation-0x10000)&&vm.channels()[0].condition==ordinal);
        const auto done=vm.tick_offline_channel(0,{true,false,0,7},{0,0,7},providers);check(done.status==s::Status::yielded&&vm.counters()[0]==(matches?1:2));
        compare(op,args[0]);++dispatches;++predicates;
    }
};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unexpected offline actor original boundary "+std::to_string(context->pc));}}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream in(argv[1],std::ios::binary);const Bytes constants{std::istreambuf_iterator<char>(in),{}};check(!constants.empty());Fixture f(constants);
    for(const auto row:authored_commands){std::cerr<<"authored "<<authored<<" op="<<std::hex<<row[0]<<std::dec<<'\n';if(row[0]==0x1aa||row[0]==0x1ac)f.predicate(row[0],{row[1],row[2],row[3]});else f.command(row[0],{row[1],row[2],row[3]});++authored;}
    for(unsigned selector=0;selector<8;++selector)for(unsigned mode:{0u,1u,2u,3u,4u,0x80000000u,0xffffffffu})for(unsigned trial=0;trial<4;++trial){
        const auto actor=f.world.primary(selector);actor->active=trial!=0;actor->ai_control=std::uint8_t(trial!=1);actor->status=0x5e0;auto& x=*actor->ai_execution;
        x.goal=21;x.action=31;x.goal_phases.fill(7);x.goal_parameters.fill(13);x.action_phases.fill(9);x.action_marker=15;x.forced_content=0xbeef;x.forced_priority=6;
        f.command(0x1a6,{selector,0xdead0000u|mode,mode});f.command(0x1a7,{selector,0,0});}
    for(unsigned selector=0;selector<8;++selector)for(unsigned trial=0;trial<12;++trial){const auto actor=f.world.primary(selector);
        actor->active=trial!=0;actor->visible=true;actor->ai_control=std::uint8_t(trial!=1);actor->slot=std::uint8_t(selector);actor->category=std::uint8_t(trial==2);
        f.world.selected_actor=std::uint8_t(trial%2?selector:(selector+1)%8);actor->status=trial;actor->auxiliary_status=trial==3?0x02000000u:0;actor->selected_resource=0;actor->resource_action=123;
        actor->inventory={};if(selector<4&&trial>=4){actor->inventory.carried={1,2,3,0};actor->inventory.storage[0]=4;actor->inventory.storage[3]=5;}
        actor->character=std::uint8_t(trial%2?6:2);actor->pending_notice=0xabcd;f.session->auxiliary_resources={};
        for(unsigned i=1;i<=8;++i){auto d=*f.resources.get(*f.resources.slot(i));d.claim_tag=7;d.ownership_tag=std::uint16_t(selector+1);check(f.resources.replace(*f.resources.slot(i),d)==s::SceneStatus::completed);}
        f.command(0x1a9,{selector,0,0});}
    f.world.selected_actor=0;
    for(unsigned selector=0;selector<8;++selector)for(float distance:{0.f,29.999f,30.f,30.001f})for(unsigned trial=0;trial<4;++trial){auto actor=f.world.primary(selector);
        actor->active=trial!=0;actor->ai_control=std::uint8_t(trial!=1);actor->room=7;actor->navigation_route->current_node=1;actor->position={100+distance,0,300};
        f.predicate(0x1aa,{selector,trial==2?65543u:7u,trial==3?257u:1u});}
    for(unsigned bank:{0u,1u,2u,3u,0xffffffffu})for(unsigned bit:{0u,31u,32u,511u})for(unsigned expected:{0u,1u,2u,0x80000000u})for(bool set:{false,true}){
        if(bank<3)check(f.owner.flags().actor_flag(s::ActorFlagFamily::primary,{false,std::uint8_t(bank)},bit,set));f.predicate(0x1ac,{bank,bit,expected});}
    check(!s::set_actor_forced_policy(f.world,8,0,0,false));++refusals;
    check(!s::offline_actor_reached_node(f.world,8,7,1));++refusals;
    auto& terminal=f.owner.actor_script_terminal();check(!terminal.retire_offline_actor_ready(8)&&terminal.retire_offline_actor(8)==s::ActorScriptTerminalStatus::unavailable_owner);++refusals;
    check(terminal.bind_resource_operations(nullptr,&f.operations)==s::ActorScriptTerminalStatus::completed);
    auto actor=f.world.primary(0);actor->active=true;actor->ai_control=1;actor->category=0;actor->slot=0;const auto status=actor->status;
    check(terminal.retire_offline_actor(0)==s::ActorScriptTerminalStatus::unavailable_owner&&actor->status==status&&actor->active);++refusals;
    actor->slot=1;check(terminal.retire_offline_actor(0)==s::ActorScriptTerminalStatus::completed&&!actor->active);
    check(f.owner.close()==u::Status::completed);
    std::cout<<"{\"checks\":"<<checks<<",\"dispatches\":"<<dispatches<<",\"authored_records\":"<<authored<<",\"original_calls\":"<<calls<<",\"predicates\":"<<predicates<<",\"retirements\":"<<retirements<<",\"refusals\":"<<refusals<<"}\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
