#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2C30
// Address: 0x1b2c30 - 0x1b2cc8
void sub_001B2C30_0x1b2c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2C30_0x1b2c30");
#endif

    switch (ctx->pc) {
        case 0x1b2c40u: goto label_1b2c40;
        case 0x1b2c70u: goto label_1b2c70;
        default: break;
    }

    ctx->pc = 0x1b2c30u;

    // 0x1b2c30: 0x3c07002c  lui         $a3, 0x2C
    ctx->pc = 0x1b2c30u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)44 << 16));
    // 0x1b2c34: 0x24060063  addiu       $a2, $zero, 0x63
    ctx->pc = 0x1b2c34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1b2c38: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B2C38u;
    {
        const bool branch_taken_0x1b2c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2C38u;
            // 0x1b2c3c: 0x24e78ea0  addiu       $a3, $a3, -0x7160 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294938272));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2c38) {
            ctx->pc = 0x1B2C54u;
            goto label_1b2c54;
        }
    }
    ctx->pc = 0x1B2C40u;
label_1b2c40:
    // 0x1b2c40: 0xe61821  addu        $v1, $a3, $a2
    ctx->pc = 0x1b2c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x1b2c44: 0x90630274  lbu         $v1, 0x274($v1)
    ctx->pc = 0x1b2c44u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 628)));
    // 0x1b2c48: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B2C48u;
    {
        const bool branch_taken_0x1b2c48 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b2c48) {
            ctx->pc = 0x1B2C60u;
            goto label_1b2c60;
        }
    }
    ctx->pc = 0x1B2C50u;
    // 0x1b2c50: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1b2c50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_1b2c54:
    // 0x1b2c54: 0x0  nop
    ctx->pc = 0x1b2c54u;
    // NOP
    // 0x1b2c58: 0x4c1fff9  bgez        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1B2C58u;
    {
        const bool branch_taken_0x1b2c58 = (GPR_S64(ctx, 6) >= 0);
        if (branch_taken_0x1b2c58) {
            ctx->pc = 0x1B2C40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2c40;
        }
    }
    ctx->pc = 0x1B2C60u;
label_1b2c60:
    // 0x1b2c60: 0x4c00017  bltz        $a2, . + 4 + (0x17 << 2)
    ctx->pc = 0x1B2C60u;
    {
        const bool branch_taken_0x1b2c60 = (GPR_S64(ctx, 6) < 0);
        if (branch_taken_0x1b2c60) {
            ctx->pc = 0x1B2CC0u;
            goto label_1b2cc0;
        }
    }
    ctx->pc = 0x1B2C68u;
    // 0x1b2c68: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1B2C68u;
    {
        const bool branch_taken_0x1b2c68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2C68u;
            // 0x1b2c6c: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2c68) {
            ctx->pc = 0x1B2CB4u;
            goto label_1b2cb4;
        }
    }
    ctx->pc = 0x1B2C70u;
label_1b2c70:
    // 0x1b2c70: 0xe31821  addu        $v1, $a3, $v1
    ctx->pc = 0x1b2c70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x1b2c74: 0x246501ac  addiu       $a1, $v1, 0x1AC
    ctx->pc = 0x1b2c74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 428));
    // 0x1b2c78: 0x846301ac  lh          $v1, 0x1AC($v1)
    ctx->pc = 0x1b2c78u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 428)));
    // 0x1b2c7c: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1B2C7Cu;
    {
        const bool branch_taken_0x1b2c7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2C80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2C7Cu;
            // 0x1b2c80: 0x62080  sll         $a0, $a2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2c7c) {
            ctx->pc = 0x1B2CB0u;
            goto label_1b2cb0;
        }
    }
    ctx->pc = 0x1B2C84u;
    // 0x1b2c84: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b2c84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b2c88: 0xe42021  addu        $a0, $a3, $a0
    ctx->pc = 0x1b2c88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x1b2c8c: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b2c8cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b2c90: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x1b2c90u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x1b2c94: 0xa4a00000  sh          $zero, 0x0($a1)
    ctx->pc = 0x1b2c94u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2c98: 0x84e4000a  lh          $a0, 0xA($a3)
    ctx->pc = 0x1b2c98u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 10)));
    // 0x1b2c9c: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x1b2c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b2ca0: 0xa4e3000a  sh          $v1, 0xA($a3)
    ctx->pc = 0x1b2ca0u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 10), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b2ca4: 0x84e3000c  lh          $v1, 0xC($a3)
    ctx->pc = 0x1b2ca4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x1b2ca8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b2ca8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b2cac: 0xa4e3000c  sh          $v1, 0xC($a3)
    ctx->pc = 0x1b2cacu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 12), (uint16_t)GPR_U32(ctx, 3));
label_1b2cb0:
    // 0x1b2cb0: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1b2cb0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1b2cb4:
    // 0x1b2cb4: 0x28c30064  slti        $v1, $a2, 0x64
    ctx->pc = 0x1b2cb4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)100) ? 1 : 0);
    // 0x1b2cb8: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1B2CB8u;
    {
        const bool branch_taken_0x1b2cb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2CB8u;
            // 0x1b2cbc: 0x61840  sll         $v1, $a2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2cb8) {
            ctx->pc = 0x1B2C70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2c70;
        }
    }
    ctx->pc = 0x1B2CC0u;
label_1b2cc0:
    // 0x1b2cc0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2CC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2C40u: goto label_1b2c40;
            case 0x1B2C54u: goto label_1b2c54;
            case 0x1B2C60u: goto label_1b2c60;
            case 0x1B2C70u: goto label_1b2c70;
            case 0x1B2CB0u: goto label_1b2cb0;
            case 0x1B2CB4u: goto label_1b2cb4;
            case 0x1B2CC0u: goto label_1b2cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2CC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
