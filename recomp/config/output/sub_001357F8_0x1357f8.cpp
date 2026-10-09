#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001357F8
// Address: 0x1357f8 - 0x135878
void sub_001357F8_0x1357f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001357F8_0x1357f8");
#endif

    switch (ctx->pc) {
        case 0x135828u: goto label_135828;
        case 0x135838u: goto label_135838;
        default: break;
    }

    ctx->pc = 0x1357f8u;

    // 0x1357f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1357f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1357fc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1357fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135800: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x135800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x135804: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135808: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x135808u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13580c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13580cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135810: 0x2451206c  addiu       $s1, $v0, 0x206C
    ctx->pc = 0x135810u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x135814: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x135814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x135818: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x135818u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13581c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13581cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x135820: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x135820u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135824: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x135824u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_135828:
    // 0x135828: 0x26310010  addiu       $s1, $s1, 0x10
    ctx->pc = 0x135828u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x13582c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13582cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135830: 0xc042d10  jal         func_10B440
    ctx->pc = 0x135830u;
    SET_GPR_U32(ctx, 31, 0x135838u);
    ctx->pc = 0x135834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135830u;
            // 0x135834: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135838u; }
        if (ctx->pc != 0x135838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135838u; }
        if (ctx->pc != 0x135838u) { return; }
    }
    ctx->pc = 0x135838u;
label_135838:
    // 0x135838: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x135838u;
    {
        const bool branch_taken_0x135838 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13583Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135838u;
            // 0x13583c: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135838) {
            ctx->pc = 0x135848u;
            goto label_135848;
        }
    }
    ctx->pc = 0x135840u;
    // 0x135840: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x135840u;
    {
        const bool branch_taken_0x135840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135840u;
            // 0x135844: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135840) {
            ctx->pc = 0x135858u;
            goto label_135858;
        }
    }
    ctx->pc = 0x135848u;
label_135848:
    // 0x135848: 0x2a020020  slti        $v0, $s0, 0x20
    ctx->pc = 0x135848u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x13584c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x13584Cu;
    {
        const bool branch_taken_0x13584c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13584Cu;
            // 0x135850: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13584c) {
            ctx->pc = 0x135828u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135828;
        }
    }
    ctx->pc = 0x135854u;
    // 0x135854: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x135854u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_135858:
    // 0x135858: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135858u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13585c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13585cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135860: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x135860u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135864: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x135864u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x135868: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x135868u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13586c: 0x3e00008  jr          $ra
    ctx->pc = 0x13586Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13586Cu;
            // 0x135870: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135828u: goto label_135828;
            case 0x135838u: goto label_135838;
            case 0x135848u: goto label_135848;
            case 0x135858u: goto label_135858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135874u;
    // 0x135874: 0x0  nop
    ctx->pc = 0x135874u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
