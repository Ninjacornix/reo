#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FF88
// Address: 0x15ff88 - 0x15ffa0
void sub_0015FF88_0x15ff88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FF88_0x15ff88");
#endif

    ctx->pc = 0x15ff88u;

    // 0x15ff88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ff88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ff8c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ff8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ff90: 0x8c840044  lw          $a0, 0x44($a0)
    ctx->pc = 0x15ff90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15ff94: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ff94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff98: 0x8059112  j           func_164448
    ctx->pc = 0x15FF98u;
    ctx->pc = 0x15FF9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF98u;
            // 0x15ff9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164448u;
    {
        auto targetFn = runtime->lookupFunction(0x164448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x15FFA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
