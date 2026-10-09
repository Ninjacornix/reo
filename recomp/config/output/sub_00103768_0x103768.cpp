#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103768
// Address: 0x103768 - 0x103780
void sub_00103768_0x103768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103768_0x103768");
#endif

    ctx->pc = 0x103768u;

    // 0x103768: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x103768u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10376c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10376cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103770: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x103770u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x103774: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x103774u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103778: 0x80431ea  j           func_10C7A8
    ctx->pc = 0x103778u;
    ctx->pc = 0x10377Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103778u;
            // 0x10377c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10C7A8u;
    if (runtime->hasFunction(0x10C7A8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010C7A8_0x10c7a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x103780u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
