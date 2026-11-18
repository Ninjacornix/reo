#pragma once
#include "postmove_view.hpp"
namespace reo::native::gameplay_collision::actors {
struct View {
    EntityId id;
    postmove::VectorRef position, previous, candidate_direction;
    std::span<const Basis> joints;
    const std::optional<ShapeDefinition>& definition;
    const std::uint8_t& actor_class;
    const std::uint8_t& priority;
    std::uint8_t& separation_count;
    postmove::FlagRef contact;
    EntityId& peer;
    const std::uint16_t& room;
    Summary& summary;
    postmove::FlagRef boundary_clamped;
};
View references(Actor&) noexcept;
Shape build(const View&, const ShapeDefinition&, Vec3 accumulated = {});
// Caller admits live, identity-qualified views and keeps their native owner/
// model-pose leases for this synchronous call. No actor/pose ref is retained.
class ViewRegistry {
  public:
    bool add(Registration);
    void clear() noexcept {
        for (std::size_t i = 0; i < count_; ++i)
            entries_[i] = {};
        count_ = 0;
    }
    std::size_t size() const noexcept {
        return count_;
    }
    SolveReport solve(std::span<View>, bool limit_repeated = false, bool fast_tick = false);

  private:
    std::array<Registration, 32> entries_{};
    std::size_t count_{};
};
class ViewBoundary {
  public:
    bool set(std::uint8_t kind, EntityId) noexcept;
    void clear() noexcept {
        owner_ = {};
    }
    void apply(std::span<View>, bool offline, std::uint16_t room, EntityId selected) const noexcept;

  private:
    EntityId owner_;
};
} // namespace reo::native::gameplay_collision::actors
