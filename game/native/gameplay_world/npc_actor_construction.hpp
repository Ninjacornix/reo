#pragma once
#include "actor_assets.hpp"
#include "auxiliary_actors.hpp"
#include "../animation/playback.hpp"
#include "../gameplay_scenario/cutscene_descriptor.hpp"
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
struct CutsceneNpcRequest {std::uint16_t id{};std::uint8_t model_class{};};
std::vector<std::optional<CutsceneNpcRequest>> cutscene_npc_requests(const gameplay_scenario::CutsceneDescriptor&);
class PreparedCutsceneNpcActors final {
public:
    std::size_t size()const noexcept{return entries_.size();}
    std::size_t npc_count()const noexcept{return count_;}
    const std::optional<CutsceneNpcRequest>& request(std::size_t index)const{return entries_.at(index).request;}
    std::span<const gameplay_scenario::CutsceneActorParameter> parameters(std::size_t index)const{return entries_.at(index).parameters;}
private:
    friend class NpcActorConstruction;
    struct Entry {
        std::optional<CutsceneNpcRequest> request;
        std::shared_ptr<const PreparedNpcActor> actor;
        std::uint8_t scale_profile{};
        std::uint32_t visibility{};
        std::vector<gameplay_scenario::CutsceneActorParameter> parameters;
    };
    std::vector<Entry> entries_;
    std::size_t count_{};
};
// Actual377560 shadow/model-work preparation belongs to the rendering
// boundary. A required provider must report whether its request completed;
// the source's no-shadow result is a completed request, not a missing owner.
class NpcSceneGraphics {
public:virtual ~NpcSceneGraphics()=default;
    virtual bool prepare_shadow(World&,actors::EntityId,std::uint16_t model)=0;
};
class NpcActorConstruction final {
public:
    explicit NpcActorConstruction(World&);
    std::shared_ptr<const PreparedNpcActor> prepare(std::uint32_t identity,std::uint32_t model_class,
        const ActorAssets&,const NpcMotionBindings&)const;
    NpcConstructed create(const PreparedNpcActor&)noexcept;
    std::shared_ptr<const PreparedCutsceneNpcActors> prepare_cutscene_npcs(
        const gameplay_scenario::CutsceneDescriptor&,const ActorAssets&,const NpcMotionBindings&)const;
    // A failure after allocation returns its real ID and preceding effects.
    // The enclosing scene owner must latch/handle that partial result.
    NpcConstructed create_cutscene_npc(const PreparedCutsceneNpcActors&,std::size_t group,NpcSceneGraphics* = nullptr)noexcept;
private:World& world_;
};
}
