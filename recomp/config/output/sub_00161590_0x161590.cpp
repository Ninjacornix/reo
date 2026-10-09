#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161590
// Address: 0x161590 - 0x1615a4
void sub_00161590_0x161590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161590_0x161590");
#endif

    ctx->pc = 0x161590u;

    // 0x161590: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161594: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x161594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161598: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161598u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16159c: 0x805855e  j           func_161578
    ctx->pc = 0x16159Cu;
    ctx->pc = 0x1615A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16159Cu;
            // 0x1615a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161578u;
    if (runtime->hasFunction(0x161578u)) {
        auto targetFn = runtime->lookupFunction(0x161578u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00161578_0x161578(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1615A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
