#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173C00
// Address: 0x173c00 - 0x173c10
void sub_00173C00_0x173c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173C00_0x173c00");
#endif

    ctx->pc = 0x173c00u;

    // 0x173c00: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x173c00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x173c04: 0x3e00008  jr          $ra
    ctx->pc = 0x173C04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173C04u;
            // 0x173c08: 0x8c62f184  lw          $v0, -0xE7C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963588)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x173C0Cu;
    // 0x173c0c: 0x0  nop
    ctx->pc = 0x173c0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
