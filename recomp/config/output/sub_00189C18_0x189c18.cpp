#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189C18
// Address: 0x189c18 - 0x189c30
void sub_00189C18_0x189c18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189C18_0x189c18");
#endif

    ctx->pc = 0x189c18u;

label_189c18:
    // 0x189c18: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x189c18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x189c1c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x189c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x189c20: 0x14a0fffd  bnez        $a1, . + 4 + (-0x3 << 2)
    ctx->pc = 0x189C20u;
    {
        const bool branch_taken_0x189c20 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x189C24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189C20u;
            // 0x189c24: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189c20) {
            ctx->pc = 0x189C18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189c18;
        }
    }
    ctx->pc = 0x189C28u;
    // 0x189c28: 0x3e00008  jr          $ra
    ctx->pc = 0x189C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189C18u: goto label_189c18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189C30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
