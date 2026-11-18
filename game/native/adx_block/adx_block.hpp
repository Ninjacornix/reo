#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

namespace reo::native::adx_block {

inline constexpr std::size_t encoded_bytes_per_block = 18;
inline constexpr std::size_t samples_per_block = 32;

struct History {
    std::int16_t newest{};
    std::int16_t previous{};
    friend bool operator==(const History&, const History&) = default;
};
struct State {
    History history;
    // Initial value admits the complete original unsigned halfword domain.
    // Each decoded block advances it into the masked 15-bit domain.
    std::uint16_t key{};
    friend bool operator==(const State&, const State&) = default;
};
struct Parameters {
    std::int16_t coefficient1{};
    std::int16_t coefficient2{};
    std::int16_t key_multiplier{};
    std::int16_t key_addend{};
};
struct Limits {
    std::size_t max_pcm_samples{131072};
};
enum class Status { ok, short_input, output_limit, no_memory };
enum class Stop { requested_count, marker };
struct Result {
    Status status{Status::short_input};
    Stop stop{Stop::requested_count};
    // Defined as an original kernel return only when status == ok.
    std::int32_t kernel_return{};
    std::uint32_t blocks_decoded{};
    std::size_t encoded_bytes_consumed{};
    std::size_t encoded_bytes_inspected{};
    State state;
    // Early marker preserves prefix PCM/key effects, but the original leaves
    // the caller's entire history pair unchanged. Normal/nonpositive count
    // publishes history, even when that publication stores unchanged values.
    bool history_committed{};
    std::vector<std::int16_t> pcm;
};

// Exactly the mono keyed 18-byte/32-sample integer kernel. Other layouts/codecs
// are not represented by this API. Coefficients are provided; no trig/header,
// stream/SJ/clock/global state is inferred. Encoded storage is borrowed only for
// this synchronous call; output is newly owned and cannot alias that storage.
// The requested count domain is the caller's sign-extended 32-bit value.
// Preflight rejects missing required bytes/output limits before decode effects.
// Every failure returns empty PCM and the initial state, uncommitted.
[[nodiscard]] Result decode_keyed_mono(std::span<const std::uint8_t> encoded,
                                      std::int32_t requested_blocks, State initial,
                                      Parameters parameters, Limits limits = {}) noexcept;

} // namespace reo::native::adx_block
