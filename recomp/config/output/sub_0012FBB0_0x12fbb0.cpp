#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FBB0
// Address: 0x12fbb0 - 0x12fbb8
void sub_0012FBB0_0x12fbb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FBB0_0x12fbb0");
#endif

    ctx->pc = 0x12fbb0u;

    // 0x12fbb0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBB0u;
            // 0x12fbb4: 0xac850070  sw          $a1, 0x70($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 112), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FBB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
