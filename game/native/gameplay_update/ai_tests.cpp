#include "update.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
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
void initialization_owner(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;u::Owner owner(world,notifications);
    const auto id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;check(bool(id));auto actor=world.resolve(id);
    std::array<std::uint8_t,20> bytes{};bytes[0]=0x24;bytes[1]=7;bytes[2]=3;bytes[3]=0x20;bytes[4]=12;bytes[8]=16;
    reo::native::gameplay_navigation::ImportFailure failure;auto asset=reo::native::gameplay_navigation::Asset::read(bytes,failure);check(bool(asset));
    check(world.navigation().bind(std::make_shared<const reo::native::gameplay_navigation::Asset>(std::move(*asset)))&&world.navigation().header_byte()==0x24);
    check(owner.initialize_ai(id).status==ai::Status::completed&&!actor->ai_execution&&!actor->navigation_route&&world.navigation().header_byte()==0);
    actor->ai_control=1;check(owner.initialize_ai(id).status==ai::Status::unavailable&&world.session().ai_control_requests.pending().empty());
    actor->slot=3;actor->ai_execution.emplace();actor->navigation_route.emplace();auto& state=*actor->ai_execution;auto& route=*actor->navigation_route;
    state.goal=42;state.action=9;state.combined_weights.fill(77);route.selection_mode=2;route.refresh=7;route.current_node=-3;
    const auto first=owner.initialize_ai(id);check(first.status==ai::Status::completed&&first.registration==ai::RegistrationStatus::created&&first.publication->status==ai::RequestStatus::queued);
    check(state.goal==0&&state.previous_goal==42&&state.action==0&&state.previous_action==9&&state.weight_profile==0&&state.base_weights==ai::weight_profile(0)->base);
    check(state.combined_weights[0]==77&&state.room_memo==65535&&state.periodic_counter==60&&state.forced_priority==-1&&route.selection_mode==255&&route.refresh==0&&route.current_node==-3);
    auto& controls=world.session().ai_control_requests;
    check(controls.registrations()[0].target==3&&controls.pending().size()==1&&controls.pending()[0].payload==std::array<std::uint8_t,4>{});
    const auto second=owner.initialize_ai(id);check(second.registration==ai::RegistrationStatus::exists&&second.publication->status==ai::RequestStatus::queued&&controls.pending().size()==2);
    for(auto i=controls.pending().size();i<64;++i)(void)ai::publish_actor_control(controls,3,99);
    state.goal=17;const auto limited=owner.initialize_ai(id);check(limited.status==ai::Status::completed&&limited.publication->status==ai::RequestStatus::full&&state.previous_goal==17&&controls.pending().size()==64);
    check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.initialize_ai(id).status==ai::Status::unavailable);
    check(world.close()==u::world::Status::completed&&owner.initialize_ai(id).status==ai::Status::unavailable&&owner.close()==u::Status::completed);
}
void reevaluation_owner(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;u::Owner owner(world,notifications);
    u::scenario::SceneResources resources;
    const auto reference_id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;
    const auto peer_id=world.spawn_primary(2,std::make_unique<u::world::Actor>()).id;
    const auto self_id=world.spawn_primary(3,std::make_unique<u::world::Actor>()).id;
    auto reference=world.resolve(reference_id),peer=world.resolve(peer_id),self=world.resolve(self_id);check(reference&&peer&&self);
    self->slot=1;self->room=reference->room=7;peer->ai_execution.emplace();peer->ai_execution->goal=3;
    check(owner.reevaluate_ai_goal(self_id,resources).status==ai::Status::unavailable);
    self->ai_execution.emplace();auto& state=*self->ai_execution;
    const auto reset=[&]{state={};state.goal=17;state.goal_refresh=1;state.observation_flags=255;state.combined_weights[0]=10;self->character=0;self->motion_class=0;self->status=self->auxiliary_status=0;reference->status=reference->auxiliary_status=0;reference->motion_class=0;peer->ai_execution->goal=3;};
    reset();check(owner.reevaluate_ai_goal(self_id,resources).status==ai::Status::unavailable&&state.observation_flags==255);
    std::vector<std::uint8_t> bytes(184);const auto put=[&](unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::uint8_t(value>>(8*i));};
    put(0,0x20030724);put(4,12);put(8,16);put(16,1);bytes[20]=7;put(24,32);put(32,80);put(36,88);put(40,1);bytes[44]=1;put(60,0xffffffff);
    for(unsigned i=0;i<4;++i){bytes[64+i]=255;bytes[108+i]=255;}
    reo::native::gameplay_navigation::ImportFailure failure;auto asset=reo::native::gameplay_navigation::Asset::read(bytes,failure);check(bool(asset));
    check(world.session().room_variants.store(7,0)&&world.navigation().bind(std::make_shared<const reo::native::gameplay_navigation::Asset>(std::move(*asset))));
    const auto goal=[&](unsigned value){const auto result=owner.reevaluate_ai_goal(self_id,resources);check(result.status==ai::Status::completed&&result.goal_written&&state.goal==value&&state.observation_flags==0);};
    reset();goal(3);check(state.goal_refresh==0);
    reset();reference->status=8;goal(10);check(state.goal_phases[3]==0);
    reset();reference->motion_class=0x30;reference->auxiliary_status=0x01000000;goal(10);check(state.goal_phases[3]==1);
    reset();reference->motion_class=0x25;goal(10);check(state.goal_phases[3]==2);
    reset();reference->status=8;peer->ai_execution->goal=10;goal(3);
    reset();reference->status=8;state.peer_priority=1;goal(3);
    reset();state.reference_request=1;state.goal_resource=0xdeadbeef;reference->equipment_slot=201;goal(11);check(state.goal_resource==201);
    reset();state.owned_request=256;goal(12);check(state.owned_request==0);
    u::scenario::SceneDescriptor descriptor;descriptor.active=128;descriptor.authored_id=0x131;descriptor.attachment_id=0x123;const auto resource=resources.load(73,descriptor);check(bool(resource));
    reset();self->character=7;self->inventory.storage[28]=73;reference->class_marker=2;reference->current=1;reference->maximum=1000;state.goal_resource=0xdeadbeef;goal(3);check(state.goal_resource==0xdeadbeef);
    descriptor.authored_id=0x777;descriptor.attachment_id=0x131;check(resources.replace(*resource,descriptor)==u::scenario::SceneStatus::completed);
    reset();self->character=7;state.goal_resource=0xdeadbeef;goal(15);check(state.goal_resource==0xdeadbe49);
    reset();state.combined_weights.fill(0);state.combined_weights[3]=255;goal(5);
    reset();state.combined_weights.fill(0);state.combined_weights[3]=255;self->status=0x200;goal(2);
    for(unsigned winner:{5u,6u,7u,8u}){reset();state.combined_weights.fill(0);if(winner<8)state.combined_weights[winner]=255;const auto result=owner.reevaluate_ai_goal(self_id,resources);check(result.status==ai::Status::completed&&!result.goal_written&&state.goal==17&&state.observation_flags==0);}
    reset();self->status=8;goal(13);reset();self->motion_class=0x3b;goal(14);
    reset();check(world.retire_primary(2)==u::world::actors::EntityStatus::completed);check(owner.reevaluate_ai_goal(self_id,resources).status==ai::Status::unavailable&&state.observation_flags==0);
    state.goal_refresh=0;check(owner.reevaluate_ai_goal(self_id,resources).status==ai::Status::completed);
    check(world.retire_primary(3)==u::world::actors::EntityStatus::completed&&owner.reevaluate_ai_goal(self_id,resources).status==ai::Status::unavailable);
    check(world.close()==u::world::Status::completed&&owner.reevaluate_ai_goal(reference_id,resources).status==ai::Status::unavailable&&owner.close()==u::Status::completed);
}
void reaction_owner(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;u::Owner owner(world,notifications);
    const auto id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;auto actor=world.resolve(id);check(bool(actor));
    auto& random=world.session().random;random.restore({0,54321,99});
    check(owner.schedule_ai_reaction(id,12).status==ai::Status::unavailable&&random.state().primary==0);
    actor->ai_execution.emplace();auto& state=*actor->ai_execution;state.reaction=77;state.pending_reaction=55;state.reaction_countdown=100;
    auto result=owner.schedule_ai_reaction(id,12);check(result.status==ai::Status::completed&&result.written&&result.random_draws==0&&state.pending_reaction==11&&state.reaction_countdown==5&&state.reaction==77&&random.state().primary==0);
    result=owner.schedule_ai_reaction(id,0);check(result.status==ai::Status::completed&&!result.written&&result.random_draws==1&&state.pending_reaction==11&&state.reaction_countdown==5&&random.state().primary==176);
    random.restore({2,54321,99});result=owner.schedule_ai_reaction(id,0);check(result.written&&result.random_draws==2&&state.pending_reaction==1&&state.reaction_countdown==10&&random.state().primary==61952);
    random.restore({4,54321,99});result=owner.schedule_ai_reaction(id,0);check(result.written&&result.random_draws==2&&state.pending_reaction==11&&random.state().primary==58541&&random.state().secondary==54321&&random.state().observed==99);
    const auto before=random.state();actor->character=255;state.combined_weights.fill(0);state.combined_weights[3]=200;
    result=owner.schedule_ai_reaction(id,5);check(result.written&&result.random_draws==0&&state.pending_reaction==11&&state.reaction_countdown==27&&random.state()==before);
    state.combined_weights.fill(0);const auto old=state;result=owner.schedule_ai_reaction(id,6);check(result.status==ai::Status::unavailable&&state==old&&random.state()==before);
    result=owner.schedule_ai_reaction(id,0xffffffff);check(result.status==ai::Status::completed&&!result.written&&state==old&&random.state()==before);
    check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.schedule_ai_reaction(id,12).status==ai::Status::unavailable&&random.state()==before);
    check(world.close()==u::world::Status::completed&&owner.schedule_ai_reaction(id,12).status==ai::Status::unavailable&&owner.close()==u::Status::completed);
}
void observation_gate_owner(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;u::Owner owner(world,notifications);
    const auto self_id=world.spawn_primary(3,std::make_unique<u::world::Actor>()).id;auto self=world.resolve(self_id);check(bool(self));
    auto& random=world.session().random;random.restore({0,3333,99});
    check(owner.admit_ai_reference_reaction(self_id,0).status==ai::Status::unavailable&&random.state().primary==0);
    self->ai_execution.emplace();self->room=17;auto& state=*self->ai_execution;state.room_memo=65535;
    check(owner.admit_ai_reference_reaction(self_id,0).status==ai::Status::unavailable&&random.state().primary==0);
    auto result=owner.admit_ai_reference_reaction(self_id,1);check(result.status==ai::Status::completed&&result.admitted&&result.random_draws==0&&state.room_memo==65535&&random.state().primary==0);
    const auto reference_id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;auto reference=world.resolve(reference_id);reference->ai_execution.emplace();
    result=owner.admit_ai_reference_reaction(self_id,0);check(result.status==ai::Status::completed&&result.admitted&&result.random_draws==1&&random.state().primary==176);
    reference->ai_execution->weight_mode=255;result=owner.admit_ai_reference_reaction(self_id,0);check(result.admitted&&result.random_draws==0&&random.state().primary==176);
    self->character=2;random.restore({0,3333,99});result=owner.admit_ai_reference_reaction(self_id,1);check(!result.admitted&&result.random_draws==1&&state.room_memo==17&&random.state().primary==176);
    result=owner.admit_ai_reference_reaction(self_id,1);check(!result.admitted&&result.random_draws==0&&random.state().primary==176);
    state.room_memo=65535;random.restore({65363,3333,99});result=owner.admit_ai_reference_reaction(self_id,1);check(!result.admitted&&result.random_draws==1&&state.room_memo==17&&random.state().primary==0);
    self->character=255;state.room_reaction_gate=255;state.room_memo=65535;result=owner.admit_ai_reference_reaction(self_id,1);check(result.status==ai::Status::completed&&!result.admitted&&result.random_draws==0&&state.room_memo==65535);
    state.room_reaction_gate=0;const auto old=state;const auto before=random.state();
    check(owner.admit_ai_reference_reaction(self_id,0).status==ai::Status::unavailable&&state==old&&random.state()==before);
    check(world.retire_primary(0)==u::world::actors::EntityStatus::completed);self->character=0;
    check(owner.admit_ai_reference_reaction(self_id,0).status==ai::Status::unavailable&&random.state()==before);
    check(world.retire_primary(3)==u::world::actors::EntityStatus::completed&&owner.admit_ai_reference_reaction(self_id,0).status==ai::Status::unavailable);
    check(world.close()==u::world::Status::completed&&owner.admit_ai_reference_reaction(self_id,1).status==ai::Status::unavailable&&owner.close()==u::Status::completed);
}
}
int main(){
    try{
        initialization_owner();
        reevaluation_owner();
        reaction_owner();
        observation_gate_owner();
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
