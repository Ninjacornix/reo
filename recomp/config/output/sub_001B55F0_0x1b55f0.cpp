#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B55F0
// Address: 0x1b55f0 - 0x1b5610
void sub_001B55F0_0x1b55f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B55F0_0x1b55f0");
#endif

    ctx->pc = 0x1b55f0u;

    // 0x1b55f0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b55f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b55f4: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b55f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b55f8: 0xac640070  sw          $a0, 0x70($v1)
    ctx->pc = 0x1b55f8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 112), GPR_U32(ctx, 4));
    // 0x1b55fc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b55fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b5600: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b5600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b5604: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5604u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B5608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5604u;
            // 0x1b5608: 0xac650074  sw          $a1, 0x74($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 116), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B560Cu;
    // 0x1b560c: 0x0  nop
    ctx->pc = 0x1b560cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
