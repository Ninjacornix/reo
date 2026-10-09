#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EB88
// Address: 0x13eb88 - 0x13eba4
void sub_0013EB88_0x13eb88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EB88_0x13eb88");
#endif

    ctx->pc = 0x13eb88u;

    // 0x13eb88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13eb88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13eb8c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13eb8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13eb90: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13eb90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13eb94: 0x2484d828  addiu       $a0, $a0, -0x27D8
    ctx->pc = 0x13eb94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957096));
    // 0x13eb98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13eb98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13eb9c: 0x8045a12  j           func_116848
    ctx->pc = 0x13EB9Cu;
    ctx->pc = 0x13EBA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB9Cu;
            // 0x13eba0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EBA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
