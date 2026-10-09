#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0620
// Address: 0x1b0620 - 0x1b0658
void sub_001B0620_0x1b0620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0620_0x1b0620");
#endif

    switch (ctx->pc) {
        case 0x1b064cu: goto label_1b064c;
        default: break;
    }

    ctx->pc = 0x1b0620u;

    // 0x1b0620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0624: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b0624u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0628: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b062c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b062cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0630: 0xac248df8  sw          $a0, -0x7208($at)
    ctx->pc = 0x1b0630u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938104), GPR_U32(ctx, 4));
    // 0x1b0634: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b0634u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0638: 0x8c238df0  lw          $v1, -0x7210($at)
    ctx->pc = 0x1b0638u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938096)));
    // 0x1b063c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B063Cu;
    {
        const bool branch_taken_0x1b063c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B0640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B063Cu;
            // 0x1b0640: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b063c) {
            ctx->pc = 0x1B064Cu;
            goto label_1b064c;
        }
    }
    ctx->pc = 0x1B0644u;
    // 0x1b0644: 0xc072e30  jal         func_1CB8C0
    ctx->pc = 0x1B0644u;
    SET_GPR_U32(ctx, 31, 0x1B064Cu);
    ctx->pc = 0x1B0648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0644u;
            // 0x1b0648: 0xac248df0  sw          $a0, -0x7210($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294938096), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB8C0u;
    if (runtime->hasFunction(0x1CB8C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CB8C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B064Cu; }
        if (ctx->pc != 0x1B064Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB8C0_0x1cb8c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B064Cu; }
        if (ctx->pc != 0x1B064Cu) { return; }
    }
    ctx->pc = 0x1B064Cu;
label_1b064c:
    // 0x1b064c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b064cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0650: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0650u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0650u;
            // 0x1b0654: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B064Cu: goto label_1b064c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0658u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
