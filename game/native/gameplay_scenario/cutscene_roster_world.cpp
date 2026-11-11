#include "cutscene_roster_preparation.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
CutsceneRosterStatus CutsceneRosterPreparation::apply(gameplay_world::World& world,CutsceneRosterState& state,std::int32_t mode)noexcept{
    if(world.closed())return CutsceneRosterStatus::closed;
    if(world.busy())return CutsceneRosterStatus::busy;
    CutsceneRosterFrame frame;frame.authored_population=world.session().primary_population;frame.scenario=world.scenario;frame.mode=mode;
    std::array<std::shared_ptr<gameplay_world::Actor>,8> actors;
    for(unsigned i=0;i<8;++i){actors[i]=world.primary(i);if(actors[i])frame.actors[i]=CutsceneRosterActor{actors[i]->status,actors[i]->room,actors[i]->character,actors[i]->slot};}
    for(unsigned i=0;i<frame.placement_rooms.size();++i)frame.placement_rooms[i]=world.session().actor_placements.requests()[i].room;
    const auto prepared=prepare_cutscene_roster(frame,state);if(prepared.status!=CutsceneRosterStatus::completed)return prepared.status;
    world.updating_=true;struct Reset{bool& busy;~Reset(){busy=false;}}reset{world.updating_};
    for(unsigned i=0;i<8;++i)if(prepared.hide_primaries[i])actors[i]->visible=false;
    state=prepared.state;return CutsceneRosterStatus::completed;
}
}
