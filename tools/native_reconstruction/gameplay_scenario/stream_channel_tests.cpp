#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "game/native/gameplay_scenario/stream_channels.hpp"
#include <array>
#include <iostream>
#include <tuple>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace {
std::size_t checks{},calls{};std::string context;
void check(bool ok){++checks;if(!ok)throw std::runtime_error("Stream channel check "+std::to_string(checks)+" "+context);}
using Effect=std::tuple<unsigned,unsigned,std::int32_t,std::int32_t,std::int32_t,std::int8_t,std::int32_t,std::uint32_t>;
std::vector<Effect> original_effects;std::array<std::int32_t,3> phases;vm::StreamFeatureGates gates;
void done(R5900Context* c,std::int32_t value=0){SET_GPR_S32(c,2,value);c->pc=GPR_U32(c,31);}
std::uint8_t channel(R5900Context* c){const auto value=GPR_U32(c,4);check(value>=0x600000&&value<0x600300&&(value-0x600000)%256==0);return std::uint8_t((value-0x600000)/256);}
void observe(std::uint8_t* r,unsigned kind,unsigned index,std::int32_t a=0,std::int32_t b=0){const auto at=0x2b8d70+24*index;
 original_effects.emplace_back(kind,index,a,b,index<3?fixture_read<std::int32_t>(r,0x4bae24+4*index):0,index<3?std::bit_cast<std::int8_t>(r[at]):0,index<3?fixture_read<std::int32_t>(r,at+4):0,index<3?fixture_read<std::uint32_t>(r,at+12):0);
}
struct Backend final:vm::StreamBackend {
 vm::StreamChannels* owner{};std::vector<Effect> effects;vm::StreamStatus status{vm::StreamStatus::completed};
 void event(unsigned kind,unsigned index,std::int32_t a=0,std::int32_t b=0){const auto& s=owner->snapshot();effects.emplace_back(kind,index,a,b,index<3?s.requested_ids[index]:0,index<3?s.channels[index].paused:0,index<3?s.channels[index].current:0,index<3?std::bit_cast<std::uint32_t>(s.channels[index].step):0);}
 vm::StreamValue phase(std::uint8_t c)noexcept override{event(0,c);return{status,phases[c]};}
 vm::StreamStatus start(std::uint8_t c,vm::StreamRequest r,std::uint32_t)noexcept override{event(1,c,std::bit_cast<std::int32_t>(r.archive),r.member);return status;}
 vm::StreamStatus stop(std::uint8_t c)noexcept override{event(2,c);return status;}
 vm::StreamStatus pause(std::uint8_t c,bool p,std::uint32_t)noexcept override{event(3,c,p?1:0);return status;}
 vm::StreamStatus attenuation(std::uint8_t c,std::int32_t a)noexcept override{event(4,c,a);return status;}
 vm::StreamStatus service(std::uint32_t)noexcept override{event(5,3);return status;}
};
void export_state(std::vector<std::uint8_t>& r,const vm::StreamChannelSnapshot& s){
 for(unsigned i=0;i<3;++i){const auto at=0x2b8d70+24*i;const auto& c=s.channels[i];r[at]=std::uint8_t(c.paused);r[at+1]=c.type;r[at+2]=c.start_wait;r[at+3]=c.started;
  fixture_write(r.data(),at+4,c.current);fixture_write(r.data(),at+8,c.maximum);fixture_write(r.data(),at+12,std::bit_cast<std::uint32_t>(c.step));fixture_write(r.data(),at+16,std::bit_cast<std::uint32_t>(c.level));fixture_write(r.data(),at+20,c.target);
  fixture_write(r.data(),0x4bae24+4*i,s.requested_ids[i]);fixture_write<std::uint32_t>(r.data(),0x2b8dc8+4*i,0x600000+256*i);
 }
 r[0x3243ff]=s.loading?1:0;std::memcpy(r.data()+0x234060,original_curve.data(),512);
}
void compare(const std::vector<std::uint8_t>& r,const vm::StreamChannelSnapshot& s){
 for(unsigned i=0;i<3;++i){const auto at=0x2b8d70+24*i;const auto& c=s.channels[i];check(r[at]==std::uint8_t(c.paused));check(r[at+1]==c.type);check(r[at+2]==c.start_wait);check(r[at+3]==c.started);
  check(fixture_read<std::int32_t>(r.data(),at+4)==c.current);check(fixture_read<std::int32_t>(r.data(),at+8)==c.maximum);check(fixture_read<std::uint32_t>(r.data(),at+12)==std::bit_cast<std::uint32_t>(c.step));check(fixture_read<std::uint32_t>(r.data(),at+16)==std::bit_cast<std::uint32_t>(c.level));check(fixture_read<std::int32_t>(r.data(),at+20)==c.target);check(fixture_read<std::int32_t>(r.data(),0x4bae24+4*i)==s.requested_ids[i]);
 }
 check(r[0x3243ff]==(s.loading?1:0));
}
std::int32_t original(PS2Runtime::Function f,std::vector<std::uint8_t>& r,unsigned channel,std::int32_t a,std::int32_t b){R5900Context c;PS2Runtime rt;SET_GPR_U32(&c,4,channel);SET_GPR_S32(&c,5,a);SET_GPR_S32(&c,6,b);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);f(r.data(),&c,&rt);check(c.pc==0xdeadbeef);++calls;return GPR_S32(&c,2);}
}
void sub_00131E38_0x131e38(std::uint8_t* r,R5900Context* c,PS2Runtime*){observe(r,2,channel(c));done(c);}
void sub_00131EF8_0x131ef8(std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto i=channel(c);observe(r,0,i);done(c,phases[i]);}
void sub_001327B8_0x1327b8(std::uint8_t* r,R5900Context* c,PS2Runtime*){observe(r,4,channel(c),GPR_S32(c,5));done(c);}
void sub_00132E50_0x132e50(std::uint8_t* r,R5900Context* c,PS2Runtime*){observe(r,3,channel(c),GPR_S32(c,5));done(c);}
void sub_00133490_0x133490(std::uint8_t* r,R5900Context* c,PS2Runtime*){observe(r,1,channel(c),GPR_S32(c,5),GPR_S32(c,6));done(c);}
void sub_001B82A0_0x1b82a0(std::uint8_t*,R5900Context* c,PS2Runtime*){done(c,GPR_U32(c,4)==14?gates.suppress_all:GPR_U32(c,4)==10?gates.suppress_channel_zero:0);}
void sub_0012BEF8_0x12bef8(std::uint8_t* r,R5900Context* c,PS2Runtime*){observe(r,5,3);done(c);}
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at)const{switch(at){
#include "original_lookup.inc"
default:throw std::runtime_error("Unexpected stream dependency "+std::to_string(at));}}
int main()try{
 check(vm::file1_stream_gain_curve()==original_curve);std::vector<std::uint8_t> ram(0x800000);std::uint32_t seed=0x48239fa7;
 constexpr std::array<PS2Runtime::Function,9> funcs{sub_001ADFD0_0x1adfd0,sub_001AE0C0_0x1ae0c0,sub_001AE3F0_0x1ae3f0,sub_001ADF00_0x1adf00,sub_001ADF50_0x1adf50,sub_001ADA20_0x1ada20,sub_001BA170_0x1ba170,sub_001AE190_0x1ae190,sub_001AE4B0_0x1ae4b0};
 constexpr std::array<std::uint32_t,8> floats{0,0x80000000u,0x3e800000u,0x3f800000u,0x40000000u,0x42fe0000u,0x43a18000u,0x00000001u};
 constexpr std::array<std::uint32_t,8> steps{0,0x80000000u,0x3e800000u,0xbf800000u,0x40000000u,0x42fe0000u,0xc2fe0000u,0x00000001u};
 constexpr std::array<std::int32_t,7> levels{0,1,8,63,127,128,323};
 constexpr std::array<std::int32_t,9> integers{-2147483647-1,-128,-1,0,1,8,63,127,2147483647};
 for(unsigned i=0;i<2048;++i){seed=seed*1664525u+1013904223u;vm::StreamChannelSnapshot initial;initial.loading=(i&1)!=0;gates={bool(i&4),bool(i&8)};
  for(unsigned j=0;j<3;++j){auto& c=initial.channels[j];c.paused=std::int8_t((i+j)%5==0?0:(i+j)%5==1?1:(i+j)%5==2?255:(i+j)%5==3?128:127);c.type=std::uint8_t(j==2?1:2);c.start_wait=std::uint8_t(i+j);c.started=std::uint8_t(seed);c.current=levels[(i+j)%levels.size()];c.maximum=levels[(i*3+j)%levels.size()];c.target=integers[(i*7+j)%integers.size()];c.level=std::bit_cast<float>(floats[(i+j)%floats.size()]);c.step=std::bit_cast<float>(steps[(i*3+j)%steps.size()]);initial.requested_ids[j]=i%3?std::bit_cast<std::int32_t>(seed):42;phases[j]=std::int32_t((i+j)%8)-1;}
  const auto channel=std::uint8_t(i%3);const auto a=i%3?integers[i%integers.size()]:42;const auto b=integers[(i/3)%integers.size()];
  for(unsigned op=0;op<funcs.size();++op){context="i="+std::to_string(i)+" op="+std::to_string(op);vm::StreamChannels state(original_curve);check(state.restore(initial)==vm::StreamStatus::completed);state.features(gates);Backend backend;backend.owner=&state;backend.effects.reserve(20);export_state(ram,initial);original_effects.clear();original_effects.reserve(20);
   const auto returned=original(funcs[op],ram,channel,a,b);vm::StreamStatus status{};std::int32_t native_return=0;
   switch(op){case 0:status=state.level(channel,a,backend);break;case 1:status=state.maximum(channel,a,backend);break;case 2:status=state.ramp(channel,a,b);break;case 3:status=state.pause(channel,1234,backend);break;case 4:status=state.resume_current(channel,1234,backend);break;
   case 5:{const auto result=state.start(channel,a,b,1234,backend);status=result.status;native_return=result.original_return;break;}
   case 6:{const auto result=state.request(channel,a,b,1234,backend);status=result.status;native_return=result.original_return;break;}
   case 7:status=state.stop(channel,backend);break;case 8:status=state.service(1234,backend);break;}
   check(status==vm::StreamStatus::completed);if(op!=8&&op!=2)check(returned==native_return);
   for(unsigned j=0;j<3;++j){const auto observed=fixture_read<std::uint32_t>(ram.data(),0x2b8d70+24*j+12),native=std::bit_cast<std::uint32_t>(state.snapshot().channels[j].step);
       if(observed!=native)throw std::runtime_error(context+" stepchannel="+std::to_string(j)+" original="+std::to_string(observed)+" native="+std::to_string(native));}
   compare(ram,state.snapshot());check(backend.effects==original_effects);
  }
 }
 vm::StreamChannels state(original_curve);Backend backend;backend.owner=&state;check(state.level(3,7,backend)==vm::StreamStatus::invalid_channel);check(state.start(255,1,0,0,backend).status==vm::StreamStatus::invalid_channel);check(state.request(3,1,0,0,backend).status==vm::StreamStatus::invalid_channel);check(state.stop(3,backend)==vm::StreamStatus::invalid_channel);check(state.ramp(3,0,0)==vm::StreamStatus::invalid_channel);check(backend.effects.empty());
 for(unsigned kind=0;kind<5;++kind){vm::StreamChannelSnapshot rejected;auto& c=rejected.channels[0];if(kind==0)c.maximum=-1;if(kind==1)c.maximum=324;if(kind==2)c.level=std::bit_cast<float>(0x7fc12345u);if(kind==3)c.level=-1;if(kind==4)c.step=std::bit_cast<float>(0x7f800000u);check(state.restore(rejected)==vm::StreamStatus::unsupported_profile);check(state.snapshot().channels[0].maximum==0);}
 {vm::StreamChannelSnapshot outlier;outlier.channels[0].maximum=127;outlier.channels[0].level=std::bit_cast<float>(0x7f7fffffu);outlier.channels[0].step=std::bit_cast<float>(0x7f7fffffu);check(state.restore(outlier)==vm::StreamStatus::completed);check(state.service(1234,backend)==vm::StreamStatus::unsupported_profile);check(backend.effects.empty());check(state.snapshot().channels[0].level==outlier.channels[0].level);}
 std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<calls<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
