#pragma once
#include "game/native/gameplay_scenario/text_cache.hpp"
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <vector>

namespace reo::native::gameplay_presentation {
struct FontGlyph {
    std::int32_t x{},y{};
    std::uint32_t size{},rgb{},index{};
    std::uint8_t alpha{};
    bool half_width{};
    friend bool operator==(const FontGlyph&,const FontGlyph&)=default;
};
// File1 font descriptor 6: one retained source-owned 7808-glyph bitmap.
// Immutable after construction; no guest memory or presentation pointer stored.
class FontFace final {
public:
    explicit FontFace(std::vector<std::byte>);
    static std::uint32_t single_code(std::uint8_t)noexcept;
    static std::uint32_t index(std::uint16_t)noexcept;
    std::span<const std::byte> bitmap(std::uint32_t)const noexcept;
    std::optional<std::vector<FontGlyph>> layout(const gameplay_scenario::CachedText&)const;
private:
    std::vector<std::byte> bytes_;
};
// Canonical 4BAE94 menu gate for the native frontend lifetime. The explicit
// fresh application boundary establishes its cold BSS value; future menu
// handling must write this same owner, not infer it from World::paused.
class FrontendTextGate final {
public:
    bool suppressed()const noexcept{return suppressed_;}
    void set_suppressed(bool value)noexcept{suppressed_=value;}
private:
    bool suppressed_{};
};
}
