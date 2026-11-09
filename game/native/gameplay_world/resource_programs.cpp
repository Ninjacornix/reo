#include "resource_programs.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
void WorldResourcePrograms::select(Actor& actor,std::uint32_t mode){
    if(world_.closed()||!world_.identity_of(actor))throw std::runtime_error("Native resource program actor foreign or retired");
    if(!actor.selected_resource)return;
    const auto id=resources_.slot(actor.selected_resource);const auto descriptor=id?resources_.get(*id):std::nullopt;
    if(!descriptor)throw std::runtime_error("Native resource program descriptor unavailable");
    if(!descriptor->primary)return;
    const auto target=std::dynamic_pointer_cast<ResourceModel>(descriptor->primary);
    if(!target)throw std::runtime_error("Native resource program primary capability unavailable");
    auto& state=target->program;
    if(actor.category!=0){state.phase=0;return;}
    state.phase=1;
    if(actor.slot>=4||!actor.weapon_programs)throw std::runtime_error("Native actor WMD source unavailable");
    state.source=actor.weapon_programs;
    const unsigned style=actor.motion_style?1:0;
    const unsigned index=(mode==0?(descriptor->parameter?0u:8u):mode==1?2u:mode==2?4u:6u)+style;
    const auto& selection=state.source->selection(index);
    if(selection.kind==animation::WeaponSelectionKind::unavailable)throw std::runtime_error("Native WMD selector overlaps unadmitted source data");
    state.selected=selection.program;state.selection_index=index;
    if(!state.selected){state.phase=0;return;}
    state.elapsed=0;state.completed.fill(0);
}
}
