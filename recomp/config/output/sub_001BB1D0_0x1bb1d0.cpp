#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB1D0
// Address: 0x1bb1d0 - 0x1bb230
void sub_001BB1D0_0x1bb1d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB1D0_0x1bb1d0");
#endif

    switch (ctx->pc) {
        case 0x1bb1e0u: goto label_1bb1e0;
        case 0x1bb1e8u: goto label_1bb1e8;
        case 0x1bb1f0u: goto label_1bb1f0;
        case 0x1bb1f8u: goto label_1bb1f8;
        case 0x1bb200u: goto label_1bb200;
        case 0x1bb208u: goto label_1bb208;
        case 0x1bb210u: goto label_1bb210;
        case 0x1bb218u: goto label_1bb218;
        default: break;
    }

    ctx->pc = 0x1bb1d0u;

    // 0x1bb1d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb1d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb1d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb1d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb1d8: 0xc06b1c8  jal         func_1AC720
    ctx->pc = 0x1BB1D8u;
    SET_GPR_U32(ctx, 31, 0x1BB1E0u);
    ctx->pc = 0x1AC720u;
    if (runtime->hasFunction(0x1AC720u)) {
        auto targetFn = runtime->lookupFunction(0x1AC720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1E0u; }
        if (ctx->pc != 0x1BB1E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC720_0x1ac720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1E0u; }
        if (ctx->pc != 0x1BB1E0u) { return; }
    }
    ctx->pc = 0x1BB1E0u;
label_1bb1e0:
    // 0x1bb1e0: 0xc06b194  jal         func_1AC650
    ctx->pc = 0x1BB1E0u;
    SET_GPR_U32(ctx, 31, 0x1BB1E8u);
    ctx->pc = 0x1AC650u;
    if (runtime->hasFunction(0x1AC650u)) {
        auto targetFn = runtime->lookupFunction(0x1AC650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1E8u; }
        if (ctx->pc != 0x1BB1E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC650_0x1ac650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1E8u; }
        if (ctx->pc != 0x1BB1E8u) { return; }
    }
    ctx->pc = 0x1BB1E8u;
label_1bb1e8:
    // 0x1bb1e8: 0xc06e1f0  jal         func_1B87C0
    ctx->pc = 0x1BB1E8u;
    SET_GPR_U32(ctx, 31, 0x1BB1F0u);
    ctx->pc = 0x1BB1ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB1E8u;
            // 0x1bb1ec: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B87C0u;
    if (runtime->hasFunction(0x1B87C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B87C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1F0u; }
        if (ctx->pc != 0x1BB1F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B87C0_0x1b87c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1F0u; }
        if (ctx->pc != 0x1BB1F0u) { return; }
    }
    ctx->pc = 0x1BB1F0u;
label_1bb1f0:
    // 0x1bb1f0: 0xc06ec8c  jal         func_1BB230
    ctx->pc = 0x1BB1F0u;
    SET_GPR_U32(ctx, 31, 0x1BB1F8u);
    ctx->pc = 0x1BB230u;
    if (runtime->hasFunction(0x1BB230u)) {
        auto targetFn = runtime->lookupFunction(0x1BB230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1F8u; }
        if (ctx->pc != 0x1BB1F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB230_0x1bb230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1F8u; }
        if (ctx->pc != 0x1BB1F8u) { return; }
    }
    ctx->pc = 0x1BB1F8u;
label_1bb1f8:
    // 0x1bb1f8: 0xc06d2a0  jal         func_1B4A80
    ctx->pc = 0x1BB1F8u;
    SET_GPR_U32(ctx, 31, 0x1BB200u);
    ctx->pc = 0x1B4A80u;
    if (runtime->hasFunction(0x1B4A80u)) {
        auto targetFn = runtime->lookupFunction(0x1B4A80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB200u; }
        if (ctx->pc != 0x1BB200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4A80_0x1b4a80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB200u; }
        if (ctx->pc != 0x1BB200u) { return; }
    }
    ctx->pc = 0x1BB200u;
label_1bb200:
    // 0x1bb200: 0xc06ce1c  jal         func_1B3870
    ctx->pc = 0x1BB200u;
    SET_GPR_U32(ctx, 31, 0x1BB208u);
    ctx->pc = 0x1BB204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB200u;
            // 0x1bb204: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3870u;
    if (runtime->hasFunction(0x1B3870u)) {
        auto targetFn = runtime->lookupFunction(0x1B3870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB208u; }
        if (ctx->pc != 0x1BB208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3870_0x1b3870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB208u; }
        if (ctx->pc != 0x1BB208u) { return; }
    }
    ctx->pc = 0x1BB208u;
label_1bb208:
    // 0x1bb208: 0xc06ce18  jal         func_1B3860
    ctx->pc = 0x1BB208u;
    SET_GPR_U32(ctx, 31, 0x1BB210u);
    ctx->pc = 0x1B3860u;
    if (runtime->hasFunction(0x1B3860u)) {
        auto targetFn = runtime->lookupFunction(0x1B3860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB210u; }
        if (ctx->pc != 0x1BB210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3860_0x1b3860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB210u; }
        if (ctx->pc != 0x1BB210u) { return; }
    }
    ctx->pc = 0x1BB210u;
label_1bb210:
    // 0x1bb210: 0xc06efdc  jal         func_1BBF70
    ctx->pc = 0x1BB210u;
    SET_GPR_U32(ctx, 31, 0x1BB218u);
    ctx->pc = 0x1BBF70u;
    if (runtime->hasFunction(0x1BBF70u)) {
        auto targetFn = runtime->lookupFunction(0x1BBF70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB218u; }
        if (ctx->pc != 0x1BB218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BBF70_0x1bbf70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB218u; }
        if (ctx->pc != 0x1BB218u) { return; }
    }
    ctx->pc = 0x1BB218u;
label_1bb218:
    // 0x1bb218: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bb218u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb21c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB21Cu;
            // 0x1bb220: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB1E0u: goto label_1bb1e0;
            case 0x1BB1E8u: goto label_1bb1e8;
            case 0x1BB1F0u: goto label_1bb1f0;
            case 0x1BB1F8u: goto label_1bb1f8;
            case 0x1BB200u: goto label_1bb200;
            case 0x1BB208u: goto label_1bb208;
            case 0x1BB210u: goto label_1bb210;
            case 0x1BB218u: goto label_1bb218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB224u;
    // 0x1bb224: 0x0  nop
    ctx->pc = 0x1bb224u;
    // NOP
    // 0x1bb228: 0x0  nop
    ctx->pc = 0x1bb228u;
    // NOP
    // 0x1bb22c: 0x0  nop
    ctx->pc = 0x1bb22cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
