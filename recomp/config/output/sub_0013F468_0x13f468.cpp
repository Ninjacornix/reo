#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F468
// Address: 0x13f468 - 0x13f474
void sub_0013F468_0x13f468(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F468_0x13f468");
#endif

    ctx->pc = 0x13f468u;

    // 0x13f468: 0xac860020  sw          $a2, 0x20($a0)
    ctx->pc = 0x13f468u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 6));
    // 0x13f46c: 0x3e00008  jr          $ra
    ctx->pc = 0x13F46Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F46Cu;
            // 0x13f470: 0xac85001c  sw          $a1, 0x1C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F474u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
