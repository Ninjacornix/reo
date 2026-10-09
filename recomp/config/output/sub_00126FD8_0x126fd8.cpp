#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126FD8
// Address: 0x126fd8 - 0x126fe4
void sub_00126FD8_0x126fd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126FD8_0x126fd8");
#endif

    ctx->pc = 0x126fd8u;

    // 0x126fd8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x126fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x126fdc: 0x3e00008  jr          $ra
    ctx->pc = 0x126FDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126FDCu;
            // 0x126fe0: 0xac44c7a8  sw          $a0, -0x3858($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294952872), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x126FE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
