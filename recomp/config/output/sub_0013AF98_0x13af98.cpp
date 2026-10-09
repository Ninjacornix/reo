#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AF98
// Address: 0x13af98 - 0x13afc8
void sub_0013AF98_0x13af98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AF98_0x13af98");
#endif

    switch (ctx->pc) {
        case 0x13afa0u: goto label_13afa0;
        default: break;
    }

    ctx->pc = 0x13af98u;

    // 0x13af98: 0x24021fff  addiu       $v0, $zero, 0x1FFF
    ctx->pc = 0x13af98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8191));
    // 0x13af9c: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x13af9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_13afa0:
    // 0x13afa0: 0x0  nop
    ctx->pc = 0x13afa0u;
    // NOP
    // 0x13afa4: 0x0  nop
    ctx->pc = 0x13afa4u;
    // NOP
    // 0x13afa8: 0x0  nop
    ctx->pc = 0x13afa8u;
    // NOP
    // 0x13afac: 0x0  nop
    ctx->pc = 0x13afacu;
    // NOP
    // 0x13afb0: 0x0  nop
    ctx->pc = 0x13afb0u;
    // NOP
    // 0x13afb4: 0x443fffa  bgezl       $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13AFB4u;
    {
        const bool branch_taken_0x13afb4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x13afb4) {
            ctx->pc = 0x13AFB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AFB4u;
            // 0x13afb8: 0x2442ffe0  addiu       $v0, $v0, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AFA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13afa0;
        }
    }
    ctx->pc = 0x13AFBCu;
    // 0x13afbc: 0x3e00008  jr          $ra
    ctx->pc = 0x13AFBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AFA0u: goto label_13afa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AFC4u;
    // 0x13afc4: 0x0  nop
    ctx->pc = 0x13afc4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
