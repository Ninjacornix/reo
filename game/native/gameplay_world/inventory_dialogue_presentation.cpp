#include "inventory_dialogue_presentation.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
InventoryDialoguePresentation::InventoryDialoguePresentation(World& world,gameplay_scenario::TextCache& cache,const InventoryUi& inventory):world_(world),cache_(cache),inventory_(inventory){
    if(!inventory_.bound_to(world_))throw std::invalid_argument("Native dialogue inventory UI belongs to another world or is closed");
}
bool InventoryDialoguePresentation::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed()&&inventory_.bound_to(world_);}
bool InventoryDialoguePresentation::erase(std::span<const std::byte> text)noexcept{return bound_to(world_)&&cache_.erase(text)==gameplay_scenario::TextCacheStatus::completed;}
std::optional<bool> InventoryDialoguePresentation::suppressed()noexcept{
    if(!bound_to(world_))return{};
    const auto& state=inventory_.snapshot();if(!state)return{};
    return dialogue_suppressed({state->update_enabled,state->phase},world_.session().inventory_owner);
}
bool InventoryDialoguePresentation::draw(std::int16_t x,std::uint16_t y,std::span<const std::byte> text,std::uint8_t alpha)noexcept{return bound_to(world_)&&cache_.dialogue(x,y,text,alpha).status==gameplay_scenario::TextCacheStatus::completed;}
}
