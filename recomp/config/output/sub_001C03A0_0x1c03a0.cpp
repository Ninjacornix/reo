#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C03A0
// Address: 0x1c03a0 - 0x1c03f0
void sub_001C03A0_0x1c03a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C03A0_0x1c03a0");
#endif

    switch (ctx->pc) {
        case 0x1c03b0u: goto label_1c03b0;
        case 0x1c03d8u: goto label_1c03d8;
        case 0x1c03e0u: goto label_1c03e0;
        default: break;
    }

    ctx->pc = 0x1c03a0u;

    // 0x1c03a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c03a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c03a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c03a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c03a8: 0xc06ade4  jal         func_1AB790
    ctx->pc = 0x1C03A8u;
    SET_GPR_U32(ctx, 31, 0x1C03B0u);
    ctx->pc = 0x1AB790u;
    if (runtime->hasFunction(0x1AB790u)) {
        auto targetFn = runtime->lookupFunction(0x1AB790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C03B0u; }
        if (ctx->pc != 0x1C03B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB790_0x1ab790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C03B0u; }
        if (ctx->pc != 0x1C03B0u) { return; }
    }
    ctx->pc = 0x1C03B0u;
label_1c03b0:
    // 0x1c03b0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c03b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c03b4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c03b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c03b8: 0x8c236ce8  lw          $v1, 0x6CE8($at)
    ctx->pc = 0x1c03b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27880)));
    // 0x1c03bc: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c03bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c03c0: 0x24425170  addiu       $v0, $v0, 0x5170
    ctx->pc = 0x1c03c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20848));
    // 0x1c03c4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c03c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c03c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c03c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c03cc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c03ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c03d0: 0x40f809  jalr        $v0
    ctx->pc = 0x1C03D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1C03D8u);
        ctx->pc = 0x1C03D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C03D0u;
            // 0x1c03d4: 0x24846c50  addiu       $a0, $a0, 0x6C50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27728));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1C03D8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C03B0u: goto label_1c03b0;
            case 0x1C03D8u: goto label_1c03d8;
            case 0x1C03E0u: goto label_1c03e0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1C03D8u; }
            if (ctx->pc != 0x1C03D8u) { return; }
        }
        }
    }
    ctx->pc = 0x1C03D8u;
label_1c03d8:
    // 0x1c03d8: 0xc06adfc  jal         func_1AB7F0
    ctx->pc = 0x1C03D8u;
    SET_GPR_U32(ctx, 31, 0x1C03E0u);
    ctx->pc = 0x1AB7F0u;
    if (runtime->hasFunction(0x1AB7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C03E0u; }
        if (ctx->pc != 0x1C03E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C03E0u; }
        if (ctx->pc != 0x1C03E0u) { return; }
    }
    ctx->pc = 0x1C03E0u;
label_1c03e0:
    // 0x1c03e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c03e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c03e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C03E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C03E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C03E4u;
            // 0x1c03e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C03B0u: goto label_1c03b0;
            case 0x1C03D8u: goto label_1c03d8;
            case 0x1C03E0u: goto label_1c03e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C03ECu;
    // 0x1c03ec: 0x0  nop
    ctx->pc = 0x1c03ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
