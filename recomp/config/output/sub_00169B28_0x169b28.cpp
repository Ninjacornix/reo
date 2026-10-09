#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169B28
// Address: 0x169b28 - 0x169b38
void sub_00169B28_0x169b28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169B28_0x169b28");
#endif

    ctx->pc = 0x169b28u;

    // 0x169b28: 0x248401fc  addiu       $a0, $a0, 0x1FC
    ctx->pc = 0x169b28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 508));
    // 0x169b2c: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x169b2cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x169b30: 0x3e00008  jr          $ra
    ctx->pc = 0x169B30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169B30u;
            // 0x169b34: 0xac800000  sw          $zero, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x169B38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
