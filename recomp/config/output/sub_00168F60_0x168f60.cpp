#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168F60
// Address: 0x168f60 - 0x168f78
void sub_00168F60_0x168f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168F60_0x168f60");
#endif

    ctx->pc = 0x168f60u;

    // 0x168f60: 0xac800090  sw          $zero, 0x90($a0)
    ctx->pc = 0x168f60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 144), GPR_U32(ctx, 0));
    // 0x168f64: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x168f64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x168f68: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x168f68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x168f6c: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x168f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x168f70: 0x3e00008  jr          $ra
    ctx->pc = 0x168F70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168F70u;
            // 0x168f74: 0xac80000c  sw          $zero, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x168F78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
