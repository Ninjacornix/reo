#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158500
// Address: 0x158500 - 0x158518
void sub_00158500_0x158500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158500_0x158500");
#endif

    ctx->pc = 0x158500u;

    // 0x158500: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x158500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x158504: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x158504u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x158508: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x158508u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x15850c: 0x3e00008  jr          $ra
    ctx->pc = 0x15850Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15850Cu;
            // 0x158510: 0xac820004  sw          $v0, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x158514u;
    // 0x158514: 0x0  nop
    ctx->pc = 0x158514u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
