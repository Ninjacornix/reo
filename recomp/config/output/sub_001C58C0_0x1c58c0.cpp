#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C58C0
// Address: 0x1c58c0 - 0x1c5970
void sub_001C58C0_0x1c58c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C58C0_0x1c58c0");
#endif

    switch (ctx->pc) {
        case 0x1c58e4u: goto label_1c58e4;
        case 0x1c58f0u: goto label_1c58f0;
        case 0x1c5908u: goto label_1c5908;
        case 0x1c5918u: goto label_1c5918;
        case 0x1c5920u: goto label_1c5920;
        case 0x1c593cu: goto label_1c593c;
        case 0x1c594cu: goto label_1c594c;
        default: break;
    }

    ctx->pc = 0x1c58c0u;

    // 0x1c58c0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1c58c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1c58c4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1c58c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1c58c8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c58c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c58cc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c58ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c58d0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1c58d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c58d4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c58d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c58d8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1c58d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c58dc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c58dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c58e0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1c58e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_1c58e4:
    // 0x1c58e4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c58e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c58e8: 0xc04a432  jal         func_1290C8
    ctx->pc = 0x1C58E8u;
    SET_GPR_U32(ctx, 31, 0x1C58F0u);
    ctx->pc = 0x1C58ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C58E8u;
            // 0x1c58ec: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1290C8u;
    if (runtime->hasFunction(0x1290C8u)) {
        auto targetFn = runtime->lookupFunction(0x1290C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C58F0u; }
        if (ctx->pc != 0x1C58F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001290C8_0x1290c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C58F0u; }
        if (ctx->pc != 0x1C58F0u) { return; }
    }
    ctx->pc = 0x1C58F0u;
label_1c58f0:
    // 0x1c58f0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c58f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c58f4: 0x0  nop
    ctx->pc = 0x1c58f4u;
    // NOP
    // 0x1c58f8: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C58F8u;
    {
        const bool branch_taken_0x1c58f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c58f8) {
            ctx->pc = 0x1C58E4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c58e4;
        }
    }
    ctx->pc = 0x1C5900u;
    // 0x1c5900: 0xc04a702  jal         func_129C08
    ctx->pc = 0x1C5900u;
    SET_GPR_U32(ctx, 31, 0x1C5908u);
    ctx->pc = 0x1C5904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5900u;
            // 0x1c5904: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129C08u;
    if (runtime->hasFunction(0x129C08u)) {
        auto targetFn = runtime->lookupFunction(0x129C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5908u; }
        if (ctx->pc != 0x1C5908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129C08_0x129c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5908u; }
        if (ctx->pc != 0x1C5908u) { return; }
    }
    ctx->pc = 0x1C5908u;
label_1c5908:
    // 0x1c5908: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c5908u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c590c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c590cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5910: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x1C5910u;
    SET_GPR_U32(ctx, 31, 0x1C5918u);
    ctx->pc = 0x1C5914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5910u;
            // 0x1c5914: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5918u; }
        if (ctx->pc != 0x1C5918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5918u; }
        if (ctx->pc != 0x1C5918u) { return; }
    }
    ctx->pc = 0x1C5918u;
label_1c5918:
    // 0x1c5918: 0xc04a752  jal         func_129D48
    ctx->pc = 0x1C5918u;
    SET_GPR_U32(ctx, 31, 0x1C5920u);
    ctx->pc = 0x1C591Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5918u;
            // 0x1c591c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5920u; }
        if (ctx->pc != 0x1C5920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5920u; }
        if (ctx->pc != 0x1C5920u) { return; }
    }
    ctx->pc = 0x1C5920u;
label_1c5920:
    // 0x1c5920: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c5920u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c5924: 0x0  nop
    ctx->pc = 0x1c5924u;
    // NOP
    // 0x1c5928: 0x0  nop
    ctx->pc = 0x1c5928u;
    // NOP
    // 0x1c592c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C592Cu;
    {
        const bool branch_taken_0x1c592c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c592c) {
            ctx->pc = 0x1C5918u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5918;
        }
    }
    ctx->pc = 0x1C5934u;
    // 0x1c5934: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1C5934u;
    SET_GPR_U32(ctx, 31, 0x1C593Cu);
    ctx->pc = 0x1C5938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5934u;
            // 0x1c5938: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C593Cu; }
        if (ctx->pc != 0x1C593Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C593Cu; }
        if (ctx->pc != 0x1C593Cu) { return; }
    }
    ctx->pc = 0x1C593Cu;
label_1c593c:
    // 0x1c593c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c593cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c5940: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c5940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5944: 0xc0704b0  jal         func_1C12C0
    ctx->pc = 0x1C5944u;
    SET_GPR_U32(ctx, 31, 0x1C594Cu);
    ctx->pc = 0x1C5948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5944u;
            // 0x1c5948: 0xae620040  sw          $v0, 0x40($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 64), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C12C0u;
    if (runtime->hasFunction(0x1C12C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C12C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C594Cu; }
        if (ctx->pc != 0x1C594Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C12C0_0x1c12c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C594Cu; }
        if (ctx->pc != 0x1C594Cu) { return; }
    }
    ctx->pc = 0x1C594Cu;
label_1c594c:
    // 0x1c594c: 0xae620028  sw          $v0, 0x28($s3)
    ctx->pc = 0x1c594cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 40), GPR_U32(ctx, 2));
    // 0x1c5950: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1c5950u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c5954: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c5954u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c5958: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c5958u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c595c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c595cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5960: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5960u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5964: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5964u;
            // 0x1c5968: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C58E4u: goto label_1c58e4;
            case 0x1C58F0u: goto label_1c58f0;
            case 0x1C5908u: goto label_1c5908;
            case 0x1C5918u: goto label_1c5918;
            case 0x1C5920u: goto label_1c5920;
            case 0x1C593Cu: goto label_1c593c;
            case 0x1C594Cu: goto label_1c594c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C596Cu;
    // 0x1c596c: 0x0  nop
    ctx->pc = 0x1c596cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
