#pragma once
#include "resource_health_effects.hpp"
#include "resource_deployment.hpp"
#include "../gameplay_events/statistics.hpp"
namespace reo::native::gameplay_world {
enum class ResourceEffectStatus {completed,unavailable,health_unavailable,deployment_unavailable,statistics_unavailable};
struct ResourceEffectResult {ResourceEffectStatus status{ResourceEffectStatus::completed};std::int8_t value{};};
// Complete5B2080 admission/dispatch/post-effect lifecycle over the actual
// consumers. Required UI/network capabilities retain their explicit failures.
class ResourceEffects final {
public:
    ResourceEffects(ResourceRecipes&,gameplay_update::Owner&,ResourceHealthUi* = nullptr);
    ResourceEffectResult apply(std::uint32_t resource,const actors::EntityId&);
    const std::optional<ResourceHealthResult>& last_health()const noexcept{return health_result_;}
    const std::optional<ResourceDeploymentValue>& last_deployment()const noexcept{return deployment_result_;}
    const std::optional<gameplay_events::Recorded>& last_record()const noexcept{return completion_;}
private:
    ResourceRecipes& lifecycle_;gameplay_update::Owner& update_;
    ResourceHealthEffects health_;ResourceDeployment deployment_;
    std::optional<ResourceHealthResult> health_result_;
    std::optional<ResourceDeploymentValue> deployment_result_;
    std::optional<gameplay_events::Recorded> completion_;
};
}
