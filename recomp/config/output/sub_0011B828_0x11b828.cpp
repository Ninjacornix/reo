#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011B828
// Address: 0x11b828 - 0x11b8b0
void sub_0011B828_0x11b828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011B828_0x11b828");
#endif

    switch (ctx->pc) {
        case 0x11b840u: goto label_11b840;
        case 0x11b848u: goto label_11b848;
        case 0x11b87cu: goto label_11b87c;
        default: break;
    }

    ctx->pc = 0x11b828u;

    // 0x11b828: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11b828u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11b82c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11b82cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11b830: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11b830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11b834: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x11b834u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x11b838: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x11B838u;
    {
        const bool branch_taken_0x11b838 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B83Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B838u;
            // 0x11b83c: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b838) {
            ctx->pc = 0x11B864u;
            goto label_11b864;
        }
    }
    ctx->pc = 0x11B840u;
label_11b840:
    // 0x11b840: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x11b840u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x11b844: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x11b844u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_11b848:
    // 0x11b848: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x11b848u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x11b84c: 0x0  nop
    ctx->pc = 0x11b84cu;
    // NOP
    // 0x11b850: 0x0  nop
    ctx->pc = 0x11b850u;
    // NOP
    // 0x11b854: 0x0  nop
    ctx->pc = 0x11b854u;
    // NOP
    // 0x11b858: 0x0  nop
    ctx->pc = 0x11b858u;
    // NOP
    // 0x11b85c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11B85Cu;
    {
        const bool branch_taken_0x11b85c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x11b85c) {
            ctx->pc = 0x11B848u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b848;
        }
    }
    ctx->pc = 0x11B864u;
label_11b864:
    // 0x11b864: 0x2630e240  addiu       $s0, $s1, -0x1DC0
    ctx->pc = 0x11b864u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294959680));
    // 0x11b868: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x11b868u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x11b86c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11b86cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b870: 0x34a50003  ori         $a1, $a1, 0x3
    ctx->pc = 0x11b870u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3);
    // 0x11b874: 0xc045e06  jal         func_117818
    ctx->pc = 0x11B874u;
    SET_GPR_U32(ctx, 31, 0x11B87Cu);
    ctx->pc = 0x11B878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B874u;
            // 0x11b878: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B87Cu; }
        if (ctx->pc != 0x11B87Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B87Cu; }
        if (ctx->pc != 0x11B87Cu) { return; }
    }
    ctx->pc = 0x11B87Cu;
label_11b87c:
    // 0x11b87c: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11B87Cu;
    {
        const bool branch_taken_0x11b87c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11b87c) {
            ctx->pc = 0x11B880u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B87Cu;
            // 0x11b880: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B88Cu;
            goto label_11b88c;
        }
    }
    ctx->pc = 0x11B884u;
    // 0x11b884: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11B884u;
    {
        const bool branch_taken_0x11b884 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B884u;
            // 0x11b888: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b884) {
            ctx->pc = 0x11B89Cu;
            goto label_11b89c;
        }
    }
    ctx->pc = 0x11B88Cu;
label_11b88c:
    // 0x11b88c: 0x1040ffec  beqz        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x11B88Cu;
    {
        const bool branch_taken_0x11b88c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B88Cu;
            // 0x11b890: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b88c) {
            ctx->pc = 0x11B840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b840;
        }
    }
    ctx->pc = 0x11B894u;
    // 0x11b894: 0xac409df8  sw          $zero, -0x6208($v0)
    ctx->pc = 0x11b894u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942200), GPR_U32(ctx, 0));
    // 0x11b898: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11b898u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11b89c:
    // 0x11b89c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11b89cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11b8a0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11b8a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11b8a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11b8a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11b8a8: 0x3e00008  jr          $ra
    ctx->pc = 0x11B8A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B8ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B8A8u;
            // 0x11b8ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B840u: goto label_11b840;
            case 0x11B848u: goto label_11b848;
            case 0x11B864u: goto label_11b864;
            case 0x11B87Cu: goto label_11b87c;
            case 0x11B88Cu: goto label_11b88c;
            case 0x11B89Cu: goto label_11b89c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B8B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
