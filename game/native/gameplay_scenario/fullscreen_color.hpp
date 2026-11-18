#pragma once
#include "display_fade.hpp"
#include <array>
#include <memory>
#include <optional>
#include <span>
#include <vector>
namespace reo::native::gameplay_scenario {
struct FullscreenColorState {
    // The first three source words are retained numerically until their
    // independent fullscreen command consumers assign narrower meanings.
    std::array<std::uint32_t,3> controls{};
    DisplayRectangle rectangle;
};
struct FullscreenColorKey {std::uint16_t frame{};std::uint32_t kind{};std::array<std::uint16_t,4> channels{};};
class FullscreenColorSource {
public:
    virtual ~FullscreenColorSource()=default;
    virtual std::optional<FullscreenColorKey> key(std::size_t)const noexcept=0;
};
class FullscreenColorStream final:public FullscreenColorSource {
public:
    static std::shared_ptr<const FullscreenColorStream> import(std::span<const std::byte>);
    const auto& keys()const noexcept{return keys_;}
    std::optional<FullscreenColorKey> key(std::size_t index)const noexcept override{
        return index<keys_.size()?std::optional(keys_[index]):std::nullopt;
    }
private:std::vector<FullscreenColorKey> keys_;
};
enum class FullscreenColorStatus {completed,unavailable};
class FullscreenColor final {
public:
    explicit FullscreenColor(FullscreenColorState& state)noexcept:state_(state){}
    FullscreenColor(const FullscreenColor&)=delete;
    FullscreenColor& operator=(const FullscreenColor&)=delete;
    // Complete1BBB10 reset, including retirement of the old authored binding.
    void reset(std::uint32_t color)noexcept;
    FullscreenColorStatus bind(std::shared_ptr<const FullscreenColorSource>,std::size_t)noexcept;
    FullscreenColorStatus sample(std::uint32_t frame)noexcept;
    std::optional<std::size_t> binding()const noexcept{return position_;}
private:
    FullscreenColorState& state_;
    std::shared_ptr<const FullscreenColorSource> stream_;
    std::optional<std::size_t> position_;
};
} // namespace reo::native::gameplay_scenario
