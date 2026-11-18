#include "room_object_commands.hpp"
namespace reo::native::gameplay_scenario {
bool RoomObjectCommands::ready(bool required,bool queries)const noexcept {
    return owner_.initialized()&&(!queries||owner_.grid())&&(!required||(lifetime_&&lifetime_->owns(owner_)&&lifetime_->available()));
}
bool RoomObjectCommands::matches(std::uint8_t index,std::int8_t external)const noexcept{return owner_.mapped_external(index,external);}
bool RoomObjectCommands::presence(std::uint8_t index,bool desired)const noexcept{return owner_.mapped_presence(index,desired);}
bool RoomObjectCommands::move(std::uint8_t external,std::uint8_t x,std::uint8_t z)noexcept {
    if(!ready(true))return false;
    try{return lifetime_->move_external(external,x,z)==gameplay_collision::room_objects::InstanceStatus::complete;}catch(const std::exception&){return false;}
}
void RoomObjectCommands::flags(std::uint8_t external,std::uint32_t set,std::uint32_t clear)noexcept{(void)owner_.change_external_flags(external,set,clear);}
}
