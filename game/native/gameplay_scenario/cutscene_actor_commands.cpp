#include "cutscene_actor_commands.hpp"
#include "../gameplay_world/linked_models.hpp"
#include "../gameplay_world/model_constraints.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
struct CueVariantScale {std::uint16_t id;std::uint32_t bits;};
#include "cutscene_command_scales.inc"
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native cutscene command requires finite values");return value;}
std::int16_t integer_half(float value){
    finite(value);if(value< -2147483648.f||value>=2147483648.f)throw std::out_of_range("Native cutscene command integer profile exceeded");
    return std::bit_cast<std::int16_t>(std::uint16_t(std::uint32_t(std::int32_t(std::trunc(value)))));
}
std::int16_t degree_turn(std::int16_t degree){
    const float product=65536.f*float(degree),turns=product/360.f;
    return integer_half(.5f+turns);
}
gameplay_world::Position scale(const gameplay_world::Actor& actor){
    if(actor.category==0){
        if(actor.character>=cue_player_scales.size())throw std::out_of_range("Native cutscene player scale identity unavailable");
        const auto& row=cue_player_scales[actor.character];return{std::bit_cast<float>(row[0]),std::bit_cast<float>(row[1]),std::bit_cast<float>(row[2])};
    }
    float value;
    if(actor.category==1){
        const auto entry=std::lower_bound(cue_variant_scales.begin(),cue_variant_scales.end(),actor.model_variant,[](const auto& row,auto id){return row.id<id;});
        if(entry==cue_variant_scales.end()||entry->id!=actor.model_variant)throw std::out_of_range("Native cutscene NPC scale identity unavailable");
        value=std::bit_cast<float>(entry->bits);
    }else value=gameplay_world::File1LinkedModelProfiles{}.definition(actor.slot,actor.model_pose_class).scale;
    return{value,value,value};
}
}
CutsceneCommandStatus apply_cutscene_actor_command(gameplay_world::World& world,
    const gameplay_actors::EntityId& id,std::span<const std::byte> event,
    std::span<const gameplay_actors::EntityId> related,const std::uint8_t& scene,CutsceneSpeech* speech){
    if(world.closed())return CutsceneCommandStatus::closed;
    if(!id)return CutsceneCommandStatus::completed;
    const auto actor=world.resolve(id);
    if(!actor||!actor->scripted)return CutsceneCommandStatus::unavailable;
    if(event.size()!=36)return CutsceneCommandStatus::malformed;
    auto& state=*actor->scripted;
    actor->active=true;actor->primary=6;state.cue_phase=2;
    const auto kind=read<std::uint8_t>(event,1);state.request_flags|=1u<<(kind&31);
    switch(kind){
    case 0:
        actor->position={finite(read<float>(event,4)),finite(read<float>(event,8)),finite(read<float>(event,12))};
        for(unsigned i=0;i<3;++i)actor->orientation[i]=degree_turn(read<std::int16_t>(event,16+2*i));
        actor->visible=true;actor->collision.pose_ready=false;break;
    case 1:{
        if(read<std::uint32_t>(event,4)){
            actor->model_correction_skip=1;state.motion_selector=std::bit_cast<std::int8_t>(std::uint8_t(read<std::uint32_t>(event,8)));
            state.motion_blend_duration=float(read<std::int32_t>(event,24));
            if(read<std::uint32_t>(event,20)&&actor->motion_style)
                state.motion_selector=std::bit_cast<std::int8_t>(std::uint8_t(std::uint8_t(state.motion_selector)+100u));
        }else{
            actor->model_correction_skip=0;state.motion_selector=std::bit_cast<std::int8_t>(std::uint8_t(actor->character+(read<std::uint32_t>(event,8)<<3)));
            state.scale_lock=std::bit_cast<std::int8_t>(std::uint8_t(read<std::uint32_t>(event,12)));
            state.request_phase=std::uint8_t(read<std::uint32_t>(event,16));
            state.motion_blend_duration=float(read<std::int32_t>(event,24));
        }
        state.scale_profile=std::uint8_t(read<std::uint32_t>(event,28));
        actor->model_scale=state.scale_profile?scale(*actor):gameplay_world::Position{1,1,1};
        gameplay_world::initialize_model_constraints(world,*actor);state.cue_phase=1;break;
    }
    case 2:{
        state.relation_mode=read<std::int16_t>(event,4);state.relation_options=read<std::uint32_t>(event,8);
        for(unsigned i=0;i<3;++i)state.relation_offset[i]=finite(read<float>(event,12+4*i));
        state.relation_parameter=read<std::uint32_t>(event,24);
        const auto index=read<std::int16_t>(event,6);
        if(index<0||std::size_t(index)>=related.size())return CutsceneCommandStatus::unavailable;
        if(related[index]&&!world.resolve(related[index]))return CutsceneCommandStatus::unavailable;
        state.related_actor=related[index];break;
    }
    case 3:{
        if(!speech||!world.scenario)return CutsceneCommandStatus::unavailable;
        const auto character=actor->category==0?std::bit_cast<std::int8_t>(std::uint8_t(actor->character+1u)):std::int8_t(0);
        const CutsceneSpeechRequest request{id,*world.scenario,read<std::uint16_t>(event,8),scene,read<std::int16_t>(event,6),character};
        const bool queued=speech->queue_voice(request);
        if(world.resolve(id)!=actor||!actor->scripted)return CutsceneCommandStatus::unavailable;
        auto facial=request;facial.scene=scene;
        facial.facial=read<std::uint16_t>(event,8);facial.voice=read<std::int16_t>(event,6);
        const bool animated=speech->animate_face(facial);
        return queued&&animated?CutsceneCommandStatus::completed:CutsceneCommandStatus::unavailable;
    }
    case 4:actor->movement_enabled=std::uint8_t(read<std::uint32_t>(event,20));break;
    case 5:
        for(unsigned i=0;i<3;++i)state.command_angles[i]=read<std::int16_t>(event,4+2*i);
        state.command_angle_copy=state.command_angles[0];break;
    case 6:
        state.forward_step=finite(read<float>(event,4));
        state.movement_angles[0]=integer_half(read<float>(event,12));state.movement_angles[1]=integer_half(read<float>(event,8));
        state.yaw_step=read<std::uint32_t>(event,20);state.movement_remaining=read<std::uint32_t>(event,24);break;
    default:state.cue_phase=0;break;
    }
    return CutsceneCommandStatus::completed;
}
}
