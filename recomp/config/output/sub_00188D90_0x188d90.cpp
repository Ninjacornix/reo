#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188D90
// Address: 0x188d90 - 0x188ed8
void sub_00188D90_0x188d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188D90_0x188d90");
#endif

    switch (ctx->pc) {
        case 0x188db8u: goto label_188db8;
        case 0x188dc0u: goto label_188dc0;
        case 0x188e54u: goto label_188e54;
        case 0x188ea8u: goto label_188ea8;
        case 0x188ebcu: goto label_188ebc;
        default: break;
    }

    ctx->pc = 0x188d90u;

    // 0x188d90: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x188d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x188d94: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x188d94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x188d98: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x188d98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x188d9c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x188d9cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188da0: 0x3c110029  lui         $s1, 0x29
    ctx->pc = 0x188da0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)41 << 16));
    // 0x188da4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x188da8: 0x26244080  addiu       $a0, $s1, 0x4080
    ctx->pc = 0x188da8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16512));
    // 0x188dac: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x188dacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x188db0: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x188DB0u;
    SET_GPR_U32(ctx, 31, 0x188DB8u);
    ctx->pc = 0x188DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188DB0u;
            // 0x188db4: 0x24850080  addiu       $a1, $a0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188DB8u; }
        if (ctx->pc != 0x188DB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188DB8u; }
        if (ctx->pc != 0x188DB8u) { return; }
    }
    ctx->pc = 0x188DB8u;
label_188db8:
    // 0x188db8: 0xc047598  jal         func_11D660
    ctx->pc = 0x188DB8u;
    SET_GPR_U32(ctx, 31, 0x188DC0u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188DC0u; }
        if (ctx->pc != 0x188DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188DC0u; }
        if (ctx->pc != 0x188DC0u) { return; }
    }
    ctx->pc = 0x188DC0u;
label_188dc0:
    // 0x188dc0: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x188dc0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x188dc4: 0x26264080  addiu       $a2, $s1, 0x4080
    ctx->pc = 0x188dc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 16512));
    // 0x188dc8: 0x24654100  addiu       $a1, $v1, 0x4100
    ctx->pc = 0x188dc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 16640));
    // 0x188dcc: 0x68c20007  ldl         $v0, 0x7($a2)
    ctx->pc = 0x188dccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188dd0: 0x6cc20000  ldr         $v0, 0x0($a2)
    ctx->pc = 0x188dd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188dd4: 0x68c4000f  ldl         $a0, 0xF($a2)
    ctx->pc = 0x188dd4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188dd8: 0x6cc40008  ldr         $a0, 0x8($a2)
    ctx->pc = 0x188dd8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188ddc: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x188ddcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188de0: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x188de0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188de4: 0xb0a4000f  sdl         $a0, 0xF($a1)
    ctx->pc = 0x188de4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188de8: 0xb4a40008  sdr         $a0, 0x8($a1)
    ctx->pc = 0x188de8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188dec: 0x68c20017  ldl         $v0, 0x17($a2)
    ctx->pc = 0x188decu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188df0: 0x6cc20010  ldr         $v0, 0x10($a2)
    ctx->pc = 0x188df0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188df4: 0x68c4001f  ldl         $a0, 0x1F($a2)
    ctx->pc = 0x188df4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188df8: 0x6cc40018  ldr         $a0, 0x18($a2)
    ctx->pc = 0x188df8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188dfc: 0xb0a20017  sdl         $v0, 0x17($a1)
    ctx->pc = 0x188dfcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e00: 0xb4a20010  sdr         $v0, 0x10($a1)
    ctx->pc = 0x188e00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e04: 0xb0a4001f  sdl         $a0, 0x1F($a1)
    ctx->pc = 0x188e04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e08: 0xb4a40018  sdr         $a0, 0x18($a1)
    ctx->pc = 0x188e08u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e0c: 0x68c20027  ldl         $v0, 0x27($a2)
    ctx->pc = 0x188e0cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188e10: 0x6cc20020  ldr         $v0, 0x20($a2)
    ctx->pc = 0x188e10u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188e14: 0x68c4002f  ldl         $a0, 0x2F($a2)
    ctx->pc = 0x188e14u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188e18: 0x6cc40028  ldr         $a0, 0x28($a2)
    ctx->pc = 0x188e18u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188e1c: 0xb0a20027  sdl         $v0, 0x27($a1)
    ctx->pc = 0x188e1cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e20: 0xb4a20020  sdr         $v0, 0x20($a1)
    ctx->pc = 0x188e20u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e24: 0xb0a4002f  sdl         $a0, 0x2F($a1)
    ctx->pc = 0x188e24u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e28: 0xb4a40028  sdr         $a0, 0x28($a1)
    ctx->pc = 0x188e28u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e2c: 0x68c20037  ldl         $v0, 0x37($a2)
    ctx->pc = 0x188e2cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x188e30: 0x6cc20030  ldr         $v0, 0x30($a2)
    ctx->pc = 0x188e30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x188e34: 0x68c4003f  ldl         $a0, 0x3F($a2)
    ctx->pc = 0x188e34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x188e38: 0x6cc40038  ldr         $a0, 0x38($a2)
    ctx->pc = 0x188e38u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x188e3c: 0xb0a20037  sdl         $v0, 0x37($a1)
    ctx->pc = 0x188e3cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e40: 0xb4a20030  sdr         $v0, 0x30($a1)
    ctx->pc = 0x188e40u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e44: 0xb0a4003f  sdl         $a0, 0x3F($a1)
    ctx->pc = 0x188e44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e48: 0xb4a40038  sdr         $a0, 0x38($a1)
    ctx->pc = 0x188e48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188e4c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x188E4Cu;
    SET_GPR_U32(ctx, 31, 0x188E54u);
    ctx->pc = 0x188E50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188E4Cu;
            // 0x188e50: 0x24704100  addiu       $s0, $v1, 0x4100 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 16640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188E54u; }
        if (ctx->pc != 0x188E54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188E54u; }
        if (ctx->pc != 0x188E54u) { return; }
    }
    ctx->pc = 0x188E54u;
label_188e54:
    // 0x188e54: 0x121880  sll         $v1, $s2, 2
    ctx->pc = 0x188e54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x188e58: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x188e58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188e5c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x188e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x188e60: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x188e60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x188e64: 0x14440016  bne         $v0, $a0, . + 4 + (0x16 << 2)
    ctx->pc = 0x188E64u;
    {
        const bool branch_taken_0x188e64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x188E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188E64u;
            // 0x188e68: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188e64) {
            ctx->pc = 0x188EC0u;
            goto label_188ec0;
        }
    }
    ctx->pc = 0x188E6Cu;
    // 0x188e6c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188e70: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x188e70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x188e74: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x188e74u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x188e78: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188e78u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188e7c: 0xac520c00  sw          $s2, 0xC00($v0)
    ctx->pc = 0x188e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 18));
    // 0x188e80: 0x24840b88  addiu       $a0, $a0, 0xB88
    ctx->pc = 0x188e80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2952));
    // 0x188e84: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x188e84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x188e88: 0x34a51303  ori         $a1, $a1, 0x1303
    ctx->pc = 0x188e88u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4867);
    // 0x188e8c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x188e8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188e90: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x188e90u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188e94: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x188e94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188e98: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x188e98u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188e9c: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x188e9cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188ea0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x188EA0u;
    SET_GPR_U32(ctx, 31, 0x188EA8u);
    ctx->pc = 0x188EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188EA0u;
            // 0x188ea4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188EA8u; }
        if (ctx->pc != 0x188EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188EA8u; }
        if (ctx->pc != 0x188EA8u) { return; }
    }
    ctx->pc = 0x188EA8u;
label_188ea8:
    // 0x188ea8: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x188EA8u;
    {
        const bool branch_taken_0x188ea8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x188ea8) {
            ctx->pc = 0x188EACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x188EA8u;
            // 0x188eac: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x188EC0u;
            goto label_188ec0;
        }
    }
    ctx->pc = 0x188EB0u;
    // 0x188eb0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x188eb0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x188eb4: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x188EB4u;
    SET_GPR_U32(ctx, 31, 0x188EBCu);
    ctx->pc = 0x188EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188EB4u;
            // 0x188eb8: 0x24841960  addiu       $a0, $a0, 0x1960 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188EBCu; }
        if (ctx->pc != 0x188EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188EBCu; }
        if (ctx->pc != 0x188EBCu) { return; }
    }
    ctx->pc = 0x188EBCu;
label_188ebc:
    // 0x188ebc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x188ebcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_188ec0:
    // 0x188ec0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x188ec0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x188ec4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x188ec4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x188ec8: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x188ec8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188ecc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188eccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x188ed0: 0x3e00008  jr          $ra
    ctx->pc = 0x188ED0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188ED0u;
            // 0x188ed4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188DB8u: goto label_188db8;
            case 0x188DC0u: goto label_188dc0;
            case 0x188E54u: goto label_188e54;
            case 0x188EA8u: goto label_188ea8;
            case 0x188EBCu: goto label_188ebc;
            case 0x188EC0u: goto label_188ec0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188ED8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
