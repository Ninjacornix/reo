#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF040
// Address: 0x1af040 - 0x1af080
void sub_001AF040_0x1af040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF040_0x1af040");
#endif

    switch (ctx->pc) {
        case 0x1af060u: goto label_1af060;
        default: break;
    }

    ctx->pc = 0x1af040u;

    // 0x1af040: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1af040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1af044: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af044u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af048: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1af048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1af04c: 0x8c234190  lw          $v1, 0x4190($at)
    ctx->pc = 0x1af04cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16784)));
    // 0x1af050: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AF050u;
    {
        const bool branch_taken_0x1af050 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1af050) {
            ctx->pc = 0x1AF074u;
            goto label_1af074;
        }
    }
    ctx->pc = 0x1AF058u;
    // 0x1af058: 0xc065788  jal         func_195E20
    ctx->pc = 0x1AF058u;
    SET_GPR_U32(ctx, 31, 0x1AF060u);
    ctx->pc = 0x195E20u;
    if (runtime->hasFunction(0x195E20u)) {
        auto targetFn = runtime->lookupFunction(0x195E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF060u; }
        if (ctx->pc != 0x1AF060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00195E20_0x195e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF060u; }
        if (ctx->pc != 0x1AF060u) { return; }
    }
    ctx->pc = 0x1AF060u;
label_1af060:
    // 0x1af060: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af060u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af064: 0x8c234190  lw          $v1, 0x4190($at)
    ctx->pc = 0x1af064u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16784)));
    // 0x1af068: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1af068u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1af06c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af06cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af070: 0xac234190  sw          $v1, 0x4190($at)
    ctx->pc = 0x1af070u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16784), GPR_U32(ctx, 3));
label_1af074:
    // 0x1af074: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1af074u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af078: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF078u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF07Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF078u;
            // 0x1af07c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF060u: goto label_1af060;
            case 0x1AF074u: goto label_1af074;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF080u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
