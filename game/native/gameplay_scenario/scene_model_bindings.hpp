#pragma once
#include "scene_models.hpp"
#include "../gameplay_collision/object_lifetime.hpp"
#include <memory>

namespace reo::native::gameplay_scenario {
enum class ModelBindingError {none,closed,busy,invalid_slot,foreign_or_stale,wrong_entity_kind,missing_target,missing_full_pose};
struct ModelBindingFailure {ModelBindingError code{ModelBindingError::none};std::uint8_t slot{};};
// Models, the scene EntityStore and room-object Lifetime outlive this adapter.
// The simulation owner serializes access. Bindings retain native targets, while
// fresh EntityStore lookups reject retirement/reuse before reading a live pose.
class SceneModelBindings final:public gameplay_collision::room_objects::ModelBindings {
public:
    using ObjectInstance=gameplay_collision::room_objects::ObjectInstance;
    using EntityId=gameplay_actors::EntityId;
    SceneModelBindings(SceneModels&,gameplay_actors::EntityStore&)noexcept;
    ~SceneModelBindings();
    SceneModelBindings(const SceneModelBindings&)=delete;
    SceneModelBindings& operator=(const SceneModelBindings&)=delete;
    std::uint8_t resolve(std::uint8_t)const noexcept override;
    bool admit(std::uint8_t,gameplay_collision::room_objects::ModelOperation)noexcept override;
    bool healthy()const noexcept override{return failure_.code==ModelBindingError::none&&!closed_;}
    void mark(std::uint8_t)noexcept override;
    void bind(std::uint8_t,EntityId)noexcept override;
    void unbind(std::uint8_t)noexcept override;
    void retain_pose(std::uint8_t,const gameplay_collision::actors::Basis&)noexcept override;
    void retain_pose_full(std::uint8_t,const gameplay_collision::actors::Basis&,const std::array<float,4>&)noexcept override;
    bool bind_pose(std::uint8_t,std::shared_ptr<ModelMatrix>)noexcept;
    ModelReference reference(std::uint8_t authored)const noexcept{return models_.reference(authored);}
    bool admit_reference(const ModelReference&,gameplay_collision::room_objects::ModelOperation)noexcept;
    void mark(const ModelReference&)noexcept;
    void bind(const ModelReference&,EntityId)noexcept;
    void retain_pose_full(const ModelReference&,const gameplay_collision::actors::Basis&,const std::array<float,4>&)noexcept;
    EntityId target(const ModelReference& ref)const noexcept{return ref.slot()?target(*ref.slot()):EntityId{};}
    bool bind_pose(const ModelReference&,std::shared_ptr<ModelMatrix>)noexcept;
    void unbind(const ModelReference&)noexcept;
    std::optional<ModelMatrix> live_pose(const ModelReference&)noexcept;
    std::optional<ModelMatrix> live_pose(std::uint8_t)noexcept;
    std::array<std::uint32_t,4> mask()const noexcept;
    EntityId target(std::uint8_t)const noexcept;
    ModelBindingFailure failure()const noexcept{return failure_;}
    ModelBindingError close()noexcept;
private:
    struct Binding {EntityId id;std::shared_ptr<ObjectInstance> object;std::shared_ptr<ModelMatrix> matrix;};
    SceneModels& models_;
    gameplay_actors::EntityStore& scene_;
    std::array<Binding,128> bindings_;
    ModelBindingFailure failure_;
    bool closed_{},busy_{};
    bool enter(std::uint8_t,bool cleanup=false)noexcept;
    void fail(ModelBindingError,std::uint8_t)noexcept;
};
} // namespace reo::native::gameplay_scenario
