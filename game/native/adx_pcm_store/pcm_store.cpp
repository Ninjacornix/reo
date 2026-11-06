#include "pcm_store.hpp"
#include <algorithm>
#include <bit>
#include <limits>
#include <stdexcept>
#include <utility>

namespace reo::native::adx_pcm {
namespace {
Grant describe(const sjrb::Chunk& c) noexcept { return c.is_null() ? Grant{} : Grant{c.offset(), c.bytes()}; }
struct Interval { std::int64_t begin, end; };
bool overlaps(Interval a, Interval b) noexcept {
    return a.begin < a.end && b.begin < b.end && a.begin < b.end && b.begin < a.end;
}
}
struct Domain { bool alive{true}; std::uint32_t channels{}; std::uint64_t write_id{}, read_id{}; };
WriteLease::WriteLease(WriteLease&& other) noexcept
    : domain_(std::move(other.domain_)), id_(std::exchange(other.id_, 0)), chunks_(std::move(other.chunks_)) {}
ReadLease::ReadLease(ReadLease&& other) noexcept
    : domain_(std::move(other.domain_)), id_(std::exchange(other.id_, 0)), chunks_(std::move(other.chunks_)) {}
Grant WriteLease::grant(std::uint32_t c) const noexcept {
    return domain_ && domain_->alive && id_ && domain_->write_id == id_ && c < domain_->channels ? describe(chunks_[c]) : Grant{};
}
Grant ReadLease::grant(std::uint32_t c) const noexcept {
    return domain_ && domain_->alive && id_ && domain_->read_id == id_ && c < domain_->channels ? describe(chunks_[c]) : Grant{};
}
Status ReadLease::read_into(std::uint32_t c, std::span<std::uint8_t> out, std::size_t at) const noexcept {
    if (!domain_ || !domain_->alive || !id_ || domain_->read_id != id_ || c >= domain_->channels) return Status::invalid_lease;
    return chunks_[c].read(out, at) == sjrb::Status::completed ? Status::completed : Status::invalid_count;
}
std::int32_t View::bytes() const noexcept { return chunk_.bytes(); }
Status View::read_into(std::span<std::uint8_t> out, std::size_t at) const noexcept {
    if (!domain_ || !domain_->alive) return Status::closed;
    return chunk_.read(out, at) == sjrb::Status::completed ? Status::completed : Status::invalid_count;
}
class Store::Scope final {
public:
    explicit Scope(Store& owner) noexcept : owner_(owner) { owner_.busy_ = true; }
    ~Scope() { owner_.transfer_ = Transfer::none; owner_.busy_ = false; }
private: Store& owner_;
};
bool Store::admits(Config c) noexcept {
    return c.channels >= 1 && c.channels <= 2 && c.cursor >= 0 && c.cursor < capacity && !(c.cursor & 1) &&
        c.queued_bytes >= 0 && c.queued_bytes <= capacity && !(c.queued_bytes & 1);
}
Store::Store(Config config, Hooks hooks, std::uint8_t initial) : config_(config), hooks_(hooks) {
    if (!admits(config)) throw std::invalid_argument("PCM store geometry");
    domain_ = std::make_shared<Domain>(); domain_->channels = config.channels;
    for (std::uint32_t c = 0; c < config.channels; ++c) {
        rings_[c] = std::make_unique<sjrb::Ring>(capacity, extension, sjrb::Hooks{}, initial);
        if (!bootstrap(c)) throw std::logic_error("PCM store bootstrap");
    }
    for (std::uint32_t c = 0; c < config.channels; ++c) {
        contexts_[c] = {this, c};
        if (rings_[c]->set_hooks({&contexts_[c], enter, leave, ring_error}) != sjrb::Status::completed)
            throw std::logic_error("PCM store hooks");
    }
}
Store::~Store() { domain_->alive = false; }
bool Store::bootstrap(std::uint32_t c) noexcept {
    auto& r = *rings_[c]; sjrb::Chunk chunk;
    if (config_.cursor) {
        if (r.get(0, config_.cursor, chunk) != sjrb::Status::completed || chunk.bytes() != config_.cursor ||
            r.put(1, chunk) != sjrb::Status::completed || r.get(1, config_.cursor, chunk) != sjrb::Status::completed ||
            r.put(0, chunk) != sjrb::Status::completed) return false;
    }
    auto remaining = config_.queued_bytes;
    while (remaining) {
        if (r.get(0, remaining, chunk) != sjrb::Status::completed || chunk.bytes() <= 0) return false;
        remaining -= chunk.bytes();
        if (r.put(1, chunk) != sjrb::Status::completed) return false;
    }
    return true;
}
void Store::enter(void* p) noexcept {
    auto& c = *static_cast<RingContext*>(p);
    if (c.owner->hooks_.guard) c.owner->hooks_.guard(c.owner->hooks_.context, c.channel, true);
}
void Store::leave(void* p) noexcept {
    auto& c = *static_cast<RingContext*>(p);
    if (c.owner->hooks_.guard) c.owner->hooks_.guard(c.owner->hooks_.context, c.channel, false);
}
void Store::ring_error(void* p, std::int32_t) noexcept { static_cast<RingContext*>(p)->owner->fault_ = true; }
bool Store::ok(sjrb::Status s) noexcept { return s == sjrb::Status::completed && !fault_; }
Status Store::fail() noexcept { fault_ = true; return Status::ring_failure; }
bool Store::sound() const noexcept {
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        const auto r = rings_[c]->snapshot();
        const auto p = producer_[c].bytes(), held = consumer_[c].bytes();
        if (r.capacity != capacity || r.extension != extension || r.data < 0 || r.free < 0 || p < 0 || held < 0 ||
            std::int64_t(r.data) + r.free + p + held != capacity ||
            r.write < 0 || r.write >= capacity || r.read < 0 || r.read >= capacity ||
            ((r.data | r.free | r.write | r.read | p | held) & 1)) return false;
    }
    return true;
}
bool Store::same_grants() const noexcept {
    if (config_.channels == 1) return true;
    const auto a = rings_[0]->snapshot(), b = rings_[1]->snapshot();
    return a.data == b.data && a.free == b.free && a.write == b.write && a.read == b.read &&
        describe(producer_[0]) == describe(producer_[1]) && describe(consumer_[0]) == describe(consumer_[1]);
}
Snapshot Store::snapshot() const noexcept {
    Snapshot s; s.write_id = domain_->write_id; s.read_id = domain_->read_id;
    s.transfer = transfer_; s.transfer_channel = transfer_channel_;
    s.stopped = stopped_; s.retired = retired_; s.fault = fault_;
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        s.rings[c] = rings_[c]->snapshot(); s.producer[c] = describe(producer_[c]); s.consumer[c] = describe(consumer_[c]);
    }
    return s;
}
bool Store::valid(const WriteLease& t) const noexcept {
    if (t.domain_ != domain_ || !domain_->alive || !t.id_ || domain_->write_id != t.id_) return false;
    for (std::uint32_t c = 0; c < config_.channels; ++c)
        if (describe(t.chunks_[c]) != describe(producer_[c])) return false;
    return true;
}
bool Store::valid(const ReadLease& t) const noexcept {
    if (t.domain_ != domain_ || !domain_->alive || !t.id_ || domain_->read_id != t.id_) return false;
    for (std::uint32_t c = 0; c < config_.channels; ++c)
        if (describe(t.chunks_[c]) != describe(consumer_[c])) return false;
    return true;
}
WriteResult Store::reserve() noexcept {
    if (busy_) return {Status::busy, {}};
    if (fault_) return {Status::invariant_fault, {}};
    if (stopped_ || retired_) return {Status::closed, {}};
    if (domain_->write_id) return {Status::busy, {}};
    if (last_write_ == std::numeric_limits<std::uint64_t>::max()) return {Status::id_exhausted, {}};
    if (!sound() || !same_grants()) return {Status::invariant_fault, {}};
    Scope scope(*this); WriteLease t; t.domain_ = domain_; t.id_ = domain_->write_id = ++last_write_;
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        transfer_ = Transfer::reserve; transfer_channel_ = c;
        if (!ok(rings_[c]->get(0, capacity, producer_[c]))) return {fail(), std::move(t)};
        t.chunks_[c] = producer_[c];
    }
    return {Status::completed, std::move(t)};
}
bool Store::safe_writes(std::uint32_t c, std::int32_t raw, std::int32_t produced, std::int32_t published) const noexcept {
    const auto r = rings_[c]->snapshot(); const auto p = describe(producer_[c]);
    const std::int64_t start = p.offset, raw_end = start + raw, logical_end = start + p.bytes;
    if (raw_end > capacity + extension || produced > p.bytes || published > produced || raw < produced ||
        (raw_end > logical_end && logical_end < capacity)) return false;
    const std::array<Interval, 4> writes{{{start, raw_end},
        {0, std::max<std::int64_t>(0, start + produced - capacity)},
        {capacity + start, capacity + std::min<std::int64_t>(extension, start + published)},
        {0, std::max<std::int64_t>(0, start + published - capacity)}}};
    // A negative/empty mirror interval is intentionally empty (start>=extension).
    const auto queued_end = std::int64_t(r.read) + r.data;
    const std::array<Interval, 4> protected_bytes{{{r.read, std::min<std::int64_t>(capacity, queued_end)},
        {0, std::max<std::int64_t>(0, queued_end - capacity)},
        {capacity, std::min<std::int64_t>(capacity + extension, queued_end)},
        {consumer_[c].offset(), std::int64_t(consumer_[c].offset()) + consumer_[c].bytes()}}};
    for (const auto write : writes) for (const auto held : protected_bytes)
        if (overlaps(write, held)) return false;
    return true;
}
Status Store::write_and_publish(WriteLease& t, Pcm pcm, std::int32_t produced, std::int32_t published) noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::invariant_fault;
    if (retired_) return Status::closed;
    if (!valid(t)) return Status::invalid_lease;
    if (!sound() || !same_grants()) return Status::invariant_fault;
    if (produced < 0 || published < 0 || published > produced || produced > (capacity + extension) / 2 ||
        pcm.left.size() > (capacity + extension) / 2 ||
        (config_.channels == 1 ? !pcm.right.empty() : pcm.left.size() != pcm.right.size()) ||
        pcm.left.size() < static_cast<std::size_t>(produced)) return Status::invalid_count;
    const auto raw = static_cast<std::int32_t>(pcm.left.size() * 2);
    for (std::uint32_t c = 0; c < config_.channels; ++c)
        if (!safe_writes(c, raw, produced * 2, published * 2)) return Status::physical_conflict;
    Scope scope(*this);
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        const auto samples = c ? pcm.right : pcm.left;
        for (std::size_t i = 0; i < samples.size(); ++i) {
            const auto v = std::bit_cast<std::uint16_t>(samples[i]);
            staging_[2 * i] = static_cast<std::uint8_t>(v); staging_[2 * i + 1] = static_cast<std::uint8_t>(v >> 8);
        }
        sjrb::Chunk raw_span;
        if (!ok(rings_[c]->make_span(producer_[0].offset(), raw, raw_span)) ||
            !ok(raw_span.write(std::span<const std::uint8_t>(staging_).first(static_cast<std::size_t>(raw))))) return fail();
    }
    const auto overflow = producer_[0].offset() + produced * 2 - capacity;
    if (overflow > 0) for (std::uint32_t c = 0; c < config_.channels; ++c) {
        sjrb::Chunk from, to;
        const auto n = static_cast<std::size_t>(overflow);
        if (n > wrap_staging_.size() || !ok(rings_[c]->make_span(capacity, overflow, from)) ||
            !ok(rings_[c]->make_span(0, overflow, to)) || !ok(from.read(std::span(wrap_staging_).first(n))) ||
            !ok(to.write(std::span<const std::uint8_t>(wrap_staging_).first(n)))) return fail();
    }
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        sjrb::Chunk prefix, suffix;
        if (!ok(sjrb::Chunk::split(producer_[c], published * 2, prefix, suffix))) return fail();
        if (hooks_.publication) { View v; v.domain_ = domain_; v.chunk_ = prefix; hooks_.publication(hooks_.context, c, v); }
        transfer_ = Transfer::publish; transfer_channel_ = c;
        if (!ok(rings_[c]->put(1, prefix))) return fail();
        producer_[c] = suffix;
        transfer_ = Transfer::restore;
        if (!ok(rings_[c]->unget(0, producer_[c]))) return fail();
        producer_[c].clear();
    }
    domain_->write_id = 0; t.id_ = 0;
    return sound() ? Status::completed : fail();
}
Status Store::restore(WriteLease& t) noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::invariant_fault;
    if (!valid(t)) return Status::invalid_lease;
    if (!sound()) return Status::invariant_fault;
    // Preflight every actual Unget equation; Ring::completed can hide mismatch.
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        const auto r = rings_[c]->snapshot(); const auto p = describe(producer_[c]);
        if (p.bytes && (std::int64_t(r.write) + capacity - p.bytes) % capacity != p.offset % capacity) return Status::invariant_fault;
    }
    Scope scope(*this);
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        transfer_ = Transfer::restore; transfer_channel_ = c;
        if (!ok(rings_[c]->unget(0, producer_[c]))) return fail();
        producer_[c].clear();
    }
    domain_->write_id = 0; t.id_ = 0; return Status::completed;
}
ReadResult Store::read(std::int32_t requested) noexcept {
    if (busy_) return {Status::busy, {}};
    if (fault_) return {Status::invariant_fault, {}};
    if (retired_) return {Status::closed, {}};
    if (requested < 0 || (requested & 1)) return {Status::invalid_count, {}};
    if (domain_->read_id) return {Status::busy, {}};
    if (last_read_ == std::numeric_limits<std::uint64_t>::max()) return {Status::id_exhausted, {}};
    if (!sound() || !same_grants()) return {Status::invariant_fault, {}};
    Scope scope(*this); ReadLease t; t.domain_ = domain_; t.id_ = domain_->read_id = ++last_read_;
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        transfer_ = Transfer::read; transfer_channel_ = c;
        if (!ok(rings_[c]->get(1, requested, consumer_[c]))) return {fail(), std::move(t)};
        t.chunks_[c] = consumer_[c];
    }
    return {Status::completed, std::move(t)};
}
Status Store::finish(ReadLease& t) noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::invariant_fault;
    if (!valid(t)) return Status::invalid_lease;
    if (!sound()) return Status::invariant_fault;
    Scope scope(*this);
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        transfer_ = Transfer::finish_read; transfer_channel_ = c;
        if (!ok(rings_[c]->put(0, consumer_[c]))) return fail();
        consumer_[c].clear();
    }
    domain_->read_id = 0; t.id_ = 0; return Status::completed;
}
Status Store::stop() noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::invariant_fault;
    stopped_ = true; return Status::completed;
}
Status Store::retire() noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::invariant_fault;
    if (retired_) return Status::completed;
    if (!stopped_ || domain_->write_id || domain_->read_id) return Status::busy;
    for (std::uint32_t c = 0; c < config_.channels; ++c) if (rings_[c]->snapshot().data) return Status::busy;
    if (!sound()) return Status::invariant_fault;
    retired_ = true; domain_->alive = false; return Status::completed;
}
Status Store::read_backing(std::uint32_t c, std::span<std::uint8_t> out) const noexcept {
    if (c >= config_.channels) return Status::invalid_configuration;
    return rings_[c]->read_backing(out) == sjrb::Status::completed ? Status::completed : Status::invalid_count;
}
} // namespace reo::native::adx_pcm
