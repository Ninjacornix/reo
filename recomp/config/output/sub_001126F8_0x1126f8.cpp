#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001126F8
// Address: 0x1126f8 - 0x112708
void sub_001126F8_0x1126f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001126F8_0x1126f8");
#endif

    ctx->pc = 0x1126f8u;

    // 0x1126f8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1126f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1126fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1126FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1126FCu;
            // 0x112700: 0x24429c70  addiu       $v0, $v0, -0x6390 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941808));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x112704u;
    // 0x112704: 0x0  nop
    ctx->pc = 0x112704u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
