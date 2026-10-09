#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1290
// Address: 0x1c1290 - 0x1c12a0
void sub_001C1290_0x1c1290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1290_0x1c1290");
#endif

    ctx->pc = 0x1c1290u;

    // 0x1c1290: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1290u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1294: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1294u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1294u;
            // 0x1c1298: 0xac206c90  sw          $zero, 0x6C90($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27792), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C129Cu;
    // 0x1c129c: 0x0  nop
    ctx->pc = 0x1c129cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
