#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B10C0
// Address: 0x1b10c0 - 0x1b1110
void sub_001B10C0_0x1b10c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B10C0_0x1b10c0");
#endif

    switch (ctx->pc) {
        case 0x1b10d4u: goto label_1b10d4;
        default: break;
    }

    ctx->pc = 0x1b10c0u;

    // 0x1b10c0: 0x3c070057  lui         $a3, 0x57
    ctx->pc = 0x1b10c0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)87 << 16));
    // 0x1b10c4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b10c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b10c8: 0x24e797d0  addiu       $a3, $a3, -0x6830
    ctx->pc = 0x1b10c8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294940624));
    // 0x1b10cc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B10CCu;
    {
        const bool branch_taken_0x1b10cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B10D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B10CCu;
            // 0x1b10d0: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b10cc) {
            ctx->pc = 0x1B10F0u;
            goto label_1b10f0;
        }
    }
    ctx->pc = 0x1B10D4u;
label_1b10d4:
    // 0x1b10d4: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x1b10d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b10d8: 0x14650003  bne         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B10D8u;
    {
        const bool branch_taken_0x1b10d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1b10d8) {
            ctx->pc = 0x1B10E8u;
            goto label_1b10e8;
        }
    }
    ctx->pc = 0x1B10E0u;
    // 0x1b10e0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B10E0u;
    {
        const bool branch_taken_0x1b10e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B10E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B10E0u;
            // 0x1b10e4: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b10e0) {
            ctx->pc = 0x1B10FCu;
            goto label_1b10fc;
        }
    }
    ctx->pc = 0x1B10E8u;
label_1b10e8:
    // 0x1b10e8: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1b10e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1b10ec: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1b10ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
label_1b10f0:
    // 0x1b10f0: 0x28c30040  slti        $v1, $a2, 0x40
    ctx->pc = 0x1b10f0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1b10f4: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B10F4u;
    {
        const bool branch_taken_0x1b10f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b10f4) {
            ctx->pc = 0x1B10D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b10d4;
        }
    }
    ctx->pc = 0x1B10FCu;
label_1b10fc:
    // 0x1b10fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B10FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B10D4u: goto label_1b10d4;
            case 0x1B10E8u: goto label_1b10e8;
            case 0x1B10F0u: goto label_1b10f0;
            case 0x1B10FCu: goto label_1b10fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1104u;
    // 0x1b1104: 0x0  nop
    ctx->pc = 0x1b1104u;
    // NOP
    // 0x1b1108: 0x0  nop
    ctx->pc = 0x1b1108u;
    // NOP
    // 0x1b110c: 0x0  nop
    ctx->pc = 0x1b110cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
