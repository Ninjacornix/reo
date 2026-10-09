#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E768
// Address: 0x17e768 - 0x17e778
void sub_0017E768_0x17e768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E768_0x17e768");
#endif

    ctx->pc = 0x17e768u;

    // 0x17e768: 0x24020015  addiu       $v0, $zero, 0x15
    ctx->pc = 0x17e768u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x17e76c: 0x3e00008  jr          $ra
    ctx->pc = 0x17E76Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E76Cu;
            // 0x17e770: 0x4100a  movz        $v0, $zero, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17E774u;
    // 0x17e774: 0x0  nop
    ctx->pc = 0x17e774u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
