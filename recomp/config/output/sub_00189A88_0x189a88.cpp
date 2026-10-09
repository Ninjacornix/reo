#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189A88
// Address: 0x189a88 - 0x189aa8
void sub_00189A88_0x189a88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189A88_0x189a88");
#endif

    ctx->pc = 0x189a88u;

label_189a88:
    // 0x189a88: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x189a88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189a8c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x189a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x189a90: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189a90u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189a94: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x189a94u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x189a98: 0x14c0fffb  bnez        $a2, . + 4 + (-0x5 << 2)
    ctx->pc = 0x189A98u;
    {
        const bool branch_taken_0x189a98 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A98u;
            // 0x189a9c: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189a98) {
            ctx->pc = 0x189A88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189a88;
        }
    }
    ctx->pc = 0x189AA0u;
    // 0x189aa0: 0x3e00008  jr          $ra
    ctx->pc = 0x189AA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189A88u: goto label_189a88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189AA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
