#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B20E0
// Address: 0x1b20e0 - 0x1b2120
void sub_001B20E0_0x1b20e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B20E0_0x1b20e0");
#endif

    switch (ctx->pc) {
        case 0x1b20f0u: goto label_1b20f0;
        case 0x1b20f8u: goto label_1b20f8;
        case 0x1b2100u: goto label_1b2100;
        case 0x1b2108u: goto label_1b2108;
        case 0x1b2110u: goto label_1b2110;
        default: break;
    }

    ctx->pc = 0x1b20e0u;

    // 0x1b20e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b20e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b20e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b20e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b20e8: 0xc06c758  jal         func_1B1D60
    ctx->pc = 0x1B20E8u;
    SET_GPR_U32(ctx, 31, 0x1B20F0u);
    ctx->pc = 0x1B1D60u;
    if (runtime->hasFunction(0x1B1D60u)) {
        auto targetFn = runtime->lookupFunction(0x1B1D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B20F0u; }
        if (ctx->pc != 0x1B20F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1D60_0x1b1d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B20F0u; }
        if (ctx->pc != 0x1B20F0u) { return; }
    }
    ctx->pc = 0x1B20F0u;
label_1b20f0:
    // 0x1b20f0: 0xc06c768  jal         func_1B1DA0
    ctx->pc = 0x1B20F0u;
    SET_GPR_U32(ctx, 31, 0x1B20F8u);
    ctx->pc = 0x1B1DA0u;
    if (runtime->hasFunction(0x1B1DA0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1DA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B20F8u; }
        if (ctx->pc != 0x1B20F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1DA0_0x1b1da0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B20F8u; }
        if (ctx->pc != 0x1B20F8u) { return; }
    }
    ctx->pc = 0x1B20F8u;
label_1b20f8:
    // 0x1b20f8: 0xc06c7b0  jal         func_1B1EC0
    ctx->pc = 0x1B20F8u;
    SET_GPR_U32(ctx, 31, 0x1B2100u);
    ctx->pc = 0x1B1EC0u;
    if (runtime->hasFunction(0x1B1EC0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2100u; }
        if (ctx->pc != 0x1B2100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1EC0_0x1b1ec0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2100u; }
        if (ctx->pc != 0x1B2100u) { return; }
    }
    ctx->pc = 0x1B2100u;
label_1b2100:
    // 0x1b2100: 0xc06c7c4  jal         func_1B1F10
    ctx->pc = 0x1B2100u;
    SET_GPR_U32(ctx, 31, 0x1B2108u);
    ctx->pc = 0x1B1F10u;
    if (runtime->hasFunction(0x1B1F10u)) {
        auto targetFn = runtime->lookupFunction(0x1B1F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2108u; }
        if (ctx->pc != 0x1B2108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1F10_0x1b1f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2108u; }
        if (ctx->pc != 0x1B2108u) { return; }
    }
    ctx->pc = 0x1B2108u;
label_1b2108:
    // 0x1b2108: 0xc06c808  jal         func_1B2020
    ctx->pc = 0x1B2108u;
    SET_GPR_U32(ctx, 31, 0x1B2110u);
    ctx->pc = 0x1B2020u;
    if (runtime->hasFunction(0x1B2020u)) {
        auto targetFn = runtime->lookupFunction(0x1B2020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2110u; }
        if (ctx->pc != 0x1B2110u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2020_0x1b2020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2110u; }
        if (ctx->pc != 0x1B2110u) { return; }
    }
    ctx->pc = 0x1B2110u;
label_1b2110:
    // 0x1b2110: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2114: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2114u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2114u;
            // 0x1b2118: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B20F0u: goto label_1b20f0;
            case 0x1B20F8u: goto label_1b20f8;
            case 0x1B2100u: goto label_1b2100;
            case 0x1B2108u: goto label_1b2108;
            case 0x1B2110u: goto label_1b2110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B211Cu;
    // 0x1b211c: 0x0  nop
    ctx->pc = 0x1b211cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
