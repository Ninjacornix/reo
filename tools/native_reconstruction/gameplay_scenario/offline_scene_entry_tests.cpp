#include "game/native/gameplay_scenario/actor_offline_navigation.hpp"
#include "game/native/gameplay_scenario/scene_entry_requests.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "game/native/animation/playback.hpp"
#include "reference.hpp"
#include "functions.h"
#include "authored_command.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;namespace nav=reo::native::gameplay_navigation;
namespace u=reo::native::gameplay_update;namespace scene=reo::native::gameplay_scene;namespace anim=reo::native::animation;
namespace {
using Bytes=std::vector<std::uint8_t>;
unsigned checks{},calls{},commands{},geometries{},authored{},refusals{},entries{},rebindings{};std::vector<unsigned> trace;std::string diagnostic;
void check(bool value,std::source_location where=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Offline scene entry check "+std::to_string(where.line())+" "+diagnostic);}
template<class Buffer,class T>void put(Buffer& b,unsigned at,T value){check(at+sizeof value<=b.size());std::memcpy(b.data()+at,&value,sizeof value);}
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
struct Notes:s::FlagNotifications{bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}};
Bytes graph_asset(unsigned room,unsigned count=32){
    const unsigned start=32,tail=12+64*count+4*count*count,directory=tail+8;
    Bytes b(start+directory+64);put(b,0,0x20030724u);put(b,4,12u);put(b,8,16u);put(b,16,1u);put(b,20,std::uint16_t(room));put(b,24,start);
    put(b,start,tail);put(b,start+4,directory);put(b,start+8,count);
    for(unsigned i=0;i<count;++i){const auto at=start+12+64*i;b[at]=1;put(b,at+4,float(100*i));put(b,at+12,300.f);put(b,at+16,0xffffffffu);}
    std::fill_n(b.begin()+start+12+64*count,4*count*count,255);return b;
}
struct Fixture {
    std::shared_ptr<w::Session> session=std::make_shared<w::Session>();w::World world{profile(),session};Notes notes;u::Owner owner{world,notes};
    s::SceneControls controls; s::SceneModelState initial_models; s::RoomModelRemap remap{};s::SceneModels models{initial_models,remap};
    Bytes memory=Bytes(0x2000000),expected_records;
    Fixture(const Bytes& constants){
        for(std::size_t at=0;at<constants.size();){unsigned dest{},n{};std::memcpy(&dest,constants.data()+at,4);std::memcpy(&n,constants.data()+at+4,4);at+=8;check(at+n<=constants.size()&&dest+n<memory.size());std::memcpy(memory.data()+dest,constants.data()+at,n);at+=n;}
        Bytes skeleton(112);put(skeleton,4,2u);put(skeleton,8,112u);put(skeleton,16,1u);put(skeleton,20,16u);put(skeleton,28,1u);put(skeleton,36,84u);put(skeleton,48,0xffffffffu);put(skeleton,52,0xffffffffu);
        for(unsigned at:{88u,92u,96u})put(skeleton,at,1.f);
        const auto rig=anim::Skeleton::import_raw(std::as_bytes(std::span(skeleton)));
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->active=true;actor->visible=true;actor->slot=std::uint8_t(i);actor->character=std::uint8_t(i);
            actor->ai_control=1;actor->ai_execution.emplace();actor->navigation_route.emplace();actor->interaction_request.emplace();actor->color_fade.emplace();actor->room=7;actor->current=100;
            actor->model=std::make_shared<anim::Instance>(rig);actor->animation=std::make_shared<anim::Playback>(actor->model,false);actor->animation->motion=77;
            check(bool(world.spawn_primary(i,std::move(actor)).id));}
        world.room=7;world.mode=0;put(memory,0x3243dc,std::uint16_t(7));put(memory,0x3243f2,std::uint8_t(0));
        //195E50 initializes the SDK identity294E00 before these callers.
        put(memory,0x294e00,reo::native::transform_math::identity());
        auto matrix=reo::native::transform_math::identity();matrix[3]={10,20,30,1};check(models.pose(3,matrix)==s::ModelStatus::completed);
        put(memory,0x49fa10+3*64,matrix);
    }
    unsigned call(unsigned pc,std::array<unsigned,4> args={}){trace.clear();R5900Context c;PS2Runtime r;c.pc=pc;for(unsigned i=0;i<4;++i)SET_GPR_U32(&c,4+i,args[i]);SET_GPR_U32(&c,29,0x1e00000);SET_GPR_U32(&c,31,0xabcdef);
        original_transform_port(memory.data(),&c,&r);if(c.pc!=0xabcdef||GPR_U32(&c,29)!=0x1e00000){std::cerr<<"reference exit pc="<<std::hex<<c.pc<<" sp="<<GPR_U32(&c,29)<<" entry="<<pc<<std::dec<<"\n";for(auto at:trace)std::cerr<<std::hex<<at<<",";std::cerr<<std::dec<<"\n";}check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1e00000);++calls;return GPR_U32(&c,2);}
    void bind(unsigned room){const auto raw=graph_asset(room);nav::ImportFailure error;const auto asset=nav::Asset::read(raw,error);check(bool(asset));session->room_variants.restore({});check(world.navigation().bind(std::make_shared<const nav::Asset>(*asset)));
        std::copy(raw.begin(),raw.end(),memory.begin()+0x843780);call(0x815e70,{2});}
    void project(Bytes& target,unsigned at,const w::Actor& actor){
        put(target,at,std::uint8_t(actor.active?128:0));put(target,at+1,std::uint8_t(actor.visible));put(target,at+3,actor.slot);put(target,at+0x1e2,actor.room);
        put(target,at+0x38,actor.position);put(target,at+0x54f,actor.motion_class);put(target,at+0xb98,actor.character);
        put(target,at+0xba0,actor.status);put(target,at+0xba4,actor.auxiliary_status);put(target,at+0xff0,actor.ai_control);put(target,at+0x10a9,actor.transient_marker);
        put(target,at+8,std::array<std::uint8_t,4>{actor.primary,actor.secondary,actor.phase,actor.subphase});put(target,at+0x90,actor.orientation);
        put(target,at+0xd94,actor.saved_action_position);put(target,at+0xda0,actor.saved_action_yaw);
        put(target,at+0xab8,actor.transient_action);put(target,at+0xabb,std::uint8_t(actor.scene_model));put(target,at+0xad4,actor.transient_equipment);put(target,at+0xad5,actor.control_request.kind);put(target,at+0xad6,actor.control_request.parameter);
        if(actor.interaction_request){const auto& x=*actor.interaction_request;put(target,at+0xab9,x.kind);put(target,at+0xaba,x.parameter);put(target,at+0xabc,x.anchor);put(target,at+0xac8,x.orientation);put(target,at+0xacc,x.travel_distance);put(target,at+0xad0,x.endpoint);}
        if(actor.animation)put(target,at+0x520,actor.animation->motion);
        if(actor.color_fade){put(target,at+0xce8,actor.color_fade->rgba);put(target,at+0xcec,actor.color_fade->step);put(target,at+0xcf0,actor.color_fade->updates_left);}
        put(target,at+0xb99,actor.motion_subtype);put(target,at+0x548,actor.action_flags);put(target,at+0xb90,actor.surface_blend_weight);put(target,at+0xbd0,actor.response_lock);
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
            put(target,at+0x1054,r.previous_action);put(target,at+0x1056,r.action);put(target,at+0x1058,r.destination_room);put(target,at+0x105a,r.completed);put(target,at+0x105b,r.selection_mode);put(target,at+0x1060,r.travel_ticks);put(target,at+0x1064,r.refresh);put(target,at+0x1065,r.last_current_node);put(target,at+0x10aa,r.output.link);
        }
    }
    void project_all(){for(unsigned i=0;i<8;++i){const auto at=0x4a5c30+0x10e0*i;std::fill_n(memory.begin()+at,0x10e0,0xa5);project(memory,at,*world.primary(i));}expected_records.assign(memory.begin()+0x4a5c30,memory.begin()+0x4a5c30+8*0x10e0);}
    void compare(){auto expected=expected_records;for(unsigned i=0;i<8;++i)project(expected,0x10e0*i,*world.primary(i));
        for(unsigned i=0;i<expected.size();++i)if(expected[i]!=memory[0x4a5c30+i]){std::cerr<<diagnostic<<" difference offset="<<std::hex<<i<<" native="<<unsigned(expected[i])<<" original="<<unsigned(memory[0x4a5c30+i])<<std::dec<<'\n';for(auto pc:trace)std::cerr<<std::hex<<pc<<',';std::cerr<<std::dec<<'\n';check(false);}}
    void command(std::array<unsigned,3> args){bind(args[1]);for(unsigned i=0;i<3;++i)put(memory,0x10000+4*i,args[i]);project_all();
        check(owner.actor_offline_navigation().command(args[0],args[1],args[2])==s::OfflineNavigationStatus::completed);check(call(0x702740,{0x10000})==0);compare();++commands;}
    void route_entry(bool executable,unsigned action=5,unsigned prior=0,unsigned status=0){
        diagnostic="complete remote entry executable="+std::to_string(executable)+" action="+std::to_string(action)+" prior="+std::to_string(prior)+" status="+std::to_string(status);
        auto section=graph_asset(7,3);section.insert(section.begin()+32+248,16,0);put(section,36,264u);put(section,32+244,1u);section[32+248]=1;section[32+249]=1;
        const unsigned start=64,tail=240,directory=264;
        Bytes b(start+section.size()-32+(executable?48:0));std::copy(section.begin()+32,section.end(),b.begin()+start);
        put(b,0,0x20030724u);put(b,4,12u);put(b,8,36u);put(b,12,1u);b[16]=7;b[18]=0;b[19]=0;b[20]=8;b[22]=1;b[24]=17;
        put(b,36,2u);put(b,40,std::uint16_t(7));put(b,44,start);put(b,52,std::uint16_t(8));put(b,56,start);
        b[start+12+1]=1;b[start+12+20]=1;put(b,start+12+24,std::uint16_t(1));
        b[start+12+64+1]=1;b[start+12+64+20]=0;put(b,start+12+64+24,std::uint16_t(action));
        if(executable){
            put(b,start+directory+8*4,64u);put(b,start+directory+12*4,88u);
            const std::array<unsigned,6> block{0x02000000u,0,0,0,1,0xa};
            std::memcpy(b.data()+start+directory+64,block.data(),sizeof block);std::memcpy(b.data()+start+directory+88,block.data(),sizeof block);
        }
        nav::ImportFailure error;const auto asset=nav::Asset::read(b,error);check(bool(asset));session->room_variants.restore({});check(world.navigation().bind(std::make_shared<const nav::Asset>(*asset)));
        std::copy(b.begin(),b.end(),memory.begin()+0x843780);call(0x815e70,{2});
        auto actor=world.primary(0);actor->active=true;actor->slot=0;actor->ai_control=1;actor->status=status;actor->room=7;actor->position={0,0,300};actor->primary=1;
        actor->navigation_route.emplace();actor->navigation_route->selection_mode=std::uint8_t(prior);actor->ai_execution.emplace();actor->ai_execution->goal=7;actor->ai_execution->action=8;
        Bytes skeleton(112);put(skeleton,4,2u);put(skeleton,8,112u);put(skeleton,16,1u);put(skeleton,20,16u);put(skeleton,28,1u);put(skeleton,36,84u);put(skeleton,48,0xffffffffu);put(skeleton,52,0xffffffffu);
        for(unsigned at:{88u,92u,96u})put(skeleton,at,1.f);
        actor->model=std::make_shared<anim::Instance>(anim::Skeleton::import_raw(std::as_bytes(std::span(skeleton))));actor->animation=std::make_shared<anim::Playback>(actor->model,false);actor->animation->motion=77;
        const std::array<unsigned,2> old_words{1,0xa};std::vector<std::byte> old_bytes(sizeof old_words);std::memcpy(old_bytes.data(),old_words.data(),sizeof old_words);
        const auto old_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{old_bytes},s::DispatchProfile::offline_actor);
        for(unsigned channel:{1u,5u}){check(owner.scripts().restore_channel(channel,{old_program,{0,0},{0,4},88,0,19})==s::Status::completed);
            put(memory,0x4bad28+4*channel,0x30004u);put(memory,0x4bacf8+4*channel,88u);put(memory,0x4bad58+4*channel,19u);}
        std::memcpy(memory.data()+0x30000,old_words.data(),sizeof old_words);
        project_all();put(memory,0x10000,0u);put(memory,0x10004,7u);put(memory,0x10008,0u);
        const auto result=owner.actor_offline_navigation().command(0,7,0);if(result!=s::OfflineNavigationStatus::completed)std::cerr<<"native entry status="<<unsigned(result)<<" room="<<actor->room<<" node="<<int(actor->navigation_route->current_node)<<" selection="<<int(actor->navigation_route->selection_mode)<<"\n";check(result==s::OfflineNavigationStatus::completed);call(0x702740,{0x10000});compare();++entries;
        check(actor->room==8&&actor->navigation_route->current_node==1&&actor->navigation_route->selection_mode==1);
        for(unsigned channel:{1u,5u}){const auto& c=owner.scripts().channels()[channel];check(c.block_index==(channel==1?8:12)&&!c.countdown&&c.saved==s::Position{0,4}&&c.saved_program==old_program&&c.condition==19);
            check(transform_read<unsigned>(memory.data(),0x4bad28+4*channel)==0x30004u&&transform_read<unsigned>(memory.data(),0x4bad58+4*channel)==19);
            check(bool(c.program)==executable);if(executable)check(c.current==s::Position{c.block_index,0});else check(c.current==s::Position{});
        }
        if(executable){
            // Execute actual self-rebinding command in channel1: 68C660 advances
            // the replacement cursor by this old16-byte command before resuming.
            actor->room=7;actor->status=0;actor->navigation_route->current_node=0;actor->navigation_route->selection_mode=0;
            std::vector<std::byte> script(20);const std::array<unsigned,5> words{0x020001a2,0,7,0,0xa};std::memcpy(script.data(),words.data(),sizeof words);
            check(owner.scripts().install(1,std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{script},s::DispatchProfile::offline_actor))==s::Status::completed);
            s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&owner.flags();providers.actor_offline_navigation=&owner.actor_offline_navigation();
            const auto result=owner.scripts().tick_offline_channel(1,{true,false,0,7},{0,0,7},providers);
            check(result.status==s::Status::yielded&&result.operations==3&&result.position==s::Position{8,20});++rebindings;
        }
        (void)tail;
    }
    void continuation_identity(){
        diagnostic="retained continuation and independent bound table";
        const auto make=[](std::initializer_list<unsigned> words){std::vector<std::byte> b(words.size()*4);std::memcpy(b.data(),words.begin(),b.size());return b;};
        auto old_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{make({1,0xa})},s::DispatchProfile::offline_actor);
        std::vector<std::vector<std::byte>> blocks(10);blocks[9]=make({1,0xa});
        const auto table=std::make_shared<const s::Program>(s::Program::from_script_blocks(blocks,s::DispatchProfile::offline_actor));
        s::Providers p;p.world=&world;p.flags=p.canonical_flags=&owner.flags();
        check(owner.scripts().restore_channel(4,{table,{0,4},{0,4},0,8,7,old_program,old_program})==s::Status::completed);
        auto result=owner.scripts().tick_offline_channel(4,{true,false,0,7},{0,0,7},p);
        check(result.status==s::Status::yielded&&result.operations==1&&result.position==s::Position{0,4});
        check(owner.scripts().channels()[4].cursor_program==old_program&&owner.scripts().channels()[4].program==table);
        const auto advance=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{make({1,7})},s::DispatchProfile::offline_actor);
        check(owner.scripts().restore_channel(4,{table,{0,4},{0,4},0,8,7,advance,advance})==s::Status::completed);
        result=owner.scripts().tick_offline_channel(4,{true,false,0,7},{0,0,7},p);
        check(result.status==s::Status::yielded&&result.operations==3&&result.position==s::Position{9,4});
        check(owner.scripts().channels()[4].program==table&&owner.scripts().channels()[4].saved_program==table);++rebindings;
    }
    void geometry(unsigned type,unsigned mode,unsigned side,unsigned yaw,unsigned selector,unsigned kind,unsigned subtype,unsigned travel,bool stop){
        diagnostic="geometry type="+std::to_string(type)+" mode="+std::to_string(mode)+" side="+std::to_string(side)+" yaw="+std::to_string(yaw)+" kind="+std::to_string(kind)+" subtype="+std::to_string(subtype);
        controls.clear();scene::Record record;record.authored_id=selector;record.collision.emplace();record.collision->lower=-345;auto actor=world.primary(1);*actor->interaction_request={};
        actor->interaction_request->kind=77;actor->interaction_request->parameter=93;actor->interaction_request->travel_distance=25;actor->interaction_request->endpoint=68;
        actor->motion_subtype=std::uint8_t(subtype);actor->transient_action=0;actor->transient_equipment=0;actor->scene_model=9;actor->position={91,92,93};actor->orientation={11,12,13,14};
        std::fill_n(memory.begin()+0x20000,0x100,0);put(memory,0x3b5150,std::uint16_t(0));put(memory,0x3b5160,0x20000u);put(memory,0x20030,std::uint8_t(type));put(memory,0x20040,selector);
        if(type==0){s::ControlTypeZero body;body.matrix_program=s::ControlMatrixProgramResource{3,0,mode};record.body=body;record.door_entry=scene::DoorEntryDetails{side,yaw};
            put(memory,0x2004c,3u);put(memory,0x20050,side);put(memory,0x20058,yaw);put(memory,0x20060,mode);
        }else if(type==1){record.body=s::ControlTypeOne{};record.object_entry=scene::ObjectEntryDetails{{11,22,33},yaw,travel,3,65535};record.collision->object.mode=std::bit_cast<std::int32_t>(mode);
            put(memory,0x2004c,std::array<float,3>{11,22,33});put(memory,0x20058,yaw);put(memory,0x2006c,mode);put(memory,0x20070,travel);put(memory,0x20078,3u);put(memory,0x20086,std::uint16_t(65535));
        }else {record.body=s::ControlTypeSix{selector&127u};record.ladder_entry=scene::LadderEntryDetails{mode,3};record.other_content=yaw;
            put(memory,0x20048,yaw);put(memory,0x2004c,mode);put(memory,0x20054,selector&127u);put(memory,0x20060,3u);put(memory,0x20020,std::int32_t(-345));}
        check(bool(controls.records()->create(record)));check(owner.flags().strided(7,selector&31u,2,stop,false));put(memory,0x4b9e24+12*7,std::uint16_t(stop?(1u<<(selector&31u)):0));
        project_all();check(s::queue_scene_entry_request(world,*actor,controls,models,owner.flags(),selector,kind)==s::SceneEntryRequestStatus::completed);
        call(type==0?0x6f8dd0:type==1?0x6f90b0:0x6f9440,{0x4a5c30+0x10e0,selector,kind});compare();++geometries;
    }
};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){trace.push_back(context->pc);switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unexpected offline scene-entry boundary "+std::to_string(context->pc));}}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream input(argv[1],std::ios::binary);const Bytes constants{std::istreambuf_iterator<char>(input),{}};Fixture f(constants);
    for(const auto args:authored_commands){diagnostic="authored";f.command(args);++authored;}
    for(unsigned slot=0;slot<8;++slot)for(unsigned active:{0u,1u})for(unsigned ai:{0u,1u}){auto actor=f.world.primary(slot);actor->active=active;actor->ai_control=std::uint8_t(ai);diagnostic="prefix gates";f.command({slot,7,2});}
    for(unsigned action:{4u,5u,8u,9u})for(unsigned prior:{0u,1u,255u})for(unsigned status:{0u,32u})f.route_entry(false,action,prior,status);
    f.route_entry(true);f.continuation_identity();
    for(unsigned mode:{0u,1u,2u,3u,0xffffffffu})for(unsigned side=0;side<4;++side)for(unsigned yaw:{0u,0x4000u,0x12348000u})for(unsigned kind:{1u,5u})for(bool stop:{false,true})f.geometry(0,mode,side,yaw,17,kind,0,0,stop);
    for(unsigned mode=0;mode<9;++mode)for(unsigned yaw:{0u,0x4000u,0x12348000u})for(unsigned subtype:{0u,1u})for(unsigned travel:{0u,168u,0x80000001u,0xffffffffu})f.geometry(1,mode,0,yaw,17,2,subtype,travel,false);
    for(unsigned mode:{4u,5u})for(unsigned yaw:{0u,0x4000u,0x12348000u})for(unsigned subtype:{0u,1u})f.geometry(6,mode,0,yaw,17|(mode==5?128u:0),4,subtype,0,false);
    check(!f.owner.actor_offline_navigation().command_ready(8,7,0));++refusals;
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"commands\":"<<commands<<",\"authored\":"<<authored<<",\"original_calls\":"<<calls<<",\"geometry_cases\":"<<geometries<<",\"entries\":"<<entries<<",\"self_rebindings\":"<<rebindings<<",\"refusals\":"<<refusals<<"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}

