#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147CE8
// Address: 0x147ce8 - 0x147cf0
void sub_00147CE8_0x147ce8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147CE8_0x147ce8");
#endif

    ctx->pc = 0x147ce8u;

    // 0x147ce8: 0x3e00008  jr          $ra
    ctx->pc = 0x147CE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147CECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147CE8u;
            // 0x147cec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x147CF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
