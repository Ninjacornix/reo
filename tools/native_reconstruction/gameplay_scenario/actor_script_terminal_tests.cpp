#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_world/actor_resource_operations.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <functional>
#include <iostream>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace e=reo::native::gameplay_events;
namespace {
unsigned checks{},calls{},dispatches{},refusals{},phase_checks{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Terminal check at "+std::to_string(at.line()));
}
template<class T>void put(std::span<std::byte> bytes,unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
using Bytes=std::vector<std::uint8_t>;
struct Packet{unsigned route{},channel{};Bytes bytes;friend bool operator==(const Packet&,const Packet&)=default;};
std::vector<Packet> original_packets;
std::function<void(std::uint8_t*,unsigned)> original_callback;
void normalize(Bytes& bytes){if(bytes[0]==1){bytes[38]=bytes[43]=0;}else if(bytes[0]==7)bytes[11]=0;}
struct Notices:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
struct Messages:u::GameplayMessageSink {
    std::vector<Packet> packets;std::function<bool(unsigned)> callback;
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool emit(u::MessageRoute route,unsigned channel,Bytes bytes)noexcept{
        normalize(bytes);const auto type=bytes[0];packets.push_back({unsigned(route),channel,std::move(bytes)});
        return !callback||callback(type);
    }
    bool send(const u::RoomClaimReleaseMessage& value)noexcept override{
        return emit(value.route,7,{4,8,value.sender,4,1,value.sender,value.room,0});
    }
    bool send(const u::ActorActionMessage& value)noexcept override{
        Bytes bytes(12);bytes[0]=7;bytes[1]=12;std::memcpy(bytes.data()+4,&value.flags,2);
        std::copy(value.values.begin(),value.values.end(),bytes.begin()+6);bytes[10]=value.equipment;
        return emit(value.route,value.channel,std::move(bytes));
    }
    bool send(const u::ActorSnapshotMessage& value)noexcept override{
        Bytes bytes(44);bytes[0]=1;bytes[1]=44;std::copy(value.action.begin(),value.action.end(),bytes.begin()+4);
        std::memcpy(bytes.data()+8,&value.position,12);std::memcpy(bytes.data()+20,&value.yaw,2);
        std::memcpy(bytes.data()+22,&value.health,2);std::memcpy(bytes.data()+24,&value.status,4);
        bytes[28]=value.selected_resource;bytes[29]=value.equipment;bytes[30]=value.interaction_resource;bytes[31]=value.grid;
        std::memcpy(bytes.data()+32,&value.aim_pitch_adjustment,2);std::memcpy(bytes.data()+34,&value.aim_target_pitch,2);
        bytes[36]=value.room;bytes[37]=value.aim_target_index;bytes[39]=value.gauge_band;
        bytes[40]=value.resource_pair[0];bytes[41]=value.resource_pair[1];bytes[42]=value.auxiliary_flag;
        return emit(value.route,value.channel,std::move(bytes));
    }
};
std::shared_ptr<const s::Program> script(bool terminal=true){
    std::vector<std::byte> bytes(terminal?12:8);put(std::span(bytes),0,1u);
    put(std::span(bytes),4,terminal?0x60u:0xau);if(terminal)put(std::span(bytes),8,0xau);
    return std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes});
}
struct Fixture {
    std::shared_ptr<w::Session> session=std::make_shared<w::Session>();
    w::World world{{{w::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session};Notices notices;Messages messages;
    u::Owner update{world,notices,e::RuleBook::create({{}},{0}),&messages};
    s::ResourceTemplates templates;s::SceneResources resources;w::ResourceModels models;
    std::array<std::byte,12> forest{};
    std::shared_ptr<const w::ResourceStaticAssets> assets;
    w::ResourceFrames frames;w::ResourceFactory factory;w::ResourceContents contents;w::ResourcePairs pairs;
    w::WorldInventory inventory;w::ResourceRecipes recipes;w::ActorResourceOperations operations,other_operations;
    static std::shared_ptr<const w::ResourceStaticAssets> static_assets(){std::array<std::byte,12> bytes{};put(bytes,8,12u);return w::ResourceStaticAssets::import_forest(bytes);}
    Fixture():assets(static_assets()),frames(world,resources,models,nullptr,{},&templates),factory(models,frames,templates,assets),
        contents(world,resources,templates,frames,factory),pairs(world,resources,templates,frames),inventory(world,resources,templates,frames),
        recipes(pairs,contents,inventory),operations(recipes),other_operations(recipes){
        session->scenario=0;check(update.initialize_completion_statistics()==e::StatisticsStatus::completed);
        std::array<std::byte,32+8*24> encoded{};put(encoded,0,3u);put(encoded,4,8u);put(encoded,16,32u);
        for(unsigned i=0;i<8;++i){put(encoded,32+i*24+18,std::uint16_t(42+i));encoded[32+i*24+21]=std::byte(i%4);}
        check(templates.load(encoded));
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();w::initialize_cleared_actor_defaults(*actor);
            actor->active=true;actor->slot=std::uint8_t(i);actor->character=std::uint8_t(i);actor->gauge_value=100000;
            check(world.spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);}
        for(unsigned i=1;i<=8;++i){s::SceneDescriptor descriptor;descriptor.active=1;descriptor.instance_index=std::uint8_t(i);
            descriptor.attachment_id=std::uint16_t(41+i);descriptor.ownership_tag=1;descriptor.flags=0x20000;
            descriptor.claim_tag=7;descriptor.template_index=std::uint8_t(i-1);check(bool(resources.load(i,descriptor)));}
    }
};
void actor_memory(Bytes& memory,const w::Actor& actor,unsigned slot){
    const auto at=0x4a5c30+slot*0x10e0;auto* m=memory.data();
    transform_write(m,at,std::uint8_t(actor.active?0x80:0));transform_write(m,at+2,actor.category);transform_write(m,at+3,actor.slot);
    transform_write(m,at+8,actor.primary);transform_write(m,at+9,actor.secondary);transform_write(m,at+10,actor.phase);transform_write(m,at+11,actor.subphase);
    transform_write(m,at+0x1e2,actor.room);transform_write(m,at+0xba0,actor.status);transform_write(m,at+0xba4,actor.auxiliary_status);
    transform_write(m,at+0x38,actor.position.x);transform_write(m,at+0x3c,actor.position.y);transform_write(m,at+0x40,actor.position.z);
    transform_write(m,at+0x92,actor.orientation[1]);transform_write(m,at+0x544,actor.current);transform_write(m,at+0xb98,actor.character);
    transform_write(m,at+0xbac,*actor.gauge_value);transform_write(m,at+0xc7c,actor.selected_resource);transform_write(m,at+0xc7f,actor.equipment_slot);
    transform_write(m,at+0xc80,*actor.interaction_resource);transform_write(m,at+0xcb0,actor.grid);
    transform_write(m,at+0xbc8,*actor.aim_pitch_adjustment);transform_write(m,at+0xcd4,*actor.aim_target_pitch);
    transform_write(m,at+0xcdc,*actor.aim_target_index);transform_write(m,at+0xcaa,actor.explicit_resource_pair[0]);transform_write(m,at+0xcab,actor.explicit_resource_pair[1]);
    transform_write(m,at+0xca8,actor.resource_action);std::memcpy(m+at+0xc84,actor.inventory.carried.data(),4);std::memcpy(m+at+0xc88,actor.inventory.storage.data(),32);
    transform_write(m,at+0xd92,actor.pending_notice);transform_write(m,at+0xd94,actor.saved_action_position.x);
    transform_write(m,at+0xd98,actor.saved_action_position.y);transform_write(m,at+0xd9c,actor.saved_action_position.z);transform_write(m,at+0xda0,actor.saved_action_yaw);
    m[at+0xda2]=actor.equipment_notice_slot;m[at+0xda3]=actor.equipment_notice_peer;m[at+0xda4]=actor.equipment_notice_parameter;m[at+0xda5]=actor.equipment_notice_detail;
}
void resource_memory(Bytes& memory,const Fixture& fixture){
    for(unsigned i=1;i<=8;++i){const auto descriptor=*fixture.resources.get(*fixture.resources.slot(i));const auto at=0x3c5630+i*60;
        memory[at]=descriptor.active;memory[at+2]=descriptor.instance_index;
        transform_write(memory.data(),at+6,descriptor.attachment_id);transform_write(memory.data(),at+24,descriptor.flags);
        transform_write(memory.data(),at+40,descriptor.ownership_tag);memory[at+42]=descriptor.claim_tag;memory[at+43]=descriptor.template_index;
    }
    std::memcpy(memory.data()+0x4bac52,fixture.session->auxiliary_resources.data(),32);
}
void comparison(unsigned mode,unsigned selected,unsigned trial){
    Fixture f;f.world.mode=std::uint8_t(mode);f.world.selected_actor=std::uint8_t(selected);f.world.selected_frame_marker=0x80;
    f.session->message_phase=std::uint8_t(trial%4);auto actor=f.world.primary(selected);
    actor->active=trial%11!=0;actor->category=std::uint8_t(trial%13==0);actor->status=trial%7==0?0x20:0x08000001;
    actor->auxiliary_status=trial%5==0?0x02000000:0x40;actor->room=std::uint16_t(trial%3==0?155:23);
    actor->primary=8;actor->secondary=9;actor->phase=10;actor->subphase=11;actor->position={12.5f,-40.25f,73};actor->orientation[1]=-731;
    actor->saved_action_position={41,42,43};actor->saved_action_yaw=123;actor->selected_resource=trial%2?1:0;
    actor->resource_action=1234;actor->pending_notice=0xabcd;actor->equipment_notice_slot=12;actor->equipment_notice_peer=13;actor->equipment_notice_parameter=14;actor->equipment_notice_detail=15;
    actor->inventory.carried={2,3,4,0};actor->inventory.storage[0]=5;actor->inventory.storage[3]=6;
    // The source recovery lists have four player rows. Physical NPC slots
    // still exercise the complete empty-inventory early exit.
    if(trial%4==0||selected>=4)actor->inventory={};actor->character=std::uint8_t(trial%8);
    constexpr std::uint32_t gauges[]{0,50000,100000,150000,273600,345600,0x80000000u,0xffffffffu};actor->gauge_value=gauges[trial%8];
    for(unsigned i=1;i<=8;++i){auto descriptor=*f.resources.get(*f.resources.slot(i));descriptor.ownership_tag=std::uint16_t(selected+1);check(f.resources.replace(*f.resources.slot(i),descriptor)==s::SceneStatus::completed);}
    auto& terminal=f.update.actor_script_terminal();check(terminal.bind_resource_operations(&f.operations)==s::ActorScriptTerminalStatus::completed);
    // Publication is synchronous: changes from the room release precede the saved action/status.
    const bool mutate=trial%6==0;
    f.messages.callback=[&](unsigned type){if(type==4&&mutate){actor->status=0x08000013;actor->primary=19;actor->room=37;}return true;};
    original_callback=[&](std::uint8_t* m,unsigned type){if(type==4&&mutate){const auto at=0x4a5c30+selected*0x10e0;transform_write(m,at+0xba0,0x08000013u);m[at+8]=19;transform_write(m,at+0x1e2,std::uint16_t(37));}};
    Bytes memory(0x900000);original_constants(memory.data());
    for(unsigned i=0;i<8;++i)actor_memory(memory,*f.world.primary(i),i);resource_memory(memory,f);
    for(unsigned i=0;i<8;++i){transform_write(memory.data(),0x74bb50+i*24+18,std::uint16_t(42+i));memory[0x74bb50+i*24+21]=std::uint8_t(i%4);}
    memory[0x3243f2]=std::uint8_t(mode);memory[0x3243fb]=f.session->message_phase;memory[0x4baded]=std::uint8_t(selected);memory[0x4bae89]=0x80;
    auto expected=memory;original_packets.clear();R5900Context context;PS2Runtime runtime;
    context.pc=0x68ef50;SET_GPR_U32(&context,29,0x880000);SET_GPR_U32(&context,31,0x100);
    o2_0068EF50_0x68ef50(memory.data(),&context,&runtime);check(context.pc==0x100);++calls;
    check(f.update.scripts().install(0,script())==s::Status::completed);
    s::Providers providers;providers.world=&f.world;providers.actor_script_terminal=&terminal;
    const auto result=f.update.scripts().tick(0,{true,false,std::uint8_t(selected)},providers);if(result.status!=s::Status::yielded)throw std::runtime_error("dispatch mode="+std::to_string(mode)+" selected="+std::to_string(selected)+" trial="+std::to_string(trial)+" status="+std::to_string(int(result.status))+" ready="+std::to_string(terminal.command_ready()));check(result.status==s::Status::yielded);++dispatches;
    for(unsigned i=0;i<8;++i)actor_memory(expected,*f.world.primary(i),i);resource_memory(expected,f);
    expected[0x4badf9]=f.update.state.pause_latched;expected[0x3b84f6]=f.update.completion_statistics().state().actors.scripted_terminal;
    for(unsigned i=0;i<8;++i)check(std::equal(expected.begin()+0x4a5c30+i*0x10e0,expected.begin()+0x4a5c30+(i+1)*0x10e0,memory.begin()+0x4a5c30+i*0x10e0));
    check(std::equal(expected.begin()+0x3c5630,expected.begin()+0x3c5630+9*60,memory.begin()+0x3c5630));
    check(std::equal(expected.begin()+0x4bac52,expected.begin()+0x4bac52+32,memory.begin()+0x4bac52));
    check(expected[0x4badf9]==memory[0x4badf9]&&expected[0x3b84f6]==memory[0x3b84f6]);
    check(f.world.selected_frame_marker==memory[0x4bae89]&&memory[0x4bae89]==0x80);
    if(f.messages.packets!=original_packets){
        std::cerr<<"packet mismatch mode="<<mode<<" selected="<<selected<<" trial="<<trial<<" native="<<f.messages.packets.size()<<" original="<<original_packets.size()<<'\n';
        for(const auto& packet:f.messages.packets){std::cerr<<"native "<<packet.route<<' '<<packet.channel<<':';for(auto value:packet.bytes)std::cerr<<' '<<unsigned(value);std::cerr<<'\n';}
        for(const auto& packet:original_packets){std::cerr<<"original "<<packet.route<<' '<<packet.channel<<':';for(auto value:packet.bytes)std::cerr<<' '<<unsigned(value);std::cerr<<'\n';}
    }
    check(f.messages.packets==original_packets);original_callback={};
}
struct Phases:u::PhaseServices {
    std::vector<std::pair<u::PhaseEffect,unsigned>> effects;
    void run(u::Worker,u::Owner&)override{}
    bool button(u::Button,u::Owner&)override{return false;}
    bool transition_request(u::Owner&)override{std::terminate();}
    void effect(u::PhaseEffect effect,u::Owner&,std::uint32_t value)override{effects.emplace_back(effect,value);}
};
struct NoActors:w::Services {
    void begin_offline_frame(w::World&)override{std::terminate();}void run(w::Stage,w::World&,w::Actor&)override{std::terminate();}
    bool remote_motion(w::World&,w::Actor&)override{std::terminate();}bool find_grid(w::World&,w::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{std::terminate();}float grid_response(w::World&,std::uint8_t)override{std::terminate();}
};
void boundaries(){
    Fixture f;auto actor=f.world.primary(0);auto& terminal=f.update.actor_script_terminal();f.world.mode=2;
    check(!terminal.command_ready());check(terminal.command()==s::ActorScriptTerminalStatus::unavailable_owner);++refusals;
    actor->active=false;check(terminal.command_ready());check(terminal.command()==s::ActorScriptTerminalStatus::completed);check(!f.update.state.pause_latched);++refusals;
    actor->active=true;actor->status=0x20;check(terminal.command_ready());check(terminal.command()==s::ActorScriptTerminalStatus::completed);check(!f.update.state.pause_latched);++refusals;
    actor->status=0;f.world.selected_actor=8;check(!terminal.command_ready());check(terminal.command()==s::ActorScriptTerminalStatus::unavailable_owner);f.world.selected_actor=0;++refusals;
    actor->active=true;actor->category=1;check(terminal.command_ready());check(terminal.command()==s::ActorScriptTerminalStatus::completed);check(f.update.state.pause_latched==1);++refusals;
    actor->category=0;f.update.state.pause_latched=0;check(terminal.bind_resource_operations(&f.operations)==s::ActorScriptTerminalStatus::completed);
    check(terminal.bind_resource_operations(&f.other_operations)==s::ActorScriptTerminalStatus::unavailable_owner);
    check(terminal.bind_resource_operations(nullptr)==s::ActorScriptTerminalStatus::unavailable_owner);
    check(terminal.bind_resource_operations(&f.operations)==s::ActorScriptTerminalStatus::completed);
    f.world.selected_actor=4;auto npc=f.world.primary(4);npc->inventory.carried[0]=1;
    check(!terminal.command_ready());check(terminal.command()==s::ActorScriptTerminalStatus::unavailable_owner);check(!f.update.state.pause_latched);
    npc->inventory={};f.world.selected_actor=0;++refusals;
    check(terminal.bind_resource_operations(nullptr,&f.operations)==s::ActorScriptTerminalStatus::completed);check(!terminal.command_ready());
    check(terminal.bind_resource_operations(&f.operations)==s::ActorScriptTerminalStatus::completed);
    actor->selected_resource=1;auto item=*f.resources.get(*f.resources.slot(1));const auto saved=item;
    item.primary=std::make_shared<s::SceneAttachment>();check(f.resources.replace(*f.resources.slot(1),item)==s::SceneStatus::completed);
    check(!terminal.command_ready());check(terminal.command()==s::ActorScriptTerminalStatus::unavailable_owner);check(!f.update.state.pause_latched);
    check(f.resources.replace(*f.resources.slot(1),saved)==s::SceneStatus::completed);actor->selected_resource=0;actor->inventory={};++refusals;
    // Direct calls borrow the same lifetime guard as the ordinary script caller.
    f.world.mode=1;f.session->message_phase=1;actor->room=14;actor->status=0;
    unsigned reentries{};f.messages.callback=[&](unsigned){
        ++reentries;check(f.update.busy());check(f.update.close()==u::Status::busy);check(f.update.open());
        check(terminal.close()==s::ActorScriptTerminalStatus::busy);
        check(terminal.bind_resource_operations(nullptr,&f.operations)==s::ActorScriptTerminalStatus::busy);
        check(terminal.bind_resource_operations(&f.other_operations,&f.operations)==s::ActorScriptTerminalStatus::busy);return true;
    };
    check(terminal.command()==s::ActorScriptTerminalStatus::completed);check(reentries==2&&terminal.command_ready());
    // A room-release failure commits only the outer flags and actor status prefix.
    actor->status=0;actor->primary=8;actor->room=14;actor->pending_notice=0xabcd;
    f.messages.callback=[](unsigned){return false;};check(terminal.command()==s::ActorScriptTerminalStatus::publication_failure);
    check(actor->status==4&&actor->primary==8&&actor->room==14&&actor->pending_notice==0xabcd);++refusals;
    // Sink rejection retains the source prefix, including the temporary action.
    f.world.mode=1;f.session->message_phase=1;actor->room=14;actor->primary=8;actor->status=0;
    f.messages.callback=[](unsigned type){return type!=1;};check(terminal.command()==s::ActorScriptTerminalStatus::publication_failure);
    check(actor->status==4&&actor->primary==1&&actor->secondary==0x30&&actor->room==0&&f.update.state.pause_latched==1);++refusals;
    check(f.update.initialize_completion_statistics()==e::StatisticsStatus::completed);check(!f.update.completion_statistics().state().actors.scripted_terminal);
    f.world.mode=2;f.session->message_phase=0;actor->status=0;f.update.state.pause_latched=0;f.world.selected_frame_marker=0x80;
    check(f.update.scripts().install(0,script())==s::Status::completed);check(f.update.step_script(0).status==u::Status::completed);
    check(f.update.state.pause_latched==1&&f.world.selected_frame_marker==0x80);++phase_checks;
    for(unsigned i=0;i<8;++i)f.world.primary(i)->active=false;
    f.update.state.scripts_enabled=false;check(f.update.scripts().install(1,script(false))==s::Status::completed);
    Phases phases;NoActors actors;check(f.update.advance(phases,actors).status==u::Status::completed);
    check((phases.effects==std::vector<std::pair<u::PhaseEffect,unsigned>>{{u::PhaseEffect::finish_request,0},{u::PhaseEffect::enter_phase,12}}));
    check(f.update.state.notification_pending==1&&f.update.state.transition_gate==1);++phase_checks;
    check(terminal.close()==s::ActorScriptTerminalStatus::completed);check(terminal.bind_resource_operations(nullptr,&f.operations)==s::ActorScriptTerminalStatus::completed);
    check(terminal.bind_resource_operations(&f.operations)==s::ActorScriptTerminalStatus::closed);++refusals;
}
}
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    switch(c->pc){
#include "original_lookup.inc"
    case 0x107c68:std::memset(m+GPR_U32(c,4),int(GPR_U32(c,5)),GPR_U32(c,6));SET_GPR_U32(c,2,GPR_U32(c,4));break;
    case 0x811190:case 0x810870:case 0x810960:case 0x8129c0:{
        const auto pc=c->pc;const auto at=GPR_U32(c,5);Bytes bytes(m+at,m+at+m[at+1]);normalize(bytes);
        const auto type=bytes[0];original_packets.push_back({unsigned(pc==0x810870||pc==0x8129c0),GPR_U32(c,4),std::move(bytes)});
        if(original_callback)original_callback(m,type);SET_GPR_U32(c,2,1);break;
    }
    default:throw std::runtime_error("Unexpected terminal original boundary "+std::to_string(c->pc));
    }
    c->pc=GPR_U32(c,31);
}
int main()try{
    for(unsigned mode=0;mode<4;++mode)for(unsigned selected=0;selected<8;++selected)for(unsigned trial=0;trial<32;++trial)comparison(mode,selected,trial);
    boundaries();std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"dispatches\":"<<dispatches<<",\"refusals\":"<<refusals<<",\"phase_consumer_checks\":"<<phase_checks<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}

