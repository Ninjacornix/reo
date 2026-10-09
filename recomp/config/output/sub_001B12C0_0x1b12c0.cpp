#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B12C0
// Address: 0x1b12c0 - 0x1b1300
void sub_001B12C0_0x1b12c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B12C0_0x1b12c0");
#endif

    switch (ctx->pc) {
        case 0x1b12d0u: goto label_1b12d0;
        default: break;
    }

    ctx->pc = 0x1b12c0u;

    // 0x1b12c0: 0x3c05004f  lui         $a1, 0x4F
    ctx->pc = 0x1b12c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)79 << 16));
    // 0x1b12c4: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1b12c4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b12c8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B12C8u;
    {
        const bool branch_taken_0x1b12c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B12CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B12C8u;
            // 0x1b12cc: 0x24a5cb80  addiu       $a1, $a1, -0x3480 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953856));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b12c8) {
            ctx->pc = 0x1B12ECu;
            goto label_1b12ec;
        }
    }
    ctx->pc = 0x1B12D0u;
label_1b12d0:
    // 0x1b12d0: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1b12d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1b12d4: 0x14440003  bne         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B12D4u;
    {
        const bool branch_taken_0x1b12d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1B12D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B12D4u;
            // 0x1b12d8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b12d4) {
            ctx->pc = 0x1B12E4u;
            goto label_1b12e4;
        }
    }
    ctx->pc = 0x1B12DCu;
    // 0x1b12dc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B12DCu;
    {
        const bool branch_taken_0x1b12dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b12dc) {
            ctx->pc = 0x1B12F8u;
            goto label_1b12f8;
        }
    }
    ctx->pc = 0x1B12E4u;
label_1b12e4:
    // 0x1b12e4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b12e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b12e8: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1b12e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
label_1b12ec:
    // 0x1b12ec: 0x28620480  slti        $v0, $v1, 0x480
    ctx->pc = 0x1b12ecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)1152) ? 1 : 0);
    // 0x1b12f0: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B12F0u;
    {
        const bool branch_taken_0x1b12f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B12F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B12F0u;
            // 0x1b12f4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b12f0) {
            ctx->pc = 0x1B12D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b12d0;
        }
    }
    ctx->pc = 0x1B12F8u;
label_1b12f8:
    // 0x1b12f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B12F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B12D0u: goto label_1b12d0;
            case 0x1B12E4u: goto label_1b12e4;
            case 0x1B12ECu: goto label_1b12ec;
            case 0x1B12F8u: goto label_1b12f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1300u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
