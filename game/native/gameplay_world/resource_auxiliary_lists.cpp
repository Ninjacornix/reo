#include "resource_auxiliary_lists.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceAuxiliaryLists::ResourceAuxiliaryLists(WorldInventory& inventory):world_(inventory.world_),resources_(inventory.resources_),templates_(inventory.templates_){
    if(world_.closed())throw std::invalid_argument("Native auxiliary resource world closed");
}
std::array<std::uint8_t,8>& ResourceAuxiliaryLists::list(std::uint32_t full_actor)const{
    if(world_.closed())throw std::runtime_error("Native auxiliary resource world closed");
    const auto actor=std::bit_cast<std::int8_t>(std::uint8_t(full_actor));
    if(actor<0||unsigned(actor)>=world_.session().auxiliary_resources.size())throw std::runtime_error("Native auxiliary resource actor unavailable");
    return world_.session().auxiliary_resources[unsigned(actor)];
}
gameplay_scenario::SceneDescriptor ResourceAuxiliaryLists::descriptor(std::uint8_t resource)const{
    const auto id=resources_.slot(resource);const auto value=id?resources_.get(*id):std::nullopt;
    if(!value)throw std::runtime_error("Native auxiliary resource descriptor unavailable");
    return *value;
}
unsigned ResourceAuxiliaryLists::group(const gameplay_scenario::SceneDescriptor& item)const{
    const auto index=item.active&&item.template_index!=255?unsigned(item.template_index):128u;
    if(index>=templates_.state().templates.size())throw std::runtime_error("Native auxiliary resource template unavailable");
    const auto value=std::to_integer<unsigned>(templates_.state().templates[index].encoded[0x15]);
    if(value>=4)throw std::runtime_error("Native auxiliary resource group unavailable");
    return value;
}
unsigned ResourceAuxiliaryLists::emit(std::array<std::uint8_t,8>& target,const Groups& groups,const std::array<unsigned,4>& used){
    target.fill(0);unsigned count{};
    for(unsigned reverse=0;reverse<4;++reverse){const auto group=3-reverse;for(unsigned i=0;i<used[group]&&count<target.size();++i)target[count++]=groups[group][i];}
    return count;
}
std::int8_t ResourceAuxiliaryLists::append(std::uint32_t actor,std::span<const std::uint8_t> input,std::int32_t count){
    auto& target=list(actor);Groups groups{};std::array<unsigned,4> used{};
    for(const auto resource:target){if(!resource)continue;const auto item=descriptor(resource);if(!item.active)continue;const auto kind=group(item);groups[kind][used[kind]++]=resource;}
    unsigned accepted{};const auto owner=unsigned(std::bit_cast<std::int8_t>(std::uint8_t(actor)))+1u;
    for(std::int32_t i=0;i<count;++i){
        if(std::size_t(i)>=input.size())throw std::runtime_error("Native auxiliary resource input unavailable");
        const auto resource=input[std::size_t(i)];if(!resource)continue;auto item=descriptor(resource);if(!item.active)continue;
        if((templates_.flags(item.template_index)&0x40u)||item.ownership_tag!=owner)continue;
        const auto kind=group(item);if(used[kind]>=8)continue;
        item.claim_tag=0;const auto id=resources_.slot(resource);
        if(!id||resources_.replace(*id,item)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native auxiliary resource descriptor changed");
        groups[kind][used[kind]++]=resource;++accepted;
    }
    if(accepted)(void)emit(target,groups,used);
    return std::int8_t(accepted);
}
std::int8_t ResourceAuxiliaryLists::remove(std::uint32_t actor,std::uint32_t full_resource){
    auto& target=list(actor);Groups groups{};std::array<unsigned,4> used{};bool removed{};const auto resource=std::uint8_t(full_resource);
    for(const auto existing:target){if(!existing)continue;if(existing==resource){removed=true;continue;}const auto item=descriptor(existing);if(!item.active)continue;const auto kind=group(item);groups[kind][used[kind]++]=existing;}
    if(removed)(void)emit(target,groups,used);
    return std::int8_t(removed);
}
std::int8_t ResourceAuxiliaryLists::regroup(std::uint32_t actor){
    auto& target=list(actor);Groups groups{};std::array<unsigned,4> used{};
    for(const auto resource:target){if(!resource)continue;const auto item=descriptor(resource);if(!item.active)continue;const auto kind=group(item);groups[kind][used[kind]++]=resource;}
    return std::int8_t(emit(target,groups,used));
}
}
