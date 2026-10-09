#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166630
// Address: 0x166630 - 0x166684
void sub_00166630_0x166630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166630_0x166630");
#endif

    switch (ctx->pc) {
        case 0x166650u: goto label_166650;
        case 0x166670u: goto label_166670;
        default: break;
    }

    ctx->pc = 0x166630u;

    // 0x166630: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x166634: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166638: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x166638u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16663c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16663cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x166640: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166644: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x166644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x166648: 0xc05d58a  jal         func_175628
    ctx->pc = 0x166648u;
    SET_GPR_U32(ctx, 31, 0x166650u);
    ctx->pc = 0x16664Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166648u;
            // 0x16664c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166650u; }
        if (ctx->pc != 0x166650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166650u; }
        if (ctx->pc != 0x166650u) { return; }
    }
    ctx->pc = 0x166650u;
label_166650:
    // 0x166650: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166654: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x166654u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166658: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x166658u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16665c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x16665cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x166660: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x166660u;
    {
        const bool branch_taken_0x166660 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166660u;
            // 0x166664: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166660) {
            ctx->pc = 0x166670u;
            goto label_166670;
        }
    }
    ctx->pc = 0x166668u;
    // 0x166668: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x166668u;
    SET_GPR_U32(ctx, 31, 0x166670u);
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166670u; }
        if (ctx->pc != 0x166670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166670u; }
        if (ctx->pc != 0x166670u) { return; }
    }
    ctx->pc = 0x166670u;
label_166670:
    // 0x166670: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166670u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166674: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166674u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166678: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16667c: 0x3e00008  jr          $ra
    ctx->pc = 0x16667Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16667Cu;
            // 0x166680: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166684u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
