#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AF48
// Address: 0x13af48 - 0x13af5c
void sub_0013AF48_0x13af48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AF48_0x13af48");
#endif

    ctx->pc = 0x13af48u;

    // 0x13af48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13af48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13af4c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13af4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13af50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13af50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13af54: 0x804e0b8  j           func_1382E0
    ctx->pc = 0x13AF54u;
    ctx->pc = 0x13AF58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AF54u;
            // 0x13af58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1382E0u;
    if (runtime->hasFunction(0x1382E0u)) {
        auto targetFn = runtime->lookupFunction(0x1382E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001382E0_0x1382e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13AF5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
