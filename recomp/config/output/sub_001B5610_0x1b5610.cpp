#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5610
// Address: 0x1b5610 - 0x1b5620
void sub_001B5610_0x1b5610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5610_0x1b5610");
#endif

    ctx->pc = 0x1b5610u;

    // 0x1b5610: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b5610u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b5614: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b5614u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b5618: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B561Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5618u;
            // 0x1b561c: 0xac640078  sw          $a0, 0x78($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 120), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B5620u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
