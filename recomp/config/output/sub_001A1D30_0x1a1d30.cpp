#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1D30
// Address: 0x1a1d30 - 0x1a1d40
void sub_001A1D30_0x1a1d30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1D30_0x1a1d30");
#endif

    ctx->pc = 0x1a1d30u;

    // 0x1a1d30: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1d30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1d34: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1D34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1D34u;
            // 0x1a1d38: 0x9022ff18  lbu         $v0, -0xE8($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294967064)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A1D3Cu;
    // 0x1a1d3c: 0x0  nop
    ctx->pc = 0x1a1d3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
