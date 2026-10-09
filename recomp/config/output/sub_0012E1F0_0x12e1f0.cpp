#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E1F0
// Address: 0x12e1f0 - 0x12e208
void sub_0012E1F0_0x12e1f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E1F0_0x12e1f0");
#endif

    ctx->pc = 0x12e1f0u;

    // 0x12e1f0: 0x94820008  lhu         $v0, 0x8($a0)
    ctx->pc = 0x12e1f0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x12e1f4: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x12e1f4u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12e1f8: 0x9483000a  lhu         $v1, 0xA($a0)
    ctx->pc = 0x12e1f8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x12e1fc: 0x3e00008  jr          $ra
    ctx->pc = 0x12E1FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1FCu;
            // 0x12e200: 0xa4c30000  sh          $v1, 0x0($a2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12E204u;
    // 0x12e204: 0x0  nop
    ctx->pc = 0x12e204u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
