#include "estimated_clock.hpp"
#include <array>
#include <cfenv>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>
#include <new>

namespace { bool deny{}; unsigned checks{}, allocations{}; }
__attribute__((noinline)) void* operator new(std::size_t size) {
    if (deny) { ++allocations; throw std::bad_alloc(); }
    if (auto* p = std::malloc(size ? size : 1)) return p;
    throw std::bad_alloc();
}
__attribute__((noinline)) void operator delete(void* p) noexcept { std::free(p); }
__attribute__((noinline)) void operator delete(void* p, std::size_t) noexcept { std::free(p); }
namespace c = reo::native::adxt_estimated_clock;
namespace {
void check(bool value, const char* message) { ++checks; if (!value) { std::fprintf(stderr, "FAILED: %s\n", message); std::exit(1); } }
auto observation() {
    c::integer::Observation o; o.state = 3; o.decoded = o.total = o.frequency = 1000; o.rna_free_bytes = 16384; return o;
}
struct Events {
    c::Clock* owner{}; c::integer::Observation input{};
    std::array<c::Event, 32> kinds{}; unsigned size{}; bool reentry{true};
    static void observe(void* context, c::Event event, c::Stream, const c::Shared&) noexcept {
        auto& self = *static_cast<Events*>(context);
        if (self.size < self.kinds.size()) self.kinds[self.size++] = event;
        self.reentry = self.reentry && self.owner->estimate(self.input, 100).status == c::Status::busy &&
            self.owner->pause(self.input, 1, 100) == c::Status::busy &&
            self.owner->discard_rebase(self.input, 100) == c::Status::busy;
    }
};
void controls() {
    auto o = observation(); c::Shared shared{{1, 1000, 0xffffffffu}, 1, 1, 0x12345678};
    Events events; events.input = o; c::Clock clock(shared, {940, 100, 0, 0}, {&events, Events::observe}); events.owner = &clock;
    deny = true;
    auto value = clock.estimate(o, 100);
    check(value.status == c::Status::completed && value.ratio == c::integer::Ratio{940, 1000}, "rebase publishes old estimate");
    check(shared.drift_bits == 0x42700001 && shared.mode.resynchronizations == 0 && clock.snapshot().estimate_base == 1000,
          "literal asymmetric drift and wrapping resynchronization count");
    check(clock.pause(o, 1, 101) == c::Status::completed && clock.snapshot().paused == 1 && clock.snapshot().rna_play == 0,
          "pause state and device intent remain distinct");
    const auto count = events.size; check(clock.pause(o, 1, 102) == c::Status::completed && events.size == count, "unchanged signed pause is no-op");
    check(clock.pause(o, 255, 150) == c::Status::completed && clock.snapshot().paused == 255 && clock.snapshot().rna_play == 1 &&
          clock.snapshot().tick_base == 150, "noncanonical byte still follows full argument resume branch");
    check(clock.pause(o, 255, 150) == c::Status::completed && events.size == count + 4, "255 does not equal sign-extended old byte minus1");
    check(clock.discard_rebase(o, 200) == c::Status::completed && clock.snapshot().tick_base == 200, "busy-only discard rebases");
    check(events.size >= 3 && events.kinds[events.size - 3] == c::Event::discard_diagnostic &&
          events.kinds[events.size - 2] == c::Event::critical_enter && events.kinds[events.size - 1] == c::Event::critical_leave && events.reentry,
          "diagnostic/critical order and reentry refusal");
    shared.service_busy = 0; const auto before = clock.snapshot(); const auto n = events.size;
    check(clock.discard_rebase(o, 300) == c::Status::unsupported_service && clock.snapshot() == before && events.size == n,
          "unowned worker profile refuses before diagnostic or state effects");
    shared.service_busy = 1;
    o.frequency = 0; const auto drift = shared.drift_bits;
    check(clock.estimate(o, 400).status == c::Status::zero_divisor && clock.snapshot() == before && shared.drift_bits == drift,
          "native zero divisor is explicit early refusal");
    shared.mode.selection = 0;
    check(clock.estimate(o, 400).ratio.denominator == 0, "integer raw mode preserves unused zero denominator");
    check(clock.centiseconds(o, 400).status == c::Status::zero_divisor, "centisecond conversion cannot divide raw zero denominator");
    o = observation(); o.rna_free_bytes = 16385;
    check(clock.estimate(o, 400).status == c::Status::invalid_queue, "invalid prepared queue cannot mutate clock");
    deny = false;
}
void environment_and_tick() {
    std::fenv_t environment{}; check(std::fegetenv(&environment) == 0, "save FP environment"); const auto csr = _mm_getcsr();
    auto o = observation(); c::Shared shared{{1,1000,17},0,1,123}; c::Clock clock(shared,{5,0xffffffffu,0,0});
    _mm_setcsr(0x1fa0); auto value = clock.estimate(o, 0);
    check(value.status == c::Status::completed && value.ratio.numerator == 105 && _mm_getcsr() == 0x1fa0, "tick wrap and caller accrued FP flags preserved");
    for (const auto mode : {0x3f80u,0x5f80u,0x7f80u,0x9f80u,0x1fc0u,0x1f00u}) {
        const auto before = clock.snapshot(); const auto drift = shared.drift_bits;
        _mm_setcsr(mode);
        check(clock.estimate(o, 1).status == c::Status::unsupported_fp && clock.snapshot() == before && shared.drift_bits == drift && _mm_getcsr() == mode,
              "unsupported FP mode refused without effects");
    }
    (void)std::fesetenv(&environment); _mm_setcsr(csr);
}
}
int main() {
    controls(); environment_and_tick(); check(allocations == 0, "clock transactions allocate nothing");
    std::printf("%u estimated clock checks passed; allocations=%u\n", checks, allocations);
}
