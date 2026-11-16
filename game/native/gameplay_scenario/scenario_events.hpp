#pragma once
#include "timer_hud.hpp"
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_tasks {class EventTasks;class FlagTimers;}
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_effects {class WorkBackend;}
namespace reo::native::gameplay_scenario {
class FlagState;
enum class ScenarioEventStatus {completed,closed,invalid_payload,unavailable_owner,no_memory,busy};
struct ScenarioEventState {
    std::uint8_t bank{},slot{},kind{},owner_selector{},render_style{},phase{};
    TimerHudPulse pulse;
    std::array<std::uint32_t,5> arguments{};
    std::optional<std::uint16_t> scenario; // D0 captures the selected scenario callback family.
};
struct ScenarioEventPresented {
    ScenarioEventStatus status{ScenarioEventStatus::completed};
    std::optional<TimerHudFrame> frame;
};
// Canonical5B92B0/D0/D1 factories over Update's three-by-ten EventTasks.
class ScenarioEvents final {
public:
    ~ScenarioEvents();
    ScenarioEvents(const ScenarioEvents&)=delete;
    ScenarioEvents& operator=(const ScenarioEvents&)=delete;
    static bool admits(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>&)noexcept;
    static bool admits_scenario(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>&)noexcept;
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool ready()const noexcept;
    ScenarioEventStatus command(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>&);
    bool scenario_ready(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>&)const noexcept;
    ScenarioEventStatus scenario_command(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>&);
    // Borrow the sole retained work owner; tasks must retire before replacement.
    ScenarioEventStatus bind_effect_work(gameplay_effects::WorkBackend*)noexcept;
    std::optional<ScenarioEventState> inspect(std::uint8_t bank,std::uint8_t slot)const noexcept;
    // Actual registered5BA530 CPU presentation policy; GPU texture submission
    // consumes the returned typed frame at the Stage5 boundary.
    ScenarioEventPresented present_timer_hud()noexcept;
    ScenarioEventStatus failure()const noexcept;
    ScenarioEventStatus close()noexcept;
private:
    struct Shared;
    struct Task;
    std::shared_ptr<Shared> state_;
    ScenarioEvents(gameplay_world::World&,FlagState&,gameplay_tasks::FlagTimers&,gameplay_tasks::EventTasks&);
    friend class gameplay_update::Owner;
};
}
