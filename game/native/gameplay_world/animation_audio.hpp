#pragma once
#include "animation_primitives.hpp"
#include "../gameplay_audio/owner.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
#include "../gameplay_scenario/scene_models.hpp"
namespace reo::native::gameplay_contact_world {class RoomResources;}
namespace reo::native::gameplay_world::animation_events {
// Concrete actor/resource/surface frontends over the existing native bank
// owner and canonical room region owner. All borrowed owners outlive this
// component. Node audio additionally requires the canonical SceneModels owner.
class BasicAudio final : public Audio {
  public:
    BasicAudio(World&, gameplay_audio::Owner&, const gameplay_audio::SpatialContext&,
               gameplay_scenario::SceneResources&, const gameplay_scenario::ResourceTemplates&);
    BasicAudio(World&, gameplay_audio::Owner&, const gameplay_audio::SpatialContext&,
               gameplay_scenario::SceneResources&, const gameplay_scenario::ResourceTemplates&,
               gameplay_contact_world::RoomResources&);
    void surface(Actor&, std::int8_t) override;
    void actor(Actor&, std::uint32_t event, bool alternate) override;
    void resource(Actor&, std::uint16_t event) override;
    void node(Actor&, std::uint16_t) override;
    void position(Actor&, std::uint32_t) override;
    bool bound_to(const World& world,const gameplay_scenario::SceneResources& resources,const gameplay_scenario::ResourceTemplates& templates)const noexcept{
        return &world_==&world && &resources_==&resources && &templates_==&templates&&!world.closed()&&owner_.bound_to(world.session().random);
    }
    void bind_scene_models(gameplay_scenario::SceneModels& models)noexcept{models_=&models;}
    // Absence means the source frontend made no bank request. Actual ignored
    // pending/unavailable/native command outcomes are retained, never converted
    // to a fabricated successful sound or an exception skipping later effects.
    const std::optional<gameplay_audio::Result>& last_result() const noexcept {
        return last_;
    }
    std::span<const gameplay_audio::Result> last_surface_results()const noexcept{return {surface_results_.data(),surface_count_};}

  private:
    World& world_;
    gameplay_audio::Owner& owner_;
    const gameplay_audio::SpatialContext& spatial_;
    gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::optional<gameplay_audio::Result> last_;
    gameplay_contact_world::RoomResources* rooms_{};
    gameplay_scenario::SceneModels* models_{};
    std::array<gameplay_audio::Result,2> surface_results_{};
    std::size_t surface_count_{};
    void admit(const Actor&) const;
    void request(const Actor&, std::uint32_t bank, std::uint32_t event);
};
} // namespace reo::native::gameplay_world::animation_events
