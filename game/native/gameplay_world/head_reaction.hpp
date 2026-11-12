#pragma once
#include "world.hpp"
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_world {
enum class HeadReactionStatus {unchanged,applied,unavailable,no_memory};
struct HeadReactionContext {
    // Borrowed scene camera4A6D48, required only by reaction mode2.
    std::optional<Position> camera;
};
// Complete376EF0 finite position-to-angle helper, including its X-zero bias.
std::array<std::int16_t,3> head_direction_turns(transform_math::Vector from,transform_math::Vector to);
// Complete661160/661310 humanoid head transition and reset helpers.
void advance_head_reaction(Actor&,std::array<std::int16_t,3>);
void reset_head_reaction(Actor&);
// Complete65F0C0 selection over the canonical World metric/linked owners.
actors::EntityId select_head_target(World&,const Actor&,float distance,std::uint8_t selector,std::int16_t aperture,std::uint8_t ordinal);
//6613A0 and67C100. Optional state is supplied by the actual humanoid owner.
HeadReactionStatus update_head_reaction(World&,Actor&,std::uint8_t mode,const HeadReactionContext& = {})noexcept;
HeadReactionStatus update_scripted_head_reaction(World&,Actor&,const HeadReactionContext& = {})noexcept;
//66A3A0 head-selection portion, after its own visibility/room/frame prelude.
// The wider ordinary callback also owns contact/statistics work separately.
HeadReactionStatus update_ordinary_head_reaction(World&,Actor&,const HeadReactionContext& = {})noexcept;
enum class OrdinaryHeadAction {unchanged,reset,track,unavailable};
OrdinaryHeadAction ordinary_head_action(const Actor&)noexcept;
// The concrete head +61A820 portion of66A3A0 after its room/frame prelude.
HeadReactionStatus finish_ordinary_actor_reactions(World&,Actor&,const HeadReactionContext& = {})noexcept;
struct CinematicReactionsUpdated {
    HeadReactionStatus status{HeadReactionStatus::applied};
    std::size_t temporary_visits{},auxiliary_visits{},heads{},secondary{};
    actors::EntityId failed{};
};
// Actual5ECBE0 post-model pass: visible temporary players then auxiliary NPCs,
// head reaction followed by the canonical61A820 secondary pose owner.
class CinematicActorReactions final {
public:
    explicit CinematicActorReactions(World& world):world_(world){}
    ~CinematicActorReactions();
    CinematicActorReactions(const CinematicActorReactions&)=delete;
    CinematicActorReactions& operator=(const CinematicActorReactions&)=delete;
    CinematicReactionsUpdated run()noexcept;
private:
    World& world_;bool running_{};
};
}
