#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A038
// Address: 0x13a038 - 0x13a044
void sub_0013A038_0x13a038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A038_0x13a038");
#endif

    ctx->pc = 0x13a038u;

    // 0x13a038: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13a038u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13a03c: 0x3e00008  jr          $ra
    ctx->pc = 0x13A03Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A03Cu;
            // 0x13a040: 0xac44d8e8  sw          $a0, -0x2718($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294957288), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13A044u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
