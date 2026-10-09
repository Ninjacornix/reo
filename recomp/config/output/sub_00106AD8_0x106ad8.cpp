#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106AD8
// Address: 0x106ad8 - 0x106af8
void sub_00106AD8_0x106ad8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106AD8_0x106ad8");
#endif

    ctx->pc = 0x106ad8u;

    // 0x106ad8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x106ad8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x106adc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x106adcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106ae0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x106ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x106ae4: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x106ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106ae8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x106ae8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106aec: 0x8041aa8  j           func_106AA0
    ctx->pc = 0x106AECu;
    ctx->pc = 0x106AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106AECu;
            // 0x106af0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106AA0u;
    if (runtime->hasFunction(0x106AA0u)) {
        auto targetFn = runtime->lookupFunction(0x106AA0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00106AA0_0x106aa0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x106AF4u;
    // 0x106af4: 0x0  nop
    ctx->pc = 0x106af4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
