#pragma once
#include "curves.hpp"
#include "../transform_math/transform_math.hpp"
#include <optional>

namespace reo::native::animation {
using transform_math::Matrix;
using transform_math::Vector;
struct NodeDefinition {
    std::int16_t palette_index{},static_index{};
    std::uint16_t track{};
    std::optional<std::size_t> child,sibling,parent;
    Parameters defaults{};
};
class Skeleton {
public:
    static std::shared_ptr<const Skeleton> import_raw(std::span<const std::byte>,std::size_t root_ordinal=0);
    std::span<const NodeDefinition> nodes()const noexcept{return nodes_;}
    std::span<const std::size_t> traversal()const noexcept{return traversal_;}
private:
    std::vector<NodeDefinition> nodes_;
    std::vector<std::size_t> traversal_;
};
struct NodePose {Parameters parameters{};Caches caches{};Matrix local{},world{};};
struct JointSnapshot {std::vector<Matrix> joints;std::uint64_t revision{};};
// A native mutable model owner, distinct from its canonical actor/object basis.
// Calls are synchronous and serialized by the enclosing native gameplay owner.
class Instance {
public:
    explicit Instance(std::shared_ptr<const Skeleton>);
    const Skeleton& skeleton()const noexcept{return *skeleton_;}
    std::span<const NodePose> nodes()const noexcept{return nodes_;}
    // Bind matches the selected subtree's track IDs in original DFS order.
    // Admission requires one clip track for each matching model node.
    void bind(std::uint16_t track,std::shared_ptr<const Clip>);
    void clear(std::uint16_t track);
    void sample(std::uint16_t track,float frame);
    void sample_all(float frame);
    void root_scale(Vector);
    Vector local_translation(std::size_t node)const;
    Vector world_translation(std::size_t node)const;
    void local_translation(std::size_t node,Vector);
    Vector consume_root_translation();
    Vector translation_difference(std::size_t node,float start,float end);
    // Equivalent to193240/193260, with real local/world node spaces and
    // source scale propagation. No actor basis is copied into persistent state.
    void rebuild(const Matrix& parent);
    std::shared_ptr<const JointSnapshot> retain()const noexcept{return snapshot_;}
private:
    friend class Constraints;
    struct Binding {std::shared_ptr<const Clip> clip;std::size_t track{};};
    std::shared_ptr<const Skeleton> skeleton_;
    std::vector<NodePose> nodes_;
    std::vector<std::optional<Binding>> bindings_;
    Vector previous_root_translation_{};
    std::shared_ptr<const JointSnapshot> snapshot_;
    std::uint64_t revision_{};
    void sample_node(std::size_t,float);
    void publish_snapshot();
    void invalidate()noexcept{snapshot_.reset();}
};
// Complete58BF50 timing policy, advanced by the original caller's game step.
// It deliberately preserves one-wrap/clamp and positive look-ahead quirks.
struct FrameRecord {float frame{},end{},restart{};std::int8_t loop{};std::uint8_t flags{};};
unsigned advance(FrameRecord&,float step);
} // namespace reo::native::animation
