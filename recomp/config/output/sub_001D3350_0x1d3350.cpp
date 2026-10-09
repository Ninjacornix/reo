#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3350
// Address: 0x1d3350 - 0x1d3540
void sub_001D3350_0x1d3350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3350_0x1d3350");
#endif

    switch (ctx->pc) {
        case 0x1d33a4u: goto label_1d33a4;
        case 0x1d33b0u: goto label_1d33b0;
        case 0x1d33bcu: goto label_1d33bc;
        case 0x1d33c4u: goto label_1d33c4;
        case 0x1d3418u: goto label_1d3418;
        case 0x1d3428u: goto label_1d3428;
        case 0x1d3430u: goto label_1d3430;
        case 0x1d343cu: goto label_1d343c;
        case 0x1d3448u: goto label_1d3448;
        case 0x1d3488u: goto label_1d3488;
        case 0x1d34f0u: goto label_1d34f0;
        case 0x1d34f8u: goto label_1d34f8;
        default: break;
    }

    ctx->pc = 0x1d3350u;

    // 0x1d3350: 0x27bdfb70  addiu       $sp, $sp, -0x490
    ctx->pc = 0x1d3350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966128));
    // 0x1d3354: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1d3354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1d3358: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d3358u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d335c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d335cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d3360: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d3360u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d3364: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d3364u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d3368: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3368u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d336c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d336cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3370: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d3370u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3374: 0x14c00004  bnez        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D3374u;
    {
        const bool branch_taken_0x1d3374 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D3378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3374u;
            // 0x1d3378: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3374) {
            ctx->pc = 0x1D3388u;
            goto label_1d3388;
        }
    }
    ctx->pc = 0x1D337Cu;
    // 0x1d337c: 0x3c14003c  lui         $s4, 0x3C
    ctx->pc = 0x1d337cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)60 << 16));
    // 0x1d3380: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D3380u;
    {
        const bool branch_taken_0x1d3380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3380u;
            // 0x1d3384: 0x269485b0  addiu       $s4, $s4, -0x7A50 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294935984));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3380) {
            ctx->pc = 0x1D339Cu;
            goto label_1d339c;
        }
    }
    ctx->pc = 0x1D3388u;
label_1d3388:
    // 0x1d3388: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3388u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d338c: 0x3c02002f  lui         $v0, 0x2F
    ctx->pc = 0x1d338cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)47 << 16));
    // 0x1d3390: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d3390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3394: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x1d3394u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x1d3398: 0x62a021  addu        $s4, $v1, $v0
    ctx->pc = 0x1d3398u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1d339c:
    // 0x1d339c: 0xc068abc  jal         func_1A2AF0
    ctx->pc = 0x1D339Cu;
    SET_GPR_U32(ctx, 31, 0x1D33A4u);
    ctx->pc = 0x1D33A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D339Cu;
            // 0x1d33a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2AF0u;
    if (runtime->hasFunction(0x1A2AF0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D33A4u; }
        if (ctx->pc != 0x1D33A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2AF0_0x1a2af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D33A4u; }
        if (ctx->pc != 0x1D33A4u) { return; }
    }
    ctx->pc = 0x1D33A4u;
label_1d33a4:
    // 0x1d33a4: 0xa6220816  sh          $v0, 0x816($s1)
    ctx->pc = 0x1d33a4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 2070), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d33a8: 0xc068acc  jal         func_1A2B30
    ctx->pc = 0x1D33A8u;
    SET_GPR_U32(ctx, 31, 0x1D33B0u);
    ctx->pc = 0x1D33ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D33A8u;
            // 0x1d33ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B30u;
    if (runtime->hasFunction(0x1A2B30u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D33B0u; }
        if (ctx->pc != 0x1D33B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B30_0x1a2b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D33B0u; }
        if (ctx->pc != 0x1D33B0u) { return; }
    }
    ctx->pc = 0x1D33B0u;
label_1d33b0:
    // 0x1d33b0: 0xa6820820  sh          $v0, 0x820($s4)
    ctx->pc = 0x1d33b0u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 2080), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d33b4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D33B4u;
    {
        const bool branch_taken_0x1d33b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D33B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D33B4u;
            // 0x1d33b8: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d33b4) {
            ctx->pc = 0x1D33DCu;
            goto label_1d33dc;
        }
    }
    ctx->pc = 0x1D33BCu;
label_1d33bc:
    // 0x1d33bc: 0xc068ad8  jal         func_1A2B60
    ctx->pc = 0x1D33BCu;
    SET_GPR_U32(ctx, 31, 0x1D33C4u);
    ctx->pc = 0x1D33C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D33BCu;
            // 0x1d33c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B60u;
    if (runtime->hasFunction(0x1A2B60u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D33C4u; }
        if (ctx->pc != 0x1D33C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B60_0x1a2b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D33C4u; }
        if (ctx->pc != 0x1D33C4u) { return; }
    }
    ctx->pc = 0x1D33C4u;
label_1d33c4:
    // 0x1d33c4: 0x3244ffff  andi        $a0, $s2, 0xFFFF
    ctx->pc = 0x1d33c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d33c8: 0x26430001  addiu       $v1, $s2, 0x1
    ctx->pc = 0x1d33c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d33cc: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1d33ccu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1d33d0: 0x3072ffff  andi        $s2, $v1, 0xFFFF
    ctx->pc = 0x1d33d0u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1d33d4: 0x9d1821  addu        $v1, $a0, $sp
    ctx->pc = 0x1d33d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 29)));
    // 0x1d33d8: 0xa4620080  sh          $v0, 0x80($v1)
    ctx->pc = 0x1d33d8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 128), (uint16_t)GPR_U32(ctx, 2));
label_1d33dc:
    // 0x1d33dc: 0x86830820  lh          $v1, 0x820($s4)
    ctx->pc = 0x1d33dcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 2080)));
    // 0x1d33e0: 0x3244ffff  andi        $a0, $s2, 0xFFFF
    ctx->pc = 0x1d33e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d33e4: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1d33e4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d33e8: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1D33E8u;
    {
        const bool branch_taken_0x1d33e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D33ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D33E8u;
            // 0x1d33ec: 0x3245ffff  andi        $a1, $s2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d33e8) {
            ctx->pc = 0x1D33BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d33bc;
        }
    }
    ctx->pc = 0x1D33F0u;
    // 0x1d33f0: 0x96250816  lhu         $a1, 0x816($s1)
    ctx->pc = 0x1d33f0u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2070)));
    // 0x1d33f4: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1d33f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1d33f8: 0x7d2021  addu        $a0, $v1, $sp
    ctx->pc = 0x1d33f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1d33fc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d33fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3400: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x1d3400u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x1d3404: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1d3404u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3408: 0xa4850080  sh          $a1, 0x80($a0)
    ctx->pc = 0x1d3408u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 128), (uint16_t)GPR_U32(ctx, 5));
    // 0x1d340c: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1d340cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3410: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1D3410u;
    {
        const bool branch_taken_0x1d3410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3410u;
            // 0x1d3414: 0x83a821  addu        $s5, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3410) {
            ctx->pc = 0x1D3504u;
            goto label_1d3504;
        }
    }
    ctx->pc = 0x1D3418u;
label_1d3418:
    // 0x1d3418: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1d3418u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1d341c: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1d341cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3420: 0xc074d50  jal         func_1D3540
    ctx->pc = 0x1D3420u;
    SET_GPR_U32(ctx, 31, 0x1D3428u);
    ctx->pc = 0x1D3424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3420u;
            // 0x1d3424: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3540u;
    if (runtime->hasFunction(0x1D3540u)) {
        auto targetFn = runtime->lookupFunction(0x1D3540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3428u; }
        if (ctx->pc != 0x1D3428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3540_0x1d3540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3428u; }
        if (ctx->pc != 0x1D3428u) { return; }
    }
    ctx->pc = 0x1D3428u;
label_1d3428:
    // 0x1d3428: 0xc064920  jal         func_192480
    ctx->pc = 0x1D3428u;
    SET_GPR_U32(ctx, 31, 0x1D3430u);
    ctx->pc = 0x1D342Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3428u;
            // 0x1d342c: 0x27a40070  addiu       $a0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192480u;
    if (runtime->hasFunction(0x192480u)) {
        auto targetFn = runtime->lookupFunction(0x192480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3430u; }
        if (ctx->pc != 0x1D3430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192480_0x192480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3430u; }
        if (ctx->pc != 0x1D3430u) { return; }
    }
    ctx->pc = 0x1D3430u;
label_1d3430:
    // 0x1d3430: 0xae22080c  sw          $v0, 0x80C($s1)
    ctx->pc = 0x1d3430u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2060), GPR_U32(ctx, 2));
    // 0x1d3434: 0xc06c430  jal         func_1B10C0
    ctx->pc = 0x1D3434u;
    SET_GPR_U32(ctx, 31, 0x1D343Cu);
    ctx->pc = 0x1D3438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3434u;
            // 0x1d3438: 0x8e24080c  lw          $a0, 0x80C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B10C0u;
    if (runtime->hasFunction(0x1B10C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B10C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D343Cu; }
        if (ctx->pc != 0x1D343Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B10C0_0x1b10c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D343Cu; }
        if (ctx->pc != 0x1D343Cu) { return; }
    }
    ctx->pc = 0x1D343Cu;
label_1d343c:
    // 0x1d343c: 0x8e25080c  lw          $a1, 0x80C($s1)
    ctx->pc = 0x1d343cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2060)));
    // 0x1d3440: 0xc064ce0  jal         func_193380
    ctx->pc = 0x1D3440u;
    SET_GPR_U32(ctx, 31, 0x1D3448u);
    ctx->pc = 0x1D3444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3440u;
            // 0x1d3444: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193380u;
    if (runtime->hasFunction(0x193380u)) {
        auto targetFn = runtime->lookupFunction(0x193380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3448u; }
        if (ctx->pc != 0x1D3448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193380_0x193380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3448u; }
        if (ctx->pc != 0x1D3448u) { return; }
    }
    ctx->pc = 0x1D3448u;
label_1d3448:
    // 0x1d3448: 0x3243ffff  andi        $v1, $s2, 0xFFFF
    ctx->pc = 0x1d3448u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d344c: 0x131040  sll         $v0, $s3, 1
    ctx->pc = 0x1d344cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x1d3450: 0x32040  sll         $a0, $v1, 1
    ctx->pc = 0x1d3450u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d3454: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1d3454u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d3458: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1d3458u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d345c: 0x24450082  addiu       $a1, $v0, 0x82
    ctx->pc = 0x1d345cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 130));
    // 0x1d3460: 0x2833021  addu        $a2, $s4, $v1
    ctx->pc = 0x1d3460u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1d3464: 0x9d1021  addu        $v0, $a0, $sp
    ctx->pc = 0x1d3464u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 29)));
    // 0x1d3468: 0x2841821  addu        $v1, $s4, $a0
    ctx->pc = 0x1d3468u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 4)));
    // 0x1d346c: 0x24480080  addiu       $t0, $v0, 0x80
    ctx->pc = 0x1d346cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x1d3470: 0xa4600c24  sh          $zero, 0xC24($v1)
    ctx->pc = 0x1d3470u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 3108), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d3474: 0x24640c24  addiu       $a0, $v1, 0xC24
    ctx->pc = 0x1d3474u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 3108));
    // 0x1d3478: 0x950a0000  lhu         $t2, 0x0($t0)
    ctx->pc = 0x1d3478u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1d347c: 0x24670824  addiu       $a3, $v1, 0x824
    ctx->pc = 0x1d347cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 2084));
    // 0x1d3480: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D3480u;
    {
        const bool branch_taken_0x1d3480 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3480u;
            // 0x1d3484: 0x2a0482d  daddu       $t1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3480) {
            ctx->pc = 0x1D34D4u;
            goto label_1d34d4;
        }
    }
    ctx->pc = 0x1D3488u;
label_1d3488:
    // 0x1d3488: 0x95020000  lhu         $v0, 0x0($t0)
    ctx->pc = 0x1d3488u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1d348c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D348Cu;
    {
        const bool branch_taken_0x1d348c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d348c) {
            ctx->pc = 0x1D34A0u;
            goto label_1d34a0;
        }
    }
    ctx->pc = 0x1D3494u;
    // 0x1d3494: 0x952200c6  lhu         $v0, 0xC6($t1)
    ctx->pc = 0x1d3494u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 9), 198)));
    // 0x1d3498: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1D3498u;
    {
        const bool branch_taken_0x1d3498 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D349Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3498u;
            // 0x1d349c: 0xa4e20000  sh          $v0, 0x0($a3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3498) {
            ctx->pc = 0x1D34C8u;
            goto label_1d34c8;
        }
    }
    ctx->pc = 0x1D34A0u;
label_1d34a0:
    // 0x1d34a0: 0x8d230174  lw          $v1, 0x174($t1)
    ctx->pc = 0x1d34a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 372)));
    // 0x1d34a4: 0x4600009  bltz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D34A4u;
    {
        const bool branch_taken_0x1d34a4 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1D34A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D34A4u;
            // 0x1d34a8: 0x25420001  addiu       $v0, $t2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d34a4) {
            ctx->pc = 0x1D34CCu;
            goto label_1d34cc;
        }
    }
    ctx->pc = 0x1D34ACu;
    // 0x1d34ac: 0x84820000  lh          $v0, 0x0($a0)
    ctx->pc = 0x1d34acu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d34b0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1d34b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1d34b4: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1d34b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1d34b8: 0xa4431024  sh          $v1, 0x1024($v0)
    ctx->pc = 0x1d34b8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 4132), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d34bc: 0x84820000  lh          $v0, 0x0($a0)
    ctx->pc = 0x1d34bcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d34c0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d34c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d34c4: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x1d34c4u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_1d34c8:
    // 0x1d34c8: 0x25420001  addiu       $v0, $t2, 0x1
    ctx->pc = 0x1d34c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_1d34cc:
    // 0x1d34cc: 0x25290190  addiu       $t1, $t1, 0x190
    ctx->pc = 0x1d34ccu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 400));
    // 0x1d34d0: 0x304affff  andi        $t2, $v0, 0xFFFF
    ctx->pc = 0x1d34d0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1d34d4:
    // 0x1d34d4: 0x94a20000  lhu         $v0, 0x0($a1)
    ctx->pc = 0x1d34d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1d34d8: 0x3143ffff  andi        $v1, $t2, 0xFFFF
    ctx->pc = 0x1d34d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
    // 0x1d34dc: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1d34dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d34e0: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1D34E0u;
    {
        const bool branch_taken_0x1d34e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d34e0) {
            ctx->pc = 0x1D3488u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3488;
        }
    }
    ctx->pc = 0x1D34E8u;
    // 0x1d34e8: 0xc064960  jal         func_192580
    ctx->pc = 0x1D34E8u;
    SET_GPR_U32(ctx, 31, 0x1D34F0u);
    ctx->pc = 0x1D34ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D34E8u;
            // 0x1d34ec: 0x8e24080c  lw          $a0, 0x80C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192580u;
    if (runtime->hasFunction(0x192580u)) {
        auto targetFn = runtime->lookupFunction(0x192580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D34F0u; }
        if (ctx->pc != 0x1D34F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192580_0x192580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D34F0u; }
        if (ctx->pc != 0x1D34F0u) { return; }
    }
    ctx->pc = 0x1D34F0u;
label_1d34f0:
    // 0x1d34f0: 0xc06c444  jal         func_1B1110
    ctx->pc = 0x1D34F0u;
    SET_GPR_U32(ctx, 31, 0x1D34F8u);
    ctx->pc = 0x1D34F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D34F0u;
            // 0x1d34f4: 0x8e24080c  lw          $a0, 0x80C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1110u;
    if (runtime->hasFunction(0x1B1110u)) {
        auto targetFn = runtime->lookupFunction(0x1B1110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D34F8u; }
        if (ctx->pc != 0x1D34F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1110_0x1b1110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D34F8u; }
        if (ctx->pc != 0x1D34F8u) { return; }
    }
    ctx->pc = 0x1D34F8u;
label_1d34f8:
    // 0x1d34f8: 0x26430001  addiu       $v1, $s2, 0x1
    ctx->pc = 0x1d34f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d34fc: 0xae20080c  sw          $zero, 0x80C($s1)
    ctx->pc = 0x1d34fcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2060), GPR_U32(ctx, 0));
    // 0x1d3500: 0x3072ffff  andi        $s2, $v1, 0xFFFF
    ctx->pc = 0x1d3500u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_1d3504:
    // 0x1d3504: 0x86830820  lh          $v1, 0x820($s4)
    ctx->pc = 0x1d3504u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 2080)));
    // 0x1d3508: 0x3253ffff  andi        $s3, $s2, 0xFFFF
    ctx->pc = 0x1d3508u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d350c: 0x263182a  slt         $v1, $s3, $v1
    ctx->pc = 0x1d350cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d3510: 0x1460ffc1  bnez        $v1, . + 4 + (-0x3F << 2)
    ctx->pc = 0x1D3510u;
    {
        const bool branch_taken_0x1d3510 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D3514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3510u;
            // 0x1d3514: 0x3247ffff  andi        $a3, $s2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3510) {
            ctx->pc = 0x1D3418u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3418;
        }
    }
    ctx->pc = 0x1D3518u;
    // 0x1d3518: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1d3518u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d351c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d351cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d3520: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d3520u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d3524: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d3524u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d3528: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d3528u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d352c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d352cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3530: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3530u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3534: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3534u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3534u;
            // 0x1d3538: 0x27bd0490  addiu       $sp, $sp, 0x490 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1168));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3388u: goto label_1d3388;
            case 0x1D339Cu: goto label_1d339c;
            case 0x1D33A4u: goto label_1d33a4;
            case 0x1D33B0u: goto label_1d33b0;
            case 0x1D33BCu: goto label_1d33bc;
            case 0x1D33C4u: goto label_1d33c4;
            case 0x1D33DCu: goto label_1d33dc;
            case 0x1D3418u: goto label_1d3418;
            case 0x1D3428u: goto label_1d3428;
            case 0x1D3430u: goto label_1d3430;
            case 0x1D343Cu: goto label_1d343c;
            case 0x1D3448u: goto label_1d3448;
            case 0x1D3488u: goto label_1d3488;
            case 0x1D34A0u: goto label_1d34a0;
            case 0x1D34C8u: goto label_1d34c8;
            case 0x1D34CCu: goto label_1d34cc;
            case 0x1D34D4u: goto label_1d34d4;
            case 0x1D34F0u: goto label_1d34f0;
            case 0x1D34F8u: goto label_1d34f8;
            case 0x1D3504u: goto label_1d3504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D353Cu;
    // 0x1d353c: 0x0  nop
    ctx->pc = 0x1d353cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
