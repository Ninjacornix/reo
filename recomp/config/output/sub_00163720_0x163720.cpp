#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163720
// Address: 0x163720 - 0x163738
void sub_00163720_0x163720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163720_0x163720");
#endif

    ctx->pc = 0x163720u;

    // 0x163720: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163724: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163728: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163728u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16372c: 0x80505f0  j           func_1417C0
    ctx->pc = 0x16372Cu;
    ctx->pc = 0x163730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16372Cu;
            // 0x163730: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1417C0u;
    if (runtime->hasFunction(0x1417C0u)) {
        auto targetFn = runtime->lookupFunction(0x1417C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001417C0_0x1417c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163734u;
    // 0x163734: 0x0  nop
    ctx->pc = 0x163734u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
