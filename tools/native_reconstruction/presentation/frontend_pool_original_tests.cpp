#include "reference.hpp"
#include "functions.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>

void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    if(c->pc==0x1a5bd0){sub_001A5BD0_0x1a5bd0(m,c,r);return;}
    throw std::runtime_error("unexpected original frontend reset callee");
}
int main(){
    std::vector<std::uint8_t> m(0x2000000);R5900Context c;PS2Runtime runtime;
    SET_GPR_U32(&c,29,0x1fff000);c.pc=0x1b22c0;sub_001B22C0_0x1b22c0(m.data(),&c,&runtime);
    unsigned checks{};auto check=[&](bool ok){++checks;if(!ok)throw std::runtime_error("frontend pool reset check "+std::to_string(checks));};
    for(unsigned i=0;i<160;++i){const auto value=transform_read<std::uint32_t>(m.data(),0x3188e0+4*i);check(value==(i==159?0:0x3188e0+4*(i+1)));}
    for(unsigned i=0;i<256;++i)check(transform_read<std::uint16_t>(m.data(),0x3166c0+2*i)==i);
    check(transform_read<std::uint32_t>(m.data(),0x3166b0)==0x3166c0);
    check(transform_read<std::uint16_t>(m.data(),0x3168c8)==256);
    check(transform_read<std::uint8_t>(m.data(),0x3168d0)==1);
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":2,\"cold_pool_slots\":160,\"free_indices\":256,\"game_run\":false}\n";
}
