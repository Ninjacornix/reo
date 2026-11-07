#pragma once
#include "../adxt_instances/instances.hpp"
#include <optional>

namespace reo::native::adxt_control_owner {
namespace instances=adxt_instances;
enum class Admission {accepted,closed,busy};
enum class Join {completed,busy,fault};
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
    void request_stop()noexcept;
    // Blocking teardown, outside every guest/provider/controller scope. No
    // elapsed-time completion or forced source reuse. A fault retains state.
    [[nodiscard]] Join join()noexcept;
    [[nodiscard]] std::shared_ptr<instances::control::output::Submix> submix()const noexcept;
    [[nodiscard]] Report report()const noexcept;
private:
    struct State;std::unique_ptr<State> state_;
};
} // namespace reo::native::adxt_control_owner
