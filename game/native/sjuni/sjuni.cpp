#include "sjuni.hpp"

#include <algorithm>
#include <bit>
#include <stdexcept>

namespace reo::native::sjuni {
namespace {
std::size_t checked_capacity(std::uint32_t count) {
    if (count == 0 || count > static_cast<std::uint32_t>(INT32_MAX)) {
        throw std::invalid_argument("SJUNI native node capacity must be positive int32");
    }
    return count;
}

bool add_offset(std::int64_t first, std::int64_t second, std::int64_t& result) noexcept {
    if ((second > 0 && first > INT64_MAX - second) ||
        (second < 0 && first < INT64_MIN - second)) {
        return false;
    }
    result = first + second;
    return true;
}

bool positive_span_end(const Span& span, std::int64_t& end) noexcept {
    return span.region != 0 && span.bytes > 0 && add_offset(span.offset, span.bytes, end);
}

bool merge_length(std::int32_t first, std::int32_t second) noexcept {
    return static_cast<std::int64_t>(first) + second <= INT32_MAX;
}
} // namespace

Pool::Pool(std::uint32_t capacity, std::uint8_t mode, Hooks hooks)
    : mode_(mode), nodes_(checked_capacity(capacity)), visited_(nodes_.size()), hooks_(hooks) {
    reset();
}

std::uint32_t Pool::capacity() const noexcept { return static_cast<std::uint32_t>(nodes_.size()); }
std::uint8_t Pool::mode() const noexcept { return mode_; }
NodeId Pool::free_head() const noexcept { return free_head_; }
const std::array<NodeId, 4>& Pool::heads() const noexcept { return heads_; }
std::span<const Node> Pool::nodes() const noexcept { return nodes_; }
void Pool::set_hooks(Hooks hooks) noexcept { hooks_ = hooks; }

void Pool::reset() noexcept {
    for (NodeId index = 0; index < capacity(); ++index) {
        nodes_[index] = Node{index + 1 < capacity() ? index + 1 : no_node, {}};
    }
    free_head_ = 0;
    heads_.fill(no_node);
}

Result Pool::import_state(const Snapshot& state) noexcept {
    if (state.nodes.size() != nodes_.size()) return Result::capacity_mismatch;
    std::fill(visited_.begin(), visited_.end(), 0);
    std::size_t seen = 0;
    auto walk = [&](NodeId current, bool queued) {
        while (current != no_node) {
            if (current >= capacity() || visited_[current] != 0) return Result::unsupported_state;
            visited_[current] = 1;
            ++seen;
            const auto& node = state.nodes[current];
            if (queued) {
                std::int64_t end;
                if (node.span.region == 0 || node.span.bytes <= 0) return Result::unsupported_state;
                if (!positive_span_end(node.span, end)) return Result::unsupported_arithmetic;
            }
            current = node.next;
        }
        return Result::completed;
    };
    auto result = walk(state.free_head, false);
    if (result != Result::completed) return result;
    for (auto head : state.heads) {
        result = walk(head, true);
        if (result != Result::completed) return result;
    }
    if (seen != nodes_.size()) return Result::unsupported_state;
    std::copy(state.nodes.begin(), state.nodes.end(), nodes_.begin());
    free_head_ = state.free_head;
    heads_ = state.heads;
    mode_ = state.mode;
    return Result::completed;
}

void Pool::export_state(Snapshot& state) const {
    state.mode = mode_;
    state.free_head = free_head_;
    state.heads = heads_;
    state.nodes.assign(nodes_.begin(), nodes_.end());
}

Snapshot Pool::snapshot() const {
    Snapshot state;
    export_state(state);
    return state;
}

NodeId Pool::tail(std::uint32_t queue) const noexcept {
    auto node = heads_[queue];
    if (node == no_node) return no_node;
    while (nodes_[node].next != no_node) node = nodes_[node].next;
    return node;
}

Result Pool::check_get(std::uint32_t queue, std::int32_t request) const noexcept {
    if (queue >= heads_.size()) return Result::completed;
    const auto head = heads_[queue];
    if (head == no_node || mode_ != 1 || request >= nodes_[head].span.bytes) return Result::completed;
    const auto& original = nodes_[head].span;
    const auto remainder = static_cast<std::int64_t>(original.bytes) - request;
    std::int64_t pointer;
    if (remainder > INT32_MAX || !add_offset(original.offset, request, pointer)) {
        return Result::unsupported_arithmetic;
    }
    return Result::completed;
}

Result Pool::check_put(std::uint32_t queue, const Span& span) const noexcept {
    if (queue >= heads_.size() || span.bytes <= 0 || span.region == 0) return Result::completed;
    std::int64_t end;
    if (!positive_span_end(span, end)) return Result::unsupported_arithmetic;
    const auto last = tail(queue);
    if (mode_ == 1 && last != no_node) {
        const auto& previous = nodes_[last].span;
        const auto previous_end = previous.offset + previous.bytes; // Invariant checked on import/publication.
        if (previous.region == span.region && previous_end == span.offset &&
            !merge_length(previous.bytes, span.bytes)) return Result::unsupported_arithmetic;
    }
    return Result::completed;
}

Result Pool::check_unget(std::uint32_t queue, const Span& span) const noexcept {
    if (queue >= heads_.size() || span.bytes <= 0 || span.region == 0) return Result::completed;
    std::int64_t end;
    if (!positive_span_end(span, end)) return Result::unsupported_arithmetic;
    const auto head = heads_[queue];
    if (mode_ == 1 && head != no_node) {
        const auto& next = nodes_[head].span;
        if (next.region == span.region && end == next.offset && !merge_length(span.bytes, next.bytes)) {
            return Result::unsupported_arithmetic;
        }
    }
    return Result::completed;
}

void Pool::enter() {
    const auto callback = hooks_.enter;
    if (callback) callback(hooks_.context);
}
void Pool::leave() {
    const auto callback = hooks_.leave;
    if (callback) callback(hooks_.context);
}
void Pool::error() {
    const auto callback = hooks_.error;
    if (callback) callback(hooks_.context, -3);
}

Result Pool::get(std::uint32_t queue, std::int32_t request, Span& output) {
    const auto admission = check_get(queue, request);
    if (admission != Result::completed) return admission;
    if (queue >= heads_.size()) {
        error();
        output = {};
        return Result::completed;
    }
    enter();
    if (check_get(queue, request) != Result::completed) {
        leave();
        return Result::callback_contract_violation;
    }
    const auto head = heads_[queue];
    if (head == no_node) {
        output = {};
    } else if (request >= nodes_[head].span.bytes) {
        output = nodes_[head].span;
        heads_[queue] = nodes_[head].next;
        nodes_[head].next = free_head_;
        free_head_ = head;
    } else if (mode_ == 1) {
        const auto original = nodes_[head].span;
        output = Span{original.region, original.offset, request};
        nodes_[head].span.offset = original.offset + request;
        nodes_[head].span.bytes = static_cast<std::int32_t>(static_cast<std::int64_t>(original.bytes) - request);
    } else {
        output = {};
    }
    leave();
    return Result::completed;
}

Result Pool::put(std::uint32_t queue, const Span& span) {
    const auto admission = check_put(queue, span);
    if (admission != Result::completed) return admission;
    if (queue >= heads_.size()) { error(); return Result::completed; }
    if (span.bytes <= 0 || span.region == 0) return Result::completed;
    enter();
    // Original fields are reread after enter. A changed but still admitted span
    // is supported; a changed invalid domain cannot be an original fallback.
    if (span.bytes <= 0 || span.region == 0 || check_put(queue, span) != Result::completed) {
        leave();
        return Result::callback_contract_violation;
    }
    const auto last = tail(queue);
    if (mode_ == 1 && last != no_node && nodes_[last].span.region == span.region &&
        nodes_[last].span.offset + nodes_[last].span.bytes == span.offset) {
        nodes_[last].span.bytes = static_cast<std::int32_t>(static_cast<std::int64_t>(nodes_[last].span.bytes) + span.bytes);
    } else if (free_head_ == no_node) {
        error(); // May reenter and supply nodes. Deliberately do not retry.
    } else {
        const auto node = free_head_;
        free_head_ = nodes_[node].next;
        nodes_[node].span = span;
        nodes_[node].next = no_node;
        if (last == no_node) heads_[queue] = node;
        else nodes_[last].next = node;
    }
    leave();
    return Result::completed;
}

Result Pool::unget(std::uint32_t queue, const Span& span) {
    const auto admission = check_unget(queue, span);
    if (admission != Result::completed) return admission;
    if (queue >= heads_.size()) { error(); return Result::completed; }
    if (span.bytes <= 0 || span.region == 0) return Result::completed;
    enter();
    if (span.bytes <= 0 || span.region == 0 || check_unget(queue, span) != Result::completed) {
        leave();
        return Result::callback_contract_violation;
    }
    const auto head = heads_[queue];
    if (mode_ == 1 && head != no_node && nodes_[head].span.region == span.region &&
        span.offset + span.bytes == nodes_[head].span.offset) {
        nodes_[head].span.offset = span.offset;
        nodes_[head].span.bytes = static_cast<std::int32_t>(static_cast<std::int64_t>(nodes_[head].span.bytes) + span.bytes);
    } else if (free_head_ == no_node) {
        error();
    } else {
        const auto node = free_head_;
        free_head_ = nodes_[node].next;
        nodes_[node].span = span;
        nodes_[node].next = heads_[queue];
        heads_[queue] = node;
    }
    leave();
    return Result::completed;
}

std::int32_t Pool::queued_bytes(std::uint32_t queue) {
    if (queue >= heads_.size()) { error(); return 0; }
    std::uint32_t total = 0;
    for (auto node = heads_[queue]; node != no_node; node = nodes_[node].next) {
        total += static_cast<std::uint32_t>(nodes_[node].span.bytes);
    }
    return std::bit_cast<std::int32_t>(total);
}

bool Pool::head_availability(std::uint32_t queue, std::int32_t request, std::int32_t& output_head_bytes) {
    output_head_bytes = 0;
    if (queue >= heads_.size()) { error(); return false; }
    const auto head = heads_[queue];
    if (head == no_node) return false;
    const auto bytes = nodes_[head].span.bytes;
    output_head_bytes = bytes;
    return mode_ == 1 ? bytes >= request : bytes == request;
}

Result Pool::queued_nodes(std::uint32_t queue, std::uint32_t& output) const noexcept {
    if (queue >= heads_.size()) return Result::unsupported_selector;
    std::uint32_t count = 0;
    for (auto node = heads_[queue]; node != no_node; node = nodes_[node].next) ++count;
    output = count;
    return Result::completed;
}

std::uint32_t Pool::free_nodes() const noexcept {
    std::uint32_t count = 0;
    for (auto node = free_head_; node != no_node; node = nodes_[node].next) ++count;
    return count;
}

} // namespace reo::native::sjuni
