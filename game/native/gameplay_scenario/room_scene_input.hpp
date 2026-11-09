#pragma once
#include "content.hpp"
#include "../gameplay_scene/records.hpp"

namespace reo::native::gameplay_scenario {
enum class RoomProxyHelper {
  none,
  depth_extension,
  depth_sixty,
  reproject_middle
};
struct RoomProxyModelSetup {
  std::uint8_t slot{};
  std::optional<std::uint8_t> sound_resource;
  RoomProxyHelper helper{};
};
// Immutable authored definition. Parsed initial values do not advertise an
// installed collision/task consumer or manufacture a native model for FF.
struct RoomProxyDefinition {
  gameplay_scene::Record initial;
  std::uint8_t ordinal{};
  std::optional<RoomProxyModelSetup> model;
  std::optional<std::uint32_t> type_one_initial_angle;
  std::optional<float> room_height;
};
class RoomSceneInput final {
public:
  RoomSceneInput(std::span<const std::byte> section_a,
                 const content::ScriptBank &,
                 gameplay_collision::ImportContext = {});
  std::span<const RoomProxyDefinition> records() const noexcept {
    return records_;
  }
  const std::array<std::uint8_t, 32> &mapping(std::size_t index) const;

private:
  std::array<std::array<std::uint8_t, 32>, 2> maps_;
  std::vector<RoomProxyDefinition> records_;
};
} // namespace reo::native::gameplay_scenario
