#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E818
// Address: 0x15e818 - 0x15e860
void sub_0015E818_0x15e818(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E818_0x15e818");
#endif

    switch (ctx->pc) {
        case 0x15e834u: goto label_15e834;
        case 0x15e844u: goto label_15e844;
        default: break;
    }

    ctx->pc = 0x15e818u;

    // 0x15e818: 0x3c050016  lui         $a1, 0x16
    ctx->pc = 0x15e818u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22 << 16));
    // 0x15e81c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e81cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e820: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15e820u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e824: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x15e824u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15e828: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15e828u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15e82c: 0xc058d56  jal         func_163558
    ctx->pc = 0x15E82Cu;
    SET_GPR_U32(ctx, 31, 0x15E834u);
    ctx->pc = 0x15E830u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E82Cu;
            // 0x15e830: 0x24a53d58  addiu       $a1, $a1, 0x3D58 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163558u;
    if (runtime->hasFunction(0x163558u)) {
        auto targetFn = runtime->lookupFunction(0x163558u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E834u; }
        if (ctx->pc != 0x15E834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163558_0x163558(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E834u; }
        if (ctx->pc != 0x15E834u) { return; }
    }
    ctx->pc = 0x15E834u;
label_15e834:
    // 0x15e834: 0x3c040016  lui         $a0, 0x16
    ctx->pc = 0x15e834u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)22 << 16));
    // 0x15e838: 0x24843da0  addiu       $a0, $a0, 0x3DA0
    ctx->pc = 0x15e838u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15776));
    // 0x15e83c: 0xc058d82  jal         func_163608
    ctx->pc = 0x15E83Cu;
    SET_GPR_U32(ctx, 31, 0x15E844u);
    ctx->pc = 0x15E840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E83Cu;
            // 0x15e840: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163608u;
    if (runtime->hasFunction(0x163608u)) {
        auto targetFn = runtime->lookupFunction(0x163608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E844u; }
        if (ctx->pc != 0x15E844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163608_0x163608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E844u; }
        if (ctx->pc != 0x15E844u) { return; }
    }
    ctx->pc = 0x15E844u;
label_15e844:
    // 0x15e844: 0x3c040016  lui         $a0, 0x16
    ctx->pc = 0x15e844u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)22 << 16));
    // 0x15e848: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15e848u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e84c: 0x24843e20  addiu       $a0, $a0, 0x3E20
    ctx->pc = 0x15e84cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15904));
    // 0x15e850: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15e850u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e854: 0x8058d6e  j           func_1635B8
    ctx->pc = 0x15E854u;
    ctx->pc = 0x15E858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E854u;
            // 0x15e858: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1635B8u;
    if (runtime->hasFunction(0x1635B8u)) {
        auto targetFn = runtime->lookupFunction(0x1635B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001635B8_0x1635b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15E85Cu;
    // 0x15e85c: 0x0  nop
    ctx->pc = 0x15e85cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
