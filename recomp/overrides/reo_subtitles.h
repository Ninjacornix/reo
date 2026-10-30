#pragma once
#ifndef GPR_U32
#include "ps2_runtime_macros.h"
#endif
#include "../../runtime/text/subtitles.h"
#include <stdexcept>
#include <vector>

namespace reo::subtitles {
using GuestFunction=void(*)(uint8_t*,R5900Context*,PS2Runtime*);
#if defined(REO_GAME_FILE2)
inline constexpr uint32_t allocator=0x1400d0, allocatorEnd=0x140210, drawLeaf=0x13faf0, slots=0x2f3d10;
inline constexpr uint32_t front=0x140210, custom=0x1402d0, frontReturn=0x1402a4, customReturn=0x140310;
inline constexpr std::array<uint32_t,4> spokenReturns{0x70f330,0x70f350,0x70f478,0x70f498};
inline constexpr std::array<uint32_t,2> typedReturns{0x6e7430,0x6e7454};
#else
inline constexpr uint32_t allocator=0x1b46e0, allocatorEnd=0x1b4820, drawLeaf=0x1b4100, slots=0x3151d0;
inline constexpr uint32_t front=0x1b4820, custom=0x1b48e0, frontReturn=0x1b48b4, customReturn=0x1b4920;
inline constexpr std::array<uint32_t,8> spokenReturns{0x6dfb1c,0x6dfb3c,0x6dfbe0,0x6dfc00,0x6dfcc0,0x6dfce0,0x6dfd84,0x6dfda4};
inline constexpr std::array<uint32_t,2> typedReturns{0x6b9d98,0x6b9dbc};
#endif
inline GuestFunction originalAllocator=nullptr,originalDraw=nullptr;
inline std::array<bool,32> spokenSlots{};
inline uint32_t readWord(const uint8_t* ram,uint32_t address) {
    address&=0x1fffffffu;
    uint32_t value=0;
    if(address<=PS2_RAM_SIZE-sizeof(value)) std::memcpy(&value,ram+address,sizeof(value));
    return value;
}
inline int slotIndex(uint32_t address,unsigned field) {
    address&=0x1fffffffu;
    if(address<slots+field) return -1;
    const auto offset=address-slots-field;
    return offset%0x8c==0 && offset/0x8c<32 ? int(offset/0x8c) : -1;
}
template<size_t N>
inline bool callerMatches(const uint8_t* ram,uint32_t caller,uint32_t target,const std::array<uint32_t,N>& returns) {
    for(auto address:returns)
        if(caller==address && readWord(ram,caller-8)==(0x0c000000u|(target>>2))) return true;
    return false;
}
inline void enqueue(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    // Both executables use a 0x90-byte allocator frame, saved RA at +0x80.
    // Recover the enqueue caller from guest frames, including resumed execution;
    // host call-stack scopes would lose provenance when a guest thread yields.
    const bool entry=ctx->pc==allocator;
    const uint32_t sp=GPR_U32(ctx,29)&0x1fffffffu;
    const uint32_t returnPc=entry ? GPR_U32(ctx,31) : readWord(ram,sp+0x80);
    const uint32_t callerSp=entry ? sp : sp+0x90;
    bool spoken=false;
    if(returnPc==frontReturn)
        spoken=callerMatches(ram,readWord(ram,callerSp+0x60),front,spokenReturns);
    else if(returnPc==customReturn)
        spoken=callerMatches(ram,readWord(ram,callerSp+0x10),custom,typedReturns);
    originalAllocator(ram,ctx,runtime);
    if(ctx->pc==returnPc) {
        // Returns alpha pointer (slot+10), not the base of the queue record.
        // Every successful reuse clears the previous slot's classification.
        const int index=slotIndex(GPR_U32(ctx,2),10);
        if(index>=0) spokenSlots[index]=spoken;
    }
}
inline void draw(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==drawLeaf) {
        poll();
        const int index=slotIndex(GPR_U32(ctx,7),12);
        if(index>=0 && spokenSlots[index] && !enabled.load(std::memory_order_relaxed)) {
            // Only the glyph submission is skipped. Original queue updates,
            // overlap culling, voice, typewriter state and timers still execute.
            ctx->pc=GPR_U32(ctx,31);
            return;
        }
    }
    originalDraw(ram,ctx,runtime);
}
inline void install(PS2Runtime& runtime) {
    originalAllocator=runtime.lookupFunction(allocator);
    originalDraw=runtime.lookupFunction(drawLeaf);
    if(!originalAllocator || !originalDraw || originalAllocator==enqueue || originalDraw==draw)
        throw std::runtime_error("Subtitle render services unavailable");
    // Register all existing allocator continuations as well as its entry.
    std::vector<uint32_t> aliases;
    for(uint32_t pc=allocator;pc<allocatorEnd;pc+=4)
        if(runtime.hasFunction(pc) && runtime.lookupFunction(pc)==originalAllocator) aliases.push_back(pc);
    for(auto pc:aliases) runtime.registerFunction(pc,enqueue);
    runtime.registerFunction(drawLeaf,draw);
    spokenSlots.fill(false);
    initialize();
}
}
