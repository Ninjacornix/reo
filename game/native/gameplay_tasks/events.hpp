#pragma once
#include "tasks.hpp"

namespace reo::native::gameplay_tasks {
// Session-owned native selection, explicitly passed instead of an implicit
// mutable global. Shared-bank callbacks see the caller's incoming selection.
class OwnerSelection {
    std::uint8_t owned_{};
    struct Borrow {};
    OwnerSelection(std::uint8_t& value,Borrow)noexcept:actor(value){}
public:
    explicit OwnerSelection(std::uint8_t value=0)noexcept:owned_(value),actor(owned_){}
    // Bind directly to the canonical native session. Selection writes during a
    // callback must be visible to other session consumers before it returns.
    static OwnerSelection borrow(std::uint8_t& value)noexcept{return OwnerSelection(value,Borrow{});}
    OwnerSelection(const OwnerSelection&)=delete;
    OwnerSelection& operator=(const OwnerSelection&)=delete;
    std::uint8_t& actor;
};
struct EventContext { std::uint8_t bank{}, slot{}; OwnerSelection& owner; };
enum class EventMode { shared_bank, owner_banks };
class EventTask {
public:
    virtual ~EventTask() = default;
    virtual void update(EventTasks&, const Handle&, EventContext) noexcept = 0;
};
class EventTasks {
public:
    static constexpr std::size_t banks = 3, slots_per_bank = 10;
    EventTasks();
    ~EventTasks();
    EventTasks(const EventTasks&) = delete;
    EventTasks& operator=(const EventTasks&) = delete;
    Created install(std::size_t bank, std::size_t slot, std::shared_ptr<EventTask>) noexcept;
    Status erase(const Handle&) noexcept;
    Status enabled(const Handle&, bool) noexcept;
    bool contains(const Handle&) const noexcept;
    std::size_t size() const noexcept { return size_; }
    PassResult run(EventMode, OwnerSelection&) noexcept;
    Status clear() noexcept;
    bool idle()const noexcept{return !running_ && !clearing_;}
    Status seal()noexcept{if(!idle())return Status::busy;closed_=true;return Status::completed;}
private:
    struct Node;
    std::shared_ptr<const Domain> domain_;
    std::array<std::shared_ptr<Node>, banks * slots_per_bank> slots_{};
    std::uint64_t next_serial_{};
    std::size_t size_{};
    bool running_{}, clearing_{}, closed_{};
    std::shared_ptr<Node> find(const Handle&) const noexcept;
};
} // namespace reo::native::gameplay_tasks
