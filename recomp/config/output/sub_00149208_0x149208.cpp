#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00149208
// Address: 0x149208 - 0x149218
void sub_00149208_0x149208(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00149208_0x149208");
#endif

    ctx->pc = 0x149208u;

    // 0x149208: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x149208u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x14920c: 0x3e00008  jr          $ra
    ctx->pc = 0x14920Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x149210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14920Cu;
            // 0x149210: 0x2442a800  addiu       $v0, $v0, -0x5800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944768));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x149214u;
    // 0x149214: 0x0  nop
    ctx->pc = 0x149214u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
