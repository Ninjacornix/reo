#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001055A0
// Address: 0x1055a0 - 0x1057b8
void sub_001055A0_0x1055a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001055A0_0x1055a0");
#endif

    switch (ctx->pc) {
        case 0x105658u: goto label_105658;
        case 0x105680u: goto label_105680;
        case 0x105694u: goto label_105694;
        case 0x1056b0u: goto label_1056b0;
        case 0x105718u: goto label_105718;
        case 0x1057a8u: goto label_1057a8;
        default: break;
    }

    ctx->pc = 0x1055a0u;

label_1055a0:
    // 0x1055a0: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x1055a0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1055a4: 0x24020072  addiu       $v0, $zero, 0x72
    ctx->pc = 0x1055a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 114));
    // 0x1055a8: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1055A8u;
    {
        const bool branch_taken_0x1055a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1055ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055A8u;
            // 0x1055ac: 0x28620073  slti        $v0, $v1, 0x73 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)115) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055a8) {
            ctx->pc = 0x1055E0u;
            goto label_1055e0;
        }
    }
    ctx->pc = 0x1055B0u;
    // 0x1055b0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1055B0u;
    {
        const bool branch_taken_0x1055b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1055B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055B0u;
            // 0x1055b4: 0x24020077  addiu       $v0, $zero, 0x77 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 119));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055b0) {
            ctx->pc = 0x1055D0u;
            goto label_1055d0;
        }
    }
    ctx->pc = 0x1055B8u;
    // 0x1055b8: 0x24020061  addiu       $v0, $zero, 0x61
    ctx->pc = 0x1055b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 97));
    // 0x1055bc: 0x10620010  beq         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1055BCu;
    {
        const bool branch_taken_0x1055bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1055C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055BCu;
            // 0x1055c0: 0x24080108  addiu       $t0, $zero, 0x108 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055bc) {
            ctx->pc = 0x105600u;
            goto label_105600;
        }
    }
    ctx->pc = 0x1055C4u;
    // 0x1055c4: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1055C4u;
    {
        const bool branch_taken_0x1055c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1055C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055C4u;
            // 0x1055c8: 0x24030016  addiu       $v1, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055c4) {
            ctx->pc = 0x105610u;
            goto label_105610;
        }
    }
    ctx->pc = 0x1055CCu;
    // 0x1055cc: 0x0  nop
    ctx->pc = 0x1055ccu;
    // NOP
label_1055d0:
    // 0x1055d0: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1055D0u;
    {
        const bool branch_taken_0x1055d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1055D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055D0u;
            // 0x1055d4: 0x24080008  addiu       $t0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055d0) {
            ctx->pc = 0x1055F0u;
            goto label_1055f0;
        }
    }
    ctx->pc = 0x1055D8u;
    // 0x1055d8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1055D8u;
    {
        const bool branch_taken_0x1055d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1055DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055D8u;
            // 0x1055dc: 0x24030016  addiu       $v1, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055d8) {
            ctx->pc = 0x105610u;
            goto label_105610;
        }
    }
    ctx->pc = 0x1055E0u;
label_1055e0:
    // 0x1055e0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x1055e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1055e4: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1055e4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1055e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1055E8u;
    {
        const bool branch_taken_0x1055e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1055ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055E8u;
            // 0x1055ec: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055e8) {
            ctx->pc = 0x105620u;
            goto label_105620;
        }
    }
    ctx->pc = 0x1055F0u;
label_1055f0:
    // 0x1055f0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1055f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1055f4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1055F4u;
    {
        const bool branch_taken_0x1055f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1055F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1055F4u;
            // 0x1055f8: 0x24070600  addiu       $a3, $zero, 0x600 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1055f4) {
            ctx->pc = 0x105620u;
            goto label_105620;
        }
    }
    ctx->pc = 0x1055FCu;
    // 0x1055fc: 0x0  nop
    ctx->pc = 0x1055fcu;
    // NOP
label_105600:
    // 0x105600: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x105600u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x105604: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x105604u;
    {
        const bool branch_taken_0x105604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105604u;
            // 0x105608: 0x24070208  addiu       $a3, $zero, 0x208 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105604) {
            ctx->pc = 0x105620u;
            goto label_105620;
        }
    }
    ctx->pc = 0x10560Cu;
    // 0x10560c: 0x0  nop
    ctx->pc = 0x10560cu;
    // NOP
label_105610:
    // 0x105610: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x105610u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105614: 0x3e00008  jr          $ra
    ctx->pc = 0x105614u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105614u;
            // 0x105618: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1055A0u: goto label_1055a0;
            case 0x1055D0u: goto label_1055d0;
            case 0x1055E0u: goto label_1055e0;
            case 0x1055F0u: goto label_1055f0;
            case 0x105600u: goto label_105600;
            case 0x105610u: goto label_105610;
            case 0x105620u: goto label_105620;
            case 0x105644u: goto label_105644;
            case 0x105648u: goto label_105648;
            case 0x10564Cu: goto label_10564c;
            case 0x105658u: goto label_105658;
            case 0x105680u: goto label_105680;
            case 0x105694u: goto label_105694;
            case 0x1056B0u: goto label_1056b0;
            case 0x1056E8u: goto label_1056e8;
            case 0x105718u: goto label_105718;
            case 0x10571Cu: goto label_10571c;
            case 0x1057A8u: goto label_1057a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10561Cu;
    // 0x10561c: 0x0  nop
    ctx->pc = 0x10561cu;
    // NOP
label_105620:
    // 0x105620: 0x80a20001  lb          $v0, 0x1($a1)
    ctx->pc = 0x105620u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x105624: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x105624u;
    {
        const bool branch_taken_0x105624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105624u;
            // 0x105628: 0x2404002b  addiu       $a0, $zero, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105624) {
            ctx->pc = 0x105648u;
            goto label_105648;
        }
    }
    ctx->pc = 0x10562Cu;
    // 0x10562c: 0x50440005  beql        $v0, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10562Cu;
    {
        const bool branch_taken_0x10562c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x10562c) {
            ctx->pc = 0x105630u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10562Cu;
            // 0x105630: 0x24080010  addiu       $t0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105644u;
            goto label_105644;
        }
    }
    ctx->pc = 0x105634u;
    // 0x105634: 0x80a20002  lb          $v0, 0x2($a1)
    ctx->pc = 0x105634u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x105638: 0x14440004  bne         $v0, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x105638u;
    {
        const bool branch_taken_0x105638 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x10563Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105638u;
            // 0x10563c: 0x671825  or          $v1, $v1, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105638) {
            ctx->pc = 0x10564Cu;
            goto label_10564c;
        }
    }
    ctx->pc = 0x105640u;
    // 0x105640: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x105640u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_105644:
    // 0x105644: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x105644u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_105648:
    // 0x105648: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x105648u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
label_10564c:
    // 0x10564c: 0x100102d  daddu       $v0, $t0, $zero
    ctx->pc = 0x10564cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105650: 0x3e00008  jr          $ra
    ctx->pc = 0x105650u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105650u;
            // 0x105654: 0xacc30000  sw          $v1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1055A0u: goto label_1055a0;
            case 0x1055D0u: goto label_1055d0;
            case 0x1055E0u: goto label_1055e0;
            case 0x1055F0u: goto label_1055f0;
            case 0x105600u: goto label_105600;
            case 0x105610u: goto label_105610;
            case 0x105620u: goto label_105620;
            case 0x105644u: goto label_105644;
            case 0x105648u: goto label_105648;
            case 0x10564Cu: goto label_10564c;
            case 0x105658u: goto label_105658;
            case 0x105680u: goto label_105680;
            case 0x105694u: goto label_105694;
            case 0x1056B0u: goto label_1056b0;
            case 0x1056E8u: goto label_1056e8;
            case 0x105718u: goto label_105718;
            case 0x10571Cu: goto label_10571c;
            case 0x1057A8u: goto label_1057a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x105658u;
label_105658:
    // 0x105658: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x105658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x10565c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x10565cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x105660: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x105660u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105664: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x105664u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105668: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x105668u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10566c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x10566cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x105670: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x105670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x105674: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x105674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x105678: 0xc041568  jal         func_1055A0
    ctx->pc = 0x105678u;
    SET_GPR_U32(ctx, 31, 0x105680u);
    ctx->pc = 0x10567Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105678u;
            // 0x10567c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1055A0u;
    goto label_1055a0;
    ctx->pc = 0x105680u;
label_105680:
    // 0x105680: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x105680u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105684: 0x12200025  beqz        $s1, . + 4 + (0x25 << 2)
    ctx->pc = 0x105684u;
    {
        const bool branch_taken_0x105684 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x105688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105684u;
            // 0x105688: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105684) {
            ctx->pc = 0x10571Cu;
            goto label_10571c;
        }
    }
    ctx->pc = 0x10568Cu;
    // 0x10568c: 0xc0414f6  jal         func_1053D8
    ctx->pc = 0x10568Cu;
    SET_GPR_U32(ctx, 31, 0x105694u);
    ctx->pc = 0x1053D8u;
    if (runtime->hasFunction(0x1053D8u)) {
        auto targetFn = runtime->lookupFunction(0x1053D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105694u; }
        if (ctx->pc != 0x105694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001053D8_0x1053d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105694u; }
        if (ctx->pc != 0x105694u) { return; }
    }
    ctx->pc = 0x105694u;
label_105694:
    // 0x105694: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x105694u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105698: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x105698u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10569c: 0x1200001f  beqz        $s0, . + 4 + (0x1F << 2)
    ctx->pc = 0x10569Cu;
    {
        const bool branch_taken_0x10569c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1056A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10569Cu;
            // 0x1056a0: 0x240701b6  addiu       $a3, $zero, 0x1B6 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 438));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10569c) {
            ctx->pc = 0x10571Cu;
            goto label_10571c;
        }
    }
    ctx->pc = 0x1056A4u;
    // 0x1056a4: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x1056a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x1056a8: 0xc042384  jal         func_108E10
    ctx->pc = 0x1056A8u;
    SET_GPR_U32(ctx, 31, 0x1056B0u);
    ctx->pc = 0x1056ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1056A8u;
            // 0x1056ac: 0x8fa60000  lw          $a2, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108E10u;
    if (runtime->hasFunction(0x108E10u)) {
        auto targetFn = runtime->lookupFunction(0x108E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1056B0u; }
        if (ctx->pc != 0x1056B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108E10_0x108e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1056B0u; }
        if (ctx->pc != 0x1056B0u) { return; }
    }
    ctx->pc = 0x1056B0u;
label_1056b0:
    // 0x1056b0: 0x3c030011  lui         $v1, 0x11
    ctx->pc = 0x1056b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17 << 16));
    // 0x1056b4: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1056b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1056b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1056b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1056bc: 0x3c040011  lui         $a0, 0x11
    ctx->pc = 0x1056bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)17 << 16));
    // 0x1056c0: 0x3c050011  lui         $a1, 0x11
    ctx->pc = 0x1056c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
    // 0x1056c4: 0x3c060011  lui         $a2, 0x11
    ctx->pc = 0x1056c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)17 << 16));
    // 0x1056c8: 0x2463a970  addiu       $v1, $v1, -0x5690
    ctx->pc = 0x1056c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294945136));
    // 0x1056cc: 0x2484a9d8  addiu       $a0, $a0, -0x5628
    ctx->pc = 0x1056ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294945240));
    // 0x1056d0: 0x24a5aa58  addiu       $a1, $a1, -0x55A8
    ctx->pc = 0x1056d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945368));
    // 0x1056d4: 0x24c6aac0  addiu       $a2, $a2, -0x5540
    ctx->pc = 0x1056d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294945472));
    // 0x1056d8: 0x4e10003  bgez        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1056D8u;
    {
        const bool branch_taken_0x1056d8 = (GPR_S64(ctx, 7) >= 0);
        ctx->pc = 0x1056DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1056D8u;
            // 0x1056dc: 0x32280100  andi        $t0, $s1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1056d8) {
            ctx->pc = 0x1056E8u;
            goto label_1056e8;
        }
    }
    ctx->pc = 0x1056E0u;
    // 0x1056e0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1056E0u;
    {
        const bool branch_taken_0x1056e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1056E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1056E0u;
            // 0x1056e4: 0xa600000c  sh          $zero, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1056e0) {
            ctx->pc = 0x10571Cu;
            goto label_10571c;
        }
    }
    ctx->pc = 0x1056E8u;
label_1056e8:
    // 0x1056e8: 0xa607000e  sh          $a3, 0xE($s0)
    ctx->pc = 0x1056e8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 7));
    // 0x1056ec: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1056ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1056f0: 0xae040024  sw          $a0, 0x24($s0)
    ctx->pc = 0x1056f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 4));
    // 0x1056f4: 0xae050028  sw          $a1, 0x28($s0)
    ctx->pc = 0x1056f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 5));
    // 0x1056f8: 0xae06002c  sw          $a2, 0x2C($s0)
    ctx->pc = 0x1056f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 6));
    // 0x1056fc: 0xa611000c  sh          $s1, 0xC($s0)
    ctx->pc = 0x1056fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 17));
    // 0x105700: 0x11000005  beqz        $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x105700u;
    {
        const bool branch_taken_0x105700 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x105704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105700u;
            // 0x105704: 0xae10001c  sw          $s0, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105700) {
            ctx->pc = 0x105718u;
            goto label_105718;
        }
    }
    ctx->pc = 0x105708u;
    // 0x105708: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x105708u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10570c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10570cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105710: 0xc041750  jal         func_105D40
    ctx->pc = 0x105710u;
    SET_GPR_U32(ctx, 31, 0x105718u);
    ctx->pc = 0x105714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105710u;
            // 0x105714: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105D40u;
    if (runtime->hasFunction(0x105D40u)) {
        auto targetFn = runtime->lookupFunction(0x105D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105718u; }
        if (ctx->pc != 0x105718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105D40_0x105d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105718u; }
        if (ctx->pc != 0x105718u) { return; }
    }
    ctx->pc = 0x105718u;
label_105718:
    // 0x105718: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x105718u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_10571c:
    // 0x10571c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x10571cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x105720: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x105720u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x105724: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x105724u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x105728: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x105728u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10572c: 0x3e00008  jr          $ra
    ctx->pc = 0x10572Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10572Cu;
            // 0x105730: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1055A0u: goto label_1055a0;
            case 0x1055D0u: goto label_1055d0;
            case 0x1055E0u: goto label_1055e0;
            case 0x1055F0u: goto label_1055f0;
            case 0x105600u: goto label_105600;
            case 0x105610u: goto label_105610;
            case 0x105620u: goto label_105620;
            case 0x105644u: goto label_105644;
            case 0x105648u: goto label_105648;
            case 0x10564Cu: goto label_10564c;
            case 0x105658u: goto label_105658;
            case 0x105680u: goto label_105680;
            case 0x105694u: goto label_105694;
            case 0x1056B0u: goto label_1056b0;
            case 0x1056E8u: goto label_1056e8;
            case 0x105718u: goto label_105718;
            case 0x10571Cu: goto label_10571c;
            case 0x1057A8u: goto label_1057a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x105734u;
    // 0x105734: 0x0  nop
    ctx->pc = 0x105734u;
    // NOP
    // 0x105738: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x105738u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10573c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10573cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x105740: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x105740u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x105744: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x105744u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105748: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x105748u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10574c: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10574cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x105750: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x105750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x105754: 0x8041596  j           func_105658
    ctx->pc = 0x105754u;
    ctx->pc = 0x105758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105754u;
            // 0x105758: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105658u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_105658;
    ctx->pc = 0x10575Cu;
    // 0x10575c: 0x0  nop
    ctx->pc = 0x10575cu;
    // NOP
    // 0x105760: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x105760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x105764: 0xffa60030  sd          $a2, 0x30($sp)
    ctx->pc = 0x105764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 6));
    // 0x105768: 0x27a60030  addiu       $a2, $sp, 0x30
    ctx->pc = 0x105768u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x10576c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10576cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x105770: 0xffa70038  sd          $a3, 0x38($sp)
    ctx->pc = 0x105770u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 7));
    // 0x105774: 0xffa80040  sd          $t0, 0x40($sp)
    ctx->pc = 0x105774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 8));
    // 0x105778: 0xffa90048  sd          $t1, 0x48($sp)
    ctx->pc = 0x105778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 9));
    // 0x10577c: 0xffaa0050  sd          $t2, 0x50($sp)
    ctx->pc = 0x10577cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 10));
    // 0x105780: 0xffab0058  sd          $t3, 0x58($sp)
    ctx->pc = 0x105780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 11));
    // 0x105784: 0xe7ac0010  swc1        $f12, 0x10($sp)
    ctx->pc = 0x105784u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x105788: 0xe7ad0014  swc1        $f13, 0x14($sp)
    ctx->pc = 0x105788u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 20), bits); }
    // 0x10578c: 0xe7ae0018  swc1        $f14, 0x18($sp)
    ctx->pc = 0x10578cu;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x105790: 0xe7af001c  swc1        $f15, 0x1C($sp)
    ctx->pc = 0x105790u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 28), bits); }
    // 0x105794: 0xe7b00020  swc1        $f16, 0x20($sp)
    ctx->pc = 0x105794u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x105798: 0xe7b10024  swc1        $f17, 0x24($sp)
    ctx->pc = 0x105798u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 36), bits); }
    // 0x10579c: 0xe7b20028  swc1        $f18, 0x28($sp)
    ctx->pc = 0x10579cu;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x1057a0: 0xc04345a  jal         func_10D168
    ctx->pc = 0x1057A0u;
    SET_GPR_U32(ctx, 31, 0x1057A8u);
    ctx->pc = 0x1057A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1057A0u;
            // 0x1057a4: 0xe7b3002c  swc1        $f19, 0x2C($sp) (Delay Slot)
        { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D168u;
    if (runtime->hasFunction(0x10D168u)) {
        auto targetFn = runtime->lookupFunction(0x10D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1057A8u; }
        if (ctx->pc != 0x1057A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D168_0x10d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1057A8u; }
        if (ctx->pc != 0x1057A8u) { return; }
    }
    ctx->pc = 0x1057A8u;
label_1057a8:
    // 0x1057a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1057a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1057ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1057ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1057B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1057ACu;
            // 0x1057b0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1055A0u: goto label_1055a0;
            case 0x1055D0u: goto label_1055d0;
            case 0x1055E0u: goto label_1055e0;
            case 0x1055F0u: goto label_1055f0;
            case 0x105600u: goto label_105600;
            case 0x105610u: goto label_105610;
            case 0x105620u: goto label_105620;
            case 0x105644u: goto label_105644;
            case 0x105648u: goto label_105648;
            case 0x10564Cu: goto label_10564c;
            case 0x105658u: goto label_105658;
            case 0x105680u: goto label_105680;
            case 0x105694u: goto label_105694;
            case 0x1056B0u: goto label_1056b0;
            case 0x1056E8u: goto label_1056e8;
            case 0x105718u: goto label_105718;
            case 0x10571Cu: goto label_10571c;
            case 0x1057A8u: goto label_1057a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1057B4u;
    // 0x1057b4: 0x0  nop
    ctx->pc = 0x1057b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
