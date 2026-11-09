#pragma once
#include "resource_models.hpp"
#include "../gameplay_scenario/periodic_effects.hpp"
#include "../gameplay_scenario/scene_record_attachment.hpp"
namespace reo::native::gameplay_world {
// Concrete primary-resource frame consumers. Borrowed canonical owners outlive
// these simulation-thread calls. Unmigrated extended actors/rebuild paths
// refuse when reached; they do not invoke a legacy callback or a no-op.
class ResourceFrames final {
public:
    ResourceFrames(World& world,gameplay_scenario::SceneResources& resources,ResourceModels& models,gameplay_scenario::PeriodicEmitter* emitter=nullptr,std::shared_ptr<gameplay_scene::Records> scene_records={}):world_(world),resources_(resources),models_(models),emitter_(emitter),scene_records_(std::move(scene_records)){}
    bool bound_to(const ResourceModels& value)const noexcept{return &models_==&value;}
    void common(const ResourceModelId&,ResourceModel&);
    void weapon(const ResourceModelId&,ResourceModel&);
    //5B1850 or5B1A90; the descriptor identity survives instance retirement.
    void release(std::uint8_t,bool clear_owner_flag=false);
private:
    World& world_;
    gameplay_scenario::SceneResources& resources_;
    ResourceModels& models_;
    gameplay_scenario::PeriodicEmitter* emitter_;
    std::shared_ptr<gameplay_scene::Records> scene_records_;
    void pulse(ResourceModel&);
    void admit(const ResourceModelId&,const ResourceModel&)const;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
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
