#include "footwear.hpp"
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
struct FootwearEntry {std::uint16_t variant;std::int8_t offset;};
#include "footwear_profile.inc"
}
std::int8_t footwear_offset(const Actor& actor){
    if(actor.model_variant){
        const auto found=std::lower_bound(variant_footwear.begin(),variant_footwear.end(),actor.model_variant,[](const auto& row,auto key){return row.variant<key;});
        if(found==variant_footwear.end()||found->variant!=actor.model_variant)throw std::domain_error("Native footwear model variant unavailable");
        return found->offset;
    }
    if(actor.character>=8||actor.appearance_variant>=3)throw std::domain_error("Native footwear appearance profile unavailable");
    return player_footwear[3u*actor.character+actor.appearance_variant];
}
}
