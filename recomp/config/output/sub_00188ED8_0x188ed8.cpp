#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188ED8
// Address: 0x188ed8 - 0x189120
void sub_00188ED8_0x188ed8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188ED8_0x188ed8");
#endif

    switch (ctx->pc) {
        case 0x188f00u: goto label_188f00;
        case 0x188f08u: goto label_188f08;
        case 0x188f9cu: goto label_188f9c;
        case 0x189018u: goto label_189018;
        case 0x18902cu: goto label_18902c;
        case 0x189088u: goto label_189088;
        case 0x18909cu: goto label_18909c;
        case 0x1890f8u: goto label_1890f8;
        case 0x18910cu: goto label_18910c;
        default: break;
    }

    ctx->pc = 0x188ed8u;

    // 0x188ed8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x188ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x188edc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x188edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x188ee0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x188ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x188ee4: 0x3c120029  lui         $s2, 0x29
    ctx->pc = 0x188ee4u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)41 << 16));
    // 0x188ee8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x188ee8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188eec: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x188eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x188ef0: 0x26444080  addiu       $a0, $s2, 0x4080
    ctx->pc = 0x188ef0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16512));
    // 0x188ef4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x188ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x188ef8: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x188EF8u;
    SET_GPR_U32(ctx, 31, 0x188F00u);
    ctx->pc = 0x188EFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188EF8u;
            // 0x188efc: 0x24850080  addiu       $a1, $a0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188F00u; }
        if (ctx->pc != 0x188F00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188F00u; }
        if (ctx->pc != 0x188F00u) { return; }
    }
    ctx->pc = 0x188F00u;
label_188f00:
    // 0x188f00: 0xc047598  jal         func_11D660
    ctx->pc = 0x188F00u;
    SET_GPR_U32(ctx, 31, 0x188F08u);
    ctx->pc = 0x188F04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188F00u;
            // 0x188f04: 0x108080  sll         $s0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188F08u; }
        if (ctx->pc != 0x188F08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188F08u; }
        if (ctx->pc != 0x188F08u) { return; }
    }
    ctx->pc = 0x188F08u;
label_188f08:
    // 0x188f08: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x188f08u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x188f0c: 0x26464080  addiu       $a2, $s2, 0x4080
    ctx->pc = 0x188f0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 16512));
    // 0x188f10: 0x24654100  addiu       $a1, $v1, 0x4100
    ctx->pc = 0x188f10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 16640));
    // 0x188f14: 0x68c20007  ldl         $v0, 0x7($a2)
    ctx->pc = 0x188f14u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188f18: 0x6cc20000  ldr         $v0, 0x0($a2)
    ctx->pc = 0x188f18u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188f1c: 0x68c4000f  ldl         $a0, 0xF($a2)
    ctx->pc = 0x188f1cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188f20: 0x6cc40008  ldr         $a0, 0x8($a2)
    ctx->pc = 0x188f20u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188f24: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x188f24u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f28: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x188f28u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f2c: 0xb0a4000f  sdl         $a0, 0xF($a1)
    ctx->pc = 0x188f2cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f30: 0xb4a40008  sdr         $a0, 0x8($a1)
    ctx->pc = 0x188f30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f34: 0x68c20017  ldl         $v0, 0x17($a2)
    ctx->pc = 0x188f34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188f38: 0x6cc20010  ldr         $v0, 0x10($a2)
    ctx->pc = 0x188f38u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188f3c: 0x68c4001f  ldl         $a0, 0x1F($a2)
    ctx->pc = 0x188f3cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188f40: 0x6cc40018  ldr         $a0, 0x18($a2)
    ctx->pc = 0x188f40u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188f44: 0xb0a20017  sdl         $v0, 0x17($a1)
    ctx->pc = 0x188f44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f48: 0xb4a20010  sdr         $v0, 0x10($a1)
    ctx->pc = 0x188f48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f4c: 0xb0a4001f  sdl         $a0, 0x1F($a1)
    ctx->pc = 0x188f4cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f50: 0xb4a40018  sdr         $a0, 0x18($a1)
    ctx->pc = 0x188f50u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f54: 0x68c20027  ldl         $v0, 0x27($a2)
    ctx->pc = 0x188f54u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188f58: 0x6cc20020  ldr         $v0, 0x20($a2)
    ctx->pc = 0x188f58u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188f5c: 0x68c4002f  ldl         $a0, 0x2F($a2)
    ctx->pc = 0x188f5cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188f60: 0x6cc40028  ldr         $a0, 0x28($a2)
    ctx->pc = 0x188f60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188f64: 0xb0a20027  sdl         $v0, 0x27($a1)
    ctx->pc = 0x188f64u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f68: 0xb4a20020  sdr         $v0, 0x20($a1)
    ctx->pc = 0x188f68u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f6c: 0xb0a4002f  sdl         $a0, 0x2F($a1)
    ctx->pc = 0x188f6cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f70: 0xb4a40028  sdr         $a0, 0x28($a1)
    ctx->pc = 0x188f70u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f74: 0x68c20037  ldl         $v0, 0x37($a2)
    ctx->pc = 0x188f74u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188f78: 0x6cc20030  ldr         $v0, 0x30($a2)
    ctx->pc = 0x188f78u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188f7c: 0x68c4003f  ldl         $a0, 0x3F($a2)
    ctx->pc = 0x188f7cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188f80: 0x6cc40038  ldr         $a0, 0x38($a2)
    ctx->pc = 0x188f80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188f84: 0xb0a20037  sdl         $v0, 0x37($a1)
    ctx->pc = 0x188f84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f88: 0xb4a20030  sdr         $v0, 0x30($a1)
    ctx->pc = 0x188f88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f8c: 0xb0a4003f  sdl         $a0, 0x3F($a1)
    ctx->pc = 0x188f8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f90: 0xb4a40038  sdr         $a0, 0x38($a1)
    ctx->pc = 0x188f90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188f94: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x188F94u;
    SET_GPR_U32(ctx, 31, 0x188F9Cu);
    ctx->pc = 0x188F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188F94u;
            // 0x188f98: 0x24714100  addiu       $s1, $v1, 0x4100 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 16640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188F9Cu; }
        if (ctx->pc != 0x188F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188F9Cu; }
        if (ctx->pc != 0x188F9Cu) { return; }
    }
    ctx->pc = 0x188F9Cu;
label_188f9c:
    // 0x188f9c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x188f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188fa0: 0x2118021  addu        $s0, $s0, $s1
    ctx->pc = 0x188fa0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x188fa4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x188fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x188fa8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x188fa8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x188fac: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x188facu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x188fb0: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x188fb0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x188fb4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x188fb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188fb8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x188fb8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x188fbc: 0x83100a  movz        $v0, $a0, $v1
    ctx->pc = 0x188fbcu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x188fc0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x188fc0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x188fc4: 0x3e00008  jr          $ra
    ctx->pc = 0x188FC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188FC4u;
            // 0x188fc8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188F00u: goto label_188f00;
            case 0x188F08u: goto label_188f08;
            case 0x188F9Cu: goto label_188f9c;
            case 0x189018u: goto label_189018;
            case 0x18902Cu: goto label_18902c;
            case 0x189030u: goto label_189030;
            case 0x189088u: goto label_189088;
            case 0x18909Cu: goto label_18909c;
            case 0x1890A0u: goto label_1890a0;
            case 0x1890F8u: goto label_1890f8;
            case 0x18910Cu: goto label_18910c;
            case 0x189110u: goto label_189110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188FCCu;
    // 0x188fcc: 0x0  nop
    ctx->pc = 0x188fccu;
    // NOP
    // 0x188fd0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x188fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x188fd4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188fd8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x188fdc: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x188fdcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x188fe0: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x188fe0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x188fe4: 0xac440c00  sw          $a0, 0xC00($v0)
    ctx->pc = 0x188fe4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 4));
    // 0x188fe8: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188fe8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188fec: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x188fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x188ff0: 0x24640b88  addiu       $a0, $v1, 0xB88
    ctx->pc = 0x188ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2952));
    // 0x188ff4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x188ff4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x188ff8: 0x34a51315  ori         $a1, $a1, 0x1315
    ctx->pc = 0x188ff8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4885);
    // 0x188ffc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x188ffcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189000: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x189000u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189004: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x189004u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189008: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x189008u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18900c: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x18900cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189010: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189010u;
    SET_GPR_U32(ctx, 31, 0x189018u);
    ctx->pc = 0x189014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189010u;
            // 0x189014: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189018u; }
        if (ctx->pc != 0x189018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189018u; }
        if (ctx->pc != 0x189018u) { return; }
    }
    ctx->pc = 0x189018u;
label_189018:
    // 0x189018: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x189018u;
    {
        const bool branch_taken_0x189018 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x189018) {
            ctx->pc = 0x18901Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x189018u;
            // 0x18901c: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x189030u;
            goto label_189030;
        }
    }
    ctx->pc = 0x189020u;
    // 0x189020: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189020u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189024: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189024u;
    SET_GPR_U32(ctx, 31, 0x18902Cu);
    ctx->pc = 0x189028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189024u;
            // 0x189028: 0x24841980  addiu       $a0, $a0, 0x1980 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18902Cu; }
        if (ctx->pc != 0x18902Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18902Cu; }
        if (ctx->pc != 0x18902Cu) { return; }
    }
    ctx->pc = 0x18902Cu;
label_18902c:
    // 0x18902c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18902cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_189030:
    // 0x189030: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x189030u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189034: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x189034u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189038: 0x3e00008  jr          $ra
    ctx->pc = 0x189038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18903Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189038u;
            // 0x18903c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188F00u: goto label_188f00;
            case 0x188F08u: goto label_188f08;
            case 0x188F9Cu: goto label_188f9c;
            case 0x189018u: goto label_189018;
            case 0x18902Cu: goto label_18902c;
            case 0x189030u: goto label_189030;
            case 0x189088u: goto label_189088;
            case 0x18909Cu: goto label_18909c;
            case 0x1890A0u: goto label_1890a0;
            case 0x1890F8u: goto label_1890f8;
            case 0x18910Cu: goto label_18910c;
            case 0x189110u: goto label_189110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189040u;
    // 0x189040: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x189040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x189044: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x189044u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x189048: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x189048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x18904c: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18904cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x189050: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x189050u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x189054: 0xac440c00  sw          $a0, 0xC00($v0)
    ctx->pc = 0x189054u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 4));
    // 0x189058: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189058u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x18905c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18905cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x189060: 0x24640b88  addiu       $a0, $v1, 0xB88
    ctx->pc = 0x189060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2952));
    // 0x189064: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189064u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x189068: 0x34a51316  ori         $a1, $a1, 0x1316
    ctx->pc = 0x189068u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4886);
    // 0x18906c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18906cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189070: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x189070u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189074: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x189074u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189078: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x189078u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18907c: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x18907cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189080: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189080u;
    SET_GPR_U32(ctx, 31, 0x189088u);
    ctx->pc = 0x189084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189080u;
            // 0x189084: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189088u; }
        if (ctx->pc != 0x189088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189088u; }
        if (ctx->pc != 0x189088u) { return; }
    }
    ctx->pc = 0x189088u;
label_189088:
    // 0x189088: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x189088u;
    {
        const bool branch_taken_0x189088 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x189088) {
            ctx->pc = 0x18908Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x189088u;
            // 0x18908c: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1890A0u;
            goto label_1890a0;
        }
    }
    ctx->pc = 0x189090u;
    // 0x189090: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189090u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189094: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189094u;
    SET_GPR_U32(ctx, 31, 0x18909Cu);
    ctx->pc = 0x189098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189094u;
            // 0x189098: 0x248419a0  addiu       $a0, $a0, 0x19A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18909Cu; }
        if (ctx->pc != 0x18909Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18909Cu; }
        if (ctx->pc != 0x18909Cu) { return; }
    }
    ctx->pc = 0x18909Cu;
label_18909c:
    // 0x18909c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18909cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1890a0:
    // 0x1890a0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1890a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1890a4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1890a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1890a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1890A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1890ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1890A8u;
            // 0x1890ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188F00u: goto label_188f00;
            case 0x188F08u: goto label_188f08;
            case 0x188F9Cu: goto label_188f9c;
            case 0x189018u: goto label_189018;
            case 0x18902Cu: goto label_18902c;
            case 0x189030u: goto label_189030;
            case 0x189088u: goto label_189088;
            case 0x18909Cu: goto label_18909c;
            case 0x1890A0u: goto label_1890a0;
            case 0x1890F8u: goto label_1890f8;
            case 0x18910Cu: goto label_18910c;
            case 0x189110u: goto label_189110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1890B0u;
    // 0x1890b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1890b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1890b4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1890b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1890b8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1890b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1890bc: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x1890bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x1890c0: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x1890c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x1890c4: 0xac440c00  sw          $a0, 0xC00($v0)
    ctx->pc = 0x1890c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 4));
    // 0x1890c8: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x1890c8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1890cc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1890ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1890d0: 0x24640b88  addiu       $a0, $v1, 0xB88
    ctx->pc = 0x1890d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2952));
    // 0x1890d4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1890d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1890d8: 0x34a51317  ori         $a1, $a1, 0x1317
    ctx->pc = 0x1890d8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4887);
    // 0x1890dc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1890dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1890e0: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1890e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1890e4: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x1890e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1890e8: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1890e8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1890ec: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x1890ecu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1890f0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1890F0u;
    SET_GPR_U32(ctx, 31, 0x1890F8u);
    ctx->pc = 0x1890F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1890F0u;
            // 0x1890f4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1890F8u; }
        if (ctx->pc != 0x1890F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1890F8u; }
        if (ctx->pc != 0x1890F8u) { return; }
    }
    ctx->pc = 0x1890F8u;
label_1890f8:
    // 0x1890f8: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1890F8u;
    {
        const bool branch_taken_0x1890f8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1890f8) {
            ctx->pc = 0x1890FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1890F8u;
            // 0x1890fc: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x189110u;
            goto label_189110;
        }
    }
    ctx->pc = 0x189100u;
    // 0x189100: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189100u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189104: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189104u;
    SET_GPR_U32(ctx, 31, 0x18910Cu);
    ctx->pc = 0x189108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189104u;
            // 0x189108: 0x248419c0  addiu       $a0, $a0, 0x19C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18910Cu; }
        if (ctx->pc != 0x18910Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18910Cu; }
        if (ctx->pc != 0x18910Cu) { return; }
    }
    ctx->pc = 0x18910Cu;
label_18910c:
    // 0x18910c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18910cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_189110:
    // 0x189110: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x189110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189114: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x189114u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189118: 0x3e00008  jr          $ra
    ctx->pc = 0x189118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18911Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189118u;
            // 0x18911c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188F00u: goto label_188f00;
            case 0x188F08u: goto label_188f08;
            case 0x188F9Cu: goto label_188f9c;
            case 0x189018u: goto label_189018;
            case 0x18902Cu: goto label_18902c;
            case 0x189030u: goto label_189030;
            case 0x189088u: goto label_189088;
            case 0x18909Cu: goto label_18909c;
            case 0x1890A0u: goto label_1890a0;
            case 0x1890F8u: goto label_1890f8;
            case 0x18910Cu: goto label_18910c;
            case 0x189110u: goto label_189110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
