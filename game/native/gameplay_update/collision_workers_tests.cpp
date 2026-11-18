#include "collision_workers.hpp"
#include "../gameplay_world/motion_transforms.hpp"
#include "../gameplay_world/surface_orientation.hpp"
#include "../gameplay_world/linked_models.hpp"
#include "../animation/model.hpp"
#include <cmath>
#include <cstring>
#include <iostream>
#include <source_location>
namespace u=reo::native::gameplay_update;
namespace g=reo::native::gameplay_world;
namespace c=reo::native::gameplay_collision;
namespace s=reo::native::gameplay_scenario;
unsigned checks{};
void check(bool value,std::source_location location=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Collision worker check "+std::to_string(checks)+" at line "+std::to_string(location.line()));
}
g::Profile profile(){return{{{0x100,0x10,0x20}},1,{16,2}};}
template<class T>void put(std::span<std::byte> bytes,unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof(T));}
std::shared_ptr<const reo::native::animation::Skeleton> cache_skeleton(){
    std::array<std::byte,28+12*84> raw{};put(raw,4,13u);put(raw,8,std::uint32_t(raw.size()));put(raw,16,1u);put(raw,20,16u);
    for(unsigned i=0;i<12;++i){const unsigned at=28+84*i,node=at+12;put(raw,at,1u);put(raw,at+4,1u);put(raw,at+8,84u);put(raw,node,i);put(raw,node+8,i==0?1u:0xffffffffu);put(raw,node+12,i>0&&i<11?i+1:0xffffffffu);for(unsigned lane=0;lane<3;++lane)put(raw,node+0x10+4*lane,1.f);}
    return reo::native::animation::Skeleton::import_raw(raw);
}
c::response::Grid cache_grid(){
    std::array<std::byte,48> raw{};put(raw,8,1000u);put(raw,12,1000u);put(raw,16,1u);put(raw,20,1u);put(raw,32,32u);put(raw,36,40u);put(raw,40,36u);put(raw,44,0xffffffffu);
    return c::response::Grid::import(raw);
}
struct Notifications:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
struct Secondary:g::actors::Entity {
    c::Vec3 position{1,2,3},normal{0,1,0},displacement;
    float height{};std::uint8_t surface{},material{},subtype{};
    std::uint16_t attributes{},controls{};std::uint32_t status{};
    std::array<std::int16_t,3> rotation{};c::ground::ProbeStates states;
};
struct Scene:u::CollisionParticipants {
    g::World& world;g::WorldBodies& queue;g::actors::EntityStore entities{{8,2}};
    g::actors::EntityId auxiliary_id,secondary_id;
    c::response::Grid walls,floors;c::regions::World regions;c::room_objects::Owner objects;
    unsigned body_acquires{},height_acquires{},room_acquires{};bool fail_body_acquire{},missing_secondary_lease{},fail_room_acquire{};
    Scene(g::World& w,g::WorldBodies& b):world(w),queue(b),walls(cache_grid()),floors(cache_grid()){
        auto actor=std::make_unique<g::Actor>();actor->active=true;actor->room=1;actor->category=2;
        actor->position={100,0,0};actor->previous_position=actor->position;actor->collision.pose_ready=true;
        actor->collision.body_definition=c::actors::ShapeDefinition{c::actors::ShapeKind::sphere,1,{},{}};
        actor->collision.local_center={9,0,0};actor->contact_flags=3;
        auxiliary_id=entities.create(std::move(actor)).id;secondary_id=entities.create(std::make_unique<Secondary>()).id;
        check(bool(auxiliary_id) && bool(secondary_id));
    }
    std::shared_ptr<g::Actor> auxiliary(){return std::dynamic_pointer_cast<g::Actor>(entities.acquire(auxiliary_id));}
    std::shared_ptr<Secondary> secondary(){return std::dynamic_pointer_cast<Secondary>(entities.acquire(secondary_id));}
    u::BodyFrame bodies_frame(){return{{{auxiliary_id,auxiliary(),{}}},world.identity(world.selected_actor),false,false};}
    u::BodyFrame bodies(u::Owner&)override{
        ++body_acquires;if(fail_body_acquire)throw std::runtime_error("Declared scene acquisition failure");
        check(queue.pending()==3);return bodies_frame();
    }
    u::HeightFrame heights(u::Owner&)override{
        ++height_acquires;auto actor=secondary();check(bool(actor));
        u::HeightFrame result;result.auxiliary.push_back(auxiliary());
        if(!missing_secondary_lease)result.secondary_owners.push_back(actor);
        const c::ground::View view{actor->position,actor->normal,actor->height,actor->surface,actor->material,
            actor->attributes,actor->status,{actor->rotation[0],actor->rotation[1],actor->rotation[2]}};
        result.secondary.push_back({secondary_id,view,actor->displacement,actor->controls,actor->subtype,actor->states});
        return result;
    }
    g::CollisionRoom room(u::Owner&)override{++room_acquires;if(fail_room_acquire)throw std::runtime_error("Declared room acquisition failure");return{walls,floors,regions,objects,{},{},false,false};}
};
struct Poses:g::BodyPoses {
    std::shared_ptr<const g::JointPose> retain(const g::actors::EntityId&,const g::Actor&)override{
        throw std::runtime_error("The fixture body has no joint references");
    }
};
struct Remaining:u::PhaseServices {
    Scene& scene;g::WorldBodies& bodies;std::vector<u::Worker> calls;unsigned buttons{},effects{},transitions{};
    Remaining(Scene& s,g::WorldBodies& b):scene(s),bodies(b){}
    void run(u::Worker stage,u::Owner&)override{
        check(stage!=u::Worker::actor_collision_shapes && stage!=u::Worker::collision_heights && stage!=u::Worker::target_caches);calls.push_back(stage);
        if(stage==u::Worker::auxiliary_actors)check(bodies.add({scene.auxiliary_id,3,2}));
    }
    bool button(u::Button,u::Owner&)override{++buttons;return false;}
    bool transition_request(u::Owner&)override{++transitions;return false;}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{++effects;}
};
struct Frame:g::Services {
    unsigned required_behavior{};
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World&,g::Actor& actor)override{
        // Individual behavior remains an explicit fixture, not a successful
        // native action implementation. Real motion/pose/queue stages compose.
        if(stage==g::Stage::update_behavior)++required_behavior;
        if(stage==g::Stage::finish_actor)actor.contact_flags|=3;
    }
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
    float grid_response(g::World&,std::uint8_t)override{return 0;}
};
struct SecondaryWalls:g::SecondaryCollisionWalls {
    Scene& scene;unsigned calls{};
    explicit SecondaryWalls(Scene& s):scene(s){}
    void correct(const g::actors::EntityId& id,c::ground::View view,const g::CollisionRoom& room)override{
        ++calls;check(id==scene.secondary_id && !room.height_layers);
        check(scene.auxiliary()->collision.previous_center_offset.x==9);
        view.position.x+=1;
    }
};
void install(u::Owner& owner){
    owner.world().session().scenario=0;check(owner.initialize_completion_statistics()==reo::native::gameplay_events::StatisticsStatus::completed);
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{
        {std::byte{1},std::byte{},std::byte{},std::byte{},std::byte{0xa},std::byte{},std::byte{},std::byte{}}});
    for(std::size_t i=0;i<6;++i)check(owner.scripts().install(i,program)==s::Status::completed);
}
int main()try{
    g::World world(profile(),std::make_shared<g::Session>());world.mode=1;world.room=1;world.selected_actor=0;
    const auto skeleton=cache_skeleton();
    for(unsigned i=0;i<2;++i){auto actor=std::make_unique<g::Actor>();actor->active=true;actor->room=1;actor->slot=std::uint8_t(i);
        actor->position={float(i),0,0};actor->previous_position=actor->position;actor->root_motion_delta={.25f,0,0};
        actor->collision.body_definition=c::actors::ShapeDefinition{c::actors::ShapeKind::sphere,2,{},{}};
        actor->model=std::make_shared<reo::native::animation::Instance>(skeleton);auto basis=reo::native::transform_math::identity();basis[3][0]=float(i);actor->model->rebuild(basis);
        check(world.spawn_primary(i,std::move(actor)).status==g::actors::EntityStatus::completed);}
    const auto target_id=world.linked_models().allocate(false).id;auto target=world.resolve(target_id);check(bool(target));
    target->active=true;target->room=1;target->position={50,0,10};target->targeting=g::TargetingState{};
    const auto target_slot=world.linked_models().physical_slot(target_id).value();
    Notifications notifications;u::Owner owner(world,notifications);install(owner);g::WorldBodies bodies(world);Scene scene(world,bodies);
    Remaining remaining(scene,bodies);Poses poses;SecondaryWalls secondary_walls(scene);
    u::CollisionWorkers workers(world,remaining,bodies,poses,scene,secondary_walls);
    Frame frame;g::GridSurfaceOrientation surface(scene.floors);g::MotionFrameServices motion(frame,bodies);
    g::MotionTransformFrameServices actor_services(motion,surface);
    check(workers.body_progress()==u::CollisionProgress::never_run && !workers.last_bodies());
    check(workers.target_progress()==u::CollisionProgress::never_run&&!workers.last_targets()&&!world.target_metrics().state());
    auto result=owner.run_workers(workers,actor_services);
    check(result.status==u::Status::completed && result.actors.updated==2 && frame.required_behavior==2);
    check(workers.body_progress()==u::CollisionProgress::completed && workers.height_progress()==u::CollisionProgress::completed);
    check(workers.last_bodies()->solve.visited==3 && workers.last_bodies()->solve.contacts>0 && bodies.pending()==0);
    check(workers.last_heights()->primary.eligible==2 && workers.last_heights()->auxiliary_visited==1 && workers.last_heights()->secondary.visited==1);
    check(scene.body_acquires==1 && scene.height_acquires==1 && secondary_walls.calls==1 && scene.secondary()->position.x==2);
    check(workers.target_progress()==u::CollisionProgress::completed&&workers.last_targets()->pairs==2&&workers.last_targets()->wall_queries==2&&workers.last_targets()->floor_queries==2&&scene.room_acquires==2);
    const auto* metrics=world.target_metrics().state();check(metrics&&metrics->linked_identity[target_slot]==target_id&&metrics->primary_linked[0][target_slot]->pair.distance==std::sqrt(2600.f));
    check(world.primary(0)->collision.pose_ready && world.primary(1)->collision.pose_ready && owner.clock().update_counter()==0);
    check(!workers.button(u::Button::primary,owner) && !workers.transition_request(owner));workers.effect(u::PhaseEffect::finish_audio,owner,0);
    check(remaining.buttons==1 && remaining.transitions==1 && remaining.effects==1);
    world.paused=1;result=owner.run_workers(workers,actor_services);check(result.status==u::Status::completed&&scene.room_acquires==2&&workers.target_progress()==u::CollisionProgress::completed);world.paused=0;
    scene.fail_room_acquire=true;bool room_failed=false;
    try{owner.run_workers(workers,actor_services);}catch(const std::runtime_error& error){if(std::string(error.what())!="Declared room acquisition failure")throw;room_failed=true;}
    check(room_failed&&workers.target_progress()==u::CollisionProgress::failed&&!workers.last_targets()&&!world.target_metrics().state()&&scene.body_acquires==1);
    scene.fail_room_acquire=false;
    scene.fail_body_acquire=true;bool failed{};
    try{owner.run_workers(workers,actor_services);}catch(const std::runtime_error& error){
        if(std::string(error.what())!="Declared scene acquisition failure")throw;
        failed=true;
    }
    check(failed && workers.body_progress()==u::CollisionProgress::failed && !workers.last_bodies());
    check(!workers.last_heights() && workers.height_progress()==u::CollisionProgress::never_run);
    check(scene.height_acquires==1 && bodies.pending()==3 && bodies.clear());scene.fail_body_acquire=false;
    scene.missing_secondary_lease=true;failed=false;
    try{owner.run_workers(workers,actor_services);}catch(const std::invalid_argument&){failed=true;}
    check(failed && workers.body_progress()==u::CollisionProgress::completed && workers.height_progress()==u::CollisionProgress::failed && !workers.last_heights());
    check(bodies.pending()==0 && secondary_walls.calls==1);scene.missing_secondary_lease=false;
    result=owner.run_workers(workers,actor_services);check(result.status==u::Status::completed && secondary_walls.calls==2);
    g::World foreign(profile(),std::make_shared<g::Session>());Notifications other;u::Owner foreign_owner(foreign,other);failed=false;
    try{workers.button(u::Button::primary,foreign_owner);}catch(const std::invalid_argument&){failed=true;}
    check(failed && remaining.buttons==1);failed=false;g::WorldBodies wrong(foreign);
    try{u::CollisionWorkers invalid(world,remaining,wrong,poses,scene,secondary_walls);}catch(const std::invalid_argument&){failed=true;}
    check(failed);check(owner.close()==u::Status::completed && world.session().timing==nullptr);
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
