unsigned hit_gauge_cases{},hit_gauge_events{},hit_gauge_failures{};
namespace hit_gauge_fixture {
namespace u=reo::native::gameplay_update;namespace g=reo::native::gameplay_world;namespace a=g::actors;
using Snapshot=std::array<unsigned,9>;using Call=std::pair<unsigned,Snapshot>;
Snapshot snapshot(const g::Actor& actor){return{actor.gauge_value.value_or(UINT32_MAX),actor.status,actor.auxiliary_status,actor.control_elapsed,actor.pending_hit,actor.notice_flags,actor.transient_contact,actor.transient_action,actor.transient_equipment};}
Snapshot snapshot(const std::uint8_t* memory){constexpr auto actor=0x4a5c30;return{get<unsigned>(memory,actor+0xbac),get<unsigned>(memory,actor+0xba0),get<unsigned>(memory,actor+0xba4),get<unsigned>(memory,actor+0xd28),memory[actor+0x13f],memory[actor+0x115],memory[actor+0xc64],memory[actor+0xab8],memory[actor+0xad4]};}
std::vector<Call> source_calls;
struct Behavior:actor_activity_fixture::Behavior {
    g::World& world;g::Actor& actor;std::vector<Call> calls;std::optional<Snapshot> after_hit;
    Behavior(g::World& w,g::Actor& value):world(w),actor(value){}
    void run(g::BehaviorStage stage,g::World& w,g::Actor& value)override{if(stage==g::BehaviorStage::progression)after_hit=hit_gauge_fixture::snapshot(actor);actor_activity_fixture::Behavior::run(stage,w,value);}
    bool locally_controlled(a::HitActor&,a::HitSession&)override{return world.locally_controlled(actor);}
    void close_inventory(a::HitActor&,a::HitSession&)override{calls.push_back({0x5f4fd0,hit_gauge_fixture::snapshot(actor)});}
    void refresh_statistics(a::HitActor&,a::HitSession&)override{calls.push_back({0x6df160,hit_gauge_fixture::snapshot(actor)});}
    void finish_contact_state(a::HitActor&,a::HitSession&)override{calls.push_back({0x6689e0,hit_gauge_fixture::snapshot(actor)});}
};
}
bool hit_gauge_port(std::uint8_t* memory,R5900Context* context){
    using namespace hit_gauge_fixture;switch(context->pc){case 0x5f4fd0:case 0x6df160:case 0x6689e0:source_calls.push_back({context->pc,snapshot(memory)});return true;default:return false;}
}
void compare_actor_hit_gauge(std::uint8_t* memory){
    using namespace hit_gauge_fixture;actor_status_fixture::nested=0;actor_state_fixture::nested_payload=false;hit_gauge_capture=true;
    for(unsigned n=0;n<8192;++n){
        g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());auto value=std::make_unique<g::Actor>();value->active=true;value->primary=1;value->current=value->maximum=100;value->character=std::uint8_t(n%8);value->gauge_value=g::actor_gauge_limits[n%8]*n/8192;value->status=0x880000u;value->pending_hit=1;value->damage_kind=0x80;value->source_kind=1;value->progression_amount=std::uint16_t(n*65521u);value->control_elapsed=n+123;value->transient_contact=17;value->transient_action=18;value->transient_equipment=19;value->room=std::uint16_t(n*17);const auto id=world.spawn_primary(0,std::move(value)).id;check(bool(id));const auto actor=world.primary(0);world.mode=std::uint8_t(n%2);world.room=actor->room;world.session().message_phase=1;actor_state_fixture::Sink sink(world);actor_action_fixture::Notifications notifications;u::Owner update(world,notifications,e::RuleBook::file1(),&sink);check(update.clock().restore({0,0,0,1},n*65521u)==u::tasks::Status::completed);world.session().feedback_suppressed=0;
        std::fill_n(memory+0x4a5c30,0x10e0,0);memory[0x4a5c30+8]=1;memory[0x4a5c30+0xb98]=actor->character;put(memory,0x4a5c30+0xbac,*actor->gauge_value);put(memory,0x4a5c30+0xba0,actor->status);memory[0x4a5c30+0x13f]=1;memory[0x4a5c30+0x13d]=0x80;memory[0x4a5c30+0x148]=1;put(memory,0x4a5c30+0x14e,actor->progression_amount);put(memory,0x4a5c30+0x544,actor->current);put(memory,0x4a5c30+0x546,actor->maximum);put(memory,0x4a5c30+0x1e2,actor->room);put(memory,0x4a5c30+0xd28,actor->control_elapsed+1u);memory[0x4a5c30+0xc64]=17;memory[0x4a5c30+0xab8]=18;memory[0x4a5c30+0xad4]=19;memory[0x4baded]=0;memory[0x4badf8]=0;memory[0x4bae8d]=0;memory[0x3243f2]=world.mode;memory[0x3243fb]=1;memory[0x3b84f4]=0;put(memory,0x3243dc,world.room);put(memory,0x4bade8,n*65521u);call(memory,0x37c170);source_calls.clear();call(memory,0x660af0,{0x4a5c30});const auto source=snapshot(memory);
        Behavior behavior(world,*actor);actor_activity_fixture::Frame frame;g::BehaviorFrameServices bound(frame,behavior,{},&update,&update);const auto result=world.update_primary(bound);check(result.status==g::Status::completed&&result.updated==1&&behavior.after_hit==source&&behavior.calls==source_calls&&actor->control_elapsed==0&&actor->pending_hit==0);check(world.session().contact_recorded==memory[0x3b84f4]&&sink.states.empty());compare(update.cooperative_events(),memory);hit_gauge_events+=unsigned(update.cooperative_events().snapshot().size());++hit_gauge_cases;
    }
    hit_gauge_capture=false;
    // An unavailable gauge stops after consume/cleanup and before statistics,
    // final contact state, behavior continuation or primary/secondary dispatch.
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());auto value=std::make_unique<g::Actor>();value->active=true;value->primary=1;value->current=value->maximum=100;value->status=0x880000u;value->pending_hit=1;value->source_kind=1;value->damage_kind=0x80;value->progression_amount=1;value->control_elapsed=42;value->transient_contact=1;value->transient_action=2;value->transient_equipment=3;const auto id=world.spawn_primary(0,std::move(value)).id;const auto actor=world.primary(0);world.mode=1;actor_action_fixture::Notifications notifications;u::Owner update(world,notifications);Behavior behavior(world,*actor);actor_activity_fixture::Frame frame;g::BehaviorFrameServices bound(frame,behavior,{},&update,&update);bool failed=false;try{(void)world.update_primary(bound);}catch(const std::runtime_error&){failed=true;}check(failed&&actor->control_elapsed==0&&actor->pending_hit==0&&actor->notice_flags==1&&actor->status==0x800000u&&!actor->transient_contact&&!actor->transient_action&&!actor->transient_equipment&&!behavior.after_hit&&!behavior.primary_calls&&!behavior.secondary_calls&&behavior.calls.size()==1&&behavior.calls[0].first==0x5f4fd0&&frame.completed==0);++hit_gauge_failures;
    g::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());g::Actor detached;check(!update.apply_hit_gauge(foreign,*actor,1)&&!update.apply_hit_gauge(world,detached,1));++hit_gauge_failures;check(update.close()==u::Status::completed&&bool(world.resolve(id))&&!update.apply_hit_gauge(world,*actor,1));++hit_gauge_failures;
}
