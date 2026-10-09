#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158FC0
// Address: 0x158fc0 - 0x159070
void sub_00158FC0_0x158fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158FC0_0x158fc0");
#endif

    switch (ctx->pc) {
        case 0x158ff8u: goto label_158ff8;
        case 0x159018u: goto label_159018;
        case 0x159030u: goto label_159030;
        case 0x15904cu: goto label_15904c;
        default: break;
    }

    ctx->pc = 0x158fc0u;

    // 0x158fc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x158fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x158fc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158fc8: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x158fc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158fcc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x158fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158fd0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x158fd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158fd4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x158fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x158fd8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x158fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x158fdc: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x158fdcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158fe0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x158fe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x158fe4: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x158fe4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158fe8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x158fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x158fec: 0x8e650004  lw          $a1, 0x4($s3)
    ctx->pc = 0x158fecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x158ff0: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x158FF0u;
    SET_GPR_U32(ctx, 31, 0x158FF8u);
    ctx->pc = 0x158FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158FF0u;
            // 0x158ff4: 0x8e640000  lw          $a0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158FF8u; }
        if (ctx->pc != 0x158FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158FF8u; }
        if (ctx->pc != 0x158FF8u) { return; }
    }
    ctx->pc = 0x158FF8u;
label_158ff8:
    // 0x158ff8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x158ff8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158ffc: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x158ffcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159000: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x159000u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x159004: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x159004u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159008: 0x12400011  beqz        $s2, . + 4 + (0x11 << 2)
    ctx->pc = 0x159008u;
    {
        const bool branch_taken_0x159008 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x15900Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159008u;
            // 0x15900c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159008) {
            ctx->pc = 0x159050u;
            goto label_159050;
        }
    }
    ctx->pc = 0x159010u;
    // 0x159010: 0xc05644a  jal         func_159128
    ctx->pc = 0x159010u;
    SET_GPR_U32(ctx, 31, 0x159018u);
    ctx->pc = 0x159128u;
    if (runtime->hasFunction(0x159128u)) {
        auto targetFn = runtime->lookupFunction(0x159128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159018u; }
        if (ctx->pc != 0x159018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159128_0x159128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159018u; }
        if (ctx->pc != 0x159018u) { return; }
    }
    ctx->pc = 0x159018u;
label_159018:
    // 0x159018: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x159018u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15901c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15901cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159020: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x159020u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159024: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x159024u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x159028: 0x40f809  jalr        $v0
    ctx->pc = 0x159028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x159030u);
        ctx->pc = 0x15902Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159028u;
            // 0x15902c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x159030u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158FF8u: goto label_158ff8;
            case 0x159018u: goto label_159018;
            case 0x159030u: goto label_159030;
            case 0x15904Cu: goto label_15904c;
            case 0x159050u: goto label_159050;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x159030u; }
            if (ctx->pc != 0x159030u) { return; }
        }
        }
    }
    ctx->pc = 0x159030u;
label_159030:
    // 0x159030: 0x8e630004  lw          $v1, 0x4($s3)
    ctx->pc = 0x159030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x159034: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x159034u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x159038: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x159038u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x15903c: 0xae830000  sw          $v1, 0x0($s4)
    ctx->pc = 0x15903cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 3));
    // 0x159040: 0x8ca2000c  lw          $v0, 0xC($a1)
    ctx->pc = 0x159040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x159044: 0x40f809  jalr        $v0
    ctx->pc = 0x159044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15904Cu);
        ctx->pc = 0x159048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159044u;
            // 0x159048: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15904Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158FF8u: goto label_158ff8;
            case 0x159018u: goto label_159018;
            case 0x159030u: goto label_159030;
            case 0x15904Cu: goto label_15904c;
            case 0x159050u: goto label_159050;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15904Cu; }
            if (ctx->pc != 0x15904Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15904Cu;
label_15904c:
    // 0x15904c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15904cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_159050:
    // 0x159050: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x159050u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159054: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159054u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x159058: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x159058u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15905c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15905cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159060: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x159060u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x159064: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x159064u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x159068: 0x3e00008  jr          $ra
    ctx->pc = 0x159068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15906Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159068u;
            // 0x15906c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158FF8u: goto label_158ff8;
            case 0x159018u: goto label_159018;
            case 0x159030u: goto label_159030;
            case 0x15904Cu: goto label_15904c;
            case 0x159050u: goto label_159050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x159070u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
