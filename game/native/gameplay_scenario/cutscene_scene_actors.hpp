#pragma once
#include "cutscene_playback.hpp"
#include "cutscene_roster_preparation.hpp"
#include "../gameplay_world/primary_actor_models.hpp"
#include "../gameplay_world/cinematic_object_construction.hpp"
#include "../gameplay_update/scripted_actor_construction.hpp"

namespace reo::native::gameplay_scenario {
// The companion physical roster bytes have one owner. The preference is always
// borrowed from CutscenePlaybackState.selected_actor, never cached here.
struct CutsceneSceneRoster {
    CutscenePrimaryRoster primary;
    std::array<std::uint8_t, 8> source_slots{};
    std::array<std::uint32_t, 8> source_statuses{};
};
enum class CutsceneSceneActorStatus { completed, busy, closed, unavailable, no_memory, partial };
struct CutsceneSceneActorsResult {
    CutsceneSceneActorStatus status{CutsceneSceneActorStatus::unavailable};
    std::size_t selected{}, initialized{}, scripted{}, npcs{}, objects{};
    std::optional<std::size_t> failed_group;
};
// Composes the existing real actor/model domains at5F0610. Object reservation
// belongs to that entry; model acquisition remains the later5ECF90 phase.
// Broader renderer/room/reset entrypoints are not silently represented here.
class CutsceneSceneActors final {
  public:
    CutsceneSceneActors(gameplay_update::Owner&, gameplay_world::PrimaryActorModels&,
                        gameplay_world::HumanoidMotionOwner&, const gameplay_world::ActorAssets&,
                        const gameplay_world::HumanoidMotionAssets&,
                        const gameplay_world::CinematicObjectAssets&, CutsceneSceneRoster initial);
    ~CutsceneSceneActors();
    CutsceneSceneActors(const CutsceneSceneActors&) = delete;
    CutsceneSceneActors& operator=(const CutsceneSceneActors&) = delete;
    // Native actor/object5F1290/571010 domains only, with the signed pause gate.
    CutsceneSceneActorStatus initialize_records() noexcept;
    // Exact5ED340 roster/visibility projection; other cleanup is caller-owned.
    CutsceneSceneActorStatus prepare_roster(CutscenePlaybackState&) noexcept;
    CutsceneSceneActorsResult
    construct(std::shared_ptr<const CutsceneDescriptor>, const CutscenePlaybackState&,
              gameplay_world::NpcSceneGraphics* = nullptr,
              const gameplay_world::PrimaryEquipmentContext* = nullptr) noexcept;
    CutsceneSceneActorStatus construct_object_models() noexcept;
    CutsceneSceneActorStatus clear_tracks() noexcept;
    CutsceneSceneActorStatus reset_records() noexcept;
    // Final exit retires only the source's selected first16 descriptors.
    // Intermediate queue transitions preserve physical rows for the next load.
    CutsceneSceneActorStatus finish_models(bool final_exit) noexcept;
    bool busy() const noexcept {
        return running_;
    }
    bool partial() const noexcept {
        return latched_ && !constructed_;
    }
    const CutsceneSceneRoster& roster() const noexcept {
        return roster_;
    }
    std::span<const CutsceneActorBinding> actors() const noexcept {
        return bindings_;
    }
    std::span<const CutsceneActorParameter> parameters(std::size_t group) const {
        return parameters_.at(group);
    }

  private:
    gameplay_update::Owner& update_;
    gameplay_world::World& world_;
    gameplay_world::PrimaryActorModels& models_;
    gameplay_world::HumanoidMotionOwner& motions_;
    const gameplay_world::ActorAssets& assets_;
    const gameplay_world::HumanoidMotionAssets& motion_assets_;
    const gameplay_world::CinematicObjectAssets& object_assets_;
    gameplay_world::NpcActorConstruction npcs_;
    gameplay_update::ScriptedActorConstruction scripted_;
    gameplay_world::CinematicObjectConstruction objects_;
    CutsceneActorTracks actor_tracks_;
    CutsceneObjectTracks object_tracks_;
    CutsceneSceneRoster roster_;
    CutsceneActorReservations reservations_;
    std::shared_ptr<const CutsceneDescriptor> descriptor_;
    std::shared_ptr<const gameplay_world::PreparedCinematicObjects> prepared_objects_;
    std::optional<gameplay_world::PrimarySceneModelScope> scope_;
    std::array<gameplay_world::PrimarySceneConstructed, 8> constructions_{};
    std::array<std::optional<std::uint8_t>, 8> construction_groups_{};
    std::vector<CutsceneActorBinding> bindings_;
    std::vector<CutsceneObjectBinding> object_bindings_;
    std::array<std::vector<CutsceneActorParameter>, 32> parameters_;
    bool running_{}, latched_{}, constructed_{}, records_reset_{};
};
} // namespace reo::native::gameplay_scenario
