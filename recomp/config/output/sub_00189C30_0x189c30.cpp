#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189C30
// Address: 0x189c30 - 0x189c80
void sub_00189C30_0x189c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189C30_0x189c30");
#endif

    switch (ctx->pc) {
        case 0x189c48u: goto label_189c48;
        case 0x189c60u: goto label_189c60;
        default: break;
    }

    ctx->pc = 0x189c30u;

label_189c30:
    // 0x189c30: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x189c30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x189c34: 0x7c800000  sq          $zero, 0x0($a0)
    ctx->pc = 0x189c34u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 0));
    // 0x189c38: 0x14a0fffd  bnez        $a1, . + 4 + (-0x3 << 2)
    ctx->pc = 0x189C38u;
    {
        const bool branch_taken_0x189c38 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x189C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189C38u;
            // 0x189c3c: 0x24840010  addiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189c38) {
            ctx->pc = 0x189C30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189c30;
        }
    }
    ctx->pc = 0x189C40u;
    // 0x189c40: 0x3e00008  jr          $ra
    ctx->pc = 0x189C40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189C30u: goto label_189c30;
            case 0x189C48u: goto label_189c48;
            case 0x189C60u: goto label_189c60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189C48u;
label_189c48:
    // 0x189c48: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x189c48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x189c4c: 0xac860000  sw          $a2, 0x0($a0)
    ctx->pc = 0x189c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x189c50: 0x14a0fffd  bnez        $a1, . + 4 + (-0x3 << 2)
    ctx->pc = 0x189C50u;
    {
        const bool branch_taken_0x189c50 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x189C54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189C50u;
            // 0x189c54: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189c50) {
            ctx->pc = 0x189C48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189c48;
        }
    }
    ctx->pc = 0x189C58u;
    // 0x189c58: 0x3e00008  jr          $ra
    ctx->pc = 0x189C58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189C30u: goto label_189c30;
            case 0x189C48u: goto label_189c48;
            case 0x189C60u: goto label_189c60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189C60u;
label_189c60:
    // 0x189c60: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x189c60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x189c64: 0x7c860000  sq          $a2, 0x0($a0)
    ctx->pc = 0x189c64u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 6));
    // 0x189c68: 0x14a0fffd  bnez        $a1, . + 4 + (-0x3 << 2)
    ctx->pc = 0x189C68u;
    {
        const bool branch_taken_0x189c68 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x189C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189C68u;
            // 0x189c6c: 0x24840010  addiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189c68) {
            ctx->pc = 0x189C60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189c60;
        }
    }
    ctx->pc = 0x189C70u;
    // 0x189c70: 0x3e00008  jr          $ra
    ctx->pc = 0x189C70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189C30u: goto label_189c30;
            case 0x189C48u: goto label_189c48;
            case 0x189C60u: goto label_189c60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189C78u;
    // 0x189c78: 0x0  nop
    ctx->pc = 0x189c78u;
    // NOP
    // 0x189c7c: 0x0  nop
    ctx->pc = 0x189c7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
