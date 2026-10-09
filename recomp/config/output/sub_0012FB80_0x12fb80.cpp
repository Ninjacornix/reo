#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FB80
// Address: 0x12fb80 - 0x12fb88
void sub_0012FB80_0x12fb80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FB80_0x12fb80");
#endif

    ctx->pc = 0x12fb80u;

    // 0x12fb80: 0x3e00008  jr          $ra
    ctx->pc = 0x12FB80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB80u;
            // 0x12fb84: 0xac850050  sw          $a1, 0x50($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 80), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FB88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
