#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192000
// Address: 0x192000 - 0x192040
void sub_00192000_0x192000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192000_0x192000");
#endif

    switch (ctx->pc) {
        case 0x192014u: goto label_192014;
        default: break;
    }

    ctx->pc = 0x192000u;

    // 0x192000: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x192000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x192004: 0x51980  sll         $v1, $a1, 6
    ctx->pc = 0x192004u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x192008: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x192008u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x19200c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x19200cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x192010: 0x613821  addu        $a3, $v1, $at
    ctx->pc = 0x192010u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 1)));
label_192014:
    // 0x192014: 0x8ce50000  lw          $a1, 0x0($a3)
    ctx->pc = 0x192014u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x192018: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x192018u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x19201c: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19201cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x192020: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x192020u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x192024: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x192024u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x192028: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x192028u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x19202c: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19202Cu;
    {
        const bool branch_taken_0x19202c = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x192030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19202Cu;
            // 0x192030: 0x24840008  addiu       $a0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19202c) {
            ctx->pc = 0x192014u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192014;
        }
    }
    ctx->pc = 0x192034u;
    // 0x192034: 0x3e00008  jr          $ra
    ctx->pc = 0x192034u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192014u: goto label_192014;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19203Cu;
    // 0x19203c: 0x0  nop
    ctx->pc = 0x19203cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
