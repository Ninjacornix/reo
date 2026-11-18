#pragma once
#include "cached_dialogue_presentation.hpp"
#include "inventory_ui.hpp"
namespace reo::native::gameplay_world {
// Dialogue borrows the application's sole inventory UI lifecycle and text
// cache. The6DEC80-produced visibility fields are read live, never copied into
// a second mutable UI owner.
class InventoryDialoguePresentation final:public DialoguePresentation {
public:
    InventoryDialoguePresentation(World&,gameplay_scenario::TextCache&,const InventoryUi&);
    bool bound_to(const World&)const noexcept override;
    bool erase(std::span<const std::byte>)noexcept override;
    std::optional<bool> suppressed()noexcept override;
    bool draw(std::int16_t,std::uint16_t,std::span<const std::byte>,std::uint8_t)noexcept override;
private:
    World& world_;
    gameplay_scenario::TextCache& cache_;
    const InventoryUi& inventory_;
};
}
