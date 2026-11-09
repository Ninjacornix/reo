#pragma once
#include "impact_policy.hpp"
#include "../gameplay_effects/work.hpp"
namespace reo::native::gameplay_collision::delivery {
class ImpactParameters {
  public:
    virtual ~ImpactParameters() = default;
    // Read the canonical current feedback settings at each successful spawn.
    virtual transform_math::Vector modulation() const = 0;
    virtual float scalar() const = 0;
    virtual bool sound(std::uint8_t actor_slot, Vec3 position, std::uint16_t event) = 0;
};
// The two distinct stock contact populations (5DD6F0 /5DD9D0). They use the
// session's actual RNG and the SAME effect work/piece owner as other emitters.
// The backend also consumes constructor RNG, before the policy's success RNG.
class ContactVisuals final : public ImpactVisuals {
  public:
    ContactVisuals(gameplay_effects::WorkBackend&, gameplay_session::Random&, ImpactParameters&);
    Status oriented(const transform_math::Matrix&, Vec3&, std::uint8_t key) override;
    Status surface(View, const std::optional<transform_math::Matrix>&, Vec3&,
                   std::uint8_t key) override;

  private:
    gameplay_effects::WorkBackend& works_;
    gameplay_session::Random& random_;
    ImpactParameters& parameters_;
};
} // namespace reo::native::gameplay_collision::delivery
