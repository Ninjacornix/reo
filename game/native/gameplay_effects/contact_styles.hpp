#pragma once
#include "work.hpp"
namespace reo::native::gameplay_effects {
class ContactStyleChannels {
public:
    virtual ~ContactStyleChannels()=default;
    // Actual571EC0 owner. This is required only by styles3/7; an absent
    // implementation must refuse rather than emit a different visual family.
    virtual WorkStatus create(const std::optional<transform_math::Matrix>&,
        transform_math::Vector,std::uint32_t mode,std::uint32_t variant)=0;
};
struct ContactStyleContext {
    std::optional<std::int16_t> discriminator;
    ContactStyleChannels* channels{};
};
// Complete5DD270 dispatch/construction policy. Natural work/resource misses
// are normal returns, including independently attempted style6 allocations.
WorkStatus construct_contact_style(WorkBackend&,ContactStyleContext,
    const std::optional<transform_math::Matrix>&,transform_math::Vector,std::uint32_t);
}
