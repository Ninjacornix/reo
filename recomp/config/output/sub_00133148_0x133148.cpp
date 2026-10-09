#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133148
// Address: 0x133148 - 0x133150
void sub_00133148_0x133148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133148_0x133148");
#endif

    ctx->pc = 0x133148u;

    // 0x133148: 0x3e00008  jr          $ra
    ctx->pc = 0x133148u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13314Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133148u;
            // 0x13314c: 0xa0850098  sb          $a1, 0x98($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 152), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133150u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
