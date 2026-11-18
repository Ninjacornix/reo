#include "primary_custom_statistics.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "primary_custom_statistics.inc"
}
std::span<const PrimaryCustomStatisticRow> file1_primary_custom_statistics()noexcept{return primary_custom_statistic_rows;}
std::optional<std::size_t> primary_custom_actor_index(std::uint16_t identity)noexcept{
    const auto found=std::find_if(primary_custom_statistic_rows.begin(),primary_custom_statistic_rows.end()-1,[&](const auto& row){return row.identity==identity;});
    return found==primary_custom_statistic_rows.end()-1?std::optional<std::size_t>{}:std::size_t(found-primary_custom_statistic_rows.begin());
}
const PrimarySubstitutionDefinition& primary_substitution_definition(std::uint16_t variant){
    const auto found=std::lower_bound(primary_substitution_definitions.begin(),primary_substitution_definitions.end(),variant,[](const auto& row,std::uint16_t key){return row.variant<key;});
    if(found==primary_substitution_definitions.end()||found->variant!=variant)throw std::out_of_range("Native primary substitution metadata unavailable");
    return *found;
}
PrimaryInitializationStatus apply_primary_custom_statistics(Actor& actor,gameplay_session::Random& random)noexcept{
    if(!actor.model_variant)return PrimaryInitializationStatus::completed;
    if(!actor.primary_state)return PrimaryInitializationStatus::unavailable;
    try{
        (void)primary_substitution_definition(actor.model_variant);
        const auto identity=std::uint16_t(actor.model_variant-1);const auto& definition=npc_actor_definition(identity);
        const auto index=primary_custom_actor_index(identity);const auto& row=index?primary_custom_statistic_rows[*index]:primary_custom_statistic_rows.back();
        const auto band=primary_custom_health_bands[row.health_band&7u];
        const auto value=std::int32_t(band[0])+std::int32_t(random.request(0))%(std::int32_t(band[1])-band[0]+1);
        actor.maximum=std::bit_cast<std::int16_t>(std::uint16_t(value));
        const float product=float(actor.maximum)*primary_custom_fractions[row.fraction_band&7u];
        actor.current=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(std::trunc(product))));
        actor.gauge_rate_variant=row.gauge_rate;actor.primary_state->statistic_multiplier=primary_custom_multipliers[row.multiplier_band&7u];actor.contact.damage_scale=row.damage_scale;
        actor.motion_style=definition.motion_style;actor.motion_subtype=definition.motion_subtype;actor.model_height_correction=definition.height_parameter;actor.model_scale={definition.scale,definition.scale,definition.scale};
        return PrimaryInitializationStatus::completed;
    }catch(...){return PrimaryInitializationStatus::unavailable;}
}
}
