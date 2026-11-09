#pragma once
#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <span>
namespace reo::native::gameplay_scenario {
// Immutable asset-format records, not live logical-resource records.
struct ResourceTemplate {
    std::array<std::byte, 24> encoded{};
};
struct ResourceTemplateState {
    std::array<ResourceTemplate, 129> templates;
    std::array<float, 129> y_offsets{};
    std::array<float, 128> offsets{};
    std::array<std::uint16_t, 384> compatibility{};
    std::array<std::uint8_t, 600> selectors;
    std::uint16_t count{};
};
class ResourceTemplates final {
  public:
    // Exact cleared-table starting state from5919F0, independent of SceneResources.
    ResourceTemplates() noexcept;
    bool load(std::span<const std::byte> version3_section);
    const ResourceTemplateState& state() const noexcept {
        return state_;
    }
    std::int8_t action_kind(std::uint8_t template_index) const;
    std::uint32_t flags(std::uint8_t template_index) const;
    // Complete5B42B0. Invalid content returns0; a tableFF is signed-1.
    std::int8_t selector(std::int16_t content) const noexcept {
        std::int32_t index=content;
        if(index>=10000)index=index%100+500;
        return index<0||index>=600?std::int8_t(0):std::bit_cast<std::int8_t>(state_.selectors[unsigned(index)]);
    }

  private:
    ResourceTemplateState state_;
};
} // namespace reo::native::gameplay_scenario
