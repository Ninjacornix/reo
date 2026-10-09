#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E1E0
// Address: 0x12e1e0 - 0x12e1f0
void sub_0012E1E0_0x12e1e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E1E0_0x12e1e0");
#endif

    ctx->pc = 0x12e1e0u;

    // 0x12e1e0: 0xa486000a  sh          $a2, 0xA($a0)
    ctx->pc = 0x12e1e0u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 10), (uint16_t)GPR_U32(ctx, 6));
    // 0x12e1e4: 0x3e00008  jr          $ra
    ctx->pc = 0x12E1E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1E4u;
            // 0x12e1e8: 0xa4850008  sh          $a1, 0x8($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 8), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12E1ECu;
    // 0x12e1ec: 0x0  nop
    ctx->pc = 0x12e1ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
