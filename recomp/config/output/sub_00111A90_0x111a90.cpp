#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111A90
// Address: 0x111a90 - 0x111cf0
void sub_00111A90_0x111a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111A90_0x111a90");
#endif

    switch (ctx->pc) {
        case 0x111b88u: goto label_111b88;
        case 0x111bb8u: goto label_111bb8;
        case 0x111c60u: goto label_111c60;
        default: break;
    }

    ctx->pc = 0x111a90u;

    // 0x111a90: 0x80582d  daddu       $t3, $a0, $zero
    ctx->pc = 0x111a90u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111a94: 0x8d670000  lw          $a3, 0x0($t3)
    ctx->pc = 0x111a94u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x111a98: 0x2ce30002  sltiu       $v1, $a3, 0x2
    ctx->pc = 0x111a98u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x111a9c: 0x14600091  bnez        $v1, . + 4 + (0x91 << 2)
    ctx->pc = 0x111A9Cu;
    {
        const bool branch_taken_0x111a9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x111AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111A9Cu;
            // 0x111aa0: 0x160102d  daddu       $v0, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111a9c) {
            ctx->pc = 0x111CE4u;
            goto label_111ce4;
        }
    }
    ctx->pc = 0x111AA4u;
    // 0x111aa4: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x111aa4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x111aa8: 0x2c830002  sltiu       $v1, $a0, 0x2
    ctx->pc = 0x111aa8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x111aac: 0x1460008d  bnez        $v1, . + 4 + (0x8D << 2)
    ctx->pc = 0x111AACu;
    {
        const bool branch_taken_0x111aac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x111AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111AACu;
            // 0x111ab0: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111aac) {
            ctx->pc = 0x111CE4u;
            goto label_111ce4;
        }
    }
    ctx->pc = 0x111AB4u;
    // 0x111ab4: 0x38e20004  xori        $v0, $a3, 0x4
    ctx->pc = 0x111ab4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) ^ (uint64_t)(uint16_t)4);
    // 0x111ab8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x111AB8u;
    {
        const bool branch_taken_0x111ab8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111AB8u;
            // 0x111abc: 0x38830004  xori        $v1, $a0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111ab8) {
            ctx->pc = 0x111AE8u;
            goto label_111ae8;
        }
    }
    ctx->pc = 0x111AC0u;
    // 0x111ac0: 0x38820004  xori        $v0, $a0, 0x4
    ctx->pc = 0x111ac0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)4);
    // 0x111ac4: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x111AC4u;
    {
        const bool branch_taken_0x111ac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111ac4) {
            ctx->pc = 0x111B38u;
            goto label_111b38;
        }
    }
    ctx->pc = 0x111ACCu;
    // 0x111acc: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x111accu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x111ad0: 0x8d620004  lw          $v0, 0x4($t3)
    ctx->pc = 0x111ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
    // 0x111ad4: 0x10430018  beq         $v0, $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x111AD4u;
    {
        const bool branch_taken_0x111ad4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x111ad4) {
            ctx->pc = 0x111B38u;
            goto label_111b38;
        }
    }
    ctx->pc = 0x111ADCu;
    // 0x111adc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x111adcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x111ae0: 0x3e00008  jr          $ra
    ctx->pc = 0x111AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111AE0u;
            // 0x111ae4: 0x244285a0  addiu       $v0, $v0, -0x7A60 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935968));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111AE8u: goto label_111ae8;
            case 0x111B38u: goto label_111b38;
            case 0x111B40u: goto label_111b40;
            case 0x111B88u: goto label_111b88;
            case 0x111BACu: goto label_111bac;
            case 0x111BB8u: goto label_111bb8;
            case 0x111BE0u: goto label_111be0;
            case 0x111BF8u: goto label_111bf8;
            case 0x111BFCu: goto label_111bfc;
            case 0x111C00u: goto label_111c00;
            case 0x111C30u: goto label_111c30;
            case 0x111C40u: goto label_111c40;
            case 0x111C60u: goto label_111c60;
            case 0x111C98u: goto label_111c98;
            case 0x111CACu: goto label_111cac;
            case 0x111CE0u: goto label_111ce0;
            case 0x111CE4u: goto label_111ce4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111AE8u;
label_111ae8:
    // 0x111ae8: 0x1060007e  beqz        $v1, . + 4 + (0x7E << 2)
    ctx->pc = 0x111AE8u;
    {
        const bool branch_taken_0x111ae8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x111AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111AE8u;
            // 0x111aec: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111ae8) {
            ctx->pc = 0x111CE4u;
            goto label_111ce4;
        }
    }
    ctx->pc = 0x111AF0u;
    // 0x111af0: 0x38820002  xori        $v0, $a0, 0x2
    ctx->pc = 0x111af0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)2);
    // 0x111af4: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x111AF4u;
    {
        const bool branch_taken_0x111af4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111AF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111AF4u;
            // 0x111af8: 0x38e30002  xori        $v1, $a3, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) ^ (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111af4) {
            ctx->pc = 0x111B40u;
            goto label_111b40;
        }
    }
    ctx->pc = 0x111AFCu;
    // 0x111afc: 0x38e20002  xori        $v0, $a3, 0x2
    ctx->pc = 0x111afcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) ^ (uint64_t)(uint16_t)2);
    // 0x111b00: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x111B00u;
    {
        const bool branch_taken_0x111b00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111b00) {
            ctx->pc = 0x111B38u;
            goto label_111b38;
        }
    }
    ctx->pc = 0x111B08u;
    // 0x111b08: 0xdd640000  ld          $a0, 0x0($t3)
    ctx->pc = 0x111b08u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x111b0c: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x111b0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111b10: 0xfcc40000  sd          $a0, 0x0($a2)
    ctx->pc = 0x111b10u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 4));
    // 0x111b14: 0xdd630008  ld          $v1, 0x8($t3)
    ctx->pc = 0x111b14u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x111b18: 0xfcc30008  sd          $v1, 0x8($a2)
    ctx->pc = 0x111b18u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 3));
    // 0x111b1c: 0xdd640010  ld          $a0, 0x10($t3)
    ctx->pc = 0x111b1cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 11), 16)));
    // 0x111b20: 0xfcc40010  sd          $a0, 0x10($a2)
    ctx->pc = 0x111b20u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 4));
    // 0x111b24: 0x8d630004  lw          $v1, 0x4($t3)
    ctx->pc = 0x111b24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
    // 0x111b28: 0x8ca40004  lw          $a0, 0x4($a1)
    ctx->pc = 0x111b28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x111b2c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x111b2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x111b30: 0x3e00008  jr          $ra
    ctx->pc = 0x111B30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111B30u;
            // 0x111b34: 0xacc30004  sw          $v1, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111AE8u: goto label_111ae8;
            case 0x111B38u: goto label_111b38;
            case 0x111B40u: goto label_111b40;
            case 0x111B88u: goto label_111b88;
            case 0x111BACu: goto label_111bac;
            case 0x111BB8u: goto label_111bb8;
            case 0x111BE0u: goto label_111be0;
            case 0x111BF8u: goto label_111bf8;
            case 0x111BFCu: goto label_111bfc;
            case 0x111C00u: goto label_111c00;
            case 0x111C30u: goto label_111c30;
            case 0x111C40u: goto label_111c40;
            case 0x111C60u: goto label_111c60;
            case 0x111C98u: goto label_111c98;
            case 0x111CACu: goto label_111cac;
            case 0x111CE0u: goto label_111ce0;
            case 0x111CE4u: goto label_111ce4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111B38u;
label_111b38:
    // 0x111b38: 0x3e00008  jr          $ra
    ctx->pc = 0x111B38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111B38u;
            // 0x111b3c: 0x160102d  daddu       $v0, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111AE8u: goto label_111ae8;
            case 0x111B38u: goto label_111b38;
            case 0x111B40u: goto label_111b40;
            case 0x111B88u: goto label_111b88;
            case 0x111BACu: goto label_111bac;
            case 0x111BB8u: goto label_111bb8;
            case 0x111BE0u: goto label_111be0;
            case 0x111BF8u: goto label_111bf8;
            case 0x111BFCu: goto label_111bfc;
            case 0x111C00u: goto label_111c00;
            case 0x111C30u: goto label_111c30;
            case 0x111C40u: goto label_111c40;
            case 0x111C60u: goto label_111c60;
            case 0x111C98u: goto label_111c98;
            case 0x111CACu: goto label_111cac;
            case 0x111CE0u: goto label_111ce0;
            case 0x111CE4u: goto label_111ce4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111B40u;
label_111b40:
    // 0x111b40: 0x10600068  beqz        $v1, . + 4 + (0x68 << 2)
    ctx->pc = 0x111B40u;
    {
        const bool branch_taken_0x111b40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x111B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111B40u;
            // 0x111b44: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111b40) {
            ctx->pc = 0x111CE4u;
            goto label_111ce4;
        }
    }
    ctx->pc = 0x111B48u;
    // 0x111b48: 0x8d680008  lw          $t0, 0x8($t3)
    ctx->pc = 0x111b48u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x111b4c: 0x8ca70008  lw          $a3, 0x8($a1)
    ctx->pc = 0x111b4cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x111b50: 0xdd6a0010  ld          $t2, 0x10($t3)
    ctx->pc = 0x111b50u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 11), 16)));
    // 0x111b54: 0x1071023  subu        $v0, $t0, $a3
    ctx->pc = 0x111b54u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x111b58: 0x22023  negu        $a0, $v0
    ctx->pc = 0x111b58u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x111b5c: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x111b5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x111b60: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x111b60u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x111b64: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x111b64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x111b68: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x111B68u;
    {
        const bool branch_taken_0x111b68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111B6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111B68u;
            // 0x111b6c: 0xdca90010  ld          $t1, 0x10($a1) (Delay Slot)
        SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 5), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111b68) {
            ctx->pc = 0x111BE0u;
            goto label_111be0;
        }
    }
    ctx->pc = 0x111B70u;
    // 0x111b70: 0xe8102a  slt         $v0, $a3, $t0
    ctx->pc = 0x111b70u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x111b74: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x111B74u;
    {
        const bool branch_taken_0x111b74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111B74u;
            // 0x111b78: 0x107102a  slt         $v0, $t0, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111b74) {
            ctx->pc = 0x111BACu;
            goto label_111bac;
        }
    }
    ctx->pc = 0x111B7Cu;
    // 0x111b7c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x111b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x111b80: 0x1073823  subu        $a3, $t0, $a3
    ctx->pc = 0x111b80u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x111b84: 0x0  nop
    ctx->pc = 0x111b84u;
    // NOP
label_111b88:
    // 0x111b88: 0x9187a  dsrl        $v1, $t1, 1
    ctx->pc = 0x111b88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) >> 1);
    // 0x111b8c: 0x1241024  and         $v0, $t1, $a0
    ctx->pc = 0x111b8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) & GPR_U64(ctx, 4));
    // 0x111b90: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x111b90u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x111b94: 0x0  nop
    ctx->pc = 0x111b94u;
    // NOP
    // 0x111b98: 0x0  nop
    ctx->pc = 0x111b98u;
    // NOP
    // 0x111b9c: 0x14e0fffa  bnez        $a3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x111B9Cu;
    {
        const bool branch_taken_0x111b9c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x111BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111B9Cu;
            // 0x111ba0: 0x434825  or          $t1, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111b9c) {
            ctx->pc = 0x111B88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_111b88;
        }
    }
    ctx->pc = 0x111BA4u;
    // 0x111ba4: 0x100382d  daddu       $a3, $t0, $zero
    ctx->pc = 0x111ba4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ba8: 0x107102a  slt         $v0, $t0, $a3
    ctx->pc = 0x111ba8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
label_111bac:
    // 0x111bac: 0x50400014  beql        $v0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x111BACu;
    {
        const bool branch_taken_0x111bac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x111bac) {
            ctx->pc = 0x111BB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111BACu;
            // 0x111bb0: 0x8d640004  lw          $a0, 0x4($t3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111C00u;
            goto label_111c00;
        }
    }
    ctx->pc = 0x111BB4u;
    // 0x111bb4: 0x240c0001  addiu       $t4, $zero, 0x1
    ctx->pc = 0x111bb4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_111bb8:
    // 0x111bb8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x111bb8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x111bbc: 0xa107a  dsrl        $v0, $t2, 1
    ctx->pc = 0x111bbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) >> 1);
    // 0x111bc0: 0x14c1824  and         $v1, $t2, $t4
    ctx->pc = 0x111bc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) & GPR_U64(ctx, 12));
    // 0x111bc4: 0x107202a  slt         $a0, $t0, $a3
    ctx->pc = 0x111bc4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x111bc8: 0x0  nop
    ctx->pc = 0x111bc8u;
    // NOP
    // 0x111bcc: 0x1480fffa  bnez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x111BCCu;
    {
        const bool branch_taken_0x111bcc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x111BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111BCCu;
            // 0x111bd0: 0x625025  or          $t2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111bcc) {
            ctx->pc = 0x111BB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_111bb8;
        }
    }
    ctx->pc = 0x111BD4u;
    // 0x111bd4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x111BD4u;
    {
        const bool branch_taken_0x111bd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111BD4u;
            // 0x111bd8: 0x8d640004  lw          $a0, 0x4($t3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111bd4) {
            ctx->pc = 0x111C00u;
            goto label_111c00;
        }
    }
    ctx->pc = 0x111BDCu;
    // 0x111bdc: 0x0  nop
    ctx->pc = 0x111bdcu;
    // NOP
label_111be0:
    // 0x111be0: 0xe8102a  slt         $v0, $a3, $t0
    ctx->pc = 0x111be0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x111be4: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x111BE4u;
    {
        const bool branch_taken_0x111be4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x111be4) {
            ctx->pc = 0x111BE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111BE4u;
            // 0x111be8: 0xe0402d  daddu       $t0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111BF8u;
            goto label_111bf8;
        }
    }
    ctx->pc = 0x111BECu;
    // 0x111bec: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x111BECu;
    {
        const bool branch_taken_0x111bec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111BECu;
            // 0x111bf0: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111bec) {
            ctx->pc = 0x111BFCu;
            goto label_111bfc;
        }
    }
    ctx->pc = 0x111BF4u;
    // 0x111bf4: 0x0  nop
    ctx->pc = 0x111bf4u;
    // NOP
label_111bf8:
    // 0x111bf8: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x111bf8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_111bfc:
    // 0x111bfc: 0x8d640004  lw          $a0, 0x4($t3)
    ctx->pc = 0x111bfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
label_111c00:
    // 0x111c00: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x111c00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x111c04: 0x10820024  beq         $a0, $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x111C04u;
    {
        const bool branch_taken_0x111c04 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x111C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111C04u;
            // 0x111c08: 0x149102f  dsubu       $v0, $t2, $t1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) - GPR_U64(ctx, 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111c04) {
            ctx->pc = 0x111C98u;
            goto label_111c98;
        }
    }
    ctx->pc = 0x111C0Cu;
    // 0x111c0c: 0x12a182f  dsubu       $v1, $t1, $t2
    ctx->pc = 0x111c0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) - GPR_U64(ctx, 10));
    // 0x111c10: 0x44180a  movz        $v1, $v0, $a0
    ctx->pc = 0x111c10u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 2));
    // 0x111c14: 0x4620006  bltzl       $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x111C14u;
    {
        const bool branch_taken_0x111c14 = (GPR_S64(ctx, 3) < 0);
        if (branch_taken_0x111c14) {
            ctx->pc = 0x111C18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111C14u;
            // 0x111c18: 0x3182f  dsubu       $v1, $zero, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) - GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111C30u;
            goto label_111c30;
        }
    }
    ctx->pc = 0x111C1Cu;
    // 0x111c1c: 0xacc80008  sw          $t0, 0x8($a2)
    ctx->pc = 0x111c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 8));
    // 0x111c20: 0xfcc30010  sd          $v1, 0x10($a2)
    ctx->pc = 0x111c20u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 3));
    // 0x111c24: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x111C24u;
    {
        const bool branch_taken_0x111c24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111C24u;
            // 0x111c28: 0xacc00004  sw          $zero, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111c24) {
            ctx->pc = 0x111C40u;
            goto label_111c40;
        }
    }
    ctx->pc = 0x111C2Cu;
    // 0x111c2c: 0x0  nop
    ctx->pc = 0x111c2cu;
    // NOP
label_111c30:
    // 0x111c30: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x111c30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x111c34: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x111c34u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x111c38: 0xacc80008  sw          $t0, 0x8($a2)
    ctx->pc = 0x111c38u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 8));
    // 0x111c3c: 0xfcc30010  sd          $v1, 0x10($a2)
    ctx->pc = 0x111c3cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 3));
label_111c40:
    // 0x111c40: 0xdcc70010  ld          $a3, 0x10($a2)
    ctx->pc = 0x111c40u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x111c44: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x111c44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111c48: 0x21178  dsll        $v0, $v0, 5
    ctx->pc = 0x111c48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 5);
    // 0x111c4c: 0x2113a  dsrl        $v0, $v0, 4
    ctx->pc = 0x111c4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 4);
    // 0x111c50: 0x64e3ffff  daddiu      $v1, $a3, -0x1
    ctx->pc = 0x111c50u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 7) + (int64_t)(int32_t)4294967295);
    // 0x111c54: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x111c54u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x111c58: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x111C58u;
    {
        const bool branch_taken_0x111c58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111c58) {
            ctx->pc = 0x111CACu;
            goto label_111cac;
        }
    }
    ctx->pc = 0x111C60u;
label_111c60:
    // 0x111c60: 0x72878  dsll        $a1, $a3, 1
    ctx->pc = 0x111c60u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) << 1);
    // 0x111c64: 0x8cc20008  lw          $v0, 0x8($a2)
    ctx->pc = 0x111c64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x111c68: 0x64a3ffff  daddiu      $v1, $a1, -0x1
    ctx->pc = 0x111c68u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x111c6c: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x111c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111c70: 0x42178  dsll        $a0, $a0, 5
    ctx->pc = 0x111c70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 5);
    // 0x111c74: 0x4213a  dsrl        $a0, $a0, 4
    ctx->pc = 0x111c74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> 4);
    // 0x111c78: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x111c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x111c7c: 0x83202b  sltu        $a0, $a0, $v1
    ctx->pc = 0x111c7cu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x111c80: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x111c80u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
    // 0x111c84: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x111c84u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111c88: 0x1080fff5  beqz        $a0, . + 4 + (-0xB << 2)
    ctx->pc = 0x111C88u;
    {
        const bool branch_taken_0x111c88 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x111C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111C88u;
            // 0x111c8c: 0xfcc50010  sd          $a1, 0x10($a2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111c88) {
            ctx->pc = 0x111C60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_111c60;
        }
    }
    ctx->pc = 0x111C90u;
    // 0x111c90: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x111C90u;
    {
        const bool branch_taken_0x111c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x111c90) {
            ctx->pc = 0x111CACu;
            goto label_111cac;
        }
    }
    ctx->pc = 0x111C98u;
label_111c98:
    // 0x111c98: 0x149102d  daddu       $v0, $t2, $t1
    ctx->pc = 0x111c98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 9));
    // 0x111c9c: 0xacc40004  sw          $a0, 0x4($a2)
    ctx->pc = 0x111c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 4));
    // 0x111ca0: 0xacc80008  sw          $t0, 0x8($a2)
    ctx->pc = 0x111ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 8));
    // 0x111ca4: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x111ca4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ca8: 0xfcc20010  sd          $v0, 0x10($a2)
    ctx->pc = 0x111ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 2));
label_111cac:
    // 0x111cac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x111cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111cb0: 0x210fa  dsrl        $v0, $v0, 3
    ctx->pc = 0x111cb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 3);
    // 0x111cb4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x111cb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x111cb8: 0x47102b  sltu        $v0, $v0, $a3
    ctx->pc = 0x111cb8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x111cbc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x111CBCu;
    {
        const bool branch_taken_0x111cbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111CBCu;
            // 0x111cc0: 0xacc30000  sw          $v1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111cbc) {
            ctx->pc = 0x111CE0u;
            goto label_111ce0;
        }
    }
    ctx->pc = 0x111CC4u;
    // 0x111cc4: 0x8cc20008  lw          $v0, 0x8($a2)
    ctx->pc = 0x111cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x111cc8: 0x7207a  dsrl        $a0, $a3, 1
    ctx->pc = 0x111cc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) >> 1);
    // 0x111ccc: 0x30e30001  andi        $v1, $a3, 0x1
    ctx->pc = 0x111cccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)1);
    // 0x111cd0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x111cd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x111cd4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x111cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x111cd8: 0xfcc30010  sd          $v1, 0x10($a2)
    ctx->pc = 0x111cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 3));
    // 0x111cdc: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x111cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
label_111ce0:
    // 0x111ce0: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x111ce0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_111ce4:
    // 0x111ce4: 0x3e00008  jr          $ra
    ctx->pc = 0x111CE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111AE8u: goto label_111ae8;
            case 0x111B38u: goto label_111b38;
            case 0x111B40u: goto label_111b40;
            case 0x111B88u: goto label_111b88;
            case 0x111BACu: goto label_111bac;
            case 0x111BB8u: goto label_111bb8;
            case 0x111BE0u: goto label_111be0;
            case 0x111BF8u: goto label_111bf8;
            case 0x111BFCu: goto label_111bfc;
            case 0x111C00u: goto label_111c00;
            case 0x111C30u: goto label_111c30;
            case 0x111C40u: goto label_111c40;
            case 0x111C60u: goto label_111c60;
            case 0x111C98u: goto label_111c98;
            case 0x111CACu: goto label_111cac;
            case 0x111CE0u: goto label_111ce0;
            case 0x111CE4u: goto label_111ce4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111CECu;
    // 0x111cec: 0x0  nop
    ctx->pc = 0x111cecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
