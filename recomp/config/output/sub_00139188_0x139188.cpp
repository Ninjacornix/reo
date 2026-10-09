#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139188
// Address: 0x139188 - 0x139198
void sub_00139188_0x139188(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139188_0x139188");
#endif

    ctx->pc = 0x139188u;

    // 0x139188: 0xac86002c  sw          $a2, 0x2C($a0)
    ctx->pc = 0x139188u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 6));
    // 0x13918c: 0x3e00008  jr          $ra
    ctx->pc = 0x13918Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13918Cu;
            // 0x139190: 0xac850028  sw          $a1, 0x28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x139194u;
    // 0x139194: 0x0  nop
    ctx->pc = 0x139194u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
