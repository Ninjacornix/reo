#pragma once
#include "resource_flight.hpp"
#include "../gameplay_contact_world/contacts.hpp"
namespace reo::native::gameplay_effects {
// One retained current room invocation covers both original segment queries.
// Query failures preserve the earlier physics prefix and cannot become misses.
class RoomFlightQueries final:public FlightQueries {
public:
    explicit RoomFlightQueries(std::shared_ptr<gameplay_contact_world::RoomInvocation>);
    FlightTrace wall(transform_math::Vector,transform_math::Vector)override;
    FlightTrace floor(transform_math::Vector,transform_math::Vector)override;
private:
    std::shared_ptr<gameplay_contact_world::RoomInvocation> room_;
    gameplay_contact_world::RoomId id_;
    bool current()const noexcept;
};
class CurrentRoomFlightQueries final:public FlightQueries {
public:
    CurrentRoomFlightQueries(gameplay_world::World&,gameplay_contact_world::RoomResources&);
    FlightTrace wall(transform_math::Vector,transform_math::Vector)override;
    FlightTrace floor(transform_math::Vector,transform_math::Vector)override;
private:
    gameplay_world::World& world_;gameplay_contact_world::RoomResources& rooms_;
    std::optional<std::uint16_t> room_number_;
    std::unique_ptr<RoomFlightQueries> queries_;
    bool prepare();
};
}
