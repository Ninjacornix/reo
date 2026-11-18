#include "session_collision_frame.hpp"
#include "session_collision_inputs.hpp"
#include "../gameplay_world/actor_assets.hpp"
#include "../gameplay_world/linked_models.hpp"
#include "runtime/assets/virtual_afs.h"
#include <bit>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace s=reo::native::gameplay_scenario;
namespace c=reo::native::gameplay_collision;
namespace {
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Collision frame check at "+std::to_string(at.line()));
}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return false;}
    bool changed(const s::StridedFlagChange&)noexcept override{return false;}
};
// Explicit controlled fixture for functionality outside this collision cut.
struct Phases final:u::PhaseServices {
    w::World* world{};float moved{};unsigned calls{};
    void run(u::Worker stage,u::Owner&)override{++calls;if(stage==u::Worker::auxiliary_actors)moved=world->primary(0)->position.x;}
    bool button(u::Button,u::Owner&)override{return true;}
    bool transition_request(u::Owner&)override{return false;}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{}
};
struct Actors final:w::Services {
    unsigned behavior{};
    void begin_offline_frame(w::World&)override{throw std::runtime_error("Unexpected offline frame");}
    void run(w::Stage stage,w::World&,w::Actor& actor)override{
        if(stage==w::Stage::update_behavior){++behavior;actor.previous_position=actor.position;}
    }
    bool remote_motion(w::World&,w::Actor&)override{return false;}
    bool find_grid(w::World&,w::Actor&,std::int8_t&)override{return false;}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{throw std::runtime_error("Unexpected grid switch");}
    float grid_response(w::World&,std::uint8_t)override{throw std::runtime_error("Unexpected grid response");}
};
struct Inputs final:a::SessionCollisionInputs {
    unsigned body_calls{},height_calls{};bool wrong_identity{};
    u::BodyFrame bodies(u::Owner& owner)override{
        ++body_calls;u::BodyFrame frame;
        if(wrong_identity)frame.additional.push_back({owner.world().identity(0),std::make_shared<w::Actor>(),{}});
        return frame;
    }
    u::HeightFrame secondary_heights(u::Owner&)override{++height_calls;return{};}
};
struct Walls final:w::SecondaryCollisionWalls {
    void correct(const w::actors::EntityId&,c::ground::View,const w::CollisionRoom&)override{
        throw std::runtime_error("Unexpected secondary population");
    }
};
// This deliberately stops immediately after the actual control preparation.
struct Behavior final:w::BehaviorServices {
    [[noreturn]] static void stop(){throw std::runtime_error("Controlled behavior boundary");}
    void run(w::BehaviorStage stage,w::World&,w::Actor&)override{
        if(stage==w::BehaviorStage::prepare_control)throw std::logic_error("Control must use canonical consumer");
        if(stage==w::BehaviorStage::analog_control)stop();
    }
    void dispatch(w::ActionPass,std::uint8_t,w::World&,w::Actor&)override{stop();}
    bool suppress_action_notice(w::World&,w::Actor&,std::uint8_t,std::uint8_t)override{stop();}
    bool authority_filter(w::actors::HealthSession&)override{stop();}
    std::int32_t selected_authority(w::actors::HealthSession&,std::uint8_t)override{stop();}
    void refresh_class(w::actors::HealthState&,w::actors::HealthSession&)override{stop();}
    void feedback(w::actors::StatusActor&,w::actors::StatusSession&,std::uint8_t)override{stop();}
    void publish(w::actors::StatusActor&,w::actors::StatusSession&,std::uint8_t)override{stop();}
    void cleanup(w::actors::StatusActor&,w::actors::StatusSession&)override{stop();}
    void recover(w::actors::StatusActor&,w::actors::StatusSession&)override{stop();}
    void snapshot(w::actors::StatusActor&,w::actors::StatusSession&)override{stop();}
    bool locally_controlled(w::actors::HitActor&,w::actors::HitSession&)override{stop();}
    std::uint32_t partner_flags(std::uint8_t)override{stop();}
    std::uint8_t partner_character(std::uint8_t)override{stop();}
    std::uint16_t scene_owner(std::uint8_t)override{stop();}
    void event(w::actors::HitActor&,w::actors::HitSession&,std::uint32_t,std::uint32_t)override{stop();}
    void add_status(w::actors::HitActor&,w::actors::HitSession&,std::uint8_t)override{stop();}
    void close_inventory(w::actors::HitActor&,w::actors::HitSession&)override{stop();}
    void detach_scene(w::actors::HitActor&,w::actors::HitSession&,std::uint8_t,std::uint8_t)override{stop();}
    void release_equipment(w::actors::HitActor&,w::actors::HitSession&,std::uint8_t)override{stop();}
    void cancel_action(w::actors::HitActor&,w::actors::HitSession&)override{stop();}
    void apply_progression(w::actors::HitActor&,w::actors::HitSession&,std::uint16_t)override{stop();}
    void refresh_statistics(w::actors::HitActor&,w::actors::HitSession&)override{stop();}
    void finish_contact_state(w::actors::HitActor&,w::actors::HitSession&)override{stop();}
    void clear_hit_relations(w::actors::HitActor&,w::actors::HitSession&)override{stop();}
};
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::invalid_argument("Owned scenario archive path required");
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);Notices notices;
    w::Profile profile;profile.layouts.push_back({});
    auto session=std::make_shared<a::NativeSession>(source,profile,notices,1);
    auto rooms=std::make_shared<a::SessionRooms>(session);Phases phases;phases.world=&session->world();
    Actors actors;Inputs inputs;Walls walls;
    a::SessionCollisionFrame frame(session,rooms,phases,actors,inputs,walls);
    check(frame.advance().status==a::SessionStatus::missing_room);
    check(session->install_room({41,73,0})==a::SessionStatus::completed);
    session->update().state.scripts_enabled=false;
    check(session->update().initialize_completion_statistics()==reo::native::gameplay_events::StatisticsStatus::completed);
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},{},{},{},std::byte{0xa},{},{},{}}});
    check(session->update().scripts().install(0,program)==s::Status::completed);
    check(session->update().scripts().install(1,program)==s::Status::completed);
    w::ActorAssets assets(source);
    const auto model=assets.read_primary(0,0,0);
    for(unsigned i=0;i<2;++i){auto actor=std::make_unique<w::Actor>();actor->active=true;actor->room=73;actor->slot=std::uint8_t(i);
        actor->position={0,0,float(i)};actor->root_motion_delta={0.25f,0,0};
        actor->collision.body_definition=c::actors::ShapeDefinition{c::actors::ShapeKind::sphere,2,{},{}};
        const auto id=session->world().spawn_primary(i,std::move(actor)).id;check(bool(id));
        check(w::bind_actor_model_asset(session->world(),id,model));
        const auto current=session->world().primary(i);
        check(current->model&&current->model->nodes().size()>11);
        // Target caches read the preceding published pose before actor motion.
        // Supply the fixture's initial pose through the actual model owner.
        auto basis=reo::native::transform_math::identity();
        basis[3]={current->position.x,current->position.y,current->position.z,1};
        current->model->rebuild(basis);check(bool(current->model->retain()));}
    const auto result=frame.advance();
    check(result.status==a::SessionStatus::completed&&result.update.actors.updated==2&&result.update.clock_committed);
    check(actors.behavior==2&&phases.moved==0.25f&&inputs.body_calls==1&&inputs.height_calls==1);
    check(frame.workers().target_progress()==u::CollisionProgress::completed&&frame.workers().body_progress()==u::CollisionProgress::completed&&frame.workers().height_progress()==u::CollisionProgress::completed);
    check(frame.workers().last_bodies()->solve.contacts>0&&frame.workers().last_heights()->primary.eligible==2);
    check(frame.bodies().pending()==0&&session->update().clock().update_counter()==1);
    inputs.wrong_identity=true;bool refused{};
    try{(void)frame.advance();}catch(const std::runtime_error&){refused=true;}
    check(refused&&frame.workers().body_progress()==u::CollisionProgress::failed&&
        frame.bodies().pending()==2&&session->update().clock().update_counter()==1);
    check(frame.bodies().clear());inputs.wrong_identity=false;
    check(frame.advance().status==a::SessionStatus::completed&&session->update().clock().update_counter()==2);
    auto actor=session->world().primary(0);actor->primary=0;actor->status=0;actor->auxiliary_status=0;
    actor->transient_equipment=1;actor->control_request={8,0};Behavior behavior;bool boundary{};
    try{(void)frame.advance_behavior(behavior,{});}catch(const std::runtime_error& error){boundary=std::string(error.what())=="Controlled behavior boundary";}
    check(boundary&&!actor->transient_equipment&&actor->primary==1&&actor->secondary==0x2e&&actor->subphase==2&&actor->response_lock==1);
    check(frame.bodies().pending()==0&&session->update().clock().update_counter()==2);
    // Real secondary owner, reverse linked-pool traversal and actual frame
    // workers; only the unrelated phase/behavior services above are fixtures.
    a::SessionCollisionPopulation population(session);
    auto& linked=session->world().linked_models();
    const auto first=linked.allocate(false),second=linked.allocate(false);
    check(first.status==w::LinkedStatus::completed&&second.status==w::LinkedStatus::completed);
    const auto one=linked.resolve(first.id),two=linked.resolve(second.id);
    one->slot=0x2d;one->contact_flags=0x20;one->position={0,50,0};
    one->collision.displacement={2,3,4};one->material_uv->u=std::bit_cast<float>(0x3f800100u);
    two->slot=7;two->contact_flags=1;two->position={0,50,0};
    two->collision.contact=true;two->collision.local_center={2,3,4};
    two->collision.basis.x={1,0,0};two->collision.basis.y={0,1,0};two->collision.basis.z={0,0,1};
    session->world().session().message_phase=2;session->world().session().clock_mode=1;
    const auto body=population.bodies(session->update());
    check(body.limit_repeated&&body.fast_tick&&body.additional.size()==2&&
        body.additional[0].id==second.id&&body.additional[1].id==first.id);
    auto heights=population.secondary_heights(session->update());
    check(heights.secondary.size()==2&&heights.secondary[0].id==second.id&&heights.secondary[1].id==first.id);
    a::SessionCollisionFrame actual(session,rooms,phases,actors,population,population);
    check(actual.advance().status==a::SessionStatus::completed);
    check(actual.workers().last_heights()->secondary.visited==2&&
        actual.workers().last_heights()->secondary.wall_queries==1&&
        actual.workers().last_heights()->secondary.displaced==1);
    check(one->position.x==2&&one->position.z==4&&!two->collision.contact&&
        two->collision.previous_center_offset.x==2&&two->collision.previous_center_offset.y==3);
    const auto bits=std::bit_cast<std::uint32_t>(one->material_uv->u);
    check((bits&~0xff00u)==(0x3f800100u&~0xff00u)&&
        ((bits>>8&0xffu)==0||(bits>>8&0xffu)==1||(bits>>8&0xffu)==255));
    session->world().session().message_phase=3;session->world().session().clock_mode=0;
    const auto slow=population.bodies(session->update());check(!slow.limit_repeated&&!slow.fast_tick);
    check(session->close()==a::SessionStatus::completed&&frame.advance().status==a::SessionStatus::closed);
    std::cout<<"Native collision frame passed "<<checks<<" checks (controlled non-collision providers)\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
