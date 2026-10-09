#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B55D0
// Address: 0x1b55d0 - 0x1b55f0
void sub_001B55D0_0x1b55d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B55D0_0x1b55d0");
#endif

    ctx->pc = 0x1b55d0u;

    // 0x1b55d0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b55d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b55d4: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b55d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b55d8: 0xac64006c  sw          $a0, 0x6C($v1)
    ctx->pc = 0x1b55d8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 108), GPR_U32(ctx, 4));
    // 0x1b55dc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b55dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b55e0: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b55e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b55e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B55E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B55E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B55E4u;
            // 0x1b55e8: 0xac640098  sw          $a0, 0x98($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 152), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B55ECu;
    // 0x1b55ec: 0x0  nop
    ctx->pc = 0x1b55ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
