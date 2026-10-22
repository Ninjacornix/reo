#pragma once
#include "weapon_shuffle.h"

namespace reo::mods {
struct SpawnProfile {
    uint8_t type{}, model{}, behavior{}, posture{};
    uint16_t health{}, weight{};
};
struct SpawnPool {
    std::array<SpawnProfile,32> profiles{};
    unsigned count=0;
    std::array<bool,256> sourceBehaviors{};
};
inline SpawnPool parseSpawnPool(std::string_view text, std::string_view behaviors) {
    SpawnPool pool;
    while(!text.empty()) {
        if(pool.count==pool.profiles.size()) throw std::runtime_error("Enemy pool exceeds 32 profiles");
        unsigned fields[6]{};
        for(unsigned i=0;i<6;++i) {
            const auto delimiter=text.find(i==5 ? ';' : ':');
            const auto part=text.substr(0,delimiter);
            const auto parsed=std::from_chars(part.data(),part.data()+part.size(),fields[i]);
            if(part.empty() || parsed.ec!=std::errc{} || parsed.ptr!=part.data()+part.size() ||
               (i!=5 && delimiter==text.npos) || (i==5 && delimiter!=text.npos && delimiter+1==text.size()))
                throw std::runtime_error("Invalid enemy profile");
            text=delimiter==text.npos ? std::string_view{} : text.substr(delimiter+1);
        }
        if(fields[0]>=64 || fields[1]>255 || fields[2]==0 || fields[2]>=32767 ||
           fields[3]>255 || fields[4]>255 || fields[5]==0 || fields[5]>100)
            throw std::runtime_error("Enemy profile out of range");
        for(unsigned i=0;i<pool.count;++i)
            if(pool.profiles[i].type==fields[0] && pool.profiles[i].model==fields[1])
                throw std::runtime_error("Duplicate enemy type/model");
        pool.profiles[pool.count++]={uint8_t(fields[0]),uint8_t(fields[1]),uint8_t(fields[3]),
            uint8_t(fields[4]),uint16_t(fields[2]),uint16_t(fields[5])};
    }
    if(!pool.count || behaviors.empty()) throw std::runtime_error("Enemy pool and source behaviors required");
    while(!behaviors.empty()) {
        const auto separator=behaviors.find(','); const auto part=behaviors.substr(0,separator);
        unsigned value=0; const auto parsed=std::from_chars(part.data(),part.data()+part.size(),value);
        if(part.empty() || parsed.ec!=std::errc{} || parsed.ptr!=part.data()+part.size() || value>255 || pool.sourceBehaviors[value] ||
           (separator!=behaviors.npos && separator+1==behaviors.size()))
            throw std::runtime_error("Invalid source behavior list");
        pool.sourceBehaviors[value]=true;
        behaviors=separator==behaviors.npos ? std::string_view{} : behaviors.substr(separator+1);
    }
    return pool;
}
inline bool enemyActorAddress(uint32_t a) {
    return a>=0x42eb00u && a+0xd90u<=0x459120u && (a-0x42eb00u)%0xd90u==0;
}
inline bool enemyAnimationAvailable(const uint8_t* ram,uint8_t type) {
    if(!ram || type>=64) return false;
    if(ram[0x4baeb0u+type]<6) return true;
    for(unsigned i=0;i<6;++i) if(ram[0x4bec30u+i*0xc84+1]==0) return true;
    return false;
}
inline bool enemyReadyForHandoff(const uint8_t* ram,uint32_t a,unsigned type,unsigned model,unsigned spawn,
                                bool entranceAlreadyCompleted=false) {
    using namespace reo::cheats;
    return ram && enemyActorAddress(a) && ram[a]==1 && ram[a+2]==2 &&
        ram[a+3]==type && half(ram,a+0xbba)==model && ram[a+0xb98]==spawn &&
        (entranceAlreadyCompleted || (ram[a+1] && ram[a+8]==1)) && int16_t(half(ram,a+0x544))>0;
}
inline uint32_t enemyProfileCallback(const uint8_t* ram, const SpawnProfile& p) {
    using namespace reo::cheats;
    if(!ram || p.type>=64) return 0;
    const auto modelTable=word(ram,0x387e90u+p.type*8);
    const auto modelCount=word(ram,0x387e94u+p.type*8);
    const auto index=half(ram,0x70aa50u+p.type*2);
    if(modelTable<0x100000u || modelTable>=0x2000000u-4096 || p.model>=modelCount || index>=32) return 0;
    return word(ram,0x70ab20u+index*4);
}
// Called on the original actor construction path, after the spawn record was
// copied but before its model, animations and family-specific renderer setup.
// No spawn-table, position, trigger, room, identity or lifecycle writes.
inline int chooseSpawnProfile(const uint8_t* ram, uint32_t a, uint32_t seed,
                              const SpawnPool& pool, const std::array<bool,32>& available) {
    using namespace reo::cheats;
    // Selection is separate from application: scripted sources wait for their
    // original entrance to hand control to ordinary AI before replacement.
    if(!ram || !enemyActorAddress(a) || ram[a]!=1 || ram[a+2]!=2 || ram[a+8]!=0 ||
       ram[a+0xb9a]>1 ||
       int16_t(half(ram,a+0x544))<=0 ||
       !pool.sourceBehaviors[ram[a+0xc2b]] ||
       (ram[a+3]!=1 && ram[a+0xc2b]!=0)) return -1;
    const auto model=half(ram,a+0xbba);
    bool source=false;
    for(unsigned i=0;i<pool.count;++i)
        source |= pool.profiles[i].type==ram[a+3] && pool.profiles[i].model==model;
    if(!source) return -1;
    unsigned total=0;
    std::array<unsigned,32> weights{};
    for(unsigned i=0;i<pool.count;++i) {
        const auto& p=pool.profiles[i];
        // Zombie-source species changes use the deferred private-model loader.
        // Other sources still require the room's original shared model.
        const bool shared=(word(ram,0x709ac0u+(p.type/32)*4)&(1u<<(p.type%32)))!=0;
        if(available[i] && (!shared || (ram[a+3]==1 && p.type!=1) || (p.type==ram[a+3] && p.model==model)))
            total += weights[i]=p.weight;
    }
    if(!total) return -1;
    // Stable scenario spawn identity, never the current room, actor allocation,
    // update count or another enemy's roll. Equal results are possible by chance.
    uint32_t state=seed ^ (uint32_t(half(ram,0x3243da))<<16) ^
        (uint32_t(ram[a+0xb98])*0x9e3779b9u) ^ (uint32_t(ram[a+3])<<8) ^ model;
    unsigned choice=next(state)%total;
    for(unsigned i=0;i<pool.count;++i) {
        if(choice<weights[i]) return int(i);
        choice-=weights[i];
    }
    return -1;
}
struct SpawnDecisions {
    std::array<int,256> profiles;
    SpawnDecisions() { reset(); }
    void reset() { profiles.fill(-2); }
    int pick(const uint8_t* ram,uint32_t actor,uint32_t seed,const SpawnPool& pool,
             const std::array<bool,32>& supported) {
        if (!ram || !enemyActorAddress(actor)) return -1;
        auto& profile=profiles[ram[actor+0xb98]];
        if (profile==-2) profile=chooseSpawnProfile(ram,actor,seed,pool,supported);
        return profile;
    }
};
inline uint16_t replacementHealth(const uint8_t* ram,uint32_t a,const SpawnProfile& p) {
    using namespace reo::cheats;
    const auto hp=int16_t(half(ram,a+0x544)), maximum=int16_t(half(ram,a+0x546));
    if(hp<=0) return 0;
    if(maximum<=0 || hp>=maximum) return p.health;
    return uint16_t(std::max(1u,unsigned(p.health)*unsigned(hp)/unsigned(maximum)));
}
inline void applySpawnProfile(uint8_t* ram,uint32_t a,const SpawnProfile& p,uint32_t callback) {
    using namespace reo::cheats;
    const auto hp=replacementHealth(ram,a,p);
    ram[a+3]=p.type; setHalf(ram,a+0xbba,p.model);
    setHalf(ram,a+0x544,hp); setHalf(ram,a+0x546,p.health);
    ram[a+0xc2b]=p.behavior; ram[a+0xb9c]=p.posture;
    setWord(ram,a+0x14,callback);
}
}
