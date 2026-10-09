#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A130
// Address: 0x13a130 - 0x13a140
void sub_0013A130_0x13a130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A130_0x13a130");
#endif

    ctx->pc = 0x13a130u;

    // 0x13a130: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x13a130u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x13a134: 0x212f8  dsll        $v0, $v0, 11
    ctx->pc = 0x13a134u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 11);
    // 0x13a138: 0x3e00008  jr          $ra
    ctx->pc = 0x13A138u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A13Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A138u;
            // 0x13a13c: 0x2103f  dsra32      $v0, $v0, 0 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13A140u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
