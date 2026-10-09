#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E0E0
// Address: 0x16e0e0 - 0x16e1f0
void sub_0016E0E0_0x16e0e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E0E0_0x16e0e0");
#endif

    switch (ctx->pc) {
        case 0x16e10cu: goto label_16e10c;
        case 0x16e11cu: goto label_16e11c;
        default: break;
    }

    ctx->pc = 0x16e0e0u;

    // 0x16e0e0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16e0e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16e0e4: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16e0e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16e0e8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16e0e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e0ec: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x16e0ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e0f0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16e0f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e0f4: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x16e0f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x16e0f8: 0x26110cdc  addiu       $s1, $s0, 0xCDC
    ctx->pc = 0x16e0f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 3292));
    // 0x16e0fc: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x16e0fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x16e100: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x16e100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16e104: 0xc05b87c  jal         func_16E1F0
    ctx->pc = 0x16E104u;
    SET_GPR_U32(ctx, 31, 0x16E10Cu);
    ctx->pc = 0x16E108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E104u;
            // 0x16e108: 0x26120d54  addiu       $s2, $s0, 0xD54 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 3412));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E1F0u;
    if (runtime->hasFunction(0x16E1F0u)) {
        auto targetFn = runtime->lookupFunction(0x16E1F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E10Cu; }
        if (ctx->pc != 0x16E10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E1F0_0x16e1f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E10Cu; }
        if (ctx->pc != 0x16E10Cu) { return; }
    }
    ctx->pc = 0x16E10Cu;
label_16e10c:
    // 0x16e10c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16e10cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e110: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x16e110u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x16e114: 0xc05da70  jal         func_1769C0
    ctx->pc = 0x16E114u;
    SET_GPR_U32(ctx, 31, 0x16E11Cu);
    ctx->pc = 0x16E118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E114u;
            // 0x16e118: 0x27a60024  addiu       $a2, $sp, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769C0u;
    if (runtime->hasFunction(0x1769C0u)) {
        auto targetFn = runtime->lookupFunction(0x1769C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E11Cu; }
        if (ctx->pc != 0x16E11Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769C0_0x1769c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E11Cu; }
        if (ctx->pc != 0x16E11Cu) { return; }
    }
    ctx->pc = 0x16E11Cu;
label_16e11c:
    // 0x16e11c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16e11cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16e120: 0x6ba20007  ldl         $v0, 0x7($sp)
    ctx->pc = 0x16e120u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16e124: 0x6fa20000  ldr         $v0, 0x0($sp)
    ctx->pc = 0x16e124u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16e128: 0x6ba3000f  ldl         $v1, 0xF($sp)
    ctx->pc = 0x16e128u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16e12c: 0x6fa30008  ldr         $v1, 0x8($sp)
    ctx->pc = 0x16e12cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16e130: 0x6ba40017  ldl         $a0, 0x17($sp)
    ctx->pc = 0x16e130u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16e134: 0x6fa40010  ldr         $a0, 0x10($sp)
    ctx->pc = 0x16e134u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16e138: 0x8fa60018  lw          $a2, 0x18($sp)
    ctx->pc = 0x16e138u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16e13c: 0xb2020d5f  sdl         $v0, 0xD5F($s0)
    ctx->pc = 0x16e13cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3423); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e140: 0xb6020d58  sdr         $v0, 0xD58($s0)
    ctx->pc = 0x16e140u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3416); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e144: 0xb2030d67  sdl         $v1, 0xD67($s0)
    ctx->pc = 0x16e144u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3431); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e148: 0xb6030d60  sdr         $v1, 0xD60($s0)
    ctx->pc = 0x16e148u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3424); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e14c: 0xb2040d6f  sdl         $a0, 0xD6F($s0)
    ctx->pc = 0x16e14cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3439); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e150: 0xb6040d68  sdr         $a0, 0xD68($s0)
    ctx->pc = 0x16e150u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3432); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e154: 0xae060d70  sw          $a2, 0xD70($s0)
    ctx->pc = 0x16e154u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3440), GPR_U32(ctx, 6));
    // 0x16e158: 0x26100d04  addiu       $s0, $s0, 0xD04
    ctx->pc = 0x16e158u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 3332));
    // 0x16e15c: 0x8e220020  lw          $v0, 0x20($s1)
    ctx->pc = 0x16e15cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x16e160: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x16e160u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16e164: 0x8fa40024  lw          $a0, 0x24($sp)
    ctx->pc = 0x16e164u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x16e168: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x16e168u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16e16c: 0xae450000  sw          $a1, 0x0($s2)
    ctx->pc = 0x16e16cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 5));
    // 0x16e170: 0xae430020  sw          $v1, 0x20($s2)
    ctx->pc = 0x16e170u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 3));
    // 0x16e174: 0xae440024  sw          $a0, 0x24($s2)
    ctx->pc = 0x16e174u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 4));
    // 0x16e178: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x16e178u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x16e17c: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x16e17cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16e180: 0x54600016  bnel        $v1, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x16E180u;
    {
        const bool branch_taken_0x16e180 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e180) {
            ctx->pc = 0x16E184u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E180u;
            // 0x16e184: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E1DCu;
            goto label_16e1dc;
        }
    }
    ctx->pc = 0x16E188u;
    // 0x16e188: 0x6a420007  ldl         $v0, 0x7($s2)
    ctx->pc = 0x16e188u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16e18c: 0x6e420000  ldr         $v0, 0x0($s2)
    ctx->pc = 0x16e18cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16e190: 0x6a43000f  ldl         $v1, 0xF($s2)
    ctx->pc = 0x16e190u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16e194: 0x6e430008  ldr         $v1, 0x8($s2)
    ctx->pc = 0x16e194u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16e198: 0x6a440017  ldl         $a0, 0x17($s2)
    ctx->pc = 0x16e198u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16e19c: 0x6e440010  ldr         $a0, 0x10($s2)
    ctx->pc = 0x16e19cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16e1a0: 0x6a45001f  ldl         $a1, 0x1F($s2)
    ctx->pc = 0x16e1a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x16e1a4: 0x6e450018  ldr         $a1, 0x18($s2)
    ctx->pc = 0x16e1a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x16e1a8: 0xb2020007  sdl         $v0, 0x7($s0)
    ctx->pc = 0x16e1a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1ac: 0xb6020000  sdr         $v0, 0x0($s0)
    ctx->pc = 0x16e1acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1b0: 0xb203000f  sdl         $v1, 0xF($s0)
    ctx->pc = 0x16e1b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1b4: 0xb6030008  sdr         $v1, 0x8($s0)
    ctx->pc = 0x16e1b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1b8: 0xb2040017  sdl         $a0, 0x17($s0)
    ctx->pc = 0x16e1b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1bc: 0xb6040010  sdr         $a0, 0x10($s0)
    ctx->pc = 0x16e1bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1c0: 0xb205001f  sdl         $a1, 0x1F($s0)
    ctx->pc = 0x16e1c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1c4: 0xb6050018  sdr         $a1, 0x18($s0)
    ctx->pc = 0x16e1c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1c8: 0x6a420027  ldl         $v0, 0x27($s2)
    ctx->pc = 0x16e1c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16e1cc: 0x6e420020  ldr         $v0, 0x20($s2)
    ctx->pc = 0x16e1ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16e1d0: 0xb2020027  sdl         $v0, 0x27($s0)
    ctx->pc = 0x16e1d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1d4: 0xb6020020  sdr         $v0, 0x20($s0)
    ctx->pc = 0x16e1d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e1d8: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x16e1d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_16e1dc:
    // 0x16e1dc: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x16e1dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16e1e0: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x16e1e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16e1e4: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16e1e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16e1e8: 0x3e00008  jr          $ra
    ctx->pc = 0x16E1E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E1ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E1E8u;
            // 0x16e1ec: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E10Cu: goto label_16e10c;
            case 0x16E11Cu: goto label_16e11c;
            case 0x16E1DCu: goto label_16e1dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E1F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
