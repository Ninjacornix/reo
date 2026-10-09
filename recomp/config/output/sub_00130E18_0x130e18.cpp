#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130E18
// Address: 0x130e18 - 0x130e28
void sub_00130E18_0x130e18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130E18_0x130e18");
#endif

    ctx->pc = 0x130e18u;

    // 0x130e18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130e1c: 0xac860014  sw          $a2, 0x14($a0)
    ctx->pc = 0x130e1cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 6));
    // 0x130e20: 0x3e00008  jr          $ra
    ctx->pc = 0x130E20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E20u;
            // 0x130e24: 0xac850018  sw          $a1, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130E28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
