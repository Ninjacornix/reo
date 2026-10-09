#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137848
// Address: 0x137848 - 0x137864
void sub_00137848_0x137848(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137848_0x137848");
#endif

    ctx->pc = 0x137848u;

    // 0x137848: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137848u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13784c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13784cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x137850: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x137850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x137854: 0x2484bb88  addiu       $a0, $a0, -0x4478
    ctx->pc = 0x137854u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949768));
    // 0x137858: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x137858u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13785c: 0x804ddce  j           func_137738
    ctx->pc = 0x13785Cu;
    ctx->pc = 0x137860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13785Cu;
            // 0x137860: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137738u;
    if (runtime->hasFunction(0x137738u)) {
        auto targetFn = runtime->lookupFunction(0x137738u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00137738_0x137738(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x137864u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
