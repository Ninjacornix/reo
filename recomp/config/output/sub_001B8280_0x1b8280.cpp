#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8280
// Address: 0x1b8280 - 0x1b8290
void sub_001B8280_0x1b8280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8280_0x1b8280");
#endif

    ctx->pc = 0x1b8280u;

    // 0x1b8280: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b8280u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b8284: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8284u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8284u;
            // 0x1b8288: 0x902241b0  lbu         $v0, 0x41B0($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 16816)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B828Cu;
    // 0x1b828c: 0x0  nop
    ctx->pc = 0x1b828cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
