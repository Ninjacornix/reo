#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D738
// Address: 0x12d738 - 0x12d748
void sub_0012D738_0x12d738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D738_0x12d738");
#endif

    ctx->pc = 0x12d738u;

    // 0x12d738: 0xac86004c  sw          $a2, 0x4C($a0)
    ctx->pc = 0x12d738u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 6));
    // 0x12d73c: 0x3e00008  jr          $ra
    ctx->pc = 0x12D73Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D73Cu;
            // 0x12d740: 0xac850048  sw          $a1, 0x48($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D744u;
    // 0x12d744: 0x0  nop
    ctx->pc = 0x12d744u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
