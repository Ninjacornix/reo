#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130560
// Address: 0x130560 - 0x1305b8
void sub_00130560_0x130560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130560_0x130560");
#endif

    switch (ctx->pc) {
        case 0x130574u: goto label_130574;
        case 0x13057cu: goto label_13057c;
        case 0x130588u: goto label_130588;
        case 0x130590u: goto label_130590;
        default: break;
    }

    ctx->pc = 0x130560u;

    // 0x130560: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130564: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130568: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13056c: 0xc04c1d2  jal         func_130748
    ctx->pc = 0x13056Cu;
    SET_GPR_U32(ctx, 31, 0x130574u);
    ctx->pc = 0x130570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13056Cu;
            // 0x130570: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130748u;
    if (runtime->hasFunction(0x130748u)) {
        auto targetFn = runtime->lookupFunction(0x130748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130574u; }
        if (ctx->pc != 0x130574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130748_0x130748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130574u; }
        if (ctx->pc != 0x130574u) { return; }
    }
    ctx->pc = 0x130574u;
label_130574:
    // 0x130574: 0xc04c148  jal         func_130520
    ctx->pc = 0x130574u;
    SET_GPR_U32(ctx, 31, 0x13057Cu);
    ctx->pc = 0x130578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130574u;
            // 0x130578: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130520u;
    if (runtime->hasFunction(0x130520u)) {
        auto targetFn = runtime->lookupFunction(0x130520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13057Cu; }
        if (ctx->pc != 0x13057Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130520_0x130520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13057Cu; }
        if (ctx->pc != 0x13057Cu) { return; }
    }
    ctx->pc = 0x13057Cu;
label_13057c:
    // 0x13057c: 0x82020045  lb          $v0, 0x45($s0)
    ctx->pc = 0x13057cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x130580: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x130580u;
    {
        const bool branch_taken_0x130580 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x130580) {
            ctx->pc = 0x130584u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130580u;
            // 0x130584: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1305A0u;
            goto label_1305a0;
        }
    }
    ctx->pc = 0x130588u;
label_130588:
    // 0x130588: 0xc04a808  jal         func_12A020
    ctx->pc = 0x130588u;
    SET_GPR_U32(ctx, 31, 0x130590u);
    ctx->pc = 0x12A020u;
    if (runtime->hasFunction(0x12A020u)) {
        auto targetFn = runtime->lookupFunction(0x12A020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130590u; }
        if (ctx->pc != 0x130590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130590u; }
        if (ctx->pc != 0x130590u) { return; }
    }
    ctx->pc = 0x130590u;
label_130590:
    // 0x130590: 0x82020045  lb          $v0, 0x45($s0)
    ctx->pc = 0x130590u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x130594: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x130594u;
    {
        const bool branch_taken_0x130594 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x130594) {
            ctx->pc = 0x130588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130588;
        }
    }
    ctx->pc = 0x13059Cu;
    // 0x13059c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13059cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1305a0:
    // 0x1305a0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1305a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1305a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1305A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1305A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1305A4u;
            // 0x1305a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130574u: goto label_130574;
            case 0x13057Cu: goto label_13057c;
            case 0x130588u: goto label_130588;
            case 0x130590u: goto label_130590;
            case 0x1305A0u: goto label_1305a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1305ACu;
    // 0x1305ac: 0x0  nop
    ctx->pc = 0x1305acu;
    // NOP
    // 0x1305b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1305B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1305B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1305B0u;
            // 0x1305b4: 0x80820045  lb          $v0, 0x45($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 69)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130574u: goto label_130574;
            case 0x13057Cu: goto label_13057c;
            case 0x130588u: goto label_130588;
            case 0x130590u: goto label_130590;
            case 0x1305A0u: goto label_1305a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1305B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
