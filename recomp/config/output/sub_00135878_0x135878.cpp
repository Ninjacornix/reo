#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135878
// Address: 0x135878 - 0x135888
void sub_00135878_0x135878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135878_0x135878");
#endif

    ctx->pc = 0x135878u;

    // 0x135878: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135878u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x13587c: 0x3e00008  jr          $ra
    ctx->pc = 0x13587Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13587Cu;
            // 0x135880: 0x24422268  addiu       $v0, $v0, 0x2268 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8808));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x135884u;
    // 0x135884: 0x0  nop
    ctx->pc = 0x135884u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
