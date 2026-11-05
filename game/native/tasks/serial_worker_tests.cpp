#include "serial_worker.hpp"

#include <array>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <latch>
#include <memory>
#include <new>
#include <stdexcept>
#include <utility>
#include <vector>

// Count ordinary allocations on the submitting thread only. Task construction
// is deliberately outside this window; unrelated worker allocations do not hide
// a queue allocation. These replacements use the matching malloc/free family.
namespace allocation_probe {
thread_local bool enabled = false;
thread_local std::size_t count = 0;
} // namespace allocation_probe

#if defined(__GNUC__)
__attribute__((noinline))
#endif
void* operator new(std::size_t size) {
    if (allocation_probe::enabled)
        ++allocation_probe::count;
    if (void* result = std::malloc(size == 0 ? 1 : size))
        return result;
    throw std::bad_alloc();
}

#if defined(__GNUC__)
__attribute__((noinline))
#endif
void operator delete(void* pointer) noexcept {
    std::free(pointer);
}
void operator delete(void* pointer, std::size_t) noexcept {
    ::operator delete(pointer);
}
void* operator new[](std::size_t size) {
    return ::operator new(size);
}
void operator delete[](void* pointer) noexcept {
    ::operator delete(pointer);
}
void operator delete[](void* pointer, std::size_t) noexcept {
    ::operator delete(pointer);
}

using namespace reo::native::tasks;
using namespace std::chrono_literals;

namespace {
std::atomic<unsigned> checks{0};
void check(bool condition, const char* message) {
    checks.fetch_add(1, std::memory_order_relaxed);
    if (!condition) {
        std::fprintf(stderr, "FAIL: %s\n", message);
        std::abort();
    }
}

struct Released {
    Task action;
    ~Released() {
        action();
    }
};

Task owned_task(Task release, Task body = {}) {
    auto owner = std::shared_ptr<Released>(new Released{std::move(release)});
    return [owner = std::move(owner), body = std::move(body)] {
        (void)owner;
        if (body)
            body();
    };
}

void invalid_capacity() {
    bool rejected = false;
    try {
        SerialWorker worker(0);
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    check(rejected, "zero capacity rejected");
}

struct Publication {
    int value = 0;
    unsigned calls = 0;
};
void publish(void* raw) noexcept {
    auto& publication = *static_cast<Publication*>(raw);
    publication.value = 42;
    ++publication.calls;
}

void fifo_full_publication_and_allocations() {
    SerialWorker worker(8);
    std::latch active(1), release(1);
    std::vector<int> order;
    order.reserve(9);
    check(worker.submit([&] {
        active.count_down();
        release.wait();
        order.push_back(-1);
    }) == SubmitStatus::accepted,
          "blocker accepted");
    active.wait();
    std::array<Publication, 8> publications;
    for (std::size_t i = 0; i < publications.size(); ++i) {
        // Large capture forces std::function storage before tracking submit.
        std::array<int, 128> capture{};
        capture[0] = static_cast<int>(i);
        Task task = [&, i, capture] {
            check(publications[i].value == 42 && publications[i].calls == 1,
                  "publication visible before execution");
            order.push_back(capture[0]);
        };
        allocation_probe::count = 0;
        allocation_probe::enabled = true;
        const auto status = worker.submit(std::move(task), publish, &publications[i]);
        allocation_probe::enabled = false;
        check(status == SubmitStatus::accepted, "pending slot accepted");
        check(allocation_probe::count == 0, "admission allocates no queue storage");
    }
    Publication rejected;
    bool rejected_capture_released = false;
    Task overflow = owned_task([&] {
        rejected_capture_released = true;
        check(worker.submit([] {}) == SubmitStatus::full,
              "full rejection capture destruction is outside queue lock");
    });
    allocation_probe::count = 0;
    allocation_probe::enabled = true;
    const auto full = worker.submit(std::move(overflow), publish, &rejected);
    allocation_probe::enabled = false;
    check(full == SubmitStatus::full && rejected.calls == 0, "full does not publish");
    check(rejected_capture_released && allocation_probe::count == 0,
          "rejected capture released without queue allocation");
    worker.request_stop(StopMode::drain);
    check(worker.submit([] {}, publish, &rejected) == SubmitStatus::stopping && rejected.calls == 0,
          "stopping does not publish");
    release.count_down();
    check(worker.join(), "drain joined");
    check(order.size() == 9 && order.front() == -1, "all admitted tasks drained");
    for (std::size_t i = 0; i < 8; ++i)
        check(order[i + 1] == static_cast<int>(i), "FIFO across ring wrap");
    check(worker.join(), "repeated join succeeds");
    check(worker.failed_tasks() == 0, "ordinary tasks do not fail");
}

void cancel_release_and_join() {
    SerialWorker worker(3);
    std::latch active(1), release(1), joining(1);
    std::atomic<bool> active_released{false};
    std::atomic<unsigned> canceled_released{0}, executed{0};
    check(worker.submit(owned_task([&] { active_released = true; },
                                   [&] {
                                       active.count_down();
                                       release.wait();
                                       check(!worker.join(),
                                             "self-join rejected while external join waits");
                                   })) == SubmitStatus::accepted,
          "owned active accepted");
    active.wait();
    for (unsigned i = 0; i < 3; ++i) {
        check(worker.submit(owned_task(
                  [&] {
                      check(worker.submit([] {}) == SubmitStatus::stopping,
                            "canceled capture can reenter submit outside queue lock");
                      check(!worker.join(), "canceled capture self-join rejected");
                      ++canceled_released;
                  },
                  [&] { ++executed; })) == SubmitStatus::accepted,
              "cancel candidate accepted");
    }
    worker.request_stop(StopMode::drain);
    worker.request_stop(StopMode::cancel_pending);
    worker.request_stop(StopMode::drain); // Cannot downgrade cancellation.
    auto joined = std::async(std::launch::async, [&] {
        joining.count_down();
        const bool result = worker.join();
        check(active_released && canceled_released == 3,
              "join includes active and canceled capture destruction");
        return result;
    });
    joining.wait();
    check(joined.wait_for(25ms) == std::future_status::timeout, "join waits for active task");
    check(!active_released && canceled_released == 0, "active capture remains live");
    release.count_down();
    check(joined.get(), "external join succeeded");
    check(executed == 0 && canceled_released == 3,
          "cancel only discards queued tasks and stays sticky");
}

void exceptions_and_serialized_join() {
    SerialWorker worker(8);
    std::latch active(1), release(1), joiners_ready(4);
    std::atomic<unsigned> after{0};
    std::atomic<bool> released{false};
    check(worker.submit(owned_task([&] { released = true; },
                                   [&] {
                                       active.count_down();
                                       release.wait();
                                   })) == SubmitStatus::accepted,
          "join blocker accepted");
    active.wait();
    check(worker.submit([] { throw std::runtime_error("synthetic"); }) == SubmitStatus::accepted,
          "throwing standard task accepted");
    check(worker.submit([] { throw 7; }) == SubmitStatus::accepted,
          "throwing nonstandard task accepted");
    check(worker.submit(Task{}) == SubmitStatus::accepted, "empty task accepted");
    check(worker.submit([&] { ++after; }) == SubmitStatus::accepted, "later task accepted");
    worker.request_stop(StopMode::drain);
    std::array<std::future<bool>, 4> joiners;
    for (auto& joined : joiners)
        joined = std::async(std::launch::async, [&] {
            joiners_ready.count_down();
            const auto result = worker.join();
            check(released && after == 1, "every join observes completed captures and later task");
            return result;
        });
    joiners_ready.wait();
    release.count_down();
    for (auto& joined : joiners)
        check(joined.get(), "concurrent join serialized successfully");
    check(worker.failed_tasks() == 3, "all invocation exceptions counted and contained");
}

void completed_capture_reentry() {
    SerialWorker worker(1);
    std::latch released(1), followup(1);
    check(worker.submit(owned_task([&] {
        check(!worker.join(), "completed capture detects self-join");
        check(worker.submit([&] { followup.count_down(); }) == SubmitStatus::accepted,
              "completed capture may submit outside queue lock");
        released.count_down();
    })) == SubmitStatus::accepted,
          "completed capture probe accepted");
    released.wait();
    followup.wait();
    worker.request_stop(StopMode::drain);
    check(worker.join(), "reentrant followup joined");
}

struct CountPublication {
    std::atomic<unsigned>* published;
    std::atomic<bool>* first;
    std::latch* admitted;
};
void count_publication(void* raw) noexcept {
    auto& context = *static_cast<CountPublication*>(raw);
    ++*context.published;
    if (!context.first->exchange(true))
        context.admitted->count_down();
}

void concurrent_submit_stop() {
    SerialWorker worker(16);
    std::atomic<unsigned> accepted{0}, published{0}, executed{0}, rejected{0};
    std::atomic<bool> first{false};
    std::latch start(1), admitted(1);
    CountPublication publication{&published, &first, &admitted};
    std::array<std::thread, 4> producers;
    for (auto& producer : producers)
        producer = std::thread([&] {
            start.wait();
            for (unsigned i = 0; i < 1000; ++i) {
                const auto result =
                    worker.submit([&] { ++executed; }, count_publication, &publication);
                if (result == SubmitStatus::accepted)
                    ++accepted;
                else
                    ++rejected;
            }
        });
    start.count_down();
    admitted.wait();
    worker.request_stop(StopMode::drain);
    for (auto& producer : producers)
        producer.join();
    check(worker.join(), "concurrent producer workload joined");
    check(accepted != 0 && accepted + rejected == 4000, "all concurrent admissions classified");
    check(accepted == published && accepted == executed,
          "drain executes exactly all published admitted tasks during stop race");
    check(worker.submit([] {}) == SubmitStatus::stopping, "post-stop submission rejected");
}

void destructor_stops_and_joins() {
    auto worker = std::make_unique<SerialWorker>(1);
    std::latch active(1), release(1), destruction_started(1);
    std::atomic<unsigned> captures_released{0};
    check(worker->submit(owned_task([&] { ++captures_released; },
                                    [&] {
                                        active.count_down();
                                        release.wait();
                                    })) == SubmitStatus::accepted,
          "destructor active accepted");
    active.wait();
    auto destroying =
        std::async(std::launch::async, [owned = std::move(worker), &destruction_started]() mutable {
            destruction_started.count_down();
            owned.reset();
        });
    destruction_started.wait();
    check(destroying.wait_for(25ms) == std::future_status::timeout,
          "destructor waits for active task");
    release.count_down();
    destroying.get();
    check(captures_released == 1,
          "destructor stops worker and releases active capture before returning");
    // An idle worker also has to be stopped by its destructor, without a caller
    // first making an explicit stop request.
    {
        SerialWorker idle(1);
    }
}
} // namespace

int main() {
    invalid_capacity();
    fifo_full_publication_and_allocations();
    cancel_release_and_join();
    exceptions_and_serialized_join();
    completed_capture_reentry();
    concurrent_submit_stop();
    destructor_stops_and_joins();
    std::printf("SerialWorker: %u checks passed\n", checks.load());
}
