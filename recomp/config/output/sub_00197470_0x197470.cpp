#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00197470
// Address: 0x197470 - 0x197480
void sub_00197470_0x197470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00197470_0x197470");
#endif

    ctx->pc = 0x197470u;

    // 0x197470: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197470u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197474: 0x3e00008  jr          $ra
    ctx->pc = 0x197474u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x197478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197474u;
            // 0x197478: 0xac24fd50  sw          $a0, -0x2B0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966608), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x19747Cu;
    // 0x19747c: 0x0  nop
    ctx->pc = 0x19747cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
