#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A80C0
// Address: 0x1a80c0 - 0x1a8100
void sub_001A80C0_0x1a80c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A80C0_0x1a80c0");
#endif

    switch (ctx->pc) {
        case 0x1a80d0u: goto label_1a80d0;
        case 0x1a80e8u: goto label_1a80e8;
        default: break;
    }

    ctx->pc = 0x1a80c0u;

    // 0x1a80c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a80c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a80c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a80c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a80c8: 0xc069fec  jal         func_1A7FB0
    ctx->pc = 0x1A80C8u;
    SET_GPR_U32(ctx, 31, 0x1A80D0u);
    ctx->pc = 0x1A7FB0u;
    if (runtime->hasFunction(0x1A7FB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A7FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A80D0u; }
        if (ctx->pc != 0x1A80D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7FB0_0x1a7fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A80D0u; }
        if (ctx->pc != 0x1A80D0u) { return; }
    }
    ctx->pc = 0x1A80D0u;
label_1a80d0:
    // 0x1a80d0: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A80D0u;
    {
        const bool branch_taken_0x1a80d0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A80D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A80D0u;
            // 0x1a80d4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a80d0) {
            ctx->pc = 0x1A80E0u;
            goto label_1a80e0;
        }
    }
    ctx->pc = 0x1A80D8u;
    // 0x1a80d8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A80D8u;
    {
        const bool branch_taken_0x1a80d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A80DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A80D8u;
            // 0x1a80dc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a80d8) {
            ctx->pc = 0x1A80ECu;
            goto label_1a80ec;
        }
    }
    ctx->pc = 0x1A80E0u;
label_1a80e0:
    // 0x1a80e0: 0xc06a018  jal         func_1A8060
    ctx->pc = 0x1A80E0u;
    SET_GPR_U32(ctx, 31, 0x1A80E8u);
    ctx->pc = 0x1A8060u;
    if (runtime->hasFunction(0x1A8060u)) {
        auto targetFn = runtime->lookupFunction(0x1A8060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A80E8u; }
        if (ctx->pc != 0x1A80E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8060_0x1a8060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A80E8u; }
        if (ctx->pc != 0x1A80E8u) { return; }
    }
    ctx->pc = 0x1A80E8u;
label_1a80e8:
    // 0x1a80e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a80e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a80ec:
    // 0x1a80ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1A80ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A80F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A80ECu;
            // 0x1a80f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A80D0u: goto label_1a80d0;
            case 0x1A80E0u: goto label_1a80e0;
            case 0x1A80E8u: goto label_1a80e8;
            case 0x1A80ECu: goto label_1a80ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A80F4u;
    // 0x1a80f4: 0x0  nop
    ctx->pc = 0x1a80f4u;
    // NOP
    // 0x1a80f8: 0x0  nop
    ctx->pc = 0x1a80f8u;
    // NOP
    // 0x1a80fc: 0x0  nop
    ctx->pc = 0x1a80fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
