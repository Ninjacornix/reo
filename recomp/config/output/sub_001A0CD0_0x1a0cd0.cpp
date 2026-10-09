#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0CD0
// Address: 0x1a0cd0 - 0x1a0ce0
void sub_001A0CD0_0x1a0cd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0CD0_0x1a0cd0");
#endif

    ctx->pc = 0x1a0cd0u;

    // 0x1a0cd0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0cd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0cd4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A0CD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0CD4u;
            // 0x1a0cd8: 0xac20fdb0  sw          $zero, -0x250($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966704), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A0CDCu;
    // 0x1a0cdc: 0x0  nop
    ctx->pc = 0x1a0cdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
