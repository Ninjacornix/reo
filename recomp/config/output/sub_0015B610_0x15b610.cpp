#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B610
// Address: 0x15b610 - 0x15b690
void sub_0015B610_0x15b610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B610_0x15b610");
#endif

    switch (ctx->pc) {
        case 0x15b63cu: goto label_15b63c;
        case 0x15b668u: goto label_15b668;
        case 0x15b674u: goto label_15b674;
        default: break;
    }

    ctx->pc = 0x15b610u;

    // 0x15b610: 0x24840078  addiu       $a0, $a0, 0x78
    ctx->pc = 0x15b610u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 120));
    // 0x15b614: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x15b614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x15b618: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x15b618u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x15b61c: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x15b61cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x15b620: 0x3e00008  jr          $ra
    ctx->pc = 0x15B620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B620u;
            // 0x15b624: 0xacc30000  sw          $v1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B63Cu: goto label_15b63c;
            case 0x15B660u: goto label_15b660;
            case 0x15B668u: goto label_15b668;
            case 0x15B674u: goto label_15b674;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B628u;
    // 0x15b628: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b62c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15b62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15b630: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15b630u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15b634: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x15B634u;
    SET_GPR_U32(ctx, 31, 0x15B63Cu);
    ctx->pc = 0x15B638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B634u;
            // 0x15b638: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B63Cu; }
        if (ctx->pc != 0x15B63Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B63Cu; }
        if (ctx->pc != 0x15B63Cu) { return; }
    }
    ctx->pc = 0x15B63Cu;
label_15b63c:
    // 0x15b63c: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15b63cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x15b640: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15b640u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b644: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15B644u;
    {
        const bool branch_taken_0x15b644 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15B648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B644u;
            // 0x15b648: 0x34a50201  ori         $a1, $a1, 0x201 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)513);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b644) {
            ctx->pc = 0x15B660u;
            goto label_15b660;
        }
    }
    ctx->pc = 0x15B64Cu;
    // 0x15b64c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b64cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b650: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15b650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b654: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15b654u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b658: 0x80563ce  j           func_158F38
    ctx->pc = 0x15B658u;
    ctx->pc = 0x15B65Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B658u;
            // 0x15b65c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15B660u;
label_15b660:
    // 0x15b660: 0xc056e0e  jal         func_15B838
    ctx->pc = 0x15B660u;
    SET_GPR_U32(ctx, 31, 0x15B668u);
    ctx->pc = 0x15B838u;
    if (runtime->hasFunction(0x15B838u)) {
        auto targetFn = runtime->lookupFunction(0x15B838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B668u; }
        if (ctx->pc != 0x15B668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B838_0x15b838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B668u; }
        if (ctx->pc != 0x15B668u) { return; }
    }
    ctx->pc = 0x15B668u;
label_15b668:
    // 0x15b668: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15b668u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b66c: 0xc056da6  jal         func_15B698
    ctx->pc = 0x15B66Cu;
    SET_GPR_U32(ctx, 31, 0x15B674u);
    ctx->pc = 0x15B670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B66Cu;
            // 0x15b670: 0x240503c4  addiu       $a1, $zero, 0x3C4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 964));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B698u;
    if (runtime->hasFunction(0x15B698u)) {
        auto targetFn = runtime->lookupFunction(0x15B698u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B674u; }
        if (ctx->pc != 0x15B674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B698_0x15b698(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B674u; }
        if (ctx->pc != 0x15B674u) { return; }
    }
    ctx->pc = 0x15B674u;
label_15b674:
    // 0x15b674: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15b674u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15b678: 0xae020188  sw          $v0, 0x188($s0)
    ctx->pc = 0x15b678u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 392), GPR_U32(ctx, 2));
    // 0x15b67c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15b67cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b680: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b680u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b684: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15b684u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b688: 0x3e00008  jr          $ra
    ctx->pc = 0x15B688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B688u;
            // 0x15b68c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B63Cu: goto label_15b63c;
            case 0x15B660u: goto label_15b660;
            case 0x15B668u: goto label_15b668;
            case 0x15B674u: goto label_15b674;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B690u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
