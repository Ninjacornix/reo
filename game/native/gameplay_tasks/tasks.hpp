#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>

namespace reo::native::gameplay_tasks {

struct Domain;
class Scheduler;
class EventTasks;
class Handle {
public:
    Handle() = default;
    explicit operator bool() const noexcept { return bool(domain_); }
    friend bool operator==(const Handle&, const Handle&) = default;
private:
    std::shared_ptr<const Domain> domain_;
    std::uint64_t serial_{};
    std::size_t slot_{};
    friend class Scheduler;
    friend class EventTasks;
};

// Gameplay callbacks execute synchronously on their simulation owner thread.
// The task and its context are native objects; presentation is a separate pass.
class Task {
public:
    virtual ~Task() = default;
    virtual void update(Scheduler&, const Handle&) noexcept = 0;
    virtual void present(Scheduler&, const Handle&) noexcept {}
};

enum class Status { completed, full, invalid, foreign_or_stale, busy, no_memory, budget_exhausted, closed };
enum class Placement { newest, oldest };
enum class Pass { update, presentation };
struct Created { Status status{Status::invalid}; Handle handle; };
struct TaskPolicy {
    std::uint8_t active_flags{1};
    std::uint8_t presentation_mask{};
    bool presentation_callback{};
};
struct PassResult { Status status{Status::completed}; std::size_t visited{}, called{}; };

class Scheduler {
public:
    static constexpr std::size_t capacity = 32;
    Scheduler();
    ~Scheduler();
    Scheduler(const Scheduler&) = delete;
    Scheduler& operator=(const Scheduler&) = delete;
    Created create(std::shared_ptr<Task>, TaskPolicy = {}, Placement = Placement::newest) noexcept;
    Status erase(const Handle&) noexcept;
    Status policy(const Handle&, TaskPolicy) noexcept;
    bool contains(const Handle&) const noexcept;
    std::size_t size() const noexcept { return size_; }
    // Read each predecessor after the callback: head-created children and
    // removals affect this pass, unlike a snapshot/vector job dispatch.
    PassResult run(Pass, std::size_t maximum_visits = 1024) noexcept;
    Status clear() noexcept;
    bool idle()const noexcept{return !running_ && !clearing_;}
    bool closed()const noexcept{return closed_;}
    // Seal admission without releasing payloads, allowing a composite owner to
    // seal all child stores before any cross-store destructor callback runs.
    Status seal()noexcept{if(!idle())return Status::busy;closed_=true;return Status::completed;}
private:
    struct Node;
    std::shared_ptr<const Domain> domain_;
    std::array<std::shared_ptr<Node>, capacity> slots_{};
    std::shared_ptr<Node> head_, tail_;
    std::uint64_t next_serial_{};
    std::size_t size_{};
    bool running_{}, clearing_{}, closed_{};
    std::shared_ptr<Node> find(const Handle&) const noexcept;
};

enum class FlagScope { scenario, session_owner_zero };
struct FlagTarget {
    FlagScope scope{FlagScope::scenario};
    std::uint16_t id{};
    friend bool operator==(const FlagTarget&, const FlagTarget&) = default;
};
struct FlagExpiry { std::size_t slot{}; FlagTarget target; };
class FlagSink {
public:
    virtual ~FlagSink() = default;
    // Synchronous. The scenario consumer sets the flag and its notification;
    // the session consumer sets owner zero without scenario notification.
    virtual void expired(const FlagExpiry&) noexcept = 0;
};
struct FlagTimer { std::int16_t remaining{}; FlagTarget target; };
class FlagTimers {
public:
    static constexpr std::size_t capacity = 8;
    Status arm(std::size_t slot, std::int16_t invocations, FlagTarget) noexcept;
    Status tick(FlagSink&) noexcept;
    const std::array<FlagTimer, capacity>& snapshot() const noexcept { return timers_; }
private:
    std::array<FlagTimer, capacity> timers_{};
    bool ticking_{};
};

enum class ClockStep : std::uint8_t { one = 1, two = 2 };
struct PlayTime {
    std::uint8_t hours{}, minutes{}, seconds{}, sixtieths{};
    friend bool operator==(const PlayTime&, const PlayTime&) = default;
};
class SimulationClock {
public:
    Status restore(PlayTime, std::uint32_t update_counter) noexcept;
    // Called once by the admitted gameplay owner AFTER its workers and gates.
    // Task passes/timer ticks do not call this implicitly. No host-time catchup.
    Status commit_update(ClockStep) noexcept;
    PlayTime play_time() const noexcept;
    std::uint32_t update_counter() const noexcept { return updates_; }
    std::uint32_t sixtieth_units() const noexcept { return units_; }
    // The original caller has explicit +150/+360 adjustment branches. Keep
    // those separate from ordinary once-per-update commits and play time.
    void adjust_update_counter(std::uint32_t delta) noexcept { updates_ += delta; }
private:
    std::uint32_t units_{}, updates_{};
};

} // namespace reo::native::gameplay_tasks
