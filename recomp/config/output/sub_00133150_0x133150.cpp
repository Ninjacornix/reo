#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133150
// Address: 0x133150 - 0x133158
void sub_00133150_0x133150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133150_0x133150");
#endif

    ctx->pc = 0x133150u;

    // 0x133150: 0x3e00008  jr          $ra
    ctx->pc = 0x133150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133150u;
            // 0x133154: 0x80820098  lb          $v0, 0x98($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 152)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x133158u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
