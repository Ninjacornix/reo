#pragma once
#include "contact_packets.hpp"
namespace reo::native::gameplay_collision::delivery {
struct PacketOwner {
    View contact;
    bool active{};
};
class PacketActors : public Actors {
  public:
    virtual std::optional<PacketOwner> owner(const actors::EntityId&) = 0;
    std::optional<View> find(const actors::EntityId&) final;
};
struct EdgeRoute {
    std::uint8_t kind{}, index{};
};
struct ShapeResult {
    Status status{Status::completed};
    bool contact{};
    std::optional<EdgeRoute> route;
};
class PacketShapes {
  public:
    virtual ~PacketShapes() = default;
    virtual ShapeResult query(PacketState&, PacketOwner) = 0;
};
class PacketEvents {
  public:
    virtual ~PacketEvents() = default;
    virtual bool audio_admitted(PacketOwner) = 0;
    virtual void sound(PacketOwner, std::uint8_t cue) = 0;
    virtual std::int32_t selected_authority(std::uint8_t selected_actor) = 0;
    virtual std::optional<std::uint16_t> room_mask(std::uint16_t room) = 0;
    // Borrowed canonical route-owner field, valid for this synchronous call.
    virtual std::int16_t* pending(std::uint8_t edge) = 0;
    // Required native680B40 consumer; no default or original-function fallback.
    virtual Status finish_routes() = 0;
};
enum class ServiceStatus {
    completed,
    closed,
    stale_packet,
    missing_actor,
    query_failed,
    unadmitted_route
};
struct ServiceReport {
    ServiceStatus status{ServiceStatus::completed};
    Status detail{Status::completed};
    std::uint32_t visited{}, released{}, paused{}, queries{}, contacts{};
};
// Uses the existing canonical selected actor, room and original clock mode;
// no independent timer, host delta or shadow session is introduced. New head
// packets created by a synchronous provider can be visited in this same pass.
ServiceReport service(Packets&, PacketActors&, gameplay_actors::HitSession&, hit_regions::Queue&,
                      PacketShapes&, PacketEvents&);
} // namespace reo::native::gameplay_collision::delivery
