#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160AE8
// Address: 0x160ae8 - 0x160b00
void sub_00160AE8_0x160ae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160AE8_0x160ae8");
#endif

    ctx->pc = 0x160ae8u;

    // 0x160ae8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160ae8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160aec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160aecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160af0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x160af0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x160af4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160af4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160af8: 0x805a7fc  j           func_169FF0
    ctx->pc = 0x160AF8u;
    ctx->pc = 0x160AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160AF8u;
            // 0x160afc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169FF0u;
    if (runtime->hasFunction(0x169FF0u)) {
        auto targetFn = runtime->lookupFunction(0x169FF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169FF0_0x169ff0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160B00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
