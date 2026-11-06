#include "adxt_refill.hpp"

#include <algorithm>
#include <stdexcept>
#include <utility>

namespace reo::native::adxt_refill {
namespace {
constexpr std::int32_t sector_bytes = 2048;
bool valid_config(const Config& c) noexcept {
    return (c.capacity == 2048 || c.capacity == 4096 || c.capacity == 8192) &&
        c.start_sector >= 0 && c.start_sector <= 0x7FFFFFFF / sector_bytes &&
        c.byte_length >= 0 && c.byte_length % sector_bytes == 0 &&
        c.threshold >= 0 && c.threshold <= c.capacity &&
        c.maximum_request_bytes >= 0 && c.maximum_request_bytes <= c.capacity &&
        c.maximum_sectors >= 0 && c.maximum_sectors <= 512 &&
        c.target_sectors >= -1 && c.target_sectors <= c.byte_length / sector_bytes &&
        c.finite_sector_limit >= 0 && c.finite_sector_limit <= 0xFFFFF &&
        c.retry_limit >= -1 && c.retry_limit <= 127 && c.maximum_id != 0;
}
std::int32_t checked_capacity(const Config& c) {
    if (!valid_config(c)) throw std::invalid_argument("Unsupported encoded-source configuration");
    return c.capacity;
}
resource_io::Config read_config(std::size_t bytes) {
    if (!bytes || bytes > 8192) throw std::invalid_argument("Bounded encoded-source read limit");
    resource_io::Config config;
    config.max_requests = 1; config.max_read_bytes = bytes; config.byte_budget = bytes * 2;
    return config;
}
class AsyncBackend final : public Backend {
public:
    explicit AsyncBackend(std::size_t bytes) : reader_(read_config(bytes)) {}
    Acceptance submit(std::shared_ptr<const resources::ByteView> view, std::uint64_t offset,
                      std::uint32_t sectors, std::uint64_t id) noexcept override {
        if (pending_ || closed_) return {0, false};
        if (!sectors) return {0, false};
        const auto result = reader_.submit(std::move(view), offset, std::size_t(sectors) * sector_bytes);
        if (result.status != resource_io::SubmitStatus::accepted) return {0, true};
        ticket_ = result.ticket; id_ = id; pending_ = true;
        return {static_cast<std::int32_t>(sectors), false};
    }
    Completion poll() noexcept override {
        if (!pending_) return {};
        auto result = reader_.poll(ticket_);
        if (result.status == resource_io::PollStatus::pending) return {BackendState::pending, id_, {}};
        pending_ = false;
        if (result.status != resource_io::PollStatus::ready || result.outcome.status != resources::Status::ok)
            return {BackendState::error, id_, {}};
        return {BackendState::complete, id_, std::move(result.outcome.bytes)};
    }
    bool shutdown_and_join() noexcept override {
        if (pending_) return false;
        closed_ = true; return reader_.shutdown_and_join();
    }
private:
    resource_io::AsyncReadOwner reader_;
    resource_io::Ticket ticket_;
    std::uint64_t id_{};
    bool pending_{}, closed_{};
};
} // namespace

struct LeaseIdentity { bool alive{true}; std::uint64_t epoch{1}, active{}; };
class EncodedSource::Scope final {
public:
    explicit Scope(EncodedSource& owner) noexcept : owner_(owner), entered_(!owner.busy_) {
        if (entered_) owner_.busy_ = true;
    }
    ~Scope() { if (entered_) owner_.busy_ = false; }
    explicit operator bool() const noexcept { return entered_; }
private:
    EncodedSource& owner_; bool entered_;
};

std::unique_ptr<Backend> make_async_backend(std::size_t bytes) { return std::make_unique<AsyncBackend>(bytes); }
DataLease::DataLease(DataLease&& other) noexcept : identity_(std::move(other.identity_)),
    chunk_(std::move(other.chunk_)), epoch_(other.epoch_), id_(std::exchange(other.id_, 0)) {}
std::int32_t DataLease::bytes() const noexcept { return id_ ? chunk_.bytes() : 0; }
std::int32_t DataLease::offset() const noexcept { return id_ ? chunk_.offset() : 0; }
Status DataLease::read_into(std::span<std::uint8_t> output, std::size_t relative) const noexcept {
    if (!identity_ || !id_ || !identity_->alive || identity_->epoch != epoch_ || identity_->active != id_)
        return Status::invalid_lease;
    return chunk_.read(output, relative) == sjrb::Status::completed ? Status::completed : Status::invalid_count;
}

EncodedSource::EncodedSource(Config config, std::shared_ptr<const resources::ByteView> view,
        std::unique_ptr<Backend> backend, Hooks hooks, InitialBuffer initial)
    : config_(config), hooks_(hooks), ring_(checked_capacity(config), 36, {}, 0xA5),
      view_(std::move(view)), backend_(std::move(backend)), identity_(std::make_shared<LeaseIdentity>()) {
    if (!backend_ || !valid_view(view_) || initial.position < 0 || initial.position >= config.capacity ||
        initial.data.size() > static_cast<std::size_t>(config.capacity))
        throw std::invalid_argument("Invalid retained encoded source or prepared buffer");
    // Constructor-only prepared input, through actual ring operations. No hooks
    // observe a partially constructed owner; no numeric ring state is restored.
    const auto advance = [&](std::int32_t count) {
        sjrb::Chunk chunk;
        if (ring_.get(0, count, chunk) != sjrb::Status::completed || chunk.bytes() != count ||
            ring_.put(1, chunk) != sjrb::Status::completed ||
            ring_.get(1, count, chunk) != sjrb::Status::completed || chunk.bytes() != count ||
            ring_.put(0, chunk) != sjrb::Status::completed) throw std::invalid_argument("Prepared cursor refused");
    };
    if (initial.position) advance(initial.position);
    std::size_t copied = 0;
    while (copied < initial.data.size()) {
        sjrb::Chunk chunk;
        const auto remaining = static_cast<std::int32_t>(initial.data.size() - copied);
        if (ring_.get(0, remaining, chunk) != sjrb::Status::completed || chunk.bytes() <= 0 ||
            chunk.write(initial.data.subspan(copied, static_cast<std::size_t>(chunk.bytes()))) != sjrb::Status::completed ||
            ring_.put(1, chunk) != sjrb::Status::completed) throw std::invalid_argument("Prepared data refused");
        copied += static_cast<std::size_t>(chunk.bytes());
    }
    if (ring_.set_hooks(hooks.ring) != sjrb::Status::completed) throw std::invalid_argument("Ring hooks refused");
    state_.state = config.byte_length ? 2 : 3; state_.service_requested = true;
    state_.source_open = true; state_.epoch = 1;
    if (config_.target_sectors == -1) config_.target_sectors = config_.byte_length / sector_bytes;
}
EncodedSource::~EncodedSource() {
    // Private backend teardown retains/join its results before ring destruction;
    // this emergency path is deliberately different from normal draining stop.
    identity_->alive = false;
    backend_.reset();
}
bool EncodedSource::valid_view(const std::shared_ptr<const resources::ByteView>& view) const noexcept {
    if (!view) return false;
    const auto begin = std::uint64_t(config_.start_sector) * sector_bytes;
    return begin <= view->size() && std::uint64_t(config_.byte_length) <= view->size() - begin;
}
Snapshot EncodedSource::snapshot() const noexcept {
    auto result = state_; result.ring = ring_.snapshot();
    result.producer_offset = producer_.is_null() ? 0 : producer_.offset(); result.producer_bytes = producer_.bytes();
    result.consumer_offset = consumer_.is_null() ? 0 : consumer_.offset(); result.consumer_bytes = consumer_.bytes();
    return result;
}
Status EncodedSource::fail(Status status, bool terminal) noexcept {
    state_.last_error = status; if (terminal) state_.state = 4; return status;
}
Status EncodedSource::return_producer(bool error) noexcept {
    if (ring_.unget(0, producer_) != sjrb::Status::completed) return fail(Status::ring_failure, true);
    producer_.clear(); state_.in_flight = false;
    if (error && config_.retry_limit >= 0) {
        if (state_.retries >= config_.retry_limit) state_.state = 4;
        else ++state_.retries;
    }
    return Status::completed;
}
Status EncodedSource::publish(Completion& result) noexcept {
    const auto size = static_cast<std::size_t>(state_.accepted_sectors) * sector_bytes;
    if (result.request_id != state_.request_id || result.bytes.size() != size) {
        (void)return_producer(false); return fail(Status::provider_protocol, true);
    }
    if (producer_.write({reinterpret_cast<const std::uint8_t*>(result.bytes.data()), size}) != sjrb::Status::completed) {
        (void)return_producer(false); return fail(Status::ring_failure, true);
    }
    state_.in_flight = false;
    sjrb::Chunk prefix, suffix;
    if (sjrb::Chunk::split(producer_, static_cast<std::int32_t>(size), prefix, suffix) != sjrb::Status::completed ||
        ring_.put(1, prefix) != sjrb::Status::completed || ring_.unget(0, suffix) != sjrb::Status::completed)
        return fail(Status::ring_failure, true);
    state_.cumulative_bytes += static_cast<std::int32_t>(size);
    state_.progress_sectors += state_.accepted_sectors; producer_.clear();
    if (state_.progress_sectors == config_.target_sectors && hooks_.target) hooks_.target(hooks_.context, snapshot());
    if (state_.progress_sectors >= config_.byte_length / sector_bytes ||
        state_.cumulative_bytes / sector_bytes >= config_.finite_sector_limit) state_.state = 3;
    state_.retries = 0;
    return Status::completed;
}
Status EncodedSource::service() noexcept {
    Scope scope(*this); if (!scope) return Status::reentrant_call;
    if (state_.joined) return Status::closed;
    if (!state_.in_flight) {
        if (state_.stop_requested) { if (!state_.service_requested) state_.state = 1; state_.stop_requested = false; }
        if (state_.close_requested) { view_.reset(); state_.source_open = false; state_.close_requested = false; }
        state_.service_requested = false;
    }
    if (state_.state != 2 || !state_.source_open) return Status::completed;
    auto result = backend_->poll();
    if (state_.in_flight) {
        if (result.state == BackendState::pending || result.state == BackendState::idle) return Status::completed;
        if (result.request_id != state_.request_id) {
            // A malformed backend does not supply a proven retirement fence.
            return fail(Status::provider_protocol, true);
        }
        if (result.state == BackendState::complete) return publish(result);
        // Original pending-error path clears inflight before returning its span;
        // declined submission clears it after the return instead.
        state_.in_flight = false;
        const auto returned = return_producer(true);
        if (returned != Status::completed) return returned;
        return fail(Status::provider_failure);
    }
    if (result.state == BackendState::pending || result.state == BackendState::complete)
        return fail(Status::provider_protocol, true);
    if (state_.paused == 1 || state_.stop_requested || state_.shutting_down) return Status::completed;
    const auto available = ring_.snapshot().free;
    if (config_.capacity - available >= config_.threshold) return Status::completed;
    if (last_request_ == config_.maximum_id) return fail(Status::id_exhausted);
    state_.in_flight = true;
    if (ring_.get(0, config_.maximum_request_bytes, producer_) != sjrb::Status::completed) {
        state_.in_flight = false;
        return fail(Status::ring_failure, true);
    }
    const auto sectors = std::min({producer_.bytes() / sector_bytes,
        config_.target_sectors - state_.progress_sectors,
        config_.byte_length / sector_bytes - state_.progress_sectors, config_.maximum_sectors});
    if (sectors < 0) { (void)return_producer(false); return fail(Status::invalid_configuration, true); }
    state_.request_id = ++last_request_; state_.in_flight = true;
    const auto offset = (std::uint64_t(config_.start_sector) + static_cast<std::uint32_t>(state_.progress_sectors)) * sector_bytes;
    const auto accepted = backend_->submit(view_, offset, static_cast<std::uint32_t>(sectors), state_.request_id);
    state_.accepted_sectors = accepted.sectors;
    if (accepted.sectors > sectors) return fail(Status::provider_protocol, true); // Retain grant: retirement unproven.
    if (accepted.sectors > 0) return Status::completed;
    const auto returned = return_producer(accepted.error);
    if (returned != Status::completed) return returned;
    return accepted.error ? fail(Status::provider_failure) : Status::completed;
}
BorrowResult EncodedSource::borrow_data(std::int32_t maximum) noexcept {
    Scope scope(*this); if (!scope) return {Status::reentrant_call, {}};
    if (state_.joined || state_.shutting_down) return {Status::closed, {}};
    if (identity_->active) return {Status::busy, {}};
    if (maximum < 0 || maximum > config_.capacity) return {Status::invalid_count, {}};
    if (last_consumer_ == config_.maximum_id) return {Status::id_exhausted, {}};
    if (ring_.get(1, maximum, consumer_) != sjrb::Status::completed) return {fail(Status::ring_failure, true), {}};
    DataLease lease; lease.identity_ = identity_; lease.epoch_ = state_.epoch;
    lease.id_ = ++last_consumer_; lease.chunk_ = consumer_;
    identity_->active = lease.id_; state_.consumer_id = lease.id_;
    return {Status::completed, std::move(lease)};
}
Status EncodedSource::finish_data(DataLease& lease, std::int32_t consumed) noexcept {
    Scope scope(*this); if (!scope) return Status::reentrant_call;
    if (lease.identity_.get() != identity_.get() || !lease.id_ || lease.epoch_ != state_.epoch || lease.id_ != identity_->active)
        return Status::invalid_lease;
    if (consumed < 0 || consumed > consumer_.bytes()) return Status::invalid_count;
    sjrb::Chunk prefix, suffix;
    if (sjrb::Chunk::split(consumer_, consumed, prefix, suffix) != sjrb::Status::completed ||
        ring_.put(0, prefix) != sjrb::Status::completed || ring_.unget(1, suffix) != sjrb::Status::completed)
        return fail(Status::ring_failure, true);
    consumer_.clear(); identity_->active = 0; state_.consumer_id = 0;
    lease.id_ = 0; lease.chunk_.clear(); lease.identity_.reset();
    return Status::completed;
}
Status EncodedSource::set_paused(std::uint8_t value) noexcept {
    Scope scope(*this); if (!scope) return Status::reentrant_call;
    if (state_.shutting_down || state_.joined) return Status::closed;
    state_.paused = value; return Status::completed;
}
Status EncodedSource::request_stop() noexcept {
    Scope scope(*this); if (!scope) return Status::reentrant_call;
    if (state_.joined) return Status::closed;
    if (state_.state == 2 && state_.in_flight) { state_.stop_requested = true; state_.service_requested = false; }
    else state_.state = 1;
    return Status::completed;
}
Status EncodedSource::request_close() noexcept {
    const auto status = request_stop(); if (status != Status::completed) return status;
    state_.close_requested = state_.source_open; return Status::completed;
}
Status EncodedSource::reset_inner() noexcept {
    const auto ring = ring_.snapshot();
    if (state_.in_flight || identity_->active || ring.data || ring.free != config_.capacity) return Status::busy;
    if (state_.epoch == config_.maximum_id) return Status::id_exhausted;
    if (ring_.reset() != sjrb::Status::completed) return fail(Status::ring_failure, true);
    ++state_.epoch; identity_->epoch = state_.epoch;
    state_.state = config_.byte_length ? 2 : 3; state_.progress_sectors = state_.cumulative_bytes = state_.retries = 0;
    state_.accepted_sectors = 0; state_.service_requested = true; state_.stop_requested = state_.close_requested = false;
    state_.last_error = Status::completed; return Status::completed;
}
Status EncodedSource::reset_quiescent() noexcept {
    Scope scope(*this); if (!scope) return Status::reentrant_call;
    if (state_.shutting_down || !state_.source_open) return Status::closed;
    if (state_.state != 1) return Status::busy;
    return reset_inner();
}
Status EncodedSource::replace_source(std::shared_ptr<const resources::ByteView> view) noexcept {
    Scope scope(*this); if (!scope) return Status::reentrant_call;
    if (state_.shutting_down || state_.joined) return Status::closed;
    if (!valid_view(view)) return Status::invalid_source;
    if (state_.source_open || state_.state != 1) return Status::busy;
    const auto status = reset_inner();
    if (status == Status::completed) { view_ = std::move(view); state_.source_open = true; }
    return status;
}
Status EncodedSource::begin_shutdown() noexcept {
    const auto status = request_stop(); if (status != Status::completed) return status;
    state_.shutting_down = true; return Status::completed;
}
bool EncodedSource::finalize_shutdown_and_join() noexcept {
    if (busy_ || !state_.shutting_down || state_.in_flight || identity_->active) return false;
    if (!backend_->shutdown_and_join()) return false;
    state_.joined = true; state_.source_open = false; view_.reset(); identity_->alive = false;
    return true;
}

} // namespace reo::native::adxt_refill
