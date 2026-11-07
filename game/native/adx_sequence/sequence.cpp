#include "sequence.hpp"
#include <algorithm>
#include <climits>
#include <new>

namespace reo::native::adx_sequence {
Sequence::Sequence(std::vector<Segment> segments, std::uint64_t bytes, std::uint32_t samples)
    : segments_(std::move(segments)), bytes_(bytes), samples_(samples) {}
Result Sequence::prepare(std::span<const std::shared_ptr<const resources::ByteView>> views) noexcept {
    if (views.size() < 2 || views.size() > maximum_segments) return {};
    try {
        std::vector<Segment> segments; segments.reserve(views.size());
        std::uint64_t bytes = 0, samples = 0; adx_header::KeyContext keys;
        for (const auto& view : views) {
            if (!view || !view->size() || view->size() % 2048) return {};
            if (view->size() > INT_MAX - bytes) return {Status::numeric_limit, {}};
            auto parsed = Clip::parse(view, keys);
            if (parsed.status != Status::completed) return {parsed.status, {}};
            auto segment = std::move(parsed.segment); const auto total = segment.header.base.total_samples;
            const auto& state = segment.header;
            if (!segments.empty() && (state.base.frequency != segments.front().header.base.frequency ||
                state.active_channels != segments.front().header.active_channels))
                return {Status::incompatible_output, {}};
            if (state.base.total_samples > INT_MAX - 31u - samples) return {Status::numeric_limit, {}};
            segment.byte_offset = bytes; segment.sample_offset = samples;
            segments.push_back(std::move(segment));
            bytes += view->size(); samples += total;
        }
        return {Status::completed, std::shared_ptr<const Sequence>(new Sequence(std::move(segments), bytes, static_cast<std::uint32_t>(samples)))};
    } catch (const std::bad_alloc&) { return {Status::no_memory, {}}; }
    catch (...) { return {Status::source_failure, {}}; }
}
resources::ReadResult Sequence::read(std::uint64_t offset, std::span<std::byte> destination) const {
    if (offset > bytes_ || destination.size() > bytes_ - offset) return {resources::Status::invalid_range, 0};
    std::size_t copied = 0;
    for (const auto& segment : segments_) {
        const auto end = segment.byte_offset + segment.view->size();
        if (offset >= end) continue;
        if (copied == destination.size()) break;
        const auto at = offset - segment.byte_offset;
        const auto count = std::min<std::uint64_t>(destination.size() - copied, segment.view->size() - at);
        const auto result = segment.view->read(at, destination.subspan(copied, static_cast<std::size_t>(count)));
        if (result.status != resources::Status::ok || result.bytes != count)
            return {result.status == resources::Status::ok ? resources::Status::source_failure : result.status, copied + std::min<std::size_t>(result.bytes, static_cast<std::size_t>(count))};
        copied += static_cast<std::size_t>(count); offset += count;
    }
    return {resources::Status::ok, copied};
}
}
