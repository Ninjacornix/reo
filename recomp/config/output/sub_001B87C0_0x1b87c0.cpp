#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B87C0
// Address: 0x1b87c0 - 0x1b87e0
void sub_001B87C0_0x1b87c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B87C0_0x1b87c0");
#endif

    ctx->pc = 0x1b87c0u;

    // 0x1b87c0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1b87c0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1b87c4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b87c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b87c8: 0x24634bf0  addiu       $v1, $v1, 0x4BF0
    ctx->pc = 0x1b87c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19440));
    // 0x1b87cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B87CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B87D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B87CCu;
            // 0x1b87d0: 0xac236560  sw          $v1, 0x6560($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 25952), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B87D4u;
    // 0x1b87d4: 0x0  nop
    ctx->pc = 0x1b87d4u;
    // NOP
    // 0x1b87d8: 0x0  nop
    ctx->pc = 0x1b87d8u;
    // NOP
    // 0x1b87dc: 0x0  nop
    ctx->pc = 0x1b87dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
