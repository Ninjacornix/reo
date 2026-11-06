#include "pcm_store.hpp"
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <new>
#include <source_location>
#include <string_view>
#include <utility>

namespace { bool deny{}; unsigned attempts{}, checks{}; }
#if defined(__GNUC__)
#define NOINLINE __attribute__((noinline))
#else
#define NOINLINE __declspec(noinline)
#endif
NOINLINE void* operator new(std::size_t n) {
    if (deny) { ++attempts; throw std::bad_alloc(); }
    if (auto* p = std::malloc(n ? n : 1)) return p;
    throw std::bad_alloc();
}
NOINLINE void operator delete(void* p) noexcept { std::free(p); }
NOINLINE void operator delete(void* p, std::size_t) noexcept { std::free(p); }
NOINLINE void* operator new[](std::size_t n) { return ::operator new(n); }
NOINLINE void operator delete[](void* p) noexcept { ::operator delete(p); }
NOINLINE void operator delete[](void* p, std::size_t) noexcept { ::operator delete(p); }
NOINLINE void* operator new(std::size_t n, std::align_val_t value) {
    if (deny) { ++attempts; throw std::bad_alloc(); }
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

namespace a = reo::native::adx_pcm::v2;
namespace {
void check(bool condition, const char* message) {
    ++checks; if (!condition) { std::fprintf(stderr, "FAILED: %s\n", message); std::exit(1); }
}
void good(a::Status s, const std::source_location at = std::source_location::current()) {
    if (s != a::Status::completed) std::fprintf(stderr, "status=%d at %s:%u\n", static_cast<int>(s), at.file_name(), at.line());
    check(s == a::Status::completed, "completed");
}
using Backing = std::array<std::uint8_t, a::capacity + a::extension>;
void conserved(const a::Store& owner, unsigned channels) {
    const auto s = owner.snapshot();
    for (unsigned c = 0; c < channels; ++c)
        check(std::int64_t(s.rings[c].data) + s.rings[c].free + s.producer[c].bytes + s.consumer[c].bytes == a::capacity,
              "actual stable credit conservation");
}
struct Observe {
    a::Store* owner{}; unsigned guards{}, publications{}; bool callback_reads{}, reentry{}; a::View retained;
    static void guard(void* p, std::uint32_t, bool) noexcept {
        auto& o = *static_cast<Observe*>(p); ++o.guards;
        if (o.owner) o.reentry = o.reentry && o.owner->stop() == a::Status::busy &&
            o.owner->reserve().status == a::Status::busy && o.owner->read(0).status == a::Status::busy;
    }
    static void pcm(void* p, std::uint32_t, const a::View& v) noexcept {
        auto& o = *static_cast<Observe*>(p); ++o.publications; o.retained = v;
        std::array<std::uint8_t, 2> first{};
        o.callback_reads = o.callback_reads && v.read_into(std::span(first).first(v.bytes() ? 2 : 0)) == a::Status::completed;
        o.reentry = o.reentry && o.owner->retire() == a::Status::busy && o.owner->stop() == a::Status::busy;
    }
};
void partial_tail() {
    Observe observer; observer.callback_reads = observer.reentry = true;
    a::Store owner({2, 0, 16288}, {&observer, Observe::guard, Observe::pcm}, 0xa5); observer.owner = &owner;
    std::array<std::int16_t, 64> left{}, right{};
    for (int i = 0; i < 64; ++i) { left[static_cast<unsigned>(i)] = static_cast<std::int16_t>(i + 1); right[static_cast<unsigned>(i)] = static_cast<std::int16_t>(-i - 1); }
    deny = true;
    auto reservation = owner.reserve(); good(reservation.status);
    check(reservation.lease.grant(0) == a::Grant{16288, 96}, "actual partial-tail reservation");
    good(owner.write_and_publish(reservation.lease, {left, right}, 33, 33));
    conserved(owner, 2);
    Backing bytes{}; good(owner.read_backing(0, bytes));
    check(std::all_of(bytes.begin(), bytes.begin() + 16288, [](auto b) { return b == 0xa5; }), "queued main bytes protected");
    check(bytes[16384] == 49 && bytes[16414] == 64 && bytes[16416] == 0xa5, "unpublished extension padding retained exactly");
    const auto state = owner.snapshot();
    check(state.rings[0].data == 16354 && state.rings[0].free == 30 && state.rings[0].write == 16354, "logical credit excludes raw padding");
    check(observer.publications == 2 && observer.callback_reads && observer.reentry, "bounded publication views and refused callback reentry");
    check(owner.restore(reservation.lease) == a::Status::invalid_lease, "published lease stale");
    good(owner.stop()); check(owner.reserve().status == a::Status::closed, "stop closes new producer");
    check(owner.retire() == a::Status::busy, "queued data prevents normal retire");
    auto drain = owner.read(a::capacity); good(drain.status); good(owner.finish(drain.lease)); good(owner.retire());
    std::array<std::uint8_t, 2> out{}; check(observer.retained.read_into(out) == a::Status::closed, "retirement invalidates retained view");
    deny = false;
}
void refusal_and_tokens() {
    a::Store owner({2, 1000, 16000}, {}, 0xa5), other({2});
    std::array<std::int16_t, 256> pcm{}; Backing before{}, after{};
    deny = true;
    auto write = owner.reserve(); good(write.status); check(write.lease.grant(0) == a::Grant{616, 384}, "wrapped queue bounded free grant");
    good(owner.read_backing(0, before));
    check(owner.write_and_publish(write.lease, {pcm, pcm}, 192, 192) == a::Status::physical_conflict, "raw excess in queued main storage refuses");
    good(owner.read_backing(0, after)); check(before == after, "refusal has no PCM stores"); conserved(owner, 2);
    check(other.restore(write.lease) == a::Status::invalid_lease, "foreign write credit refused");
    a::WriteLease moved(std::move(write.lease)); check(owner.restore(write.lease) == a::Status::invalid_lease, "moved write token refused");
    good(owner.restore(moved)); check(owner.restore(moved) == a::Status::invalid_lease, "write credit returned once");
    auto read = owner.read(128); good(read.status); a::ReadLease moved_read(std::move(read.lease));
    check(owner.finish(read.lease) == a::Status::invalid_lease, "moved reader refused");
    check(other.finish(moved_read) == a::Status::invalid_lease, "foreign reader refused");
    check(moved_read.read_into(2, after) == a::Status::invalid_lease, "foreign channel refused");
    good(owner.finish(moved_read)); check(owner.finish(moved_read) == a::Status::invalid_lease, "consumer credit returned once");
    check(moved_read.read_into(0, std::span(after).first(2)) == a::Status::invalid_lease, "finished token cannot read");
    check(owner.read(1).status == a::Status::invalid_count, "odd request before effects");
    check(owner.read(-2).status == a::Status::invalid_count, "negative request before effects");
    good(owner.stop());
    while (owner.snapshot().rings[0].data) { auto tail = owner.read(a::capacity); good(tail.status); good(owner.finish(tail.lease)); }
    good(owner.retire()); check(owner.read(0).status == a::Status::closed, "retired consumer admission closed");
    deny = false;
}
void wrap_and_held_consumer() {
    a::Store owner({2, 16320, 0}, {}, 0xa5); std::array<std::int16_t, 64> samples{};
    for (unsigned i = 0; i < samples.size(); ++i) samples[i] = static_cast<std::int16_t>(i + 1);
    deny = true;
    auto write = owner.reserve(); good(write.status); good(owner.write_and_publish(write.lease, {samples, samples}, 64, 64));
    Backing bytes{}; good(owner.read_backing(0, bytes));
    check(bytes[0] == 33 && bytes[62] == 64 && bytes[16384] == 33, "corrected wrap and Ring mirror bytes");
    auto held = owner.read(128); good(held.status);
    check(held.lease.grant(0) == a::Grant{16320, 128}, "consumer actual physical tail+extension span");
    std::array<std::uint8_t, 128> read_before{}, read_after{}; good(held.lease.read_into(0, read_before));
    auto next = owner.reserve(); good(next.status); conserved(owner, 2);
    std::array<std::int16_t, 32> next_samples{}; next_samples.fill(1234);
    good(owner.write_and_publish(next.lease, {next_samples, next_samples}, 32, 32));
    good(held.lease.read_into(0, read_after)); check(read_before == read_after, "publication preserves held extension lease");
    good(owner.finish(held.lease)); auto last = owner.read(64); good(last.status); good(owner.finish(last.lease));
    good(owner.stop()); good(owner.retire()); deny = false;
}
void lifetime_and_lost_credit() {
    auto survivor = [] {
        a::Store owner({1, 0, 64}, {}, 0xa5);
        auto read = owner.read(64); good(read.status);
        return read;
    }();
    std::array<std::uint8_t, 2> out{};
    check(survivor.lease.read_into(0, out) == a::Status::invalid_lease, "outliving storage token refuses reads after owner death");
    a::Store lost({1, 0, 64});
    { auto read = lost.read(64); good(read.status); }
    check(lost.snapshot().consumer[0].bytes == 64, "read destructor returns no credit");
    good(lost.stop()); check(lost.retire() == a::Status::busy, "lost consumer retains busy ledger");
    a::Store lost_write({1});
    { auto write = lost_write.reserve(); good(write.status); }
    good(lost_write.stop()); check(lost_write.retire() == a::Status::busy, "lost producer retains busy ledger");
}
void long_store() {
    a::Store owner({2}); std::array<std::int16_t, 1216> samples{}; samples.fill(-1234);
    deny = true;
    std::uint64_t published = 0, consumed = 0;
    for (unsigned i = 0; i < 400; ++i) {
        auto write = owner.reserve(); good(write.status);
        const auto bytes = std::min(write.lease.grant(0).bytes, 2432);
        const auto count = bytes / 64 * 32;
        good(owner.write_and_publish(write.lease, {std::span(samples).first(static_cast<std::size_t>(count)), std::span(samples).first(static_cast<std::size_t>(count))}, count, count));
        published += static_cast<unsigned>(count) * 2;
        auto read = owner.read(2432); good(read.status);
        consumed += static_cast<unsigned>(read.lease.grant(0).bytes);
        good(owner.finish(read.lease)); conserved(owner, 2);
    }
    good(owner.stop());
    for (unsigned i = 0; i < 3 && owner.snapshot().rings[0].data; ++i) {
        auto read = owner.read(a::capacity); good(read.status); consumed += static_cast<unsigned>(read.lease.grant(0).bytes); good(owner.finish(read.lease));
    }
    check(published == consumed && published > 40017 * 2, "long distinct produced/consumed counters without reset");
    good(owner.retire()); deny = false;
}
void empty_and_invalid() {
    a::Store owner({1}); std::array<std::int16_t, 32> samples{};
    deny = true;
    auto read = owner.read(0); good(read.status);
    check(read.lease.grant(0) == a::Grant{0, 0}, "zero consumer is still an explicit lease");
    check(owner.read(0).status == a::Status::busy, "zero held consumer prevents replacement");
    good(owner.finish(read.lease));
    auto write = owner.reserve(); good(write.status);
    check(owner.reserve().status == a::Status::busy, "held producer prevents replacement");
    check(owner.write_and_publish(write.lease, {samples, samples}, 32, 32) == a::Status::invalid_count, "mono right plane refuses before stores");
    check(owner.write_and_publish(write.lease, {samples, {}}, 33, 33) == a::Status::invalid_count, "produced extent cannot exceed raw input");
    check(owner.write_and_publish(write.lease, {samples, {}}, 16, 17) == a::Status::invalid_count, "publication cannot exceed corrected production");
    check(owner.write_and_publish(write.lease, {samples, {}}, -1, 0) == a::Status::invalid_count, "negative corrected production refuses");
    good(owner.write_and_publish(write.lease, {{}, {}}, 0, 0)); conserved(owner, 1);
    good(owner.stop()); good(owner.stop()); good(owner.retire()); good(owner.retire()); deny = false;
    bool threw = false; deny = true;
    try { a::Store cannot_allocate({1}); } catch (const std::bad_alloc&) { threw = true; }
    deny = false; check(threw && attempts == 1, "construction allocation failure has no published owner");
    attempts = 0;
}
void cursor_matrix() {
    // Queue wrap, held physical reads, arbitrary even cursors and padding. This
    // is native ownership policy coverage, not additional original equivalence.
    for (int cursor : {0, 2, 190, 1000, 8190, 16192, 16320, 16382}) {
        for (int queued : {0, 2, 64, 192, 8000, 16000, 16320, 16384}) {
            a::Store owner({2, cursor, queued}, {}, 0xa5);
            std::array<std::int16_t, 128> raw{}; raw.fill(0x1234);
            deny = true;
            auto held = owner.read(128); good(held.status);
            std::array<std::uint8_t, 128> old{}, now{};
            const auto n = static_cast<std::size_t>(held.lease.grant(0).bytes);
            good(held.lease.read_into(0, std::span(old).first(n)));
            auto write = owner.reserve(); good(write.status);
            auto old_queued = owner.snapshot().rings[0].data;
            const auto produced = std::min(write.lease.grant(0).bytes / 2, 128);
            const auto status = owner.write_and_publish(write.lease, {raw, raw}, produced, produced);
            check(status == a::Status::completed || status == a::Status::physical_conflict, "bounded raw plan accepts or retains reservation");
            if (status == a::Status::physical_conflict) good(owner.restore(write.lease));
            good(held.lease.read_into(0, std::span(now).first(n))); check(old == now, "held physical bytes unchanged across cursor matrix");
            conserved(owner, 2); good(owner.finish(held.lease)); good(owner.stop());
            Backing queued_bytes{};
            for (unsigned i = 0; i < 3 && old_queued; ++i) {
                auto r = owner.read(old_queued); good(r.status);
                const auto count = r.lease.grant(0).bytes;
                good(r.lease.read_into(0, std::span(queued_bytes).first(static_cast<std::size_t>(count))));
                check(std::all_of(queued_bytes.begin(), queued_bytes.begin() + count, [](auto b) { return b == 0xa5; }), "queued original bytes and readable mirror unchanged");
                old_queued -= count; good(owner.finish(r.lease));
            }
            check(old_queued == 0, "all original queued bytes checked");
            for (unsigned i = 0; i < 3 && owner.snapshot().rings[0].data; ++i) {
                auto r = owner.read(a::capacity); good(r.status); good(owner.finish(r.lease));
            }
            good(owner.retire()); deny = false;
        }
    }
}
void exhausted_ids() {
    a::Store owner({1}); const auto before = owner.snapshot();
    check(owner.reserve().status == a::Status::id_exhausted && owner.read(0).status == a::Status::id_exhausted, "ID exhaustion refuses before Ring effects");
    check(owner.snapshot().rings == before.rings && !owner.snapshot().write_id && !owner.snapshot().read_id, "no zero/wrapped IDs or queue effects");
    good(owner.stop()); good(owner.retire());
}
void staged_boundary() {
    Observe observer; observer.callback_reads = observer.reentry = true;
    a::Store owner({2, 0, 16288}, {&observer, Observe::guard, Observe::pcm}, 0xa5); observer.owner = &owner;
    std::array<std::int16_t, 64> samples{}; samples.fill(0x1234);
    deny = true;
    auto held = owner.read(64); good(held.status);
    auto write = owner.reserve(); good(write.status);
    const auto reserved = owner.snapshot();
    check(reserved.phase == a::Phase::reserved, "actual producer acquired before staging");
    check(owner.publish(write.lease) == a::Status::busy, "cannot publish without accepted raw stores");
    const auto guards = observer.guards;
    good(owner.stage(write.lease, {samples, samples}, 33, 33));
    const auto staged = owner.snapshot();
    check(staged.phase == a::Phase::staged && staged.rings == reserved.rings && staged.producer == reserved.producer,
          "raw PCM accepted but all logical credit and producer grants unchanged");
    check(observer.guards == guards && observer.publications == 0, "stage emits no premature publication or credit guards");
    Backing bytes{}; good(owner.read_backing(0, bytes));
    check(bytes[16288] == 0x34 && bytes[16384] == 0x34 && bytes[16416] == 0xa5, "raw and padding visible at encoded credit-return boundary");
    check(owner.restore(write.lease) == a::Status::busy && owner.stop() == a::Status::busy && owner.retire() == a::Status::busy,
          "staged effects cannot be silently rolled back or retired");
    check(owner.finish(held.lease) == a::Status::busy && owner.read(0).status == a::Status::busy, "PCM credit geometry stable between stages");
    std::array<std::uint8_t, 64> old{}; good(held.lease.read_into(0, old));
    check(std::all_of(old.begin(), old.end(), [](auto b) { return b == 0xa5; }), "held reader remains readable");
    samples.fill(0); // Caller-owned codec staging may now be reused.
    good(owner.publish(write.lease));
    check(owner.snapshot().phase == a::Phase::idle && observer.publications == 2, "explicit publication completes actual ordered credit");
    good(owner.read_backing(0, bytes)); check(bytes[16288] == 0x34, "publish does not reread scalar input");
    check(owner.publish(write.lease) == a::Status::invalid_lease, "publication at most once");
    good(owner.finish(held.lease)); good(owner.stop());
    while (owner.snapshot().rings[0].data) { auto r = owner.read(a::capacity); good(r.status); good(owner.finish(r.lease)); }
    good(owner.retire()); deny = false;
    a::Store lost({1});
    { auto w = lost.reserve(); good(w.status); good(lost.stage(w.lease, {samples, {}}, 32, 32)); }
    check(lost.snapshot().phase == a::Phase::staged && lost.snapshot().rings[0].data == 0,
          "lost staged token neither publishes nor returns credit");
    check(lost.retire() == a::Status::busy && lost.stop() == a::Status::busy, "staged transaction retains blocked owner");
}
void sizing_with_queued_audio() {
    a::Store owner({2, 2048, 14344});
    auto held = owner.read(64); good(held.status);
    auto write = owner.reserve(); good(write.status);
    check(write.lease.grant(0) == a::Grant{8, 2040}, "captured loop failure geometry");
    Backing before{}, after{}; good(owner.read_backing(0, before));
    const auto snapshot = owner.snapshot(); deny = true;
    check(owner.admit_stage(write.lease, 1024, 996, 996) == a::Status::physical_conflict, "raw tail must not overwrite queued samples");
    good(owner.admit_stage(write.lease, 992, 992, 992));
    good(owner.read_backing(0, after));
    check(before == after && owner.snapshot().phase == snapshot.phase && owner.snapshot().write_id == snapshot.write_id &&
          owner.snapshot().producer == snapshot.producer && owner.snapshot().rings[0].data == snapshot.rings[0].data,
          "sizing admission is pure and retains actual credit");
    std::array<std::int16_t, 992> samples{};
    good(owner.stage(write.lease, {samples, samples}, 992, 992)); good(owner.publish(write.lease));
    good(owner.finish(held.lease)); good(owner.stop());
    while (owner.snapshot().rings[0].data) { auto read = owner.read(a::capacity); good(read.status); good(owner.finish(read.lease)); }
    good(owner.retire()); deny = false;
}
void post_effect() {
    a::Store owner({2, 0, 16288}); std::array<std::int16_t, 64> samples{};
    auto write = owner.reserve(); good(write.status);
    check(owner.write_and_publish(write.lease, {samples, samples}, 33, 33) == a::Status::ring_failure, "injected post-prefix failure detected");
    const auto s = owner.snapshot();
    check(s.fault && s.rings[0].data == 16354 && s.producer[0] == a::Grant{16354, 30}, "first publication retained with exact suffix");
    check(s.rings[1].data == 16288 && s.producer[1] == a::Grant{16288, 96}, "second producer remains wholly held");
    conserved(owner, 2);
    check(owner.restore(write.lease) == a::Status::invariant_fault && owner.retire() == a::Status::invariant_fault, "no rollback or false retirement after partial failure");
}
}
int main(int argc, char** argv) {
    if (argc == 2 && std::string_view(argv[1]) == "posteffect") { post_effect(); }
    else if (argc == 2 && std::string_view(argv[1]) == "ids") { exhausted_ids(); }
    else {
        check(!a::Store::admits({0}) && !a::Store::admits({3}) && !a::Store::admits({1, 1, 0}), "configuration admission");
        partial_tail(); refusal_and_tokens(); wrap_and_held_consumer(); lifetime_and_lost_credit(); long_store(); empty_and_invalid(); cursor_matrix(); staged_boundary(); sizing_with_queued_audio();
        check(attempts == 0, "zero post-construction allocations under denial");
    }
    std::printf("%u PCM ownership checks passed; allocation attempts=%u\n", checks, attempts);
}
