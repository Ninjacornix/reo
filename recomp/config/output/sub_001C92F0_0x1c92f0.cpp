#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C92F0
// Address: 0x1c92f0 - 0x1c9530
void sub_001C92F0_0x1c92f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C92F0_0x1c92f0");
#endif

    switch (ctx->pc) {
        case 0x1c9344u: goto label_1c9344;
        case 0x1c936cu: goto label_1c936c;
        case 0x1c9390u: goto label_1c9390;
        case 0x1c93c8u: goto label_1c93c8;
        case 0x1c9410u: goto label_1c9410;
        case 0x1c945cu: goto label_1c945c;
        case 0x1c9474u: goto label_1c9474;
        case 0x1c94b4u: goto label_1c94b4;
        default: break;
    }

    ctx->pc = 0x1c92f0u;

    // 0x1c92f0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1c92f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1c92f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c92f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c92f8: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1c92f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1c92fc: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1c92fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1c9300: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c9300u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c9304: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c9304u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c9308: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1c9308u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c930c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c930cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c9310: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1c9310u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9314: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c9314u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c9318: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1c9318u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c931c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c931cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c9320: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x1c9320u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c9324: 0x10620036  beq         $v1, $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x1C9324u;
    {
        const bool branch_taken_0x1c9324 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C9328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9324u;
            // 0x1c9328: 0xe0882d  daddu       $s1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9324) {
            ctx->pc = 0x1C9400u;
            goto label_1c9400;
        }
    }
    ctx->pc = 0x1C932Cu;
    // 0x1c932c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C932Cu;
    {
        const bool branch_taken_0x1c932c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C932Cu;
            // 0x1c9330: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c932c) {
            ctx->pc = 0x1C933Cu;
            goto label_1c933c;
        }
    }
    ctx->pc = 0x1C9334u;
    // 0x1c9334: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1C9334u;
    {
        const bool branch_taken_0x1c9334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9334u;
            // 0x1c9338: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9334) {
            ctx->pc = 0x1C9500u;
            goto label_1c9500;
        }
    }
    ctx->pc = 0x1C933Cu;
label_1c933c:
    // 0x1c933c: 0xc072428  jal         func_1C90A0
    ctx->pc = 0x1C933Cu;
    SET_GPR_U32(ctx, 31, 0x1C9344u);
    ctx->pc = 0x1C90A0u;
    if (runtime->hasFunction(0x1C90A0u)) {
        auto targetFn = runtime->lookupFunction(0x1C90A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9344u; }
        if (ctx->pc != 0x1C9344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C90A0_0x1c90a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9344u; }
        if (ctx->pc != 0x1C9344u) { return; }
    }
    ctx->pc = 0x1C9344u;
label_1c9344:
    // 0x1c9344: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1c9344u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1c9348: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x1c9348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1c934c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C934Cu;
    {
        const bool branch_taken_0x1c934c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C934Cu;
            // 0x1c9350: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c934c) {
            ctx->pc = 0x1C9364u;
            goto label_1c9364;
        }
    }
    ctx->pc = 0x1C9354u;
    // 0x1c9354: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9354u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9358: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c9358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c935c: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1C935Cu;
    {
        const bool branch_taken_0x1c935c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C935Cu;
            // 0x1c9360: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c935c) {
            ctx->pc = 0x1C9500u;
            goto label_1c9500;
        }
    }
    ctx->pc = 0x1C9364u;
label_1c9364:
    // 0x1c9364: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1C9364u;
    {
        const bool branch_taken_0x1c9364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9364u;
            // 0x1c9368: 0x2a020008  slti        $v0, $s0, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9364) {
            ctx->pc = 0x1C93B8u;
            goto label_1c93b8;
        }
    }
    ctx->pc = 0x1C936Cu;
label_1c936c:
    // 0x1c936c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1c936cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1c9370: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1c9370u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1c9374: 0x2442d170  addiu       $v0, $v0, -0x2E90
    ctx->pc = 0x1c9374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955376));
    // 0x1c9378: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c9378u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c937c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c937cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9380: 0x43a821  addu        $s5, $v0, $v1
    ctx->pc = 0x1c9380u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c9384: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1c9384u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1c9388: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1C9388u;
    SET_GPR_U32(ctx, 31, 0x1C9390u);
    ctx->pc = 0x1C938Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9388u;
            // 0x1c938c: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9390u; }
        if (ctx->pc != 0x1C9390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9390u; }
        if (ctx->pc != 0x1C9390u) { return; }
    }
    ctx->pc = 0x1C9390u;
label_1c9390:
    // 0x1c9390: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C9390u;
    {
        const bool branch_taken_0x1c9390 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c9390) {
            ctx->pc = 0x1C93B0u;
            goto label_1c93b0;
        }
    }
    ctx->pc = 0x1C9398u;
    // 0x1c9398: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9398u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c939c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c939cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c93a0: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1c93a0u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c93a4: 0x8ea30100  lw          $v1, 0x100($s5)
    ctx->pc = 0x1c93a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 256)));
    // 0x1c93a8: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x1C93A8u;
    {
        const bool branch_taken_0x1c93a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C93ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C93A8u;
            // 0x1c93ac: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c93a8) {
            ctx->pc = 0x1C9500u;
            goto label_1c9500;
        }
    }
    ctx->pc = 0x1C93B0u;
label_1c93b0:
    // 0x1c93b0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1c93b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1c93b4: 0x2a020008  slti        $v0, $s0, 0x8
    ctx->pc = 0x1c93b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)8) ? 1 : 0);
label_1c93b8:
    // 0x1c93b8: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1C93B8u;
    {
        const bool branch_taken_0x1c93b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C93BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C93B8u;
            // 0x1c93bc: 0x101980  sll         $v1, $s0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c93b8) {
            ctx->pc = 0x1C936Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c936c;
        }
    }
    ctx->pc = 0x1C93C0u;
    // 0x1c93c0: 0xc075b30  jal         func_1D6CC0
    ctx->pc = 0x1C93C0u;
    SET_GPR_U32(ctx, 31, 0x1C93C8u);
    ctx->pc = 0x1C93C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C93C0u;
            // 0x1c93c4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6CC0u;
    if (runtime->hasFunction(0x1D6CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D6CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C93C8u; }
        if (ctx->pc != 0x1C93C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6CC0_0x1d6cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C93C8u; }
        if (ctx->pc != 0x1C93C8u) { return; }
    }
    ctx->pc = 0x1C93C8u;
label_1c93c8:
    // 0x1c93c8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c93c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c93cc: 0xa422d990  sh          $v0, -0x2670($at)
    ctx->pc = 0x1c93ccu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957456), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c93d0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c93d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c93d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c93d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c93d8: 0x8423d990  lh          $v1, -0x2670($at)
    ctx->pc = 0x1c93d8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294957456)));
    // 0x1c93dc: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C93DCu;
    {
        const bool branch_taken_0x1c93dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c93dc) {
            ctx->pc = 0x1C93ECu;
            goto label_1c93ec;
        }
    }
    ctx->pc = 0x1C93E4u;
    // 0x1c93e4: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1C93E4u;
    {
        const bool branch_taken_0x1c93e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C93E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C93E4u;
            // 0x1c93e8: 0xdfbf0060  ld          $ra, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c93e4) {
            ctx->pc = 0x1C9504u;
            goto label_1c9504;
        }
    }
    ctx->pc = 0x1C93ECu;
label_1c93ec:
    // 0x1c93ec: 0x82820000  lb          $v0, 0x0($s4)
    ctx->pc = 0x1c93ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1c93f0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c93f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c93f4: 0xa2820000  sb          $v0, 0x0($s4)
    ctx->pc = 0x1c93f4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c93f8: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1C93F8u;
    {
        const bool branch_taken_0x1c93f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C93FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C93F8u;
            // 0x1c93fc: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c93f8) {
            ctx->pc = 0x1C94FCu;
            goto label_1c94fc;
        }
    }
    ctx->pc = 0x1C9400u;
label_1c9400:
    // 0x1c9400: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9400u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9404: 0x8424d990  lh          $a0, -0x2670($at)
    ctx->pc = 0x1c9404u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294957456)));
    // 0x1c9408: 0xc075b58  jal         func_1D6D60
    ctx->pc = 0x1C9408u;
    SET_GPR_U32(ctx, 31, 0x1C9410u);
    ctx->pc = 0x1C940Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9408u;
            // 0x1c940c: 0x27a5007c  addiu       $a1, $sp, 0x7C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 124));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6D60u;
    if (runtime->hasFunction(0x1D6D60u)) {
        auto targetFn = runtime->lookupFunction(0x1D6D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9410u; }
        if (ctx->pc != 0x1C9410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6D60_0x1d6d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9410u; }
        if (ctx->pc != 0x1C9410u) { return; }
    }
    ctx->pc = 0x1C9410u;
label_1c9410:
    // 0x1c9410: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c9410u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c9414: 0x10430015  beq         $v0, $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1C9414u;
    {
        const bool branch_taken_0x1c9414 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C9418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9414u;
            // 0x1c9418: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9414) {
            ctx->pc = 0x1C946Cu;
            goto label_1c946c;
        }
    }
    ctx->pc = 0x1C941Cu;
    // 0x1c941c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c941cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c9420: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1C9420u;
    {
        const bool branch_taken_0x1c9420 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c9420) {
            ctx->pc = 0x1C9450u;
            goto label_1c9450;
        }
    }
    ctx->pc = 0x1C9428u;
    // 0x1c9428: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x1c9428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1c942c: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C942Cu;
    {
        const bool branch_taken_0x1c942c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c942c) {
            ctx->pc = 0x1C9450u;
            goto label_1c9450;
        }
    }
    ctx->pc = 0x1C9434u;
    // 0x1c9434: 0x2403fffd  addiu       $v1, $zero, -0x3
    ctx->pc = 0x1c9434u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1c9438: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9438u;
    {
        const bool branch_taken_0x1c9438 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c9438) {
            ctx->pc = 0x1C9448u;
            goto label_1c9448;
        }
    }
    ctx->pc = 0x1C9440u;
    // 0x1c9440: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9440u;
    {
        const bool branch_taken_0x1c9440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c9440) {
            ctx->pc = 0x1C9450u;
            goto label_1c9450;
        }
    }
    ctx->pc = 0x1C9448u;
label_1c9448:
    // 0x1c9448: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1C9448u;
    {
        const bool branch_taken_0x1c9448 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C944Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9448u;
            // 0x1c944c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9448) {
            ctx->pc = 0x1C9500u;
            goto label_1c9500;
        }
    }
    ctx->pc = 0x1C9450u;
label_1c9450:
    // 0x1c9450: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9450u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9454: 0xc075b44  jal         func_1D6D10
    ctx->pc = 0x1C9454u;
    SET_GPR_U32(ctx, 31, 0x1C945Cu);
    ctx->pc = 0x1C9458u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9454u;
            // 0x1c9458: 0x8424d990  lh          $a0, -0x2670($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294957456)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6D10u;
    if (runtime->hasFunction(0x1D6D10u)) {
        auto targetFn = runtime->lookupFunction(0x1D6D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C945Cu; }
        if (ctx->pc != 0x1C945Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6D10_0x1d6d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C945Cu; }
        if (ctx->pc != 0x1C945Cu) { return; }
    }
    ctx->pc = 0x1C945Cu;
label_1c945c:
    // 0x1c945c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c945cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9460: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c9460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c9464: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1C9464u;
    {
        const bool branch_taken_0x1c9464 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9464u;
            // 0x1c9468: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9464) {
            ctx->pc = 0x1C9500u;
            goto label_1c9500;
        }
    }
    ctx->pc = 0x1C946Cu;
label_1c946c:
    // 0x1c946c: 0xc075b44  jal         func_1D6D10
    ctx->pc = 0x1C946Cu;
    SET_GPR_U32(ctx, 31, 0x1C9474u);
    ctx->pc = 0x1C9470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C946Cu;
            // 0x1c9470: 0x8424d990  lh          $a0, -0x2670($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294957456)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6D10u;
    if (runtime->hasFunction(0x1D6D10u)) {
        auto targetFn = runtime->lookupFunction(0x1D6D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9474u; }
        if (ctx->pc != 0x1C9474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6D10_0x1d6d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9474u; }
        if (ctx->pc != 0x1C9474u) { return; }
    }
    ctx->pc = 0x1C9474u;
label_1c9474:
    // 0x1c9474: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9474u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9478: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1c9478u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1c947c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1c947cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9480: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9480u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9484: 0x8fa3007c  lw          $v1, 0x7C($sp)
    ctx->pc = 0x1c9484u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x1c9488: 0x2442d170  addiu       $v0, $v0, -0x2E90
    ctx->pc = 0x1c9488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955376));
    // 0x1c948c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c948cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9490: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1c9490u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1c9494: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x1c9494u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x1c9498: 0x8c24d160  lw          $a0, -0x2EA0($at)
    ctx->pc = 0x1c9498u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955360)));
    // 0x1c949c: 0x41980  sll         $v1, $a0, 6
    ctx->pc = 0x1c949cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
    // 0x1c94a0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1c94a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1c94a4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c94a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c94a8: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1c94a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c94ac: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1C94ACu;
    SET_GPR_U32(ctx, 31, 0x1C94B4u);
    ctx->pc = 0x1C94B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C94ACu;
            // 0x1c94b0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C94B4u; }
        if (ctx->pc != 0x1C94B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C94B4u; }
        if (ctx->pc != 0x1C94B4u) { return; }
    }
    ctx->pc = 0x1C94B4u;
label_1c94b4:
    // 0x1c94b4: 0x8fa2007c  lw          $v0, 0x7C($sp)
    ctx->pc = 0x1c94b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
    // 0x1c94b8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c94b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c94bc: 0xae020100  sw          $v0, 0x100($s0)
    ctx->pc = 0x1c94bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 256), GPR_U32(ctx, 2));
    // 0x1c94c0: 0x8c22d160  lw          $v0, -0x2EA0($at)
    ctx->pc = 0x1c94c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955360)));
    // 0x1c94c4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c94c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c94c8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c94c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c94cc: 0xac22d160  sw          $v0, -0x2EA0($at)
    ctx->pc = 0x1c94ccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955360), GPR_U32(ctx, 2));
    // 0x1c94d0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c94d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c94d4: 0x8c23d160  lw          $v1, -0x2EA0($at)
    ctx->pc = 0x1c94d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955360)));
    // 0x1c94d8: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C94D8u;
    {
        const bool branch_taken_0x1c94d8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1C94DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C94D8u;
            // 0x1c94dc: 0x30620007  andi        $v0, $v1, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c94d8) {
            ctx->pc = 0x1C94ECu;
            goto label_1c94ec;
        }
    }
    ctx->pc = 0x1C94E0u;
    // 0x1c94e0: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C94E0u;
    {
        const bool branch_taken_0x1c94e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c94e0) {
            ctx->pc = 0x1C94ECu;
            goto label_1c94ec;
        }
    }
    ctx->pc = 0x1C94E8u;
    // 0x1c94e8: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x1c94e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
label_1c94ec:
    // 0x1c94ec: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c94ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c94f0: 0xac22d160  sw          $v0, -0x2EA0($at)
    ctx->pc = 0x1c94f0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955360), GPR_U32(ctx, 2));
    // 0x1c94f4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C94F4u;
    {
        const bool branch_taken_0x1c94f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C94F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C94F4u;
            // 0x1c94f8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c94f4) {
            ctx->pc = 0x1C9500u;
            goto label_1c9500;
        }
    }
    ctx->pc = 0x1C94FCu;
label_1c94fc:
    // 0x1c94fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c94fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c9500:
    // 0x1c9500: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1c9500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_1c9504:
    // 0x1c9504: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1c9504u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c9508: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c9508u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c950c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c950cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c9510: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c9510u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c9514: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c9514u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c9518: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c9518u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c951c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C951Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C9520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C951Cu;
            // 0x1c9520: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C933Cu: goto label_1c933c;
            case 0x1C9344u: goto label_1c9344;
            case 0x1C9364u: goto label_1c9364;
            case 0x1C936Cu: goto label_1c936c;
            case 0x1C9390u: goto label_1c9390;
            case 0x1C93B0u: goto label_1c93b0;
            case 0x1C93B8u: goto label_1c93b8;
            case 0x1C93C8u: goto label_1c93c8;
            case 0x1C93ECu: goto label_1c93ec;
            case 0x1C9400u: goto label_1c9400;
            case 0x1C9410u: goto label_1c9410;
            case 0x1C9448u: goto label_1c9448;
            case 0x1C9450u: goto label_1c9450;
            case 0x1C945Cu: goto label_1c945c;
            case 0x1C946Cu: goto label_1c946c;
            case 0x1C9474u: goto label_1c9474;
            case 0x1C94B4u: goto label_1c94b4;
            case 0x1C94ECu: goto label_1c94ec;
            case 0x1C94FCu: goto label_1c94fc;
            case 0x1C9500u: goto label_1c9500;
            case 0x1C9504u: goto label_1c9504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C9524u;
    // 0x1c9524: 0x0  nop
    ctx->pc = 0x1c9524u;
    // NOP
    // 0x1c9528: 0x0  nop
    ctx->pc = 0x1c9528u;
    // NOP
    // 0x1c952c: 0x0  nop
    ctx->pc = 0x1c952cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
