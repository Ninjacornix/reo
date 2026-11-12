#include "actor_offset_sound_policy.hpp"
namespace reo::native::gameplay_world {
ActorOffsetSoundPlan plan_actor_offset_sound(std::optional<ActorSoundState> state,std::uint32_t event)noexcept{
    if(!state)return{};
    if(!state->allocation_slot&&!state->program_variant)return{true,{}};
    //554 is only the outer gate here;1AC7F0 overwrites its incoming a2.
    return{true,gameplay_audio::Request{12,event,UINT32_MAX,UINT32_MAX,state->program_variant}};
}
}
