#include "resource_session.hpp"
#include "virtual_file_view.hpp"
#include "bounded_view.hpp"
#include "runtime/assets/virtual_afs.h"

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <fstream>
#include <future>
#include <iostream>
#include <mutex>
#include <new>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
std::atomic<bool> fail_next_allocation{false};
}
#if defined(_MSC_VER)
#define RESOURCE_TEST_NOINLINE __declspec(noinline)
#elif defined(__GNUC__) || defined(__clang__)
#define RESOURCE_TEST_NOINLINE __attribute__((noinline))
#else
#define RESOURCE_TEST_NOINLINE
#endif
RESOURCE_TEST_NOINLINE void* operator new(std::size_t bytes) {
    if (fail_next_allocation.exchange(false)) throw std::bad_alloc();
    if (auto* p = std::malloc(bytes == 0 ? 1 : bytes)) return p;
    throw std::bad_alloc();
}
RESOURCE_TEST_NOINLINE void operator delete(void* p) noexcept { std::free(p); }
RESOURCE_TEST_NOINLINE void operator delete(void* p, std::size_t) noexcept { std::free(p); }
RESOURCE_TEST_NOINLINE void* operator new[](std::size_t bytes) { return ::operator new(bytes); }
RESOURCE_TEST_NOINLINE void operator delete[](void* p) noexcept { ::operator delete(p); }
RESOURCE_TEST_NOINLINE void operator delete[](void* p, std::size_t) noexcept { ::operator delete(p); }
#undef RESOURCE_TEST_NOINLINE

using namespace reo::native::resources;
using namespace std::chrono_literals;

namespace {
void require(bool value, const char* expression, int line) {
    if (!value) throw std::runtime_error(std::string("line ") + std::to_string(line) + ": " + expression);
}
#define REQUIRE(...) require((__VA_ARGS__), #__VA_ARGS__, __LINE__)

class PatternView final : public ByteView {
public:
    explicit PatternView(std::uint64_t length = 100, std::byte value = std::byte{0x42})
        : length_(length), value_(value) {}
    std::uint64_t size() const noexcept override { return length_; }
    ReadResult read(std::uint64_t, std::span<std::byte> output) const override {
        std::fill(output.begin(), output.end(), value_);
        return {Status::ok, output.size()};
    }
private:
    std::uint64_t length_;
    std::byte value_;
};

class FailingView final : public ByteView {
public:
    explicit FailingView(int kind) : kind_(kind) {}
    std::uint64_t size() const noexcept override { return 100; }
    ReadResult read(std::uint64_t, std::span<std::byte> output) const override {
        std::fill(output.begin(), output.end(), std::byte{0xEE});
        if (kind_ == 0) return {Status::source_failure, output.size()};
        if (kind_ == 1) return {Status::ok, output.size() - 1};
        if (kind_ == 2) throw std::runtime_error("Synthetic source failure after writes");
        if (kind_ == 3) throw std::bad_alloc();
        if (kind_ == 4) return {Status::no_memory, 2};
        return {Status::invalid_range, 0}; // Provider errors cannot impersonate session admission.
    }
private:
    int kind_;
};

struct Files {
    std::filesystem::path directory;
    std::filesystem::path source;
    Files() {
        const auto root = std::filesystem::temp_directory_path();
        const auto stamp = std::chrono::steady_clock::now().time_since_epoch().count();
        for (unsigned index = 0; index < 1000; ++index) {
            auto candidate = root / ("reo-native-resource-test-" + std::to_string(stamp) + "-" + std::to_string(index));
            if (std::filesystem::create_directory(candidate)) { directory = candidate; break; }
        }
        if (directory.empty()) throw std::runtime_error("No private synthetic test directory");
#ifdef _WIN32
        source = directory / std::filesystem::path(L"source-\u010c-\u6e2c.bin");
#else
        source = directory / "source.bin";
#endif
        std::ofstream output(source, std::ios::binary);
        output.write("abcdefgh", 8);
        REQUIRE(bool(output));
    }
    ~Files() {
        // Only explicitly created file/directory; no recursive deletion.
        std::error_code ignored;
        std::filesystem::remove(source, ignored);
        std::filesystem::remove(directory, ignored);
    }
};

void frozen_virtual_view_and_cross_segment_reads() {
    Files files;
    auto source = std::make_shared<reo::assets::Source>(files.source);
    auto memory = std::make_shared<std::vector<std::uint8_t>>(std::initializer_list<std::uint8_t>{'X', 'Y', 'Z'});
    reo::assets::VirtualFile file{12, {{2, 3, 2, source, {}}, {8, 2, 0, {}, memory}}};
    const auto made = VirtualFileView::create(file);
    REQUIRE(made.status == Status::ok && made.view->size() == 12);
    // Caller-owned structures, buffers and source configuration may change after
    // snapshot creation without changing the mounted view. File bytes stay fixed.
    (*memory)[0] = 'Q';
    file.size = 1;
    file.segments.clear();
    source->size = 0;
    source->path = files.directory / "not-a-source";
    ResourceSession session;
    const auto opened = session.open(made.view);
    REQUIRE(opened.status == Status::ok);
    std::array<std::byte, 12> output;
    output.fill(std::byte{0xA5});
    REQUIRE(session.read_exact(opened.handle, 0, output) == ReadResult{Status::ok, 12});
    const std::array<std::byte, 12> expected{
        std::byte{0}, std::byte{0}, std::byte{'c'}, std::byte{'d'}, std::byte{'e'}, std::byte{0},
        std::byte{0}, std::byte{0}, std::byte{'X'}, std::byte{'Y'}, std::byte{0}, std::byte{0}};
    REQUIRE(output == expected);
    std::array<std::byte, 8> crossing;
    REQUIRE(session.read_exact(opened.handle, 3, crossing) == ReadResult{Status::ok, 8});
    REQUIRE(std::equal(crossing.begin(), crossing.end(), expected.begin() + 3));
    REQUIRE(session.size(opened.handle).bytes == 12);
}

void invalid_virtual_views_are_rejected() {
    auto bytes = std::make_shared<std::vector<std::uint8_t>>(8, 7);
    auto reject = [&](reo::assets::VirtualFile file) {
        const auto made = VirtualFileView::create(file);
        REQUIRE(made.status == Status::invalid_view && !made.view);
    };
    reject({10, {{0, 2, 0, {}, {}}}});
    reject({10, {{0, 9, 0, {}, bytes}}});
    reject({10, {{9, 2, 0, {}, bytes}}});
    reject({10, {{0, 2, 1, {}, bytes}}});
    reject({10, {{4, 2, 0, {}, bytes}, {1, 2, 0, {}, bytes}}});
    reject({10, {{1, 4, 0, {}, bytes}, {4, 2, 0, {}, bytes}}});
    reject({UINT64_MAX, {{UINT64_MAX, 1, 0, {}, bytes}}});
    Files files;
    auto source = std::make_shared<reo::assets::Source>(files.source);
    reject({10, {{0, 2, 0, source, bytes}}});
    reject({10, {{0, 3, 7, source, {}}}});
    reject({10, {{0, 1, UINT64_MAX, source, {}}}});
    source->size = 1; // Source metadata/file extent disagree at snapshot time.
    REQUIRE(VirtualFileView::create({1, {{0, 1, 0, source, {}}}}).status == Status::source_failure);
}

void exact_bounds_limits_and_sparse_edges() {
    ResourceSession session({16, 2, UINT64_MAX});
    const auto opened = session.open(std::make_shared<PatternView>());
    std::array<std::byte, 17> output;
    output.fill(std::byte{0xA5});
    const auto before = output;
    REQUIRE(session.read_exact(opened.handle, 0, output) == ReadResult{Status::read_limit, 0});
    REQUIRE(output == before);
    REQUIRE(session.read_exact(opened.handle, 99, std::span(output).first(2)) == ReadResult{Status::invalid_range, 0});
    REQUIRE(session.read_exact(opened.handle, UINT64_MAX, std::span(output).first(1)) == ReadResult{Status::invalid_range, 0});
    REQUIRE(output == before);
    REQUIRE(session.read_exact(opened.handle, 100, {}) == ReadResult{Status::ok, 0});
    REQUIRE(session.read_exact(opened.handle, 101, {}) == ReadResult{Status::invalid_range, 0});
    const auto sparse = VirtualFileView::create({UINT64_MAX, {}});
    REQUIRE(sparse.status == Status::ok);
    const auto sparse_handle = session.open(sparse.view);
    std::array<std::byte, 2> edge{std::byte{1}, std::byte{1}};
    REQUIRE(session.read_exact(sparse_handle.handle, UINT64_MAX - 2, edge) == ReadResult{Status::ok, 2});
    REQUIRE(edge == std::array<std::byte, 2>{});
    REQUIRE(session.read_exact(sparse_handle.handle, UINT64_MAX, std::span(edge).first(1)) == ReadResult{Status::invalid_range, 0});
}

void failures_do_not_publish_partial_bytes() {
    for (int kind = 0; kind < 6; ++kind) {
        ResourceSession session;
        const auto opened = session.open(std::make_shared<FailingView>(kind));
        std::array<std::byte, 8> output;
        output.fill(std::byte{0xA5});
        const auto expected = output;
        const auto result = session.read_exact(opened.handle, 0, output);
        REQUIRE(result == ReadResult{kind == 3 || kind == 4 ? Status::no_memory : Status::source_failure, 0});
        REQUIRE(output == expected);
        session.shutdown_and_drain();
    }
}

void allocation_failures_are_typed_and_transactional() {
    ResourceSession session;
    const auto provider = std::make_shared<PatternView>();
    fail_next_allocation = true;
    const auto failed_open = session.open(provider);
    fail_next_allocation = false;
    REQUIRE(failed_open.status == Status::no_memory);
    const auto opened = session.open(provider);
    REQUIRE(opened.status == Status::ok);
    std::array<std::byte, 8> output;
    output.fill(std::byte{0xA5});
    const auto before = output;
    fail_next_allocation = true;
    const auto result = session.read_exact(opened.handle, 0, output);
    fail_next_allocation = false;
    REQUIRE(result == ReadResult{Status::no_memory, 0} && output == before);
    session.shutdown_and_drain(); // Failed allocation released its active lease.
    reo::assets::VirtualFile empty;
    fail_next_allocation = true;
    const auto view = VirtualFileView::create(empty);
    fail_next_allocation = false;
    REQUIRE(view.status == Status::no_memory && !view.view);
}

void handles_reuse_retire_and_bind_to_the_session() {
    ResourceSession session({16, 1, 2});
    const auto provider = std::make_shared<PatternView>();
    const auto first = session.open(provider);
    REQUIRE(first.status == Status::ok && session.size(first.handle).bytes == 100);
    REQUIRE(session.open(provider).status == Status::capacity_exhausted);
    REQUIRE(session.close(first.handle) == Status::ok);
    REQUIRE(session.close(first.handle) == Status::invalid_handle);
    const auto second = session.open(provider);
    REQUIRE(second.status == Status::ok);
    REQUIRE(session.size(first.handle).status == Status::invalid_handle);
    ResourceSession other;
    REQUIRE(other.size(second.handle).status == Status::invalid_handle);
    REQUIRE(session.close(second.handle) == Status::ok);
    REQUIRE(session.open(provider).status == Status::capacity_exhausted); // Retired, never wrapped.
    REQUIRE(session.size(Handle{}).status == Status::invalid_handle);
    session.shutdown_and_drain();
    REQUIRE(session.open(provider).status == Status::session_closed);
    REQUIRE(session.open({}).status == Status::session_closed);
    REQUIRE(session.size(second.handle).status == Status::session_closed);
    REQUIRE(session.close(second.handle) == Status::session_closed);
    std::array<std::byte, 1> output{std::byte{0xA5}};
    REQUIRE(session.read_exact(second.handle, 0, output) == ReadResult{Status::session_closed, 0});
    REQUIRE(output[0] == std::byte{0xA5});
    session.shutdown_and_drain(); // Idempotent.
}

struct Gate {
    std::mutex mutex;
    std::condition_variable changed;
    bool started{};
    bool released{};
    std::atomic<bool> destroyed{};
    bool wait_started() {
        std::unique_lock lock(mutex);
        return changed.wait_for(lock, 3s, [&] { return started; });
    }
    void release() {
        std::lock_guard lock(mutex);
        released = true;
        changed.notify_all();
    }
};

class BlockingView final : public ByteView {
public:
    explicit BlockingView(std::shared_ptr<Gate> gate) : gate_(std::move(gate)) {}
    ~BlockingView() override { gate_->destroyed = true; }
    std::uint64_t size() const noexcept override { return 16; }
    ReadResult read(std::uint64_t, std::span<std::byte> output) const override {
        std::unique_lock lock(gate_->mutex);
        gate_->started = true;
        gate_->changed.notify_all();
        gate_->changed.wait(lock, [&] { return gate_->released; });
        std::fill(output.begin(), output.end(), std::byte{0x31});
        return {Status::ok, output.size()};
    }
private:
    std::shared_ptr<Gate> gate_;
};

struct ReleaseOnExit {
    std::shared_ptr<Gate> gate;
    ~ReleaseOnExit() { gate->release(); }
};

void close_and_reuse_during_inflight_read() {
    ResourceSession session({16, 1, UINT64_MAX});
    auto gate = std::make_shared<Gate>();
    auto provider = std::make_shared<BlockingView>(gate);
    std::weak_ptr<const ByteView> weak = provider;
    const auto opened = session.open(provider);
    std::array<std::byte, 8> output;
    auto reading = std::async(std::launch::async, [&] { return session.read_exact(opened.handle, 0, output); });
    ReleaseOnExit release{gate};
    REQUIRE(gate->wait_started());
    provider.reset();
    auto closing = std::async(std::launch::async, [&] { return session.close(opened.handle); });
    const bool closed_without_io = closing.wait_for(1s) == std::future_status::ready;
    if (!closed_without_io) gate->release();
    const auto close_status = closing.get();
    REQUIRE(closed_without_io && close_status == Status::ok);
    REQUIRE(!weak.expired() && !gate->destroyed);
    const auto replacement = session.open(std::make_shared<PatternView>(16, std::byte{0x77}));
    REQUIRE(replacement.status == Status::ok && session.size(opened.handle).status == Status::invalid_handle);
    std::array<std::byte, 1> newer;
    REQUIRE(session.read_exact(replacement.handle, 0, newer) == ReadResult{Status::ok, 1});
    REQUIRE(newer[0] == std::byte{0x77});
    gate->release();
    REQUIRE(reading.get() == ReadResult{Status::ok, 8});
    REQUIRE(std::all_of(output.begin(), output.end(), [](auto byte) { return byte == std::byte{0x31}; }));
    REQUIRE(weak.expired() && gate->destroyed);
}

void shutdown_and_drain_retain_the_active_provider() {
    ResourceSession session;
    auto gate = std::make_shared<Gate>();
    auto provider = std::make_shared<BlockingView>(gate);
    std::weak_ptr<const ByteView> weak = provider;
    const auto opened = session.open(provider);
    std::array<std::byte, 8> output;
    auto reading = std::async(std::launch::async, [&] { return session.read_exact(opened.handle, 0, output); });
    ReleaseOnExit release{gate};
    REQUIRE(gate->wait_started());
    provider.reset();
    auto shutting = std::async(std::launch::async, [&] { session.shutdown(); });
    const bool stopped_without_io = shutting.wait_for(1s) == std::future_status::ready;
    if (!stopped_without_io) gate->release();
    shutting.get();
    REQUIRE(stopped_without_io && !weak.expired());
    REQUIRE(session.size(opened.handle).status == Status::session_closed);
    auto draining = std::async(std::launch::async, [&] { session.drain(); });
    const bool waited = draining.wait_for(30ms) == std::future_status::timeout;
    gate->release();
    REQUIRE(reading.get() == ReadResult{Status::ok, 8});
    draining.get();
    REQUIRE(waited && weak.expired() && gate->destroyed);
}

class OffsetView final : public ByteView {
public:
    std::uint64_t size() const noexcept override { return UINT64_MAX; }
    ReadResult read(std::uint64_t offset, std::span<std::byte> output) const override {
        for (std::size_t i = 0; i < output.size(); ++i) output[i] = std::byte((offset + i) & 255);
        return {Status::ok, output.size()};
    }
};

void bounded_views_retain_parent_and_validate_composed_ranges() {
    auto parent = std::make_shared<OffsetView>();
    std::weak_ptr<const ByteView> weak = parent;
    auto first = bounded_view(parent, UINT64_MAX - 100, 100);
    REQUIRE(first.status == Status::ok && first.view->size() == 100);
    auto nested = bounded_view(first.view, 90, 10);
    REQUIRE(nested.status == Status::ok);
    REQUIRE(bounded_view(first.view, 101, 0).status == Status::invalid_range);
    REQUIRE(bounded_view(first.view, 90, 11).status == Status::invalid_range);
    REQUIRE(bounded_view(parent, UINT64_MAX, 1).status == Status::invalid_range);
    REQUIRE(bounded_view({}, 0, 0).status == Status::invalid_view);
    auto empty = bounded_view(parent, UINT64_MAX, 0);
    REQUIRE(empty.status == Status::ok && empty.view->read(0, {}) == ReadResult{Status::ok, 0});
    fail_next_allocation = true;
    REQUIRE(bounded_view(parent, 0, 1).status == Status::no_memory);
    REQUIRE(!fail_next_allocation);
    first.view.reset();
    parent.reset();
    REQUIRE(!weak.expired());
    ResourceSession session;
    const auto opened = session.open(nested.view);
    std::array<std::byte, 10> output{};
    REQUIRE(session.read_exact(opened.handle, 0, output) == ReadResult{Status::ok, 10});
    for (unsigned i = 0; i < output.size(); ++i)
        REQUIRE(output[i] == std::byte((UINT64_MAX - 10 + i) & 255));
    output.fill(std::byte{0xCC});
    REQUIRE(nested.view->read(1, output) == ReadResult{Status::invalid_range, 0});
    REQUIRE(std::all_of(output.begin(), output.end(), [](auto b) { return b == std::byte{0xCC}; }));
    REQUIRE(session.read_exact(opened.handle, 10, {}) == ReadResult{Status::ok, 0});
    nested.view.reset();
    REQUIRE(session.close(opened.handle) == Status::ok);
    // The independently retained empty view still owns the same parent.
    REQUIRE(!weak.expired());
    empty.view.reset();
    REQUIRE(weak.expired());
}
} // namespace

int main() {
    try {
        frozen_virtual_view_and_cross_segment_reads();
        invalid_virtual_views_are_rejected();
        exact_bounds_limits_and_sparse_edges();
        failures_do_not_publish_partial_bytes();
        allocation_failures_are_typed_and_transactional();
        handles_reuse_retire_and_bind_to_the_session();
        close_and_reuse_during_inflight_read();
        shutdown_and_drain_retain_the_active_provider();
        bounded_views_retain_parent_and_validate_composed_ranges();
        std::cout << "Native resources: 9 focused contract groups passed; synthetic providers/files only\n";
        return 0;
    } catch (const std::exception& error) {
        fail_next_allocation = false;
        std::cerr << "Native resource test failure: " << error.what() << '\n';
        return 1;
    }
}
