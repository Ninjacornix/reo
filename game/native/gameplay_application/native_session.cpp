#include "native_session.hpp"
#include "session_resources.hpp"
#include "session_resource_workers.hpp"
#include "session_rooms.hpp"
#include "../gameplay_scenario/cutscene_playback.hpp"
#include "../gameplay_scenario/script_program.hpp"
#include "../gameplay_scenario/room_camera_records.hpp"
#include "../gameplay_scenario/room_camera_modes.hpp"
#include <stdexcept>
#include <utility>
#include <cstdio>
#include <algorithm>

namespace reo::native::gameplay_application {
namespace {
namespace scenario=gameplay_scenario;
bool room_providers(const scenario::Program& program,const gameplay_world::World& world,const scenario::Providers& providers,const scenario::Interpreter& scripts)noexcept{
    return (!program.needs_flags()||providers.flags)&&(!program.needs_timers()||providers.timers)&&
        !program.needs_actor_events()&&!program.needs_signals()&&
        (!program.needs_scene_resources()||providers.scene_resources)&&!program.needs_session_counters()&&
        !program.needs_streams()&&!program.needs_saved_controls()&&
        (!program.needs_selected_actor()||bool(world.primary(world.selected_actor)))&&
        (!program.needs_action_choices()||providers.action_choices)&&(!program.needs_models()||providers.models)&&
        !program.needs_room_objects()&&!program.needs_periodic_effects()&&!program.needs_surface_effects()&&!program.needs_forced_terminal()&&
        !program.needs_script_audio()&&
        program.admits_scene_record_parameters(&world,providers.messages)&&
        program.admits_resource_parameter_commands(&world,providers.resource_parameters,providers.scene_resources,providers.resource_templates)&&
        program.admits_resource_activation(providers.resource_activation,&world,providers.scene_resources,providers.resource_templates)&&
        program.admits_room_counters(&world)&&program.admits_inventory_grants(&world,providers.scene_resources,providers.resource_templates)&&
        program.admits_actor_roster(&world)&&program.admits_character_remap(&world)&&program.admits_actor_script_commands(&world,providers.canonical_flags)&&
        program.admits_actor_script_terminal(providers.actor_script_terminal,&world)&&
        program.admits_offline_actor_inventory(providers.actor_resource_operations,&world,providers.scene_resources,providers.resource_templates)&&
        program.admits_actor_offline_navigation(providers.actor_offline_navigation,&world,&scripts)&&
        program.admits_actor_interaction_commands(&world,providers.scene_resources)&&
        program.admits_offline_room_variants(&world)&&
        program.admits_scenario_enemy_relocation(&world,providers.flags==providers.canonical_flags?providers.canonical_flags:nullptr)&&
        program.admits_timed_scene_text(providers.timed_scene_text,&world)&&
        program.admits_difficulty(&world)&&program.admits_inventory_ui(providers.inventory_ui,&world)&&program.admits_actor_model_classes(&world);
}
}
struct NativeSession::RoomState final:gameplay_scenario::ControlEffects {
    struct Tag final:gameplay_actors::Entity {};
    gameplay_update::Owner& update_owner;
    std::shared_ptr<gameplay_scene::Records> records=std::make_shared<gameplay_scene::Records>(128);
    gameplay_scenario::SceneControls controls{records};
    gameplay_collision::ownership::Proxies proxies{records};
    gameplay_actors::EntityStore room_identity{{1}};
    gameplay_actors::EntityStore entities{{64}};
    gameplay_actors::EntityId identity;
    std::optional<gameplay_scenario::content::RoomId> room;
    std::optional<gameplay_scenario::content::RdtDirectory> directory;
    std::shared_ptr<SessionRoomGeometry> geometry;
    gameplay_scenario::SceneModels models;
    gameplay_scenario::SceneModelBindings bindings;
    gameplay_scenario::SceneMatrixPrograms matrices;
    gameplay_scenario::RoomSceneGlobals globals;
    std::shared_ptr<const gameplay_scenario::RoomSceneInput> input;
    std::unique_ptr<gameplay_scenario::RoomSceneOwner> owner;
    std::unique_ptr<gameplay_scenario::RoomCameraModes> camera_modes;
    gameplay_scenario::CameraDisplayBinding* camera_display{};
    bool navigation_bound{};
    std::shared_ptr<gameplay_collision::room_objects::Owner> object_owner;
    std::shared_ptr<gameplay_collision::room_objects::Scene> objects;
    gameplay_collision::room_objects::SceneResult objects_result;
    gameplay_scenario::SceneMatrixStatus effects_status{gameplay_scenario::SceneMatrixStatus::completed};
    static gameplay_scenario::RoomModelRemap absent_remap()noexcept{
        gameplay_scenario::RoomModelRemap result;result.fill(255);return result;
    }
    RoomState(gameplay_update::Owner& update,gameplay_world::World& world,const gameplay_scenario::SceneModelState& initial):
        update_owner(update),models(initial,absent_remap()),bindings(models,entities),matrices(controls,models,bindings,update.flags(),world.room){
        const auto created=room_identity.create(std::make_unique<Tag>());
        if(created.status!=gameplay_actors::EntityStatus::completed)throw std::bad_alloc();
        identity=created.id;
    }
    ~RoomState(){close();}
    void reset(gameplay_scenario::SceneControls& source,const gameplay_scenario::SceneControlId& id)noexcept override{
        if(&source!=&controls||controls.reset_five(id)!=gameplay_scenario::ControlStatus::completed)
            effects_status=gameplay_scenario::SceneMatrixStatus::unavailable_control;
    }
    void refresh(gameplay_scenario::SceneControls& source,const gameplay_scenario::SceneControlId& id,std::uint8_t authored)noexcept override{
        if(&source!=&controls||!controls.get(id)){effects_status=gameplay_scenario::SceneMatrixStatus::unavailable_control;return;}
        const auto result=matrices.select(authored,gameplay_scenario::SceneMatrixSelection::terminal);
        if(result.status!=gameplay_scenario::SceneMatrixStatus::completed)effects_status=result.status;
    }
    gameplay_collision::room_objects::InstanceStatus close_camera()noexcept{
        using gameplay_collision::room_objects::InstanceStatus;
        using gameplay_scenario::CameraModeStatus;
        if(!camera_modes)return InstanceStatus::complete;
        const auto prior=camera_modes->status();
        if(camera_modes->close()==CameraModeStatus::busy)return InstanceStatus::busy;
        if(update_owner.room_camera_modes()==camera_modes.get()){
            const auto released=update_owner.bind_room_camera_modes(nullptr,camera_modes.get());
            if(released==gameplay_update::Status::busy)return InstanceStatus::busy;
            if(released!=gameplay_update::Status::completed)return InstanceStatus::model_refused;
        }
        camera_modes.reset();camera_display=nullptr;
        return prior==CameraModeStatus::completed||prior==CameraModeStatus::closed?
            InstanceStatus::complete:InstanceStatus::model_refused;
    }
    gameplay_collision::room_objects::InstanceStatus close()noexcept{
        using gameplay_collision::room_objects::InstanceStatus;
        if(navigation_bound){
            const auto released=update_owner.actor_offline_navigation().bind_scene(nullptr,nullptr,nullptr,{},&controls);
            if(released==gameplay_scenario::OfflineNavigationStatus::busy)return InstanceStatus::busy;
            if(released!=gameplay_scenario::OfflineNavigationStatus::completed)return InstanceStatus::model_refused;
            navigation_bound=false;
        }
        const auto camera=close_camera();if(camera==InstanceStatus::busy)return camera;
        const auto result=objects?objects->close():InstanceStatus::complete;
        if(result==InstanceStatus::busy)return result;
        owner.reset();matrices.close();const auto binding_result=bindings.close();entities.shutdown();room_identity.shutdown();
        return camera==InstanceStatus::complete&&result==InstanceStatus::complete&&binding_result==gameplay_scenario::ModelBindingError::none?
            InstanceStatus::complete:InstanceStatus::model_refused;
    }
};
NativeSession::NativeSession(std::shared_ptr<const reo::assets::Source> archive,gameplay_world::Profile profile,
    gameplay_scenario::FlagNotifications& notifications,std::uint8_t mode,gameplay_update::GameplayMessageSink* messages):
    archive_(archive),session_(std::make_shared<gameplay_world::Session>()),
    world_(std::move(profile),session_),reception_(world_),update_(world_,notifications,gameplay_events::RuleBook::file1(),messages),
    scene_text_bank_(*session_,archive_),room_state_(std::make_shared<RoomState>(update_,world_,room_models_.cold_state())){
    world_.mode=mode;
    if(!reception_.bind_room_membership(&room_membership_))
        throw std::invalid_argument("Canonical room membership binding unavailable");
    // Actual1AC688..1AC698 always selects archive asset mode. The native archive
    // supplies that IO owner; this adopts its constant field subproducer only.
    session_->asset_loading_mode=1;
    inventory_ui_.reset(new gameplay_world::InventoryUi(world_));
    if(inventory_ui_->initialize()!=gameplay_world::InventoryUiStatus::completed)
        throw std::runtime_error("Native inventory UI initialization unavailable");
    inventory_ui_resources_=std::make_unique<gameplay_scenario::InventoryUiResources>(world_,archive_,std::move(archive),scene_message_variant_);
    if(inventory_ui_->bind_resources(inventory_ui_resources_.get())!=gameplay_world::InventoryUiStatus::completed)
        throw std::runtime_error("Native inventory UI resource binding unavailable");
    timed_scene_text_=std::make_unique<gameplay_scenario::TimedSceneText>(world_,scene_text_bank_,update_.linked(),
        text_cache_,*inventory_ui_,application_lifecycle_);
}
NativeSession::~NativeSession(){if(close()==SessionStatus::busy)std::terminate();}
NativeSession::RoomLease::RoomLease(std::shared_ptr<NativeSession> host,std::shared_ptr<RoomState> state):
    host_(std::move(host)),state_(std::move(state)){}
bool NativeSession::RoomLease::current()const noexcept{
    if(!host_->open()||host_->room_state_!=state_||!state_->room||!state_->room_identity.acquire(state_->identity)||!state_->matrices.inspect(0))return false;
    const auto id=*state_->room;
    return host_->room_&&host_->room_->scenario==id.scenario&&host_->room_->room==id.room&&host_->room_->variant==id.variant&&
        host_->world_.scenario==id.scenario&&host_->world_.room==id.room;
}
gameplay_actors::EntityId NativeSession::RoomLease::identity()const noexcept{return state_->identity;}
gameplay_scenario::content::RoomId NativeSession::RoomLease::room()const noexcept{return *state_->room;}
std::shared_ptr<gameplay_world::World> NativeSession::RoomLease::world()const noexcept{return {host_,&host_->world_};}
std::shared_ptr<gameplay_scenario::SceneMatrixPrograms> NativeSession::RoomLease::programs()const noexcept{return {shared_from_this(),&state_->matrices};}
const gameplay_scenario::content::RdtDirectory& NativeSession::RoomLease::directory()const noexcept{return *state_->directory;}
NativeSession::RoomLease::ObjectContext NativeSession::RoomLease::object_context()const noexcept{
    return {state_->entities,state_->proxies,state_->bindings,state_->models};
}
gameplay_collision::room_objects::SceneResult NativeSession::RoomLease::initialize_objects(
    std::shared_ptr<gameplay_collision::room_objects::Owner> objects,
    const gameplay_collision::response::Grid& walls,const gameplay_collision::response::Grid& floors,
    gameplay_collision::response::Filter filter){
    using gameplay_collision::room_objects::SceneStatus;
    if(!current()||!objects||!objects->initialized())return {SceneStatus::unavailable_owner};
    if(state_->objects)return state_->objects_result;
    state_->object_owner=std::move(objects);
    state_->objects=std::make_shared<gameplay_collision::room_objects::Scene>(*state_->object_owner,
        state_->entities,state_->proxies,state_->bindings,walls,floors);
    state_->objects_result=state_->objects->initialize(room().room,filter);return state_->objects_result;
}
std::shared_ptr<gameplay_collision::room_objects::Scene> NativeSession::RoomLease::object_scene()const noexcept{
    if(!state_->objects)return{};
    // Keep both the retired scene and its borrowed owners alive even if a
    // later 6AD5C0 replaces the current scene under this same room identity.
    struct Lease {std::shared_ptr<const RoomLease> room;std::shared_ptr<SessionRoomGeometry> geometry;
        std::shared_ptr<gameplay_collision::room_objects::Owner> objects;std::shared_ptr<gameplay_collision::room_objects::Scene> scene;};
    try{auto retained=std::make_shared<Lease>(Lease{shared_from_this(),state_->geometry,state_->object_owner,state_->objects});
        return {retained,retained->scene.get()};}catch(...){return{};}
}
bool NativeSession::RoomLease::retire_objects()noexcept{
    if(!current())return false;
    if(state_->objects&&state_->objects->close()!=gameplay_collision::room_objects::InstanceStatus::complete)return false;
    state_->objects.reset();state_->object_owner.reset();state_->geometry.reset();state_->objects_result={};return true;
}
std::shared_ptr<SessionRoomGeometry>& NativeSession::RoomLease::geometry_cache()const noexcept{return state_->geometry;}
std::shared_ptr<NativeSession::RoomLease> NativeSession::retain_room(std::shared_ptr<NativeSession> host)noexcept{
    if(host.get()!=this||!open()||!room_||!room_state_->matrices.inspect(0))return {};
    try{return std::shared_ptr<RoomLease>(new RoomLease(std::move(host),room_state_));}catch(...){return {};}
}
gameplay_scenario::SceneControls& NativeSession::scene_controls()noexcept{return room_state_->controls;}
gameplay_collision::ownership::Proxies& NativeSession::scene_proxies()noexcept{return room_state_->proxies;}
gameplay_scenario::SceneModels& NativeSession::scene_models()noexcept{return room_state_->models;}
gameplay_scenario::SceneMatrixPrograms& NativeSession::scene_matrices()noexcept{return room_state_->matrices;}
std::shared_ptr<gameplay_scene::Records> NativeSession::scene_records()const noexcept{return room_state_->records;}
std::shared_ptr<const gameplay_scenario::RoomSceneInput> NativeSession::room_scene_input()const noexcept{return room_state_->input;}
const gameplay_scenario::RoomSceneOwner* NativeSession::room_scene()const noexcept{return room_state_->owner.get();}
gameplay_collision::room_objects::Scene* NativeSession::object_instances()noexcept{return room_state_->objects.get();}
gameplay_scenario::Providers NativeSession::providers()noexcept{
    gameplay_scenario::Providers result;result.world=&world_;
    result.flags=result.canonical_flags=&update_.flags();result.timers=&update_.timers();
    result.action_choices=&update_.action_choices();result.sequences=&sequences_;
    result.lighting=&lighting_;result.scene_channels=&channels_;result.scene_controls=&room_state_->controls;
    result.control_effects=room_state_.get();
    result.scenario_events=&update_.scenario_events();
    result.actor_script_terminal=&update_.actor_script_terminal();result.actor_offline_navigation=&update_.actor_offline_navigation();result.messages=update_.message_sink();
    result.inventory_ui=inventory_ui_.get();
    result.timed_scene_text=timed_scene_text_.get();
    result.models=&room_state_->models;
    if(resources_)resources_->provide(result);
    return result;
}
SessionStatus NativeSession::bind_resource_assets(std::shared_ptr<const SessionResourceAssets> assets,std::shared_ptr<SessionRooms> rooms)noexcept{
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy()||world_.busy())return SessionStatus::busy;
    if(const auto controller=world_.cinematic_controller();controller&&controller->busy())return SessionStatus::busy;
    if(!room_)return SessionStatus::missing_room;
    if(resources_||!assets||assets->scenario!=room_->scenario||!rooms||rooms->world().get()!=&world_)return SessionStatus::missing_providers;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{resources_.reset(new SessionResources(*this,std::move(assets),std::move(rooms)));return SessionStatus::completed;}
    catch(const std::exception&){return SessionStatus::missing_providers;}
}
ResourceImportReport NativeSession::initialize_resources()noexcept{
    if(!open()){ResourceImportReport result;result.status=ResourceImportStatus::closed;return result;}
    if(running_||update_.busy()||world_.busy()){ResourceImportReport result;result.status=ResourceImportStatus::busy;return result;}
    if(const auto controller=world_.cinematic_controller();controller&&controller->busy()){ResourceImportReport result;result.status=ResourceImportStatus::busy;return result;}
    if(!resources_)return {};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};return resources_->initialize();
}
SessionStatus NativeSession::import_launch_difficulty(std::uint8_t selected)noexcept{
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy())return SessionStatus::busy;
    session_->difficulty=selected;return SessionStatus::completed;
}
SessionStatus NativeSession::select_scene_message_catalog(gameplay_scenario::SceneTextVariant variant)noexcept{
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy()||world_.busy())return SessionStatus::busy;
    if(variant!=gameplay_scenario::SceneTextVariant::standard&&variant!=gameplay_scenario::SceneTextVariant::alternate)
        return SessionStatus::missing_providers;
    scene_message_variant_=variant;return SessionStatus::completed;
}
SessionStatus NativeSession::step_room_camera(gameplay_scenario::CameraDisplayBinding& display){
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy()||world_.busy())return SessionStatus::busy;
    if(!room_)return SessionStatus::missing_room;
    const auto& models=room_models_.asset();if(!models)return SessionStatus::missing_providers;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    gameplay_scenario::RoomCamera camera(sequences_,camera_parameters_);
    return camera.update(world_,room_state_->models,models->parts(),fog_,display)==gameplay_scenario::RoomCameraStatus::completed?
        SessionStatus::completed:SessionStatus::missing_providers;
}
SessionStatus NativeSession::bind_room_camera(SessionRooms& rooms,gameplay_scenario::CameraDisplayBinding& display)noexcept{
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy())return SessionStatus::busy;
    if(!room_||!room_state_->owner||!room_state_->input)return SessionStatus::missing_room;
    if(rooms.world().get()!=&world_||room_state_->camera_modes)return SessionStatus::missing_providers;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        auto floors=rooms.retain_floor(room_->room);if(!floors)return SessionStatus::missing_providers;
        auto camera=std::make_unique<gameplay_scenario::RoomCameraModes>(world_,update_.linked(),sequences_,camera_parameters_,
            lighting_,*room_state_->owner,room_state_->controls,room_state_->models,room_state_->bindings,room_state_->input,std::move(floors));
        if(update_.bind_room_camera_modes(camera.get())!=gameplay_update::Status::completed)return SessionStatus::missing_providers;
        room_state_->camera_modes=std::move(camera);room_state_->camera_display=&display;return SessionStatus::completed;
    }catch(...){return SessionStatus::missing_providers;}
}
bool NativeSession::room_camera_bound_to(const gameplay_scenario::CameraDisplayBinding& display)const noexcept{
    return open()&&room_state_&&room_state_->camera_modes&&room_state_->camera_display==&display;
}
SessionStatus NativeSession::unbind_room_camera(const gameplay_scenario::CameraDisplayBinding* expected)noexcept{
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy())return SessionStatus::busy;
    if(expected&&room_state_->camera_display&&room_state_->camera_display!=expected)return SessionStatus::missing_providers;
    const auto retired=room_state_->close_camera();
    return retired==gameplay_collision::room_objects::InstanceStatus::complete?SessionStatus::completed:
        retired==gameplay_collision::room_objects::InstanceStatus::busy?SessionStatus::busy:SessionStatus::frame_failure;
}
SessionStatus NativeSession::run_room_camera()noexcept{
    if(!open())return SessionStatus::closed;
    if(!running_||!update_.busy())return SessionStatus::busy;
    const auto& models=room_models_.asset();
    if(!room_state_->camera_modes||!room_state_->camera_display||!models)return SessionStatus::missing_providers;
    return room_state_->camera_modes->update(models->parts(),fog_,*room_state_->camera_display)==gameplay_scenario::CameraModeStatus::completed?
        SessionStatus::completed:SessionStatus::frame_failure;
}
SessionStatus NativeSession::install_room(gameplay_scenario::content::RoomId id){
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy()||world_.busy())return SessionStatus::busy;
    // Resource descriptors/inventory persist. Until the actual591920 rebind
    // caller is adopted, refuse a room replacement instead of discarding them.
    if(resources_)return SessionStatus::missing_providers;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        const auto room=archive_.room(id);if(!room)return SessionStatus::missing_room;
        //1D3830's section table dispatches section0 to5BE3E0 before lighting.
        // Prepare immutable geometry before publishing its canonical command
        // header. An absent source section does not invoke the loader/reset.
        std::shared_ptr<const gameplay_scenario::RoomCameraRecords> camera;
        if(const auto data=room->section(0)){
            try{camera=gameplay_scenario::RoomCameraRecords::import(*data);}
            catch(const std::logic_error&){return SessionStatus::missing_providers;}
        }
        const auto section=room->section(1);if(!section)return SessionStatus::missing_room;
        auto bytes=std::make_shared<const std::vector<std::byte>>(section->begin(),section->end());
        const gameplay_scenario::content::ScriptBank bank(bytes,gameplay_scenario::content::BankFormat::room_section);
        const auto admitted=gameplay_scenario::content::admit_script_program(bank,world_.mode==0?
            gameplay_scenario::DispatchProfile::offline_actor:gameplay_scenario::DispatchProfile::ordinary);
        if(admitted.status!=gameplay_scenario::content::ScriptAdmission::admitted||!admitted.program)return SessionStatus::unsupported_script;
        if(!room_providers(*admitted.program,world_,providers(),update_.scripts()))return SessionStatus::missing_providers;
        const auto scene=room->section(10),lig=room->section(11);
        if(!scene||!lig)return SessionStatus::missing_providers;
        gameplay_scenario::Lighting prepared_lighting;
        if(prepared_lighting.import_lig(*lig)!=gameplay_scenario::LightingImport::completed)return SessionStatus::missing_providers;
        //1D3830 row236860 sends actual sectionD to6B23E0. Preserve prior fog
        // when absent and publish a valid imported catalog with the room.
        auto prepared_fog=fog_;
        if(const auto data=room->section(13)){
            const auto status=prepared_fog.import_fog(*data);
            if(status!=gameplay_scenario::FogStatus::completed&&status!=gameplay_scenario::FogStatus::unsupported_version)
                return SessionStatus::missing_providers;
        }
        auto model_asset=room_models_.current(id)?room_models_.asset():nullptr;
        if(!model_asset){
            char name[32];const auto count=std::snprintf(name,sizeof name,"r%03u%02u%02u.nbd",unsigned(id.scenario),unsigned(id.room),unsigned(id.variant));
            if(count<=0||std::size_t(count)>=sizeof name)return SessionStatus::missing_providers;
            const auto model_bytes=archive_.read_resource(id.scenario,name);if(!model_bytes)return SessionStatus::missing_providers;
            try{model_asset=gameplay_scenario::RoomModelAsset::import(name,model_bytes);}
            catch(const std::logic_error&){return SessionStatus::missing_providers;}
        }
        auto current_models=room_state_->models.state();
        // Retirement retains actual bound object/matrix targets into their
        // source slots. Capture those same live values before preparing the
        // next generation, so admission can fail without abandoning owners.
        for(unsigned i=0;i<128;++i){const auto pose=room_state_->bindings.live_pose(std::uint8_t(i));
            if(!pose)return SessionStatus::missing_providers;
            current_models.poses[i]=*pose;
        }
        auto prepared=std::make_shared<RoomState>(update_,world_,room_models_.prepare(id,*model_asset,current_models));
        prepared->room=id;prepared->directory=*room;
        prepared->input=std::make_shared<const gameplay_scenario::RoomSceneInput>(*scene,bank,
            gameplay_collision::ImportContext{id.scenario,id.room});
        // A physical helper requires this actual bundle's loaded pose/part;
        // unrelated retained slots do not establish a new asset capability.
        for(const auto& definition:prepared->input->records())
            if(definition.model)if(const auto slot=definition.model->slot.slot()){
                if(*slot>=model_asset->parts()||std::none_of(model_asset->poses().begin(),model_asset->poses().end(),
                    [&](const auto& pose){return pose.slot==*slot;}))return SessionStatus::missing_providers;
            }
        auto installed=gameplay_scenario::RoomSceneOwner::install(prepared->input,prepared->controls,
            prepared->proxies,prepared->models,prepared->matrices,prepared->globals,
            gameplay_scenario::NoModelRepair::authored_absent);
        if(installed.status!=gameplay_scenario::RoomSceneStatus::completed||!installed.owner)return SessionStatus::missing_providers;
        prepared->owner=std::move(installed.owner);
        auto status=gameplay_update::Status::script_failure;
        if(world_.mode==0){
            // The canonical offline coordinator dispatches physical party
            // classes0/1/2 through channels1/2/3. Publish the complete set in
            // one checked replacement, including the secondary room entry.
            const std::array<gameplay_scenario::ChannelReplacement,4> replacements{{
                {1,admitted.program,admitted.entries[0]},
                {2,admitted.program,admitted.entries[0]},
                {3,admitted.program,admitted.entries[0]},
                {5,admitted.entries[1]?admitted.program:nullptr,admitted.entries[1]}
            }};
            const auto bound=update_.scripts().replace_channels(replacements);
            status=bound==gameplay_scenario::Status::completed?gameplay_update::Status::completed:
                bound==gameplay_scenario::Status::busy?gameplay_update::Status::busy:gameplay_update::Status::script_failure;
        }else status=update_.bind_room_scripts(bank);
        if(status!=gameplay_update::Status::completed)return status==gameplay_update::Status::busy?SessionStatus::busy:SessionStatus::script_failure;
        // Both parses see the same retained immutable bytes; publication below
        // performs no provider callback or resource allocation.
        (void)lighting_.import_lig(*lig);
        const auto retired=room_state_->close();
        if(retired==gameplay_collision::room_objects::InstanceStatus::busy)return SessionStatus::busy;
        if(update_.actor_offline_navigation().bind_scene(&prepared->controls,&prepared->models,&prepared->matrices,{})!=
            gameplay_scenario::OfflineNavigationStatus::completed)return SessionStatus::missing_providers;
        prepared->navigation_bound=true;
        room_state_=std::move(prepared);
        fog_=std::move(prepared_fog);
        if(camera)sequences_.install_camera_records(std::move(camera),world_.selected_actor);
        (void)room_models_.commit(id,std::move(model_asset));
        world_.scenario=id.scenario;world_.room=id.room;room_=id;
        return retired==gameplay_collision::room_objects::InstanceStatus::complete?SessionStatus::completed:SessionStatus::frame_failure;
    }catch(const std::invalid_argument&){return SessionStatus::unsupported_script;}
}
ScriptStep NativeSession::step_room_script(std::size_t budget){
    if(!open())return{SessionStatus::closed,{}};
    if(running_||update_.busy()||world_.busy())return{SessionStatus::busy,{}};
    if(!room_)return{SessionStatus::missing_room,{}};
    if(world_.mode==0){
        bool active=false;for(unsigned i=0;i<3;++i){const auto actor=world_.primary(i);active|=actor&&actor->active;}
        if(!active)return{SessionStatus::missing_providers,{}};
    }
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    room_state_->effects_status=gameplay_scenario::SceneMatrixStatus::completed;
    auto result=update_.step_script(1,providers(),budget);
    const auto status=result.status==gameplay_update::Status::completed&&
        room_state_->effects_status==gameplay_scenario::SceneMatrixStatus::completed?SessionStatus::completed:SessionStatus::script_failure;
    return{status,std::move(result)};
}
FrameStep NativeSession::advance(gameplay_update::PhaseServices* phases,gameplay_world::Services* actors,
    std::size_t script_budget,std::size_t task_budget){
    if(!open())return{SessionStatus::closed,{}};
    if(running_||update_.busy()||world_.busy())return{SessionStatus::busy,{}};
    if(!room_)return{SessionStatus::missing_room,{}};
    if(!phases||!actors)return{SessionStatus::missing_frame_services,{}};
    if(resources_&&!resources_->initialized())return{SessionStatus::missing_providers,{}};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    room_state_->effects_status=gameplay_scenario::SceneMatrixStatus::completed;
    gameplay_update::Result result;
    if(resources_){SessionResourceWorkers workers(*this,*resources_,*phases);result=update_.advance(workers,*actors,providers(),script_budget,task_budget);}
    else result=update_.advance(*phases,*actors,providers(),script_budget,task_budget);
    const auto status=result.status==gameplay_update::Status::completed&&
        room_state_->effects_status==gameplay_scenario::SceneMatrixStatus::completed&&
        timed_scene_text_->snapshot().callback_status==gameplay_scenario::TimedTextStatus::completed?
        SessionStatus::completed:SessionStatus::frame_failure;
    return{status,std::move(result)};
}
bool NativeSession::busy()const noexcept{
    if(running_||update_.busy()||world_.busy())return true;
    if(const auto controller=world_.cinematic_controller();controller&&controller->busy())return true;
    return (resources_&&resources_->busy())||(timed_scene_text_&&timed_scene_text_->busy())||
        (inventory_ui_resources_&&inventory_ui_resources_->busy());
}
SessionStatus NativeSession::close()noexcept{
    if(closed_)return SessionStatus::completed;
    if(busy())return SessionStatus::busy;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    // Scenario callbacks borrow the canonical resource work owner. Retire
    // those tasks while their World and visuals still exist, then tear down
    // resources. An earlier task failure remains visible to the close caller.
    const auto events=update_.scenario_events().close();
    if(events==gameplay_scenario::ScenarioEventStatus::busy)return SessionStatus::busy;
    bool failed=events!=gameplay_scenario::ScenarioEventStatus::completed;
    if(timed_scene_text_){
        failed|=timed_scene_text_->snapshot().callback_status!=gameplay_scenario::TimedTextStatus::completed;
        const auto text=timed_scene_text_->close();
        if(text==gameplay_scenario::TimedTextStatus::busy)return SessionStatus::busy;
        failed|=text!=gameplay_scenario::TimedTextStatus::completed;
    }
    if(resources_){
        const auto resources=resources_->close();
        if(resources==SessionResourceStatus::busy)return SessionStatus::busy;
        failed|=resources!=SessionResourceStatus::completed;
        resources_.reset();
    }
    if(inventory_ui_resources_){
        const auto released=inventory_ui_->bind_resources(nullptr,inventory_ui_resources_.get());
        if(released==gameplay_world::InventoryUiStatus::busy)return SessionStatus::busy;
        failed|=released!=gameplay_world::InventoryUiStatus::completed;
        const auto inventory=inventory_ui_resources_->close();
        if(inventory==gameplay_scenario::InventoryResourcesStatus::busy)return SessionStatus::busy;
        failed|=inventory!=gameplay_scenario::InventoryResourcesStatus::completed;
    }
    const auto navigation=update_.actor_offline_navigation().close();
    if(navigation==gameplay_scenario::OfflineNavigationStatus::busy)return SessionStatus::busy;
    failed|=navigation!=gameplay_scenario::OfflineNavigationStatus::completed;
    // World performs its actual controller-busy check before retiring anything.
    // Update's idle check above guarantees its subsequent close is admissible.
    if(world_.close()!=gameplay_world::Status::completed)return SessionStatus::busy;
    const auto retired=room_state_->close();
    if(retired==gameplay_collision::room_objects::InstanceStatus::busy)return SessionStatus::busy;
    if(update_.close()!=gameplay_update::Status::completed)return SessionStatus::busy;
    room_membership_.clear();
    application_lifecycle_.close();
    closed_=true;
    return !failed&&retired==gameplay_collision::room_objects::InstanceStatus::complete?SessionStatus::completed:SessionStatus::frame_failure;
}
}
