#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D238
// Address: 0x17d238 - 0x17d244
void sub_0017D238_0x17d238(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D238_0x17d238");
#endif

    ctx->pc = 0x17d238u;

    // 0x17d238: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17d238u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17d23c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D23Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D23Cu;
            // 0x17d240: 0x8c62f29c  lw          $v0, -0xD64($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963868)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D244u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
