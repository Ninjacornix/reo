#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FEE0
// Address: 0x15fee0 - 0x15ff04
void sub_0015FEE0_0x15fee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FEE0_0x15fee0");
#endif

    ctx->pc = 0x15fee0u;

    // 0x15fee0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fee4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15fee4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fee8: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x15FEE8u;
    {
        const bool branch_taken_0x15fee8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FEE8u;
            // 0x15feec: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fee8) {
            ctx->pc = 0x15FEF4u;
            goto label_15fef4;
        }
    }
    ctx->pc = 0x15FEF0u;
    // 0x15fef0: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x15fef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
label_15fef4:
    // 0x15fef4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15fef4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fef8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15fef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fefc: 0x805d562  j           func_175588
    ctx->pc = 0x15FEFCu;
    ctx->pc = 0x15FF00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FEFCu;
            // 0x15ff00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175588u;
    if (runtime->hasFunction(0x175588u)) {
        auto targetFn = runtime->lookupFunction(0x175588u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175588_0x175588(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
