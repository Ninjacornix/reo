#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FDA8
// Address: 0x12fda8 - 0x12fdb0
void sub_0012FDA8_0x12fda8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FDA8_0x12fda8");
#endif

    ctx->pc = 0x12fda8u;

    // 0x12fda8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDA8u;
            // 0x12fdac: 0x8c82002c  lw          $v0, 0x2C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FDB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
