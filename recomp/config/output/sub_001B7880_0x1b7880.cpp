#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7880
// Address: 0x1b7880 - 0x1b7890
void sub_001B7880_0x1b7880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7880_0x1b7880");
#endif

    ctx->pc = 0x1b7880u;

    // 0x1b7880: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7880u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7884: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7888: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B788Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7888u;
            // 0x1b788c: 0xac64007c  sw          $a0, 0x7C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 124), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B7890u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
