#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130520
// Address: 0x130520 - 0x130560
void sub_00130520_0x130520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130520_0x130520");
#endif

    switch (ctx->pc) {
        case 0x130534u: goto label_130534;
        case 0x13053cu: goto label_13053c;
        default: break;
    }

    ctx->pc = 0x130520u;

    // 0x130520: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130524: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130528: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13052c: 0xc04c1b8  jal         func_1306E0
    ctx->pc = 0x13052Cu;
    SET_GPR_U32(ctx, 31, 0x130534u);
    ctx->pc = 0x130530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13052Cu;
            // 0x130530: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1306E0u;
    if (runtime->hasFunction(0x1306E0u)) {
        auto targetFn = runtime->lookupFunction(0x1306E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130534u; }
        if (ctx->pc != 0x130534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001306E0_0x1306e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130534u; }
        if (ctx->pc != 0x130534u) { return; }
    }
    ctx->pc = 0x130534u;
label_130534:
    // 0x130534: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x130534u;
    SET_GPR_U32(ctx, 31, 0x13053Cu);
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13053Cu; }
        if (ctx->pc != 0x13053Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13053Cu; }
        if (ctx->pc != 0x13053Cu) { return; }
    }
    ctx->pc = 0x13053Cu;
label_13053c:
    // 0x13053c: 0x82030045  lb          $v1, 0x45($s0)
    ctx->pc = 0x13053cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x130540: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130544: 0x50620001  beql        $v1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x130544u;
    {
        const bool branch_taken_0x130544 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x130544) {
            ctx->pc = 0x130548u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130544u;
            // 0x130548: 0xa2030042  sb          $v1, 0x42($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13054Cu;
            goto label_13054c;
        }
    }
    ctx->pc = 0x13054Cu;
label_13054c:
    // 0x13054c: 0xa2000041  sb          $zero, 0x41($s0)
    ctx->pc = 0x13054cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 65), (uint8_t)GPR_U32(ctx, 0));
    // 0x130550: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130554: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130554u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130558: 0x80505ba  j           func_1416E8
    ctx->pc = 0x130558u;
    ctx->pc = 0x13055Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130558u;
            // 0x13055c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x130560u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
