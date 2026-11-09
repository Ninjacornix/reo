#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
namespace reo::native::gameplay_collision::delivery {
struct RouteEntry {
    std::uint8_t room{}, edge{};
    std::int16_t amount{};
    friend bool operator==(const RouteEntry&, const RouteEntry&) = default;
};
struct RouteDestination {
    std::uint32_t room{}, edge{};
};
class RouteTarget {
  public:
    virtual ~RouteTarget() = default;
    virtual std::uint8_t type() const noexcept = 0;
    // Requery the selected native identity, including stale-ID admission.
    virtual std::optional<RouteDestination> destination() const = 0;
};
struct RouteLookup {
    bool admitted{};
    std::shared_ptr<const RouteTarget> target;
};
class RouteServices {
  public:
    virtual ~RouteServices() = default;
    // +3A4 closure mask differs from +3A6 contact-amount reduction.
    // The original indexes the full room field before narrowing its call args.
    virtual std::optional<std::uint16_t> closed_edges(std::uint32_t room) = 0;
    virtual bool apply(std::uint8_t room, std::uint8_t edge, std::int32_t amount) = 0;
    virtual bool finish(std::uint32_t room, std::uint32_t edge, std::uint8_t kind) = 0;
    // Exact first type0/2 matching control, independent of its enabled byte.
    // Result retains the selected native identity, not a copied destination.
    // destination() is called again after apply(), as the original does.
    virtual RouteLookup related(std::uint8_t edge) = 0;
    virtual std::int32_t send_authority() = 0;
    // Native typed equivalent of the header4/type30 batch on channel5.
    // Implementations copy the entries if delivery outlives this call.
    virtual bool send(std::span<const RouteEntry>) = 0;
};
enum class RouteStatus { completed, unadmitted_room, unavailable_owner, provider_failed };
struct RouteReport {
    RouteStatus status{RouteStatus::completed};
    std::uint8_t visited{}, applied{}, finished{}, batched{};
    bool sent{};
};
// Reads exactly original indices0..23, preserves pending values, and stops
// immediately when its ten-entry batch fills. Session room is canonical and
// may change synchronously during an apply callback; no room copy is retained.
RouteReport consume_routes(std::span<const std::int16_t, 32> pending,
                           const std::uint16_t& current_room, RouteServices&);
} // namespace reo::native::gameplay_collision::delivery
