#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D708
// Address: 0x15d708 - 0x15d740
void sub_0015D708_0x15d708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D708_0x15d708");
#endif

    switch (ctx->pc) {
        case 0x15d71cu: goto label_15d71c;
        case 0x15d72cu: goto label_15d72c;
        default: break;
    }

    ctx->pc = 0x15d708u;

    // 0x15d708: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15d708u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15d70c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d70cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d710: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15d710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15d714: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15D714u;
    SET_GPR_U32(ctx, 31, 0x15D71Cu);
    ctx->pc = 0x15D718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D714u;
            // 0x15d718: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D71Cu; }
        if (ctx->pc != 0x15D71Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D71Cu; }
        if (ctx->pc != 0x15D71Cu) { return; }
    }
    ctx->pc = 0x15D71Cu;
label_15d71c:
    // 0x15d71c: 0x8c440030  lw          $a0, 0x30($v0)
    ctx->pc = 0x15d71cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x15d720: 0x8c43002c  lw          $v1, 0x2C($v0)
    ctx->pc = 0x15d720u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x15d724: 0x60f809  jalr        $v1
    ctx->pc = 0x15D724u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x15D72Cu);
        ctx->pc = 0x15D728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D724u;
            // 0x15d728: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15D72Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D71Cu: goto label_15d71c;
            case 0x15D72Cu: goto label_15d72c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15D72Cu; }
            if (ctx->pc != 0x15D72Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15D72Cu;
label_15d72c:
    // 0x15d72c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d72cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d730: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d730u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d734: 0x3e00008  jr          $ra
    ctx->pc = 0x15D734u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D734u;
            // 0x15d738: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D71Cu: goto label_15d71c;
            case 0x15D72Cu: goto label_15d72c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D73Cu;
    // 0x15d73c: 0x0  nop
    ctx->pc = 0x15d73cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
