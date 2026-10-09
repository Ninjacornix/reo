#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BAB60
// Address: 0x1bab60 - 0x1babc0
void sub_001BAB60_0x1bab60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BAB60_0x1bab60");
#endif

    switch (ctx->pc) {
        case 0x1bab80u: goto label_1bab80;
        case 0x1bab88u: goto label_1bab88;
        case 0x1bab90u: goto label_1bab90;
        case 0x1bab98u: goto label_1bab98;
        case 0x1baba0u: goto label_1baba0;
        case 0x1baba8u: goto label_1baba8;
        default: break;
    }

    ctx->pc = 0x1bab60u;

    // 0x1bab60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bab60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bab64: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bab64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bab68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bab68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bab6c: 0x8c236598  lw          $v1, 0x6598($at)
    ctx->pc = 0x1bab6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26008)));
    // 0x1bab70: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1BAB70u;
    {
        const bool branch_taken_0x1bab70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bab70) {
            ctx->pc = 0x1BABA8u;
            goto label_1baba8;
        }
    }
    ctx->pc = 0x1BAB78u;
    // 0x1bab78: 0xc06b92c  jal         func_1AE4B0
    ctx->pc = 0x1BAB78u;
    SET_GPR_U32(ctx, 31, 0x1BAB80u);
    ctx->pc = 0x1AE4B0u;
    if (runtime->hasFunction(0x1AE4B0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE4B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB80u; }
        if (ctx->pc != 0x1BAB80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE4B0_0x1ae4b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB80u; }
        if (ctx->pc != 0x1BAB80u) { return; }
    }
    ctx->pc = 0x1BAB80u;
label_1bab80:
    // 0x1bab80: 0xc06ce18  jal         func_1B3860
    ctx->pc = 0x1BAB80u;
    SET_GPR_U32(ctx, 31, 0x1BAB88u);
    ctx->pc = 0x1B3860u;
    if (runtime->hasFunction(0x1B3860u)) {
        auto targetFn = runtime->lookupFunction(0x1B3860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB88u; }
        if (ctx->pc != 0x1BAB88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3860_0x1b3860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB88u; }
        if (ctx->pc != 0x1BAB88u) { return; }
    }
    ctx->pc = 0x1BAB88u;
label_1bab88:
    // 0x1bab88: 0xc0686d8  jal         func_1A1B60
    ctx->pc = 0x1BAB88u;
    SET_GPR_U32(ctx, 31, 0x1BAB90u);
    ctx->pc = 0x1A1B60u;
    if (runtime->hasFunction(0x1A1B60u)) {
        auto targetFn = runtime->lookupFunction(0x1A1B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB90u; }
        if (ctx->pc != 0x1BAB90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1B60_0x1a1b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB90u; }
        if (ctx->pc != 0x1BAB90u) { return; }
    }
    ctx->pc = 0x1BAB90u;
label_1bab90:
    // 0x1bab90: 0xc06ec58  jal         func_1BB160
    ctx->pc = 0x1BAB90u;
    SET_GPR_U32(ctx, 31, 0x1BAB98u);
    ctx->pc = 0x1BB160u;
    if (runtime->hasFunction(0x1BB160u)) {
        auto targetFn = runtime->lookupFunction(0x1BB160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB98u; }
        if (ctx->pc != 0x1BAB98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB160_0x1bb160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAB98u; }
        if (ctx->pc != 0x1BAB98u) { return; }
    }
    ctx->pc = 0x1BAB98u;
label_1bab98:
    // 0x1bab98: 0xc06b3e8  jal         func_1ACFA0
    ctx->pc = 0x1BAB98u;
    SET_GPR_U32(ctx, 31, 0x1BABA0u);
    ctx->pc = 0x1ACFA0u;
    if (runtime->hasFunction(0x1ACFA0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACFA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BABA0u; }
        if (ctx->pc != 0x1BABA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACFA0_0x1acfa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BABA0u; }
        if (ctx->pc != 0x1BABA0u) { return; }
    }
    ctx->pc = 0x1BABA0u;
label_1baba0:
    // 0x1baba0: 0xc07307c  jal         func_1CC1F0
    ctx->pc = 0x1BABA0u;
    SET_GPR_U32(ctx, 31, 0x1BABA8u);
    ctx->pc = 0x1CC1F0u;
    if (runtime->hasFunction(0x1CC1F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC1F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BABA8u; }
        if (ctx->pc != 0x1BABA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC1F0_0x1cc1f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BABA8u; }
        if (ctx->pc != 0x1BABA8u) { return; }
    }
    ctx->pc = 0x1BABA8u;
label_1baba8:
    // 0x1baba8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1baba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1babac: 0x3e00008  jr          $ra
    ctx->pc = 0x1BABACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BABB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BABACu;
            // 0x1babb0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BAB80u: goto label_1bab80;
            case 0x1BAB88u: goto label_1bab88;
            case 0x1BAB90u: goto label_1bab90;
            case 0x1BAB98u: goto label_1bab98;
            case 0x1BABA0u: goto label_1baba0;
            case 0x1BABA8u: goto label_1baba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BABB4u;
    // 0x1babb4: 0x0  nop
    ctx->pc = 0x1babb4u;
    // NOP
    // 0x1babb8: 0x0  nop
    ctx->pc = 0x1babb8u;
    // NOP
    // 0x1babbc: 0x0  nop
    ctx->pc = 0x1babbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
