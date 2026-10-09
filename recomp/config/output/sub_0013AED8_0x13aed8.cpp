#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AED8
// Address: 0x13aed8 - 0x13aee4
void sub_0013AED8_0x13aed8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AED8_0x13aed8");
#endif

    ctx->pc = 0x13aed8u;

    // 0x13aed8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13aed8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13aedc: 0x3e00008  jr          $ra
    ctx->pc = 0x13AEDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AEDCu;
            // 0x13aee0: 0x2442d8f0  addiu       $v0, $v0, -0x2710 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957296));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13AEE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
