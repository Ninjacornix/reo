#pragma once
#include "scene_resources.hpp"
namespace reo::native::gameplay_world {class World;class ResourceModels;class ResourceFactory;class WorldInventory;}
namespace reo::native::gameplay_scenario {
bool script_resource_parameter_noop(const gameplay_world::World&,std::uint16_t)noexcept;
// Complete6949A0 through the actual canonical model/inventory lifetime owners.
// No arbitrary SceneEffects/SceneOwners implementation can stand in for them.
// Borrowed simulation owners must outlive this facade.
class ScriptResourceParameters final {
public:
    ScriptResourceParameters(gameplay_world::World&,SceneResources&,const ResourceTemplates&,
        gameplay_world::ResourceModels&,gameplay_world::ResourceFactory&,gameplay_world::WorldInventory&);
    bool bound_to(const gameplay_world::World&,const SceneResources* = nullptr,const ResourceTemplates* = nullptr)const noexcept;
    bool ready(std::uint16_t resource,std::int16_t quantity)const noexcept;
    SceneStatus command(std::uint16_t resource,std::int16_t quantity)noexcept;
private:
    gameplay_world::World& world_;SceneResources& resources_;const ResourceTemplates& templates_;
    gameplay_world::ResourceModels& models_;gameplay_world::ResourceFactory& factory_;gameplay_world::WorldInventory& inventory_;
    struct Prepared {SceneStatus status{SceneStatus::provider_unavailable};std::optional<AttachedSceneResource> resource{};std::int16_t quantity{};bool detach{};};
    Prepared prepare(std::uint16_t,std::int16_t)const noexcept;
};
}
