#include "sjuni.hpp"

#include <cstdlib>
#include <functional>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
std::size_t allocations = 0;
bool record_allocations = false;
}

// Keep replacement allocation boundaries visible to GCC's pairing analysis.
// Inlining delete's malloc-backed implementation into standard containers can
// otherwise produce a spurious mismatched-new-delete warning at -O1.
#if defined(_MSC_VER)
#define SJUNI_TEST_NOINLINE __declspec(noinline)
#elif defined(__GNUC__) || defined(__clang__)
#define SJUNI_TEST_NOINLINE __attribute__((noinline))
#else
#define SJUNI_TEST_NOINLINE
#endif

SJUNI_TEST_NOINLINE void* operator new(std::size_t bytes) {
    if (record_allocations) ++allocations;
    if (auto* value = std::malloc(bytes == 0 ? 1 : bytes)) return value;
    throw std::bad_alloc();
}
SJUNI_TEST_NOINLINE void operator delete(void* value) noexcept { std::free(value); }
SJUNI_TEST_NOINLINE void operator delete(void* value, std::size_t) noexcept { std::free(value); }
SJUNI_TEST_NOINLINE void* operator new[](std::size_t bytes) { return ::operator new(bytes); }
SJUNI_TEST_NOINLINE void operator delete[](void* value) noexcept { ::operator delete(value); }
SJUNI_TEST_NOINLINE void operator delete[](void* value, std::size_t) noexcept { ::operator delete(value); }
#undef SJUNI_TEST_NOINLINE

using namespace reo::native::sjuni;

namespace {
void require(bool condition, const char* expression, int line) {
    if (!condition) throw std::runtime_error(std::string("line ") + std::to_string(line) + ": " + expression);
}
#define REQUIRE(...) require((__VA_ARGS__), #__VA_ARGS__, __LINE__)
#define OK(...) REQUIRE((__VA_ARGS__) == Result::completed)

struct Trace {
    Pool* pool{};
    std::vector<std::string> events;
    std::function<void()> on_enter;
    std::function<void()> on_leave;
    std::function<void()> on_error;
    Hooks hooks() {
        return {this,
            [](void* context) {
                auto& self = *static_cast<Trace*>(context);
                self.events.emplace_back("enter");
                auto action = self.on_enter;
                if (action) action();
            },
            [](void* context) {
                auto& self = *static_cast<Trace*>(context);
                self.events.emplace_back("leave");
                auto action = self.on_leave;
                if (action) action();
            },
            [](void* context, std::int32_t code) {
                REQUIRE(code == -3);
                auto& self = *static_cast<Trace*>(context);
                self.events.emplace_back("error");
                auto action = self.on_error;
                if (action) action();
            }};
    }
};

void topology_and_lifetime() {
    Pool pool(4);
    REQUIRE(pool.free_nodes() == 4 && pool.free_head() == 0);
    auto initial = pool.snapshot();
    for (NodeId i = 0; i < 4; ++i) {
        REQUIRE(initial.nodes[i].next == (i == 3 ? no_node : i + 1));
        REQUIRE(initial.nodes[i].span == Span{});
    }
    for (std::uint32_t q = 0; q < 4; ++q) OK(pool.put(q, Span{q + 1, 100, 10}));
    REQUIRE(pool.free_nodes() == 0);
    for (std::uint32_t q = 0; q < 4; ++q) {
        REQUIRE(pool.heads()[q] == q);
        REQUIRE(pool.queued_bytes(q) == 10);
    }
    Span result;
    OK(pool.get(1, 1000, result));
    REQUIRE(result == Span{2, 100, 10});
    REQUIRE(pool.free_head() == 1);
    REQUIRE(pool.nodes()[1].span == result); // Stale borrowed descriptor retained.
    OK(pool.get(3, 10, result));
    REQUIRE(pool.free_head() == 3 && pool.nodes()[3].next == 1);
    OK(pool.put(1, Span{12, 20, 6}));
    REQUIRE(pool.heads()[1] == 3 && pool.free_head() == 1); // Free list is LIFO.
    pool.reset();
    REQUIRE(pool.snapshot() == initial);
}

void split_zero_negative_and_modes() {
    Pool pool(2);
    OK(pool.put(0, Span{1, 100, 16}));
    Span out;
    OK(pool.get(0, 6, out));
    REQUIRE(out == Span{1, 100, 6});
    REQUIRE(pool.nodes()[0].span == Span{1, 106, 10});
    const auto before = pool.snapshot();
    OK(pool.get(0, 0, out));
    REQUIRE(out == Span{1, 106, 0});
    REQUIRE(pool.snapshot() == before);
    OK(pool.get(0, -2, out));
    REQUIRE(out == Span{1, 106, -2});
    REQUIRE(pool.nodes()[0].span == Span{1, 104, 12});
    REQUIRE(pool.free_nodes() == 1);
    std::int32_t length = -1;
    REQUIRE(pool.head_availability(0, -100, length) && length == 12);
    REQUIRE(!pool.head_availability(0, 13, length) && length == 12);
    OK(pool.get(0, 100, out));
    REQUIRE(out == Span{1, 104, 12});
    OK(pool.get(0, 0, out));
    REQUIRE(out == Span{}); // Empty differs from nonempty zero-size split.
    for (std::uint8_t mode : {0, 2, 255}) {
        Pool nonsplitting(1, mode);
        OK(nonsplitting.put(0, Span{1, 10, 8}));
        const auto stable = nonsplitting.snapshot();
        OK(nonsplitting.get(0, -1, out));
        REQUIRE(out == Span{} && nonsplitting.snapshot() == stable);
        OK(nonsplitting.get(0, 7, out));
        REQUIRE(out == Span{} && nonsplitting.snapshot() == stable);
        REQUIRE(nonsplitting.head_availability(0, 8, length) && length == 8);
        REQUIRE(!nonsplitting.head_availability(0, 9, length) && length == 8);
        OK(nonsplitting.get(0, 9, out));
        REQUIRE(out == Span{1, 10, 8});
    }
}

void merge_and_region_identity() {
    Trace trace;
    Pool pool(1, 1, trace.hooks());
    trace.pool = &pool;
    OK(pool.put(0, Span{4, 100, 10}));
    OK(pool.put(0, Span{4, 110, 5})); // Can merge with no free nodes.
    OK(pool.unget(0, Span{4, 90, 10}));
    REQUIRE(pool.nodes()[0].span == Span{4, 90, 25});
    trace.events.clear();
    OK(pool.put(0, Span{5, 115, 8})); // Numerically adjacent, different region.
    REQUIRE(trace.events == std::vector<std::string>{"enter", "error", "leave"});
    REQUIRE(pool.nodes()[0].span == Span{4, 90, 25});
    trace.events.clear();
    OK(pool.unget(0, Span{5, 80, 10}));
    REQUIRE(trace.events == std::vector<std::string>{"enter", "error", "leave"});
}

void error_output_and_admission_order() {
    Trace trace;
    Pool pool(2, 1, trace.hooks());
    trace.pool = &pool;
    Span output{8, 30, 17};
    trace.on_error = [&] { REQUIRE(output == Span{8, 30, 17}); };
    OK(pool.get(UINT32_MAX, 1, output));
    REQUIRE(output == Span{});
    REQUIRE(trace.events == std::vector<std::string>{"error"});
    trace.events.clear();
    std::int32_t available = 99;
    trace.on_error = [&] { REQUIRE(available == 0); available = 77; };
    REQUIRE(!pool.head_availability(4, 1, available));
    REQUIRE(available == 77); // Invalid availability does not clear again after callback.
    trace.on_error = {};
    trace.events.clear();
    OK(pool.put(4, Span{1, INT64_MAX, INT32_MAX})); // Selector first, even bad arithmetic.
    OK(pool.unget(9, Span{}));
    REQUIRE(trace.events == std::vector<std::string>{"error", "error"});
    trace.events.clear();
    OK(pool.put(0, Span{0, INT64_MAX, 5}));
    OK(pool.put(0, Span{1, INT64_MAX, 0}));
    OK(pool.unget(0, Span{1, INT64_MAX, -1}));
    REQUIRE(trace.events.empty());
    OK(pool.get(0, 10, output)); // Valid empty path does enter/leave.
    REQUIRE(trace.events == std::vector<std::string>{"enter", "leave"});
    trace.events.clear();
    REQUIRE(pool.queued_bytes(4) == 0);
    REQUIRE(trace.events == std::vector<std::string>{"error"});
    std::uint32_t count = 61;
    trace.events.clear();
    REQUIRE(pool.queued_nodes(4, count) == Result::unsupported_selector && count == 61);
    REQUIRE(trace.events.empty()); // Original unchecked count is an admission boundary.
}

void reentry_without_retry() {
    Trace trace;
    Pool pool(1, 1, trace.hooks());
    trace.pool = &pool;
    OK(pool.put(0, Span{1, 0, 10}));
    trace.events.clear();
    Span taken;
    trace.on_error = [&] { OK(pool.get(0, 10, taken)); };
    OK(pool.put(1, Span{2, 20, 5}));
    REQUIRE(trace.events == std::vector<std::string>{"enter", "error", "enter", "leave", "leave"});
    REQUIRE(taken == Span{1, 0, 10});
    REQUIRE(pool.heads()[1] == no_node && pool.free_nodes() == 1); // No retry.
    OK(pool.put(0, Span{1, 0, 10}));
    trace.events.clear();
    trace.on_error = [&] {
        auto image = pool.snapshot();
        image.heads[0] = no_node;
        image.heads[2] = 0;
        image.nodes[0].span = Span{6, 55, 9};
        OK(pool.import_state(image));
    };
    OK(pool.unget(1, Span{8, 1, 2}));
    REQUIRE(pool.heads()[1] == no_node && pool.heads()[2] == 0);
    REQUIRE(pool.nodes()[0].span == Span{6, 55, 9});
    REQUIRE(trace.events == std::vector<std::string>{"enter", "error", "leave"});
}

void import_roundtrip_and_rejection() {
    Pool pool(3);
    auto state = pool.snapshot();
    state.mode = 255;
    state.free_head = 2;
    state.heads[3] = 1;
    state.nodes[1] = Node{no_node, Span{7, -50, 8}};
    state.nodes[2] = Node{0, Span{0, INT64_MIN, INT32_MIN}}; // Arbitrary stale descriptor.
    state.nodes[0].next = no_node;
    OK(pool.import_state(state));
    REQUIRE(pool.snapshot() == state);
    auto reject = [&](Snapshot bad, Result expected = Result::unsupported_state) {
        REQUIRE(pool.import_state(bad) == expected);
        REQUIRE(pool.snapshot() == state);
    };
    auto bad = state;
    bad.nodes[0].next = 2; // Cycle.
    reject(bad);
    bad = state; bad.heads[0] = 0; reject(bad); // Same node in two lists.
    bad = state; bad.nodes[2].next = no_node; reject(bad); // Unreachable node.
    bad = state; bad.nodes[0].next = 3; reject(bad); // Invalid ID.
    bad = state; bad.nodes[1].span.bytes = 0; reject(bad);
    bad = state; bad.nodes[1].span.region = 0; reject(bad);
    bad = state; bad.nodes[1].span.offset = INT64_MAX; reject(bad, Result::unsupported_arithmetic);
    bad = state; bad.nodes.pop_back(); reject(bad, Result::capacity_mismatch);
    std::uint32_t count;
    OK(pool.queued_nodes(3, count)); REQUIRE(count == 1 && pool.free_nodes() == 2);
}

void unsupported_is_side_effect_free() {
    Trace trace;
    Pool pool(2, 1, trace.hooks());
    Span output{19, 13, 17};
    OK(pool.put(0, Span{1, 0, INT32_MAX}));
    trace.events.clear();
    auto stable = pool.snapshot();
    REQUIRE(pool.check_get(0, -1) == Result::unsupported_arithmetic);
    REQUIRE(pool.get(0, -1, output) == Result::unsupported_arithmetic);
    REQUIRE(output == Span{19, 13, 17});
    REQUIRE(pool.put(0, Span{1, INT32_MAX, 1}) == Result::unsupported_arithmetic);
    REQUIRE(pool.unget(0, Span{1, -1, 1}) == Result::unsupported_arithmetic);
    REQUIRE(pool.put(1, Span{1, INT64_MAX, 1}) == Result::unsupported_arithmetic);
    REQUIRE(pool.snapshot() == stable && trace.events.empty());
    pool.reset();
    OK(pool.put(0, Span{1, INT64_MIN, 2}));
    trace.events.clear();
    stable = pool.snapshot();
    REQUIRE(pool.get(0, -1, output) == Result::unsupported_arithmetic);
    REQUIRE(pool.snapshot() == stable && trace.events.empty());
}

void enter_reread_and_contract_violation() {
    Trace trace;
    Pool pool(1, 1, trace.hooks());
    Span incoming{1, 5, 3};
    trace.on_enter = [&] { incoming = Span{8, 100, 7}; };
    OK(pool.put(0, incoming));
    REQUIRE(pool.nodes()[0].span == incoming);
    pool.reset();
    trace.events.clear();
    trace.on_enter = [&] { incoming = Span{1, INT64_MAX, 1}; };
    REQUIRE(pool.put(0, incoming) == Result::callback_contract_violation);
    REQUIRE(pool.free_nodes() == 1 && pool.heads()[0] == no_node);
    REQUIRE(trace.events == std::vector<std::string>{"enter", "leave"});
    trace.on_enter = {};
    OK(pool.put(0, Span{1, 0, 10}));
    trace.events.clear();
    Span output{7, 1, 2};
    trace.on_enter = [&] {
        auto changed = pool.snapshot();
        changed.nodes[0].span.bytes = INT32_MAX;
        OK(pool.import_state(changed));
    };
    REQUIRE(pool.get(0, -1, output) == Result::callback_contract_violation);
    REQUIRE(output == Span{7, 1, 2});
    REQUIRE(pool.nodes()[0].span.bytes == INT32_MAX); // Hook mutation remains: no safe fallback.
    REQUIRE(trace.events == std::vector<std::string>{"enter", "leave"});
}

void leave_reentry_and_wrapped_queries() {
    Trace trace;
    Pool pool(2, 1, trace.hooks());
    OK(pool.put(0, Span{1, 0, INT32_MAX}));
    OK(pool.put(0, Span{2, 0, INT32_MAX}));
    trace.events.clear();
    REQUIRE(pool.queued_bytes(0) == -2);
    std::uint32_t count;
    OK(pool.queued_nodes(0, count)); REQUIRE(count == 2);
    std::int32_t length;
    REQUIRE(pool.head_availability(0, 1, length));
    REQUIRE(length == INT32_MAX && trace.events.empty()); // Queries have no guard.
    bool once = true;
    trace.on_leave = [&] { if (once) { once = false; pool.reset(); } };
    Span out;
    OK(pool.get(0, INT32_MAX, out));
    REQUIRE(out == Span{1, 0, INT32_MAX});
    REQUIRE(pool.free_nodes() == 2 && pool.heads()[0] == no_node);
}

void queue_operations_do_not_allocate() {
    Pool pool(16);
    auto image = pool.snapshot();
    Span out;
    allocations = 0;
    record_allocations = true;
    bool correct = true;
    for (int i = 0; i < 10000; ++i) {
        correct &= pool.put(0, Span{1, 0, 10}) == Result::completed;
        correct &= pool.get(0, -1, out) == Result::completed;
        correct &= pool.get(0, 11, out) == Result::completed;
        correct &= pool.import_state(image) == Result::completed;
        pool.reset();
    }
    record_allocations = false;
    REQUIRE(correct && allocations == 0);
}
} // namespace

int main() {
    try {
        topology_and_lifetime();
        split_zero_negative_and_modes();
        merge_and_region_identity();
        error_output_and_admission_order();
        reentry_without_retry();
        import_roundtrip_and_rejection();
        unsupported_is_side_effect_free();
        enter_reread_and_contract_violation();
        leave_reentry_and_wrapped_queries();
        queue_operations_do_not_allocate();
        bool rejected = false;
        try { Pool invalid(0); } catch (const std::invalid_argument&) { rejected = true; }
        REQUIRE(rejected);
        std::cout << "SJUNI: 11 focused synthetic contract groups passed; no original-execution parity claimed\n";
        return 0;
    } catch (const std::exception& error) {
        record_allocations = false;
        std::cerr << "SJUNI test failure: " << error.what() << '\n';
        return 1;
    }
}
