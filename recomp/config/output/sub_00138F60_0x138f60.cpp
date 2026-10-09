#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138F60
// Address: 0x138f60 - 0x138f74
void sub_00138F60_0x138f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138F60_0x138f60");
#endif

    ctx->pc = 0x138f60u;

    // 0x138f60: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x138f60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x138f64: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x138f64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x138f68: 0xac800024  sw          $zero, 0x24($a0)
    ctx->pc = 0x138f68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x138f6c: 0x3e00008  jr          $ra
    ctx->pc = 0x138F6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138F6Cu;
            // 0x138f70: 0xac800028  sw          $zero, 0x28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x138F74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
