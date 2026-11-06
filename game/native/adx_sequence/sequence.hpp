#pragma once
#include "../resources/byte_view.hpp"
#include "../adx_header/adx_header.hpp"
#include <vector>

namespace reo::native::adx_sequence {
inline constexpr std::size_t maximum_segments = 16;
enum class Status { completed, invalid_input, source_failure, unsupported_header, incompatible_output, numeric_limit, no_memory };
struct Segment {
    std::shared_ptr<const resources::ByteView> view;
    adx_header::DecoderState header;
    std::uint64_t byte_offset{}, sample_offset{}, encoded_end{};
};
class Sequence;
struct Result { Status status{Status::invalid_input}; std::shared_ptr<const Sequence> sequence; };
// Preparation performs bounded control-thread header/tail I/O. The resulting
// view has immutable metadata and retains all providers. Backing bytes must
// remain externally immutable, as required by the resource-view contract.
class Sequence final : public resources::ByteView {
public:
    [[nodiscard]] static Result prepare(std::span<const std::shared_ptr<const resources::ByteView>>) noexcept;
    [[nodiscard]] std::uint64_t size() const noexcept override { return bytes_; }
    [[nodiscard]] resources::ReadResult read(std::uint64_t, std::span<std::byte>) const override;
    [[nodiscard]] std::span<const Segment> segments() const noexcept { return segments_; }
    [[nodiscard]] std::uint32_t total_samples() const noexcept { return samples_; }
    [[nodiscard]] std::uint32_t channels() const noexcept { return segments_.front().header.base.channels; }
    [[nodiscard]] std::uint32_t frequency() const noexcept { return segments_.front().header.base.frequency; }
private:
    Sequence(std::vector<Segment>, std::uint64_t, std::uint32_t);
    const std::vector<Segment> segments_;
    const std::uint64_t bytes_;
    const std::uint32_t samples_;
};
}
