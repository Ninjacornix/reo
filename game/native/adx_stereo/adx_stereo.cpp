#include "adx_stereo.hpp"

#include <bit>
#include <new>
#include <stdexcept>

namespace reo::native::adx_stereo {
namespace {
std::uint16_t header(std::span<const std::uint8_t> bytes, std::size_t at) noexcept {
    return static_cast<std::uint16_t>((std::uint16_t(bytes[at]) << 8) | bytes[at + 1]);
}
std::int32_t nibble(unsigned value) noexcept {
    return value < 8 ? static_cast<std::int32_t>(value) : static_cast<std::int32_t>(value) - 16;
}
std::uint32_t product(std::int16_t a, std::int16_t b) noexcept {
    return static_cast<std::uint32_t>(std::int64_t(a) * b);
}
std::int32_t shift12(std::uint32_t word) noexcept {
    return std::bit_cast<std::int32_t>((word >> 12) | ((word & 0x80000000u) ? 0xFFF00000u : 0u));
}
std::int16_t clamp(std::int32_t value) noexcept {
    return value < -32768 ? std::int16_t{-32768} :
           value > 32767 ? std::int16_t{32767} : static_cast<std::int16_t>(value);
}
std::int16_t sample(unsigned code, std::int32_t scale, History& history,
                    Parameters parameters) noexcept {
    const auto prediction = shift12(product(parameters.coefficient1, history.newest) +
                                    product(parameters.coefficient2, history.previous));
    const auto word = static_cast<std::uint32_t>(prediction) +
                      static_cast<std::uint32_t>(nibble(code) * scale);
    const auto value = clamp(std::bit_cast<std::int32_t>(word));
    history.previous = history.newest;
    history.newest = value;
    return value;
}
std::uint16_t next_key(std::uint16_t key, Parameters parameters) noexcept {
    const auto word = static_cast<std::uint32_t>(std::int64_t(key) * parameters.key_multiplier) +
                      static_cast<std::uint32_t>(static_cast<std::int32_t>(parameters.key_addend));
    return static_cast<std::uint16_t>(word & 0x7FFFu);
}
struct Plan {
    Status status{Status::ok};
    Stop stop{Stop::requested_count};
    std::uint32_t pairs{};
    std::size_t consumed{}, inspected{};
};
Plan preflight(std::span<const std::uint8_t> encoded, std::int32_t pairs,
               std::size_t sample_limit) noexcept {
    Plan plan;
    for (std::int32_t pair = 0; pair < pairs; ++pair) {
        if (encoded.size() - plan.consumed < 2) return {Status::short_input};
        if (header(encoded, plan.consumed) & 0x8000u) {
            plan.stop = Stop::left_marker;
            plan.inspected = plan.consumed + 2;
            return plan;
        }
        if (encoded.size() - plan.consumed < 20) return {Status::short_input};
        if (header(encoded, plan.consumed + 18) & 0x8000u) {
            plan.stop = Stop::right_marker;
            plan.inspected = plan.consumed + 20;
            return plan;
        }
        if (encoded.size() - plan.consumed < encoded_bytes_per_pair) return {Status::short_input};
        if (plan.pairs >= sample_limit / samples_per_channel_per_pair) return {Status::output_limit};
        ++plan.pairs;
        plan.consumed += encoded_bytes_per_pair;
        plan.inspected = plan.consumed;
    }
    return plan;
}
Result refusal(State initial, Status status) noexcept {
    Result result;
    result.status = status;
    result.state = initial;
    return result;
}
} // namespace

Result decode_keyed_stereo(std::span<const std::uint8_t> encoded,
                          std::int32_t requested_blocks, State initial,
                          Parameters parameters, Mode mode, Limits limits) noexcept {
    if (mode != Mode::separate_channels && mode != Mode::downmix_7_over_10)
        return refusal(initial, Status::unsupported_mode);
    // C++ signed division by positive two truncates toward zero, matching the
    // original sign-bit bias, word addition and arithmetic shift sequence.
    const auto plan = preflight(encoded, requested_blocks / 2, limits.max_samples_per_channel);
    if (plan.status != Status::ok) return refusal(initial, plan.status);
    Result result;
    result.state = initial;
    try {
        const auto size = static_cast<std::size_t>(plan.pairs) * samples_per_channel_per_pair;
        result.left_pcm.resize(size);
        result.right_pcm.resize(size);
    } catch (const std::bad_alloc&) {
        return refusal(initial, Status::no_memory);
    } catch (const std::length_error&) {
        return refusal(initial, Status::no_memory);
    }
    auto left = initial.left;
    auto right = initial.right;
    auto key = initial.key;
    std::size_t at = 0, output = 0;
    for (std::uint32_t pair = 0; pair < plan.pairs; ++pair) {
        const auto left_scale = static_cast<std::int32_t>(((header(encoded, at) ^ key) & 0x1FFFu) + 1);
        key = next_key(key, parameters);
        const auto right_scale = static_cast<std::int32_t>(((header(encoded, at + 18) ^ key) & 0x1FFFu) + 1);
        key = next_key(key, parameters);
        for (std::size_t i = 0; i < 32; ++i) {
            const auto shift = (i % 2 == 0) ? 4 : 0;
            const auto l = sample((encoded[at + 2 + i / 2] >> shift) & 15u, left_scale, left, parameters);
            const auto r = sample((encoded[at + 20 + i / 2] >> shift) & 15u, right_scale, right, parameters);
            if (mode == Mode::downmix_7_over_10) {
                // Both channel samples are already clipped. This product is
                // bounded by [-458752,458738]; signed division truncates to zero.
                const auto mixed = clamp((7 * (std::int32_t(l) + r)) / 10);
                result.left_pcm[output] = mixed;
                result.right_pcm[output] = mixed;
            } else {
                result.left_pcm[output] = l;
                result.right_pcm[output] = r;
            }
            ++output;
        }
        at += encoded_bytes_per_pair;
    }
    // A right marker is tested after advancing the left key but before either
    // channel's payload is decoded. Even zero completed pairs retain this step.
    if (plan.stop == Stop::right_marker) key = next_key(key, parameters);
    result.state.key = key;
    result.histories_committed = plan.stop == Stop::requested_count;
    if (result.histories_committed) {
        result.state.left = left;
        result.state.right = right;
    }
    result.stop = plan.stop;
    result.pairs_decoded = plan.pairs;
    result.kernel_return = result.histories_committed ? requested_blocks : static_cast<std::int32_t>(plan.pairs * 2u);
    result.encoded_bytes_consumed = plan.consumed;
    result.encoded_bytes_inspected = plan.inspected;
    return result;
}
} // namespace reo::native::adx_stereo
