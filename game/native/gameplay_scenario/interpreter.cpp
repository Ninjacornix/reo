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
#include "room_object_commands.hpp"
#include "periodic_effects.hpp"
#include "surface_effects.hpp"
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
    switch(op){case 0xa8:return 4;case 0x131:return 14;case 0x100:return 4;case 0x109:return 8;case 0xc2:case 0xc3:case 0xea:return 5;case 0xc4:return 9;case 0xc5:case 0xc6:case 0xc7:return 1;case 0xb0:case 0xb1:return 1;case 0xb4:return 8;case 0x62:case 0x135:return 20;case 0x155:return 8;case 0x120:case 0x121:case 0x122:case 0x180:return 4;
    case 0x50:case 0x54:case 0x55:case 0xf2:case 0x104:case 0x105:return 12;case 0x57:return 16;
    case 0x51:case 0x52:case 0x58:case 0x5a:case 0x5f:case 0x72:case 0xb5:case 0xf6:case 0x173:return 8;
    case 0x53:case 0x56:case 0x59:case 0x5b:case 0x5c:case 0x5d:case 0x5e:return 4;
    case 0x70:case 0xa0:case 0xa1:return 4;case 0x20:case 0x23:case 0x24:case 0x65:return 1;case 0x10:case 0x11:case 0x14:return 4;case 0x13:return 6;case 0x15:return 1;case 0x16:return 16;case 0x17:return 8;
    case 3:case 4:case 6:case 0x44:case 0x4c:return 4;case 8:return 5;
    case 0xe3:case 0xe6:case 0xe8:case 0xe9:case 0xec:case 0xed:case 0xef:case 0xf4:case 0xf5:return 8;
    case 0x40:case 0x41:case 0x42:case 0x43:case 0x47:case 0x48:case 0x49:case 0x4d:case 0x110:case 0x111:case 0x112:return 8;
    case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x86:return 2;case 0x37:return 5;case 0x36:case 0x38:case 0x39:case 0x85:return 10;case 0x87:return 6;
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
    case 0xec:case 0xed:case 0xef:case 0x113:case 0x155:case 0x180:
        binding.flow=ScriptFlow::if_test;break;
    case 0x36:binding.flow=ScriptFlow::if_test_without_open;break;
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
            low_actor_population_|=!noop&&(op==0x38||op==0x39);
            full_actor_population_|=!noop&&op==0x173;
            actor_roster_|=!noop&&op==0xea;
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
            if(!noop&&op==0x69){
                using gameplay_world::ActorPlacements;
                const auto actor=std::to_integer<unsigned>(b[at+4]);
                const auto command=std::to_integer<unsigned>(b[at+8]);
                const bool immediate=command==0xf0||command==0xf1;
                if(actor>=gameplay_world::World::primary_capacity||
                    (!immediate&&actor!=4&&actor>=ActorPlacements::request_count)||
                    (command==0xf0&&std::to_integer<unsigned>(b[at+12])>=ActorPlacements::position_capacity))
                    throw std::invalid_argument("Native actor placement profile");
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
            scene_resources_|=coverage[op].scene_resources_required;session_counters_|=coverage[op].session_counters_required;
            sequences_|=coverage[op].sequences_required;lighting_|=coverage[op].lighting_required;scene_channels_|=coverage[op].scene_channels_required;
            scene_controls_|=coverage[op].scene_controls_required;streams_|=coverage[op].streams_required;saved_controls_|=coverage[op].saved_controls_required;
            world_|=coverage[op].world_required&&(op!=0xa8||surface_command);selected_actor_|=coverage[op].selected_actor_required;action_choices_|=coverage[op].action_choices_required;models_|=coverage[op].models_required;
            scenario_|=coverage[op].scenario_required;canonical_flags_|=coverage[op].canonical_flags_required;at+=bytes;
        }
    }
}
bool Program::admits_room_counters(const gameplay_world::World* world)const noexcept {
    return !room_counters_ || (world && !world->closed() &&
        world->session().room_contacts.counters_ready(scenario_counter_policy_));
}
bool Program::admits_inventory_grants(const gameplay_world::World* world,const SceneResources* resources,
                                     const ResourceTemplates* templates)const noexcept{
    return (!low_actor_population_&&!full_actor_population_)||
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
    for(const auto i:{0x46,0x47,0x48})out[i]={true,false,false,true};
    out[0x45]={true,false,true,false};
    for(std::size_t i=0x30;i<=0x37;++i)out[i]={true,false,false,false,true};
    for(const auto i:{0x38,0x39,0x173}){
        out[i].native_algorithm=true;
        out[i].scene_resources_required=true;
        out[i].world_required=true;
    }
    for(const auto i:{0xe8,0xe9})out[i]={true,false,false,false,false,true};
    for(std::size_t i=0x10;i<=0x17;++i)out[i]={true,false,false,false,false,false,true};
    for(const auto i:{0x20,0x23,0x24,0x25})out[i]={true,false,false,false,false,false,false,true};
    for(std::size_t i=0xa0;i<=0xa3;++i)out[i]={true,false,false,false,false,false,false,false,true};
    out[0x190].native_algorithm=true;
    for(std::size_t i=0;i<out.size();++i)if(control_command(std::uint32_t(i)))out[i]={true,false,false,false,false,false,false,false,false,true};
    for(const auto i:{0x70,0x71})out[i]={true,false,false,false,false,false,false,false,false,false,true};
    for(const auto i:{0x104,0x105})out[i]={true,false,false,false,false,false,false,false,false,true};
    for(const auto i:{0x5a,0x62,0x65,0x68,0x69,0x6a,0x85,0x86,0x87,0xea,0xf2,0x120,0x121,0x122,0x135,0x155,0x180}){out[i].native_algorithm=true;out[i].world_required=true;}
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
    if(profile==DispatchProfile::offline_actor)for(std::size_t i=0;i<out.size();++i){
        if(offline_bindings[i].noop)out[i]={true,false,false,false};
        else if(!offline_bindings[i].same_handler&&i!=0xb&&i!=0xc&&i!=0xe3&&i!=0xed&&i!=0xef&&i!=0x104&&i!=0x105)out[i]={};
        if(i==0x104||i==0x105)out[i].saved_controls_required=true;
    }
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
    if(!value.program||!value.program->record(value.current)||value.block_index>=value.program->blocks())return Status::invalid_program;
    if(value.saved.block!=UINT32_MAX&&!value.program->record(value.saved))return Status::invalid_program;
    if(value.program->unsupported())return Status::unsupported_opcode;
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
    auto& c=channels_[id];if(!c.program)return{Status::invalid_program,0,{},0};
    if(c.program->profile()!=(offline?DispatchProfile::offline_actor:DispatchProfile::ordinary))return{Status::invalid_program,0,{},0};
    if(offline&&offline->actor_category>4)return{Status::invalid_program,0,{},0};
    if(offline&&(!providers.canonical_flags||providers.flags!=providers.canonical_flags))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_actor_events()&&context.selected_actor>=4)return{Status::invalid_program,0,{},0};
    if((c.program->needs_flags()&&!providers.flags)||(c.program->needs_timers()&&!providers.timers))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_signals()&&!providers.signals)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_scene_resources()&&!providers.scene_resources)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_session_counters()&&!providers.session_counters)return{Status::provider_unavailable,0,{},0};
    if(offline&&c.program->needs_session_counters()&&context.selected_actor>=3)return{Status::invalid_program,0,{},0};
    if(c.program->needs_sequences()&&!providers.sequences)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_lighting()&&!providers.lighting)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_scene_channels()&&!providers.scene_channels)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_scene_controls()&&!providers.scene_controls)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_streams()&&(!providers.streams||!providers.stream_backend||!context.stream_tick))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_saved_controls()&&(!providers.saved_controls||context.selected_actor>=SavedControlRecords::owner_count))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_world()&&(!providers.world||providers.world->closed()||providers.world->selected_actor!=context.selected_actor))return{Status::provider_unavailable,0,{},0};
    if(!c.program->admits_room_counters(providers.world))return{Status::provider_unavailable,0,{},0};
    if(!c.program->admits_inventory_grants(providers.world,providers.scene_resources,providers.resource_templates))return{Status::provider_unavailable,0,{},0};
    if(!c.program->admits_actor_roster(providers.world))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_selected_actor()&&!providers.world->primary(context.selected_actor))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_action_choices()&&!providers.action_choices)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_scenario()&&!providers.world->scenario)return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_canonical_flags()&&(!providers.canonical_flags||providers.flags!=providers.canonical_flags))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_periodic_effects()&&(!providers.periodic_effects||!providers.periodic_effects->admitted()||
        !providers.periodic_effects->bound_to(*providers.scene_controls,*providers.canonical_flags,providers.world->session().random)))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_surface_effects()&&(!providers.surface_effects||!providers.surface_effects->bound_to(*providers.world)))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_room_objects()&&(!providers.room_objects||!providers.room_objects->ready(c.program->needs_room_object_lifetime(),c.program->needs_room_object_queries())))return{Status::provider_unavailable,0,{},0};
    if(c.program->needs_models()&&!providers.models)return{Status::provider_unavailable,0,{},0};
    for(const auto authored:c.program->adjusted_models())if(!providers.models->admits_adjustment(authored))return{Status::provider_unavailable,0,{},0};
    for(const auto authored:c.program->visibility_models())if(!providers.models->admits_visibility(authored))return{Status::provider_unavailable,0,{},0};
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
            const auto current=c.program->record(c.current);if(!current)return Status::invalid_record;
            advance(*current);const auto record=c.program->record(c.current);if(!record)return Status::invalid_record;
            ++operations;const auto op=record->opcode;c.condition+=opener(op)?1u:0u;
            if(failed&&op==0xe4&&c.condition==saved){advance(*record);return Status::completed;}
            if(op==0xe5){if(c.condition==saved){--c.condition;advance(*record);return Status::completed;}--c.condition;}
            if(op==0xa||op==0xd){c.condition=0;return Status::completed;}
        }
    };
    for(;;){
        const auto record=c.program->record(c.current);if(!record)return result(Status::invalid_record);
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
        case 1:c.saved=c.current;c.saved.offset+=record->bytes;break;
        case 2:case 0xa:c.current=c.saved;flow=1;break;
        case 3:{const auto count=value(0);for(std::uint32_t i=0;i<count;++i){
            if(operations>=budget)return result(Status::budget_exhausted);
            const auto r=c.program->record(c.current);if(!r)return result(Status::invalid_record);advance(*r);++operations;
        }flow=1;break;}
        case 4:c.countdown=value(0);break;
        case 5:case 6:{
            const auto slot=value(0);if(context.selected_actor>=events_.size()||slot>=4)return result(Status::invalid_record);
            auto& event=events_[context.selected_actor][slot];
            if(opcode==6)event.active=0;
            else if(!event.active){event.active=1;event.kind=std::to_integer<std::uint8_t>(payload[8]);event.value=std::uint16_t(value(4));}
            break;}
        case 7:case 0xd:++c.block_index;if(c.block_index>=c.program->blocks())return result(Status::invalid_record);
            c.current={c.block_index,0};flow=1;break;
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
        case 0x173:
            if(!grant_special_inventory(*providers.world,*providers.scene_resources,*providers.resource_templates,
                std::uint16_t(value(0)),std::bit_cast<std::int32_t>(value(4))))return result(Status::provider_unavailable);
            break;
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
        case 0x5a:if(providers.world->closed()||!providers.world->session().room_variants.store(value(0),value(4)))return result(Status::provider_unavailable);break;
        case 0x44:if(value(0)<128&&!providers.flags->write(FlagBank::bounded_byte,value(0),true))return result(Status::provider_unavailable);break;
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
