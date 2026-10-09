#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1080
// Address: 0x1b1080 - 0x1b10b4
void sub_001B1080_0x1b1080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1080_0x1b1080");
#endif

    switch (ctx->pc) {
        case 0x1b1090u: goto label_1b1090;
        default: break;
    }

    ctx->pc = 0x1b1080u;

    // 0x1b1080: 0x3c060057  lui         $a2, 0x57
    ctx->pc = 0x1b1080u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)87 << 16));
    // 0x1b1084: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1084u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1088: 0x24c697d0  addiu       $a2, $a2, -0x6830
    ctx->pc = 0x1b1088u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294940624));
    // 0x1b108c: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1b108cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b1090:
    // 0x1b1090: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b1090u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1b1094: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1b1094u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1b1098: 0x28a30040  slti        $v1, $a1, 0x40
    ctx->pc = 0x1b1098u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1b109c: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1b109cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1b10a0: 0x0  nop
    ctx->pc = 0x1b10a0u;
    // NOP
    // 0x1b10a4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B10A4u;
    {
        const bool branch_taken_0x1b10a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b10a4) {
            ctx->pc = 0x1B1090u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1090;
        }
    }
    ctx->pc = 0x1B10ACu;
    // 0x1b10ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1B10ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1090u: goto label_1b1090;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B10B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
