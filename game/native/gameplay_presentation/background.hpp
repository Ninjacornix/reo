#pragma once
#include <array>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_presentation {
// 1AF6A0 -> 196010(0x14) -> 197470. The finite owned palette is the
// 48-byte File1 table immediately preceding the next data record at234380.
class BackgroundState final {
public:
    bool select(std::uint32_t index)noexcept;
    const std::optional<std::array<std::uint8_t,3>>& rgb()const noexcept{return rgb_;} // 32407C..7E
    std::optional<std::uint32_t> parameter14()const noexcept{return parameter14_;} // 29FD50
    // Other real 197470 callers may update the render parameter independently
    // of 1AF6A0's RGB bytes; unknown prior RGB stays unknown.
    void parameter14(std::uint32_t word)noexcept{parameter14_=word;}
private:
    std::optional<std::array<std::uint8_t,3>> rgb_;
    std::optional<std::uint32_t> parameter14_;
};
}
