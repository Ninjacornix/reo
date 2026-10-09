#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B35B0
// Address: 0x1b35b0 - 0x1b3674
void sub_001B35B0_0x1b35b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B35B0_0x1b35b0");
#endif

    switch (ctx->pc) {
        case 0x1b361cu: goto label_1b361c;
        case 0x1b3624u: goto label_1b3624;
        case 0x1b3630u: goto label_1b3630;
        case 0x1b363cu: goto label_1b363c;
        case 0x1b3648u: goto label_1b3648;
        case 0x1b3654u: goto label_1b3654;
        case 0x1b365cu: goto label_1b365c;
        default: break;
    }

    ctx->pc = 0x1b35b0u;

    // 0x1b35b0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1b35b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1b35b4: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1b35b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b35b8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b35b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b35bc: 0x28620008  slti        $v0, $v1, 0x8
    ctx->pc = 0x1b35bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b35c0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b35c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b35c4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b35c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b35c8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b35c8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b35cc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b35ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b35d0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1b35d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b35d4: 0xafa70070  sw          $a3, 0x70($sp)
    ctx->pc = 0x1b35d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 7));
    // 0x1b35d8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1b35d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b35dc: 0xffa80080  sd          $t0, 0x80($sp)
    ctx->pc = 0x1b35dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 8));
    // 0x1b35e0: 0xffa90088  sd          $t1, 0x88($sp)
    ctx->pc = 0x1b35e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 9));
    // 0x1b35e4: 0xffaa0090  sd          $t2, 0x90($sp)
    ctx->pc = 0x1b35e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 10));
    // 0x1b35e8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B35E8u;
    {
        const bool branch_taken_0x1b35e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B35ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B35E8u;
            // 0x1b35ec: 0xffab0098  sd          $t3, 0x98($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b35e8) {
            ctx->pc = 0x1B35F8u;
            goto label_1b35f8;
        }
    }
    ctx->pc = 0x1B35F0u;
    // 0x1b35f0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B35F0u;
    {
        const bool branch_taken_0x1b35f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B35F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B35F0u;
            // 0x1b35f4: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b35f0) {
            ctx->pc = 0x1B3604u;
            goto label_1b3604;
        }
    }
    ctx->pc = 0x1B35F8u;
label_1b35f8:
    // 0x1b35f8: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1b35f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b35fc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1b35fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b3600: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1b3600u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1b3604:
    // 0x1b3604: 0x8fa50070  lw          $a1, 0x70($sp)
    ctx->pc = 0x1b3604u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1b3608: 0x27a200a0  addiu       $v0, $sp, 0xA0
    ctx->pc = 0x1b3608u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1b360c: 0x3c04002c  lui         $a0, 0x2C
    ctx->pc = 0x1b360cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)44 << 16));
    // 0x1b3610: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x1b3610u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b3614: 0xc043e20  jal         func_10F880
    ctx->pc = 0x1B3614u;
    SET_GPR_U32(ctx, 31, 0x1B361Cu);
    ctx->pc = 0x1B3618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3614u;
            // 0x1b3618: 0x248491e0  addiu       $a0, $a0, -0x6E20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B361Cu; }
        if (ctx->pc != 0x1B361Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B361Cu; }
        if (ctx->pc != 0x1B361Cu) { return; }
    }
    ctx->pc = 0x1B361Cu;
label_1b361c:
    // 0x1b361c: 0xc06ce30  jal         func_1B38C0
    ctx->pc = 0x1B361Cu;
    SET_GPR_U32(ctx, 31, 0x1B3624u);
    ctx->pc = 0x1B3620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B361Cu;
            // 0x1b3620: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B38C0u;
    if (runtime->hasFunction(0x1B38C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B38C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3624u; }
        if (ctx->pc != 0x1B3624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B38C0_0x1b38c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3624u; }
        if (ctx->pc != 0x1B3624u) { return; }
    }
    ctx->pc = 0x1B3624u;
label_1b3624:
    // 0x1b3624: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1b3624u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b3628: 0xc06cec4  jal         func_1B3B10
    ctx->pc = 0x1B3628u;
    SET_GPR_U32(ctx, 31, 0x1B3630u);
    ctx->pc = 0x1B362Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3628u;
            // 0x1b362c: 0x2405000c  addiu       $a1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3B10u;
    if (runtime->hasFunction(0x1B3B10u)) {
        auto targetFn = runtime->lookupFunction(0x1B3B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3630u; }
        if (ctx->pc != 0x1B3630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3B10_0x1b3b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3630u; }
        if (ctx->pc != 0x1B3630u) { return; }
    }
    ctx->pc = 0x1B3630u;
label_1b3630:
    // 0x1b3630: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b3630u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3634: 0xc06ce24  jal         func_1B3890
    ctx->pc = 0x1B3634u;
    SET_GPR_U32(ctx, 31, 0x1B363Cu);
    ctx->pc = 0x1B3638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3634u;
            // 0x1b3638: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3890u;
    if (runtime->hasFunction(0x1B3890u)) {
        auto targetFn = runtime->lookupFunction(0x1B3890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B363Cu; }
        if (ctx->pc != 0x1B363Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3890_0x1b3890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B363Cu; }
        if (ctx->pc != 0x1B363Cu) { return; }
    }
    ctx->pc = 0x1B363Cu;
label_1b363c:
    // 0x1b363c: 0x3c04002c  lui         $a0, 0x2C
    ctx->pc = 0x1b363cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)44 << 16));
    // 0x1b3640: 0xc06ce48  jal         func_1B3920
    ctx->pc = 0x1B3640u;
    SET_GPR_U32(ctx, 31, 0x1B3648u);
    ctx->pc = 0x1B3644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3640u;
            // 0x1b3644: 0x248491e0  addiu       $a0, $a0, -0x6E20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3920u;
    if (runtime->hasFunction(0x1B3920u)) {
        auto targetFn = runtime->lookupFunction(0x1B3920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3648u; }
        if (ctx->pc != 0x1B3648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3920_0x1b3920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3648u; }
        if (ctx->pc != 0x1B3648u) { return; }
    }
    ctx->pc = 0x1B3648u;
label_1b3648:
    // 0x1b3648: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1b3648u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b364c: 0xc06cec4  jal         func_1B3B10
    ctx->pc = 0x1B364Cu;
    SET_GPR_U32(ctx, 31, 0x1B3654u);
    ctx->pc = 0x1B3650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B364Cu;
            // 0x1b3650: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B3B10u;
    if (runtime->hasFunction(0x1B3B10u)) {
        auto targetFn = runtime->lookupFunction(0x1B3B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3654u; }
        if (ctx->pc != 0x1B3654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3B10_0x1b3b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3654u; }
        if (ctx->pc != 0x1B3654u) { return; }
    }
    ctx->pc = 0x1B3654u;
label_1b3654:
    // 0x1b3654: 0xc06ce30  jal         func_1B38C0
    ctx->pc = 0x1B3654u;
    SET_GPR_U32(ctx, 31, 0x1B365Cu);
    ctx->pc = 0x1B3658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3654u;
            // 0x1b3658: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B38C0u;
    if (runtime->hasFunction(0x1B38C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B38C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B365Cu; }
        if (ctx->pc != 0x1B365Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B38C0_0x1b38c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B365Cu; }
        if (ctx->pc != 0x1B365Cu) { return; }
    }
    ctx->pc = 0x1B365Cu;
label_1b365c:
    // 0x1b365c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b365cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b3660: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b3660u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b3664: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b3664u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b3668: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b3668u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b366c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B366Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B3670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B366Cu;
            // 0x1b3670: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B35F8u: goto label_1b35f8;
            case 0x1B3604u: goto label_1b3604;
            case 0x1B361Cu: goto label_1b361c;
            case 0x1B3624u: goto label_1b3624;
            case 0x1B3630u: goto label_1b3630;
            case 0x1B363Cu: goto label_1b363c;
            case 0x1B3648u: goto label_1b3648;
            case 0x1B3654u: goto label_1b3654;
            case 0x1B365Cu: goto label_1b365c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3674u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
