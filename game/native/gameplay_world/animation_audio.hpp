#pragma once
#include "animation_primitives.hpp"
#include "../gameplay_audio/owner.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
namespace reo::native::gameplay_contact_world {class RoomResources;}
namespace reo::native::gameplay_world::animation_events {
// Concrete actor/resource/surface frontends over the existing native bank
// owner and canonical room region owner. All borrowed owners outlive this
// component. Node/scenario-remap routes remain explicit reached refusals.
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
    std::array<gameplay_audio::Result,2> surface_results_{};
    std::size_t surface_count_{};
    void admit(const Actor&) const;
    void request(const Actor&, std::uint32_t bank, std::uint32_t event);
};
} // namespace reo::native::gameplay_world::animation_events
