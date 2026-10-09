#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B06A0
// Address: 0x1b06a0 - 0x1b06f0
void sub_001B06A0_0x1b06a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B06A0_0x1b06a0");
#endif

    switch (ctx->pc) {
        case 0x1b06c0u: goto label_1b06c0;
        case 0x1b06d8u: goto label_1b06d8;
        case 0x1b06e0u: goto label_1b06e0;
        default: break;
    }

    ctx->pc = 0x1b06a0u;

    // 0x1b06a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b06a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b06a4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b06a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b06a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b06a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b06ac: 0x8c238df8  lw          $v1, -0x7208($at)
    ctx->pc = 0x1b06acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938104)));
    // 0x1b06b0: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1B06B0u;
    {
        const bool branch_taken_0x1b06b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B06B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B06B0u;
            // 0x1b06b4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b06b0) {
            ctx->pc = 0x1B06E0u;
            goto label_1b06e0;
        }
    }
    ctx->pc = 0x1B06B8u;
    // 0x1b06b8: 0xc067db0  jal         func_19F6C0
    ctx->pc = 0x1B06B8u;
    SET_GPR_U32(ctx, 31, 0x1B06C0u);
    ctx->pc = 0x19F6C0u;
    if (runtime->hasFunction(0x19F6C0u)) {
        auto targetFn = runtime->lookupFunction(0x19F6C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B06C0u; }
        if (ctx->pc != 0x1B06C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F6C0_0x19f6c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B06C0u; }
        if (ctx->pc != 0x1B06C0u) { return; }
    }
    ctx->pc = 0x1B06C0u;
label_1b06c0:
    // 0x1b06c0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b06c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b06c4: 0x8c228e00  lw          $v0, -0x7200($at)
    ctx->pc = 0x1b06c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938112)));
    // 0x1b06c8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B06C8u;
    {
        const bool branch_taken_0x1b06c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b06c8) {
            ctx->pc = 0x1B06D8u;
            goto label_1b06d8;
        }
    }
    ctx->pc = 0x1B06D0u;
    // 0x1b06d0: 0xc06c16c  jal         func_1B05B0
    ctx->pc = 0x1B06D0u;
    SET_GPR_U32(ctx, 31, 0x1B06D8u);
    ctx->pc = 0x1B05B0u;
    if (runtime->hasFunction(0x1B05B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B05B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B06D8u; }
        if (ctx->pc != 0x1B06D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B05B0_0x1b05b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B06D8u; }
        if (ctx->pc != 0x1B06D8u) { return; }
    }
    ctx->pc = 0x1B06D8u;
label_1b06d8:
    // 0x1b06d8: 0xc073018  jal         func_1CC060
    ctx->pc = 0x1B06D8u;
    SET_GPR_U32(ctx, 31, 0x1B06E0u);
    ctx->pc = 0x1CC060u;
    if (runtime->hasFunction(0x1CC060u)) {
        auto targetFn = runtime->lookupFunction(0x1CC060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B06E0u; }
        if (ctx->pc != 0x1B06E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC060_0x1cc060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B06E0u; }
        if (ctx->pc != 0x1B06E0u) { return; }
    }
    ctx->pc = 0x1B06E0u;
label_1b06e0:
    // 0x1b06e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b06e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b06e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B06E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B06E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B06E4u;
            // 0x1b06e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B06C0u: goto label_1b06c0;
            case 0x1B06D8u: goto label_1b06d8;
            case 0x1B06E0u: goto label_1b06e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B06ECu;
    // 0x1b06ec: 0x0  nop
    ctx->pc = 0x1b06ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
