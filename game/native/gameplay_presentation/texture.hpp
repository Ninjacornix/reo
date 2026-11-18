#pragma once
#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>
namespace reo::native::gameplay_presentation {
struct Texture {
    std::uint16_t width{},height{};
    std::vector<std::uint8_t> rgba;
};
// Bounded Outbreak halfword compression and indexed TIM2 used by the owned
// room/character profiles. Unsupported encodings refuse without placeholders.
std::vector<std::byte> decompress_texture(std::span<const std::byte>);
Texture decode_texture(std::span<const std::byte>);
}
