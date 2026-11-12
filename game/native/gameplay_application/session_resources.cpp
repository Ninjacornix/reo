#include "session_resources.hpp"
#include "native_session.hpp"
#include "session_resource_import.hpp"
#include "session_rooms.hpp"
#include "../gameplay_scenario/cutscene_playback.hpp"
#include "../gameplay_scenario/resource_collisions.hpp"
#include "../gameplay_world/linked_pose_timing.hpp"
#include "../gameplay_world/pose_cloud.hpp"
#include "../gameplay_world/pose_trail_effects.hpp"
#include "../gameplay_world/pose_timed_projectile.hpp"
#include "../gameplay_world/room_pose_projectiles.hpp"
#include "../gameplay_world/canonical_actor_sounds.hpp"
#include <stdexcept>
namespace reo::native::gameplay_application {
namespace {
std::shared_ptr<const SessionResourceAssets> validate_assets(std::shared_ptr<const SessionResourceAssets> assets){
    if(!assets||!assets->models||!assets->effects||!assets->contacts)
        throw std::invalid_argument("Native session resources require actual asset owners");
    (void)assets->contacts->tables();return assets;
}
}
struct SessionResources::Impl:gameplay_world::ResourceModelPostUpdate {
    NativeSession& session;
    std::shared_ptr<const SessionResourceAssets> assets;
    std::shared_ptr<SessionRooms> rooms;
    std::shared_ptr<gameplay_scene::Records> records;
    gameplay_scenario::SceneResources descriptors;
    gameplay_scenario::ResourceTemplates templates;
    gameplay_world::ResourceModels models;
    gameplay_effects::PeriodicVisuals visuals;
    gameplay_world::ResourceFrames frames;
    gameplay_world::ResourceFactory factory;
    gameplay_scenario::ResourceCollisions collisions;
    gameplay_world::WorldInventory inventory;
    gameplay_world::WorldResourceAttachments attachments;
    gameplay_scenario::ScriptResourceParameters parameters;
    gameplay_scenario::ScriptResourceActivation activation;
    ResourceBootstrap bootstrap;
    gameplay_world::PoseWorkPool poses;
    gameplay_collision::delivery::Packets packets;
    gameplay_world::ResourcePoseWork pose_factory;
    gameplay_world::PresetPoseWork presets;
    gameplay_lighting::Pool lights;
    gameplay_lighting::TimedLights timed_lights;
    gameplay_world::LinkedPoseTimingQuantum quantum;
    gameplay_world::CanonicalProjectileParentVariant variants;
    gameplay_world::MappedPoseTrailEffects trails;
    gameplay_world::PoseMotionUpdates motions;
    gameplay_world::RoomPoseArcs arcs;
    gameplay_world::PoseCloudUpdates clouds;
    gameplay_world::RoomParentPoseFlight parent_flights;
    gameplay_world::RoomTimedPoseProjectiles timed_projectiles;
    gameplay_world::RoomPoseProjectiles projectiles;
    gameplay_world::ResourcePoseUpdates pose_updates;
    bool closed{},descriptors_ready{};
    Impl(NativeSession& value,std::shared_ptr<const SessionResourceAssets> input,std::shared_ptr<SessionRooms> room_resources):
        session(value),assets(validate_assets(std::move(input))),rooms(std::move(room_resources)),records(value.scene_records()),
        visuals(assets->effects,value.world().session().random),
        frames(value.world(),descriptors,models,&visuals,records,&templates),
        factory(models,frames,templates,assets->models),
        collisions(descriptors,records),
        inventory(value.world(),descriptors,templates,frames),
        attachments(value.world(),descriptors,templates),
        parameters(value.world(),descriptors,templates,models,factory,inventory),
        activation(value.world(),descriptors,templates,models,factory),
        bootstrap(value.world(),descriptors,templates,inventory),
        poses(value.world()),pose_factory(value.world(),poses,descriptors,templates,packets,*assets->contacts),
        presets(value.world(),poses,packets,*assets->contacts),lights(value.lighting()),timed_lights(value.world(),value.update().linked(),lights),
        quantum(value.world()),variants(value.world()),trails(value.world(),visuals,*rooms),
        motions(value.world(),poses,&quantum),arcs(value.world(),poses,*rooms,&trails,&motions),
        clouds(value.world(),poses,visuals,timed_lights,&arcs),
        parent_flights(value.world(),poses,*rooms,&trails,nullptr,&clouds),
        timed_projectiles(value.world(),poses,*rooms,packets,*assets->contacts,&trails,&quantum,&variants,&parent_flights),
        projectiles(value.world(),poses,*rooms,packets,*assets->contacts,&presets,&trails,nullptr,nullptr,nullptr,&timed_projectiles),
        pose_updates(value.world(),poses,descriptors,templates,packets,*assets->contacts,&projectiles){
        if(!value.open()||!value.room()||value.update().busy()||value.world().busy())
            throw std::invalid_argument("Native session resource scope requires an idle installed room");
        if(!rooms||rooms->world().get()!=&value.world())throw std::invalid_argument("Canonical room resources required");
        const auto floors=rooms->retain_floor(value.world().room);
        if(!floors||!factory.bind_scene(collisions,floors,value.world().room))throw std::invalid_argument("Actual resource floor/collision owners unavailable");
    }
    void apply(gameplay_world::ResourceModels& owner)override{
        if(&owner!=&models||closed||session.scene_records()!=records)throw std::runtime_error("Retired resource post-update scope");
        const auto scene=session.object_instances();if(!scene||!scene->open())throw std::runtime_error("Canonical room dynamic owner unavailable");
        // Actual6AEDA0 uses this same room-object owner and walls. Its retained
        // dynamic cache is the one consumed by SessionRooms invocations.
        scene->lifetime().rebuild_dynamic();
        if(scene->dynamic().status==gameplay_collision::trace::SamplingStatus::capacity||scene->dynamic().status==gameplay_collision::trace::SamplingStatus::nonprogress)
            throw std::runtime_error("Native dynamic room post-update profile unavailable");
    }
};
SessionResources::SessionResources(NativeSession& session,std::shared_ptr<const SessionResourceAssets> assets,std::shared_ptr<SessionRooms> rooms):impl_(std::make_unique<Impl>(session,std::move(assets),std::move(rooms))){}
SessionResources::~SessionResources(){if(close()==SessionResourceStatus::busy)std::terminate();}
bool SessionResources::bound_to(const NativeSession& session)const noexcept{
    return impl_&&!impl_->closed&&&impl_->session==&session&&session.open()&&
        impl_->session.scene_records()==impl_->records&&impl_->poses.bound_to(impl_->session.world());
}
SessionResourceStatus SessionResources::close()noexcept{
    if(impl_->closed)return SessionResourceStatus::completed;
    if(impl_->session.update().busy()||impl_->session.world().busy())return SessionResourceStatus::busy;
    if(const auto controller=impl_->session.world().cinematic_controller();controller&&controller->busy())return SessionResourceStatus::busy;
    impl_->timed_lights.close();
    const auto pose=impl_->poses.close();
    if(pose==gameplay_world::PoseWorkStatus::busy)return SessionResourceStatus::busy;
    auto& world=impl_->session.world();world.updating_=true;
    struct Guard{bool& flag;~Guard(){flag=false;}}guard{world.updating_};
    const auto models=impl_->models.close();
    if(models==gameplay_world::ResourceModelStatus::busy)return SessionResourceStatus::busy;
    for(unsigned i=0;i<gameplay_scenario::SceneResources::capacity;++i)(void)impl_->descriptors.load(i,{});
    impl_->packets.close();impl_->visuals.close();impl_->closed=true;return SessionResourceStatus::completed;
}
bool SessionResources::initialized()const noexcept{return bound_to(impl_->session)&&impl_->descriptors_ready;}
ResourceImportReport SessionResources::initialize()noexcept{
    if(!bound_to(impl_->session)||impl_->descriptors_ready||impl_->models.available()!=64||impl_->poses.remaining()!=64)return {};
    auto report=impl_->bootstrap.run(impl_->session.archive());impl_->descriptors_ready=report.status==ResourceImportStatus::completed;return report;
}
SessionResourceStatus SessionResources::run_worker(gameplay_update::Worker worker,gameplay_update::Owner& owner){
    if(&owner!=&impl_->session.update())return SessionResourceStatus::unavailable_owner;
    if(!initialized())return SessionResourceStatus::unavailable_room;
    if(worker==gameplay_update::Worker::resource_instances){
        auto& world=impl_->session.world();if(world.busy())return SessionResourceStatus::busy;
        const auto controller=impl_->session.world().cinematic_controller();if(!controller)return SessionResourceStatus::resource_failure;
        world.updating_=true;struct Guard{bool& flag;~Guard(){flag=false;}}guard{world.updating_};
        const auto result=impl_->models.update(controller->state().cinematic_enabled!=0,impl_.get());
        return result.status==gameplay_world::ResourceModelStatus::completed?SessionResourceStatus::completed:SessionResourceStatus::resource_failure;
    }
    if(worker==gameplay_update::Worker::scene_pose_tasks){
        const auto result=impl_->poses.update(&impl_->pose_updates);
        return result.status==gameplay_world::PoseWorkStatus::completed?SessionResourceStatus::completed:SessionResourceStatus::pose_failure;
    }
    return SessionResourceStatus::unavailable_owner;
}
void SessionResources::provide(gameplay_scenario::Providers& providers)noexcept{
    // A cold table is not the authored selection/placement producer. Never
    // admit stock resource instructions through an empty successful provider.
    if(!bound_to(impl_->session)||!impl_->descriptors_ready)return;
    providers.scene_resources=&impl_->descriptors;providers.scene_effects=&impl_->factory;
    providers.scene_owners=&impl_->inventory;providers.resource_templates=&impl_->templates;
    providers.resource_parameters=&impl_->parameters;providers.resource_activation=&impl_->activation;
}
gameplay_scenario::SceneResources& SessionResources::descriptors()noexcept{return impl_->descriptors;}
const gameplay_scenario::ResourceTemplates& SessionResources::templates()const noexcept{return impl_->templates;}
gameplay_world::ResourceModels& SessionResources::models()noexcept{return impl_->models;}
gameplay_world::ResourceFactory& SessionResources::factory()noexcept{return impl_->factory;}
gameplay_world::WorldInventory& SessionResources::inventory()noexcept{return impl_->inventory;}
gameplay_world::WorldResourceAttachments& SessionResources::attachments()noexcept{return impl_->attachments;}
gameplay_world::PoseWorkPool& SessionResources::pose_pool()noexcept{return impl_->poses;}
gameplay_world::ResourcePoseWork& SessionResources::pose_factory()noexcept{return impl_->pose_factory;}
gameplay_collision::delivery::Packets& SessionResources::contact_packets()noexcept{return impl_->packets;}
gameplay_effects::PeriodicVisuals& SessionResources::visuals()noexcept{return impl_->visuals;}
}
