#pragma once
#include "cutscene_primary_selection.hpp"
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_scenario {
struct CutsceneRosterActor {std::uint32_t status{};std::uint16_t room{};std::uint8_t character{},slot{};};
struct CutsceneRosterFrame {
    std::array<std::optional<CutsceneRosterActor>,8> actors;
    std::optional<std::uint32_t> authored_population;
    std::optional<std::uint16_t> scenario;
    std::int32_t mode{}; // Scene mode38ECD4, independent of online/offline World.mode.
    // Canonical ActorPlacements request rooms. The source has four owned rows;
    // a read beyond them is unavailable rather than neighboring global memory.
    std::array<std::optional<std::uint8_t>,4> placement_rooms;
};
struct CutsceneRosterState {
    CutscenePrimaryRoster roster;
    std::array<std::uint8_t,8> source_slots{};
    std::array<std::uint32_t,8> source_statuses{};
    std::uint32_t preferred_one_based{};
};
enum class CutsceneRosterStatus {completed,unavailable,invalid_count,invalid_preference,busy,closed};
struct CutsceneRosterPrepared {
    CutsceneRosterStatus status{CutsceneRosterStatus::unavailable};
    CutsceneRosterState state;
    std::array<bool,8> hide_primaries{};
};
// Pure roster/visibility projection of5ED340. Previous tail bytes/metadata are
// explicit inputs. This does not reset pools/banks, release render resources or
// publish a live World. The enclosing scene owner must serialize that lifecycle.
inline CutsceneRosterPrepared prepare_cutscene_roster(const CutsceneRosterFrame& frame,const CutsceneRosterState& previous)noexcept{
    const auto failed=[&](CutsceneRosterStatus status){return CutsceneRosterPrepared{status,previous,{}};};
    if(!frame.authored_population||!frame.scenario)return failed(CutsceneRosterStatus::unavailable);
    const auto population=*frame.authored_population,preferred=previous.preferred_one_based;
    if(population>8)return failed(CutsceneRosterStatus::invalid_count);
    if(preferred>8)return failed(CutsceneRosterStatus::invalid_preference);
    for(unsigned i=0;i<population;++i)if(!frame.actors[i])return failed(CutsceneRosterStatus::unavailable);
    CutsceneRosterPrepared result{CutsceneRosterStatus::completed,previous,{}};result.state.roster.eligible_count=0;
    const auto append=[&](const CutsceneRosterActor& actor){
        const auto index=result.state.roster.eligible_count++;
        result.state.roster.characters[index]=actor.character;result.state.source_slots[index]=actor.slot;result.state.source_statuses[index]=actor.status;
    };
    for(unsigned i=0;i<population;++i){
        result.hide_primaries[i]=true;const auto& actor=*frame.actors[i];if(actor.status&0x5e0u)continue;
        if(frame.mode==4||frame.mode==5){
            if(!preferred)continue;
            if(!frame.actors[preferred-1])return failed(CutsceneRosterStatus::unavailable);
            if(actor.room!=frame.actors[preferred-1]->room)continue;
        }else if(frame.mode==6&&(!preferred||i!=preferred-1)){
            if(!preferred||preferred>frame.placement_rooms.size()||!frame.placement_rooms[preferred-1])return failed(CutsceneRosterStatus::unavailable);
            if(actor.room!=*frame.placement_rooms[preferred-1])continue;
        }
        append(actor);
    }
    if(*frame.scenario==0x23&&frame.mode==6&&result.state.roster.eligible_count==1){
        for(unsigned i=0;i<population;++i)if(frame.actors[i]->room==0x13){append(*frame.actors[i]);break;}
    }
    if(preferred)for(unsigned i=0;i<result.state.roster.eligible_count;++i)if(result.state.source_slots[i]==preferred-1){result.state.preferred_one_based=i+1;break;}
    return result;
}
// Publish the roster/visibility projection from canonical World/session data.
// Resource cleanup and temporary-pool reset are separate phase operations.
class CutsceneRosterPreparation final {
public:
    static CutsceneRosterStatus apply(gameplay_world::World&,CutsceneRosterState&,std::int32_t scene_mode)noexcept;
};
}
