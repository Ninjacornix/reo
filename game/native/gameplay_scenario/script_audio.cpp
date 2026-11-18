#include "script_audio.hpp"
#include "../gameplay_audio/scenario_cues.hpp"
#include <stdexcept>
namespace reo::native::gameplay_scenario {
ScriptAudio::ScriptAudio(gameplay_world::World& world,gameplay_audio::Owner& owner,
                         const gameplay_audio::SpatialContext& spatial)
    :world_(world),owner_(owner),spatial_(spatial){
    if(!bound_to(world))throw std::invalid_argument("Native script audio requires the canonical World/bank owner");
}
bool ScriptAudio::bound_to(const gameplay_world::World& world)const noexcept{
    return &world_==&world&&!world_.closed()&&owner_.bound_to(world_.session().random);
}
bool ScriptAudio::ready(std::uint32_t event,std::uint32_t mode,std::uint32_t actor)const noexcept{
    if(mode>2)return true;
    if(!bound_to(world_)||!world_.session().scenario)return false;
    try{(void)gameplay_audio::scenario_cue(*world_.session().scenario,event);}catch(...){return false;}
    if(mode!=1)return true;
    if(actor==4)actor=world_.selected_actor;
    return actor<gameplay_world::World::primary_capacity&&bool(world_.primary(actor));
}
bool ScriptAudio::command(std::uint32_t event,std::uint32_t mode,std::uint32_t actor,
                          std::array<std::int32_t,3> coordinates)noexcept{
    last_.reset();
    if(!ready(event,mode,actor))return false;
    if(mode==0)return play(event);
    if(mode==1){
        if(actor==4)actor=world_.selected_actor;
        const auto target=world_.primary(actor);
        return play(event,gameplay_audio::Vector{target->position.x,target->position.y,target->position.z});
    }
    if(mode==2)return play(event,gameplay_audio::Vector{float(coordinates[0]),float(coordinates[1]),float(coordinates[2])});
    return true;
}
bool ScriptAudio::play(std::uint32_t event,std::optional<gameplay_audio::Vector> position)noexcept{
    last_.reset();
    if(!ready(event,0))return false;
    const auto cue=gameplay_audio::scenario_cue(*world_.session().scenario,event);
    if(cue==255)return true;
    last_=position?owner_.positional({2,cue},*position,spatial_,1):owner_.request({2,cue});
    // The original stores this even when the bank ignores/rejects a command.
    world_.session().last_scenario_audio=std::uint16_t(cue);
    return true;
}
}
