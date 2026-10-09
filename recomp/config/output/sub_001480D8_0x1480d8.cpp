#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001480D8
// Address: 0x1480d8 - 0x1480e8
void sub_001480D8_0x1480d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001480D8_0x1480d8");
#endif

    ctx->pc = 0x1480d8u;

    // 0x1480d8: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1480d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1480dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1480DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1480E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1480DCu;
            // 0x1480e0: 0xac820008  sw          $v0, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1480E4u;
    // 0x1480e4: 0x0  nop
    ctx->pc = 0x1480e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
