#pragma once
#include "impact_policy.hpp"
#include "../gameplay_effects/work.hpp"
namespace reo::native::gameplay_collision::delivery {
// Shared complete5DD6F0 policy. This lane needs no feedback/sound parameter
// provider; its immutable selectors consume the actual work owner and RNG.
Status oriented_contact_impact(gameplay_effects::WorkBackend&,gameplay_session::Random&,
                               const transform_math::Matrix&,Vec3&,std::uint8_t key);
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
// Every stock call has constructor variant0; authored masks are separate.
// A foreign RNG binding is rejected before this provider can emit anything.
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
