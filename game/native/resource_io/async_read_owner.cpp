#include "async_read_owner.hpp"
#include "../resources/resource_session.hpp"
#include "../tasks/serial_worker.hpp"

#include <condition_variable>
#include <exception>
#include <mutex>
#include <new>
#include <stdexcept>
#include <utility>

namespace reo::native::resource_io {
struct ReadOwnerIdentity {};

namespace {
Config checked_config(Config config) {
    if (!config.max_requests || !config.max_read_bytes || !config.byte_budget || !config.max_ticket_id)
        throw std::invalid_argument("AsyncReadOwner limits must be positive");
    return config;
}
} // namespace

struct ReadOwnerState {
    enum class Phase { free, preparing, pending, active, ready, releasing };
    struct Slot {
        std::uint64_t id{};
        std::uint64_t offset{};
        std::size_t count{}, charge{};
        Phase phase{Phase::free};
        bool cancelled{};
        ReadOutcome result;
    };
    Config config;
    std::shared_ptr<const ReadOwnerIdentity> identity = std::make_shared<ReadOwnerIdentity>();
    resources::ResourceSession session;
    std::mutex mutex;
    std::condition_variable idle;
    std::vector<Slot> slots;
    std::size_t charged_bytes{}, submissions{}, outstanding{};
    std::uint64_t last_ticket{};
    bool closed{}, shutdown_complete{};
    // Last member: its thread cannot observe partially constructed owner state.
    tasks::SerialWorker worker;

    explicit ReadOwnerState(Config value)
        : config(checked_config(value)), session({config.max_read_bytes, config.max_requests}),
          slots(config.max_requests), worker(config.max_requests) {}

    bool owns(const Ticket& ticket) const noexcept {
        return ticket.id_ != 0 && ticket.owner_.lock() == identity;
    }
    Slot* find(const Ticket& ticket) noexcept {
        if (!owns(ticket)) return nullptr;
        for (auto& slot : slots)
            if (slot.phase != Phase::free && slot.id == ticket.id_ && !slot.cancelled) return &slot;
        return nullptr;
    }
    void release(Slot& slot) noexcept {
        // Any owned result buffer must already have been moved out. No provider
        // or callable is destroyed while holding this mutex.
        charged_bytes -= slot.charge;
        --outstanding;
        slot.id = 0;
        slot.charge = 0;
        slot.cancelled = false;
        slot.phase = Phase::free;
        idle.notify_all();
    }
    struct Submission {
        ReadOwnerState& state;
        explicit Submission(ReadOwnerState& owner) : state(owner) {
            std::lock_guard lock(state.mutex);
            ++state.submissions;
        }
        ~Submission() {
            std::lock_guard lock(state.mutex);
            --state.submissions;
            state.idle.notify_all();
        }
    };

    SubmitResult submit(std::shared_ptr<const resources::ByteView> view,
                        std::uint64_t offset, std::size_t count) noexcept {
        Submission submission(*this);
        // The inner parameter/capture is destroyed before Submission's guard,
        // so join cannot return while an admitting thread still retains a view.
        return submit_inner(std::move(view), offset, count);
    }

    SubmitResult submit_inner(std::shared_ptr<const resources::ByteView> view,
                              std::uint64_t offset, std::size_t count) noexcept {
        {
            std::lock_guard lock(mutex);
            if (closed) return {SubmitStatus::owner_closed, {}, resources::Status::session_closed};
        }
        if (!view) return {SubmitStatus::invalid_view, {}, resources::Status::invalid_view};
        const auto size = view->size(); // Immutable, nonblocking; outside owner/session locks.
        if (offset > size || count > size - offset)
            return {SubmitStatus::invalid_range, {}, resources::Status::invalid_range};
        if (count > config.max_read_bytes)
            return {SubmitStatus::read_limit, {}, resources::Status::read_limit};
        if (count > config.byte_budget / 2)
            return {SubmitStatus::byte_budget, {}, resources::Status::ok};
        const auto charge = count * 2; // Division check above also prevents multiplication overflow.
        std::size_t index = slots.size();
        std::uint64_t id = 0;
        {
            std::lock_guard lock(mutex);
            if (closed) return {SubmitStatus::owner_closed, {}, resources::Status::session_closed};
            if (last_ticket == config.max_ticket_id)
                return {SubmitStatus::ticket_exhausted, {}, resources::Status::ok};
            for (std::size_t i = 0; i < slots.size(); ++i)
                if (slots[i].phase == Phase::free) { index = i; break; }
            if (index == slots.size()) return {SubmitStatus::request_capacity, {}, resources::Status::ok};
            if (charge > config.byte_budget - charged_bytes)
                return {SubmitStatus::byte_budget, {}, resources::Status::ok};
            id = ++last_ticket; // Zero is invalid; never increments past the configured final ID.
            auto& slot = slots[index];
            slot.id = id;
            slot.offset = offset;
            slot.count = count;
            slot.charge = charge;
            slot.cancelled = false;
            slot.phase = Phase::preparing;
            charged_bytes += charge;
            ++outstanding;
        }
        const auto opened = session.open(view);
        if (opened.status != resources::Status::ok) {
            std::lock_guard lock(mutex);
            release(slots[index]);
            return {opened.status == resources::Status::no_memory ? SubmitStatus::no_memory : SubmitStatus::session_error,
                    {}, opened.status};
        }
        bool stopped = false;
        {
            std::lock_guard lock(mutex);
            stopped = closed;
            if (!stopped) slots[index].phase = Phase::pending;
        }
        if (stopped) {
            (void)session.close(opened.handle);
            std::lock_guard lock(mutex);
            release(slots[index]);
            return {SubmitStatus::owner_closed, {}, resources::Status::session_closed};
        }
        auto refusal = SubmitStatus::worker_unavailable;
        try {
            const auto accepted = worker.submit([this, index, id, handle = opened.handle] {
                execute(index, id, handle);
            });
            if (accepted == tasks::SubmitStatus::accepted) {
                Ticket ticket;
                ticket.owner_ = identity;
                ticket.id_ = id;
                return {SubmitStatus::accepted, ticket, resources::Status::ok};
            }
            if (accepted == tasks::SubmitStatus::stopping) refusal = SubmitStatus::owner_closed;
        } catch (const std::bad_alloc&) {
            refusal = SubmitStatus::no_memory;
        } catch (const std::length_error&) {
            refusal = SubmitStatus::no_memory;
        } catch (...) {
            refusal = SubmitStatus::worker_unavailable;
        }
        (void)session.close(opened.handle);
        {
            std::lock_guard lock(mutex);
            release(slots[index]);
        }
        return {refusal, {}, refusal == SubmitStatus::no_memory ? resources::Status::no_memory : resources::Status::ok};
    }

    void execute(std::size_t index, std::uint64_t id, const resources::Handle& handle) noexcept {
        std::uint64_t offset = 0;
        std::size_t count = 0;
        bool read = false;
        {
            std::lock_guard lock(mutex);
            auto& slot = slots[index];
            if (slot.id == id && !closed && !slot.cancelled) {
                slot.phase = Phase::active;
                offset = slot.offset;
                count = slot.count;
                read = true;
            }
        }
        ReadOutcome result;
        if (read) {
            try {
                result.bytes.resize(count);
                result.status = session.read_exact(handle, offset, result.bytes).status;
            } catch (const std::bad_alloc&) {
                result.status = resources::Status::no_memory;
            } catch (const std::length_error&) {
                result.status = resources::Status::no_memory;
            } catch (...) {
                result.status = resources::Status::source_failure;
            }
            if (result.status != resources::Status::ok) {
                std::vector<std::byte> discard;
                discard.swap(result.bytes); // Release failed output outside both registry locks.
            }
        }
        // Closing a view may call its destructor, including nonblocking owner
        // reentry. Complete that release before publishing or freeing a slot.
        (void)session.close(handle);
        bool discard = false;
        {
            std::lock_guard lock(mutex);
            auto& slot = slots[index];
            if (slot.id != id) std::terminate(); // An active/cancelled slot cannot be reused early.
            if (closed || slot.cancelled || !read) {
                slot.phase = Phase::releasing;
                discard = true;
            }
            else {
                slot.result = std::move(result);
                slot.phase = Phase::ready;
            }
        }
        if (discard) {
            std::vector<std::byte>().swap(result.bytes);
            std::lock_guard lock(mutex);
            release(slots[index]);
        }
    }

    PollResult poll(const Ticket& ticket) noexcept {
        std::lock_guard lock(mutex);
        if (!owns(ticket)) return {PollStatus::invalid_ticket, {}};
        if (closed) return {PollStatus::owner_closed, {}};
        auto* slot = find(ticket);
        if (!slot) return {PollStatus::invalid_ticket, {}};
        if (slot->phase != Phase::ready) return {PollStatus::pending, {}};
        auto result = std::move(slot->result);
        release(*slot);
        return {PollStatus::ready, std::move(result)};
    }

    CancelStatus cancel(const Ticket& ticket) noexcept {
        ReadOutcome discard;
        Slot* releasing = nullptr;
        {
            std::lock_guard lock(mutex);
            if (!owns(ticket)) return CancelStatus::invalid_ticket;
            if (closed) return CancelStatus::owner_closed;
            auto* slot = find(ticket);
            if (!slot) return CancelStatus::invalid_ticket;
            slot->cancelled = true;
            if (slot->phase == Phase::ready) {
                discard = std::move(slot->result);
                slot->phase = Phase::releasing;
                releasing = slot;
            }
        }
        if (releasing) {
            std::vector<std::byte>().swap(discard.bytes);
            std::lock_guard lock(mutex);
            release(*releasing);
        }
        return CancelStatus::cancelled;
    }

    void shutdown() noexcept {
        {
            std::lock_guard lock(mutex);
            if (closed) return;
            closed = true;
            for (auto& slot : slots) slot.cancelled = true;
        }
        worker.request_stop(tasks::StopMode::drain);
        for (auto& slot : slots) {
            ReadOutcome discard;
            bool releasing = false;
            {
                std::lock_guard lock(mutex);
                if (slot.phase == Phase::ready) {
                    discard = std::move(slot.result);
                    slot.phase = Phase::releasing;
                    releasing = true;
                }
            }
            if (releasing) {
                std::vector<std::byte>().swap(discard.bytes);
                std::lock_guard lock(mutex);
                release(slot);
            }
        }
        {
            std::lock_guard lock(mutex);
            shutdown_complete = true;
        }
        idle.notify_all();
    }

    bool join() noexcept {
        {
            std::lock_guard lock(mutex);
            if (!closed) return false;
        }
        try {
            // SerialWorker checks its TLS identity before locking/waiting. Do
            // this before waiting on submissions, including during provider reentry.
            if (!worker.join()) return false;
            {
                std::unique_lock lock(mutex);
                idle.wait(lock, [&] { return shutdown_complete && submissions == 0 && outstanding == 0; });
            }
            session.shutdown_and_drain();
            return true;
        } catch (...) { return false; }
    }
};

AsyncReadOwner::AsyncReadOwner(Config config) : state_(std::make_unique<ReadOwnerState>(config)) {}
AsyncReadOwner::~AsyncReadOwner() noexcept {
    state_->shutdown();
    if (!state_->join()) std::terminate();
}
SubmitResult AsyncReadOwner::submit(std::shared_ptr<const resources::ByteView> view,
                                   std::uint64_t offset, std::size_t bytes) noexcept {
    return state_->submit(std::move(view), offset, bytes);
}
PollResult AsyncReadOwner::poll(const Ticket& ticket) noexcept { return state_->poll(ticket); }
CancelStatus AsyncReadOwner::cancel(const Ticket& ticket) noexcept { return state_->cancel(ticket); }
void AsyncReadOwner::shutdown() noexcept { state_->shutdown(); }
bool AsyncReadOwner::join() noexcept { return state_->join(); }
bool AsyncReadOwner::shutdown_and_join() noexcept { shutdown(); return join(); }

} // namespace reo::native::resource_io
