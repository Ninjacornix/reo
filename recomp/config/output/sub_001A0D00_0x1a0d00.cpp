#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0D00
// Address: 0x1a0d00 - 0x1a0d10
void sub_001A0D00_0x1a0d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0D00_0x1a0d00");
#endif

    ctx->pc = 0x1a0d00u;

    // 0x1a0d00: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1a0d00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1a0d04: 0x3e00008  jr          $ra
    ctx->pc = 0x1A0D04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0D04u;
            // 0x1a0d08: 0xac2441a0  sw          $a0, 0x41A0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 16800), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A0D0Cu;
    // 0x1a0d0c: 0x0  nop
    ctx->pc = 0x1a0d0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
