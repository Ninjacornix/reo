#include "queue.hpp"
#include <cstdio>
#include <cstdlib>
#include <new>
#include <stdexcept>

namespace { bool deny{}; unsigned allocations{}, checks{}; }
#if defined(__GNUC__)
__attribute__((noinline))
#endif
void* operator new(std::size_t bytes) {
    if (deny) { ++allocations; throw std::bad_alloc(); }
    if (auto* value = std::malloc(bytes ? bytes : 1)) return value;
    throw std::bad_alloc();
}
#if defined(__GNUC__)
__attribute__((noinline))
#endif
void release(void* value) noexcept { std::free(value); }
void operator delete(void* value) noexcept { release(value); }
void operator delete(void* value, std::size_t) noexcept { release(value); }
namespace q = reo::native::lsc_queue;
void check(bool value) { ++checks; if (!value) { std::fprintf(stderr, "Queue check %u failed\n", checks); std::abort(); } }
struct Ports final : q::LowerFile, q::EmptyNotification, q::Errors {
    q::Queue* queue{}; std::shared_ptr<const q::Name> next;
    bool available{true}, nested{}, enqueue_on_empty{};
    std::int32_t lower{}; unsigned errors{}, notifications{}, starts{}, closes{}, stops{};
    bool present() const noexcept override { return available; }
    void stop_before_open() noexcept override {}
    void close_before_open() noexcept override { ++closes; }
    void open_range(const q::Entry&) noexcept override {}
    void set_limit(std::uint32_t) noexcept override {}
    void thresholds(std::uint32_t, std::uint32_t) noexcept override {}
    void position(std::uint32_t) noexcept override {}
    void start() noexcept override { ++starts; }
    void stop_async() noexcept override { ++stops; }
    std::int32_t state() noexcept override { return lower; }
    std::uint32_t progress_sectors() noexcept override { return 7; }
    void report(q::Error) noexcept override { ++errors; }
    void notify() noexcept override {
        ++notifications;
        if (nested) check(queue->service() == q::Service::busy);
        if (enqueue_on_empty) check(queue->enqueue({next, {11, 0, 4}}) >= 0);
    }
};
int main() { try {
    std::string input = "first.adx"; auto first = q::Name::prepare(input); input[0] = 'X';
    check(first->bytes() == "first.adx");
    bool refused = false;
    try { (void)q::Name::prepare(std::string("a\0b", 3)); } catch (const std::invalid_argument&) { refused = true; }
    check(refused); refused = false;
    try { (void)q::Name::prepare(std::string(q::maximum_name_bytes + 1, 'x')); } catch (const std::invalid_argument&) { refused = true; }
    check(refused); check(q::Name::prepare(std::string(q::maximum_name_bytes, 'x'))->bytes().size() == q::maximum_name_bytes);
    auto second = q::Name::prepare("second.adx"); auto ports = std::make_shared<Ports>(); ports->next = second;
    for (const q::Config invalid : {q::Config{8192, 16, 0}, q::Config{8192, 0, 0x80000000}, q::Config{0x7fffffff, 0, 0}}) {
        refused = false; try { q::Queue queue(invalid, ports, ports, ports); } catch (const std::invalid_argument&) { refused = true; } check(refused);
    }
    q::Queue queue({}, ports, ports, ports); ports->queue = &queue;
    check(queue.snapshot().minimum == 6553);
    check(!queue.name(0) && queue.status(0) == 0 && queue.progress(0) == 0 && !ports->errors);
    std::weak_ptr<const q::Name> retained = first;
    deny = true;
    check(queue.enqueue({first, {3, 1, 5}}) == 1); first.reset();
    check(queue.enqueue({second, {4, 2, 6}}) == 2); queue.stop();
    check(queue.snapshot().count == 2); queue.start();
    check(queue.service() == q::Service::completed && ports->starts == 1);
    ports->lower = 2; check(queue.service() == q::Service::completed && queue.progress(1) == 7);
    ports->lower = 3; check(queue.service() == q::Service::completed && queue.status(1) == 2 && queue.progress(1) == 5 && ports->starts == 2);
    check(queue.service() == q::Service::completed && queue.snapshot().state == 1 && !queue.snapshot().count);
    check(!retained.expired() && queue.name(1)->bytes() == "first.adx");
    queue.stop();
    for (unsigned i = 0; i < q::slots; ++i) check(queue.enqueue({second, {}}) >= 0);
    check(retained.expired());
    const auto errors = ports->errors;
    check(queue.enqueue({nullptr, {}}) == -1 && ports->errors == errors && queue.snapshot().count == 16);
    queue.start(); queue.start(); check(!queue.snapshot().count && queue.snapshot().state == 1);
    check(queue.enqueue({second, {0, 0, 9}}) >= 0); queue.repeat(1); ports->nested = true; ports->enqueue_on_empty = true;
    check(queue.service() == q::Service::completed);
    for (unsigned i = 0; i < 64; ++i) check(queue.service() == q::Service::completed);
    check(ports->notifications >= 2 && queue.snapshot().count >= 1 && !queue.snapshot().servicing);
    queue.pause(257); check(!queue.snapshot().paused); queue.pause(1); check(queue.snapshot().paused == 1);
    const auto starts = ports->starts; check(queue.service() == q::Service::completed && starts == ports->starts);
    queue.repeat(256); check(!queue.snapshot().repeat); queue.stop();
    check(!queue.snapshot().state && !queue.snapshot().count && ports->stops >= 1);
    check(allocations == 0); deny = false;
    std::printf("%u LSC ownership checks; post-construction allocations=%u\n", checks, allocations);
} catch (const std::exception& e) { deny = false; std::fprintf(stderr, "%s\n", e.what()); return 1; } }
