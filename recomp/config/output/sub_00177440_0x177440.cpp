#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177440
// Address: 0x177440 - 0x177448
void sub_00177440_0x177440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177440_0x177440");
#endif

    ctx->pc = 0x177440u;

    // 0x177440: 0x3e00008  jr          $ra
    ctx->pc = 0x177440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177440u;
            // 0x177444: 0xac850f28  sw          $a1, 0xF28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 3880), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
