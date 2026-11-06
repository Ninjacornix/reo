#pragma once
#include <cstdint>

namespace reo::native::adxt_integer_clock {
enum class Query { rna_ratio, decoded_minus_queued };
enum class Status { completed, invalid_query, invalid_queue_snapshot };
// Prepared, externally serialized observations. Queue counts are original byte
// counts, NOT PCM-device consumption. No guest addresses or retained storage.
struct Observation {
    std::uint8_t state{};
    std::uint32_t decoded{}, total{}, frequency{}, base{}, offset{};
    std::int16_t depth_mode{}, depth_code{};
    bool output_present{};
    std::uint32_t output_bytes{}, rna_free_bytes{};
};
struct Ratio {
    std::uint32_t numerator{}, denominator{};
    bool operator==(const Ratio&) const = default;
};
struct Result { Status status; Ratio ratio; };
struct Mode {
    std::uint32_t selection{}, ratio{}, resynchronizations{};
    bool operator==(const Mode&) const = default;
};
// Original modulo32 integer accounting only. Estimated/tick/FP clock, queue
// ownership and synchronization belong to their separate future owners.
[[nodiscard]] Result query(Query, Observation) noexcept;
void select_mode(Mode&, std::uint32_t selection) noexcept;
void count_resynchronization(Mode&) noexcept;
} // namespace reo::native::adxt_integer_clock
