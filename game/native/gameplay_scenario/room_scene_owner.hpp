#pragma once
#include "room_scene_input.hpp"
#include "scene_matrix_programs.hpp"

namespace reo::native::gameplay_scenario {
struct RoomSceneGlobals {
  // Original49F78C. Only a type10 record writes it during this initializer;
  // absence preserves the caller's canonical state instead of resetting it.
  std::optional<float> height;
};
enum class RoomSceneStatus {
  completed,
  owner_mismatch,
  nonempty_pool,
  unadmitted_model,
  unadmitted_channel,
  unsupported_numeric,
  pool_full,
  no_memory
};
enum class NoModelRepair {disabled,authored_absent};
class RoomSceneOwner;
struct RoomSceneInstalled {
  RoomSceneStatus status{RoomSceneStatus::completed};
  std::unique_ptr<RoomSceneOwner> owner;
};
class RoomSceneOwner final {
public:
  static RoomSceneInstalled install(std::shared_ptr<const RoomSceneInput>,
                                    SceneControls &,
                                    gameplay_collision::ownership::Proxies &,
                                    SceneModels &, SceneMatrixPrograms &,
                                    RoomSceneGlobals &,NoModelRepair=NoModelRepair::disabled) noexcept;
  ~RoomSceneOwner();
  RoomSceneOwner(const RoomSceneOwner &) = delete;
  RoomSceneOwner &operator=(const RoomSceneOwner &) = delete;
  std::span<const gameplay_scene::RecordId> identities() const noexcept {
    return ids_;
  }
  // Returns immutable authored initial state, never a second mutable runtime
  // record. Retired/reused identities refuse even while this owner survives.
  const RoomProxyDefinition *
  definition(const gameplay_scene::RecordId &) const noexcept;
  void close() noexcept;

private:
  RoomSceneOwner(std::shared_ptr<const RoomSceneInput>,
                 std::shared_ptr<gameplay_scene::Records>);
  std::shared_ptr<const RoomSceneInput> input_;
  std::shared_ptr<gameplay_scene::Records> records_;
  std::shared_ptr<const AuthoredModelLease> absent_lease_;
  std::vector<gameplay_scene::RecordId> ids_;
  std::vector<std::pair<gameplay_scene::RecordId, std::size_t>> definitions_;
};
} // namespace reo::native::gameplay_scenario
