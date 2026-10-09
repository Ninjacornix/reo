#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155DE0
// Address: 0x155de0 - 0x155e38
void sub_00155DE0_0x155de0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155DE0_0x155de0");
#endif

    switch (ctx->pc) {
        case 0x155e08u: goto label_155e08;
        default: break;
    }

    ctx->pc = 0x155de0u;

    // 0x155de0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155de0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155de4: 0x24424c10  addiu       $v0, $v0, 0x4C10
    ctx->pc = 0x155de4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19472));
    // 0x155de8: 0x8c460040  lw          $a2, 0x40($v0)
    ctx->pc = 0x155de8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x155dec: 0x18c0000f  blez        $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x155DECu;
    {
        const bool branch_taken_0x155dec = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x155DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155DECu;
            // 0x155df0: 0x8c430044  lw          $v1, 0x44($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155dec) {
            ctx->pc = 0x155E2Cu;
            goto label_155e2c;
        }
    }
    ctx->pc = 0x155DF4u;
    // 0x155df4: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x155df4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x155df8: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x155df8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x155dfc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x155dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x155e00: 0x24440018  addiu       $a0, $v0, 0x18
    ctx->pc = 0x155e00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x155e04: 0x0  nop
    ctx->pc = 0x155e04u;
    // NOP
label_155e08:
    // 0x155e08: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x155e08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x155e0c: 0x14470002  bne         $v0, $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x155E0Cu;
    {
        const bool branch_taken_0x155e0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        ctx->pc = 0x155E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155E0Cu;
            // 0x155e10: 0x246306a0  addiu       $v1, $v1, 0x6A0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155e0c) {
            ctx->pc = 0x155E18u;
            goto label_155e18;
        }
    }
    ctx->pc = 0x155E14u;
    // 0x155e14: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x155e14u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
label_155e18:
    // 0x155e18: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x155e18u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x155e1c: 0x0  nop
    ctx->pc = 0x155e1cu;
    // NOP
    // 0x155e20: 0x0  nop
    ctx->pc = 0x155e20u;
    // NOP
    // 0x155e24: 0x14c0fff8  bnez        $a2, . + 4 + (-0x8 << 2)
    ctx->pc = 0x155E24u;
    {
        const bool branch_taken_0x155e24 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x155E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155E24u;
            // 0x155e28: 0x248406a0  addiu       $a0, $a0, 0x6A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155e24) {
            ctx->pc = 0x155E08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155e08;
        }
    }
    ctx->pc = 0x155E2Cu;
label_155e2c:
    // 0x155e2c: 0x3e00008  jr          $ra
    ctx->pc = 0x155E2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155E08u: goto label_155e08;
            case 0x155E18u: goto label_155e18;
            case 0x155E2Cu: goto label_155e2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155E34u;
    // 0x155e34: 0x0  nop
    ctx->pc = 0x155e34u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
