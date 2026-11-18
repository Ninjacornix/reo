#pragma once
#include "update.hpp"
#include "../gameplay_world/dialogue_responses.hpp"
#include "../gameplay_world/inventory_ui.hpp"
namespace reo::native::gameplay_update {
// Exact6B7E40 adoption at Worker::sequences. The remaining phase services,
// global menu producer and canonical inventory/resource owners stay borrowed.
class DialogueWorkers final:public PhaseServices {
public:
    DialogueWorkers(Owner&,PhaseServices&,world::DialoguePool&,const world::InventoryUi&,
        const world::input::Frame*,const std::optional<std::uint32_t>& menu_actions,
        const scenario::SceneResources* =nullptr,const scenario::ResourceTemplates* =nullptr);
    ~DialogueWorkers();
    DialogueWorkers(const DialogueWorkers&)=delete;
    DialogueWorkers& operator=(const DialogueWorkers&)=delete;
    void run(Worker,Owner&)override;
    bool button(Button,Owner&)override;
    bool transition_request(Owner&)override;
    void effect(PhaseEffect,Owner&,std::uint32_t=0)override;
    Status close()noexcept;
    const std::optional<world::DialogueResponsesUpdated>& last_result()const noexcept{return last_;}
private:
    Owner& owner_;
    PhaseServices& remaining_;
    world::DialoguePool& pool_;
    const world::InventoryUi& inventory_;
    const world::input::Frame* menu_;
    const std::optional<std::uint32_t>& menu_actions_;
    const scenario::SceneResources* resources_;
    const scenario::ResourceTemplates* templates_;
    std::optional<world::DialogueResponsesUpdated> last_;
    bool running_{},closed_{};
    void verify(Owner&)const;
};
}
