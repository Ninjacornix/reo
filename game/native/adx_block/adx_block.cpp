#include "adx_block.hpp"

#include <bit>
#include <new>
#include <stdexcept>

namespace reo::native::adx_block {
namespace {

std::uint16_t header(std::span<const std::uint8_t> input, std::size_t offset) noexcept {
    return static_cast<std::uint16_t>((std::uint16_t(input[offset]) << 8) | input[offset + 1]);
}
std::int32_t signed_nibble(unsigned value) noexcept {
    return value < 8 ? static_cast<std::int32_t>(value) : static_cast<std::int32_t>(value) - 16;
}
std::uint32_t product(std::int16_t a, std::int16_t b) noexcept {
    // Integer multiplication is widened before explicitly selecting its low word.
    return static_cast<std::uint32_t>(std::int64_t(a) * std::int64_t(b));
}
std::int32_t arithmetic_shift_12(std::uint32_t bits) noexcept {
    const auto shifted = (bits >> 12) | ((bits & 0x80000000u) ? 0xFFF00000u : 0u);
    return std::bit_cast<std::int32_t>(shifted);
}
std::int16_t sample(std::int32_t nibble, std::int32_t scale,
                    History& history, const Parameters& parameters) noexcept {
    const std::uint32_t products = product(parameters.coefficient1, history.newest) +
                                   product(parameters.coefficient2, history.previous);
    const auto predicted = arithmetic_shift_12(products);
    // nibble*scale is bounded by [-65536,57344]. Express the subsequent ADDU as
    // unsigned-word addition, not overflowing host signed arithmetic.
    const auto bits = static_cast<std::uint32_t>(predicted) + static_cast<std::uint32_t>(nibble * scale);
    const auto value = std::bit_cast<std::int32_t>(bits);
    const auto clipped = value < -32768 ? std::int16_t{-32768} :
                         value > 32767 ? std::int16_t{32767} : static_cast<std::int16_t>(value);
    history.previous = history.newest;
    history.newest = clipped;
    return clipped;
}
std::uint16_t advance_key(std::uint16_t value, const Parameters& parameters) noexcept {
    const auto low_product = static_cast<std::uint32_t>(std::int64_t(value) * parameters.key_multiplier);
    const auto sum = low_product + static_cast<std::uint32_t>(static_cast<std::int32_t>(parameters.key_addend));
    return static_cast<std::uint16_t>(sum & 0x7FFFu);
}

struct Plan {
    Status status{Status::ok};
    std::uint32_t blocks{};
    std::size_t consumed{}, inspected{};
    bool marker{};
};
Plan preflight(std::span<const std::uint8_t> input, std::int32_t requested,
                std::size_t max_samples) noexcept {
    Plan plan;
    for (std::int32_t block = 0; block < requested; ++block) {
        if (input.size() - plan.consumed < 2) return {Status::short_input};
        if (header(input, plan.consumed) & 0x8000u) {
            plan.marker = true;
            plan.inspected = plan.consumed + 2;
            return plan;
        }
        if (input.size() - plan.consumed < encoded_bytes_per_block) return {Status::short_input};
        if (plan.blocks >= max_samples / samples_per_block) return {Status::output_limit};
        ++plan.blocks;
        // Subtraction check above proves this increment stays within the span.
        plan.consumed += encoded_bytes_per_block;
        plan.inspected = plan.consumed;
    }
    return plan;
}
} // namespace

Result decode_keyed_mono(std::span<const std::uint8_t> encoded, std::int32_t requested_blocks,
                         State initial, Parameters parameters, Limits limits) noexcept {
    Result result;
    result.state = initial;
    if (requested_blocks <= 0) {
        result.status = Status::ok;
        result.kernel_return = requested_blocks;
        result.history_committed = true;
        return result;
    }
    const auto plan = preflight(encoded, requested_blocks, limits.max_pcm_samples);
    if (plan.status != Status::ok) {
        result.status = plan.status;
        return result;
    }
    try {
        // preflight's quotient comparison proves this multiplication cannot wrap.
        result.pcm.resize(static_cast<std::size_t>(plan.blocks) * samples_per_block);
    } catch (const std::bad_alloc&) {
        result.status = Status::no_memory;
        return result;
    } catch (const std::length_error&) {
        result.status = Status::no_memory;
        return result;
    }
    auto history = initial.history;
    auto key = initial.key;
    std::size_t output = 0, at = 0;
    for (std::uint32_t block = 0; block < plan.blocks; ++block) {
        const auto scale = static_cast<std::int32_t>(((header(encoded, at) ^ key) & 0x1FFFu) + 1u);
        key = advance_key(key, parameters); // Stored before any sample of this block.
        for (std::size_t i = 2; i < encoded_bytes_per_block; ++i) {
            const auto byte = encoded[at + i];
            result.pcm[output++] = sample(signed_nibble(byte >> 4), scale, history, parameters);
            result.pcm[output++] = sample(signed_nibble(byte & 15), scale, history, parameters);
        }
        at += encoded_bytes_per_block;
    }
    result.status = Status::ok;
    result.stop = plan.marker ? Stop::marker : Stop::requested_count;
    result.kernel_return = plan.marker ? static_cast<std::int32_t>(plan.blocks) : requested_blocks;
    result.blocks_decoded = plan.blocks;
    result.encoded_bytes_consumed = plan.consumed;
    result.encoded_bytes_inspected = plan.inspected;
    result.state.key = key;
    result.history_committed = !plan.marker;
    if (result.history_committed) result.state.history = history;
    return result;
}

} // namespace reo::native::adx_block
