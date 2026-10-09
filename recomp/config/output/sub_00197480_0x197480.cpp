#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00197480
// Address: 0x197480 - 0x197490
void sub_00197480_0x197480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00197480_0x197480");
#endif

    ctx->pc = 0x197480u;

    // 0x197480: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197480u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197484: 0x3e00008  jr          $ra
    ctx->pc = 0x197484u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x197488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197484u;
            // 0x197488: 0x8c22fd50  lw          $v0, -0x2B0($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966608)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x19748Cu;
    // 0x19748c: 0x0  nop
    ctx->pc = 0x19748cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
