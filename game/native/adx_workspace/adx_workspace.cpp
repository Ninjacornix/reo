#include "adx_workspace.hpp"

#include <bit>
#include <limits>
#include <utility>

namespace reo::native::adx_workspace {
namespace {
struct Extent { std::uintptr_t begin{}, end{}; };
bool extent(const void* pointer, std::size_t bytes, Extent& out) noexcept {
    const auto begin = reinterpret_cast<std::uintptr_t>(pointer);
    if (bytes && (!pointer || begin > std::numeric_limits<std::uintptr_t>::max() - bytes))
        return false;
    out = {begin, begin + bytes};
    return true;
}
bool overlaps(Extent a, Extent b) noexcept {
    return a.begin < a.end && b.begin < b.end && a.begin < b.end && b.begin < a.end;
}
std::uint16_t header(std::span<const std::uint8_t> input, std::size_t at) noexcept {
    return static_cast<std::uint16_t>((std::uint16_t(input[at]) << 8) | input[at + 1]);
}
std::int32_t nibble(unsigned code) noexcept {
    return code < 8 ? static_cast<std::int32_t>(code) : static_cast<std::int32_t>(code) - 16;
}
std::uint32_t product(std::int16_t a, std::int16_t b) noexcept {
    return static_cast<std::uint32_t>(std::int64_t(a) * std::int64_t(b));
}
std::int32_t shift12(std::uint32_t word) noexcept {
    return std::bit_cast<std::int32_t>((word >> 12) | ((word & 0x80000000u) ? 0xFFF00000u : 0u));
}
std::int16_t clamp(std::int32_t value) noexcept {
    return value < -32768 ? std::int16_t{-32768} : value > 32767 ? std::int16_t{32767} : static_cast<std::int16_t>(value);
}
std::int16_t sample(unsigned code, std::int32_t scale, History& history, Parameters p) noexcept {
    // Original low-word products ADD before ASR12. No host signed overflow.
    const auto prediction = shift12(product(p.coefficient1, history.newest) + product(p.coefficient2, history.previous));
    const auto word = static_cast<std::uint32_t>(prediction) + static_cast<std::uint32_t>(nibble(code) * scale);
    const auto result = clamp(std::bit_cast<std::int32_t>(word));
    history.previous = history.newest;
    history.newest = result;
    return result;
}
std::uint16_t next_key(std::uint16_t key, Parameters p) noexcept {
    const auto low_product = static_cast<std::uint32_t>(std::int64_t(key) * p.multiplier);
    const auto sum = low_product + static_cast<std::uint32_t>(static_cast<std::int32_t>(p.addend));
    return static_cast<std::uint16_t>(sum & 0x7FFFu);
}
} // namespace

Prepared::Prepared(Route route, std::span<const std::uint8_t> encoded, PcmOutput output,
                   std::int32_t requested, std::uint32_t groups, std::size_t consumed,
                   std::size_t inspected, Stop stop) noexcept
    : route_(route), encoded_(encoded), output_(output), requested_(requested), groups_(groups),
      consumed_(consumed), inspected_(inspected), stop_(stop) {}

Admission prepare_into(Route route, std::span<const std::uint8_t> encoded,
                       std::int32_t requested, PcmOutput output) noexcept {
    if (route != Route::mono && route != Route::stereo && route != Route::downmix_7_over_10)
        return {Status::unsupported_route, {}};
    if (encoded.size() > maximum_encoded_bytes || output.left.size() > maximum_pcm_samples_per_plane ||
        output.right.size() > maximum_pcm_samples_per_plane || (route == Route::mono && !output.right.empty()))
        return {Status::physical_span, {}};
    Extent input, left, right;
    if ((!output.left.empty() && reinterpret_cast<std::uintptr_t>(output.left.data()) % alignof(std::int16_t)) ||
        (!output.right.empty() && reinterpret_cast<std::uintptr_t>(output.right.data()) % alignof(std::int16_t)))
        return {Status::invalid_storage, {}};
    if (!extent(encoded.data(), encoded.size(), input) ||
        !extent(output.left.data(), output.left.size_bytes(), left) ||
        !extent(output.right.data(), output.right.size_bytes(), right))
        return {Status::invalid_storage, {}};
    if (overlaps(input, left) || overlaps(input, right) || overlaps(left, right))
        return {Status::overlapping_storage, {}};
    const auto mono = route == Route::mono;
    // Signed division by +2 is defined for every int32, including INT_MIN.
    const auto requested_groups = mono ? requested : requested / 2;
    std::uint32_t groups = 0;
    std::size_t at = 0, inspected = 0;
    Stop stop = Stop::requested_count;
    while (requested_groups > 0 && groups < static_cast<std::uint32_t>(requested_groups)) {
        // Every increment below is proven within encoded's physical bound.
        if (encoded.size() - at < 2) return {Status::short_input, {}};
        if (header(encoded, at) & 0x8000u) {
            stop = mono ? Stop::mono_marker : Stop::left_marker;
            inspected = at + 2;
            break;
        }
        if (!mono) {
            if (encoded.size() - at < 20) return {Status::short_input, {}};
            if (header(encoded, at + 18) & 0x8000u) {
                stop = Stop::right_marker;
                inspected = at + 20;
                break;
            }
        }
        const auto stride = mono ? encoded_bytes_per_block : 2 * encoded_bytes_per_block;
        if (encoded.size() - at < stride) return {Status::short_input, {}};
        // Quotient comparison proves groups*32 and both output extents.
        if (groups >= output.left.size() / samples_per_block ||
            (!mono && groups >= output.right.size() / samples_per_block))
            return {Status::short_output, {}};
        ++groups;
        at += stride;
        inspected = at;
    }
    return {Status::admitted, Prepared(route, encoded, output, requested, groups, at, inspected, stop)};
}

Result execute(Prepared plan, State initial, Parameters parameters) noexcept {
    Result result;
    result.stop = plan.stop_;
    result.state = initial;
    const auto mono = plan.route_ == Route::mono;
    auto left = initial.left;
    auto right = initial.right;
    auto key = initial.key;
    std::size_t at = 0, output = 0;
    for (std::uint32_t group = 0; group < plan.groups_; ++group) {
        const auto left_scale = static_cast<std::int32_t>(((header(plan.encoded_, at) ^ key) & 0x1FFFu) + 1u);
        key = next_key(key, parameters);
        std::int32_t right_scale = 0;
        if (!mono) {
            right_scale = static_cast<std::int32_t>(((header(plan.encoded_, at + 18) ^ key) & 0x1FFFu) + 1u);
            key = next_key(key, parameters);
        }
        for (std::size_t i = 0; i < samples_per_block; ++i) {
            const auto shift = i % 2 == 0 ? 4 : 0;
            const auto l = sample((plan.encoded_[at + 2 + i / 2] >> shift) & 15u, left_scale, left, parameters);
            if (mono) {
                plan.output_.left[output] = l;
            } else {
                const auto r = sample((plan.encoded_[at + 20 + i / 2] >> shift) & 15u, right_scale, right, parameters);
                if (plan.route_ == Route::downmix_7_over_10) {
                    const auto mixed = clamp((7 * (std::int32_t(l) + r)) / 10);
                    plan.output_.left[output] = mixed;
                    plan.output_.right[output] = mixed;
                } else {
                    plan.output_.left[output] = l;
                    plan.output_.right[output] = r;
                }
            }
            ++output;
        }
        at += mono ? 18 : 36;
    }
    if (plan.stop_ == Stop::right_marker) key = next_key(key, parameters);
    result.state.key = key;
    result.left_history_committed = plan.stop_ == Stop::requested_count;
    result.right_history_committed = !mono && result.left_history_committed;
    if (result.left_history_committed) result.state.left = left;
    if (result.right_history_committed) result.state.right = right;
    result.complete_channel_blocks = plan.groups_ * (mono ? 1u : 2u);
    result.kernel_return = plan.stop_ == Stop::requested_count ? plan.requested_ : static_cast<std::int32_t>(result.complete_channel_blocks);
    result.samples_per_plane = output;
    result.encoded_bytes_consumed = plan.consumed_;
    result.encoded_bytes_inspected = plan.inspected_;
    return result;
}

} // namespace reo::native::adx_workspace
