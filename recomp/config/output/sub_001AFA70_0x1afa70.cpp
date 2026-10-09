#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFA70
// Address: 0x1afa70 - 0x1afb20
void sub_001AFA70_0x1afa70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFA70_0x1afa70");
#endif

    switch (ctx->pc) {
        case 0x1afa88u: goto label_1afa88;
        case 0x1afac4u: goto label_1afac4;
        case 0x1afad4u: goto label_1afad4;
        default: break;
    }

    ctx->pc = 0x1afa70u;

    // 0x1afa70: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1afa70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1afa74: 0x3c05002c  lui         $a1, 0x2C
    ctx->pc = 0x1afa74u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)44 << 16));
    // 0x1afa78: 0x8c278e10  lw          $a3, -0x71F0($at)
    ctx->pc = 0x1afa78u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938128)));
    // 0x1afa7c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1afa7cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afa80: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AFA80u;
    {
        const bool branch_taken_0x1afa80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFA84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFA80u;
            // 0x1afa84: 0x24a58e20  addiu       $a1, $a1, -0x71E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294938144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afa80) {
            ctx->pc = 0x1AFAA4u;
            goto label_1afaa4;
        }
    }
    ctx->pc = 0x1AFA88u;
label_1afa88:
    // 0x1afa88: 0xa33021  addu        $a2, $a1, $v1
    ctx->pc = 0x1afa88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1afa8c: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1afa8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1afa90: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFA90u;
    {
        const bool branch_taken_0x1afa90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1afa90) {
            ctx->pc = 0x1AFAA0u;
            goto label_1afaa0;
        }
    }
    ctx->pc = 0x1AFA98u;
    // 0x1afa98: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1AFA98u;
    {
        const bool branch_taken_0x1afa98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFA9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFA98u;
            // 0x1afa9c: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afa98) {
            ctx->pc = 0x1AFAB0u;
            goto label_1afab0;
        }
    }
    ctx->pc = 0x1AFAA0u;
label_1afaa0:
    // 0x1afaa0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1afaa0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
label_1afaa4:
    // 0x1afaa4: 0x107182a  slt         $v1, $t0, $a3
    ctx->pc = 0x1afaa4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1afaa8: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1AFAA8u;
    {
        const bool branch_taken_0x1afaa8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AFAACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFAA8u;
            // 0x1afaac: 0x81880  sll         $v1, $t0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afaa8) {
            ctx->pc = 0x1AFA88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1afa88;
        }
    }
    ctx->pc = 0x1AFAB0u;
label_1afab0:
    // 0x1afab0: 0x107182a  slt         $v1, $t0, $a3
    ctx->pc = 0x1afab0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1afab4: 0x14600015  bnez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1AFAB4u;
    {
        const bool branch_taken_0x1afab4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AFAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFAB4u;
            // 0x1afab8: 0x3c05002c  lui         $a1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afab4) {
            ctx->pc = 0x1AFB0Cu;
            goto label_1afb0c;
        }
    }
    ctx->pc = 0x1AFABCu;
    // 0x1afabc: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1AFABCu;
    {
        const bool branch_taken_0x1afabc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afabc) {
            ctx->pc = 0x1AFB18u;
            goto label_1afb18;
        }
    }
    ctx->pc = 0x1AFAC4u;
label_1afac4:
    // 0x1afac4: 0xa33021  addu        $a2, $a1, $v1
    ctx->pc = 0x1afac4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1afac8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1afac8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1afacc: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1afaccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1afad0: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x1afad0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
label_1afad4:
    // 0x1afad4: 0x104182a  slt         $v1, $t0, $a0
    ctx->pc = 0x1afad4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1afad8: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AFAD8u;
    {
        const bool branch_taken_0x1afad8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AFADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFAD8u;
            // 0x1afadc: 0x81880  sll         $v1, $t0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afad8) {
            ctx->pc = 0x1AFAC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1afac4;
        }
    }
    ctx->pc = 0x1AFAE0u;
    // 0x1afae0: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1afae0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1afae4: 0x82080  sll         $a0, $t0, 2
    ctx->pc = 0x1afae4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1afae8: 0x24638e20  addiu       $v1, $v1, -0x71E0
    ctx->pc = 0x1afae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938144));
    // 0x1afaec: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1afaecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1afaf0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1afaf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1afaf4: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1afaf4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1afaf8: 0x8c238e10  lw          $v1, -0x71F0($at)
    ctx->pc = 0x1afaf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938128)));
    // 0x1afafc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1afafcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1afb00: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1afb00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1afb04: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AFB04u;
    {
        const bool branch_taken_0x1afb04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFB08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB04u;
            // 0x1afb08: 0xac238e10  sw          $v1, -0x71F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294938128), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afb04) {
            ctx->pc = 0x1AFB18u;
            goto label_1afb18;
        }
    }
    ctx->pc = 0x1AFB0Cu;
label_1afb0c:
    // 0x1afb0c: 0x24e4ffff  addiu       $a0, $a3, -0x1
    ctx->pc = 0x1afb0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1afb10: 0x1000fff0  b           . + 4 + (-0x10 << 2)
    ctx->pc = 0x1AFB10u;
    {
        const bool branch_taken_0x1afb10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFB14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB10u;
            // 0x1afb14: 0x24a58e20  addiu       $a1, $a1, -0x71E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294938144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afb10) {
            ctx->pc = 0x1AFAD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1afad4;
        }
    }
    ctx->pc = 0x1AFB18u;
label_1afb18:
    // 0x1afb18: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFB18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFA88u: goto label_1afa88;
            case 0x1AFAA0u: goto label_1afaa0;
            case 0x1AFAA4u: goto label_1afaa4;
            case 0x1AFAB0u: goto label_1afab0;
            case 0x1AFAC4u: goto label_1afac4;
            case 0x1AFAD4u: goto label_1afad4;
            case 0x1AFB0Cu: goto label_1afb0c;
            case 0x1AFB18u: goto label_1afb18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFB20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
