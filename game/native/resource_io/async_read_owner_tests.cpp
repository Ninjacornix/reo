#include "async_read_owner.hpp"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <limits>
#include <mutex>
#include <new>
#include <stdexcept>
#include <string>
#include <thread>

using namespace std::chrono_literals;
namespace io = reo::native::resource_io;
namespace r = reo::native::resources;
namespace {
std::atomic<unsigned> checks{};
void check(bool condition, const char* message) {
    ++checks;
    if (!condition) throw std::runtime_error(message);
}
struct Gate {
    std::mutex mutex;
    std::condition_variable cv;
    bool entered{}, released{};
    void block() {
        std::unique_lock lock(mutex);
        entered = true;
        cv.notify_all();
        if (!cv.wait_for(lock, 5s, [&] { return released; })) throw std::runtime_error("provider gate timeout");
    }
    void wait() {
        std::unique_lock lock(mutex);
        check(cv.wait_for(lock, 3s, [&] { return entered; }), "provider entered");
    }
    void release() { std::lock_guard lock(mutex); released = true; cv.notify_all(); }
};
struct ReleaseOnExit { Gate& gate; ~ReleaseOnExit() { gate.release(); } };
struct Counts { std::atomic<unsigned> reads{}, deaths{}; };
r::ReadResult fill(std::uint64_t offset, std::span<std::byte> output) {
    for (std::size_t i = 0; i < output.size(); ++i) output[i] = std::byte((offset + i) % 251);
    return {r::Status::ok, output.size()};
}
class View final : public r::ByteView {
public:
    using Read = std::function<r::ReadResult(std::uint64_t, std::span<std::byte>)>;
    View(std::uint64_t size, std::shared_ptr<Counts> counts = std::make_shared<Counts>(),
         Read action = {}, std::function<void()> destroy = {})
        : size_(size), counts_(std::move(counts)), read_(std::move(action)), destroy_(std::move(destroy)) {}
    ~View() override { ++counts_->deaths; if (destroy_) destroy_(); }
    std::uint64_t size() const noexcept override { return size_; }
    r::ReadResult read(std::uint64_t offset, std::span<std::byte> output) const override {
        ++counts_->reads;
        return read_ ? read_(offset, output) : fill(offset, output);
    }
private:
    std::uint64_t size_;
    std::shared_ptr<Counts> counts_;
    Read read_;
    std::function<void()> destroy_;
};
io::ReadOutcome ready(io::AsyncReadOwner& owner, const io::Ticket& ticket) {
    const auto deadline = std::chrono::steady_clock::now() + 3s;
    for (;;) {
        auto result = owner.poll(ticket);
        if (result.status == io::PollStatus::ready) return std::move(result.outcome);
        if (result.status != io::PollStatus::pending) throw std::runtime_error("live request became invalid before ready");
        if (std::chrono::steady_clock::now() >= deadline) throw std::runtime_error("result deadline");
        std::this_thread::yield();
    }
}
io::Ticket accepted(io::AsyncReadOwner& owner, std::shared_ptr<const r::ByteView> view,
                    std::uint64_t offset, std::size_t bytes) {
    auto result = owner.submit(std::move(view), offset, bytes);
    check(result.status == io::SubmitStatus::accepted, "read accepted");
    return result.ticket;
}

void exact_and_bounds() {
    for (unsigned which = 0; which < 4; ++which) {
        io::Config config;
        if (which == 0) config.max_requests = 0;
        if (which == 1) config.max_read_bytes = 0;
        if (which == 2) config.byte_budget = 0;
        if (which == 3) config.max_ticket_id = 0;
        bool rejected = false;
        try { io::AsyncReadOwner owner(config); } catch (const std::invalid_argument&) { rejected = true; }
        check(rejected, "positive constructor limits");
    }
    io::AsyncReadOwner owner({2, 8, 16});
    check(!owner.join(), "join requires shutdown");
    auto counts = std::make_shared<Counts>();
    auto view = std::make_shared<View>(32, counts);
    check(owner.submit({}, 0, 1).status == io::SubmitStatus::invalid_view, "null view rejected");
    check(owner.submit(view, 33, 0).status == io::SubmitStatus::invalid_range, "offset outside view");
    check(owner.submit(view, 31, 2).status == io::SubmitStatus::invalid_range, "range subtract check");
    check(owner.submit(view, 0, 9).status == io::SubmitStatus::read_limit, "per-read bound");
    const auto ticket = accepted(owner, view, 3, 8);
    auto result = ready(owner, ticket);
    check(result.status == r::Status::ok && result.bytes.size() == 8, "exact owned result");
    for (std::size_t i = 0; i < result.bytes.size(); ++i)
        check(result.bytes[i] == std::byte(3 + i), "exact result payload");
    check(owner.poll(ticket).status == io::PollStatus::invalid_ticket, "one-shot consumption");
    check(owner.cancel(ticket) == io::CancelStatus::invalid_ticket, "consumed ticket cannot cancel");
    const auto zero = accepted(owner, view, 32, 0);
    const auto empty = ready(owner, zero);
    check(empty.status == r::Status::ok && empty.bytes.empty() && counts->reads == 1,
          "zero-length endpoint read needs no provider I/O");
    check(owner.shutdown_and_join(), "ordinary shutdown joins");
    check(result.bytes[0] == std::byte{3}, "caller-owned output survives shutdown");
    check(owner.submit(view, 0, 1).status == io::SubmitStatus::owner_closed, "closed submission rejected");
}

void ready_and_byte_quotas() {
    Gate gate;
    io::AsyncReadOwner owner({2, 8, 16});
    ReleaseOnExit release{gate};
    auto first = std::make_shared<View>(16);
    auto block = std::make_shared<View>(16, std::make_shared<Counts>(), [&](auto at, auto out) {
        gate.block(); return fill(at, out);
    });
    const auto first_ticket = accepted(owner, first, 0, 4);
    const auto active = accepted(owner, block, 0, 4);
    gate.wait(); // FIFO proves first result has already been published and ignored.
    check(owner.submit(first, 0, 1).status == io::SubmitStatus::request_capacity,
          "ignored ready results occupy request/result capacity");
    check(owner.cancel(first_ticket) == io::CancelStatus::cancelled, "ready result cancellation");
    check(owner.poll(first_ticket).status == io::PollStatus::invalid_ticket, "ready cancellation invalidates ticket");
    const auto pending = accepted(owner, first, 0, 4);
    check(owner.cancel(pending) == io::CancelStatus::cancelled, "pending cancellation");
    check(owner.submit(first, 0, 1).status == io::SubmitStatus::request_capacity,
          "cancelled pending request retains its capacity until release");
    gate.release();
    check(ready(owner, active).status == r::Status::ok, "active request completes");
    check(owner.shutdown_and_join(), "cancelled pending request drained");

    Gate second_gate;
    io::AsyncReadOwner bytes({4, 16, 16});
    ReleaseOnExit second_release{second_gate};
    auto larger = std::make_shared<View>(32, std::make_shared<Counts>(), [&](auto at, auto out) {
        second_gate.block(); return fill(at, out);
    });
    const auto ticket = accepted(bytes, larger, 0, 8);
    second_gate.wait();
    check(bytes.submit(first, 0, 1).status == io::SubmitStatus::byte_budget,
          "output plus exact-staging bytes reserved before publication");
    check(bytes.cancel(ticket) == io::CancelStatus::cancelled, "active cancellation");
    check(bytes.submit(first, 0, 1).status == io::SubmitStatus::byte_budget,
          "active cancellation cannot return the byte budget early");
    second_gate.release();
    check(bytes.shutdown_and_join(), "active cancellation joins");
}

void stop_and_provider_retention() {
    Gate gate;
    io::AsyncReadOwner owner({2, 8, 32});
    ReleaseOnExit release{gate};
    auto active_counts = std::make_shared<Counts>();
    auto pending_counts = std::make_shared<Counts>();
    auto active = std::make_shared<View>(8, active_counts, [&](auto at, auto out) {
        gate.block(); return fill(at, out);
    });
    auto pending = std::make_shared<View>(8, pending_counts);
    std::weak_ptr<const r::ByteView> active_weak = active, pending_weak = pending;
    const auto active_ticket = accepted(owner, active, 0, 4);
    gate.wait();
    const auto pending_ticket = accepted(owner, pending, 0, 4);
    active.reset(); pending.reset();
    owner.shutdown();
    owner.shutdown();
    check(!active_weak.expired(), "stop retains in-flight provider");
    check(owner.poll(active_ticket).status == io::PollStatus::owner_closed &&
          owner.poll(pending_ticket).status == io::PollStatus::owner_closed, "shutdown invalidates publication");
    auto joining = std::async(std::launch::async, [&] { return owner.join(); });
    check(joining.wait_for(30ms) == std::future_status::timeout, "join waits for blocked provider");
    gate.release();
    check(joining.get(), "stop drains owned work");
    check(active_weak.expired() && pending_weak.expired(), "join releases all owner-held views");
    check(active_counts->reads == 1 && pending_counts->reads == 0, "queued work releases without provider read");
    check(active_counts->deaths == 1 && pending_counts->deaths == 1, "provider release completes before join");
    check(owner.join(), "join is idempotent");
}

void provider_errors() {
    io::AsyncReadOwner owner({2, 8, 32});
    for (unsigned kind = 0; kind < 6; ++kind) {
        auto view = std::make_shared<View>(8, std::make_shared<Counts>(), [kind](auto, auto out) -> r::ReadResult {
            std::fill(out.begin(), out.end(), std::byte{0xee});
            if (kind == 0) return {r::Status::source_failure, out.size()};
            if (kind == 1) return {r::Status::ok, out.size() - 1};
            if (kind == 2) throw std::bad_alloc();
            if (kind == 3) throw std::length_error("synthetic provider length failure");
            if (kind == 4) throw std::runtime_error("synthetic provider failure");
            return {r::Status::no_memory, 0};
        });
        const auto result = ready(owner, accepted(owner, view, 0, 4));
        const auto expected = kind == 2 || kind == 3 || kind == 5 ? r::Status::no_memory : r::Status::source_failure;
        check(result.status == expected && result.bytes.empty(), "typed failure publishes no partial bytes");
    }
    const auto healthy = ready(owner, accepted(owner, std::make_shared<View>(8), 0, 4));
    check(healthy.status == r::Status::ok && healthy.bytes[0] == std::byte{0}, "worker survives provider errors");
    check(owner.shutdown_and_join(), "error sequence shutdown");
}

void identities_and_overflow() {
    auto view = std::make_shared<View>(std::numeric_limits<std::uint64_t>::max());
    io::AsyncReadOwner limited({1, std::numeric_limits<std::size_t>::max(),
                               std::numeric_limits<std::size_t>::max(), 2});
    check(limited.submit(view, std::numeric_limits<std::uint64_t>::max(), 1).status == io::SubmitStatus::invalid_range,
          "offset addition cannot wrap");
    check(limited.submit(view, 0, std::numeric_limits<std::size_t>::max()).status == io::SubmitStatus::byte_budget,
          "double staging charge cannot wrap");
    const auto old = accepted(limited, view, std::numeric_limits<std::uint64_t>::max(), 0);
    check(ready(limited, old).status == r::Status::ok, "maximum offset zero-byte read");
    (void)ready(limited, accepted(limited, view, 0, 0));
    check(limited.submit(view, 0, 0).status == io::SubmitStatus::ticket_exhausted,
          "nonwrapping ticket domain exhausted");
    io::AsyncReadOwner other({1, 8, 16, 1});
    check(other.poll(old).status == io::PollStatus::invalid_ticket &&
          other.cancel(old) == io::CancelStatus::invalid_ticket, "foreign owner rejects ticket");
    check(other.poll({}).status == io::PollStatus::invalid_ticket, "default ticket invalid");

    alignas(io::AsyncReadOwner) std::byte storage[sizeof(io::AsyncReadOwner)];
    auto* first = new (storage) io::AsyncReadOwner({1, 8, 16, 1});
    const auto stale = accepted(*first, std::make_shared<View>(8), 0, 1);
    first->~AsyncReadOwner();
    auto* reused = new (storage) io::AsyncReadOwner({1, 8, 16, 1});
    check(reused->poll(stale).status == io::PollStatus::invalid_ticket, "reused owner address cannot resurrect ticket");
    (void)ready(*reused, accepted(*reused, std::make_shared<View>(8), 0, 1));
    reused->~AsyncReadOwner();
}

void reentry_and_self_join() {
    Gate gate;
    io::AsyncReadOwner owner({2, 8, 32});
    ReleaseOnExit release{gate};
    io::Ticket ticket;
    std::atomic<unsigned> flags{};
    auto counts = std::make_shared<Counts>();
    auto queued_counts = std::make_shared<Counts>();
    auto view = std::make_shared<View>(8, counts, [&](auto at, auto out) {
        gate.block();
        if (owner.poll(ticket).status == io::PollStatus::pending) flags.fetch_or(1);
        if (owner.cancel(ticket) == io::CancelStatus::cancelled) flags.fetch_or(2);
        if (owner.submit(std::make_shared<View>(8, queued_counts), 0, 1).status == io::SubmitStatus::accepted)
            flags.fetch_or(16);
        owner.shutdown();
        if (!owner.join()) flags.fetch_or(4);
        return fill(at, out);
    }, [&] {
        // This destructor runs on the worker after its session lease is closed.
        if (owner.poll(ticket).status == io::PollStatus::owner_closed) flags.fetch_or(8);
        owner.shutdown();
    });
    ticket = accepted(owner, view, 0, 4);
    gate.wait();
    view.reset();
    gate.release();
    const auto deadline = std::chrono::steady_clock::now() + 3s;
    while (!(flags.load() & 4) && std::chrono::steady_clock::now() < deadline) std::this_thread::yield();
    check((flags.load() & 4) != 0, "provider requested shutdown and self-join refused");
    check(owner.join(), "external join succeeds after nonblocking provider reentry");
    check(counts->deaths == 1 && flags.load() == 31, "submit/poll/cancel/stop/self-join and destructor reentry");
    check(queued_counts->reads == 0 && queued_counts->deaths == 1,
          "provider-reentered submission releases without I/O after shutdown");
}

void concurrent_consumption_and_stop() {
    io::AsyncReadOwner owner({4, 8, 64});
    auto view = std::make_shared<View>(8);
    const auto ticket = accepted(owner, view, 0, 4);
    auto poller = [&] {
        for (;;) {
            auto value = owner.poll(ticket);
            if (value.status != io::PollStatus::pending) return value.status;
            std::this_thread::yield();
        }
    };
    auto a = std::async(std::launch::async, poller), b = std::async(std::launch::async, poller);
    const auto av = a.get(), bv = b.get();
    check((av == io::PollStatus::ready && bv == io::PollStatus::invalid_ticket) ||
          (bv == io::PollStatus::ready && av == io::PollStatus::invalid_ticket), "concurrent polls consume once");
    check(owner.shutdown_and_join(), "concurrent poll shutdown");
    for (unsigned round = 0; round < 30; ++round) {
        io::AsyncReadOwner racing({4, 8, 64});
        std::atomic<bool> go{};
        std::vector<std::thread> submitters;
        for (unsigned i = 0; i < 4; ++i) submitters.emplace_back([&] {
            while (!go.load()) std::this_thread::yield();
            for (unsigned j = 0; j < 20; ++j) {
                auto result = racing.submit(view, 0, 4);
                if (result.status == io::SubmitStatus::accepted) (void)racing.cancel(result.ticket);
            }
        });
        go = true;
        racing.shutdown();
        for (auto& thread : submitters) thread.join();
        check(racing.join(), "concurrent submission/stop releases preparing and queued work");
    }
}
} // namespace

int main() {
    try {
        exact_and_bounds();
        ready_and_byte_quotas();
        stop_and_provider_retention();
        provider_errors();
        identities_and_overflow();
        reentry_and_self_join();
        concurrent_consumption_and_stop();
        std::cout << "native resource I/O ownership: " << checks << " checks passed in 7 groups\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "native resource I/O check failed: " << error.what() << '\n';
        return 1;
    }
}
