#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B4F8
// Address: 0x15b4f8 - 0x15b548
void sub_0015B4F8_0x15b4f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B4F8_0x15b4f8");
#endif

    switch (ctx->pc) {
        case 0x15b518u: goto label_15b518;
        default: break;
    }

    ctx->pc = 0x15b4f8u;

    // 0x15b4f8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x15b4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x15b4fc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15b4fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b500: 0x24424c70  addiu       $v0, $v0, 0x4C70
    ctx->pc = 0x15b500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19568));
    // 0x15b504: 0x8c450054  lw          $a1, 0x54($v0)
    ctx->pc = 0x15b504u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 84)));
    // 0x15b508: 0x18a0000c  blez        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x15B508u;
    {
        const bool branch_taken_0x15b508 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x15B50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B508u;
            // 0x15b50c: 0x8c440058  lw          $a0, 0x58($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 88)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b508) {
            ctx->pc = 0x15B53Cu;
            goto label_15b53c;
        }
    }
    ctx->pc = 0x15B510u;
    // 0x15b510: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x15b510u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15b514: 0x8c830188  lw          $v1, 0x188($a0)
    ctx->pc = 0x15b514u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 392)));
label_15b518:
    // 0x15b518: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x15b518u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b51c: 0x10670008  beq         $v1, $a3, . + 4 + (0x8 << 2)
    ctx->pc = 0x15B51Cu;
    {
        const bool branch_taken_0x15b51c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 7));
        ctx->pc = 0x15B520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B51Cu;
            // 0x15b520: 0x248403e0  addiu       $a0, $a0, 0x3E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 992));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b51c) {
            ctx->pc = 0x15B540u;
            goto label_15b540;
        }
    }
    ctx->pc = 0x15B524u;
    // 0x15b524: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x15b524u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x15b528: 0xc5102a  slt         $v0, $a2, $a1
    ctx->pc = 0x15b528u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x15b52c: 0x0  nop
    ctx->pc = 0x15b52cu;
    // NOP
    // 0x15b530: 0x0  nop
    ctx->pc = 0x15b530u;
    // NOP
    // 0x15b534: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x15B534u;
    {
        const bool branch_taken_0x15b534 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15b534) {
            ctx->pc = 0x15B538u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15B534u;
            // 0x15b538: 0x8c830188  lw          $v1, 0x188($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 392)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15B518u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15b518;
        }
    }
    ctx->pc = 0x15B53Cu;
label_15b53c:
    // 0x15b53c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15b53cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15b540:
    // 0x15b540: 0x3e00008  jr          $ra
    ctx->pc = 0x15B540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B518u: goto label_15b518;
            case 0x15B53Cu: goto label_15b53c;
            case 0x15B540u: goto label_15b540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B548u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
