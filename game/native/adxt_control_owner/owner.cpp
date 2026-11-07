#include "owner.hpp"
#include <atomic>
#include <chrono>
#include <exception>
#include <mutex>
#include <thread>

namespace reo::native::adxt_control_owner {
namespace {
// Refuse all nested owners, including A -> B -> A: a top-owner-only test
// would miss the held outer controller mutex and deadlock on reentry.
thread_local bool inside_control{};
struct ControlScope {ControlScope(){inside_control=true;}~ControlScope(){inside_control=false;}};
}
struct Owner::State {
    std::mutex control;instances::Instances players;
    const std::shared_ptr<instances::control::output::Submix> render;
    std::atomic<bool> stopping{},joined{};
    std::atomic<std::uint64_t> admitted{},refused{},scoped_join_refused{},waiting{};
    instances::Snapshot final;
    explicit State(instances::control::Config config):players(config),render(players.submix()){}
};
Owner::Owner(instances::control::Config config):state_(std::make_unique<State>(config)){}
Owner::~Owner(){if(join()!=Join::completed)std::terminate();}
Admission Owner::run(Operation& operation)noexcept {
    auto& s=*state_;
    if(inside_control){++s.refused;return Admission::busy;}
    if(s.stopping.load(std::memory_order_acquire)){++s.refused;return Admission::closed;}
    ++s.waiting;std::lock_guard lock(s.control);--s.waiting;
    // A caller can pass the first test before shutdown closes admission and
    // then wait behind an accepted operation. Never invoke it after that wait.
    if(s.stopping.load(std::memory_order_acquire)){++s.refused;return Admission::closed;}
    ControlScope scope;++s.admitted;operation.run(s.players);return Admission::accepted;
}
void Owner::request_stop()noexcept{state_->stopping.store(true,std::memory_order_release);}
Join Owner::join()noexcept {
    auto& s=*state_;
    if(inside_control){++s.scoped_join_refused;return Join::busy;}
    request_stop();std::lock_guard lock(s.control);
    if(s.joined.load(std::memory_order_relaxed))return Join::completed;
    // A file-only source worker never waits on a guest or this controller.
    // Keep its actual backing alive until it acknowledges cancellation/join.
    for(;;){const auto status=s.players.join();
        if(status==instances::Status::completed)break;
        if(status!=instances::Status::pending)return Join::fault;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    s.final=s.players.snapshot();s.joined.store(true,std::memory_order_release);return Join::completed;
}
std::shared_ptr<instances::control::output::Submix> Owner::submix()const noexcept{return state_->render;}
Report Owner::report()const noexcept {
    const auto& s=*state_;Report result;result.admitted=s.admitted.load();result.refused=s.refused.load();result.scoped_join_refused=s.scoped_join_refused.load();result.waiting=s.waiting.load();
    result.joined=s.joined.load(std::memory_order_acquire);result.stopping=s.stopping.load(std::memory_order_acquire);
    if(result.joined)result.final=s.final; // Written once, published by joined.
    return result;
}
} // namespace reo::native::adxt_control_owner
