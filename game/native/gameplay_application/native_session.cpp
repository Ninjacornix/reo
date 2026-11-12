#include "native_session.hpp"
#include "../gameplay_scenario/script_program.hpp"
#include <stdexcept>
#include <utility>

namespace reo::native::gameplay_application {
namespace {
namespace scenario=gameplay_scenario;
bool minimal_room_providers(const scenario::Program& program)noexcept{
    // This concrete initial composition admits the seven providers required by
    // owned r0417300. Other existing owners will be attached explicitly as the
    // application expands; a parser-admitted program alone is insufficient.
    return !program.needs_flags()&&!program.needs_timers()&&!program.needs_actor_events()&&
        !program.needs_signals()&&!program.needs_scene_resources()&&!program.needs_session_counters()&&
        !program.needs_streams()&&!program.needs_saved_controls()&&!program.needs_selected_actor()&&
        !program.needs_action_choices()&&!program.needs_models()&&!program.needs_room_objects()&&
        !program.needs_periodic_effects()&&!program.needs_surface_effects()&&!program.needs_forced_terminal()&&
        !program.needs_script_audio()&&!program.needs_scene_record_parameters()&&!program.needs_resource_parameters()&&
        program.admits_room_counters(nullptr)&&program.admits_inventory_grants(nullptr,nullptr,nullptr)&&
        program.admits_actor_roster(nullptr)&&program.admits_character_remap(nullptr)&&program.admits_actor_script_commands(nullptr);
}
}
struct NativeSession::RoomState final:gameplay_scenario::ControlEffects {
    std::shared_ptr<gameplay_scene::Records> records=std::make_shared<gameplay_scene::Records>(128);
    gameplay_scenario::SceneControls controls{records};
    gameplay_collision::ownership::Proxies proxies{records};
    gameplay_actors::EntityStore entities;
    gameplay_scenario::SceneModels models;
    gameplay_scenario::SceneModelBindings bindings;
    gameplay_scenario::SceneMatrixPrograms matrices;
    gameplay_scenario::RoomSceneGlobals globals;
    std::shared_ptr<const gameplay_scenario::RoomSceneInput> input;
    std::unique_ptr<gameplay_scenario::RoomSceneOwner> owner;
    gameplay_scenario::SceneMatrixStatus effects_status{gameplay_scenario::SceneMatrixStatus::completed};
    static gameplay_scenario::RoomModelRemap absent_remap()noexcept{
        gameplay_scenario::RoomModelRemap result;result.fill(255);return result;
    }
    RoomState(gameplay_update::Owner& update,gameplay_world::World& world):
        models({},absent_remap()),bindings(models,entities),matrices(controls,models,bindings,update.flags(),world.room){}
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
    void close()noexcept{
        owner.reset();matrices.close();(void)bindings.close();entities.shutdown();
    }
};
NativeSession::NativeSession(std::shared_ptr<const reo::assets::Source> archive,gameplay_world::Profile profile,
    gameplay_scenario::FlagNotifications& notifications,std::uint8_t mode):
    archive_(std::move(archive)),session_(std::make_shared<gameplay_world::Session>()),
    world_(std::move(profile),session_),update_(world_,notifications),room_state_(std::make_unique<RoomState>(update_,world_)){
    world_.mode=mode;
}
NativeSession::~NativeSession(){if(close()==SessionStatus::busy)std::terminate();}
gameplay_scenario::SceneControls& NativeSession::scene_controls()noexcept{return room_state_->controls;}
gameplay_collision::ownership::Proxies& NativeSession::scene_proxies()noexcept{return room_state_->proxies;}
gameplay_scenario::SceneModels& NativeSession::scene_models()noexcept{return room_state_->models;}
gameplay_scenario::SceneMatrixPrograms& NativeSession::scene_matrices()noexcept{return room_state_->matrices;}
std::shared_ptr<gameplay_scene::Records> NativeSession::scene_records()const noexcept{return room_state_->records;}
const gameplay_scenario::RoomSceneOwner* NativeSession::room_scene()const noexcept{return room_state_->owner.get();}
gameplay_scenario::Providers NativeSession::providers()noexcept{
    gameplay_scenario::Providers result;result.world=&world_;
    result.flags=result.canonical_flags=&update_.flags();result.timers=&update_.timers();
    result.action_choices=&update_.action_choices();result.sequences=&sequences_;
    result.lighting=&lighting_;result.scene_channels=&channels_;result.scene_controls=&room_state_->controls;
    result.control_effects=room_state_.get();
    return result;
}
SessionStatus NativeSession::install_room(gameplay_scenario::content::RoomId id){
    if(!open())return SessionStatus::closed;
    if(running_||update_.busy()||world_.busy())return SessionStatus::busy;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        const auto room=archive_.room(id);if(!room)return SessionStatus::missing_room;
        const auto section=room->section(1);if(!section)return SessionStatus::missing_room;
        auto bytes=std::make_shared<const std::vector<std::byte>>(section->begin(),section->end());
        const gameplay_scenario::content::ScriptBank bank(bytes,gameplay_scenario::content::BankFormat::room_section);
        const auto admitted=gameplay_scenario::content::admit_script_program(bank,world_.mode==0?
            gameplay_scenario::DispatchProfile::offline_actor:gameplay_scenario::DispatchProfile::ordinary);
        if(admitted.status!=gameplay_scenario::content::ScriptAdmission::admitted||!admitted.program)return SessionStatus::unsupported_script;
        if(!minimal_room_providers(*admitted.program))return SessionStatus::missing_providers;
        const auto scene=room->section(10),lig=room->section(11);
        if(!scene||!lig)return SessionStatus::missing_providers;
        gameplay_scenario::Lighting prepared_lighting;
        if(prepared_lighting.import_lig(*lig)!=gameplay_scenario::LightingImport::completed)return SessionStatus::missing_providers;
        auto prepared=std::make_unique<RoomState>(update_,world_);
        prepared->input=std::make_shared<const gameplay_scenario::RoomSceneInput>(*scene,bank,
            gameplay_collision::ImportContext{id.scenario,id.room});
        // The first owned room has authored FF model absence. Demanding any
        // physical model slot requires the future real room asset owner.
        for(const auto& definition:prepared->input->records())
            if(definition.model&&definition.model->slot.slot())return SessionStatus::missing_providers;
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
        room_state_=std::move(prepared);
        world_.scenario=id.scenario;world_.room=id.room;room_=id;return SessionStatus::completed;
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
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    room_state_->effects_status=gameplay_scenario::SceneMatrixStatus::completed;
    auto result=update_.advance(*phases,*actors,providers(),script_budget,task_budget);
    const auto status=result.status==gameplay_update::Status::completed&&
        room_state_->effects_status==gameplay_scenario::SceneMatrixStatus::completed?SessionStatus::completed:SessionStatus::frame_failure;
    return{status,std::move(result)};
}
SessionStatus NativeSession::close()noexcept{
    if(closed_)return SessionStatus::completed;
    if(running_||update_.busy()||world_.busy())return SessionStatus::busy;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    // World performs its actual controller-busy check before retiring anything.
    // Update's idle check above guarantees its subsequent close is admissible.
    if(world_.close()!=gameplay_world::Status::completed)return SessionStatus::busy;
    room_state_->close();
    if(update_.close()!=gameplay_update::Status::completed)return SessionStatus::busy;
    closed_=true;return SessionStatus::completed;
}
}
