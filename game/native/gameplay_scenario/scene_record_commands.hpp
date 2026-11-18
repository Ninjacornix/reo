#pragma once
#include "flags.hpp"
#include "../gameplay_world/world.hpp"

namespace reo::native::gameplay_scenario {
// Complete admitted6943D0: clear the canonical condition bit first, then
// inspect all256 physical descriptor rows, including rows beyond count().
// Matching remote rows retire the first actual kind2 control registration.
// This operation does not retire live actors or synthesize notifications.
inline bool clear_scene_record_eligibility(FlagState& flags,gameplay_world::World& world,
                                           std::uint32_t id)noexcept {
    if(world.closed()||id>=SceneRecordEligibility::capacity)return false;
    if(!flags.write(FlagBank::scene_record_eligibility,id,false))return false;
    auto& session=world.session();
    const auto records=session.enemy_descriptors.records();
    for(std::size_t index=0;index<records.size();++index)
        if(records[index].owner_mode&&records[index].condition==id)
            (void)session.ai_control_requests.unregister_control(2,std::uint32_t(index));
    return true;
}
}
