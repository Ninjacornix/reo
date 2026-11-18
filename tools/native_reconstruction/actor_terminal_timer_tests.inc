#include "game/native/gameplay_world/actor_terminal_timer.hpp"
unsigned terminal_timer_cases{},terminal_timer_transitions{},terminal_timer_live{},terminal_timer_compositions{},terminal_timer_refusals{};
namespace terminal_fixture {
using namespace auxiliary_fixture;namespace a=g::actors;
void export_actor(Fixture& q,const g::Actor& actor,unsigned slot){const auto at=0x4a5c30+0x10e0*slot;inventory_fixture::export_actor(q.memory,actor,slot);export_notice(q,actor,slot);q.memory[at+8]=actor.primary;q.memory[at+9]=actor.secondary;q.memory[at+10]=actor.phase;q.memory[at+11]=actor.subphase;q.memory[at+0x54f]=actor.motion_class;put(q.memory,at+0xba0,actor.status);put(q.memory,at+0xba4,actor.auxiliary_status);put(q.memory,at+0xbac,actor.gauge_value.value_or(0xdeadbeefu));put(q.memory,at+0xc62,actor.terminal_countdown);put(q.memory,at+0x38,actor.position);put(q.memory,at+0x90,actor.orientation);put(q.memory,at+0xd94,actor.saved_action_position);put(q.memory,at+0xda0,actor.saved_action_yaw);}
void compare_terminal_actor(Fixture& q,const g::Actor& actor,unsigned slot){actor_operation_fixture::compare_actor(q,actor,slot);const auto at=0x4a5c30+0x10e0*slot;check(actor.primary==q.memory[at+8]&&actor.secondary==q.memory[at+9]&&actor.phase==q.memory[at+10]&&actor.subphase==q.memory[at+11]&&actor.motion_class==q.memory[at+0x54f]);check(actor.gauge_value==get<unsigned>(q.memory,at+0xbac)&&actor.terminal_countdown==get<std::uint16_t>(q.memory,at+0xc62)&&actor.status==get<unsigned>(q.memory,at+0xba0)&&actor.auxiliary_status==get<unsigned>(q.memory,at+0xba4));check(std::memcmp(&actor.saved_action_position,q.memory+at+0xd94,12)==0&&actor.saved_action_yaw==get<std::int16_t>(q.memory,at+0xda0));}
void compare_tick(Consuming& f,g::ActorTerminalTimer& timer,unsigned index){const auto actor=f.q.world.primary(index);call(f.q.memory,0x6687a0,{0x4a5c30+0x10e0*index});timer.tick(f.q.world.identity(index));compare_items(f.q);for(unsigned i=0;i<4;++i)compare_terminal_actor(f.q,*f.q.world.primary(i),i);f.q.compare_world();if(actor->primary==4&&actor->motion_class==0xa0)++terminal_timer_transitions;++terminal_timer_cases;}
struct Sink:u::GameplayMessageSink {
    bool available{true};std::vector<u::ActorActionMessage> actions;
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool send(const u::ActorActionMessage& value)noexcept override{actions.push_back(value);return available;}
};
struct Behavior:g::BehaviorServices {
    unsigned primary_calls{},secondary_calls{},transitions{};
    [[noreturn]] static void unentered(){throw std::runtime_error("Unentered terminal timer provider");}
    void run(g::BehaviorStage stage,g::World&,g::Actor&)override{if(stage==g::BehaviorStage::terminal_timer)unentered();}
    void dispatch(g::ActionPass pass,std::uint8_t state,g::World&,g::Actor&)override{check(state==4);if(pass==g::ActionPass::primary)++primary_calls;else ++secondary_calls;}
    bool suppress_action_notice(g::World&,g::Actor&,std::uint8_t,std::uint8_t)override{unentered();}
    bool authority_filter(a::HealthSession&)override{unentered();}
    std::int32_t selected_authority(a::HealthSession&,std::uint8_t)override{unentered();}
    void refresh_class(a::HealthState&,a::HealthSession&)override{unentered();}
    void feedback(a::StatusActor&,a::StatusSession&,std::uint8_t)override{unentered();}
    void publish(a::StatusActor& actor,a::StatusSession&,std::uint8_t selector)override{check(selector==5&&actor.primary==4);++transitions;}
    void cleanup(a::StatusActor&,a::StatusSession&)override{unentered();}
    void recover(a::StatusActor&,a::StatusSession&)override{unentered();}
    void snapshot(a::StatusActor&,a::StatusSession&)override{unentered();}
    bool locally_controlled(a::HitActor&,a::HitSession&)override{return true;}
    std::uint32_t partner_flags(std::uint8_t)override{unentered();}
    std::uint8_t partner_character(std::uint8_t)override{unentered();}
    std::uint16_t scene_owner(std::uint8_t)override{unentered();}
    void event(a::HitActor&,a::HitSession&,std::uint32_t,std::uint32_t)override{unentered();}
    void add_status(a::HitActor&,a::HitSession&,std::uint8_t)override{unentered();}
    void close_inventory(a::HitActor&,a::HitSession&)override{unentered();}
    void detach_scene(a::HitActor&,a::HitSession&,std::uint8_t,std::uint8_t)override{unentered();}
    void release_equipment(a::HitActor&,a::HitSession&,std::uint8_t)override{unentered();}
    void cancel_action(a::HitActor&,a::HitSession&)override{unentered();}
    void apply_progression(a::HitActor&,a::HitSession&,std::uint16_t)override{unentered();}
    void refresh_statistics(a::HitActor&,a::HitSession&)override{unentered();}
    void finish_contact_state(a::HitActor&,a::HitSession&)override{unentered();}
    void clear_hit_relations(a::HitActor&,a::HitSession&)override{unentered();}
};
struct Frame:g::Services {
    Consuming& fixture;unsigned notices{},finished{};
    explicit Frame(Consuming& value):fixture(value){}
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World& world,g::Actor& actor)override{if(stage==g::Stage::update_behavior)Behavior::unentered();if(stage==g::Stage::finish_actor)++finished;if(stage==g::Stage::publish_notice){check(actor.pending_notice==0x2000);++notices;if(fixture.update.record_actor_action(world.identity_of(actor))!=u::PublicationStatus::completed)throw std::runtime_error("Terminal notice delivery unavailable");}}
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{Behavior::unentered();}
    float grid_response(g::World&,std::uint8_t)override{Behavior::unentered();}
};
}
void compare_actor_terminal_timer(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace terminal_fixture;const auto assets=factory_load(static_path,16);auto banks=factory_load(template_path,5);std::vector<std::byte> controlled(32+4*24);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(controlled.data()+at,&value,sizeof value);};write(0,3u);write(4,4u);write(16,32u);for(unsigned i=0;i<4;++i){write(32+24*i,0x100001u);write(32+24*i+12,std::int8_t(1));write(32+24*i+18,std::uint16_t(42));write(32+24*i+21,std::uint8_t(i));}banks.push_back(controlled);
    for(const auto& bank:banks){Consuming f(ram,assets[0],bank);g::ActorResourceOperations operations(f.recipes);g::ActorTerminalTimer timer(f.q.world,operations);
        const auto prepare=[&](unsigned n,bool expire){seed(f,n);f.mode(n%4,(n/4)%4);f.q.session->clock_mode=std::uint8_t(n>>8);f.q.memory[0x3243cc]=f.q.session->clock_mode;f.q.world.paused=std::bit_cast<std::int8_t>(std::uint8_t(n));for(unsigned i=0;i<4;++i){const auto actor=f.q.world.primary(i);actor->inventory.carried={3,4,0,0};actor->inventory.storage={5,6,0};actor->selected_resource=0;actor->secondary_equipped_resource=0;actor->resource_action=123;actor->primary=std::uint8_t(expire?1:n%6);actor->secondary=std::uint8_t(n);actor->phase=std::uint8_t(n>>8);actor->subphase=17;actor->motion_class=9;actor->terminal_countdown=expire?1:std::uint16_t(n);actor->gauge_value=n*1664525u;actor->status=expire?0x18u:n*65521u;actor->auxiliary_status=expire?0x1000u:n*1664525u;actor->pending_notice=std::uint16_t(n*257u);actor->equipment_notice_slot=17;actor->equipment_notice_peer=19;actor->equipment_notice_parameter=23;actor->position={float(n),-float(n),float(n*7)};actor->orientation={17,std::bit_cast<std::int16_t>(std::uint16_t(n*65521)),19,23};actor->saved_action_position={-1,-2,-3};actor->saved_action_yaw=-7;f.actor(i,std::uint8_t(expire?0:n%3),std::uint8_t(n%3?6:n%8));export_actor(f.q,*actor,i);}};
        for(unsigned n=0;n<65536;++n){prepare(n,false);compare_tick(f,timer,n%4);}
        for(unsigned n=0;n<512;++n){prepare(n,true);compare_tick(f,timer,n%4);}
    }
    for(unsigned mask=0;mask<16;++mask){Consuming f(ram,assets[0],controlled);g::ActorResourceOperations operations(f.recipes);g::ActorTerminalTimer timer(f.q.world,operations);auto actor=f.q.world.primary(0);f.mode(1,mask&8?1:0);actor->inventory.carried={3,4,0,0};actor->inventory.storage={5,6,0};actor->selected_resource=3;actor->resource_action=123;actor->primary=1;actor->terminal_countdown=1;actor->gauge_value=100;actor->status=0x18;actor->auxiliary_status=0x1000u|(mask&4?0x02000000u:0u);actor->position={100,-20,300};actor->orientation[1]=-123;f.actor(0,0,6);for(unsigned i=0;i<4;++i)export_actor(f.q,*f.q.world.primary(i),i);for(unsigned i=3;i<=6;++i){s::SceneDescriptor item;item.active=1;item.instance_index=std::uint8_t(i);item.template_index=0;item.ownership_tag=1;item.attachment_id=42;item.flags=0x20000;sync_full(f.q,i,item);}std::shared_ptr<g::ResourceModel> held;if(mask&1){auto [made,raw]=f.q.create(42,7);held=made.model;held->resource_slot=3;f.q.memory[raw+0x240]=3;auto item=*f.q.resources.get(*f.q.resources.slot(3));item.primary=held;sync_full(f.q,3,item);}if(mask&2)secondary(f.q,3);export_lists(f.q);call(f.q.memory,0x6687a0,{0x4a5c30});timer.tick(f.q.world.identity(0));for(unsigned i=3;i<=6;++i)compare_full(f.q,i);compare_lists(f.q);compare_terminal_actor(f.q,*actor,0);f.q.compare_world();if(held)check(held->current()==bool(mask&8));cleanup(f.q,3);++terminal_timer_live;}
    for(bool fail:{false,true}){Sink sink;sink.available=!fail;Consuming f(ram,assets[0],controlled,&sink);g::ActorResourceOperations operations(f.recipes);g::ActorTerminalTimer timer(f.q.world,operations);for(unsigned i=0;i<4;++i)f.q.world.primary(i)->active=false;const auto actor=f.q.world.primary(0);actor->active=true;actor->current=0;actor->primary=1;actor->status=0x18;actor->auxiliary_status=0x1000;actor->terminal_countdown=1;actor->gauge_value=100;actor->room=f.q.world.room;actor->inventory.carried={3,4,0,0};actor->inventory.storage={5,6,0};actor->selected_resource=0;actor->pending_notice=0;f.actor(0,0,6);for(unsigned i=3;i<=6;++i){s::SceneDescriptor item;item.active=1;item.instance_index=std::uint8_t(i);item.ownership_tag=1;item.template_index=0;sync_full(f.q,i,item);}f.mode(1,0);f.q.world.session().message_phase=1;f.q.world.session().session_state=1;f.q.world.session().auxiliary_resources={};Behavior behavior;Frame frame(f);g::BehaviorFrameServices bound(frame,behavior,{},&f.update,&f.update,&timer);bool failed{};try{const auto result=f.q.world.update_primary(bound);check(result.status==g::Status::completed&&result.updated==1);}catch(const std::runtime_error&){failed=true;}check(failed==fail&&actor->primary==4&&actor->terminal_countdown==0&&actor->gauge_value==0&&actor->inventory.carried==std::array<std::uint8_t,4>{}&&actor->inventory.storage==std::array<std::uint8_t,32>{}&&frame.notices==1&&frame.finished==1&&behavior.primary_calls==1&&behavior.secondary_calls==1&&behavior.transitions==1&&sink.actions.size()==1&&sink.actions[0].flags==0x2000&&actor->pending_notice==(fail?0x2000:0));++terminal_timer_compositions;}
    {Consuming f(ram,assets[0],controlled);g::ActorResourceOperations operations(f.recipes);g::ActorTerminalTimer timer(f.q.world,operations);const auto actor=f.q.world.primary(0);actor->primary=1;actor->auxiliary_status=0x1000;actor->gauge_value.reset();timer.tick(f.q.world.identity(0));check(actor->gauge_value==0);const auto refused=[&](auto action){bool caught{};try{action();}catch(const std::exception&){caught=true;}check(caught);++terminal_timer_refusals;};refused([&]{timer.tick({});});g::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());refused([&]{g::ActorTerminalTimer wrong(foreign,operations);});g::Actor detached;check(!timer.apply_terminal_timer(foreign,*actor)&&!timer.apply_terminal_timer(f.q.world,detached));++terminal_timer_refusals;check(f.q.world.close()==g::Status::completed);refused([&]{timer.tick(f.q.world.identity(0));});}
}
