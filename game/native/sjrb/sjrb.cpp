#include "sjrb.hpp"

#include <algorithm>
#include <bit>
#include <limits>
#include <stdexcept>
#include <vector>

namespace reo::native::sjrb {
namespace {
constexpr std::int32_t add(std::int32_t a, std::int32_t b) noexcept {
    return std::bit_cast<std::int32_t>(std::bit_cast<std::uint32_t>(a) + std::bit_cast<std::uint32_t>(b));
}
constexpr std::int32_t sub(std::int32_t a, std::int32_t b) noexcept {
    return std::bit_cast<std::int32_t>(std::bit_cast<std::uint32_t>(a) - std::bit_cast<std::uint32_t>(b));
}
}

struct Storage final {
    std::vector<std::uint8_t> bytes;
    std::uint64_t incarnation{1};
    Storage(std::size_t size, std::uint8_t fill) : bytes(size, fill) {}
};

Chunk Chunk::null(std::int32_t bytes) noexcept { Chunk c; c.bytes_ = bytes; return c; }
bool Chunk::is_null() const noexcept { return !storage_; }
std::int32_t Chunk::offset() const noexcept { return offset_; }
std::int32_t Chunk::bytes() const noexcept { return bytes_; }
std::uint64_t Chunk::incarnation() const noexcept { return incarnation_; }
void Chunk::set_bytes(std::int32_t bytes) noexcept { bytes_ = bytes; }
void Chunk::clear() noexcept { *this = {}; }

Status Chunk::check_extent() const noexcept {
    if (!storage_) return Status::invalid_span;
    if (incarnation_ != storage_->incarnation) return Status::stale_incarnation;
    if (offset_ < 0 || bytes_ < 0 || std::size_t(offset_) > storage_->bytes.size() ||
        std::size_t(bytes_) > storage_->bytes.size() - std::size_t(offset_)) return Status::invalid_span;
    return Status::completed;
}

Status Chunk::read(std::span<std::uint8_t> output, std::size_t relative) const noexcept {
    const auto status = check_extent();
    if (status != Status::completed) return status;
    if (relative > std::size_t(bytes_) || output.size() > std::size_t(bytes_) - relative) return Status::invalid_span;
    std::copy_n(storage_->bytes.data() + offset_ + relative, output.size(), output.begin());
    return Status::completed;
}

Status Chunk::write(std::span<const std::uint8_t> input, std::size_t relative) noexcept {
    const auto status = check_extent();
    if (status != Status::completed) return status;
    if (relative > std::size_t(bytes_) || input.size() > std::size_t(bytes_) - relative) return Status::invalid_span;
    std::copy(input.begin(), input.end(), storage_->bytes.begin() + offset_ + relative);
    return Status::completed;
}

Status Chunk::split(const Chunk& input, std::int32_t prefix, Chunk& first, Chunk& remainder) noexcept {
    if (&input == &first || &input == &remainder || &first == &remainder || prefix < 0) return Status::invalid_span;
    if (input.is_null()) {
        if (input.bytes_ != 0) return Status::invalid_span;
        first.clear(); remainder.clear(); return Status::completed;
    }
    const auto status = input.check_extent();
    if (status != Status::completed) return status;
    Chunk left = input, right = input;
    left.bytes_ = std::min(prefix, input.bytes_);
    right.bytes_ = input.bytes_ - left.bytes_;
    if (right.bytes_) right.offset_ += left.bytes_;
    else right.clear();
    first = std::move(left); remainder = std::move(right);
    return Status::completed;
}

class Ring::Scope final {
public:
    Scope(Ring& ring, bool guarded) noexcept : ring_(ring), hooks_(ring.hooks_), guarded_(guarded) {
        ring_.busy_ = true;
        if (guarded_ && hooks_.enter) hooks_.enter(hooks_.context);
    }
    ~Scope() {
        if (guarded_ && hooks_.leave) hooks_.leave(hooks_.context);
        ring_.busy_ = false;
    }
    void error() const noexcept { if (hooks_.error) hooks_.error(hooks_.context, -3); }
    Scope(const Scope&) = delete;
    Scope& operator=(const Scope&) = delete;
private:
    Ring& ring_;
    Hooks hooks_;
    bool guarded_;
};

bool Ring::admits_geometry(std::int32_t capacity, std::int32_t extension) noexcept {
    return capacity > 0 && extension >= 0 && extension <= capacity &&
           extension <= std::numeric_limits<std::int32_t>::max() - capacity;
}

Ring::Ring(std::int32_t capacity, std::int32_t extension, Hooks hooks, std::uint8_t initial_byte)
    : hooks_(hooks) {
    if (!admits_geometry(capacity, extension)) throw std::invalid_argument("SJRB backing geometry");
    storage_ = std::make_shared<Storage>(std::size_t(capacity) + std::size_t(extension), initial_byte);
    state_.capacity = capacity; state_.extension = extension; state_.free = capacity; state_.incarnation = 1;
}
Ring::~Ring() = default;
Snapshot Ring::snapshot() const noexcept { return state_; }
std::size_t Ring::backing_size() const noexcept { return storage_->bytes.size(); }

Status Ring::set_hooks(Hooks hooks) noexcept {
    if (busy_) return Status::reentrant_call;
    hooks_ = hooks;
    return Status::completed;
}

Status Ring::reset() noexcept {
    if (busy_) return Status::reentrant_call;
    if (state_.incarnation == std::numeric_limits<std::uint64_t>::max()) return Status::incarnation_exhausted;
    Scope scope(*this, true);
    ++state_.incarnation;
    storage_->incarnation = state_.incarnation;
    state_.data = 0; state_.free = state_.capacity; state_.write = 0; state_.read = 0; state_.totals = {};
    return Status::completed;
}

Status Ring::check_span(const Chunk& span) const noexcept {
    if (!span.storage_) return Status::invalid_span;
    if (span.storage_ != storage_) return Status::foreign_storage;
    return span.check_extent();
}

Status Ring::check_position(std::uint32_t pool) const noexcept {
    const auto position = pool ? state_.read : state_.write;
    return position >= 0 && position < state_.capacity ? Status::completed : Status::unsafe_state;
}

std::int32_t Ring::grant(std::uint32_t pool, std::int32_t requested) const noexcept {
    const auto position = pool ? state_.read : state_.write;
    const auto available = pool ? state_.data : state_.free;
    return std::min(std::min(add(sub(state_.capacity, position), state_.extension), available), requested);
}

Status Ring::get(std::uint32_t pool, std::int32_t requested, Chunk& output) noexcept {
    if (busy_) return Status::reentrant_call;
    if (pool <= 1) {
        if (requested < 0) return Status::unsafe_request;
        if (check_position(pool) != Status::completed || (pool ? state_.data : state_.free) < 0) return Status::unsafe_state;
    }
    Scope scope(*this, true);
    if (pool > 1) { output.clear(); scope.error(); return Status::completed; }
    const auto bytes = grant(pool, requested);
    auto& position = pool ? state_.read : state_.write;
    auto& available = pool ? state_.data : state_.free;
    output.storage_ = storage_; output.incarnation_ = state_.incarnation; output.offset_ = position; output.bytes_ = bytes;
    position = add(position, bytes) % state_.capacity;
    available = sub(available, bytes);
    state_.totals[2 * pool] += std::bit_cast<std::uint32_t>(bytes);
    return Status::completed;
}

Status Ring::put(std::uint32_t pool, Chunk& span) noexcept {
    if (span.bytes_ <= 0 || span.is_null()) return Status::completed;
    if (busy_) return Status::reentrant_call;
    const auto status = check_span(span);
    if (status != Status::completed) return status;
    const auto before_storage = span.storage_; const auto before_epoch = span.incarnation_;
    const auto before_offset = span.offset_; const auto before_bytes = span.bytes_;
    Scope scope(*this, true);
    if (span.storage_ != before_storage || span.incarnation_ != before_epoch ||
        span.offset_ != before_offset || span.bytes_ != before_bytes) return Status::callback_contract_violation;
    if (pool == 1) {
        state_.data = add(state_.data, span.bytes_);
        const auto offset = span.offset_, bytes = span.bytes_;
        if (offset < state_.extension) {
            const auto size = std::min(sub(state_.extension, offset), bytes);
            std::copy_n(storage_->bytes.begin() + offset, size,
                        storage_->bytes.begin() + state_.capacity + offset);
        }
        const auto end = add(offset, bytes);
        if (state_.capacity < end) {
            const auto size = std::min(sub(end, state_.capacity), bytes);
            std::copy_n(storage_->bytes.begin() + sub(end, size), size, storage_->bytes.begin());
        }
        state_.totals[3] += std::bit_cast<std::uint32_t>(span.bytes_);
    } else if (pool == 0) {
        state_.free = add(state_.free, span.bytes_);
        state_.totals[1] += std::bit_cast<std::uint32_t>(span.bytes_);
    } else {
        span.clear(); scope.error();
    }
    return Status::completed;
}

Status Ring::unget(std::uint32_t pool, Chunk& span) noexcept {
    if (span.bytes_ <= 0 || span.is_null()) return Status::completed;
    if (busy_) return Status::reentrant_call;
    const auto status = check_span(span);
    if (status != Status::completed) return status;
    const auto before_storage = span.storage_; const auto before_epoch = span.incarnation_;
    const auto before_offset = span.offset_; const auto before_bytes = span.bytes_;
    Scope scope(*this, true);
    if (span.storage_ != before_storage || span.incarnation_ != before_epoch ||
        span.offset_ != before_offset || span.bytes_ != before_bytes) return Status::callback_contract_violation;
    if (pool > 1) { span.clear(); scope.error(); return Status::completed; }
    auto& position = pool ? state_.read : state_.write;
    auto& available = pool ? state_.data : state_.free;
    const auto previous = sub(add(position, state_.capacity), span.bytes_) % state_.capacity;
    if (previous == span.offset_ % state_.capacity) {
        position = previous;
        available = add(available, span.bytes_);
    } else {
        scope.error();
    }
    // Original rereads length even after a returning mismatch callback.
    state_.totals[2 * pool] -= std::bit_cast<std::uint32_t>(span.bytes_);
    return Status::completed;
}

Status Ring::peek(std::uint32_t pool, std::int32_t requested, std::int32_t& granted, bool& fits) noexcept {
    if (busy_) return Status::reentrant_call;
    if (pool <= 1 && check_position(pool) != Status::completed) return Status::unsafe_state;
    Scope scope(*this, true);
    std::int32_t value = 0;
    if (pool > 1) scope.error();
    else value = grant(pool, requested);
    granted = value;
    fits = value == requested;
    return Status::completed;
}

Status Ring::count(std::uint32_t pool, std::int32_t& output) noexcept {
    if (pool <= 1) { output = pool ? state_.data : state_.free; return Status::completed; }
    if (busy_) return Status::reentrant_call;
    Scope scope(*this, false);
    scope.error(); output = 0;
    return Status::completed;
}

Status Ring::set_total(std::uint32_t pool, std::uint32_t which, std::uint32_t value) noexcept {
    if (busy_) return Status::reentrant_call;
    if (pool > 1 || which > 1) return Status::invalid_selector;
    state_.totals[2 * pool + which] = value;
    return Status::completed;
}
Status Ring::total(std::uint32_t pool, std::uint32_t which, std::uint32_t& output) const noexcept {
    if (pool > 1 || which > 1) return Status::invalid_selector;
    output = state_.totals[2 * pool + which];
    return Status::completed;
}

Status Ring::make_span(std::int32_t offset, std::int32_t bytes, Chunk& output) const noexcept {
    if (busy_) return Status::reentrant_call;
    if (offset < 0 || std::size_t(offset) > backing_size() ||
        (bytes > 0 && std::size_t(bytes) > backing_size() - std::size_t(offset))) return Status::invalid_span;
    Chunk result;
    result.storage_ = storage_; result.incarnation_ = state_.incarnation; result.offset_ = offset; result.bytes_ = bytes;
    output = std::move(result);
    return Status::completed;
}

Status Ring::read_backing(std::span<std::uint8_t> output) const noexcept {
    if (output.size() != backing_size()) return Status::invalid_span;
    std::copy(storage_->bytes.begin(), storage_->bytes.end(), output.begin());
    return Status::completed;
}

} // namespace reo::native::sjrb
