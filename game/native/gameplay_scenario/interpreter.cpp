#include "interpreter.hpp"
#include "flags.hpp"
#include "scene_resources.hpp"
#include "session_counters.hpp"
#include "sequence_control.hpp"
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
    switch(op){case 0x10:case 0x11:case 0x14:return 4;case 0x13:return 6;case 0x15:return 1;case 0x16:return 16;case 0x17:return 8;
    case 3:case 4:case 6:case 0x44:case 0x4c:return 4;case 8:return 5;
    case 0xe3:case 0xe6:case 0xe8:case 0xe9:case 0xec:case 0xed:case 0xef:case 0xf4:case 0xf5:return 8;
    case 0x40:case 0x41:case 0x42:case 0x43:case 0x47:case 0x48:case 0x49:case 0x4d:case 0x110:case 0x111:case 0x112:return 8;
    case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:return 2;case 0x37:return 5;case 0x36:return 10;
    case 5:case 0xb:return 9;case 0xc:case 0x46:case 0x113:case 0xb7:case 0xb8:return 12;case 0x45:return 16;default:return 0;}
}
bool opener(std::uint32_t op)noexcept{
    constexpr std::array<std::uint32_t,32> values{0xe6,8,0xe3,0x34,0xe9,0xea,0xec,0xed,0x14,0x113,0x150,0x151,0x152,0x153,0x155,0x156,0xc2,0xc3,0xee,0x36,0x47,0x48,0x49,0x4d,0xb7,0xb8,0x158,0x180,0x159,0x17,0x1aa,0x1ac};
    return std::find(values.begin(),values.end(),op)!=values.end();
}
}
std::uint32_t Program::record_bytes(std::uint32_t header)noexcept{return (std::uint32_t(1)<<((header>>24)&31))*4u;}
Program::Program(std::vector<std::vector<std::byte>> blocks,DispatchProfile profile):blocks_(std::move(blocks)),profile_(profile){
    if(blocks_.empty()||blocks_.size()>UINT32_MAX)throw std::invalid_argument("Bounded native script blocks required");
    boundaries_.resize(blocks_.size());const auto coverage=Interpreter::coverage(profile);
    for(std::size_t i=0;i<blocks_.size();++i){
        const auto& b=blocks_[i];if(b.empty()||b.size()>UINT32_MAX)throw std::invalid_argument("Native script block extent");
        std::size_t at=0;
        while(at<b.size()){
            if(b.size()-at<4)throw std::invalid_argument("Truncated script header");
            const auto h=word(b.data()+at),bytes=record_bytes(h),op=h&0xffffff;
            const bool noop=op<432&&(profile==DispatchProfile::ordinary?original_noops[op]:offline_bindings[op].noop);
            if(!bytes||bytes>b.size()-at||op>=432||(!noop&&bytes-4<payload_minimum(op)))throw std::invalid_argument("Invalid script record");
            boundaries_[i].push_back(static_cast<std::uint32_t>(at));unsupported_|=!coverage[op].native_algorithm;
            if(!noop&&(op==5||op==6)){if(word(b.data()+at+4)>=4)throw std::invalid_argument("Actor event slot extent");actor_events_=true;}
            if(!noop&&(op==0xe8||op==0xe9)&&word(b.data()+at+4)>=2)throw std::invalid_argument("Native session counter profile");
            if(!noop&&(op==0x10||op==0x11)&&word(b.data()+at+4)>=256)throw std::invalid_argument("Native sequence index profile");
            flags_|=coverage[op].flags_required;timers_|=coverage[op].timers_required;signals_|=coverage[op].signals_required;
            scene_resources_|=coverage[op].scene_resources_required;session_counters_|=coverage[op].session_counters_required;
            sequences_|=coverage[op].sequences_required;at+=bytes;
        }
    }
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
    for(const auto i:{0xe8,0xe9})out[i]={true,false,false,false,false,true};
    for(std::size_t i=0x10;i<=0x17;++i)out[i]={true,false,false,false,false,false,true};
    if(profile==DispatchProfile::offline_actor)for(std::size_t i=0;i<out.size();++i){
        if(offline_bindings[i].noop)out[i]={true,false,false,false};
        else if(!offline_bindings[i].same_handler&&i!=0xb&&i!=0xc&&i!=0xe3&&i!=0xed&&i!=0xef)out[i]={};
    }
    return out;
}
Status Interpreter::install(std::size_t id,std::shared_ptr<const Program> p,Position entry)noexcept{
    if(running_)return Status::busy;
    if(id>=channel_count)return Status::invalid_channel;
    if(!p||!p->record(entry))return Status::invalid_program;
    if(p->unsupported())return Status::unsupported_opcode;
    channels_[id]=Channel{std::move(p),entry,{},0,entry.block,0};return Status::completed;
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
        case 0x13:providers.sequences->select(std::to_integer<std::uint8_t>(payload[0]),std::uint16_t(value(4)));break;
        case 0x15:providers.sequences->cancel_if_selected(std::to_integer<std::uint8_t>(payload[0]));break;
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
        case 0xf4:case 0xf5:if(!providers.flags->strided(value(0),value(4),5,opcode==0xf4,false))return result(Status::provider_unavailable);break;
        case 0xe8:if(!providers.session_counters->store(offline?context.selected_actor:0,value(0),value(4)))return result(Status::provider_unavailable);break;
        case 0xe9:{++c.condition;const auto matches=providers.session_counters->consume(offline?context.selected_actor:0,value(0),value(4)!=0);
            if(!matches)return result(Status::provider_unavailable);
            if(!*matches){const auto status=scan(true);if(status!=Status::completed)return result(status);flow=2;}break;}
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
