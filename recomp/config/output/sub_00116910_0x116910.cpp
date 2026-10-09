#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116910
// Address: 0x116910 - 0x11691c
void sub_00116910_0x116910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116910_0x116910");
#endif

    ctx->pc = 0x116910u;

    // 0x116910: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x116910u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x116914: 0x3e00008  jr          $ra
    ctx->pc = 0x116914u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116914u;
            // 0x116918: 0x2442af98  addiu       $v0, $v0, -0x5068 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946712));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11691Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
