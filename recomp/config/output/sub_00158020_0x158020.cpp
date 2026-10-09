#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158020
// Address: 0x158020 - 0x158030
void sub_00158020_0x158020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158020_0x158020");
#endif

    ctx->pc = 0x158020u;

    // 0x158020: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x158020u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x158024: 0x3e00008  jr          $ra
    ctx->pc = 0x158024u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158024u;
            // 0x158028: 0x2442e570  addiu       $v0, $v0, -0x1A90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960496));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15802Cu;
    // 0x15802c: 0x0  nop
    ctx->pc = 0x15802cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
