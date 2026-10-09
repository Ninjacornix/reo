#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177DD0
// Address: 0x177dd0 - 0x177dd8
void sub_00177DD0_0x177dd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177DD0_0x177dd0");
#endif

    ctx->pc = 0x177dd0u;

    // 0x177dd0: 0x3e00008  jr          $ra
    ctx->pc = 0x177DD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177DD0u;
            // 0x177dd4: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177DD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
