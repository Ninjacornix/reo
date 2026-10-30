#pragma once
#include "../../runtime/audio/host_bridge.h"

extern void sub_00133490_0x133490(uint8_t*,R5900Context*,PS2Runtime*);
namespace reo::audio {
inline void (*originalFrame)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
inline void frame(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x19f6c0u) poll();
    originalFrame(ram,ctx,runtime);
}
inline void startStream(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x133490u) {
        const uint32_t adxt=GPR_U32(ctx,4)&0x1fffffffu;
        uint32_t rna=0,handle=0;
        if(adxt && adxt<PS2_RAM_SIZE-0x10) std::memcpy(&rna,ram+adxt+0xc,4);
        rna&=0x1fffffffu;
        if(rna && rna<PS2_RAM_SIZE-0x24) std::memcpy(&handle,ram+rna+0x20,4);
        if(handle) {
            const auto afs=GPR_U32(ctx,5),member=GPR_U32(ctx,6),bus=streamBus(afs);
            routeStream(handle,bus);
            static unsigned reports=0;
            if(reports++<64) std::fprintf(stderr,"[AUDIO-STREAM-1] handle=%08x afs=%u member=%u bus=%u\n",handle,afs,member,bus);
        }
    }
    sub_00133490_0x133490(ram,ctx,runtime);
}
inline void install(PS2Runtime& runtime) {
    initialize();
    originalFrame=runtime.lookupFunction(0x19f6c0u);
    if(!originalFrame || originalFrame==frame) throw std::runtime_error("Audio controls frame service unavailable");
    runtime.registerFunction(0x19f6c0u,frame);
    runtime.registerFunction(0x133490u,startStream);
    std::fprintf(stderr,"[AUDIO-MIXER-1] master,music,sfx,voice,ui\n");
}
}
