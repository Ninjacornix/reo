#pragma once
#include "../gameplay_scenario/scenario_archive.hpp"
#include "../gameplay_scenario/room_return_points.hpp"
#include "../gameplay_world/world.hpp"
#include <array>
#include <memory>
#include <optional>
namespace reo::native::gameplay_application {
enum class ScenarioDataStatus {completed,unavailable,busy,closed,no_memory,invalid_asset};
struct EnemyPlacement {
    std::uint16_t field0{},yaw{};
    std::array<std::int32_t,3> position{};
    std::uint32_t field16{};
};
struct EnemyPlacementResult {ScenarioDataStatus status{ScenarioDataStatus::unavailable};std::optional<EnemyPlacement> placement;};
struct DoorPositionRecord {std::uint8_t type{},id{};std::uint16_t group{};std::int16_t x{},z{};};
struct DoorRecordView {std::span<const std::byte> groups;std::uint32_t metadata{};std::span<const std::byte> admissions;};
// 1BAEC0's retained EPP/door workspaces and 759D50's position bank.
// Initialization is a concrete fresh-application step, never a roster retry.
class SessionScenarioResources final {
public:
    SessionScenarioResources(gameplay_world::World&,const gameplay_scenario::content::ScenarioArchive&)noexcept;
    ~SessionScenarioResources();
    SessionScenarioResources(const SessionScenarioResources&)=delete;
    SessionScenarioResources& operator=(const SessionScenarioResources&)=delete;
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool ready()const noexcept{return initialized_&&!closed_&&!world_.closed();}
    bool busy()const noexcept{return running_;}
    ScenarioDataStatus initialize()noexcept;
    ScenarioDataStatus load_placements()noexcept; // complete 1D49E0 for scenario archives
    ScenarioDataStatus load_doors()noexcept; // complete bounded 6DD9A0
    ScenarioDataStatus load_return_points()noexcept; //1D4570, missing file preserves prior bytes
    std::shared_ptr<const gameplay_scenario::RoomReturnPoints> return_points()const noexcept{return ready()&&!running_?return_points_:nullptr;}
    ScenarioDataStatus reset_positions()noexcept; // complete 6ECAC0
    EnemyPlacementResult placement(std::uint16_t,std::uint16_t,std::uint16_t)const noexcept;
    // Borrowed spans expire on the next door reload or owner close.
    std::optional<DoorRecordView> doors()const noexcept;
    std::span<const DoorPositionRecord> positions()const noexcept;
    ScenarioDataStatus close()noexcept;
private:
    gameplay_world::World& world_;
    const gameplay_scenario::content::ScenarioArchive& archive_;
    std::unique_ptr<std::byte[]> epp_,door_,rtp_;
    std::shared_ptr<const gameplay_scenario::RoomReturnPoints> return_points_;
    std::array<DoorPositionRecord,64> positions_{};
    std::size_t epp_known_{},door_group_end_{},door_admission_{},rtp_known_{};
    std::uint32_t door_metadata_{};
    bool initialized_{},positions_ready_{},doors_ready_{},running_{},closed_{};
};
}
