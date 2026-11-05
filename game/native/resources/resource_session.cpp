#include "resource_session.hpp"

#include <algorithm>
#include <condition_variable>
#include <mutex>
#include <new>
#include <stdexcept>
#include <utility>
#include <vector>

namespace reo::native::resources {

struct SessionIdentity {};

struct ResourceSession::State {
    struct Slot {
        std::shared_ptr<const ByteView> view;
        std::uint64_t size{};
        std::uint64_t generation{1};
        bool retired{};
    };
    SessionConfig config;
    std::shared_ptr<const SessionIdentity> identity = std::make_shared<SessionIdentity>();
    std::mutex mutex;
    std::condition_variable idle;
    std::vector<Slot> slots;
    std::size_t active_reads{};
    bool closed{};

    explicit State(SessionConfig value) : config(value) {}

    bool valid(const Handle& handle) const noexcept {
        return handle.owner_.lock() == identity && handle.slot_ < slots.size() &&
            slots[handle.slot_].view && slots[handle.slot_].generation == handle.generation_;
    }

    struct ReadLease {
        std::shared_ptr<State> state;
        std::shared_ptr<const ByteView> view;
        ~ReadLease() {
            // Provider destruction, including host file close, is outside the
            // registry mutex and completes before a draining owner is released.
            view.reset();
            std::lock_guard lock(state->mutex);
            if (--state->active_reads == 0) state->idle.notify_all();
        }
    };
};

ResourceSession::ResourceSession(SessionConfig config) {
    if (!config.max_read_bytes || !config.max_handles || !config.max_generation)
        throw std::invalid_argument("Resource session limits must be positive");
    state_ = std::make_shared<State>(config);
}

ResourceSession::~ResourceSession() { shutdown(); }

OpenResult ResourceSession::open(std::shared_ptr<const ByteView> view) noexcept {
    const auto state = state_;
    // size() is an immutable, nonblocking metadata query; never call a provider
    // method while holding the registry mutex, even for this query.
    {
        std::lock_guard lock(state->mutex);
        if (state->closed) return {Status::session_closed, {}};
    }
    if (!view) return {Status::invalid_view, {}};
    const auto bytes = view->size();
    try {
        std::lock_guard lock(state->mutex);
        if (state->closed) return {Status::session_closed, {}};
        std::size_t index = 0;
        while (index < state->slots.size() && (state->slots[index].view || state->slots[index].retired)) ++index;
        if (index == state->slots.size()) {
            if (index >= state->config.max_handles) return {Status::capacity_exhausted, {}};
            state->slots.emplace_back();
        }
        auto& slot = state->slots[index];
        slot.view = std::move(view);
        slot.size = bytes;
        Handle handle;
        handle.owner_ = state->identity;
        handle.slot_ = static_cast<std::uint32_t>(index);
        handle.generation_ = slot.generation;
        return {Status::ok, handle};
    } catch (const std::bad_alloc&) {
        return {Status::no_memory, {}};
    } catch (const std::length_error&) {
        return {Status::no_memory, {}};
    }
}

SizeResult ResourceSession::size(const Handle& handle) const noexcept {
    const auto state = state_;
    std::lock_guard lock(state->mutex);
    if (state->closed) return {Status::session_closed, 0};
    if (!state->valid(handle)) return {Status::invalid_handle, 0};
    return {Status::ok, state->slots[handle.slot_].size};
}

ReadResult ResourceSession::read_exact(const Handle& handle, std::uint64_t offset,
                                     std::span<std::byte> destination) noexcept {
    const auto state = state_;
    std::shared_ptr<const ByteView> view;
    {
        std::lock_guard lock(state->mutex);
        if (state->closed) return {Status::session_closed, 0};
        if (!state->valid(handle)) return {Status::invalid_handle, 0};
        const auto& slot = state->slots[handle.slot_];
        if (offset > slot.size || destination.size() > slot.size - offset) return {Status::invalid_range, 0};
        if (destination.size() > state->config.max_read_bytes) return {Status::read_limit, 0};
        if (destination.empty()) return {Status::ok, 0};
        view = slot.view;
        ++state->active_reads;
    }
    State::ReadLease lease{state, std::move(view)};
    try {
        std::vector<std::byte> temporary(destination.size());
        const auto result = lease.view->read(offset, temporary);
        if (result.status == Status::no_memory) return {Status::no_memory, 0};
        if (result.status != Status::ok || result.bytes != temporary.size()) return {Status::source_failure, 0};
        std::copy(temporary.begin(), temporary.end(), destination.begin());
        return {Status::ok, destination.size()};
    } catch (const std::bad_alloc&) {
        return {Status::no_memory, 0};
    } catch (const std::length_error&) {
        return {Status::no_memory, 0};
    } catch (...) {
        return {Status::source_failure, 0};
    }
}

Status ResourceSession::close(const Handle& handle) noexcept {
    const auto state = state_;
    std::shared_ptr<const ByteView> release;
    {
        std::lock_guard lock(state->mutex);
        if (state->closed) return Status::session_closed;
        if (!state->valid(handle)) return Status::invalid_handle;
        auto& slot = state->slots[handle.slot_];
        release = std::move(slot.view);
        if (slot.generation == state->config.max_generation) slot.retired = true;
        else ++slot.generation;
    }
    return Status::ok;
}

void ResourceSession::shutdown() noexcept {
    const auto state = state_;
    std::vector<State::Slot> release;
    {
        std::lock_guard lock(state->mutex);
        state->closed = true;
        release.swap(state->slots);
    }
}

void ResourceSession::drain() noexcept {
    const auto state = state_;
    std::unique_lock lock(state->mutex);
    state->idle.wait(lock, [&] { return state->active_reads == 0; });
}

void ResourceSession::shutdown_and_drain() noexcept { shutdown(); drain(); }

} // namespace reo::native::resources
