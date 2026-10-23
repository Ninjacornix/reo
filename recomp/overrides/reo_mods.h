#pragma once
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "../../runtime/mods/weapon_shuffle.h"
#include "../../runtime/mods/global_items.h"
#include "../../runtime/mods/enemy_randomizer.h"
#include "../../runtime/mods/enemy_spawn_randomizer.h"
#include <charconv>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#if defined(REO_GAME_FILE1)
extern void o2_005924E0_0x5924e0(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006BAA40_0x6baa40(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006BB040_0x6bb040(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006BB9F0_0x6bb9f0(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_00696300_0x696300(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006055E0_0x6055e0(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_0061C3E0_0x61c3e0(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_0060F710_0x60f710(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006CE400_0x6ce400(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_001A9F20_0x1a9f20(uint8_t*, R5900Context*, PS2Runtime*);
extern void o9_0081DA80_0x81da80(uint8_t*, R5900Context*, PS2Runtime*);
extern void o9_0081DA90_0x81da90(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_001A0D10_0x1a0d10(uint8_t*, R5900Context*, PS2Runtime*);
namespace reo::mods {
inline std::array<float,50> foreignNeptuneHeight{};
inline std::array<bool,50> foreignNeptune{};
inline void clampRandomizedNeptune(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    const auto a=GPR_U32(ctx,4);
    o2_006CE400_0x6ce400(ram,ctx,runtime);
    if(enemyActorAddress(a) && foreignNeptune[(a-0x42eb00)/0xd90] && ram[a+0xba5]==99)
        std::memcpy(ram+a+0x3c,&foreignNeptuneHeight[(a-0x42eb00)/0xd90],4);
}
inline void readGlobalModelBank(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    const char* catalogue=std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE");
    const uint32_t source=GPR_U32(ctx,5),destination=GPR_U32(ctx,6);
    std::string path;
    if(catalogue && source<PS2_RAM_SIZE) {
        for(unsigned i=0;i<256 && source+i<PS2_RAM_SIZE && ram[source+i];++i) {
            char c=char(ram[source+i]);path+=c>='a' && c<='z' ? char(c-'a'+'A') : c;
        }
    }
    const auto position=path.find("OBJS");
    if(position!=std::string::npos && position+10<=path.size() && path.substr(position+6,4)==".NBD") {
        const auto name=path.substr(position,10);
        static std::map<std::string,std::vector<uint8_t>> cached;
        auto& bytes=cached[name];
        if(bytes.empty()) {
            const auto folder=std::filesystem::path(std::u8string(reinterpret_cast<const char8_t*>(catalogue))).parent_path()/"global-models";
            std::ifstream input(folder/name,std::ios::binary|std::ios::ate);
            const auto length=input ? std::streamoff(input.tellg()) : -1;
            if(length<=64 || length>2*1024*1024) throw std::runtime_error("Global item model bank is missing or too large");
            bytes.resize(size_t(length));input.seekg(0);
            if(!input.read(reinterpret_cast<char*>(bytes.data()),length)) throw std::runtime_error("Cannot read global item models");
        }
        size_t start=0,length=bytes.size();
        const auto suffix=path.substr(position+10);
        for(auto [label,offset]:std::array<std::pair<const char*,unsigned>,3>{{{"TEX",0},{"AMO",16},{"AHI",32}}})
            if(suffix.find(label)!=std::string::npos) {
                start=reo::cheats::word(bytes.data(),offset+4);length=reo::cheats::word(bytes.data(),offset+8);
            }
        if(start>bytes.size() || length>bytes.size()-start ||
           (destination && (destination<0x100000 || uint64_t(destination)+length>PS2_RAM_SIZE)))
            throw std::runtime_error("Global model read exceeds the native buffer");
        if(destination) std::memcpy(ram+destination,bytes.data()+start,length);
        std::fprintf(stderr,"[MOD-GLOBAL-MODELS-1] file=%s destination=%08x bytes=%zu\n",path.c_str(),destination,length);
        SET_GPR_U32(ctx,2,uint32_t(length));ctx->pc=GPR_U32(ctx,31);return;
    }
    sub_001A9F20_0x1a9f20(ram,ctx,runtime);
}
inline bool enemyEnabled = false, enemyPending = true, enemyDiagnostics = false;
inline bool spawnEnabled = false;
inline SpawnPool spawnPool{};
inline SpawnDecisions spawnDecisions{};
inline std::array<bool,256> completedSpawnEntrances{};
inline uint32_t enemySeed = 0;

struct PendingEnemy { bool waiting=false; SpawnProfile profile{}; uint8_t sourceType{},sourceModel{},spawn{}; };
inline std::array<PendingEnemy,50> pendingEnemies{};
inline constexpr uint32_t replacementResume=0x01ff1000u;
inline void initializeModAssetHeap(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x1a0d10u && spawnEnabled) {
        if(ps2RamBackingBytes!=2u*PS2_RAM_SIZE) throw std::runtime_error("Enemy mods require the native asset bank");
        SET_GPR_U32(ctx,4,PS2_RAM_SIZE); SET_GPR_U32(ctx,5,PS2_RAM_SIZE);
        reo::cheats::setWord(ram,0x29fda8,PS2_RAM_SIZE);
        reo::cheats::setWord(ram,0x29fdac,PS2_RAM_SIZE);
        std::fprintf(stderr,"[MOD-ENEMY-ASSETS-1] base=02000000 bytes=33554432\n");
    }
    sub_001A0D10_0x1a0d10(ram,ctx,runtime);
}
// Native guest-call continuation. The original enemy callback's stack and s0
// survive asynchronous model/animation I/O through the normal scheduler.
inline void continueEnemyReplacement(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    using namespace reo::cheats;
    const auto a=GPR_U32(ctx,16), sp=GPR_U32(ctx,29);
    auto call=[&](uint32_t entry,unsigned step) {
        const uint32_t resume=replacementResume+step*4;
        SET_GPR_U32(ctx,31,resume);ctx->pc=entry;
        runtime->lookupFunction(entry)(ram,ctx,runtime);
        return ctx->pc==resume;
    };
    switch((ctx->pc-replacementResume)/4) {
    case 0:
        SET_GPR_U32(ctx,4,a); SET_GPR_U32(ctx,5,sp+32);
        if(!call(0x6bbda0,5)) return;
        [[fallthrough]];
    case 5:
        // Reapply the native spawn's target-priority setup as the room loader
        // does, without re-entering our selection hook for this same actor.
        SET_GPR_U32(ctx,4,a); SET_GPR_U32(ctx,31,replacementResume+6*4);
        ctx->pc=0x6bb9f0;
        o2_006BB9F0_0x6bb9f0(ram,ctx,runtime);
        if(ctx->pc!=replacementResume+6*4) return;
        [[fallthrough]];
    case 6:
        std::memcpy(ram+a+0x38,ram+sp+128,12);
        std::memcpy(ram+a+0x90,ram+sp+144,8);
        SET_GPR_U32(ctx,4,a);
        if(!call(0x1b92e0,1)) return;
        [[fallthrough]];
    case 1:
        ram[a+0x33]=uint8_t(GPR_U32(ctx,2));ram[a+0x554]=0;
        SET_GPR_U32(ctx,4,ram[a+0x54d]); SET_GPR_U32(ctx,5,ram[a+0x31]);
        SET_GPR_U32(ctx,6,ram[a+3]);SET_GPR_U32(ctx,7,half(ram,a+0xbba));SET_GPR_U32(ctx,8,0);
        if(!call(0x6ba790,2)) return;
        [[fallthrough]];
    case 2: {
        const auto model=word(ram,a+0x34);
        setWord(ram,model+0x1460,0);setWord(ram,model+0x1464,0);
        SET_GPR_U32(ctx,4,a);SET_GPR_U32(ctx,5,2);SET_GPR_U32(ctx,6,ram[a+3]);
        if(!call(0x377560,3)) return;
        [[fallthrough]];
    }
    case 3:
        if(GPR_U32(ctx,2)) {
            SET_GPR_U32(ctx,4,a);SET_GPR_U32(ctx,5,ram[a+0x31]+4);
            if(!call(0x3777b0,4)) return;
        }
        [[fallthrough]];
    case 4: {
        const auto model=word(ram,a+0x34);
        if(enemyDiagnostics) std::fprintf(stderr,"[TEST-ENEMY-RESOURCE] actor=%08x slot=%u model=%08x geometry=%08x motion=%08x\n",a,ram[a+0x31],model,word(ram,model+0x808),word(ram,a+0x51c));
        const auto bones=half(ram,model+0x812);
        if(bones>128) throw std::runtime_error("Invalid replacement skeleton");
        std::memset(ram+a+0xf4,1,bones);
        const auto slot=ram[0x4baeb0+ram[a+3]];
        if(slot>=6) throw std::runtime_error("Replacement animation did not load");
        ram[a+0x54e]=ram[a+3];
        setWord(ram,a+0x51c,0x4bec30+slot*0xc84);
        setWord(ram,a+0x514,0x4bd4a0+slot*0x3ec);
        ram[a+0x524]=ram[0x4bec30+slot*0xc84+1];
        // Crows and wasps have a scene-specific flight path selected by +4.
        // A foreign room lacks its flight ceiling/script setup: crows stay at
        // floor height and wasps enter a scripted exit. Use native free flight
        // for these replacements; their AI still handles collision and damage.
        // Neptune uses the same field to select swimming versus stranded AI;
        // a zombie's scene flag must not select a pool at a foreign elevation.
        if(ram[a+3]==5 || ram[a+3]==6 || ram[a+3]==26) ram[a+4]=0;
        if(ram[a+3]==26) {
            const auto slot=(a-0x42eb00)/0xd90;
            foreignNeptune[slot]=true;std::memcpy(&foreignNeptuneHeight[slot],ram+a+0x3c,4);
        }
        ram[a+8]=ram[a+9]=ram[a+10]=ram[a+11]=0;
        completedSpawnEntrances[ram[a+0xb98]]=true;
        std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] ready actor=%08x spawn=%u type=%u model=%u bones=%u animation=%u callback=%08x\n",
            a,ram[a+0xb98],ram[a+3],half(ram,a+0xbba),bones,slot,word(ram,a+0x14));
        ctx->r[16]=_mm_loadu_si128(reinterpret_cast<const __m128i*>(ram+sp));
        uint64_t ra;std::memcpy(&ra,ram+sp+16,8);SET_GPR_U64(ctx,31,ra);
        SET_GPR_U32(ctx,29,sp+160);ctx->pc=uint32_t(ra);
        return;
    }
    default: throw std::runtime_error("Invalid enemy replacement continuation");
    }
}
inline bool releasePendingEnemy(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime,uint32_t a) {
    using namespace reo::cheats;
    if(!spawnEnabled || !enemyActorAddress(a)) return false;
    auto& pending=pendingEnemies[(a-0x42eb00)/0xd90];
    if(!pending.waiting || !enemyReadyForHandoff(ram,a,pending.sourceType,pending.sourceModel,pending.spawn,
                                                completedSpawnEntrances[pending.spawn])) return false;
    if(!enemyAnimationAvailable(ram,pending.profile.type)) {
        throw std::runtime_error("Enemy randomizer exceeds this room's six native animation families");
    }
    pending.waiting=false;
    std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] handoff actor=%08x spawn=%u source=%u:%u replacement=%u:%u xyz=%.0f,%.0f\n",
        a,pending.spawn,pending.sourceType,pending.sourceModel,pending.profile.type,pending.profile.model,
        *reinterpret_cast<float*>(ram+a+0x38),*reinterpret_cast<float*>(ram+a+0x40));
    const auto callback=enemyProfileCallback(ram,pending.profile);
    const auto sp=GPR_U32(ctx,29)-160;
    _mm_storeu_si128(reinterpret_cast<__m128i*>(ram+sp),ctx->r[16]);
    uint64_t ra=GPR_U64(ctx,31);std::memcpy(ram+sp+16,&ra,8);
    std::memcpy(ram+sp+32,ram+0x74f250+pending.spawn*96,96);
    std::memcpy(ram+sp+128,ram+a+0x38,12);
    std::memcpy(ram+sp+144,ram+a+0x90,8);
    const auto record=sp+32;
    // Give native spatial initialization the entrance's current location too;
    // restore the exact floats after the integer spawn-record constructor.
    for(unsigned i=0;i<3;++i) {
        float position;std::memcpy(&position,ram+sp+128+i*4,4);
        setWord(ram,record+0x10+i*4,uint32_t(int32_t(position)));
    }
    setWord(ram,record+8,uint32_t(int16_t(half(ram,a+0x90))));
    setWord(ram,record+12,uint32_t(int16_t(half(ram,a+0x92))));
    ram[record+2]=pending.profile.type;ram[record+3]=pending.profile.model;
    ram[record+0x2a]=pending.profile.behavior;ram[record+0x2b]=pending.profile.posture;
    setHalf(ram,record+0x1c,replacementHealth(ram,a,pending.profile));setHalf(ram,record+0x1e,pending.profile.health);
    // Rebuild in place, keeping the allocated slot and intrusive-list links.
    // Each native constructor expects fresh private animation/collision state.
    const auto previous=word(ram,a+0x1c),nextActor=word(ram,a+0x20),render=word(ram,a+0x34);
    const auto rendererCallback=word(ram,a+0x18);const auto renderSlot=ram[a+0x31];
    const auto room=half(ram,a+0x1e2);
    std::memset(ram+a,0,0xd90);
    ram[a]=1;ram[a+2]=2;ram[a+3]=pending.profile.type;ram[a+6]=uint8_t((a-0x42eb00)/0xd90);
    setWord(ram,a+0x14,callback);setWord(ram,a+0x18,rendererCallback);
    setWord(ram,a+0x1c,previous);setWord(ram,a+0x20,nextActor);
    ram[a+0x31]=renderSlot;setWord(ram,a+0x34,render);setHalf(ram,a+0x1e2,room);
    std::memset(ram+a+0xccc,0xff,4);ram[a+0xca0]=ram[a+0xca1]=0xff;
    SET_GPR_U32(ctx,29,sp);SET_GPR_U32(ctx,16,a);ctx->pc=replacementResume;
    continueEnemyReplacement(ram,ctx,runtime);return true;
}
inline void resetEnemyShuffle(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    // 6baa40 reloads the whole scenario spawn table. Room initialization at
    // 6bb040 only clears transient actor slots, and must not discard choices.
    if (ctx->pc == 0x6baa40u) { enemyPending = true; pendingEnemies={}; spawnDecisions.reset(); completedSpawnEntrances={}; }
    o2_006BAA40_0x6baa40(ram, ctx, runtime);
}
inline void initializeEnemies(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    const bool firstInitialization=enemyPending && ctx->pc==0x6bb040u;
    if (enemyPending && ctx->pc == 0x6bb040u) {
        enemyPending = false;
        // Shuffle native zombie appearances before construction, including the
        // scripted spawns whose family must remain compatible with later events.
        if (enemyEnabled || spawnEnabled) {
            ZombieShuffleFilter scripted;
            if(spawnEnabled) {
                scripted.behaviors=spawnPool.sourceBehaviors;
                scripted.behaviors[0]=false;
                for(unsigned i=0;i<spawnPool.count;++i)
                    if(spawnPool.profiles[i].type==1) scripted.variants[spawnPool.profiles[i].model]=true;
            }
            const auto result = shuffleZombieProfiles(ram, enemySeed, spawnEnabled ? &scripted : nullptr);
            std::fprintf(stderr, "[MOD-ZOMBIE-RANDOMIZER-1] seed=%u eligible=%u changed=%u\n",
                enemySeed, result.count, result.changed);
            for (unsigned i = 0; i < result.count; ++i) {
                const auto& a = result.before[i];
                const auto& b = result.after[i];
                std::fprintf(stderr, "[MOD-ZOMBIE-RANDOMIZER-1] record=%08x room=%u mode=%u variant=%u:%u -> %u:%u\n",
                    a.address, a.room, a.mode, a.variant, a.health, b.variant, b.health);
            }
        }
        if (enemyDiagnostics) {
            const unsigned count = ram[0x4bae8e];
            std::fprintf(stderr, "[TEST-ENEMIES] table count=%u\n", count);
            for (unsigned i = 0; i < count; ++i) {
                const auto a = 0x74f250u + i * 96;
                std::fprintf(stderr, "[TEST-ENEMIES] record=%08x bytes=", a);
                for (unsigned b = 0; b < 96; ++b) std::fprintf(stderr, "%02x", ram[a + b]);
                std::fprintf(stderr, "\n");
            }
        }
    }
    if(spawnEnabled && ctx->pc==0x6bb040u) {
        pendingEnemies={};
        const auto room=reo::cheats::half(ram,0x3243dc);
        // Developer compatibility fixture: add an independent ordinary spawn
        // through the native constructor. Existing scenario actors/scripts are
        // unchanged. This branch is never enabled by an ordinary mod launch.
        if(firstInitialization && enemyDiagnostics && std::getenv("REO_TEST_ENEMY_PROBE")) {
            const unsigned count=ram[0x4bae8e];
            const unsigned start=ram[0x7552d0+room],roomCount=ram[0x755250+room],probe=start+roomCount;
            if(probe>=254 || !roomCount) throw std::runtime_error("No native room-group slot for roster probe");
            const auto record=0x74f250+probe*96;
            // Extend this room's contiguous group into the next, currently
            // inactive room slot. Never alter this room's scripted actor IDs.
            // The fixture ends in this room and is not a progression test.
            std::memcpy(ram+record,ram+0x74f250+start*96,96);
            ram[record]=ram[record+0x27]=uint8_t(probe);ram[record+2]=1;ram[record+3]=9;
            ram[record+0x22]=uint8_t(room);
            ram[record+0x26]=ram[record+0x2a]=ram[record+0x2b]=0;
            reo::cheats::setWord(ram,record+0x10,8500);reo::cheats::setWord(ram,record+0x18,13150);
            reo::cheats::setHalf(ram,record+0x1c,700);reo::cheats::setHalf(ram,record+0x1e,700);
            ram[0x755250+room]=uint8_t(roomCount+1);
            ram[0x4bae8e]=uint8_t(std::max(count,probe+1));
            std::fprintf(stderr,"[TEST-ENEMY-PROBE] independent native spawn=%u room=%u\n",probe,room);
        }
        if(firstInitialization) {
            std::array<bool,MaxSpawnProfiles> supported{};
            for(unsigned i=0;i<spawnPool.count;++i) {
                const auto callback=enemyProfileCallback(ram,spawnPool.profiles[i]);
                if(!callback || !runtime->hasFunction(callback))
                    throw std::runtime_error("The seeded enemy plan contains an unsupported native profile");
                supported[i]=true;
            }
            spawnDecisions.prepare(ram,enemySeed,spawnPool,supported);
            std::fprintf(stderr,"[MOD-ENEMY-PLAN-3] scenario=%u seed=%u records=%u\n",
                reo::cheats::half(ram,0x3243da),enemySeed,ram[0x4bae8e]);
            for(unsigned id=0;id<ram[0x4bae8e];++id) {
                const int choice=spawnDecisions.profiles[id];
                if(choice<0) continue;
                const auto& p=spawnPool.profiles[choice];
                std::fprintf(stderr,"[MOD-ENEMY-PLAN-3] spawn=%u type=%u model=%u hp=%u behavior=%u posture=%u\n",
                    id,p.type,p.model,p.health,p.behavior,p.posture);
            }
        }
    }
    o2_006BB040_0x6bb040(ram,ctx,runtime);
}
inline void inspectEnemyActor(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    if (ctx->pc == 0x6bb9f0u) {
        const uint32_t a = uint32_t(_mm_cvtsi128_si32(ctx->r[4]));
        if(enemyActorAddress(a)) {
            pendingEnemies[(a-0x42eb00)/0xd90]={};foreignNeptune[(a-0x42eb00)/0xd90]=false;
        }
        if(spawnEnabled && enemyActorAddress(a)) {
            std::array<bool,MaxSpawnProfiles> available{};
            for(unsigned i=0;i<spawnPool.count;++i) {
                const auto& p=spawnPool.profiles[i];
                const auto callback=enemyProfileCallback(ram,p);
                available[i]=callback && runtime->hasFunction(callback);
            }
            const int index=spawnDecisions.pick(ram,a,enemySeed,spawnPool,available);
            if(index>=0) {
                const auto& p=spawnPool.profiles[index];
                const auto callback=enemyProfileCallback(ram,p);
                std::fprintf(stderr,"[MOD-ENEMY-CHOICE-2] scenario=%u room=%u spawn=%u type=%u model=%u\n",
                    reo::cheats::half(ram,0x3243da),reo::cheats::half(ram,0x3243dc),ram[a+0xb98],p.type,p.model);
                std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] actor=%08x spawn=%u source=%u:%u behavior=%u replacement=%u:%u hp=%u callback=%08x\n",
                    a,ram[a+0xb98],ram[a+3],reo::cheats::half(ram,a+0xbba),ram[a+0xc2b],p.type,p.model,p.health,callback);
                auto& pending=pendingEnemies[(a-0x42eb00)/0xd90];
                pending={};
                if(ram[a+3]==1 && (p.type!=ram[a+3] || p.model!=reo::cheats::half(ram,a+0xbba))) {
                    pending={true,p,ram[a+3],uint8_t(reo::cheats::half(ram,a+0xbba)),ram[a+0xb98]};
                    std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] deferred actor=%08x behavior=%u\n",a,ram[a+0xc2b]);
                } else if(ram[a+0xc2b]==0 &&
                          !(spawnDecisions.planned && spawnDecisions.scripted[ram[a+0xb98]])) {
                    // Online reconstruction can clear an entrance's behavior on
                    // only one peer. Keep its original scripted health/profile.
                    applySpawnProfile(ram,a,p,callback);
                    const auto metadata=reo::cheats::word(ram,0x387e90+p.type*8)+p.model*16;
                    for(unsigned offset:{0xb4u,0xb8u,0xbcu}) reo::cheats::setWord(ram,a+offset,reo::cheats::word(ram,metadata+8));
                    ram[a+0xc24]=ram[0x72be20+p.type];
                }
            }
        }
        if (enemyDiagnostics && enemyActorAddress(a))
            std::fprintf(stderr, "[TEST-ENEMIES] actor=%08x type=%u variant=%u spawn=%u hp=%u callback=%08x\n",
                a, ram[a + 3], reo::cheats::half(ram, a + 0xbba), ram[a + 0xb98],
                reo::cheats::half(ram, a + 0x544), reo::cheats::word(ram, a + 0x14));
    }
    o2_006BB9F0_0x6bb9f0(ram, ctx, runtime);
}
inline void inspectSpecies(uint8_t* ram) {
    static auto last=std::chrono::steady_clock::time_point{};
    const auto now=std::chrono::steady_clock::now();
    if(!enemyDiagnostics || now-last<std::chrono::seconds(2)) return;
    last=now;
    const auto unixMs=std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    for(uint32_t a=0x42eb00;a<0x459120;a+=0xd90) {
        if(ram[a]!=1 || ram[a+2]!=2) continue;
        float xyz[3];std::memcpy(xyz,ram+a+0x38,12);
        std::fprintf(stderr,"[TEST-ENEMY-SPECIES] actor=%08x spawn=%u type=%u model=%u hp=%u state=%u/%u/%u xyz=%.2f,%.2f,%.2f callback=%08x unixMs=%lld room=%u\n",
            a,ram[a+0xb98],ram[a+3],reo::cheats::half(ram,a+0xbba),reo::cheats::half(ram,a+0x544),
            ram[a+8],ram[a+9],ram[a+10],xyz[0],xyz[1],xyz[2],reo::cheats::word(ram,a+0x14),
            static_cast<long long>(unixMs),reo::cheats::half(ram,0x3243dc));
    }
}
inline void inspectZombieUpdate(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    static std::array<std::chrono::steady_clock::time_point, 50> last{};
    static uint16_t playerHp = 0;
    const auto now = std::chrono::steady_clock::now();
    if (ctx->pc == 0x696300u) {
        if(releasePendingEnemy(ram,ctx,runtime,GPR_U32(ctx,4))) return;
        if(!enemyDiagnostics) { o2_00696300_0x696300(ram,ctx,runtime); return; }
        inspectSpecies(ram);
        const auto hp = reo::cheats::half(ram, 0x4a6174u);
        if (playerHp && hp < playerHp)
            std::fprintf(stderr, "[TEST-ENEMIES] PLAYER DAMAGE before=%u after=%u state=%u/%u\n",
                playerHp, hp, ram[0x4a5c38], ram[0x4a5c39]);
        playerHp = hp;
        const uint32_t a = uint32_t(_mm_cvtsi128_si32(ctx->r[4]));
        if (a >= 0x42eb00u && a + 0xd90u <= 0x459120u && (a - 0x42eb00u) % 0xd90u == 0 &&
            now - last[(a - 0x42eb00u) / 0xd90u] >= std::chrono::seconds(5)) {
            last[(a - 0x42eb00u) / 0xd90u] = now;
            float x, z;
            std::memcpy(&x, ram + a + 0x38, 4); std::memcpy(&z, ram + a + 0x40, 4);
            std::fprintf(stderr, "[TEST-ENEMIES] update actor=%08x spawn=%u variant=%u state=%u/%u/%u hp=%u xyz=%.2f,%.2f playerHp=%u playerState=%u/%u\n",
                a, ram[a + 0xb98], reo::cheats::half(ram, a + 0xbba), ram[a+8], ram[a+9], ram[a+10],
                reo::cheats::half(ram,a+0x544), x, z, reo::cheats::half(ram,0x4a6174), ram[0x4a5c38], ram[0x4a5c39]);
        }
    }
    o2_00696300_0x696300(ram, ctx, runtime);
}
inline void inspectDogUpdate(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    static std::array<std::chrono::steady_clock::time_point, 50> last{};
    if(ctx->pc==0x6055e0u) {
        const uint32_t a=uint32_t(_mm_cvtsi128_si32(ctx->r[4]));
        const auto now=std::chrono::steady_clock::now();
        if(enemyDiagnostics && a>=0x42eb00u && a+0xd90u<=0x459120u && (a-0x42eb00u)%0xd90u==0 &&
           now-last[(a-0x42eb00u)/0xd90u]>=std::chrono::seconds(2)) {
            last[(a-0x42eb00u)/0xd90u]=now;
            float x,z; std::memcpy(&x,ram+a+0x38,4); std::memcpy(&z,ram+a+0x40,4);
            std::fprintf(stderr,"[TEST-ENEMIES] dog actor=%08x spawn=%u variant=%u state=%u/%u/%u hp=%u xyz=%.2f,%.2f playerHp=%u\n",
                a,ram[a+0xb98],reo::cheats::half(ram,a+0xbba),ram[a+8],ram[a+9],ram[a+10],
                reo::cheats::half(ram,a+0x544),x,z,reo::cheats::half(ram,0x4a6174));
        }
    }
    o2_006055E0_0x6055e0(ram,ctx,runtime);
}
inline void inspectLickerUpdate(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x61c3e0u) inspectSpecies(ram);
    o2_0061C3E0_0x61c3e0(ram,ctx,runtime);
}
inline void inspectHunterUpdate(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x60f710u) inspectSpecies(ram);
    o2_0060F710_0x60f710(ram,ctx,runtime);
}
inline uint32_t weaponSeed = 0;
inline bool allOrdinaryItems = false;
inline ItemExclusions excludedItems{};
inline void initializePickups(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    // This entry runs after scenario item/metadata loading, before bonus items.
    // Resume labels must never apply a second permutation.
    if (ctx->pc == 0x5924e0u) {
        const char* catalogue=std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE");
        if(catalogue) {
            const auto entries=readItemCatalogue(catalogue);
            const auto count=installItemCatalogue(ram,entries);
            std::fprintf(stderr,"[MOD-GLOBAL-ITEMS-1] definitions=%u categories=weapon,ammunition,common\n",count);
        }
        const auto result = catalogue ? randomizeGlobalPickups(ram,weaponSeed,excludedItems)
                                     : shufflePickups(ram, weaponSeed, allOrdinaryItems, excludedItems);
        const char* tag = allOrdinaryItems ? "MOD-ITEM-RANDOMIZER-1" : "MOD-WEAPON-SHUFFLE-1";
        std::fprintf(stderr, "[%s] seed=%u eligible=%u changed=%u\n",
                     tag, weaponSeed, result.count, result.changed);
        for (unsigned i = 0; i < result.count; ++i)
            std::fprintf(stderr, "[%s] item=%08x %04x:%u -> %04x:%u metadata=%u\n",
                tag, result.before[i].address, result.before[i].type, result.before[i].quantity,
                result.after[i].type, result.after[i].quantity, result.after[i].metadata);
    }
    o2_005924E0_0x5924e0(ram, ctx, runtime);
}
inline void install(PS2Runtime& runtime) {
    std::fprintf(stderr,"[MOD-SESSION-3] scenario-plan\n");
    enemyDiagnostics = std::getenv("REO_TEST_ENEMIES") != nullptr;
    if (const char* seed = std::getenv("REO_MOD_ENEMY_SPAWN_SEED")) {
        const auto parsed=std::from_chars(seed,seed+std::strlen(seed),enemySeed);
        if(parsed.ec!=std::errc{} || parsed.ptr!=seed+std::strlen(seed)) throw std::runtime_error("Invalid enemy spawn seed");
        const char* pool=std::getenv("REO_MOD_ENEMY_POOL");
        const char* behaviors=std::getenv("REO_MOD_ENEMY_SOURCE_BEHAVIORS");
        if(!pool || !behaviors) throw std::runtime_error("Enemy spawn pool required");
        spawnPool=parseSpawnPool(pool,behaviors); spawnEnabled=true;
        std::fprintf(stderr,"[MOD-ENEMY-ROSTER-1] installed\n");
        std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] installed seed=%u\n",enemySeed);
    }
    if (const char* seed = std::getenv("REO_MOD_ZOMBIE_RANDOMIZER_SEED")) {
        if (spawnEnabled) throw std::runtime_error("Only one enemy randomizer can be enabled");
        const auto parsed = std::from_chars(seed, seed + std::strlen(seed), enemySeed);
        if (parsed.ec != std::errc{} || parsed.ptr != seed + std::strlen(seed))
            throw std::runtime_error("Invalid zombie randomizer seed");
        enemyEnabled = true;
        std::fprintf(stderr, "[MOD-ZOMBIE-RANDOMIZER-1] installed seed=%u\n", enemySeed);
    }
    if (enemyEnabled || spawnEnabled || enemyDiagnostics) {
        runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x6baa40u, resetEnemyShuffle);
        runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x6bb040u, initializeEnemies);
    }
    if (enemyDiagnostics) {
        runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x6055e0u, inspectDogUpdate);
        runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x61c3e0u, inspectLickerUpdate);
        runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x60f710u, inspectHunterUpdate);
    }
    if (spawnEnabled || enemyDiagnostics)
        runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x6bb9f0u, inspectEnemyActor);
    if (enemyDiagnostics || spawnEnabled) {
        runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x696300u, inspectZombieUpdate);
    }
    if(spawnEnabled) {
        runtime.registerOverlayFunction(0x570000u,0x336f574du,4u,3u,0x6ce400u,clampRandomizedNeptune);
        // Original NPC grab reactions reached by G-type and Thanatos attacks.
        // Their entry points were missing from the overlay function map.
        runtime.registerOverlayFunction(0x810000u,0x336f574du,4u,9u,0x81da80u,o9_0081DA80_0x81da80);
        for(uint32_t pc:{0x81da90u,0x81db20u,0x81db30u,0x81db40u,0x81db50u,
                         0x81db64u,0x81db7cu,0x81db94u,0x81dbacu})
            runtime.registerOverlayFunction(0x810000u,0x336f574du,4u,9u,pc,o9_0081DA90_0x81da90);
        runtime.registerFunction(0x1a0d10u,initializeModAssetHeap);
        for(unsigned i=0;i<=6;++i) runtime.registerFunction(replacementResume+i*4,continueEnemyReplacement);
    }
    const char* value = std::getenv("REO_MOD_WEAPON_SHUFFLE_SEED");
    if (const char* items = std::getenv("REO_MOD_ITEM_RANDOMIZER_SEED")) {
        if (value) throw std::runtime_error("Only one pickup randomizer can be enabled");
        value = items;
        allOrdinaryItems = true;
        if(std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE"))
            std::fprintf(stderr,"[MOD-GLOBAL-ITEMS-1] installed\n");
        if(std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE")) {
            runtime.registerFunction(0x1a9f20u,readGlobalModelBank);
            std::fprintf(stderr,"[MOD-GLOBAL-MODELS-1] installed\n");
        }
    }
    if (!value) return;
    if (const char* exclusions = std::getenv("REO_MOD_ITEM_EXCLUDE_TYPES")) {
        if (!allOrdinaryItems) throw std::runtime_error("Item exclusions require the item randomizer");
        excludedItems = parseItemExclusions(exclusions);
        std::fprintf(stderr, "[MOD-ITEM-EXCLUSIONS-1] installed\n");
    }
    const auto parsed = std::from_chars(value, value + std::strlen(value), weaponSeed);
    if (parsed.ec != std::errc{} || parsed.ptr != value + std::strlen(value))
        throw std::runtime_error("Invalid weapon shuffle seed");
    runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4u, 3u, 0x5924e0u, initializePickups);
    if (allOrdinaryItems)
        std::fprintf(stderr, "[MOD-ITEM-RANDOMIZER-1] installed seed=%u\n", weaponSeed);
    else
        std::fprintf(stderr, "[MOD-WEAPON-SHUFFLE-1] installed seed=%u\n", weaponSeed);
}
}
#endif
