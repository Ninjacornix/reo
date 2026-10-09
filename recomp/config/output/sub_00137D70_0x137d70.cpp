#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137D70
// Address: 0x137d70 - 0x137d7c
void sub_00137D70_0x137d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137D70_0x137d70");
#endif

    ctx->pc = 0x137d70u;

    // 0x137d70: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137d70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137d74: 0x3e00008  jr          $ra
    ctx->pc = 0x137D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137D74u;
            // 0x137d78: 0x8c62bbc4  lw          $v0, -0x443C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294949828)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x137D7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
