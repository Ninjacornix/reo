#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141FA8
// Address: 0x141fa8 - 0x141fc0
void sub_00141FA8_0x141fa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141FA8_0x141fa8");
#endif

    ctx->pc = 0x141fa8u;

    // 0x141fa8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141fa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x141fac: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x141facu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x141fb0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x141fb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x141fb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x141fb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141fb8: 0x8050788  j           func_141E20
    ctx->pc = 0x141FB8u;
    ctx->pc = 0x141FBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141FB8u;
            // 0x141fbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E20u;
    if (runtime->hasFunction(0x141E20u)) {
        auto targetFn = runtime->lookupFunction(0x141E20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141E20_0x141e20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141FC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
