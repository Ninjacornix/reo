#include "inventory_presence.hpp"
namespace reo::native::gameplay_world {
bool InventoryPresence::activate()noexcept{
    if(world_.closed())return false;
    peers_.fill(std::nullopt);active_=true;return true;
}
void InventoryPresence::close()noexcept{active_=false;peers_.fill(std::nullopt);}
std::optional<InventoryPeerPresence> InventoryPresence::peer(std::uint32_t index)const noexcept{return active()&&index<peers_.size()?peers_[index]:std::nullopt;}
PresenceStatus InventoryPresence::refresh(std::uint32_t index)noexcept{
    if(world_.closed())return PresenceStatus::unavailable;
    if(index==world_.selected_actor||!active_)return PresenceStatus::completed;
    if(index>=peers_.size())return PresenceStatus::unavailable;
    const auto actor=world_.primary(index);if(!actor)return PresenceStatus::unavailable;
    peers_[index]=InventoryPeerPresence{std::uint8_t(actor->room),actor->position,90};
    return PresenceStatus::completed;
}
}
