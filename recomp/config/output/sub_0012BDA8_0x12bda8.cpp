#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BDA8
// Address: 0x12bda8 - 0x12bdb4
void sub_0012BDA8_0x12bda8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BDA8_0x12bda8");
#endif

    ctx->pc = 0x12bda8u;

    // 0x12bda8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12bda8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12bdac: 0x3e00008  jr          $ra
    ctx->pc = 0x12BDACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12BDB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BDACu;
            // 0x12bdb0: 0x8c620480  lw          $v0, 0x480($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1152)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12BDB4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
