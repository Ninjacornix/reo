#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123A40
// Address: 0x123a40 - 0x123d58
void sub_00123A40_0x123a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123A40_0x123a40");
#endif

    ctx->pc = 0x123a40u;

    // 0x123a40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x123a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x123a44: 0x80702d  daddu       $t6, $a0, $zero
    ctx->pc = 0x123a44u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123a48: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x123a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x123a4c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x123a4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123a50: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x123a50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x123a54: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x123a54u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123a58: 0x3c0c0064  lui         $t4, 0x64
    ctx->pc = 0x123a58u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)100 << 16));
    // 0x123a5c: 0xa0c82d  daddu       $t9, $a1, $zero
    ctx->pc = 0x123a5cu;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123a60: 0x91cb0003  lbu         $t3, 0x3($t6)
    ctx->pc = 0x123a60u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x123a64: 0x358c732e  ori         $t4, $t4, 0x732E
    ctx->pc = 0x123a64u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | (uint64_t)(uint16_t)29486);
    // 0x123a68: 0x91c30002  lbu         $v1, 0x2($t6)
    ctx->pc = 0x123a68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x123a6c: 0x100682d  daddu       $t5, $t0, $zero
    ctx->pc = 0x123a6cu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123a70: 0x91c40001  lbu         $a0, 0x1($t6)
    ctx->pc = 0x123a70u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x123a74: 0xb5e00  sll         $t3, $t3, 24
    ctx->pc = 0x123a74u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 24));
    // 0x123a78: 0x91c20000  lbu         $v0, 0x0($t6)
    ctx->pc = 0x123a78u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x123a7c: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x123a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x123a80: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x123a80u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x123a84: 0x120c02d  daddu       $t8, $t1, $zero
    ctx->pc = 0x123a84u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123a88: 0x4b1025  or          $v0, $v0, $t3
    ctx->pc = 0x123a88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 11));
    // 0x123a8c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x123a8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123a90: 0x432025  or          $a0, $v0, $v1
    ctx->pc = 0x123a90u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x123a94: 0x108c0005  beq         $a0, $t4, . + 4 + (0x5 << 2)
    ctx->pc = 0x123A94u;
    {
        const bool branch_taken_0x123a94 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 12));
        ctx->pc = 0x123A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123A94u;
            // 0x123a98: 0x25cb0004  addiu       $t3, $t6, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 14), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123a94) {
            ctx->pc = 0x123AACu;
            goto label_123aac;
        }
    }
    ctx->pc = 0x123A9Cu;
    // 0x123a9c: 0x3c03646e  lui         $v1, 0x646E
    ctx->pc = 0x123a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)25710 << 16));
    // 0x123aa0: 0x3463732e  ori         $v1, $v1, 0x732E
    ctx->pc = 0x123aa0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)29486);
    // 0x123aa4: 0x148300a8  bne         $a0, $v1, . + 4 + (0xA8 << 2)
    ctx->pc = 0x123AA4u;
    {
        const bool branch_taken_0x123aa4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x123AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123AA4u;
            // 0x123aa8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123aa4) {
            ctx->pc = 0x123D48u;
            goto label_123d48;
        }
    }
    ctx->pc = 0x123AACu;
label_123aac:
    // 0x123aac: 0x91660003  lbu         $a2, 0x3($t3)
    ctx->pc = 0x123aacu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 3)));
    // 0x123ab0: 0x3c0f00ff  lui         $t7, 0xFF
    ctx->pc = 0x123ab0u;
    SET_GPR_S32(ctx, 15, (int32_t)((uint32_t)255 << 16));
    // 0x123ab4: 0x91640002  lbu         $a0, 0x2($t3)
    ctx->pc = 0x123ab4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 2)));
    // 0x123ab8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x123ab8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123abc: 0x91650001  lbu         $a1, 0x1($t3)
    ctx->pc = 0x123abcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 1)));
    // 0x123ac0: 0x63600  sll         $a2, $a2, 24
    ctx->pc = 0x123ac0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 24));
    // 0x123ac4: 0x91630000  lbu         $v1, 0x0($t3)
    ctx->pc = 0x123ac4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x123ac8: 0x52a00  sll         $a1, $a1, 8
    ctx->pc = 0x123ac8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x123acc: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x123accu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x123ad0: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x123ad0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x123ad4: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x123ad4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x123ad8: 0x646025  or          $t4, $v1, $a0
    ctx->pc = 0x123ad8u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123adc: 0xc3202  srl         $a2, $t4, 8
    ctx->pc = 0x123adcu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 12), 8));
    // 0x123ae0: 0xc2a00  sll         $a1, $t4, 8
    ctx->pc = 0x123ae0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 12), 8));
    // 0x123ae4: 0xc2600  sll         $a0, $t4, 24
    ctx->pc = 0x123ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 12), 24));
    // 0x123ae8: 0xc1e02  srl         $v1, $t4, 24
    ctx->pc = 0x123ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 12), 24));
    // 0x123aec: 0xaf2824  and         $a1, $a1, $t7
    ctx->pc = 0x123aecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 15));
    // 0x123af0: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x123af0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x123af4: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x123af4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123af8: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x123af8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x123afc: 0x656025  or          $t4, $v1, $a1
    ctx->pc = 0x123afcu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x123b00: 0x32c202a  slt         $a0, $t9, $t4
    ctx->pc = 0x123b00u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 12)) ? 1 : 0);
    // 0x123b04: 0x14800090  bnez        $a0, . + 4 + (0x90 << 2)
    ctx->pc = 0x123B04u;
    {
        const bool branch_taken_0x123b04 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x123B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123B04u;
            // 0x123b08: 0x256b0004  addiu       $t3, $t3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123b04) {
            ctx->pc = 0x123D48u;
            goto label_123d48;
        }
    }
    ctx->pc = 0x123B0Cu;
    // 0x123b0c: 0x91690000  lbu         $t1, 0x0($t3)
    ctx->pc = 0x123b0cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x123b10: 0x24190002  addiu       $t9, $zero, 0x2
    ctx->pc = 0x123b10u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x123b14: 0x91680003  lbu         $t0, 0x3($t3)
    ctx->pc = 0x123b14u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 3)));
    // 0x123b18: 0x91660002  lbu         $a2, 0x2($t3)
    ctx->pc = 0x123b18u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 2)));
    // 0x123b1c: 0x91670001  lbu         $a3, 0x1($t3)
    ctx->pc = 0x123b1cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 1)));
    // 0x123b20: 0x256b0004  addiu       $t3, $t3, 0x4
    ctx->pc = 0x123b20u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
    // 0x123b24: 0x91650003  lbu         $a1, 0x3($t3)
    ctx->pc = 0x123b24u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 3)));
    // 0x123b28: 0x84600  sll         $t0, $t0, 24
    ctx->pc = 0x123b28u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 24));
    // 0x123b2c: 0x91640002  lbu         $a0, 0x2($t3)
    ctx->pc = 0x123b2cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 2)));
    // 0x123b30: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x123b30u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x123b34: 0x91620001  lbu         $v0, 0x1($t3)
    ctx->pc = 0x123b34u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 1)));
    // 0x123b38: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x123b38u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x123b3c: 0x91630000  lbu         $v1, 0x0($t3)
    ctx->pc = 0x123b3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x123b40: 0x256b0004  addiu       $t3, $t3, 0x4
    ctx->pc = 0x123b40u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
    // 0x123b44: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x123b44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123b48: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x123b48u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x123b4c: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x123b4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x123b50: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x123b50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x123b54: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x123b54u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x123b58: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x123b58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123b5c: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x123b5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x123b60: 0x1284825  or          $t1, $t1, $t0
    ctx->pc = 0x123b60u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 8));
    // 0x123b64: 0x1264825  or          $t1, $t1, $a2
    ctx->pc = 0x123b64u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 6));
    // 0x123b68: 0x43602  srl         $a2, $a0, 24
    ctx->pc = 0x123b68u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x123b6c: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x123b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x123b70: 0x42a00  sll         $a1, $a0, 8
    ctx->pc = 0x123b70u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x123b74: 0x93a02  srl         $a3, $t1, 8
    ctx->pc = 0x123b74u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 9), 8));
    // 0x123b78: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x123b78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x123b7c: 0x91a00  sll         $v1, $t1, 8
    ctx->pc = 0x123b7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x123b80: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x123b80u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x123b84: 0xaf2824  and         $a1, $a1, $t7
    ctx->pc = 0x123b84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 15));
    // 0x123b88: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x123b88u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x123b8c: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x123b8cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x123b90: 0x91602  srl         $v0, $t1, 24
    ctx->pc = 0x123b90u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 24));
    // 0x123b94: 0x92600  sll         $a0, $t1, 24
    ctx->pc = 0x123b94u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 9), 24));
    // 0x123b98: 0x6f1824  and         $v1, $v1, $t7
    ctx->pc = 0x123b98u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 15));
    // 0x123b9c: 0x30e7ff00  andi        $a3, $a3, 0xFF00
    ctx->pc = 0x123b9cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65280);
    // 0x123ba0: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x123ba0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x123ba4: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x123ba4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x123ba8: 0xc52025  or          $a0, $a2, $a1
    ctx->pc = 0x123ba8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x123bac: 0x10990012  beq         $a0, $t9, . + 4 + (0x12 << 2)
    ctx->pc = 0x123BACu;
    {
        const bool branch_taken_0x123bac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 25));
        ctx->pc = 0x123BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123BACu;
            // 0x123bb0: 0x434825  or          $t1, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123bac) {
            ctx->pc = 0x123BF8u;
            goto label_123bf8;
        }
    }
    ctx->pc = 0x123BB4u;
    // 0x123bb4: 0x2c820003  sltiu       $v0, $a0, 0x3
    ctx->pc = 0x123bb4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x123bb8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x123BB8u;
    {
        const bool branch_taken_0x123bb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x123BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123BB8u;
            // 0x123bbc: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123bb8) {
            ctx->pc = 0x123BD8u;
            goto label_123bd8;
        }
    }
    ctx->pc = 0x123BC0u;
    // 0x123bc0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123bc4: 0x10820008  beq         $a0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x123BC4u;
    {
        const bool branch_taken_0x123bc4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x123BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123BC4u;
            // 0x123bc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123bc4) {
            ctx->pc = 0x123BE8u;
            goto label_123be8;
        }
    }
    ctx->pc = 0x123BCCu;
    // 0x123bcc: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x123BCCu;
    {
        const bool branch_taken_0x123bcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123BCCu;
            // 0x123bd0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123bcc) {
            ctx->pc = 0x123D4Cu;
            goto label_123d4c;
        }
    }
    ctx->pc = 0x123BD4u;
    // 0x123bd4: 0x0  nop
    ctx->pc = 0x123bd4u;
    // NOP
label_123bd8:
    // 0x123bd8: 0x1082000d  beq         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x123BD8u;
    {
        const bool branch_taken_0x123bd8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x123BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123BD8u;
            // 0x123bdc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123bd8) {
            ctx->pc = 0x123C10u;
            goto label_123c10;
        }
    }
    ctx->pc = 0x123BE0u;
    // 0x123be0: 0x1000005a  b           . + 4 + (0x5A << 2)
    ctx->pc = 0x123BE0u;
    {
        const bool branch_taken_0x123be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123BE0u;
            // 0x123be4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123be0) {
            ctx->pc = 0x123D4Cu;
            goto label_123d4c;
        }
    }
    ctx->pc = 0x123BE8u;
label_123be8:
    // 0x123be8: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x123be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x123bec: 0xad590000  sw          $t9, 0x0($t2)
    ctx->pc = 0x123becu;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 25));
    // 0x123bf0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x123BF0u;
    {
        const bool branch_taken_0x123bf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123BF0u;
            // 0x123bf4: 0xada20000  sw          $v0, 0x0($t5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123bf0) {
            ctx->pc = 0x123C1Cu;
            goto label_123c1c;
        }
    }
    ctx->pc = 0x123BF8u;
label_123bf8:
    // 0x123bf8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123bfc: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x123bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x123c00: 0xad420000  sw          $v0, 0x0($t2)
    ctx->pc = 0x123c00u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 2));
    // 0x123c04: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x123C04u;
    {
        const bool branch_taken_0x123c04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123C04u;
            // 0x123c08: 0xada30000  sw          $v1, 0x0($t5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123c04) {
            ctx->pc = 0x123C1Cu;
            goto label_123c1c;
        }
    }
    ctx->pc = 0x123C0Cu;
    // 0x123c0c: 0x0  nop
    ctx->pc = 0x123c0cu;
    // NOP
label_123c10:
    // 0x123c10: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x123c10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x123c14: 0xad400000  sw          $zero, 0x0($t2)
    ctx->pc = 0x123c14u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 0));
    // 0x123c18: 0xada20000  sw          $v0, 0x0($t5)
    ctx->pc = 0x123c18u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 2));
label_123c1c:
    // 0x123c1c: 0x91650003  lbu         $a1, 0x3($t3)
    ctx->pc = 0x123c1cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 3)));
    // 0x123c20: 0x3c0600ff  lui         $a2, 0xFF
    ctx->pc = 0x123c20u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)255 << 16));
    // 0x123c24: 0x91630002  lbu         $v1, 0x2($t3)
    ctx->pc = 0x123c24u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 2)));
    // 0x123c28: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x123c28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x123c2c: 0x91640001  lbu         $a0, 0x1($t3)
    ctx->pc = 0x123c2cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 1)));
    // 0x123c30: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x123c30u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x123c34: 0x91620000  lbu         $v0, 0x0($t3)
    ctx->pc = 0x123c34u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x123c38: 0x256b0004  addiu       $t3, $t3, 0x4
    ctx->pc = 0x123c38u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
    // 0x123c3c: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x123c3cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x123c40: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x123c40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x123c44: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x123c44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123c48: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x123c48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x123c4c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x123c4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x123c50: 0x22a03  sra         $a1, $v0, 8
    ctx->pc = 0x123c50u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 2), 8));
    // 0x123c54: 0x22200  sll         $a0, $v0, 8
    ctx->pc = 0x123c54u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123c58: 0x30a5ff00  andi        $a1, $a1, 0xFF00
    ctx->pc = 0x123c58u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x123c5c: 0x21e02  srl         $v1, $v0, 24
    ctx->pc = 0x123c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x123c60: 0x862024  and         $a0, $a0, $a2
    ctx->pc = 0x123c60u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 6));
    // 0x123c64: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x123c64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x123c68: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x123c68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x123c6c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x123c6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x123c70: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x123c70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123c74: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x123c74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x123c78: 0x91650001  lbu         $a1, 0x1($t3)
    ctx->pc = 0x123c78u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 1)));
    // 0x123c7c: 0x91640003  lbu         $a0, 0x3($t3)
    ctx->pc = 0x123c7cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 3)));
    // 0x123c80: 0x91630002  lbu         $v1, 0x2($t3)
    ctx->pc = 0x123c80u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 2)));
    // 0x123c84: 0x52a00  sll         $a1, $a1, 8
    ctx->pc = 0x123c84u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x123c88: 0x91620000  lbu         $v0, 0x0($t3)
    ctx->pc = 0x123c88u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x123c8c: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x123c8cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x123c90: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x123c90u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x123c94: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x123c94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x123c98: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x123c98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x123c9c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x123c9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x123ca0: 0x22a03  sra         $a1, $v0, 8
    ctx->pc = 0x123ca0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 2), 8));
    // 0x123ca4: 0x22200  sll         $a0, $v0, 8
    ctx->pc = 0x123ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123ca8: 0x21e02  srl         $v1, $v0, 24
    ctx->pc = 0x123ca8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x123cac: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x123cacu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x123cb0: 0x862024  and         $a0, $a0, $a2
    ctx->pc = 0x123cb0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 6));
    // 0x123cb4: 0x30a5ff00  andi        $a1, $a1, 0xFF00
    ctx->pc = 0x123cb4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x123cb8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x123cb8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x123cbc: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x123cbcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x123cc0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x123cc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x123cc4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x123cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x123cc8: 0x8d4a0000  lw          $t2, 0x0($t2)
    ctx->pc = 0x123cc8u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x123ccc: 0x15470008  bne         $t2, $a3, . + 4 + (0x8 << 2)
    ctx->pc = 0x123CCCu;
    {
        const bool branch_taken_0x123ccc = (GPR_U64(ctx, 10) != GPR_U64(ctx, 7));
        ctx->pc = 0x123CD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123CCCu;
            // 0x123cd0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123ccc) {
            ctx->pc = 0x123CF0u;
            goto label_123cf0;
        }
    }
    ctx->pc = 0x123CD4u;
    // 0x123cd4: 0x123001a  div         $zero, $t1, $v1
    ctx->pc = 0x123cd4u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 9);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x123cd8: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x123CD8u;
    {
        const bool branch_taken_0x123cd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x123cd8) {
            ctx->pc = 0x123CDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123CD8u;
            // 0x123cdc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x123CE0u;
            goto label_123ce0;
        }
    }
    ctx->pc = 0x123CE0u;
label_123ce0:
    // 0x123ce0: 0x1012  mflo        $v0
    ctx->pc = 0x123ce0u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x123ce4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x123CE4u;
    {
        const bool branch_taken_0x123ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123CE4u;
            // 0x123ce8: 0xaf020000  sw          $v0, 0x0($t8) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123ce4) {
            ctx->pc = 0x123D44u;
            goto label_123d44;
        }
    }
    ctx->pc = 0x123CECu;
    // 0x123cec: 0x0  nop
    ctx->pc = 0x123cecu;
    // NOP
label_123cf0:
    // 0x123cf0: 0x15420007  bne         $t2, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x123CF0u;
    {
        const bool branch_taken_0x123cf0 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 2));
        if (branch_taken_0x123cf0) {
            ctx->pc = 0x123D10u;
            goto label_123d10;
        }
    }
    ctx->pc = 0x123CF8u;
    // 0x123cf8: 0x123001a  div         $zero, $t1, $v1
    ctx->pc = 0x123cf8u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 9);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x123cfc: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x123CFCu;
    {
        const bool branch_taken_0x123cfc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x123cfc) {
            ctx->pc = 0x123D00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123CFCu;
            // 0x123d00: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x123D04u;
            goto label_123d04;
        }
    }
    ctx->pc = 0x123D04u;
label_123d04:
    // 0x123d04: 0x1012  mflo        $v0
    ctx->pc = 0x123d04u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x123d08: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x123D08u;
    {
        const bool branch_taken_0x123d08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123D0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123D08u;
            // 0x123d0c: 0xaf020000  sw          $v0, 0x0($t8) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123d08) {
            ctx->pc = 0x123D44u;
            goto label_123d44;
        }
    }
    ctx->pc = 0x123D10u;
label_123d10:
    // 0x123d10: 0x1540000b  bnez        $t2, . + 4 + (0xB << 2)
    ctx->pc = 0x123D10u;
    {
        const bool branch_taken_0x123d10 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x123D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123D10u;
            // 0x123d14: 0x3c027fff  lui         $v0, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123d10) {
            ctx->pc = 0x123D40u;
            goto label_123d40;
        }
    }
    ctx->pc = 0x123D18u;
    // 0x123d18: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x123d18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x123d1c: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x123D1Cu;
    {
        const bool branch_taken_0x123d1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x123d1c) {
            ctx->pc = 0x123D20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123D1Cu;
            // 0x123d20: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x123D24u;
            goto label_123d24;
        }
    }
    ctx->pc = 0x123D24u;
label_123d24:
    // 0x123d24: 0x1221021  addu        $v0, $t1, $v0
    ctx->pc = 0x123d24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x123d28: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x123d28u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x123d2c: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x123d2cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x123d30: 0x1012  mflo        $v0
    ctx->pc = 0x123d30u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x123d34: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x123D34u;
    {
        const bool branch_taken_0x123d34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123D34u;
            // 0x123d38: 0xaf020000  sw          $v0, 0x0($t8) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123d34) {
            ctx->pc = 0x123D44u;
            goto label_123d44;
        }
    }
    ctx->pc = 0x123D3Cu;
    // 0x123d3c: 0x0  nop
    ctx->pc = 0x123d3cu;
    // NOP
label_123d40:
    // 0x123d40: 0xaf020000  sw          $v0, 0x0($t8)
    ctx->pc = 0x123d40u;
    WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 2));
label_123d44:
    // 0x123d44: 0x1cc1021  addu        $v0, $t6, $t4
    ctx->pc = 0x123d44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 12)));
label_123d48:
    // 0x123d48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x123d48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_123d4c:
    // 0x123d4c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x123d4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x123d50: 0x3e00008  jr          $ra
    ctx->pc = 0x123D50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123D50u;
            // 0x123d54: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123AACu: goto label_123aac;
            case 0x123BD8u: goto label_123bd8;
            case 0x123BE8u: goto label_123be8;
            case 0x123BF8u: goto label_123bf8;
            case 0x123C10u: goto label_123c10;
            case 0x123C1Cu: goto label_123c1c;
            case 0x123CE0u: goto label_123ce0;
            case 0x123CF0u: goto label_123cf0;
            case 0x123D04u: goto label_123d04;
            case 0x123D10u: goto label_123d10;
            case 0x123D24u: goto label_123d24;
            case 0x123D40u: goto label_123d40;
            case 0x123D44u: goto label_123d44;
            case 0x123D48u: goto label_123d48;
            case 0x123D4Cu: goto label_123d4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123D58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
