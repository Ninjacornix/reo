#pragma once
#include "mixer.h"
#include <charconv>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#ifdef _WIN32
#if (defined(_M_X64) || defined(__x86_64__)) && !defined(_AMD64_)
#define _AMD64_
#endif
#include <minwindef.h>
#include <winnt.h>
#include <memoryapi.h>
#include <handleapi.h>
#endif

namespace reo::audio {
// Environment and launcher IPC use the same validated host mixer state.
inline bool applyEnvironmentLevels(const char* value) {
    if(!value) return false;
    const char* cursor=value;const char* end=value+std::strlen(value);Levels levels{};
    for(unsigned i=0;i<Count;++i) {
        const auto parsed=std::from_chars(cursor,end,levels[i]);
        if(parsed.ec!=std::errc{} || (i+1<Count ? parsed.ptr==end || *parsed.ptr!=',' : parsed.ptr!=end)) return false;
        cursor=parsed.ptr+(i+1<Count ? 1:0);
    }
    if(!valid(levels)) return false;
    publish(levels);return true;
}
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
    static_assert(std::atomic_ref<uint32_t>::is_always_lock_free);
    const auto read=[&](unsigned index,std::memory_order order) {
        // Only load from the read-only view. libc++ does not support loading
        // atomic_ref<const uint32_t>, so remove const for the reference alone.
        return std::atomic_ref<uint32_t>(const_cast<uint32_t&>(map.data[index])).load(order);
    };
    const uint32_t before=read(2,std::memory_order_acquire);
    if(before&1u) return;
    std::array<uint32_t,8> words{};
    for(unsigned i=0;i<8;++i) words[i]=read(i,std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    const auto after=read(2,std::memory_order_acquire);
    const auto previous=current.load(std::memory_order_relaxed);
    if(words[2]==before && accept(words,after) && previous!=current.load(std::memory_order_relaxed) &&
       std::getenv("REO_AUDIO_DIAG"))
        std::fprintf(stderr,"[AUDIO-LEVELS-1] master=%u music=%u sfx=%u voice=%u ui=%u\n",
                     words[3],words[4],words[5],words[6],words[7]);
#endif
}
inline void initialize() {
    applyEnvironmentLevels(std::getenv("REO_AUDIO_LEVELS"));
    poll();
}
}

// Host mixer ABI, defined once by the game's bootstrap translation unit.
// These controls do not change guest volumes, resources or playback cursors.
float reoAudioMasterGain() { return reo::audio::gain(reo::audio::Master); }
float reoAudioStreamGain(uint32_t handle) { return reo::audio::streamGain(handle); }
void reoAudioResetStreams() {
    for(auto& entry:reo::audio::streamRoutes) entry.store(0,std::memory_order_relaxed);
}
float reoAudioBankGain(unsigned port,unsigned sequence,uint64_t fingerprint) {
#if defined(REO_GAME_FILE2)
    return reo::audio::gain(reo::audio::file2BankBus(port,sequence,fingerprint));
#else
    return reo::audio::gain(reo::audio::bankBus(port,sequence,fingerprint));
#endif
}
void reoAudioPoll() { reo::audio::poll(); }
