#pragma once
#include "weapon_shuffle.h"

namespace reo::mods {
inline constexpr unsigned MaxSpawnProfiles=128;
struct SpawnProfile {
    uint8_t type{}, model{}, behavior{}, posture{};
    uint16_t health{}, weight{};
};
struct SpawnPool {
    std::array<SpawnProfile,MaxSpawnProfiles> profiles{};
    unsigned count=0;
    std::array<bool,256> sourceBehaviors{};
};
inline SpawnPool parseSpawnPool(std::string_view text, std::string_view behaviors) {
    SpawnPool pool;
    while(!text.empty()) {
        if(pool.count==pool.profiles.size()) throw std::runtime_error("Enemy pool exceeds 128 profiles");
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
    return a>=gameLayout.enemyBase && a<=gameLayout.enemyEnd-gameLayout.enemyStride &&
           (a-gameLayout.enemyBase)%gameLayout.enemyStride==0;
}
inline bool enemyAnimationAvailable(const uint8_t* ram,uint8_t type) {
    if(!ram || type>=64) return false;
    if(ram[gameLayout.animationSlots+type]<6) return true;
    for(unsigned i=0;i<6;++i) if(ram[gameLayout.animationPool+i*gameLayout.animationStride+1]==0) return true;
    return false;
}
inline bool enemyReadyForHandoff(const uint8_t* ram,uint32_t a,unsigned type,unsigned model,unsigned spawn,
                                bool entranceAlreadyCompleted=false) {
    using namespace reo::cheats;
    return ram && enemyActorAddress(a) && ram[a]==1 && ram[a+2]==2 &&
        ram[a+3]==type && half(ram,a+gameLayout.enemyModel)==model && ram[a+gameLayout.enemySpawn]==spawn &&
        (entranceAlreadyCompleted || (ram[a+1] && ram[a+8]==1)) && int16_t(half(ram,a+gameLayout.enemyHealth))>0;
}
inline uint32_t enemyProfileCallback(const uint8_t* ram, const SpawnProfile& p) {
    using namespace reo::cheats;
    if(!ram || p.type>=64) return 0;
    const auto modelTable=word(ram,gameLayout.modelTable+p.type*8);
    const auto modelCount=word(ram,(gameLayout.modelTable+4)+p.type*8);
    const auto index=half(ram,gameLayout.callbackIndex+p.type*2);
#if defined(REO_GAME_FILE2)
    // File #2 retains model metadata for removed File #1 families. Index
    // zero is its placeholder callback (661120), not a playable enemy.
    if (index == 0) return 0;
#endif
    if(modelTable<0x100000u || modelTable>=0x2000000u-4096 || p.model>=modelCount || index>=32) return 0;
    return word(ram,gameLayout.callbackTable+index*4);
}
// Called on the original actor construction path, after the spawn record was
// copied but before its model, animations and family-specific renderer setup.
// No spawn-table, position, trigger, room, identity or lifecycle writes.
template<size_t N>
inline int chooseSpawnIdentity(unsigned type,unsigned model,unsigned behavior,unsigned lifecycle,
                               int health,unsigned spawn,unsigned scenario,uint32_t seed,
                               uint64_t sharedTypes,const SpawnPool& pool,
                               const std::array<bool,N>& available) {
    if(type>=64 || lifecycle>1 || health<=0 || !pool.sourceBehaviors[behavior] ||
       (type!=1 && behavior!=0)) return -1;
    bool source=false;
    for(unsigned i=0;i<pool.count;++i)
        source |= pool.profiles[i].type==type && pool.profiles[i].model==model;
    if(!source) return -1;
    unsigned total=0;
    std::array<unsigned,MaxSpawnProfiles> weights{};
    for(unsigned i=0;i<pool.count;++i) {
        const auto& p=pool.profiles[i];
        // Scripted sources remain addressable by scenario commands after their
        // entrance ends. Those commands use the original family's state table;
        // e.g. a zombie command 10/1 jumps through a null hunter callback.
        // Keep that contract for the spawn's entire seeded lifetime, including
        // room revisits. Ordinary behavior-zero sources may change families.
        const bool scriptCompatible=behavior==0 || p.type==type;
        // Zombie-source species changes use the deferred private-model loader.
        // Other sources still require the room's original shared model.
        const bool shared=(sharedTypes&(uint64_t(1)<<p.type))!=0;
        if(scriptCompatible && i<N && available[i] && (!shared || (type==1 && p.type!=1) || (p.type==type && p.model==model)))
            total += weights[i]=p.weight;
    }
    if(!total) return -1;
    // Stable scenario spawn identity, never the current room, actor allocation,
    // update count or another enemy's roll. Equal results are possible by chance.
    uint32_t state=seed ^ (uint32_t(scenario)<<16) ^
        (uint32_t(spawn)*0x9e3779b9u) ^ (uint32_t(type)<<8) ^ model;
    unsigned choice=next(state)%total;
    for(unsigned i=0;i<pool.count;++i) {
        if(choice<weights[i]) return int(i);
        choice-=weights[i];
    }
    return -1;
}
inline uint64_t sharedEnemyTypes(const uint8_t* ram) {
    using namespace reo::cheats;
#if defined(REO_GAME_FILE2)
    // Original 5C8E10: the three bonus scenarios use these native shared
    // families instead of the normal loaded-resource bitset.
    const auto scenario = half(ram, gameLayout.scenario);
    if (scenario >= 21 && scenario <= 23)
        return (uint64_t(1) << 41) | (uint64_t(1) << 43);
#endif
    return uint64_t(word(ram, gameLayout.sharedTypes)) |
           (uint64_t(word(ram, gameLayout.sharedTypes + 4)) << 32);
}
template<size_t N>
inline int chooseSpawnProfile(const uint8_t* ram,uint32_t a,uint32_t seed,
                              const SpawnPool& pool,const std::array<bool,N>& available) {
    using namespace reo::cheats;
    if(!ram || !enemyActorAddress(a) || ram[a]!=1 || ram[a+2]!=2 || ram[a+8]!=0) return -1;
    return chooseSpawnIdentity(ram[a+3],half(ram,a+gameLayout.enemyModel),ram[a+gameLayout.enemyBehavior],ram[a+gameLayout.enemyLifecycle],
        int16_t(half(ram,a+gameLayout.enemyHealth)),ram[a+gameLayout.enemySpawn],half(ram,gameLayout.scenario),seed,
        sharedEnemyTypes(ram),pool,available);
}
struct SpawnDecisions {
    std::array<int,256> profiles;
    std::array<bool,256> scripted{};
    bool planned=false;
    SpawnDecisions() { reset(); }
    void reset() { profiles.fill(-2);scripted.fill(false);planned=false; }
    template<size_t N>
    void prepare(const uint8_t* ram,uint32_t seed,const SpawnPool& pool,
                 const std::array<bool,N>& supported) {
        using namespace reo::cheats;
        if(!ram) throw std::runtime_error("Cannot plan an absent enemy table");
        profiles.fill(-1);scripted.fill(false);planned=true;
        std::array<uint64_t,256> families{};
        const unsigned count=ram[gameLayout.spawnCount];
        // Reserve every original family first. Then roll all records in stable
        // spawn-ID order, before any actor, room visit or network update can
        // affect resource availability or the original source identity.
        for(unsigned id=0;id<count;++id) {
            const auto record=gameLayout.spawnTable+id*96;
            if(ram[record]!=id || ram[record+2]>=64 || !ram[record+0x22]) continue;
            families[ram[record+0x22]]|=uint64_t(1)<<ram[record+2];
        }
        const uint64_t shared=sharedEnemyTypes(ram);
        for(unsigned id=0;id<count;++id) {
            const auto record=gameLayout.spawnTable+id*96;
            const unsigned room=ram[record+0x22];
            if(ram[record]!=id || !room) continue;
            scripted[id]=ram[record+0x2a]!=0;
            auto reserved=families[room];unsigned used=0;
            for(auto bits=reserved;bits;bits&=bits-1) ++used;
            std::array<bool,N> available{};
            for(unsigned i=0;i<pool.count && i<N;++i)
                available[i]=supported[i] && (used<6 || (reserved&(uint64_t(1)<<pool.profiles[i].type)));
            const int choice=chooseSpawnIdentity(ram[record+2],ram[record+3],ram[record+0x2a],
                ram[record+0x26],int16_t(half(ram,record+0x1c)),id,half(ram,gameLayout.scenario),
                seed,shared,pool,available);
            profiles[id]=choice;
            if(choice>=0) families[room]|=uint64_t(1)<<pool.profiles[choice].type;
        }
    }
    template<size_t N>
    int pick(const uint8_t* ram,uint32_t actor,uint32_t seed,const SpawnPool& pool,
             const std::array<bool,N>& supported) {
        if (!ram || !enemyActorAddress(actor)) return -1;
        auto& profile=profiles[ram[actor+gameLayout.enemySpawn]];
        if(planned) return profile;
        if (profile==-2) profile=chooseSpawnProfile(ram,actor,seed,pool,supported);
        return profile;
    }
};
inline uint16_t replacementHealth(const uint8_t* ram,uint32_t a,const SpawnProfile& p) {
    using namespace reo::cheats;
    const auto hp=int16_t(half(ram,a+gameLayout.enemyHealth)), maximum=int16_t(half(ram,a+gameLayout.enemyMaximum));
    if(hp<=0) return 0;
    if(maximum<=0 || hp>=maximum) return p.health;
    return uint16_t(std::max(1u,unsigned(p.health)*unsigned(hp)/unsigned(maximum)));
}
inline void applySpawnProfile(uint8_t* ram,uint32_t a,const SpawnProfile& p,uint32_t callback) {
    using namespace reo::cheats;
    const auto hp=replacementHealth(ram,a,p);
    ram[a+3]=p.type; setHalf(ram,a+gameLayout.enemyModel,p.model);
    setHalf(ram,a+gameLayout.enemyHealth,hp); setHalf(ram,a+gameLayout.enemyMaximum,p.health);
    ram[a+gameLayout.enemyBehavior]=p.behavior; ram[a+gameLayout.enemyPosture]=p.posture;
    setWord(ram,a+0x14,callback);
}
}
