#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BBB80
// Address: 0x1bbb80 - 0x1bbb9c
void sub_001BBB80_0x1bbb80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BBB80_0x1bbb80");
#endif

    ctx->pc = 0x1bbb80u;

    // 0x1bbb80: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x1bbb80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bbb84: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bbb84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bbb88: 0x14a30002  bne         $a1, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BBB88u;
    {
        const bool branch_taken_0x1bbb88 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x1BBB8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB88u;
            // 0x1bbb8c: 0x3c010039  lui         $at, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbb88) {
            ctx->pc = 0x1BBB94u;
            goto label_1bbb94;
        }
    }
    ctx->pc = 0x1BBB90u;
    // 0x1bbb90: 0xac24eb10  sw          $a0, -0x14F0($at)
    ctx->pc = 0x1bbb90u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961936), GPR_U32(ctx, 4));
label_1bbb94:
    // 0x1bbb94: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBB94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBB94u: goto label_1bbb94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBB9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
