#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>

namespace reo::native::adx_workspace {

inline constexpr std::size_t maximum_encoded_bytes = 8228;
inline constexpr std::size_t maximum_pcm_samples_per_plane = 8288;
inline constexpr std::size_t encoded_bytes_per_block = 18;
inline constexpr std::size_t samples_per_block = 32;

enum class Route { mono, stereo, downmix_7_over_10 };
enum class Stop { requested_count, mono_marker, left_marker, right_marker };
enum class Status { admitted, unsupported_route, physical_span, invalid_storage,
                    overlapping_storage, short_input, short_output };
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
    std::int16_t coefficient1{}, coefficient2{}, multiplier{}, addend{};
};
struct PcmOutput { std::span<std::int16_t> left{}, right{}; };
struct Result {
    Stop stop{};
    std::int32_t kernel_return{};
    std::uint32_t complete_channel_blocks{};
    std::size_t encoded_bytes_consumed{}, encoded_bytes_inspected{}, samples_per_plane{};
    State state{};
    bool left_history_committed{}, right_history_committed{};
};
struct Admission;

// Stable synchronous borrowed view, NOT an owned source/storage lease.
// Only prepare_into constructs one. Move it once into execute; do not reuse a
// moved-from view. Input/outputs must remain alive, stable and externally
// serialized between prepare and execute. No destructor mutation or callback.
class Prepared final {
public:
    Prepared(const Prepared&) = delete;
    Prepared& operator=(const Prepared&) = delete;
    Prepared(Prepared&&) noexcept = default;
    Prepared& operator=(Prepared&&) = delete;
private:
    Prepared(Route route, std::span<const std::uint8_t> encoded, PcmOutput output,
             std::int32_t requested, std::uint32_t groups, std::size_t consumed,
             std::size_t inspected, Stop stop) noexcept;
    Route route_;
    std::span<const std::uint8_t> encoded_;
    PcmOutput output_;
    std::int32_t requested_;
    std::uint32_t groups_;
    std::size_t consumed_, inspected_;
    Stop stop_;
    friend Admission prepare_into(Route, std::span<const std::uint8_t>, std::int32_t, PcmOutput) noexcept;
    friend Result execute(Prepared, State, Parameters) noexcept;
};
struct Admission {
    Status status;
    std::optional<Prepared> prepared;
};

// All refusals precede input scanning/PCM effects except short_input/output,
// which inspect a bounded prefix but still write no PCM or caller state.
// Full spans must be byte-disjoint, even when the actual PCM prefix is empty.
// Mono requires an empty right span. Physical maxima are profile admission,
// not proof every byte of a ring's mirror backing is valid queued input.
[[nodiscard]] Admission prepare_into(Route, std::span<const std::uint8_t> encoded,
                                     std::int32_t requested_encoded_blocks,
                                     PcmOutput output) noexcept;

// No admission, allocation, callback, I/O or failure result. Requires the valid
// stable Prepared described above. All scalar inputs are VALUES, so PCM stores
// cannot change subsequently read caller-owned parameters/history/key.
// Only the admitted PCM prefix is written. Result carries value state; no raw
// pointers, queue publication, global odd flag or asynchronous work escapes.
[[nodiscard]] Result execute(Prepared, State initial, Parameters) noexcept;

} // namespace reo::native::adx_workspace
