unsigned actor_activity_cases{},actor_activity_deliveries{},actor_activity_failures{};
namespace actor_activity_fixture {
namespace u=reo::native::gameplay_update;namespace g=reo::native::gameplay_world;
namespace a=g::actors;namespace act=actor_action_fixture;namespace state=actor_state_fixture;
struct Behavior:g::BehaviorServices {
    unsigned primary_calls{},secondary_calls{};std::vector<g::BehaviorStage> stages;
    [[noreturn]] static void unentered(){throw std::runtime_error("Unentered activity binding provider");}
    void run(g::BehaviorStage stage,g::World&,g::Actor&)override{if(stage==g::BehaviorStage::activity_notice)unentered();stages.push_back(stage);}
    void dispatch(g::ActionPass pass,std::uint8_t,g::World&,g::Actor& actor)override{if(pass==g::ActionPass::primary){++primary_calls;actor.position.x+=1;}else{++secondary_calls;check(!(actor.status&0x800000u));}}
    bool suppress_action_notice(g::World&,g::Actor&,std::uint8_t,std::uint8_t)override{unentered();}
    bool authority_filter(a::HealthSession&)override{unentered();}
    std::int32_t selected_authority(a::HealthSession&,std::uint8_t)override{unentered();}
    void refresh_class(a::HealthState&,a::HealthSession&)override{unentered();}
    void feedback(a::StatusActor&,a::StatusSession&,std::uint8_t)override{unentered();}
    void publish(a::StatusActor&,a::StatusSession&,std::uint8_t)override{unentered();}
    void cleanup(a::StatusActor&,a::StatusSession&)override{unentered();}
    void recover(a::StatusActor&,a::StatusSession&)override{unentered();}
    void snapshot(a::StatusActor&,a::StatusSession&)override{unentered();}
    bool locally_controlled(a::HitActor& actor,a::HitSession& session)override{return actor.category==0&&actor.slot==session.selected_actor;}
    std::uint32_t partner_flags(std::uint8_t)override{unentered();}
    std::uint8_t partner_character(std::uint8_t)override{unentered();}
    std::uint16_t scene_owner(std::uint8_t)override{unentered();}
    void event(a::HitActor&,a::HitSession&,std::uint32_t,std::uint32_t)override{unentered();}
    void add_status(a::HitActor&,a::HitSession&,std::uint8_t)override{unentered();}
    void close_inventory(a::HitActor&,a::HitSession&)override{unentered();}
    void detach_scene(a::HitActor&,a::HitSession&,std::uint8_t,std::uint8_t)override{unentered();}
    void release_equipment(a::HitActor&,a::HitSession&,std::uint8_t)override{unentered();}
    void cancel_action(a::HitActor&,a::HitSession&)override{unentered();}
    void clear_owner_interaction(a::HitActor&,a::HitSession&)override{unentered();}
    void apply_progression(a::HitActor&,a::HitSession&,std::uint16_t)override{unentered();}
    void refresh_statistics(a::HitActor&,a::HitSession&)override{unentered();}
    void finish_contact_state(a::HitActor&,a::HitSession&)override{unentered();}
    void clear_hit_relations(a::HitActor&,a::HitSession&)override{unentered();}
};
struct Frame:g::Services {
    unsigned behavior_forwarded{},completed{};
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World&,g::Actor&)override{if(stage==g::Stage::update_behavior)++behavior_forwarded;if(stage==g::Stage::finish_actor)++completed;}
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{Behavior::unentered();}
    float grid_response(g::World&,std::uint8_t)override{Behavior::unentered();}
};
}
void compare_actor_activity_binding(){
    using namespace actor_activity_fixture;actor_status_fixture::nested=0;state::nested_payload=false;
    // Complete native World->BehaviorFrameServices->update_behavior->Owner->
    // publication composition. Other frame/action providers are declared here.
    // Healthy actors deliberately leave every health/hit effect unentered.
    for(unsigned mode=0;mode<2;++mode)for(unsigned tick=0;tick<60;++tick)for(bool paused:{false,true})for(unsigned suppression:{0u,2u}){
        g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());auto value=std::make_unique<g::Actor>();value->active=true;value->primary=1;value->current=value->maximum=100;value->status=0x800000u;value->position={10,20,30};value->character=0;value->gauge_value=151200;const auto id=world.spawn_primary(0,std::move(value)).id;check(bool(id));const auto actor=world.primary(0);world.mode=std::uint8_t(mode);world.paused=std::int8_t(paused);world.session().message_phase=1;state::Sink sink(world);act::Notifications notifications;u::Owner update(world,notifications,e::RuleBook::file1(),&sink);check(update.clock().restore({0,0,0,std::uint8_t(tick)},0)==u::tasks::Status::completed);world.session().feedback_suppressed=std::uint8_t(tick%30?0:1);
        Behavior behavior;Frame frame;g::BehaviorFrameServices bound(frame,behavior,{},&update);
        // World resets744638 before behavior; the separate direct-behavior case
        // below tests selector suppression after that reset, at the actual gate.
        world.session().actor_message_suppression=std::uint16_t(suppression);const auto result=world.update_primary(bound);check(result.status==g::Status::completed&&result.updated==1&&!frame.behavior_forwarded&&frame.completed==1);check(behavior.primary_calls==unsigned(!paused)&&behavior.secondary_calls==1&&!(actor->status&0x800000u));const auto sent=unsigned(!paused&&tick%30==0);check(sink.states.size()==sent);if(sent){check(sink.states[0].position.x==11&&sink.states[0].status==0x08800000u&&sink.states[0].gauge_band==3&&actor->status==0x08000000u);++actor_activity_deliveries;}
        check(update.clock().play_time().sixtieths==tick&&actor->position.x==(paused?10:11));++actor_activity_cases;
    }
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());auto value=std::make_unique<g::Actor>();value->active=true;value->primary=1;value->current=value->maximum=100;value->gauge_value=0;const auto id=world.spawn_primary(0,std::move(value)).id;const auto actor=world.primary(0);state::Sink sink(world);act::Notifications notifications;u::Owner update(world,notifications,e::RuleBook::file1(),&sink);world.mode=1;world.session().message_phase=1;Behavior behavior;Frame frame;g::BehaviorFrameServices bound(frame,behavior,{},&update);
    world.session().actor_message_suppression=2;g::update_behavior(world,*actor,behavior,{},nullptr,&update);check(sink.states.empty()&&!(actor->status&0x08000000u));++actor_activity_cases;
    world.session().actor_message_suppression=0;sink.available=false;actor->status=0x800000u;const auto before_secondary=behavior.secondary_calls;bool failed=false;try{(void)world.update_primary(bound);}catch(const std::runtime_error&){failed=true;}check(failed&&behavior.secondary_calls==before_secondary&&actor->status==0x08800000u&&sink.states.size()==1&&frame.completed==0);++actor_activity_failures;sink.available=true;sink.states.clear();actor->gauge_value.reset();actor->status=0x800000u;failed=false;try{(void)world.update_primary(bound);}catch(const std::runtime_error&){failed=true;}check(failed&&behavior.secondary_calls==before_secondary&&actor->status==0x08800000u&&sink.states.empty());++actor_activity_failures;
    // Foreign worlds, foreign actors, retired leases and a closed update Owner
    // cannot publish through a borrowed binding.
    g::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());g::Actor detached;check(!update.publish_activity(foreign,*actor)&&!update.publish_activity(world,detached));++actor_activity_failures;check(world.retire_primary(0)==a::EntityStatus::completed&&!update.publish_activity(world,*actor));++actor_activity_failures;
    const auto replacement=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(replacement)&&replacement!=id);const auto live=world.primary(0);check(update.close()==u::Status::completed&&bool(world.identity_of(*live))&&!update.publish_activity(world,*live));++actor_activity_failures;
}
