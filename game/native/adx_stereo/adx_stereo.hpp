#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

namespace reo::native::adx_stereo {
inline constexpr std::size_t encoded_bytes_per_pair = 36;
inline constexpr std::size_t samples_per_channel_per_pair = 32;
struct History {
    std::int16_t newest{}, previous{};
    bool operator==(const History&) const = default;
};
struct State {
    History left{}, right{};
    std::uint16_t key{};
    bool operator==(const State&) const = default;
};
struct Parameters {
    std::int16_t coefficient1{}, coefficient2{}, key_multiplier{}, key_addend{};
};
enum class Mode { separate_channels, downmix_7_over_10 };
enum class Status { ok, short_input, output_limit, no_memory, unsupported_mode };
enum class Stop { requested_count, left_marker, right_marker };
struct Limits { std::size_t max_samples_per_channel{131072}; };
struct Result {
    Status status{Status::ok};
    Stop stop{Stop::requested_count};
    std::int32_t kernel_return{}; // Defined original return only when status==ok.
    std::uint32_t pairs_decoded{};
    std::size_t encoded_bytes_consumed{}, encoded_bytes_inspected{};
    State state{};
    bool histories_committed{};
    std::vector<std::int16_t> left_pcm{}, right_pcm{};
};
// Encoded storage is borrowed immutably for this synchronous call only. PCM is
// owned by the result. Refusals publish no PCM/state changes; admitted markers
// retain prefix PCM/key but deliberately do not publish either history pair.
Result decode_keyed_stereo(std::span<const std::uint8_t> encoded,
                          std::int32_t requested_blocks, State initial,
                          Parameters parameters, Mode mode,
                          Limits limits = {}) noexcept;
} // namespace reo::native::adx_stereo
