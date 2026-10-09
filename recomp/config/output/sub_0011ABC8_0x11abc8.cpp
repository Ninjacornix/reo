#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011ABC8
// Address: 0x11abc8 - 0x11abe4
void sub_0011ABC8_0x11abc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011ABC8_0x11abc8");
#endif

    switch (ctx->pc) {
        case 0x11abd8u: goto label_11abd8;
        default: break;
    }

    ctx->pc = 0x11abc8u;

    // 0x11abc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11abc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11abcc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11abccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11abd0: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x11ABD0u;
    SET_GPR_U32(ctx, 31, 0x11ABD8u);
    ctx->pc = 0x11ABD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ABD0u;
            // 0x11abd4: 0x24050012  addiu       $a1, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ABD8u; }
        if (ctx->pc != 0x11ABD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ABD8u; }
        if (ctx->pc != 0x11ABD8u) { return; }
    }
    ctx->pc = 0x11ABD8u;
label_11abd8:
    // 0x11abd8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11abd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11abdc: 0x3e00008  jr          $ra
    ctx->pc = 0x11ABDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11ABE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ABDCu;
            // 0x11abe0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11ABD8u: goto label_11abd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11ABE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
