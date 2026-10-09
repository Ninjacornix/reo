#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147FE0
// Address: 0x147fe0 - 0x1480b0
void sub_00147FE0_0x147fe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147FE0_0x147fe0");
#endif

    switch (ctx->pc) {
        case 0x147ff8u: goto label_147ff8;
        default: break;
    }

    ctx->pc = 0x147fe0u;

    // 0x147fe0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x147fe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x147fe4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x147fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x147fe8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x147fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x147fec: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x147fecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147ff0: 0xc051fda  jal         func_147F68
    ctx->pc = 0x147FF0u;
    SET_GPR_U32(ctx, 31, 0x147FF8u);
    ctx->pc = 0x147FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147FF0u;
            // 0x147ff4: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147FF8u; }
        if (ctx->pc != 0x147FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147FF8u; }
        if (ctx->pc != 0x147FF8u) { return; }
    }
    ctx->pc = 0x147FF8u;
label_147ff8:
    // 0x147ff8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x147ff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x147ffc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x147ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148000: 0x3e00008  jr          $ra
    ctx->pc = 0x148000u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148000u;
            // 0x148004: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148008u;
    // 0x148008: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148008u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14800c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x14800cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148010: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x148010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148014: 0xfc650090  sd          $a1, 0x90($v1)
    ctx->pc = 0x148014u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 144), GPR_U64(ctx, 5));
    // 0x148018: 0x3e00008  jr          $ra
    ctx->pc = 0x148018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14801Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148018u;
            // 0x14801c: 0xac64008c  sw          $a0, 0x8C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 140), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148020u;
    // 0x148020: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148020u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x148024: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x148024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148028: 0xfc600090  sd          $zero, 0x90($v1)
    ctx->pc = 0x148028u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 144), GPR_U64(ctx, 0));
    // 0x14802c: 0x3e00008  jr          $ra
    ctx->pc = 0x14802Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14802Cu;
            // 0x148030: 0xac60008c  sw          $zero, 0x8C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 140), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148034u;
    // 0x148034: 0x0  nop
    ctx->pc = 0x148034u;
    // NOP
    // 0x148038: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148038u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14803c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x14803cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148040: 0x3e00008  jr          $ra
    ctx->pc = 0x148040u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148040u;
            // 0x148044: 0xac6500f0  sw          $a1, 0xF0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 240), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148048u;
    // 0x148048: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148048u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14804c: 0x3e00008  jr          $ra
    ctx->pc = 0x14804Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14804Cu;
            // 0x148050: 0x8c6200e4  lw          $v0, 0xE4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 228)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148054u;
    // 0x148054: 0x0  nop
    ctx->pc = 0x148054u;
    // NOP
    // 0x148058: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148058u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14805c: 0x3e00008  jr          $ra
    ctx->pc = 0x14805Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14805Cu;
            // 0x148060: 0x8c6200e8  lw          $v0, 0xE8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 232)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148064u;
    // 0x148064: 0x0  nop
    ctx->pc = 0x148064u;
    // NOP
    // 0x148068: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x148068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14806c: 0x3e00008  jr          $ra
    ctx->pc = 0x14806Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14806Cu;
            // 0x148070: 0x244200cc  addiu       $v0, $v0, 0xCC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 204));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148074u;
    // 0x148074: 0x0  nop
    ctx->pc = 0x148074u;
    // NOP
    // 0x148078: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x148078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14807c: 0x3e00008  jr          $ra
    ctx->pc = 0x14807Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14807Cu;
            // 0x148080: 0x244200cc  addiu       $v0, $v0, 0xCC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 204));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148084u;
    // 0x148084: 0x0  nop
    ctx->pc = 0x148084u;
    // NOP
    // 0x148088: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14808c: 0x8c620100  lw          $v0, 0x100($v1)
    ctx->pc = 0x14808cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 256)));
    // 0x148090: 0x3e00008  jr          $ra
    ctx->pc = 0x148090u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148090u;
            // 0x148094: 0xac650100  sw          $a1, 0x100($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 256), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148098u;
    // 0x148098: 0x8c860040  lw          $a2, 0x40($a0)
    ctx->pc = 0x148098u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14809c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x14809cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1480a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1480a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1480a4: 0xacc30110  sw          $v1, 0x110($a2)
    ctx->pc = 0x1480a4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 272), GPR_U32(ctx, 3));
    // 0x1480a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1480A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1480ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1480A8u;
            // 0x1480ac: 0xfcc50108  sd          $a1, 0x108($a2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 6), 264), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147FF8u: goto label_147ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1480B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
