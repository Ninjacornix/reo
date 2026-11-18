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
    void use_carried_content(const actors::EntityId&,std::uint32_t content); //5B4460
    void consume_carried_content(const actors::EntityId&,std::uint32_t content); //5B45E0
    void destroy_content(const actors::EntityId&,std::uint32_t content); //5B47F0
    //5B6450: scenario41 ages content3717 in all four carried slots and,
    // for character6, all32 storage slots. Successful expiry transforms
    // publish operation5 through the same canonical gameplay message owner.
    bool age_carried_expirations(const actors::EntityId&);
    const std::optional<gameplay_events::Recorded>& last_record()const noexcept{return last_record_;}
private:
    ResourceRecipes& lifecycle_;gameplay_update::Owner& update_;ResourceUse use_;
    std::optional<gameplay_events::Recorded> last_record_;
    std::shared_ptr<Actor> actor(const actors::EntityId&)const;
    std::uint8_t addressed(std::uint32_t)const;
    void record(const Actor&,std::uint16_t content);
    void cleanup(const actors::EntityId&,std::uint8_t);
    void decrement_core(const actors::EntityId&,std::uint32_t);
    void notify(std::uint8_t resource,std::uint8_t actor,std::uint8_t operation);
};
}
