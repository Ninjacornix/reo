#pragma once
#include "resource_recipes.hpp"
#include "../gameplay_events/events.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
// Main owned-pair execution5B28F0 with real5B6740 cooperative event publication.
// Recipes, update owner and their canonical World must outlive these calls.
class OwnedResourceRecipes final {
public:
    OwnedResourceRecipes(ResourceRecipes&,gameplay_update::Owner&);
    std::int8_t apply(std::uint32_t first,std::uint32_t second);
    // True means an event request was made. Source-compatible priority/full
    // drops are distinguished by last_event(), not reported as recorded events.
    bool publish(std::uint32_t recipe,std::uint32_t extra,std::uint32_t old_content,const actors::EntityId&);
    const std::optional<gameplay_events::Status>& last_event()const noexcept{return last_event_;}
private:
    ResourceRecipes& recipes_;gameplay_update::Owner& update_;
    std::optional<gameplay_events::Status> last_event_;
    void admit()const;
};
}
