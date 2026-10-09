#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3880
// Address: 0x1a3880 - 0x1a3930
void sub_001A3880_0x1a3880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3880_0x1a3880");
#endif

    switch (ctx->pc) {
        case 0x1a389cu: goto label_1a389c;
        case 0x1a38bcu: goto label_1a38bc;
        case 0x1a38d4u: goto label_1a38d4;
        case 0x1a3908u: goto label_1a3908;
        default: break;
    }

    ctx->pc = 0x1a3880u;

    // 0x1a3880: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3884: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x1a3884u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3888: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a388c: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1a388cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3890: 0x80582d  daddu       $t3, $a0, $zero
    ctx->pc = 0x1a3890u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3894: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A3894u;
    SET_GPR_U32(ctx, 31, 0x1A389Cu);
    ctx->pc = 0x1A3898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3894u;
            // 0x1a3898: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A389Cu; }
        if (ctx->pc != 0x1A389Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A389Cu; }
        if (ctx->pc != 0x1A389Cu) { return; }
    }
    ctx->pc = 0x1A389Cu;
label_1a389c:
    // 0x1a389c: 0x4a082a  slt         $at, $v0, $t2
    ctx->pc = 0x1a389cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a38a0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A38A0u;
    {
        const bool branch_taken_0x1a38a0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A38A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A38A0u;
            // 0x1a38a4: 0x160202d  daddu       $a0, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a38a0) {
            ctx->pc = 0x1A38B0u;
            goto label_1a38b0;
        }
    }
    ctx->pc = 0x1A38A8u;
    // 0x1a38a8: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1A38A8u;
    {
        const bool branch_taken_0x1a38a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A38ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A38A8u;
            // 0x1a38ac: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a38a8) {
            ctx->pc = 0x1A3920u;
            goto label_1a3920;
        }
    }
    ctx->pc = 0x1A38B0u;
label_1a38b0:
    // 0x1a38b0: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a38b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a38b4: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A38B4u;
    SET_GPR_U32(ctx, 31, 0x1A38BCu);
    ctx->pc = 0x1A38B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A38B4u;
            // 0x1a38b8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A38BCu; }
        if (ctx->pc != 0x1A38BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A38BCu; }
        if (ctx->pc != 0x1A38BCu) { return; }
    }
    ctx->pc = 0x1A38BCu;
label_1a38bc:
    // 0x1a38bc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A38BCu;
    {
        const bool branch_taken_0x1a38bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A38C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A38BCu;
            // 0x1a38c0: 0x2445000c  addiu       $a1, $v0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a38bc) {
            ctx->pc = 0x1A38CCu;
            goto label_1a38cc;
        }
    }
    ctx->pc = 0x1A38C4u;
    // 0x1a38c4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1A38C4u;
    {
        const bool branch_taken_0x1a38c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A38C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A38C4u;
            // 0x1a38c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a38c4) {
            ctx->pc = 0x1A3920u;
            goto label_1a3920;
        }
    }
    ctx->pc = 0x1A38CCu;
label_1a38cc:
    // 0x1a38cc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A38CCu;
    {
        const bool branch_taken_0x1a38cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A38D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A38CCu;
            // 0x1a38d0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a38cc) {
            ctx->pc = 0x1A38E8u;
            goto label_1a38e8;
        }
    }
    ctx->pc = 0x1A38D4u;
label_1a38d4:
    // 0x1a38d4: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x1a38d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1a38d8: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a38d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a38dc: 0x8ca20008  lw          $v0, 0x8($a1)
    ctx->pc = 0x1a38dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1a38e0: 0x1034021  addu        $t0, $t0, $v1
    ctx->pc = 0x1a38e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1a38e4: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1a38e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1a38e8:
    // 0x1a38e8: 0x8a102a  slt         $v0, $a0, $t2
    ctx->pc = 0x1a38e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a38ec: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A38ECu;
    {
        const bool branch_taken_0x1a38ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a38ec) {
            ctx->pc = 0x1A38D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a38d4;
        }
    }
    ctx->pc = 0x1A38F4u;
    // 0x1a38f4: 0x160202d  daddu       $a0, $t3, $zero
    ctx->pc = 0x1a38f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a38f8: 0x3c050006  lui         $a1, 0x6
    ctx->pc = 0x1a38f8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)6 << 16));
    // 0x1a38fc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a38fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3900: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3900u;
    SET_GPR_U32(ctx, 31, 0x1A3908u);
    ctx->pc = 0x1A3904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3900u;
            // 0x1a3904: 0x1094021  addu        $t0, $t0, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3908u; }
        if (ctx->pc != 0x1A3908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3908u; }
        if (ctx->pc != 0x1A3908u) { return; }
    }
    ctx->pc = 0x1A3908u;
label_1a3908:
    // 0x1a3908: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3908u;
    {
        const bool branch_taken_0x1a3908 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A390Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3908u;
            // 0x1a390c: 0x81880  sll         $v1, $t0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3908) {
            ctx->pc = 0x1A3918u;
            goto label_1a3918;
        }
    }
    ctx->pc = 0x1A3910u;
    // 0x1a3910: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3910u;
    {
        const bool branch_taken_0x1a3910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3910u;
            // 0x1a3914: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3910) {
            ctx->pc = 0x1A3920u;
            goto label_1a3920;
        }
    }
    ctx->pc = 0x1A3918u;
label_1a3918:
    // 0x1a3918: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a3918u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a391c: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1a391cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
label_1a3920:
    // 0x1a3920: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3920u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3924: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3924u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3924u;
            // 0x1a3928: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A389Cu: goto label_1a389c;
            case 0x1A38B0u: goto label_1a38b0;
            case 0x1A38BCu: goto label_1a38bc;
            case 0x1A38CCu: goto label_1a38cc;
            case 0x1A38D4u: goto label_1a38d4;
            case 0x1A38E8u: goto label_1a38e8;
            case 0x1A3908u: goto label_1a3908;
            case 0x1A3918u: goto label_1a3918;
            case 0x1A3920u: goto label_1a3920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A392Cu;
    // 0x1a392c: 0x0  nop
    ctx->pc = 0x1a392cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
