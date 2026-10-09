#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA250
// Address: 0x1ba250 - 0x1ba330
void sub_001BA250_0x1ba250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA250_0x1ba250");
#endif

    switch (ctx->pc) {
        case 0x1ba2b0u: goto label_1ba2b0;
        case 0x1ba2d4u: goto label_1ba2d4;
        case 0x1ba2f0u: goto label_1ba2f0;
        case 0x1ba300u: goto label_1ba300;
        case 0x1ba314u: goto label_1ba314;
        default: break;
    }

    ctx->pc = 0x1ba250u;

    // 0x1ba250: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ba250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ba254: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1ba254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1ba258: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ba258u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ba25c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ba25cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ba260: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1ba260u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba264: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1ba264u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba268: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA268u;
    {
        const bool branch_taken_0x1ba268 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1BA26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA268u;
            // 0x1ba26c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba268) {
            ctx->pc = 0x1BA278u;
            goto label_1ba278;
        }
    }
    ctx->pc = 0x1BA270u;
    // 0x1ba270: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1BA270u;
    {
        const bool branch_taken_0x1ba270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA270u;
            // 0x1ba274: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba270) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA278u;
label_1ba278:
    // 0x1ba278: 0x92420002  lbu         $v0, 0x2($s2)
    ctx->pc = 0x1ba278u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x1ba27c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BA27Cu;
    {
        const bool branch_taken_0x1ba27c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA27Cu;
            // 0x1ba280: 0x24100005  addiu       $s0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba27c) {
            ctx->pc = 0x1BA288u;
            goto label_1ba288;
        }
    }
    ctx->pc = 0x1BA284u;
    // 0x1ba284: 0x92500003  lbu         $s0, 0x3($s2)
    ctx->pc = 0x1ba284u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
label_1ba288:
    // 0x1ba288: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1ba288u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1ba28c: 0x2442ae71  addiu       $v0, $v0, -0x518F
    ctx->pc = 0x1ba28cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946417));
    // 0x1ba290: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ba290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ba294: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1ba294u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba298: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA298u;
    {
        const bool branch_taken_0x1ba298 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA29Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA298u;
            // 0x1ba29c: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba298) {
            ctx->pc = 0x1BA2A8u;
            goto label_1ba2a8;
        }
    }
    ctx->pc = 0x1BA2A0u;
    // 0x1ba2a0: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1BA2A0u;
    {
        const bool branch_taken_0x1ba2a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2A0u;
            // 0x1ba2a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2a0) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA2A8u;
label_1ba2a8:
    // 0x1ba2a8: 0xc06b8b8  jal         func_1AE2E0
    ctx->pc = 0x1BA2A8u;
    SET_GPR_U32(ctx, 31, 0x1BA2B0u);
    ctx->pc = 0x1BA2ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2A8u;
            // 0x1ba2ac: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE2E0u;
    if (runtime->hasFunction(0x1AE2E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE2E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2B0u; }
        if (ctx->pc != 0x1BA2B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE2E0_0x1ae2e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2B0u; }
        if (ctx->pc != 0x1BA2B0u) { return; }
    }
    ctx->pc = 0x1BA2B0u;
label_1ba2b0:
    // 0x1ba2b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba2b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba2b4: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA2B4u;
    {
        const bool branch_taken_0x1ba2b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BA2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2B4u;
            // 0x1ba2b8: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2b4) {
            ctx->pc = 0x1BA2C4u;
            goto label_1ba2c4;
        }
    }
    ctx->pc = 0x1BA2BCu;
    // 0x1ba2bc: 0x14440003  bne         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA2BCu;
    {
        const bool branch_taken_0x1ba2bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1BA2C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2BCu;
            // 0x1ba2c0: 0x26060005  addiu       $a2, $s0, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2bc) {
            ctx->pc = 0x1BA2CCu;
            goto label_1ba2cc;
        }
    }
    ctx->pc = 0x1BA2C4u;
label_1ba2c4:
    // 0x1ba2c4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1BA2C4u;
    {
        const bool branch_taken_0x1ba2c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2C4u;
            // 0x1ba2c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2c4) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA2CCu;
label_1ba2cc:
    // 0x1ba2cc: 0xc06e85c  jal         func_1BA170
    ctx->pc = 0x1BA2CCu;
    SET_GPR_U32(ctx, 31, 0x1BA2D4u);
    ctx->pc = 0x1BA2D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2CCu;
            // 0x1ba2d0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA170u;
    if (runtime->hasFunction(0x1BA170u)) {
        auto targetFn = runtime->lookupFunction(0x1BA170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2D4u; }
        if (ctx->pc != 0x1BA2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA170_0x1ba170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2D4u; }
        if (ctx->pc != 0x1BA2D4u) { return; }
    }
    ctx->pc = 0x1BA2D4u;
label_1ba2d4:
    // 0x1ba2d4: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1BA2D4u;
    {
        const bool branch_taken_0x1ba2d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2D4u;
            // 0x1ba2d8: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2d4) {
            ctx->pc = 0x1BA314u;
            goto label_1ba314;
        }
    }
    ctx->pc = 0x1BA2DCu;
    // 0x1ba2dc: 0x26440038  addiu       $a0, $s2, 0x38
    ctx->pc = 0x1ba2dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 56));
    // 0x1ba2e0: 0x8c254bf4  lw          $a1, 0x4BF4($at)
    ctx->pc = 0x1ba2e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 19444)));
    // 0x1ba2e4: 0x27a6004c  addiu       $a2, $sp, 0x4C
    ctx->pc = 0x1ba2e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
    // 0x1ba2e8: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1BA2E8u;
    SET_GPR_U32(ctx, 31, 0x1BA2F0u);
    ctx->pc = 0x1BA2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2E8u;
            // 0x1ba2ec: 0x27a70048  addiu       $a3, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2F0u; }
        if (ctx->pc != 0x1BA2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA2F0u; }
        if (ctx->pc != 0x1BA2F0u) { return; }
    }
    ctx->pc = 0x1BA2F0u;
label_1ba2f0:
    // 0x1ba2f0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA2F0u;
    {
        const bool branch_taken_0x1ba2f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BA2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2F0u;
            // 0x1ba2f4: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba2f0) {
            ctx->pc = 0x1BA308u;
            goto label_1ba308;
        }
    }
    ctx->pc = 0x1BA2F8u;
    // 0x1ba2f8: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1BA2F8u;
    SET_GPR_U32(ctx, 31, 0x1BA300u);
    ctx->pc = 0x1BA2FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA2F8u;
            // 0x1ba2fc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA300u; }
        if (ctx->pc != 0x1BA300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA300u; }
        if (ctx->pc != 0x1BA300u) { return; }
    }
    ctx->pc = 0x1BA300u;
label_1ba300:
    // 0x1ba300: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA300u;
    {
        const bool branch_taken_0x1ba300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA300u;
            // 0x1ba304: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba300) {
            ctx->pc = 0x1BA318u;
            goto label_1ba318;
        }
    }
    ctx->pc = 0x1BA308u;
label_1ba308:
    // 0x1ba308: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x1ba308u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1ba30c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1BA30Cu;
    SET_GPR_U32(ctx, 31, 0x1BA314u);
    ctx->pc = 0x1BA310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA30Cu;
            // 0x1ba310: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA314u; }
        if (ctx->pc != 0x1BA314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA314u; }
        if (ctx->pc != 0x1BA314u) { return; }
    }
    ctx->pc = 0x1BA314u;
label_1ba314:
    // 0x1ba314: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ba314u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ba318:
    // 0x1ba318: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1ba318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ba31c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ba31cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ba320: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ba320u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ba324: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba324u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba328: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA328u;
            // 0x1ba32c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA278u: goto label_1ba278;
            case 0x1BA288u: goto label_1ba288;
            case 0x1BA2A8u: goto label_1ba2a8;
            case 0x1BA2B0u: goto label_1ba2b0;
            case 0x1BA2C4u: goto label_1ba2c4;
            case 0x1BA2CCu: goto label_1ba2cc;
            case 0x1BA2D4u: goto label_1ba2d4;
            case 0x1BA2F0u: goto label_1ba2f0;
            case 0x1BA300u: goto label_1ba300;
            case 0x1BA308u: goto label_1ba308;
            case 0x1BA314u: goto label_1ba314;
            case 0x1BA318u: goto label_1ba318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA330u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
