#include "interpreter.hpp"
#include "script_flow.hpp"
#include "flags.hpp"
#include "scene_resources.hpp"
#include "session_counters.hpp"
#include "sequence_control.hpp"
#include "lighting.hpp"
#include "scene_channels.hpp"
#include "scene_controls.hpp"
#include "stream_channels.hpp"
#include "saved_controls.hpp"
#include "action_choices.hpp"
#include "scene_models.hpp"
#include "room_rules.hpp"
#include "actor_requests.hpp"
#include "actor_inventory_commands.hpp"
#include "character_remap.hpp"
#include "room_object_commands.hpp"
#include "periodic_effects.hpp"
#include "surface_effects.hpp"
#include "script_audio.hpp"
#include "script_resource_parameters.hpp"
#include "script_resource_activation.hpp"
#include "scenario_events.hpp"
#include "actor_script_terminal.hpp"
#include "actor_offline_navigation.hpp"
#include "../gameplay_world/actor_resource_operations.hpp"
#include "actor_interaction_commands.hpp"
#include "room_variant_commands.hpp"
#include "scenario_enemy_relocation.hpp"
#include "timed_scene_text.hpp"
#include "difficulty_predicate.hpp"
#include "actor_model_classes.hpp"
#include "../gameplay_world/inventory_ui.hpp"
#include "scene_record_parameters.hpp"
#include "actor_script_commands.hpp"
#include "actor_room_population.hpp"
#include "actor_script_predicates.hpp"
#include "actor_ai_policy.hpp"
#include "offline_navigation_controls.hpp"
#include "scene_record_commands.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>
#include <bit>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
namespace {
#include "opcode_bindings.inc"
#include "offline_bindings.inc"
std::uint32_t word(const std::byte* p)noexcept{
    return std::to_integer<std::uint32_t>(p[0])|(std::to_integer<std::uint32_t>(p[1])<<8)|
        (std::to_integer<std::uint32_t>(p[2])<<16)|(std::to_integer<std::uint32_t>(p[3])<<24);
}
std::size_t payload_minimum(std::uint32_t op)noexcept{
    switch(op) {
    case 0x80:case 0x81:case 0x164:case 0x165:case 0x1a5:case 0x1a7:case 0x1a8:case 0x1a9:return 4;
    case 0x166:return 9;
    case 0x150:case 0x153:case 0x1a0:case 0x1a1:case 0x1a2:case 0x1a6:case 0x1aa:case 0x1ac:return 12;
    case 0x151:return 8;
    case 0x175:return 16;
    case 0x1a4:return 8;
    case 0x172:return 8;
    case 0x169:return 1;
    case 0x132:return 2;
    case 0x6c:return 13;
    case 0x106:return 18;
    case 0x156:return 20;
    case 0x170:case 0x174:return 6;
    case 0xd0:case 0xd1:return 28;
    case 0x73:return 8;
    case 0x88:return 16;
    case 0x89:return 22;
    case 0x8a:case 0x8c:return 8;
    case 0x8b:return 2;
    default:break;
    }
    switch(op){case 0xa8:return 4;case 0x131:return 14;case 0x100:return 4;case 0x109:return 8;case 0xc2:case 0xc3:case 0xea:return 5;case 0xc4:return 9;case 0xc5:case 0xc6:case 0xc7:return 1;case 0xb0:case 0xb1:return 1;case 0xb4:return 8;case 0x62:case 0x135:return 20;case 0x155:return 8;case 0x120:case 0x121:case 0x122:case 0x180:return 4;
    case 0x50:case 0x54:case 0x55:case 0xf2:case 0x104:case 0x105:return 12;case 0x57:return 16;
    case 0x51:case 0x52:case 0x58:case 0x5a:case 0x5f:case 0x72:case 0xb5:case 0xf6:case 0x173:return 8;
    case 0x53:case 0x56:case 0x59:case 0x5b:case 0x5c:case 0x5d:case 0x5e:return 4;
    case 0x61:case 0x70:case 0xa0:case 0xa1:return 4;case 0x20:case 0x23:case 0x24:case 0x65:return 1;case 0x10:case 0x11:case 0x14:return 4;case 0x13:return 6;case 0x15:return 1;case 0x16:return 16;case 0x17:return 8;
    case 3:case 4:case 6:case 0x44:case 0x4c:return 4;case 8:return 5;
    case 0x63:return 4;
    case 0x64:return 1;
    case 0xee:return 5;
    case 0xe3:case 0xe6:case 0xe8:case 0xe9:case 0xec:case 0xed:case 0xef:case 0xf4:case 0xf5:return 8;
    case 0x40:case 0x41:case 0x42:case 0x43:case 0x47:case 0x48:case 0x49:case 0x4d:case 0x110:case 0x111:case 0x112:return 8;
    case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x86:return 2;case 0x37:return 5;case 0x3d:return 6;case 0x36:case 0x38:case 0x39:case 0x3a:case 0x85:return 10;case 0x87:return 6;
    case 5:case 0xb:case 0x68:case 0x69:return 9;case 0xc:case 0x46:case 0x113:case 0xb7:case 0xb8:return 12;case 0x45:return 16;default:return 0;}
}
std::optional<ControlCommand> control_command(std::uint32_t op)noexcept{
    switch(op){case 0x50:return ControlCommand::zero_two_parameter;case 0x51:return ControlCommand::type_one_parameter;
    case 0x52:return ControlCommand::enable_even;case 0x53:return ControlCommand::disable_even;case 0x54:return ControlCommand::zero_word_byte;
    case 0x55:return ControlCommand::restart_five;case 0x56:return ControlCommand::reset_five;case 0x57:return ControlCommand::restart_five_byte;
    case 0x58:return ControlCommand::enable_odd;case 0x59:return ControlCommand::disable_odd;case 0x5b:return ControlCommand::enable_one;
    case 0x5c:return ControlCommand::disable_one;case 0x5d:return ControlCommand::enable_zero_two;case 0x5e:return ControlCommand::disable_zero_two;
    case 0x5f:return ControlCommand::zero_two_half;case 0x72:return ControlCommand::enable_nine;
    case 0xb5:return ControlCommand::refresh_zero_two;case 0xf6:return ControlCommand::enable_thirteen;default:return{};}
}
bool opener(std::uint32_t op)noexcept{
    constexpr std::array<std::uint32_t,32> values{0xe6,8,0xe3,0x34,0xe9,0xea,0xec,0xed,0x14,0x113,0x150,0x151,0x152,0x153,0x155,0x156,0xc2,0xc3,0xee,0x36,0x47,0x48,0x49,0x4d,0xb7,0xb8,0x158,0x180,0x159,0x17,0x1aa,0x1ac};
    return std::find(values.begin(),values.end(),op)!=values.end();
}
}
detail::ScriptFlowBinding detail::script_flow_binding(std::uint32_t opcode,DispatchProfile profile)noexcept {
    ScriptFlowBinding binding;
    binding.opens_condition=opener(opcode);
    const bool offline=profile==DispatchProfile::offline_actor;
    if(offline){
        const auto& entry=offline_bindings[opcode];
        binding.context_dependent=entry.restricted||entry.relation_one||entry.relation_two;
        if(entry.noop)return binding;
    }else if(original_noops[opcode])return binding;
    binding.minimum_payload=payload_minimum(opcode);
    switch(opcode){
    case 1:binding.flow=ScriptFlow::remember;break;
    case 2:binding.flow=ScriptFlow::resume;break;
    case 0xa:binding.flow=ScriptFlow::resume_yield;break;
    case 7:binding.flow=ScriptFlow::next_block;break;
    case 0xd:binding.flow=ScriptFlow::next_block_yield;break;
    case 3:binding.flow=ScriptFlow::skip;break;
    case 4:binding.flow=ScriptFlow::delay;break;
    case 8:case 0x14:case 0x17:case 0x34:case 0x47:case 0x48:case 0x49:case 0x4d:
    case 0xb7:case 0xb8:case 0xc2:case 0xc3:case 0xe3:case 0xe6:case 0xe9:case 0xea:
    case 0xec:case 0xed:case 0xee:case 0xef:case 0x113:case 0x150:case 0x151:case 0x153:case 0x155:case 0x156:case 0x180:case 0x1ac:
        binding.flow=ScriptFlow::if_test;break;
    case 0x36:case 0x1aa:binding.flow=ScriptFlow::if_test_without_open;break;
    case 0xe4:binding.flow=ScriptFlow::else_scan;break;
    case 0xe5:binding.flow=ScriptFlow::end_if;break;
    default:break;
    }
    return binding;
}
std::uint32_t Program::record_bytes(std::uint32_t header)noexcept{return (std::uint32_t(1)<<((header>>24)&31))*4u;}
Program::Program(std::vector<std::vector<std::byte>> blocks,DispatchProfile profile)
    :Program(std::move(blocks),profile,false){}
Program Program::from_script_blocks(std::vector<std::vector<std::byte>> blocks,DispatchProfile profile){
    return Program(std::move(blocks),profile,true);
}
Program::Program(std::vector<std::vector<std::byte>> blocks,DispatchProfile profile,bool allow_missing_blocks)
    :blocks_(std::move(blocks)),profile_(profile){
    if(blocks_.empty()||blocks_.size()>UINT32_MAX)throw std::invalid_argument("Bounded native script blocks required");
    boundaries_.resize(blocks_.size());const auto coverage=Interpreter::coverage(profile);
    for(std::size_t i=0;i<blocks_.size();++i){
        const auto& b=blocks_[i];
        if(b.empty()&&allow_missing_blocks)continue;
        if(b.empty()||b.size()>UINT32_MAX)throw std::invalid_argument("Native script block extent");
        std::size_t at=0;
        while(at<b.size()){
            if(b.size()-at<4)throw std::invalid_argument("Truncated script header");
            const auto h=word(b.data()+at),bytes=record_bytes(h),op=h&0xffffff;
            const bool noop=op<432&&(profile==DispatchProfile::ordinary?original_noops[op]:offline_bindings[op].noop);
            if(!bytes||bytes>b.size()-at||op>=432||(!noop&&bytes-4<payload_minimum(op)))throw std::invalid_argument("Invalid script record");
            boundaries_[i].push_back(static_cast<std::uint32_t>(at));unsupported_|=!coverage[op].native_algorithm;
            if(!noop&&(op==5||op==6)){if(word(b.data()+at+4)>=4)throw std::invalid_argument("Actor event slot extent");actor_events_=true;}
            if(!noop&&(op==0xe8||op==0xe9)&&word(b.data()+at+4)>=2)throw std::invalid_argument("Native session counter profile");
            if(!noop&&(op==0x164||op==0x165)&&word(b.data()+at+4)>=SceneRecordEligibility::capacity)
                throw std::invalid_argument("Native scene-record eligibility profile");
            if(!noop&&op==0x73){
                const auto mode=word(b.data()+at+8);
                if((mode==1&&bytes-4<12)||(mode==2&&bytes-4<20))
                    throw std::invalid_argument("Truncated native script sound position");
                if(mode<=2){script_audio_=true;world_=true;
                    audio_requests_.push_back({word(b.data()+at+4),mode,mode==1?word(b.data()+at+12):0});}
            }
            if(!noop&&op==0x150){
                const auto selector=word(b.data()+at+4);
                if(selector>=gameplay_world::World::primary_capacity)throw std::invalid_argument("Native actor room selector");
                room_actor_selectors_.push_back(selector);
            }
            if(!noop&&op==0x1a1){
                const auto mode=word(b.data()+at+4),selector=word(b.data()+at+8);
                if(!mode&&selector>=gameplay_world::World::primary_capacity)throw std::invalid_argument("Native actor AI profile selector");
                actor_profile_requests_.push_back({mode,selector,std::bit_cast<std::int32_t>(word(b.data()+at+12))});
            }
            actor_population_rooms_|=!noop&&op==0x151;
            if(!noop&&op==0x153)actor_room_population_queries_.push_back(word(b.data()+at+4));
            if(!noop&&op==0x156){
                const auto mode=word(b.data()+at+4),selector=word(b.data()+at+8),query=word(b.data()+at+12),parameter=word(b.data()+at+16);
                if(!mode&&selector>=gameplay_world::World::primary_capacity)throw std::invalid_argument("Native actor condition selector");
                if(query==5){
                    if(parameter>=512)throw std::invalid_argument("Native actor scenario owner extent");
                    flags_=canonical_flags_=true;
                }
                actor_condition_requests_.push_back({mode,selector,query,parameter});
            }
            actor_ai_counter_|=!noop&&op==0x1a5;
            actor_script_terminal_|=!noop&&op==0x60;
            if(!noop&&op==0x132)timed_text_requests_.push_back(std::uint16_t(word(b.data()+at+4)));
            if(!noop&&op==0x169)enemy_relocation_requests_.push_back(std::to_integer<std::uint8_t>(b[at+4]));
            if(!noop&&op==0x5a&&profile==DispatchProfile::offline_actor){
                if(word(b.data()+at+4)>=gameplay_session::RoomVariants::capacity)throw std::invalid_argument("Native offline room variant profile");
                offline_room_variants_=true;
            }
            if(!noop&&op==0x172){
                if(word(b.data()+at+8)>=512)throw std::invalid_argument("Native inventory flag extent");
                inventory_flags_=true;
            }
            if(!noop&&op==0x106){
                const auto selector=word(b.data()+at+4);
                if(selector>=gameplay_world::World::primary_capacity)throw std::invalid_argument("Native actor anchor selector");
                script_anchor_selectors_.push_back(selector);
            }
            actor_ai_damage_policy_|=!noop&&op==0x1a8;
            if(!noop&&(op==0x1a6||op==0x1a7||op==0x1a9||op==0x1aa)){
                const auto selector=word(b.data()+at+4);
                if(selector>=gameplay_world::World::primary_capacity)throw std::invalid_argument("Native offline actor physical selector");
                if(op==0x1a9)actor_retire_selectors_.push_back(selector);
                else if(op!=0x1aa)actor_forced_policy_selectors_.push_back(selector);
            }
            if(!noop&&op==0x1ac&&word(b.data()+at+4)<3){
                if(word(b.data()+at+8)>=512)throw std::invalid_argument("Native offline actor flag extent");
                flags_=canonical_flags_=true;
            }
            if(!noop&&op==0x175)offline_inventory_requests_.push_back({std::bit_cast<std::int16_t>(std::uint16_t(word(b.data()+at+4))),std::bit_cast<std::int16_t>(std::uint16_t(word(b.data()+at+8)))});
            if(!noop&&op==0x1a2)offline_navigation_requests_.push_back({word(b.data()+at+4),word(b.data()+at+8),word(b.data()+at+12)});
            if(!noop&&op==0x1a0)destination_policy_requests_.push_back({word(b.data()+at+4),word(b.data()+at+8),word(b.data()+at+12)});
            if(!noop&&op==0x1a4){
                const auto selector=word(b.data()+at+4);
                if(selector>=gameplay_world::World::primary_capacity)throw std::invalid_argument("Native actor AI inhibition selector");
                actor_inhibition_requests_.push_back({selector,word(b.data()+at+8)});
            }
            if(!noop&&op==0x170)resource_parameter_requests_.push_back({std::uint16_t(word(b.data()+at+4)),std::bit_cast<std::int16_t>(std::uint16_t(word(b.data()+at+8)))});
            if(!noop&&op==0x174&&std::bit_cast<std::int16_t>(std::uint16_t(word(b.data()+at+4)))>0){resource_activation_=true;world_=true;}
            if(!noop&&op==0xd1){
                std::array<std::uint32_t,5> args;for(unsigned i=0;i<args.size();++i)args[i]=word(b.data()+at+12+4*i);
                if(!ScenarioEvents::admits(word(b.data()+at+4),word(b.data()+at+8),args))throw std::invalid_argument("Native scenario event callback/payload profile");
                scenario_events_=true;world_=true;
            }
            if(!noop&&op==0xd0){
                std::array<std::uint32_t,5> args;for(unsigned i=0;i<args.size();++i)args[i]=word(b.data()+at+12+4*i);
                const auto kind=word(b.data()+at+4),slot=word(b.data()+at+8);
                if(!ScenarioEvents::admits_scenario(kind,slot,args))throw std::invalid_argument("Native scenario-specific event callback/payload profile");
                scenario_event_requests_.push_back({kind,slot,args});scenario_events_=true;world_=true;
            }
            if(!noop&&op==0xee&&std::to_integer<std::uint8_t>(b[at+8])<6){difficulty_=true;world_=true;}
            inventory_ui_|=!noop&&op==0x108;
            actor_model_classes_|=!noop&&op==0x64;
            if(!noop&&op==0x63)inventory_requests_.push_back(word(b.data()+at+4));
            low_actor_population_|=!noop&&(op==0x38||op==0x39);
            full_actor_population_|=!noop&&op==0x173;
            npc_inventory_grants_|=!noop&&op==0x3a;
            if (!noop && (op==0x80 || op==0x81 || op==0x88 || op==0x89 ||
                          op==0x8a || op==0x8b || op==0x8c)) {
                const bool full=op==0x80 || op==0x81 || op==0x88;
                const auto id=full ? word(b.data()+at+4) :
                    std::to_integer<std::uint32_t>(b[at+4]) | std::to_integer<std::uint32_t>(b[at+5])<<8;
                if (id>=210) throw std::invalid_argument("Native NPC alias index profile");
            }
            actor_roster_|=!noop&&op==0xea;
            character_remap_|=!noop&&op==0x84;
            forced_terminal_|=!noop&&op==0x61;
            if(!noop&&(op==0x85||op==0x87)&&word(b.data()+at+4)>=RoomActorAssets::room_count)
                throw std::invalid_argument("Native room actor asset row profile");
            if(!noop&&(op==0x120||op==0x121)){
                const auto index=std::bit_cast<std::int32_t>(word(b.data()+at+4));
                if(index < -31 || index >= std::int32_t(AuxiliaryScene::timer_count))
                    throw std::invalid_argument("Native auxiliary timer index profile");
            }
            if(!noop&&op==0xf2){
                using gameplay_collision::delivery::RoomCounters;
                if(word(b.data()+at+4)>=RoomCounters::rooms||word(b.data()+at+8)>=RoomCounters::edges)
                    throw std::invalid_argument("Native room counter destination");
                room_counters_=true;
                scenario_counter_policy_|=std::bit_cast<std::int32_t>(word(b.data()+at+12))>=100;
            }
            if(!noop&&(op==0x10||op==0x11)&&word(b.data()+at+4)>=32)throw std::invalid_argument("Native sequence index profile");
            if(!noop&&(op==0x13||op==0x15)&&std::to_integer<unsigned>(b[at+4])>=32)throw std::invalid_argument("Native sequence selector profile");
            if(!noop&&(op==0x23||op==0x24)&&std::to_integer<unsigned>(b[at+4])>=32)throw std::invalid_argument("Native lighting entry profile");
            if(!noop&&(op==0x69||op==0x6c)){
                using gameplay_world::ActorPlacements;
                const auto actor=std::to_integer<unsigned>(b[at+4]);
                const auto command=std::to_integer<unsigned>(b[at+8]);
                const bool immediate=command==0xf0||command==0xf1;
                if(actor>=gameplay_world::World::primary_capacity||
                    (!immediate&&actor!=4&&actor>=ActorPlacements::request_count)||
                    (command==0xf0&&std::to_integer<unsigned>(b[at+12])>=ActorPlacements::position_capacity))
                    throw std::invalid_argument("Native actor placement profile");
                if(op==0x6c)control_placement_requests_.push_back({std::uint8_t(actor),std::uint8_t(command),std::to_integer<std::uint8_t>(b[at+12])});
            }
            if(!noop&&op==0x70&&std::bit_cast<std::int32_t>(word(b.data()+at+4))<0)throw std::invalid_argument("Native stream member profile");
            if(!noop&&op==0xb4){if(word(b.data()+at+8)>=8)throw std::invalid_argument("Native model transform preset profile");adjusted_models_.push_back(std::to_integer<std::uint8_t>(b[at+4]));}
            if(!noop&&(op==0xb0||op==0xb1))visibility_models_.push_back(std::to_integer<std::uint8_t>(b[at+4]));
            if(!noop&&(op==0xc2||op==0xc3)&&std::to_integer<unsigned>(b[at+4])>=8)throw std::invalid_argument("Native cached room-object index profile");
            room_objects_|=coverage[op].room_objects_required;room_object_lifetime_|=coverage[op].room_object_lifetime_required;room_object_queries_|=coverage[op].room_object_queries_required;
            if(!noop&&(op==0x100||op==0x109)&&!actor_request_kind_supported(std::to_integer<std::uint8_t>(b[at+4])))throw std::invalid_argument("Native actor request callback profile");
            if(!noop&&op==0x131){const auto stop=std::uint16_t(word(b.data()+at+12));if(!(stop&0x8000)&&stop>=128)throw std::invalid_argument("Native periodic byte-flag profile");}
            periodic_effects_|=coverage[op].periodic_effects_required;
            const bool surface_command=!noop&&op==0xa8&&word(b.data()+at+4)==1;
            if(surface_command&&bytes-4<20)throw std::invalid_argument("Truncated native surface command");
            surface_effects_|=surface_command;
            flags_|=coverage[op].flags_required;timers_|=coverage[op].timers_required;signals_|=coverage[op].signals_required;
            scene_record_parameters_|=coverage[op].scene_record_parameters_required;
            scene_resources_|=coverage[op].scene_resources_required;session_counters_|=coverage[op].session_counters_required;
            sequences_|=coverage[op].sequences_required;lighting_|=coverage[op].lighting_required;scene_channels_|=coverage[op].scene_channels_required;
            scene_controls_|=coverage[op].scene_controls_required;streams_|=coverage[op].streams_required;saved_controls_|=coverage[op].saved_controls_required;
            world_|=coverage[op].world_required&&(op!=0xa8||surface_command);selected_actor_|=coverage[op].selected_actor_required;action_choices_|=coverage[op].action_choices_required;models_|=coverage[op].models_required;
            scenario_|=coverage[op].scenario_required;canonical_flags_|=coverage[op].canonical_flags_required;at+=bytes;
        }
    }
}
bool Program::admits_script_audio(const ScriptAudio* audio,const gameplay_world::World* world)const noexcept{
    if(!script_audio_)return true;
    if(!audio||!world||!audio->bound_to(*world))return false;
    for(const auto& request:audio_requests_)if(!audio->ready(request.event,request.mode,request.actor))return false;
    return true;
}
bool Program::admits_actor_interaction_commands(const gameplay_world::World* world,const SceneResources* resources)const noexcept{
    if(control_placement_requests_.empty()&&script_anchor_selectors_.empty()&&!inventory_flags_)return true;
    if(!world)return false;
    for(const auto& request:control_placement_requests_)
        if(!script_anchor_actor(*world,request.selector))return false;
    for(const auto selector:script_anchor_selectors_)if(!script_anchor_actor(*world,selector))return false;
    return !inventory_flags_||inventory_flag_ready(*world,resources);
}
bool Program::admits_offline_room_variants(const gameplay_world::World* world)const noexcept{
    return !offline_room_variants_||(world&&offline_room_variant_ready(*world));
}
bool Program::admits_scenario_enemy_relocation(const gameplay_world::World* world,const FlagState* flags)const noexcept{
    if(enemy_relocation_requests_.empty())return true;
    if(!world)return false;
    for(const auto condition:enemy_relocation_requests_)if(!scenario_enemy_relocation_plan(*world,flags,condition).ready)return false;
    return true;
}
bool Program::admits_timed_scene_text(const TimedSceneText* text,const gameplay_world::World* world)const noexcept{
    if(timed_text_requests_.empty())return true;
    if(!text||!world||!text->bound_to(*world))return false;
    for(const auto id:timed_text_requests_)if(!text->ready(id))return false;
    return true;
}
bool Program::admits_scene_record_parameters(const gameplay_world::World* world,const gameplay_update::GameplayMessageSink* messages)const noexcept{
    return !scene_record_parameters_||(world&&scene_record_parameters_ready(*world,messages));
}
bool Program::admits_actor_script_commands(const gameplay_world::World* world,const FlagState* flags)const noexcept{
    if(room_actor_selectors_.empty()&&actor_profile_requests_.empty()&&actor_condition_requests_.empty()&&!actor_ai_counter_&&!actor_ai_damage_policy_&&actor_inhibition_requests_.empty()&&actor_forced_policy_selectors_.empty()&&destination_policy_requests_.empty()&&!actor_population_rooms_&&actor_room_population_queries_.empty())return true;
    if(!world||world->closed())return false;
    for(const auto selector:room_actor_selectors_)if(!actor_room_query_ready(*world,selector))return false;
    if(actor_population_rooms_&&!actor_population_rooms_ready(*world))return false;
    for(const auto room:actor_room_population_queries_)if(!actor_room_population_ready(*world,room))return false;
    for(const auto& request:actor_profile_requests_)
        if(!actor_weight_profile_ready(*world,request.mode,request.selector,request.profile))return false;
    for(const auto& request:actor_condition_requests_)
        if(!actor_condition_matches(*world,flags,request.mode,request.selector,request.query,request.parameter,0))return false;
    if(actor_ai_counter_&&!actor_ai_counter_ready(*world))return false;
    if(actor_ai_damage_policy_&&!actor_ai_damage_policy_ready(*world))return false;
    for(const auto& request:actor_inhibition_requests_)
        if(!actor_ai_inhibition_ready(*world,request.selector,request.value))return false;
    for(const auto selector:actor_forced_policy_selectors_)
        if(!actor_forced_policy_ready(*world,selector))return false;
    //1D3F60 publishes SGL only after68C890 has run EVB entry1. The complete
    // static closure also includes later blocks, so their1A0 descriptors cannot
    // be required before that producer. The reached1A0 handler retains the
    // exact signed gate and descriptor/AI readiness before its first mutation.
    return true;
}
bool Program::admits_resource_parameter_commands(const gameplay_world::World* world,const ScriptResourceParameters* parameters,
    const SceneResources* resources,const ResourceTemplates* templates)const noexcept{
    if(resource_parameter_requests_.empty())return true;
    if(!world)return false;
    for(const auto& request:resource_parameter_requests_){
        if(script_resource_parameter_noop(*world,request.resource))continue;
        if(!parameters||!parameters->bound_to(*world,resources,templates)||!parameters->ready(request.resource,request.quantity))return false;
    }
    return true;
}
bool Program::admits_resource_activation(const ScriptResourceActivation* activation,const gameplay_world::World* world,
    const SceneResources* resources,const ResourceTemplates* templates)const noexcept{
    return !resource_activation_||(activation&&world&&activation->bound_to(*world,resources,templates));
}
bool Program::admits_scenario_events(const ScenarioEvents* events,const gameplay_world::World* world)const noexcept{
    if(!scenario_events_)return true;
    if(!events||!world||!events->bound_to(*world)||!events->ready())return false;
    for(const auto& request:scenario_event_requests_)
        if(!events->scenario_ready(request.kind,request.slot,request.arguments))return false;
    return true;
}
bool Program::admits_actor_script_terminal(const ActorScriptTerminal* terminal,const gameplay_world::World* world)const noexcept{
    if(!actor_script_terminal_&&actor_retire_selectors_.empty())return true;
    if(!terminal||!world||!terminal->bound_to(*world))return false;
    if(actor_script_terminal_&&!terminal->command_ready())return false;
    for(const auto selector:actor_retire_selectors_)if(!terminal->retire_offline_actor_ready(selector))return false;
    return true;
}
bool Program::admits_offline_actor_inventory(const gameplay_world::ActorResourceOperations* operations,const gameplay_world::World* world,const SceneResources* resources,const ResourceTemplates* templates)const noexcept{
    for(const auto& request:offline_inventory_requests_){
        if(!world)return false;
        const auto required=gameplay_world::offline_actor_resource_required(*world,request[0],request[1]);if(!required)return false;
        if(*required&&(!operations||!resources||!templates||!operations->bound_to(*world,*resources,*templates)))return false;
    }
    return true;
}
bool Program::admits_actor_offline_navigation(const ActorOfflineNavigation* owner,const gameplay_world::World* world,const Interpreter* scripts)const noexcept{
    if(offline_navigation_requests_.empty())return true;
    // Keep the concrete owner identity required for the complete closure.
    // Graph/node readiness belongs to the reached1A2 command, after the actual
    // SGL producer; checking future blocks here would prevent entry1 itself.
    return owner&&world&&!world->closed()&&scripts&&owner->bound_to(*world,*scripts);
}
bool Program::admits_difficulty(const gameplay_world::World* world)const noexcept{
    return !difficulty_||(world&&!world->closed()&&world->session().difficulty.has_value());
}
bool Program::admits_inventory_ui(const gameplay_world::InventoryUi* ui,const gameplay_world::World* world)const noexcept{
    if(!needs_inventory_ui())return true;
    if(!ui||!world||!ui->bound_to(*world)||(inventory_ui_&&!ui->close_ready()))return false;
    for(auto request:inventory_requests_)if(!ui->request_mode_ready(request))return false;
    return true;
}
bool Program::admits_actor_model_classes(const gameplay_world::World* world)const noexcept{
    return !actor_model_classes_||(world&&actor_model_classes_ready(*world));
}
bool Program::admits_room_counters(const gameplay_world::World* world)const noexcept {
    return !room_counters_ || (world && !world->closed() &&
        world->session().room_contacts.counters_ready(scenario_counter_policy_));
}
bool Program::admits_character_remap(const gameplay_world::World* world)const noexcept {
    return !character_remap_ || (world && character_remap_ready(*world));
}
bool Program::admits_inventory_grants(const gameplay_world::World* world,const SceneResources* resources,
                                     const ResourceTemplates* templates)const noexcept{
    return (!low_actor_population_&&!full_actor_population_&&!npc_inventory_grants_)||
        (world&&resources&&templates&&(!low_actor_population_||actor_inventory_population_ready(*world))&&
         (!full_actor_population_||actor_inventory_population_ready(*world,true)));
}
bool Program::admits_actor_roster(const gameplay_world::World* world)const noexcept {
    return !actor_roster_ || (world && world->actor_roster_ready());
}
std::optional<Record> Program::record(Position p)const noexcept{
    if(p.block>=blocks_.size())return{};
    const auto& indices=boundaries_[p.block];if(!std::binary_search(indices.begin(),indices.end(),p.offset))return{};
    const auto& b=blocks_[p.block];const auto h=word(b.data()+p.offset),bytes=record_bytes(h);
    return Record{h&0xffffff,bytes,{b.data()+p.offset+4,bytes-4}};
}
std::array<OpcodeCoverage,432> Interpreter::coverage(DispatchProfile profile)noexcept{
    std::array<OpcodeCoverage,432> out{};
    for(std::size_t i=0;i<out.size();++i)out[i].native_algorithm=original_noops[i];
    for(const auto i:{1,2,3,4,5,6,7,0xa,0xd,0xe4,0xe5,0x110,0x111,0x112,0x113,0x114})out[i].native_algorithm=true;
    for(const auto i:{8,0xb,0xc,0x40,0x41,0x42,0x43,0x44,0x49,0x4c,0x4d,0xe3,0xe6,0xec,0xed,0xef,0xb7,0xb8,0xf4,0xf5})out[i]={true,true,false,false};
    out[0x164]={true,true,false,false};
    out[0x165].native_algorithm=true;out[0x165].flags_required=true;
    out[0x165].canonical_flags_required=true;out[0x165].world_required=true;
    out[0x73].native_algorithm=true;out[0x73].script_audio_required=true;
    out[0x166].native_algorithm=true;out[0x166].world_required=true;out[0x166].scene_record_parameters_required=true;
    for(const auto i:{0x46,0x47,0x48})out[i]={true,false,false,true};
    out[0x45]={true,false,true,false};
    for(std::size_t i=0x30;i<=0x37;++i)out[i]={true,false,false,false,true};
    for(const auto i:{0x38,0x39,0x173}){
        out[i].native_algorithm=true;
        out[i].scene_resources_required=true;
        out[i].world_required=true;
    }
    for (const auto i:{0x3a,0x3d}) {
        out[i].native_algorithm=true;
        out[i].scene_resources_required=true;
        out[i].world_required=true;
    }
    for (const auto i:{0x80,0x81,0x84,0x88,0x89,0x8a,0x8b,0x8c}) {
        out[i].native_algorithm=true;
        out[i].world_required=true;
    }
    for(const auto i:{0xe8,0xe9})out[i]={true,false,false,false,false,true};
    for(std::size_t i=0x10;i<=0x17;++i)out[i]={true,false,false,false,false,false,true};
    for(const auto i:{0x20,0x23,0x24,0x25})out[i]={true,false,false,false,false,false,false,true};
    for(std::size_t i=0xa0;i<=0xa3;++i)out[i]={true,false,false,false,false,false,false,false,true};
    out[0x190].native_algorithm=true;
    out[0x174].native_algorithm=true;
    for(std::size_t i=0;i<out.size();++i)if(control_command(std::uint32_t(i)))out[i]={true,false,false,false,false,false,false,false,false,true};
    for(const auto i:{0x70,0x71})out[i]={true,false,false,false,false,false,false,false,false,false,true};
    for(const auto i:{0x104,0x105})out[i]={true,false,false,false,false,false,false,false,false,true};
    for(const auto i:{0x5a,0x61,0x62,0x65,0x68,0x69,0x6a,0x85,0x86,0x87,0xea,0xf2,0x120,0x121,0x122,0x135,0x150,0x151,0x153,0x155,0x156,0x170,0x180}){out[i].native_algorithm=true;out[i].world_required=true;}
    out[0x62].selected_actor_required=true;
    out[0x135].scene_controls_required=true;out[0x135].action_choices_required=true;
    out[0x135].selected_actor_required=true;out[0x155].selected_actor_required=true;
    for(const auto i:{0xb0,0xb1,0xb4}){out[i].native_algorithm=true;out[i].models_required=true;}
    for(const auto i:{0xc2,0xc3,0xc4,0xc5,0xc6,0xc7}){out[i].native_algorithm=true;out[i].room_objects_required=true;}
    out[0xc4].room_object_lifetime_required=true;out[0xc2].room_object_queries_required=true;out[0xc3].room_object_queries_required=true;
    for(const auto i:{0x100,0x109}){out[i].native_algorithm=true;out[i].world_required=true;out[i].selected_actor_required=true;}
    out[0x131].native_algorithm=true;out[0x131].scene_controls_required=true;out[0x131].world_required=true;out[0x131].canonical_flags_required=true;out[0x131].periodic_effects_required=true;
    out[0xa8].native_algorithm=true;out[0xa8].world_required=true;out[0xa8].surface_effects_required=true;
    out[0x191].native_algorithm=true;out[0x191].world_required=true;out[0x191].scenario_required=true;out[0x191].canonical_flags_required=true;out[0x191].scene_controls_required=true;
    out[0xd1].native_algorithm=true;out[0xd1].world_required=true;
    out[0xd0].native_algorithm=true;out[0xd0].world_required=true;out[0xd0].scenario_required=true;
    out[0x60].native_algorithm=true;out[0x60].world_required=true;
    for(const auto i:{0x6c,0x106,0x172}){out[i].native_algorithm=true;out[i].world_required=true;}
    out[0x172].canonical_flags_required=true;
    out[0x169].native_algorithm=true;out[0x169].world_required=true;
    out[0x132].native_algorithm=true;out[0x132].world_required=true;
    out[0xee].native_algorithm=true; // Valid comparisons require canonical difficulty, selected per Program.
    out[0x108].native_algorithm=true;out[0x108].world_required=true;
    out[0x64].native_algorithm=true;out[0x64].world_required=true;
    out[0x63].native_algorithm=true;out[0x63].world_required=true;
    if(profile==DispatchProfile::offline_actor)for(std::size_t i=0;i<out.size();++i){
        if(offline_bindings[i].noop)out[i]={true,false,false,false};
        else if(!offline_bindings[i].same_handler&&i!=0xb&&i!=0xc&&i!=0xe3&&i!=0xed&&i!=0xef&&i!=0x104&&i!=0x105)out[i]={};
        if(i==0x104||i==0x105)out[i].saved_controls_required=true;
    }
    if(profile==DispatchProfile::offline_actor)for(const auto i:{0x5a,0x1a0,0x1a1,0x1a2,0x1a4,0x1a5,0x1a6,0x1a7,0x1a8,0x1a9,0x1aa}){out[i].native_algorithm=true;out[i].world_required=true;}
    if(profile==DispatchProfile::offline_actor){out[0x1ac].native_algorithm=true;out[0x175].native_algorithm=true;out[0x175].world_required=true;}
    //7012C0/701550 dependencies are reached-path capabilities: category>=2
    // dispatch skips; the canonical disabled pool exits before SGL reads.
    if(profile==DispatchProfile::offline_actor)for(const auto i:{0x53,0x58}){out[i]={};out[i].native_algorithm=true;}
    return out;
}
Status Interpreter::install(std::size_t id,std::shared_ptr<const Program> p,Position entry)noexcept{
    const ChannelReplacement replacement{id,std::move(p),entry};
    return replace_channels(std::span(&replacement,1));
}
Status Interpreter::replace_channels(std::span<const ChannelReplacement> replacements)noexcept{
    if(running_)return Status::busy;
    std::array<bool,channel_count> seen{};
    for(const auto& change:replacements){
        if(change.channel>=channel_count||seen[change.channel])return Status::invalid_channel;
        seen[change.channel]=true;
        if(bool(change.program)!=bool(change.entry))return Status::invalid_program;
        if(change.entry&&!change.program->record(*change.entry))return Status::invalid_program;
        if(change.program&&change.program->unsupported())return Status::unsupported_opcode;
    }
    for(const auto& change:replacements){
        auto& channel=channels_[change.channel];
        if(!change.entry){channel={};continue;}
        channel=Channel{change.program,*change.entry,{},0,change.entry->block,0};
    }
    return Status::completed;
}
Status Interpreter::restore_channel(std::size_t id,const Channel& value)noexcept{
    if(running_)return Status::busy;
    if(id>=channel_count)return Status::invalid_channel;
    const auto current=value.cursor_program?value.cursor_program:value.program;
    const auto saved=value.saved_program?value.saved_program:value.program;
    if((current&&current->unsupported())||(saved&&saved->unsupported())||(value.program&&value.program->unsupported()))return Status::unsupported_opcode;
    if(current){if(!current->record(value.current))return Status::invalid_program;}
    else if(value.current!=Position{}||value.countdown)return Status::invalid_program;
    if(value.program&&value.block_index>=value.program->blocks())return Status::invalid_program;
    if(value.saved!=Position{}&&(!saved||!saved->record(value.saved)))return Status::invalid_program;
    if(value.program&&((current&&current->profile()!=value.program->profile())||(saved&&saved->profile()!=value.program->profile())))return Status::invalid_program;
    channels_[id]=value;return Status::completed;
}
Status Interpreter::restore_counters(const std::array<std::uint32_t,4>& values)noexcept{
    if(running_)return Status::busy;
    counters_=values;return Status::completed;
}
TickResult Interpreter::tick(std::size_t id,const TickContext& context,Providers providers,std::size_t budget)noexcept{
    if(context.alternate_mode)return{Status::alternate_mode_unavailable,0,{},0};
    return execute(id,context,providers,budget,nullptr);
}
TickResult Interpreter::tick_offline_channel(std::size_t id,const TickContext& context,OfflineDispatch dispatch,Providers providers,std::size_t budget)noexcept{
    return execute(id,context,providers,budget,&dispatch);
}
TickResult Interpreter::execute(std::size_t id,const TickContext& context,Providers providers,std::size_t budget,const OfflineDispatch* offline)noexcept{
    if(running_)return{Status::busy,0,{},0};
    if(id>=channel_count)return{Status::invalid_channel,0,{},0};
    auto& c=channels_[id];
    const auto initial_program=c.cursor_program?c.cursor_program:c.program;
    if(!initial_program)return{Status::invalid_program,0,{},0};
    const auto provider_status=[&](const Program& program)->Status{
    if(program.profile()!=(offline?DispatchProfile::offline_actor:DispatchProfile::ordinary))return Status::invalid_program;
    if(offline&&offline->actor_category>4)return Status::invalid_program;
    if(offline&&(!providers.canonical_flags||providers.flags!=providers.canonical_flags))return Status::provider_unavailable;
    if(program.needs_actor_events()&&context.selected_actor>=4)return Status::invalid_program;
    if((program.needs_flags()&&!providers.flags)||(program.needs_timers()&&!providers.timers))return Status::provider_unavailable;
    if(program.needs_signals()&&!providers.signals)return Status::provider_unavailable;
    if(program.needs_forced_terminal()&&!providers.forced_terminal)return Status::provider_unavailable;
    if(program.needs_scene_resources()&&!providers.scene_resources)return Status::provider_unavailable;
    if(program.needs_session_counters()&&!providers.session_counters)return Status::provider_unavailable;
    if(offline&&program.needs_session_counters()&&context.selected_actor>=3)return Status::invalid_program;
    if(program.needs_sequences()&&!providers.sequences)return Status::provider_unavailable;
    if(program.needs_lighting()&&!providers.lighting)return Status::provider_unavailable;
    if(program.needs_scene_channels()&&!providers.scene_channels)return Status::provider_unavailable;
    if(program.needs_scene_controls()&&!providers.scene_controls)return Status::provider_unavailable;
    if(program.needs_streams()&&(!providers.streams||!providers.stream_backend||!context.stream_tick))return Status::provider_unavailable;
    if(program.needs_saved_controls()&&(!providers.saved_controls||context.selected_actor>=SavedControlRecords::owner_count))return Status::provider_unavailable;
    if(program.needs_world()&&(!providers.world||providers.world->closed()||providers.world->selected_actor!=context.selected_actor))return Status::provider_unavailable;
    if(!program.admits_room_counters(providers.world))return Status::provider_unavailable;
    if(!program.admits_inventory_grants(providers.world,providers.scene_resources,providers.resource_templates))return Status::provider_unavailable;
    if(!program.admits_actor_roster(providers.world))return Status::provider_unavailable;
    if(!program.admits_character_remap(providers.world))return Status::provider_unavailable;
    if(!program.admits_script_audio(providers.script_audio,providers.world))return Status::provider_unavailable;
    if(!program.admits_scene_record_parameters(providers.world,providers.messages))return Status::provider_unavailable;
    if(!program.admits_actor_script_commands(providers.world,providers.canonical_flags))return Status::provider_unavailable;
    if(!program.admits_resource_parameter_commands(providers.world,providers.resource_parameters,providers.scene_resources,providers.resource_templates))return Status::provider_unavailable;
    if(!program.admits_resource_activation(providers.resource_activation,providers.world,providers.scene_resources,providers.resource_templates))return Status::provider_unavailable;
    if(!program.admits_scenario_events(providers.scenario_events,providers.world))return Status::provider_unavailable;
    if(!program.admits_actor_script_terminal(providers.actor_script_terminal,providers.world))return Status::provider_unavailable;
    if(!program.admits_actor_interaction_commands(providers.world,providers.scene_resources))return Status::provider_unavailable;
    if(!program.admits_offline_room_variants(providers.world))return Status::provider_unavailable;
    if(!program.admits_scenario_enemy_relocation(providers.world,providers.flags==providers.canonical_flags?providers.canonical_flags:nullptr))return Status::provider_unavailable;
    if(!program.admits_timed_scene_text(providers.timed_scene_text,providers.world))return Status::provider_unavailable;
    if(!program.admits_difficulty(providers.world))return Status::provider_unavailable;
    if(!program.admits_inventory_ui(providers.inventory_ui,providers.world))return Status::provider_unavailable;
    if(!program.admits_actor_model_classes(providers.world))return Status::provider_unavailable;
    if(program.needs_selected_actor()&&!providers.world->primary(context.selected_actor))return Status::provider_unavailable;
    if(program.needs_action_choices()&&!providers.action_choices)return Status::provider_unavailable;
    if(program.needs_scenario()&&!providers.world->scenario)return Status::provider_unavailable;
    if(program.needs_canonical_flags()&&(!providers.canonical_flags||providers.flags!=providers.canonical_flags))return Status::provider_unavailable;
    if(program.needs_periodic_effects()&&(!providers.periodic_effects||!providers.periodic_effects->admitted()||
        !providers.periodic_effects->bound_to(*providers.scene_controls,*providers.canonical_flags,providers.world->session().random)))return Status::provider_unavailable;
    if(program.needs_surface_effects()&&(!providers.surface_effects||!providers.surface_effects->bound_to(*providers.world)))return Status::provider_unavailable;
    if(program.needs_room_objects()&&(!providers.room_objects||!providers.room_objects->ready(program.needs_room_object_lifetime(),program.needs_room_object_queries())))return Status::provider_unavailable;
    if(program.needs_models()&&!providers.models)return Status::provider_unavailable;
    for(const auto authored:program.adjusted_models())if(!providers.models->admits_adjustment(authored))return Status::provider_unavailable;
    for(const auto authored:program.visibility_models())if(!providers.models->admits_visibility(authored))return Status::provider_unavailable;
    if(!program.admits_offline_actor_inventory(providers.actor_resource_operations,providers.world,providers.scene_resources,providers.resource_templates))return Status::provider_unavailable;
    if(!program.admits_actor_offline_navigation(providers.actor_offline_navigation,providers.world,this))return Status::provider_unavailable;
    return Status::completed;
    };
    if(const auto status=provider_status(*initial_program);status!=Status::completed)return{status,0,{},0};
    auto validated_program=initial_program;
    running_=true;struct Reset{bool& flag;~Reset(){flag=false;}} reset{running_};
    selected_=static_cast<std::uint8_t>(id);std::size_t operations=0;std::uint32_t opcode=0;
    auto result=[&](Status s){return TickResult{s,operations,c.current,opcode};};
    if(!context.enabled)return result(Status::disabled);
    c.condition=0;
    auto advance=[&](const Record& r){c.current.offset+=r.bytes;};
    auto scan=[&](bool failed){
        const auto saved=c.condition;
        for(;;){
            if(operations>=budget)return Status::budget_exhausted;
            const auto scan_program=c.cursor_program?c.cursor_program:c.program;
            if(!scan_program)return Status::invalid_program;
            const auto current=scan_program->record(c.current);if(!current)return Status::invalid_record;
            advance(*current);const auto record=scan_program->record(c.current);if(!record)return Status::invalid_record;
            ++operations;const auto op=record->opcode;c.condition+=opener(op)?1u:0u;
            if(failed&&op==0xe4&&c.condition==saved){advance(*record);return Status::completed;}
            if(op==0xe5){if(c.condition==saved){--c.condition;advance(*record);return Status::completed;}--c.condition;}
            if(op==0xa||op==0xd){c.condition=0;return Status::completed;}
        }
    };
    for(;;){
        const auto cursor_program=c.cursor_program?c.cursor_program:c.program;
        if(!cursor_program)return result(Status::invalid_program);
        if(cursor_program!=validated_program){
            if(const auto status=provider_status(*cursor_program);status!=Status::completed)return result(status);
            validated_program=cursor_program;
        }
        //700330 can replace this channel during the handler. Keep its record
        //alive; 68C660 advances the replacement cursor by the old record size.
        const auto executing_program=cursor_program;
        const auto record=executing_program->record(c.current);if(!record)return result(Status::invalid_record);
        if(c.countdown){--c.countdown;return result(Status::yielded);}
        if(operations>=budget)return result(Status::budget_exhausted);
        ++operations;opcode=record->opcode;const auto payload=record->payload;
        auto value=[&](std::size_t offset){return word(payload.data()+offset);};
        auto signed_half=[&](std::size_t offset){return std::bit_cast<std::int16_t>(std::uint16_t(std::to_integer<std::uint16_t>(payload[offset])|
            (std::to_integer<std::uint16_t>(payload[offset+1])<<8)));};
        unsigned flow=0;
        bool skipped=false;
        if(offline){const auto& binding=offline_bindings[opcode];
            skipped=(binding.restricted&&offline->actor_category>=2)||
                (offline->room_relation==1&&binding.relation_one)||(offline->room_relation==2&&binding.relation_two);
        }
        if(skipped){if(opener(opcode)){++c.condition;const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}}
        else if(offline?offline_bindings[opcode].noop:original_noops[opcode]){}
        else switch(opcode){
        case 1:c.saved=c.current;c.saved.offset+=record->bytes;c.saved_program=executing_program;break;
        case 2:case 0xa:c.current=c.saved;c.cursor_program=c.saved_program?c.saved_program:c.program;flow=1;break;
        case 3:{const auto count=value(0);for(std::uint32_t i=0;i<count;++i){
            if(operations>=budget)return result(Status::budget_exhausted);
            const auto r=executing_program->record(c.current);if(!r)return result(Status::invalid_record);advance(*r);++operations;
        }flow=1;break;}
        case 4:c.countdown=value(0);break;
        case 5:case 6:{
            const auto slot=value(0);if(context.selected_actor>=events_.size()||slot>=4)return result(Status::invalid_record);
            auto& event=events_[context.selected_actor][slot];
            if(opcode==6)event.active=0;
            else if(!event.active){event.active=1;event.kind=std::to_integer<std::uint8_t>(payload[8]);event.value=std::uint16_t(value(4));}
            break;}
        case 7:case 0xd:++c.block_index;if(!c.program||c.block_index>=c.program->blocks())return result(Status::invalid_record);
            c.cursor_program.reset();c.current={c.block_index,0};flow=1;break;
        case 8:{++c.condition;const auto flag=providers.flags->get(FlagBank::scenario,value(0));
            if(!flag)return result(Status::provider_unavailable);
            const bool wanted=payload[4]!=std::byte{};if(*flag!=wanted){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0xb:{const auto selector=value(0),flag=value(4);const auto raw=std::to_integer<std::uint8_t>(payload[8]);bool ok=true;
            if(selector==0||selector==2)ok=providers.flags->scenario(flag,raw,selector==0?NotifyOwner::selected_actor_plus_one:NotifyOwner::zero,
                selector==0?static_cast<std::uint8_t>(context.selected_actor+1):std::uint8_t(0));
            else if(selector==1)ok=offline?providers.canonical_flags->actor_flag(ActorFlagFamily::primary,
                {offline->actor_category==0,static_cast<std::uint8_t>(offline->actor_category-1)},flag,raw!=0):providers.flags->write(FlagBank::local_primary,flag,raw!=0);
            if(!ok)return result(Status::provider_unavailable);
            break;}
        case 0xc:{const bool ok=value(0)==0?providers.flags->write(FlagBank::secondary,value(4),value(8)!=0):
            offline?providers.canonical_flags->actor_flag(ActorFlagFamily::auxiliary,{offline->actor_category==0,static_cast<std::uint8_t>(offline->actor_category-1)},value(4),value(8)!=0):
                providers.flags->write(FlagBank::local_auxiliary,value(4),value(8)!=0);
            if(!ok)return result(Status::provider_unavailable);
            break;}
        case 0x10:case 0x11:if(!providers.sequences->active(value(0),opcode==0x10))return result(Status::provider_unavailable);break;
        case 0x12:providers.sequences->enable_all();break;
        case 0x20:providers.lighting->select(std::to_integer<std::uint8_t>(payload[0]));break;
        case 0x23:if(!providers.lighting->create(std::to_integer<std::uint8_t>(payload[0])))return result(Status::provider_unavailable);break;
        case 0x24:if(!providers.lighting->remove(std::to_integer<std::uint8_t>(payload[0])))return result(Status::provider_unavailable);break;
        case 0x25:if(!providers.lighting->create_all())return result(Status::provider_unavailable);break;
        case 0xa0:case 0xa1:providers.scene_channels->bit(value(0),opcode==0xa0);break;
        case 0xa8:if(value(0)==1&&!providers.surface_effects->configure_surface(1,{value(4),value(8),value(12),value(16)}))return result(Status::provider_unavailable);break;
        case 0xa2:case 0xa3:providers.scene_channels->all(opcode==0xa2);break;
        case 0x190:break; // File1 main1B3C30 is the checked return-only body.
        case 0xc2:case 0xc3:{++c.condition;const auto index=std::to_integer<std::uint8_t>(payload[0]);
            const bool pass=opcode==0xc2?providers.room_objects->matches(index,std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(payload[4]))):providers.room_objects->presence(index,payload[4]!=std::byte{});
            if(!pass){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0xc4:if(!providers.room_objects->move(std::to_integer<std::uint8_t>(payload[0]),std::to_integer<std::uint8_t>(payload[4]),std::to_integer<std::uint8_t>(payload[8])))return result(Status::provider_unavailable);break;
        case 0xc5:case 0xc6:case 0xc7:providers.room_objects->flags(std::to_integer<std::uint8_t>(payload[0]),opcode==0xc5?16u:opcode==0xc7?32u:0u,opcode==0xc6?16u:0u);break;
        case 0x100:case 0x109:if(queue_actor_request(*providers.world,value(0),opcode==0x100?65535u:value(4))!=ActorRequestStatus::completed)return result(Status::provider_unavailable);break;
        case 0x131:{const auto status=providers.scene_controls->start_periodic({value(0),std::uint16_t(value(4)),std::uint16_t(value(8)),std::uint16_t(value(12))},*providers.periodic_effects);
            if(status.status!=ControlStatus::completed)return result(status.status==ControlStatus::budget_exhausted?Status::budget_exhausted:Status::provider_unavailable);
            break;}
        case 0x191:{const auto status=apply_scenario_room_rules(*providers.world,*providers.canonical_flags,*providers.scene_controls);
            if(status!=RoomRuleStatus::completed)return result(status==RoomRuleStatus::budget_exhausted?Status::budget_exhausted:Status::provider_unavailable);
            break;}
        case 0xb0:case 0xb1:if(providers.models->visibility(std::to_integer<std::uint8_t>(payload[0]),opcode==0xb1)!=ModelStatus::completed)return result(Status::provider_unavailable);break;
        case 0xb4:if(providers.models->adjust(std::to_integer<std::uint8_t>(payload[0]),value(4))!=ModelStatus::completed)return result(Status::provider_unavailable);break;
        case 0x63:if(providers.inventory_ui->configure_requests(value(0))!=gameplay_world::InventoryUiStatus::completed)return result(Status::provider_unavailable);break;
        case 0x64:if(!set_actor_model_classes(*providers.world,std::to_integer<std::uint8_t>(payload[0])))return result(Status::provider_unavailable);break;
        case 0x65:providers.world->session().script_room_parameter=std::to_integer<std::uint8_t>(payload[0]);break;
        case 0x68:
            if(!gameplay_world::queue_character_placement(*providers.world,std::to_integer<std::uint8_t>(payload[0]),
                std::to_integer<std::uint8_t>(payload[4]),std::to_integer<std::uint8_t>(payload[8])))
                return result(Status::provider_unavailable);
            break;
        case 0x69:
            if(!gameplay_world::script_actor_placement(*providers.world,std::to_integer<std::uint8_t>(payload[0]),
                std::to_integer<std::uint8_t>(payload[4]),std::to_integer<std::uint8_t>(payload[8])))
                return result(Status::provider_unavailable);
            break;
        case 0x6c:
            if(!script_control_placement(*providers.world,std::to_integer<std::uint8_t>(payload[0]),
                std::to_integer<std::uint8_t>(payload[4]),std::to_integer<std::uint8_t>(payload[8]),std::to_integer<std::uint8_t>(payload[12])))return result(Status::provider_unavailable);
            break;
        case 0x106:
            if(!set_script_anchor(*providers.world,value(0),value(4),value(8),value(12),std::bit_cast<std::int16_t>(std::uint16_t(value(16)))))return result(Status::provider_unavailable);
            break;
        case 0x172:
            if(!update_inventory_flag(*providers.world,providers.scene_resources,*providers.canonical_flags,std::uint16_t(value(0)),value(4)))return result(Status::provider_unavailable);
            break;
        case 0x6a:providers.world->session().actor_placements.clear_requests();break;
        case 0x70:{const auto audio=providers.streams->request(0,std::bit_cast<std::int32_t>(value(0)),0,*context.stream_tick,*providers.stream_backend);
            if(!stream_accepted(audio.status))return result(Status::provider_unavailable);
            break;}
        case 0x71:if(!stream_accepted(providers.streams->stop(0,*providers.stream_backend)))return result(Status::provider_unavailable);break;
        case 0x104:case 0x105:{
            const bool enable=opcode==0x104;
            if(!offline||offline->room_relation==0){
                const auto applied=providers.scene_controls->apply_typed(enable,value(0),value(4),value(8));
                if(applied.status!=ControlStatus::completed)return result(applied.status==ControlStatus::budget_exhausted?Status::budget_exhausted:Status::provider_unavailable);
                // The original shared-list sentinel returns before its saved
                // descriptor loop; it is not just a live-list-only filter.
                if(!providers.scene_controls->enabled())break;
            }
            if(offline&&!providers.saved_controls->apply(context.selected_actor,enable,value(0),value(4),value(8)))return result(Status::provider_unavailable);
            break;}
        case 0x135:{const auto actor=providers.world->primary(providers.world->selected_actor);if(!actor)return result(Status::provider_unavailable);
            const bool permitted=providers.world->locally_controlled(*actor);
            const auto applied=providers.scene_controls->choose_five(value(0),{value(4),value(8),value(12),value(16)},*providers.action_choices,actor->character,permitted,providers.world->session().random);
            if(applied.status!=ControlStatus::completed)return result(applied.status==ControlStatus::budget_exhausted?Status::budget_exhausted:Status::provider_unavailable);
            break;}
        case 0x155:case 0x180:{++c.condition;bool matches=false;
            if(opcode==0x155){const auto actor=providers.world->primary(providers.world->selected_actor);if(!actor)return result(Status::provider_unavailable);
                const bool equal=actor->character==std::to_integer<std::uint8_t>(payload[0]);matches=value(4)!=0?equal:!equal;
            }else matches=(value(0)==0&&providers.world->mode==0)||(value(0)==1&&providers.world->mode!=0);
            if(!matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0x50:case 0x51:case 0x52:case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:
        case 0x58:case 0x59:case 0x5b:case 0x5c:case 0x5d:case 0x5e:case 0x5f:case 0x72:case 0xb5:case 0xf6:{
            if(offline&&(opcode==0x53||opcode==0x58)){
                if(!apply_offline_navigation_control(providers.world,providers.scene_controls,offline->actor_room,
                    offline->room_relation,opcode==0x58,value(0),opcode==0x58?std::uint16_t(value(4)):0))
                    return result(Status::provider_unavailable);
                break;
            }
            const auto bytes=payload_minimum(opcode);ControlArguments arguments;arguments.authored_id=value(0);
            if(bytes>=8)arguments.parameter=value(4);
            if(bytes>=12)arguments.selector=value(8);
            if(bytes>=16)arguments.extra=std::uint16_t(value(12));
            const auto applied=providers.scene_controls->apply(*control_command(opcode),arguments,providers.control_effects);
            if(applied.status!=ControlStatus::completed)return result(applied.status==ControlStatus::budget_exhausted?Status::budget_exhausted:Status::provider_unavailable);
            break;}
        case 0x13:if(!providers.sequences->select(std::to_integer<std::uint8_t>(payload[0]),std::uint16_t(value(4))))return result(Status::provider_unavailable);break;
        case 0x15:if(!providers.sequences->cancel_if_selected(std::to_integer<std::uint8_t>(payload[0])))return result(Status::provider_unavailable);break;
        case 0x16:providers.sequences->percentage(std::to_integer<std::uint8_t>(payload[0]),signed_half(4),signed_half(8),value(12));break;
        case 0x14:case 0x17:{++c.condition;const bool matches=opcode==0x14?providers.sequences->phase_matches(value(0)):providers.sequences->id_matches(value(0),value(4));
            if(!matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0x30:case 0x31:case 0x32:case 0x33:{const auto id=providers.scene_resources->lookup(signed_half(0));
            if(id&&providers.scene_resources->command(*id,SceneCommand(opcode-0x30),context.current_room,providers.scene_effects)!=SceneStatus::completed)return result(Status::provider_unavailable);
            break;}
        case 0x34:{++c.condition;const auto id=providers.scene_resources->lookup(signed_half(0));
            const bool matches=id&&providers.scene_resources->inactive_or_flag29(*id).value_or(false);
            if(!matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0x35:{const auto attached=providers.scene_resources->lookup_attached(signed_half(0));
            if(attached&&providers.scene_resources->detach(*attached,providers.scene_effects,providers.scene_owners)!=SceneStatus::completed)return result(Status::provider_unavailable);
            break;}
        case 0x36:{
            // Unlike the other conditional handlers this original body does
            // NOT increment the condition ordinal before calling the scanner.
            const bool matches=providers.scene_resources->compare_attached(signed_half(0),signed_half(4),signed_half(8));
            if(!matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0x37:{const auto id=providers.scene_resources->lookup(signed_half(0));
            if(id&&providers.scene_resources->flag800(*id,std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(payload[4])))!=SceneStatus::completed)return result(Status::provider_unavailable);
            break;}
        case 0x38:
            if(!grant_actor_resource(*providers.world,*providers.scene_resources,*providers.resource_templates,
                signed_half(0),signed_half(4),signed_half(8)))return result(Status::provider_unavailable);
            break;
        case 0x39:
            if(!grant_character_resource(*providers.world,*providers.scene_resources,*providers.resource_templates,
                std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(payload[0])),signed_half(4),signed_half(8)))
                return result(Status::provider_unavailable);
            break;
        case 0x3a:
            if (!providers.world->session().npc_descriptors.grant(*providers.scene_resources,
                *providers.resource_templates,signed_half(0),signed_half(4),signed_half(8)))
                return result(Status::provider_unavailable);
            break;
        case 0x3d:
            if (!providers.world->session().npc_descriptors.select(*providers.scene_resources,
                std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(payload[0])),signed_half(4)))
                return result(Status::provider_unavailable);
            break;
        case 0x84:
            if (!remap_missing_characters(*providers.world,selected_)) return result(Status::provider_unavailable);
            break;
        case 0x80:case 0x88: {
            auto& session=providers.world->session();
            const auto id=session.missing_characters.resolve(value(0),session.actor_placements.selected_request,selected_);
            if (!id) return result(Status::invalid_program);
            const auto parameters=opcode==0x80 ? std::array<std::uint32_t,3>{} :
                std::array<std::uint32_t,3>{value(4),value(8),value(12)};
            if (!session.npc_descriptors.enable(session,*id,parameters)) return result(Status::provider_unavailable);
            break;
        }
        case 0x81: {
            auto& session=providers.world->session();
            const auto id=session.missing_characters.resolve(value(0),session.actor_placements.selected_request,selected_);
            if (!id) return result(Status::invalid_program);
            const auto index=session.npc_descriptors.disable(*id);
            if (index) (void)session.ai_control_requests.unregister_control(1,std::uint32_t(*index));
            break;
        }
        case 0x89:case 0x8a:case 0x8b:case 0x8c: {
            auto& session=providers.world->session();
            const auto id=session.missing_characters.resolve(std::uint16_t(value(0)),session.actor_placements.selected_request,selected_);
            if (!id) return result(Status::invalid_program);
            switch (opcode) {
            case 0x89:
                session.npc_descriptors.position(*id,std::uint8_t(value(4)),
                    {float(std::bit_cast<std::int32_t>(value(8))),float(std::bit_cast<std::int32_t>(value(12))),
                     float(std::bit_cast<std::int32_t>(value(16)))},std::uint16_t(value(20)));
                break;
            case 0x8a:session.npc_descriptors.health_flags(*id,std::bit_cast<std::int32_t>(value(4)),0x40000000u);break;
            case 0x8b:session.npc_descriptors.health_flags(*id,-1,0x40000008u);break;
            case 0x8c:session.npc_descriptors.health_flags(*id,-1,value(4)?0x80000010u:0x40000010u);break;
            default:break;
            }
            break;
        }
        case 0x173:
            if(!grant_special_inventory(*providers.world,*providers.scene_resources,*providers.resource_templates,
                std::uint16_t(value(0)),std::bit_cast<std::int32_t>(value(4))))return result(Status::provider_unavailable);
            break;
        case 0xee:{++c.condition;
            const auto selector=std::to_integer<std::uint8_t>(payload[4]);
            const bool matches=selector<6&&difficulty_matches(*providers.world->session().difficulty,std::to_integer<std::uint8_t>(payload[0]),selector);
            if(!matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0xe3:case 0xe6:case 0xec:case 0xed:case 0xef:{++c.condition;
            const auto actor_flag=[&](ActorFlagFamily family,std::uint32_t id){return offline?
                providers.canonical_flags->actor_flag(family,static_cast<std::uint8_t>(offline->actor_category),id):
                providers.flags->get(family==ActorFlagFamily::primary?FlagBank::local_primary:FlagBank::local_auxiliary,id);};
            const auto id=opcode==0xef&&!offline?std::to_integer<std::uint32_t>(payload[0]):value(0);
            const bool wanted=opcode==0xef&&!offline?payload[4]!=std::byte{}:value(4)!=0;
            std::optional<bool> flag;
            if(opcode==0xe3)flag=actor_flag(ActorFlagFamily::primary,id);
            else if(opcode==0xef)flag=actor_flag(ActorFlagFamily::auxiliary,id);
            else if(opcode==0xe6)flag=providers.flags->get(FlagBank::secondary,id);
            else{
                const auto first=opcode==0xec?providers.flags->get(FlagBank::scenario,id):actor_flag(ActorFlagFamily::primary,id);
                if(!first)return result(Status::provider_unavailable);
                // Preserve the original short circuit: the second bank is not
                // read if the first bit is clear.
                if(!*first)flag=false;
                else{const auto second=opcode==0xec?providers.flags->get(FlagBank::secondary,id):actor_flag(ActorFlagFamily::auxiliary,id);
                    if(!second)return result(Status::provider_unavailable);
                    flag=!*second;
                }
            }
            if(!flag)return result(Status::provider_unavailable);
            if(*flag!=wanted){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0xb7:case 0xb8:{++c.condition;const auto flag=providers.flags->test_strided(value(0),value(4),opcode==0xb7?2:0);
            if(!flag)return result(Status::provider_unavailable);
            if(*flag!=(value(8)!=0)){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0xf2:
            if(!providers.world->session().room_contacts.set_from_policy(value(0),value(4),std::bit_cast<std::int32_t>(value(8))))
                return result(Status::provider_unavailable);
            break;
        case 0xf4:case 0xf5:if(!providers.flags->strided(value(0),value(4),5,opcode==0xf4,false))return result(Status::provider_unavailable);break;
        case 0xe8:if(!providers.session_counters->store(offline?context.selected_actor:0,value(0),value(4)))return result(Status::provider_unavailable);break;
        case 0xe9:{++c.condition;const auto matches=providers.session_counters->consume(offline?context.selected_actor:0,value(0),value(4)!=0);
            if(!matches)return result(Status::provider_unavailable);
            if(!*matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0xea:{
            ++c.condition;
            const auto present=providers.world->contains_character(std::to_integer<std::uint8_t>(payload[0]));
            if(!present)return result(Status::provider_unavailable);
            const auto wanted=std::to_integer<std::uint8_t>(payload[4]);
            if(wanted<=1 && *present!=(wanted==1)){
                const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;
            }
            break;
        }
        case 0x62:{
            std::array<std::uint16_t,5> arguments;
            for(std::size_t i=0;i<arguments.size();++i)arguments[i]=std::uint16_t(value(4*i));
            if(!queue_cutscene(*providers.world,arguments,providers.forced_terminal))return result(Status::provider_unavailable);
            break;
        }
        case 0x61:
            if(!providers.forced_terminal->apply(*providers.world,value(0)))return result(Status::provider_unavailable);
            break;
        case 0x120:case 0x121:
            if(!providers.world->session().auxiliary_scene.set_timer(std::bit_cast<std::int32_t>(value(0)),opcode==0x120))
                return result(Status::provider_unavailable);
            break;
        case 0x122:
            providers.world->session().auxiliary_scene.select(value(0));
            break;
        case 0x85:
            if(!providers.world->session().room_actor_assets.append(value(0),
                {std::uint16_t(signed_half(4)),std::uint16_t(signed_half(8))}))return result(Status::provider_unavailable);
            break;
        case 0x86:
            (void)providers.world->session().room_actor_assets.remove(std::uint16_t(signed_half(0)));
            break;
        case 0x87:
            if(!providers.world->session().room_actor_assets.remove(std::uint16_t(signed_half(4)),value(0)))
                return result(Status::provider_unavailable);
            break;
        case 0x5a:
            if(offline){if(!set_offline_room_variant(*providers.world,value(0),value(4)))return result(Status::provider_unavailable);}
            else if(providers.world->closed()||!providers.world->session().room_variants.store(value(0),value(4)))return result(Status::provider_unavailable);
            break;
        case 0x44:if(value(0)<128&&!providers.flags->write(FlagBank::bounded_byte,value(0),true))return result(Status::provider_unavailable);break;
        case 0x164:if(!providers.flags->write(FlagBank::scene_record_eligibility,value(0),true))return result(Status::provider_unavailable);break;
        case 0x165:if(!clear_scene_record_eligibility(*providers.canonical_flags,*providers.world,value(0)))return result(Status::provider_unavailable);break;
        case 0x132:{
            const auto status=providers.timed_scene_text->request(std::uint16_t(value(0)));
            if(status!=TimedTextStatus::completed)return result(Status::provider_unavailable);
            break;
        }
        case 0x169:
            if(!relocate_scenario_enemy(*providers.world,providers.flags==providers.canonical_flags?providers.canonical_flags:nullptr,std::to_integer<std::uint8_t>(payload[0])))return result(Status::provider_unavailable);
            break;
        case 0x166:if(update_scene_record_parameter(*providers.world,std::to_integer<std::uint8_t>(payload[0]),std::to_integer<std::uint8_t>(payload[4]),std::to_integer<std::uint8_t>(payload[8]),providers.messages).status!=SceneRecordParameterStatus::completed)return result(Status::provider_unavailable);break;
        case 0x150:{++c.condition;
            const auto matches=actor_room_matches(*providers.world,value(0),std::uint16_t(value(4)),value(8)!=0);
            if(!matches)return result(Status::provider_unavailable);
            if(!*matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}
            break;}
        case 0x1a1:if(!set_actor_weight_profile(*providers.world,value(0),value(4),std::bit_cast<std::int32_t>(value(8))))return result(Status::provider_unavailable);break;
        case 0x151:{++c.condition;
            const auto matches=actor_population_rooms_match(*providers.world,std::uint16_t(value(0)),value(4));
            if(!matches)return result(Status::provider_unavailable);
            if(!*matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}
            break;}
        case 0x153:{++c.condition;
            const auto matches=actor_room_population_matches(*providers.world,value(0),value(4),value(8));
            if(!matches)return result(Status::provider_unavailable);
            if(!*matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}
            break;}
        case 0x156:{++c.condition;
            const auto matches=actor_condition_matches(*providers.world,providers.canonical_flags,value(0),value(4),value(8),value(12),value(16));
            if(!matches)return result(Status::provider_unavailable);
            if(!*matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}
            break;}
        case 0x1a5:if(!set_actor_ai_counter(*providers.world,value(0)))return result(Status::provider_unavailable);break;
        case 0x1a8:if(!set_actor_ai_damage_policy(*providers.world,value(0)))return result(Status::provider_unavailable);break;
        case 0x1a4:if(!set_actor_ai_inhibition(*providers.world,value(0),value(4)))return result(Status::provider_unavailable);break;
        case 0x1a6:case 0x1a7:
            if(!set_actor_forced_policy(*providers.world,value(0),opcode==0x1a7?0:value(4),opcode==0x1a7?0:value(8),opcode==0x1a7))return result(Status::provider_unavailable);
            break;
        case 0x1a9:
            if(providers.actor_script_terminal->retire_offline_actor(value(0))!=ActorScriptTerminalStatus::completed)return result(Status::provider_unavailable);
            break;
        case 0x1aa:{ //702D70 omits the ordinal increment despite scanner opener membership.
            const auto matches=offline_actor_reached_node(*providers.world,value(0),value(4),value(8));
            if(!matches)return result(Status::provider_unavailable);
            if(!*matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}
            break;}
        case 0x1ac:{const auto bank=value(0);if(bank>=3)break;++c.condition;
            const auto flag=providers.canonical_flags->actor_flag(ActorFlagFamily::primary,std::uint8_t(bank+1),value(4));
            if(!flag)return result(Status::provider_unavailable);
            if(*flag!=(value(8)!=0)){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}
            break;}
        case 0x175:{
            const auto required=gameplay_world::offline_actor_resource_required(*providers.world,signed_half(0),signed_half(4));
            if(!required)return result(Status::provider_unavailable);
            if(*required&&(!providers.actor_resource_operations||!providers.actor_resource_operations->grant_offline_resource(signed_half(0),signed_half(4),signed_half(8),signed_half(12))))return result(Status::provider_unavailable);
            break;}
        case 0x1a2:
            if(!providers.actor_offline_navigation||providers.actor_offline_navigation->command(value(0),value(4),value(8))!=OfflineNavigationStatus::completed)return result(Status::provider_unavailable);
            break;
        case 0x1a0:if(!set_actor_destination_policy(*providers.world,value(0),value(4),value(8)))return result(Status::provider_unavailable);break;
        case 0x170:
            if(!script_resource_parameter_noop(*providers.world,std::uint16_t(value(0)))&&
               providers.resource_parameters->command(std::uint16_t(value(0)),signed_half(4))!=SceneStatus::completed)return result(Status::provider_unavailable);
            break;
        case 0x174:
            if(signed_half(0)>0&&providers.resource_activation->command(signed_half(0),signed_half(4))!=SceneStatus::completed)return result(Status::provider_unavailable);
            break;
        case 0xd0:case 0xd1:{
            std::array<std::uint32_t,5> args;for(unsigned i=0;i<args.size();++i)args[i]=value(8+4*i);
            const auto status=opcode==0xd0?providers.scenario_events->scenario_command(value(0),value(4),args):providers.scenario_events->command(value(0),value(4),args);
            if(status!=ScenarioEventStatus::completed)return result(Status::provider_unavailable);
            break;
        }
        case 0x60:
            if(providers.actor_script_terminal->command()!=ActorScriptTerminalStatus::completed)return result(Status::provider_unavailable);
            break;
        case 0x108:
            if(providers.inventory_ui->force_close()!=gameplay_world::InventoryUiStatus::completed)return result(Status::provider_unavailable);
            break;
        case 0x73:{
            const auto mode=value(4);
            if(mode<=2){
                const auto actor=mode==1?value(8):0;
                std::array<std::int32_t,3> coordinates{};
                if(mode==2)for(unsigned i=0;i<3;++i)coordinates[i]=std::bit_cast<std::int32_t>(value(8+4*i));
                if(!providers.script_audio->command(value(0),mode,actor,coordinates))return result(Status::provider_unavailable);
            }
            break;}
        case 0x40:case 0x41:case 0x42:case 0x43:
            if(!providers.flags->strided(value(0),value(4),0,opcode==0x40||opcode==0x42,opcode==0x42||opcode==0x43))return result(Status::provider_unavailable);
            break;
        case 0x45:{const auto slot=value(8);if(slot<8){const auto packed=std::uint16_t(std::uint16_t(value(4))|(value(0)?0x8000:0));
            const gameplay_tasks::FlagTarget target{packed&0x8000?gameplay_tasks::FlagScope::session_owner_zero:gameplay_tasks::FlagScope::scenario,std::uint16_t(packed&0x7fff)};
            if(providers.timers->arm(slot,std::bit_cast<std::int16_t>(std::uint16_t(value(12))),target)!=gameplay_tasks::Status::completed)return result(Status::provider_unavailable);
        }break;}
        case 0x46:if(!providers.signals->send({value(0),std::to_integer<std::uint8_t>(payload[4]),value(8)}))return result(Status::provider_unavailable);break;
        case 0x47:case 0x48:{++c.condition;const auto predicate=providers.signals->query(value(0));if(!predicate)return result(Status::provider_unavailable);
            const bool wanted=value(4)!=0;
            // Opcode47's nonzero selector requires ZERO, unlike opcode48's
            // exact-one predicate. Preserve the actual opposite polarity.
            const bool matches=opcode==0x47?((*predicate==0)==wanted):((*predicate==1)==wanted);
            if(!matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0x49:case 0x4d:{++c.condition;std::optional<bool> flag;
            if(opcode==0x49)flag=providers.flags->get(FlagBank::bounded_byte,value(0));
            else flag=(value(0)&31)>=16?std::optional<bool>(false):providers.flags->get(FlagBank::bounded_halfword,value(0)&31);
            if(!flag)return result(Status::provider_unavailable);
            if(*flag!=(value(4)!=0)){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0x4c:if(value(0)<16&&!providers.flags->write(FlagBank::bounded_halfword,value(0),true))return result(Status::provider_unavailable);break;
        case 0x110:case 0x111:case 0x112:{const auto index=value(0);if(index<4){
            if(opcode==0x110)counters_[index]=value(4);else if(opcode==0x111)counters_[index]+=value(4);else counters_[index]-=value(4);
        }break;}
        case 0x113:{const auto index=value(0);if(index>=4)break;++c.condition;
            const auto operation=value(8),actual=counters_[index],expected=value(4);bool matches=true;
            switch(operation){case 0:matches=actual==expected;break;case 1:matches=actual!=expected;break;
            case 2:matches=actual>=expected;break;case 3:matches=actual<=expected;break;
            case 4:matches=actual>expected;break;case 5:matches=actual<expected;break;default:break;}
            if(!matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
        case 0x114:counters_.fill(0);break;
        case 0xe4:{const auto status=scan(false);if(status!=Status::completed)return result(status);flow=2;break;}
        case 0xe5:++c.condition;break;
        default:return result(Status::unsupported_opcode);
        }
        // Return2 reloads before the explicit0A/0D yield checks in the original.
        if(flow==2)continue;
        if(opcode==0xa||opcode==0xd)return result(Status::yielded);
        if(flow==0)advance(*record);
    }
}
} // namespace reo::native::gameplay_scenario
