#pragma once
#include "resource_recipes.hpp"
#include "../gameplay_events/events.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
struct ResourceHealthNotice {std::uint32_t kind{},x{},y{},width{},height{},text{};};
// Remaining UI consumer must belong to this World. No implicit success when
// close, feedback or owned text presentation is unavailable.
class ResourceHealthUi {
public:
    virtual ~ResourceHealthUi()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool close()noexcept=0;
    virtual bool feedback(const actors::EntityId&,std::uint8_t selector)noexcept=0;
    virtual bool message(const ResourceHealthNotice&)noexcept=0;
};
enum class ResourceHealthStatus {completed,unavailable,healing_unavailable,ui_unavailable,message_unavailable,event_unavailable};
struct ResourceHealthResult {ResourceHealthStatus status{ResourceHealthStatus::completed};std::uint8_t value{};};
class ResourceHealthEffects final {
public:
    ResourceHealthEffects(ResourceRecipes&,gameplay_update::Owner&,ResourceHealthUi* = nullptr);
    ResourceHealthResult apply(std::uint32_t resource,const actors::EntityId&); //5B2230
    ResourceHealthResult publish(std::uint32_t resource,std::uint32_t mask,const actors::EntityId&); //5B6610
    const std::optional<gameplay_events::Status>& last_event()const noexcept{return last_event_;}
private:
    ResourceRecipes& lifecycle_;gameplay_update::Owner& update_;ResourceHealthUi* ui_;
    std::optional<gameplay_events::Status> last_event_;
};
}
