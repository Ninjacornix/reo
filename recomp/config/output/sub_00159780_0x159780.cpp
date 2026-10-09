#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159780
// Address: 0x159780 - 0x159820
void sub_00159780_0x159780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159780_0x159780");
#endif

    switch (ctx->pc) {
        case 0x1597b0u: goto label_1597b0;
        case 0x1597ccu: goto label_1597cc;
        case 0x1597e4u: goto label_1597e4;
        case 0x159800u: goto label_159800;
        default: break;
    }

    ctx->pc = 0x159780u;

    // 0x159780: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x159780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x159784: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x159784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x159788: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x159788u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15978c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15978cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x159790: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x159790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x159794: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x159794u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159798: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x159798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15979c: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x15979cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1597a0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1597a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1597a4: 0x8e450004  lw          $a1, 0x4($s2)
    ctx->pc = 0x1597a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1597a8: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x1597A8u;
    SET_GPR_U32(ctx, 31, 0x1597B0u);
    ctx->pc = 0x1597ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1597A8u;
            // 0x1597ac: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1597B0u; }
        if (ctx->pc != 0x1597B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1597B0u; }
        if (ctx->pc != 0x1597B0u) { return; }
    }
    ctx->pc = 0x1597B0u;
label_1597b0:
    // 0x1597b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1597b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1597b4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1597b4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1597b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1597b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1597bc: 0x12200011  beqz        $s1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1597BCu;
    {
        const bool branch_taken_0x1597bc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1597C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1597BCu;
            // 0x1597c0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1597bc) {
            ctx->pc = 0x159804u;
            goto label_159804;
        }
    }
    ctx->pc = 0x1597C4u;
    // 0x1597c4: 0xc056548  jal         func_159520
    ctx->pc = 0x1597C4u;
    SET_GPR_U32(ctx, 31, 0x1597CCu);
    ctx->pc = 0x159520u;
    if (runtime->hasFunction(0x159520u)) {
        auto targetFn = runtime->lookupFunction(0x159520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1597CCu; }
        if (ctx->pc != 0x1597CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159520_0x159520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1597CCu; }
        if (ctx->pc != 0x1597CCu) { return; }
    }
    ctx->pc = 0x1597CCu;
label_1597cc:
    // 0x1597cc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1597ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1597d0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1597d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1597d4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1597d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1597d8: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1597d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1597dc: 0x40f809  jalr        $v0
    ctx->pc = 0x1597DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1597E4u);
        ctx->pc = 0x1597E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1597DCu;
            // 0x1597e0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1597E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1597B0u: goto label_1597b0;
            case 0x1597CCu: goto label_1597cc;
            case 0x1597E4u: goto label_1597e4;
            case 0x159800u: goto label_159800;
            case 0x159804u: goto label_159804;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1597E4u; }
            if (ctx->pc != 0x1597E4u) { return; }
        }
        }
    }
    ctx->pc = 0x1597E4u;
label_1597e4:
    // 0x1597e4: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x1597e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1597e8: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x1597e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1597ec: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1597ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1597f0: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x1597f0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1597f4: 0x8ca2000c  lw          $v0, 0xC($a1)
    ctx->pc = 0x1597f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1597f8: 0x40f809  jalr        $v0
    ctx->pc = 0x1597F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x159800u);
        ctx->pc = 0x1597FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1597F8u;
            // 0x1597fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x159800u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1597B0u: goto label_1597b0;
            case 0x1597CCu: goto label_1597cc;
            case 0x1597E4u: goto label_1597e4;
            case 0x159800u: goto label_159800;
            case 0x159804u: goto label_159804;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x159800u; }
            if (ctx->pc != 0x159800u) { return; }
        }
        }
    }
    ctx->pc = 0x159800u;
label_159800:
    // 0x159800: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x159800u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_159804:
    // 0x159804: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x159804u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159808: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159808u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15980c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15980cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x159810: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x159810u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159814: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x159814u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x159818: 0x3e00008  jr          $ra
    ctx->pc = 0x159818u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15981Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159818u;
            // 0x15981c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1597B0u: goto label_1597b0;
            case 0x1597CCu: goto label_1597cc;
            case 0x1597E4u: goto label_1597e4;
            case 0x159800u: goto label_159800;
            case 0x159804u: goto label_159804;
            default: break;
        }
        return;
    }
    ctx->pc = 0x159820u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
