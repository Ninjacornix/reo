#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001645A8
// Address: 0x1645a8 - 0x1645bc
void sub_001645A8_0x1645a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001645A8_0x1645a8");
#endif

    ctx->pc = 0x1645a8u;

    // 0x1645a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1645a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1645ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1645acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1645b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1645b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1645b4: 0x804c3f8  j           func_130FE0
    ctx->pc = 0x1645B4u;
    ctx->pc = 0x1645B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1645B4u;
            // 0x1645b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE0u;
    {
        auto targetFn = runtime->lookupFunction(0x130FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1645BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
