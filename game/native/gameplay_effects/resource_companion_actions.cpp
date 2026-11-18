#include "resource_companion_actions.hpp"
namespace reo::native::gameplay_effects {
bool NativeResourceCompanionActions::bound_to(const gameplay_world::World& world,const gameplay_scenario::SceneResources& resources,const gameplay_world::ResourceModels& models,const gameplay_scenario::ResourceTemplates& templates)const noexcept{
    return &world_==&world && &resources_==&resources && &models_==&models && &templates_==&templates&&audio_.bound_to(world,resources,templates)&&lights_.bound_to(world);
}
bool NativeResourceCompanionActions::light(const gameplay_actors::EntityId& actor,transform_math::Vector position)noexcept{
    last_light_.reset();if(!bound_to(world_,resources_,models_,templates_))return false;
    last_light_=lights_.create(actor,{position.x,position.y,position.z});
    const auto status=last_light_->status;
    return status==gameplay_lighting::TimedStatus::completed||status==gameplay_lighting::TimedStatus::skipped||status==gameplay_lighting::TimedStatus::task_full||status==gameplay_lighting::TimedStatus::light_full;
}
bool NativeResourceCompanionActions::cue(const gameplay_actors::EntityId& id,std::uint16_t cue)noexcept{
    last_audio_.reset();if(!bound_to(world_,resources_,models_,templates_))return false;
    const auto actor=world_.resolve(id);if(!actor)return false;
    try{audio_.resource(*actor,cue);last_audio_=audio_.last_result();return true;}
    catch(...){return false;}
}
}
