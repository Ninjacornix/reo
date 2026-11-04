#pragma once
#include <array>
#include <atomic>
#include <cstdint>

namespace reo::audio {
enum Bus : unsigned { Master, Music, Sfx, Voice, Ui, Count };
constexpr uint32_t magic=0x52454f41u, version=1;
using Levels=std::array<uint32_t,Count>;
constexpr Levels defaults{100,100,100,100,100};
constexpr bool valid(const Levels& levels) {
    for(auto value:levels) if(value>100) return false;
    return true;
}
constexpr uint64_t pack(const Levels& levels) {
    uint64_t result=0;
    for(unsigned i=0;i<Count;++i) result|=uint64_t(levels[i])<<(i*7);
    return result;
}
inline std::atomic<uint64_t> current{pack(defaults)};
inline std::array<std::atomic<uint64_t>,64> streamRoutes{};
inline void publish(const Levels& levels) {
    if(valid(levels)) current.store(pack(levels),std::memory_order_relaxed);
}
inline float gain(unsigned bus) {
    return bus<Count ? float((current.load(std::memory_order_relaxed)>>(bus*7))&127u)/100.f : 1.f;
}
inline unsigned streamBus(unsigned afs) {
    if(afs==0) return Music;
    if(afs==1 || (afs>=5 && afs<=8)) return Voice;
    if(afs==2) return Count; // Movie sound is already mixed; Master controls it.
    if(afs==4) return Sfx;
    return Count; // Mixed cinematics and unknown streams follow Master only.
}
constexpr uint64_t startVoiceBank=0xa402cd5907c716a7ull;
constexpr uint64_t file2StartVoiceBank=0x2b5c216e4d0bfbd7ull;
constexpr unsigned bankBusFor(unsigned port,unsigned sequence,uint64_t fingerprint,uint64_t selectionBank) {
    if(port==0) return Ui;
    if(port>=4 && port<=7) return Voice;
    if(port==12 && fingerprint==selectionBank) return Voice;
    // NPC banks also carry their firearm cues.
    if(port==13 && sequence!=6 && sequence!=8 && sequence!=9) return Voice;
    return Sfx;
}
constexpr unsigned bankBus(unsigned port,unsigned sequence,uint64_t fingerprint) {
    return bankBusFor(port,sequence,fingerprint,startVoiceBank);
}
constexpr unsigned file2BankBus(unsigned port,unsigned sequence,uint64_t fingerprint) {
    // SLUS-20984: 144440 player voices, 144500 weapon/NPC exceptions,
    // 144AD0 enemy port. Selection speech uses File #2's own start.snd header.
    return bankBusFor(port,sequence,fingerprint,file2StartVoiceBank);
}
inline void routeStream(uint32_t handle,unsigned bus) {
    if(!handle || bus>Count) return;
    const uint64_t value=(uint64_t(handle)<<8)|(bus+1u);
    for(auto& entry:streamRoutes) {
        const auto old=entry.load(std::memory_order_relaxed);
        if(!old || uint32_t(old>>8)==handle) {entry.store(value,std::memory_order_relaxed);return;}
    }
    // Bounded storage; replacing an old handle cannot grow callback work.
    streamRoutes[(handle>>6)%streamRoutes.size()].store(value,std::memory_order_relaxed);
}
inline float streamGain(uint32_t handle) {
    for(const auto& entry:streamRoutes) {
        const auto value=entry.load(std::memory_order_relaxed);
        if(value && uint32_t(value>>8)==handle) return gain(unsigned(value&255u)-1u);
    }
    return 1.f;
}
// A seqlock update must be complete and validated before it can affect audio.
inline bool accept(const std::array<uint32_t,8>& words,uint32_t after) {
    if(words[0]!=magic || words[1]!=version || (words[2]&1) || words[2]!=after) return false;
    Levels levels{};
    for(unsigned i=0;i<Count;++i) levels[i]=words[3+i];
    if(!valid(levels)) return false;
    publish(levels);return true;
}
}
