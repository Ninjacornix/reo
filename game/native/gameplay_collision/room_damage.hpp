#pragma once
#include <array>
#include <cstdint>
#include <optional>
#include <span>
namespace reo::native::gameplay_collision::delivery {
// Original initialization proves128 room rows, each24 signed halfwords.
// Native callers must use checked indices instead of aliasing adjacent owners.
class RoomCounters {
  public:
    static constexpr std::size_t rooms = 128, edges = 24;
    void reset(std::int16_t policy) noexcept;
    std::optional<std::int16_t> get(std::uint32_t room, std::uint32_t edge) const noexcept;
    bool set(std::uint32_t room, std::uint32_t edge, std::int16_t value) noexcept;
    const auto& snapshot() const noexcept {
        return values_;
    }

  private:
    std::array<std::array<std::int16_t, edges>, rooms> values_{};
};
class RouteFlags {
  public:
    virtual ~RouteFlags() = default;
    virtual std::optional<std::uint16_t> half(std::uint32_t room,
                                              std::uint32_t slot) const noexcept = 0;
    virtual bool bit(std::uint32_t room, std::uint32_t edge, std::uint8_t slot,
                     bool set) noexcept = 0;
};
// Instantiate with the actual canonical scenario FlagState. This binding adds
// no storage and uses the same checked array and existing bit-write operations.
template <class CanonicalFlags> class RouteFlagBinding final : public RouteFlags {
    CanonicalFlags& flags_;

  public:
    explicit RouteFlagBinding(CanonicalFlags& flags) : flags_(flags) {}
    std::optional<std::uint16_t> half(std::uint32_t room,
                                      std::uint32_t slot) const noexcept override {
        return flags_.strided_half(room, slot);
    }
    bool bit(std::uint32_t room, std::uint32_t edge, std::uint8_t slot,
             bool set) noexcept override {
        return flags_.strided(room, edge, slot, set, false);
    }
};
struct RouteChannel {
    std::uint8_t gate{}, active{};
};
struct ChannelView {
    std::uint8_t& gate;
    std::uint8_t& active;
};
struct RoomContacts {
    RoomCounters counters;
    std::array<std::int16_t, 24> pending{};
    std::int16_t* pending_amount(std::uint32_t edge) noexcept {
        return edge < pending.size() ? &pending[edge] : nullptr;
    }
};
class RouteDamageEffects {
  public:
    virtual ~RouteDamageEffects() = default;
    virtual bool refresh_channel(std::uint8_t edge) = 0;
    virtual bool notify(std::uint32_t room, std::uint32_t edge, std::uint8_t value,
                        std::uint8_t kind) = 0;
};
enum class DamageStatus {
    completed,
    unadmitted_counter,
    unadmitted_flags,
    unavailable_channel,
    provider_failed
};
struct DamageReport {
    DamageStatus status{DamageStatus::completed};
    bool refreshed{};
};
// Provider owns these channel bytes together with the native matrix program.
// The original sets active before examining flags; no independent flag copy.
class RouteChannels {
  public:
    virtual ~RouteChannels() = default;
    virtual std::optional<ChannelView> channel(std::uint8_t edge) = 0;
};
DamageReport apply_route_damage(RoomCounters&, RouteFlags&, RouteChannels&, RouteDamageEffects&,
                                const std::uint16_t& current_room, std::uint8_t room,
                                std::uint8_t edge, std::int32_t amount);
DamageStatus finish_route(RouteFlags&, RouteDamageEffects&, std::uint32_t room, std::uint32_t edge,
                          std::uint8_t kind);
} // namespace reo::native::gameplay_collision::delivery
