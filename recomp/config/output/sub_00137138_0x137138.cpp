#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137138
// Address: 0x137138 - 0x1371ec
void sub_00137138_0x137138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137138_0x137138");
#endif

    switch (ctx->pc) {
        case 0x13716cu: goto label_13716c;
        case 0x13717cu: goto label_13717c;
        case 0x1371a0u: goto label_1371a0;
        case 0x1371c0u: goto label_1371c0;
        default: break;
    }

    ctx->pc = 0x137138u;

    // 0x137138: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x137138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x13713c: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x13713cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x137140: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x137140u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137144: 0xffb30278  sd          $s3, 0x278($sp)
    ctx->pc = 0x137144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 19));
    // 0x137148: 0x27b30130  addiu       $s3, $sp, 0x130
    ctx->pc = 0x137148u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x13714c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13714cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137150: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x137150u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137154: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x137154u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137158: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x137158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x13715c: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x13715cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x137160: 0xffbf0280  sd          $ra, 0x280($sp)
    ctx->pc = 0x137160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 31));
    // 0x137164: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x137164u;
    SET_GPR_U32(ctx, 31, 0x13716Cu);
    ctx->pc = 0x137168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137164u;
            // 0x137168: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13716Cu; }
        if (ctx->pc != 0x13716Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13716Cu; }
        if (ctx->pc != 0x13716Cu) { return; }
    }
    ctx->pc = 0x13716Cu;
label_13716c:
    // 0x13716c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13716cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137170: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x137170u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137174: 0xc04d622  jal         func_135888
    ctx->pc = 0x137174u;
    SET_GPR_U32(ctx, 31, 0x13717Cu);
    ctx->pc = 0x137178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137174u;
            // 0x137178: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13717Cu; }
        if (ctx->pc != 0x13717Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13717Cu; }
        if (ctx->pc != 0x13717Cu) { return; }
    }
    ctx->pc = 0x13717Cu;
label_13717c:
    // 0x13717c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13717cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137180: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x137180u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137184: 0x240500ca  addiu       $a1, $zero, 0xCA
    ctx->pc = 0x137184u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 202));
    // 0x137188: 0x8e420060  lw          $v0, 0x60($s2)
    ctx->pc = 0x137188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 96)));
    // 0x13718c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x13718cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137190: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x137190u;
    {
        const bool branch_taken_0x137190 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x137194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137190u;
            // 0x137194: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137190) {
            ctx->pc = 0x1371CCu;
            goto label_1371cc;
        }
    }
    ctx->pc = 0x137198u;
    // 0x137198: 0x40f809  jalr        $v0
    ctx->pc = 0x137198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1371A0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1371A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1371A0u; }
            if (ctx->pc != 0x1371A0u) { return; }
        }
        }
    }
    ctx->pc = 0x1371A0u;
label_1371a0:
    // 0x1371a0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1371a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371a4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1371a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371a8: 0x8e420060  lw          $v0, 0x60($s2)
    ctx->pc = 0x1371a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 96)));
    // 0x1371ac: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1371acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371b0: 0x240500cb  addiu       $a1, $zero, 0xCB
    ctx->pc = 0x1371b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 203));
    // 0x1371b4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1371b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371b8: 0x40f809  jalr        $v0
    ctx->pc = 0x1371B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1371C0u);
        ctx->pc = 0x1371BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1371B8u;
            // 0x1371bc: 0x10803c  dsll32      $s0, $s0, 0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1371C0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1371C0u; }
            if (ctx->pc != 0x1371C0u) { return; }
        }
        }
    }
    ctx->pc = 0x1371C0u;
label_1371c0:
    // 0x1371c0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1371c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1371c4: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1371c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1371c8: 0x202802d  daddu       $s0, $s0, $v0
    ctx->pc = 0x1371c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_1371cc:
    // 0x1371cc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1371ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371d0: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x1371d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x1371d4: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x1371d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x1371d8: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x1371d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x1371dc: 0xdfb30278  ld          $s3, 0x278($sp)
    ctx->pc = 0x1371dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x1371e0: 0xdfbf0280  ld          $ra, 0x280($sp)
    ctx->pc = 0x1371e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x1371e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1371E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1371E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1371E4u;
            // 0x1371e8: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1371ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
