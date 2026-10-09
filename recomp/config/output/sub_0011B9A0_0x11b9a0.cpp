#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011B9A0
// Address: 0x11b9a0 - 0x11ba18
void sub_0011B9A0_0x11b9a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011B9A0_0x11b9a0");
#endif

    switch (ctx->pc) {
        case 0x11b9fcu: goto label_11b9fc;
        default: break;
    }

    ctx->pc = 0x11b9a0u;

    // 0x11b9a0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11b9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11b9a4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11b9a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11b9a8: 0x8c629df8  lw          $v0, -0x6208($v1)
    ctx->pc = 0x11b9a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942200)));
    // 0x11b9ac: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11b9acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b9b0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11b9b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11b9b4: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11B9B4u;
    {
        const bool branch_taken_0x11b9b4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B9B4u;
            // 0x11b9b8: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b9b4) {
            ctx->pc = 0x11B9C4u;
            goto label_11b9c4;
        }
    }
    ctx->pc = 0x11B9BCu;
    // 0x11b9bc: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x11B9BCu;
    {
        const bool branch_taken_0x11b9bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B9C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B9BCu;
            // 0x11b9c0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b9bc) {
            ctx->pc = 0x11BA08u;
            goto label_11ba08;
        }
    }
    ctx->pc = 0x11B9C4u;
label_11b9c4:
    // 0x11b9c4: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x11b9c4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x11b9c8: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11b9c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11b9cc: 0xace5e2c0  sw          $a1, -0x1D40($a3)
    ctx->pc = 0x11b9ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294959808), GPR_U32(ctx, 5));
    // 0x11b9d0: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11b9d0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11b9d4: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11b9d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11b9d8: 0x24e7e2c0  addiu       $a3, $a3, -0x1D40
    ctx->pc = 0x11b9d8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959808));
    // 0x11b9dc: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b9dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b9e0: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x11b9e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11b9e4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b9e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b9e8: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11b9e8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b9ec: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11b9ecu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11b9f0: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b9f0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b9f4: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B9F4u;
    SET_GPR_U32(ctx, 31, 0x11B9FCu);
    ctx->pc = 0x11B9F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B9F4u;
            // 0x11b9f8: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B9FCu; }
        if (ctx->pc != 0x11B9FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B9FCu; }
        if (ctx->pc != 0x11B9FCu) { return; }
    }
    ctx->pc = 0x11B9FCu;
label_11b9fc:
    // 0x11b9fc: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x11B9FCu;
    {
        const bool branch_taken_0x11b9fc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B9FCu;
            // 0x11ba00: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b9fc) {
            ctx->pc = 0x11BA08u;
            goto label_11ba08;
        }
    }
    ctx->pc = 0x11BA04u;
    // 0x11ba04: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11ba04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_11ba08:
    // 0x11ba08: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ba08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ba0c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11ba0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ba10: 0x3e00008  jr          $ra
    ctx->pc = 0x11BA10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BA10u;
            // 0x11ba14: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B9C4u: goto label_11b9c4;
            case 0x11B9FCu: goto label_11b9fc;
            case 0x11BA08u: goto label_11ba08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BA18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
