#include "import.hpp"
#include <algorithm>

namespace reo::native::gameplay_audio {
namespace {
std::uint32_t word(std::span<const std::uint8_t> data, std::size_t at) noexcept {
    return std::uint32_t(data[at]) | std::uint32_t(data[at + 1]) << 8 |
           std::uint32_t(data[at + 2]) << 16 | std::uint32_t(data[at + 3]) << 24;
}
bool contains(std::size_t size, std::size_t at, std::size_t count) noexcept {
    return at <= size && count <= size - at;
}
} // namespace
ImportResult import_snd(std::span<const std::uint8_t> bytes, unsigned slot,
                        ImportMode mode) noexcept {
    ImportResult result;
    if (slot >= (mode == ImportMode::direct ? 14u : 16u)) {
        result.status = Status::invalid_input;
        return result;
    }
    if (bytes.size() < 40)
        return result;
    for (unsigned n = 0; n < 3; ++n) {
        auto& part = result.value.parts[n];
        part = {word(bytes, 8 + n * 8), word(bytes, 12 + n * 8)};
        if (mode == ImportMode::direct && !contains(bytes.size(), part.offset, part.size))
            return result;
    }
    const auto offset = word(bytes, 32), size = word(bytes, 36);
    if (size < 32 || !contains(bytes.size(), offset, size))
        return result;
    const auto rows = std::min<std::size_t>(128, (size - 16) >> 4);
    for (std::size_t n = 0; n < rows; ++n) {
        const auto row = bytes.subspan(offset + 16 + n * 16, 16);
        result.value.descriptors[n] = {
            row[0],
            static_cast<std::uint16_t>(mode == ImportMode::direct ? row[10] | row[11] << 8 : 0),
            row[8],
            row[9],
            row[12],
            row[13],
            static_cast<std::uint8_t>(row[6] & 127),
            static_cast<std::uint8_t>(row[6] >> 7),
            row[15]};
    }
    result.value.rows = rows;
    result.value.source_return = size >> 4;
    result.status = Status::completed;
    return result;
}
} // namespace reo::native::gameplay_audio
