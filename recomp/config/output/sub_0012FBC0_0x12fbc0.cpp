#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FBC0
// Address: 0x12fbc0 - 0x12fbc8
void sub_0012FBC0_0x12fbc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FBC0_0x12fbc0");
#endif

    ctx->pc = 0x12fbc0u;

    // 0x12fbc0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBC0u;
            // 0x12fbc4: 0xac850078  sw          $a1, 0x78($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 120), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FBC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
