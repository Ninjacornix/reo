#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E588
// Address: 0x12e588 - 0x12e598
void sub_0012E588_0x12e588(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E588_0x12e588");
#endif

    ctx->pc = 0x12e588u;

    // 0x12e588: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x12e588u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x12e58c: 0x3e00008  jr          $ra
    ctx->pc = 0x12E58Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E58Cu;
            // 0x12e590: 0xa0860058  sb          $a2, 0x58($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 88), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12E594u;
    // 0x12e594: 0x0  nop
    ctx->pc = 0x12e594u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
