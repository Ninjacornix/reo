#include "contact_routes.hpp"
namespace reo::native::gameplay_collision::delivery {
namespace {
bool closed(std::uint16_t mask, std::uint32_t edge) {
    return (std::uint32_t(mask) & (1u << (edge & 31))) != 0;
}
} // namespace
RouteReport consume_routes(std::span<const std::int16_t, 32> pending,
                           const std::uint16_t& current_room, RouteServices& services) {
    RouteReport report;
    std::array<RouteEntry, 10> batch;
    for (std::uint8_t edge = 0; edge < 24; ++edge) {
        ++report.visited;
        const auto amount = pending[edge];
        if (amount < 1)
            continue;
        auto mask = services.closed_edges(current_room);
        if (!mask) {
            report.status = RouteStatus::unadmitted_room;
            return report;
        }
        if (!closed(*mask, edge)) {
            if (!services.apply(std::uint8_t(current_room), edge, amount)) {
                report.status = RouteStatus::provider_failed;
                return report;
            }
            ++report.applied;
            mask = services.closed_edges(current_room);
            if (!mask) {
                report.status = RouteStatus::unadmitted_room;
                return report;
            }
            if (!closed(*mask, edge)) {
                batch[report.batched++] = {std::uint8_t(current_room), edge, amount};
                if (report.batched == batch.size())
                    break;
            } else {
                if (!services.finish(current_room, edge, 2)) {
                    report.status = RouteStatus::provider_failed;
                    return report;
                }
                ++report.finished;
            }
        }
        if (edge >= 16)
            continue;
        const auto lookup = services.related(edge);
        if (!lookup.admitted) {
            report.status = RouteStatus::unavailable_owner;
            return report;
        }
        const auto& target = lookup.target;
        if (!target || target->type())
            continue;
        auto destination = target->destination();
        if (!destination) {
            report.status = RouteStatus::unavailable_owner;
            return report;
        }
        mask = services.closed_edges(destination->room);
        if (!mask) {
            report.status = RouteStatus::unadmitted_room;
            return report;
        }
        if (closed(*mask, destination->edge))
            continue;
        if (!services.apply(std::uint8_t(destination->room), std::uint8_t(destination->edge),
                            amount)) {
            report.status = RouteStatus::provider_failed;
            return report;
        }
        ++report.applied;
        destination = target->destination();
        if (!destination) {
            report.status = RouteStatus::unavailable_owner;
            return report;
        }
        mask = services.closed_edges(destination->room);
        if (!mask) {
            report.status = RouteStatus::unadmitted_room;
            return report;
        }
        if (!closed(*mask, destination->edge)) {
            batch[report.batched++] = {std::uint8_t(destination->room),
                                       std::uint8_t(destination->edge), amount};
            if (report.batched == batch.size())
                break;
        } else {
            if (!services.finish(destination->room, destination->edge, 2)) {
                report.status = RouteStatus::provider_failed;
                return report;
            }
            ++report.finished;
        }
    }
    if (report.batched && services.send_authority() == 1) {
        if (!services.send({batch.data(), report.batched})) {
            report.status = RouteStatus::provider_failed;
            return report;
        }
        report.sent = true;
    }
    return report;
}
} // namespace reo::native::gameplay_collision::delivery
