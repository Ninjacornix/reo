#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010AAC0
// Address: 0x10aac0 - 0x10aadc
void sub_0010AAC0_0x10aac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010AAC0_0x10aac0");
#endif

    ctx->pc = 0x10aac0u;

    // 0x10aac0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10aac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10aac4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10aac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10aac8: 0x8485000e  lh          $a1, 0xE($a0)
    ctx->pc = 0x10aac8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x10aacc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10aaccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10aad0: 0x8c840054  lw          $a0, 0x54($a0)
    ctx->pc = 0x10aad0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 84)));
    // 0x10aad4: 0x8040e7c  j           func_1039F0
    ctx->pc = 0x10AAD4u;
    ctx->pc = 0x10AAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AAD4u;
            // 0x10aad8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1039F0u;
    if (runtime->hasFunction(0x1039F0u)) {
        auto targetFn = runtime->lookupFunction(0x1039F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001039F0_0x1039f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10AADCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
