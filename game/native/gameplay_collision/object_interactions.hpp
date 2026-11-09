#pragma once
#include "room_geometry.hpp"
namespace reo::native::gameplay_collision::room_objects {
struct Parameters {std::int8_t request_threshold{},parameter4{};std::uint8_t parameter5{};};
// All mutations target the existing canonical32-record owner. Checked mutable
// access stays private; authored physical ordinals do not encode EntityIds.
class InteractionOwner final {
public:
    class Lifetime;
    explicit InteractionOwner(Owner& owner)noexcept:owner_(owner){}
    std::optional<ObjectId> masked(std::uint8_t source_slot)const noexcept;
    std::optional<std::uint8_t> source_ordinal(const ObjectId&)const noexcept;
    void increment(const ObjectId&)noexcept;
    void decrement(const ObjectId&)noexcept;
    bool below_capacity(const ObjectId&)const noexcept;
    // Equality is checked on full authored signed-byte selectors before masking;
    // aliases such as33and1 must not collapse to identical native IDs first.
    void transfer(std::int8_t old_source,std::int8_t next_source)noexcept;
    bool claim_secondary(const ObjectId&,std::uint16_t heading,bool input_gate)noexcept;
    void request_primary(const ObjectId&,std::uint16_t heading)noexcept;
    void clear_secondary(const ObjectId&)noexcept;
    void decay(const ObjectId&)noexcept;
    Parameters parameters(std::uint8_t source_slot)const noexcept;
    static std::uint8_t direction(std::uint16_t heading)noexcept;
private:
    Owner& owner_;
    Object* edit(const ObjectId& id)noexcept{return owner_.mutable_object(id);}
};
}
