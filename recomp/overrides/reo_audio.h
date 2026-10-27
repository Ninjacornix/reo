#pragma once
#include "../../runtime/audio/mixer.h"
#include <charconv>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#ifdef _WIN32
// Minimal Win32 headers need the architecture macro windows.h would define
// (llvm-mingw derives it itself; the Windows SDK headers do not).
#if (defined(_M_X64) || defined(__x86_64__)) && !defined(_AMD64_)
#define _AMD64_
#endif
#include <minwindef.h>
#include <winnt.h>
#include <memoryapi.h>
#include <handleapi.h>
#endif

// Private bridge used by the two host audio mixers. No guest volumes, resource
// structures, scheduling or playback cursors are changed by these controls.
float reoAudioMasterGain() { return reo::audio::gain(reo::audio::Master); }
float reoAudioStreamGain(uint32_t handle) { return reo::audio::streamGain(handle); }
void reoAudioResetStreams() {
    for(auto& entry:reo::audio::streamRoutes) entry.store(0,std::memory_order_relaxed);
}
float reoAudioBankGain(unsigned port,unsigned sequence,uint64_t fingerprint) {
    return reo::audio::gain(reo::audio::bankBus(port,sequence,fingerprint));
}

extern void sub_00133490_0x133490(uint8_t*,R5900Context*,PS2Runtime*);
namespace reo::audio {
inline void (*originalFrame)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
#ifdef _WIN32
struct Mapping {
    HANDLE handle=nullptr;
    const uint32_t* data=nullptr;
    Mapping() {
        const char* name=std::getenv("REO_AUDIO_MAP");
        if(name && *name) {
            const std::wstring wideName(name,name+std::strlen(name));
            handle=OpenFileMappingW(FILE_MAP_READ,FALSE,wideName.c_str());
            if(handle) data=static_cast<const uint32_t*>(MapViewOfFile(handle,FILE_MAP_READ,0,0,32));
        }
    }
    ~Mapping() { if(data) UnmapViewOfFile(data);if(handle) CloseHandle(handle); }
};
#endif
inline void poll() {
#ifdef _WIN32
    static Mapping map;
    if(!map.data) return;
    const uint32_t before=__atomic_load_n(map.data+2,__ATOMIC_ACQUIRE);
    if(before&1u) return;
    std::array<uint32_t,8> words{};
    for(unsigned i=0;i<8;++i) words[i]=__atomic_load_n(map.data+i,__ATOMIC_RELAXED);
    __atomic_thread_fence(__ATOMIC_ACQUIRE);
    const auto after=__atomic_load_n(map.data+2,__ATOMIC_ACQUIRE);
    const auto previous=current.load(std::memory_order_relaxed);
    if(words[2]==before && accept(words,after) && previous!=current.load(std::memory_order_relaxed) &&
       std::getenv("REO_AUDIO_DIAG"))
        std::fprintf(stderr,"[AUDIO-LEVELS-1] master=%u music=%u sfx=%u voice=%u ui=%u\n",
                     words[3],words[4],words[5],words[6],words[7]);
#endif
}
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
    if(const char* value=std::getenv("REO_AUDIO_LEVELS")) {
        const char* cursor=value;const char* end=value+std::strlen(value);Levels levels{};
        bool ok=true;
        for(unsigned i=0;i<Count;++i) {
            const auto parsed=std::from_chars(cursor,end,levels[i]);
            if(parsed.ec!=std::errc{} || (i+1<Count ? parsed.ptr==end || *parsed.ptr!=',' : parsed.ptr!=end)) {ok=false;break;}
            cursor=parsed.ptr+(i+1<Count ? 1:0);
        }
        if(ok && valid(levels)) publish(levels);
    }
    poll();
    originalFrame=runtime.lookupFunction(0x19f6c0u);
    if(!originalFrame || originalFrame==frame) throw std::runtime_error("Audio controls frame service unavailable");
    runtime.registerFunction(0x19f6c0u,frame);
    runtime.registerFunction(0x133490u,startStream);
    std::fprintf(stderr,"[AUDIO-MIXER-1] master,music,sfx,voice,ui\n");
}
}
void reoAudioPoll() { reo::audio::poll(); }
