#pragma once
#include "../gameplay_tasks/events.hpp"
#include <cstdint>
#include <memory>
#include <optional>

namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_scenario {
class FlagState;
enum class ScenePolicyFlagCallback : std::uint8_t {clear_primary,set_primary};
enum class ScenePolicyTaskStatus : std::uint8_t {completed,closed,invalid_payload,unavailable_owner,no_memory,busy};
struct ScenePolicyTaskRegistration {
    std::uint8_t bank{},slot{},actor_owner{};
    std::uint32_t flag{};
    ScenePolicyFlagCallback callback{ScenePolicyFlagCallback::clear_primary};
};
// Typed owner for the actual 5BAEE0/5BAF20 task callbacks. It is intentionally
// separate from ScenarioEvents: those callbacks write primary actor flags and
// retire their individual EventTasks record.
class ScenePolicyFlagTasks final {
public:
    ScenePolicyFlagTasks(gameplay_world::World&,FlagState&,gameplay_tasks::EventTasks&);
    ~ScenePolicyFlagTasks();
    ScenePolicyFlagTasks(const ScenePolicyFlagTasks&)=delete;
    ScenePolicyFlagTasks& operator=(const ScenePolicyFlagTasks&)=delete;
    ScenePolicyTaskStatus register_callback(ScenePolicyTaskRegistration);
    ScenePolicyTaskStatus failure()const noexcept;
    ScenePolicyTaskStatus close()noexcept;
private:
    struct Shared;
    std::shared_ptr<Shared> shared_;
};
}
