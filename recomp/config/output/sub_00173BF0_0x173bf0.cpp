#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173BF0
// Address: 0x173bf0 - 0x173c00
void sub_00173BF0_0x173bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173BF0_0x173bf0");
#endif

    ctx->pc = 0x173bf0u;

    // 0x173bf0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x173bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x173bf4: 0x3e00008  jr          $ra
    ctx->pc = 0x173BF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173BF4u;
            // 0x173bf8: 0xac44f184  sw          $a0, -0xE7C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963588), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x173BFCu;
    // 0x173bfc: 0x0  nop
    ctx->pc = 0x173bfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
