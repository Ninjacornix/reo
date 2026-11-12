#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
namespace reo::native::gameplay_scenario {
enum class TextCacheStatus {completed,unbound,unsupported_profile};
struct CachedText {
    bool active{};
    std::int16_t x{},y{},duration{};
    std::uint8_t height{},fade{},alpha{},priority{};
    std::array<std::byte,128> text{};
    friend bool operator==(const CachedText&,const CachedText&)=default;
};
struct CachedTextResult {TextCacheStatus status{TextCacheStatus::completed};std::optional<std::size_t> index;};
// One simulation-owned queue of the32 actual3151D0 text entries. Snapshots are
// values; rendering does not borrow mutable live cache storage.
class TextCache final {
public:
    static constexpr std::size_t capacity=32;
    void reset()noexcept; //1B4A60 record clear
    bool initialized()const noexcept{return initialized_;}
    std::optional<std::array<CachedText,capacity>> snapshot()const noexcept{return initialized_?std::optional(records_):std::nullopt;}
    CachedTextResult request(std::int32_t priority,std::int32_t x,std::int32_t y,std::int32_t duration,
        std::int32_t height,std::span<const std::byte>,std::int32_t fade)noexcept; //1B46E0
    CachedTextResult dialogue(std::int16_t x,std::uint16_t y,std::span<const std::byte>,std::uint8_t alpha)noexcept; //1B48E0 fixed dialogue args
    TextCacheStatus erase(std::span<const std::byte>)noexcept; //1B49B0
    TextCacheStatus expire()noexcept; //1B4940
    TextCacheStatus cull()noexcept; //1B4450
private:
    std::array<CachedText,capacity> records_;
    bool initialized_{};
};
} // namespace reo::native::gameplay_scenario
