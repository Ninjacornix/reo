#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FBA8
// Address: 0x12fba8 - 0x12fbb0
void sub_0012FBA8_0x12fba8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FBA8_0x12fba8");
#endif

    ctx->pc = 0x12fba8u;

    // 0x12fba8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBA8u;
            // 0x12fbac: 0xac850068  sw          $a1, 0x68($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 104), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FBB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
