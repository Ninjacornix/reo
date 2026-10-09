#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ADF50
// Address: 0x1adf50 - 0x1adfd0
void sub_001ADF50_0x1adf50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ADF50_0x1adf50");
#endif

    switch (ctx->pc) {
        case 0x1adf84u: goto label_1adf84;
        case 0x1adfb0u: goto label_1adfb0;
        default: break;
    }

    ctx->pc = 0x1adf50u;

    // 0x1adf50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1adf50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1adf54: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1adf54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1adf58: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1adf58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1adf5c: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adf5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adf60: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1adf60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1adf64: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1adf64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1adf68: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1adf68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1adf6c: 0x24428d74  addiu       $v0, $v0, -0x728C
    ctx->pc = 0x1adf6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937972));
    // 0x1adf70: 0x380c0  sll         $s0, $v1, 3
    ctx->pc = 0x1adf70u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1adf74: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1adf74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1adf78: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1adf78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1adf7c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1ADF7Cu;
    SET_GPR_U32(ctx, 31, 0x1ADF84u);
    ctx->pc = 0x1ADF80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADF7Cu;
            // 0x1adf80: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADF84u; }
        if (ctx->pc != 0x1ADF84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADF84u; }
        if (ctx->pc != 0x1ADF84u) { return; }
    }
    ctx->pc = 0x1ADF84u;
label_1adf84:
    // 0x1adf84: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adf84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adf88: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1adf88u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1adf8c: 0x24428d70  addiu       $v0, $v0, -0x7290
    ctx->pc = 0x1adf8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937968));
    // 0x1adf90: 0x502021  addu        $a0, $v0, $s0
    ctx->pc = 0x1adf90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1adf94: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adf94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adf98: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1adf98u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1adf9c: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1adf9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1adfa0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1adfa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adfa4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1adfa4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1adfa8: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1ADFA8u;
    SET_GPR_U32(ctx, 31, 0x1ADFB0u);
    ctx->pc = 0x1ADFACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADFA8u;
            // 0x1adfac: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADFB0u; }
        if (ctx->pc != 0x1ADFB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADFB0u; }
        if (ctx->pc != 0x1ADFB0u) { return; }
    }
    ctx->pc = 0x1ADFB0u;
label_1adfb0:
    // 0x1adfb0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1adfb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1adfb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1adfb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adfb8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1adfb8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1adfbc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1adfbcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1adfc0: 0x3e00008  jr          $ra
    ctx->pc = 0x1ADFC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ADFC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADFC0u;
            // 0x1adfc4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ADF84u: goto label_1adf84;
            case 0x1ADFB0u: goto label_1adfb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ADFC8u;
    // 0x1adfc8: 0x0  nop
    ctx->pc = 0x1adfc8u;
    // NOP
    // 0x1adfcc: 0x0  nop
    ctx->pc = 0x1adfccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
