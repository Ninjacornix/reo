#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B250
// Address: 0x13b250 - 0x13b264
void sub_0013B250_0x13b250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B250_0x13b250");
#endif

    ctx->pc = 0x13b250u;

    // 0x13b250: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b250u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b254: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13b254u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13b258: 0xac44da7c  sw          $a0, -0x2584($v0)
    ctx->pc = 0x13b258u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294957692), GPR_U32(ctx, 4));
    // 0x13b25c: 0x3e00008  jr          $ra
    ctx->pc = 0x13B25Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B25Cu;
            // 0x13b260: 0xac65da80  sw          $a1, -0x2580($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294957696), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13B264u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
