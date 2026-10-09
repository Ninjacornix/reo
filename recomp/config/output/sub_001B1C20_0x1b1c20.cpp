#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1C20
// Address: 0x1b1c20 - 0x1b1cb0
void sub_001B1C20_0x1b1c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1C20_0x1b1c20");
#endif

    switch (ctx->pc) {
        case 0x1b1c74u: goto label_1b1c74;
        case 0x1b1c9cu: goto label_1b1c9c;
        default: break;
    }

    ctx->pc = 0x1b1c20u;

    // 0x1b1c20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b1c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b1c24: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1b1c24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1b1c28: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b1c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b1c2c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1b1c2cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1b1c30: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b1c30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b1c34: 0x24634410  addiu       $v1, $v1, 0x4410
    ctx->pc = 0x1b1c34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17424));
    // 0x1b1c38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1c38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b1c3c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b1c3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1c40: 0x280c0  sll         $s0, $v0, 3
    ctx->pc = 0x1b1c40u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1b1c44: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1c44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1c48: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b1c48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b1c4c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b1c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b1c50: 0x24424412  addiu       $v0, $v0, 0x4412
    ctx->pc = 0x1b1c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17426));
    // 0x1b1c54: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b1c54u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b1c58: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b1c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b1c5c: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1b1c5cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b1c60: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b1c60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b1c64: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b1c64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b1c68: 0x23040  sll         $a2, $v0, 1
    ctx->pc = 0x1b1c68u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1b1c6c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B1C6Cu;
    SET_GPR_U32(ctx, 31, 0x1B1C74u);
    ctx->pc = 0x1B1C70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1C6Cu;
            // 0x1b1c70: 0x24640fa4  addiu       $a0, $v1, 0xFA4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4004));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1C74u; }
        if (ctx->pc != 0x1B1C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1C74u; }
        if (ctx->pc != 0x1B1C74u) { return; }
    }
    ctx->pc = 0x1B1C74u;
label_1b1c74:
    // 0x1b1c74: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b1c74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b1c78: 0x24424414  addiu       $v0, $v0, 0x4414
    ctx->pc = 0x1b1c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17428));
    // 0x1b1c7c: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x1b1c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b1c80: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b1c80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b1c84: 0x94650000  lhu         $a1, 0x0($v1)
    ctx->pc = 0x1b1c84u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b1c88: 0x24424416  addiu       $v0, $v0, 0x4416
    ctx->pc = 0x1b1c88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17430));
    // 0x1b1c8c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b1c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b1c90: 0x94460000  lhu         $a2, 0x0($v0)
    ctx->pc = 0x1b1c90u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b1c94: 0xc06c6d0  jal         func_1B1B40
    ctx->pc = 0x1B1C94u;
    SET_GPR_U32(ctx, 31, 0x1B1C9Cu);
    ctx->pc = 0x1B1C98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1C94u;
            // 0x1b1c98: 0x26240004  addiu       $a0, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1B40u;
    if (runtime->hasFunction(0x1B1B40u)) {
        auto targetFn = runtime->lookupFunction(0x1B1B40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1C9Cu; }
        if (ctx->pc != 0x1B1C9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1B40_0x1b1b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1C9Cu; }
        if (ctx->pc != 0x1B1C9Cu) { return; }
    }
    ctx->pc = 0x1B1C9Cu;
label_1b1c9c:
    // 0x1b1c9c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b1c9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b1ca0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b1ca0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1ca4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1ca4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1ca8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1CA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1CA8u;
            // 0x1b1cac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1C74u: goto label_1b1c74;
            case 0x1B1C9Cu: goto label_1b1c9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1CB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
