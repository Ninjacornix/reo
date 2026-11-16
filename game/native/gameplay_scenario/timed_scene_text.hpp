#pragma once
#include "scene_text_bank.hpp"
#include "text_cache.hpp"
#include "../gameplay_tasks/tasks.hpp"
#include "../gameplay_world/inventory_ui.hpp"
#include "../gameplay_session/application_lifecycle.hpp"
#include <memory>
namespace reo::native::gameplay_scenario {
enum class TimedTextStatus {completed,busy,closed,unavailable,no_memory};
struct TimedTextSnapshot {
    std::optional<std::uint8_t> active;
    std::optional<std::uint8_t> priority;
    std::size_t tasks{};
    TimedTextStatus callback_status{TimedTextStatus::completed};
};
struct TimedTextRequest {
    std::uint16_t id{};std::int16_t duration{60},delay{};std::uint8_t priority{1};
    std::uint32_t text_kind{}; //570080 uses2; existing132/default requests use0.
};
// Complete692BE0/570080/570120/570140 +6B6880 use the actual message banks,
// text queue, inventory gates and linked Scheduler. No implicit task pass.
class TimedSceneText final {
    struct Shared;
public:
    TimedSceneText(gameplay_world::World&,SceneTextBank&,gameplay_tasks::Scheduler&,
        TextCache&,const gameplay_world::InventoryUi&,
        const gameplay_session::ApplicationLifecycle&);
    ~TimedSceneText();
    TimedSceneText(const TimedSceneText&)=delete;
    TimedSceneText& operator=(const TimedSceneText&)=delete;
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool ready(std::uint16_t id)const noexcept;
    TimedTextStatus request(std::uint16_t id)noexcept;
    TimedTextStatus request(TimedTextRequest)noexcept;
    // Complete5A52C0 and5A5060 ->5A5090/5A52C0. These immediate cache
    // consumers draw no invented answer/input and create no Scheduler task.
    TimedTextStatus show_yes_no(std::uint32_t duration)noexcept;
    TimedTextStatus show_choice_prompt(std::uint32_t message,std::uint32_t duration)noexcept;
    bool busy()const noexcept;
    TimedTextSnapshot snapshot()const noexcept;
    TimedTextStatus close()noexcept;
private:
    std::shared_ptr<Shared> state_;
};
}
