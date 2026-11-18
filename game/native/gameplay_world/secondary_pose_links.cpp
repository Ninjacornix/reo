#include "secondary_pose_links.hpp"
#include "../animation/model.hpp"
#include <new>
namespace reo::native::gameplay_world {
namespace {
using animation::NodeLink;
using animation::NodeLinkPatch;
#include "secondary_pose_link_profiles.inc"
template<std::size_t N>SecondaryPoseLinkSelection select(const std::array<std::uint8_t,N>& table,std::size_t index)noexcept{
    if(index>=table.size())return{false,{}};
    if(table[index]==255)return{};
    return{true,table[index]};
}
std::span<const NodeLinkPatch> patches(std::uint8_t profile){
    switch(profile){
    case 0:return secondary_restore_links_0;
    case 1:return secondary_restore_links_1;
    case 2:return secondary_restore_links_2;
    case 3:return secondary_restore_links_3;
    default:return{};
    }
}
}
SecondaryPoseLinkSelection select_secondary_pose_links(const Actor& actor)noexcept{
    if(!actor.active||!actor.visible||(actor.contact_flags&0x40))return{};
    if(actor.category==0){
        if(actor.model_variant)return select(ordinary_variant_secondary_links,std::size_t(actor.model_variant)-1);
        if(actor.model_pose_class==1)return select(high_character_secondary_links,actor.character);
        if(actor.appearance_variant!=0)return{};
        return select(ordinary_character_secondary_links,actor.character);
    }
    if(actor.category==1)return actor.model_pose_class==1?
        select(high_variant_secondary_links,actor.model_variant):select(ordinary_variant_secondary_links,actor.model_variant);
    return{};
}
SecondaryPoseLinksRestored restore_secondary_pose_links(Actor& actor)noexcept{
    const auto selected=select_secondary_pose_links(actor);
    if(!selected.available)return{};
    if(!selected.profile)return{SecondaryPoseLinksStatus::unchanged};
    if(!actor.model)return{SecondaryPoseLinksStatus::unavailable,selected.profile};
    const auto recipe=patches(*selected.profile);
    if(recipe.empty())return{SecondaryPoseLinksStatus::unavailable,selected.profile};
    try{
        actor.model->patch_links(recipe);
        return{SecondaryPoseLinksStatus::restored,selected.profile,recipe.size()};
    }catch(const std::bad_alloc&){return{SecondaryPoseLinksStatus::no_memory,selected.profile};}
    catch(...){return{SecondaryPoseLinksStatus::unavailable,selected.profile};}
}
}
