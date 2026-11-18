#include "launch_roster.hpp"
#include "world.hpp"
#include "../gameplay_scenario/action_choices.hpp"

namespace reo::native::gameplay_world {
bool apply_launch_roster(World& world,gameplay_scenario::ActionChoices& choices,
                         const gameplay_session::LaunchRoster& roster) noexcept {
    if(world.closed()||roster.count>roster.actors.size()||roster.choice_row>=4)return false;
    std::array<std::shared_ptr<Actor>,6> actors;
    for(std::size_t index=0;index<roster.count;++index) {
        actors[index]=world.primary(index);
        if(!actors[index])return false;
    }
    auto choice_state=choices.state();
    choice_state.table_row=roster.choice_row;
    if(!choices.restore(choice_state))return false;
    auto& session=world.session();
    if(world.mode==0)session.single_roster_setup=1;
    session.gameplay_flags=roster.gameplay_flags;
    session.scenario=roster.scenario;
    for(std::size_t index=0;index<roster.count;++index) {
        auto& actor=*actors[index];
        const auto& entry=roster.actors[index];
        actor.character=entry.character;
        actor.appearance_variant=entry.appearance;
        actor.model_variant=entry.model_variant;
        actor.ai_control=entry.ai_control;
    }
    session.primary_population=std::uint32_t(roster.count);
    const auto observed=std::uint8_t(session.random.request(3)&3u);
    auto random=session.random.state();
    random.observed=observed;
    session.random.restore(random);
    return true;
}
}
