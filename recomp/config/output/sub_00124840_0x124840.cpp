#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124840
// Address: 0x124840 - 0x12485c
void sub_00124840_0x124840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124840_0x124840");
#endif

    ctx->pc = 0x124840u;

    // 0x124840: 0x8c82008c  lw          $v0, 0x8C($a0)
    ctx->pc = 0x124840u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x124844: 0x8c830088  lw          $v1, 0x88($a0)
    ctx->pc = 0x124844u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0x124848: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x124848u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x12484c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x12484cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x124850: 0xac82008c  sw          $v0, 0x8C($a0)
    ctx->pc = 0x124850u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 140), GPR_U32(ctx, 2));
    // 0x124854: 0x3e00008  jr          $ra
    ctx->pc = 0x124854u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124854u;
            // 0x124858: 0xac830088  sw          $v1, 0x88($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12485Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
