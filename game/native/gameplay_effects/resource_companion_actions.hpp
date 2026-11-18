#pragma once
#include "resource_companion.hpp"
#include "../gameplay_world/animation_audio.hpp"
#include "../gameplay_lighting/timed_lights.hpp"
namespace reo::native::gameplay_effects {
// Concrete cross-subsystem owner: requests reach the real native resource audio
// frontend/bank mixer and the real canonical scheduler/light pool.
class NativeResourceCompanionActions final:public ResourceCompanionActions {
public:
    NativeResourceCompanionActions(gameplay_world::World& world,gameplay_scenario::SceneResources& resources,
        gameplay_world::ResourceModels& models,const gameplay_scenario::ResourceTemplates& templates,
        gameplay_world::animation_events::BasicAudio& audio,gameplay_lighting::TimedLights& lights):
        world_(world),resources_(resources),models_(models),templates_(templates),audio_(audio),lights_(lights){}
    bool bound_to(const gameplay_world::World&,const gameplay_scenario::SceneResources&,const gameplay_world::ResourceModels&,const gameplay_scenario::ResourceTemplates&)const noexcept override;
    bool light(const gameplay_actors::EntityId&,transform_math::Vector)noexcept override;
    bool cue(const gameplay_actors::EntityId&,std::uint16_t)noexcept override;
    const std::optional<gameplay_lighting::TimedCreated>& last_light()const noexcept{return last_light_;}
    const std::optional<gameplay_audio::Result>& last_audio()const noexcept{return last_audio_;}
private:
    gameplay_world::World& world_;gameplay_scenario::SceneResources& resources_;gameplay_world::ResourceModels& models_;
    const gameplay_scenario::ResourceTemplates& templates_;gameplay_world::animation_events::BasicAudio& audio_;gameplay_lighting::TimedLights& lights_;
    std::optional<gameplay_lighting::TimedCreated> last_light_;
    std::optional<gameplay_audio::Result> last_audio_;
};
}
