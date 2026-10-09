#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174848
// Address: 0x174848 - 0x174874
void sub_00174848_0x174848(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174848_0x174848");
#endif

    ctx->pc = 0x174848u;

    // 0x174848: 0x8c832ab0  lw          $v1, 0x2AB0($a0)
    ctx->pc = 0x174848u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10928)));
    // 0x17484c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17484Cu;
    {
        const bool branch_taken_0x17484c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x17484c) {
            ctx->pc = 0x17486Cu;
            goto label_17486c;
        }
    }
    ctx->pc = 0x174854u;
    // 0x174854: 0x8c620da4  lw          $v0, 0xDA4($v1)
    ctx->pc = 0x174854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 3492)));
    // 0x174858: 0x4420001  bltzl       $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x174858u;
    {
        const bool branch_taken_0x174858 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x174858) {
            ctx->pc = 0x17485Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x174858u;
            // 0x17485c: 0xac650da4  sw          $a1, 0xDA4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 3492), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x174860u;
            goto label_174860;
        }
    }
    ctx->pc = 0x174860u;
label_174860:
    // 0x174860: 0x8c620da8  lw          $v0, 0xDA8($v1)
    ctx->pc = 0x174860u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 3496)));
    // 0x174864: 0x4420001  bltzl       $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x174864u;
    {
        const bool branch_taken_0x174864 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x174864) {
            ctx->pc = 0x174868u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x174864u;
            // 0x174868: 0xac660da8  sw          $a2, 0xDA8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 3496), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17486Cu;
            goto label_17486c;
        }
    }
    ctx->pc = 0x17486Cu;
label_17486c:
    // 0x17486c: 0x3e00008  jr          $ra
    ctx->pc = 0x17486Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174860u: goto label_174860;
            case 0x17486Cu: goto label_17486c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174874u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
