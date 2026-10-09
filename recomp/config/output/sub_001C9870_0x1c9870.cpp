#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C9870
// Address: 0x1c9870 - 0x1c9950
void sub_001C9870_0x1c9870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C9870_0x1c9870");
#endif

    switch (ctx->pc) {
        case 0x1c98e8u: goto label_1c98e8;
        case 0x1c9924u: goto label_1c9924;
        default: break;
    }

    ctx->pc = 0x1c9870u;

    // 0x1c9870: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1c9870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1c9874: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1c9874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1c9878: 0x7fb70080  sq          $s7, 0x80($sp)
    ctx->pc = 0x1c9878u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 23));
    // 0x1c987c: 0x7fb60070  sq          $s6, 0x70($sp)
    ctx->pc = 0x1c987cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 22));
    // 0x1c9880: 0x160b82d  daddu       $s7, $t3, $zero
    ctx->pc = 0x1c9880u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9884: 0x7fb50060  sq          $s5, 0x60($sp)
    ctx->pc = 0x1c9884u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 21));
    // 0x1c9888: 0x140b02d  daddu       $s6, $t2, $zero
    ctx->pc = 0x1c9888u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c988c: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x1c988cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x1c9890: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1c9890u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9894: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x1c9894u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x1c9898: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1c9898u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c989c: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1c989cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1c98a0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1c98a0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98a4: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1c98a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1c98a8: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1c98a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98ac: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1c98acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1c98b0: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x1c98b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98b4: 0x81620000  lb          $v0, 0x0($t3)
    ctx->pc = 0x1c98b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x1c98b8: 0x120802d  daddu       $s0, $t1, $zero
    ctx->pc = 0x1c98b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98bc: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x1c98bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x1c98c0: 0x84e80000  lh          $t0, 0x0($a3)
    ctx->pc = 0x1c98c0u;
    SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1c98c4: 0x80890000  lb          $t1, 0x0($a0)
    ctx->pc = 0x1c98c4u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c98c8: 0x80aa0000  lb          $t2, 0x0($a1)
    ctx->pc = 0x1c98c8u;
    SET_GPR_S32(ctx, 10, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c98cc: 0x80cb0000  lb          $t3, 0x0($a2)
    ctx->pc = 0x1c98ccu;
    SET_GPR_S32(ctx, 11, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1c98d0: 0x3c070025  lui         $a3, 0x25
    ctx->pc = 0x1c98d0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)37 << 16));
    // 0x1c98d4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c98d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c98d8: 0x24e72e00  addiu       $a3, $a3, 0x2E00
    ctx->pc = 0x1c98d8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 11776));
    // 0x1c98dc: 0x2405001b  addiu       $a1, $zero, 0x1B
    ctx->pc = 0x1c98dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x1c98e0: 0xc072420  jal         func_1C9080
    ctx->pc = 0x1C98E0u;
    SET_GPR_U32(ctx, 31, 0x1C98E8u);
    ctx->pc = 0x1C98E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C98E0u;
            // 0x1c98e4: 0x80302d  daddu       $a2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C9080u;
    if (runtime->hasFunction(0x1C9080u)) {
        auto targetFn = runtime->lookupFunction(0x1C9080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C98E8u; }
        if (ctx->pc != 0x1C98E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9080_0x1c9080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C98E8u; }
        if (ctx->pc != 0x1C98E8u) { return; }
    }
    ctx->pc = 0x1C98E8u;
label_1c98e8:
    // 0x1c98e8: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1c98e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1c98ec: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c98ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c98f0: 0x24425fd8  addiu       $v0, $v0, 0x5FD8
    ctx->pc = 0x1c98f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24536));
    // 0x1c98f4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1c98f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98f8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1c98f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98fc: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1c98fcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9900: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1c9900u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9904: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1c9904u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9908: 0x2c0502d  daddu       $t2, $s6, $zero
    ctx->pc = 0x1c9908u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c990c: 0x2e0582d  daddu       $t3, $s7, $zero
    ctx->pc = 0x1c990cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9910: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c9910u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c9914: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c9914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c9918: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c9918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c991c: 0x40f809  jalr        $v0
    ctx->pc = 0x1C991Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1C9924u);
        ctx->pc = 0x1C9920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C991Cu;
            // 0x1c9920: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1C9924u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1C9924u; }
            if (ctx->pc != 0x1C9924u) { return; }
        }
        }
    }
    ctx->pc = 0x1C9924u;
label_1c9924:
    // 0x1c9924: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1c9924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1c9928: 0x7bb70080  lq          $s7, 0x80($sp)
    ctx->pc = 0x1c9928u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1c992c: 0x7bb60070  lq          $s6, 0x70($sp)
    ctx->pc = 0x1c992cu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1c9930: 0x7bb50060  lq          $s5, 0x60($sp)
    ctx->pc = 0x1c9930u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1c9934: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x1c9934u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c9938: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x1c9938u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c993c: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1c993cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c9940: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1c9940u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c9944: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1c9944u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c9948: 0x3e00008  jr          $ra
    ctx->pc = 0x1C9948u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C994Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9948u;
            // 0x1c994c: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C9950u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
