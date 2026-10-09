#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FF58
// Address: 0x15ff58 - 0x15ff70
void sub_0015FF58_0x15ff58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FF58_0x15ff58");
#endif

    ctx->pc = 0x15ff58u;

    // 0x15ff58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ff58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ff5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ff5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ff60: 0x8c840044  lw          $a0, 0x44($a0)
    ctx->pc = 0x15ff60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15ff64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ff64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff68: 0x805915a  j           func_164568
    ctx->pc = 0x15FF68u;
    ctx->pc = 0x15FF6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF68u;
            // 0x15ff6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164568u;
    if (runtime->hasFunction(0x164568u)) {
        auto targetFn = runtime->lookupFunction(0x164568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00164568_0x164568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
