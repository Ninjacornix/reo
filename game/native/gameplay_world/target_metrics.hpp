#pragma once
#include "../gameplay_collision/trace.hpp"
#include "../gameplay_actors/entity.hpp"
#include <array>
#include <memory>
namespace reo::native::gameplay_world {
class World;
struct Actor;
struct TargetPairMetric {float distance{};std::uint16_t bearing{};};
struct TargetLinkedMetric {TargetPairMetric pair;std::uint8_t wall{},floor{};};
struct TargetMetricState {
    std::array<gameplay_actors::EntityId,8> primary_identity;
    std::array<gameplay_actors::EntityId,10> auxiliary_identity;
    std::array<gameplay_actors::EntityId,50> linked_identity;
    // The primary-to-auxiliary list uses compact active-source rows. Metric
    // cells still use physical primary slots, and inverse entries store them.
    std::array<gameplay_actors::EntityId,8> primary_auxiliary_sources;
    std::array<std::array<std::optional<TargetPairMetric>,8>,8> primary_pairs;
    std::array<std::array<std::optional<TargetLinkedMetric>,50>,8> primary_linked;
    std::array<std::array<std::optional<TargetLinkedMetric>,50>,10> auxiliary_linked;
    // This source bank writes a known-zero wall byte but leaves its floor byte
    // untouched. Only its meaningful distance/bearing are native state here.
    std::array<std::array<std::optional<TargetPairMetric>,10>,8> primary_auxiliary;
    std::array<std::array<std::uint8_t,50>,8> primary_linked_order;
    std::array<std::array<std::uint8_t,8>,50> reverse_primary_order;
    std::array<std::array<std::uint8_t,50>,10> auxiliary_linked_order;
    std::array<std::array<std::uint8_t,10>,50> reverse_auxiliary_order;
    std::array<std::array<std::uint8_t,10>,8> primary_auxiliary_order;
    std::array<std::array<std::uint8_t,8>,10> auxiliary_primary_order;
};
struct TargetMetricRoom {
    const gameplay_collision::response::Grid& walls;
    const gameplay_collision::response::Grid& floors;
    gameplay_collision::response::Filter filter;
    std::span<const gameplay_collision::response::Triangle> dynamic;
};
enum class TargetMetricStatus {completed,unavailable,closed};
struct TargetMetricReport {
    TargetMetricStatus status{TargetMetricStatus::unavailable};
    std::size_t pairs{},wall_queries{},floor_queries{},sorts{},comparisons{},swaps{};
    // Deliberate correction of unwritten original distance scratch. It is a
    // native algorithm policy, not a claim to preserve arbitrary stack history.
    bool initialized_work{true};
};
class TargetMetricCache final {
public:
    TargetMetricCache(const TargetMetricCache&)=delete;
    TargetMetricCache& operator=(const TargetMetricCache&)=delete;
    TargetMetricReport rebuild(const TargetMetricRoom&)noexcept;
    const TargetMetricState* state()const noexcept;
private:
    friend class World;
    explicit TargetMetricCache(World& world)noexcept:world_(world){}
    void close()noexcept{ready_=false;closed_=true;}
    World& world_;
    TargetMetricState state_{};
    bool ready_{},closed_{};
};
}
