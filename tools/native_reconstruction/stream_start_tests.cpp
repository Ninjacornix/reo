#include "game/native/gameplay_scenario/stream_channels.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;
struct Event {unsigned channel{};std::int32_t value{};bool stopped{};friend bool operator==(const Event&,const Event&)=default;};
std::vector<Event> source_events,native_events;std::uint64_t checks{},calls{},cases{};unsigned seed{},method_case{},channel_case{};
void check(bool ok,std::source_location where=std::source_location::current()){++checks;if(!ok)throw std::runtime_error("stream start seed "+std::to_string(seed)+" method "+std::to_string(method_case)+" channel "+std::to_string(channel_case)+" line "+std::to_string(where.line()));}
template<class T>void put(std::uint8_t* m,unsigned at,T value){transform_write(m,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
case 0x131e38:source_events.push_back({(GPR_U32(context,4)-0x10000u)/256,0,true});break;
case 0x1327b8:source_events.push_back({(GPR_U32(context,4)-0x10000u)/256,GPR_S32(context,5),false});break;
default:throw std::runtime_error("undeclared stream start call "+std::to_string(context->pc));
}SET_GPR_U32(context,2,0);context->pc=GPR_U32(context,31);}
std::int32_t invoke(std::uint8_t* memory,unsigned pc,unsigned index){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,index);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);
check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);return GPR_S32(&context,2);}
struct Legacy:s::StreamBackend {
 s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
 s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
struct Backend final:Legacy {
 std::array<bool,3> available{};std::array<std::int8_t,3> ready{};std::array<std::uint8_t,3> inhibit{};
 s::StreamValue instance_available(std::uint8_t index)noexcept override{return{s::StreamStatus::completed,available[index]?1:0};}
 s::StreamValue start_ready(std::uint8_t index)noexcept override{return{s::StreamStatus::completed,ready[index]};}
 s::StreamStatus start_inhibit(std::uint8_t index,bool value)noexcept override{inhibit[index]=value?1:0;return s::StreamStatus::completed;}
 s::StreamStatus stop(std::uint8_t index)noexcept override{native_events.push_back({index,0,true});return s::StreamStatus::completed;}
 s::StreamStatus attenuation(std::uint8_t index,std::int32_t value)noexcept override{native_events.push_back({index,value,false});return s::StreamStatus::completed;}
};
void project(std::uint8_t* memory,const s::StreamChannels& channels,const Backend& backend){for(unsigned i=0;i<3;++i){const auto& c=channels.snapshot().channels[i];const unsigned at=0x2b8d70+24*i,handle=0x10000+256*i;put(memory,at,c.paused);put(memory,at+1,c.type);put(memory,at+2,c.start_wait);put(memory,at+3,c.started);put(memory,at+4,c.current);put(memory,at+8,c.maximum);put(memory,at+12,c.step);put(memory,at+16,c.level);put(memory,at+20,c.target);put(memory,0x2b8dc8+4*i,backend.available[i]?handle:0u);put(memory,handle+0x70,backend.inhibit[i]);put(memory,handle+0x71,backend.ready[i]);}}
void compare(std::uint8_t* memory,const s::StreamChannels& channels,const Backend& backend){for(unsigned i=0;i<3;++i){const auto& c=channels.snapshot().channels[i];const unsigned at=0x2b8d70+24*i,handle=0x10000+256*i;
check(c.paused==transform_read<std::int8_t>(memory,at));
check(c.type==memory[at+1]&&c.start_wait==memory[at+2]&&c.started==memory[at+3]);
if(c.current!=transform_read<std::int32_t>(memory,at+4))std::cerr<<"current "<<c.current<<","<<transform_read<std::int32_t>(memory,at+4)<<" index "<<i<<"\n";
check(c.current==transform_read<std::int32_t>(memory,at+4)&&c.maximum==transform_read<std::int32_t>(memory,at+8)&&c.target==transform_read<std::int32_t>(memory,at+20));
check(std::bit_cast<unsigned>(c.step)==transform_read<unsigned>(memory,at+12)&&std::bit_cast<unsigned>(c.level)==transform_read<unsigned>(memory,at+16));
check(backend.inhibit[i]==memory[handle+0x70]);}
check(native_events==source_events);}
int main()try{const auto previous=_mm_getcsr();struct Reset{unsigned previous;~Reset(){_mm_setcsr(previous);}}reset{previous};_mm_setcsr(0x1f80);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());s::StreamChannels channels(s::file1_stream_gain_curve());Backend backend;
 for(seed=0;seed<8192;++seed)for(unsigned channel=0;channel<3;++channel)for(unsigned method=0;method<3;++method){s::StreamChannelSnapshot state;for(unsigned i=0;i<3;++i){auto& c=state.channels[i];c.paused=std::bit_cast<std::int8_t>(std::uint8_t(seed+i));c.type=std::uint8_t(seed/3+i);c.start_wait=std::uint8_t(seed/7+i);c.started=std::array<std::uint8_t,4>{0,1,128,255}[(seed/5+i)%4];c.current=std::int32_t((seed*17+i)%324);c.maximum=std::int32_t((seed*23+i)%324);c.target=std::int32_t(seed*29+i);c.level=float(c.current);c.step=float(int(seed%17)-8)*.25f;backend.available[i]=(seed+i)%7!=0;backend.ready[i]=std::bit_cast<std::int8_t>(std::uint8_t(seed+i));backend.inhibit[i]=std::uint8_t(seed/11+i);}
check(channels.restore(state)==s::StreamStatus::completed);project(memory.data(),channels,backend);native_events.clear();source_events.clear();const auto pc=std::array<unsigned,3>{0x1ae910,0x1ae9a0,0x1aeb00}[method];method_case=method;channel_case=channel;const auto original=invoke(memory.data(),pc,channel);if(method==0){const auto result=channels.prepared_ready(std::uint8_t(channel),backend);
check(result.status==s::StreamStatus::completed&&result.value==original);}else {
check((method==1?channels.release_start(std::uint8_t(channel),backend):channels.stop_preserving_state(std::uint8_t(channel),backend))==s::StreamStatus::completed);}
compare(memory.data(),channels,backend);++cases;}
 Legacy legacy;
check(channels.prepared_ready(0,legacy).status==s::StreamStatus::unbound);
check(channels.release_start(0,legacy)==s::StreamStatus::unbound);
check(channels.stop_preserving_state(0,legacy)==s::StreamStatus::unbound);
check(channels.prepared_ready(3,backend).status==s::StreamStatus::invalid_channel);
check(channels.release_start(255,backend)==s::StreamStatus::invalid_channel);
check(channels.stop_preserving_state(255,backend)==s::StreamStatus::invalid_channel);
 std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
