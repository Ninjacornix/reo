#include "movie_position.hpp"
#include <bit>
#include <limits>

namespace reo::native::movie_position {
namespace {
std::int32_t signed_bits(std::uint32_t value) noexcept {
    return std::bit_cast<std::int32_t>(value);
}
std::int32_t add(std::int32_t a, std::int32_t b) noexcept {
    return signed_bits(std::uint32_t(a) + std::uint32_t(b));
}
std::int32_t subtract(std::int32_t a, std::int32_t b) noexcept {
    return signed_bits(std::uint32_t(a) - std::uint32_t(b));
}
std::int32_t scale(std::int32_t a, std::int32_t b, std::int32_t divisor) noexcept {
    if (!divisor) {
        // Source checks XOR of the operands, even when their product is zero.
        return ((a < 0) != (b < 0)) ? std::numeric_limits<std::int32_t>::min()
                                   : std::numeric_limits<std::int32_t>::max();
    }
    // Two int32 operands cannot produce INT64_MIN, so / -1 is also defined.
    const auto product = std::int64_t(a) * std::int64_t(b);
    const auto quotient = product / std::int64_t(divisor);
    return signed_bits(std::uint32_t(quotient));
}
}

Publication publish(const Input& in, Latest latest) noexcept {
    Publication result;
    auto& descriptor = result.descriptor;
    descriptor.denominator = in.denominator;
    descriptor.position = add(subtract(in.counter, in.subtract_counter), in.bias);
    descriptor.source_position = in.counter;
    descriptor.offset_position = add(in.counter, in.bias);
    if (in.inner_clock_enabled) {
        const auto delta = subtract(in.inner_counter, in.inner_baseline);
        const auto thousand_delta = signed_bits(std::uint32_t(delta) * 1000u);
        descriptor.source_position = scale(in.denominator, thousand_delta, in.rate);
        descriptor.position = add(descriptor.source_position, in.bias);
        descriptor.offset_position = descriptor.position;
        result.zero_divisor_saturated = in.rate == 0;
    }
    result.latest_advanced = latest.numerator < descriptor.position;
    if (result.latest_advanced) {
        latest = {descriptor.position, descriptor.denominator};
        result.final_value = descriptor.denominator;
    }
    result.latest = latest;
    return result;
}
} // namespace reo::native::movie_position
