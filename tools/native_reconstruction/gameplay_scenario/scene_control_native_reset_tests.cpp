#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "game/native/gameplay_scenario/scene_controls.hpp"
#include <array>
#include <iostream>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace {
std::size_t checks{},calls{};
void check(bool ok){++checks;if(!ok)throw std::runtime_error("Native scene reset "+std::to_string(checks));}
constexpr std::uint32_t node=0x500000;
void export_record(std::uint8_t* ram,const vm::SceneControl& record){const auto& v=std::get<vm::ControlTypeFive>(record.body);ram[node+0x3c]=record.enabled;
 fixture_write(ram,node+0x50,v.selector);fixture_write(ram,node+0x52,v.reset_sentinel);fixture_write(ram,node+0x56,v.secondary_parameter);ram[node+0x58]=v.byte_parameter;ram[node+0x59]=v.reset_byte_a;
 fixture_write(ram,node+0x6a,v.duration);fixture_write(ram,node+0x6c,v.countdown);ram[node+0x6e]=v.reset_byte_b;fixture_write(ram,node+0x74,v.completion);
}
void call(PS2Runtime::Function f,std::vector<std::uint8_t>& ram,std::uint32_t argument){R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,argument);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);f(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++calls;}
}
int main()try{
 std::vector<std::uint8_t> ram(0x800000),expected(0x800000);vm::SceneControls owner;const auto id=*owner.append({42,0,vm::ControlTypeFive{}});std::uint32_t seed=0xa1348b72;
 constexpr std::array<PS2Runtime::Function,4> funcs{o2_005C45C0_0x5c45c0,o2_0068E920_0x68e920,o2_0068E9E0_0x68e9e0,o2_0068EA70_0x68ea70};
 for(unsigned i=0;i<4096;++i){seed=seed*1664525u+1013904223u;vm::ControlTypeFive five;five.selector=std::uint16_t(seed);five.duration=std::uint16_t(seed>>16);five.countdown=std::uint16_t(seed^0x8173);five.secondary_parameter=std::uint16_t(seed+7);five.completion=seed;five.byte_parameter=std::uint8_t(seed>>24);five.reset_sentinel=std::uint16_t(seed>>8);five.reset_byte_a=std::uint8_t(seed);five.reset_byte_b=std::uint8_t(seed>>16);
  const vm::SceneControl initial{42,std::uint8_t(seed>>8),five};
  for(unsigned mode=0;mode<4;++mode){check(owner.replace(id,initial)==vm::ControlStatus::completed);std::fill(ram.begin()+node,ram.begin()+node+256,std::uint8_t(seed));ram[node+0x30]=5;fixture_write<std::uint32_t>(ram.data(),node+0x40,42);fixture_write<std::uint32_t>(ram.data(),node+0x28,0);export_record(ram.data(),initial);
   std::copy(ram.begin()+node,ram.begin()+node+256,expected.begin()+node);fixture_write<std::int16_t>(ram.data(),0x3b5150,-1);fixture_write(ram.data(),0x3b5160,node);
   fixture_write<std::uint32_t>(ram.data(),0x10000,42);fixture_write(ram.data(),0x10004,seed);fixture_write(ram.data(),0x10008,seed^0xffffffffu);fixture_write<std::uint16_t>(ram.data(),0x1000c,std::uint16_t(seed+0x1234));call(funcs[mode],ram,mode?0x10000:node);
   if(!mode)check(owner.reset_five(id)==vm::ControlStatus::completed);
   else check(owner.apply(mode==1?vm::ControlCommand::restart_five:mode==2?vm::ControlCommand::reset_five:vm::ControlCommand::restart_five_byte,{42,seed,seed^0xffffffffu,std::uint16_t(seed+0x1234)},nullptr).status==vm::ControlStatus::completed);
   export_record(expected.data(),*owner.get(id));check(std::memcmp(ram.data()+node,expected.data()+node,256)==0);
  }
 }
 check(owner.reset_five({})==vm::ControlStatus::invalid_identity);vm::SceneControls other;check(other.reset_five(id)==vm::ControlStatus::invalid_identity);check(owner.replace(id,{42,0,vm::ControlTypeZero{}})==vm::ControlStatus::completed);check(owner.reset_five(id)==vm::ControlStatus::invalid_profile);owner.erase(id);check(owner.reset_five(id)==vm::ControlStatus::invalid_identity);
 std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<calls<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
