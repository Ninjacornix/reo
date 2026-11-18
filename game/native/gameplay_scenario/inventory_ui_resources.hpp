#pragma once
#include "scene_text_bank.hpp"
#include <memory>
namespace reo::assets {struct Source;}
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_scenario {
enum class InventoryResourcesStatus {completed,busy,closed,unavailable,invalid_asset,no_memory};
// Host resource identities replace the old GS arena addresses. Pixel indices,
// source alpha (0..128), palettes and authored dimensions remain exact.
struct InventoryImage {
    struct Region {std::uint32_t byte_offset{};std::uint16_t width{},height{},source_palette_selector{};};
    std::uint64_t identity{};
    std::uint16_t width{},height{},count{},palette_count{};
    std::uint8_t index_bits{};
    std::vector<std::byte> indices;
    std::vector<std::uint32_t> palettes;
    std::vector<Region> regions;
};
struct InventoryBackgroundParticle {
    std::uint16_t angle{};
    std::uint8_t selector{};
    float velocity_x{},velocity_y{},x{},y{};
    std::int8_t offset_x{},offset_y{};
};
struct InventoryResourceSnapshot {
    std::array<std::uint8_t,3> cache{}; //4BAE7C/7D/7E
    bool cache_known{};
    content::Bytes common_text,scenario_text,special_items,files;
    std::optional<InventoryImage> item_icons,file_icons,background;
    std::array<InventoryBackgroundParticle,32> particles{};
    std::optional<bool> result_present; //75:5760;unknown identity is preserved
    std::optional<std::uint64_t> context_identity;
};
// Complete reached604310 ->6DDD70(0) resource producer. Construction is inert.
// This publishes UI resources; the active inventory presentation consumer is
// separately required before claiming a visible inventory screen.
class InventoryUiResources final {
public:
    InventoryUiResources(gameplay_world::World&,const content::ScenarioArchive&,
        std::shared_ptr<const reo::assets::Source>,
        const std::optional<SceneTextVariant>& canonical_selector)noexcept;
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool ready_zero()const noexcept;
    bool busy()const noexcept{return running_;}
    InventoryResourcesStatus refresh_zero()noexcept;
    InventoryResourcesStatus close()noexcept;
    const InventoryResourceSnapshot& snapshot()const noexcept{return state_;}
private:
    gameplay_world::World& world_;
    const content::ScenarioArchive& archive_;
    std::shared_ptr<const reo::assets::Source> source_;
    const std::optional<SceneTextVariant>& selector_;
    InventoryResourceSnapshot state_;
    std::uint64_t next_identity_{1};
    std::shared_ptr<const std::uint64_t> context_;
    bool running_{},closed_{};
};
}
