#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148158
// Address: 0x148158 - 0x148170
void sub_00148158_0x148158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148158_0x148158");
#endif

    ctx->pc = 0x148158u;

    // 0x148158: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x148158u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14815c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x14815cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x148160: 0x8c850008  lw          $a1, 0x8($a0)
    ctx->pc = 0x148160u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x148164: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x148164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x148168: 0x3e00008  jr          $ra
    ctx->pc = 0x148168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14816Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148168u;
            // 0x14816c: 0x451023  subu        $v0, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148170u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
