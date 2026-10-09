#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122E28
// Address: 0x122e28 - 0x122e30
void sub_00122E28_0x122e28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122E28_0x122e28");
#endif

    ctx->pc = 0x122e28u;

    // 0x122e28: 0x3e00008  jr          $ra
    ctx->pc = 0x122E28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E28u;
            // 0x122e2c: 0xc4800024  lwc1        $f0, 0x24($a0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x122E30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
