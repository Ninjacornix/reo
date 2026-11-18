#pragma once
#include "scene_resources.hpp"
#include <cstdint>
namespace reo::native::gameplay_world {
class World;class ResourceModels;class ResourceFactory;
}
namespace reo::native::gameplay_scenario {
// Complete694D70/592E90. This borrows the actual delayed resource constructor
// and its canonical pool; no effect-service implementation can stand in for it.
class ScriptResourceActivation final {
public:
    ScriptResourceActivation(gameplay_world::World&,SceneResources&,const ResourceTemplates&,
                             gameplay_world::ResourceModels&,gameplay_world::ResourceFactory&);
    bool bound_to(const gameplay_world::World&,const SceneResources* = nullptr,
                  const ResourceTemplates* = nullptr)const noexcept;
    SceneStatus command(std::int16_t authored,std::int16_t ticks)noexcept;
private:
    gameplay_world::World& world_;SceneResources& resources_;const ResourceTemplates& templates_;
    gameplay_world::ResourceModels& models_;gameplay_world::ResourceFactory& factory_;
};
}
