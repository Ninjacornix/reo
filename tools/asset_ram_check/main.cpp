#include "ps2_runtime.h"
#include "runtime/ps2_memory.h"
#include "Kernel/Stubs/LibC.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

int main() {
    unsigned checks=0;
    auto check=[&](bool ok) { ++checks; if(!ok) throw std::runtime_error("asset RAM integration check failed"); };
    PS2Runtime runtime;
    auto& memory=runtime.memory();
    check(memory.initialize(2u*PS2_RAM_SIZE));
    check(PS2_RAM_SIZE==0x2000000u && ps2RamBackingBytes==0x4000000u);
    memory.write32(0x1000,0xaabbccdd);
    memory.write32(0x2001000,0x11223344);
    for(uint32_t alias:{0u,0x20000000u,0x80000000u,0xa0000000u}) {
        check(memory.read32(alias+0x2001000)==0x11223344);
        check(memory.read32(alias+0x1000)==0xaabbccdd);
    }
    const auto quad=_mm_set_epi32(44,33,22,11);
    memory.write128(0x2001000,quad);
    auto read=memory.read128(0x2001000);
    check(std::memcmp(&read,&quad,16)==0);
    memory.writeIORegister(0x1000d410,0x2001000);
    memory.writeIORegister(0x1000d420,1);
    memory.writeIORegister(0x1000d480,0x200);
    memory.writeIORegister(0x1000d400,0x100);
    check(std::memcmp(memory.getScratchpad()+0x200,&quad,16)==0);
    memory.writeIORegister(0x1000d010,0x2002000);
    memory.writeIORegister(0x1000d020,1);
    memory.writeIORegister(0x1000d080,0x200);
    memory.writeIORegister(0x1000d000,0x100);
    read=memory.read128(0x2002000);
    check(std::memcmp(&read,&quad,16)==0);
    R5900Context context{};
    read=runtime.Load128(memory.getRDRAM(),&context,0x70000200);
    check(std::memcmp(&read,&quad,16)==0);
    context.r[4]=_mm_set_epi64x(0,0x2003000);
    context.r[5]=_mm_set_epi64x(0,0x2002000);
    context.r[6]=_mm_set_epi64x(0,16);
    ps2_stubs::memcpy(memory.getRDRAM(),&context,&runtime);
    read=memory.read128(0x2003000);
    check(std::memcmp(&read,&quad,16)==0);
    check(memory.read32(0x1000)==0xaabbccdd && memory.read32(0x2000)==0 && memory.read32(0x3000)==0);
    check(!memory.initialize(3u*PS2_RAM_SIZE/2));
    check(ps2RamBackingBytes==2u*PS2_RAM_SIZE);
    check(memory.initialize());
    check(ps2RamBackingBytes==PS2_RAM_SIZE);
    std::cout<<"PASS native asset RAM: "<<checks<<" CPU, alias, DMA, libc and reset checks\n";
}
