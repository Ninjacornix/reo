#pragma once
#include "actor_assets.hpp"
#include "auxiliary_actors.hpp"
#include "../animation/playback.hpp"
namespace reo::native::gameplay_world {
struct NpcDefinitionRecord {
    std::uint16_t id{},model_id{};
    std::uint8_t motion_style{},motion_subtype{},contact_selector{};
    std::int16_t health{};
    float scale{},height_parameter{};
};
const NpcDefinitionRecord& npc_actor_definition(std::uint16_t);
// Actual bank owners must supply these before actor creation. They remain
// immutable native resources, with explicit absence refused, never guessed.
struct NpcMotionBindings {
    std::shared_ptr<const animation::MotionBank> primary;
    std::array<std::shared_ptr<const animation::MotionBank>,2> style;
    std::array<std::shared_ptr<const animation::MotionBank>,8> actor_type;
};
class PreparedNpcActor final {
public:
    const std::shared_ptr<const ActorModelAsset>& asset()const noexcept{return asset_;}
    const NpcDefinitionRecord& definition()const noexcept{return definition_;}
private:
    friend class NpcActorConstruction;
    std::shared_ptr<const ActorModelAsset> asset_;
    NpcDefinitionRecord definition_;
    std::uint8_t model_class_{},character_{};
    std::array<std::shared_ptr<const animation::MotionBank>,3> banks_;
};
enum class NpcConstructionStatus {completed,full,unavailable,busy,closed,no_memory};
struct NpcConstructed {NpcConstructionStatus status{NpcConstructionStatus::unavailable};actors::EntityId id;};
class NpcActorConstruction final {
public:
    explicit NpcActorConstruction(World&);
    std::shared_ptr<const PreparedNpcActor> prepare(std::uint32_t identity,std::uint32_t model_class,
        const ActorAssets&,const NpcMotionBindings&)const;
    NpcConstructed create(const PreparedNpcActor&)noexcept;
private:World& world_;
};
}
