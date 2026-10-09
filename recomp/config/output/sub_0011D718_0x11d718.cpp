#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D718
// Address: 0x11d718 - 0x11d724
void sub_0011D718_0x11d718(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D718_0x11d718");
#endif

    ctx->pc = 0x11d718u;

    // 0x11d718: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11d718u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11d71c: 0x3e00008  jr          $ra
    ctx->pc = 0x11D71Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D71Cu;
            // 0x11d720: 0x8c62a474  lw          $v0, -0x5B8C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294943860)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D724u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
