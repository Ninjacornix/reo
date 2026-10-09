#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6760
// Address: 0x1c6760 - 0x1c676c
void sub_001C6760_0x1c6760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6760_0x1c6760");
#endif

    ctx->pc = 0x1c6760u;

    // 0x1c6760: 0xa48501e8  sh          $a1, 0x1E8($a0)
    ctx->pc = 0x1c6760u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 488), (uint16_t)GPR_U32(ctx, 5));
    // 0x1c6764: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6764u;
            // 0x1c6768: 0xa48001e0  sh          $zero, 0x1E0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 480), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C676Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
