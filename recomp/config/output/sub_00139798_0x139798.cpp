#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139798
// Address: 0x139798 - 0x139828
void sub_00139798_0x139798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139798_0x139798");
#endif

    switch (ctx->pc) {
        case 0x1397bcu: goto label_1397bc;
        case 0x1397d0u: goto label_1397d0;
        case 0x1397e4u: goto label_1397e4;
        default: break;
    }

    ctx->pc = 0x139798u;

    // 0x139798: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x139798u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13979c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13979cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1397a0: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x1397a0u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x1397a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1397a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1397a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1397a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1397ac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1397acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1397b0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1397b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1397b4: 0xc050864  jal         func_142190
    ctx->pc = 0x1397B4u;
    SET_GPR_U32(ctx, 31, 0x1397BCu);
    ctx->pc = 0x1397B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1397B4u;
            // 0x1397b8: 0x2664cbf0  addiu       $a0, $s3, -0x3410 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294953968));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142190u;
    if (runtime->hasFunction(0x142190u)) {
        auto targetFn = runtime->lookupFunction(0x142190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1397BCu; }
        if (ctx->pc != 0x1397BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142190_0x142190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1397BCu; }
        if (ctx->pc != 0x1397BCu) { return; }
    }
    ctx->pc = 0x1397BCu;
label_1397bc:
    // 0x1397bc: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1397BCu;
    {
        const bool branch_taken_0x1397bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1397C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1397BCu;
            // 0x1397c0: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1397bc) {
            ctx->pc = 0x1397F4u;
            goto label_1397f4;
        }
    }
    ctx->pc = 0x1397C4u;
    // 0x1397c4: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1397c4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1397c8: 0x2450cc60  addiu       $s0, $v0, -0x33A0
    ctx->pc = 0x1397c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954080));
    // 0x1397cc: 0x24110027  addiu       $s1, $zero, 0x27
    ctx->pc = 0x1397ccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
label_1397d0:
    // 0x1397d0: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1397d0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1397d4: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1397D4u;
    {
        const bool branch_taken_0x1397d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x1397d4) {
            ctx->pc = 0x1397D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1397D4u;
            // 0x1397d8: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1397E8u;
            goto label_1397e8;
        }
    }
    ctx->pc = 0x1397DCu;
    // 0x1397dc: 0xc04e5b4  jal         func_1396D0
    ctx->pc = 0x1397DCu;
    SET_GPR_U32(ctx, 31, 0x1397E4u);
    ctx->pc = 0x1397E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1397DCu;
            // 0x1397e0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1396D0u;
    if (runtime->hasFunction(0x1396D0u)) {
        auto targetFn = runtime->lookupFunction(0x1396D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1397E4u; }
        if (ctx->pc != 0x1397E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001396D0_0x1396d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1397E4u; }
        if (ctx->pc != 0x1397E4u) { return; }
    }
    ctx->pc = 0x1397E4u;
label_1397e4:
    // 0x1397e4: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1397e4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_1397e8:
    // 0x1397e8: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1397E8u;
    {
        const bool branch_taken_0x1397e8 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1397ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1397E8u;
            // 0x1397ec: 0x26100048  addiu       $s0, $s0, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1397e8) {
            ctx->pc = 0x1397D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1397d0;
        }
    }
    ctx->pc = 0x1397F0u;
    // 0x1397f0: 0xae60cbf0  sw          $zero, -0x3410($s3)
    ctx->pc = 0x1397f0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294953968), GPR_U32(ctx, 0));
label_1397f4:
    // 0x1397f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1397f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1397f8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1397f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1397fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1397fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139800: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x139800u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139804: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x139804u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139808: 0x3e00008  jr          $ra
    ctx->pc = 0x139808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13980Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139808u;
            // 0x13980c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1397BCu: goto label_1397bc;
            case 0x1397D0u: goto label_1397d0;
            case 0x1397E4u: goto label_1397e4;
            case 0x1397E8u: goto label_1397e8;
            case 0x1397F4u: goto label_1397f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139810u;
    // 0x139810: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139810u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139814: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x139814u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x139818: 0xac44cbe4  sw          $a0, -0x341C($v0)
    ctx->pc = 0x139818u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294953956), GPR_U32(ctx, 4));
    // 0x13981c: 0x3e00008  jr          $ra
    ctx->pc = 0x13981Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13981Cu;
            // 0x139820: 0xac65cbe8  sw          $a1, -0x3418($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294953960), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1397BCu: goto label_1397bc;
            case 0x1397D0u: goto label_1397d0;
            case 0x1397E4u: goto label_1397e4;
            case 0x1397E8u: goto label_1397e8;
            case 0x1397F4u: goto label_1397f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139824u;
    // 0x139824: 0x0  nop
    ctx->pc = 0x139824u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
