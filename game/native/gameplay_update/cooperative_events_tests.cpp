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
    void changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    void changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
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
void check_automatic_worker(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;
    e::RuleGroup group;group.automatic={{3,0,42,0,5,2}};u::Owner owner(world,notifications,e::RuleBook::create({group},{0}));
    world.mode=1;world.paused=1;Remaining remaining;EmptyActors actors;
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},std::byte{},std::byte{},std::byte{},std::byte{0xa},std::byte{},std::byte{},std::byte{}}});
    for(unsigned i=0;i<2;++i)check(owner.scripts().install(i,program)==s::Status::completed);
    check(owner.clock().restore({},123)==u::tasks::Status::completed);
    auto result=owner.run_workers(remaining,actors);check(result.status==u::Status::statistics_failure&&result.completion_checked&&!result.clock_committed);
    world.session().scenario=0;check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);
    result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&result.completion_checked&&result.completion.matched==0);
    remaining.calls.clear();check(owner.flags().write(s::FlagBank::scenario,42,true));
    result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&result.completion_checked&&result.completion.matched==1&&result.completion.recorded==1);
    check((remaining.calls==std::vector<u::Worker>{u::Worker::reset_entity_queues,u::Worker::armed_request,u::Worker::clear_interaction_activity,u::Worker::clear_proxy_work}));
    const auto events=owner.cooperative_events().snapshot();check(events.size()==1&&events[0].value.id==5&&events[0].value.timestamp==123&&owner.completion_statistics().state().points==2);
    check(owner.run_workers(remaining,actors).completion.matched==0);
    check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);world.paused=0;owner.state.session_work_gate=1;
    result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&!result.completion_checked&&owner.cooperative_events().snapshot().empty());
    owner.state.session_work_gate=0;result=owner.run_workers(remaining,actors);check(result.status==u::Status::completed&&result.completion_checked&&result.completion.matched==1);
    s::ActionChoices foreign;s::Providers providers;providers.action_choices=&foreign;result=owner.run_workers(remaining,actors,providers);check(result.status==u::Status::script_failure&&!result.completion_checked);
    check(owner.close()==u::Status::completed&&owner.check_scenario_events().status==e::StatisticsStatus::unavailable);check(world.close()==u::world::Status::completed);
}
int main()try{
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
