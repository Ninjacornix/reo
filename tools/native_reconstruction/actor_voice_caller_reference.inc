#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
namespace {
std::vector<std::uint8_t> memory(0x2000000);
std::vector<Event> original_events;
Output* original_output{};int original_member{};std::uint8_t original_slot{};
constexpr unsigned actor_base=0x10000;
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
unsigned original_channel(R5900Context* context){const auto handle=GPR_U32(context,4);check(handle>=0x610000&&handle<0x610300&&(handle-0x610000)%256==0);return (handle-0x610000)/256;}
void event(unsigned kind,unsigned channel,std::int32_t first=0,std::int32_t second=0){const auto at=0x2b8d70+24*channel;original_events.push_back({kind,channel,first,second,get<unsigned>(0x20f3c4),get<std::int32_t>(0x4bae24+4*channel),std::int8_t(memory[at]),get<std::int32_t>(at+4),get<unsigned>(at+12)});}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++source_calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x1b82a0:SET_GPR_U32(context,2,0);break; // Explicit source feature flags are both disabled.
    case 0x131e38:event(2,original_channel(context));break;
    case 0x131ef8:event(0,original_channel(context));SET_GPR_S32(context,2,original_output->phase_value);break;
    case 0x1327b8:event(4,original_channel(context),GPR_S32(context,5));break;
    case 0x132e50:event(3,original_channel(context),GPR_S32(context,5));break;
    case 0x133490:check(GPR_U32(context,5)==unsigned(original_slot)+5u&&GPR_S32(context,6)==original_member);event(1,original_channel(context),GPR_S32(context,5),GPR_S32(context,6));break;
    case 0x1b94b0:{
        check(GPR_U32(context,4)==actor_base+0x38&&GPR_U32(context,5)==0x234890);
        // Independently qualified spatial helper boundary. Native caller runs
        // actual locate(); these fixed points have source-known gains.
        const float distance=get<float>(actor_base+0x38);check(distance==0||distance==50||distance==100||distance==400||distance==4750||distance==5000);
        const unsigned gain=distance<=100?127:distance==400?122:0;
        if(gain){const unsigned pan=63;std::memcpy(memory+GPR_U32(context,6),&gain,4);std::memcpy(memory+GPR_U32(context,7),&pan,4);}
        SET_GPR_U32(context,2,gain?1:0);break;
    }
    default:throw std::runtime_error("Undeclared actor voice caller helper "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void begin_original(const w::Actor& actor,const s::StreamChannelSnapshot& state,Output& output,int member){
    owned_constants(memory.data());original_output=&output;original_member=member;original_slot=actor.slot;original_events.clear();original_events.reserve(32);
    memory[actor_base+2]=actor.category;memory[actor_base+3]=actor.slot;put(actor_base+0x38,actor.position.x);put(actor_base+0x3c,actor.position.y);put(actor_base+0x40,actor.position.z);
    for(unsigned slot=0;slot<5;++slot){const auto marker=output.actual.actor_archive_marker(std::uint8_t(slot));check(marker.status==s::StreamStatus::completed);memory[0x4bae71+slot]=std::uint8_t(marker.value);}
    for(unsigned i=0;i<3;++i){const auto at=0x2b8d70+24*i;const auto& channel=state.channels[i];memory[at]=std::uint8_t(channel.paused);memory[at+1]=channel.type;memory[at+2]=channel.start_wait;memory[at+3]=channel.started;put(at+4,channel.current);put(at+8,channel.maximum);put(at+12,channel.step);put(at+16,channel.level);put(at+20,channel.target);put(0x4bae24+4*i,state.requested_ids[i]);put(0x2b8dc8+4*i,0x610000u+256*i);}
    put(0x20f3c4,output.tick);
}
void compare_original(const s::StreamChannelSnapshot& state,const Output& output,const w::ActorVoiceResult& result){
    R5900Context context;PS2Runtime runtime;context.pc=0x1ba250;SET_GPR_U32(&context,4,actor_base);SET_GPR_U32(&context,5,27);SET_GPR_S32(&context,6,original_member);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000&&GPR_S32(&context,2)==result.original_return);
    for(unsigned i=0;i<3;++i){const auto at=0x2b8d70+24*i;const auto& channel=state.channels[i];check(std::int8_t(memory[at])==channel.paused&&memory[at+1]==channel.type&&memory[at+2]==channel.start_wait&&memory[at+3]==channel.started);check(get<std::int32_t>(at+4)==channel.current&&get<std::int32_t>(at+8)==channel.maximum&&get<unsigned>(at+12)==std::bit_cast<unsigned>(channel.step)&&get<unsigned>(at+16)==std::bit_cast<unsigned>(channel.level)&&get<std::int32_t>(at+20)==channel.target&&get<std::int32_t>(0x4bae24+4*i)==state.requested_ids[i]);}
    if(output.events!=original_events){std::cerr<<"events native="<<output.events.size()<<" original="<<original_events.size()<<'\n';for(unsigned i=0;i<std::min(output.events.size(),original_events.size());++i)if(output.events[i]!=original_events[i]){std::cerr<<"event index="<<i<<" kind="<<output.events[i].kind<<"/"<<original_events[i].kind<<'\n';break;}}
    check(output.events==original_events);++original_cases;
}
