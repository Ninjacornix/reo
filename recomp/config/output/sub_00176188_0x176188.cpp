#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176188
// Address: 0x176188 - 0x176198
void sub_00176188_0x176188(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176188_0x176188");
#endif

    ctx->pc = 0x176188u;

    // 0x176188: 0xac860110  sw          $a2, 0x110($a0)
    ctx->pc = 0x176188u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 272), GPR_U32(ctx, 6));
    // 0x17618c: 0x3e00008  jr          $ra
    ctx->pc = 0x17618Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17618Cu;
            // 0x176190: 0xac85010c  sw          $a1, 0x10C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 268), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x176194u;
    // 0x176194: 0x0  nop
    ctx->pc = 0x176194u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
