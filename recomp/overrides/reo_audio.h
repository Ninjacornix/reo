#pragma once
#include "../../runtime/audio/host_bridge.h"

// Runtime patch 0120 (Kernel/Syscalls/Helpers/CriAudio.h). Declared here so the audio
// bridge checks build without the PS2Recomp tree.
namespace ps2_cri_audio { void pauseNow(uint32_t voice, bool paused); }

namespace reo::audio {
// pauseAddress: CRI ADXT_Pause(adxt, on). It stores the flag at adxt+0x72 and, only for
// status 3 (playing) or 4 (decoding finished), sends the PS2RNA play-switch-off command.
#if defined(REO_GAME_FILE2)
inline constexpr uint32_t frameAddress=0x1edcb0u,streamAddress=0x18e090u,pauseAddress=0x18da50u;
#else
inline constexpr uint32_t frameAddress=0x19f6c0u,streamAddress=0x133490u,pauseAddress=0x132e50u;
#endif
inline void (*originalFrame)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
inline void (*originalStream)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
inline void (*originalPause)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
// The host plays behind the game, so stop requests normally drain queued PCM to keep
// speech endings (runtime patch 0118). A pause while the stream is still decoding
// (status 3) is not an ending: hardware stops at once. File #1 Decisions, Decisions
// starts its music and pauses it 16 ms later; draining that was an audible blip (#72).
inline void pause(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    const uint32_t adxt=GPR_U32(ctx,4)&0x1fffffffu,on=GPR_U32(ctx,5);
    if(ctx->pc==pauseAddress && (on==0u || on==1u) && adxt && adxt<PS2_RAM_SIZE-0x80 &&
       ram[adxt+0x72]!=on && static_cast<int8_t>(ram[adxt+1])==3) {
        uint32_t rna=0,handle=0;
        std::memcpy(&rna,ram+adxt+0xc,4);
        rna&=0x1fffffffu;
        if(rna && rna<PS2_RAM_SIZE-0x24) std::memcpy(&handle,ram+rna+0x20,4);
        if(handle) {
            ps2_cri_audio::pauseNow(handle,on==1u);
            static unsigned reports=0;
            if(reports++<64) std::fprintf(stderr,"[AUDIO-PAUSE-1] handle=%08x mid-stream %s\n",handle,on?"pause":"resume");
        }
    }
    originalPause(ram,ctx,runtime);
}
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
    originalPause=runtime.lookupFunction(pauseAddress);
    if(!originalPause || originalPause==pause) throw std::runtime_error("Audio pause service unavailable");
    runtime.registerFunction(frameAddress,frame);
    runtime.registerFunction(streamAddress,startStream);
    runtime.registerFunction(pauseAddress,pause);
#if defined(REO_GAME_FILE2)
    std::fprintf(stderr,"[AUDIO-MIXER-FILE2-1] master,music,sfx,voice,ui\n");
#else
    std::fprintf(stderr,"[AUDIO-MIXER-1] master,music,sfx,voice,ui\n");
#endif
}
}
