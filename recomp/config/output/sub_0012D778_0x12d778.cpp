#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D778
// Address: 0x12d778 - 0x12d790
void sub_0012D778_0x12d778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D778_0x12d778");
#endif

    ctx->pc = 0x12d778u;

    // 0x12d778: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d778u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d77c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d77cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d780: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d780u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d784: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d784u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d788: 0x804939a  j           func_124E68
    ctx->pc = 0x12D788u;
    ctx->pc = 0x12D78Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D788u;
            // 0x12d78c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E68u;
    if (runtime->hasFunction(0x124E68u)) {
        auto targetFn = runtime->lookupFunction(0x124E68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124E68_0x124e68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D790u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
