#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8950
// Address: 0x1c8950 - 0x1c8960
void sub_001C8950_0x1c8950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8950_0x1c8950");
#endif

    ctx->pc = 0x1c8950u;

    // 0x1c8950: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x1c8950u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1c8954: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1c8954u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c8958: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8958u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C895Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8958u;
            // 0x1c895c: 0x621023  subu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8960u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
