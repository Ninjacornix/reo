#pragma once
#include "resource_models.hpp"
#include "../gameplay_scenario/periodic_effects.hpp"
namespace reo::native::gameplay_world {
// Concrete primary-resource frame consumers. Borrowed canonical owners outlive
// these simulation-thread calls. Unmigrated extended actors/rebuild paths
// refuse when reached; they do not invoke a legacy callback or a no-op.
class ResourceFrames final {
public:
    ResourceFrames(World& world,gameplay_scenario::SceneResources& resources,ResourceModels& models,gameplay_scenario::PeriodicEmitter* emitter=nullptr):world_(world),resources_(resources),models_(models),emitter_(emitter){}
    bool bound_to(const ResourceModels& value)const noexcept{return &models_==&value;}
    void common(const ResourceModelId&,ResourceModel&);
    void weapon(const ResourceModelId&,ResourceModel&);
private:
    World& world_;
    gameplay_scenario::SceneResources& resources_;
    ResourceModels& models_;
    gameplay_scenario::PeriodicEmitter* emitter_;
    void pulse(ResourceModel&);
    void admit(const ResourceModelId&,const ResourceModel&)const;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
    void release(std::uint8_t,bool clear_owner_flag);
    const ResourcePartPoses& bases(const ResourceModel&)const;
};
class WeaponModelWork final:public ResourceModelWork {
public:
    explicit WeaponModelWork(ResourceFrames& frames):frames_(frames){}
    void update(ResourceModels&,const ResourceModelId&,ResourceModel&)override;
private:
    ResourceFrames& frames_;
};
class CommonModelWork final:public ResourceModelWork {
public:
    explicit CommonModelWork(ResourceFrames& frames):frames_(frames){}
    void update(ResourceModels&,const ResourceModelId&,ResourceModel&)override;
private:
    ResourceFrames& frames_;
};
}
