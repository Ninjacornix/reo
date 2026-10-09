#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0FB0
// Address: 0x1b0fb0 - 0x1b0fe4
void sub_001B0FB0_0x1b0fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0FB0_0x1b0fb0");
#endif

    switch (ctx->pc) {
        case 0x1b0fc0u: goto label_1b0fc0;
        default: break;
    }

    ctx->pc = 0x1b0fb0u;

    // 0x1b0fb0: 0x3c060057  lui         $a2, 0x57
    ctx->pc = 0x1b0fb0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)87 << 16));
    // 0x1b0fb4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b0fb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0fb8: 0x24c698d0  addiu       $a2, $a2, -0x6730
    ctx->pc = 0x1b0fb8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294940880));
    // 0x1b0fbc: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1b0fbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b0fc0:
    // 0x1b0fc0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b0fc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1b0fc4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1b0fc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1b0fc8: 0x28a302bc  slti        $v1, $a1, 0x2BC
    ctx->pc = 0x1b0fc8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)700) ? 1 : 0);
    // 0x1b0fcc: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1b0fccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1b0fd0: 0x0  nop
    ctx->pc = 0x1b0fd0u;
    // NOP
    // 0x1b0fd4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B0FD4u;
    {
        const bool branch_taken_0x1b0fd4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b0fd4) {
            ctx->pc = 0x1B0FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0fc0;
        }
    }
    ctx->pc = 0x1B0FDCu;
    // 0x1b0fdc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0FDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0FC0u: goto label_1b0fc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0FE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
