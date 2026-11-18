#pragma once
#include "pose_arcs.hpp"
namespace reo::native::gameplay_world {
struct PoseTrailSelection {std::uint8_t policy{};std::uint16_t resource{};};
// Actual578620 byte-type/mode/resource admission. A disengaged selection is
// the original early no-effect branch, before any motion or resource read.
std::optional<PoseTrailSelection> select_pose_trail(std::uint8_t type,std::uint8_t mode)noexcept;
class PoseTrailAdmission final:public PoseTrails {
public:
    PoseTrailAdmission(World&,PoseTrails* reached_consumer=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool emit(const actors::EntityId&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseTrails* reached_;
};
}
