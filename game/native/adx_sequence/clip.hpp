#pragma once
#include "../resources/byte_view.hpp"
#include "../adx_header/adx_header.hpp"
#include <utility>

namespace reo::native::adx_sequence {
enum class Status { completed, invalid_input, source_failure, unsupported_header, incompatible_output, numeric_limit, no_memory };
struct Segment {
    std::shared_ptr<const resources::ByteView> view;
    adx_header::DecoderState header;
    std::uint64_t byte_offset{}, sample_offset{}, encoded_end{};
};
class Sequence;
class Clip;
struct ClipResult { Status status{Status::invalid_input}; std::shared_ptr<const Clip> clip; };
// One sealed admitted asset, prepared before queue/source publication. The view
// remains the original retained provider, including its actual sector tail.
class Clip final {
public:
    [[nodiscard]] static ClipResult prepare(std::shared_ptr<const resources::ByteView>) noexcept;
    [[nodiscard]] const Segment& metadata() const noexcept { return segment_; }
private:
    friend class Sequence;
    struct Parsed { Status status{Status::invalid_input}; Segment segment; };
    [[nodiscard]] static Parsed parse(std::shared_ptr<const resources::ByteView>, adx_header::KeyContext&);
    explicit Clip(Segment segment) : segment_(std::move(segment)) {}
    const Segment segment_;
};
}
