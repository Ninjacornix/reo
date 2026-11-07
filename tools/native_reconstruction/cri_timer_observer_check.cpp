// Exact-delegation fixture for the real observer header with explicit mock
// runtime/guest calls. No game, source provider, audio device or PC sampler.
#include "observer.h"
#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace ps2_sched {
std::atomic<int64_t> g_waitNs[256]{};
int currentThread(){return 6;}
}
std::vector<unsigned> calls;
void require(bool v){if(!v)throw std::runtime_error("Timer observer delegation mismatch");}
void init_rpc(uint8_t*,R5900Context* c,PS2Runtime*){calls.push_back(11);c->regs[2]=101;}
void call_rpc(uint8_t*,R5900Context* c,PS2Runtime*){calls.push_back(12);c->regs[2]=102;}
void sub_00138208_0x138208(uint8_t*,R5900Context* c,PS2Runtime*){calls.push_back(13);c->regs[2]=103;}
void sub_00137D80_0x137d80(uint8_t* m,R5900Context* c,PS2Runtime* r){
    calls.push_back(3);
    reo_cri_server::hle<init_rpc,0>(m,c,r);
    c->regs[4]=0x1700;reo_cri_server::marker(m,c,r);
    reo_cri_server::hle<call_rpc,1>(m,c,r);
    c->regs[4]=0x1701;reo_cri_server::marker(m,c,r);
}
void sub_00141E20_0x141e20(uint8_t* m,R5900Context* c,PS2Runtime* r){
    calls.push_back(1);reo_cri_server::step<sub_00137D80_0x137d80>(m,c,r);c->regs[2]=0x12345;
}
#define LEAF(name,tag) void name(uint8_t*,R5900Context* c,PS2Runtime*){calls.push_back(tag);c->regs[2]=tag;}
LEAF(sub_00130D48_0x130d48,20)
LEAF(sub_00135EF0_0x135ef0,21)
LEAF(sub_00129A60_0x129a60,22)
LEAF(sub_001640D8_0x1640d8,23)
LEAF(sub_001724C8_0x1724c8,24)
LEAF(sub_00163738_0x163738,25)
LEAF(sub_00164270_0x164270,26)
LEAF(sub_0013ED28_0x13ed28,27)
LEAF(sub_00138650_0x138650,28)
LEAF(sub_00139568_0x139568,29)
LEAF(sub_0012D678_0x12d678,30)
LEAF(sub_00134C58_0x134c58,31)
LEAF(sub_0012C798_0x12c798,32)
#undef LEAF
int main(){try{
    std::vector<uint8_t> ram(PS2_RAM_SIZE);R5900Context c{};PS2Runtime runtime;
    const auto store=[&](uint32_t at,uint32_t value){std::memcpy(ram.data()+at,&value,4);};
    store(0x141e20,0x00041040);store(0x141e24,0x27bdffc0);store(0x141e28,0x00441021);store(0x141e2c,0xffb40020);store(0x20f390,3);
    c.regs[4]=4;reo_cri_server::dispatch(ram.data(),&c,&runtime);
    const std::vector<unsigned> expected{1,3,11,13,12,13};require(calls==expected && c.regs[2]==0x12345);
    // The same body with observation enabled must delegate every child once,
    // preserve its guest result and clear scoped observer state after return.
    reo_cri_server::threshold_ns=1;reo_cri_server::ram=ram.data();calls.clear();c={};c.regs[4]=4;
    reo_cri_server::dispatch(ram.data(),&c,&runtime);
    require(calls==expected && c.regs[2]==0x12345 && !reo_cri_server::in_dispatch && !reo_cri_server::in_step3);
    require(reo_cri_server::hle_calls[0]==1 && reo_cri_server::hle_calls[1]==1 && reo_cri_server::mark_count==3);
    require(reo_cri_server::marks[0].code==0x1700 && reo_cri_server::marks[1].code==0x1701 && reo_cri_server::marks[2].code==0xffffffff);
    require(reo_cri_server::reports==1);
    calls.clear();c.regs[4]=8;reo_cri_server::dispatch(ram.data(),&c,&runtime);
    require(calls==expected && reo_cri_server::reports==1); // Unadmitted group.
    calls.clear();reo_cri_server::part<sub_001640D8_0x1640d8,0>(ram.data(),&c,&runtime);
    require(calls==std::vector<unsigned>{23} && c.regs[2]==23);
    reo_cri_server::in_dispatch=true;reo_cri_server::dispatch_id=6;calls.clear();
    reo_cri_server::part<sub_001640D8_0x1640d8,0>(ram.data(),&c,&runtime);
    require(calls==std::vector<unsigned>{23} && reo_cri_server::part_calls[0]==1 && c.regs[2]==23);
    std::cout<<"Owner-thread CRI timer delegation checks passed\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
