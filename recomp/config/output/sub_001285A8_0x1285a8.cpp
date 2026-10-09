#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001285A8
// Address: 0x1285a8 - 0x1285d8
void sub_001285A8_0x1285a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001285A8_0x1285a8");
#endif

    switch (ctx->pc) {
        case 0x1285b0u: goto label_1285b0;
        default: break;
    }

    ctx->pc = 0x1285a8u;

    // 0x1285a8: 0x3402c350  ori         $v0, $zero, 0xC350
    ctx->pc = 0x1285a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)50000);
    // 0x1285ac: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1285acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_1285b0:
    // 0x1285b0: 0x0  nop
    ctx->pc = 0x1285b0u;
    // NOP
    // 0x1285b4: 0x0  nop
    ctx->pc = 0x1285b4u;
    // NOP
    // 0x1285b8: 0x0  nop
    ctx->pc = 0x1285b8u;
    // NOP
    // 0x1285bc: 0x0  nop
    ctx->pc = 0x1285bcu;
    // NOP
    // 0x1285c0: 0x0  nop
    ctx->pc = 0x1285c0u;
    // NOP
    // 0x1285c4: 0x5440fffa  bnel        $v0, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1285C4u;
    {
        const bool branch_taken_0x1285c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1285c4) {
            ctx->pc = 0x1285C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1285C4u;
            // 0x1285c8: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1285B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1285b0;
        }
    }
    ctx->pc = 0x1285CCu;
    // 0x1285cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1285CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1285B0u: goto label_1285b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1285D4u;
    // 0x1285d4: 0x0  nop
    ctx->pc = 0x1285d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
