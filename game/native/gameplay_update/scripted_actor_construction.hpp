#pragma once
#include "material_animation.hpp"
#include "../gameplay_world/actor_assets.hpp"
#include "../gameplay_scenario/cutscene_descriptor.hpp"

namespace reo::native::gameplay_update {
struct ScriptedActorRequest {std::uint32_t model_group{},type{},variant{},definition_index{};};
// I/O-free authored request selection. Absent entries require their distinct
// primary/NPC owner or are authored terminal/ignored headers.
std::vector<std::optional<ScriptedActorRequest>> cutscene_scripted_requests(const gameplay_scenario::CutsceneDescriptor&);
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
// Only kind2 headers select6BA5C0. Other kinds remain explicit unavailable
// entries for their actual primary/NPC owners; no null actor is fabricated.
class PreparedCutsceneScriptedActors final {
public:
    std::size_t size()const noexcept{return entries_.size();}
    std::size_t scripted_count()const noexcept{return scripted_count_;}
    const std::optional<ScriptedActorRequest>& request(std::size_t index)const{return entries_.at(index).request;}
private:
    friend class ScriptedActorConstruction;
    struct Entry {
        std::optional<ScriptedActorRequest> request;
        std::shared_ptr<const PreparedScriptedActor> actor;
        std::uint8_t scale_profile{};
        std::uint32_t visibility{};
    };
    std::vector<Entry> entries_;
    std::size_t scripted_count_{};
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
    std::shared_ptr<const PreparedCutsceneScriptedActors> prepare_cutscene_scripted(
        const gameplay_scenario::CutsceneDescriptor&,const gameplay_world::ActorAssets&)const;
    ScriptedConstructed create_cutscene_scripted(const PreparedCutsceneScriptedActors&,std::size_t group)noexcept;
private:
    gameplay_world::World& world_;
    MaterialAnimations& materials_;
};
}
