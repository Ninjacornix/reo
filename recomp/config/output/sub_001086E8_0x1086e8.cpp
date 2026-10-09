#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001086E8
// Address: 0x1086e8 - 0x108750
void sub_001086E8_0x1086e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001086E8_0x1086e8");
#endif

    switch (ctx->pc) {
        case 0x108718u: goto label_108718;
        default: break;
    }

    ctx->pc = 0x1086e8u;

    // 0x1086e8: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1086e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1086ec: 0x8ca30010  lw          $v1, 0x10($a1)
    ctx->pc = 0x1086ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x1086f0: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1086f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1086f4: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1086F4u;
    {
        const bool branch_taken_0x1086f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1086f4) {
            ctx->pc = 0x108748u;
            goto label_108748;
        }
    }
    ctx->pc = 0x1086FCu;
    // 0x1086fc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1086fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x108700: 0x248a0014  addiu       $t2, $a0, 0x14
    ctx->pc = 0x108700u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 4), 20));
    // 0x108704: 0x24a20014  addiu       $v0, $a1, 0x14
    ctx->pc = 0x108704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 20));
    // 0x108708: 0x1433821  addu        $a3, $t2, $v1
    ctx->pc = 0x108708u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x10870c: 0x434821  addu        $t1, $v0, $v1
    ctx->pc = 0x10870cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x108710: 0x24e7fffc  addiu       $a3, $a3, -0x4
    ctx->pc = 0x108710u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967292));
    // 0x108714: 0x0  nop
    ctx->pc = 0x108714u;
    // NOP
label_108718:
    // 0x108718: 0x2529fffc  addiu       $t1, $t1, -0x4
    ctx->pc = 0x108718u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967292));
    // 0x10871c: 0x8ce50000  lw          $a1, 0x0($a3)
    ctx->pc = 0x10871cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x108720: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x108720u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x108724: 0x8d240000  lw          $a0, 0x0($t1)
    ctx->pc = 0x108724u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x108728: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x108728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10872c: 0x147402b  sltu        $t0, $t2, $a3
    ctx->pc = 0x10872cu;
    SET_GPR_U64(ctx, 8, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x108730: 0xa4182b  sltu        $v1, $a1, $a0
    ctx->pc = 0x108730u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x108734: 0x14a40004  bne         $a1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x108734u;
    {
        const bool branch_taken_0x108734 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x108738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108734u;
            // 0x108738: 0xc3100a  movz        $v0, $a2, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108734) {
            ctx->pc = 0x108748u;
            goto label_108748;
        }
    }
    ctx->pc = 0x10873Cu;
    // 0x10873c: 0x5500fff6  bnel        $t0, $zero, . + 4 + (-0xA << 2)
    ctx->pc = 0x10873Cu;
    {
        const bool branch_taken_0x10873c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x10873c) {
            ctx->pc = 0x108740u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10873Cu;
            // 0x108740: 0x24e7fffc  addiu       $a3, $a3, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967292));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108718u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108718;
        }
    }
    ctx->pc = 0x108744u;
    // 0x108744: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x108744u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_108748:
    // 0x108748: 0x3e00008  jr          $ra
    ctx->pc = 0x108748u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108718u: goto label_108718;
            case 0x108748u: goto label_108748;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108750u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
