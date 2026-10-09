#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E358
// Address: 0x12e358 - 0x12e368
void sub_0012E358_0x12e358(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E358_0x12e358");
#endif

    ctx->pc = 0x12e358u;

    // 0x12e358: 0xa4860006  sh          $a2, 0x6($a0)
    ctx->pc = 0x12e358u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 6), (uint16_t)GPR_U32(ctx, 6));
    // 0x12e35c: 0x3e00008  jr          $ra
    ctx->pc = 0x12E35Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E35Cu;
            // 0x12e360: 0xa4850004  sh          $a1, 0x4($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 4), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12E364u;
    // 0x12e364: 0x0  nop
    ctx->pc = 0x12e364u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
