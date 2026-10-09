#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171520
// Address: 0x171520 - 0x171530
void sub_00171520_0x171520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171520_0x171520");
#endif

    ctx->pc = 0x171520u;

    // 0x171520: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x171520u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x171524: 0x3e00008  jr          $ra
    ctx->pc = 0x171524u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171524u;
            // 0x171528: 0xac44f1c0  sw          $a0, -0xE40($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963648), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17152Cu;
    // 0x17152c: 0x0  nop
    ctx->pc = 0x17152cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
