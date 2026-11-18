#include "events.hpp"
#include <limits>
#include <new>
#include <utility>

namespace reo::native::gameplay_tasks {
// Domain instances carry only native lifetime identity, shared by opaque keys.
// The definition matches the scheduler translation unit's empty identity type.
struct Domain {};
struct EventTasks::Node { Handle handle; std::shared_ptr<EventTask> task; bool enabled{true}; };
EventTasks::EventTasks() : domain_(std::make_shared<Domain>()) {}
EventTasks::~EventTasks() { closed_ = true; (void)clear(); }
std::shared_ptr<EventTasks::Node> EventTasks::find(const Handle& handle) const noexcept {
    if (handle.domain_ != domain_ || handle.slot_ >= slots_.size()) return {};
    const auto node = slots_[handle.slot_];
    return node && node->handle.serial_ == handle.serial_ ? node : nullptr;
}
bool EventTasks::contains(const Handle& handle) const noexcept { return bool(find(handle)); }
std::optional<EventView> EventTasks::slot(std::size_t bank,std::size_t slot)const noexcept{
    if(bank>=banks||slot>=slots_per_bank)return{};
    const auto& node=slots_[bank*slots_per_bank+slot];
    return node?std::optional<EventView>{{node->handle,node->enabled,node->task}}:std::nullopt;
}
Created EventTasks::install(std::size_t bank, std::size_t slot, std::shared_ptr<EventTask> task) noexcept {
    if (closed_) return {Status::closed, {}};
    if (clearing_) return {Status::busy, {}};
    if (bank >= banks || slot >= slots_per_bank || !task) return {};
    const auto index = bank * slots_per_bank + slot;
    if (slots_[index] || next_serial_ == std::numeric_limits<std::uint64_t>::max()) return {Status::full, {}};
    try {
        auto node = std::make_shared<Node>(); node->task = std::move(task);
        node->handle.domain_ = domain_; node->handle.serial_ = ++next_serial_; node->handle.slot_ = index;
        slots_[index] = node; ++size_; return {Status::completed, node->handle};
    } catch (const std::bad_alloc&) { return {Status::no_memory, {}}; }
}
Status EventTasks::erase(const Handle& handle) noexcept {
    auto node = find(handle); if (!node) return Status::foreign_or_stale;
    slots_[handle.slot_].reset(); --size_; return Status::completed;
}
Status EventTasks::enabled(const Handle& handle, bool value) noexcept {
    const auto node = find(handle); if (!node) return Status::foreign_or_stale;
    node->enabled = value; return Status::completed;
}
PassResult EventTasks::run(EventMode mode, OwnerSelection& owner) noexcept {
    if (closed_) return {Status::closed};
    if (running_ || clearing_) return {Status::busy};
    if (mode != EventMode::shared_bank && mode != EventMode::owner_banks) return {Status::invalid};
    running_ = true; struct Exit { bool& running; ~Exit(){running=false;} } exit{running_};
    PassResult result;
    const auto count = mode == EventMode::owner_banks ? banks : std::size_t{1};
    for (std::size_t bank = 0; bank < count; ++bank) {
        if (bank) owner.actor = static_cast<std::uint8_t>(bank);
        for (std::size_t slot = 0; slot < slots_per_bank; ++slot) {
            ++result.visited;
            // Read each actual slot when reached: an earlier callback can
            // enable/replace a later slot, which then runs in this same pass.
            auto node = slots_[bank * slots_per_bank + slot];
            if (!node || !node->enabled) continue;
            ++result.called;
            node->task->update(*this, node->handle,
                {static_cast<std::uint8_t>(bank), static_cast<std::uint8_t>(slot), owner});
        }
    }
    if (mode == EventMode::owner_banks) owner.actor = 0;
    return result;
}
Status EventTasks::clear() noexcept {
    if (running_ || clearing_) return Status::busy;
    clearing_ = true; struct Exit {bool& clearing;~Exit(){clearing=false;}} exit{clearing_};
    auto retired = std::move(slots_); slots_ = {}; size_ = 0;
    return Status::completed;
}
} // namespace reo::native::gameplay_tasks
