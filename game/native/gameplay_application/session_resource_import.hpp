#pragma once
#include "../gameplay_world/inventory.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
namespace reo::native::gameplay_application {
enum class ResourceImportStatus {completed,busy,closed,unavailable_profile,invalid_asset,unavailable_actor};
struct ResourceTuningRecord {std::array<std::int16_t,4> values{};};
struct ResourceImportReport {
    ResourceImportStatus status{ResourceImportStatus::unavailable_profile};
    std::string selection_key;
    bool selection_found{},item_found{};
    std::size_t selected{},placed{},starting{},tuning_records{};
};
// Actual ordinary591C50 startup over one canonical resource/inventory graph.
// Offline4BAE96 adjustment and filesystem asset mode remain explicit profiles.
class ResourceBootstrap final {
public:
    ResourceBootstrap(gameplay_world::World&,gameplay_scenario::SceneResources&,
        gameplay_scenario::ResourceTemplates&,gameplay_world::WorldInventory&);
    ResourceImportReport run(const gameplay_scenario::content::ScenarioArchive&)noexcept;
    const std::array<ResourceTuningRecord,129>& tuning()const noexcept{return tuning_;}
private:
    gameplay_world::World& world_;gameplay_scenario::SceneResources& resources_;
    gameplay_scenario::ResourceTemplates& templates_;gameplay_world::WorldInventory& inventory_;
    std::array<ResourceTuningRecord,129> tuning_{};
    bool running_{};
    void clear();
    void selection(std::span<const std::byte>,std::uint16_t,ResourceImportReport&);
    void item(std::span<const std::byte>,ResourceImportReport&);
    void starting(ResourceImportReport&);
};
}
