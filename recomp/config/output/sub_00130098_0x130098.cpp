#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130098
// Address: 0x130098 - 0x1300a4
void sub_00130098_0x130098(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130098_0x130098");
#endif

    ctx->pc = 0x130098u;

    // 0x130098: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x130098u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13009c: 0x3e00008  jr          $ra
    ctx->pc = 0x13009Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1300A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13009Cu;
            // 0x1300a0: 0xac44a8a4  sw          $a0, -0x575C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294944932), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1300A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
