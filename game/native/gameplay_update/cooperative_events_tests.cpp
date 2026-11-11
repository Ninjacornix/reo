#include "update.hpp"
#include "../gameplay_scenario/content.hpp"
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
    void run(u::Worker stage,u::Owner& owner)override{
        if(stage==u::Worker::reset_entity_queues)
            check(owner.world().session().ai_control_requests.pending().empty());
        calls.push_back(stage);
    }
};
struct ControlPayloadCapture final : reo::native::gameplay_ai::ControlPayloadSink {
    std::optional<reo::native::gameplay_ai::ControlPayloadPacket> packet;
    bool send_control_payload(const reo::native::gameplay_ai::ControlPayloadPacket& value) noexcept override {
        packet = value;
        return true;
    }
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
    bool send(const u::ResourcePositionMessage&)noexcept override{return false;}
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
    namespace ai = reo::native::gameplay_ai;
    const auto actor_id = world.identity(0);
    check(owner.register_ai_control(actor_id) == ai::RegistrationStatus::created);
    check(owner.publish_ai_control(actor_id, 19)->status == ai::RequestStatus::queued);
    ControlPayloadCapture control_capture;
    const auto flushed = owner.flush_ai_control_payloads(control_capture);
    check(flushed.status == ai::ControlPayloadStatus::completed && flushed.sent == 1);
    check(control_capture.packet == ai::ControlPayloadPacket{0, 9, 0x80, 0, 0, 19, 0, 0, 0});
    check(owner.publish_ai_control(actor_id, 23)->status == ai::RequestStatus::queued);
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},std::byte{},std::byte{},std::byte{},std::byte{0xa},std::byte{},std::byte{},std::byte{}}});
    for(unsigned i=0;i<2;++i)check(owner.scripts().install(i,program)==s::Status::completed);
    check(owner.clock().restore({},123)==u::tasks::Status::completed);
    auto result=owner.run_workers(remaining,actors);check(result.status==u::Status::statistics_failure&&result.completion_checked&&!result.clock_committed);
    check(world.session().ai_control_requests.pending().empty() &&
          world.session().ai_control_requests.registered(0, 0));
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
void check_session_script_binding(){
    const u::world::Profile profile{{{1,2,4}},1,{16,UINT64_MAX}};
    u::world::World world(profile,std::make_shared<u::world::Session>());
    u::world::World foreign(profile,std::make_shared<u::world::Session>());
    Notifications notifications;
    u::Owner owner(world,notifications);
    world.mode=1;
    world.paused=true;
    world.session().scenario=0;
    check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);
    const auto bytes=[](std::initializer_list<std::uint32_t> words){
        std::vector<std::byte> result;
        for(const auto word:words)
            for(unsigned i=0;i<4;++i)result.push_back(std::byte((word>>(8*i))&255));
        return result;
    };
    const auto program=std::make_shared<const s::Program>(std::vector{
        bytes({1,0x020000f2,7,17,15,0xa}),bytes({1,0xa})});
    check(owner.scripts().install(0,program,{0,0})==s::Status::completed);
    check(owner.scripts().install(1,program,{1,0})==s::Status::completed);
    auto& contacts=world.session().room_contacts;
    Remaining workers;
    EmptyActors actors;
    check(owner.run_workers(workers,actors).status==u::Status::script_failure);
    check(contacts.initialize_counters(2)&&contacts.counters.get(7,17)==1900);
    s::Providers providers;
    providers.world=&foreign;
    check(owner.run_workers(workers,actors,providers).status==u::Status::script_failure);
    check(contacts.counters.get(7,17)==1900&&owner.scripts().channels()[0].current==s::Position{0,0});
    const auto result=owner.run_workers(workers,actors);
    check(result.status==u::Status::completed&&result.script_operations==5);
    check(contacts.counters.get(7,17)==4800&&foreign.session().room_contacts.counters.get(7,17)==0);
}
void check_content_script_binding(){
    namespace content=s::content;
    const u::world::Profile profile{{{1,2,4}},1,{16,UINT64_MAX}};
    u::world::World world(profile,std::make_shared<u::world::Session>());
    Notifications notifications;
    u::Owner owner(world,notifications);
    world.mode=1;
    world.paused=true;
    world.session().scenario=0;
    check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);
    const auto put=[](std::vector<std::byte>& data,std::size_t at,std::uint32_t word){
        for(unsigned byte=0;byte<4;++byte)data.at(at+byte)=std::byte((word>>(8*byte))&255);
    };
    auto scenario=std::make_shared<std::vector<std::byte>>(512);
    put(*scenario,0,128);
    put(*scenario,128,1);
    put(*scenario,132,0x020000f2);
    put(*scenario,136,7);
    put(*scenario,140,17);
    put(*scenario,144,100);
    put(*scenario,148,0xa);
    auto load_scenario=[&](std::uint8_t row){
        return owner.bind_scenario_scripts(content::ScriptBank(scenario,content::BankFormat::scenario_evb),row);
    };
    check(load_scenario(2)==u::Status::script_failure&&!owner.scripts().channels()[0].program);
    put(*scenario,0x34,192);
    put(*scenario,192+2*64,0x1234fedcu);
    check(load_scenario(4)==u::Status::script_failure&&!owner.scripts().channels()[0].program);
    put(*scenario,0x60,492);
    put(*scenario,492,484);
    put(*scenario,496,488);
    put(*scenario,500,UINT32_MAX);
    (*scenario)[490]=std::byte{37};
    check(owner.scripts().restore_counters({1,2,3,4})==s::Status::completed);
    check(load_scenario(2)==u::Status::completed&&owner.scripts().counters()==std::array<std::uint32_t,4>{});
    check(owner.scripts().channels()[0].current==s::Position{0,0}&&!owner.scripts().channels()[4].program);
    auto& auxiliary=world.session().auxiliary_scene;
    auxiliary.select(1);
    check(auxiliary.index(2)==37);
    const auto previous_scenario=owner.scripts().channels()[0].program;
    auto malformed=std::make_shared<std::vector<std::byte>>(*scenario);
    put(*malformed,492,256);
    check(owner.bind_scenario_scripts(content::ScriptBank(malformed,content::BankFormat::scenario_evb),2)==u::Status::script_failure);
    check(owner.scripts().channels()[0].program==previous_scenario);
    check(auxiliary.index(2)==37);
    auto room=std::make_shared<std::vector<std::byte>>(88);
    put(*room,32,64);
    put(*room,48,80);
    put(*room,64,1);
    put(*room,68,0xa);
    put(*room,80,1);
    put(*room,84,0xa);
    auto load_room=[&](std::size_t channel=1){
        return owner.bind_room_scripts(content::ScriptBank(room,content::BankFormat::room_section),channel);
    };
    check(load_room(2)==u::Status::script_failure);
    check(load_room()==u::Status::completed);
    check(owner.scripts().channels()[1].current==s::Position{8,0}&&owner.scripts().channels()[5].current==s::Position{12,0});
    const auto previous=owner.scripts().channels()[1].program;
    put(*room,80,0xd0);
    check(load_room()==u::Status::script_failure);
    check(owner.scripts().channels()[1].program==previous&&owner.scripts().channels()[5].program==previous);
    put(*room,48,0);
    check(load_room()==u::Status::completed&&!owner.scripts().channels()[5].program);
    Remaining workers;
    EmptyActors actors;
    check(owner.run_workers(workers,actors).status==u::Status::completed);
    check(world.session().room_contacts.counters.get(7,17)==-292);
    world.mode=0;
    check(load_room(3)==u::Status::completed);
    check(owner.scripts().channels()[3].program->profile()==s::DispatchProfile::offline_actor);
    check(owner.close()==u::Status::completed&&load_room()==u::Status::closed);
}
void check_auxiliary_timer_order(){
    const u::world::Profile profile{{{1,2,4}},1,{16,UINT64_MAX}};
    u::world::World world(profile,std::make_shared<u::world::Session>());
    Notifications notifications;
    u::Owner owner(world,notifications);
    world.mode=1;
    world.session().scenario=0;
    check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);
    const auto program=std::make_shared<const s::Program>(
        std::vector<std::vector<std::byte>>{{std::byte{1},{},{},{},std::byte{0xa},{},{},{}}});
    check(owner.scripts().install(0,program)==s::Status::completed);
    check(owner.scripts().install(1,program)==s::Status::completed);
    auto& auxiliary=world.session().auxiliary_scene;
    check(auxiliary.set_timer(91,true));
    struct Workers final : u::Services {
        std::optional<std::uint32_t> at_sequence,at_occupancy;
        void run(u::Worker stage,u::Owner& owner) override {
            auto& auxiliary=owner.world().session().auxiliary_scene;
            if(stage==u::Worker::sequences)at_sequence=auxiliary.timer(91);
            if(stage==u::Worker::room_occupancy)at_occupancy=auxiliary.timer(91);
        }
    } workers;
    EmptyActors actors;
    world.paused=1;
    check(owner.run_workers(workers,actors).status==u::Status::completed);
    check(auxiliary.timer(91)==0&&!workers.at_sequence&&!workers.at_occupancy);
    world.paused=0;
    check(owner.run_workers(workers,actors).status==u::Status::completed);
    check(workers.at_sequence==0&&workers.at_occupancy==1&&auxiliary.timer(91)==1);
    check(auxiliary.set_timer(91,false));
    check(owner.run_workers(workers,actors).status==u::Status::completed);
    check(workers.at_sequence==1&&workers.at_occupancy==0&&auxiliary.timer(91)==0);
}
int main()try{
    check_actor_status();
    check_automatic_worker();
    check_session_script_binding();
    check_content_script_binding();
    check_auxiliary_timer_order();
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
