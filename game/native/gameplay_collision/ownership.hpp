#pragma once
#include "actors.hpp"
#include "sweep.hpp"
#include "../gameplay_scene/records.hpp"
#include <memory>

namespace reo::native::gameplay_collision::ownership {
using Handle=gameplay_scene::RecordId;
struct Record {
    Proxy geometry;
    gameplay_actors::EntityId owner;
    std::optional<std::uint8_t> last_query_class;
    Handle source;
    std::optional<Door> door;
    std::optional<std::uint8_t> owner_snapshot, extra;
};
struct Selected {Handle proxy;gameplay_actors::EntityId actor;std::uint8_t query_class{};};
struct LazySelected {LazySelectionStatus status{LazySelectionStatus::completed};std::optional<Selected> selected;};
// Simulation-owner only. Native handles reject stale reuse and foreign rooms.
// List ordering is separate from reusable storage, preserving prepend/append.
class Proxies final {
public:
    explicit Proxies(std::uint32_t capacity=128,std::uint64_t maximum_generation=UINT64_MAX);
    explicit Proxies(std::shared_ptr<gameplay_scene::Records>);
    ~Proxies();
    std::shared_ptr<gameplay_scene::Records> records()const noexcept{return pool_;}
    class InvocationLease final {
    public:
        explicit operator bool()const noexcept{return bool(node_);}
        const gameplay_scene::Record* canonical()const noexcept{return node_?&node_->value:nullptr;}
    private:
        std::shared_ptr<const gameplay_scene::Records::Node> node_;
        friend class Proxies;
    };
    InvocationLease acquire(const Handle&)const noexcept;
    Proxies(const Proxies&)=delete;
    Proxies& operator=(const Proxies&)=delete;
    std::optional<Handle> create(Record,bool prepend=false);
    bool retire(const Handle&) noexcept;
    const Record* get(const Handle&)const noexcept;
    bool replace(const Handle&,Record) noexcept;
    bool publish_owner(const Handle&,gameplay_actors::EntityId actor) noexcept;
    bool publish_query(const Handle&,gameplay_actors::EntityId actor,
                       std::uint8_t query_class) noexcept;
    std::vector<Handle> ordered()const;
    std::optional<Selected> select(const ActorQuery&,gameplay_actors::EntityId,
                                  std::span<const ProxyState>)const;
    LazySelected select_lazy(ActorQuery&,gameplay_actors::EntityId,
                             QueryStateProvider&)const;
    std::size_t size()const noexcept{return pool_->size();}
    void clear() noexcept;
private:
    std::shared_ptr<gameplay_scene::Records> pool_;
    struct Projection {Handle id;std::optional<Record> value;};
    mutable std::array<Projection,128> projections_{};
    mutable std::uint64_t projection_revision_{UINT64_MAX},snapshot_revision_{UINT64_MAX};
    mutable std::optional<World> snapshot_;

};

// Model-space constructors retain the original scaled-orthogonal inverse
// arithmetic; the input is a retained native model pose, never a matrix slot.
std::optional<Proxy> depth_extension(const Proxy&,const actors::Basis&)noexcept;
std::optional<Proxy> depth_sixty(const Proxy&,const actors::Basis&,bool already_bound=false)noexcept;
std::optional<Quad> reproject_middle(const Quad&,const actors::Basis&)noexcept;
Record owned_region(std::uint8_t kind,Quad,std::int32_t lower,std::int32_t upper,
                    gameplay_actors::EntityId,std::uint8_t owner_snapshot=0,std::uint8_t extra=0);

struct WallState {
    Vec3 position,previous,local_center,previous_center_offset;
    float radius{};
    std::uint32_t include{},exclude{};
    bool disabled{},dynamic_kind_gate{},contact{};
    std::optional<Vec3> point,normal;
};
// Original 5DA420 boundary: keep cached center even while disabled, resolve
// current->previous center and apply only X/Z correction to actor position.
sweep::Result move_against_walls(WallState&,const actors::Basis&,
    const response::Grid&,response::Filter,std::span<const response::Triangle> dynamic={});
}
