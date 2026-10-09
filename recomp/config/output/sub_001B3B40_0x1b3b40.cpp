#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3B40
// Address: 0x1b3b40 - 0x1b3d90
void sub_001B3B40_0x1b3b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3B40_0x1b3b40");
#endif

    switch (ctx->pc) {
        case 0x1b3ca8u: goto label_1b3ca8;
        case 0x1b3cf4u: goto label_1b3cf4;
        case 0x1b3d18u: goto label_1b3d18;
        case 0x1b3d50u: goto label_1b3d50;
        case 0x1b3d64u: goto label_1b3d64;
        case 0x1b3d84u: goto label_1b3d84;
        default: break;
    }

    ctx->pc = 0x1b3b40u;

    // 0x1b3b40: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3B40u;
    {
        const bool branch_taken_0x1b3b40 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x1B3B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3B40u;
            // 0x1b3b44: 0x30a2000f  andi        $v0, $a1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3b40) {
            ctx->pc = 0x1B3B54u;
            goto label_1b3b54;
        }
    }
    ctx->pc = 0x1B3B48u;
    // 0x1b3b48: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3B48u;
    {
        const bool branch_taken_0x1b3b48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3B48u;
            // 0x1b3b4c: 0x260c0  sll         $t4, $v0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3b48) {
            ctx->pc = 0x1B3B58u;
            goto label_1b3b58;
        }
    }
    ctx->pc = 0x1B3B50u;
    // 0x1b3b50: 0x2442fff0  addiu       $v0, $v0, -0x10
    ctx->pc = 0x1b3b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967280));
label_1b3b54:
    // 0x1b3b54: 0x260c0  sll         $t4, $v0, 3
    ctx->pc = 0x1b3b54u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1b3b58:
    // 0x1b3b58: 0x4a10003  bgez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3B58u;
    {
        const bool branch_taken_0x1b3b58 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x1B3B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3B58u;
            // 0x1b3b5c: 0x51903  sra         $v1, $a1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3b58) {
            ctx->pc = 0x1B3B68u;
            goto label_1b3b68;
        }
    }
    ctx->pc = 0x1B3B60u;
    // 0x1b3b60: 0x24a2000f  addiu       $v0, $a1, 0xF
    ctx->pc = 0x1b3b60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x1b3b64: 0x21903  sra         $v1, $v0, 4
    ctx->pc = 0x1b3b64u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 4));
label_1b3b68:
    // 0x1b3b68: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x1b3b68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b3b6c: 0x9283c  dsll32      $a1, $t1, 0
    ctx->pc = 0x1b3b6cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 9) << (32 + 0));
    // 0x1b3b70: 0xea3021  addu        $a2, $a3, $t2
    ctx->pc = 0x1b3b70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x1b3b74: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1b3b74u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1b3b78: 0x73900  sll         $a3, $a3, 4
    ctx->pc = 0x1b3b78u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x1b3b7c: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x1b3b7cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1b3b80: 0x24e76c00  addiu       $a3, $a3, 0x6C00
    ctx->pc = 0x1b3b80u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 27648));
    // 0x1b3b84: 0x24c66c00  addiu       $a2, $a2, 0x6C00
    ctx->pc = 0x1b3b84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 27648));
    // 0x1b3b88: 0x7483c  dsll32      $t1, $a3, 0
    ctx->pc = 0x1b3b88u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) << (32 + 0));
    // 0x1b3b8c: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1b3b8cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1b3b90: 0x6383c  dsll32      $a3, $a2, 0
    ctx->pc = 0x1b3b90u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b3b94: 0x9483f  dsra32      $t1, $t1, 0
    ctx->pc = 0x1b3b94u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 0));
    // 0x1b3b98: 0x10b3021  addu        $a2, $t0, $t3
    ctx->pc = 0x1b3b98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 11)));
    // 0x1b3b9c: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x1b3b9cu;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x1b3ba0: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x1b3ba0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x1b3ba4: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x1b3ba4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1b3ba8: 0x25087200  addiu       $t0, $t0, 0x7200
    ctx->pc = 0x1b3ba8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 29184));
    // 0x1b3bac: 0x24c67200  addiu       $a2, $a2, 0x7200
    ctx->pc = 0x1b3bacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 29184));
    // 0x1b3bb0: 0x8403c  dsll32      $t0, $t0, 0
    ctx->pc = 0x1b3bb0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1b3bb4: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x1b3bb4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b3bb8: 0x8403f  dsra32      $t0, $t0, 0
    ctx->pc = 0x1b3bb8u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 0));
    // 0x1b3bbc: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x1b3bbcu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x1b3bc0: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x1b3bc0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x1b3bc4: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x1b3bc4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x1b3bc8: 0x1284025  or          $t0, $t1, $t0
    ctx->pc = 0x1b3bc8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 9) | GPR_U64(ctx, 8));
    // 0x1b3bcc: 0xe63025  or          $a2, $a3, $a2
    ctx->pc = 0x1b3bccu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1b3bd0: 0xa83825  or          $a3, $a1, $t0
    ctx->pc = 0x1b3bd0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) | GPR_U64(ctx, 8));
    // 0x1b3bd4: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1b3bd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1b3bd8: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1b3bd8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1b3bdc: 0x340c0  sll         $t0, $v1, 3
    ctx->pc = 0x1b3bdcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1b3be0: 0x331c0  sll         $a2, $v1, 7
    ctx->pc = 0x1b3be0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
    // 0x1b3be4: 0x25030008  addiu       $v1, $t0, 0x8
    ctx->pc = 0x1b3be4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
    // 0x1b3be8: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x1b3be8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x1b3bec: 0x3c083f80  lui         $t0, 0x3F80
    ctx->pc = 0x1b3becu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)16256 << 16));
    // 0x1b3bf0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1b3bf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1b3bf4: 0x8483c  dsll32      $t1, $t0, 0
    ctx->pc = 0x1b3bf4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1b3bf8: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1b3bf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1b3bfc: 0x491025  or          $v0, $v0, $t1
    ctx->pc = 0x1b3bfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 9));
    // 0x1b3c00: 0xc4100  sll         $t0, $t4, 4
    ctx->pc = 0x1b3c00u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 12), 4));
    // 0x1b3c04: 0xfc820008  sd          $v0, 0x8($a0)
    ctx->pc = 0x1b3c04u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 2));
    // 0x1b3c08: 0x1063025  or          $a2, $t0, $a2
    ctx->pc = 0x1b3c08u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 8) | GPR_U64(ctx, 6));
    // 0x1b3c0c: 0x25820008  addiu       $v0, $t4, 0x8
    ctx->pc = 0x1b3c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 8));
    // 0x1b3c10: 0xfc860010  sd          $a2, 0x10($a0)
    ctx->pc = 0x1b3c10u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 6));
    // 0x1b3c14: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1b3c14u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b3c18: 0xfc870018  sd          $a3, 0x18($a0)
    ctx->pc = 0x1b3c18u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 7));
    // 0x1b3c1c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1b3c1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b3c20: 0xfc820020  sd          $v0, 0x20($a0)
    ctx->pc = 0x1b3c20u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 32), GPR_U64(ctx, 2));
    // 0x1b3c24: 0x24820030  addiu       $v0, $a0, 0x30
    ctx->pc = 0x1b3c24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 48));
    // 0x1b3c28: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B3C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3C28u;
            // 0x1b3c2c: 0xfc850028  sd          $a1, 0x28($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 40), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3B54u: goto label_1b3b54;
            case 0x1B3B58u: goto label_1b3b58;
            case 0x1B3B68u: goto label_1b3b68;
            case 0x1B3CA8u: goto label_1b3ca8;
            case 0x1B3CB8u: goto label_1b3cb8;
            case 0x1B3CBCu: goto label_1b3cbc;
            case 0x1B3CC4u: goto label_1b3cc4;
            case 0x1B3CF4u: goto label_1b3cf4;
            case 0x1B3D18u: goto label_1b3d18;
            case 0x1B3D50u: goto label_1b3d50;
            case 0x1B3D58u: goto label_1b3d58;
            case 0x1B3D64u: goto label_1b3d64;
            case 0x1B3D84u: goto label_1b3d84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3C30u;
    // 0x1b3c30: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3C30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3B54u: goto label_1b3b54;
            case 0x1B3B58u: goto label_1b3b58;
            case 0x1B3B68u: goto label_1b3b68;
            case 0x1B3CA8u: goto label_1b3ca8;
            case 0x1B3CB8u: goto label_1b3cb8;
            case 0x1B3CBCu: goto label_1b3cbc;
            case 0x1B3CC4u: goto label_1b3cc4;
            case 0x1B3CF4u: goto label_1b3cf4;
            case 0x1B3D18u: goto label_1b3d18;
            case 0x1B3D50u: goto label_1b3d50;
            case 0x1B3D58u: goto label_1b3d58;
            case 0x1B3D64u: goto label_1b3d64;
            case 0x1B3D84u: goto label_1b3d84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3C38u;
    // 0x1b3c38: 0x0  nop
    ctx->pc = 0x1b3c38u;
    // NOP
    // 0x1b3c3c: 0x0  nop
    ctx->pc = 0x1b3c3cu;
    // NOP
    // 0x1b3c40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b3c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b3c44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3c44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3c48: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b3c48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b3c4c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b3c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b3c50: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1b3c50u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1b3c54: 0x1483004b  bne         $a0, $v1, . + 4 + (0x4B << 2)
    ctx->pc = 0x1B3C54u;
    {
        const bool branch_taken_0x1b3c54 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B3C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3C54u;
            // 0x1b3c58: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3c54) {
            ctx->pc = 0x1B3D84u;
            goto label_1b3d84;
        }
    }
    ctx->pc = 0x1B3C5Cu;
    // 0x1b3c5c: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x1b3c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1b3c60: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1b3c60u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b3c64: 0x14830017  bne         $a0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1B3C64u;
    {
        const bool branch_taken_0x1b3c64 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b3c64) {
            ctx->pc = 0x1B3CC4u;
            goto label_1b3cc4;
        }
    }
    ctx->pc = 0x1B3C6Cu;
    // 0x1b3c6c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3c6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3c70: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x1b3c70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x1b3c74: 0x8c249c7c  lw          $a0, -0x6384($at)
    ctx->pc = 0x1b3c74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294941820)));
    // 0x1b3c78: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1b3c78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1b3c7c: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B3C7Cu;
    {
        const bool branch_taken_0x1b3c7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3c7c) {
            ctx->pc = 0x1B3CC4u;
            goto label_1b3cc4;
        }
    }
    ctx->pc = 0x1B3C84u;
    // 0x1b3c84: 0x3c01003b  lui         $at, 0x3B
    ctx->pc = 0x1b3c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)59 << 16));
    // 0x1b3c88: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x1b3c88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1b3c8c: 0x84245150  lh          $a0, 0x5150($at)
    ctx->pc = 0x1b3c8cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 20816)));
    // 0x1b3c90: 0x1083000c  beq         $a0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1B3C90u;
    {
        const bool branch_taken_0x1b3c90 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b3c90) {
            ctx->pc = 0x1B3CC4u;
            goto label_1b3cc4;
        }
    }
    ctx->pc = 0x1B3C98u;
    // 0x1b3c98: 0x3c01003b  lui         $at, 0x3B
    ctx->pc = 0x1b3c98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)59 << 16));
    // 0x1b3c9c: 0x8c255160  lw          $a1, 0x5160($at)
    ctx->pc = 0x1b3c9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20832)));
    // 0x1b3ca0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B3CA0u;
    {
        const bool branch_taken_0x1b3ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3CA0u;
            // 0x1b3ca4: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ca0) {
            ctx->pc = 0x1B3CBCu;
            goto label_1b3cbc;
        }
    }
    ctx->pc = 0x1B3CA8u;
label_1b3ca8:
    // 0x1b3ca8: 0x90a40030  lbu         $a0, 0x30($a1)
    ctx->pc = 0x1b3ca8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 48)));
    // 0x1b3cac: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B3CACu;
    {
        const bool branch_taken_0x1b3cac = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b3cac) {
            ctx->pc = 0x1B3CB8u;
            goto label_1b3cb8;
        }
    }
    ctx->pc = 0x1B3CB4u;
    // 0x1b3cb4: 0xa0a0003c  sb          $zero, 0x3C($a1)
    ctx->pc = 0x1b3cb4u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 60), (uint8_t)GPR_U32(ctx, 0));
label_1b3cb8:
    // 0x1b3cb8: 0x8ca50028  lw          $a1, 0x28($a1)
    ctx->pc = 0x1b3cb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
label_1b3cbc:
    // 0x1b3cbc: 0x14a0fffa  bnez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B3CBCu;
    {
        const bool branch_taken_0x1b3cbc = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3cbc) {
            ctx->pc = 0x1B3CA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3ca8;
        }
    }
    ctx->pc = 0x1B3CC4u;
label_1b3cc4:
    // 0x1b3cc4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3cc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3cc8: 0x24030023  addiu       $v1, $zero, 0x23
    ctx->pc = 0x1b3cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x1b3ccc: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1b3cccu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b3cd0: 0x1483002c  bne         $a0, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1B3CD0u;
    {
        const bool branch_taken_0x1b3cd0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B3CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3CD0u;
            // 0x1b3cd4: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3cd0) {
            ctx->pc = 0x1B3D84u;
            goto label_1b3d84;
        }
    }
    ctx->pc = 0x1B3CD8u;
    // 0x1b3cd8: 0x8c229a8c  lw          $v0, -0x6574($at)
    ctx->pc = 0x1b3cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294941324)));
    // 0x1b3cdc: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x1b3cdcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x1b3ce0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3CE0u;
    {
        const bool branch_taken_0x1b3ce0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3CE0u;
            // 0x1b3ce4: 0x24040070  addiu       $a0, $zero, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ce0) {
            ctx->pc = 0x1B3CF4u;
            goto label_1b3cf4;
        }
    }
    ctx->pc = 0x1B3CE8u;
    // 0x1b3ce8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b3ce8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b3cec: 0xc15c17c  jal         func_5705F0
    ctx->pc = 0x1B3CECu;
    SET_GPR_U32(ctx, 31, 0x1B3CF4u);
    ctx->pc = 0x1B3CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3CECu;
            // 0x1b3cf0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5705F0u;
    {
        auto targetFn = runtime->lookupFunction(0x5705F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3CF4u; }
        if (ctx->pc != 0x1B3CF4u) { return; }
    }
    ctx->pc = 0x1B3CF4u;
label_1b3cf4:
    // 0x1b3cf4: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3cf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3cf8: 0x8c229c24  lw          $v0, -0x63DC($at)
    ctx->pc = 0x1b3cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294941732)));
    // 0x1b3cfc: 0x30420400  andi        $v0, $v0, 0x400
    ctx->pc = 0x1b3cfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1024);
    // 0x1b3d00: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B3D00u;
    {
        const bool branch_taken_0x1b3d00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3D00u;
            // 0x1b3d04: 0x24040071  addiu       $a0, $zero, 0x71 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3d00) {
            ctx->pc = 0x1B3D58u;
            goto label_1b3d58;
        }
    }
    ctx->pc = 0x1B3D08u;
    // 0x1b3d08: 0x24040071  addiu       $a0, $zero, 0x71
    ctx->pc = 0x1b3d08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
    // 0x1b3d0c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b3d0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b3d10: 0xc15c17c  jal         func_5705F0
    ctx->pc = 0x1B3D10u;
    SET_GPR_U32(ctx, 31, 0x1B3D18u);
    ctx->pc = 0x1B3D14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3D10u;
            // 0x1b3d14: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5705F0u;
    {
        auto targetFn = runtime->lookupFunction(0x5705F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3D18u; }
        if (ctx->pc != 0x1B3D18u) { return; }
    }
    ctx->pc = 0x1B3D18u;
label_1b3d18:
    // 0x1b3d18: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3d18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3d1c: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x1b3d1cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x1b3d20: 0x8c249a8c  lw          $a0, -0x6574($at)
    ctx->pc = 0x1b3d20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294941324)));
    // 0x1b3d24: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1b3d24u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1b3d28: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B3D28u;
    {
        const bool branch_taken_0x1b3d28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3d28) {
            ctx->pc = 0x1B3D64u;
            goto label_1b3d64;
        }
    }
    ctx->pc = 0x1B3D30u;
    // 0x1b3d30: 0x3c030002  lui         $v1, 0x2
    ctx->pc = 0x1b3d30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)2 << 16));
    // 0x1b3d34: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1b3d34u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1b3d38: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B3D38u;
    {
        const bool branch_taken_0x1b3d38 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3d38) {
            ctx->pc = 0x1B3D64u;
            goto label_1b3d64;
        }
    }
    ctx->pc = 0x1B3D40u;
    // 0x1b3d40: 0x24040072  addiu       $a0, $zero, 0x72
    ctx->pc = 0x1b3d40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 114));
    // 0x1b3d44: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b3d44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b3d48: 0xc15c17c  jal         func_5705F0
    ctx->pc = 0x1B3D48u;
    SET_GPR_U32(ctx, 31, 0x1B3D50u);
    ctx->pc = 0x1B3D4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3D48u;
            // 0x1b3d4c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5705F0u;
    {
        auto targetFn = runtime->lookupFunction(0x5705F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3D50u; }
        if (ctx->pc != 0x1B3D50u) { return; }
    }
    ctx->pc = 0x1B3D50u;
label_1b3d50:
    // 0x1b3d50: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3D50u;
    {
        const bool branch_taken_0x1b3d50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3d50) {
            ctx->pc = 0x1B3D64u;
            goto label_1b3d64;
        }
    }
    ctx->pc = 0x1B3D58u;
label_1b3d58:
    // 0x1b3d58: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b3d58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3d5c: 0xc15c17c  jal         func_5705F0
    ctx->pc = 0x1B3D5Cu;
    SET_GPR_U32(ctx, 31, 0x1B3D64u);
    ctx->pc = 0x1B3D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3D5Cu;
            // 0x1b3d60: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5705F0u;
    {
        auto targetFn = runtime->lookupFunction(0x5705F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3D64u; }
        if (ctx->pc != 0x1B3D64u) { return; }
    }
    ctx->pc = 0x1B3D64u;
label_1b3d64:
    // 0x1b3d64: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3d64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3d68: 0x8c239a8c  lw          $v1, -0x6574($at)
    ctx->pc = 0x1b3d68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294941324)));
    // 0x1b3d6c: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x1b3d6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x1b3d70: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3D70u;
    {
        const bool branch_taken_0x1b3d70 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3D70u;
            // 0x1b3d74: 0x24040070  addiu       $a0, $zero, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3d70) {
            ctx->pc = 0x1B3D84u;
            goto label_1b3d84;
        }
    }
    ctx->pc = 0x1B3D78u;
    // 0x1b3d78: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b3d78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3d7c: 0xc15c17c  jal         func_5705F0
    ctx->pc = 0x1B3D7Cu;
    SET_GPR_U32(ctx, 31, 0x1B3D84u);
    ctx->pc = 0x1B3D80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3D7Cu;
            // 0x1b3d80: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5705F0u;
    {
        auto targetFn = runtime->lookupFunction(0x5705F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3D84u; }
        if (ctx->pc != 0x1B3D84u) { return; }
    }
    ctx->pc = 0x1B3D84u;
label_1b3d84:
    // 0x1b3d84: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b3d84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b3d88: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B3D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3D88u;
            // 0x1b3d8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3B54u: goto label_1b3b54;
            case 0x1B3B58u: goto label_1b3b58;
            case 0x1B3B68u: goto label_1b3b68;
            case 0x1B3CA8u: goto label_1b3ca8;
            case 0x1B3CB8u: goto label_1b3cb8;
            case 0x1B3CBCu: goto label_1b3cbc;
            case 0x1B3CC4u: goto label_1b3cc4;
            case 0x1B3CF4u: goto label_1b3cf4;
            case 0x1B3D18u: goto label_1b3d18;
            case 0x1B3D50u: goto label_1b3d50;
            case 0x1B3D58u: goto label_1b3d58;
            case 0x1B3D64u: goto label_1b3d64;
            case 0x1B3D84u: goto label_1b3d84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3D90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
