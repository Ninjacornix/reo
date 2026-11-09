#pragma once
#include "actors.hpp"
#include "sweep.hpp"
#include <memory>

namespace reo::native::gameplay_collision::ownership {
struct Domain;
class Proxies;
class Handle final {
public:
    Handle()=default;
    explicit operator bool()const noexcept{return bool(domain_);}
    friend bool operator==(const Handle&,const Handle&)=default;
private:
    std::shared_ptr<const Domain> domain_;
    std::uint64_t generation_{};
    std::uint32_t slot_{};
    friend class Proxies;
};
struct Record {
    Proxy geometry;
    gameplay_actors::EntityId owner;
    Handle source;
    std::optional<Door> door;
    std::optional<std::uint8_t> owner_snapshot, extra;
};
struct Selected {Handle proxy;gameplay_actors::EntityId actor;std::uint8_t query_class{};};
// Simulation-owner only. Native handles reject stale reuse and foreign rooms.
// List ordering is separate from reusable storage, preserving prepend/append.
class Proxies final {
public:
    explicit Proxies(std::uint32_t capacity=128,std::uint64_t maximum_generation=UINT64_MAX);
    ~Proxies();
    Proxies(const Proxies&)=delete;
    Proxies& operator=(const Proxies&)=delete;
    std::optional<Handle> create(Record,bool prepend=false);
    bool retire(const Handle&) noexcept;
    const Record* get(const Handle&)const noexcept;
    bool replace(const Handle&,Record) noexcept;
    std::vector<Handle> ordered()const;
    std::optional<Selected> select(const ActorQuery&,gameplay_actors::EntityId,
                                  std::span<const ProxyState>)const;
    std::size_t size()const noexcept{return order_.size();}
    void clear() noexcept;
private:
    struct Slot{std::optional<Record> record;std::uint64_t generation{};};
    std::shared_ptr<const Domain> domain_;
    std::vector<Slot> slots_;
    std::vector<std::uint32_t> free_,order_;
    std::uint64_t maximum_generation_;
    mutable std::optional<World> snapshot_;
    bool matches(const Handle&)const noexcept;
    Handle handle(std::uint32_t)const noexcept;
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
