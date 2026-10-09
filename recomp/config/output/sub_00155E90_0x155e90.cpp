#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155E90
// Address: 0x155e90 - 0x155ea4
void sub_00155E90_0x155e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155E90_0x155e90");
#endif

    ctx->pc = 0x155e90u;

    // 0x155e90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155e94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155e98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155e9c: 0x8041eac  j           func_107AB0
    ctx->pc = 0x155E9Cu;
    ctx->pc = 0x155EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155E9Cu;
            // 0x155ea0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155EA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
