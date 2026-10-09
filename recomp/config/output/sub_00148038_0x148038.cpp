#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148038
// Address: 0x148038 - 0x148048
void sub_00148038_0x148038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148038_0x148038");
#endif

    ctx->pc = 0x148038u;

    // 0x148038: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148038u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14803c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x14803cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148040: 0x3e00008  jr          $ra
    ctx->pc = 0x148040u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148040u;
            // 0x148044: 0xac6500f0  sw          $a1, 0xF0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 240), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148048u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
