#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146C38
// Address: 0x146c38 - 0x146c60
void sub_00146C38_0x146c38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146C38_0x146c38");
#endif

    ctx->pc = 0x146c38u;

    // 0x146c38: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x146c38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x146c3c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x146c3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x146c40: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x146C40u;
    {
        const bool branch_taken_0x146c40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x146C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146C40u;
            // 0x146c44: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146c40) {
            ctx->pc = 0x146C58u;
            goto label_146c58;
        }
    }
    ctx->pc = 0x146C48u;
    // 0x146c48: 0x8c820130  lw          $v0, 0x130($a0)
    ctx->pc = 0x146c48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 304)));
    // 0x146c4c: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x146c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x146c50: 0xac8200c4  sw          $v0, 0xC4($a0)
    ctx->pc = 0x146c50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 196), GPR_U32(ctx, 2));
    // 0x146c54: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x146c54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_146c58:
    // 0x146c58: 0x3e00008  jr          $ra
    ctx->pc = 0x146C58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146C58u;
            // 0x146c5c: 0xac820838  sw          $v0, 0x838($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 2104), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146C58u: goto label_146c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146C60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
