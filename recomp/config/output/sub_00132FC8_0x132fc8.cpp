#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132FC8
// Address: 0x132fc8 - 0x132fdc
void sub_00132FC8_0x132fc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132FC8_0x132fc8");
#endif

    ctx->pc = 0x132fc8u;

    // 0x132fc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132fc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132fcc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132fd0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132fd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132fd4: 0x804b23c  j           func_12C8F0
    ctx->pc = 0x132FD4u;
    ctx->pc = 0x132FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132FD4u;
            // 0x132fd8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C8F0u;
    if (runtime->hasFunction(0x12C8F0u)) {
        auto targetFn = runtime->lookupFunction(0x12C8F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012C8F0_0x12c8f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132FDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
