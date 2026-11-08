#pragma once
#include "handle_profile.h"
#include "game/native/adxt_control_owner/owner.hpp"

namespace reo::native::adxt_binding {
namespace instances=adxt_instances;
namespace control_owner=adxt_control_owner;
struct GameIdentity;
class GameKey final {
public:GameKey()=default;
private:friend class GameHandles;std::weak_ptr<const GameIdentity> owner_;std::uint32_t slot_{};std::uint64_t generation_{};
};
struct Adoption {instances::Status status{instances::Status::invalid_input};GameKey key;};
class HandleOperation {
public:
    virtual ~HandleOperation()=default;
    // Synchronous control only, under the canonical owner's admission guard.
    // Use the supplied key for source/control/snapshot operations. Lifecycle,
    // creation and order belong to GameHandles. No retained mutable aliases,
    // guest callbacks, provider I/O, joins or nested owner admission.
    virtual void run(instances::Instances&,const instances::Key&,const Handle&)noexcept=0;
};
struct HandleCounts {std::uint32_t mapped{},destroying{};bool cleared_after_join{};};
// Guest adapter bookkeeping, not a new native source/session. Requires a single
// external guest controller and an initially empty, exclusively used Owner.
// No guest pointers/RAM aliases are retained. The runtime adapter separately
// fences its accepted guest calls before clearing/destroying this map.
class GameHandles final {
public:
    explicit GameHandles(std::shared_ptr<control_owner::Owner>);
    ~GameHandles();
    GameHandles(const GameHandles&)=delete;GameHandles& operator=(const GameHandles&)=delete;
    [[nodiscard]] Adoption adopt(const HandleResult&,std::shared_ptr<const adxt_attenuation::Table>)noexcept;
    [[nodiscard]] GameKey find(const HandleResult&)const noexcept;
    [[nodiscard]] instances::Status with(const GameKey&,HandleOperation&)noexcept;
    // Original destruction must not free/reuse children until completed. A
    // pending result retains BOTH original DTR reservations and the game key.
    [[nodiscard]] instances::Status destroy(const GameKey&)noexcept;
    [[nodiscard]] instances::Status set_order(std::span<const GameKey>)noexcept;
    [[nodiscard]] instances::Status service(std::uint32_t original_tick)noexcept;
    [[nodiscard]] HandleCounts counts()const noexcept;
    // Whole-owner shutdown proof only, called after the guest admission fence.
    [[nodiscard]] instances::Status clear_after_join()noexcept;
private:
    struct State;std::unique_ptr<State> state_;
    bool valid(const GameKey&,bool destroying=false)const noexcept;
    void release(std::uint32_t)noexcept;
};
} // namespace reo::native::adxt_binding
