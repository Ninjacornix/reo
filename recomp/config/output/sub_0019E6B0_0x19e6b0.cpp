#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019E6B0
// Address: 0x19e6b0 - 0x19e7d0
void sub_0019E6B0_0x19e6b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019E6B0_0x19e6b0");
#endif

    switch (ctx->pc) {
        case 0x19e6c4u: goto label_19e6c4;
        case 0x19e6d0u: goto label_19e6d0;
        case 0x19e6d4u: goto label_19e6d4;
        default: break;
    }

    ctx->pc = 0x19e6b0u;

    // 0x19e6b0: 0x61a00  sll         $v1, $a2, 8
    ctx->pc = 0x19e6b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x19e6b4: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x19e6b4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x19e6b8: 0x2463ffe0  addiu       $v1, $v1, -0x20
    ctx->pc = 0x19e6b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967264));
    // 0x19e6bc: 0x25080d90  addiu       $t0, $t0, 0xD90
    ctx->pc = 0x19e6bcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 3472));
    // 0x19e6c0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x19e6c0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19e6c4:
    // 0x19e6c4: 0x8d070000  lw          $a3, 0x0($t0)
    ctx->pc = 0x19e6c4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x19e6c8: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x19e6c8u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e6cc: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x19e6ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
label_19e6d0:
    // 0x19e6d0: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x19e6d0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19e6d4:
    // 0x19e6d4: 0x8cec0000  lw          $t4, 0x0($a3)
    ctx->pc = 0x19e6d4u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19e6d8: 0x31860001  andi        $a2, $t4, 0x1
    ctx->pc = 0x19e6d8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)1);
    // 0x19e6dc: 0x14c00009  bnez        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x19E6DCu;
    {
        const bool branch_taken_0x19e6dc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E6DCu;
            // 0x19e6e0: 0xc3043  sra         $a2, $t4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e6dc) {
            ctx->pc = 0x19E704u;
            goto label_19e704;
        }
    }
    ctx->pc = 0x19E6E4u;
    // 0x19e6e4: 0x5810003  bgez        $t4, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E6E4u;
    {
        const bool branch_taken_0x19e6e4 = (GPR_S64(ctx, 12) >= 0);
        ctx->pc = 0x19E6E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E6E4u;
            // 0x19e6e8: 0xc3043  sra         $a2, $t4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e6e4) {
            ctx->pc = 0x19E6F4u;
            goto label_19e6f4;
        }
    }
    ctx->pc = 0x19E6ECu;
    // 0x19e6ec: 0x25860001  addiu       $a2, $t4, 0x1
    ctx->pc = 0x19e6ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x19e6f0: 0x63043  sra         $a2, $a2, 1
    ctx->pc = 0x19e6f0u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 1));
label_19e6f4:
    // 0x19e6f4: 0x863021  addu        $a2, $a0, $a2
    ctx->pc = 0x19e6f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x19e6f8: 0x90c60000  lbu         $a2, 0x0($a2)
    ctx->pc = 0x19e6f8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19e6fc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x19E6FCu;
    {
        const bool branch_taken_0x19e6fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E6FCu;
            // 0x19e700: 0x30c6000f  andi        $a2, $a2, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e6fc) {
            ctx->pc = 0x19E728u;
            goto label_19e728;
        }
    }
    ctx->pc = 0x19E704u;
label_19e704:
    // 0x19e704: 0x5810003  bgez        $t4, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E704u;
    {
        const bool branch_taken_0x19e704 = (GPR_S64(ctx, 12) >= 0);
        if (branch_taken_0x19e704) {
            ctx->pc = 0x19E714u;
            goto label_19e714;
        }
    }
    ctx->pc = 0x19E70Cu;
    // 0x19e70c: 0x25860001  addiu       $a2, $t4, 0x1
    ctx->pc = 0x19e70cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x19e710: 0x63043  sra         $a2, $a2, 1
    ctx->pc = 0x19e710u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 1));
label_19e714:
    // 0x19e714: 0x863021  addu        $a2, $a0, $a2
    ctx->pc = 0x19e714u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x19e718: 0x90c60000  lbu         $a2, 0x0($a2)
    ctx->pc = 0x19e718u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19e71c: 0x30c600f0  andi        $a2, $a2, 0xF0
    ctx->pc = 0x19e71cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)240);
    // 0x19e720: 0x63103  sra         $a2, $a2, 4
    ctx->pc = 0x19e720u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 4));
    // 0x19e724: 0x30c600ff  andi        $a2, $a2, 0xFF
    ctx->pc = 0x19e724u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
label_19e728:
    // 0x19e728: 0x8ced0004  lw          $t5, 0x4($a3)
    ctx->pc = 0x19e728u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19e72c: 0x30c600ff  andi        $a2, $a2, 0xFF
    ctx->pc = 0x19e72cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x19e730: 0x31ac0001  andi        $t4, $t5, 0x1
    ctx->pc = 0x19e730u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 13) & (uint64_t)(uint16_t)1);
    // 0x19e734: 0x1580000b  bnez        $t4, . + 4 + (0xB << 2)
    ctx->pc = 0x19E734u;
    {
        const bool branch_taken_0x19e734 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E734u;
            // 0x19e738: 0x24e70008  addiu       $a3, $a3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e734) {
            ctx->pc = 0x19E764u;
            goto label_19e764;
        }
    }
    ctx->pc = 0x19E73Cu;
    // 0x19e73c: 0x5a10003  bgez        $t5, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E73Cu;
    {
        const bool branch_taken_0x19e73c = (GPR_S64(ctx, 13) >= 0);
        ctx->pc = 0x19E740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E73Cu;
            // 0x19e740: 0xd6043  sra         $t4, $t5, 1 (Delay Slot)
        SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 13), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e73c) {
            ctx->pc = 0x19E74Cu;
            goto label_19e74c;
        }
    }
    ctx->pc = 0x19E744u;
    // 0x19e744: 0x25ac0001  addiu       $t4, $t5, 0x1
    ctx->pc = 0x19e744u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x19e748: 0xc6043  sra         $t4, $t4, 1
    ctx->pc = 0x19e748u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 12), 1));
label_19e74c:
    // 0x19e74c: 0x8c6021  addu        $t4, $a0, $t4
    ctx->pc = 0x19e74cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x19e750: 0x918c0000  lbu         $t4, 0x0($t4)
    ctx->pc = 0x19e750u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x19e754: 0x318c000f  andi        $t4, $t4, 0xF
    ctx->pc = 0x19e754u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)15);
    // 0x19e758: 0xc6100  sll         $t4, $t4, 4
    ctx->pc = 0x19e758u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 4));
    // 0x19e75c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x19E75Cu;
    {
        const bool branch_taken_0x19e75c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E75Cu;
            // 0x19e760: 0x318c00ff  andi        $t4, $t4, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e75c) {
            ctx->pc = 0x19E784u;
            goto label_19e784;
        }
    }
    ctx->pc = 0x19E764u;
label_19e764:
    // 0x19e764: 0x5a10003  bgez        $t5, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E764u;
    {
        const bool branch_taken_0x19e764 = (GPR_S64(ctx, 13) >= 0);
        ctx->pc = 0x19E768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E764u;
            // 0x19e768: 0xd6043  sra         $t4, $t5, 1 (Delay Slot)
        SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 13), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e764) {
            ctx->pc = 0x19E774u;
            goto label_19e774;
        }
    }
    ctx->pc = 0x19E76Cu;
    // 0x19e76c: 0x25ac0001  addiu       $t4, $t5, 0x1
    ctx->pc = 0x19e76cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x19e770: 0xc6043  sra         $t4, $t4, 1
    ctx->pc = 0x19e770u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 12), 1));
label_19e774:
    // 0x19e774: 0x8c6021  addu        $t4, $a0, $t4
    ctx->pc = 0x19e774u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x19e778: 0x918c0000  lbu         $t4, 0x0($t4)
    ctx->pc = 0x19e778u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x19e77c: 0x318c00f0  andi        $t4, $t4, 0xF0
    ctx->pc = 0x19e77cu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)240);
    // 0x19e780: 0x318c00ff  andi        $t4, $t4, 0xFF
    ctx->pc = 0x19e780u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)255);
label_19e784:
    // 0x19e784: 0x318c00ff  andi        $t4, $t4, 0xFF
    ctx->pc = 0x19e784u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)255);
    // 0x19e788: 0x30c600ff  andi        $a2, $a2, 0xFF
    ctx->pc = 0x19e788u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x19e78c: 0xcc3025  or          $a2, $a2, $t4
    ctx->pc = 0x19e78cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 12));
    // 0x19e790: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x19e790u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x19e794: 0xa0a60000  sb          $a2, 0x0($a1)
    ctx->pc = 0x19e794u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x19e798: 0x29460020  slti        $a2, $t2, 0x20
    ctx->pc = 0x19e798u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x19e79c: 0x14c0ffcd  bnez        $a2, . + 4 + (-0x33 << 2)
    ctx->pc = 0x19E79Cu;
    {
        const bool branch_taken_0x19e79c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E79Cu;
            // 0x19e7a0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e79c) {
            ctx->pc = 0x19E6D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e6d4;
        }
    }
    ctx->pc = 0x19E7A4u;
    // 0x19e7a4: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x19e7a4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x19e7a8: 0x29660002  slti        $a2, $t3, 0x2
    ctx->pc = 0x19e7a8u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 11) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x19e7ac: 0x14c0ffc8  bnez        $a2, . + 4 + (-0x38 << 2)
    ctx->pc = 0x19E7ACu;
    {
        const bool branch_taken_0x19e7ac = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E7ACu;
            // 0x19e7b0: 0xa32821  addu        $a1, $a1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e7ac) {
            ctx->pc = 0x19E6D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e6d0;
        }
    }
    ctx->pc = 0x19E7B4u;
    // 0x19e7b4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x19e7b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x19e7b8: 0x29260004  slti        $a2, $t1, 0x4
    ctx->pc = 0x19e7b8u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x19e7bc: 0x14c0ffc1  bnez        $a2, . + 4 + (-0x3F << 2)
    ctx->pc = 0x19E7BCu;
    {
        const bool branch_taken_0x19e7bc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E7BCu;
            // 0x19e7c0: 0x24840100  addiu       $a0, $a0, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e7bc) {
            ctx->pc = 0x19E6C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e6c4;
        }
    }
    ctx->pc = 0x19E7C4u;
    // 0x19e7c4: 0x3e00008  jr          $ra
    ctx->pc = 0x19E7C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19E6C4u: goto label_19e6c4;
            case 0x19E6D0u: goto label_19e6d0;
            case 0x19E6D4u: goto label_19e6d4;
            case 0x19E6F4u: goto label_19e6f4;
            case 0x19E704u: goto label_19e704;
            case 0x19E714u: goto label_19e714;
            case 0x19E728u: goto label_19e728;
            case 0x19E74Cu: goto label_19e74c;
            case 0x19E764u: goto label_19e764;
            case 0x19E774u: goto label_19e774;
            case 0x19E784u: goto label_19e784;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19E7CCu;
    // 0x19e7cc: 0x0  nop
    ctx->pc = 0x19e7ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
