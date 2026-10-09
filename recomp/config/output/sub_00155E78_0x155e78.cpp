#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155E78
// Address: 0x155e78 - 0x155e8c
void sub_00155E78_0x155e78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155E78_0x155e78");
#endif

    ctx->pc = 0x155e78u;

    // 0x155e78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155e78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155e7c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155e80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155e80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155e84: 0x8041eac  j           func_107AB0
    ctx->pc = 0x155E84u;
    ctx->pc = 0x155E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155E84u;
            // 0x155e88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155E8Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
