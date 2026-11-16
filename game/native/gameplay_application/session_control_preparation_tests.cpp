#include "session_control_preparation.hpp"
#include "../gameplay_scenario/actor_requests.hpp"
#include <iostream>
#include <source_location>
#include <stdexcept>

namespace app=reo::native::gameplay_application;
namespace world=reo::native::gameplay_world;
namespace scenario=reo::native::gameplay_scenario;
namespace {
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;
    if(!value)throw std::runtime_error("Control preparation check at "+std::to_string(at.line()));
}
world::Profile profile(){world::Profile value;value.layouts.push_back({});return value;}
}
int main()try{
    auto state=std::make_shared<world::Session>();
    world::World actual(profile(),state),foreign(profile(),std::make_shared<world::Session>());
    app::SessionControlPreparation controls(actual);
    auto value=std::make_unique<world::Actor>();value->active=true;value->slot=0;
    value->position={2,3,4};value->orientation[1]=123;
    const auto id=actual.spawn_primary(0,std::move(value)).id;
    check(bool(id));auto actor=actual.resolve(id);
    check(controls.prepare_control(actual,*actor));
    check(scenario::queue_actor_request(actual,5,0)==scenario::ActorRequestStatus::completed);
    check(actor->transient_equipment==1&&actor->response_lock==0);
    check(controls.prepare_control(actual,*actor));
    check(actor->transient_equipment==0&&actor->response_lock==1&&state->control_notice==1);
    check(scenario::queue_actor_request(actual,8,0)==scenario::ActorRequestStatus::completed);
    actor->input.held=0x123;actor->input.pressed=0x100;actor->input.released=0x10;actor->input.repeat=0x20;
    check(controls.prepare_control(actual,*actor));
    check(actor->primary==1&&actor->secondary==0x2e&&actor->phase==0&&actor->subphase==2);
    check(actor->saved_action_position.x==2&&actor->saved_action_position.y==3&&
          actor->saved_action_position.z==4&&actor->saved_action_yaw==123);
    check(actor->input.history[0]==0x123&&actor->input.held==0x123&&
          actor->input.pressed==0&&actor->input.released==0&&actor->input.repeat==0);
    actor->transient_equipment=1;actor->control_request={0xff,7};actor->status=0;
    check(!controls.prepare_control(actual,*actor));
    check(actor->transient_equipment==1&&actor->control_request.kind==0xff&&actor->control_request.parameter==7);
    check(!controls.prepare_control(foreign,*actor));
    check(actor->transient_equipment==1);
    // Original terminal status clears a request before callback selection,
    // including a kind outside the ordinary admitted consumer profile.
    actor->status=0x80;
    check(controls.prepare_control(actual,*actor)&&actor->transient_equipment==0);
    actor->status=0;actor->transient_equipment=1;actor->control_request={5,0};
    check(actual.retire_primary(0)==world::actors::EntityStatus::completed);
    check(!controls.prepare_control(actual,*actor)&&actor->transient_equipment==1);
    auto replacement=std::make_unique<world::Actor>();replacement->active=true;
    check(bool(actual.spawn_primary(0,std::move(replacement)).id));
    check(!controls.prepare_control(actual,*actor)&&actor->transient_equipment==1);
    check(actual.close()==world::Status::completed);
    check(!controls.prepare_control(actual,*actor));
    std::cout<<"Native session control preparation passed "<<checks<<" checks\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
