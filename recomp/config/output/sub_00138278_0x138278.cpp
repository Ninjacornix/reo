#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138278
// Address: 0x138278 - 0x138284
void sub_00138278_0x138278(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138278_0x138278");
#endif

    ctx->pc = 0x138278u;

    // 0x138278: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138278u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13827c: 0x3e00008  jr          $ra
    ctx->pc = 0x13827Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13827Cu;
            // 0x138280: 0x8c62bbf8  lw          $v0, -0x4408($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294949880)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x138284u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
