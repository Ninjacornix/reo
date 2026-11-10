#pragma once
#include "resource_recipes.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
struct ResourceDeploymentValue {ResourceModelStatus status{ResourceModelStatus::completed};std::int8_t value{};};
class ResourceDeployment final {
public:
    ResourceDeployment(ResourceRecipes&,gameplay_update::Owner&);
    ResourceDeploymentValue count()const; //5B5AF0
    ResourceDeploymentValue admission(std::uint32_t resource)const; //5B2770/5B2890
    ResourceModelCreated place(const actors::EntityId&,std::uint32_t resource,const Position&); //5B5CB0
    ResourceDeploymentValue effect(std::uint32_t resource,const actors::EntityId&); //5B26D0
private:
    ResourceRecipes& lifecycle_;gameplay_update::Owner& update_;ResourceFactory& factory_;
};
}
