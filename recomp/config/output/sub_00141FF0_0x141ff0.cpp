#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141FF0
// Address: 0x141ff0 - 0x142008
void sub_00141FF0_0x141ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141FF0_0x141ff0");
#endif

    ctx->pc = 0x141ff0u;

    // 0x141ff0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x141ff4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x141ff4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x141ff8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x141ff8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x141ffc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x141ffcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142000: 0x8050788  j           func_141E20
    ctx->pc = 0x142000u;
    ctx->pc = 0x142004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142000u;
            // 0x142004: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E20u;
    if (runtime->hasFunction(0x141E20u)) {
        auto targetFn = runtime->lookupFunction(0x141E20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141E20_0x141e20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x142008u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
