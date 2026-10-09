#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141730
// Address: 0x141730 - 0x141748
void sub_00141730_0x141730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141730_0x141730");
#endif

    ctx->pc = 0x141730u;

    // 0x141730: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x141734: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x141734u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x141738: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x141738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14173c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14173cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141740: 0x8050578  j           func_1415E0
    ctx->pc = 0x141740u;
    ctx->pc = 0x141744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141740u;
            // 0x141744: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1415E0u;
    if (runtime->hasFunction(0x1415E0u)) {
        auto targetFn = runtime->lookupFunction(0x1415E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001415E0_0x1415e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141748u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
