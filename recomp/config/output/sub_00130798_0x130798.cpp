#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130798
// Address: 0x130798 - 0x1307a8
void sub_00130798_0x130798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130798_0x130798");
#endif

    ctx->pc = 0x130798u;

    // 0x130798: 0xac860038  sw          $a2, 0x38($a0)
    ctx->pc = 0x130798u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 6));
    // 0x13079c: 0x3e00008  jr          $ra
    ctx->pc = 0x13079Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1307A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13079Cu;
            // 0x1307a0: 0xac850034  sw          $a1, 0x34($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1307A4u;
    // 0x1307a4: 0x0  nop
    ctx->pc = 0x1307a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
