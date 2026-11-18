#pragma once
#include "game/native/gameplay_scenario/scene_text_bank.hpp"
#include "game/native/gameplay_scenario/text_cache.hpp"
#include "game/native/gameplay_tasks/tasks.hpp"
#include "game/native/gameplay_world/inventory_ui.hpp"
#include "application_lifecycle.hpp"
#include <memory>
namespace reo::native::gameplay_scenario {
enum class TimedTextStatus {completed,busy,closed,unavailable,no_memory};
struct TimedTextSnapshot {
    bool active{};
    std::optional<std::uint8_t> priority;
    std::size_t tasks{};
    TimedTextStatus callback_status{TimedTextStatus::completed};
};
// Complete692BE0/570120/570140 +6B6880 use the application's actual front SPK,
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
    TimedTextSnapshot snapshot()const noexcept;
    TimedTextStatus close()noexcept;
private:
    std::shared_ptr<Shared> state_;
};
}
