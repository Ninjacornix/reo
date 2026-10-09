#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FE88
// Address: 0x15fe88 - 0x15fea0
void sub_0015FE88_0x15fe88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FE88_0x15fe88");
#endif

    ctx->pc = 0x15fe88u;

    // 0x15fe88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fe88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fe8c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15fe8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15fe90: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15fe90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15fe94: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15fe94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fe98: 0x805d5c4  j           func_175710
    ctx->pc = 0x15FE98u;
    ctx->pc = 0x15FE9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE98u;
            // 0x15fe9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175710u;
    if (runtime->hasFunction(0x175710u)) {
        auto targetFn = runtime->lookupFunction(0x175710u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175710_0x175710(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FEA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
