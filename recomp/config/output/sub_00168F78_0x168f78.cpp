#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168F78
// Address: 0x168f78 - 0x168f88
void sub_00168F78_0x168f78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168F78_0x168f78");
#endif

    ctx->pc = 0x168f78u;

    // 0x168f78: 0xac800090  sw          $zero, 0x90($a0)
    ctx->pc = 0x168f78u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 144), GPR_U32(ctx, 0));
    // 0x168f7c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x168f7cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x168f80: 0x3e00008  jr          $ra
    ctx->pc = 0x168F80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168F80u;
            // 0x168f84: 0xac80000c  sw          $zero, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x168F88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
