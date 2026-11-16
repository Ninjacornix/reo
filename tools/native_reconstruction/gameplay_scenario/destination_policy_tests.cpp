#include "game/native/gameplay_scenario/actor_ai_policy.hpp"
#include "game/native/gameplay_scenario/interpreter.hpp"
#include "game/native/gameplay_scenario/scene_resources.hpp"
#include "game/native/gameplay_ai/goal_route.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "reference.hpp"
#include "functions.h"
#include "authored_command.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <string>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
namespace nav=reo::native::gameplay_navigation;namespace ai=reo::native::gameplay_ai;
namespace u=reo::native::gameplay_update;
namespace {
using Bytes=std::vector<std::uint8_t>;
std::uint64_t checks{},calls{},commands{},weighted{},goals{},refusals{},authored{},continuations{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Destination policy check "+std::to_string(at.line()));
}
template<class T>void put(Bytes& bytes,unsigned at,T value){check(at+sizeof(T)<=bytes.size());std::memcpy(bytes.data()+at,&value,sizeof value);}
w::Profile profile(){w::Profile result;result.layouts.push_back({});return result;}
struct Notes final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
Bytes graph_asset(unsigned room=1,unsigned variant=0){
    constexpr unsigned count=5,start=56,tail=12+64*count+4*count*count,directory=tail+8;
    Bytes b(start+directory+64);put(b,0,0x20030724u);put(b,4,12u);put(b,8,16u);put(b,12,0u);put(b,16,3u);
    for(unsigned i=0;i<3;++i){put(b,20+12*i,std::uint16_t(room));put(b,22+12*i,i==2?std::uint16_t(65535):std::uint16_t(variant));put(b,24+12*i,start);put(b,28+12*i,i==1?3u:0u);}
    put(b,start,tail);put(b,start+4,directory);put(b,start+8,count);
    for(unsigned n=0;n<count;++n){const auto at=start+12+64*n;b[at]=1;b[at+1]=4;
        put(b,at+4,float(100*n));put(b,at+8,0.f);put(b,at+12,300.f);put(b,at+16,0xffffffffu);
        unsigned slot{};for(unsigned other=0;other<count;++other)if(other!=n){b[at+20+slot]=std::uint8_t(other);put(b,at+24+2*slot,std::uint16_t(1));put(b,at+36+2*slot,std::uint16_t(100));++slot;}
        for(unsigned p=0;p<4;++p)b[at+32+p]=std::uint8_t(1+((n+1)*(p+1))%13);
    }
    for(unsigned a=0;a<count;++a)for(unsigned d=0;d<count;++d){const auto at=start+12+64*count+4*(d*count+a);
        b[at]=a==d?255:std::uint8_t(d-(d>a?1:0));b[at+1]=b[at+2]=b[at+3]=255;}
    return b;
}
struct Fixture;Fixture* running{};
struct Fixture {
    Notes notes;std::shared_ptr<w::Session> session=std::make_shared<w::Session>();w::World world{profile(),session};u::Owner owner{world,notes};
    s::SceneResources resources;Bytes memory=Bytes(0x2000000),asset_bytes,expected_records;std::shared_ptr<const nav::Asset> asset;std::string diagnostic;
    Fixture(const Bytes& constants){check(!running);running=this;
        for(std::size_t at=0;at<constants.size();){check(at+8<=constants.size());unsigned target{},n{};std::memcpy(&target,constants.data()+at,4);std::memcpy(&n,constants.data()+at+4,4);at+=8;check(at+n<=constants.size()&&target+n<memory.size());std::memcpy(memory.data()+target,constants.data()+at,n);at+=n;}
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->ai_execution.emplace();actor->navigation_route.emplace();actor->active=true;actor->slot=std::uint8_t(i);actor->character=std::uint8_t(i);actor->ai_control=1;
            check(world.spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);}
        bind(1,0);
    }
    ~Fixture(){running=nullptr;}
    template<class T>void write(unsigned at,T value){put(memory,at,value);}
    template<class T>T get(unsigned at)const{return transform_read<T>(memory.data(),at);}
    unsigned call(unsigned pc,std::array<unsigned,4> args={}){
        R5900Context c;PS2Runtime runtime;c.pc=pc;for(unsigned i=0;i<4;++i)SET_GPR_U32(&c,4+i,args[i]);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);
        original_transform_port(memory.data(),&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);++calls;return GPR_U32(&c,2);
    }
    void bind(unsigned room,unsigned variant){asset_bytes=graph_asset(room,variant);nav::ImportFailure failure;const auto parsed=nav::Asset::read(asset_bytes,failure);check(bool(parsed));asset=std::make_shared<const nav::Asset>(*parsed);
        std::array<std::uint8_t,128> variants{};variants.at(room)=std::uint8_t(variant);session->room_variants.restore(variants);check(world.navigation().bind(asset));
        std::copy(asset_bytes.begin(),asset_bytes.end(),memory.begin()+0x843780);std::copy(variants.begin(),variants.end(),memory.begin()+0x4b9d20);call(0x815e70,{2});
        world.room=std::uint16_t(room);write(0x3243dc,std::uint16_t(room));
        for(unsigned i=0;i<8;++i){auto a=world.primary(i);a->room=std::uint16_t(room);a->position={0,0,300};a->motion_class=0;*a->navigation_route={};a->navigation_route->current_node=0;}
    }
    void project(Bytes& target,unsigned at,const w::Actor& actor){
        put(target,at,std::uint8_t(actor.active?128:0));put(target,at+3,actor.slot);put(target,at+0x1e2,actor.room);
        put(target,at+0x38,actor.position);put(target,at+0x54f,actor.motion_class);put(target,at+0xb98,actor.character);
        put(target,at+0xba0,actor.status);put(target,at+0xba4,actor.auxiliary_status);put(target,at+0xff0,actor.ai_control);put(target,at+0x10a9,actor.transient_marker);
        if(actor.ai_execution){const auto& x=*actor.ai_execution;
            put(target,at+0xff1,x.inhibited);put(target,at+0xff2,x.steering_button_10);put(target,at+0xff3,x.steering_button_20);
            put(target,at+0xff4,x.goal);put(target,at+0xff6,x.previous_goal);put(target,at+0xff8,x.action);put(target,at+0xffa,x.previous_action);
            for(unsigned i=0;i<4;++i){put(target,at+0xffc+i,x.goal_phases[i]);put(target,at+0x1000+2*i,x.goal_parameters[i]);put(target,at+0x1008+i,x.action_phases[i]);}
            put(target,at+0x1034,x.action_counter);put(target,at+0x103a,x.action_marker);put(target,at+0x1070,x.observation_cooldown);put(target,at+0x1074,x.goal_refresh);
            put(target,at+0x1078,x.health_band_1078);put(target,at+0x1079,x.previous_health_band_1079);put(target,at+0x107a,x.gauge_band_107a);put(target,at+0x107b,x.previous_gauge_band_107b);
            put(target,at+0x107e,x.room_reaction_gate);put(target,at+0x107f,x.previous_room_reaction_gate);put(target,at+0x1080,x.reference_request);put(target,at+0x1083,x.observation_flags);put(target,at+0x108a,x.owned_request);
            put(target,at+0x106c,x.threat_band);put(target,at+0x106d,x.previous_threat_band);
        }
        if(actor.navigation_route){const auto& r=*actor.navigation_route;
            put(target,at+0x100c,r.current_node);put(target,at+0x100d,r.destination_node);put(target,at+0x100e,r.output.route.first);put(target,at+0x100f,r.output.route.second);
            put(target,at+0x1010,r.final_position);put(target,at+0x101c,r.output.route.first_position);put(target,at+0x1028,r.output.route.second_position);
            put(target,at+0x1054,r.previous_action);put(target,at+0x1056,r.action);put(target,at+0x1058,r.destination_room);put(target,at+0x105a,r.completed);put(target,at+0x105b,r.selection_mode);put(target,at+0x1064,r.refresh);put(target,at+0x1065,r.last_current_node);put(target,at+0x10aa,r.output.link);
        }
    }
    void project_all(){for(unsigned i=0;i<8;++i){const auto at=0x4a5c30+0x10e0*i;std::fill_n(memory.begin()+at,0x10e0,0xa5);project(memory,at,*world.primary(i));}
        expected_records.assign(memory.begin()+0x4a5c30,memory.begin()+0x4a5c30+8*0x10e0);}
    void compare(){Bytes expected=expected_records;
        for(unsigned i=0;i<8;++i)project(expected,0x10e0*i,*world.primary(i));
        if(std::memcmp(expected.data(),memory.data()+0x4a5c30,expected.size()))for(unsigned i=0;i<expected.size();++i)if(expected[i]!=memory[0x4a5c30+i]){std::cerr<<diagnostic<<" Actor difference offset="<<std::hex<<i<<" native="<<unsigned(expected[i])<<" original="<<unsigned(memory[0x4a5c30+i])<<std::dec<<'\n';break;}
        check(!std::memcmp(expected.data(),memory.data()+0x4a5c30,expected.size()));
        const auto n=get<unsigned>(0x843780+8);for(unsigned i=0;i<asset->descriptors().size();++i){const auto& d=asset->descriptors()[i];
            // Lookup observes FIRST duplicate only; compare each unique key.
            if(i&&d.room==asset->descriptors()[0].room&&d.variant==asset->descriptors()[0].variant)continue;
            check(world.navigation().descriptor_policy(d.room,d.variant)==get<unsigned>(0x843780+n+4+12*i+8));}
        check(session->random.state().primary==get<std::uint16_t>(0x3244b0));
    }
    void random(unsigned value){session->random.restore({std::uint16_t(value),19,0});write(0x3244b0,std::uint16_t(value));write(0x3244b8,std::uint16_t(19));}
    void command(std::array<unsigned,3> args,bool offline=true){
        project_all();std::vector<std::byte> b(24);const std::array<unsigned,6> words{1,0x20001a0,args[0],args[1],args[2],0xa};std::memcpy(b.data(),words.data(),b.size());
        const auto p=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{b},offline?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary);
        s::Interpreter vm;check(vm.install(0,p)==s::Status::completed);s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&owner.flags();
        const auto result=offline?vm.tick_offline_channel(0,{true,false,0,world.room},{0,0,world.room},providers):vm.tick(0,{},providers);check(result.status==s::Status::yielded);
        if(offline){for(unsigned i=0;i<3;++i)write(0x10000+4*i,args[i]);check(call(0x702620,{0x10000})==0);}
        compare();++commands;
    }
    void goal(){project_all();const auto before=session->random.state();write(0x3244b0,before.primary);write(0x3244b8,before.secondary);
        const auto a=world.primary(1);const auto& x=*a->ai_execution;diagnostic="goal phase="+std::to_string(x.goal_phases[0])+" action="+std::to_string(x.action)+" remaining="+std::to_string(x.goal_parameters[1])+" policy="+std::to_string(world.navigation().descriptor_policy(1,0).value_or(999))+" seed="+std::to_string(before.primary)+" completed="+std::to_string(a->navigation_route->completed);
        const auto id=world.identity(1);check(bool(id));const auto result=owner.dispatch_ai_goal(id,resources);check(result.status==ai::Status::completed&&result.selected==1);
        check(call(0x813df0,{0x4a5c30+0x10e0})==0);compare();++goals;
    }
    void continuation(){project_all();auto a=world.primary(1);nav::RoomFlags flags;flags.fill(0);
        const nav::RouteActorFacts facts{{a->character,a->slot,a->ai_control},a->status,a->auxiliary_status,a->room,
            {a->position.x,a->position.y,a->position.z},a->motion_class,a->transient_marker};
        const auto result=nav::continue_actor_route(world.navigation(),facts,world.room,flags,*a->navigation_route);
        check(result.status==nav::QueryStatus::completed);
        check(result.selected==std::bit_cast<std::int32_t>(call(0x816c10,{0x4a5c30+0x10e0})));compare();
        for(unsigned node=0;node<128;++node)check(world.navigation().occupancy(a->room,node)==get<std::uint8_t>(0x83e550+164*a->room+0x14+node));
        ++continuations;
    }
    void weighted_node(std::int32_t excluded,unsigned mode){project_all();auto a=world.primary(1);nav::RoomFlags unknown;
        const nav::RouteActorFacts facts{{a->character,a->slot,a->ai_control},a->status,a->auxiliary_status,a->room,
            {a->position.x,a->position.y,a->position.z},a->motion_class,a->transient_marker};
        const auto result=nav::weighted_destination_node(world.navigation(),facts,*a->navigation_route,excluded,a->room,mode,unknown,session->random);
        check(result.status==nav::QueryStatus::completed);
        check(result.node==std::bit_cast<std::int32_t>(call(0x816530,{0x4a5c30+0x10e0,std::uint32_t(excluded),a->room,mode})));compare();++weighted;
    }
};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unexpected destination policy original boundary "+std::to_string(context->pc));}}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream in(argv[1],std::ios::binary);const Bytes constants{std::istreambuf_iterator<char>(in),{}};check(!constants.empty());Fixture f(constants);f.random(0);
    for(const auto args:authored_commands){f.bind(args[0],args[1]);f.command(args);++authored;}
    f.bind(1,0);
    for(unsigned policy:{0u,1u,2u,3u,4u,0x7fffffffu,0x80000000u,0xffffffffu,0xffffffe0u})for(unsigned trial=0;trial<4;++trial){
        for(unsigned i=0;i<8;++i){auto a=f.world.primary(i);a->active=(trial+i)%3!=0;a->ai_control=std::uint8_t((trial+i)%4);a->status=0x5e0;auto& x=*a->ai_execution;x.goal=std::uint16_t(100+i);x.action=std::uint16_t(200+i);x.goal_parameters.fill(13);x.goal_phases.fill(7);x.action_phases.fill(8);}
        f.command({1,0,policy});f.command({0xffffffffu,0xffffffffu,4});f.command({1,0,policy},false);
    }
    f.command({1,0xffffffffu,2}); //signed-half -1 matches the complete word -1
    for(unsigned policy:{0u,1u,2u,3u,0xffffffffu,0xffffffe0u,0xffffffd4u})for(unsigned seed:{0u,1u,37u,65535u}){
        f.bind(1,0);f.command({1,0,policy});for(unsigned i=0;i<8;++i){auto a=f.world.primary(i);a->active=true;a->ai_control=1;a->status=0;*a->ai_execution={};}
        auto a=f.world.primary(1);auto& x=*a->ai_execution;x.goal=1;x.goal_refresh=0;x.goal_phases[0]=2;x.goal_parameters[1]=500;x.action=1;f.random(seed);f.goal();++weighted;
        x.goal=1;x.goal_refresh=0;x.goal_phases[0]=3;x.action=0;a->navigation_route->completed=1;f.goal();++continuations;
    }
    {auto a=f.world.primary(1);*a->ai_execution={};a->ai_execution->goal=1;a->ai_execution->goal_refresh=0;f.random(19);f.goal();f.goal();}
    {const auto before=f.world.navigation().descriptor_policy(1,0);check(!s::actor_destination_policy_ready(f.world,127,0,1));check(f.world.navigation().descriptor_policy(1,0)==before);++refusals;}
    check(!s::actor_destination_policy_ready(f.world,0x10001,0,1));check(!s::actor_destination_policy_ready(f.world,1,0x10000,1));refusals+=2;
    {w::World empty(profile(),std::make_shared<w::Session>());check(!empty.navigation_if_created());
        check(s::set_actor_destination_policy(empty,0xffffffffu,0xffffffffu,4)&&!empty.navigation_if_created());
        check(!s::set_actor_destination_policy(empty,1,0,3)&&!empty.navigation_if_created());++refusals;}
    f.bind(1,0);for(unsigned policy:{0u,1u,2u,3u,0xffffffffu,0xffffffe0u,0xffffffd4u}){
        f.command({1,0,policy});for(unsigned i=0;i<8;++i){auto a=f.world.primary(i);a->status=0;a->motion_class=0;}
        for(unsigned seed:{0u,1u,175u,65535u})for(unsigned mode:{0u,1u})for(int excluded:{-1,0,4}){f.random(seed);f.weighted_node(excluded,mode);}}
    f.bind(1,0);f.command({1,0,2});check(f.world.navigation().bind(f.asset));f.call(0x815e70,{2});check(f.world.navigation().descriptor_policy(1,0)==2);
    check(f.world.navigation().refresh_rooms_mode_two());f.call(0x815e70,{2});check(f.world.navigation().descriptor_policy(1,0)==2);
    f.world.navigation().clear_rooms();f.call(0x815e30);f.command({1,0,3});check(f.world.navigation().refresh_rooms_mode_two());f.call(0x815e70,{2});check(f.world.navigation().descriptor_policy(1,0)==3);
    for(unsigned phase:{0u,1u,255u})for(unsigned refresh:{0u,1u})for(unsigned motion:{0u,0x1au,0x21u})for(unsigned current=0;current<5;++current)for(unsigned first=0;first<5;++first)for(float offset:{0.f,49.999f,50.f,100.f}){
        auto a=f.world.primary(1);a->status=0;a->auxiliary_status=0;a->transient_marker=0;a->motion_class=std::uint8_t(motion);
        a->position={100.f*float(current)+offset,100.f,300};auto& r=*a->navigation_route;r={};r.completed=std::uint8_t(phase);r.refresh=std::uint8_t(refresh);
        r.current_node=std::int8_t(current);r.last_current_node=std::int8_t(current);r.destination_node=std::int8_t(first);r.destination_room=1;
        r.output.route.first=r.output.route.second=std::int8_t(first);r.final_position={100.f*float(first),0,300};r.output.route.first_position=r.output.route.second_position=r.final_position;
        f.continuation();
    }
    {auto a=f.world.primary(1);auto& r=*a->navigation_route;r={};r.current_node=0;
        check(f.world.navigation().descriptor_policy(1,0,0x80000000u));check(f.world.navigation().occupancy(1,0,255));
        nav::RoomFlags unknown;const nav::RouteActorFacts facts{{a->character,a->slot,a->ai_control},0,0,1,{0,0,300},0,0};const auto before=f.session->random.state();
        check(nav::weighted_destination_node(f.world.navigation(),facts,r,0,1,0,unknown,f.session->random).status==nav::QueryStatus::unavailable);
        check(f.world.navigation().occupancy(1,0)==253&&f.session->random.state()==before);++refusals;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"commands\":"<<commands<<",\"authored_commands\":"<<authored<<",\"original_calls\":"<<calls<<",\"weighted_cases\":"<<weighted<<",\"goal1_calls\":"<<goals<<",\"continuations\":"<<continuations<<",\"refusals\":"<<refusals<<"}\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
