#include "update.hpp"
#include <iostream>
#include <stdexcept>
#include <source_location>
namespace u=reo::native::gameplay_update;
namespace e=reo::native::gameplay_events;
namespace s=reo::native::gameplay_scenario;
void check(bool value,std::source_location at=std::source_location::current()){if(!value)throw std::runtime_error("Cooperative update-owner binding check at "+std::to_string(at.line()));}
// No flag operations are exercised; these callbacks fail if unexpectedly used.
struct Notifications:s::FlagNotifications {
    unsigned scenario_changes{};
    bool changed(const s::ScenarioFlagChange&)noexcept override{++scenario_changes;return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
struct Remaining:u::Services {
    std::vector<u::Worker> calls;
    void run(u::Worker stage,u::Owner&)override{calls.push_back(stage);}
};
struct EmptyActors:u::world::Services {
    void begin_offline_frame(u::world::World&)override{std::terminate();}
    void run(u::world::Stage,u::world::World&,u::world::Actor&)override{std::terminate();}
    bool remote_motion(u::world::World&,u::world::Actor&)override{std::terminate();}
    bool find_grid(u::world::World&,u::world::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(u::world::World&,std::int32_t,std::int32_t)override{std::terminate();}
    float grid_response(u::world::World&,std::uint8_t)override{std::terminate();}
};
struct ActorMessages:u::GameplayMessageSink {
    std::optional<u::ActorStatusMessage> last;unsigned sends{},lookups{};bool available{true};
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage& value)noexcept override{++sends;last=value;return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{if(route!=u::MessageRoute::mode_one||room!=0x1234)std::terminate();++lookups;return 3;}
};
void check_actor_status(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;ActorMessages messages;u::Owner owner(world,notifications,e::RuleBook::file1(),&messages);
    const auto id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;check(bool(id));auto actor=world.resolve(id);actor->current=10;actor->maximum=100;actor->status=3;world.session().message_phase=1;
    check(owner.clear_actor_status(id,0x10004)==u::PublicationStatus::completed&&actor->current==100&&actor->status==0);check(messages.sends==1&&messages.last&&messages.last->health==100&&messages.last->status==0&&messages.last->channel==1&&messages.last->route==u::MessageRoute::mode_zero);
    world.session().actor_message_suppression=14;actor->current=1;check(owner.clear_actor_status(id,1)==u::PublicationStatus::completed&&actor->current==100&&messages.sends==1);
    world.session().actor_message_suppression=0;world.paused=1;actor->status=3;check(owner.clear_actor_status(id,2)==u::PublicationStatus::completed&&actor->status==2&&messages.sends==1);
    world.paused=0;world.mode=1;world.room=0x1234;actor->category=1;actor->status=0x10000003;actor->current=55;check(owner.clear_actor_status(id,5)==u::PublicationStatus::completed&&actor->status==0x10000000&&messages.lookups==1&&messages.sends==2&&messages.last->channel==4&&messages.last->health==55);
    actor->category=0;actor->current=1;actor->status=3;messages.available=false;check(owner.clear_actor_status(id,4)==u::PublicationStatus::message_unavailable&&actor->current==100&&actor->status==0);
    check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.clear_actor_status(id,1)==u::PublicationStatus::unavailable);check(owner.close()==u::Status::completed&&world.close()==u::world::Status::completed);
}
void check_automatic_worker(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;
    e::RuleGroup group;group.automatic={{3,2,42,0,5,2}};u::Owner owner(world,notifications,e::RuleBook::create({group},{0}));
    world.mode=1;world.paused=1;Remaining remaining;EmptyActors actors;
    check(bool(world.spawn_primary(0,std::make_unique<u::world::Actor>()).id));
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},std::byte{},std::byte{},std::byte{},std::byte{0xa},std::byte{},std::byte{},std::byte{}}});
    for(unsigned i=0;i<2;++i)check(owner.scripts().install(i,program)==s::Status::completed);
    check(owner.clock().restore({},123)==u::tasks::Status::completed);
    auto result=owner.run_workers(remaining,actors);check(result.status==u::Status::statistics_failure&&result.completion_checked&&!result.clock_committed);
    world.session().scenario=0;check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);
    result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&result.completion_checked&&result.completion.matched==0);
    remaining.calls.clear();check(owner.flags().scenario(42,1,s::NotifyOwner::selected_actor_plus_one,1));check(owner.flags().scenario_owner(42)==1&&notifications.scenario_changes==1);
    result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&result.completion_checked&&result.completion.matched==1&&result.completion.recorded==1);
    check((remaining.calls==std::vector<u::Worker>{u::Worker::reset_entity_queues,u::Worker::armed_request,u::Worker::clear_interaction_activity,u::Worker::clear_proxy_work}));
    const auto events=owner.cooperative_events().snapshot();check(events.size()==1&&events[0].value.id==5&&events[0].value.timestamp==123&&owner.completion_statistics().state().points==2);
    check(owner.run_workers(remaining,actors).completion.matched==0);
    check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);world.paused=0;owner.state.session_work_gate=1;
    result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&!result.completion_checked&&owner.cooperative_events().snapshot().empty());
    owner.state.session_work_gate=0;result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&result.completion_checked&&result.completion.matched==1);
    s::ActionChoices foreign;s::Providers providers;providers.action_choices=&foreign;result=owner.run_workers(remaining,actors,providers);check(result.status==u::Status::script_failure&&!result.completion_checked);
    world.session().message_phase=1;check(!owner.flags().scenario(43,1,s::NotifyOwner::selected_actor_plus_one,1));check(owner.flags().get(s::FlagBank::scenario,43)==true&&owner.flags().scenario_owner(43)==0&&notifications.scenario_changes==1);
    world.primary(0)->status=0x400;check(owner.flags().scenario(44,1,s::NotifyOwner::selected_actor_plus_one,1));check(owner.flags().scenario_owner(44)==0&&notifications.scenario_changes==2);
    check(owner.close()==u::Status::completed&&owner.check_scenario_events().status==e::StatisticsStatus::unavailable);check(world.close()==u::world::Status::completed);
}
int main()try{
    check_actor_status();
    check_automatic_worker();
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;u::Owner owner(world,notifications);check(owner.open());
    world.room=0x1234;check(owner.clock().restore({0,0,0,0},UINT32_MAX)==u::tasks::Status::completed);
    const auto first=owner.record_event(0xabcd0013,0x12345678,0xabcdef90);check(first.status==e::Status::completed);
    const auto value=owner.cooperative_events().get(first.id);check(value&&value->id==0x13&&value->timestamp==0xa4c478&&value->room==0x1234&&value->first==0x5678&&value->second==0xef90);
    check(owner.clock().commit_update(u::tasks::ClockStep::two)==u::tasks::Status::completed);world.room=7;
    const auto next=owner.record_event(0x14,1,2);const auto after=owner.cooperative_events().get(next.id);check(after&&after->timestamp==0&&after->room==7);
    const auto generic=owner.record_simple_event(0xabcdffff);const auto simple=owner.cooperative_events().get(generic.id);check(simple&&simple->id==65535&&simple->type==1&&simple->priority==9&&simple->room==0);
    check(owner.record_event(0xffff,0,0).status==e::Status::unavailable);const auto snapshot=owner.cooperative_events().snapshot();check(snapshot.size()==3);
    check(owner.record_scenario_event(10100).status==e::StatisticsStatus::unavailable);
    world.session().scenario=0;check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed&&!owner.cooperative_events().get(first.id));check(owner.completion_statistics().state().unique_available==31);
    const auto recorded=owner.record_scenario_event(0xabcd0000u|10100);check(recorded.status==e::StatisticsStatus::completed&&recorded.matched==1&&recorded.recorded==1&&recorded.dropped==0);const auto completion=owner.completion_statistics().state();check(completion.points==20&&completion.completed[0]==2&&completion.explicit_seen[0]==1);
    const auto completion_events=owner.cooperative_events().snapshot();check(completion_events.size()==1&&completion_events[0].value.id==1&&completion_events[0].value.type==1&&completion_events[0].value.priority==9&&completion_events[0].value.timestamp==0);check(owner.record_scenario_event(10100).matched==0);
    check(owner.close()==u::Status::completed&&!owner.open()&&!owner.cooperative_events().get(first.id));check(owner.record_event(1,0,0).status==e::Status::closed&&owner.record_simple_event(1).status==e::Status::closed&&snapshot.size()==3);
    check(world.close()==u::world::Status::completed);std::cout<<"Cooperative events use the actual update clock/room and joined closure.\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
