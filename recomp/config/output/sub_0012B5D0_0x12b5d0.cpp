#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B5D0
// Address: 0x12b5d0 - 0x12b610
void sub_0012B5D0_0x12b5d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B5D0_0x12b5d0");
#endif

    switch (ctx->pc) {
        case 0x12b5e0u: goto label_12b5e0;
        case 0x12b5e8u: goto label_12b5e8;
        case 0x12b5f0u: goto label_12b5f0;
        case 0x12b5f8u: goto label_12b5f8;
        case 0x12b600u: goto label_12b600;
        default: break;
    }

    ctx->pc = 0x12b5d0u;

    // 0x12b5d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12b5d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12b5d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12b5d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12b5d8: 0xc0507ea  jal         func_141FA8
    ctx->pc = 0x12B5D8u;
    SET_GPR_U32(ctx, 31, 0x12B5E0u);
    ctx->pc = 0x141FA8u;
    if (runtime->hasFunction(0x141FA8u)) {
        auto targetFn = runtime->lookupFunction(0x141FA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5E0u; }
        if (ctx->pc != 0x12B5E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141FA8_0x141fa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5E0u; }
        if (ctx->pc != 0x12B5E0u) { return; }
    }
    ctx->pc = 0x12B5E0u;
label_12b5e0:
    // 0x12b5e0: 0xc0507f0  jal         func_141FC0
    ctx->pc = 0x12B5E0u;
    SET_GPR_U32(ctx, 31, 0x12B5E8u);
    ctx->pc = 0x141FC0u;
    if (runtime->hasFunction(0x141FC0u)) {
        auto targetFn = runtime->lookupFunction(0x141FC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5E8u; }
        if (ctx->pc != 0x12B5E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141FC0_0x141fc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5E8u; }
        if (ctx->pc != 0x12B5E8u) { return; }
    }
    ctx->pc = 0x12B5E8u;
label_12b5e8:
    // 0x12b5e8: 0xc050802  jal         func_142008
    ctx->pc = 0x12B5E8u;
    SET_GPR_U32(ctx, 31, 0x12B5F0u);
    ctx->pc = 0x142008u;
    if (runtime->hasFunction(0x142008u)) {
        auto targetFn = runtime->lookupFunction(0x142008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5F0u; }
        if (ctx->pc != 0x12B5F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142008_0x142008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5F0u; }
        if (ctx->pc != 0x12B5F0u) { return; }
    }
    ctx->pc = 0x12B5F0u;
label_12b5f0:
    // 0x12b5f0: 0xc050808  jal         func_142020
    ctx->pc = 0x12B5F0u;
    SET_GPR_U32(ctx, 31, 0x12B5F8u);
    ctx->pc = 0x142020u;
    if (runtime->hasFunction(0x142020u)) {
        auto targetFn = runtime->lookupFunction(0x142020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5F8u; }
        if (ctx->pc != 0x12B5F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142020_0x142020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B5F8u; }
        if (ctx->pc != 0x12B5F8u) { return; }
    }
    ctx->pc = 0x12B5F8u;
label_12b5f8:
    // 0x12b5f8: 0xc05080e  jal         func_142038
    ctx->pc = 0x12B5F8u;
    SET_GPR_U32(ctx, 31, 0x12B600u);
    ctx->pc = 0x142038u;
    if (runtime->hasFunction(0x142038u)) {
        auto targetFn = runtime->lookupFunction(0x142038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B600u; }
        if (ctx->pc != 0x12B600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142038_0x142038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B600u; }
        if (ctx->pc != 0x12B600u) { return; }
    }
    ctx->pc = 0x12B600u;
label_12b600:
    // 0x12b600: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b600u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b604: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12b604u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b608: 0x3e00008  jr          $ra
    ctx->pc = 0x12B608u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B608u;
            // 0x12b60c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B5E0u: goto label_12b5e0;
            case 0x12B5E8u: goto label_12b5e8;
            case 0x12B5F0u: goto label_12b5f0;
            case 0x12B5F8u: goto label_12b5f8;
            case 0x12B600u: goto label_12b600;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B610u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
