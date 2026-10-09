#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CD08
// Address: 0x13cd08 - 0x13cd10
void sub_0013CD08_0x13cd08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CD08_0x13cd08");
#endif

    ctx->pc = 0x13cd08u;

    // 0x13cd08: 0x3e00008  jr          $ra
    ctx->pc = 0x13CD08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CD0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD08u;
            // 0x13cd0c: 0xac850028  sw          $a1, 0x28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13CD10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
