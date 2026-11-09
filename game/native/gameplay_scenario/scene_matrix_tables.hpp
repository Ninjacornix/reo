#pragma once
#include <array>
#include <cstdint>
#include <span>
namespace reo::native::gameplay_scenario {
struct SceneMatrixKey {float value{};std::int32_t time{};};
struct SceneMatrixSound {std::uint32_t event{};std::int32_t time{};};
struct SceneMatrixProgram {std::uint8_t transform{},count{};std::array<std::uint8_t,6> groups{};};
struct SceneMatrixGroup {std::array<std::uint8_t,4> curves{};std::array<std::int8_t,4> sounds{};};
struct SceneMatrixTables {
    std::array<std::uint8_t,4> descriptors;
    std::array<std::array<std::uint8_t,2>,64> metadata;
    std::array<std::uint8_t,64> direct_remap;
    std::array<SceneMatrixProgram,36> programs;
    std::array<SceneMatrixGroup,59> groups;
    std::array<std::span<const SceneMatrixKey>,64> curves;
    std::array<std::span<const SceneMatrixSound>,13> sounds;
};
const SceneMatrixTables& stock_scene_matrix_tables()noexcept;
}
