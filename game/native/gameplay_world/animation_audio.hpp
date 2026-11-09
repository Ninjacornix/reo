#pragma once
#include "animation_primitives.hpp"
#include "../gameplay_audio/owner.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
namespace reo::native::gameplay_world::animation_events {
// Concrete original1B8BB0/1B8B20/1B8C70 frontends over the existing native bank
// owner. Surface-region, node-surface and scenario-remap routes remain explicit
// unsupported operations; they are not replaced by a guessed sound request.
class BasicAudio final : public Audio {
  public:
    BasicAudio(World&, gameplay_audio::Owner&, const gameplay_audio::SpatialContext&,
               gameplay_scenario::SceneResources&, const gameplay_scenario::ResourceTemplates&);
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

  private:
    World& world_;
    gameplay_audio::Owner& owner_;
    const gameplay_audio::SpatialContext& spatial_;
    gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::optional<gameplay_audio::Result> last_;
    void admit(const Actor&) const;
    void request(const Actor&, std::uint32_t bank, std::uint32_t event);
};
} // namespace reo::native::gameplay_world::animation_events
