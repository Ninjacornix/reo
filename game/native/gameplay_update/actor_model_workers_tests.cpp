#include "actor_model_workers.hpp"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace u=reo::native::gameplay_update;
namespace g=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace a=reo::native::animation;
void check(bool yes,std::source_location at=std::source_location::current()){
    if(!yes)throw std::runtime_error("Actor model worker check at "+std::to_string(at.line()));
}
std::shared_ptr<a::Instance> model(){
    constexpr unsigned count=22;std::vector<std::byte> bytes(28+84*count);
    const auto put=[&](unsigned offset,auto value){std::memcpy(bytes.data()+offset,&value,sizeof value);};
    put(4,count+1);put(8,unsigned(bytes.size()));put(16,1u);put(20,16u);put(24,0u);
    for(unsigned i=0;i<count;++i){const unsigned record=28+84*i,node=record+12;
        put(record,1u);put(record+4,1u);put(record+8,84u);
        put(node+8,UINT32_MAX);put(node+12,i+1<count?i+1:UINT32_MAX);
        for(unsigned axis=0;axis<3;++axis)put(node+16+4*axis,1.f);
    }
    auto result=std::make_shared<a::Instance>(a::Skeleton::import_raw(bytes));
    result->rebuild(reo::native::transform_math::identity());return result;
}
struct Notifications final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
struct UnreachedBehavior final:g::Services {
    void begin_offline_frame(g::World&)override{std::terminate();}
    void run(g::Stage,g::World&,g::Actor&)override{std::terminate();}
    bool remote_motion(g::World&,g::Actor&)override{std::terminate();}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{std::terminate();}
    float grid_response(g::World&,std::uint8_t)override{std::terminate();}
};
struct Remaining final:u::PhaseServices {
    g::World& world;g::actors::EntityId primary,auxiliary;std::vector<u::Worker> calls;
    unsigned publications_seen{},buttons{},effects{};
    Remaining(g::World& value,g::actors::EntityId p,g::actors::EntityId q):world(value),primary(p),auxiliary(q){}
    void run(u::Worker stage,u::Owner&)override{
        check(stage!=u::Worker::primary_model_poses&&stage!=u::Worker::auxiliary_model_poses);
        // The declared fixture boundary activates actors after behavior. The
        // actual model stages must see these same-pass creations before hits.
        if(stage==u::Worker::actor_collision_shapes){world.resolve(primary)->active=true;world.resolve(auxiliary)->active=true;}
        if(stage==u::Worker::primary_hit_regions){
            for(const auto& id:{primary,auxiliary}){const auto actor=world.resolve(id);check(actor->model->retain()!=nullptr);check(actor->collision.basis.translation.x==actor->position.x);}
            ++publications_seen;
        }
        calls.push_back(stage);
    }
    bool button(u::Button,u::Owner&)override{++buttons;return true;}
    bool transition_request(u::Owner&)override{return true;}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{++effects;}
};
int main()try{
    g::Profile profile;profile.layouts.push_back({1,2,4});profile.controller_count=1;profile.entities.capacity=32;
    g::World world(profile,std::make_shared<g::Session>());world.mode=1;world.session().scenario=0;
    Notifications notifications;u::Owner owner(world,notifications);owner.state.scripts_enabled=false;
    check(owner.initialize_completion_statistics()==reo::native::gameplay_events::StatisticsStatus::completed);
    const auto p=world.spawn_primary(7,std::make_unique<g::Actor>()).id;
    const auto q=world.auxiliary_actors().allocate(1).id;
    const auto primary=world.resolve(p),auxiliary=world.resolve(q);
    for(const auto& actor:{primary,auxiliary}){actor->active=false;actor->visible=false;actor->model=model();actor->contact_flags=0x12;actor->model_scale={1,1,1};}
    primary->position={70,0,1};auxiliary->position={90,0,2};
    Remaining remaining(world,p,q);g::File1ModelCorrectionScales scales;s::SceneResources resources;s::ResourceTemplates templates;
    g::WorldResourceAttachments attachments(world,resources,templates);u::ActorModelWorkers workers(world,remaining,scales,attachments);UnreachedBehavior behavior;
    auto result=owner.run_workers(workers,behavior);
    check(result.status==u::Status::script_failure&&!workers.primary_result()&&!workers.auxiliary_result());
    const auto idle=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},{},{},{},std::byte{0xa},{},{},{}}});
    check(owner.scripts().install(0,idle)==s::Status::completed&&owner.scripts().install(1,idle)==s::Status::completed);
    result=owner.run_workers(workers,behavior);
    check(result.status==u::Status::completed&&workers.primary_result()&&workers.auxiliary_result());
    check(workers.primary_result()->visited==8&&workers.primary_result()->published==1&&workers.auxiliary_result()->visited==1&&workers.auxiliary_result()->published==1&&remaining.publications_seen==1);
    const auto old=primary->model->retain();const auto old_joints=old->joints;
    primary->active=auxiliary->active=false;primary->position.x+=50;
    check(owner.run_workers(workers,behavior).status==u::Status::completed&&primary->model->retain()!=old&&old->joints==old_joints&&remaining.publications_seen==2);
    world.paused=1;check(owner.run_workers(workers,behavior).status==u::Status::completed&&!workers.primary_result()&&!workers.auxiliary_result());world.paused=0;
    g::World foreign(profile,std::make_shared<g::Session>());Notifications foreign_notifications;u::Owner other(foreign,foreign_notifications);
    bool refused=false;try{workers.run(u::Worker::primary_model_poses,other);}catch(const std::invalid_argument&){refused=true;}check(refused);
    primary->active=auxiliary->active=false;primary->model.reset();refused=false;
    try{(void)owner.run_workers(workers,behavior);}catch(const std::runtime_error&){refused=true;}
    check(refused&&!workers.primary_result()&&!workers.auxiliary_result()&&!world.busy());
    primary->model=model();primary->active=auxiliary->active=false;
    check(owner.run_workers(workers,behavior).status==u::Status::completed&&remaining.publications_seen==3);
    check(workers.button(u::Button::primary,owner)&&workers.transition_request(owner));workers.effect(u::PhaseEffect::update_ui,owner,17);check(remaining.buttons==1&&remaining.effects==1);
    check(workers.close()==u::Status::completed&&owner.close()==u::Status::completed&&world.close()==g::Status::completed);
    std::cout<<"Native actor model passes run before hit work, preserve old poses, and release failure/phase guards.\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
