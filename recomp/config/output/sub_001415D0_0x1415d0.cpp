#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001415D0
// Address: 0x1415d0 - 0x1415e0
void sub_001415D0_0x1415d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001415D0_0x1415d0");
#endif

    ctx->pc = 0x1415d0u;

    // 0x1415d0: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x1415d0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1415d4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1415d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1415d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1415D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1415DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1415D8u;
            // 0x1415dc: 0xa4820002  sh          $v0, 0x2($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1415E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
