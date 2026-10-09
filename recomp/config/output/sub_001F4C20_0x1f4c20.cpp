#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4C20
// Address: 0x1f4c20 - 0x1f4cc0
void sub_001F4C20_0x1f4c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4C20_0x1f4c20");
#endif

    switch (ctx->pc) {
        case 0x1f4c9cu: goto label_1f4c9c;
        default: break;
    }

    ctx->pc = 0x1f4c20u;

    // 0x1f4c20: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f4c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f4c24: 0x51602  srl         $v0, $a1, 24
    ctx->pc = 0x1f4c24u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 24));
    // 0x1f4c28: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f4c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f4c2c: 0x304700ff  andi        $a3, $v0, 0xFF
    ctx->pc = 0x1f4c2cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f4c30: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f4c30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f4c34: 0x51202  srl         $v0, $a1, 8
    ctx->pc = 0x1f4c34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
    // 0x1f4c38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f4c38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f4c3c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1f4c3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1f4c40: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1f4c40u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1f4c44: 0x8c890020  lw          $t1, 0x20($a0)
    ctx->pc = 0x1f4c44u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1f4c48: 0x8c88002c  lw          $t0, 0x2C($a0)
    ctx->pc = 0x1f4c48u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1f4c4c: 0x53200  sll         $a2, $a1, 8
    ctx->pc = 0x1f4c4cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1f4c50: 0x51e00  sll         $v1, $a1, 24
    ctx->pc = 0x1f4c50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1f4c54: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1f4c54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1f4c58: 0xc22824  and         $a1, $a2, $v0
    ctx->pc = 0x1f4c58u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x1f4c5c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1f4c5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4c60: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1f4c60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1f4c64: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1f4c64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1f4c68: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1f4c68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1f4c6c: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1f4c6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1f4c70: 0xafa2003c  sw          $v0, 0x3C($sp)
    ctx->pc = 0x1f4c70u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 2));
    // 0x1f4c74: 0x8c83002c  lw          $v1, 0x2C($a0)
    ctx->pc = 0x1f4c74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1f4c78: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x1f4c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1f4c7c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1f4c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1f4c80: 0x43082b  sltu        $at, $v0, $v1
    ctx->pc = 0x1f4c80u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1f4c84: 0x14200008  bnez        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F4C84u;
    {
        const bool branch_taken_0x1f4c84 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4C88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4C84u;
            // 0x1f4c88: 0x1288021  addu        $s0, $t1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4c84) {
            ctx->pc = 0x1F4CA8u;
            goto label_1f4ca8;
        }
    }
    ctx->pc = 0x1F4C8Cu;
    // 0x1f4c8c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f4c8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4c90: 0x27a5003c  addiu       $a1, $sp, 0x3C
    ctx->pc = 0x1f4c90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x1f4c94: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F4C94u;
    SET_GPR_U32(ctx, 31, 0x1F4C9Cu);
    ctx->pc = 0x1F4C98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4C94u;
            // 0x1f4c98: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4C9Cu; }
        if (ctx->pc != 0x1F4C9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4C9Cu; }
        if (ctx->pc != 0x1F4C9Cu) { return; }
    }
    ctx->pc = 0x1F4C9Cu;
label_1f4c9c:
    // 0x1f4c9c: 0x8e22002c  lw          $v0, 0x2C($s1)
    ctx->pc = 0x1f4c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x1f4ca0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f4ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f4ca4: 0xae22002c  sw          $v0, 0x2C($s1)
    ctx->pc = 0x1f4ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 2));
label_1f4ca8:
    // 0x1f4ca8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1f4ca8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4cac: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f4cacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f4cb0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f4cb0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4cb4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4cb4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4cb8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4CB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4CB8u;
            // 0x1f4cbc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4C9Cu: goto label_1f4c9c;
            case 0x1F4CA8u: goto label_1f4ca8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4CC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
