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
#include "../gameplay_world/animation_primitives.hpp"
#include "../gameplay_world/primary_locomotion.hpp"
#include "../gameplay_world/actor_forced_terminal.hpp"
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
    gameplay_world::ResourcePairs pairs;
    gameplay_world::ResourceContents contents;
    gameplay_world::ResourceRecipes recipes;
    gameplay_world::ActorResourceOperations actor_operations;
    gameplay_world::ActorForcedTerminal forced_terminal;
    gameplay_world::ResourceConsumption consumption;
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
    gameplay_world::WorldMotionResources motion_resources;
    gameplay_world::File1MotionProfiles motion_profiles;
    gameplay_world::animation_events::File1Metadata animation_metadata;
    gameplay_world::animation_events::NativeConsumer animation_consumer;
    gameplay_world::animation_events::Prelude animation_prelude;
    gameplay_world::WorldAnimation animation;
    gameplay_world::NativeActionAnimation action_animation;
    bool closed{},closing{},initializing{},descriptors_ready{},events_bound{},actor_bound{},navigation_bound{};
    Impl(NativeSession& value,std::shared_ptr<const SessionResourceAssets> input,std::shared_ptr<SessionRooms> room_resources):
        session(value),assets(validate_assets(std::move(input))),rooms(std::move(room_resources)),records(value.scene_records()),
        visuals(assets->effects,value.world().session().random,value.fog()),
        frames(value.world(),descriptors,models,&visuals,records,&templates),
        factory(models,frames,templates,assets->models),
        collisions(descriptors,records),
        inventory(value.world(),descriptors,templates,frames),
        pairs(value.world(),descriptors,templates,frames),
        contents(value.world(),descriptors,templates,frames,factory),
        recipes(pairs,contents,inventory),actor_operations(recipes),forced_terminal(value.update(),actor_operations,value.inventory_ui()),consumption(recipes,value.update()),
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
        pose_updates(value.world(),poses,descriptors,templates,packets,*assets->contacts,&projectiles),
        motion_resources(value.world()),
        animation_consumer(value.world(),animation_metadata,nullptr,&packets,assets->contacts.get(),&descriptors),
        animation_prelude(value.world(),animation_metadata,animation_consumer),
        animation(value.world(),motion_resources,motion_profiles,animation_prelude),
        action_animation(value.world(),animation){
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
gameplay_world::WorldAnimation& SessionResources::animation()noexcept{return impl_->animation;}
gameplay_world::NativeActionAnimation& SessionResources::action_animation()noexcept{return impl_->action_animation;}
void SessionResources::locomotion_action(gameplay_world::Actor& actor){
    if(!initialized())throw std::runtime_error("Native locomotion resource owner unavailable");
    auto& world=impl_->session.world();const auto id=world.identity_of(actor);
    const auto retained=world.resolve(id);
    if(!retained||retained.get()!=&actor)throw std::runtime_error("Native locomotion actor retired or foreign");
    const auto room=impl_->rooms->retain(world.room);
    if(!room)throw std::runtime_error("Native locomotion room unavailable");
    const auto validate=[&]{
        if(!initialized()||world.resolve(id)!=retained||room->room_number()!=world.room||!room->current(room->identity()))
            throw std::runtime_error("Native locomotion invocation retired");
    };
    using Validator=decltype(validate);
    struct Actions final:gameplay_world::ActionAnimation {
        gameplay_world::ActionAnimation& target;const Validator& validate;
        Actions(gameplay_world::ActionAnimation& t,const Validator& v):target(t),validate(v){}
        void select(gameplay_world::Actor& a,std::uint32_t m,float f,float b)override{validate();target.select(a,m,f,b);validate();}
        void activate(gameplay_world::Actor& a)override{validate();target.activate(a);validate();}
        std::int8_t tick(gameplay_world::Actor& a,float f)override{validate();const auto r=target.tick(a,f);validate();return r;}
        void or_flags(gameplay_world::Actor& a)override{validate();target.or_flags(a);validate();}
        float first_frame(gameplay_world::Actor& a,std::uint32_t m,std::uint16_t t)override{validate();const auto r=target.first_frame(a,m,t);validate();return r;}
        float last_frame(gameplay_world::Actor& a,std::uint32_t m,std::uint16_t t)override{validate();const auto r=target.last_frame(a,m,t);validate();return r;}
        float matched_frame(gameplay_world::Actor& a,std::uint32_t m,std::uint16_t t)override{validate();const auto r=target.matched_frame(a,m,t);validate();return r;}
    } actions(impl_->action_animation,validate);
    validate();gameplay_world::update_locomotion_action(world,actor,room->geometry().floors,actions);validate();
}
bool SessionResources::initialize_roster_room_objects()noexcept{
    return impl_&&!impl_->closed&&!impl_->closing&&impl_->rooms&&impl_->rooms->initialize_roster_objects();
}
bool SessionResources::bound_to(const NativeSession& session)const noexcept{
    return impl_&&!impl_->closed&&!impl_->closing&&&impl_->session==&session&&session.open()&&
        impl_->session.scene_records()==impl_->records&&impl_->poses.bound_to(impl_->session.world());
}
bool SessionResources::busy()const noexcept{
    if(!impl_||impl_->closed)return false;
    const auto& world=impl_->session.world();
    if(impl_->closing||impl_->initializing||impl_->session.update().busy()||world.busy()||impl_->poses.busy()||
       impl_->models.busy()||impl_->visuals.busy()||impl_->forced_terminal.busy())return true;
    const auto controller=world.cinematic_controller();return controller&&controller->busy();
}
SessionResourceStatus SessionResources::close()noexcept{
    if(impl_->closed)return SessionResourceStatus::completed;
    if(busy())return SessionResourceStatus::busy;
    impl_->closing=true;struct Reset{bool& value;~Reset(){value=false;}}reset{impl_->closing};
    if(impl_->events_bound){
        // A standalone resource close must not erase unrelated event work.
        // Session shutdown may first close ScenarioEvents, which retires its
        // tasks and clears this borrow; otherwise unbind requires no tasks.
        auto& events=impl_->session.update().scenario_events();
        const auto status=events.bind_effect_work(nullptr);
        if(status==gameplay_scenario::ScenarioEventStatus::busy)return SessionResourceStatus::busy;
        if(status!=gameplay_scenario::ScenarioEventStatus::completed)return SessionResourceStatus::resource_failure;
        impl_->events_bound=false;
    }
    if(impl_->navigation_bound){
        const auto status=impl_->session.update().actor_offline_navigation().bind_resource_operations(nullptr,&impl_->actor_operations);
        if(status==gameplay_scenario::OfflineNavigationStatus::busy)return SessionResourceStatus::busy;
        if(status!=gameplay_scenario::OfflineNavigationStatus::completed)return SessionResourceStatus::resource_failure;
        impl_->navigation_bound=false;
    }
    if(impl_->actor_bound){
        const auto status=impl_->session.update().actor_script_terminal().bind_resource_operations(nullptr,&impl_->actor_operations);
        if(status==gameplay_scenario::ActorScriptTerminalStatus::busy)return SessionResourceStatus::busy;
        if(status!=gameplay_scenario::ActorScriptTerminalStatus::completed)return SessionResourceStatus::resource_failure;
        impl_->actor_bound=false;
    }
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
ResourceImportReport SessionResources::initialize()noexcept{return initialize_impl(false);}
ResourceImportReport SessionResources::initialize_roster()noexcept{return initialize_impl(true);}
ResourceImportReport SessionResources::initialize_impl(bool nested)noexcept{
    auto& world=impl_->session.world();
    if(!bound_to(impl_->session)||impl_->initializing||
       (nested&&(!world.updating_||!world.primary_resource_startup_||
                  impl_->session.update().events().size()!=0||impl_->visuals.size()!=0))||
       (!nested&&(world.busy()||impl_->descriptors_ready))||
       impl_->models.busy()||impl_->poses.busy()||impl_->visuals.busy()||
       impl_->models.available()!=64||impl_->poses.remaining()!=64||impl_->packets.size()!=0)return {};
    const auto controller=world.cinematic_controller();if(controller&&controller->busy())return {};
    impl_->initializing=true;struct Guard{bool& value;~Guard(){value=false;}}guard{impl_->initializing};
    auto& events=impl_->session.update().scenario_events();
    auto& terminal=impl_->session.update().actor_script_terminal();
    auto& navigation=impl_->session.update().actor_offline_navigation();
    // The private nested capability is reached only under the exact 5EB520
    // source-site permit checked above; public binding remains idle-only.
    const auto bind_actor=[&](gameplay_world::ActorResourceOperations* operations,
                               gameplay_world::ActorResourceOperations* expected=nullptr){
        return nested?terminal.bind_roster_resources(operations,expected):terminal.bind_resource_operations(operations,expected);
    };
    const auto bind_navigation=[&](gameplay_world::ActorResourceOperations* operations,
                                    gameplay_world::ActorResourceOperations* expected=nullptr){
        auto* terminal_owner=operations?&impl_->forced_terminal:nullptr;
        return nested?navigation.bind_roster_resources(operations,expected,terminal_owner):navigation.bind_resource_operations(operations,expected,terminal_owner);
    };
    if(impl_->navigation_bound){
        if(bind_navigation(nullptr,&impl_->actor_operations)!=gameplay_scenario::OfflineNavigationStatus::completed)return {};
        impl_->navigation_bound=false;
    }
    const bool had_events=impl_->events_bound;
    if(had_events){
        if(events.bind_effect_work(nullptr)!=gameplay_scenario::ScenarioEventStatus::completed)return {};
        impl_->events_bound=false;
    }
    if(impl_->actor_bound){
        if(bind_actor(nullptr,&impl_->actor_operations)!=gameplay_scenario::ActorScriptTerminalStatus::completed){
            if(had_events&&events.bind_effect_work(&impl_->visuals)==gameplay_scenario::ScenarioEventStatus::completed)
                impl_->events_bound=true;
            else impl_->descriptors_ready=false;
            return {};
        }
        impl_->actor_bound=false;
    }
    // A reset has now been admitted and both old borrows have retired.
    // Later failures must not advertise the old graph as initialized.
    impl_->descriptors_ready=false;
    if(events.bind_effect_work(&impl_->visuals)!=gameplay_scenario::ScenarioEventStatus::completed)return {};
    impl_->events_bound=true;
    auto report=impl_->bootstrap.run_impl(impl_->session.archive(),nested);
    if(report.status==ResourceImportStatus::completed){
        if(bind_actor(&impl_->actor_operations)==gameplay_scenario::ActorScriptTerminalStatus::completed){
            impl_->actor_bound=true;
            if(bind_navigation(&impl_->actor_operations)==gameplay_scenario::OfflineNavigationStatus::completed){
                impl_->navigation_bound=true;impl_->descriptors_ready=true;
            }else{
                report.status=ResourceImportStatus::unavailable_profile;
                if(bind_actor(nullptr,&impl_->actor_operations)==gameplay_scenario::ActorScriptTerminalStatus::completed)impl_->actor_bound=false;
            }
        }else report.status=ResourceImportStatus::unavailable_profile;
    }
    if(!impl_->descriptors_ready&&events.bind_effect_work(nullptr)==gameplay_scenario::ScenarioEventStatus::completed)
        impl_->events_bound=false;
    return report;
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
    providers.actor_resource_operations=&impl_->actor_operations;
    providers.forced_terminal=&impl_->forced_terminal;
    providers.scene_resources=&impl_->descriptors;providers.scene_effects=&impl_->factory;
    providers.room_objects=impl_->rooms->script_commands();
    providers.scene_owners=&impl_->inventory;providers.resource_templates=&impl_->templates;
    providers.resource_parameters=&impl_->parameters;providers.resource_activation=&impl_->activation;
}
gameplay_scenario::SceneResources& SessionResources::descriptors()noexcept{return impl_->descriptors;}
const gameplay_scenario::ResourceTemplates& SessionResources::templates()const noexcept{return impl_->templates;}
gameplay_world::ResourceModels& SessionResources::models()noexcept{return impl_->models;}
std::shared_ptr<const gameplay_world::ResourceStaticAssets> SessionResources::static_models()const noexcept{return impl_->factory.static_assets();}
gameplay_world::ResourceFactory& SessionResources::factory()noexcept{return impl_->factory;}
gameplay_world::WorldInventory& SessionResources::inventory()noexcept{return impl_->inventory;}
gameplay_world::ActorResourceOperations& SessionResources::actor_operations()noexcept{return impl_->actor_operations;}
gameplay_world::ResourceConsumption& SessionResources::consumption()noexcept{return impl_->consumption;}
gameplay_world::WorldResourceAttachments& SessionResources::attachments()noexcept{return impl_->attachments;}
gameplay_world::PoseWorkPool& SessionResources::pose_pool()noexcept{return impl_->poses;}
gameplay_world::ResourcePoseWork& SessionResources::pose_factory()noexcept{return impl_->pose_factory;}
gameplay_collision::delivery::Packets& SessionResources::contact_packets()noexcept{return impl_->packets;}
gameplay_effects::PeriodicVisuals& SessionResources::visuals()noexcept{return impl_->visuals;}
}
