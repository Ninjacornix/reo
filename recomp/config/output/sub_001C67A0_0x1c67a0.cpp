#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C67A0
// Address: 0x1c67a0 - 0x1c67a8
void sub_001C67A0_0x1c67a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C67A0_0x1c67a0");
#endif

    ctx->pc = 0x1c67a0u;

    // 0x1c67a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C67A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C67A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C67A0u;
            // 0x1c67a4: 0x908201ce  lbu         $v0, 0x1CE($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 462)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C67A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
