#pragma once
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "../../runtime/mods/weapon_shuffle.h"
#include "../../runtime/mods/global_items.h"
#include "../../runtime/mods/enemy_randomizer.h"
#include "../../runtime/mods/enemy_spawn_randomizer.h"
#include <charconv>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#if defined(REO_GAME_FILE2)
#include "reo_weapon_motions.h"
extern void o2_005B0900_0x5b0900(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006E80B0_0x6e80b0(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006E8710_0x6e8710(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006E9300_0x6e9300(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_006C69D0_0x6c69d0(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_00625910_0x625910(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_00648FE0_0x648fe0(uint8_t*, R5900Context*, PS2Runtime*);
extern void o2_0063ADF0_0x63adf0(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_001353E0_0x1353e0(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_001ED8E0_0x1ed8e0(uint8_t*, R5900Context*, PS2Runtime*);
namespace reo::mods {
inline void readGlobalModelBank(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    const char* catalogue=std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE");
    const uint32_t source=GPR_U32(ctx,5),destination=GPR_U32(ctx,6);
    std::string path;
    if(catalogue && source<PS2_RAM_SIZE) {
        for(unsigned i=0;i<256 && source+i<PS2_RAM_SIZE && ram[source+i];++i) {
            char c=char(ram[source+i]);path+=c>='a' && c<='z' ? char(c-'a'+'A') : c;
        }
    }
    if(catalogue && readGlobalWeaponMotions(ram,ctx,path,destination,catalogue)) return;
    const auto position=path.find("OBJS");
    if(position!=std::string::npos && position+10<=path.size() &&
       (path.substr(position+6,4)==".NBD" || path.substr(position+6,4)==".MAT")) {
        const auto name=path.substr(position,10);
        static std::map<std::string,std::vector<uint8_t>> cached;
        auto& bytes=cached[name];
        if(bytes.empty()) {
            const auto folder=std::filesystem::path(std::u8string(reinterpret_cast<const char8_t*>(catalogue))).parent_path()/"global-models";
            std::ifstream input(folder/name,std::ios::binary|std::ios::ate);
            const auto length=input ? std::streamoff(input.tellg()) : -1;
            if(length<16 || length>2*1024*1024) throw std::runtime_error("Global item model bank is missing or too large");
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
    sub_001353E0_0x1353e0(ram,ctx,runtime);
}
inline bool enemyEnabled = false, enemyPending = true, enemyDiagnostics = false;
inline bool spawnEnabled = false;
inline SpawnPool spawnPool{};
inline SpawnDecisions spawnDecisions{};
inline std::array<bool,256> completedSpawnEntrances{};
inline uint32_t enemySeed = 0;

inline PS2Runtime::RecompiledFunction originalPacketEnqueue = nullptr;
inline PS2Runtime::RecompiledFunction originalCombinedPacketEnqueue = nullptr;
inline std::atomic<unsigned> zeroPacketEnqueueReports{0};
inline void reportZeroPacketEnqueue(uint8_t* ram,R5900Context* ctx,uint32_t entry,unsigned argument) {
    if(ctx->pc!=entry || GPR_U32(ctx,argument)!=0 || !enemyDiagnostics) return;
    if(zeroPacketEnqueueReports.fetch_add(1,std::memory_order_relaxed)>=8) return;
    std::fprintf(stderr,"[TEST-ENEMY-ZERO-ENQUEUE] entry=%08x ra=%08x sp=%08x "
        "a0=%08x a1=%08x a2=%08x a3=%08x "
        "s0=%08x s1=%08x s2=%08x s3=%08x s4=%08x s5=%08x s6=%08x s7=%08x scenario=%u room=%u\n",
        entry,GPR_U32(ctx,31),GPR_U32(ctx,29),
        GPR_U32(ctx,4),GPR_U32(ctx,5),GPR_U32(ctx,6),GPR_U32(ctx,7),
        GPR_U32(ctx,16),GPR_U32(ctx,17),GPR_U32(ctx,18),GPR_U32(ctx,19),
        GPR_U32(ctx,20),GPR_U32(ctx,21),GPR_U32(ctx,22),GPR_U32(ctx,23),
        unsigned(reo::cheats::half(ram,0x30095a)),unsigned(reo::cheats::half(ram,0x30095c)));
}
inline void inspectPacketEnqueue(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    reportZeroPacketEnqueue(ram,ctx,0x1dd5b0u,4);
    originalPacketEnqueue(ram,ctx,runtime);
}
inline void inspectCombinedPacketEnqueue(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    reportZeroPacketEnqueue(ram,ctx,0x1dd670u,5);
    originalCombinedPacketEnqueue(ram,ctx,runtime);
}

struct PendingEnemy { bool waiting=false; SpawnProfile profile{}; uint8_t sourceType{},sourceModel{},spawn{}; };
inline std::array<PendingEnemy,50> pendingEnemies{};
inline constexpr uint32_t replacementResume=0x1ff1000u;
inline constexpr uint32_t enemyScratchBase=0x03800000u,enemyScratchBytes=0x00800000u;
inline constexpr uint32_t enemyAssetHeapBytes=enemyScratchBase-PS2_RAM_SIZE;
static_assert(PS2_RAM_SIZE+enemyAssetHeapBytes==enemyScratchBase);
static_assert(uint64_t(enemyScratchBase)+enemyScratchBytes==2u*PS2_RAM_SIZE);
static_assert(0x200000u+0x10000u<enemyScratchBytes);
inline void restoreEnemyReplacementScratch(uint8_t* ram,uint32_t sp) {
    reo::cheats::setWord(ram,0x30099c,reo::cheats::word(ram,sp+24));
    reo::cheats::setWord(ram,0x303738,reo::cheats::word(ram,sp+28));
    reo::cheats::setWord(ram,0x303740,reo::cheats::word(ram,sp+152));
}
inline void initializeModAssetHeap(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x1ed8e0u && spawnEnabled) {
        if(ps2RamBackingBytes!=2u*PS2_RAM_SIZE) throw std::runtime_error("Enemy mods require the native asset bank");
        SET_GPR_U32(ctx,4,PS2_RAM_SIZE); SET_GPR_U32(ctx,5,enemyAssetHeapBytes);
        reo::cheats::setWord(ram,0x358cf8,PS2_RAM_SIZE);
        reo::cheats::setWord(ram,0x358cfc,enemyAssetHeapBytes);
        std::fprintf(stderr,"[MOD-ENEMY-ASSETS-1] base=02000000 bytes=25165824 scratch=03800000 scratchBytes=8388608\n");
    }
    sub_001ED8E0_0x1ed8e0(ram,ctx,runtime);
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
    try {
    switch((ctx->pc-replacementResume)/4) {
    case 0:
        SET_GPR_U32(ctx,4,a); SET_GPR_U32(ctx,5,sp+32);
        if(!call(0x6e97c0,5)) return;
        [[fallthrough]];
    case 5:
        // Reapply the native spawn's target-priority setup as the room loader
        // does, without re-entering our selection hook for this same actor.
        SET_GPR_U32(ctx,4,a); SET_GPR_U32(ctx,31,replacementResume+6*4);
        ctx->pc=0x6e9300;
        o2_006E9300_0x6e9300(ram,ctx,runtime);
        if(ctx->pc!=replacementResume+6*4) return;
        [[fallthrough]];
    case 6:
        std::memcpy(ram+a+0x38,ram+sp+128,12);
        std::memcpy(ram+a+0x90,ram+sp+144,8);
        SET_GPR_U32(ctx,4,a);
        if(!call(0x144aa0,1)) return;
        [[fallthrough]];
    case 1:
        ram[a+0x33]=uint8_t(GPR_U32(ctx,2));ram[a+0x550]=0;
        // Native 136610 reads complete enemy NBDs through 30099C. The stock
        // buffer overlaps the live UI packet workspace at +190000; room loads
        // initialize that workspace afterwards, but deferred handoffs cannot.
        // Keep the native scratch aliases redirected across asynchronous I/O.
        if(ps2RamBackingBytes!=uint64_t(enemyScratchBase)+enemyScratchBytes)
            throw std::runtime_error("Enemy replacement scratch exceeds the native asset bank");
        setWord(ram,0x30099c,enemyScratchBase);
        setWord(ram,0x303738,enemyScratchBase+0x10000);
        setWord(ram,0x303740,enemyScratchBase);
        SET_GPR_U32(ctx,4,ram[a+0x549]); SET_GPR_U32(ctx,5,ram[a+0x31]);
        SET_GPR_U32(ctx,6,ram[a+3]);SET_GPR_U32(ctx,7,half(ram,a+0xbd2));SET_GPR_U32(ctx,8,0);
        if(!call(0x6e7e00,2)) return;
        [[fallthrough]];
    case 2: {
        const auto model=word(ram,a+0x34);
        setWord(ram,model+0x1460,0);setWord(ram,model+0x1464,0);
        SET_GPR_U32(ctx,4,a);SET_GPR_U32(ctx,5,2);SET_GPR_U32(ctx,6,ram[a+3]);
        if(!call(0x393c40,3)) return;
        [[fallthrough]];
    }
    case 3:
        if(GPR_U32(ctx,2)) {
            SET_GPR_U32(ctx,4,a);SET_GPR_U32(ctx,5,ram[a+0x31]+4);
            if(!call(0x393e90,4)) return;
        }
        [[fallthrough]];
    case 4: {
        restoreEnemyReplacementScratch(ram,sp);
        const auto model=word(ram,a+0x34);
        if(enemyDiagnostics) std::fprintf(stderr,"[TEST-ENEMY-RESOURCE] actor=%08x slot=%u model=%08x geometry=%08x motion=%08x\n",a,ram[a+0x31],model,word(ram,model+0x808),word(ram,a+0x51c));
        const auto bones=half(ram,model+0x812);
        if(bones>128) throw std::runtime_error("Invalid replacement skeleton");
        std::memset(ram+a+0xf4,1,bones);
        const auto slot=ram[0x4db470+ram[a+3]];
        if(slot>=6) throw std::runtime_error("Replacement animation did not load");
        ram[a+0x54a]=ram[a+3];
        setWord(ram,a+0x51c,0x4df200+slot*0xc84);
        const auto pose=0x4dda70+slot*0x3ec;
        setWord(ram,a+0x514,ram[pose+1] ? pose : 0);
        ram[a+0x522]=ram[0x4df200+slot*0xc84+1];
        // Crows and wasps have a scene-specific flight path selected by +4.
        // A foreign room lacks its flight ceiling/script setup: crows stay at
        // floor height and wasps enter a scripted exit. Use native free flight
        // for these replacements; their AI still handles collision and damage.
        if(ram[a+3]==5 || ram[a+3]==6) ram[a+4]=0;
        ram[a+8]=ram[a+9]=ram[a+10]=ram[a+11]=0;
        completedSpawnEntrances[ram[a+0xbb0]]=true;
        std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] ready actor=%08x spawn=%u type=%u model=%u bones=%u animation=%u callback=%08x\n",
            a,ram[a+0xbb0],ram[a+3],half(ram,a+0xbd2),bones,slot,word(ram,a+0x14));
        ctx->r[16]=_mm_loadu_si128(reinterpret_cast<const __m128i*>(ram+sp));
        uint64_t ra;std::memcpy(&ra,ram+sp+16,8);SET_GPR_U64(ctx,31,ra);
        SET_GPR_U32(ctx,29,sp+160);ctx->pc=uint32_t(ra);
        return;
    }
    default: throw std::runtime_error("Invalid enemy replacement continuation");
    }
    } catch(...) {
        restoreEnemyReplacementScratch(ram,sp);
        throw;
    }
}
inline bool releasePendingEnemy(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime,uint32_t a) {
    using namespace reo::cheats;
    if(!spawnEnabled || !enemyActorAddress(a)) return false;
    auto& pending=pendingEnemies[(a-0x44de90)/0xdb0];
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
    setWord(ram,sp+24,word(ram,0x30099c));
    setWord(ram,sp+28,word(ram,0x303738));
    setWord(ram,sp+152,word(ram,0x303740));
    std::memcpy(ram+sp+32,ram+0x7aff80+pending.spawn*96,96);
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
    std::memset(ram+a,0,0xdb0);
    ram[a]=1;ram[a+2]=2;ram[a+3]=pending.profile.type;ram[a+6]=uint8_t((a-0x44de90)/0xdb0);
    setWord(ram,a+0x14,callback);setWord(ram,a+0x18,rendererCallback);
    setWord(ram,a+0x1c,previous);setWord(ram,a+0x20,nextActor);
    ram[a+0x31]=renderSlot;setWord(ram,a+0x34,render);setHalf(ram,a+0x1e2,room);
    std::memset(ram+a+0xce4,0xff,4);ram[a+0xcba]=ram[a+0xcbb]=0xff;
    SET_GPR_U32(ctx,29,sp);SET_GPR_U32(ctx,16,a);ctx->pc=replacementResume;
    continueEnemyReplacement(ram,ctx,runtime);return true;
}
inline void resetEnemyShuffle(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    // 6e80b0 reloads the whole scenario spawn table. Room initialization at
    // 6e8710 only clears transient actor slots, and must not discard choices.
    if (ctx->pc == 0x6e80b0u) { enemyPending = true; pendingEnemies={}; spawnDecisions.reset(); completedSpawnEntrances={}; }
    o2_006E80B0_0x6e80b0(ram, ctx, runtime);
}
inline void initializeEnemies(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    const bool firstInitialization=enemyPending && ctx->pc==0x6e8710u;
    if (enemyPending && ctx->pc == 0x6e8710u) {
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
            const unsigned count = ram[0x4db44e];
            std::fprintf(stderr, "[TEST-ENEMIES] table count=%u\n", count);
            for (unsigned i = 0; i < count; ++i) {
                const auto a = 0x7aff80u + i * 96;
                std::fprintf(stderr, "[TEST-ENEMIES] record=%08x bytes=", a);
                for (unsigned b = 0; b < 96; ++b) std::fprintf(stderr, "%02x", ram[a + b]);
                std::fprintf(stderr, "\n");
            }
        }
    }
    if(spawnEnabled && ctx->pc==0x6e8710u) {
        pendingEnemies={};
        const auto room=reo::cheats::half(ram,0x30095c);
        // Developer compatibility fixture: add an independent ordinary spawn
        // through the native constructor. Existing scenario actors/scripts are
        // unchanged. This branch is never enabled by an ordinary mod launch.
        if(firstInitialization && enemyDiagnostics && std::getenv("REO_TEST_ENEMY_PROBE")) {
            const unsigned count=ram[0x4db44e];
            const unsigned start=ram[0x7b6000+room],roomCount=ram[0x7b5f80+room],probe=start+roomCount;
            if(probe>=254 || !roomCount) throw std::runtime_error("No native room-group slot for roster probe");
            const auto record=0x7aff80+probe*96;
            // Extend this room's contiguous group into the next, currently
            // inactive room slot. Never alter this room's scripted actor IDs.
            // The fixture ends in this room and is not a progression test.
            std::memcpy(ram+record,ram+0x7aff80+start*96,96);
            ram[record]=ram[record+0x27]=uint8_t(probe);ram[record+2]=1;ram[record+3]=9;
            ram[record+0x22]=uint8_t(room);
            ram[record+0x26]=ram[record+0x2a]=ram[record+0x2b]=0;
            reo::cheats::setWord(ram,record+0x10,8500);reo::cheats::setWord(ram,record+0x18,13150);
            reo::cheats::setHalf(ram,record+0x1c,700);reo::cheats::setHalf(ram,record+0x1e,700);
            ram[0x7b5f80+room]=uint8_t(roomCount+1);
            ram[0x4db44e]=uint8_t(std::max(count,probe+1));
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
                reo::cheats::half(ram,0x30095a),enemySeed,ram[0x4db44e]);
            for(unsigned id=0;id<ram[0x4db44e];++id) {
                const int choice=spawnDecisions.profiles[id];
                if(choice<0) continue;
                const auto& p=spawnPool.profiles[choice];
                std::fprintf(stderr,"[MOD-ENEMY-PLAN-3] spawn=%u type=%u model=%u hp=%u behavior=%u posture=%u\n",
                    id,p.type,p.model,p.health,p.behavior,p.posture);
            }
        }
    }
    o2_006E8710_0x6e8710(ram,ctx,runtime);
}
inline void inspectEnemyActor(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    if (ctx->pc == 0x6e9300u) {
        const uint32_t a = uint32_t(_mm_cvtsi128_si32(ctx->r[4]));
        if(enemyActorAddress(a)) {
            pendingEnemies[(a-0x44de90)/0xdb0]={};
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
                    reo::cheats::half(ram,0x30095a),reo::cheats::half(ram,0x30095c),ram[a+0xbb0],p.type,p.model);
                std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] actor=%08x spawn=%u source=%u:%u behavior=%u replacement=%u:%u hp=%u callback=%08x\n",
                    a,ram[a+0xbb0],ram[a+3],reo::cheats::half(ram,a+0xbd2),ram[a+0xc48],p.type,p.model,p.health,callback);
                auto& pending=pendingEnemies[(a-0x44de90)/0xdb0];
                pending={};
                if(ram[a+3]==1 && (p.type!=ram[a+3] || p.model!=reo::cheats::half(ram,a+0xbd2))) {
                    pending={true,p,ram[a+3],uint8_t(reo::cheats::half(ram,a+0xbd2)),ram[a+0xbb0]};
                    std::fprintf(stderr,"[MOD-ENEMY-SPAWN-1] deferred actor=%08x behavior=%u\n",a,ram[a+0xc48]);
                } else if(ram[a+0xc48]==0 &&
                          !(spawnDecisions.planned && spawnDecisions.scripted[ram[a+0xbb0]])) {
                    // Online reconstruction can clear an entrance's behavior on
                    // only one peer. Keep its original scripted health/profile.
                    applySpawnProfile(ram,a,p,callback);
                    const auto metadata=reo::cheats::word(ram,0x3a2360+p.type*8)+p.model*16;
                    for(unsigned offset:{0xb4u,0xb8u,0xbcu}) reo::cheats::setWord(ram,a+offset,reo::cheats::word(ram,metadata+8));
                    ram[a+0xc41]=ram[0x7862f0+p.type];
                }
            }
        }
        if (enemyDiagnostics && enemyActorAddress(a))
            std::fprintf(stderr, "[TEST-ENEMIES] actor=%08x type=%u variant=%u spawn=%u hp=%u callback=%08x\n",
                a, ram[a + 3], reo::cheats::half(ram, a + 0xbd2), ram[a + 0xbb0],
                reo::cheats::half(ram, a + 0x540), reo::cheats::word(ram, a + 0x14));
    }
    o2_006E9300_0x6e9300(ram, ctx, runtime);
}
inline void inspectSpecies(uint8_t* ram) {
    static auto last=std::chrono::steady_clock::time_point{};
    const auto now=std::chrono::steady_clock::now();
    if(!enemyDiagnostics || now-last<std::chrono::seconds(2)) return;
    last=now;
    const auto unixMs=std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    for(uint32_t a=0x44de90;a<0x478af0;a+=0xdb0) {
        if(ram[a]!=1 || ram[a+2]!=2) continue;
        float xyz[3];std::memcpy(xyz,ram+a+0x38,12);
        std::fprintf(stderr,"[TEST-ENEMY-SPECIES] actor=%08x spawn=%u type=%u model=%u hp=%u state=%u/%u/%u xyz=%.2f,%.2f,%.2f callback=%08x unixMs=%lld room=%u\n",
            a,ram[a+0xbb0],ram[a+3],reo::cheats::half(ram,a+0xbd2),reo::cheats::half(ram,a+0x540),
            ram[a+8],ram[a+9],ram[a+10],xyz[0],xyz[1],xyz[2],reo::cheats::word(ram,a+0x14),
            static_cast<long long>(unixMs),reo::cheats::half(ram,0x30095c));
    }
}
inline void inspectZombieUpdate(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    static std::array<std::chrono::steady_clock::time_point, 50> last{};
    static uint16_t playerHp = 0;
    const auto now = std::chrono::steady_clock::now();
    if (ctx->pc == 0x6c69d0u) {
        if(releasePendingEnemy(ram,ctx,runtime,GPR_U32(ctx,4))) return;
        if(!enemyDiagnostics) { o2_006C69D0_0x6c69d0(ram,ctx,runtime); return; }
        inspectSpecies(ram);
        const auto hp = reo::cheats::half(ram, 0x4c6350u);
        if (playerHp && hp < playerHp)
            std::fprintf(stderr, "[TEST-ENEMIES] PLAYER DAMAGE before=%u after=%u state=%u/%u\n",
                playerHp, hp, ram[0x4c5e18], ram[0x4c5e19]);
        playerHp = hp;
        const uint32_t a = uint32_t(_mm_cvtsi128_si32(ctx->r[4]));
        if (a >= 0x44de90u && a + 0xdb0u <= 0x478af0u && (a - 0x44de90u) % 0xdb0u == 0 &&
            now - last[(a - 0x44de90u) / 0xdb0u] >= std::chrono::seconds(5)) {
            last[(a - 0x44de90u) / 0xdb0u] = now;
            float x, z;
            std::memcpy(&x, ram + a + 0x38, 4); std::memcpy(&z, ram + a + 0x40, 4);
            std::fprintf(stderr, "[TEST-ENEMIES] update actor=%08x spawn=%u variant=%u state=%u/%u/%u hp=%u xyz=%.2f,%.2f playerHp=%u playerState=%u/%u\n",
                a, ram[a + 0xbb0], reo::cheats::half(ram, a + 0xbd2), ram[a+8], ram[a+9], ram[a+10],
                reo::cheats::half(ram,a+0x540), x, z, reo::cheats::half(ram,0x4c6350), ram[0x4c5e18], ram[0x4c5e19]);
        }
    }
    o2_006C69D0_0x6c69d0(ram, ctx, runtime);
}
inline void inspectDogUpdate(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    static std::array<std::chrono::steady_clock::time_point, 50> last{};
    if(ctx->pc==0x625910u) {
        const uint32_t a=uint32_t(_mm_cvtsi128_si32(ctx->r[4]));
        const auto now=std::chrono::steady_clock::now();
        if(enemyDiagnostics && a>=0x44de90u && a+0xdb0u<=0x478af0u && (a-0x44de90u)%0xdb0u==0 &&
           now-last[(a-0x44de90u)/0xdb0u]>=std::chrono::seconds(2)) {
            last[(a-0x44de90u)/0xdb0u]=now;
            float x,z; std::memcpy(&x,ram+a+0x38,4); std::memcpy(&z,ram+a+0x40,4);
            std::fprintf(stderr,"[TEST-ENEMIES] dog actor=%08x spawn=%u variant=%u state=%u/%u/%u hp=%u xyz=%.2f,%.2f playerHp=%u\n",
                a,ram[a+0xbb0],reo::cheats::half(ram,a+0xbd2),ram[a+8],ram[a+9],ram[a+10],
                reo::cheats::half(ram,a+0x540),x,z,reo::cheats::half(ram,0x4c6350));
        }
    }
    o2_00625910_0x625910(ram,ctx,runtime);
}
inline void inspectLickerUpdate(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x648fe0u) inspectSpecies(ram);
    o2_00648FE0_0x648fe0(ram,ctx,runtime);
}
inline void inspectHunterUpdate(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x63adf0u) inspectSpecies(ram);
    o2_0063ADF0_0x63adf0(ram,ctx,runtime);
}
inline uint32_t weaponSeed = 0;
inline bool allOrdinaryItems = false;
inline ItemExclusions excludedItems{};
inline void initializePickups(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    // This entry runs after scenario item/metadata loading, before bonus items.
    // Resume labels must never apply a second permutation.
    if (ctx->pc == 0x5b0900u) {
        const char* catalogue=std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE");
        ItemAvailability floorModels{};
        if(catalogue) {
            char name[64];
            std::snprintf(name,sizeof(name),"global-items-%03u.bin",
                          unsigned(reo::cheats::half(ram,gameLayout.scenario)));
            const auto folder=std::filesystem::path(std::u8string(reinterpret_cast<const char8_t*>(catalogue))).parent_path();
            const auto path=(folder/name).u8string();
            const auto entries=readItemCatalogue(reinterpret_cast<const char*>(path.c_str()));
            auto floorPath=folder/name;floorPath.replace_extension(".floor");
            std::ifstream floors(floorPath,std::ios::binary);
            char magic[8]{};
            if(!floors.read(magic,8) || std::memcmp(magic,"RGIF1\0\0\0",8) ||
               !floors.read(reinterpret_cast<char*>(floorModels.data()),floorModels.size()) ||
               floors.peek()!=std::char_traits<char>::eof() ||
               std::any_of(floorModels.begin(),floorModels.end(),[](uint8_t value){return value>1;}))
                throw std::runtime_error("Invalid File #2 floor-model availability");
            const auto count=installItemCatalogue(ram,entries);
            std::fprintf(stderr,"[MOD-GLOBAL-ITEMS-1] definitions=%u categories=weapon,ammunition,common\n",count);
        }
        const auto result = catalogue ? randomizeGlobalPickups(ram,weaponSeed,excludedItems,&floorModels)
                                     : shufflePickups(ram, weaponSeed, allOrdinaryItems, excludedItems);
        const char* tag = allOrdinaryItems ? "MOD-ITEM-RANDOMIZER-1" : "MOD-WEAPON-SHUFFLE-1";
        std::fprintf(stderr, "[%s] seed=%u eligible=%u changed=%u\n",
                     tag, weaponSeed, result.count, result.changed);
        for (unsigned i = 0; i < result.count; ++i)
            std::fprintf(stderr, "[%s] item=%08x %04x:%u -> %04x:%u metadata=%u\n",
                tag, result.before[i].address, result.before[i].type, result.before[i].quantity,
                result.after[i].type, result.after[i].quantity, result.after[i].metadata);
    }
    o2_005B0900_0x5b0900(ram, ctx, runtime);
}
inline void install(PS2Runtime& runtime) {
    std::fprintf(stderr,"[MOD-FILE2-1] installed\n");
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
        runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x6e80b0u, resetEnemyShuffle);
        runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x6e8710u, initializeEnemies);
    }
    if (enemyDiagnostics) {
        runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x625910u, inspectDogUpdate);
        runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x648fe0u, inspectLickerUpdate);
        runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x63adf0u, inspectHunterUpdate);
    }
    if (spawnEnabled || enemyDiagnostics)
        runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x6e9300u, inspectEnemyActor);
    if (enemyDiagnostics || spawnEnabled) {
        runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x6c69d0u, inspectZombieUpdate);
    }
    if(spawnEnabled) {
        // File #2 has no Neptune callback. Its original NPC reaction entries
        // are registered by the generated overlay; retain that native dispatch.
        runtime.registerFunction(0x1ed8e0u,initializeModAssetHeap);
        for(unsigned i=0;i<=6;++i) runtime.registerFunction(replacementResume+i*4,continueEnemyReplacement);
    }
    if(spawnEnabled && enemyDiagnostics) {
        const auto enqueue=runtime.lookupFunction(0x1dd5b0u);
        const auto combined=runtime.lookupFunction(0x1dd670u);
        if(enqueue!=inspectPacketEnqueue) originalPacketEnqueue=enqueue;
        if(combined!=inspectCombinedPacketEnqueue) originalCombinedPacketEnqueue=combined;
        runtime.registerFunction(0x1dd5b0u,inspectPacketEnqueue);
        runtime.registerFunction(0x1dd670u,inspectCombinedPacketEnqueue);
    }
    const char* value = std::getenv("REO_MOD_WEAPON_SHUFFLE_SEED");
    if (const char* items = std::getenv("REO_MOD_ITEM_RANDOMIZER_SEED")) {
        if (value) throw std::runtime_error("Only one pickup randomizer can be enabled");
        value = items;
        allOrdinaryItems = true;
        if(std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE"))
            std::fprintf(stderr,"[MOD-GLOBAL-ITEMS-1] installed\n");
        if(std::getenv("REO_MOD_GLOBAL_ITEM_CATALOGUE")) {
            runtime.registerFunction(0x1353e0u,readGlobalModelBank);
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
    runtime.registerOverlayFunction(0x58d000u, 0x336f574du, 4u, 3u, 0x5b0900u, initializePickups);
    if (allOrdinaryItems)
        std::fprintf(stderr, "[MOD-ITEM-RANDOMIZER-1] installed seed=%u\n", weaponSeed);
    else
        std::fprintf(stderr, "[MOD-WEAPON-SHUFFLE-1] installed seed=%u\n", weaponSeed);
}
}
#endif
