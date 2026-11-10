#include "reactions.hpp"
#include "../gameplay_session/session.hpp"
namespace reo::native::gameplay_ai {
namespace {
struct Policy {std::int8_t duration,reaction,auxiliary;std::array<std::int8_t,8> chances;};
constexpr std::array<Policy,13> policies{{
#include "reaction_policies.inc"
}};
}
ReactionScheduled schedule_reaction(ExecutionState& state,std::uint8_t character,std::uint32_t event,gameplay_session::Random& random)noexcept{
    if(event>=policies.size())return {Status::completed,0,false};
    const auto& policy=policies[event];
    ReactionScheduled result{Status::completed,0,false};
    const auto write=[&](std::uint8_t reaction){state.pending_reaction=reaction;state.reaction_countdown=std::uint16_t(std::int16_t(policy.duration));result.written=true;};
    if(event==12){write(std::uint8_t(policy.reaction));return result;}
    const bool weighted=event>=5&&event<=8;
    if(weighted){
        unsigned best=0,index=0;
        for(unsigned i=0;i<8;++i)if(state.combined_weights[i]>best){best=state.combined_weights[i];index=i;}
        if(int(index)!=policy.auxiliary){write(index==3?11:10);return result;}
    }
    if(character>=policy.chances.size())return {};
    const auto draw=[&]{++result.random_draws;return int(random.request(1)%100);};
    if(draw()>policy.chances[character])return result;
    write(std::uint8_t(policy.reaction));
    if(!weighted&&policy.auxiliary&&draw()<=policy.auxiliary)state.pending_reaction=11;
    return result;
}
}
