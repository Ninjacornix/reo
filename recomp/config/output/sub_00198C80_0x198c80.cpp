#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198C80
// Address: 0x198c80 - 0x199380
void sub_00198C80_0x198c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198C80_0x198c80");
#endif

    ctx->pc = 0x198c80u;

    // 0x198c80: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x198c80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x198c84: 0xac830048  sw          $v1, 0x48($a0)
    ctx->pc = 0x198c84u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 3));
    // 0x198c88: 0xac80004c  sw          $zero, 0x4C($a0)
    ctx->pc = 0x198c88u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 0));
    // 0x198c8c: 0x3c03ff00  lui         $v1, 0xFF00
    ctx->pc = 0x198c8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65280 << 16));
    // 0x198c90: 0x8c86000c  lw          $a2, 0xC($a0)
    ctx->pc = 0x198c90u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x198c94: 0x8c870004  lw          $a3, 0x4($a0)
    ctx->pc = 0x198c94u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x198c98: 0x8c850008  lw          $a1, 0x8($a0)
    ctx->pc = 0x198c98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x198c9c: 0xc31824  and         $v1, $a2, $v1
    ctx->pc = 0x198c9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x198ca0: 0x6323c  dsll32      $a2, $a2, 8
    ctx->pc = 0x198ca0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 8));
    // 0x198ca4: 0x6323e  dsrl32      $a2, $a2, 8
    ctx->pc = 0x198ca4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 8));
    // 0x198ca8: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198CA8u;
    {
        const bool branch_taken_0x198ca8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x198CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198CA8u;
            // 0x198cac: 0xe52825  or          $a1, $a3, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198ca8) {
            ctx->pc = 0x198CB8u;
            goto label_198cb8;
        }
    }
    ctx->pc = 0x198CB0u;
    // 0x198cb0: 0x100001b1  b           . + 4 + (0x1B1 << 2)
    ctx->pc = 0x198CB0u;
    {
        const bool branch_taken_0x198cb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198cb0) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198CB8u;
label_198cb8:
    // 0x198cb8: 0x3c030002  lui         $v1, 0x2
    ctx->pc = 0x198cb8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)2 << 16));
    // 0x198cbc: 0x34674080  ori         $a3, $v1, 0x4080
    ctx->pc = 0x198cbcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16512);
    // 0x198cc0: 0x10c7019f  beq         $a2, $a3, . + 4 + (0x19F << 2)
    ctx->pc = 0x198CC0u;
    {
        const bool branch_taken_0x198cc0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198CC0u;
            // 0x198cc4: 0x34674380  ori         $a3, $v1, 0x4380 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17280);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198cc0) {
            ctx->pc = 0x199340u;
            goto label_199340;
        }
    }
    ctx->pc = 0x198CC8u;
    // 0x198cc8: 0x10c7018e  beq         $a2, $a3, . + 4 + (0x18E << 2)
    ctx->pc = 0x198CC8u;
    {
        const bool branch_taken_0x198cc8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198cc8) {
            ctx->pc = 0x199304u;
            goto label_199304;
        }
    }
    ctx->pc = 0x198CD0u;
    // 0x198cd0: 0x3467c380  ori         $a3, $v1, 0xC380
    ctx->pc = 0x198cd0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)50048);
    // 0x198cd4: 0x10c7017c  beq         $a2, $a3, . + 4 + (0x17C << 2)
    ctx->pc = 0x198CD4u;
    {
        const bool branch_taken_0x198cd4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198CD4u;
            // 0x198cd8: 0x34678802  ori         $a3, $v1, 0x8802 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)34818);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198cd4) {
            ctx->pc = 0x1992C8u;
            goto label_1992c8;
        }
    }
    ctx->pc = 0x198CDCu;
    // 0x198cdc: 0x10c7015e  beq         $a2, $a3, . + 4 + (0x15E << 2)
    ctx->pc = 0x198CDCu;
    {
        const bool branch_taken_0x198cdc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198cdc) {
            ctx->pc = 0x199258u;
            goto label_199258;
        }
    }
    ctx->pc = 0x198CE4u;
    // 0x198ce4: 0x3467c802  ori         $a3, $v1, 0xC802
    ctx->pc = 0x198ce4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)51202);
    // 0x198ce8: 0x10c7013f  beq         $a2, $a3, . + 4 + (0x13F << 2)
    ctx->pc = 0x198CE8u;
    {
        const bool branch_taken_0x198ce8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198CECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198CE8u;
            // 0x198cec: 0x3467c822  ori         $a3, $v1, 0xC822 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)51234);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198ce8) {
            ctx->pc = 0x1991E8u;
            goto label_1991e8;
        }
    }
    ctx->pc = 0x198CF0u;
    // 0x198cf0: 0x10c70121  beq         $a2, $a3, . + 4 + (0x121 << 2)
    ctx->pc = 0x198CF0u;
    {
        const bool branch_taken_0x198cf0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198cf0) {
            ctx->pc = 0x199178u;
            goto label_199178;
        }
    }
    ctx->pc = 0x198CF8u;
    // 0x198cf8: 0x3407c802  ori         $a3, $zero, 0xC802
    ctx->pc = 0x198cf8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)51202);
    // 0x198cfc: 0x10c7010f  beq         $a2, $a3, . + 4 + (0x10F << 2)
    ctx->pc = 0x198CFCu;
    {
        const bool branch_taken_0x198cfc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198CFCu;
            // 0x198d00: 0x34078882  ori         $a3, $zero, 0x8882 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)34946);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198cfc) {
            ctx->pc = 0x19913Cu;
            goto label_19913c;
        }
    }
    ctx->pc = 0x198D04u;
    // 0x198d04: 0x10c700f1  beq         $a2, $a3, . + 4 + (0xF1 << 2)
    ctx->pc = 0x198D04u;
    {
        const bool branch_taken_0x198d04 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198d04) {
            ctx->pc = 0x1990CCu;
            goto label_1990cc;
        }
    }
    ctx->pc = 0x198D0Cu;
    // 0x198d0c: 0x3467c080  ori         $a3, $v1, 0xC080
    ctx->pc = 0x198d0cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)49280);
    // 0x198d10: 0x10c700df  beq         $a2, $a3, . + 4 + (0xDF << 2)
    ctx->pc = 0x198D10u;
    {
        const bool branch_taken_0x198d10 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198D10u;
            // 0x198d14: 0x3467c000  ori         $a3, $v1, 0xC000 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)49152);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198d10) {
            ctx->pc = 0x199090u;
            goto label_199090;
        }
    }
    ctx->pc = 0x198D18u;
    // 0x198d18: 0x10c700ce  beq         $a2, $a3, . + 4 + (0xCE << 2)
    ctx->pc = 0x198D18u;
    {
        const bool branch_taken_0x198d18 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198d18) {
            ctx->pc = 0x199054u;
            goto label_199054;
        }
    }
    ctx->pc = 0x198D20u;
    // 0x198d20: 0x3407c202  ori         $a3, $zero, 0xC202
    ctx->pc = 0x198d20u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49666);
    // 0x198d24: 0x10c700af  beq         $a2, $a3, . + 4 + (0xAF << 2)
    ctx->pc = 0x198D24u;
    {
        const bool branch_taken_0x198d24 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198D24u;
            // 0x198d28: 0x34674000  ori         $a3, $v1, 0x4000 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16384);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198d24) {
            ctx->pc = 0x198FE4u;
            goto label_198fe4;
        }
    }
    ctx->pc = 0x198D2Cu;
    // 0x198d2c: 0x10c7009e  beq         $a2, $a3, . + 4 + (0x9E << 2)
    ctx->pc = 0x198D2Cu;
    {
        const bool branch_taken_0x198d2c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198d2c) {
            ctx->pc = 0x198FA8u;
            goto label_198fa8;
        }
    }
    ctx->pc = 0x198D34u;
    // 0x198d34: 0x24074000  addiu       $a3, $zero, 0x4000
    ctx->pc = 0x198d34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x198d38: 0x10c7008c  beq         $a2, $a3, . + 4 + (0x8C << 2)
    ctx->pc = 0x198D38u;
    {
        const bool branch_taken_0x198d38 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198D38u;
            // 0x198d3c: 0x24074002  addiu       $a3, $zero, 0x4002 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16386));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198d38) {
            ctx->pc = 0x198F6Cu;
            goto label_198f6c;
        }
    }
    ctx->pc = 0x198D40u;
    // 0x198d40: 0x10c7007b  beq         $a2, $a3, . + 4 + (0x7B << 2)
    ctx->pc = 0x198D40u;
    {
        const bool branch_taken_0x198d40 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198d40) {
            ctx->pc = 0x198F30u;
            goto label_198f30;
        }
    }
    ctx->pc = 0x198D48u;
    // 0x198d48: 0x24074202  addiu       $a3, $zero, 0x4202
    ctx->pc = 0x198d48u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16898));
    // 0x198d4c: 0x10c70069  beq         $a2, $a3, . + 4 + (0x69 << 2)
    ctx->pc = 0x198D4Cu;
    {
        const bool branch_taken_0x198d4c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198d4c) {
            ctx->pc = 0x198EF4u;
            goto label_198ef4;
        }
    }
    ctx->pc = 0x198D54u;
    // 0x198d54: 0x10c3004e  beq         $a2, $v1, . + 4 + (0x4E << 2)
    ctx->pc = 0x198D54u;
    {
        const bool branch_taken_0x198d54 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x198D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198D54u;
            // 0x198d58: 0x3c070012  lui         $a3, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)18 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198d54) {
            ctx->pc = 0x198E90u;
            goto label_198e90;
        }
    }
    ctx->pc = 0x198D5Cu;
    // 0x198d5c: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x198d5cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x198d60: 0x10c70032  beq         $a2, $a3, . + 4 + (0x32 << 2)
    ctx->pc = 0x198D60u;
    {
        const bool branch_taken_0x198d60 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198D60u;
            // 0x198d64: 0x3c070012  lui         $a3, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)18 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198d60) {
            ctx->pc = 0x198E2Cu;
            goto label_198e2c;
        }
    }
    ctx->pc = 0x198D68u;
    // 0x198d68: 0x34078802  ori         $a3, $zero, 0x8802
    ctx->pc = 0x198d68u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)34818);
    // 0x198d6c: 0x10c70013  beq         $a2, $a3, . + 4 + (0x13 << 2)
    ctx->pc = 0x198D6Cu;
    {
        const bool branch_taken_0x198d6c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        ctx->pc = 0x198D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198D6Cu;
            // 0x198d70: 0x34670080  ori         $a3, $v1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198d6c) {
            ctx->pc = 0x198DBCu;
            goto label_198dbc;
        }
    }
    ctx->pc = 0x198D74u;
    // 0x198d74: 0x10c70003  beq         $a2, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x198D74u;
    {
        const bool branch_taken_0x198d74 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 7));
        if (branch_taken_0x198d74) {
            ctx->pc = 0x198D84u;
            goto label_198d84;
        }
    }
    ctx->pc = 0x198D7Cu;
    // 0x198d7c: 0x1000017e  b           . + 4 + (0x17E << 2)
    ctx->pc = 0x198D7Cu;
    {
        const bool branch_taken_0x198d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198d7c) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198D84u;
label_198d84:
    // 0x198d84: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x198d84u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x198d88: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x198d88u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x198d8c: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198D8Cu;
    {
        const bool branch_taken_0x198d8c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198d8c) {
            ctx->pc = 0x198DA8u;
            goto label_198da8;
        }
    }
    ctx->pc = 0x198D94u;
    // 0x198d94: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198d94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198d98: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198D98u;
    {
        const bool branch_taken_0x198d98 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198d98) {
            ctx->pc = 0x198DA8u;
            goto label_198da8;
        }
    }
    ctx->pc = 0x198DA0u;
    // 0x198da0: 0x10000175  b           . + 4 + (0x175 << 2)
    ctx->pc = 0x198DA0u;
    {
        const bool branch_taken_0x198da0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198da0) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198DA8u;
label_198da8:
    // 0x198da8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198da8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198dac: 0xac800048  sw          $zero, 0x48($a0)
    ctx->pc = 0x198dacu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 0));
    // 0x198db0: 0x246301f0  addiu       $v1, $v1, 0x1F0
    ctx->pc = 0x198db0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 496));
    // 0x198db4: 0x10000170  b           . + 4 + (0x170 << 2)
    ctx->pc = 0x198DB4u;
    {
        const bool branch_taken_0x198db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198DB4u;
            // 0x198db8: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198db4) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198DBCu;
label_198dbc:
    // 0x198dbc: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x198dbcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x198dc0: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x198dc0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x198dc4: 0x10a60013  beq         $a1, $a2, . + 4 + (0x13 << 2)
    ctx->pc = 0x198DC4u;
    {
        const bool branch_taken_0x198dc4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x198DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198DC4u;
            // 0x198dc8: 0x3c060032  lui         $a2, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198dc4) {
            ctx->pc = 0x198E14u;
            goto label_198e14;
        }
    }
    ctx->pc = 0x198DCCu;
    // 0x198dcc: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x198dccu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x198dd0: 0x10a60010  beq         $a1, $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x198DD0u;
    {
        const bool branch_taken_0x198dd0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198dd0) {
            ctx->pc = 0x198E14u;
            goto label_198e14;
        }
    }
    ctx->pc = 0x198DD8u;
    // 0x198dd8: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x198dd8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x198ddc: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x198ddcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x198de0: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198DE0u;
    {
        const bool branch_taken_0x198de0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198de0) {
            ctx->pc = 0x198DFCu;
            goto label_198dfc;
        }
    }
    ctx->pc = 0x198DE8u;
    // 0x198de8: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198de8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198dec: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198DECu;
    {
        const bool branch_taken_0x198dec = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198dec) {
            ctx->pc = 0x198DFCu;
            goto label_198dfc;
        }
    }
    ctx->pc = 0x198DF4u;
    // 0x198df4: 0x10000160  b           . + 4 + (0x160 << 2)
    ctx->pc = 0x198DF4u;
    {
        const bool branch_taken_0x198df4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198df4) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198DFCu;
label_198dfc:
    // 0x198dfc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x198dfcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x198e00: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198e00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198e04: 0x24630220  addiu       $v1, $v1, 0x220
    ctx->pc = 0x198e04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 544));
    // 0x198e08: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198e08u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198e0c: 0x1000015a  b           . + 4 + (0x15A << 2)
    ctx->pc = 0x198E0Cu;
    {
        const bool branch_taken_0x198e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198E0Cu;
            // 0x198e10: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198e0c) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198E14u;
label_198e14:
    // 0x198e14: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x198e14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x198e18: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198e18u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198e1c: 0x24630260  addiu       $v1, $v1, 0x260
    ctx->pc = 0x198e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 608));
    // 0x198e20: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198e20u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198e24: 0x10000154  b           . + 4 + (0x154 << 2)
    ctx->pc = 0x198E24u;
    {
        const bool branch_taken_0x198e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198E24u;
            // 0x198e28: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198e24) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198E2Cu;
label_198e2c:
    // 0x198e2c: 0x34e61025  ori         $a2, $a3, 0x1025
    ctx->pc = 0x198e2cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)4133);
    // 0x198e30: 0x10a60011  beq         $a1, $a2, . + 4 + (0x11 << 2)
    ctx->pc = 0x198E30u;
    {
        const bool branch_taken_0x198e30 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x198E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198E30u;
            // 0x198e34: 0x34661025  ori         $a2, $v1, 0x1025 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4133);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198e30) {
            ctx->pc = 0x198E78u;
            goto label_198e78;
        }
    }
    ctx->pc = 0x198E38u;
    // 0x198e38: 0x10a6000f  beq         $a1, $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x198E38u;
    {
        const bool branch_taken_0x198e38 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198e38) {
            ctx->pc = 0x198E78u;
            goto label_198e78;
        }
    }
    ctx->pc = 0x198E40u;
    // 0x198e40: 0x34e61035  ori         $a2, $a3, 0x1035
    ctx->pc = 0x198e40u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)4149);
    // 0x198e44: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198E44u;
    {
        const bool branch_taken_0x198e44 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198e44) {
            ctx->pc = 0x198E60u;
            goto label_198e60;
        }
    }
    ctx->pc = 0x198E4Cu;
    // 0x198e4c: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198e4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198e50: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198E50u;
    {
        const bool branch_taken_0x198e50 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198e50) {
            ctx->pc = 0x198E60u;
            goto label_198e60;
        }
    }
    ctx->pc = 0x198E58u;
    // 0x198e58: 0x10000147  b           . + 4 + (0x147 << 2)
    ctx->pc = 0x198E58u;
    {
        const bool branch_taken_0x198e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198e58) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198E60u;
label_198e60:
    // 0x198e60: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x198e60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x198e64: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198e64u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198e68: 0x24630290  addiu       $v1, $v1, 0x290
    ctx->pc = 0x198e68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 656));
    // 0x198e6c: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198e70: 0x10000141  b           . + 4 + (0x141 << 2)
    ctx->pc = 0x198E70u;
    {
        const bool branch_taken_0x198e70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198E70u;
            // 0x198e74: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198e70) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198E78u;
label_198e78:
    // 0x198e78: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x198e78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x198e7c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198e7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198e80: 0x246302c0  addiu       $v1, $v1, 0x2C0
    ctx->pc = 0x198e80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 704));
    // 0x198e84: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198e84u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198e88: 0x1000013b  b           . + 4 + (0x13B << 2)
    ctx->pc = 0x198E88u;
    {
        const bool branch_taken_0x198e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198E88u;
            // 0x198e8c: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198e88) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198E90u;
label_198e90:
    // 0x198e90: 0x34e61025  ori         $a2, $a3, 0x1025
    ctx->pc = 0x198e90u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)4133);
    // 0x198e94: 0x10a60011  beq         $a1, $a2, . + 4 + (0x11 << 2)
    ctx->pc = 0x198E94u;
    {
        const bool branch_taken_0x198e94 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x198E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198E94u;
            // 0x198e98: 0x34661025  ori         $a2, $v1, 0x1025 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4133);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198e94) {
            ctx->pc = 0x198EDCu;
            goto label_198edc;
        }
    }
    ctx->pc = 0x198E9Cu;
    // 0x198e9c: 0x10a6000f  beq         $a1, $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x198E9Cu;
    {
        const bool branch_taken_0x198e9c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198e9c) {
            ctx->pc = 0x198EDCu;
            goto label_198edc;
        }
    }
    ctx->pc = 0x198EA4u;
    // 0x198ea4: 0x34e61035  ori         $a2, $a3, 0x1035
    ctx->pc = 0x198ea4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)4149);
    // 0x198ea8: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198EA8u;
    {
        const bool branch_taken_0x198ea8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198ea8) {
            ctx->pc = 0x198EC4u;
            goto label_198ec4;
        }
    }
    ctx->pc = 0x198EB0u;
    // 0x198eb0: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198eb0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198eb4: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198EB4u;
    {
        const bool branch_taken_0x198eb4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198eb4) {
            ctx->pc = 0x198EC4u;
            goto label_198ec4;
        }
    }
    ctx->pc = 0x198EBCu;
    // 0x198ebc: 0x1000012e  b           . + 4 + (0x12E << 2)
    ctx->pc = 0x198EBCu;
    {
        const bool branch_taken_0x198ebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198ebc) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198EC4u;
label_198ec4:
    // 0x198ec4: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x198ec4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x198ec8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198ecc: 0x246302f0  addiu       $v1, $v1, 0x2F0
    ctx->pc = 0x198eccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 752));
    // 0x198ed0: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198ed0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198ed4: 0x10000128  b           . + 4 + (0x128 << 2)
    ctx->pc = 0x198ED4u;
    {
        const bool branch_taken_0x198ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198ED4u;
            // 0x198ed8: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198ed4) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198EDCu;
label_198edc:
    // 0x198edc: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x198edcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x198ee0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198ee0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198ee4: 0x24630320  addiu       $v1, $v1, 0x320
    ctx->pc = 0x198ee4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 800));
    // 0x198ee8: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198ee8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198eec: 0x10000122  b           . + 4 + (0x122 << 2)
    ctx->pc = 0x198EECu;
    {
        const bool branch_taken_0x198eec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198EECu;
            // 0x198ef0: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198eec) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198EF4u;
label_198ef4:
    // 0x198ef4: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x198ef4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x198ef8: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x198ef8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x198efc: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198EFCu;
    {
        const bool branch_taken_0x198efc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198efc) {
            ctx->pc = 0x198F18u;
            goto label_198f18;
        }
    }
    ctx->pc = 0x198F04u;
    // 0x198f04: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198f04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198f08: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198F08u;
    {
        const bool branch_taken_0x198f08 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198f08) {
            ctx->pc = 0x198F18u;
            goto label_198f18;
        }
    }
    ctx->pc = 0x198F10u;
    // 0x198f10: 0x10000119  b           . + 4 + (0x119 << 2)
    ctx->pc = 0x198F10u;
    {
        const bool branch_taken_0x198f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198f10) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198F18u;
label_198f18:
    // 0x198f18: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x198f18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x198f1c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198f20: 0x24630350  addiu       $v1, $v1, 0x350
    ctx->pc = 0x198f20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 848));
    // 0x198f24: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198f24u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198f28: 0x10000113  b           . + 4 + (0x113 << 2)
    ctx->pc = 0x198F28u;
    {
        const bool branch_taken_0x198f28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198F28u;
            // 0x198f2c: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198f28) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198F30u;
label_198f30:
    // 0x198f30: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x198f30u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x198f34: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x198f34u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x198f38: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198F38u;
    {
        const bool branch_taken_0x198f38 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198f38) {
            ctx->pc = 0x198F54u;
            goto label_198f54;
        }
    }
    ctx->pc = 0x198F40u;
    // 0x198f40: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198f40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198f44: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198F44u;
    {
        const bool branch_taken_0x198f44 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198f44) {
            ctx->pc = 0x198F54u;
            goto label_198f54;
        }
    }
    ctx->pc = 0x198F4Cu;
    // 0x198f4c: 0x1000010a  b           . + 4 + (0x10A << 2)
    ctx->pc = 0x198F4Cu;
    {
        const bool branch_taken_0x198f4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198f4c) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198F54u;
label_198f54:
    // 0x198f54: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x198f54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x198f58: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198f58u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198f5c: 0x24630380  addiu       $v1, $v1, 0x380
    ctx->pc = 0x198f5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 896));
    // 0x198f60: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198f60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198f64: 0x10000104  b           . + 4 + (0x104 << 2)
    ctx->pc = 0x198F64u;
    {
        const bool branch_taken_0x198f64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198F64u;
            // 0x198f68: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198f64) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198F6Cu;
label_198f6c:
    // 0x198f6c: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x198f6cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x198f70: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x198f70u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x198f74: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198F74u;
    {
        const bool branch_taken_0x198f74 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198f74) {
            ctx->pc = 0x198F90u;
            goto label_198f90;
        }
    }
    ctx->pc = 0x198F7Cu;
    // 0x198f7c: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198f7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198f80: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198F80u;
    {
        const bool branch_taken_0x198f80 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198f80) {
            ctx->pc = 0x198F90u;
            goto label_198f90;
        }
    }
    ctx->pc = 0x198F88u;
    // 0x198f88: 0x100000fb  b           . + 4 + (0xFB << 2)
    ctx->pc = 0x198F88u;
    {
        const bool branch_taken_0x198f88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198f88) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198F90u;
label_198f90:
    // 0x198f90: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x198f90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x198f94: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198f94u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198f98: 0x246303b0  addiu       $v1, $v1, 0x3B0
    ctx->pc = 0x198f98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 944));
    // 0x198f9c: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198f9cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198fa0: 0x100000f5  b           . + 4 + (0xF5 << 2)
    ctx->pc = 0x198FA0u;
    {
        const bool branch_taken_0x198fa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198FA0u;
            // 0x198fa4: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198fa0) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198FA8u;
label_198fa8:
    // 0x198fa8: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x198fa8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x198fac: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x198facu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x198fb0: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x198FB0u;
    {
        const bool branch_taken_0x198fb0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198fb0) {
            ctx->pc = 0x198FCCu;
            goto label_198fcc;
        }
    }
    ctx->pc = 0x198FB8u;
    // 0x198fb8: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x198fb8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x198fbc: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198FBCu;
    {
        const bool branch_taken_0x198fbc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x198fbc) {
            ctx->pc = 0x198FCCu;
            goto label_198fcc;
        }
    }
    ctx->pc = 0x198FC4u;
    // 0x198fc4: 0x100000ec  b           . + 4 + (0xEC << 2)
    ctx->pc = 0x198FC4u;
    {
        const bool branch_taken_0x198fc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198fc4) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198FCCu;
label_198fcc:
    // 0x198fcc: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x198fccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x198fd0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x198fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x198fd4: 0x246303e0  addiu       $v1, $v1, 0x3E0
    ctx->pc = 0x198fd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 992));
    // 0x198fd8: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x198fd8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x198fdc: 0x100000e6  b           . + 4 + (0xE6 << 2)
    ctx->pc = 0x198FDCu;
    {
        const bool branch_taken_0x198fdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198FDCu;
            // 0x198fe0: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198fdc) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x198FE4u;
label_198fe4:
    // 0x198fe4: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x198fe4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x198fe8: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x198fe8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x198fec: 0x10a60013  beq         $a1, $a2, . + 4 + (0x13 << 2)
    ctx->pc = 0x198FECu;
    {
        const bool branch_taken_0x198fec = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x198FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198FECu;
            // 0x198ff0: 0x3c060032  lui         $a2, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198fec) {
            ctx->pc = 0x19903Cu;
            goto label_19903c;
        }
    }
    ctx->pc = 0x198FF4u;
    // 0x198ff4: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x198ff4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x198ff8: 0x10a60010  beq         $a1, $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x198FF8u;
    {
        const bool branch_taken_0x198ff8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x198ff8) {
            ctx->pc = 0x19903Cu;
            goto label_19903c;
        }
    }
    ctx->pc = 0x199000u;
    // 0x199000: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199000u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199004: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199004u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x199008: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x199008u;
    {
        const bool branch_taken_0x199008 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x199008) {
            ctx->pc = 0x199024u;
            goto label_199024;
        }
    }
    ctx->pc = 0x199010u;
    // 0x199010: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x199010u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x199014: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x199014u;
    {
        const bool branch_taken_0x199014 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x199014) {
            ctx->pc = 0x199024u;
            goto label_199024;
        }
    }
    ctx->pc = 0x19901Cu;
    // 0x19901c: 0x100000d6  b           . + 4 + (0xD6 << 2)
    ctx->pc = 0x19901Cu;
    {
        const bool branch_taken_0x19901c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19901c) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199024u;
label_199024:
    // 0x199024: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x199024u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x199028: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x199028u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x19902c: 0x24630410  addiu       $v1, $v1, 0x410
    ctx->pc = 0x19902cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1040));
    // 0x199030: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199030u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199034: 0x100000d0  b           . + 4 + (0xD0 << 2)
    ctx->pc = 0x199034u;
    {
        const bool branch_taken_0x199034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x199038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199034u;
            // 0x199038: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199034) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x19903Cu;
label_19903c:
    // 0x19903c: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x19903cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x199040: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x199040u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x199044: 0x24630450  addiu       $v1, $v1, 0x450
    ctx->pc = 0x199044u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1104));
    // 0x199048: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199048u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x19904c: 0x100000ca  b           . + 4 + (0xCA << 2)
    ctx->pc = 0x19904Cu;
    {
        const bool branch_taken_0x19904c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x199050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19904Cu;
            // 0x199050: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19904c) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199054u;
label_199054:
    // 0x199054: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199054u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199058: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199058u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x19905c: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x19905Cu;
    {
        const bool branch_taken_0x19905c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x19905c) {
            ctx->pc = 0x199078u;
            goto label_199078;
        }
    }
    ctx->pc = 0x199064u;
    // 0x199064: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x199064u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x199068: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x199068u;
    {
        const bool branch_taken_0x199068 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x199068) {
            ctx->pc = 0x199078u;
            goto label_199078;
        }
    }
    ctx->pc = 0x199070u;
    // 0x199070: 0x100000c1  b           . + 4 + (0xC1 << 2)
    ctx->pc = 0x199070u;
    {
        const bool branch_taken_0x199070 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x199070) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199078u;
label_199078:
    // 0x199078: 0x2405000d  addiu       $a1, $zero, 0xD
    ctx->pc = 0x199078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x19907c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x19907cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x199080: 0x24630480  addiu       $v1, $v1, 0x480
    ctx->pc = 0x199080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1152));
    // 0x199084: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199084u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199088: 0x100000bb  b           . + 4 + (0xBB << 2)
    ctx->pc = 0x199088u;
    {
        const bool branch_taken_0x199088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19908Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199088u;
            // 0x19908c: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199088) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199090u;
label_199090:
    // 0x199090: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199090u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199094: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199094u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x199098: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x199098u;
    {
        const bool branch_taken_0x199098 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x199098) {
            ctx->pc = 0x1990B4u;
            goto label_1990b4;
        }
    }
    ctx->pc = 0x1990A0u;
    // 0x1990a0: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x1990a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x1990a4: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1990A4u;
    {
        const bool branch_taken_0x1990a4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1990a4) {
            ctx->pc = 0x1990B4u;
            goto label_1990b4;
        }
    }
    ctx->pc = 0x1990ACu;
    // 0x1990ac: 0x100000b2  b           . + 4 + (0xB2 << 2)
    ctx->pc = 0x1990ACu;
    {
        const bool branch_taken_0x1990ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1990ac) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1990B4u;
label_1990b4:
    // 0x1990b4: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x1990b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1990b8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1990b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1990bc: 0x246304b0  addiu       $v1, $v1, 0x4B0
    ctx->pc = 0x1990bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1200));
    // 0x1990c0: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x1990c0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x1990c4: 0x100000ac  b           . + 4 + (0xAC << 2)
    ctx->pc = 0x1990C4u;
    {
        const bool branch_taken_0x1990c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1990C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1990C4u;
            // 0x1990c8: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1990c4) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1990CCu;
label_1990cc:
    // 0x1990cc: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x1990ccu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x1990d0: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x1990d0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x1990d4: 0x10a60013  beq         $a1, $a2, . + 4 + (0x13 << 2)
    ctx->pc = 0x1990D4u;
    {
        const bool branch_taken_0x1990d4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x1990D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1990D4u;
            // 0x1990d8: 0x3c060032  lui         $a2, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1990d4) {
            ctx->pc = 0x199124u;
            goto label_199124;
        }
    }
    ctx->pc = 0x1990DCu;
    // 0x1990dc: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x1990dcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x1990e0: 0x10a60010  beq         $a1, $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x1990E0u;
    {
        const bool branch_taken_0x1990e0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x1990e0) {
            ctx->pc = 0x199124u;
            goto label_199124;
        }
    }
    ctx->pc = 0x1990E8u;
    // 0x1990e8: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x1990e8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x1990ec: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x1990ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x1990f0: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1990F0u;
    {
        const bool branch_taken_0x1990f0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x1990f0) {
            ctx->pc = 0x19910Cu;
            goto label_19910c;
        }
    }
    ctx->pc = 0x1990F8u;
    // 0x1990f8: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x1990f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x1990fc: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1990FCu;
    {
        const bool branch_taken_0x1990fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1990fc) {
            ctx->pc = 0x19910Cu;
            goto label_19910c;
        }
    }
    ctx->pc = 0x199104u;
    // 0x199104: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x199104u;
    {
        const bool branch_taken_0x199104 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x199104) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x19910Cu;
label_19910c:
    // 0x19910c: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x19910cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x199110: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x199110u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x199114: 0x246304e0  addiu       $v1, $v1, 0x4E0
    ctx->pc = 0x199114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1248));
    // 0x199118: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199118u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x19911c: 0x10000096  b           . + 4 + (0x96 << 2)
    ctx->pc = 0x19911Cu;
    {
        const bool branch_taken_0x19911c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x199120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19911Cu;
            // 0x199120: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19911c) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199124u;
label_199124:
    // 0x199124: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x199124u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x199128: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x199128u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x19912c: 0x24630520  addiu       $v1, $v1, 0x520
    ctx->pc = 0x19912cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1312));
    // 0x199130: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199130u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199134: 0x10000090  b           . + 4 + (0x90 << 2)
    ctx->pc = 0x199134u;
    {
        const bool branch_taken_0x199134 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x199138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199134u;
            // 0x199138: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199134) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x19913Cu;
label_19913c:
    // 0x19913c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x19913cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x199140: 0x34631135  ori         $v1, $v1, 0x1135
    ctx->pc = 0x199140u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4405);
    // 0x199144: 0x10a30006  beq         $a1, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x199144u;
    {
        const bool branch_taken_0x199144 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x199148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199144u;
            // 0x199148: 0x3c030032  lui         $v1, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199144) {
            ctx->pc = 0x199160u;
            goto label_199160;
        }
    }
    ctx->pc = 0x19914Cu;
    // 0x19914c: 0x34631135  ori         $v1, $v1, 0x1135
    ctx->pc = 0x19914cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4405);
    // 0x199150: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x199150u;
    {
        const bool branch_taken_0x199150 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x199150) {
            ctx->pc = 0x199160u;
            goto label_199160;
        }
    }
    ctx->pc = 0x199158u;
    // 0x199158: 0x10000087  b           . + 4 + (0x87 << 2)
    ctx->pc = 0x199158u;
    {
        const bool branch_taken_0x199158 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x199158) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199160u;
label_199160:
    // 0x199160: 0x24050011  addiu       $a1, $zero, 0x11
    ctx->pc = 0x199160u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x199164: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x199164u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x199168: 0x24630560  addiu       $v1, $v1, 0x560
    ctx->pc = 0x199168u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1376));
    // 0x19916c: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x19916cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199170: 0x10000081  b           . + 4 + (0x81 << 2)
    ctx->pc = 0x199170u;
    {
        const bool branch_taken_0x199170 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x199174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199170u;
            // 0x199174: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199170) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199178u;
label_199178:
    // 0x199178: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x199178u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x19917c: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x19917cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x199180: 0x10a60013  beq         $a1, $a2, . + 4 + (0x13 << 2)
    ctx->pc = 0x199180u;
    {
        const bool branch_taken_0x199180 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x199184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199180u;
            // 0x199184: 0x3c060032  lui         $a2, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199180) {
            ctx->pc = 0x1991D0u;
            goto label_1991d0;
        }
    }
    ctx->pc = 0x199188u;
    // 0x199188: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x199188u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x19918c: 0x10a60010  beq         $a1, $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x19918Cu;
    {
        const bool branch_taken_0x19918c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x19918c) {
            ctx->pc = 0x1991D0u;
            goto label_1991d0;
        }
    }
    ctx->pc = 0x199194u;
    // 0x199194: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199194u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199198: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199198u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x19919c: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x19919Cu;
    {
        const bool branch_taken_0x19919c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x19919c) {
            ctx->pc = 0x1991B8u;
            goto label_1991b8;
        }
    }
    ctx->pc = 0x1991A4u;
    // 0x1991a4: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x1991a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x1991a8: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1991A8u;
    {
        const bool branch_taken_0x1991a8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1991a8) {
            ctx->pc = 0x1991B8u;
            goto label_1991b8;
        }
    }
    ctx->pc = 0x1991B0u;
    // 0x1991b0: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1991B0u;
    {
        const bool branch_taken_0x1991b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1991b0) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1991B8u;
label_1991b8:
    // 0x1991b8: 0x24050012  addiu       $a1, $zero, 0x12
    ctx->pc = 0x1991b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1991bc: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1991bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1991c0: 0x24630590  addiu       $v1, $v1, 0x590
    ctx->pc = 0x1991c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1424));
    // 0x1991c4: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x1991c4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x1991c8: 0x1000006b  b           . + 4 + (0x6B << 2)
    ctx->pc = 0x1991C8u;
    {
        const bool branch_taken_0x1991c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1991CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1991C8u;
            // 0x1991cc: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1991c8) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1991D0u;
label_1991d0:
    // 0x1991d0: 0x24050013  addiu       $a1, $zero, 0x13
    ctx->pc = 0x1991d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1991d4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1991d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1991d8: 0x246305d0  addiu       $v1, $v1, 0x5D0
    ctx->pc = 0x1991d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1488));
    // 0x1991dc: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x1991dcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x1991e0: 0x10000065  b           . + 4 + (0x65 << 2)
    ctx->pc = 0x1991E0u;
    {
        const bool branch_taken_0x1991e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1991E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1991E0u;
            // 0x1991e4: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1991e0) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1991E8u;
label_1991e8:
    // 0x1991e8: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x1991e8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x1991ec: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x1991ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x1991f0: 0x10a60013  beq         $a1, $a2, . + 4 + (0x13 << 2)
    ctx->pc = 0x1991F0u;
    {
        const bool branch_taken_0x1991f0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x1991F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1991F0u;
            // 0x1991f4: 0x3c060032  lui         $a2, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1991f0) {
            ctx->pc = 0x199240u;
            goto label_199240;
        }
    }
    ctx->pc = 0x1991F8u;
    // 0x1991f8: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x1991f8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x1991fc: 0x10a60010  beq         $a1, $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x1991FCu;
    {
        const bool branch_taken_0x1991fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x1991fc) {
            ctx->pc = 0x199240u;
            goto label_199240;
        }
    }
    ctx->pc = 0x199204u;
    // 0x199204: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199204u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199208: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199208u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x19920c: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x19920Cu;
    {
        const bool branch_taken_0x19920c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x19920c) {
            ctx->pc = 0x199228u;
            goto label_199228;
        }
    }
    ctx->pc = 0x199214u;
    // 0x199214: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x199214u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x199218: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x199218u;
    {
        const bool branch_taken_0x199218 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x199218) {
            ctx->pc = 0x199228u;
            goto label_199228;
        }
    }
    ctx->pc = 0x199220u;
    // 0x199220: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x199220u;
    {
        const bool branch_taken_0x199220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x199220) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199228u;
label_199228:
    // 0x199228: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x199228u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x19922c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x19922cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x199230: 0x24630600  addiu       $v1, $v1, 0x600
    ctx->pc = 0x199230u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1536));
    // 0x199234: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199234u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199238: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x199238u;
    {
        const bool branch_taken_0x199238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19923Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199238u;
            // 0x19923c: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199238) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199240u;
label_199240:
    // 0x199240: 0x24050015  addiu       $a1, $zero, 0x15
    ctx->pc = 0x199240u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x199244: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x199244u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x199248: 0x24630640  addiu       $v1, $v1, 0x640
    ctx->pc = 0x199248u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1600));
    // 0x19924c: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x19924cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199250: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x199250u;
    {
        const bool branch_taken_0x199250 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x199254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199250u;
            // 0x199254: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199250) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199258u;
label_199258:
    // 0x199258: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x199258u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x19925c: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x19925cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x199260: 0x10a60013  beq         $a1, $a2, . + 4 + (0x13 << 2)
    ctx->pc = 0x199260u;
    {
        const bool branch_taken_0x199260 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x199264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199260u;
            // 0x199264: 0x3c060032  lui         $a2, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199260) {
            ctx->pc = 0x1992B0u;
            goto label_1992b0;
        }
    }
    ctx->pc = 0x199268u;
    // 0x199268: 0x34c61135  ori         $a2, $a2, 0x1135
    ctx->pc = 0x199268u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4405);
    // 0x19926c: 0x10a60010  beq         $a1, $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x19926Cu;
    {
        const bool branch_taken_0x19926c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x19926c) {
            ctx->pc = 0x1992B0u;
            goto label_1992b0;
        }
    }
    ctx->pc = 0x199274u;
    // 0x199274: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199274u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199278: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199278u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x19927c: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x19927Cu;
    {
        const bool branch_taken_0x19927c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x19927c) {
            ctx->pc = 0x199298u;
            goto label_199298;
        }
    }
    ctx->pc = 0x199284u;
    // 0x199284: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x199284u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x199288: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x199288u;
    {
        const bool branch_taken_0x199288 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x199288) {
            ctx->pc = 0x199298u;
            goto label_199298;
        }
    }
    ctx->pc = 0x199290u;
    // 0x199290: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x199290u;
    {
        const bool branch_taken_0x199290 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x199290) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199298u;
label_199298:
    // 0x199298: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x199298u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x19929c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x19929cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1992a0: 0x24630670  addiu       $v1, $v1, 0x670
    ctx->pc = 0x1992a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1648));
    // 0x1992a4: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x1992a4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x1992a8: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1992A8u;
    {
        const bool branch_taken_0x1992a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1992ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1992A8u;
            // 0x1992ac: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1992a8) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1992B0u;
label_1992b0:
    // 0x1992b0: 0x24050017  addiu       $a1, $zero, 0x17
    ctx->pc = 0x1992b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1992b4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1992b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1992b8: 0x246306b0  addiu       $v1, $v1, 0x6B0
    ctx->pc = 0x1992b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1712));
    // 0x1992bc: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x1992bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x1992c0: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1992C0u;
    {
        const bool branch_taken_0x1992c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1992C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1992C0u;
            // 0x1992c4: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1992c0) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1992C8u;
label_1992c8:
    // 0x1992c8: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x1992c8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x1992cc: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x1992ccu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x1992d0: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1992D0u;
    {
        const bool branch_taken_0x1992d0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x1992d0) {
            ctx->pc = 0x1992ECu;
            goto label_1992ec;
        }
    }
    ctx->pc = 0x1992D8u;
    // 0x1992d8: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x1992d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x1992dc: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1992DCu;
    {
        const bool branch_taken_0x1992dc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1992dc) {
            ctx->pc = 0x1992ECu;
            goto label_1992ec;
        }
    }
    ctx->pc = 0x1992E4u;
    // 0x1992e4: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1992E4u;
    {
        const bool branch_taken_0x1992e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1992e4) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x1992ECu;
label_1992ec:
    // 0x1992ec: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x1992ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1992f0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1992f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1992f4: 0x246306e0  addiu       $v1, $v1, 0x6E0
    ctx->pc = 0x1992f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1760));
    // 0x1992f8: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x1992f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x1992fc: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1992FCu;
    {
        const bool branch_taken_0x1992fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x199300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1992FCu;
            // 0x199300: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1992fc) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199304u;
label_199304:
    // 0x199304: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199304u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199308: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199308u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x19930c: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x19930Cu;
    {
        const bool branch_taken_0x19930c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x19930c) {
            ctx->pc = 0x199328u;
            goto label_199328;
        }
    }
    ctx->pc = 0x199314u;
    // 0x199314: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x199314u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x199318: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x199318u;
    {
        const bool branch_taken_0x199318 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x199318) {
            ctx->pc = 0x199328u;
            goto label_199328;
        }
    }
    ctx->pc = 0x199320u;
    // 0x199320: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x199320u;
    {
        const bool branch_taken_0x199320 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x199320) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199328u;
label_199328:
    // 0x199328: 0x24050019  addiu       $a1, $zero, 0x19
    ctx->pc = 0x199328u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x19932c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x19932cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x199330: 0x24630710  addiu       $v1, $v1, 0x710
    ctx->pc = 0x199330u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1808));
    // 0x199334: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199334u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199338: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x199338u;
    {
        const bool branch_taken_0x199338 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19933Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199338u;
            // 0x19933c: 0xac83004c  sw          $v1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x199338) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199340u;
label_199340:
    // 0x199340: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x199340u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x199344: 0x34c61035  ori         $a2, $a2, 0x1035
    ctx->pc = 0x199344u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4149);
    // 0x199348: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x199348u;
    {
        const bool branch_taken_0x199348 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x199348) {
            ctx->pc = 0x199364u;
            goto label_199364;
        }
    }
    ctx->pc = 0x199350u;
    // 0x199350: 0x34631035  ori         $v1, $v1, 0x1035
    ctx->pc = 0x199350u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4149);
    // 0x199354: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x199354u;
    {
        const bool branch_taken_0x199354 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x199354) {
            ctx->pc = 0x199364u;
            goto label_199364;
        }
    }
    ctx->pc = 0x19935Cu;
    // 0x19935c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x19935Cu;
    {
        const bool branch_taken_0x19935c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19935c) {
            ctx->pc = 0x199378u;
            goto label_199378;
        }
    }
    ctx->pc = 0x199364u;
label_199364:
    // 0x199364: 0x2405001a  addiu       $a1, $zero, 0x1A
    ctx->pc = 0x199364u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x199368: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x199368u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x19936c: 0x24630740  addiu       $v1, $v1, 0x740
    ctx->pc = 0x19936cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1856));
    // 0x199370: 0xac850048  sw          $a1, 0x48($a0)
    ctx->pc = 0x199370u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
    // 0x199374: 0xac83004c  sw          $v1, 0x4C($a0)
    ctx->pc = 0x199374u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
label_199378:
    // 0x199378: 0x3e00008  jr          $ra
    ctx->pc = 0x199378u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x198CB8u: goto label_198cb8;
            case 0x198D84u: goto label_198d84;
            case 0x198DA8u: goto label_198da8;
            case 0x198DBCu: goto label_198dbc;
            case 0x198DFCu: goto label_198dfc;
            case 0x198E14u: goto label_198e14;
            case 0x198E2Cu: goto label_198e2c;
            case 0x198E60u: goto label_198e60;
            case 0x198E78u: goto label_198e78;
            case 0x198E90u: goto label_198e90;
            case 0x198EC4u: goto label_198ec4;
            case 0x198EDCu: goto label_198edc;
            case 0x198EF4u: goto label_198ef4;
            case 0x198F18u: goto label_198f18;
            case 0x198F30u: goto label_198f30;
            case 0x198F54u: goto label_198f54;
            case 0x198F6Cu: goto label_198f6c;
            case 0x198F90u: goto label_198f90;
            case 0x198FA8u: goto label_198fa8;
            case 0x198FCCu: goto label_198fcc;
            case 0x198FE4u: goto label_198fe4;
            case 0x199024u: goto label_199024;
            case 0x19903Cu: goto label_19903c;
            case 0x199054u: goto label_199054;
            case 0x199078u: goto label_199078;
            case 0x199090u: goto label_199090;
            case 0x1990B4u: goto label_1990b4;
            case 0x1990CCu: goto label_1990cc;
            case 0x19910Cu: goto label_19910c;
            case 0x199124u: goto label_199124;
            case 0x19913Cu: goto label_19913c;
            case 0x199160u: goto label_199160;
            case 0x199178u: goto label_199178;
            case 0x1991B8u: goto label_1991b8;
            case 0x1991D0u: goto label_1991d0;
            case 0x1991E8u: goto label_1991e8;
            case 0x199228u: goto label_199228;
            case 0x199240u: goto label_199240;
            case 0x199258u: goto label_199258;
            case 0x199298u: goto label_199298;
            case 0x1992B0u: goto label_1992b0;
            case 0x1992C8u: goto label_1992c8;
            case 0x1992ECu: goto label_1992ec;
            case 0x199304u: goto label_199304;
            case 0x199328u: goto label_199328;
            case 0x199340u: goto label_199340;
            case 0x199364u: goto label_199364;
            case 0x199378u: goto label_199378;
            default: break;
        }
        return;
    }
    ctx->pc = 0x199380u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
