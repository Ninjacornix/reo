#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130E88
// Address: 0x130e88 - 0x130e94
void sub_00130E88_0x130e88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130E88_0x130e88");
#endif

    ctx->pc = 0x130e88u;

    // 0x130e88: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x130e88u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x130e8c: 0x3e00008  jr          $ra
    ctx->pc = 0x130E8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E8Cu;
            // 0x130e90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130E94u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
