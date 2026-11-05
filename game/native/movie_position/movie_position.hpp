#pragma once
#include <cstdint>

namespace reo::native::movie_position {

// Value snapshots for the File1 picture-position publisher. The caller owns
// descriptor selection, source leases, thread serialization and clock choice.
// No memory aliases, external callbacks or guest scheduling are represented.
struct Input {
    std::int32_t counter{};          // D54 + 20
    std::int32_t denominator{};      // D54 + 24
    std::int32_t subtract_counter{}; // player + DC4
    std::int32_t bias{};             // CC0 + 120
    bool inner_clock_enabled{};     // inner + 9D8 != 0
    std::int32_t inner_counter{};    // inner + A08
    std::int32_t inner_baseline{};   // CC0 + 11C
    std::int32_t rate{};             // selected table value, not its index
};
struct Latest {
    std::int32_t numerator{}, denominator{}; // CC0 + 240 / 244
};
struct Descriptor {
    std::int32_t position{}, denominator{}; // descriptor + 0C / 10
    std::int32_t source_position{};         // descriptor + 20
    std::int32_t offset_position{};         // descriptor + 24
};
struct Publication {
    Descriptor descriptor;
    Latest latest;
    bool latest_advanced{}, zero_divisor_saturated{};
    // Observed final v0 bits, without claiming callers use a declared return.
    std::int32_t final_value{};
};

// Pure bounded integer work. Wraps the source's 32-bit sums/differences and
// delta*1000 before signed 64-bit multiply/divide, truncating toward zero.
// The original arithmetic helper saturates a zero divisor according to operand
// signs; it does not perform a host divide by zero.
[[nodiscard]] Publication publish(const Input&, Latest) noexcept;

} // namespace reo::native::movie_position
