#pragma once
#include "resource_recipes.hpp"
#include "../gameplay_events/statistics.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
// Canonical resource consumption over the already bound recipe/lifecycle owners.
// Empty actor identity is known null; stale/foreign nonempty identities refuse.
class ResourceConsumption final {
public:
    ResourceConsumption(ResourceRecipes&,gameplay_update::Owner&);
    void decrement(const actors::EntityId&,std::uint32_t resource); //5B4550
    std::uint8_t consume_or_transform(const actors::EntityId&,std::uint32_t resource); //5B46A0
    void destroy(const actors::EntityId&,std::uint32_t resource); //5B4900
    std::uint8_t transform(const actors::EntityId&,std::uint32_t resource); //5B4990
    const std::optional<gameplay_events::Recorded>& last_record()const noexcept{return last_record_;}
private:
    ResourceRecipes& lifecycle_;gameplay_update::Owner& update_;ResourceUse use_;
    std::optional<gameplay_events::Recorded> last_record_;
    std::shared_ptr<Actor> actor(const actors::EntityId&)const;
    std::uint8_t addressed(std::uint32_t)const;
    void record(const Actor&,std::uint16_t content);
    void cleanup(const actors::EntityId&,std::uint8_t);
};
}
