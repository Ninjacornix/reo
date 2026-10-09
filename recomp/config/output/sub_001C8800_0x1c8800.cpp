#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8800
// Address: 0x1c8800 - 0x1c8808
void sub_001C8800_0x1c8800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8800_0x1c8800");
#endif

    ctx->pc = 0x1c8800u;

    // 0x1c8800: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8800u;
            // 0x1c8804: 0x80820044  lb          $v0, 0x44($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 68)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8808u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
