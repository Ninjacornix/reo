#include "packet_service.hpp"
#include <bit>
namespace reo::native::gameplay_collision::delivery {
std::optional<View> PacketActors::find(const actors::EntityId& id) {
    const auto found = owner(id);
    if (!found)
        return {};
    return found->contact;
}
namespace {
void decrement(std::uint8_t& value, std::uint8_t mode) {
    value = std::uint8_t(value - (mode ? 2 : 1));
    if (value == 255)
        value = 0;
}
bool add_route(PacketState& packet, PacketOwner owner, EdgeRoute route, PacketActors& actors,
               gameplay_actors::HitSession& session, PacketEvents& events) {
    if (!route.kind || route.kind > 2 || route.index >= 32)
        return false;
    bool local{};
    auto& actor = owner.contact.actor;
    if (actor.category == 0) {
        if (actor.slot != session.selected_actor)
            return true;
        local = true;
    } else if (actor.category == 9) {
        if (!packet.delivery.cached_related)
            return true;
        auto related = actors.owner(packet.delivery.cached_related);
        if (!related)
            return false;
        if (related->contact.actor.category == 0) {
            if (related->contact.actor.slot != session.selected_actor)
                return true;
            local = true;
        } else if (!events.selected_authority(session.selected_actor))
            return true;
    } else if (!events.selected_authority(session.selected_actor))
        return true;
    bool reduced{};
    if (route.index < 16) {
        const auto mask = events.room_mask(session.room);
        if (!mask)
            return false;
        reduced = (*mask & (std::uint16_t(1u << route.index))) != 0;
    }
    auto* pending = events.pending(route.index);
    if (!pending)
        return false;
    const auto amount = packet.delivery.response.route_amount;
    if (reduced) {
        const float scaled = float(std::uint16_t(amount)) / (local ? 2.0f : 5.0f);
        const auto result = std::int32_t(float(*pending) + scaled);
        *pending = std::bit_cast<std::int16_t>(std::uint16_t(result));
    } else
        *pending = std::bit_cast<std::int16_t>(
            std::uint16_t(std::int32_t(*pending) + std::int32_t(amount)));
    return true;
}
} // namespace
ServiceReport service(Packets& packets, PacketActors& actors, gameplay_actors::HitSession& session,
                      hit_regions::Queue& targets, PacketShapes& shapes, PacketEvents& events) {
    ServiceReport report;
    if (packets.closed()) {
        report.status = ServiceStatus::closed;
        return report;
    }
    auto id = packets.tail();
    while (id) {
        auto lease = packets.acquire(id);
        if (!lease) {
            report.status = ServiceStatus::stale_packet;
            return report;
        }
        ++report.visited;
        auto& packet = lease.state();
        auto owner = actors.owner(packet.delivery.source);
        const auto retire = [&] {
            const auto prior = lease.previous();
            packets.release(id);
            ++report.released;
            id = prior;
        };
        if (!owner || !owner->active || (owner->contact.actor.notice_flags & 1)) {
            retire();
            continue;
        }
        if ((owner->contact.actor.notice_flags & 2) || !packet.enabled) {
            packet.previous_valid = 0;
            ++report.paused;
            id = lease.previous();
            continue;
        }
        if (packet.startup) {
            decrement(packet.startup, session.clock_mode);
            packet.previous_valid = 0;
            ++report.paused;
            id = lease.previous();
            continue;
        }
        if (!packet.lifetime) {
            retire();
            continue;
        }
        if (packet.lifetime != 255)
            decrement(packet.lifetime, session.clock_mode);
        if (packet.cooldown) {
            decrement(packet.cooldown, session.clock_mode);
            packet.previous_valid = 0;
            ++report.paused;
            id = lease.previous();
            continue;
        }
        packet.delivery.event = 0;
        if (!packet.definition ||
            std::holds_alternative<std::monostate>(packet.definition->geometry)) {
            retire();
            continue;
        }
        ++report.queries;
        const auto result = shapes.query(packet, *owner);
        if (result.status != Status::completed) {
            report.status = ServiceStatus::query_failed;
            report.detail = result.status;
            return report;
        }
        if (packets.closed()) {
            report.status = ServiceStatus::closed;
            return report;
        }
        if (packet.delivery.event) {
            const auto restored = restore_provenance(packet.delivery, actors);
            if (restored != Status::completed) {
                report.status = ServiceStatus::missing_actor;
                report.detail = restored;
                return report;
            }
        }
        if (result.contact) {
            ++report.contacts;
            if (packet.delivery.event == 1)
                events.sound(*owner, packet.delivery.response.scene_sound);
            if (result.route) {
                if (!add_route(packet, *owner, *result.route, actors, session, events)) {
                    report.status = ServiceStatus::unadmitted_route;
                    return report;
                }
            } else if (!packet.delivery.event && events.audio_admitted(*owner))
                events.sound(*owner, packet.delivery.response.actor_sound);
            if (packet.contacts > packet.delivery.response.max_contacts) {
                retire();
                continue;
            }
            packet.cooldown = packet.delivery.response.cooldown;
        }
        id = lease.previous();
    }
    report.detail = events.finish_routes();
    if (report.detail != Status::completed) {
        report.status = ServiceStatus::query_failed;
        return report;
    }
    targets.clear();
    return report;
}
} // namespace reo::native::gameplay_collision::delivery
