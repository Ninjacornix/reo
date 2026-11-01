// SPDX-License-Identifier: GPL-3.0-only
#pragma once
#include "native_netcode.h"
#include <algorithm>
#include <cmath>
#include <cstring>

namespace reo_network::native {
// Verified NTSC-U layouts; callers install only in the corresponding edition.
struct GameLayout {
    uint32_t actors, stride, local, phase, room, online, interval;
    uint16_t target, targetYaw, remaining;
};
inline constexpr GameLayout File1{0x4a5c30,0x10e0,0x4baded,0x4badd0,0x3243dc,0x3243fb,0x235f60,0xd74,0xd8c,0xd90};
inline constexpr GameLayout File2{0x4c5e10,0x1100,0x4db3ad,0x4db390,0x30095c,0x30097b,0x2412a0,0xd78,0xd90,0xd94};
template<class T> inline T read(const uint8_t* ram,uint32_t address) { T v; std::memcpy(&v,ram+address,sizeof(v)); return v; }
template<class T> inline void write(uint8_t* ram,uint32_t address,T value) { std::memcpy(ram+address,&value,sizeof(value)); }
inline bool online(const uint8_t* ram,const GameLayout& g) { return ram[g.online]==1 || ram[g.online]==2; }
inline void capture(uint8_t* ram,const GameLayout& g) {
    auto& state=runtime();
    if (!online(ram,g) || ram[g.phase]!=2 || ram[g.local]>=4 || ram[g.local+1] || ram[g.local+11]) { state.local(nullptr); return; }
    Motion m; m.slot=ram[g.local]; m.room=read<uint16_t>(ram,g.room);
    const uint32_t actor=g.actors+g.stride*m.slot;
    if (!ram[actor] || ram[actor+2] || ram[actor+3]!=m.slot || read<uint16_t>(ram,actor+0x1e2)!=m.room) {
        state.local(nullptr); return;
    }
    m.yaw=read<uint16_t>(ram,actor+0x92);
    for(size_t i=0;i<3;++i) m.xyz[i]=read<float>(ram,actor+0x38+uint32_t(i*4));
    state.local(&m);
}
inline bool correction(uint8_t* ram,const GameLayout& g,uint32_t actor) {
    if (actor<g.actors || (actor-g.actors)%g.stride || actor>=g.actors+4*g.stride || !online(ram,g) || ram[g.phase]!=2)
        return false;
    const auto slot=uint8_t((actor-g.actors)/g.stride);
    const auto room=read<uint16_t>(ram,g.room);
    if (slot==ram[g.local] || !ram[actor] || ram[actor+2] || ram[actor+3]!=slot || read<uint16_t>(ram,actor+0x1e2)!=room)
        return false;
    Motion target;
    if (!runtime().target(slot,room,nowUs(),target)) return false;
    // Feed the original target record. Its updater still checks animation states,
    // collision, authority, active/local status and scripted movement exceptions.
    for(size_t i=0;i<3;++i) {
        write(ram,actor+g.target+uint32_t(i*4),target.xyz[i]);
        write<uint32_t>(ram,actor+g.target+12+uint32_t(i*4),0);
    }
    write(ram,actor+g.targetYaw,target.yaw);
    write<uint16_t>(ram,actor+g.remaining,1);
    write<uint16_t>(ram,actor+g.remaining-2,0);
    return true;
}
// Preserve the non-motion fields and the original receiver's stateful actions.
// Restore only the adapted bytes, because the original handler legitimately
// modifies other flags in its receive buffer. This object stays on the guest owner.
class MotionRecord {
  public:
    MotionRecord(uint8_t* ram,const GameLayout& g,uint32_t sender,uint32_t address) {
        const bool packed=g.stride==File2.stride;
        const uint32_t size=44;
        if (sender<1 || sender>4 || address>0x2000000u-size || !online(ram,g) || ram[g.phase]!=2) return;
        const uint8_t slot=uint8_t(sender-1);
        const uint16_t room=read<uint16_t>(ram,g.room);
        const uint32_t actor=g.actors+g.stride*slot;
        const uint32_t flags=read<uint32_t>(ram,address+(packed?20:24));
        if (ram[address]!=1 || ram[address+1]!=size || ram[address+2]!=slot || slot==ram[g.local] ||
            flags&(packed?0x00080000u:0x10000000u) || !ram[actor] || ram[actor+2] ||
            ram[address+(packed?24:36)]!=room || read<uint16_t>(ram,actor+0x1e2)!=room) return;
        Motion value;
        if (!runtime().target(slot,room,nowUs(),value)) return;
        if (packed && (value.xyz[0]<-32768 || value.xyz[0]>32767 || value.xyz[2]<-32768 || value.xyz[2]>32767)) return;
        bytes_=ram+address+8;
        length_=packed?10:14;
        std::memcpy(saved_.data(),bytes_,length_);
        if (packed) {
            write<int16_t>(ram,address+8,int16_t(value.xyz[0]));
            write<int16_t>(ram,address+10,int16_t(value.xyz[2]));
            write(ram,address+12,value.xyz[1]);
            write(ram,address+16,value.yaw);
        } else {
            for(size_t i=0;i<3;++i) write(ram,address+8+uint32_t(i*4),value.xyz[i]);
            write(ram,address+20,value.yaw);
        }
    }
    ~MotionRecord() { if(bytes_) std::memcpy(bytes_,saved_.data(),length_); }
    MotionRecord(const MotionRecord&)=delete;
    MotionRecord& operator=(const MotionRecord&)=delete;
  private:
    uint8_t* bytes_=nullptr;
    size_t length_=0;
    std::array<uint8_t,14> saved_{};
};
// Changes/restores only our exact value. Server-supplied non-default tuning wins.
inline void cadence(uint8_t* ram,const GameLayout& g,bool enabled) {
    const uint32_t bits=read<uint32_t>(ram,g.interval);
    const uint32_t fast=0x3dcccccdu; // 100 ms batch opportunities, not world tick rate.
    if (enabled && bits==0x3f000000u) write(ram,g.interval,fast);
    else if (!enabled && bits==fast) write<uint32_t>(ram,g.interval,0x3f000000u);
}
inline uint32_t eventReliability(const uint8_t* ram,const GameLayout& g,uint32_t group,uint32_t record,uint32_t mode) {
    if ((mode!=2 && mode!=3) || record>0x2000000u-2 || ram[record+1]<2 || record>0x2000000u-ram[record+1]) return mode;
    auto& state=runtime();
    if (!state.enhanced(nowUs()) || !(state.status().features&CriticalEvents)) return mode;
    bool reliable=group==5;
    if(group==8) {
        // Verified absolute HP, HP/counter, behavior, room, death and revival
        // records. Large kinematic/AI variants retain their original lane.
        switch(ram[record]) {
            case 0x08: case 0x09: case 0x32: case 0x33:
            case 0x36: case 0x59: reliable=true; break;
            case 0x54: case 0x55: reliable=g.stride==File1.stride; break;
            default: break;
        }
    }
    if(reliable) { state.promoted(); return 4; }
    return mode;
}
inline void worldPump(uint8_t* ram,R5900Context* context,PS2Runtime* runtime,bool file2) {
    auto& state=reo_network::native::runtime();
    const auto status=state.status();
    static uint32_t previousSession=0,previousEpoch=0;
    if(status.session!=previousSession || status.epoch!=previousEpoch) {
        worldReset(); previousSession=status.session; previousEpoch=status.epoch;
    }
    const auto now=nowUs();
    if(!state.enhanced(now) || !(status.features&WorldChecks)) { state.worldLocal(nullptr,now); return; }
    WorldDigest digest;
    if(worldCapture(ram,file2,now,digest)) state.worldLocal(&digest,now);
    else state.worldLocal(nullptr,now);
    uint16_t room; uint8_t authority;
    while(state.worldPendingRequest(room,authority)) worldRequest(room,authority);
    worldTick(ram,context,runtime,file2,now);
    state.worldStats(worldStats());
}
} // namespace reo_network::native
