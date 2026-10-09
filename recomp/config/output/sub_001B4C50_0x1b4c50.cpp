#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4C50
// Address: 0x1b4c50 - 0x1b4d40
void sub_001B4C50_0x1b4c50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4C50_0x1b4c50");
#endif

    switch (ctx->pc) {
        case 0x1b4c70u: goto label_1b4c70;
        case 0x1b4cb8u: goto label_1b4cb8;
        case 0x1b4cd8u: goto label_1b4cd8;
        case 0x1b4cecu: goto label_1b4cec;
        case 0x1b4d08u: goto label_1b4d08;
        case 0x1b4d2cu: goto label_1b4d2c;
        default: break;
    }

    ctx->pc = 0x1b4c50u;

label_1b4c50:
    // 0x1b4c50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b4c50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b4c54: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4c54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4c58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b4c58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b4c5c: 0x8c24aa30  lw          $a0, -0x55D0($at)
    ctx->pc = 0x1b4c5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945328)));
    // 0x1b4c60: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B4C60u;
    {
        const bool branch_taken_0x1b4c60 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4c60) {
            ctx->pc = 0x1B4C80u;
            goto label_1b4c80;
        }
    }
    ctx->pc = 0x1B4C68u;
    // 0x1b4c68: 0xc063724  jal         func_18DC90
    ctx->pc = 0x1B4C68u;
    SET_GPR_U32(ctx, 31, 0x1B4C70u);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C70u; }
        if (ctx->pc != 0x1B4C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C70u; }
        if (ctx->pc != 0x1B4C70u) { return; }
    }
    ctx->pc = 0x1B4C70u;
label_1b4c70:
    // 0x1b4c70: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4c74: 0xac20aa30  sw          $zero, -0x55D0($at)
    ctx->pc = 0x1b4c74u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945328), GPR_U32(ctx, 0));
    // 0x1b4c78: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4c78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4c7c: 0xa02043eb  sb          $zero, 0x43EB($at)
    ctx->pc = 0x1b4c7cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17387), (uint8_t)GPR_U32(ctx, 0));
label_1b4c80:
    // 0x1b4c80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b4c80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4c84: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4C84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4C88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C84u;
            // 0x1b4c88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4C50u: goto label_1b4c50;
            case 0x1B4C70u: goto label_1b4c70;
            case 0x1B4C80u: goto label_1b4c80;
            case 0x1B4CB8u: goto label_1b4cb8;
            case 0x1B4CD0u: goto label_1b4cd0;
            case 0x1B4CD8u: goto label_1b4cd8;
            case 0x1B4CECu: goto label_1b4cec;
            case 0x1B4CF4u: goto label_1b4cf4;
            case 0x1B4D08u: goto label_1b4d08;
            case 0x1B4D2Cu: goto label_1b4d2c;
            case 0x1B4D30u: goto label_1b4d30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4C8Cu;
    // 0x1b4c8c: 0x0  nop
    ctx->pc = 0x1b4c8cu;
    // NOP
    // 0x1b4c90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b4c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b4c94: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4c94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4c98: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b4c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b4c9c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b4c9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4ca0: 0x8c24aa30  lw          $a0, -0x55D0($at)
    ctx->pc = 0x1b4ca0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945328)));
    // 0x1b4ca4: 0x1480000a  bnez        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B4CA4u;
    {
        const bool branch_taken_0x1b4ca4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4ca4) {
            ctx->pc = 0x1B4CD0u;
            goto label_1b4cd0;
        }
    }
    ctx->pc = 0x1B4CACu;
    // 0x1b4cac: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x1b4cacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x1b4cb0: 0xc063714  jal         func_18DC50
    ctx->pc = 0x1B4CB0u;
    SET_GPR_U32(ctx, 31, 0x1B4CB8u);
    ctx->pc = 0x1B4CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4CB0u;
            // 0x1b4cb4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4CB8u; }
        if (ctx->pc != 0x1B4CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4CB8u; }
        if (ctx->pc != 0x1B4CB8u) { return; }
    }
    ctx->pc = 0x1B4CB8u;
label_1b4cb8:
    // 0x1b4cb8: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4cb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4cbc: 0xac22aa30  sw          $v0, -0x55D0($at)
    ctx->pc = 0x1b4cbcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945328), GPR_U32(ctx, 2));
    // 0x1b4cc0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4cc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4cc4: 0x8c24aa30  lw          $a0, -0x55D0($at)
    ctx->pc = 0x1b4cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945328)));
    // 0x1b4cc8: 0x10800018  beqz        $a0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B4CC8u;
    {
        const bool branch_taken_0x1b4cc8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4cc8) {
            ctx->pc = 0x1B4D2Cu;
            goto label_1b4d2c;
        }
    }
    ctx->pc = 0x1B4CD0u;
label_1b4cd0:
    // 0x1b4cd0: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x1B4CD0u;
    SET_GPR_U32(ctx, 31, 0x1B4CD8u);
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4CD8u; }
        if (ctx->pc != 0x1B4CD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4CD8u; }
        if (ctx->pc != 0x1B4CD8u) { return; }
    }
    ctx->pc = 0x1B4CD8u;
label_1b4cd8:
    // 0x1b4cd8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b4cd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4cdc: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B4CDCu;
    {
        const bool branch_taken_0x1b4cdc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4CDCu;
            // 0x1b4ce0: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4cdc) {
            ctx->pc = 0x1B4CF4u;
            goto label_1b4cf4;
        }
    }
    ctx->pc = 0x1B4CE4u;
    // 0x1b4ce4: 0xc06d314  jal         func_1B4C50
    ctx->pc = 0x1B4CE4u;
    SET_GPR_U32(ctx, 31, 0x1B4CECu);
    ctx->pc = 0x1B4C50u;
    goto label_1b4c50;
    ctx->pc = 0x1B4CECu;
label_1b4cec:
    // 0x1b4cec: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B4CECu;
    {
        const bool branch_taken_0x1b4cec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4CECu;
            // 0x1b4cf0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4cec) {
            ctx->pc = 0x1B4D30u;
            goto label_1b4d30;
        }
    }
    ctx->pc = 0x1B4CF4u;
label_1b4cf4:
    // 0x1b4cf4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b4cf4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4cf8: 0x8c24478c  lw          $a0, 0x478C($at)
    ctx->pc = 0x1b4cf8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18316)));
    // 0x1b4cfc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1b4cfcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4d00: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1B4D00u;
    SET_GPR_U32(ctx, 31, 0x1B4D08u);
    ctx->pc = 0x1B4D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4D00u;
            // 0x1b4d04: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4D08u; }
        if (ctx->pc != 0x1B4D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4D08u; }
        if (ctx->pc != 0x1B4D08u) { return; }
    }
    ctx->pc = 0x1B4D08u;
label_1b4d08:
    // 0x1b4d08: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b4d08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4d0c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4d0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4d10: 0xa02243eb  sb          $v0, 0x43EB($at)
    ctx->pc = 0x1b4d10u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17387), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b4d14: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b4d14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4d18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4d18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4d1c: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x1b4d1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1b4d20: 0x94274414  lhu         $a3, 0x4414($at)
    ctx->pc = 0x1b4d20u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b4d24: 0xc06d404  jal         func_1B5010
    ctx->pc = 0x1B4D24u;
    SET_GPR_U32(ctx, 31, 0x1B4D2Cu);
    ctx->pc = 0x1B4D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4D24u;
            // 0x1b4d28: 0x24060600  addiu       $a2, $zero, 0x600 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5010u;
    if (runtime->hasFunction(0x1B5010u)) {
        auto targetFn = runtime->lookupFunction(0x1B5010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4D2Cu; }
        if (ctx->pc != 0x1B4D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5010_0x1b5010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4D2Cu; }
        if (ctx->pc != 0x1B4D2Cu) { return; }
    }
    ctx->pc = 0x1B4D2Cu;
label_1b4d2c:
    // 0x1b4d2c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b4d2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b4d30:
    // 0x1b4d30: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4d30u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4d34: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4D34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4D34u;
            // 0x1b4d38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4C50u: goto label_1b4c50;
            case 0x1B4C70u: goto label_1b4c70;
            case 0x1B4C80u: goto label_1b4c80;
            case 0x1B4CB8u: goto label_1b4cb8;
            case 0x1B4CD0u: goto label_1b4cd0;
            case 0x1B4CD8u: goto label_1b4cd8;
            case 0x1B4CECu: goto label_1b4cec;
            case 0x1B4CF4u: goto label_1b4cf4;
            case 0x1B4D08u: goto label_1b4d08;
            case 0x1B4D2Cu: goto label_1b4d2c;
            case 0x1B4D30u: goto label_1b4d30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4D3Cu;
    // 0x1b4d3c: 0x0  nop
    ctx->pc = 0x1b4d3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
