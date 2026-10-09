#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D7A8
// Address: 0x12d7a8 - 0x12d7c0
void sub_0012D7A8_0x12d7a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D7A8_0x12d7a8");
#endif

    ctx->pc = 0x12d7a8u;

    // 0x12d7a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d7a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d7ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d7acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d7b0: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d7b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d7b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d7b8: 0x804939e  j           func_124E78
    ctx->pc = 0x12D7B8u;
    ctx->pc = 0x12D7BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D7B8u;
            // 0x12d7bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E78u;
    if (runtime->hasFunction(0x124E78u)) {
        auto targetFn = runtime->lookupFunction(0x124E78u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124E78_0x124e78(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D7C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
