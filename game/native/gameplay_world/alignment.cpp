#include "alignment.hpp"
#include "../transform_math/heading.hpp"
#include "../transform_math/transform_math.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
bool prepare_contact_alignment(Actor& actor,std::uint32_t full_limit,float offset){
    const auto& contact=actor.projectile_contact;
    const auto direction=transform_math::direction_turn(contact.normal.x,contact.normal.z);
    const auto facing=std::uint16_t(direction+0x8000u);
    const auto limit=std::bit_cast<std::int16_t>(std::uint16_t(full_limit));
    if(limit){
        const auto difference=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(actor.orientation[1])-facing));
        if(!(std::fabs(float(difference))<=float(std::bit_cast<std::int32_t>(full_limit))))return false;
    }
    if(!std::isfinite(offset)||!std::isfinite(contact.point.x)||!std::isfinite(contact.point.z))throw std::domain_error("Native contact alignment finite profile required");
    const float radians=std::bit_cast<float>(0x38c90fdbu)*float(direction);
    const auto wave=transform_math::sin_cos(radians);
    const float x=contact.point.x+offset*wave.sine;
    const float z=contact.point.z+offset*wave.cosine;
    if(!std::isfinite(x)||!std::isfinite(z))throw std::domain_error("Native contact alignment result unavailable");
    actor.alignment_target=AlignmentTarget{{x,actor.position.y,z},std::bit_cast<std::int16_t>(facing)};return true;
}
}
