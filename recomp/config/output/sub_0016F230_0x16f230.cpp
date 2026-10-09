#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016F230
// Address: 0x16f230 - 0x16f338
void sub_0016F230_0x16f230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016F230_0x16f230");
#endif

    switch (ctx->pc) {
        case 0x16f298u: goto label_16f298;
        case 0x16f2acu: goto label_16f2ac;
        case 0x16f2c8u: goto label_16f2c8;
        default: break;
    }

    ctx->pc = 0x16f230u;

    // 0x16f230: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16f230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16f234: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16f234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16f238: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16f238u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f23c: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x16f23cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x16f240: 0x26110da4  addiu       $s1, $s0, 0xDA4
    ctx->pc = 0x16f240u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 3492));
    // 0x16f244: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x16f244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x16f248: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x16f248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16f24c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x16f24cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x16f250: 0x14400033  bnez        $v0, . + 4 + (0x33 << 2)
    ctx->pc = 0x16F250u;
    {
        const bool branch_taken_0x16f250 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F250u;
            // 0x16f254: 0x26120cdc  addiu       $s2, $s0, 0xCDC (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 3292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f250) {
            ctx->pc = 0x16F320u;
            goto label_16f320;
        }
    }
    ctx->pc = 0x16F258u;
    // 0x16f258: 0x6a020d5f  ldl         $v0, 0xD5F($s0)
    ctx->pc = 0x16f258u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3423); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16f25c: 0x6e020d58  ldr         $v0, 0xD58($s0)
    ctx->pc = 0x16f25cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3416); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16f260: 0x6a030d67  ldl         $v1, 0xD67($s0)
    ctx->pc = 0x16f260u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3431); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16f264: 0x6e030d60  ldr         $v1, 0xD60($s0)
    ctx->pc = 0x16f264u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3424); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16f268: 0x6a060d6f  ldl         $a2, 0xD6F($s0)
    ctx->pc = 0x16f268u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3439); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x16f26c: 0x6e060d68  ldr         $a2, 0xD68($s0)
    ctx->pc = 0x16f26cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3432); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x16f270: 0x8e070d70  lw          $a3, 0xD70($s0)
    ctx->pc = 0x16f270u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3440)));
    // 0x16f274: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x16f274u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f278: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x16f278u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f27c: 0xb3a3000f  sdl         $v1, 0xF($sp)
    ctx->pc = 0x16f27cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f280: 0xb7a30008  sdr         $v1, 0x8($sp)
    ctx->pc = 0x16f280u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f284: 0xb3a60017  sdl         $a2, 0x17($sp)
    ctx->pc = 0x16f284u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f288: 0xb7a60010  sdr         $a2, 0x10($sp)
    ctx->pc = 0x16f288u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f28c: 0xafa70018  sw          $a3, 0x18($sp)
    ctx->pc = 0x16f28cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 7));
    // 0x16f290: 0xc05b9da  jal         func_16E768
    ctx->pc = 0x16F290u;
    SET_GPR_U32(ctx, 31, 0x16F298u);
    ctx->pc = 0x16F294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F290u;
            // 0x16f294: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E768u;
    if (runtime->hasFunction(0x16E768u)) {
        auto targetFn = runtime->lookupFunction(0x16E768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F298u; }
        if (ctx->pc != 0x16F298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E768_0x16e768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F298u; }
        if (ctx->pc != 0x16F298u) { return; }
    }
    ctx->pc = 0x16F298u;
label_16f298:
    // 0x16f298: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f298u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f29c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16F29Cu;
    {
        const bool branch_taken_0x16f29c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F29Cu;
            // 0x16f2a0: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f29c) {
            ctx->pc = 0x16F2B8u;
            goto label_16f2b8;
        }
    }
    ctx->pc = 0x16F2A4u;
    // 0x16f2a4: 0xc05ba38  jal         func_16E8E0
    ctx->pc = 0x16F2A4u;
    SET_GPR_U32(ctx, 31, 0x16F2ACu);
    ctx->pc = 0x16E8E0u;
    if (runtime->hasFunction(0x16E8E0u)) {
        auto targetFn = runtime->lookupFunction(0x16E8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F2ACu; }
        if (ctx->pc != 0x16F2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E8E0_0x16e8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F2ACu; }
        if (ctx->pc != 0x16F2ACu) { return; }
    }
    ctx->pc = 0x16F2ACu;
label_16f2ac:
    // 0x16f2ac: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x16f2acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f2b0: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x16f2b0u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x16f2b4: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x16f2b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
label_16f2b8:
    // 0x16f2b8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16f2b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f2bc: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x16f2bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x16f2c0: 0xc05da70  jal         func_1769C0
    ctx->pc = 0x16F2C0u;
    SET_GPR_U32(ctx, 31, 0x16F2C8u);
    ctx->pc = 0x16F2C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F2C0u;
            // 0x16f2c4: 0x27a60024  addiu       $a2, $sp, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769C0u;
    if (runtime->hasFunction(0x1769C0u)) {
        auto targetFn = runtime->lookupFunction(0x1769C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F2C8u; }
        if (ctx->pc != 0x16F2C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769C0_0x1769c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F2C8u; }
        if (ctx->pc != 0x16F2C8u) { return; }
    }
    ctx->pc = 0x16F2C8u;
label_16f2c8:
    // 0x16f2c8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16f2c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16f2cc: 0x6ba20007  ldl         $v0, 0x7($sp)
    ctx->pc = 0x16f2ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16f2d0: 0x6fa20000  ldr         $v0, 0x0($sp)
    ctx->pc = 0x16f2d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16f2d4: 0x6ba3000f  ldl         $v1, 0xF($sp)
    ctx->pc = 0x16f2d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16f2d8: 0x6fa30008  ldr         $v1, 0x8($sp)
    ctx->pc = 0x16f2d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16f2dc: 0x6ba40017  ldl         $a0, 0x17($sp)
    ctx->pc = 0x16f2dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16f2e0: 0x6fa40010  ldr         $a0, 0x10($sp)
    ctx->pc = 0x16f2e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16f2e4: 0x8fa60018  lw          $a2, 0x18($sp)
    ctx->pc = 0x16f2e4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f2e8: 0xb2020daf  sdl         $v0, 0xDAF($s0)
    ctx->pc = 0x16f2e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3503); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f2ec: 0xb6020da8  sdr         $v0, 0xDA8($s0)
    ctx->pc = 0x16f2ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3496); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f2f0: 0xb2030db7  sdl         $v1, 0xDB7($s0)
    ctx->pc = 0x16f2f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3511); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f2f4: 0xb6030db0  sdr         $v1, 0xDB0($s0)
    ctx->pc = 0x16f2f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3504); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f2f8: 0xb2040dbf  sdl         $a0, 0xDBF($s0)
    ctx->pc = 0x16f2f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3519); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f2fc: 0xb6040db8  sdr         $a0, 0xDB8($s0)
    ctx->pc = 0x16f2fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3512); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f300: 0xae060dc0  sw          $a2, 0xDC0($s0)
    ctx->pc = 0x16f300u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3520), GPR_U32(ctx, 6));
    // 0x16f304: 0x8fa40024  lw          $a0, 0x24($sp)
    ctx->pc = 0x16f304u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x16f308: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x16f308u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16f30c: 0x8e430020  lw          $v1, 0x20($s2)
    ctx->pc = 0x16f30cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x16f310: 0xae250000  sw          $a1, 0x0($s1)
    ctx->pc = 0x16f310u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 5));
    // 0x16f314: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x16f314u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16f318: 0xae240024  sw          $a0, 0x24($s1)
    ctx->pc = 0x16f318u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 4));
    // 0x16f31c: 0xae220020  sw          $v0, 0x20($s1)
    ctx->pc = 0x16f31cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 2));
label_16f320:
    // 0x16f320: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x16f320u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16f324: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x16f324u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16f328: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x16f328u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16f32c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16f32cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16f330: 0x3e00008  jr          $ra
    ctx->pc = 0x16F330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F330u;
            // 0x16f334: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F298u: goto label_16f298;
            case 0x16F2ACu: goto label_16f2ac;
            case 0x16F2B8u: goto label_16f2b8;
            case 0x16F2C8u: goto label_16f2c8;
            case 0x16F320u: goto label_16f320;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F338u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
