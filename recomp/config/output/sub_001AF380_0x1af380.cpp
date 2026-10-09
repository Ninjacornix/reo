#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF380
// Address: 0x1af380 - 0x1af3bc
void sub_001AF380_0x1af380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF380_0x1af380");
#endif

    switch (ctx->pc) {
        case 0x1af390u: goto label_1af390;
        case 0x1af398u: goto label_1af398;
        case 0x1af3a0u: goto label_1af3a0;
        case 0x1af3a8u: goto label_1af3a8;
        case 0x1af3b0u: goto label_1af3b0;
        default: break;
    }

    ctx->pc = 0x1af380u;

    // 0x1af380: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1af380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1af384: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1af384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1af388: 0xc07326c  jal         func_1CC9B0
    ctx->pc = 0x1AF388u;
    SET_GPR_U32(ctx, 31, 0x1AF390u);
    ctx->pc = 0x1CC9B0u;
    if (runtime->hasFunction(0x1CC9B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC9B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF390u; }
        if (ctx->pc != 0x1AF390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC9B0_0x1cc9b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF390u; }
        if (ctx->pc != 0x1AF390u) { return; }
    }
    ctx->pc = 0x1AF390u;
label_1af390:
    // 0x1af390: 0xc06c63c  jal         func_1B18F0
    ctx->pc = 0x1AF390u;
    SET_GPR_U32(ctx, 31, 0x1AF398u);
    ctx->pc = 0x1B18F0u;
    if (runtime->hasFunction(0x1B18F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B18F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF398u; }
        if (ctx->pc != 0x1AF398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B18F0_0x1b18f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF398u; }
        if (ctx->pc != 0x1AF398u) { return; }
    }
    ctx->pc = 0x1AF398u;
label_1af398:
    // 0x1af398: 0xc06c838  jal         func_1B20E0
    ctx->pc = 0x1AF398u;
    SET_GPR_U32(ctx, 31, 0x1AF3A0u);
    ctx->pc = 0x1B20E0u;
    if (runtime->hasFunction(0x1B20E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B20E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3A0u; }
        if (ctx->pc != 0x1AF3A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B20E0_0x1b20e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3A0u; }
        if (ctx->pc != 0x1AF3A0u) { return; }
    }
    ctx->pc = 0x1AF3A0u;
label_1af3a0:
    // 0x1af3a0: 0xc06c65c  jal         func_1B1970
    ctx->pc = 0x1AF3A0u;
    SET_GPR_U32(ctx, 31, 0x1AF3A8u);
    ctx->pc = 0x1B1970u;
    if (runtime->hasFunction(0x1B1970u)) {
        auto targetFn = runtime->lookupFunction(0x1B1970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3A8u; }
        if (ctx->pc != 0x1AF3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1970_0x1b1970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3A8u; }
        if (ctx->pc != 0x1AF3A8u) { return; }
    }
    ctx->pc = 0x1AF3A8u;
label_1af3a8:
    // 0x1af3a8: 0xc15d6a0  jal         func_575A80
    ctx->pc = 0x1AF3A8u;
    SET_GPR_U32(ctx, 31, 0x1AF3B0u);
    ctx->pc = 0x575A80u;
    {
        auto targetFn = runtime->lookupFunction(0x575A80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3B0u; }
        if (ctx->pc != 0x1AF3B0u) { return; }
    }
    ctx->pc = 0x1AF3B0u;
label_1af3b0:
    // 0x1af3b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1af3b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af3b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF3B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF3B4u;
            // 0x1af3b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF390u: goto label_1af390;
            case 0x1AF398u: goto label_1af398;
            case 0x1AF3A0u: goto label_1af3a0;
            case 0x1AF3A8u: goto label_1af3a8;
            case 0x1AF3B0u: goto label_1af3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF3BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
