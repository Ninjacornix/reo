#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001899F0
// Address: 0x1899f0 - 0x189b08
void sub_001899F0_0x1899f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001899F0_0x1899f0");
#endif

    switch (ctx->pc) {
        case 0x189a88u: goto label_189a88;
        case 0x189aa8u: goto label_189aa8;
        case 0x189ae0u: goto label_189ae0;
        default: break;
    }

    ctx->pc = 0x1899f0u;

    // 0x1899f0: 0x8c880014  lw          $t0, 0x14($a0)
    ctx->pc = 0x1899f0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1899f4: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1899f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1899f8: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x1899f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1899fc: 0x2507ffff  addiu       $a3, $t0, -0x1
    ctx->pc = 0x1899fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x189a00: 0xa82821  addu        $a1, $a1, $t0
    ctx->pc = 0x189a00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x189a04: 0xe03827  not         $a3, $a3
    ctx->pc = 0x189a04u;
    SET_GPR_U64(ctx, 7, ~(GPR_U64(ctx, 7) | GPR_U64(ctx, 0)));
    // 0x189a08: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x189a08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x189a0c: 0xe52824  and         $a1, $a3, $a1
    ctx->pc = 0x189a0cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x189a10: 0x453821  addu        $a3, $v0, $a1
    ctx->pc = 0x189a10u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x189a14: 0x67082b  sltu        $at, $v1, $a3
    ctx->pc = 0x189a14u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x189a18: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x189A18u;
    {
        const bool branch_taken_0x189a18 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x189a18) {
            ctx->pc = 0x189A28u;
            goto label_189a28;
        }
    }
    ctx->pc = 0x189A20u;
    // 0x189a20: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x189A20u;
    {
        const bool branch_taken_0x189a20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A20u;
            // 0x189a24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189a20) {
            ctx->pc = 0x189A44u;
            goto label_189a44;
        }
    }
    ctx->pc = 0x189A28u;
label_189a28:
    // 0x189a28: 0x10c00005  beqz        $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x189A28u;
    {
        const bool branch_taken_0x189a28 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x189a28) {
            ctx->pc = 0x189A40u;
            goto label_189a40;
        }
    }
    ctx->pc = 0x189A30u;
    // 0x189a30: 0x651023  subu        $v0, $v1, $a1
    ctx->pc = 0x189a30u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x189a34: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x189a34u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x189a38: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x189A38u;
    {
        const bool branch_taken_0x189a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A38u;
            // 0x189a3c: 0x8c820010  lw          $v0, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189a38) {
            ctx->pc = 0x189A44u;
            goto label_189a44;
        }
    }
    ctx->pc = 0x189A40u;
label_189a40:
    // 0x189a40: 0xac87000c  sw          $a3, 0xC($a0)
    ctx->pc = 0x189a40u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 7));
label_189a44:
    // 0x189a44: 0x3e00008  jr          $ra
    ctx->pc = 0x189A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189A28u: goto label_189a28;
            case 0x189A40u: goto label_189a40;
            case 0x189A44u: goto label_189a44;
            case 0x189A88u: goto label_189a88;
            case 0x189AA8u: goto label_189aa8;
            case 0x189AE0u: goto label_189ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189A4Cu;
    // 0x189a4c: 0x0  nop
    ctx->pc = 0x189a4cu;
    // NOP
    // 0x189a50: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x189a50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x189a54: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x189a54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x189a58: 0x8c63000c  lw          $v1, 0xC($v1)
    ctx->pc = 0x189a58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x189a5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x189a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x189a60: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x189a60u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x189a64: 0x3e00008  jr          $ra
    ctx->pc = 0x189A64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A64u;
            // 0x189a68: 0xacc50004  sw          $a1, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189A28u: goto label_189a28;
            case 0x189A40u: goto label_189a40;
            case 0x189A44u: goto label_189a44;
            case 0x189A88u: goto label_189a88;
            case 0x189AA8u: goto label_189aa8;
            case 0x189AE0u: goto label_189ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189A6Cu;
    // 0x189a6c: 0x0  nop
    ctx->pc = 0x189a6cu;
    // NOP
    // 0x189a70: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x189a70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x189a74: 0x8ca60000  lw          $a2, 0x0($a1)
    ctx->pc = 0x189a74u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x189a78: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x189a78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x189a7c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x189a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x189a80: 0x3e00008  jr          $ra
    ctx->pc = 0x189A80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A80u;
            // 0x189a84: 0xac66000c  sw          $a2, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189A28u: goto label_189a28;
            case 0x189A40u: goto label_189a40;
            case 0x189A44u: goto label_189a44;
            case 0x189A88u: goto label_189a88;
            case 0x189AA8u: goto label_189aa8;
            case 0x189AE0u: goto label_189ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189A88u;
label_189a88:
    // 0x189a88: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x189a88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189a8c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x189a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x189a90: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189a90u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189a94: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x189a94u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x189a98: 0x14c0fffb  bnez        $a2, . + 4 + (-0x5 << 2)
    ctx->pc = 0x189A98u;
    {
        const bool branch_taken_0x189a98 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A98u;
            // 0x189a9c: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189a98) {
            ctx->pc = 0x189A88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189a88;
        }
    }
    ctx->pc = 0x189AA0u;
    // 0x189aa0: 0x3e00008  jr          $ra
    ctx->pc = 0x189AA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189A28u: goto label_189a28;
            case 0x189A40u: goto label_189a40;
            case 0x189A44u: goto label_189a44;
            case 0x189A88u: goto label_189a88;
            case 0x189AA8u: goto label_189aa8;
            case 0x189AE0u: goto label_189ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189AA8u;
label_189aa8:
    // 0x189aa8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x189aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189aac: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x189aacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x189ab0: 0x8c880008  lw          $t0, 0x8($a0)
    ctx->pc = 0x189ab0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189ab4: 0x8c89000c  lw          $t1, 0xC($a0)
    ctx->pc = 0x189ab4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x189ab8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x189ab8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x189abc: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x189abcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x189ac0: 0xaca80008  sw          $t0, 0x8($a1)
    ctx->pc = 0x189ac0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 8));
    // 0x189ac4: 0xaca9000c  sw          $t1, 0xC($a1)
    ctx->pc = 0x189ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 9));
    // 0x189ac8: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189ac8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189acc: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x189accu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x189ad0: 0x14c0fff5  bnez        $a2, . + 4 + (-0xB << 2)
    ctx->pc = 0x189AD0u;
    {
        const bool branch_taken_0x189ad0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189AD0u;
            // 0x189ad4: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189ad0) {
            ctx->pc = 0x189AA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189aa8;
        }
    }
    ctx->pc = 0x189AD8u;
    // 0x189ad8: 0x3e00008  jr          $ra
    ctx->pc = 0x189AD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189A28u: goto label_189a28;
            case 0x189A40u: goto label_189a40;
            case 0x189A44u: goto label_189a44;
            case 0x189A88u: goto label_189a88;
            case 0x189AA8u: goto label_189aa8;
            case 0x189AE0u: goto label_189ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189AE0u;
label_189ae0:
    // 0x189ae0: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x189ae0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189ae4: 0xdc830008  ld          $v1, 0x8($a0)
    ctx->pc = 0x189ae4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189ae8: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x189ae8u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x189aec: 0xfca30008  sd          $v1, 0x8($a1)
    ctx->pc = 0x189aecu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 3));
    // 0x189af0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189af0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189af4: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x189af4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x189af8: 0x14c0fff9  bnez        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189AF8u;
    {
        const bool branch_taken_0x189af8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189AF8u;
            // 0x189afc: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189af8) {
            ctx->pc = 0x189AE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189ae0;
        }
    }
    ctx->pc = 0x189B00u;
    // 0x189b00: 0x3e00008  jr          $ra
    ctx->pc = 0x189B00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189A28u: goto label_189a28;
            case 0x189A40u: goto label_189a40;
            case 0x189A44u: goto label_189a44;
            case 0x189A88u: goto label_189a88;
            case 0x189AA8u: goto label_189aa8;
            case 0x189AE0u: goto label_189ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189B08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
