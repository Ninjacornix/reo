#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160D48
// Address: 0x160d48 - 0x160d58
void sub_00160D48_0x160d48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160D48_0x160d48");
#endif

    ctx->pc = 0x160d48u;

    // 0x160d48: 0x8c820030  lw          $v0, 0x30($a0)
    ctx->pc = 0x160d48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x160d4c: 0x3e00008  jr          $ra
    ctx->pc = 0x160D4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160D4Cu;
            // 0x160d50: 0xaca2004c  sw          $v0, 0x4C($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 76), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x160D54u;
    // 0x160d54: 0x0  nop
    ctx->pc = 0x160d54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
