#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198B60
// Address: 0x198b60 - 0x198c80
void sub_00198B60_0x198b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198B60_0x198b60");
#endif

    switch (ctx->pc) {
        case 0x198ba4u: goto label_198ba4;
        default: break;
    }

    ctx->pc = 0x198b60u;

    // 0x198b60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x198b60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x198b64: 0x41402  srl         $v0, $a0, 16
    ctx->pc = 0x198b64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x198b68: 0xa3a2000c  sb          $v0, 0xC($sp)
    ctx->pc = 0x198b68u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 12), (uint8_t)GPR_U32(ctx, 2));
    // 0x198b6c: 0x27a9000d  addiu       $t1, $sp, 0xD
    ctx->pc = 0x198b6cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 13));
    // 0x198b70: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x198b70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x198b74: 0x27a8000e  addiu       $t0, $sp, 0xE
    ctx->pc = 0x198b74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 14));
    // 0x198b78: 0xa1220000  sb          $v0, 0x0($t1)
    ctx->pc = 0x198b78u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x198b7c: 0x27a6000f  addiu       $a2, $sp, 0xF
    ctx->pc = 0x198b7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 15));
    // 0x198b80: 0xa1040000  sb          $a0, 0x0($t0)
    ctx->pc = 0x198b80u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x198b84: 0x41602  srl         $v0, $a0, 24
    ctx->pc = 0x198b84u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x198b88: 0x14a0001a  bnez        $a1, . + 4 + (0x1A << 2)
    ctx->pc = 0x198B88u;
    {
        const bool branch_taken_0x198b88 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x198B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198B88u;
            // 0x198b8c: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198b88) {
            ctx->pc = 0x198BF4u;
            goto label_198bf4;
        }
    }
    ctx->pc = 0x198B90u;
    // 0x198b90: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x198b90u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x198b94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x198b94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x198b98: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x198b98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x198b9c: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x198b9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x198ba0: 0x15d1021  addu        $v0, $t2, $sp
    ctx->pc = 0x198ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 29)));
label_198ba4:
    // 0x198ba4: 0x2447000c  addiu       $a3, $v0, 0xC
    ctx->pc = 0x198ba4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x198ba8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x198ba8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x198bac: 0x14450003  bne         $v0, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198BACu;
    {
        const bool branch_taken_0x198bac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x198bac) {
            ctx->pc = 0x198BBCu;
            goto label_198bbc;
        }
    }
    ctx->pc = 0x198BB4u;
    // 0x198bb4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x198BB4u;
    {
        const bool branch_taken_0x198bb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198BB4u;
            // 0x198bb8: 0xa0e40000  sb          $a0, 0x0($a3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198bb4) {
            ctx->pc = 0x198BDCu;
            goto label_198bdc;
        }
    }
    ctx->pc = 0x198BBCu;
label_198bbc:
    // 0x198bbc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x198BBCu;
    {
        const bool branch_taken_0x198bbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x198bbc) {
            ctx->pc = 0x198BDCu;
            goto label_198bdc;
        }
    }
    ctx->pc = 0x198BC4u;
    // 0x198bc4: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x198bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x198bc8: 0xa0e20000  sb          $v0, 0x0($a3)
    ctx->pc = 0x198bc8u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x198bcc: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x198bccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x198bd0: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x198BD0u;
    {
        const bool branch_taken_0x198bd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x198bd0) {
            ctx->pc = 0x198BDCu;
            goto label_198bdc;
        }
    }
    ctx->pc = 0x198BD8u;
    // 0x198bd8: 0xa0e30000  sb          $v1, 0x0($a3)
    ctx->pc = 0x198bd8u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 3));
label_198bdc:
    // 0x198bdc: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x198bdcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x198be0: 0x29420004  slti        $v0, $t2, 0x4
    ctx->pc = 0x198be0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x198be4: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x198BE4u;
    {
        const bool branch_taken_0x198be4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x198BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198BE4u;
            // 0x198be8: 0x15d1021  addu        $v0, $t2, $sp (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198be4) {
            ctx->pc = 0x198BA4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_198ba4;
        }
    }
    ctx->pc = 0x198BECu;
    // 0x198bec: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x198BECu;
    {
        const bool branch_taken_0x198bec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198BECu;
            // 0x198bf0: 0x90c50000  lbu         $a1, 0x0($a2) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198bec) {
            ctx->pc = 0x198C30u;
            goto label_198c30;
        }
    }
    ctx->pc = 0x198BF4u;
label_198bf4:
    // 0x198bf4: 0x90c30000  lbu         $v1, 0x0($a2)
    ctx->pc = 0x198bf4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x198bf8: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x198bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x198bfc: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x198BFCu;
    {
        const bool branch_taken_0x198bfc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x198C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198BFCu;
            // 0x198c00: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198bfc) {
            ctx->pc = 0x198C0Cu;
            goto label_198c0c;
        }
    }
    ctx->pc = 0x198C04u;
    // 0x198c04: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x198C04u;
    {
        const bool branch_taken_0x198c04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198C04u;
            // 0x198c08: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198c04) {
            ctx->pc = 0x198C2Cu;
            goto label_198c2c;
        }
    }
    ctx->pc = 0x198C0Cu;
label_198c0c:
    // 0x198c0c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x198C0Cu;
    {
        const bool branch_taken_0x198c0c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x198C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198C0Cu;
            // 0x198c10: 0x31042  srl         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198c0c) {
            ctx->pc = 0x198C2Cu;
            goto label_198c2c;
        }
    }
    ctx->pc = 0x198C14u;
    // 0x198c14: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x198c14u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x198c18: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x198c18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x198c1c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x198C1Cu;
    {
        const bool branch_taken_0x198c1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x198c1c) {
            ctx->pc = 0x198C2Cu;
            goto label_198c2c;
        }
    }
    ctx->pc = 0x198C24u;
    // 0x198c24: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x198c24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x198c28: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x198c28u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
label_198c2c:
    // 0x198c2c: 0x90c50000  lbu         $a1, 0x0($a2)
    ctx->pc = 0x198c2cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
label_198c30:
    // 0x198c30: 0x93a4000c  lbu         $a0, 0xC($sp)
    ctx->pc = 0x198c30u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x198c34: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x198c34u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x198c38: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x198c38u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x198c3c: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x198c3cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x198c40: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x198c40u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x198c44: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x198c44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x198c48: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x198c48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x198c4c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x198c4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x198c50: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x198c50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x198c54: 0x3e00008  jr          $ra
    ctx->pc = 0x198C54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198C54u;
            // 0x198c58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x198BA4u: goto label_198ba4;
            case 0x198BBCu: goto label_198bbc;
            case 0x198BDCu: goto label_198bdc;
            case 0x198BF4u: goto label_198bf4;
            case 0x198C0Cu: goto label_198c0c;
            case 0x198C2Cu: goto label_198c2c;
            case 0x198C30u: goto label_198c30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x198C5Cu;
    // 0x198c5c: 0x0  nop
    ctx->pc = 0x198c5cu;
    // NOP
    // 0x198c60: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198c60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198c64: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x198c64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x198c68: 0xac24fd6c  sw          $a0, -0x294($at)
    ctx->pc = 0x198c68u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966636), GPR_U32(ctx, 4));
    // 0x198c6c: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x198c6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x198c70: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198c74: 0x3e00008  jr          $ra
    ctx->pc = 0x198C74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198C74u;
            // 0x198c78: 0xac23fd70  sw          $v1, -0x290($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966640), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x198BA4u: goto label_198ba4;
            case 0x198BBCu: goto label_198bbc;
            case 0x198BDCu: goto label_198bdc;
            case 0x198BF4u: goto label_198bf4;
            case 0x198C0Cu: goto label_198c0c;
            case 0x198C2Cu: goto label_198c2c;
            case 0x198C30u: goto label_198c30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x198C7Cu;
    // 0x198c7c: 0x0  nop
    ctx->pc = 0x198c7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
