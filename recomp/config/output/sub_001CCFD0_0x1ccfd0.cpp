#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CCFD0
// Address: 0x1ccfd0 - 0x1cd030
void sub_001CCFD0_0x1ccfd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CCFD0_0x1ccfd0");
#endif

    switch (ctx->pc) {
        case 0x1cd008u: goto label_1cd008;
        case 0x1cd020u: goto label_1cd020;
        default: break;
    }

    ctx->pc = 0x1ccfd0u;

    // 0x1ccfd0: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1ccfd0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccfd4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ccfd4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ccfd8: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1ccfd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccfdc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ccfdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ccfe0: 0x14820007  bne         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CCFE0u;
    {
        const bool branch_taken_0x1ccfe0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1CCFE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCFE0u;
            // 0x1ccfe4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ccfe0) {
            ctx->pc = 0x1CD000u;
            goto label_1cd000;
        }
    }
    ctx->pc = 0x1CCFE8u;
    // 0x1ccfe8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1ccfe8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1ccfec: 0x8c2466c8  lw          $a0, 0x66C8($at)
    ctx->pc = 0x1ccfecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26312)));
    // 0x1ccff0: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CCFF0u;
    {
        const bool branch_taken_0x1ccff0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1ccff0) {
            ctx->pc = 0x1CD000u;
            goto label_1cd000;
        }
    }
    ctx->pc = 0x1CCFF8u;
    // 0x1ccff8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1CCFF8u;
    {
        const bool branch_taken_0x1ccff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CCFFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCFF8u;
            // 0x1ccffc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ccff8) {
            ctx->pc = 0x1CD024u;
            goto label_1cd024;
        }
    }
    ctx->pc = 0x1CD000u;
label_1cd000:
    // 0x1cd000: 0xc0732cc  jal         func_1CCB30
    ctx->pc = 0x1CD000u;
    SET_GPR_U32(ctx, 31, 0x1CD008u);
    ctx->pc = 0x1CCB30u;
    if (runtime->hasFunction(0x1CCB30u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD008u; }
        if (ctx->pc != 0x1CD008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB30_0x1ccb30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD008u; }
        if (ctx->pc != 0x1CD008u) { return; }
    }
    ctx->pc = 0x1CD008u;
label_1cd008:
    // 0x1cd008: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CD008u;
    {
        const bool branch_taken_0x1cd008 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD00Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD008u;
            // 0x1cd00c: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd008) {
            ctx->pc = 0x1CD018u;
            goto label_1cd018;
        }
    }
    ctx->pc = 0x1CD010u;
    // 0x1cd010: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1CD010u;
    {
        const bool branch_taken_0x1cd010 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD010u;
            // 0x1cd014: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd010) {
            ctx->pc = 0x1CD024u;
            goto label_1cd024;
        }
    }
    ctx->pc = 0x1CD018u;
label_1cd018:
    // 0x1cd018: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1CD018u;
    SET_GPR_U32(ctx, 31, 0x1CD020u);
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD020u; }
        if (ctx->pc != 0x1CD020u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD020u; }
        if (ctx->pc != 0x1CD020u) { return; }
    }
    ctx->pc = 0x1CD020u;
label_1cd020:
    // 0x1cd020: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1cd020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1cd024:
    // 0x1cd024: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cd024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd028: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD028u;
            // 0x1cd02c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD000u: goto label_1cd000;
            case 0x1CD008u: goto label_1cd008;
            case 0x1CD018u: goto label_1cd018;
            case 0x1CD020u: goto label_1cd020;
            case 0x1CD024u: goto label_1cd024;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD030u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
