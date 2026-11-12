#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
namespace {
std::vector<std::uint8_t> memory(0x2000000);
std::vector<Event> original_events;
constexpr unsigned record_base=0x100000,body_base=0x300000,actor_base=0x200000;
unsigned original_channel{};bool original_hidden{};
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
unsigned actor_address(const w::DialogueContext& context,const w::actors::EntityId& id){for(unsigned i=0;i<2;++i)if(context.world.identity(i)==id)return actor_base+i*0x10e0;return 0;}
std::vector<std::byte> original_string(unsigned at){std::vector<std::byte> value;for(unsigned i=0;i<64;++i){const auto c=memory.at(at+i);if(!c)return value;value.push_back(std::byte(c));}throw std::runtime_error("Unterminated original dialogue output");}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++source_calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x1ba250:if(GPR_S32(context,6)>=0)original_events.push_back({3,std::int32_t(memory[GPR_U32(context,4)+3]),GPR_S32(context,6),0,{}});SET_GPR_S32(context,2,-1);break; // Qualified ordinary archive marker0 leaf.
    case 0x1b49b0:original_events.push_back({0,0,0,0,original_string(GPR_U32(context,4))});break;
    case 0x6dee20:original_events.push_back({1,original_hidden?1:0,0,0,{}});SET_GPR_U32(context,2,original_hidden?1:0);break;
    case 0x1b48e0:check(GPR_U32(context,6)==1&&GPR_U32(context,7)==20);original_events.push_back({2,GPR_S32(context,4),GPR_S32(context,5),std::uint8_t(GPR_U32(context,9)),original_string(GPR_U32(context,8))});break;
    default:throw std::runtime_error("Undeclared dialogue source helper "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void export_original(const w::DialogueRecord& record,const w::DialogueContext& context,unsigned channel,bool hidden){
    original_channel=channel;original_hidden=hidden;original_events.clear();owned_constants(memory.data());
    std::fill_n(memory.data()+record_base,0x98,0);put(record_base,std::uint16_t(record.active));put(record_base+2,record.phase);put(record_base+4,record.delay);put(record_base+6,record.initial_delay);put(record_base+8,record.age);put(record_base+0xa,record.fade_ticks);put(record_base+0xb,record.character_ticks);put(record_base+0xc,record.alpha);put(record_base+0xd,record.channel);put(record_base+0xe,record.revealed);put(record_base+0x10,record.line_bytes);put(record_base+0x14,body_base);std::memcpy(memory.data()+record_base+0x18,record.buffer.data(),record.buffer.size());put(record_base+0x58,record.voice);put(record_base+0x5a,record.center);put(record_base+0x5c,actor_address(context,record.actor));put(record_base+0x60,record.sequence);put(record_base+0x62,record.glyphs);put(record_base+0x65,record.corruption_count);put(record_base+0x66,record.reveal_index);put(record_base+0x67,record.literal);put(record_base+0x68,record.page);put(record_base+0x69,record.newlines);std::memcpy(memory.data()+record_base+0x6a,record.prefix.data(),4);std::memcpy(memory.data()+record_base+0x72,record.corrupted.data(),32);put(record_base+0x92,record.display_style);
    const auto text=record.text_owner->text(record.text_index);check(bool(text));std::memcpy(memory.data()+body_base,text->body.data(),text->body.size());memory[body_base+text->body.size()]=0;
    for(unsigned i=0;i<2;++i){const auto actor=context.world.primary(i);const unsigned at=actor_base+0x10e0*i;memory[at+2]=actor->category;memory[at+3]=actor->slot;put(at+0x58,actor->collision.basis.x.z);put(at+0xdb8,*actor->speech.gauge_notice);put(at+0x1075,*actor->speech.display_style);put(0x74dd30+2*i,context.selected_counts[i]);const auto selected=0x400000u+256*i;put(0x74dcb4+64*i,selected);put(selected,std::uint16_t(context.second_selected_active[i]));}
    put(0x74e778,context.previous_secondary_actor?actor_address(context,*context.previous_secondary_actor):0);const auto random=context.world.session().random.state();put(0x3244b0,random.primary);put(0x3244b8,random.secondary);put(0x2b8de8,random.observed);
}
void compare_original(const w::DialogueRecord& record,const w::DialogueContext& context){
    R5900Context state;PS2Runtime runtime;state.pc=0x6b97d0;SET_GPR_U32(&state,4,record_base);SET_GPR_U32(&state,5,original_channel);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==0xabcdef&&GPR_U32(&state,29)==0x1f00000);
    if(std::memcmp(memory.data()+record_base+0x18,record.buffer.data(),64)){std::cerr<<"Buffer difference case="<<source_cases<<" phase="<<record.phase<<" revealed="<<record.revealed<<'\n';for(unsigned i=0;i<64;++i)if(memory[record_base+0x18+i]!=std::to_integer<unsigned>(record.buffer[i]))std::cerr<<i<<":"<<unsigned(memory[record_base+0x18+i])<<"/"<<std::to_integer<unsigned>(record.buffer[i])<<" ";std::cerr<<'\n';}
    for(const auto& [offset,value]:std::array<std::pair<unsigned,int>,11>{{{2,record.phase},{4,record.delay},{0xa,record.fade_ticks},{0xb,record.character_ticks},{0xc,record.alpha},{0xe,record.revealed},{0x10,record.line_bytes},{0x5a,record.center},{0x62,record.glyphs},{0x65,record.corruption_count},{0x66,record.reveal_index}}}){const int original=offset<8||offset==0xe||offset==0x10||offset==0x5a||offset==0x62?get<std::int16_t>(record_base+offset):offset==0xc?get<std::uint8_t>(record_base+offset):get<std::int8_t>(record_base+offset);if(original!=value)std::cerr<<"Scalar difference case="<<source_cases<<" offset="<<offset<<" original="<<original<<" native="<<value<<'\n';}
    check(get<std::uint16_t>(record_base)==unsigned(record.active));check(get<std::int16_t>(record_base+2)==record.phase);check(get<std::int16_t>(record_base+4)==record.delay);check(get<std::int16_t>(record_base+6)==record.initial_delay);check(get<std::int16_t>(record_base+8)==record.age);check(get<std::int8_t>(record_base+0xa)==record.fade_ticks);check(get<std::int8_t>(record_base+0xb)==record.character_ticks);check(get<std::uint8_t>(record_base+0xc)==record.alpha);check(get<std::int8_t>(record_base+0xd)==record.channel);check(get<std::int16_t>(record_base+0xe)==record.revealed);check(get<std::int16_t>(record_base+0x10)==record.line_bytes);check(std::memcmp(memory.data()+record_base+0x18,record.buffer.data(),64)==0);check(get<std::int16_t>(record_base+0x58)==record.voice);check(get<std::int16_t>(record_base+0x5a)==record.center);check(get<std::uint16_t>(record_base+0x60)==record.sequence);check(get<std::int16_t>(record_base+0x62)==record.glyphs);check(get<std::int8_t>(record_base+0x65)==record.corruption_count);check(get<std::int8_t>(record_base+0x66)==record.reveal_index);check(get<std::int8_t>(record_base+0x67)==record.literal);check(get<std::int8_t>(record_base+0x68)==record.page);check(get<std::int8_t>(record_base+0x69)==record.newlines);check(std::memcmp(memory.data()+record_base+0x6a,record.prefix.data(),4)==0);check(std::memcmp(memory.data()+record_base+0x72,record.corrupted.data(),32)==0);check(get<std::int8_t>(record_base+0x92)==record.display_style);
    for(unsigned i=0;i<2;++i)check(get<std::int8_t>(actor_base+0x10e0*i+0x1075)==*context.world.primary(i)->speech.display_style);
    const auto random=context.world.session().random.state();check(get<std::uint16_t>(0x3244b0)==random.primary&&get<std::uint16_t>(0x3244b8)==random.secondary&&get<std::uint8_t>(0x2b8de8)==random.observed);
    if(events!=original_events){std::cerr<<"Event difference frame="<<source_cases<<" native="<<events.size()<<" original="<<original_events.size()<<'\n';}
    check(events==original_events);++source_cases;
}
