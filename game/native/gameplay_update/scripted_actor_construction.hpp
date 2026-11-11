#pragma once
#include "material_animation.hpp"
#include "../gameplay_world/actor_assets.hpp"

namespace reo::native::gameplay_update {
struct ScriptedActorRequest {std::uint32_t model_group{},type{},variant{},definition_index{};};
// Immutable, fully prepared content. File reads happen during prepare, outside
// simulation scheduling. Only this factory can pair a request with its assets.
class PreparedScriptedActor final {
public:
    const std::shared_ptr<const gameplay_world::ActorModelAsset>& asset()const noexcept{return asset_;}
private:
    friend class ScriptedActorConstruction;
    PreparedScriptedActor()=default;
    std::uint8_t group_{},type_{},variant_{},definition_{};
    float scale_{};
    gameplay_world::ActorRenderRequest render_;
    std::shared_ptr<const gameplay_world::ActorModelAsset> asset_;
};
enum class ScriptedConstructionStatus {completed,full,unavailable,no_memory};
struct ScriptedConstructed {
    ScriptedConstructionStatus status{ScriptedConstructionStatus::unavailable};
    gameplay_world::actors::EntityId id;
    gameplay_tasks::Created material_task;
};
class ScriptedActorConstruction final {
public:
    // Both native owners are borrowed and must outlive this factory.
    ScriptedActorConstruction(gameplay_world::World&,MaterialAnimations&);
    std::shared_ptr<const PreparedScriptedActor> prepare(const ScriptedActorRequest&,const gameplay_world::ActorAssets&)const;
    ScriptedConstructed create(const PreparedScriptedActor&)noexcept;
private:
    gameplay_world::World& world_;
    MaterialAnimations& materials_;
};
}
