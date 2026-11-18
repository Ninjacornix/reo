#pragma once
#include "../adxt_instances/instances.hpp"
#include <optional>

namespace reo::native::adxt_control_owner {
namespace instances=adxt_instances;
enum class Admission {accepted,closed,busy};
enum class Join {completed,busy,fault};
class Owner;
// Synchronous, noncopyable proof minted with canonical admission held and NO
// constructed instances, pending starts or retiring sources. Only the exact
// private submix on this calling thread is authorized. Output emptiness alone
// cannot mint this proof. Never retain it beyond its EmptyOperation.
class Quiescent final {
public:
    ~Quiescent();
    Quiescent(const Quiescent&)=delete;Quiescent& operator=(const Quiescent&)=delete;
    [[nodiscard]] bool authorizes(const std::shared_ptr<instances::control::output::Submix>&)const noexcept;
private:
    friend class Owner;
    explicit Quiescent(std::shared_ptr<instances::control::output::Submix>);
    std::shared_ptr<instances::control::output::Submix> render_;
};
class EmptyOperation {
public:
    virtual ~EmptyOperation()=default;
    // Bounded reset/control only: no source/provider I/O, joins, guest or SDK
    // callbacks, owner reentry, or retained proof reference.
    virtual void run(const Quiescent&)noexcept=0;
};
enum class Empty {completed,occupied,closed,busy};
class Operation {
public:
    virtual ~Operation()=default;
    // One synchronous, bounded control borrow. Do not retain mutable aliases,
    // wait for guest work, perform provider I/O, or reenter ANY control owner.
    // Source retirement returns pending; later service advances it normally.
    virtual void run(instances::Instances&)noexcept=0;
};
struct Report {
    std::uint64_t admitted{},refused{},scoped_join_refused{},waiting{};
    bool stopping{},joined{};
    std::optional<instances::Snapshot> final;
};
// Canonical device-free instance owner with a controller admission fence.
// request_stop is signal-only and may race accepted controls/rendering. join
// closes admission, waits for an accepted borrow, then drains actual sources
// without guest/RPC work. Render leases use only the private output state.
class Owner final {
public:
    explicit Owner(instances::control::Config);
    ~Owner();
    Owner(const Owner&)=delete;Owner& operator=(const Owner&)=delete;
    [[nodiscard]] Admission run(Operation&)noexcept;
    [[nodiscard]] Empty when_empty(EmptyOperation&)noexcept;
    void request_stop()noexcept;
    // Blocking teardown, outside every guest/provider/controller scope. No
    // elapsed-time completion or forced source reuse. A fault retains state.
    [[nodiscard]] Join join()noexcept;
    // Outer runtime/device owners check this BEFORE fencing their own child.
    // A controller borrow may not synchronously join any source owner.
    [[nodiscard]] static bool join_allowed_on_current_thread()noexcept;
    [[nodiscard]] std::shared_ptr<instances::control::output::Submix> submix()const noexcept;
    [[nodiscard]] Report report()const noexcept;
private:
    struct State;std::unique_ptr<State> state_;
    void invoke_empty(EmptyOperation&)noexcept;
};
} // namespace reo::native::adxt_control_owner
