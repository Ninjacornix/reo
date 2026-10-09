#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141DF0
// Address: 0x141df0 - 0x141e08
void sub_00141DF0_0x141df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141DF0_0x141df0");
#endif

    ctx->pc = 0x141df0u;

    // 0x141df0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141df0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141df4: 0x244249e0  addiu       $v0, $v0, 0x49E0
    ctx->pc = 0x141df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18912));
    // 0x141df8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x141df8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x141dfc: 0x3e00008  jr          $ra
    ctx->pc = 0x141DFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141DFCu;
            // 0x141e00: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x141E04u;
    // 0x141e04: 0x0  nop
    ctx->pc = 0x141e04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
