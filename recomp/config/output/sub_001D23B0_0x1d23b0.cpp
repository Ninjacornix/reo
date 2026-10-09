#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D23B0
// Address: 0x1d23b0 - 0x1d2474
void sub_001D23B0_0x1d23b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D23B0_0x1d23b0");
#endif

    switch (ctx->pc) {
        case 0x1d23e0u: goto label_1d23e0;
        case 0x1d2408u: goto label_1d2408;
        case 0x1d2418u: goto label_1d2418;
        case 0x1d2420u: goto label_1d2420;
        case 0x1d2430u: goto label_1d2430;
        case 0x1d2438u: goto label_1d2438;
        default: break;
    }

    ctx->pc = 0x1d23b0u;

    // 0x1d23b0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d23b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d23b4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d23b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d23b8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d23b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d23bc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d23bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d23c0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d23c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d23c4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d23c4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23c8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d23c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d23cc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d23ccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23d0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1d23d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23d4: 0x24044200  addiu       $a0, $zero, 0x4200
    ctx->pc = 0x1d23d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16896));
    // 0x1d23d8: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D23D8u;
    SET_GPR_U32(ctx, 31, 0x1D23E0u);
    ctx->pc = 0x1D23DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D23D8u;
            // 0x1d23dc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D23E0u; }
        if (ctx->pc != 0x1D23E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D23E0u; }
        if (ctx->pc != 0x1D23E0u) { return; }
    }
    ctx->pc = 0x1D23E0u;
label_1d23e0:
    // 0x1d23e0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d23e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d23e4: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d23e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d23e8: 0x8c34440c  lw          $s4, 0x440C($at)
    ctx->pc = 0x1d23e8u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d23ec: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1d23ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1d23f0: 0x248465d0  addiu       $a0, $a0, 0x65D0
    ctx->pc = 0x1d23f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26064));
    // 0x1d23f4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d23f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d23f8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d23f8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d23fc: 0x2828021  addu        $s0, $s4, $v0
    ctx->pc = 0x1d23fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x1d2400: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D2400u;
    SET_GPR_U32(ctx, 31, 0x1D2408u);
    ctx->pc = 0x1D2404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2400u;
            // 0x1d2404: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2408u; }
        if (ctx->pc != 0x1D2408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2408u; }
        if (ctx->pc != 0x1D2408u) { return; }
    }
    ctx->pc = 0x1D2408u;
label_1d2408:
    // 0x1d2408: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D2408u;
    {
        const bool branch_taken_0x1d2408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D240Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2408u;
            // 0x1d240c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2408) {
            ctx->pc = 0x1D2454u;
            goto label_1d2454;
        }
    }
    ctx->pc = 0x1D2410u;
    // 0x1d2410: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1D2410u;
    SET_GPR_U32(ctx, 31, 0x1D2418u);
    ctx->pc = 0x1D2414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2410u;
            // 0x1d2414: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2418u; }
        if (ctx->pc != 0x1D2418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2418u; }
        if (ctx->pc != 0x1D2418u) { return; }
    }
    ctx->pc = 0x1D2418u;
label_1d2418:
    // 0x1d2418: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1D2418u;
    {
        const bool branch_taken_0x1d2418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D241Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2418u;
            // 0x1d241c: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2418) {
            ctx->pc = 0x1D2448u;
            goto label_1d2448;
        }
    }
    ctx->pc = 0x1D2420u;
label_1d2420:
    // 0x1d2420: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x1d2420u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d2424: 0x26844200  addiu       $a0, $s4, 0x4200
    ctx->pc = 0x1d2424u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 16896));
    // 0x1d2428: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D2428u;
    SET_GPR_U32(ctx, 31, 0x1D2430u);
    ctx->pc = 0x1D242Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2428u;
            // 0x1d242c: 0x2022821  addu        $a1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2430u; }
        if (ctx->pc != 0x1D2430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2430u; }
        if (ctx->pc != 0x1D2430u) { return; }
    }
    ctx->pc = 0x1D2430u;
label_1d2430:
    // 0x1d2430: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1D2430u;
    SET_GPR_U32(ctx, 31, 0x1D2438u);
    ctx->pc = 0x1D2434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2430u;
            // 0x1d2434: 0x26844200  addiu       $a0, $s4, 0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 16896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2438u; }
        if (ctx->pc != 0x1D2438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2438u; }
        if (ctx->pc != 0x1D2438u) { return; }
    }
    ctx->pc = 0x1D2438u;
label_1d2438:
    // 0x1d2438: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1d2438u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1d243c: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x1d243cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d2440: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x1d2440u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x1d2444: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1d2444u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_1d2448:
    // 0x1d2448: 0x291182a  slt         $v1, $s4, $s1
    ctx->pc = 0x1d2448u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1d244c: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1D244Cu;
    {
        const bool branch_taken_0x1d244c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d244c) {
            ctx->pc = 0x1D2420u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2420;
        }
    }
    ctx->pc = 0x1D2454u;
label_1d2454:
    // 0x1d2454: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d2454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d2458: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d2458u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d245c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d245cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d2460: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d2460u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2464: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d2464u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2468: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d2468u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d246c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D246Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D246Cu;
            // 0x1d2470: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D23E0u: goto label_1d23e0;
            case 0x1D2408u: goto label_1d2408;
            case 0x1D2418u: goto label_1d2418;
            case 0x1D2420u: goto label_1d2420;
            case 0x1D2430u: goto label_1d2430;
            case 0x1D2438u: goto label_1d2438;
            case 0x1D2448u: goto label_1d2448;
            case 0x1D2454u: goto label_1d2454;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2474u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
