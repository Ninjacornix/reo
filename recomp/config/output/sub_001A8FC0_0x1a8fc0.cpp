#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A8FC0
// Address: 0x1a8fc0 - 0x1a8ffc
void sub_001A8FC0_0x1a8fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A8FC0_0x1a8fc0");
#endif

    switch (ctx->pc) {
        case 0x1a8fe0u: goto label_1a8fe0;
        case 0x1a8ff0u: goto label_1a8ff0;
        default: break;
    }

    ctx->pc = 0x1a8fc0u;

    // 0x1a8fc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a8fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a8fc4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8fc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8fc8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a8fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a8fcc: 0x8c220ec8  lw          $v0, 0xEC8($at)
    ctx->pc = 0x1a8fccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 3784)));
    // 0x1a8fd0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A8FD0u;
    {
        const bool branch_taken_0x1a8fd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a8fd0) {
            ctx->pc = 0x1A8FE8u;
            goto label_1a8fe8;
        }
    }
    ctx->pc = 0x1A8FD8u;
    // 0x1a8fd8: 0xc06a318  jal         func_1A8C60
    ctx->pc = 0x1A8FD8u;
    SET_GPR_U32(ctx, 31, 0x1A8FE0u);
    ctx->pc = 0x1A8C60u;
    if (runtime->hasFunction(0x1A8C60u)) {
        auto targetFn = runtime->lookupFunction(0x1A8C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8FE0u; }
        if (ctx->pc != 0x1A8FE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8C60_0x1a8c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8FE0u; }
        if (ctx->pc != 0x1A8FE0u) { return; }
    }
    ctx->pc = 0x1A8FE0u;
label_1a8fe0:
    // 0x1a8fe0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A8FE0u;
    {
        const bool branch_taken_0x1a8fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8FE0u;
            // 0x1a8fe4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8fe0) {
            ctx->pc = 0x1A8FF4u;
            goto label_1a8ff4;
        }
    }
    ctx->pc = 0x1A8FE8u;
label_1a8fe8:
    // 0x1a8fe8: 0xc06a328  jal         func_1A8CA0
    ctx->pc = 0x1A8FE8u;
    SET_GPR_U32(ctx, 31, 0x1A8FF0u);
    ctx->pc = 0x1A8CA0u;
    if (runtime->hasFunction(0x1A8CA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A8CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8FF0u; }
        if (ctx->pc != 0x1A8FF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8CA0_0x1a8ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8FF0u; }
        if (ctx->pc != 0x1A8FF0u) { return; }
    }
    ctx->pc = 0x1A8FF0u;
label_1a8ff0:
    // 0x1a8ff0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a8ff0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a8ff4:
    // 0x1a8ff4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A8FF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8FF4u;
            // 0x1a8ff8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A8FE0u: goto label_1a8fe0;
            case 0x1A8FE8u: goto label_1a8fe8;
            case 0x1A8FF0u: goto label_1a8ff0;
            case 0x1A8FF4u: goto label_1a8ff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A8FFCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
