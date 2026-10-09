#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E3C0
// Address: 0x12e3c0 - 0x12e3d0
void sub_0012E3C0_0x12e3c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E3C0_0x12e3c0");
#endif

    ctx->pc = 0x12e3c0u;

    // 0x12e3c0: 0xa486000a  sh          $a2, 0xA($a0)
    ctx->pc = 0x12e3c0u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 10), (uint16_t)GPR_U32(ctx, 6));
    // 0x12e3c4: 0x3e00008  jr          $ra
    ctx->pc = 0x12E3C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E3C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E3C4u;
            // 0x12e3c8: 0xa4850008  sh          $a1, 0x8($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 8), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12E3CCu;
    // 0x12e3cc: 0x0  nop
    ctx->pc = 0x12e3ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
