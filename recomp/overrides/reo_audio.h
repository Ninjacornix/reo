#pragma once
#include "../../runtime/audio/host_bridge.h"

namespace reo::audio {
#if defined(REO_GAME_FILE2)
inline constexpr uint32_t frameAddress=0x1edcb0u,streamAddress=0x18e090u;
#else
inline constexpr uint32_t frameAddress=0x19f6c0u,streamAddress=0x133490u;
#endif
inline void (*originalFrame)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
inline void (*originalStream)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
inline void frame(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==frameAddress) poll();
    originalFrame(ram,ctx,runtime);
}
inline void startStream(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==streamAddress) {
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
    originalStream(ram,ctx,runtime);
}
inline void install(PS2Runtime& runtime) {
    initialize();
    originalFrame=runtime.lookupFunction(frameAddress);
    originalStream=runtime.lookupFunction(streamAddress);
    if(!originalFrame || originalFrame==frame) throw std::runtime_error("Audio controls frame service unavailable");
    if(!originalStream || originalStream==startStream) throw std::runtime_error("Audio controls stream service unavailable");
    runtime.registerFunction(frameAddress,frame);
    runtime.registerFunction(streamAddress,startStream);
#if defined(REO_GAME_FILE2)
    std::fprintf(stderr,"[AUDIO-MIXER-FILE2-1] master,music,sfx,voice,ui\n");
#else
    std::fprintf(stderr,"[AUDIO-MIXER-1] master,music,sfx,voice,ui\n");
#endif
}
}
