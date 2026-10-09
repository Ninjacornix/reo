#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122948
// Address: 0x122948 - 0x122ae4
void sub_00122948_0x122948(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122948_0x122948");
#endif

    switch (ctx->pc) {
        case 0x122978u: goto label_122978;
        case 0x1229a8u: goto label_1229a8;
        case 0x1229c4u: goto label_1229c4;
        case 0x1229d8u: goto label_1229d8;
        case 0x1229f4u: goto label_1229f4;
        case 0x122a04u: goto label_122a04;
        case 0x122a1cu: goto label_122a1c;
        case 0x122a40u: goto label_122a40;
        case 0x122a58u: goto label_122a58;
        case 0x122a6cu: goto label_122a6c;
        case 0x122a88u: goto label_122a88;
        case 0x122a98u: goto label_122a98;
        case 0x122ab0u: goto label_122ab0;
        default: break;
    }

    ctx->pc = 0x122948u;

    // 0x122948: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x122948u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12294c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12294cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x122950: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x122950u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122954: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x122954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x122958: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x122958u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12295c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12295cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x122960: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x122960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x122964: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x122964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x122968: 0x82220002  lb          $v0, 0x2($s1)
    ctx->pc = 0x122968u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x12296c: 0x18400009  blez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12296Cu;
    {
        const bool branch_taken_0x12296c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x122970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12296Cu;
            // 0x122970: 0x92240002  lbu         $a0, 0x2($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12296c) {
            ctx->pc = 0x122994u;
            goto label_122994;
        }
    }
    ctx->pc = 0x122974u;
    // 0x122974: 0x26230014  addiu       $v1, $s1, 0x14
    ctx->pc = 0x122974u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
label_122978:
    // 0x122978: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x122978u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x12297c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x12297cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x122980: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x122980u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x122984: 0x82220002  lb          $v0, 0x2($s1)
    ctx->pc = 0x122984u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x122988: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x122988u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12298c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x12298Cu;
    {
        const bool branch_taken_0x12298c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x122990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12298Cu;
            // 0x122990: 0x92240002  lbu         $a0, 0x2($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12298c) {
            ctx->pc = 0x122978u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122978;
        }
    }
    ctx->pc = 0x122994u;
label_122994:
    // 0x122994: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x122994u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x122998: 0xae20002c  sw          $zero, 0x2C($s1)
    ctx->pc = 0x122998u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 0));
    // 0x12299c: 0x18400024  blez        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x12299Cu;
    {
        const bool branch_taken_0x12299c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1229A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12299Cu;
            // 0x1229a0: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12299c) {
            ctx->pc = 0x122A30u;
            goto label_122a30;
        }
    }
    ctx->pc = 0x1229A4u;
    // 0x1229a4: 0x26330004  addiu       $s3, $s1, 0x4
    ctx->pc = 0x1229a4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_1229a8:
    // 0x1229a8: 0x8e700000  lw          $s0, 0x0($s3)
    ctx->pc = 0x1229a8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1229ac: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x1229acu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1229b0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1229b0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1229b4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1229b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1229b8: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x1229b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x1229bc: 0x40f809  jalr        $v0
    ctx->pc = 0x1229BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1229C4u);
        ctx->pc = 0x1229C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1229BCu;
            // 0x1229c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1229C4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1229C4u; }
            if (ctx->pc != 0x1229C4u) { return; }
        }
        }
    }
    ctx->pc = 0x1229C4u;
label_1229c4:
    // 0x1229c4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1229c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1229c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1229c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1229cc: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1229ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1229d0: 0x40f809  jalr        $v0
    ctx->pc = 0x1229D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1229D8u);
        ctx->pc = 0x1229D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1229D0u;
            // 0x1229d4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1229D8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1229D8u; }
            if (ctx->pc != 0x1229D8u) { return; }
        }
        }
    }
    ctx->pc = 0x1229D8u;
label_1229d8:
    // 0x1229d8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1229d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1229dc: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1229dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1229e0: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x1229e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1229e4: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x1229e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1229e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1229e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1229ec: 0x40f809  jalr        $v0
    ctx->pc = 0x1229ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1229F4u);
        ctx->pc = 0x1229F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1229ECu;
            // 0x1229f0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1229F4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1229F4u; }
            if (ctx->pc != 0x1229F4u) { return; }
        }
        }
    }
    ctx->pc = 0x1229F4u;
label_1229f4:
    // 0x1229f4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1229f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1229f8: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1229f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1229fc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1229FCu;
    SET_GPR_U32(ctx, 31, 0x122A04u);
    ctx->pc = 0x122A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1229FCu;
            // 0x122a00: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122A04u; }
        if (ctx->pc != 0x122A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122A04u; }
        if (ctx->pc != 0x122A04u) { return; }
    }
    ctx->pc = 0x122A04u;
label_122a04:
    // 0x122a04: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x122a04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x122a08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x122a08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122a0c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x122a0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122a10: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x122a10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x122a14: 0x40f809  jalr        $v0
    ctx->pc = 0x122A14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122A1Cu);
        ctx->pc = 0x122A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122A14u;
            // 0x122a18: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122A1Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122A1Cu; }
            if (ctx->pc != 0x122A1Cu) { return; }
        }
        }
    }
    ctx->pc = 0x122A1Cu;
label_122a1c:
    // 0x122a1c: 0x82220002  lb          $v0, 0x2($s1)
    ctx->pc = 0x122a1cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x122a20: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x122a20u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x122a24: 0x1440ffe0  bnez        $v0, . + 4 + (-0x20 << 2)
    ctx->pc = 0x122A24u;
    {
        const bool branch_taken_0x122a24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x122A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122A24u;
            // 0x122a28: 0x92240002  lbu         $a0, 0x2($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122a24) {
            ctx->pc = 0x1229A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1229a8;
        }
    }
    ctx->pc = 0x122A2Cu;
    // 0x122a2c: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x122a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
label_122a30:
    // 0x122a30: 0x18400023  blez        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x122A30u;
    {
        const bool branch_taken_0x122a30 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x122A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122A30u;
            // 0x122a34: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122a30) {
            ctx->pc = 0x122AC0u;
            goto label_122ac0;
        }
    }
    ctx->pc = 0x122A38u;
    // 0x122a38: 0x2633000c  addiu       $s3, $s1, 0xC
    ctx->pc = 0x122a38u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x122a3c: 0x8e700000  lw          $s0, 0x0($s3)
    ctx->pc = 0x122a3cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_122a40:
    // 0x122a40: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x122a40u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x122a44: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x122a44u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x122a48: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x122a48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x122a4c: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x122a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x122a50: 0x40f809  jalr        $v0
    ctx->pc = 0x122A50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122A58u);
        ctx->pc = 0x122A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122A50u;
            // 0x122a54: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122A58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122A58u; }
            if (ctx->pc != 0x122A58u) { return; }
        }
        }
    }
    ctx->pc = 0x122A58u;
label_122a58:
    // 0x122a58: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x122a58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x122a5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x122a5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122a60: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x122a60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x122a64: 0x40f809  jalr        $v0
    ctx->pc = 0x122A64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122A6Cu);
        ctx->pc = 0x122A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122A64u;
            // 0x122a68: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122A6Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122A6Cu; }
            if (ctx->pc != 0x122A6Cu) { return; }
        }
        }
    }
    ctx->pc = 0x122A6Cu;
label_122a6c:
    // 0x122a6c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x122a6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x122a70: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x122a70u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122a74: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x122a74u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122a78: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x122a78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x122a7c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x122a7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122a80: 0x40f809  jalr        $v0
    ctx->pc = 0x122A80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122A88u);
        ctx->pc = 0x122A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122A80u;
            // 0x122a84: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122A88u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122A88u; }
            if (ctx->pc != 0x122A88u) { return; }
        }
        }
    }
    ctx->pc = 0x122A88u;
label_122a88:
    // 0x122a88: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x122a88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122a8c: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x122a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122a90: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x122A90u;
    SET_GPR_U32(ctx, 31, 0x122A98u);
    ctx->pc = 0x122A94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122A90u;
            // 0x122a94: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122A98u; }
        if (ctx->pc != 0x122A98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122A98u; }
        if (ctx->pc != 0x122A98u) { return; }
    }
    ctx->pc = 0x122A98u;
label_122a98:
    // 0x122a98: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x122a98u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x122a9c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x122a9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122aa0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x122aa0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122aa4: 0x8cc3001c  lw          $v1, 0x1C($a2)
    ctx->pc = 0x122aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 28)));
    // 0x122aa8: 0x60f809  jalr        $v1
    ctx->pc = 0x122AA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x122AB0u);
        ctx->pc = 0x122AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122AA8u;
            // 0x122aac: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122AB0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122AB0u; }
            if (ctx->pc != 0x122AB0u) { return; }
        }
        }
    }
    ctx->pc = 0x122AB0u;
label_122ab0:
    // 0x122ab0: 0x82220002  lb          $v0, 0x2($s1)
    ctx->pc = 0x122ab0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x122ab4: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x122ab4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x122ab8: 0x5440ffe1  bnel        $v0, $zero, . + 4 + (-0x1F << 2)
    ctx->pc = 0x122AB8u;
    {
        const bool branch_taken_0x122ab8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x122ab8) {
            ctx->pc = 0x122ABCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122AB8u;
            // 0x122abc: 0x8e700000  lw          $s0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122A40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122a40;
        }
    }
    ctx->pc = 0x122AC0u;
label_122ac0:
    // 0x122ac0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x122ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x122ac4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x122ac4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x122ac8: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x122ac8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x122acc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x122accu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x122ad0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x122ad0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x122ad4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x122ad4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x122ad8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x122ad8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x122adc: 0x3e00008  jr          $ra
    ctx->pc = 0x122ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122ADCu;
            // 0x122ae0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122978u: goto label_122978;
            case 0x122994u: goto label_122994;
            case 0x1229A8u: goto label_1229a8;
            case 0x1229C4u: goto label_1229c4;
            case 0x1229D8u: goto label_1229d8;
            case 0x1229F4u: goto label_1229f4;
            case 0x122A04u: goto label_122a04;
            case 0x122A1Cu: goto label_122a1c;
            case 0x122A30u: goto label_122a30;
            case 0x122A40u: goto label_122a40;
            case 0x122A58u: goto label_122a58;
            case 0x122A6Cu: goto label_122a6c;
            case 0x122A88u: goto label_122a88;
            case 0x122A98u: goto label_122a98;
            case 0x122AB0u: goto label_122ab0;
            case 0x122AC0u: goto label_122ac0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122AE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
