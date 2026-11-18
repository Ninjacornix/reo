#include "stream_window.hpp"
#include <vector>
#include <condition_variable>
#include <chrono>
#include <mutex>
#include <thread>
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <new>
#include <source_location>
#include <string_view>
#include <utility>
#include <cfenv>
#include <immintrin.h>
#include <stdexcept>

namespace {
thread_local bool deny{};
thread_local int fail_after{-1};
unsigned attempts{}, checks{};
void admit_allocation() {
    if (deny) { ++attempts; throw std::bad_alloc(); }
    if (fail_after == 0) throw std::bad_alloc();
    if (fail_after > 0) --fail_after;
}
}
#if defined(__GNUC__)
#define NOINLINE __attribute__((noinline))
#else
#define NOINLINE __declspec(noinline)
#endif
NOINLINE void* operator new(std::size_t n) {
    admit_allocation();
    if (auto* p = std::malloc(n ? n : 1)) return p;
    throw std::bad_alloc();
}
NOINLINE void operator delete(void* p) noexcept { std::free(p); }
NOINLINE void operator delete(void* p, std::size_t) noexcept { std::free(p); }
NOINLINE void* operator new[](std::size_t n) { return ::operator new(n); }
NOINLINE void operator delete[](void* p) noexcept { ::operator delete(p); }
NOINLINE void operator delete[](void* p, std::size_t) noexcept { ::operator delete(p); }
NOINLINE void* operator new(std::size_t n, std::align_val_t value) {
    admit_allocation();
    const auto a = static_cast<std::size_t>(value);
    if (n > std::numeric_limits<std::size_t>::max() - a - sizeof(void*)) throw std::bad_alloc();
    auto* raw = std::malloc(n + a + sizeof(void*));
    if (!raw) throw std::bad_alloc();
    const auto address = (reinterpret_cast<std::uintptr_t>(raw) + sizeof(void*) + a - 1) & ~(a - 1);
    auto* result = reinterpret_cast<void*>(address); reinterpret_cast<void**>(result)[-1] = raw; return result;
}
NOINLINE void operator delete(void* p, std::align_val_t) noexcept { if (p) std::free(reinterpret_cast<void**>(p)[-1]); }
NOINLINE void operator delete(void* p, std::size_t, std::align_val_t a) noexcept { ::operator delete(p, a); }
NOINLINE void* operator new[](std::size_t n, std::align_val_t a) { return ::operator new(n, a); }
NOINLINE void operator delete[](void* p, std::align_val_t a) noexcept { ::operator delete(p, a); }
NOINLINE void operator delete[](void* p, std::size_t, std::align_val_t a) noexcept { ::operator delete(p, a); }

namespace w = reo::native::adx_window::v2;
namespace s = reo::native::adxt_shared_source;
namespace a = reo::native::adxt_refill;
namespace r = reo::native::resources;
namespace {
void check(bool c, const char* message) { ++checks; if (!c) { std::fprintf(stderr, "FAILED: %s\n", message); std::exit(1); } }
void good(w::Status status, const std::source_location at = std::source_location::current()) {
    if (status != w::Status::completed) std::fprintf(stderr, "Window2 status=%d at line%u\n", static_cast<int>(status), at.line());
    check(status == w::Status::completed, "completed Window2 operation");
}
struct View final : r::ByteView {
    std::vector<std::uint8_t> bytes;
    explicit View(std::vector<std::uint8_t> data) : bytes(std::move(data)) {}
    std::uint64_t size() const noexcept override { return bytes.size(); }
    r::ReadResult read(std::uint64_t at, std::span<std::byte> out) const override {
        if (at > bytes.size() || out.size() > bytes.size() - at) return {r::Status::invalid_range, 0};
        for (std::size_t i = 0; i < out.size(); ++i) out[i] = std::byte(bytes[static_cast<std::size_t>(at) + i]);
        return {r::Status::ok, out.size()};
    }
};
struct Backend final : s::Backend {
    std::shared_ptr<const r::ByteView> view;
    std::vector<std::byte> result;
    std::uint64_t offset{}, id{}; std::uint32_t sectors{};
    bool pending{}, ready{}, joined{}, failed{}, wrong_id{}; unsigned submissions{};
    a::Acceptance submit(std::shared_ptr<const r::ByteView> v, std::uint64_t at, std::uint32_t n, std::uint64_t token) noexcept override {
        ++submissions; if (pending) return {0, true};
        view = std::move(v); offset = at; id = token; sectors = n; pending = n > 0; return {static_cast<std::int32_t>(n), false};
    }
    void complete() {
        if (!pending) return;
        result.resize(static_cast<std::size_t>(sectors) * 2048);
        check(view->read(offset, result).status == r::Status::ok, "provider exact private completion"); ready = true;
    }
    a::Completion poll() noexcept override {
        if (!pending) return {};
        if (!ready) return {a::BackendState::pending, id, {}};
        pending = ready = false; view.reset();
        if (failed) { result.clear(); return {a::BackendState::error, id, {}}; }
        return {a::BackendState::complete, id + (wrong_id ? 1 : 0), std::move(result)};
    }
    bool shutdown_and_join() noexcept override { if (pending) return false; joined = true; return true; }
};
void be16(std::vector<std::uint8_t>& v, std::size_t at, std::uint16_t n) { v[at] = static_cast<std::uint8_t>(n >> 8); v[at + 1] = static_cast<std::uint8_t>(n); }
void be32(std::vector<std::uint8_t>& v, std::size_t at, std::uint32_t n) {
    for (unsigned i = 0; i < 4; ++i) v[at + i] = static_cast<std::uint8_t>(n >> (24 - i * 8));
}
std::vector<std::uint8_t> file(unsigned channels, unsigned rate, unsigned total) {
    const auto blocks = (total + 31) / 32 * channels;
    std::vector<std::uint8_t> data(((96 + blocks * 18 + 2047) / 2048) * 2048);
    be16(data, 0, 0x8000); be16(data, 2, 92); data[4] = 3; data[5] = 18; data[6] = 4;
    data[7] = static_cast<std::uint8_t>(channels); be32(data, 8, rate); be32(data, 12, total); be16(data, 16, 500); data[18] = 3;
    for (unsigned b = 0; b < blocks; ++b) {
        const auto at = 96 + b * 18; data[at] = 0; data[at + 1] = 3;
        std::fill_n(data.begin() + at + 2, 16, static_cast<std::uint8_t>(0x11 + b % 7));
    }
    return data;
}
struct Observer {
    w::StreamWindowOwner* owner{}; unsigned guards{}, credit_boundaries{}, publications{};
    bool reentry{true}, order{true};
    static void guard(void* context, std::uint32_t ring, bool entering) noexcept {
        auto& o = *static_cast<Observer*>(context); ++o.guards;
        if (!o.owner) return;
        o.reentry = o.reentry && o.owner->stop_decode() == w::Status::busy &&
            o.owner->borrow_pcm(0).status == w::pcm::Status::busy;
        const auto state = o.owner->snapshot();
        if (ring == 0 && !entering && state.phase == w::Phase::encoded_credit) {
            ++o.credit_boundaries;
            o.order = o.order && state.pcm.phase == w::pcm::Phase::staged && state.pcm_write_held;
            std::array<std::uint8_t, w::pcm::capacity + w::pcm::extension> bytes{};
            o.order = o.order && o.owner->read_pcm_backing(0, bytes) == w::Status::completed;
            if (state.engine.produced_samples) o.order = o.order && bytes[static_cast<std::size_t>(state.outer.pcm_grants[0].offset)] != 0xa5;
        }
    }
    static void publication(void* context, std::uint32_t, const w::pcm::View&, const w::Snapshot& state) noexcept {
        auto& o = *static_cast<Observer*>(context); ++o.publications;
        o.order = o.order && !state.source_batch_held && state.phase == w::Phase::pcm_credit;
    }
};
struct Fixture {
    std::shared_ptr<View> view; Backend* backend{}; Observer observer;
    std::shared_ptr<reo::native::adx_header::KeyContext> keys = std::make_shared<reo::native::adx_header::KeyContext>();
    std::unique_ptr<w::StreamWindowOwner> owner;
    Fixture(unsigned channels, unsigned rate, unsigned total, bool downmix = false, int pcm_queued = 0,
            std::vector<std::uint8_t> custom = {}, bool seamless = false, int source_cursor = 0, std::size_t seed_limit = 8192, int retries = 2) {
        view = std::make_shared<View>(custom.empty() ? file(channels, rate, total) : std::move(custom));
        auto implementation = std::make_unique<Backend>(); backend = implementation.get();
        w::Config c; c.channels = channels; c.downmix = downmix; c.seamless_enabled = seamless;
        c.source_config.byte_length = static_cast<std::int32_t>(view->size());
        c.source_config.threshold = 8192; c.source_config.maximum_request_bytes = 8192; c.source_config.maximum_sectors = 4;
        c.source_config.retry_limit = retries;
        const auto seeded = std::min(seed_limit, view->bytes.size());
        owner = std::make_unique<w::StreamWindowOwner>(c, view, std::move(implementation), keys,
            w::Hooks{&observer, Observer::guard, {}, Observer::publication, {}},
            w::Bootstrap{{source_cursor, static_cast<std::int32_t>(seeded / 2048), std::span(view->bytes).first(seeded)}, 0, pcm_queued});
        observer.owner = owner.get();
    }
    void refill() {
        deny = false; backend->complete();
        deny = true; check(owner->service_source().status == s::Status::completed, "complete separately scheduled source service");
    }
    void drain() {
        while (owner->snapshot().pcm.rings[0].data) {
            auto read = owner->borrow_pcm(w::pcm::capacity); check(read.status == w::pcm::Status::completed, "PCM drain lease"); good(owner->finish_pcm(read.lease));
        }
    }
    void retire() {
        const bool previous_denial = deny;
        good(owner->stop_decode()); drain();
        for (unsigned i = 0; i < 8; ++i) {
            deny = false; backend->complete(); deny = true;
            const auto result = owner->retire_on_control_thread();
            if (result == w::Status::completed) { check(backend->joined, "actual backend fence observed"); deny = previous_denial; return; }
            check(result == w::Status::retirement_pending, "retirement pending without invented fence");
        }
        check(false, "retirement makes bounded progress");
    }
};
void finite_and_identity() {
    Fixture f(2, 44100, 33, false, 16288); Fixture other(1, 44100, 1000);
    deny = true;
    good(f.owner->service_header()); good(f.owner->configure_ready());
    const auto request = f.owner->request();
    check(f.owner->service_decode(other.owner->request()) == w::Status::invalid_request, "foreign decoder request before effects");
    good(f.owner->service_decode(request));
    const auto state = f.owner->snapshot();
    check(state.outer.decoded_samples == 33 && state.outer.encoded_bytes == 72 && state.pcm.rings[0].data == 16354,
          "whole partial final stereo raw/published accounting");
    check(state.ready.format == 16, "actual tag0 RNA output depth separate from encoded bits4");
    check(f.observer.order && f.observer.reentry && f.observer.credit_boundaries && f.observer.publications == 2,
          "actual source credit sees raw PCM before callbacks/publication");
    f.retire(); check(f.owner->service_decode(request) == w::Status::closed, "stopped decoder admission");
    good(f.owner->retire_on_control_thread()); deny = false;
}
void long_stream(unsigned channels, unsigned rate, bool downmix) {
    Fixture f(channels, rate, 40017, downmix); deny = true;
    good(f.owner->service_header()); good(f.owner->configure_ready()); const auto request = f.owner->request();
    unsigned previous = 0;
    for (unsigned i = 0; i < 700; ++i) {
        f.refill(); const auto result = f.owner->service_decode(request);
        check(result == w::Status::completed || result == w::Status::backpressure, "whole original-size repeated decode");
        const auto state = f.owner->snapshot();
        check(state.outer.decoded_samples >= static_cast<int>(previous), "monotonic decoded samples"); previous = static_cast<unsigned>(state.outer.decoded_samples);
        f.drain(); if (state.outer.phase == w::OuterPhase::ended) break;
    }
    const auto state = f.owner->snapshot();
    check(state.outer.decoded_samples == 40017 && state.outer.phase == w::OuterPhase::ended, "long stream reaches actual intended total");
    check(f.observer.order && f.observer.reentry, "long-stream phase observations and reentry controls");
    f.retire(); deny = false;
}
void before_block_pressure() {
    Fixture f(1, 24000, 17, false, 16354); deny = true;
    good(f.owner->service_header()); good(f.owner->configure_ready()); const auto before = f.owner->snapshot();
    check(f.owner->service_decode(f.owner->request()) == w::Status::backpressure, "actual minimum-free-block condition");
    const auto after = f.owner->snapshot(); check(before.pcm.rings == after.pcm.rings && !after.source_batch_held && !after.pcm_write_held,
        "backpressure restores only actual input grant");
    f.retire(); deny = false;
}
std::vector<std::uint8_t> seamless_file() {
    auto data = file(1, 44100, 32); auto next = file(1, 48000, 65);
    data[114] = 0x80; data[115] = 1; be16(data, 116, 12);
    std::copy_n(next.begin(), 96 + 3 * 18, data.begin() + 130);
    data[130 + 18] = 4; // New header with selective, nonzero predictor history.
    be16(data, 130 + 24, 1234); be16(data, 130 + 28, 5678);
    return data;
}
void seamless_and_defer() {
    for (int cursor : {0, 8030}) {
        Fixture f(1, 44100, 32, false, 0, seamless_file(), true, cursor); deny = true;
        good(f.owner->service_header()); good(f.owner->configure_ready()); auto request = f.owner->request();
        good(f.owner->service_decode(request));
        check(f.owner->snapshot().outer.decoded_samples == 32, "first segment actual decode");
        f.drain(); good(f.owner->service_decode(request)); const auto state = f.owner->snapshot();
        check(state.loop.seamless_samples == 32 && state.header.base.frequency == 48000 && state.ready.frequency == 44100,
              "seamless accumulation and new header preserve previous RNA configuration");
        if (!cursor) {
            check(state.outer.decoded_samples == 65 && state.outer.phase == w::OuterPhase::decoding && state.sample_limit == 65,
                  "new seamless segment decodes without source reset");
        } else {
            check(state.outer.phase == w::OuterPhase::header && !state.loop.seamless_enabled && state.outer.decoded_samples == 0,
                  "wrapped short actual header preserves defer and consumed prefix");
            check(state.header.predictor.history[0] == 1234 && state.header.predictor.history[1] == 0 &&
                  state.header.predictor.history[2] == 5678 && state.header.predictor.history[3] == 0,
                  "stop clears actual histories before selective next-header parse");
            const auto old_guards = f.observer.guards;
            good(f.owner->service(request));
            check(f.observer.guards == old_guards + 4 && f.owner->snapshot().outer.phase == w::OuterPhase::header,
                  "scheduled service retries deferred header through actual Get/Unget");
        }
        f.retire(); deny = false;
    }
}
void file_loop_order() {
    auto data = file(1, 44100, 40017); data[18] = 4;
    be16(data, 24, 1234); be16(data, 28, 5678);
    be16(data, 32, 1); be16(data, 34, 1);
    be32(data, 40, 32); be32(data, 44, 114); be32(data, 48, 128); be32(data, 52, 168);
    Fixture f(1, 44100, 40017, false, 0, std::move(data), false, 0, 2048); deny = true;
    good(f.owner->set_loop_enabled(true)); good(f.owner->service_header()); good(f.owner->configure_ready());
    const auto request = f.owner->request(); good(f.owner->service_decode(request));
    const auto intro = f.owner->snapshot(); check(intro.outer.position == 32 && intro.sample_limit == 32, "loop intro stops at actual start sample");
    f.drain(); good(f.owner->service_decode(request)); const auto first = f.owner->snapshot();
    check(first.loop.saved_valid && first.loop.saved.history == intro.header.predictor.history && first.loop.saved.key == intro.header.predictor.key,
          "first loop snapshots current predictor before accounting reset");
    check(first.outer.position == 128 && first.outer.sample_progress == 96 && first.sample_limit == 96 && first.outer.encoded_progress == 168,
          "first loop span and byte accounting distinct from total decode");
    f.drain(); good(f.owner->set_loop_enabled(false)); good(f.owner->service_decode(request)); const auto repeat = f.owner->snapshot();
    check(repeat.loop.iterations == 1 && repeat.outer.position == 32 && repeat.outer.sample_progress == 0 && repeat.outer.encoded_progress == 114,
          "file-backed repeat consumes real padding even after runtime loop disabled");
    check(repeat.header.predictor.history == first.loop.saved.history && repeat.source.ring.data == 0,
          "repeat restores saved predictor and owns exact padding disposal");
    check(repeat.engine.decoded_total == 128 && repeat.header.output_cursor == 0, "cumulative engine samples separate from acknowledged per-window cursor");
    f.retire(); deny = false;
}
void invalid_geometry_drains_pending_source() {
    auto data = file(1, 44100, 40017);
    be16(data, 20, 1); be16(data, 22, 1); be32(data, 28, 32); be32(data, 32, 114);
    be32(data, 36, 96); be32(data, 40, 0x7fffffff);
    Fixture f(1, 44100, 40017, false, 0, std::move(data), false, 0, 2048); deny = true;
    check(f.owner->service_source().status == s::Status::completed && f.backend->pending, "private provider already pending before invalid parsed geometry");
    check(f.owner->service_header() == w::Status::unsupported_profile, "post-parse invalid geometry owned fault");
    const auto fault = f.owner->snapshot();
    check(fault.fault && fault.source_batch_held && fault.header.loop.positions[3] == 0x7fffffffu,
          "invalid header evidence and actual source loan retained");
    check(fault.source.loop.file_action == s::FileTargetAction::none && fault.source.loop.decoder_action == s::DecoderLimitAction::none &&
          fault.source.loop.target_sectors == 0x7fffffff, "last valid geometry safely disarmed before accepted drain");
    check(f.owner->retire_on_control_thread() == w::Status::retirement_pending && !f.backend->joined,
          "pending accepted work prevents false fence");
    deny = false; f.backend->complete(); deny = true;
    good(f.owner->retire_on_control_thread());
    check(f.backend->joined && f.owner->snapshot().fault && f.owner->snapshot().phase == w::Phase::retired,
          "actual accepted publication and join retain fault finding"); deny = false;
}
void source_fence_before_pcm_drain() {
    Fixture f(1, 44100, 32); deny = true;
    good(f.owner->service_header()); good(f.owner->configure_ready()); good(f.owner->service_decode(f.owner->request()));
    good(f.owner->stop_decode());
    check(f.owner->retire_on_control_thread() == w::Status::retirement_pending && f.backend->joined,
          "source can fence while accepted PCM remains drainable");
    f.drain(); good(f.owner->retire_on_control_thread()); good(f.owner->retire_on_control_thread()); deny = false;
}
void provider_error_preserves_buffered_decode() {
    Fixture f(1, 44100, 40017, false, 0, {}, false, 0, 2048, 2); deny = true;
    good(f.owner->service_header()); good(f.owner->configure_ready()); const auto request = f.owner->request();
    check(f.owner->service_source().status == s::Status::completed && f.backend->pending, "accepted provider request before measured I/O error");
    deny = false; f.backend->complete(); f.backend->failed = true; deny = true;
    check(f.owner->service_source().status == s::Status::provider_failure, "actual provider error returned to caller");
    const auto error = f.owner->snapshot();
    check(error.source.state == 2 && error.source.retries == 1 && !error.fault && error.last_error == w::Status::source_failure && error.source.ring.data == 1952,
          "source error recorded without inventing decoder corruption");
    good(f.owner->service_decode(request));
    check(f.owner->snapshot().outer.decoded_samples == 1152, "already queued original bytes still decode after I/O error");
    for (unsigned i = 0; i < 2; ++i) {
        check(f.owner->service_source().status == s::Status::completed && f.backend->pending, "explicit original retry submission");
        deny = false; f.backend->complete(); deny = true;
        check(f.owner->service_source().status == s::Status::provider_failure && !f.owner->snapshot().fault,
              "retry errors do not corrupt decoder ownership");
    }
    check(f.owner->snapshot().source.state == 4 && f.owner->snapshot().source.retries == 2,
          "actual source terminal error follows original retry count");
    f.retire(); deny = false;
}
void accepted_source_stop() {
    Fixture f(1, 44100, 40017, false, 0, {}, false, 0, 2048); deny = true;
    good(f.owner->service_header()); good(f.owner->configure_ready());
    check(f.owner->service_source().status == s::Status::completed && f.backend->pending, "accepted work before source stop");
    good(f.owner->request_source_stop());
    check(f.owner->snapshot().source.stop_requested && !f.owner->snapshot().stopped, "source stop retains independent decoder admission");
    deny = false; f.backend->complete(); deny = true;
    const auto result = f.owner->service_source();
    check(result.status == s::Status::completed && result.published && f.owner->snapshot().source.ring.data == 8096,
          "stop publishes accepted result with original byte conservation");
    check(f.owner->service_source().status == s::Status::completed && f.owner->snapshot().source.state == 1,
          "next complete lifecycle consumes the stop request");
    good(f.owner->service(f.owner->request())); check(f.owner->snapshot().outer.decoded_samples == 1152, "source stop leaves buffered decode live");
    f.retire(); deny = false;
}
struct BlockView final : r::ByteView {
    std::vector<std::uint8_t> bytes;
    mutable std::mutex mutex; mutable std::condition_variable cv; mutable bool entered{}, released{};
    BlockView() : bytes(file(1, 44100, 40017)) {
        be16(bytes, 20, 1); be16(bytes, 22, 1); be32(bytes, 28, 32); be32(bytes, 32, 114);
        be32(bytes, 36, 96); be32(bytes, 40, 0x7fffffff);
    }
    std::uint64_t size() const noexcept override { return bytes.size(); }
    r::ReadResult read(std::uint64_t offset, std::span<std::byte> output) const override {
        { std::unique_lock lock(mutex); entered = true; cv.notify_all(); cv.wait(lock, [&] { return released; }); }
        if (offset > bytes.size() || output.size() > bytes.size() - offset) return {r::Status::invalid_range, 0};
        for (std::size_t i = 0; i < output.size(); ++i) output[i] = std::byte(bytes[static_cast<std::size_t>(offset) + i]);
        return {r::Status::ok, output.size()};
    }
    bool wait_entered() const {
        std::unique_lock lock(mutex); return cv.wait_for(lock, std::chrono::seconds(3), [&] { return entered; });
    }
    void release() const { std::lock_guard lock(mutex); released = true; cv.notify_all(); }
};
void actual_blocked_provider_fault_drain() {
    auto view = std::make_shared<BlockView>();
    auto keys = std::make_shared<reo::native::adx_header::KeyContext>(); w::Config config;
    config.source_config.byte_length = static_cast<std::int32_t>(view->size());
    config.source_config.threshold = 8192; config.source_config.maximum_request_bytes = 8192; config.source_config.maximum_sectors = 4;
    w::StreamWindowOwner owner(config, view, a::make_async_backend(8192), keys, {},
        {{0, 1, std::span(view->bytes).first(2048)}, 0, 0});
    // The unchanged real backend owns bounded task/result allocations; they are
    // not presented as allocation-free owner/header/codec work.
    check(owner.service_source().status == s::Status::completed && view->wait_entered(), "actual worker entered independently blocked read");
    deny = true;
    check(owner.service_header() == w::Status::unsupported_profile, "actual pending worker plus invalid parsed geometry");
    check(owner.retire_on_control_thread() == w::Status::retirement_pending && !owner.snapshot().source.joined,
          "no blocking join or false fence while actual read owns work");
    check(owner.snapshot().source.loop.file_action == s::FileTargetAction::none && owner.snapshot().source.loop.target_sectors == 0x7fffffff,
          "actual provider cannot publish against stale parsed target");
    deny = false; view->release();
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3); bool retired = false, unexpected = false;
    while (std::chrono::steady_clock::now() < deadline) {
        const auto result = owner.retire_on_control_thread();
        if (result == w::Status::completed) { retired = true; break; }
        if (result != w::Status::retirement_pending) { unexpected = true; break; }
        std::this_thread::yield();
    }
    check(!unexpected && retired && owner.snapshot().source.joined && owner.snapshot().fault, "actual worker completion/fence keeps original fault evidence");
}

void request_and_read_lifetimes() {
    w::Request stale;
    std::optional<w::pcm::ReadLease> stale_read;
    std::weak_ptr<View> old_view;
    {
        Fixture f(1, 44100, 32); old_view = f.view;
        good(f.owner->service_header()); good(f.owner->configure_ready());
        stale = f.owner->request(); good(f.owner->service(stale));
        auto read = f.owner->borrow_pcm(64);
        check(read.status == w::pcm::Status::completed, "read actually held across owner lifetime");
        stale_read.emplace(std::move(read.lease));
        std::array<std::uint8_t, 64> samples{};
        check(stale_read->read_into(0, samples) == w::pcm::Status::completed, "live held read is readable");
        good(f.owner->stop_decode());
        check(f.owner->retire_on_control_thread() == w::Status::retirement_pending && f.backend->joined,
              "held read prevents successful PCM retirement after real source join");
    }
    check(old_view.expired(), "stale request/read do not retain source or provider control");
    std::array<std::uint8_t, 64> samples{};
    check(stale_read->read_into(0, samples) == w::pcm::Status::invalid_lease, "destroyed owner invalidates held read");
    Fixture f(1, 44100, 32); good(f.owner->service_header()); good(f.owner->configure_ready());
    const auto before = f.owner->snapshot(); const auto guards = f.observer.guards;
    check(f.owner->service(stale) == w::Status::invalid_request &&
          f.owner->service_decode(w::Request{}) == w::Status::invalid_request,
          "stale/default request never binds to a replacement owner");
    check(f.owner->finish_pcm(*stale_read) == w::Status::pcm_failure && f.observer.guards == guards &&
          f.owner->snapshot().pcm.rings == before.pcm.rings, "stale read finish has no new owner's credit effects");
    auto request = f.owner->request(); auto moved = std::move(request);
    check(f.owner->service(request) == w::Status::invalid_request, "moved request refuses without effects");
    good(f.owner->service(moved));
    auto read = f.owner->borrow_pcm(64); auto lease = std::move(read.lease);
    check(f.owner->finish_pcm(read.lease) == w::Status::pcm_failure, "moved read cannot return credit");
    good(f.owner->finish_pcm(lease));
    check(f.owner->finish_pcm(lease) == w::Status::pcm_failure, "finished read cannot return credit twice");
    f.retire();
    {
        Fixture lost(1, 44100, 32); good(lost.owner->service_header()); good(lost.owner->configure_ready());
        good(lost.owner->service(lost.owner->request()));
        const auto after_decode = lost.owner->snapshot();
        { auto abandoned = lost.owner->borrow_pcm(64); check(abandoned.status == w::pcm::Status::completed, "lost read acquired"); }
        good(lost.owner->stop_decode());
        const auto held = lost.owner->snapshot();
        check(held.pcm.consumer[0].bytes == 64 && held.pcm.rings[0].free == after_decode.pcm.rings[0].free,
              "lost token destructor does not invent returned credit");
        check(lost.owner->retire_on_control_thread() == w::Status::retirement_pending,
              "lost read blocks ordinary retirement until emergency owner destruction");
    }
}

void fp_and_constructor_admission() {
    Fixture f(1, 44100, 32);
    std::fenv_t saved{}; check(std::fegetenv(&saved) == 0, "save whole-owner FP environment");
    const auto csr = _mm_getcsr();
    for (const auto unsupported : {0x3f80u, 0x5f80u, 0x7f80u, 0x9f80u, 0x1fc0u, 0x1f00u}) {
        const auto before = f.owner->snapshot(); const auto guards = f.observer.guards;
        _mm_setcsr(unsupported);
        check(f.owner->service_header() == w::Status::unsupported_profile && _mm_getcsr() == unsupported,
              "unsupported FP refused before actual header borrow, caller mode retained");
        check(f.observer.guards == guards && f.owner->snapshot().source.ring == before.source.ring &&
              !f.owner->snapshot().source_batch_held && !f.owner->snapshot().fault,
              "header FP refusal has no effects or owned fault");
    }
    (void)std::fesetenv(&saved); _mm_setcsr(csr);
    good(f.owner->service_header()); good(f.owner->configure_ready());
    for (const auto unsupported : {0x3f80u, 0x5f80u, 0x7f80u, 0x9f80u, 0x1fc0u, 0x1f00u}) {
        const auto before = f.owner->snapshot(); const auto guards = f.observer.guards;
        _mm_setcsr(unsupported);
        check(f.owner->service_decode(f.owner->request()) == w::Status::unsupported_profile && _mm_getcsr() == unsupported,
              "unsupported FP refuses before loop/input/PCM effects");
        check(f.observer.guards == guards && f.owner->snapshot().source.ring == before.source.ring &&
              f.owner->snapshot().pcm.rings == before.pcm.rings && !f.owner->snapshot().fault,
              "decode FP refusal retains all credits");
    }
    (void)std::fesetenv(&saved); _mm_setcsr(csr); f.retire();

    // Every actual construction allocation is denied in turn. No source I/O or
    // externally visible guard runs before a fully constructed owner exists.
    auto view = std::make_shared<View>(file(2, 48000, 32));
    auto keys = std::make_shared<reo::native::adx_header::KeyContext>();
    w::Config config; config.channels = 2; config.source_config.byte_length = static_cast<int>(view->size());
    bool success = false; unsigned failures = 0;
    for (int budget = 0; budget < 64; ++budget) {
        auto backend = std::make_unique<Backend>(); Observer observed;
        fail_after = budget;
        try {
            w::StreamWindowOwner owner(config, view, std::move(backend), keys,
                {&observed, Observer::guard, {}, Observer::publication, {}},
                {{0, 1, view->bytes}, 0, 0});
            fail_after = -1; check(observed.guards == 0 && owner.snapshot().source.request_id == 0,
                                  "successful construction starts no provider work");
            success = true;
        } catch (const std::bad_alloc&) { fail_after = -1; ++failures; }
        check(observed.guards == 0 && view.use_count() == 1 && keys.use_count() == 1,
              "constructor failure releases private graph and emits no external credit effects");
        if (success) break;
    }
    check(success && failures >= 8, "construction failure sweep covered actual storage/domain allocations");
}

void malformed_marker_and_provider_identity() {
    // The authored prepared prefix ends ten bytes into the marker. Further
    // file bytes exist, but have not been accepted by this source yet.
    auto data = file(1, 44100, 32); data[114] = 0x80; data[115] = 1; be16(data, 116, 12);
    Fixture f(1, 44100, 32, false, 0, std::move(data), false, 0, 124);
    good(f.owner->service_header()); good(f.owner->configure_ready());
    good(f.owner->service(f.owner->request())); f.drain();
    check(f.owner->service(f.owner->request()) == w::Status::unsupported_profile, "short marker becomes explicit owned fault");
    const auto fault = f.owner->snapshot();
    check(fault.fault && fault.source_batch_held && fault.source.consumers[0].bytes == 10 &&
          fault.source.loop.file_action == s::FileTargetAction::none,
          "malformed descriptor remains owned and selectors disarmed");
    good(f.owner->retire_on_control_thread());
    check(f.owner->snapshot().source.joined && f.owner->snapshot().fault, "short marker proven remaining grant restores before actual join");

    Fixture bad(1, 44100, 40017, false, 0, {}, false, 0, 2048);
    good(bad.owner->service_header()); good(bad.owner->configure_ready());
    check(bad.owner->service_source().status == s::Status::completed && bad.backend->pending, "provider request actually accepted");
    bad.backend->complete(); bad.backend->wrong_id = true;
    const auto before = bad.owner->snapshot();
    check(bad.owner->service_source().status == s::Status::provider_protocol, "wrong result identity rejected");
    const auto after = bad.owner->snapshot();
    check(after.fault && after.source.ring == before.source.ring && after.source.in_flight &&
          after.source.producer_remaining == before.source.producer_remaining,
          "wrong completion cannot publish bytes or erase pending ownership");
    check(bad.owner->retire_on_control_thread() == w::Status::retirement_pending && !bad.backend->joined,
          "protocol fault retains blocked fence rather than trusting consumed wrong result");
}

void private_numeric_boundary() {
    // Fields are seeded only in the verifier's archived private source copy.
    // Normal native API deliberately offers no mutable counter or source alias.
    Fixture f(1, 44100, 40017); good(f.owner->service_header()); good(f.owner->configure_ready());
    const auto before = f.owner->snapshot(); const auto guards = f.observer.guards;
    check(f.owner->service(f.owner->request()) == w::Status::numeric_limit, "every seeded horizon counter refuses before effects");
    const auto after = f.owner->snapshot();
    check(f.observer.guards == guards && before.source.ring == after.source.ring && before.pcm.rings == after.pcm.rings &&
          before.outer.decoded_samples == after.outer.decoded_samples && before.loop.iterations == after.loop.iterations &&
          before.engine.decoded_total == after.engine.decoded_total && !after.fault,
          "numeric horizon refusal leaves graph usable and all credits untouched");
    f.retire();
}

void private_post_encoded_credit() {
    Fixture f(2, 48000, 33); good(f.owner->service_header()); good(f.owner->configure_ready());
    const auto before = f.owner->snapshot();
    check(f.owner->service(f.owner->request()) == w::Status::pcm_failure, "injected failure after actual encoded credit is owned");
    const auto after = f.owner->snapshot();
    check(after.fault && after.stopped && !after.source_batch_held && after.pcm_write_held &&
          after.source.ring.free == before.source.ring.free + 72 && after.pcm.rings[0].data == 0 &&
          after.pcm.phase == w::pcm::Phase::staged && after.engine.decoded_total == 33 && after.outer.decoded_samples == 0,
          "post-credit fault preserves actual input return, staged raw output, and pre-publication counters");
    check(f.owner->retire_on_control_thread() == w::Status::retirement_pending && !f.backend->joined,
          "staged unpublished PCM cannot roll back or manufacture successful retirement");
}

void private_source_ids() {
    Fixture f(1, 44100, 40017); good(f.owner->service_header()); good(f.owner->configure_ready());
    const auto before = f.owner->snapshot(); const auto guards = f.observer.guards;
    check(f.owner->service(f.owner->request()) == w::Status::source_failure, "exhausted actual source batch identity faults before borrow");
    check(f.observer.guards == guards && f.owner->snapshot().source.ring == before.source.ring,
          "exhausted IDs never wrap or manufacture actual grants");
    good(f.owner->retire_on_control_thread());
}

void private_pcm_ids() {
    Fixture f(1, 44100, 32); good(f.owner->service_header()); good(f.owner->configure_ready());
    const auto before = f.owner->snapshot();
    check(f.owner->service(f.owner->request()) == w::Status::pcm_failure, "PCM identity exhaustion is an owned failure");
    const auto after = f.owner->snapshot();
    check(after.fault && after.source_batch_held && !after.pcm_write_held &&
          before.pcm.rings == after.pcm.rings && after.pcm.write_id == 0,
          "exhausted PCM ID retains actual source grant without manufacturing output grant");
    good(f.owner->retire_on_control_thread());
}

void private_partial_pcm_publication() {
    Fixture f(2, 48000, 33); good(f.owner->service_header()); good(f.owner->configure_ready());
    check(f.owner->service(f.owner->request()) == w::Status::pcm_failure, "first-channel post-effect failure reaches concrete owner");
    const auto after = f.owner->snapshot();
    check(after.fault && !after.source_batch_held && after.pcm_write_held && after.pcm.fault &&
          after.pcm.rings[0].data == 66 && after.pcm.rings[1].data == 0 &&
          after.pcm.producer[0] == w::pcm::Grant{66, 16318} && after.pcm.producer[1] == w::pcm::Grant{0, 16384} &&
          after.outer.decoded_samples == 0 && f.observer.publications == 1,
          "earlier channel publication retained with exact remaining suffix and second grant");
    check(f.owner->retire_on_control_thread() == w::Status::retirement_pending && !f.backend->joined,
          "partial channel failure cannot roll back credits or fake graph retirement");
}
}
int main(int argc, char** argv) {
    if (argc == 2) {
        const std::string_view mode(argv[1]);
        if (mode == "numeric") private_numeric_boundary();
        else if (mode == "postcredit") private_post_encoded_credit();
        else if (mode == "ids") private_source_ids();
        else if (mode == "pcmids") private_pcm_ids();
        else if (mode == "partialpcm") private_partial_pcm_publication();
        else { check(false, "unknown private fault mode"); }
        std::printf("%u Window2 private fault checks passed\n", checks); return 0;
    }
    finite_and_identity(); long_stream(1, 44100, false); long_stream(2, 48000, false); long_stream(2, 24000, true); before_block_pressure();
    seamless_and_defer(); file_loop_order(); invalid_geometry_drains_pending_source(); source_fence_before_pcm_drain();
    provider_error_preserves_buffered_decode();
    accepted_source_stop();
    actual_blocked_provider_fault_drain();
    request_and_read_lifetimes(); fp_and_constructor_admission(); malformed_marker_and_provider_identity();
    check(attempts == 0, "no owner/header/codec allocations under guarded whole transactions");
    std::printf("%u Window2 prototype checks passed; allocation attempts=%u\n", checks, attempts);
}
