#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A45A0
// Address: 0x1a45a0 - 0x1a4c70
void sub_001A45A0_0x1a45a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A45A0_0x1a45a0");
#endif

    switch (ctx->pc) {
        case 0x1a45d8u: goto label_1a45d8;
        case 0x1a45ecu: goto label_1a45ec;
        case 0x1a45f8u: goto label_1a45f8;
        case 0x1a4604u: goto label_1a4604;
        case 0x1a4628u: goto label_1a4628;
        case 0x1a4630u: goto label_1a4630;
        case 0x1a463cu: goto label_1a463c;
        case 0x1a4648u: goto label_1a4648;
        case 0x1a4708u: goto label_1a4708;
        case 0x1a4710u: goto label_1a4710;
        case 0x1a4720u: goto label_1a4720;
        case 0x1a472cu: goto label_1a472c;
        case 0x1a4738u: goto label_1a4738;
        case 0x1a4750u: goto label_1a4750;
        case 0x1a4798u: goto label_1a4798;
        case 0x1a47fcu: goto label_1a47fc;
        case 0x1a480cu: goto label_1a480c;
        case 0x1a4860u: goto label_1a4860;
        case 0x1a48f8u: goto label_1a48f8;
        case 0x1a4900u: goto label_1a4900;
        case 0x1a4924u: goto label_1a4924;
        case 0x1a4948u: goto label_1a4948;
        case 0x1a4964u: goto label_1a4964;
        case 0x1a4aa4u: goto label_1a4aa4;
        case 0x1a4ad4u: goto label_1a4ad4;
        case 0x1a4ae0u: goto label_1a4ae0;
        case 0x1a4b94u: goto label_1a4b94;
        default: break;
    }

    ctx->pc = 0x1a45a0u;

    // 0x1a45a0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1a45a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1a45a4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1a45a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1a45a8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1a45a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1a45ac: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1a45acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1a45b0: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1a45b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1a45b4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a45b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a45b8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a45b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a45bc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a45bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a45c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a45c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a45c4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a45c4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a45c8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1a45c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a45cc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a45ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a45d0: 0xc068d68  jal         func_1A35A0
    ctx->pc = 0x1A45D0u;
    SET_GPR_U32(ctx, 31, 0x1A45D8u);
    ctx->pc = 0x1A45D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A45D0u;
            // 0x1a45d4: 0x3c05000a  lui         $a1, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)10 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35A0u;
    if (runtime->hasFunction(0x1A35A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A45D8u; }
        if (ctx->pc != 0x1A45D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35A0_0x1a35a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A45D8u; }
        if (ctx->pc != 0x1A45D8u) { return; }
    }
    ctx->pc = 0x1A45D8u;
label_1a45d8:
    // 0x1a45d8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1a45d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1a45dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a45dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a45e0: 0x34421000  ori         $v0, $v0, 0x1000
    ctx->pc = 0x1a45e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x1a45e4: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A45E4u;
    SET_GPR_U32(ctx, 31, 0x1A45ECu);
    ctx->pc = 0x1A45E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A45E4u;
            // 0x1a45e8: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A45ECu; }
        if (ctx->pc != 0x1A45ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A45ECu; }
        if (ctx->pc != 0x1A45ECu) { return; }
    }
    ctx->pc = 0x1A45ECu;
label_1a45ec:
    // 0x1a45ec: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1a45ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a45f0: 0xc068df8  jal         func_1A37E0
    ctx->pc = 0x1A45F0u;
    SET_GPR_U32(ctx, 31, 0x1A45F8u);
    ctx->pc = 0x1A45F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A45F0u;
            // 0x1a45f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A37E0u;
    if (runtime->hasFunction(0x1A37E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A37E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A45F8u; }
        if (ctx->pc != 0x1A45F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A37E0_0x1a37e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A45F8u; }
        if (ctx->pc != 0x1A45F8u) { return; }
    }
    ctx->pc = 0x1A45F8u;
label_1a45f8:
    // 0x1a45f8: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1a45f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1a45fc: 0xc068fb8  jal         func_1A3EE0
    ctx->pc = 0x1A45FCu;
    SET_GPR_U32(ctx, 31, 0x1A4604u);
    ctx->pc = 0x1A4600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A45FCu;
            // 0x1a4600: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3EE0u;
    if (runtime->hasFunction(0x1A3EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4604u; }
        if (ctx->pc != 0x1A4604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3EE0_0x1a3ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4604u; }
        if (ctx->pc != 0x1A4604u) { return; }
    }
    ctx->pc = 0x1A4604u;
label_1a4604:
    // 0x1a4604: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a4604u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a4608: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4608u;
    {
        const bool branch_taken_0x1a4608 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1A460Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4608u;
            // 0x1a460c: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4608) {
            ctx->pc = 0x1A4620u;
            goto label_1a4620;
        }
    }
    ctx->pc = 0x1A4610u;
    // 0x1a4610: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1a4610u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1a4614: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1a4614u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1a4618: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a4618u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a461c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1a461cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_1a4620:
    // 0x1a4620: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1A4620u;
    {
        const bool branch_taken_0x1a4620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4620u;
            // 0x1a4624: 0x782d  daddu       $t7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4620) {
            ctx->pc = 0x1A4660u;
            goto label_1a4660;
        }
    }
    ctx->pc = 0x1A4628u;
label_1a4628:
    // 0x1a4628: 0xc068dd8  jal         func_1A3760
    ctx->pc = 0x1A4628u;
    SET_GPR_U32(ctx, 31, 0x1A4630u);
    ctx->pc = 0x1A462Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4628u;
            // 0x1a462c: 0x1e0282d  daddu       $a1, $t7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3760u;
    if (runtime->hasFunction(0x1A3760u)) {
        auto targetFn = runtime->lookupFunction(0x1A3760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4630u; }
        if (ctx->pc != 0x1A4630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3760_0x1a3760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4630u; }
        if (ctx->pc != 0x1A4630u) { return; }
    }
    ctx->pc = 0x1A4630u;
label_1a4630:
    // 0x1a4630: 0x40682d  daddu       $t5, $v0, $zero
    ctx->pc = 0x1a4630u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4634: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A4634u;
    {
        const bool branch_taken_0x1a4634 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4634u;
            // 0x1a4638: 0x702d  daddu       $t6, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4634) {
            ctx->pc = 0x1A4650u;
            goto label_1a4650;
        }
    }
    ctx->pc = 0x1A463Cu;
label_1a463c:
    // 0x1a463c: 0x1e0282d  daddu       $a1, $t7, $zero
    ctx->pc = 0x1a463cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4640: 0xc068e4c  jal         func_1A3930
    ctx->pc = 0x1A4640u;
    SET_GPR_U32(ctx, 31, 0x1A4648u);
    ctx->pc = 0x1A4644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4640u;
            // 0x1a4644: 0x1c0302d  daddu       $a2, $t6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3930u;
    if (runtime->hasFunction(0x1A3930u)) {
        auto targetFn = runtime->lookupFunction(0x1A3930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4648u; }
        if (ctx->pc != 0x1A4648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3930_0x1a3930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4648u; }
        if (ctx->pc != 0x1A4648u) { return; }
    }
    ctx->pc = 0x1A4648u;
label_1a4648:
    // 0x1a4648: 0x1826021  addu        $t4, $t4, $v0
    ctx->pc = 0x1a4648u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 2)));
    // 0x1a464c: 0x25ce0001  addiu       $t6, $t6, 0x1
    ctx->pc = 0x1a464cu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 1));
label_1a4650:
    // 0x1a4650: 0x1cd102a  slt         $v0, $t6, $t5
    ctx->pc = 0x1a4650u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 14) < (int64_t)GPR_S64(ctx, 13)) ? 1 : 0);
    // 0x1a4654: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A4654u;
    {
        const bool branch_taken_0x1a4654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4654u;
            // 0x1a4658: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4654) {
            ctx->pc = 0x1A463Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a463c;
        }
    }
    ctx->pc = 0x1A465Cu;
    // 0x1a465c: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x1a465cu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
label_1a4660:
    // 0x1a4660: 0x1f2102a  slt         $v0, $t7, $s2
    ctx->pc = 0x1a4660u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 15) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1a4664: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1A4664u;
    {
        const bool branch_taken_0x1a4664 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4664u;
            // 0x1a4668: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4664) {
            ctx->pc = 0x1A4628u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a4628;
        }
    }
    ctx->pc = 0x1A466Cu;
    // 0x1a466c: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x1a466cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a4670: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1a4670u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1a4674: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1a4674u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1a4678: 0xac1821  addu        $v1, $a1, $t4
    ctx->pc = 0x1a4678u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x1a467c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1a467cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1a4680: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A4680u;
    {
        const bool branch_taken_0x1a4680 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4680u;
            // 0x1a4684: 0x33040  sll         $a2, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4680) {
            ctx->pc = 0x1A4690u;
            goto label_1a4690;
        }
    }
    ctx->pc = 0x1A4688u;
    // 0x1a4688: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1a4688u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a468c: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1a468cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_1a4690:
    // 0x1a4690: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1a4690u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1a4694: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1a4694u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1a4698: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A4698u;
    {
        const bool branch_taken_0x1a4698 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A469Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4698u;
            // 0x1a469c: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4698) {
            ctx->pc = 0x1A46A8u;
            goto label_1a46a8;
        }
    }
    ctx->pc = 0x1A46A0u;
    // 0x1a46a0: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1a46a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a46a4: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1a46a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_1a46a8:
    // 0x1a46a8: 0x8c22ffe0  lw          $v0, -0x20($at)
    ctx->pc = 0x1a46a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967264)));
    // 0x1a46ac: 0x46082a  slt         $at, $v0, $a2
    ctx->pc = 0x1a46acu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1a46b0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A46B0u;
    {
        const bool branch_taken_0x1a46b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a46b0) {
            ctx->pc = 0x1A46C0u;
            goto label_1a46c0;
        }
    }
    ctx->pc = 0x1A46B8u;
    // 0x1a46b8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a46b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a46bc: 0xac26ffe0  sw          $a2, -0x20($at)
    ctx->pc = 0x1a46bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967264), GPR_U32(ctx, 6));
label_1a46c0:
    // 0x1a46c0: 0x3c010004  lui         $at, 0x4
    ctx->pc = 0x1a46c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
    // 0x1a46c4: 0x34210001  ori         $at, $at, 0x1
    ctx->pc = 0x1a46c4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)1);
    // 0x1a46c8: 0xc1082a  slt         $at, $a2, $at
    ctx->pc = 0x1a46c8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1a46cc: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A46CCu;
    {
        const bool branch_taken_0x1a46cc = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A46D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A46CCu;
            // 0x1a46d0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a46cc) {
            ctx->pc = 0x1A46DCu;
            goto label_1a46dc;
        }
    }
    ctx->pc = 0x1A46D4u;
    // 0x1a46d4: 0x1000015a  b           . + 4 + (0x15A << 2)
    ctx->pc = 0x1A46D4u;
    {
        const bool branch_taken_0x1a46d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A46D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A46D4u;
            // 0x1a46d8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a46d4) {
            ctx->pc = 0x1A4C40u;
            goto label_1a4c40;
        }
    }
    ctx->pc = 0x1A46DCu;
label_1a46dc:
    // 0x1a46dc: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1a46dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1a46e0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A46E0u;
    {
        const bool branch_taken_0x1a46e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A46E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A46E0u;
            // 0x1a46e4: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a46e0) {
            ctx->pc = 0x1A46F0u;
            goto label_1a46f0;
        }
    }
    ctx->pc = 0x1A46E8u;
    // 0x1a46e8: 0x10000155  b           . + 4 + (0x155 << 2)
    ctx->pc = 0x1A46E8u;
    {
        const bool branch_taken_0x1a46e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A46ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A46E8u;
            // 0x1a46ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a46e8) {
            ctx->pc = 0x1A4C40u;
            goto label_1a4c40;
        }
    }
    ctx->pc = 0x1A46F0u;
label_1a46f0:
    // 0x1a46f0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a46f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a46f4: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1a46f4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1a46f8: 0xae26001c  sw          $a2, 0x1C($s1)
    ctx->pc = 0x1a46f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 6));
    // 0x1a46fc: 0x8e340008  lw          $s4, 0x8($s1)
    ctx->pc = 0x1a46fcu;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1a4700: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1A4700u;
    {
        const bool branch_taken_0x1a4700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4700u;
            // 0x1a4704: 0x702d  daddu       $t6, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4700) {
            ctx->pc = 0x1A4838u;
            goto label_1a4838;
        }
    }
    ctx->pc = 0x1A4708u;
label_1a4708:
    // 0x1a4708: 0xc068dd8  jal         func_1A3760
    ctx->pc = 0x1A4708u;
    SET_GPR_U32(ctx, 31, 0x1A4710u);
    ctx->pc = 0x1A470Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4708u;
            // 0x1a470c: 0x1c0282d  daddu       $a1, $t6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3760u;
    if (runtime->hasFunction(0x1A3760u)) {
        auto targetFn = runtime->lookupFunction(0x1A3760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4710u; }
        if (ctx->pc != 0x1A4710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3760_0x1a3760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4710u; }
        if (ctx->pc != 0x1A4710u) { return; }
    }
    ctx->pc = 0x1A4710u;
label_1a4710:
    // 0x1a4710: 0x40682d  daddu       $t5, $v0, $zero
    ctx->pc = 0x1a4710u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4714: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a4714u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4718: 0xc068db8  jal         func_1A36E0
    ctx->pc = 0x1A4718u;
    SET_GPR_U32(ctx, 31, 0x1A4720u);
    ctx->pc = 0x1A471Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4718u;
            // 0x1a471c: 0x1c0282d  daddu       $a1, $t6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36E0u;
    if (runtime->hasFunction(0x1A36E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4720u; }
        if (ctx->pc != 0x1A4720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36E0_0x1a36e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4720u; }
        if (ctx->pc != 0x1A4720u) { return; }
    }
    ctx->pc = 0x1A4720u;
label_1a4720:
    // 0x1a4720: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1a4720u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4724: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1A4724u;
    {
        const bool branch_taken_0x1a4724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4724u;
            // 0x1a4728: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4724) {
            ctx->pc = 0x1A4828u;
            goto label_1a4828;
        }
    }
    ctx->pc = 0x1A472Cu;
label_1a472c:
    // 0x1a472c: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a472cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4730: 0xc068e4c  jal         func_1A3930
    ctx->pc = 0x1A4730u;
    SET_GPR_U32(ctx, 31, 0x1A4738u);
    ctx->pc = 0x1A4734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4730u;
            // 0x1a4734: 0x180302d  daddu       $a2, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3930u;
    if (runtime->hasFunction(0x1A3930u)) {
        auto targetFn = runtime->lookupFunction(0x1A3930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4738u; }
        if (ctx->pc != 0x1A4738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3930_0x1a3930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4738u; }
        if (ctx->pc != 0x1A4738u) { return; }
    }
    ctx->pc = 0x1A4738u;
label_1a4738:
    // 0x1a4738: 0xa6820000  sh          $v0, 0x0($s4)
    ctx->pc = 0x1a4738u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a473c: 0x40782d  daddu       $t7, $v0, $zero
    ctx->pc = 0x1a473cu;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4740: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a4740u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4744: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a4744u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4748: 0xc068e78  jal         func_1A39E0
    ctx->pc = 0x1A4748u;
    SET_GPR_U32(ctx, 31, 0x1A4750u);
    ctx->pc = 0x1A474Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4748u;
            // 0x1a474c: 0x180302d  daddu       $a2, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A39E0u;
    if (runtime->hasFunction(0x1A39E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A39E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4750u; }
        if (ctx->pc != 0x1A4750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A39E0_0x1a39e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4750u; }
        if (ctx->pc != 0x1A4750u) { return; }
    }
    ctx->pc = 0x1A4750u;
label_1a4750:
    // 0x1a4750: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4750u;
    {
        const bool branch_taken_0x1a4750 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a4750) {
            ctx->pc = 0x1A4768u;
            goto label_1a4768;
        }
    }
    ctx->pc = 0x1A4758u;
    // 0x1a4758: 0x96820000  lhu         $v0, 0x0($s4)
    ctx->pc = 0x1a4758u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1a475c: 0x34428000  ori         $v0, $v0, 0x8000
    ctx->pc = 0x1a475cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x1a4760: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A4760u;
    {
        const bool branch_taken_0x1a4760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4760u;
            // 0x1a4764: 0xa6820000  sh          $v0, 0x0($s4) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4760) {
            ctx->pc = 0x1A4774u;
            goto label_1a4774;
        }
    }
    ctx->pc = 0x1A4768u;
label_1a4768:
    // 0x1a4768: 0x96820000  lhu         $v0, 0x0($s4)
    ctx->pc = 0x1a4768u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1a476c: 0x34424000  ori         $v0, $v0, 0x4000
    ctx->pc = 0x1a476cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16384);
    // 0x1a4770: 0xa6820000  sh          $v0, 0x0($s4)
    ctx->pc = 0x1a4770u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
label_1a4774:
    // 0x1a4774: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1a4774u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1a4778: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1a4778u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1a477c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a477cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a4780: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A4780u;
    {
        const bool branch_taken_0x1a4780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4780u;
            // 0x1a4784: 0x26940002  addiu       $s4, $s4, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4780) {
            ctx->pc = 0x1A47A0u;
            goto label_1a47a0;
        }
    }
    ctx->pc = 0x1A4788u;
    // 0x1a4788: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a4788u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a478c: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a478cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4790: 0xc068e20  jal         func_1A3880
    ctx->pc = 0x1A4790u;
    SET_GPR_U32(ctx, 31, 0x1A4798u);
    ctx->pc = 0x1A4794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4790u;
            // 0x1a4794: 0x180302d  daddu       $a2, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3880u;
    if (runtime->hasFunction(0x1A3880u)) {
        auto targetFn = runtime->lookupFunction(0x1A3880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4798u; }
        if (ctx->pc != 0x1A4798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3880_0x1a3880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4798u; }
        if (ctx->pc != 0x1A4798u) { return; }
    }
    ctx->pc = 0x1A4798u;
label_1a4798:
    // 0x1a4798: 0xa6820000  sh          $v0, 0x0($s4)
    ctx->pc = 0x1a4798u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a479c: 0x26940002  addiu       $s4, $s4, 0x2
    ctx->pc = 0x1a479cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
label_1a47a0:
    // 0x1a47a0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1a47a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1a47a4: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1a47a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1a47a8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a47a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a47ac: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1A47ACu;
    {
        const bool branch_taken_0x1a47ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A47B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A47ACu;
            // 0x1a47b0: 0x3c020004  lui         $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a47ac) {
            ctx->pc = 0x1A47E4u;
            goto label_1a47e4;
        }
    }
    ctx->pc = 0x1A47B4u;
    // 0x1a47b4: 0x12620008  beq         $s3, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A47B4u;
    {
        const bool branch_taken_0x1a47b4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a47b4) {
            ctx->pc = 0x1A47D8u;
            goto label_1a47d8;
        }
    }
    ctx->pc = 0x1A47BCu;
    // 0x1a47bc: 0x3c020003  lui         $v0, 0x3
    ctx->pc = 0x1a47bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3 << 16));
    // 0x1a47c0: 0x12620003  beq         $s3, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A47C0u;
    {
        const bool branch_taken_0x1a47c0 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a47c0) {
            ctx->pc = 0x1A47D0u;
            goto label_1a47d0;
        }
    }
    ctx->pc = 0x1A47C8u;
    // 0x1a47c8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A47C8u;
    {
        const bool branch_taken_0x1a47c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A47CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A47C8u;
            // 0x1a47cc: 0x26940002  addiu       $s4, $s4, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a47c8) {
            ctx->pc = 0x1A47E4u;
            goto label_1a47e4;
        }
    }
    ctx->pc = 0x1A47D0u;
label_1a47d0:
    // 0x1a47d0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A47D0u;
    {
        const bool branch_taken_0x1a47d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A47D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A47D0u;
            // 0x1a47d4: 0xa6800000  sh          $zero, 0x0($s4) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a47d0) {
            ctx->pc = 0x1A47E0u;
            goto label_1a47e0;
        }
    }
    ctx->pc = 0x1A47D8u;
label_1a47d8:
    // 0x1a47d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a47d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a47dc: 0xa6820000  sh          $v0, 0x0($s4)
    ctx->pc = 0x1a47dcu;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
label_1a47e0:
    // 0x1a47e0: 0x26940002  addiu       $s4, $s4, 0x2
    ctx->pc = 0x1a47e0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
label_1a47e4:
    // 0x1a47e4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1a47e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1a47e8: 0x30421000  andi        $v0, $v0, 0x1000
    ctx->pc = 0x1a47e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4096);
    // 0x1a47ec: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1A47ECu;
    {
        const bool branch_taken_0x1a47ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A47F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A47ECu;
            // 0x1a47f0: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a47ec) {
            ctx->pc = 0x1A4824u;
            goto label_1a4824;
        }
    }
    ctx->pc = 0x1A47F4u;
    // 0x1a47f4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A47F4u;
    {
        const bool branch_taken_0x1a47f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A47F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A47F4u;
            // 0x1a47f8: 0x2af102a  slt         $v0, $s5, $t7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 15)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a47f4) {
            ctx->pc = 0x1A481Cu;
            goto label_1a481c;
        }
    }
    ctx->pc = 0x1A47FCu;
label_1a47fc:
    // 0x1a47fc: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a47fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4800: 0x180302d  daddu       $a2, $t4, $zero
    ctx->pc = 0x1a4800u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4804: 0xc068ea8  jal         func_1A3AA0
    ctx->pc = 0x1A4804u;
    SET_GPR_U32(ctx, 31, 0x1A480Cu);
    ctx->pc = 0x1A4808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4804u;
            // 0x1a4808: 0x2a0382d  daddu       $a3, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3AA0u;
    if (runtime->hasFunction(0x1A3AA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A480Cu; }
        if (ctx->pc != 0x1A480Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3AA0_0x1a3aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A480Cu; }
        if (ctx->pc != 0x1A480Cu) { return; }
    }
    ctx->pc = 0x1A480Cu;
label_1a480c:
    // 0x1a480c: 0xa6820000  sh          $v0, 0x0($s4)
    ctx->pc = 0x1a480cu;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a4810: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x1a4810u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x1a4814: 0x26940002  addiu       $s4, $s4, 0x2
    ctx->pc = 0x1a4814u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
    // 0x1a4818: 0x2af102a  slt         $v0, $s5, $t7
    ctx->pc = 0x1a4818u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 15)) ? 1 : 0);
label_1a481c:
    // 0x1a481c: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A481Cu;
    {
        const bool branch_taken_0x1a481c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A481Cu;
            // 0x1a4820: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a481c) {
            ctx->pc = 0x1A47FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a47fc;
        }
    }
    ctx->pc = 0x1A4824u;
label_1a4824:
    // 0x1a4824: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x1a4824u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
label_1a4828:
    // 0x1a4828: 0x18d102a  slt         $v0, $t4, $t5
    ctx->pc = 0x1a4828u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 13)) ? 1 : 0);
    // 0x1a482c: 0x1440ffbf  bnez        $v0, . + 4 + (-0x41 << 2)
    ctx->pc = 0x1A482Cu;
    {
        const bool branch_taken_0x1a482c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A482Cu;
            // 0x1a4830: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a482c) {
            ctx->pc = 0x1A472Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a472c;
        }
    }
    ctx->pc = 0x1A4834u;
    // 0x1a4834: 0x25ce0001  addiu       $t6, $t6, 0x1
    ctx->pc = 0x1a4834u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 1));
label_1a4838:
    // 0x1a4838: 0x1d2102a  slt         $v0, $t6, $s2
    ctx->pc = 0x1a4838u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 14) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1a483c: 0x1440ffb2  bnez        $v0, . + 4 + (-0x4E << 2)
    ctx->pc = 0x1A483Cu;
    {
        const bool branch_taken_0x1a483c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A483Cu;
            // 0x1a4840: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a483c) {
            ctx->pc = 0x1A4708u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a4708;
        }
    }
    ctx->pc = 0x1A4844u;
    // 0x1a4844: 0x24020035  addiu       $v0, $zero, 0x35
    ctx->pc = 0x1a4844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
    // 0x1a4848: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a4848u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a484c: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x1a484cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x1a4850: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1a4850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1a4854: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x1a4854u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x1a4858: 0xc068e10  jal         func_1A3840
    ctx->pc = 0x1A4858u;
    SET_GPR_U32(ctx, 31, 0x1A4860u);
    ctx->pc = 0x1A485Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4858u;
            // 0x1a485c: 0xae22000c  sw          $v0, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3840u;
    if (runtime->hasFunction(0x1A3840u)) {
        auto targetFn = runtime->lookupFunction(0x1A3840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4860u; }
        if (ctx->pc != 0x1A4860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3840_0x1a3840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4860u; }
        if (ctx->pc != 0x1A4860u) { return; }
    }
    ctx->pc = 0x1A4860u;
label_1a4860:
    // 0x1a4860: 0xae220014  sw          $v0, 0x14($s1)
    ctx->pc = 0x1a4860u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
    // 0x1a4864: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a4864u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a4868: 0x8e240014  lw          $a0, 0x14($s1)
    ctx->pc = 0x1a4868u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a486c: 0x8c22ffe0  lw          $v0, -0x20($at)
    ctx->pc = 0x1a486cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967264)));
    // 0x1a4870: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1a4870u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a4874: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a4874u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a4878: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1a4878u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1a487c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a487cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a4880: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a4880u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a4884: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1a4884u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a4888: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A4888u;
    {
        const bool branch_taken_0x1a4888 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A488Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4888u;
            // 0x1a488c: 0x3c010004  lui         $at, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4888) {
            ctx->pc = 0x1A489Cu;
            goto label_1a489c;
        }
    }
    ctx->pc = 0x1A4890u;
    // 0x1a4890: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a4890u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a4894: 0xac23ffe0  sw          $v1, -0x20($at)
    ctx->pc = 0x1a4894u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967264), GPR_U32(ctx, 3));
    // 0x1a4898: 0x3c010004  lui         $at, 0x4
    ctx->pc = 0x1a4898u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
label_1a489c:
    // 0x1a489c: 0x34210001  ori         $at, $at, 0x1
    ctx->pc = 0x1a489cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)1);
    // 0x1a48a0: 0x61082a  slt         $at, $v1, $at
    ctx->pc = 0x1a48a0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1a48a4: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A48A4u;
    {
        const bool branch_taken_0x1a48a4 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A48A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A48A4u;
            // 0x1a48a8: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a48a4) {
            ctx->pc = 0x1A48B4u;
            goto label_1a48b4;
        }
    }
    ctx->pc = 0x1A48ACu;
    // 0x1a48ac: 0x100000e4  b           . + 4 + (0xE4 << 2)
    ctx->pc = 0x1A48ACu;
    {
        const bool branch_taken_0x1a48ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A48B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A48ACu;
            // 0x1a48b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a48ac) {
            ctx->pc = 0x1A4C40u;
            goto label_1a4c40;
        }
    }
    ctx->pc = 0x1A48B4u;
label_1a48b4:
    // 0x1a48b4: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1a48b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1a48b8: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A48B8u;
    {
        const bool branch_taken_0x1a48b8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A48BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A48B8u;
            // 0x1a48bc: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a48b8) {
            ctx->pc = 0x1A48C8u;
            goto label_1a48c8;
        }
    }
    ctx->pc = 0x1A48C0u;
    // 0x1a48c0: 0x100000df  b           . + 4 + (0xDF << 2)
    ctx->pc = 0x1A48C0u;
    {
        const bool branch_taken_0x1a48c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A48C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A48C0u;
            // 0x1a48c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a48c0) {
            ctx->pc = 0x1A4C40u;
            goto label_1a4c40;
        }
    }
    ctx->pc = 0x1A48C8u;
label_1a48c8:
    // 0x1a48c8: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x1a48c8u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a48cc: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1a48ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a48d0: 0x27b30094  addiu       $s3, $sp, 0x94
    ctx->pc = 0x1a48d0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 148));
    // 0x1a48d4: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x1a48d4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x1a48d8: 0x27b20098  addiu       $s2, $sp, 0x98
    ctx->pc = 0x1a48d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 152));
    // 0x1a48dc: 0xae230018  sw          $v1, 0x18($s1)
    ctx->pc = 0x1a48dcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 3));
    // 0x1a48e0: 0x27b9009c  addiu       $t9, $sp, 0x9C
    ctx->pc = 0x1a48e0u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 29), 156));
    // 0x1a48e4: 0x8e2a0010  lw          $t2, 0x10($s1)
    ctx->pc = 0x1a48e4u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1a48e8: 0x27b80084  addiu       $t8, $sp, 0x84
    ctx->pc = 0x1a48e8u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 29), 132));
    // 0x1a48ec: 0x27af0088  addiu       $t7, $sp, 0x88
    ctx->pc = 0x1a48ecu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 29), 136));
    // 0x1a48f0: 0x100000ce  b           . + 4 + (0xCE << 2)
    ctx->pc = 0x1A48F0u;
    {
        const bool branch_taken_0x1a48f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A48F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A48F0u;
            // 0x1a48f4: 0x27b6008c  addiu       $s6, $sp, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 29), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a48f0) {
            ctx->pc = 0x1A4C2Cu;
            goto label_1a4c2c;
        }
    }
    ctx->pc = 0x1A48F8u;
label_1a48f8:
    // 0x1a48f8: 0xc068ee0  jal         func_1A3B80
    ctx->pc = 0x1A48F8u;
    SET_GPR_U32(ctx, 31, 0x1A4900u);
    ctx->pc = 0x1A48FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A48F8u;
            // 0x1a48fc: 0x180282d  daddu       $a1, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3B80u;
    if (runtime->hasFunction(0x1A3B80u)) {
        auto targetFn = runtime->lookupFunction(0x1A3B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4900u; }
        if (ctx->pc != 0x1A4900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3B80_0x1a3b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4900u; }
        if (ctx->pc != 0x1A4900u) { return; }
    }
    ctx->pc = 0x1A4900u;
label_1a4900:
    // 0x1a4900: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a4900u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4904: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a4904u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4908: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x1a4908u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a490c: 0xe5400000  swc1        $f0, 0x0($t2)
    ctx->pc = 0x1a490cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 0), bits); }
    // 0x1a4910: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a4910u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4914: 0xe5400004  swc1        $f0, 0x4($t2)
    ctx->pc = 0x1a4914u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 4), bits); }
    // 0x1a4918: 0xc4400008  lwc1        $f0, 0x8($v0)
    ctx->pc = 0x1a4918u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a491c: 0xc068ef4  jal         func_1A3BD0
    ctx->pc = 0x1A491Cu;
    SET_GPR_U32(ctx, 31, 0x1A4924u);
    ctx->pc = 0x1A4920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A491Cu;
            // 0x1a4920: 0xe5400008  swc1        $f0, 0x8($t2) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3BD0u;
    if (runtime->hasFunction(0x1A3BD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3BD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4924u; }
        if (ctx->pc != 0x1A4924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3BD0_0x1a3bd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4924u; }
        if (ctx->pc != 0x1A4924u) { return; }
    }
    ctx->pc = 0x1A4924u;
label_1a4924:
    // 0x1a4924: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a4924u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4928: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a4928u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a492c: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x1a492cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4930: 0xe540000c  swc1        $f0, 0xC($t2)
    ctx->pc = 0x1a4930u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 12), bits); }
    // 0x1a4934: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a4934u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4938: 0xe5400010  swc1        $f0, 0x10($t2)
    ctx->pc = 0x1a4938u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 16), bits); }
    // 0x1a493c: 0xc4400008  lwc1        $f0, 0x8($v0)
    ctx->pc = 0x1a493cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4940: 0xc068f08  jal         func_1A3C20
    ctx->pc = 0x1A4940u;
    SET_GPR_U32(ctx, 31, 0x1A4948u);
    ctx->pc = 0x1A4944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4940u;
            // 0x1a4944: 0xe5400014  swc1        $f0, 0x14($t2) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 20), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3C20u;
    if (runtime->hasFunction(0x1A3C20u)) {
        auto targetFn = runtime->lookupFunction(0x1A3C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4948u; }
        if (ctx->pc != 0x1A4948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3C20_0x1a3c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4948u; }
        if (ctx->pc != 0x1A4948u) { return; }
    }
    ctx->pc = 0x1A4948u;
label_1a4948:
    // 0x1a4948: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a4948u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a494c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a494cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4950: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x1a4950u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4954: 0xe540001c  swc1        $f0, 0x1C($t2)
    ctx->pc = 0x1a4954u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 28), bits); }
    // 0x1a4958: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a4958u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a495c: 0xc068f18  jal         func_1A3C60
    ctx->pc = 0x1A495Cu;
    SET_GPR_U32(ctx, 31, 0x1A4964u);
    ctx->pc = 0x1A4960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A495Cu;
            // 0x1a4960: 0xe5400020  swc1        $f0, 0x20($t2) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 32), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3C60u;
    if (runtime->hasFunction(0x1A3C60u)) {
        auto targetFn = runtime->lookupFunction(0x1A3C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4964u; }
        if (ctx->pc != 0x1A4964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3C60_0x1a3c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4964u; }
        if (ctx->pc != 0x1A4964u) { return; }
    }
    ctx->pc = 0x1A4964u;
label_1a4964:
    // 0x1a4964: 0xc441000c  lwc1        $f1, 0xC($v0)
    ctx->pc = 0x1a4964u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a4968: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a4968u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a496c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a496cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4970: 0x0  nop
    ctx->pc = 0x1a4970u;
    // NOP
    // 0x1a4974: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a4974u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4978: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4978u;
    {
        const bool branch_taken_0x1a4978 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a4978) {
            ctx->pc = 0x1A4990u;
            goto label_1a4990;
        }
    }
    ctx->pc = 0x1A4980u;
    // 0x1a4980: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4980u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4984: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4984u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4988: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A4988u;
    {
        const bool branch_taken_0x1a4988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A498Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4988u;
            // 0x1a498c: 0xc4410000  lwc1        $f1, 0x0($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4988) {
            ctx->pc = 0x1A49ACu;
            goto label_1a49ac;
        }
    }
    ctx->pc = 0x1A4990u;
label_1a4990:
    // 0x1a4990: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a4990u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a4994: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a4994u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4998: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4998u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a499c: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a499cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a49a0: 0x0  nop
    ctx->pc = 0x1a49a0u;
    // NOP
    // 0x1a49a4: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a49a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a49a8: 0xc4410000  lwc1        $f1, 0x0($v0)
    ctx->pc = 0x1a49a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a49ac:
    // 0x1a49ac: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a49acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a49b0: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a49b0u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a49b4: 0x0  nop
    ctx->pc = 0x1a49b4u;
    // NOP
    // 0x1a49b8: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a49b8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a49bc: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A49BCu;
    {
        const bool branch_taken_0x1a49bc = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1A49C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A49BCu;
            // 0x1a49c0: 0x42e00  sll         $a1, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a49bc) {
            ctx->pc = 0x1A49D4u;
            goto label_1a49d4;
        }
    }
    ctx->pc = 0x1A49C4u;
    // 0x1a49c4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a49c4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a49c8: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a49c8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a49cc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A49CCu;
    {
        const bool branch_taken_0x1a49cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A49D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A49CCu;
            // 0x1a49d0: 0xc4410004  lwc1        $f1, 0x4($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a49cc) {
            ctx->pc = 0x1A49F0u;
            goto label_1a49f0;
        }
    }
    ctx->pc = 0x1A49D4u;
label_1a49d4:
    // 0x1a49d4: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a49d4u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a49d8: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a49d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a49dc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a49dcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a49e0: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a49e0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a49e4: 0x0  nop
    ctx->pc = 0x1a49e4u;
    // NOP
    // 0x1a49e8: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a49e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a49ec: 0xc4410004  lwc1        $f1, 0x4($v0)
    ctx->pc = 0x1a49ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a49f0:
    // 0x1a49f0: 0x41c00  sll         $v1, $a0, 16
    ctx->pc = 0x1a49f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1a49f4: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x1a49f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1a49f8: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a49f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a49fc: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a49fcu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4a00: 0x0  nop
    ctx->pc = 0x1a4a00u;
    // NOP
    // 0x1a4a04: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a4a04u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4a08: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4A08u;
    {
        const bool branch_taken_0x1a4a08 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a4a08) {
            ctx->pc = 0x1A4A20u;
            goto label_1a4a20;
        }
    }
    ctx->pc = 0x1A4A10u;
    // 0x1a4a10: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4a10u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4a14: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4a14u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4a18: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A4A18u;
    {
        const bool branch_taken_0x1a4a18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4A18u;
            // 0x1a4a1c: 0xc4410008  lwc1        $f1, 0x8($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4a18) {
            ctx->pc = 0x1A4A3Cu;
            goto label_1a4a3c;
        }
    }
    ctx->pc = 0x1A4A20u;
label_1a4a20:
    // 0x1a4a20: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a4a20u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a4a24: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a4a24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4a28: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4a28u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4a2c: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4a2cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4a30: 0x0  nop
    ctx->pc = 0x1a4a30u;
    // NOP
    // 0x1a4a34: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a4a34u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a4a38: 0xc4410008  lwc1        $f1, 0x8($v0)
    ctx->pc = 0x1a4a38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a4a3c:
    // 0x1a4a3c: 0x41a00  sll         $v1, $a0, 8
    ctx->pc = 0x1a4a3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1a4a40: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1a4a40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1a4a44: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a4a44u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4a48: 0x0  nop
    ctx->pc = 0x1a4a48u;
    // NOP
    // 0x1a4a4c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a4a4cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4a50: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4A50u;
    {
        const bool branch_taken_0x1a4a50 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1A4A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4A50u;
            // 0x1a4a54: 0x652025  or          $a0, $v1, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4a50) {
            ctx->pc = 0x1A4A68u;
            goto label_1a4a68;
        }
    }
    ctx->pc = 0x1A4A58u;
    // 0x1a4a58: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4a58u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4a5c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a4a5cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a4a60: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A4A60u;
    {
        const bool branch_taken_0x1a4a60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4A60u;
            // 0x1a4a64: 0x641025  or          $v0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4a60) {
            ctx->pc = 0x1A4A84u;
            goto label_1a4a84;
        }
    }
    ctx->pc = 0x1A4A68u;
label_1a4a68:
    // 0x1a4a68: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a4a68u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a4a6c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1a4a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4a70: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4a70u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4a74: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a4a74u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a4a78: 0x0  nop
    ctx->pc = 0x1a4a78u;
    // NOP
    // 0x1a4a7c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1a4a7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a4a80: 0x641025  or          $v0, $v1, $a0
    ctx->pc = 0x1a4a80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
label_1a4a84:
    // 0x1a4a84: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x1a4a84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4a88: 0xad420018  sw          $v0, 0x18($t2)
    ctx->pc = 0x1a4a88u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 24), GPR_U32(ctx, 2));
    // 0x1a4a8c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a4a8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4a90: 0xad400024  sw          $zero, 0x24($t2)
    ctx->pc = 0x1a4a90u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 36), GPR_U32(ctx, 0));
    // 0x1a4a94: 0x254d0024  addiu       $t5, $t2, 0x24
    ctx->pc = 0x1a4a94u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 10), 36));
    // 0x1a4a98: 0x254e0028  addiu       $t6, $t2, 0x28
    ctx->pc = 0x1a4a98u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 10), 40));
    // 0x1a4a9c: 0xc068f28  jal         func_1A3CA0
    ctx->pc = 0x1A4A9Cu;
    SET_GPR_U32(ctx, 31, 0x1A4AA4u);
    ctx->pc = 0x1A4AA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4A9Cu;
            // 0x1a4aa0: 0xad400028  sw          $zero, 0x28($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3CA0u;
    if (runtime->hasFunction(0x1A3CA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4AA4u; }
        if (ctx->pc != 0x1A4AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3CA0_0x1a3ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4AA4u; }
        if (ctx->pc != 0x1A4AA4u) { return; }
    }
    ctx->pc = 0x1A4AA4u;
label_1a4aa4:
    // 0x1a4aa4: 0xafa00090  sw          $zero, 0x90($sp)
    ctx->pc = 0x1a4aa4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 144), GPR_U32(ctx, 0));
    // 0x1a4aa8: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x1a4aa8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4aac: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x1a4aacu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x1a4ab0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1a4ab0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4ab4: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1a4ab4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1a4ab8: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x1a4ab8u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4abc: 0xaf200000  sw          $zero, 0x0($t9)
    ctx->pc = 0x1a4abcu;
    WRITE32(ADD32(GPR_U32(ctx, 25), 0), GPR_U32(ctx, 0));
    // 0x1a4ac0: 0xafa00080  sw          $zero, 0x80($sp)
    ctx->pc = 0x1a4ac0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 0));
    // 0x1a4ac4: 0xaf000000  sw          $zero, 0x0($t8)
    ctx->pc = 0x1a4ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 0));
    // 0x1a4ac8: 0xade00000  sw          $zero, 0x0($t7)
    ctx->pc = 0x1a4ac8u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 0), GPR_U32(ctx, 0));
    // 0x1a4acc: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1A4ACCu;
    {
        const bool branch_taken_0x1a4acc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4AD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4ACCu;
            // 0x1a4ad0: 0xaec00000  sw          $zero, 0x0($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4acc) {
            ctx->pc = 0x1A4B44u;
            goto label_1a4b44;
        }
    }
    ctx->pc = 0x1A4AD4u;
label_1a4ad4:
    // 0x1a4ad4: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x1a4ad4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4ad8: 0xc068f40  jal         func_1A3D00
    ctx->pc = 0x1A4AD8u;
    SET_GPR_U32(ctx, 31, 0x1A4AE0u);
    ctx->pc = 0x1A4ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4AD8u;
            // 0x1a4adc: 0x160302d  daddu       $a2, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3D00u;
    if (runtime->hasFunction(0x1A3D00u)) {
        auto targetFn = runtime->lookupFunction(0x1A3D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4AE0u; }
        if (ctx->pc != 0x1A4AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3D00_0x1a3d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4AE0u; }
        if (ctx->pc != 0x1A4AE0u) { return; }
    }
    ctx->pc = 0x1A4AE0u;
label_1a4ae0:
    // 0x1a4ae0: 0xc4410004  lwc1        $f1, 0x4($v0)
    ctx->pc = 0x1a4ae0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a4ae4: 0x3c04437f  lui         $a0, 0x437F
    ctx->pc = 0x1a4ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)17279 << 16));
    // 0x1a4ae8: 0x44841000  mtc1        $a0, $f2
    ctx->pc = 0x1a4ae8u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1a4aec: 0xb1880  sll         $v1, $t3, 2
    ctx->pc = 0x1a4aecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 11), 2));
    // 0x1a4af0: 0x7d2021  addu        $a0, $v1, $sp
    ctx->pc = 0x1a4af0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1a4af4: 0x24850090  addiu       $a1, $a0, 0x90
    ctx->pc = 0x1a4af4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 144));
    // 0x1a4af8: 0x3c0442c8  lui         $a0, 0x42C8
    ctx->pc = 0x1a4af8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)17096 << 16));
    // 0x1a4afc: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x1a4afcu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x1a4b00: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1a4b00u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4b04: 0x0  nop
    ctx->pc = 0x1a4b04u;
    // NOP
    // 0x1a4b08: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1a4b08u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1a4b0c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4b0cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1a4b10: 0x44040000  mfc1        $a0, $f0
    ctx->pc = 0x1a4b10u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4b14: 0x0  nop
    ctx->pc = 0x1a4b14u;
    // NOP
    // 0x1a4b18: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1a4b18u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1a4b1c: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x1a4b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x1a4b20: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x1a4b20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a4b24: 0x4082a  slt         $at, $zero, $a0
    ctx->pc = 0x1a4b24u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1a4b28: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A4B28u;
    {
        const bool branch_taken_0x1a4b28 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a4b28) {
            ctx->pc = 0x1A4B34u;
            goto label_1a4b34;
        }
    }
    ctx->pc = 0x1A4B30u;
    // 0x1a4b30: 0x160a02d  daddu       $s4, $t3, $zero
    ctx->pc = 0x1a4b30u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
label_1a4b34:
    // 0x1a4b34: 0x90440000  lbu         $a0, 0x0($v0)
    ctx->pc = 0x1a4b34u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a4b38: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x1a4b38u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1a4b3c: 0x7d1021  addu        $v0, $v1, $sp
    ctx->pc = 0x1a4b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1a4b40: 0xac440080  sw          $a0, 0x80($v0)
    ctx->pc = 0x1a4b40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 4));
label_1a4b44:
    // 0x1a4b44: 0x175102a  slt         $v0, $t3, $s5
    ctx->pc = 0x1a4b44u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 11) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0x1a4b48: 0x1440ffe2  bnez        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1A4B48u;
    {
        const bool branch_taken_0x1a4b48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4B48u;
            // 0x1a4b4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4b48) {
            ctx->pc = 0x1A4AD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a4ad4;
        }
    }
    ctx->pc = 0x1A4B50u;
    // 0x1a4b50: 0x8fa90090  lw          $t1, 0x90($sp)
    ctx->pc = 0x1a4b50u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1a4b54: 0x141080  sll         $v0, $s4, 2
    ctx->pc = 0x1a4b54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x1a4b58: 0x8e680000  lw          $t0, 0x0($s3)
    ctx->pc = 0x1a4b58u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a4b5c: 0x5d2821  addu        $a1, $v0, $sp
    ctx->pc = 0x1a4b5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1a4b60: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x1a4b60u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1a4b64: 0x240b00ff  addiu       $t3, $zero, 0xFF
    ctx->pc = 0x1a4b64u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a4b68: 0x8f260000  lw          $a2, 0x0($t9)
    ctx->pc = 0x1a4b68u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x1a4b6c: 0x26a4ffff  addiu       $a0, $s5, -0x1
    ctx->pc = 0x1a4b6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x1a4b70: 0x8ca30090  lw          $v1, 0x90($a1)
    ctx->pc = 0x1a4b70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 144)));
    // 0x1a4b74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a4b74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4b78: 0x1694823  subu        $t1, $t3, $t1
    ctx->pc = 0x1a4b78u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 9)));
    // 0x1a4b7c: 0x1284023  subu        $t0, $t1, $t0
    ctx->pc = 0x1a4b7cu;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x1a4b80: 0x1073823  subu        $a3, $t0, $a3
    ctx->pc = 0x1a4b80u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x1a4b84: 0xe63023  subu        $a2, $a3, $a2
    ctx->pc = 0x1a4b84u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x1a4b88: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1a4b88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1a4b8c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A4B8Cu;
    {
        const bool branch_taken_0x1a4b8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4B8Cu;
            // 0x1a4b90: 0xaca30090  sw          $v1, 0x90($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4b8c) {
            ctx->pc = 0x1A4BC0u;
            goto label_1a4bc0;
        }
    }
    ctx->pc = 0x1A4B94u;
label_1a4b94:
    // 0x1a4b94: 0x7d2821  addu        $a1, $v1, $sp
    ctx->pc = 0x1a4b94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1a4b98: 0x8ca30090  lw          $v1, 0x90($a1)
    ctx->pc = 0x1a4b98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 144)));
    // 0x1a4b9c: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A4B9Cu;
    {
        const bool branch_taken_0x1a4b9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4B9Cu;
            // 0x1a4ba0: 0x24a60090  addiu       $a2, $a1, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4b9c) {
            ctx->pc = 0x1A4BBCu;
            goto label_1a4bbc;
        }
    }
    ctx->pc = 0x1A4BA4u;
    // 0x1a4ba4: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1a4ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1a4ba8: 0x24a50080  addiu       $a1, $a1, 0x80
    ctx->pc = 0x1a4ba8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 128));
    // 0x1a4bac: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x1a4bacu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1a4bb0: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x1a4bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1a4bb4: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1a4bb4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1a4bb8: 0xacc00004  sw          $zero, 0x4($a2)
    ctx->pc = 0x1a4bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 0));
label_1a4bbc:
    // 0x1a4bbc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a4bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1a4bc0:
    // 0x1a4bc0: 0x44182a  slt         $v1, $v0, $a0
    ctx->pc = 0x1a4bc0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1a4bc4: 0x1460fff3  bnez        $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A4BC4u;
    {
        const bool branch_taken_0x1a4bc4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4BC4u;
            // 0x1a4bc8: 0x21880  sll         $v1, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4bc4) {
            ctx->pc = 0x1A4B94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a4b94;
        }
    }
    ctx->pc = 0x1A4BCCu;
    // 0x1a4bcc: 0x8fa50090  lw          $a1, 0x90($sp)
    ctx->pc = 0x1a4bccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1a4bd0: 0x254a002c  addiu       $t2, $t2, 0x2C
    ctx->pc = 0x1a4bd0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 44));
    // 0x1a4bd4: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x1a4bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a4bd8: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x1a4bd8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x1a4bdc: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1a4bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1a4be0: 0x8f220000  lw          $v0, 0x0($t9)
    ctx->pc = 0x1a4be0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x1a4be4: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x1a4be4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1a4be8: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1a4be8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1a4bec: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1a4becu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1a4bf0: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1a4bf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1a4bf4: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1a4bf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1a4bf8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a4bf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a4bfc: 0xadc20000  sw          $v0, 0x0($t6)
    ctx->pc = 0x1a4bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 14), 0), GPR_U32(ctx, 2));
    // 0x1a4c00: 0x8fa50080  lw          $a1, 0x80($sp)
    ctx->pc = 0x1a4c00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1a4c04: 0x8f040000  lw          $a0, 0x0($t8)
    ctx->pc = 0x1a4c04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x1a4c08: 0x8de30000  lw          $v1, 0x0($t7)
    ctx->pc = 0x1a4c08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x1a4c0c: 0x8ec20000  lw          $v0, 0x0($s6)
    ctx->pc = 0x1a4c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1a4c10: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x1a4c10u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1a4c14: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1a4c14u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1a4c18: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1a4c18u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1a4c1c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1a4c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1a4c20: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1a4c20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1a4c24: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a4c24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a4c28: 0xada20000  sw          $v0, 0x0($t5)
    ctx->pc = 0x1a4c28u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 2));
label_1a4c2c:
    // 0x1a4c2c: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x1a4c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a4c30: 0x182102a  slt         $v0, $t4, $v0
    ctx->pc = 0x1a4c30u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a4c34: 0x1440ff30  bnez        $v0, . + 4 + (-0xD0 << 2)
    ctx->pc = 0x1A4C34u;
    {
        const bool branch_taken_0x1a4c34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4C38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4C34u;
            // 0x1a4c38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4c34) {
            ctx->pc = 0x1A48F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a48f8;
        }
    }
    ctx->pc = 0x1A4C3Cu;
    // 0x1a4c3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a4c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a4c40:
    // 0x1a4c40: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1a4c40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1a4c44: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1a4c44u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1a4c48: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1a4c48u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a4c4c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1a4c4cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a4c50: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a4c50u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a4c54: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a4c54u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a4c58: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a4c58u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a4c5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a4c5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a4c60: 0x3e00008  jr          $ra
    ctx->pc = 0x1A4C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A4C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4C60u;
            // 0x1a4c64: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A45D8u: goto label_1a45d8;
            case 0x1A45ECu: goto label_1a45ec;
            case 0x1A45F8u: goto label_1a45f8;
            case 0x1A4604u: goto label_1a4604;
            case 0x1A4620u: goto label_1a4620;
            case 0x1A4628u: goto label_1a4628;
            case 0x1A4630u: goto label_1a4630;
            case 0x1A463Cu: goto label_1a463c;
            case 0x1A4648u: goto label_1a4648;
            case 0x1A4650u: goto label_1a4650;
            case 0x1A4660u: goto label_1a4660;
            case 0x1A4690u: goto label_1a4690;
            case 0x1A46A8u: goto label_1a46a8;
            case 0x1A46C0u: goto label_1a46c0;
            case 0x1A46DCu: goto label_1a46dc;
            case 0x1A46F0u: goto label_1a46f0;
            case 0x1A4708u: goto label_1a4708;
            case 0x1A4710u: goto label_1a4710;
            case 0x1A4720u: goto label_1a4720;
            case 0x1A472Cu: goto label_1a472c;
            case 0x1A4738u: goto label_1a4738;
            case 0x1A4750u: goto label_1a4750;
            case 0x1A4768u: goto label_1a4768;
            case 0x1A4774u: goto label_1a4774;
            case 0x1A4798u: goto label_1a4798;
            case 0x1A47A0u: goto label_1a47a0;
            case 0x1A47D0u: goto label_1a47d0;
            case 0x1A47D8u: goto label_1a47d8;
            case 0x1A47E0u: goto label_1a47e0;
            case 0x1A47E4u: goto label_1a47e4;
            case 0x1A47FCu: goto label_1a47fc;
            case 0x1A480Cu: goto label_1a480c;
            case 0x1A481Cu: goto label_1a481c;
            case 0x1A4824u: goto label_1a4824;
            case 0x1A4828u: goto label_1a4828;
            case 0x1A4838u: goto label_1a4838;
            case 0x1A4860u: goto label_1a4860;
            case 0x1A489Cu: goto label_1a489c;
            case 0x1A48B4u: goto label_1a48b4;
            case 0x1A48C8u: goto label_1a48c8;
            case 0x1A48F8u: goto label_1a48f8;
            case 0x1A4900u: goto label_1a4900;
            case 0x1A4924u: goto label_1a4924;
            case 0x1A4948u: goto label_1a4948;
            case 0x1A4964u: goto label_1a4964;
            case 0x1A4990u: goto label_1a4990;
            case 0x1A49ACu: goto label_1a49ac;
            case 0x1A49D4u: goto label_1a49d4;
            case 0x1A49F0u: goto label_1a49f0;
            case 0x1A4A20u: goto label_1a4a20;
            case 0x1A4A3Cu: goto label_1a4a3c;
            case 0x1A4A68u: goto label_1a4a68;
            case 0x1A4A84u: goto label_1a4a84;
            case 0x1A4AA4u: goto label_1a4aa4;
            case 0x1A4AD4u: goto label_1a4ad4;
            case 0x1A4AE0u: goto label_1a4ae0;
            case 0x1A4B34u: goto label_1a4b34;
            case 0x1A4B44u: goto label_1a4b44;
            case 0x1A4B94u: goto label_1a4b94;
            case 0x1A4BBCu: goto label_1a4bbc;
            case 0x1A4BC0u: goto label_1a4bc0;
            case 0x1A4C2Cu: goto label_1a4c2c;
            case 0x1A4C40u: goto label_1a4c40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A4C68u;
    // 0x1a4c68: 0x0  nop
    ctx->pc = 0x1a4c68u;
    // NOP
    // 0x1a4c6c: 0x0  nop
    ctx->pc = 0x1a4c6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
