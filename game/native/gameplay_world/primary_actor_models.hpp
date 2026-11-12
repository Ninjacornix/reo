#pragma once
#include "actor_assets.hpp"
#include "humanoid_motion_owner.hpp"
#include "primary_actor_initialization.hpp"
#include "../gameplay_scenario/cutscene_primary_selection.hpp"
namespace reo::native::gameplay_world {
struct PrimaryModelDomain;
struct PrimaryStartupContext;
struct PrimaryStartupReport;
// Physical resources have read-only retained views; channels/constraints stay
// Actor-owned. Mutable instances remain private to simulation-owned bindings.
struct PrimaryModelResources {
    std::shared_ptr<const ActorModelAsset> asset;
    std::shared_ptr<const animation::Instance> primary,secondary;
};
class PrimarySceneModelScope final {
    friend class PrimaryActorModels;
    std::shared_ptr<const PrimaryModelDomain> domain_;
    std::uint64_t epoch_{};
};
struct PrimarySceneActorProfile {
    std::uint8_t scale_profile{};std::uint32_t visibility{};
    std::vector<gameplay_scenario::CutsceneActorParameter> parameters;
};
class PrimaryModelRequest final {
    friend class PrimaryActorModels;
    friend class PreparedPrimaryModel;
    std::shared_ptr<const PrimaryModelDomain> domain_;
    std::uint64_t revision_{};
    actors::EntityId actor_;
    std::shared_ptr<animation::Playback> playback_;
    std::shared_ptr<animation::Instance> model_;
    std::shared_ptr<const ActorModelAsset> asset_;
    std::shared_ptr<const HumanoidMotionBanks> banks_;
    PrimaryModelResources physical_;
    std::uint16_t variant_{};
    std::uint8_t slot_{},character_{},model_class_{},appearance_{},loading_mode_{},previous_character_{255};
    std::uint8_t expected_appearance_{};
    std::uint8_t previous_model_class_{255};
    std::optional<PrimarySceneActorProfile> scene_;
    bool rebuild_{},secondary_policy_{},retirement_{},temporary_{};
};
class PreparedPrimaryModel final {
public:
    std::span<const gameplay_scenario::CutsceneActorParameter> scene_parameters()const noexcept{
        return request_.scene_?std::span<const gameplay_scenario::CutsceneActorParameter>(request_.scene_->parameters):std::span<const gameplay_scenario::CutsceneActorParameter>{};
    }
private:
    friend class PrimaryActorModels;
    PrimaryModelRequest request_;
    std::shared_ptr<const ActorModelAsset> asset_;
    std::shared_ptr<animation::Instance> model_,secondary_;
    std::shared_ptr<animation::Playback> first_playback_;
    std::shared_ptr<const HumanoidMotionBanks> banks_;
    std::vector<std::uint8_t> scene_visibility_;
};
enum class PrimaryModelStatus {completed,unavailable,stale,busy,closed,no_memory,full};
struct PrimaryModelApplied {
    PrimaryModelStatus status{PrimaryModelStatus::unavailable};
    bool replaced{},character_released{},initialized{};
    bool retired{};
    bool rebound{};
};
struct PrimarySceneEntryReleased {
    PrimaryModelStatus status{PrimaryModelStatus::unavailable};
    std::size_t visited{},retired{},character_releases{};
    bool base_released{};
    std::optional<std::size_t> failed_slot{};
};
struct PrimarySceneConstructed {
    PrimaryModelStatus status{PrimaryModelStatus::unavailable};
    actors::EntityId id{};
    std::optional<std::uint8_t> roster_slot{};
    bool release_on_exit{},retirement_completed{},main_model_retired{};
};
// Canonical simulation-owner cache for the admitted archive-bundle5EC100 path.
// Capture on the simulation owner; prepare uses only retained immutable request
// inputs and content providers, so asset I/O need not run on that owner.
// A live cache row cannot migrate to another EntityId generation implicitly.
class PrimaryActorModels final {
public:
    PrimaryActorModels(World&,HumanoidMotionOwner&);
    ~PrimaryActorModels();
    PrimaryActorModels(const PrimaryActorModels&)=delete;
    PrimaryActorModels& operator=(const PrimaryActorModels&)=delete;
    bool bound_to(const World& world)const noexcept{return &world_==&world;}
    std::optional<PrimaryModelRequest> capture(actors::EntityId)const noexcept;
    std::optional<PrimaryModelRequest> capture_release(actors::EntityId)const noexcept;
    // Kind0/3 adapter after the scene owner has assigned a real primary ID to
    // this group. Preparation projects663170's appearance reset without
    // changing the live actor; application commits its prefix and postlude.
    std::optional<PrimaryModelRequest> capture_scene(actors::EntityId,
        const gameplay_scenario::CutsceneDescriptor&,std::size_t group)const;
    std::optional<PrimarySceneModelScope> open_scene_models()noexcept;
    // Fresh temporary initialization only; borrowed-slot restore is unavailable.
    std::optional<PrimaryModelRequest> capture_scene(const PrimarySceneModelScope&,actors::EntityId,
        const gameplay_scenario::CutsceneDescriptor&,std::size_t group)const;
    PrimaryModelStatus reset_scene_actors(const PrimarySceneModelScope&)noexcept;
    // Selected descriptor policy is recorded by actual construction. Retirement
    // remains authorized after the temporary Actor generation has been reset.
    PrimaryModelApplied release_scene_model(const PrimarySceneModelScope&,std::size_t slot,const HumanoidMotionAssets&)noexcept;
    // Returns physical work to previously capable canonical bindings. This
    // does not initialize them; the enclosing scene owner must do so afterward.
    PrimaryModelStatus return_scene_models(const PrimarySceneModelScope&)noexcept;
    // Intermediate5ED340 reset before the next queued5ECF90. Final5ED770
    // descriptor retirement has not occurred, so physical rows remain owned.
    PrimaryModelStatus continue_scene_models(const PrimarySceneModelScope&)noexcept;
    static std::shared_ptr<const PreparedPrimaryModel> prepare(const PrimaryModelRequest&,const ActorAssets&,const HumanoidMotionAssets&);
    PrimaryModelApplied apply(const PreparedPrimaryModel&,const gameplay_update::State&,const PrimaryEquipmentContext* = nullptr)noexcept;
    // Complete5EB520 roster/model startup, with reached external resources
    // supplied explicitly. Refusals preserve the source's completed prefix.
    PrimaryStartupReport start_roster(const PrimaryStartupContext&)noexcept;
    // Complete admitted5F0C00 CPU/resource phase. No asset acquisition runs:
    // preparation here only clones bounded immutable banks during scene load.
    PrimarySceneEntryReleased release_scene_entry(const HumanoidMotionAssets&)noexcept;
    // Apply one choice against the current BEFORE-choice roster, after pool
    // initialization. Construction/retirement only: no temporary model-cache
    // admission or update readiness is granted. A failed result with an ID is
    // an explicit committed construction prefix; the scene owner must latch it.
    PrimarySceneConstructed construct_scene_primary(
        const gameplay_scenario::CutscenePrimaryChoice&,
        gameplay_scenario::CutscenePrimaryRoster&,const HumanoidMotionAssets&)noexcept;
    PrimaryModelStatus close()noexcept;
    struct CacheKey {std::uint8_t character{255},model_class{255};friend bool operator==(const CacheKey&,const CacheKey&)=default;};
    CacheKey key(std::size_t slot)const{return rows_.at(slot).key;}
    PrimaryModelResources resident(std::size_t slot)const{return rows_.at(slot).resources;}
private:
    PrimaryModelStatus return_scene_models(const PrimarySceneModelScope&,bool final_exit)noexcept;
    std::optional<PrimaryModelRequest> capture(actors::EntityId,bool retirement,bool nested=false,bool temporary=false)const noexcept;
    std::optional<PrimaryModelRequest> capture_scene(actors::EntityId,const gameplay_scenario::CutsceneDescriptor&,std::size_t,bool)const;
    bool owns(const PrimarySceneModelScope&)const noexcept;
    static std::shared_ptr<const PreparedPrimaryModel> prepare_release(const PrimaryModelRequest&,const HumanoidMotionAssets&);
    PrimaryModelApplied apply(const PreparedPrimaryModel&,const gameplay_update::State&,const PrimaryEquipmentContext*,bool nested)noexcept;
    std::vector<std::array<std::shared_ptr<const animation::MotionBank>,3>> retain_resources()const;
    struct Row {CacheKey key;actors::EntityId actor;PrimaryModelResources resources;};
    World& world_;HumanoidMotionOwner& motions_;
    std::shared_ptr<const PrimaryModelDomain> domain_;
    std::array<Row,8> rows_{};
    struct SceneRecord {PrimarySceneConstructed construction;std::size_t group{};bool bound{},released{};};
    std::array<SceneRecord,8> scene_records_{};
    std::array<actors::EntityId,8> return_bindings_{};
    std::uint64_t scene_epoch_{};
    std::uint64_t revision_{};
    bool running_{},closed_{},scene_open_{},scene_reset_{};
};
}
