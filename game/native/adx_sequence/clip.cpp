#include "clip.hpp"
#include <algorithm>
#include <bit>
#include <climits>
#include <new>

namespace reo::native::adx_sequence {
namespace {
bool exact(const resources::ByteView& view, std::uint64_t offset, std::span<std::uint8_t> bytes) {
    const auto result = view.read(offset, std::as_writable_bytes(bytes));
    return result.status == resources::Status::ok && result.bytes == bytes.size();
}
bool output(const adx_header::DecoderState& h) noexcept {
    const bool ainf = std::bit_cast<std::int32_t>(h.ainf.value) > 0;
    if (ainf && std::bit_cast<std::int16_t>(h.ainf.code)) return false;
    for (int c = 0; c < h.active_channels; ++c) {
        const auto pan = ainf ? std::bit_cast<std::int16_t>(h.ainf.halves[c]) : -128;
        const auto expected = h.active_channels == 1 ? 0 : c == 0 ? -15 : 15;
        if (pan != -128 && pan != expected) return false;
    }
    return true;
}
}
Clip::Parsed Clip::parse(std::shared_ptr<const resources::ByteView> view, adx_header::KeyContext& keys) {
    if (!view || !view->size() || view->size() % 2048) return {};
    if (view->size() > INT_MAX) return {Status::numeric_limit, {}};
    std::array<std::uint8_t, 2048> header{};
    if (!exact(*view, 0, header)) return {Status::source_failure, {}};
    adx_header::DecoderState state; state.borrowed_pcm = {8192, 8288, 1};
    const auto parsed = adx_header::decode_header(header, state, keys);
    if (parsed.status != adx_header::Status::completed || parsed.source_result <= 0 || parsed.source_result > 2048 ||
        state.base.bits != 4 || state.active_samples_per_block != 32 || state.active_block_bytes != 18 ||
        state.active_channels < 1 || state.active_channels > 2 || !state.base.total_samples ||
        std::bit_cast<std::int16_t>(state.loop.enabled) > 0)
        return {Status::unsupported_header, {}};
    if (!output(state)) return {Status::incompatible_output, {}};
    if (state.base.total_samples > INT_MAX - 31u) return {Status::numeric_limit, {}};
    const auto end = std::uint64_t(parsed.source_result) + (std::uint64_t(state.base.total_samples) + 31) / 32 * 18 * state.active_channels;
    if (end > view->size() || view->size() - end < 16 || view->size() - end > 4096)
        return {Status::unsupported_header, {}};
    std::array<std::uint8_t, 4096> tail{};
    const auto length = static_cast<std::size_t>(view->size() - end);
    if (!exact(*view, end, std::span(tail).first(length))) return {Status::source_failure, {}};
    const auto record = (unsigned(tail[2]) << 8) + tail[3] + 4;
    if (tail[0] != 0x80 || tail[1] != 1 || record < 16 || record > INT16_MAX || record > length ||
        std::any_of(tail.begin() + record, tail.begin() + length, [](auto value) { return value != 0; }))
        return {Status::unsupported_header, {}};
    // Parsed metadata describes the admitted output channels, without owning PCM.
    state.output_channels = state.active_channels;
    return {Status::completed, {std::move(view), state, 0, 0, end}};
}
ClipResult Clip::prepare(std::shared_ptr<const resources::ByteView> view) noexcept {
    try {
        adx_header::KeyContext keys; auto parsed = parse(std::move(view), keys);
        if (parsed.status != Status::completed) return {parsed.status, {}};
        return {Status::completed, std::shared_ptr<const Clip>(new Clip(std::move(parsed.segment)))};
    } catch (const std::bad_alloc&) { return {Status::no_memory, {}}; }
    catch (...) { return {Status::source_failure, {}}; }
}
}
