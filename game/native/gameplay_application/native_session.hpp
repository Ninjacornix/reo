#pragma once
#include "../gameplay_world/inventory_ui.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
#include "../gameplay_scenario/sequence_control.hpp"
#include "../gameplay_scenario/lighting.hpp"
#include "../gameplay_scenario/scene_channels.hpp"
#include "../gameplay_scenario/scene_controls.hpp"
#include "../gameplay_scenario/room_scene_owner.hpp"
#include "../gameplay_update/update.hpp"
#include "../gameplay_update/reception.hpp"
#include "../gameplay_collision/object_scene.hpp"
#include "room_models.hpp"

namespace reo::native::gameplay_application {
class SessionRooms;
struct SessionRoomGeometry;
struct SessionRoomObjects;
enum class SessionStatus {
    completed,busy,closed,missing_room,unsupported_script,missing_providers,
    missing_frame_services,script_failure,frame_failure
};
struct ScriptStep {
    SessionStatus status{SessionStatus::completed};
    gameplay_update::Result update;
};
struct FrameStep {
    SessionStatus status{SessionStatus::completed};
    gameplay_update::Result update;
};
// Concrete simulation-thread application lifetime. This first admitted room
// profile owns script state and providers; complete actor/physics workers are
// still explicit capabilities of advance(), not implicit successful defaults.
class NativeSession final {
    struct RoomState;
public:
    // A synchronous room-resource lease retains the actual application owners.
    // Its opaque identity retires at replacement, even while old data is held.
    class RoomLease final:public std::enable_shared_from_this<RoomLease> {
    public:
        struct ObjectContext {
            gameplay_actors::EntityStore& entities;
            gameplay_collision::ownership::Proxies& proxies;
            gameplay_scenario::SceneModelBindings& bindings;
            gameplay_scenario::SceneModels& models;
        };
        bool current()const noexcept;
        gameplay_actors::EntityId identity()const noexcept;
        gameplay_scenario::content::RoomId room()const noexcept;
        std::shared_ptr<gameplay_world::World> world()const noexcept;
        std::shared_ptr<gameplay_scenario::SceneMatrixPrograms> programs()const noexcept;
        const gameplay_scenario::content::RdtDirectory& directory()const noexcept;
        ObjectContext object_context()const noexcept;
        gameplay_collision::room_objects::SceneResult initialize_objects(
            std::shared_ptr<gameplay_collision::room_objects::Owner>,
            const gameplay_collision::response::Grid&,const gameplay_collision::response::Grid&,
            gameplay_collision::response::Filter);
        std::shared_ptr<gameplay_collision::room_objects::Scene> object_scene()const noexcept;
    private:
        std::shared_ptr<NativeSession> host_;
        std::shared_ptr<RoomState> state_;
        RoomLease(std::shared_ptr<NativeSession>,std::shared_ptr<RoomState>);
        std::shared_ptr<SessionRoomGeometry>& geometry_cache()const noexcept;
        friend class NativeSession;
        friend class SessionRooms;
    };
    NativeSession(std::shared_ptr<const reo::assets::Source>,gameplay_world::Profile,
                  gameplay_scenario::FlagNotifications&,std::uint8_t mode=1);
    ~NativeSession();
    NativeSession(const NativeSession&)=delete;
    NativeSession& operator=(const NativeSession&)=delete;
    SessionStatus install_room(gameplay_scenario::content::RoomId);
    // Exact37F330 difficulty subproducer; the host supplies its actual selected
    // frontend byte. This does not claim the remaining launch side effects.
    SessionStatus import_launch_difficulty(std::uint8_t)noexcept;
    ScriptStep step_room_script(std::size_t maximum_operations=4096);
    FrameStep advance(gameplay_update::PhaseServices*,gameplay_world::Services*,
                      std::size_t script_budget=4096,std::size_t task_budget=1024);
    SessionStatus close()noexcept;
    bool open()const noexcept{return !closed_&&!world_.closed();}
    gameplay_world::World& world()noexcept{return world_;}
    gameplay_update::Owner& update()noexcept{return update_;}
    gameplay_world::InventoryUi& inventory_ui()noexcept{return *inventory_ui_;}
    gameplay_update::ActorReception& reception()noexcept{return reception_;}
    const gameplay_scenario::content::ScenarioArchive& archive()const noexcept{return archive_;}
    gameplay_scenario::SequenceControl& sequences()noexcept{return sequences_;}
    gameplay_scenario::Lighting& lighting()noexcept{return lighting_;}
    gameplay_scenario::SceneChannels& scene_channels()noexcept{return channels_;}
    gameplay_scenario::SceneControls& scene_controls()noexcept;
    gameplay_collision::ownership::Proxies& scene_proxies()noexcept;
    gameplay_scenario::SceneModels& scene_models()noexcept;
    RoomModels& room_models()noexcept{return room_models_;}
    gameplay_scenario::SceneMatrixPrograms& scene_matrices()noexcept;
    std::shared_ptr<gameplay_scene::Records> scene_records()const noexcept;
    const gameplay_scenario::RoomSceneOwner* room_scene()const noexcept;
    std::optional<gameplay_scenario::content::RoomId> room()const noexcept{return room_;}
    std::shared_ptr<RoomLease> retain_room(std::shared_ptr<NativeSession>)noexcept;
private:
    RoomModels room_models_;
    gameplay_scenario::content::ScenarioArchive archive_;
    std::shared_ptr<gameplay_world::Session> session_;
    gameplay_world::World world_;
    gameplay_update::ActorReception reception_;
    gameplay_update::Owner update_;
    gameplay_scenario::SequenceControl sequences_;
    gameplay_scenario::Lighting lighting_;
    gameplay_scenario::SceneChannels channels_;
    std::shared_ptr<RoomState> room_state_;
    std::shared_ptr<SessionRoomObjects> room_objects_;
    std::optional<gameplay_scenario::content::RoomId> room_;
    bool running_{},closed_{};
    std::unique_ptr<gameplay_world::InventoryUi> inventory_ui_;
    gameplay_scenario::Providers providers()noexcept;
    friend class SessionRooms;
};
}
