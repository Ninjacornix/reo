#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001407A8
// Address: 0x1407a8 - 0x1407dc
void sub_001407A8_0x1407a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001407A8_0x1407a8");
#endif

    switch (ctx->pc) {
        case 0x1407b8u: goto label_1407b8;
        default: break;
    }

    ctx->pc = 0x1407a8u;

    // 0x1407a8: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1407a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1407ac: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1407ACu;
    {
        const bool branch_taken_0x1407ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1407B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1407ACu;
            // 0x1407b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1407ac) {
            ctx->pc = 0x1407D4u;
            goto label_1407d4;
        }
    }
    ctx->pc = 0x1407B4u;
    // 0x1407b4: 0x0  nop
    ctx->pc = 0x1407b4u;
    // NOP
label_1407b8:
    // 0x1407b8: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1407b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1407bc: 0x0  nop
    ctx->pc = 0x1407bcu;
    // NOP
    // 0x1407c0: 0x0  nop
    ctx->pc = 0x1407c0u;
    // NOP
    // 0x1407c4: 0x0  nop
    ctx->pc = 0x1407c4u;
    // NOP
    // 0x1407c8: 0x0  nop
    ctx->pc = 0x1407c8u;
    // NOP
    // 0x1407cc: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1407CCu;
    {
        const bool branch_taken_0x1407cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1407D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1407CCu;
            // 0x1407d0: 0x24420001  addiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1407cc) {
            ctx->pc = 0x1407B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1407b8;
        }
    }
    ctx->pc = 0x1407D4u;
label_1407d4:
    // 0x1407d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1407D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1407B8u: goto label_1407b8;
            case 0x1407D4u: goto label_1407d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1407DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
