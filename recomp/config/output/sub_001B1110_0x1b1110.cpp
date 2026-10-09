#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1110
// Address: 0x1b1110 - 0x1b1150
void sub_001B1110_0x1b1110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1110_0x1b1110");
#endif

    switch (ctx->pc) {
        case 0x1b1120u: goto label_1b1120;
        default: break;
    }

    ctx->pc = 0x1b1110u;

    // 0x1b1110: 0x3c070057  lui         $a3, 0x57
    ctx->pc = 0x1b1110u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)87 << 16));
    // 0x1b1114: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b1114u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1118: 0x24e797d0  addiu       $a3, $a3, -0x6830
    ctx->pc = 0x1b1118u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294940624));
    // 0x1b111c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1b111cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b1120:
    // 0x1b1120: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x1b1120u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b1124: 0x14640002  bne         $v1, $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B1124u;
    {
        const bool branch_taken_0x1b1124 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1b1124) {
            ctx->pc = 0x1B1130u;
            goto label_1b1130;
        }
    }
    ctx->pc = 0x1B112Cu;
    // 0x1b112c: 0xace50000  sw          $a1, 0x0($a3)
    ctx->pc = 0x1b112cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 5));
label_1b1130:
    // 0x1b1130: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1b1130u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1b1134: 0x28c30040  slti        $v1, $a2, 0x40
    ctx->pc = 0x1b1134u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1b1138: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1B1138u;
    {
        const bool branch_taken_0x1b1138 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B113Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1138u;
            // 0x1b113c: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1138) {
            ctx->pc = 0x1B1120u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1120;
        }
    }
    ctx->pc = 0x1B1140u;
    // 0x1b1140: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1140u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1120u: goto label_1b1120;
            case 0x1B1130u: goto label_1b1130;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1148u;
    // 0x1b1148: 0x0  nop
    ctx->pc = 0x1b1148u;
    // NOP
    // 0x1b114c: 0x0  nop
    ctx->pc = 0x1b114cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
