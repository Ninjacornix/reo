#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016FEC8
// Address: 0x16fec8 - 0x16fed0
void sub_0016FEC8_0x16fec8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016FEC8_0x16fec8");
#endif

    ctx->pc = 0x16fec8u;

    // 0x16fec8: 0x3e00008  jr          $ra
    ctx->pc = 0x16FEC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16FECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FEC8u;
            // 0x16fecc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16FED0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
