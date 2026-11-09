#include "tasks.hpp"

#include <limits>
#include <new>
#include <utility>

namespace reo::native::gameplay_tasks {
struct Domain {};
struct Scheduler::Node {
    Handle handle;
    std::shared_ptr<Task> task;
    TaskPolicy policy;
    // One direction owns its chain, so there is no list reference cycle.
    std::shared_ptr<Node> previous;
    std::weak_ptr<Node> next;
    bool linked{true};
};
Scheduler::Scheduler() : domain_(std::make_shared<Domain>()) {}
Scheduler::~Scheduler() { closed_ = true; (void)clear(); }

std::shared_ptr<Scheduler::Node> Scheduler::find(const Handle& handle) const noexcept {
    if (handle.domain_ != domain_ || handle.slot_ >= slots_.size()) return {};
    const auto node = slots_[handle.slot_];
    return node && node->handle.serial_ == handle.serial_ ? node : nullptr;
}
bool Scheduler::contains(const Handle& handle) const noexcept { return bool(find(handle)); }
Created Scheduler::create(std::shared_ptr<Task> task, TaskPolicy policy, Placement placement) noexcept {
    if (closed_) return {Status::closed, {}};
    if (clearing_) return {Status::busy, {}};
    if (!task || (placement != Placement::newest && placement != Placement::oldest)) return {};
    if (size_ == capacity) return {Status::full, {}};
    if (next_serial_ == std::numeric_limits<std::uint64_t>::max()) return {Status::full, {}};
    std::size_t slot = 0;
    while (slots_[slot]) ++slot;
    try {
        auto node = std::make_shared<Node>();
        node->handle.domain_ = domain_; node->handle.serial_ = ++next_serial_; node->handle.slot_ = slot;
        node->task = std::move(task); node->policy = policy;
        if (!head_) head_ = tail_ = node;
        else if (placement == Placement::newest) {
            node->next = head_; head_->previous = node; head_ = node;
        } else {
            node->previous = tail_; tail_->next = node; tail_ = node;
        }
        slots_[slot] = node; ++size_;
        return {Status::completed, node->handle};
    } catch (const std::bad_alloc&) { return {Status::no_memory, {}}; }
}
Status Scheduler::erase(const Handle& handle) noexcept {
    const auto node = find(handle);
    if (!node) return Status::foreign_or_stale;
    const auto next = node->next.lock();
    if (next) next->previous = node->previous;
    else tail_ = node->previous;
    if (node->previous) node->previous->next = next;
    else head_ = next;
    node->linked = false;
    slots_[handle.slot_].reset(); --size_;
    // Do not clear previous: a callback may retire itself and traversal still
    // follows its predecessor after return. A local shared owner retains task
    // storage through that call; a recycled slot never aliases its old node.
    return Status::completed;
}
Status Scheduler::policy(const Handle& handle, TaskPolicy value) noexcept {
    const auto node = find(handle);
    if (!node) return Status::foreign_or_stale;
    node->policy = value; return Status::completed;
}
PassResult Scheduler::run(Pass pass, std::size_t maximum_visits) noexcept {
    if (closed_) return {Status::closed};
    if (running_ || clearing_) return {Status::busy};
    if ((pass != Pass::update && pass != Pass::presentation) || !maximum_visits) return {Status::invalid};
    running_ = true;
    struct Exit { bool& running; ~Exit() { running = false; } } exit{running_};
    PassResult result;
    for (auto cursor = tail_; cursor; cursor = cursor->previous) {
        if (result.visited == maximum_visits) { result.status = Status::budget_exhausted; break; }
        ++result.visited;
        if (!cursor->linked) continue;
        auto task = cursor->task;
        if (pass == Pass::update) { ++result.called; task->update(*this, cursor->handle); }
        else if (cursor->policy.presentation_callback &&
                 (cursor->policy.active_flags & cursor->policy.presentation_mask)) {
            ++result.called; task->present(*this, cursor->handle);
        }
    }
    return result;
}
Status Scheduler::clear() noexcept {
    if (running_ || clearing_) return Status::busy;
    clearing_ = true;
    struct Exit { bool& clearing; ~Exit() { clearing = false; } } exit{clearing_};
    // Complete state retirement before releasing owners/destructors.
    auto retired = std::move(slots_);
    slots_ = {}; head_.reset(); tail_.reset(); size_ = 0;
    for (auto& node : retired) if (node) node->linked = false;
    return Status::completed;
}

Status FlagTimers::arm(std::size_t slot, std::int16_t remaining, FlagTarget target) noexcept {
    if (slot >= capacity || target.id > 0x7fff ||
        (target.scope != FlagScope::scenario && target.scope != FlagScope::session_owner_zero)) return Status::invalid;
    timers_[slot] = {remaining, target}; return Status::completed;
}
Status FlagTimers::tick(FlagSink& sink) noexcept {
    if (ticking_) return Status::busy;
    ticking_ = true;
    struct Exit { bool& ticking; ~Exit() { ticking = false; } } exit{ticking_};
    for (std::size_t i = 0; i < capacity; ++i) {
        auto& timer = timers_[i];
        if (timer.remaining <= 0) continue;
        --timer.remaining;
        if (timer.remaining == 0) sink.expired({i, timer.target});
    }
    return Status::completed;
}

Status SimulationClock::restore(PlayTime time, std::uint32_t updates) noexcept {
    if (time.hours >= 100 || time.minutes >= 60 || time.seconds >= 60 || time.sixtieths >= 60) return Status::invalid;
    units_ = ((std::uint32_t(time.hours) * 60 + time.minutes) * 60 + time.seconds) * 60 + time.sixtieths;
    updates_ = updates; return Status::completed;
}
Status SimulationClock::commit_update(ClockStep step) noexcept {
    if (step != ClockStep::one && step != ClockStep::two) return Status::invalid;
    units_ = (units_ + static_cast<std::uint32_t>(step)) % (100u * 60u * 60u * 60u);
    ++updates_; return Status::completed;
}
PlayTime SimulationClock::play_time() const noexcept {
    auto value = units_;
    PlayTime time; time.sixtieths = static_cast<std::uint8_t>(value % 60); value /= 60;
    time.seconds = static_cast<std::uint8_t>(value % 60); value /= 60;
    time.minutes = static_cast<std::uint8_t>(value % 60); value /= 60;
    time.hours = static_cast<std::uint8_t>(value); return time;
}
} // namespace reo::native::gameplay_tasks
