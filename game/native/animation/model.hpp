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
enum class SkeletonExtent {declared,bounded_records};
class Skeleton {
public:
    // File1 NPC records can have stale redundant length metadata. The explicit
    // record profile walks the count in the bounded section, never pads data.
    static std::shared_ptr<const Skeleton> import_raw(std::span<const std::byte>,std::size_t root_ordinal=0,SkeletonExtent=SkeletonExtent::declared);
    std::span<const NodeDefinition> nodes()const noexcept{return nodes_;}
    std::span<const std::size_t> traversal()const noexcept{return traversal_;}
private:
    std::vector<NodeDefinition> nodes_;
    std::vector<std::size_t> traversal_;
};
struct NodePose {Parameters parameters{};Caches caches{};Matrix local{},world{};};
struct JointSnapshot {std::vector<Matrix> joints;std::uint64_t revision{};};
struct NodeLinks {
    std::optional<std::size_t> parent,child,sibling;
    friend bool operator==(const NodeLinks&,const NodeLinks&)=default;
};
enum class NodeLink {parent,child,sibling};
struct NodeLinkPatch {std::size_t node{};NodeLink link{};std::optional<std::size_t> target;};
struct JointPosePatch {std::size_t node{};Matrix world;};
struct LocalPosePatch {std::size_t node{};Matrix local;};
// A native mutable model owner, distinct from its canonical actor/object basis.
// Calls are synchronous and serialized by the enclosing native gameplay owner.
class Instance {
public:
    explicit Instance(std::shared_ptr<const Skeleton>);
    const Skeleton& skeleton()const noexcept{return *skeleton_;}
    std::span<const NodePose> nodes()const noexcept{return nodes_;}
    std::span<const NodeLinks> links()const noexcept{return links_;}
    std::span<const std::size_t> traversal()const noexcept{return traversal_;}
    // Atomic typed topology replacement. Disconnected owned branches remain
    // alive; invalid indices, cycles and shared child/sibling paths refuse.
    // Detached branches retain their original parent metadata. Reachable
    // parent links must agree with the child/sibling walk used by the source.
    void patch_links(std::span<const NodeLinkPatch>);
    void patch_links_preserving_world(std::span<const NodeLinkPatch>);
    std::span<const std::uint16_t> track_ids()const noexcept{return track_ids_;}
    // Runtime node routing is instance-owned. Temporary cinematic relabels
    // never mutate the shared authored Skeleton or another model bank.
    void relabel_prefix(std::size_t count,std::uint16_t track);
    void relabel_prefix(std::span<const std::uint16_t> tracks);
    // Bind matches the selected subtree's track IDs in original DFS order.
    // Admission requires one clip track for each matching model node.
    void bind(std::uint16_t track,std::shared_ptr<const Clip>);
    //192BF0 consumes one clip track per matching node and ignores a retained
    // trailing clip suffix. Fewer clip tracks remain unavailable. Exact bind
    // above stays the admission contract for existing actor channel callers.
    void bind_prefix(std::uint16_t track,std::shared_ptr<const Clip>);
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
    // Secondary pose consumers alter published joints without rebuilding the
    // sampled local pose. Validate and prepare a new immutable snapshot before
    // replacing world matrices; retained snapshots remain independent.
    void patch_world_poses(std::span<const JointPosePatch>);
    void patch_local_poses(std::span<const LocalPosePatch>);
    //193240 starts with unit incoming scale;193260 callers can supply the
    // actual incoming scale. Prepare all local/world changes and publication
    // before replacing state; retained snapshots and outside nodes survive.
    void patch_local_poses_and_rebuild(std::span<const LocalPosePatch>,std::size_t subtree,const Matrix& parent,bool include_root_siblings=true,Vector parent_scale={1,1,1});
    void patch_local_rotation_axes(std::size_t node,transform_math::Angles);
    std::shared_ptr<const JointSnapshot> retain()const noexcept{return snapshot_;}
private:
    friend class Constraints;
    friend class PoseBlend;
    struct Binding {std::shared_ptr<const Clip> clip;std::size_t track{};};
    std::shared_ptr<const Skeleton> skeleton_;
    std::vector<NodePose> nodes_;
    std::vector<NodeLinks> links_;
    std::vector<std::size_t> traversal_;
    std::vector<std::uint16_t> track_ids_;
    std::vector<std::optional<Binding>> bindings_;
    Vector previous_root_translation_{};
    std::shared_ptr<const JointSnapshot> snapshot_;
    std::uint64_t revision_{};
    void sample_node(std::size_t,float);
    void bind_matching(std::uint16_t,std::shared_ptr<const Clip>,bool allow_trailing);
    void publish_snapshot();
    void invalidate()noexcept{snapshot_.reset();}
};
// Complete58BF50 timing policy, advanced by the original caller's game step.
// It deliberately preserves one-wrap/clamp and positive look-ahead quirks.
struct FrameRecord {float frame{},end{},restart{};std::int8_t loop{};std::uint8_t flags{};};
unsigned advance(FrameRecord&,float step);
} // namespace reo::native::animation
