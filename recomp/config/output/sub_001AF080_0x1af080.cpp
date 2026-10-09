#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF080
// Address: 0x1af080 - 0x1af0c0
void sub_001AF080_0x1af080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF080_0x1af080");
#endif

    switch (ctx->pc) {
        case 0x1af0a0u: goto label_1af0a0;
        default: break;
    }

    ctx->pc = 0x1af080u;

    // 0x1af080: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1af080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1af084: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af084u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af088: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1af088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1af08c: 0x8c234190  lw          $v1, 0x4190($at)
    ctx->pc = 0x1af08cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16784)));
    // 0x1af090: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AF090u;
    {
        const bool branch_taken_0x1af090 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af090) {
            ctx->pc = 0x1AF0B4u;
            goto label_1af0b4;
        }
    }
    ctx->pc = 0x1AF098u;
    // 0x1af098: 0xc06578c  jal         func_195E30
    ctx->pc = 0x1AF098u;
    SET_GPR_U32(ctx, 31, 0x1AF0A0u);
    ctx->pc = 0x195E30u;
    if (runtime->hasFunction(0x195E30u)) {
        auto targetFn = runtime->lookupFunction(0x195E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF0A0u; }
        if (ctx->pc != 0x1AF0A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00195E30_0x195e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF0A0u; }
        if (ctx->pc != 0x1AF0A0u) { return; }
    }
    ctx->pc = 0x1AF0A0u;
label_1af0a0:
    // 0x1af0a0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af0a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af0a4: 0x8c234190  lw          $v1, 0x4190($at)
    ctx->pc = 0x1af0a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16784)));
    // 0x1af0a8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1af0a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1af0ac: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af0acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af0b0: 0xac234190  sw          $v1, 0x4190($at)
    ctx->pc = 0x1af0b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16784), GPR_U32(ctx, 3));
label_1af0b4:
    // 0x1af0b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1af0b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af0b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF0B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF0BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF0B8u;
            // 0x1af0bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF0A0u: goto label_1af0a0;
            case 0x1AF0B4u: goto label_1af0b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF0C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
