#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162138
// Address: 0x162138 - 0x162150
void sub_00162138_0x162138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162138_0x162138");
#endif

    ctx->pc = 0x162138u;

    // 0x162138: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16213c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16213cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162140: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x162140u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x162144: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162144u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162148: 0x805f520  j           func_17D480
    ctx->pc = 0x162148u;
    ctx->pc = 0x16214Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162148u;
            // 0x16214c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D480u;
    if (runtime->hasFunction(0x17D480u)) {
        auto targetFn = runtime->lookupFunction(0x17D480u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D480_0x17d480(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162150u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
