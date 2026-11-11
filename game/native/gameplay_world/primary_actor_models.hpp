#pragma once
#include "actor_assets.hpp"
#include "humanoid_motion_owner.hpp"
#include "primary_actor_initialization.hpp"
namespace reo::native::gameplay_world {
struct PrimaryModelDomain;
class PrimaryModelRequest final {
    friend class PrimaryActorModels;
    std::shared_ptr<const PrimaryModelDomain> domain_;
    std::uint64_t revision_{};
    actors::EntityId actor_;
    std::shared_ptr<animation::Playback> playback_;
    std::shared_ptr<animation::Instance> model_;
    std::shared_ptr<const HumanoidMotionBanks> banks_;
    std::uint16_t variant_{};
    std::uint8_t slot_{},character_{},model_class_{},appearance_{},loading_mode_{},previous_character_{255};
    bool rebuild_{},secondary_policy_{};
};
class PreparedPrimaryModel final {
    friend class PrimaryActorModels;
    PrimaryModelRequest request_;
    std::shared_ptr<const ActorModelAsset> asset_;
    std::shared_ptr<animation::Instance> model_,secondary_;
    std::shared_ptr<animation::Playback> first_playback_;
    std::shared_ptr<const HumanoidMotionBanks> banks_;
};
enum class PrimaryModelStatus {completed,unavailable,stale,busy,closed,no_memory};
struct PrimaryModelApplied {
    PrimaryModelStatus status{PrimaryModelStatus::unavailable};
    bool replaced{},character_released{},initialized{};
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
    std::optional<PrimaryModelRequest> capture(actors::EntityId)const noexcept;
    static std::shared_ptr<const PreparedPrimaryModel> prepare(const PrimaryModelRequest&,const ActorAssets&,const HumanoidMotionAssets&);
    PrimaryModelApplied apply(const PreparedPrimaryModel&,const gameplay_update::State&,const PrimaryEquipmentContext* = nullptr)noexcept;
    PrimaryModelStatus close()noexcept;
    struct CacheKey {std::uint8_t character{255},model_class{255};friend bool operator==(const CacheKey&,const CacheKey&)=default;};
    CacheKey key(std::size_t slot)const{return rows_.at(slot).key;}
private:
    struct Row {CacheKey key;actors::EntityId actor;};
    World& world_;HumanoidMotionOwner& motions_;
    std::shared_ptr<const PrimaryModelDomain> domain_;
    std::array<Row,8> rows_{};
    std::uint64_t revision_{};
    bool running_{},closed_{};
};
}
