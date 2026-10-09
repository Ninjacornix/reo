#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014FF50
// Address: 0x14ff50 - 0x150000
void sub_0014FF50_0x14ff50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014FF50_0x14ff50");
#endif

    switch (ctx->pc) {
        case 0x14ff88u: goto label_14ff88;
        case 0x14ffa0u: goto label_14ffa0;
        case 0x14ffa8u: goto label_14ffa8;
        default: break;
    }

    ctx->pc = 0x14ff50u;

    // 0x14ff50: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x14ff50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14ff54: 0x8c850008  lw          $a1, 0x8($a0)
    ctx->pc = 0x14ff54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14ff58: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x14ff58u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x14ff5c: 0x2466000f  addiu       $a2, $v1, 0xF
    ctx->pc = 0x14ff5cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x14ff60: 0xc2180b  movn        $v1, $a2, $v0
    ctx->pc = 0x14ff60u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 6));
    // 0x14ff64: 0x28a20000  slti        $v0, $a1, 0x0
    ctx->pc = 0x14ff64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x14ff68: 0x24a7001f  addiu       $a3, $a1, 0x1F
    ctx->pc = 0x14ff68u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), 31));
    // 0x14ff6c: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x14ff6cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x14ff70: 0xe2280b  movn        $a1, $a3, $v0
    ctx->pc = 0x14ff70u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x14ff74: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x14ff74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14ff78: 0x1860001e  blez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x14FF78u;
    {
        const bool branch_taken_0x14ff78 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x14FF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FF78u;
            // 0x14ff7c: 0x52943  sra         $a1, $a1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14ff78) {
            ctx->pc = 0x14FFF4u;
            goto label_14fff4;
        }
    }
    ctx->pc = 0x14FF80u;
    // 0x14ff80: 0x56280  sll         $t4, $a1, 10
    ctx->pc = 0x14ff80u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 5), 10));
    // 0x14ff84: 0x55ac0  sll         $t3, $a1, 11
    ctx->pc = 0x14ff84u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 5), 11));
label_14ff88:
    // 0x14ff88: 0x24880003  addiu       $t0, $a0, 0x3
    ctx->pc = 0x14ff88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 3));
    // 0x14ff8c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x14ff8cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14ff90: 0x10c1021  addu        $v0, $t0, $t4
    ctx->pc = 0x14ff90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 12)));
    // 0x14ff94: 0x18a00014  blez        $a1, . + 4 + (0x14 << 2)
    ctx->pc = 0x14FF94u;
    {
        const bool branch_taken_0x14ff94 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x14FF98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FF94u;
            // 0x14ff98: 0x2447ffff  addiu       $a3, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14ff94) {
            ctx->pc = 0x14FFE8u;
            goto label_14ffe8;
        }
    }
    ctx->pc = 0x14FF9Cu;
    // 0x14ff9c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x14ff9cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_14ffa0:
    // 0x14ffa0: 0x2406000f  addiu       $a2, $zero, 0xF
    ctx->pc = 0x14ffa0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x14ffa4: 0x0  nop
    ctx->pc = 0x14ffa4u;
    // NOP
label_14ffa8:
    // 0x14ffa8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x14ffa8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ffac: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x14ffacu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x14ffb0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x14ffb0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x14ffb4: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x14ffb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x14ffb8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x14ffb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x14ffbc: 0xa1020000  sb          $v0, 0x0($t0)
    ctx->pc = 0x14ffbcu;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x14ffc0: 0x4c1fff9  bgez        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x14FFC0u;
    {
        const bool branch_taken_0x14ffc0 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x14FFC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FFC0u;
            // 0x14ffc4: 0x25080004  addiu       $t0, $t0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14ffc0) {
            ctx->pc = 0x14FFA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14ffa8;
        }
    }
    ctx->pc = 0x14FFC8u;
    // 0x14ffc8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x14ffc8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x14ffcc: 0x29220010  slti        $v0, $t1, 0x10
    ctx->pc = 0x14ffccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x14ffd0: 0x5440fff5  bnel        $v0, $zero, . + 4 + (-0xB << 2)
    ctx->pc = 0x14FFD0u;
    {
        const bool branch_taken_0x14ffd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x14ffd0) {
            ctx->pc = 0x14FFD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14FFD0u;
            // 0x14ffd4: 0x2406000f  addiu       $a2, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14FFA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14ffa8;
        }
    }
    ctx->pc = 0x14FFD8u;
    // 0x14ffd8: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x14ffd8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x14ffdc: 0x145102a  slt         $v0, $t2, $a1
    ctx->pc = 0x14ffdcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x14ffe0: 0x5440ffef  bnel        $v0, $zero, . + 4 + (-0x11 << 2)
    ctx->pc = 0x14FFE0u;
    {
        const bool branch_taken_0x14ffe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x14ffe0) {
            ctx->pc = 0x14FFE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14FFE0u;
            // 0x14ffe4: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14FFA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14ffa0;
        }
    }
    ctx->pc = 0x14FFE8u;
label_14ffe8:
    // 0x14ffe8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x14ffe8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x14ffec: 0x1460ffe6  bnez        $v1, . + 4 + (-0x1A << 2)
    ctx->pc = 0x14FFECu;
    {
        const bool branch_taken_0x14ffec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x14FFF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FFECu;
            // 0x14fff0: 0x8b2021  addu        $a0, $a0, $t3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14ffec) {
            ctx->pc = 0x14FF88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14ff88;
        }
    }
    ctx->pc = 0x14FFF4u;
label_14fff4:
    // 0x14fff4: 0x3e00008  jr          $ra
    ctx->pc = 0x14FFF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14FF88u: goto label_14ff88;
            case 0x14FFA0u: goto label_14ffa0;
            case 0x14FFA8u: goto label_14ffa8;
            case 0x14FFE8u: goto label_14ffe8;
            case 0x14FFF4u: goto label_14fff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FFFCu;
    // 0x14fffc: 0x0  nop
    ctx->pc = 0x14fffcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
