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
thread_local const Quiescent* empty_proof{};
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
Quiescent::Quiescent(std::shared_ptr<instances::control::output::Submix> render):render_(std::move(render)){empty_proof=this;}
Quiescent::~Quiescent(){empty_proof=nullptr;}
bool Quiescent::authorizes(const std::shared_ptr<instances::control::output::Submix>& render)const noexcept{return inside_control && empty_proof==this && render && render==render_;}
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
Empty Owner::when_empty(EmptyOperation& operation)noexcept {
    // The SAME admission/recheck protocol stays locked through the reset, so
    // later construction cannot race an earlier empty observation. This path
    // never joins a source: ordinary destruction must already have done so.
    struct Check final:Operation {
        Owner& owner;EmptyOperation& target;bool invoked{};
        Check(Owner& o,EmptyOperation& t):owner(o),target(t){}
        void run(instances::Instances& players)noexcept override{
            const auto state=players.snapshot();
            if(state.closing || state.instances || state.pending || state.retiring || state.session.records || state.session.retiring || state.session.service_busy || state.session.guard_fault || state.session.output.occupied)return;
            owner.invoke_empty(target);invoked=true;
        }
    } check(*this,operation);
    const auto admitted=run(check);
    return admitted==Admission::closed?Empty::closed:admitted==Admission::busy?Empty::busy:check.invoked?Empty::completed:Empty::occupied;
}
void Owner::invoke_empty(EmptyOperation& operation)noexcept {Quiescent proof(state_->render);operation.run(proof);}
void Owner::request_stop()noexcept{state_->stopping.store(true,std::memory_order_release);}
bool Owner::join_allowed_on_current_thread()noexcept{return !inside_control;}
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
