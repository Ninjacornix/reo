#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4650
// Address: 0x1b4650 - 0x1b46e0
void sub_001B4650_0x1b4650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4650_0x1b4650");
#endif

    switch (ctx->pc) {
        case 0x1b4680u: goto label_1b4680;
        case 0x1b46a0u: goto label_1b46a0;
        default: break;
    }

    ctx->pc = 0x1b4650u;

    // 0x1b4650: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b4650u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b4654: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b4654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b4658: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b4658u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b465c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b465cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b4660: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b4660u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4664: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b4664u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4668: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b4668u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b466c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b466cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4670: 0x3c110031  lui         $s1, 0x31
    ctx->pc = 0x1b4670u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49 << 16));
    // 0x1b4674: 0x263151d0  addiu       $s1, $s1, 0x51D0
    ctx->pc = 0x1b4674u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20944));
    // 0x1b4678: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1B4678u;
    {
        const bool branch_taken_0x1b4678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B467Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4678u;
            // 0x1b467c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4678) {
            ctx->pc = 0x1B46B8u;
            goto label_1b46b8;
        }
    }
    ctx->pc = 0x1B4680u;
label_1b4680:
    // 0x1b4680: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1b4680u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b4684: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B4684u;
    {
        const bool branch_taken_0x1b4684 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4684) {
            ctx->pc = 0x1B46B0u;
            goto label_1b46b0;
        }
    }
    ctx->pc = 0x1B468Cu;
    // 0x1b468c: 0x86220004  lh          $v0, 0x4($s1)
    ctx->pc = 0x1b468cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1b4690: 0x14530007  bne         $v0, $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B4690u;
    {
        const bool branch_taken_0x1b4690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        ctx->pc = 0x1B4694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4690u;
            // 0x1b4694: 0x2624000c  addiu       $a0, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4690) {
            ctx->pc = 0x1B46B0u;
            goto label_1b46b0;
        }
    }
    ctx->pc = 0x1B4698u;
    // 0x1b4698: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1B4698u;
    SET_GPR_U32(ctx, 31, 0x1B46A0u);
    ctx->pc = 0x1B469Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4698u;
            // 0x1b469c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B46A0u; }
        if (ctx->pc != 0x1B46A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B46A0u; }
        if (ctx->pc != 0x1B46A0u) { return; }
    }
    ctx->pc = 0x1B46A0u;
label_1b46a0:
    // 0x1b46a0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B46A0u;
    {
        const bool branch_taken_0x1b46a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b46a0) {
            ctx->pc = 0x1B46B0u;
            goto label_1b46b0;
        }
    }
    ctx->pc = 0x1B46A8u;
    // 0x1b46a8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B46A8u;
    {
        const bool branch_taken_0x1b46a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B46ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B46A8u;
            // 0x1b46ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b46a8) {
            ctx->pc = 0x1B46C4u;
            goto label_1b46c4;
        }
    }
    ctx->pc = 0x1B46B0u;
label_1b46b0:
    // 0x1b46b0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b46b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b46b4: 0x2631008c  addiu       $s1, $s1, 0x8C
    ctx->pc = 0x1b46b4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
label_1b46b8:
    // 0x1b46b8: 0x2a020020  slti        $v0, $s0, 0x20
    ctx->pc = 0x1b46b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b46bc: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1B46BCu;
    {
        const bool branch_taken_0x1b46bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B46C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B46BCu;
            // 0x1b46c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b46bc) {
            ctx->pc = 0x1B4680u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b4680;
        }
    }
    ctx->pc = 0x1B46C4u;
label_1b46c4:
    // 0x1b46c4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b46c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b46c8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b46c8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b46cc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b46ccu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b46d0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b46d0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b46d4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b46d4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b46d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B46D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B46DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B46D8u;
            // 0x1b46dc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4680u: goto label_1b4680;
            case 0x1B46A0u: goto label_1b46a0;
            case 0x1B46B0u: goto label_1b46b0;
            case 0x1B46B8u: goto label_1b46b8;
            case 0x1B46C4u: goto label_1b46c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B46E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
