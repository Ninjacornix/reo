#include "resource_templates.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
template <class T> T read(std::span<const std::byte> b, std::size_t at) {
    if (at > b.size() || sizeof(T) > b.size() - at)
        throw std::invalid_argument("Truncated native resource template section");
    T v;
    std::memcpy(&v, b.data() + at, sizeof v);
    return v;
}
void bounds(std::span<const std::byte> b, std::size_t at, std::size_t n) {
    if (at > b.size() || n > b.size() - at)
        throw std::invalid_argument("Native resource template section extent unavailable");
}
} // namespace
ResourceTemplates::ResourceTemplates() noexcept {
    state_.selectors.fill(255);
}
bool ResourceTemplates::load(std::span<const std::byte> b) {
    const auto version = read<std::uint32_t>(b, 0);
    const auto n = read<std::int32_t>(b, 4), compatible = read<std::int32_t>(b, 8),
               offsets = read<std::int32_t>(b, 12);
    if (version != 3 || n == 0)
        return false;
    if (n < 0 || n > 129 || compatible < 0 || compatible > 384 || offsets < 0 || offsets > 128)
        throw std::out_of_range("Native resource template counts exceed owned capacities");
    std::array<std::uint32_t, 4> start;
    for (unsigned i = 0; i < 4; ++i)
        start[i] = read<std::uint32_t>(b, 16 + 4 * i);
    const std::array<std::size_t, 4> sizes{24u * unsigned(n), 4u * unsigned(n),
                                           4u * unsigned(offsets), 2u * unsigned(compatible)};
    for (unsigned i = 0; i < 4; ++i)
        if (start[i] && sizes[i])
            bounds(b, start[i], sizes[i]);
    // Admission precedes effects. For admitted inputs the source publication order
    // is count, templates, Y offsets, float offsets, compatibility, selector scan.
    state_.count = std::uint16_t(n);
    if (start[0])
        std::memcpy(state_.templates.data(), b.data() + start[0], sizes[0]);
    if (start[1])
        std::memcpy(state_.y_offsets.data(), b.data() + start[1], sizes[1]);
    if (start[2] && sizes[2])
        std::memcpy(state_.offsets.data(), b.data() + start[2], sizes[2]);
    if (start[3] && sizes[3])
        std::memcpy(state_.compatibility.data(), b.data() + start[3], sizes[3]);
    for (unsigned i = 0; i < unsigned(n); ++i) {
        const auto content = read<std::uint16_t>(state_.templates[i].encoded, 18);
        const auto normalized =
            content >= 10000 ? unsigned(content % 100) + 500u : unsigned(content);
        const auto signed_content = std::bit_cast<std::int16_t>(std::uint16_t(normalized));
        if (signed_content >= 0 && signed_content < 600)
            state_.selectors[unsigned(signed_content)] = std::uint8_t(i);
    }
    return true;
}
std::int8_t ResourceTemplates::action_kind(std::uint8_t index) const {
    if (index >= state_.templates.size())
        throw std::out_of_range("Native resource template index unavailable");
    return std::bit_cast<std::int8_t>(
        std::to_integer<std::uint8_t>(state_.templates[index].encoded[15]));
}
std::uint32_t ResourceTemplates::flags(std::uint8_t index) const {
    if(index==255)return 0;
    if(index>=state_.templates.size())throw std::out_of_range("Native resource flag template index unavailable");
    return read<std::uint32_t>(state_.templates[index].encoded,0);
}
} // namespace reo::native::gameplay_scenario
