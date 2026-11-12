#pragma once
#include "world.hpp"
#include "../gameplay_effects/pose_lifetime.hpp"
namespace reo::native::gameplay_world {
class PoseWorkPool;
class PoseWorkUpdates {
public:
    virtual ~PoseWorkUpdates()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t kind)=0;
};
enum class PoseWorkStatus {completed,full,closed,busy,unavailable,invalid_identity,no_memory,budget_exhausted};
struct PoseWorkCreated {PoseWorkStatus status{PoseWorkStatus::unavailable};actors::EntityId id;};
struct PoseWorkPass {PoseWorkStatus status{PoseWorkStatus::completed};std::size_t called{},retired{};};
// Actual64-entry scene pose domain. Actors live in the canonical World's
// EntityStore; this owner retains only source-order and physical budget data.
// World must outlive this owner. NativeSession owns them in that order.
class PoseWorkPool final {
public:
    static constexpr std::size_t capacity=64;
    explicit PoseWorkPool(World&);
    ~PoseWorkPool();
    PoseWorkPool(const PoseWorkPool&)=delete;
    PoseWorkPool& operator=(const PoseWorkPool&)=delete;
    bool bound_to(const World&)const noexcept;
    PoseWorkCreated allocate(bool prepend=true)noexcept;
    PoseWorkStatus retire(const actors::EntityId&,bool clear_visible=false)noexcept;
    PoseWorkStatus reset()noexcept;
    PoseWorkStatus close()noexcept;
    std::size_t remaining()const noexcept{return bound_to(world_)?remaining_:0;}
    std::optional<std::uint8_t> physical_slot(const actors::EntityId&)const noexcept;
    actors::EntityId head()const noexcept;
    actors::EntityId tail()const noexcept;
    std::shared_ptr<Actor> resolve(const actors::EntityId&)const noexcept;
    World& world()const noexcept{return world_;}
    PoseWorkPass update(PoseWorkUpdates* =nullptr,std::size_t budget=4096);
private:
    struct Slot {actors::EntityId id;std::optional<std::uint8_t> previous,next;};
    World& world_;
    std::array<Slot,capacity> slots_;
    std::array<std::uint8_t,capacity> free_{};
    std::optional<std::uint8_t> head_,tail_;
    std::size_t remaining_{capacity};
    bool closed_{},busy_{},resetting_{};
    PoseWorkStatus retire_impl(const actors::EntityId&,bool)noexcept;
    PoseWorkStatus clear(bool)noexcept;
};
}
