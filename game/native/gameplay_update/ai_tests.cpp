#include "update.hpp"
#include <iostream>
#include <stdexcept>
namespace u=reo::native::gameplay_update;
namespace ai=reo::native::gameplay_ai;
namespace {
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Canonical AI Owner composition check "+std::to_string(checks));}
struct Notifications:u::scenario::FlagNotifications {
    bool changed(const u::scenario::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const u::scenario::StridedFlagChange&)noexcept override{std::terminate();}
};
}
int main(){
    try{
        u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());
        Notifications notifications;u::Owner owner(world,notifications);
        const auto id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;check(bool(id));
        check(owner.set_ai_goal(id,0)==ai::Status::unavailable&&owner.set_ai_action(id,0)==ai::Status::unavailable&&owner.select_ai_weight_profile(id,0)==ai::Status::unavailable);
        auto actor=world.resolve(id);actor->ai_execution.emplace();auto& state=*actor->ai_execution;
        actor->navigation_route.emplace();actor->navigation_route->action=123;actor->navigation_route->previous_action=456;
        state.goal=17;state.previous_goal=99;state.goal_phases.fill(255);state.goal_parameters.fill(65535);state.action=27;state.previous_action=98;state.action_phases.fill(254);state.action_marker=42;
        check(owner.set_ai_goal(id,256)==ai::Status::completed&&state.goal==256&&state.previous_goal==99&&state.goal_refresh==0);
        check(state.goal_phases==std::array<std::uint8_t,4>{}&&state.goal_parameters==std::array<std::uint16_t,4>{}&&state.action==27&&state.action_marker==42);
        check(owner.set_ai_goal(id,65536)==ai::Status::completed&&state.goal==0&&state.previous_goal==256&&state.goal_refresh==1);
        check(owner.set_ai_action(id,0x10004)==ai::Status::completed&&state.action==4&&state.previous_action==27&&state.action_marker==0&&state.action_phases==std::array<std::uint8_t,4>{});
        check(actor->navigation_route->action==123&&actor->navigation_route->previous_action==456);
        state.reactive_weights.fill(7);state.status_weights.fill(8);state.combined_weights.fill(9);
        check(owner.select_ai_weight_profile(id,19)==ai::Status::completed&&state.weight_profile==19&&state.base_weights==ai::weight_profile(19)->base);
        const std::array<std::uint8_t,8> combined{9,9,9,9,9,9,9,9};
        check(state.reactive_weights==std::array<std::uint8_t,8>{}&&state.status_weights==std::array<std::uint8_t,8>{}&&state.combined_weights==combined);
        const auto before=state;check(owner.select_ai_weight_profile(id,20)==ai::Status::completed&&state==before);
        check(owner.select_ai_weight_profile(id,-1)==ai::Status::unavailable&&state==before);
        actor->slot=5;auto& controls=world.session().ai_control_requests;
        check(owner.publish_ai_control(id,1)->status==ai::RequestStatus::missing_registration&&controls.pending().empty());
        check(owner.register_ai_control(id)==ai::RegistrationStatus::created&&owner.register_ai_control(id)==ai::RegistrationStatus::exists);
        check(controls.registrations()[0].kind==0&&controls.registrations()[0].target==5&&controls.registrations()[0].owner_tag==255);
        check(owner.publish_ai_control(id,0x12345678)->status==ai::RequestStatus::queued&&controls.pending().size()==1);
        check(controls.pending()[0].registration==0&&controls.pending()[0].payload==std::array<std::uint8_t,4>{0x78,0,0,0});
        const std::array<std::uint8_t,9> value_packet{0,9,0,0,0,0x22,0x33,0x44,0x55};
        check(!owner.ai_activity_mode()&&owner.receive_ai_controls(value_packet).status==ai::ControlApplyStatus::completed&&controls.registrations()[0].payload==std::array<std::uint8_t,4>{0x22,0x33,0x44,0x55});
        const std::array<std::uint8_t,6> owner_packet{1,6,0,0,0,77};
        check(owner.receive_ai_controls(owner_packet).status==ai::ControlApplyStatus::unavailable&&controls.registrations()[0].owner_tag==255);
        world.session().activity.single=1;check(owner.ai_activity_mode()==1&&owner.receive_ai_controls(owner_packet).status==ai::ControlApplyStatus::completed&&controls.registrations()[0].owner_tag==255);
        world.session().activity.single=0;check(owner.ai_activity_mode()==0&&owner.receive_ai_controls(owner_packet).status==ai::ControlApplyStatus::completed&&controls.registrations()[0].owner_tag==77);
        world.mode=1;check(!owner.ai_activity_mode());world.session().activity.online=-1;check(owner.ai_activity_mode()==-1);world.mode=2;check(owner.ai_activity_mode()==1);world.mode=0;
        check(owner.publish_ai_control(id,0)->status==ai::RequestStatus::missing_registration&&controls.pending().size()==1);
        u::world::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());const auto other=foreign.spawn_primary(0,std::make_unique<u::world::Actor>()).id;
        check(owner.set_ai_goal(other,0)==ai::Status::unavailable&&owner.set_ai_action(other,0)==ai::Status::unavailable&&owner.select_ai_weight_profile(other,0)==ai::Status::unavailable);
        check(!owner.register_ai_control(other)&&!owner.publish_ai_control(other,0)&&controls.pending().size()==1);
        check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.set_ai_goal(id,0)==ai::Status::unavailable);
        check(!owner.register_ai_control(id)&&!owner.publish_ai_control(id,0)&&controls.pending().size()==1);
        check(world.close()==u::world::Status::completed&&owner.set_ai_action(id,0)==ai::Status::unavailable&&owner.select_ai_weight_profile(id,0)==ai::Status::unavailable);
        check(!owner.ai_activity_mode()&&owner.receive_ai_controls(value_packet).status==ai::ControlApplyStatus::unavailable);
        check(owner.close()==u::Status::completed);std::cout<<"{\"checks\":"<<checks<<"}\n";
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
