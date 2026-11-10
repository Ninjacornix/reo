#pragma once
#include "resource_recipes.hpp"
#include "animation_audio.hpp"
#include "../gameplay_weapon_resources/weapon_resources.hpp"
#include "../gameplay_effects/periodic_visuals.hpp"
namespace reo::native::gameplay_world {
enum class ResourceDepletionStatus {completed,closed,unavailable,visual_unavailable,audio_unavailable,weapon_unavailable};
struct ResourceDepletionResult {ResourceDepletionStatus status{ResourceDepletionStatus::completed};std::int8_t value{};};
class ResourceDepletion final {
public:
    ResourceDepletion(ResourceRecipes&,gameplay_effects::PeriodicVisuals&,animation_events::BasicAudio&,gameplay_weapon_resources::Owner&);
    ResourceDepletionResult replace_depleted(std::uint32_t resource,const actors::EntityId&); //5B4AD0
    ResourceDepletionResult use_cost(std::uint32_t resource,const actors::EntityId&); //5B2590
    const std::optional<gameplay_effects::PeriodicVisuals::CompanionsCreated>& last_debris()const noexcept{return debris_;}
    const std::optional<gameplay_audio::Result>& last_cue()const noexcept{return cue_;}
    const std::optional<gameplay_weapon_resources::Refreshed>& last_refresh()const noexcept{return refresh_;}
private:
    ResourceRecipes& lifecycle_;ResourceFactory& factory_;ResourceUse use_;
    gameplay_effects::PeriodicVisuals& visuals_;animation_events::BasicAudio& audio_;gameplay_weapon_resources::Owner& weapons_;
    std::optional<gameplay_effects::PeriodicVisuals::CompanionsCreated> debris_;
    std::optional<gameplay_audio::Result> cue_;
    std::optional<gameplay_weapon_resources::Refreshed> refresh_;
    void reset()noexcept;
    ResourceDepletionResult replace_core(std::uint32_t,const actors::EntityId&);
};
}
