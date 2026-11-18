#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "game/native/gameplay_scenario/scene_channels.hpp"
#include <array>
#include <iostream>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
int main()try{
 std::size_t checks=0,calls=0;const auto check=[&](bool ok){++checks;if(!ok)throw std::runtime_error("Scene channel parity "+std::to_string(checks));};
 std::vector<std::uint8_t> ram(0x800000);std::uint32_t random=0x73a621bd;
 constexpr std::array<PS2Runtime::Function,4> originals{o2_00690340_0x690340,o2_00690370_0x690370,o2_006903A0_0x6903a0,o2_006903C0_0x6903c0};
 for(unsigned i=0;i<65536;++i){random=random*1664525u+1013904223u;const auto initial=random;random=random*1664525u+1013904223u;const auto index=i<1024?i:random;
  for(unsigned op=0;op<4;++op){vm::SceneChannels state;state.restore(initial);fixture_write(ram.data(),0x4b9d0c,initial);fixture_write(ram.data(),0x10000,index);
   R5900Context ctx;PS2Runtime runtime;SET_GPR_U32(&ctx,4,0x10000);SET_GPR_U32(&ctx,31,0xdeadbeef);originals[op](ram.data(),&ctx,&runtime);++calls;check(ctx.pc==0xdeadbeef);check(GPR_U32(&ctx,2)==0);
   if(op<2)state.bit(index,op==0);else state.all(op==2);
   check(state.mask()==fixture_read<std::uint32_t>(ram.data(),0x4b9d0c));check(state.enabled(index)==bool(state.mask()&(1u<<(index&31))));
  }
 }
 std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<calls<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
