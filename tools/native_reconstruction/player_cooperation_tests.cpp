#include "game/native/gameplay_world/assistance.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "game/native/gameplay_world/idle_action.hpp"
#include "game/native/gameplay_world/inventory_ui.hpp"
#include "game/native/gameplay_world/interaction_registration.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_application/native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include "game/native/transform_math/heading.hpp"
#include <cstdio>
#include <source_location>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace s=reo::native::gameplay_scenario;
namespace e=reo::native::gameplay_events;
namespace {
constexpr unsigned base=0x4a5c30,aux_at=0x20000,done=0x1234;
std::vector<std::uint8_t> ram(0x900000);
unsigned checks{},cases{},phase{},events{};
std::vector<std::array<std::uint8_t,8>> registrations;
std::vector<std::array<unsigned,3>> animations;
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Player cooperation check "+std::to_string(checks)+" case "+std::to_string(cases)+" phase "+std::to_string(phase)+" line "+std::to_string(at.line()));}
template<class T>void put(unsigned at,T value){ref_write(ram.data(),at,value);}
template<class T>T get(unsigned at){return ref_read<T>(ram.data(),at);}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
struct Messages final:u::GameplayMessageSink {
    std::vector<u::ActorPeerMessage> peers;
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool send(const u::ActorPeerMessage& message)noexcept override{peers.push_back(message);return true;}
};
struct Animation final:w::ActionAnimation {
    std::vector<std::array<unsigned,3>> calls;
    void select(w::Actor&,unsigned value,float initial,float blend)override{calls.push_back({value,std::bit_cast<unsigned>(initial),std::bit_cast<unsigned>(blend)});}
    void activate(w::Actor&)override{calls.push_back({0,0,0});}
    std::int8_t tick(w::Actor&,float)override{throw std::runtime_error("Unexpected animation tick");}
};
struct Registration final:w::InteractionRegistrationPublication {
    std::vector<w::InteractionRegistrationMessage> calls;
    bool publish(w::World&,w::Actor&,const w::InteractionRegistrationMessage& message)override{calls.push_back(message);return true;}
};
unsigned encode(const w::actors::ActorReference& ref){return ref.identifier|(ref.kind==w::actors::ActorReference::Kind::auxiliary?0x8000u:0u);}
void export_actor(unsigned at,const w::Actor& a){
    std::fill(ram.begin()+at,ram.begin()+at+4320,0);
    ram[at]=a.active;ram[at+1]=a.visible;ram[at+2]=a.category;ram[at+3]=a.slot;
    ram[at+8]=a.primary;ram[at+9]=a.secondary;ram[at+10]=a.phase;ram[at+11]=a.subphase;
    put(at+0x38,a.position);put(at+0x90,a.orientation);put(at+0xba0,a.status);put(at+0xba4,a.auxiliary_status);
    ram[at+0xb98]=a.character;ram[at+0xb9b]=a.class_marker;ram[at+0xbd0]=a.response_lock;ram[at+0xff0]=a.ai_control;
    ram[at+0x54f]=a.motion_class;put(at+0x548,a.action_flags);put(at+0xbb4,a.model_variant);put(at+0x1e2,a.room);
    ram[at+0xc64]=a.transient_contact;ram[at+0xc65]=a.peer_request->state_high;put(at+0xc66,std::uint16_t(encode(a.peer_request->peer)));put(at+0xc68,a.peer_request->parameters);
    put(at+0xd94,a.saved_action_position);put(at+0xda0,a.saved_action_yaw);
    put(at+0xb34,a.interaction_registration->selection_word);ram[at+0xda6]=a.interaction_registration->sequence;ram[at+0xda7]=a.interaction_registration->previous_sequence;
}
void compare_actor(unsigned at,const w::Actor& a){
    check(a.primary==ram[at+8]&&a.secondary==ram[at+9]&&a.phase==ram[at+10]&&a.subphase==ram[at+11]);
    check(a.status==get<unsigned>(at+0xba0)&&a.auxiliary_status==get<unsigned>(at+0xba4));
    check(a.motion_class==ram[at+0x54f]&&a.action_flags==get<std::uint16_t>(at+0x548));
    check(a.transient_contact==ram[at+0xc64]&&a.peer_request->state_high==ram[at+0xc65]);
    check(encode(a.peer_request->peer)==get<std::uint16_t>(at+0xc66)&&a.peer_request->parameters==get<std::array<std::int16_t,2>>(at+0xc68));
    const auto pos=get<w::Position>(at+0xd94);check(a.saved_action_position.x==pos.x&&a.saved_action_position.y==pos.y&&a.saved_action_position.z==pos.z&&a.saved_action_yaw==get<std::int16_t>(at+0xda0));
}
void port(std::uint8_t* memory,R5900Context* c,PS2Runtime*){
    const auto actor=GPR_U32(c,4);
    switch(c->pc){
    case 0x191d10:{const auto a=ref_read<w::Position>(memory,actor),b=ref_read<w::Position>(memory,GPR_U32(c,5));const auto x=a.x-b.x,y=a.y-b.y,z=a.z-b.z;c->f[0]=std::sqrt((x*x+y*y)+z*z);break;}
    case 0x65f410:{const auto a=ref_read<w::Position>(memory,actor+0x38),b=ref_read<w::Position>(memory,GPR_U32(c,5)+0x38);const auto h=reo::native::transform_math::direction_turn(b.x-a.x,b.z-a.z);SET_GPR_U32(c,2,std::uint16_t(h-ref_read<std::uint16_t>(memory,actor+0x92)+0x4000u)<=0x8000u);break;}
    case 0x37c060:check(actor==9);++events;break;
    case 0x67e230:break; //qualified publication; cases suppress snapshots or use peer in mode1
    case 0x107c68:std::memset(memory+actor,int(GPR_U32(c,5)),GPR_U32(c,6));break;
    case 0x1afdd0:{const auto mode=ref_read<std::int16_t>(memory,0x3243f2);if(mode==0||mode==1){std::array<std::uint8_t,8> row;std::memcpy(row.data(),memory+GPR_U32(c,5),8);registrations.push_back(row);}break;}
    case 0x5d4cf0:animations.push_back({GPR_U32(c,5),std::bit_cast<unsigned>(c->f[12]),std::bit_cast<unsigned>(c->f[13])});break;
    case 0x58c7b0:animations.push_back({0,0,0});break;
    case 0x5f4fd0:{const auto selected=memory[0x4baded];const auto at=base+4320*selected;put(at+0xba4,get<unsigned>(at+0xba4)|0x400u);put(at+0xba0,get<unsigned>(at+0xba0)&~0x8000u);memory[0x4bae89]|=3;memory[0x4badee]=0;break;}
    default:throw std::runtime_error("Unexpected cooperation dependency "+std::to_string(c->pc));
    }
    c->pc=GPR_U32(c,31);
}
void original(PS2Runtime& runtime,unsigned entry,unsigned actor=base,unsigned arg=0,unsigned third=0){
    R5900Context ctx{};ctx.pc=entry;ctx.g[4].lo=actor;ctx.g[5].lo=arg;ctx.g[6].lo=third;ctx.g[29].lo=0x50000;ctx.g[31].lo=done;
    runtime.lookupFunction(entry)(ram.data(),&ctx,&runtime);check(ctx.pc==done);put(0x1000,GPR_U32(&ctx,2));
}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{
    switch(at){/* ORIGINAL_LOOKUP */default:return port;}
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::invalid_argument("Owned scenario archive required");
    Notices notices;Messages messages;PS2Runtime runtime;
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);
    reo::native::gameplay_application::NativeSession session(source,{{{1,2,4}},1,{32,UINT64_MAX}},notices,1,&messages);
    auto& world=session.world();
    for(unsigned i=0;i<3;++i){auto a=std::make_unique<w::Actor>();w::initialize_cleared_actor_defaults(*a);a->slot=i;check(bool(world.spawn_primary(i,std::move(a)).id));}
    const auto aux_id=world.auxiliary_actors().allocate(1).id;check(bool(aux_id));
    auto aux=world.resolve(aux_id);w::initialize_cleared_actor_defaults(*aux);aux->category=1;aux->model_variant=7;
    world.session().primary_population=3;world.scenario=41;
    auto& update=session.update();auto& inventory=session.inventory_ui();check(inventory.initialize()==w::InventoryUiStatus::completed);
    const auto reset=[&](){
        for(unsigned i=0;i<3;++i){auto& a=*world.primary(i);a.active=a.visible=true;a.category=0;a.slot=i;a.status=i?8:4;a.auxiliary_status=0;a.class_marker=i?2:0;a.response_lock=0;a.ai_control=0;a.primary=1;a.secondary=a.phase=a.subphase=0;a.motion_class=0;a.position={0,0,float(i*60)};a.orientation={};a.peer_request=w::PeerRequest{};a.saved_action_position={};a.saved_action_yaw=0;a.interaction_registration=w::InteractionRegistrationState{0xabcdef01,255,99};a.action_flags=0xffff;a.transient_contact=0;}
        aux->active=aux->visible=true;aux->status=8;aux->class_marker=2;aux->response_lock=0;aux->position={0,0,80};aux->motion_class=0;aux->peer_request=w::PeerRequest{};
        world.mode=1;world.paused=0;world.selected_actor=0;world.selected_frame_marker=0;world.session().message_phase=0;world.session().inventory_owner=0;world.session().actor_message_suppression=0;
        check(update.initialize_completion_statistics()==e::StatisticsStatus::completed);messages.peers.clear();registrations.clear();animations.clear();events=0;
    };
    const auto export_all=[&](){
        for(unsigned i=0;i<3;++i)export_actor(base+4320*i,*world.primary(i));export_actor(aux_at,*aux);put(aux_at+0x1c,0u);put(0x3b59f0,aux_at);
        put(0x3243f2,world.mode);ram[0x3243fb]=world.session().message_phase;ram[0x4badf8]=world.paused;ram[0x4baded]=world.selected_actor;ram[0x4bae89]=world.selected_frame_marker;ram[0x4badee]=world.session().inventory_owner;put(0x4baea0,3u);put(0x3b84ea,update.completion_statistics().state().actors.assistance_requests);
        constexpr std::array<unsigned,7> table{0x66673c,0x6667f0,0x6667d8,0x666814,0x666748,0x666874,0x6668fc};put(0x740410,table);
        constexpr std::array<unsigned,7> registration{0x680134,0x680018,0x68004c,0x680070,0x6800b0,0x6800d4,0x680114};put(0x740790,registration);
    };
    phase=1;
    for(unsigned trial=0;trial<24;++trial)for(unsigned mode=0;mode<4;++mode){
        ++cases;reset();world.mode=std::int16_t(mode);auto& a=*world.primary(0);auto& target=*world.primary(1);
        switch(trial){case 1:world.paused=1;break;case 2:a.category=1;break;case 3:a.motion_class=0x16;break;case 4:a.status|=0x80;break;case 5:target.response_lock=1;break;case 6:a.ai_control=1;target.slot=0;break;case 7:target.motion_class=4;break;case 8:target.class_marker=0;target.status=0;break;case 9:target.visible=false;break;case 10:target.active=false;break;case 11:target.position.y=30;break;case 12:target.position.y=30.01f;break;case 13:target.position.y=-30;break;case 14:target.position.y=-30.01f;break;case 15:target.position.z=-10;break;case 16:target.position.z=100;aux->active=false;break;case 17:target.position.z=100.01f;aux->active=false;break;case 18:a.class_marker=2;target.status=0x10;aux->status=0;aux->position.z=20;break;case 19:target.position.x=60;target.position.z=0;break;case 20:a.orientation[1]=std::int16_t(0x8000);break;case 21:target.position.z=0;break;case 22:{auto state=update.completion_statistics().state();state.actors.assistance_requests=65535;update.completion_statistics().restore(state);break;}case 23:world.selected_actor=1;break;default:break;}
        export_all();original(runtime,0x6507f0);const auto expected=get<unsigned>(0x1000);const auto actual=w::select_assistance_actor(update,a);
        const auto native_at=!actual?0u:actual==aux_id?aux_at:base+world.resolve(actual)->slot*4320;
        check(expected==native_at);check(update.completion_statistics().state().actors.assistance_requests==get<std::uint16_t>(0x3b84ea));
    }
    phase=2;
    for(unsigned category:{0u,1u,2u})for(unsigned message_phase:{0u,1u}){
        ++cases;reset();auto& a=*world.primary(0);auto& target=category==1?*aux:*world.primary(1);target.category=category;target.peer_request->parameters={std::int16_t(0xabcd),123};a.status=0;world.session().message_phase=message_phase;
        export_all();original(runtime,0x6506c0,base,category==1?aux_at:base+4320);w::begin_assistance(update,a,target);
        compare_actor(base,a);compare_actor(category==1?aux_at:base+4320,target);
        check(messages.peers.size()==unsigned(category<=1&&message_phase==1));
        if(!messages.peers.empty())check(messages.peers[0].state==0x102&&encode(messages.peers[0].peer)==(category==1?0x8007u:1u));
    }
    phase=3;
    for(unsigned request=0;request<6;++request)for(unsigned variant=0;variant<15;++variant){
        ++cases;reset();auto& a=*world.primary(0);a.transient_contact=2;a.peer_request->state_high=request;a.peer_request->peer={w::actors::ActorReference::Kind::primary,1};a.class_marker=2;a.status=12;a.motion_class=0x16;
        switch(variant){case 1:world.paused=1;break;case 2:a.transient_contact=0;break;case 3:world.selected_frame_marker=2;break;case 4:a.class_marker=0;a.status=4;break;case 5:a.auxiliary_status=0x10000;break;case 6:a.response_lock=1;break;case 7:a.primary=2;break;case 8:a.secondary=15;break;case 9:a.secondary=0x31;break;case 10:a.secondary=0x32;break;case 11:world.session().message_phase=1;break;case 12:a.category=1;break;case 13:a.motion_class=0;break;case 14:a.secondary=0xa2;break;default:break;}
        export_all();original(runtime,0x64f7b0);Animation animation;w::update_cooperation_action(update,a,inventory,&animation);compare_actor(base,a);
        check(animation.calls==animations);check(world.selected_frame_marker==ram[0x4bae89]&&world.session().inventory_owner==ram[0x4badee]);
    }
    phase=4;
    for(unsigned selector=1;selector<=6;++selector)for(unsigned control:{0u,7u,255u})for(unsigned message_phase:{0u,1u,2u,3u})for(unsigned category:{0u,1u})for(unsigned mode:{0u,1u,3u}){
        ++cases;reset();auto& a=*world.primary(0);a.category=category;a.room=73;a.orientation[1]=-12345;world.mode=std::int16_t(mode);world.session().message_phase=message_phase;export_all();
        original(runtime,0x67ff80,base,selector,control);Registration registration;check(w::register_interaction(world,a,std::uint8_t(selector),std::uint8_t(control),registration)==w::InteractionRegistrationStatus::completed);
        check(a.interaction_registration->selection_word==get<unsigned>(base+0xb34));check(a.interaction_registration->sequence==ram[base+0xda6]&&a.interaction_registration->previous_sequence==ram[base+0xda7]);
        check(registration.calls.size()==registrations.size());
        if(!registrations.empty()){const auto& x=registration.calls[0];const auto& y=registrations[0];check(x.selector==y[0]&&y[1]==8&&x.control_selector==y[4]&&x.room==y[5]&&x.sequence==y[6]);if(selector==3||selector==5)check(x.yaw_high==y[7]);}
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"game_run\":false}\n",checks,cases);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}
