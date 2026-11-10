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
        u::world::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());const auto other=foreign.spawn_primary(0,std::make_unique<u::world::Actor>()).id;
        check(owner.set_ai_goal(other,0)==ai::Status::unavailable&&owner.set_ai_action(other,0)==ai::Status::unavailable&&owner.select_ai_weight_profile(other,0)==ai::Status::unavailable);
        check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.set_ai_goal(id,0)==ai::Status::unavailable);
        check(world.close()==u::world::Status::completed&&owner.set_ai_action(id,0)==ai::Status::unavailable&&owner.select_ai_weight_profile(id,0)==ai::Status::unavailable);
        check(owner.close()==u::Status::completed);std::cout<<"{\"checks\":"<<checks<<"}\n";
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
