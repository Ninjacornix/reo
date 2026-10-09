#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001345F0
// Address: 0x1345f0 - 0x1347f8
void sub_001345F0_0x1345f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001345F0_0x1345f0");
#endif

    switch (ctx->pc) {
        case 0x13462cu: goto label_13462c;
        case 0x13463cu: goto label_13463c;
        case 0x134644u: goto label_134644;
        case 0x134650u: goto label_134650;
        case 0x134678u: goto label_134678;
        case 0x1346b0u: goto label_1346b0;
        case 0x1346d0u: goto label_1346d0;
        case 0x1346ecu: goto label_1346ec;
        case 0x134704u: goto label_134704;
        case 0x134720u: goto label_134720;
        case 0x134740u: goto label_134740;
        case 0x134750u: goto label_134750;
        case 0x13476cu: goto label_13476c;
        case 0x134784u: goto label_134784;
        case 0x1347a4u: goto label_1347a4;
        case 0x1347b0u: goto label_1347b0;
        case 0x1347bcu: goto label_1347bc;
        default: break;
    }

    ctx->pc = 0x1345f0u;

    // 0x1345f0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1345f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1345f4: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x1345f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x1345f8: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1345f8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1345fc: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x1345fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x134600: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x134600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x134604: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x134604u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134608: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x134608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x13460c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x13460cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x134610: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x134610u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x134614: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x134614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x134618: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x134618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x13461c: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x13461cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x134620: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x134620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x134624: 0xc04b1cc  jal         func_12C730
    ctx->pc = 0x134624u;
    SET_GPR_U32(ctx, 31, 0x13462Cu);
    ctx->pc = 0x134628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134624u;
            // 0x134628: 0x8ec4000c  lw          $a0, 0xC($s6) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C730u;
    if (runtime->hasFunction(0x12C730u)) {
        auto targetFn = runtime->lookupFunction(0x12C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13462Cu; }
        if (ctx->pc != 0x13462Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C730_0x12c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13462Cu; }
        if (ctx->pc != 0x13462Cu) { return; }
    }
    ctx->pc = 0x13462Cu;
label_13462c:
    // 0x13462c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13462cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x134630: 0x0  nop
    ctx->pc = 0x134630u;
    // NOP
    // 0x134634: 0xc04b5ea  jal         func_12D7A8
    ctx->pc = 0x134634u;
    SET_GPR_U32(ctx, 31, 0x13463Cu);
    ctx->pc = 0x134638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134634u;
            // 0x134638: 0x8ec40004  lw          $a0, 0x4($s6) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7A8u;
    if (runtime->hasFunction(0x12D7A8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13463Cu; }
        if (ctx->pc != 0x13463Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7A8_0x12d7a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13463Cu; }
        if (ctx->pc != 0x13463Cu) { return; }
    }
    ctx->pc = 0x13463Cu;
label_13463c:
    // 0x13463c: 0xc049938  jal         func_1264E0
    ctx->pc = 0x13463Cu;
    SET_GPR_U32(ctx, 31, 0x134644u);
    ctx->pc = 0x134640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13463Cu;
            // 0x134640: 0x40b82d  daddu       $s7, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134644u; }
        if (ctx->pc != 0x134644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134644u; }
        if (ctx->pc != 0x134644u) { return; }
    }
    ctx->pc = 0x134644u;
label_134644:
    // 0x134644: 0x1ae00014  blez        $s7, . + 4 + (0x14 << 2)
    ctx->pc = 0x134644u;
    {
        const bool branch_taken_0x134644 = (GPR_S64(ctx, 23) <= 0);
        ctx->pc = 0x134648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134644u;
            // 0x134648: 0x8ed50048  lw          $s5, 0x48($s6) (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134644) {
            ctx->pc = 0x134698u;
            goto label_134698;
        }
    }
    ctx->pc = 0x13464Cu;
    // 0x13464c: 0x26d10018  addiu       $s1, $s6, 0x18
    ctx->pc = 0x13464cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 22), 24));
label_134650:
    // 0x134650: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x134650u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x134654: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x134654u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x134658: 0x1480c0  sll         $s0, $s4, 3
    ctx->pc = 0x134658u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x13465c: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x13465cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x134660: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x134660u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x134664: 0x153040  sll         $a2, $s5, 1
    ctx->pc = 0x134664u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 21), 1));
    // 0x134668: 0x3b03821  addu        $a3, $sp, $s0
    ctx->pc = 0x134668u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 16)));
    // 0x13466c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x13466cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x134670: 0x40f809  jalr        $v0
    ctx->pc = 0x134670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134678u);
        ctx->pc = 0x134674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134670u;
            // 0x134674: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x134678u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13462Cu: goto label_13462c;
            case 0x13463Cu: goto label_13463c;
            case 0x134644u: goto label_134644;
            case 0x134650u: goto label_134650;
            case 0x134678u: goto label_134678;
            case 0x134698u: goto label_134698;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346ECu: goto label_1346ec;
            case 0x134704u: goto label_134704;
            case 0x134720u: goto label_134720;
            case 0x13472Cu: goto label_13472c;
            case 0x134740u: goto label_134740;
            case 0x134750u: goto label_134750;
            case 0x13476Cu: goto label_13476c;
            case 0x13477Cu: goto label_13477c;
            case 0x134784u: goto label_134784;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C8u: goto label_1347c8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134678u; }
            if (ctx->pc != 0x134678u) { return; }
        }
        }
    }
    ctx->pc = 0x134678u;
label_134678:
    // 0x134678: 0x297202a  slt         $a0, $s4, $s7
    ctx->pc = 0x134678u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 23)) ? 1 : 0);
    // 0x13467c: 0x27a20004  addiu       $v0, $sp, 0x4
    ctx->pc = 0x13467cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x134680: 0x508021  addu        $s0, $v0, $s0
    ctx->pc = 0x134680u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x134684: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x134684u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x134688: 0x31842  srl         $v1, $v1, 1
    ctx->pc = 0x134688u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x13468c: 0x75102b  sltu        $v0, $v1, $s5
    ctx->pc = 0x13468cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 21)) ? 1 : 0);
    // 0x134690: 0x1480ffef  bnez        $a0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x134690u;
    {
        const bool branch_taken_0x134690 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x134694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134690u;
            // 0x134694: 0x62a80b  movn        $s5, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134690) {
            ctx->pc = 0x134650u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_134650;
        }
    }
    ctx->pc = 0x134698u;
label_134698:
    // 0x134698: 0x1ae00024  blez        $s7, . + 4 + (0x24 << 2)
    ctx->pc = 0x134698u;
    {
        const bool branch_taken_0x134698 = (GPR_S64(ctx, 23) <= 0);
        ctx->pc = 0x13469Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134698u;
            // 0x13469c: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134698) {
            ctx->pc = 0x13472Cu;
            goto label_13472c;
        }
    }
    ctx->pc = 0x1346A0u;
    // 0x1346a0: 0x15f040  sll         $fp, $s5, 1
    ctx->pc = 0x1346a0u;
    SET_GPR_S32(ctx, 30, (int32_t)SLL32(GPR_U32(ctx, 21), 1));
    // 0x1346a4: 0x26d30018  addiu       $s3, $s6, 0x18
    ctx->pc = 0x1346a4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 22), 24));
    // 0x1346a8: 0x27a20010  addiu       $v0, $sp, 0x10
    ctx->pc = 0x1346a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1346ac: 0x0  nop
    ctx->pc = 0x1346acu;
    // NOP
label_1346b0:
    // 0x1346b0: 0x1480c0  sll         $s0, $s4, 3
    ctx->pc = 0x1346b0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x1346b4: 0x3b08821  addu        $s1, $sp, $s0
    ctx->pc = 0x1346b4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 16)));
    // 0x1346b8: 0x509021  addu        $s2, $v0, $s0
    ctx->pc = 0x1346b8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1346bc: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1346bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1346c0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1346c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1346c4: 0x3c0282d  daddu       $a1, $fp, $zero
    ctx->pc = 0x1346c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1346c8: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x1346C8u;
    SET_GPR_U32(ctx, 31, 0x1346D0u);
    ctx->pc = 0x1346CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1346C8u;
            // 0x1346cc: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1346D0u; }
        if (ctx->pc != 0x1346D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1346D0u; }
        if (ctx->pc != 0x1346D0u) { return; }
    }
    ctx->pc = 0x1346D0u;
label_1346d0:
    // 0x1346d0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1346d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1346d4: 0x27a20004  addiu       $v0, $sp, 0x4
    ctx->pc = 0x1346d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x1346d8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1346d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1346dc: 0x508021  addu        $s0, $v0, $s0
    ctx->pc = 0x1346dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1346e0: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1346e0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1346e4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1346E4u;
    SET_GPR_U32(ctx, 31, 0x1346ECu);
    ctx->pc = 0x1346E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1346E4u;
            // 0x1346e8: 0x8e060000  lw          $a2, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1346ECu; }
        if (ctx->pc != 0x1346ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1346ECu; }
        if (ctx->pc != 0x1346ECu) { return; }
    }
    ctx->pc = 0x1346ECu;
label_1346ec:
    // 0x1346ec: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x1346ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1346f0: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1346f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1346f4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1346f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1346f8: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1346f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1346fc: 0x40f809  jalr        $v0
    ctx->pc = 0x1346FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134704u);
        ctx->pc = 0x134700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1346FCu;
            // 0x134700: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x134704u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13462Cu: goto label_13462c;
            case 0x13463Cu: goto label_13463c;
            case 0x134644u: goto label_134644;
            case 0x134650u: goto label_134650;
            case 0x134678u: goto label_134678;
            case 0x134698u: goto label_134698;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346ECu: goto label_1346ec;
            case 0x134704u: goto label_134704;
            case 0x134720u: goto label_134720;
            case 0x13472Cu: goto label_13472c;
            case 0x134740u: goto label_134740;
            case 0x134750u: goto label_134750;
            case 0x13476Cu: goto label_13476c;
            case 0x13477Cu: goto label_13477c;
            case 0x134784u: goto label_134784;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C8u: goto label_1347c8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134704u; }
            if (ctx->pc != 0x134704u) { return; }
        }
        }
    }
    ctx->pc = 0x134704u;
label_134704:
    // 0x134704: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x134704u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x134708: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x134708u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13470c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13470cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134710: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x134710u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x134714: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x134714u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x134718: 0x40f809  jalr        $v0
    ctx->pc = 0x134718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134720u);
        ctx->pc = 0x13471Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134718u;
            // 0x13471c: 0x26730004  addiu       $s3, $s3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x134720u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13462Cu: goto label_13462c;
            case 0x13463Cu: goto label_13463c;
            case 0x134644u: goto label_134644;
            case 0x134650u: goto label_134650;
            case 0x134678u: goto label_134678;
            case 0x134698u: goto label_134698;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346ECu: goto label_1346ec;
            case 0x134704u: goto label_134704;
            case 0x134720u: goto label_134720;
            case 0x13472Cu: goto label_13472c;
            case 0x134740u: goto label_134740;
            case 0x134750u: goto label_134750;
            case 0x13476Cu: goto label_13476c;
            case 0x13477Cu: goto label_13477c;
            case 0x134784u: goto label_134784;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C8u: goto label_1347c8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134720u; }
            if (ctx->pc != 0x134720u) { return; }
        }
        }
    }
    ctx->pc = 0x134720u;
label_134720:
    // 0x134720: 0x297182a  slt         $v1, $s4, $s7
    ctx->pc = 0x134720u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 23)) ? 1 : 0);
    // 0x134724: 0x1460ffe2  bnez        $v1, . + 4 + (-0x1E << 2)
    ctx->pc = 0x134724u;
    {
        const bool branch_taken_0x134724 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x134728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134724u;
            // 0x134728: 0x27a20010  addiu       $v0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134724) {
            ctx->pc = 0x1346B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1346b0;
        }
    }
    ctx->pc = 0x13472Cu;
label_13472c:
    // 0x13472c: 0x8ec200a8  lw          $v0, 0xA8($s6)
    ctx->pc = 0x13472cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 168)));
    // 0x134730: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x134730u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134734: 0x551021  addu        $v0, $v0, $s5
    ctx->pc = 0x134734u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
    // 0x134738: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x134738u;
    SET_GPR_U32(ctx, 31, 0x134740u);
    ctx->pc = 0x13473Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134738u;
            // 0x13473c: 0xaec200a8  sw          $v0, 0xA8($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 168), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134740u; }
        if (ctx->pc != 0x134740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134740u; }
        if (ctx->pc != 0x134740u) { return; }
    }
    ctx->pc = 0x134740u;
label_134740:
    // 0x134740: 0x1ae0000e  blez        $s7, . + 4 + (0xE << 2)
    ctx->pc = 0x134740u;
    {
        const bool branch_taken_0x134740 = (GPR_S64(ctx, 23) <= 0);
        if (branch_taken_0x134740) {
            ctx->pc = 0x13477Cu;
            goto label_13477c;
        }
    }
    ctx->pc = 0x134748u;
    // 0x134748: 0x2e0a02d  daddu       $s4, $s7, $zero
    ctx->pc = 0x134748u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13474c: 0x26d00018  addiu       $s0, $s6, 0x18
    ctx->pc = 0x13474cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 24));
label_134750:
    // 0x134750: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x134750u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x134754: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x134754u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x134758: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x134758u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13475c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13475cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x134760: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x134760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x134764: 0x40f809  jalr        $v0
    ctx->pc = 0x134764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13476Cu);
        ctx->pc = 0x134768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134764u;
            // 0x134768: 0x2694ffff  addiu       $s4, $s4, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13476Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13462Cu: goto label_13462c;
            case 0x13463Cu: goto label_13463c;
            case 0x134644u: goto label_134644;
            case 0x134650u: goto label_134650;
            case 0x134678u: goto label_134678;
            case 0x134698u: goto label_134698;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346ECu: goto label_1346ec;
            case 0x134704u: goto label_134704;
            case 0x134720u: goto label_134720;
            case 0x13472Cu: goto label_13472c;
            case 0x134740u: goto label_134740;
            case 0x134750u: goto label_134750;
            case 0x13476Cu: goto label_13476c;
            case 0x13477Cu: goto label_13477c;
            case 0x134784u: goto label_134784;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C8u: goto label_1347c8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13476Cu; }
            if (ctx->pc != 0x13476Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13476Cu;
label_13476c:
    // 0x13476c: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x13476cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x134770: 0x51182a  slt         $v1, $v0, $s1
    ctx->pc = 0x134770u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x134774: 0x1680fff6  bnez        $s4, . + 4 + (-0xA << 2)
    ctx->pc = 0x134774u;
    {
        const bool branch_taken_0x134774 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x134778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134774u;
            // 0x134778: 0x43880a  movz        $s1, $v0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134774) {
            ctx->pc = 0x134750u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_134750;
        }
    }
    ctx->pc = 0x13477Cu;
label_13477c:
    // 0x13477c: 0xc04b1cc  jal         func_12C730
    ctx->pc = 0x13477Cu;
    SET_GPR_U32(ctx, 31, 0x134784u);
    ctx->pc = 0x134780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13477Cu;
            // 0x134780: 0x8ec4000c  lw          $a0, 0xC($s6) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C730u;
    if (runtime->hasFunction(0x12C730u)) {
        auto targetFn = runtime->lookupFunction(0x12C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134784u; }
        if (ctx->pc != 0x134784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C730_0x12c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134784u; }
        if (ctx->pc != 0x134784u) { return; }
    }
    ctx->pc = 0x134784u;
label_134784:
    // 0x134784: 0x8ec300a8  lw          $v1, 0xA8($s6)
    ctx->pc = 0x134784u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 168)));
    // 0x134788: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x134788u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x13478c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x13478cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x134790: 0x5c40000d  bgtzl       $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x134790u;
    {
        const bool branch_taken_0x134790 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x134790) {
            ctx->pc = 0x134794u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134790u;
            // 0x134794: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1347C8u;
            goto label_1347c8;
        }
    }
    ctx->pc = 0x134798u;
    // 0x134798: 0x8ec4000c  lw          $a0, 0xC($s6)
    ctx->pc = 0x134798u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x13479c: 0xc04b1ba  jal         func_12C6E8
    ctx->pc = 0x13479Cu;
    SET_GPR_U32(ctx, 31, 0x1347A4u);
    ctx->pc = 0x1347A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13479Cu;
            // 0x1347a0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C6E8u;
    if (runtime->hasFunction(0x12C6E8u)) {
        auto targetFn = runtime->lookupFunction(0x12C6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347A4u; }
        if (ctx->pc != 0x1347A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C6E8_0x12c6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347A4u; }
        if (ctx->pc != 0x1347A4u) { return; }
    }
    ctx->pc = 0x1347A4u;
label_1347a4:
    // 0x1347a4: 0x8ec4000c  lw          $a0, 0xC($s6)
    ctx->pc = 0x1347a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x1347a8: 0xc04b1c0  jal         func_12C700
    ctx->pc = 0x1347A8u;
    SET_GPR_U32(ctx, 31, 0x1347B0u);
    ctx->pc = 0x1347ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1347A8u;
            // 0x1347ac: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C700u;
    if (runtime->hasFunction(0x12C700u)) {
        auto targetFn = runtime->lookupFunction(0x12C700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347B0u; }
        if (ctx->pc != 0x1347B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C700_0x12c700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347B0u; }
        if (ctx->pc != 0x1347B0u) { return; }
    }
    ctx->pc = 0x1347B0u;
label_1347b0:
    // 0x1347b0: 0x8ec4000c  lw          $a0, 0xC($s6)
    ctx->pc = 0x1347b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x1347b4: 0xc04fb16  jal         func_13EC58
    ctx->pc = 0x1347B4u;
    SET_GPR_U32(ctx, 31, 0x1347BCu);
    ctx->pc = 0x1347B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1347B4u;
            // 0x1347b8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EC58u;
    if (runtime->hasFunction(0x13EC58u)) {
        auto targetFn = runtime->lookupFunction(0x13EC58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347BCu; }
        if (ctx->pc != 0x1347BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013EC58_0x13ec58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1347BCu; }
        if (ctx->pc != 0x1347BCu) { return; }
    }
    ctx->pc = 0x1347BCu;
label_1347bc:
    // 0x1347bc: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1347bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1347c0: 0xa2c20001  sb          $v0, 0x1($s6)
    ctx->pc = 0x1347c0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1347c4: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1347c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1347c8:
    // 0x1347c8: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1347c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1347cc: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1347ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1347d0: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x1347d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1347d4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1347d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1347d8: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x1347d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1347dc: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x1347dcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1347e0: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x1347e0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1347e4: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x1347e4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1347e8: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x1347e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1347ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1347ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1347F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1347ECu;
            // 0x1347f0: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13462Cu: goto label_13462c;
            case 0x13463Cu: goto label_13463c;
            case 0x134644u: goto label_134644;
            case 0x134650u: goto label_134650;
            case 0x134678u: goto label_134678;
            case 0x134698u: goto label_134698;
            case 0x1346B0u: goto label_1346b0;
            case 0x1346D0u: goto label_1346d0;
            case 0x1346ECu: goto label_1346ec;
            case 0x134704u: goto label_134704;
            case 0x134720u: goto label_134720;
            case 0x13472Cu: goto label_13472c;
            case 0x134740u: goto label_134740;
            case 0x134750u: goto label_134750;
            case 0x13476Cu: goto label_13476c;
            case 0x13477Cu: goto label_13477c;
            case 0x134784u: goto label_134784;
            case 0x1347A4u: goto label_1347a4;
            case 0x1347B0u: goto label_1347b0;
            case 0x1347BCu: goto label_1347bc;
            case 0x1347C8u: goto label_1347c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1347F4u;
    // 0x1347f4: 0x0  nop
    ctx->pc = 0x1347f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
