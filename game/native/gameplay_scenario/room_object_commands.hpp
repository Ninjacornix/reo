#pragma once
#include "../gameplay_collision/object_lifetime.hpp"
namespace reo::native::gameplay_scenario {
// Borrowed canonical native scene owners. No object/grid/instance mirror is held.
// The scene owners outlive this simulation-thread-only facade.
class RoomObjectCommands final {
public:
    explicit RoomObjectCommands(gameplay_collision::room_objects::Owner& owner)noexcept:owner_(owner){}
    RoomObjectCommands(gameplay_collision::room_objects::Owner& owner,gameplay_collision::room_objects::InteractionOwner::Lifetime& lifetime)noexcept:owner_(owner),lifetime_(&lifetime){}
    bool ready(bool require_lifetime,bool require_queries=false)const noexcept;
    bool matches(std::uint8_t index,std::int8_t external)const noexcept;
    bool presence(std::uint8_t index,bool desired)const noexcept;
    bool move(std::uint8_t external,std::uint8_t x,std::uint8_t z)noexcept;
    void flags(std::uint8_t external,std::uint32_t set,std::uint32_t clear)noexcept;
private:
    gameplay_collision::room_objects::Owner& owner_;
    gameplay_collision::room_objects::InteractionOwner::Lifetime* lifetime_{};
};
}
