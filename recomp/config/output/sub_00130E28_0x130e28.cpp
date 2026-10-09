#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130E28
// Address: 0x130e28 - 0x130e40
void sub_00130E28_0x130e28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130E28_0x130e28");
#endif

    ctx->pc = 0x130e28u;

    // 0x130e28: 0xac850028  sw          $a1, 0x28($a0)
    ctx->pc = 0x130e28u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 5));
    // 0x130e2c: 0x3e00008  jr          $ra
    ctx->pc = 0x130E2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E2Cu;
            // 0x130e30: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130E34u;
    // 0x130e34: 0x0  nop
    ctx->pc = 0x130e34u;
    // NOP
    // 0x130e38: 0x3e00008  jr          $ra
    ctx->pc = 0x130E38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130E40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
