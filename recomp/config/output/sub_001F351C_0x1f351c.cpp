#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F351C
// Address: 0x1f351c - 0x1f357c
void sub_001F351C_0x1f351c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F351C_0x1f351c");
#endif

    switch (ctx->pc) {
        case 0x1f3540u: goto label_1f3540;
        case 0x1f3550u: goto label_1f3550;
        default: break;
    }

    ctx->pc = 0x1f351cu;

    // 0x1f351c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f351cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f3520: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1f3520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1f3524: 0xffbe0018  sd          $fp, 0x18($sp)
    ctx->pc = 0x1f3524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 30));
    // 0x1f3528: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f3528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f352c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f352cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3530: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3530u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3534: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3534u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3538: 0xc07c6cd  jal         func_1F1B34
    ctx->pc = 0x1F3538u;
    SET_GPR_U32(ctx, 31, 0x1F3540u);
    ctx->pc = 0x1F1B34u;
    if (runtime->hasFunction(0x1F1B34u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3540u; }
        if (ctx->pc != 0x1F3540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B34_0x1f1b34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3540u; }
        if (ctx->pc != 0x1F3540u) { return; }
    }
    ctx->pc = 0x1F3540u;
label_1f3540:
    // 0x1f3540: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1f3540u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3544: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3544u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3548: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F3548u;
    SET_GPR_U32(ctx, 31, 0x1F3550u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3550u; }
        if (ctx->pc != 0x1F3550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3550u; }
        if (ctx->pc != 0x1F3550u) { return; }
    }
    ctx->pc = 0x1F3550u;
label_1f3550:
    // 0x1f3550: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f3550u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3554: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1f3554u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3558: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1f3558u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f355c: 0x2442ffd4  addiu       $v0, $v0, -0x2C
    ctx->pc = 0x1f355cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967252));
    // 0x1f3560: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3560u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3564: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1f3564u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3568: 0xdfbe0018  ld          $fp, 0x18($sp)
    ctx->pc = 0x1f3568u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f356c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f356cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f3570: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f3570u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f3574: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3540u: goto label_1f3540;
            case 0x1F3550u: goto label_1f3550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F357Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
