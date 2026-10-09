#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122E30
// Address: 0x122e30 - 0x122e38
void sub_00122E30_0x122e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122E30_0x122e30");
#endif

    ctx->pc = 0x122e30u;

    // 0x122e30: 0x3e00008  jr          $ra
    ctx->pc = 0x122E30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E30u;
            // 0x122e34: 0xe48c0028  swc1        $f12, 0x28($a0) (Delay Slot)
        { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x122E38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
