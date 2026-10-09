#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FFA0
// Address: 0x15ffa0 - 0x15ffc0
void sub_0015FFA0_0x15ffa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FFA0_0x15ffa0");
#endif

    ctx->pc = 0x15ffa0u;

    // 0x15ffa0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ffa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ffa4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x15ffa4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ffa8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ffa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ffac: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x15ffacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x15ffb0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15ffb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15ffb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ffb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ffb8: 0x805d4ce  j           func_175338
    ctx->pc = 0x15FFB8u;
    ctx->pc = 0x15FFBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FFB8u;
            // 0x15ffbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FFC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
