#pragma once
#include "model_attachments.hpp"
namespace reo::native::gameplay_world {
// Complete6B4420 selector over actual canonical actor/resource owners. WMD
// playback/visual submission remains a separate consumer of this same state.
class WorldResourcePrograms final {
public:
    WorldResourcePrograms(World& world,gameplay_scenario::SceneResources& resources):world_(world),resources_(resources){}
    bool bound_to(const World& world,const gameplay_scenario::SceneResources& resources)const noexcept{return &world_==&world && &resources_==&resources && !world_.closed();}
    void select(Actor&,std::uint32_t mode);
private:
    World& world_;
    gameplay_scenario::SceneResources& resources_;
};
}
