#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A91C0
// Address: 0x1a91c0 - 0x1a91d0
void sub_001A91C0_0x1a91c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A91C0_0x1a91c0");
#endif

    ctx->pc = 0x1a91c0u;

    // 0x1a91c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A91C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A91C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A91C0u;
            // 0x1a91c4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A91C8u;
    // 0x1a91c8: 0x0  nop
    ctx->pc = 0x1a91c8u;
    // NOP
    // 0x1a91cc: 0x0  nop
    ctx->pc = 0x1a91ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
