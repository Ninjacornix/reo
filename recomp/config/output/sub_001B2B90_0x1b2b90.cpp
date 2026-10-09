#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2B90
// Address: 0x1b2b90 - 0x1b2cd0
void sub_001B2B90_0x1b2b90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2B90_0x1b2b90");
#endif

    switch (ctx->pc) {
        case 0x1b2bb0u: goto label_1b2bb0;
        case 0x1b2c14u: goto label_1b2c14;
        case 0x1b2c40u: goto label_1b2c40;
        case 0x1b2c70u: goto label_1b2c70;
        default: break;
    }

    ctx->pc = 0x1b2b90u;

    // 0x1b2b90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b2b90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b2b94: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b2b94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b2b98: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b2b98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b2b9c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b2b9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b2ba0: 0x3c11002c  lui         $s1, 0x2C
    ctx->pc = 0x1b2ba0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)44 << 16));
    // 0x1b2ba4: 0x26318ea0  addiu       $s1, $s1, -0x7160
    ctx->pc = 0x1b2ba4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294938272));
    // 0x1b2ba8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B2BA8u;
    {
        const bool branch_taken_0x1b2ba8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2BA8u;
            // 0x1b2bac: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2ba8) {
            ctx->pc = 0x1B2BC4u;
            goto label_1b2bc4;
        }
    }
    ctx->pc = 0x1B2BB0u;
label_1b2bb0:
    // 0x1b2bb0: 0x2231821  addu        $v1, $s1, $v1
    ctx->pc = 0x1b2bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x1b2bb4: 0x8c63001c  lw          $v1, 0x1C($v1)
    ctx->pc = 0x1b2bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1b2bb8: 0x10640006  beq         $v1, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B2BB8u;
    {
        const bool branch_taken_0x1b2bb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1B2BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2BB8u;
            // 0x1b2bbc: 0x24030064  addiu       $v1, $zero, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2bb8) {
            ctx->pc = 0x1B2BD4u;
            goto label_1b2bd4;
        }
    }
    ctx->pc = 0x1B2BC0u;
    // 0x1b2bc0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b2bc0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1b2bc4:
    // 0x1b2bc4: 0x2a030064  slti        $v1, $s0, 0x64
    ctx->pc = 0x1b2bc4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)100) ? 1 : 0);
    // 0x1b2bc8: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1B2BC8u;
    {
        const bool branch_taken_0x1b2bc8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2BC8u;
            // 0x1b2bcc: 0x101880  sll         $v1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2bc8) {
            ctx->pc = 0x1B2BB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2bb0;
        }
    }
    ctx->pc = 0x1B2BD0u;
    // 0x1b2bd0: 0x24030064  addiu       $v1, $zero, 0x64
    ctx->pc = 0x1b2bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
label_1b2bd4:
    // 0x1b2bd4: 0x12030011  beq         $s0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B2BD4u;
    {
        const bool branch_taken_0x1b2bd4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B2BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2BD4u;
            // 0x1b2bd8: 0x101840  sll         $v1, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2bd4) {
            ctx->pc = 0x1B2C1Cu;
            goto label_1b2c1c;
        }
    }
    ctx->pc = 0x1B2BDCu;
    // 0x1b2bdc: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1b2bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b2be0: 0x846501ac  lh          $a1, 0x1AC($v1)
    ctx->pc = 0x1b2be0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 428)));
    // 0x1b2be4: 0x10a0000d  beqz        $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x1B2BE4u;
    {
        const bool branch_taken_0x1b2be4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2be4) {
            ctx->pc = 0x1B2C1Cu;
            goto label_1b2c1c;
        }
    }
    ctx->pc = 0x1B2BECu;
    // 0x1b2bec: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b2becu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b2bf0: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x1b2bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1b2bf4: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1b2bf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b2bf8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1b2bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1b2bfc: 0x8c64001c  lw          $a0, 0x1C($v1)
    ctx->pc = 0x1b2bfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1b2c00: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1b2c00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1b2c04: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1b2c04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1b2c08: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b2c08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2c0c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B2C0Cu;
    SET_GPR_U32(ctx, 31, 0x1B2C14u);
    ctx->pc = 0x1B2C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2C0Cu;
            // 0x1b2c10: 0x230c0  sll         $a2, $v0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2C14u; }
        if (ctx->pc != 0x1B2C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2C14u; }
        if (ctx->pc != 0x1B2C14u) { return; }
    }
    ctx->pc = 0x1B2C14u;
label_1b2c14:
    // 0x1b2c14: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x1b2c14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1b2c18: 0xa0600274  sb          $zero, 0x274($v1)
    ctx->pc = 0x1b2c18u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 628), (uint8_t)GPR_U32(ctx, 0));
label_1b2c1c:
    // 0x1b2c1c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b2c1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b2c20: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b2c20u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2c24: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b2c24u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2c28: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2C28u;
            // 0x1b2c2c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2BB0u: goto label_1b2bb0;
            case 0x1B2BC4u: goto label_1b2bc4;
            case 0x1B2BD4u: goto label_1b2bd4;
            case 0x1B2C14u: goto label_1b2c14;
            case 0x1B2C1Cu: goto label_1b2c1c;
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
    ctx->pc = 0x1B2C30u;
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
            case 0x1B2BB0u: goto label_1b2bb0;
            case 0x1B2BC4u: goto label_1b2bc4;
            case 0x1B2BD4u: goto label_1b2bd4;
            case 0x1B2C14u: goto label_1b2c14;
            case 0x1B2C1Cu: goto label_1b2c1c;
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
    // 0x1b2cc8: 0x0  nop
    ctx->pc = 0x1b2cc8u;
    // NOP
    // 0x1b2ccc: 0x0  nop
    ctx->pc = 0x1b2cccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
