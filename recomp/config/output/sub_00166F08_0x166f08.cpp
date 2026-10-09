#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166F08
// Address: 0x166f08 - 0x166f18
void sub_00166F08_0x166f08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166F08_0x166f08");
#endif

    ctx->pc = 0x166f08u;

    // 0x166f08: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x166f08u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x166f0c: 0x3e00008  jr          $ra
    ctx->pc = 0x166F0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166F0Cu;
            // 0x166f10: 0xac800000  sw          $zero, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x166F14u;
    // 0x166f14: 0x0  nop
    ctx->pc = 0x166f14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
