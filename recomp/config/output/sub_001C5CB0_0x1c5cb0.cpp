#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5CB0
// Address: 0x1c5cb0 - 0x1c5ce0
void sub_001C5CB0_0x1c5cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5CB0_0x1c5cb0");
#endif

    switch (ctx->pc) {
        case 0x1c5cbcu: goto label_1c5cbc;
        default: break;
    }

    ctx->pc = 0x1c5cb0u;

    // 0x1c5cb0: 0x8ca50000  lw          $a1, 0x0($a1)
    ctx->pc = 0x1c5cb0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c5cb4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C5CB4u;
    {
        const bool branch_taken_0x1c5cb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5CB4u;
            // 0x1c5cb8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5cb4) {
            ctx->pc = 0x1C5CD0u;
            goto label_1c5cd0;
        }
    }
    ctx->pc = 0x1C5CBCu;
label_1c5cbc:
    // 0x1c5cbc: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x1c5cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1c5cc0: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1c5cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1c5cc4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1c5cc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1c5cc8: 0xac650000  sw          $a1, 0x0($v1)
    ctx->pc = 0x1c5cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
    // 0x1c5ccc: 0x8ca50004  lw          $a1, 0x4($a1)
    ctx->pc = 0x1c5cccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
label_1c5cd0:
    // 0x1c5cd0: 0x14a0fffa  bnez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C5CD0u;
    {
        const bool branch_taken_0x1c5cd0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c5cd0) {
            ctx->pc = 0x1C5CBCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5cbc;
        }
    }
    ctx->pc = 0x1C5CD8u;
    // 0x1c5cd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5CD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5CBCu: goto label_1c5cbc;
            case 0x1C5CD0u: goto label_1c5cd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5CE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
