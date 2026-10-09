#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7A70
// Address: 0x1b7a70 - 0x1b7af4
void sub_001B7A70_0x1b7a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7A70_0x1b7a70");
#endif

    switch (ctx->pc) {
        case 0x1b7ad4u: goto label_1b7ad4;
        case 0x1b7ae4u: goto label_1b7ae4;
        default: break;
    }

    ctx->pc = 0x1b7a70u;

    // 0x1b7a70: 0x27bdfd90  addiu       $sp, $sp, -0x270
    ctx->pc = 0x1b7a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966672));
    // 0x1b7a74: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b7a74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b7a78: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b7a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b7a7c: 0x28620008  slti        $v0, $v1, 0x8
    ctx->pc = 0x1b7a7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b7a80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7a80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7a84: 0xafa40228  sw          $a0, 0x228($sp)
    ctx->pc = 0x1b7a84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 552), GPR_U32(ctx, 4));
    // 0x1b7a88: 0xffa50238  sd          $a1, 0x238($sp)
    ctx->pc = 0x1b7a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 568), GPR_U64(ctx, 5));
    // 0x1b7a8c: 0xffa60240  sd          $a2, 0x240($sp)
    ctx->pc = 0x1b7a8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 576), GPR_U64(ctx, 6));
    // 0x1b7a90: 0xffa70248  sd          $a3, 0x248($sp)
    ctx->pc = 0x1b7a90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 584), GPR_U64(ctx, 7));
    // 0x1b7a94: 0xffa80250  sd          $t0, 0x250($sp)
    ctx->pc = 0x1b7a94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 592), GPR_U64(ctx, 8));
    // 0x1b7a98: 0xffa90258  sd          $t1, 0x258($sp)
    ctx->pc = 0x1b7a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 600), GPR_U64(ctx, 9));
    // 0x1b7a9c: 0xffaa0260  sd          $t2, 0x260($sp)
    ctx->pc = 0x1b7a9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 10));
    // 0x1b7aa0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7AA0u;
    {
        const bool branch_taken_0x1b7aa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7AA0u;
            // 0x1b7aa4: 0xffab0268  sd          $t3, 0x268($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7aa0) {
            ctx->pc = 0x1B7AB0u;
            goto label_1b7ab0;
        }
    }
    ctx->pc = 0x1B7AA8u;
    // 0x1b7aa8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B7AA8u;
    {
        const bool branch_taken_0x1b7aa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7AA8u;
            // 0x1b7aac: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7aa8) {
            ctx->pc = 0x1B7ABCu;
            goto label_1b7abc;
        }
    }
    ctx->pc = 0x1B7AB0u;
label_1b7ab0:
    // 0x1b7ab0: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1b7ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b7ab4: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1b7ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7ab8: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1b7ab8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1b7abc:
    // 0x1b7abc: 0x8fa50228  lw          $a1, 0x228($sp)
    ctx->pc = 0x1b7abcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 552)));
    // 0x1b7ac0: 0x27a20270  addiu       $v0, $sp, 0x270
    ctx->pc = 0x1b7ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
    // 0x1b7ac4: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x1b7ac4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b7ac8: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x1b7ac8u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7acc: 0xc043e20  jal         func_10F880
    ctx->pc = 0x1B7ACCu;
    SET_GPR_U32(ctx, 31, 0x1B7AD4u);
    ctx->pc = 0x1B7AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7ACCu;
            // 0x1b7ad0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7AD4u; }
        if (ctx->pc != 0x1B7AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7AD4u; }
        if (ctx->pc != 0x1B7AD4u) { return; }
    }
    ctx->pc = 0x1B7AD4u;
label_1b7ad4:
    // 0x1b7ad4: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1b7ad4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1b7ad8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1b7ad8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b7adc: 0xc06de28  jal         func_1B78A0
    ctx->pc = 0x1B7ADCu;
    SET_GPR_U32(ctx, 31, 0x1B7AE4u);
    ctx->pc = 0x1B7AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7ADCu;
            // 0x1b7ae0: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B78A0u;
    if (runtime->hasFunction(0x1B78A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B78A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7AE4u; }
        if (ctx->pc != 0x1B7AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B78A0_0x1b78a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7AE4u; }
        if (ctx->pc != 0x1B7AE4u) { return; }
    }
    ctx->pc = 0x1B7AE4u;
label_1b7ae4:
    // 0x1b7ae4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b7ae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7ae8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7ae8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7aec: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7AECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7AECu;
            // 0x1b7af0: 0x27bd0270  addiu       $sp, $sp, 0x270 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7AB0u: goto label_1b7ab0;
            case 0x1B7ABCu: goto label_1b7abc;
            case 0x1B7AD4u: goto label_1b7ad4;
            case 0x1B7AE4u: goto label_1b7ae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7AF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
