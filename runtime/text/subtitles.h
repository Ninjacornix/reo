#pragma once
#include <array>
#include <atomic>
#include <cstdint>
#include <cstdlib>
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

namespace reo::subtitles {
inline constexpr uint32_t magic=0x53554254, version=1;
inline std::atomic<bool> enabled{true};
inline bool applyEnvironment(const char* value) {
    if(!value || (std::strcmp(value,"0") && std::strcmp(value,"1"))) return false;
    enabled.store(*value=='1',std::memory_order_relaxed);
    return true;
}
inline bool accept(const std::array<uint32_t,4>& words,uint32_t after) {
    if(words[0]!=magic || words[1]!=version || (after&1u) || words[2]!=after || words[3]>1) return false;
    enabled.store(words[3]!=0,std::memory_order_relaxed);
    return true;
}
#ifdef _WIN32
struct Mapping {
    HANDLE handle=nullptr;
    const uint32_t* data=nullptr;
    Mapping() {
        const char* name=std::getenv("REO_SUBTITLE_MAP");
        if(name && *name) {
            const std::wstring wide(name,name+std::strlen(name));
            handle=OpenFileMappingW(FILE_MAP_READ,FALSE,wide.c_str());
            if(handle) data=static_cast<const uint32_t*>(MapViewOfFile(handle,FILE_MAP_READ,0,0,16));
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
    const auto read=[&](unsigned i,std::memory_order order) {
        return std::atomic_ref<uint32_t>(const_cast<uint32_t&>(map.data[i])).load(order);
    };
    const auto before=read(2,std::memory_order_acquire);
    if(before&1u) return;
    std::array<uint32_t,4> words{};
    for(unsigned i=0;i<4;++i) words[i]=read(i,std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    const auto after=read(2,std::memory_order_acquire);
    if(words[2]==before) accept(words,after);
#endif
}
inline void initialize() {
    enabled.store(true,std::memory_order_relaxed);
    applyEnvironment(std::getenv("REO_SUBTITLES"));
    poll();
}
}
